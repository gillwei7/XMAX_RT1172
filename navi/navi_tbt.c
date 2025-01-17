/*********************************************************************
* @file
* navi_tbt.c
*
* @brief
* Navi module - Handle TBT.
*
* Copyright 2021 by Garmin Ltd. or its subsidiaries.
*********************************************************************/

/*--------------------------------------------------------------------
                           GENERAL INCLUDES
--------------------------------------------------------------------*/
#include "FreeRTOS.h"
#include "event_groups.h"
#include "task.h"
#include "semphr.h"
#include "fsl_debug_console.h"
#include "EW_pub.h"
#include "NAVI_pub.h"
#include "navi_priv.h"
#include "NAVILITE_pub.h"
#include "error_code.h"
#include <stdio.h>
#include <stdlib.h>

/*--------------------------------------------------------------------
                           LITERAL CONSTANTS
--------------------------------------------------------------------*/
#define TBT_HAS_NEXT_UPDATE         ( true )
#define TBT_UPDATE_ONCE             ( false )

/*--------------------------------------------------------------------
                                 TYPES
--------------------------------------------------------------------*/
typedef enum
    {
    TBT_LIST_STATE_IDLE,
    TBT_LIST_STATE_UPDATE,
    TBT_LIST_STATE_CHECK_40TH_ACTIVE_TBT_IDX
    } tbt_list_state_type;

/*--------------------------------------------------------------------
                           PROJECT INCLUDES
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                           MEMORY CONSTANTS
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                               VARIABLES
--------------------------------------------------------------------*/
static SemaphoreHandle_t tbt_semphr_hndl;
static int32_t ticks_to_wait = pdMS_TO_TICKS( 500 );
static uint16_t num_of_tbt_list_item = 0;
static navi_tbt_data_type navi_tbt_buffer[MAX_TBT_SIZE];
static tbt_list_state_type tbt_list_state = TBT_LIST_STATE_IDLE;
static uint16_t cur_act_tbt_idx = 0;
static bool has_more_tbt_items = false;
static int tbt_buff_idx = 0;

/*--------------------------------------------------------------------
                                MACROS
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                              PROCEDURES
--------------------------------------------------------------------*/

/*********************************************************************
*
* @private
* navi_add_tbt_item
*
* Add navi tbt item to navi tbt buffer.
*
*********************************************************************/
void navi_add_tbt_item
    (
    navilite_tbt_list_type* tbt_list_item
    )
{
if( pdTRUE == xSemaphoreTake( tbt_semphr_hndl, ticks_to_wait ) )
    {
    if( tbt_buff_idx < MAX_TBT_SIZE )
        {
        memcpy( navi_tbt_buffer[tbt_buff_idx].description, tbt_list_item->desc, MAX_TBT_DESCRIPTION_SIZE );
        if( tbt_list_item->desc_size < MAX_TBT_DESCRIPTION_SIZE )
            {
            navi_tbt_buffer[tbt_buff_idx].description[tbt_list_item->desc_size] = '\0';
            }
        else
            {
            navi_tbt_buffer[tbt_buff_idx].description[MAX_TBT_DESCRIPTION_SIZE-1] = '\0';
            }

        memcpy( navi_tbt_buffer[tbt_buff_idx].dist_unit, tbt_list_item->distance_unit, MAX_TBT_DIST_UNIT_SIZE );
        if( tbt_list_item->dist_unit_size < MAX_TBT_DIST_UNIT_SIZE )
            {
            navi_tbt_buffer[tbt_buff_idx].dist_unit[tbt_list_item->dist_unit_size] = '\0';
            }
        else
            {
            navi_tbt_buffer[tbt_buff_idx].dist_unit[MAX_TBT_DIST_UNIT_SIZE-1] = '\0';
            }

        navi_tbt_buffer[tbt_buff_idx].distance = NAVILITE_bytes_to_float( tbt_list_item->distance );
        navi_tbt_buffer[tbt_buff_idx].list_idx = tbt_list_item->list_item_index;
        navi_tbt_buffer[tbt_buff_idx].icon_idx = tbt_list_item->icon_index;

        if( tbt_buff_idx < num_of_tbt_list_item )
            {
            tbt_buff_idx++;
            }
        EW_notify_tbt_list_update();
        }
    xSemaphoreGive( tbt_semphr_hndl );
    }
else
    {
    PRINTF( "%s: Semaphore is hold by another task\r\n", __FUNCTION__ );
    }
}

