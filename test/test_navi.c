/*********************************************************************
* @file
* test_navi.c
*
* @brief
* Test module - Navi
*
* Copyright 2021 by Garmin Ltd. or its subsidiaries.
*********************************************************************/

/*--------------------------------------------------------------------
                           GENERAL INCLUDES
--------------------------------------------------------------------*/
#include "FreeRTOS.h"
#include "event_groups.h"
#include "task.h"
#include "fsl_debug_console.h"
#include "EW_pub.h"
#include "TEST_pub.h"
#include "test_priv.h"

/*--------------------------------------------------------------------
                           LITERAL CONSTANTS
--------------------------------------------------------------------*/
#define TEST_NAVI_PERIOD_MS     ( 1000 )

/*--------------------------------------------------------------------
                                 TYPES
--------------------------------------------------------------------*/
typedef enum
    {
    TEST_NAVI_CUR_RD,
    TEST_NAVI_ETA,
    TEST_NAVI_SPEEDLIMIT,
    TEST_NAVI_DAYNIGHT,
    TEST_NAVI_EVENT,
    TEST_NAVI_ROUTE_START,
    TEST_NAVI_TOTAL_ITEM
    } navi_test_type;

/*--------------------------------------------------------------------
                           PROJECT INCLUDES
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                           MEMORY CONSTANTS
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                               VARIABLES
--------------------------------------------------------------------*/
#if( UNIT_TEST_NAVI )
    static int test_type = TEST_NAVI_CUR_RD;
    static uint8_t cur_rd[MAX_ROAD_NAME_SIZE] = "Jalan Kemang Raya Perumahan Kemang Swasta";
    static uint8_t eta[MAX_STR_SIZE] = "982";
    static uint8_t speed_limit[MAX_STR_SIZE] = "80";
    static uint8_t navi_event_message[MAX_STR_SIZE] = "60km/h;100m";
    static int daynight_mode = 0;
    static int test_navi_tick = 0;
    static const int TEST_NAVI_TICK_COUNT = ( TEST_NAVI_PERIOD_MS / TEST_TICK_PERIOD_MS );
    static bool is_navi_event_sent = false;
    static navi_data_type navi_data_obj;
    static bool is_route_guidance_started = false;

#endif

