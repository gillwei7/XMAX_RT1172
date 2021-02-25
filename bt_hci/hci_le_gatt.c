/*********************************************************************
* @file hci_le_gatt.c
*
* @brief
* Handle BLE gatt data and events.
*
* Copyright 2020-2021 by Garmin Ltd. or its subsidiaries.
*********************************************************************/

/*--------------------------------------------------------------------
                          GENERAL INCLUDES
--------------------------------------------------------------------*/
#include "projdefs.h"
#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"
#include "error_code.h"
#include "fsl_debug_console.h"
#include "hci_control_api.h"
#include "HCI_pub.h"
#include "hci_prv.h"

/*--------------------------------------------------------------------
                           LITERAL CONSTANTS
--------------------------------------------------------------------*/
#define GATT_WRITE_REQUEST_QUEUE_LENGTH   ( 16 )
#define GATT_WRITE_REQUEST_HEADER_LENGTH  ( 4 ) /* connection handle 2 bytes, characteristic handle 2 bytes */

#define ENABLE_BLE_DEBUG_LOG    ( 0 )
#if( ENABLE_BLE_DEBUG_LOG )
    #define BLE_PRINTF  PRINTF
#else
    #define BLE_PRINTF(fmt, ...)
#endif

/*--------------------------------------------------------------------
                                TYPES
--------------------------------------------------------------------*/
typedef struct
    {
    uint16_t start_handle;
    uint16_t end_handle;
    bool     is_discovered;
    const ble_client_callback* callback;
    } ble_client_struct;

typedef struct
    {
    uint16_t handle;
    uint8_t  data[BLE_GATT_WRITE_REQUEST_DATA_MAX_LEN];
    uint16_t data_len;
    } ble_gatt_write_request_struct;

typedef enum
    {
    GATT_WRITE_REQUEST_STATE_IDLE,
    GATT_WRITE_REQUEST_STATE_WAIT_FOR_RESPONSE
    } gatt_write_request_state_struct;

/*--------------------------------------------------------------------
                            VARIABLES
--------------------------------------------------------------------*/
/* BLE service client UUID in little endian */
static const char BLE_CLIENT_UUID_TABLE[BLE_CLIENT_TOTAL][UUID_128BIT_LEN] =
    {
    {0xDC, 0xF8, 0x55, 0xAD, 0x02, 0xC5, 0xF4, 0x8E, 0x3A, 0x43, 0x36, 0x0F, 0x2B, 0x50, 0xD3, 0x89}, // AMS
    {0xD0, 0x00, 0x2D, 0x12, 0x1E, 0x4B, 0x0F, 0xA4, 0x99, 0x4E, 0xCE, 0xB5, 0x31, 0xF4, 0x05, 0x79}  // ANCS
    };

ble_client_struct ble_clients[BLE_CLIENT_TOTAL];
static uint16_t connection_handle = 0;
static bool     is_ble_connected = false;

gatt_write_request_state_struct gatt_write_request_state = GATT_WRITE_REQUEST_STATE_IDLE;
static QueueHandle_t gatt_write_quest_queue_handle;

/*--------------------------------------------------------------------
                            PROCEDURES
--------------------------------------------------------------------*/
/*********************************************************************
*
* @private
* find_ble_client_having_handle
*
* Lookup the index of the BLE service clients.
*
* @param handle The BLE service client handle.
* @return The client index of the BLE client in ble_clients
*
*********************************************************************/
static int find_ble_client_having_handle
    (
    const uint16_t handle
    )
{
int client_idx = -1;
for( int i = 0; i < BLE_CLIENT_TOTAL; i++ )
    {
    if( handle >= ble_clients[i].start_handle &&
        handle <= ble_clients[i].end_handle )
        {
        client_idx = i;
        break;
        }
    }
return client_idx;
}