/*********************************************************************
*
* @public
* NAVI_reset_tbt_buffer
*
* Reset Tbt buffer.
*
*********************************************************************/
void NAVI_reset_tbt_buffer
    (
    void
    )
{
if( pdTRUE == xSemaphoreTake( tbt_semphr_hndl, ticks_to_wait ) )
    {
    PRINTF( "%s\r\n", __FUNCTION__ );
    for( int i = 0; i < MAX_TBT_SIZE; i++ )
        {
        navi_tbt_buffer[i].list_idx = 0;
        navi_tbt_buffer[i].icon_idx = 0;
        navi_tbt_buffer[i].distance = 0.0;
        memset( navi_tbt_buffer[i].dist_unit, 0, MAX_TBT_DIST_UNIT_SIZE );
        memset( navi_tbt_buffer[i].description, 0, MAX_TBT_DESCRIPTION_SIZE );
        }
    tbt_list_state = TBT_LIST_STATE_IDLE;
    num_of_tbt_list_item = 0;
    cur_act_tbt_idx = 0;
    has_more_tbt_items = false;
    tbt_buff_idx = 0;
    xSemaphoreGive( tbt_semphr_hndl );
    }
}

/*********************************************************************
*
* @public
* NAVI_get_tbt_item
*
* Get navi tbt item from navi tbt buffer.
*
*********************************************************************/
bool NAVI_get_tbt_item
    (
    const int tbt_index,
    uint32_t* icon_index,
    float* distance,
    char** dist_unit,
    char** description
    )
{
PRINTF( "%s\r\n", __FUNCTION__ );
bool res = false;
if( pdTRUE == xSemaphoreTake( tbt_semphr_hndl, ticks_to_wait ) )
    {
    if( tbt_index < MAX_TBT_SIZE )
        {
        *icon_index = navi_tbt_buffer[tbt_index].icon_idx;
        *distance = navi_tbt_buffer[tbt_index].distance;
        *dist_unit = navi_tbt_buffer[tbt_index].dist_unit;
        *description = navi_tbt_buffer[tbt_index].description;
        }
    xSemaphoreGive( tbt_semphr_hndl );
    }
return res;
}

/*********************************************************************
*
* @public
* navi_set_tbt_item
*
* Update navi tbt item in the navi tbt buffer.
*
*********************************************************************/
bool navi_set_tbt_item
    (
    const uint8_t icon_index,
    const uint32_t distance,
    const uint8_t* distance_unit,
    const uint8_t distance_unit_size
    )
{
PRINTF( "%s\r\n", __FUNCTION__ );
bool res = false;
if( pdTRUE == xSemaphoreTake( tbt_semphr_hndl, ticks_to_wait ) )
    {
    // For LC, active tbt item is always on the top of tbt list based on the UX spec.
    navi_tbt_buffer[0].icon_idx = icon_index;
    memcpy( navi_tbt_buffer[0].dist_unit, distance_unit, MAX_TBT_DIST_UNIT_SIZE );
    if( distance_unit_size < MAX_TBT_DIST_UNIT_SIZE )
        {
        navi_tbt_buffer[0].dist_unit[distance_unit_size] = '\0';
        }
    else
        {
        navi_tbt_buffer[0].dist_unit[MAX_TBT_DIST_UNIT_SIZE-1] = '\0';
        }

    navi_tbt_buffer[0].distance = NAVILITE_bytes_to_float( distance );
    EW_notify_tbt_list_update();
    xSemaphoreGive( tbt_semphr_hndl );
    }
return res;
}

/*********************************************************************
*
* @private
* navi_notify_more_tbt_item
*
* Notify if there are more tbt items after the request this time.
*
* @param has_next_tbt_request Indicates whether there are more tbt items to be received from navi app.
* @param tbt_list_size        Tbt list size.
*
*********************************************************************/
void navi_notify_more_tbt_item
    (
    const bool has_next_tbt_request,
    const uint16_t tbt_list_size
    )
{
PRINTF( "%s\r\n", __FUNCTION__ );
// If the has_next_tbt_request is true, it means that there are more tbt items to be sent to LC.
// If the has_next_tbt_request is false, it means that the total number of tbt items is less than maximum size of tbt list.
switch( has_next_tbt_request )
    {
    case TBT_HAS_NEXT_UPDATE:
        has_more_tbt_items = true;
        tbt_list_state = TBT_LIST_STATE_UPDATE;
        break;
    case TBT_UPDATE_ONCE:
        if( has_more_tbt_items )
            {
            has_more_tbt_items = false;
            tbt_list_state = TBT_LIST_STATE_CHECK_40TH_ACTIVE_TBT_IDX;
            }
        else
            {
            tbt_list_state = TBT_LIST_STATE_UPDATE;
            }
        break;
    }
num_of_tbt_list_item = tbt_list_size;
}