/*--------------------------------------------------------------------
                                MACROS
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                              PROCEDURES
--------------------------------------------------------------------*/
#if( UNIT_TEST_NAVI )
    /*********************************************************************
    *
    * @public
    * TEST_navi_cur_road
    *
    * Callback from JPEG module when JPEG decode is done.
    *
    *********************************************************************/
    static void test_navi_cur_road
        (
        uint8_t* str,
        uint8_t str_size
        )
    {
    if( MAX_ROAD_NAME_SIZE > str_size )
        {
        PRINTF( "Current Road: %s length: %d\r\n", str, str_size );
        strncpy( navi_data_obj.current_road, ( char* )str, MAX_ROAD_NAME_SIZE );

        EW_notify_current_road_update();
        }
    else
        {
        PRINTF( "Unexpected length of current road name: %d\r\n", str_size );
        }
    }

    /*********************************************************************
    *
    * @private
    * test_navi_eta
    *
    * Test ETA.
    *
    *********************************************************************/
    static void test_navi_eta
        (
        uint8_t* str,
        uint8_t str_size
        )
    {
    PRINTF( "ETA: %s length: %d\r\n", str, str_size );
    int eta = atoi( ( char* ) str );
    navi_data_obj.eta = eta;

    EW_notify_eta_update();
    }

    /*********************************************************************
    *
    * @private
    * test_navi_speed_limit
    *
    * Test Navi speed limit.
    *
    *********************************************************************/
    static void test_navi_speed_limit
        (
        uint8_t* str,
        uint8_t str_size
        )
    {
    PRINTF( "Navi speed limit update: %s\r\n", str );
    int spd_lmt = atoi( ( char* ) str );
    navi_data_obj.speed_limit = spd_lmt;

    EW_notify_speed_limit_update();
    }

    /*********************************************************************
    *
    * @private
    * test_navi_daynight_mode
    *
    * Test Navi daynight mode.
    *
    *********************************************************************/
    static void test_navi_daynight_mode
        (
        const int dn_mode
        )
    {
    PRINTF( "DayNight mode update: %d\r\n", dn_mode );
    navi_data_obj.daynight = dn_mode;

    EW_notify_daynight_mode_update();
    }

    /*********************************************************************
    *
    * @private
    * test_navi_navigating_status
    *
    * Update the navigation status when start/stop route guidance.
    *
    *********************************************************************/
    static void test_navi_navigating_status
        (
        const uint8_t status
        )
    {
    PRINTF( "Navigating status update: %d\r\n", status );
    navi_data_obj.is_navigating = status;

    EW_notify_navigating_status_update();
    }

    /*********************************************************************
    *
    * @private
    * test_navi_event
    *
    * Test Navi event.
    *
    *********************************************************************/
    static void test_navi_event
        (
        uint8_t* str,
        uint8_t str_size,
        navi_event_type navi_event_type,
        uint8_t visibility
        )
    {
    if( MAX_STR_SIZE*2 > str_size )
        {
        int idx = 1;
        int length = 0;
        navi_event_stat event;
        char* cur_str = ( char* )str;
        char* next_str = strtok( cur_str, ";" );

        if( NULL == next_str )
            {
            memset( event.dist, 0, MAX_STR_SIZE );
            memcpy( event.dist, next_str, MAX_STR_SIZE );
            event.dist[str_size] = '\0';
            }
        else
            {
            while( NULL != next_str )
                {
                if( idx == 1 )
                    {
                    length = strlen( next_str );
                    memset( event.speed, 0, MAX_STR_SIZE );
                    memcpy( event.speed, next_str, MAX_STR_SIZE );
                    event.speed[length] = '\0';
                    }
                else
                    {
                    length = str_size - length;
                    memset( event.dist, 0, MAX_STR_SIZE );
                    memcpy( event.dist, next_str, MAX_STR_SIZE );
                    event.dist[length] = '\0';
                    }
                next_str = strtok( NULL, ";" );
                idx++;
                }
            }
        event.event_type = navi_event_type;
        event.visibility = visibility;
        event.desc_size = str_size;

        navi_data_obj.navi_event = event;

        PRINTF( "Event update: %s, %d, %d, %d\r\n", str, str_size, navi_event_type, visibility );
        EW_notify_navi_event_update();
        }
    else
        {
        PRINTF( "Unexpected length of navi event message: %d\r\n", str_size );
        }
    }

    /*********************************************************************
    *
    * @public
    * TEST_navi_set_test_type
    *
    * Set test type.
    *
    *********************************************************************/
    void TEST_navi_set_test_type
        (
        const int type
        )
    {
    test_type = type;
    }

    /*********************************************************************
    *
    * @public
    * TEST_navi_get_route_guidance_status
    *
    * Get the route guidance status.
    *
    *********************************************************************/
    bool TEST_navi_get_route_guidance_status
        (
        void
        )
    {
    return navi_data_obj.is_navigating;
    }

    /*********************************************************************
    *
    * @public
    * TEST_get_navi_event
    *
    * Get navi event.
    *
    *********************************************************************/
    navi_data_type* TEST_get_navi_obj
        (
        void
        )
    {
    return &navi_data_obj;
    }

    /*********************************************************************
    *
    * @public
    * test_navi_proc
    *
    * Test module - navi test process.
    *
    *********************************************************************/
    void test_navi_proc
        (
        void
        )
    {
    // Simulate the data sent from navi
    if( test_navi_tick == 0 )
        {
        test_navi_tick = TEST_NAVI_TICK_COUNT;
        switch( test_type )
            {
            case TEST_NAVI_CUR_RD:
                test_navi_cur_road( cur_rd, strlen( ( char* ) cur_rd ) );
                break;
            case TEST_NAVI_ETA:
                test_navi_eta( eta, strlen( ( char* ) eta ) );
                break;
            case TEST_NAVI_SPEEDLIMIT:
                test_navi_speed_limit( speed_limit, strlen( ( char* ) speed_limit ) );
                break;
            case TEST_NAVI_DAYNIGHT:
                {
                test_navi_daynight_mode( daynight_mode );
                if( daynight_mode )
                    {
                    daynight_mode = 0;
                    }
                    else
                    {
                    daynight_mode = 1;
                    } 
                }
                break;
            case TEST_NAVI_EVENT:
                {
                    // Simulate the school zone event in 15 seconds after system boot up.
                    if( xTaskGetTickCount() >= 15000 && !is_navi_event_sent )
                    {
                    is_navi_event_sent = true;
                    test_navi_event( navi_event_message, strlen( ( char* ) navi_event_message ), NAVIEVENT_TYPE_CAMERA, 1 );
                    }
                }
                break;
            case TEST_NAVI_ROUTE_START:
                {
                test_navi_navigating_status( is_route_guidance_started );
                }
                break;
            default:
                break;
            }

        if( test_type == TEST_NAVI_TOTAL_ITEM )
            {
            test_type = TEST_NAVI_CUR_RD;
            }
            else
            {
            test_type++;
            }
        }
    test_navi_tick--;
    }

    /*********************************************************************
    *
    * @public
    * test_navi_int
    *
    * Test module - init navi test.
    *
    *********************************************************************/
    void test_navi_int
        (
        void
        )
    {
    return;
    }
#endif