/*********************************************************************
*
* @private
* clear_status
*
* Clear BLE connection status
*
*********************************************************************/
static int clear_status
    (
    void
    )
{
BLE_PRINTF( "%s\r\n", __FUNCTION__ );

// clear characteristic handles
connection_handle = 0;
for( int i = 0; i < BLE_CLIENT_TOTAL; i++ )
    {
    ble_clients[i].start_handle  = 0;
    ble_clients[i].end_handle    = 0;
    ble_clients[i].is_discovered = false;
    }

// clear write request queue
xQueueReset( gatt_write_quest_queue_handle );

// clear write request state
gatt_write_request_state = GATT_WRITE_REQUEST_STATE_IDLE;

return ERR_NONE;
}

/*********************************************************************
*
* @private
* notify_ble_connected
*
* Notify the registered BLE application that BLE is connected
*
*********************************************************************/
static void notify_ble_connected
    (
    void
    )
{
for( int i = 0; i < BLE_CLIENT_TOTAL; i++ )
    {
    if( NULL != ble_clients[i].callback &&
        NULL != ble_clients[i].callback->ble_connected_callback )
        {
        ble_clients[i].callback->ble_connected_callback();
        }
    }
}

/*********************************************************************
*
* @private
* notify_ble_disconnected
*
* Notify the registered BLE application that BLE is disconnected
*
*********************************************************************/
static void notify_ble_disconnected
    (
    void
    )
{
for( int i = 0; i < BLE_CLIENT_TOTAL; i++ )
    {
    if( NULL != ble_clients[i].callback &&
        NULL != ble_clients[i].callback->ble_disconnected_callback )
        {
        ble_clients[i].callback->ble_disconnected_callback();
        }
    }
}

/*********************************************************************
*
* @private
* hci_le_event_received
*
* Process the HCI LE event data
*
* @param opcode HCI operation code
* @param data The pointer to the data byte array
* @param length The length of the data byte array
* @return The result of success/error.
*
*********************************************************************/
int hci_le_event_received
    (
    const uint16_t opcode,
    const uint8_t* data,
    const uint16_t length
    )
{
switch( opcode )
    {
    case HCI_CONTROL_LE_EVENT_CONNECTED:
        is_ble_connected = true;
        connection_handle = WORD_LITTLE( data[7], data[8] );
        BLE_PRINTF( "LE_EVENT_CONNECTED, conn handle: 0x%x\r\n", connection_handle );
        notify_ble_connected();
        break;

    case HCI_CONTROL_LE_EVENT_DISCONNECTED:
        BLE_PRINTF( "LE_EVENT_DISCONNECTED\r\n" );
        is_ble_connected = false;
        clear_status();
        notify_ble_disconnected();
        break;

    default:
        BLE_PRINTF( "other le opcode 0x%x\r\n", opcode );
        break;
    }
return ERR_NONE;
}