/*********************************************************************
*
* @public
* NAVI_get_tbt_list_size
*
* Return tbt list size
*
*********************************************************************/
uint16_t NAVI_get_tbt_list_size
    (
    void
    )
{
PRINTF( "%s, %d\r\n", __FUNCTION__, num_of_tbt_list_item );
return num_of_tbt_list_item;
}

/*********************************************************************
*
* @private
* NAVI_is_tbt_message_displayed
*
* Determine whether to inform user that there are more Tbt items.
*
*********************************************************************/
bool NAVI_is_tbt_message_displayed
    (
    void
    )
{
return has_more_tbt_items;
}

/*********************************************************************
*
* @private
* navi_delete_tbt_item
*
* Delete a tbt item
*
*********************************************************************/
static void navi_delete_tbt_item
    (
    void
    )
{
PRINTF( "%s\r\n", __FUNCTION__);
if( pdTRUE == xSemaphoreTake( tbt_semphr_hndl, ticks_to_wait ) )
    {
    for( int i = 1; i < num_of_tbt_list_item; i++ )
        {
        navi_tbt_buffer[i-1] = navi_tbt_buffer[i];
        }
    if( num_of_tbt_list_item > 0 )
        {
        num_of_tbt_list_item--;
        }
    xSemaphoreGive( tbt_semphr_hndl );
    }
}

/*********************************************************************
*
* @private
* navi_update_active_tbt_item
*
* Update active Tbt index.
*
* @param recv_act_tbt_idx The received active tbt index.
*
*********************************************************************/
void navi_update_active_tbt_item
    (
    const uint16_t recv_act_tbt_idx
    )
{
PRINTF( "%s\r\n", __FUNCTION__ );
// Reset tbt_idx to 0 since tbt list data has received and active tbt update starts.
tbt_buff_idx = 0;

// Theoretically, The difference is greater than 0.
int tbt_idx_diff = ( recv_act_tbt_idx - cur_act_tbt_idx );

if( tbt_idx_diff < 0 )
    {
    PRINTF( "%s: Invalid index, active tbt update can not be done", __FUNCTION__ );
    }
else
    {
    switch( tbt_list_state )
        {
        case TBT_LIST_STATE_CHECK_40TH_ACTIVE_TBT_IDX:
            // Remove previous tbt item when active tbt index is updated.
            // The recevied active_tbt_index = 41 means it's the first tbt item of second Tbt update so that we should delete tbt item from next active tbt index.
            if( recv_act_tbt_idx > ( TBT_NEXT_UPDATE_IDX + 1 ) &&
                tbt_idx_diff == 1 )
                {
                PRINTF( "%s: Receive Active tbt Index: %d\r\n", __FUNCTION__, recv_act_tbt_idx );
                navi_delete_tbt_item();
                }
            break;
        case TBT_LIST_STATE_UPDATE:
            // Remove previous tbt item when active tbt index is updated.
            // The recevied active_tbt_index = 1 means it's the first tbt item of first Tbt update so that we should delete tbt item from next active tbt index.
            if( recv_act_tbt_idx > 1 &&
                tbt_idx_diff == 1 )
                {
                navi_delete_tbt_item();
                }
            break;
        default:
            break;
        }
    cur_act_tbt_idx = recv_act_tbt_idx;
    EW_notify_tbt_list_update();
    }
}

/*********************************************************************
*
* @private
* navi_tbt_init
*
* Initialize navi tbt
*
*********************************************************************/
void navi_tbt_init
    (
    void
    )
{
tbt_semphr_hndl = xSemaphoreCreateBinary();
configASSERT( NULL != tbt_semphr_hndl );
xSemaphoreGive( tbt_semphr_hndl );
NAVI_reset_tbt_buffer();
}


