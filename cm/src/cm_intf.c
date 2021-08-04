/*********************************************************************
* @file  cm_intf.c
* @brief Connection Manager Public General interface definition.
*
* Copyright 2021 by Garmin Ltd. or its subsidiaries.
*********************************************************************/

#ifdef __cplusplus
extern "C"{
#endif

/*--------------------------------------------------------------------
                        GENERAL INCLUDES
--------------------------------------------------------------------*/
#include "string.h"
#include "cm_types.h"
#include "CM_pub.h"
#include "cm_tsk.h"
#include "cm_prv.h"

/*--------------------------------------------------------------------
                        Definitions
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                        LITERAL CONSTANTS
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                        TYPES
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                        PROJECT INCLUDES
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                        MEMORY CONSTANTS
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                        VARIABLES
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                        PROTOTYPES
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                        PROCEDURES
--------------------------------------------------------------------*/
/*================================================================================================
@brief   Connection Manager initialization
@details Create Connection Manager main initialization process
@return  None
@retval  The error code specified in BT_status_e
================================================================================================*/
CM_status_e CM_init
    (
    void
    )
{
CM_core_init();
CM_tsk_init();

return CM_STATUS_OK;
}

/*================================================================================================
@brief   Connect the SPP app to the remote device
@details Send the request of connecting the SPP app to the remote device to Connection Manager
@return  None
@retval  The error code specified in CM_status_e
================================================================================================*/
CM_status_e CM_connect
    (
    const uint8_t* bd_addr
    )
{
CM_task_request_t task_request;
task_request.CM_REQUEST_type = CM_REQUEST_SPP_CONNECT;
memcpy( task_request.CM_spp_connect_request.bd_addr, bd_addr, BT_DEVICE_ADDRESS_LEN );
if( false == CM_tsk_send_request( &task_request ) )
    {
    return CM_STATUS_QUEUE_FULL;
    }
return CM_STATUS_OK;
}

/*================================================================================================
@brief   Disconnect the SPP app to the remote device
@details Send the request of disconnect the SPP app to the remote device to Connection Manager
@return  None
@retval  The error code specified in CM_status_e
================================================================================================*/
CM_status_e CM_disconnect
    (
    const uint8_t* bd_addr
    )
{
CM_task_request_t task_request;
task_request.CM_REQUEST_type = CM_REQUEST_SPP_DISCONNECT;
memcpy( task_request.CM_spp_disconnect_request.bd_addr, bd_addr, BT_DEVICE_ADDRESS_LEN );
if( false == CM_tsk_send_request( &task_request ) )
    {
    return CM_STATUS_QUEUE_FULL;
    }
return CM_STATUS_OK;
}

/*================================================================================================
@brief   Get SPP connection status
@details For HMI get spp connection status
@return  None
@retval  Return SPP connection status for different APP
================================================================================================*/
bool CM_get_spp_connection_status
    (
    const CM_app_type_e app_type
    )
{
return CM_core_get_spp_connection_status( app_type );
}


/*================================================================================================
@brief   Get SPP connection status
@details For HMI get spp connection status
@return  None
@retval  Return SPP connection status for different APP
================================================================================================*/
bool CM_get_app_connection_status
    (
    const CM_app_type_e app_type,
    const uint8_t* bd_addr
    )
{
return CM_core_get_app_connection_status( app_type, bd_addr );
}

/*================================================================================================
@brief   Handle the BT manager pairing result
@details Handle the BT manager pairing result
@return  None
@retval  Return Connection manager send request status
================================================================================================*/
CM_status_e CM_handle_btmgr_pairing_result
    (
    const bool pairing_result,
    const uint8_t* bd_addr
    )
{
CM_task_request_t task_request;
task_request.CM_REQUEST_type = CM_REQUEST_PAIRING_RESULT;
task_request.CM_btmgr_pairing_result.pairing_result = pairing_result;
memcpy( task_request.CM_btmgr_pairing_result.bd_addr, bd_addr, BT_DEVICE_ADDRESS_LEN );
if( false == CM_tsk_send_request( &task_request ) )
    {
    return CM_STATUS_QUEUE_FULL;
    }
return CM_STATUS_OK;
}

/*================================================================================================
@brief   Handle the SPP connection status change
@details Handle the SPP connection status change
@return  None
@retval  Return Connection manager send request status
================================================================================================*/
CM_status_e CM_handle_btmgr_spp_connection_status_changed
    (
    const bool connected,
    const CM_app_type_e app_type,
    const uint8_t* bd_addr
    )
{
CM_task_request_t task_request;
task_request.CM_REQUEST_type = CM_REQUEST_CONNECTION_STATUS_CHANGE;
task_request.CM_connection_status_change.app_type = app_type;
task_request.CM_connection_status_change.connected = connected;
memcpy( task_request.CM_connection_status_change.bd_addr, bd_addr, BT_DEVICE_ADDRESS_LEN );

if( false == CM_tsk_send_request( &task_request ) )
    {
    return CM_STATUS_QUEUE_FULL;
    }
return CM_STATUS_OK;
}

/*================================================================================================
@brief   Handle the Application authentication result
@details Used for Motocon SDK authentication result and Navillite authentication result and send result to
         Connection manager
@return  None
@retval  None
================================================================================================*/
CM_status_e CM_handle_app_auth_result
    (
    const CM_app_type_e app_type,
    const bool auth_result
    )
{
CM_task_request_t task_request;
task_request.CM_REQUEST_type = CM_REQUEST_AUTHENTICATION_RESULT;
task_request.CM_auth_result.app_type = app_type;
task_request.CM_auth_result.result = auth_result;

if( false == CM_tsk_send_request( &task_request ) )
    {
    return CM_STATUS_QUEUE_FULL;
    }
return CM_STATUS_OK;
}

#ifdef __cplusplus
}
#endif