/*********************************************************************
*
* @private
* hci_gatt_event_received
*
* Process the HCI GATT event data
*
* @param opcode HCI operation code
* @param data The pointer to the data byte array
* @param length The length of the data byte array
* @return The result of success/error.
*
*********************************************************************/
int hci_gatt_event_received
    (
    const uint16_t opcode,
    const uint8_t* data,
    const uint16_t length
    )
{
uint16_t handle = 0;
int service_idx = 0;

switch( opcode )
    {
    case HCI_CONTROL_GATT_EVENT_COMMAND_STATUS:
        BLE_PRINTF( "GATT_EVENT_COMMAND_STATUS: %d\r\n", data[0] );
        break;

    case HCI_CONTROL_GATT_EVENT_DISCOVERY_COMPLETE:
        BLE_PRINTF( "GATT_EVENT_DISCOVERY_COMPLETE\r\n" );
        for( int i = 0; i < BLE_CLIENT_TOTAL; i++ )
            {
            if( ble_clients[i].is_discovered )
                {
                if( NULL != ble_clients[i].callback &&
                    NULL != ble_clients[i].callback->discovery_complete_callback )
                    {
                    ble_clients[i].callback->discovery_complete_callback();
                    }
                }
            }
        break;

    case HCI_CONTROL_GATT_EVENT_SERVICE_DISCOVERED:
        BLE_PRINTF( "GATT_EVENT_SERVICE_DISCOVERED, conn handle: %x\r\n", WORD_LITTLE( data[0], data[1] ) );
        BLE_PRINTF( "UUID: %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x\r\n",
                data[2], data[3], data[4], data[5], data[6], data[7], data[8], data[9],
                data[10], data[11], data[12], data[13], data[14], data[15], data[16], data[17] );
        BLE_PRINTF( "start handle: 0x%x, end handle: 0x%x\r\n",
                WORD_LITTLE( data[18], data[19] ), WORD_LITTLE( data[20], data[21] ) );

        for( service_idx = 0; service_idx < BLE_CLIENT_TOTAL; service_idx++ )
            {
            if( 0 == memcmp( &data[2], BLE_CLIENT_UUID_TABLE[service_idx], UUID_128BIT_LEN ) )
                {
                ble_clients[service_idx].is_discovered = true;
                ble_clients[service_idx].start_handle  = WORD_LITTLE( data[18], data[19] );
                ble_clients[service_idx].end_handle    = WORD_LITTLE( data[20], data[21] );
                if( NULL != ble_clients[service_idx].callback &&
                    NULL != ble_clients[service_idx].callback->service_discovered_callback )
                    {
                    ble_clients[service_idx].callback->service_discovered_callback(
                            WORD_LITTLE( data[18], data[19] ),
                            WORD_LITTLE( data[20], data[21] ) );
                    }
                }
            }
        break;

    case HCI_CONTROL_GATT_EVENT_CHARACTERISTIC_DISCOVERED:
        BLE_PRINTF( "GATT_EVENT_CHARACTERISTIC_DISCOVERED, conn handle: %x\r\n", WORD_LITTLE( data[0], data[1] ) );
        BLE_PRINTF( "characteristic handle: 0x%x %x\r\n", data[2], data[3] );
        BLE_PRINTF( "UUID: %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x\r\n",
                data[4], data[5], data[6], data[7], data[8], data[9], data[10], data[11],
                data[12], data[13], data[14], data[15], data[16], data[17], data[18], data[19] );
        BLE_PRINTF( "characteristic property: 0x%x\r\n", data[20] );
        BLE_PRINTF( "value handle: 0x%x %x\r\n", data[21], data[22] );

        handle = WORD_LITTLE( data[21], data[22] );
        service_idx = find_ble_client_having_handle( handle );
        if( service_idx >= 0 )
            {
            if( NULL != ble_clients[service_idx].callback &&
                NULL != ble_clients[service_idx].callback->characteristic_discovered_callback )
                {
                ble_clients[service_idx].callback->characteristic_discovered_callback( &data[4], handle );
                }
            }
        else
            {
            PRINTF( "err: not found service containing handle 0x%x\r\n", handle );
            }
        break;

    case HCI_CONTROL_GATT_EVENT_DESCRIPTOR_DISCOVERED:
        BLE_PRINTF( "GATT_EVENT_DESCRIPTOR_DISCOVERED, conn handle: 0x%x\r\n", WORD_LITTLE( data[0], data[1] ) );
        BLE_PRINTF( "descriptor UUID: %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x\r\n",
                data[2], data[3], data[4], data[5], data[6], data[7], data[8], data[9],
                data[10], data[11], data[12], data[13], data[14], data[15], data[16], data[17] );
        BLE_PRINTF( "descriptor handle: 0x%x %x\r\n", data[18], data[19] );

        handle = WORD_LITTLE( data[18], data[19] );
        service_idx = find_ble_client_having_handle( handle );
        if( service_idx >= 0 )
            {
            if( NULL != ble_clients[service_idx].callback &&
                NULL != ble_clients[service_idx].callback->descriptor_discovered_callback )
                {
                ble_clients[service_idx].callback->descriptor_discovered_callback( handle );
                }
            }
        else
            {
            PRINTF( "err: not found service containing handle 0x%x\r\n", handle );
            }
        break;

    case HCI_CONTROL_GATT_EVENT_READ_REQUEST:
        BLE_PRINTF( "GATT_EVENT_READ_REQUEST\r\n");
        break;

    case HCI_CONTROL_GATT_EVENT_READ_RESPONSE:
        BLE_PRINTF( "GATT_EVENT_READ_RESPONSE\r\n");
        break;

    case HCI_CONTROL_GATT_EVENT_WRITE_REQUEST:
        BLE_PRINTF( "GATT_EVENT_WRITE_REQUEST\r\n");
        break;

    case HCI_CONTROL_GATT_EVENT_WRITE_RESPONSE:
        BLE_PRINTF( "GATT_EVENT_WRITE_RESPONSE, conn handle: 0x%x, result: 0x%x\r\n", WORD_LITTLE( data[0], data[1] ), data[2] );
        gatt_write_request_state = GATT_WRITE_REQUEST_STATE_IDLE;
        if( GATT_WRITE_REQUEST_QUEUE_LENGTH > uxQueueSpacesAvailable( gatt_write_quest_queue_handle ) )
            {
            hci_notify_gatt_write_request_queued();
            }
        break;

    case HCI_CONTROL_GATT_EVENT_INDICATION:
        BLE_PRINTF( "GATT_EVENT_INDICATION\r\n" );
        break;

    case HCI_CONTROL_GATT_EVENT_NOTIFICATION:
        handle = WORD_LITTLE( data[2], data[3] );
        BLE_PRINTF( "GATT_EVENT_NOTIFICATION, conn: 0x%x, handle: 0x%x, len: %d\r\n", WORD_LITTLE( data[0], data[1] ), handle, length );
        for( service_idx = 0; service_idx < BLE_CLIENT_TOTAL; service_idx++ )
            {
            if( handle >= ble_clients[service_idx].start_handle &&
                handle <= ble_clients[service_idx].end_handle )
                {
                ble_clients[service_idx].callback->notification_received_callback( handle, &data[4], length - 4 );
                break;
                }
            }
        break;

    case HCI_CONTROL_GATT_EVENT_READ_ERROR:
        BLE_PRINTF( "GATT_EVENT_READ_ERROR\r\n");
        break;

    case HCI_CONTROL_GATT_EVENT_WRITE_ERROR:
        BLE_PRINTF( "GATT_EVENT_WRITE_ERROR\r\n");
        break;

    default:
        BLE_PRINTF( "invalid gatt opcode %x\r\n", opcode );
        break;
    }
return ERR_NONE;
}

