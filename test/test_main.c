/*********************************************************************
* @file
* test_main.c
*
* @brief
* Test module - main
*
* Copyright 2020 by Garmin Ltd. or its subsidiaries.
*********************************************************************/

/*--------------------------------------------------------------------
                           GENERAL INCLUDES
--------------------------------------------------------------------*/
#include "FreeRTOS.h"
#include "event_groups.h"
#include "task.h"
#include "semphr.h"
#include "ewrte.h"
#include "fsl_debug_console.h"
#include <TEST_pub.h>
#include <test_priv.h>
#include "GRM_pub_prj.h"

/*--------------------------------------------------------------------
                           LITERAL CONSTANTS
--------------------------------------------------------------------*/
#define TEST_TASK_PRIORITY   ( TASK_PRIO_VEHICLE_INFO_MNGR )
#define TEST_TASK_STACK_SIZE ( configMINIMAL_STACK_SIZE * ( 2 + ( UNIT_TEST_NAVILITE ) * 7 ) )
#define TEST_TASK_NAME       "test_task"

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
#if( UNIT_TEST_ENABLE )
    static const int TEST_TASK_DELAY_TICKS = pdMS_TO_TICKS( TEST_TICK_PERIOD_MS );
#endif

/*--------------------------------------------------------------------
                                MACROS
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                              PROCEDURES
--------------------------------------------------------------------*/
#if( UNIT_TEST_ENABLE )
    /*********************************************************************
    *
    * @private
    * task_main
    *
    * Main loop of the test task
    *
    *********************************************************************/
    static void task_main
        (
        void* arg
        )
    {
    while( true )
        {
        #if( UNIT_TEST_PRODUCTION )
            test_production_proc();
        #endif

        #if( UNIT_TEST_INSPECTION )
            test_inspection_proc();
        #endif

        #if( UNIT_TEST_BURNIN )
            test_burnin_proc();
        #endif

        #if( UNIT_TEST_JPEG )
            test_jpeg_proc();
        #endif

        #if( UNIT_TEST_ADC )
            test_adc_proc();
        #endif

        #if( UNIT_TEST_NAVI )
            test_navi_proc();
        #endif

        #if( UNIT_TEST_EEPROM )
            test_eeprom_proc();
        #endif

        #if( UNIT_TEST_VI )
            test_vi_proc();
        #endif

        #if( UNIT_TEST_TACHO_SPEED )
            test_tacho_speed_proc();
        #endif

        #if( UNIT_TEST_NOTIFICATION )
            test_notification_proc();
        #endif

        #if( UNIT_TEST_WEA )
            test_wea_proc();
        #endif

        #if( UNIT_TEST_NAVILITE )
            test_navilite_proc();
        #endif

        vTaskDelay( TEST_TASK_DELAY_TICKS );
        }

    vTaskDelete( NULL );
    }

    /*********************************************************************
    *
    * @private
    * create_task
    *
    * Create test task
    *
    *********************************************************************/
    static void create_task
        (
        void
        )
    {
    BaseType_t result = xTaskCreate( task_main, TEST_TASK_NAME, TEST_TASK_STACK_SIZE, NULL, TEST_TASK_PRIORITY, NULL );
    configASSERT( pdPASS == result );
    }

    /*********************************************************************
    *
    * @private
    * TEST_init
    *
    * Init test module.
    *
    *********************************************************************/
    void TEST_init
        (
        void
        )
    {
    create_task();

    #if( UNIT_TEST_PRODUCTION )
        test_production_int();
    #endif

    #if( UNIT_TEST_INSPECTION )
        test_inspection_int();
    #endif

    #if( UNIT_TEST_BURNIN )
        test_burnin_int();
    #endif

    #if( UNIT_TEST_JPEG )
        test_jpeg_int();
    #endif

    #if( UNIT_TEST_ADC )
        test_adc_int();
    #endif

    #if( UNIT_TEST_NAVI )
        test_navi_int();
    #endif

    #if( UNIT_TEST_EEPROM )
        test_eeprom_int();
    #endif

    #if( UNIT_TEST_VI )
        test_vi_int();
    #endif

    #if( UNIT_TEST_TACHO_SPEED )
        test_tacho_speed_int();
    #endif

    #if( UNIT_TEST_NOTIFICATION )
        test_notification_int();
    #endif

    #if( UNIT_TEST_WEA )
        test_wea_int();
    #endif

    #if( UNIT_TEST_NAVILITE )
        test_navilite_int();
    #endif
    }
#endif

