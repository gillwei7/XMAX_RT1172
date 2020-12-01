/*
 * hci_bt_event_handler.c
 *
 *  Created on: Aug 14, 2020
 *      Author: WeiGill
 */

/*--------------------------------------------------------------------
                           GENERAL INCLUDES
--------------------------------------------------------------------*/
#include <stdio.h>
#include "FreeRTOS.h"
#include "hci_control_api.h"
#include "fsl_debug_console.h"
#include "BTM_pub.h"
#include "hci_prv.h"
#include "HCI_pub.h"
#include "JPEGPARSER_pub.h"
#include "EW_pub.h"

/*--------------------------------------------------------------------
                           LITERAL CONSTANTS
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                                TYPES
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                              PROCEDURES
--------------------------------------------------------------------*/

/*********************************************************************
*
* @private
* hci_misc_event_handler
*
* Handle BT MISC and vendor specific events
*
* @param opcode    operation code
* @param p_data    uint8 data pointer
* @param data_len  data length
*
*********************************************************************/
void hci_misc_event_handler
    (
    const uint16_t opcode,
    const uint8_t* p_data,
    const uint32_t data_len
    )
{
uint8_t    bt_sw_version[2];

switch( opcode )
    {
    case HCI_CONTROL_MISC_EVENT_SW_VERSION:
        if( INIT_STATE_REQUEST_VERSION == getBTInitUpdateState() )
            {
            setBTInitUpdateState( INIT_STATE_GET_VERSION );
            bt_sw_version[0] = p_data[0];
            bt_sw_version[1] = p_data[1];
            BTM_update_sw_version( bt_sw_version );
            if( ( bt_sw_version[0] < GARMIN_SW_MAJOR_VER ) || ( ( GARMIN_SW_MAJOR_VER == bt_sw_version[0] ) && ( GARMIN_SW_MINOR_VER > bt_sw_version[1] ) ) )
                {
                PRINTF( "Current BT FW is older than MCU BT version:%d.%d. BT update\n\r", bt_sw_version[0], bt_sw_version[1] );
                BT_update_received();
                }
            else
                {
                PRINTF( "BT FW version is equal or higher:%d.%d.\n\r", bt_sw_version[0], bt_sw_version[1] );
                HCI_wiced_send_command( HCI_CONTROL_MISC_COMMAND_READ_PAIR_INFO, NULL, 0 );
                }
            }
        break;

    case HCI_CONTROL_MISC_EVENT_READ_PAIR_INFO:
        BTM_pairing_info_update( p_data );
        break;

    default:
        break;
    }
}

/*********************************************************************
*
* @private
* hci_device_event_handler
*
* Handle BT device events
*
* @param opcode    operation code
* @param p_data    uint8 data pointer
* @param data_len  data length
*
*********************************************************************/
void hci_device_event_handler
    (
    const uint16_t cmd_opcode,
    const uint8_t* p_data,
    const uint32_t data_len
    )
{
switch( cmd_opcode )
    {
    case HCI_CONTROL_EVENT_READ_LOCAL_BDA:
        PRINTF( "BD addr: %02x:%02x:%02x:%02x:%02x:%02x\n\r",
                 (int)p_data[5], (int)p_data[4], (int)p_data[3], (int)p_data[2], (int)p_data[1], (int)p_data[0] );
        break;

    case HCI_CONTROL_EVENT_DEVICE_STARTED:
        PRINTF( "Receive BT device start event\r\n" );
        break;

    default:
            break;

    }
}

/*********************************************************************
*
* @private
* hci_spp_event_handler
*
* Handle BT serial port protocol events
*
* @param opcode    operation code
* @param p_data    uint8 data pointer
* @param data_len  data length
*
*********************************************************************/
void hci_spp_event_handler
    (
    const uint16_t cmd_opcode,
    const uint8_t* p_data,
    const uint32_t data_len
    )
{
bool connection_is_up = false;
uint8_t bd_addr[BT_DEVICE_ADDRESS_LEN] = { 0 };
uint8_t bd_addr_rev[BT_DEVICE_ADDRESS_LEN] = { 0 };

switch( cmd_opcode )
    {
    case HCI_CONTROL_SPP_EVENT_RX_DATA:
        getUartJpegData( (uint8_t *)p_data, (uint32_t)data_len );
        break;

    case HCI_CONTROL_SPP_EVENT_CONNECTED:
        connection_is_up = true;
        BTM_notify_EW_connection_status( BT_CONNECTION_SUCCESS );
        BTM_connection_info_update( connection_is_up, &( p_data[0] ) );
        break;

    case HCI_CONTROL_SPP_EVENT_DISCONNECTED:
        connection_is_up = false;
        BTM_connection_info_update( connection_is_up, &( p_data[0] ) );
        break;

    case HCI_CONTROL_SPP_EVENT_CONNECTION_FAILED:
        BTM_get_paired_device_addr( 0, &bd_addr[0] );
        for( uint8_t i = 0; i < BT_DEVICE_ADDRESS_LEN; i++ )
            {
            bd_addr_rev[i] = bd_addr[BT_DEVICE_ADDRESS_LEN - 1 - i];
            }
        // Use reversed BT address for connect
        HCI_wiced_send_command( HCI_CONTROL_IAP2_COMMAND_CONNECT, bd_addr_rev, BT_DEVICE_ADDRESS_LEN );
        break;

    case HCI_CONTROL_SPP_EVENT_SERVICE_NOT_FOUND:
        BTM_get_paired_device_addr( 0, &bd_addr[0] );
        for( uint8_t i = 0; i < BT_DEVICE_ADDRESS_LEN; i++ )
            {
            bd_addr_rev[i] = bd_addr[BT_DEVICE_ADDRESS_LEN - 1 - i];
            }
        //Use reversed BT address for connect
        HCI_wiced_send_command( HCI_CONTROL_IAP2_COMMAND_CONNECT, bd_addr_rev, BT_DEVICE_ADDRESS_LEN );
        break;

    default:
        break;
    }
}

/*********************************************************************
*
* @private
* hci_iap2_event_handler
*
* Handle BT iAP2 events
*
* @param opcode    operation code
* @param p_data    uint8 data pointer
* @param data_len  data length
*
*********************************************************************/
void hci_iap2_event_handler
    (
    const uint16_t cmd_opcode,
    const uint8_t* p_data,
    const uint32_t data_len
    )
{
bool connection_is_up = false;

switch( cmd_opcode )
    {
    case HCI_CONTROL_IAP2_EVENT_RX_DATA:
        getUartJpegData( (uint8_t *)p_data, (uint32_t)data_len );
        break;

    case HCI_CONTROL_IAP2_EVENT_CONNECTED:
        connection_is_up = true;
        BTM_notify_EW_connection_status( BT_CONNECTION_SUCCESS );
        BTM_connection_info_update( connection_is_up, &( p_data[0] ) );
        break;

    case HCI_CONTROL_IAP2_EVENT_DISCONNECTED:
        connection_is_up = false;
        BTM_connection_info_update( connection_is_up, &( p_data[0] ) );
        break;

    case HCI_CONTROL_IAP2_EVENT_CONNECTION_FAILED:
        BTM_notify_EW_connection_status( BT_CONNECTION_FAIL );
        break;

    case HCI_CONTROL_IAP2_EVENT_SERVICE_NOT_FOUND:
        BTM_notify_EW_connection_status( BT_CONNECTION_FAIL );
        break;

    default:
        break;
    }
}