/*********************************************************************
*
* @private
* send_gatt_write_request
*
* Send BLE GATT write request
*
* @param handle The service client handle
* @param data The pointer to the data buffer
* @param length Length of the data to write
* @return The result of success/error.
*
*********************************************************************/
static int send_gatt_write_request
    (
    const uint16_t handle,
    const uint8_t* data,
    const uint16_t length
    )
{
int result = ERR_NONE;
uint8_t send_data[GATT_WRITE_REQUEST_HEADER_LENGTH + BLE_GATT_WRITE_REQUEST_DATA_MAX_LEN];

BLE_PRINTF( "%s handle: 0x%x, len: %d\r\n", __FUNCTION__, handle, length );

if( BLE_GATT_WRITE_REQUEST_DATA_MAX_LEN >= length )
    {
    send_data[0] = connection_handle & 0xff;
    send_data[1] = ( connection_handle >> 8 ) & 0xff;
    send_data[2] = handle & 0xff;
    send_data[3] = ( handle >> 8 )& 0xff;
    memcpy( &send_data[GATT_WRITE_REQUEST_HEADER_LENGTH], data, length );

    if( pdFALSE == HCI_wiced_send_command( HCI_CONTROL_GATT_COMMAND_WRITE_REQUEST, send_data, GATT_WRITE_REQUEST_HEADER_LENGTH + length ) )
        {
        result = ERR_BLE_WRITE;
        }
    }
else
    {
    result = ERR_BLE_WRITE;
    }
return result;
}

/*********************************************************************
*
* @private
* hhci_le_proc_gatt_write_request
*
* Get the GATT write request from queue and
* call send_gatt_write_request() to send to the peer device.
*
*********************************************************************/
void hci_le_proc_gatt_write_request
    (
    void
    )
{
ble_gatt_write_request_struct gatt_write_request;

if( GATT_WRITE_REQUEST_STATE_IDLE == gatt_write_request_state )
    {
    if( pdTRUE == xQueueReceive( gatt_write_quest_queue_handle, &gatt_write_request, 0 ) )
        {
        gatt_write_request_state = GATT_WRITE_REQUEST_STATE_WAIT_FOR_RESPONSE;
        send_gatt_write_request( gatt_write_request.handle, gatt_write_request.data, gatt_write_request.data_len );
        }
    else
        {
        PRINTF( "%s false\r\n", __FUNCTION__ );
        }
    }
}

/*********************************************************************
*
* @public
* HCI_le_enqueue_gatt_write_request
*
* Enqueue the BLE GATT write request
*
* @param handle The service client handle
* @param data The pointer to the data buffer
* @param length Length of the data to write
* @return The result of success/error.
*
*********************************************************************/
int HCI_le_enqueue_gatt_write_request
    (
    const uint16_t handle,
    const uint8_t* data,
    const uint16_t length
    )
{
int result = ERR_NONE;

if( length <= BLE_GATT_WRITE_REQUEST_DATA_MAX_LEN )
    {
    ble_gatt_write_request_struct gatt_write_request;
    gatt_write_request.handle   = handle;
    gatt_write_request.data_len = length;
    memcpy( gatt_write_request.data, data, length );

    if( pdTRUE == xQueueSend( gatt_write_quest_queue_handle, &gatt_write_request, 0 ) )
        {
        hci_notify_gatt_write_request_queued();
        }
    else
        {
        result = ERR_BUF_OVERFLOW;
        PRINTF( "Err: %s queue full\r\n", __FUNCTION__ );
        }
    }
else
    {
    result = ERR_BUF_OPERATION;
    PRINTF( "Err: %s data too long\r\n", __FUNCTION__ );
    }

return result;
}

/*********************************************************************
*
* @public
* HCI_le_register_client_callback
*
* Register the callback function of the BLE GATT service client
*
* @param client_type The BLE GATT client of ble_client_type
* @param callback The pointer of the callback struct of ble_client_callback
* @return The result of success/error.
*
*********************************************************************/
int HCI_le_register_client_callback
    (
    const ble_client_type      client_type,
    const ble_client_callback* callback
    )
{
ble_clients[client_type].callback = callback;
return ERR_NONE;
}

/*********************************************************************
*
* @public
* HCI_le_is_connected
*
* Get the BLE connection status
*
* @return The state of BLE connection.
* @retval True if BLE is connected.
* @retval False if BLE is not connected.
*
*********************************************************************/
bool HCI_le_is_connected
    (
    void
    )
{
return is_ble_connected;
}

/*********************************************************************
*
* @private
* hci_le_init
*
* Init HCI LE group and GATT group
*
*********************************************************************/
void hci_le_init
    (
    void
    )
{
gatt_write_quest_queue_handle = xQueueCreate( GATT_WRITE_REQUEST_QUEUE_LENGTH, sizeof( ble_gatt_write_request_struct ) );
configASSERT( NULL != gatt_write_quest_queue_handle );
}