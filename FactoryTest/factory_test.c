/*********************************************************************
* @file
* factory_test.c
*
* Brief factory test application
*
* Copyright 2020 by Garmin Ltd. or its subsidiaries.
*********************************************************************/

#ifdef __cplusplus
extern "C"{
#endif

/*--------------------------------------------------------------------
                           GENERAL INCLUDES
--------------------------------------------------------------------*/
#include "board.h"
#include "MIMXRT1172.h"
#include "clock_config.h"
#include "FreeRTOS.h"
#include "pin_mux.h"
#include "task.h"

#include "fsl_debug_console.h"
#include "PERIPHERAL_pub.h"
#include "GRM_pub_prj.h"
#include "EW_pub.h"
#include "EEPM_pub.h"
#include "RTC_pub.h"
#include "WDG_pub.h"
#include "BT_pub.h"

#include "can_cfg.h"
#include "can_drv.h"
#include "can_hw.h"
#include "can_dll_par.h"
#include "can_dll_prv_par.h"

#include "IOP_pub_inst.h"
#include "IOP_pub_cmnd.h"
#include "IOP_pub_vim_inst_prj.h"

#include "factory_test.h"

/*--------------------------------------------------------------------
                           LITERAL CONSTANTS
--------------------------------------------------------------------*/
#define FACTORY_TASK_PERIOD_MS  ( 10 )
#define NULL_PTR                ( ( void * ) 0 )

#define E_OK                    ( 0 )
#define E_NOT_OK                ( 1 )

#define STD_HIGH                ( 1u ) /* Physical state 5V or 3.3V */
#define STD_LOW                 ( 0u ) /* Physical state 0V */

#define DATA_INVALID_BYTE       ( 0xFF )
#define DATA_INVALID_2BYTES     ( 0xFFFF )
#define DATA_INVALID_4BYTES     ( 0xFFFFFFFF )

#define BIT_32_DATA_LEN         ( 4 )
#define BIT_24_DATA_LEN         ( 3 )
#define BIT_16_DATA_LEN         ( 2 )
#define BIT_8_DATA_LEN          ( 1 )

#define IOP_VIM_MAX_DATA_SIZE   ( 200 )
#define IOP_MAX_QUEUE_SIZE      ( 100 )
#define IOP_QUEUE_INVALID       ( -1 )

#define ESN_REWRITE_ID          ( 0xFFFFFFFF )
#define ASCII_BYTE_OFFSET       ( 0x30 )
#define ASCII_BYTE_DOT          ( 0x2E ) // .
#define ASCII_BYTE_NEXT_LINE    ( 0x00 )
#define LOW_BYTE_MASK           ( 0x00FF )
#define MAX_PIN_NUM             ( 32 )

#define IOP_PRODUCT_HW_ID       ( 0 )
#define IOP_PRODUCT_SKU_ID      ( 1 )

#define BURN_IN_TASK_TIME       ( 1000 )
#define BURN_IN_QUAL_DFT_TIME   ( 8 * 60 * 60 )
#define BURN_IN_QUAL_TEMP       ( 55 * 1000 )
#define BURN_IN_QUAL_MIN_TIME   ( 1 * 60 * 60 )
#define BURN_IN_QUAL_MAX_TIME   ( BURN_IN_QUAL_DFT_TIME )
#define BURN_IN_SUCCESS         ( 1 )
#define BURN_IN_FAIL            ( 0 )
#define BURN_IN_START_FLAG      ( 1 )

#define CANID_TEST_MAX_ROUND    ( 3 )
#define CANID_TEST_SEND_MS      ( 500 )
#define CANID_TEST_SEND_CNT     ( CANID_TEST_SEND_MS / FACTORY_TASK_PERIOD_MS )
#define CANID_TEST_MAX_TIME_MS  ( CANID_TEST_SEND_MS * ( sizeof( CAN_test_ID ) / sizeof( CAN_test_ID[0] ) ) )
#define CANID_TEST_MAX_TIME_CNT ( CANID_TEST_MAX_TIME_MS / FACTORY_TASK_PERIOD_MS )

#define ABSOLUTE_TEMP_OFFSET    ( 273150 )

// For Factory Reset IOP
#define OPERATION_MODE_NORMAL   ( 0 )
#define OPERATION_MODE_FACTORY  ( 1 )
#define FACTORY_RST_FLAG_NEXIST ( 0 )
#define FACTORY_RST_FLAG_EXIST  ( 1 )

// For QRcode IOP
#define QRCODE_STATUS_INVALID       ( 0x00 )
#define QRCODE_STATUS_FUSED1_OK     ( 0x01 )
#define QRCODE_STATUS_FUSED2_OK     ( 0x02 )
#define QRCODE_STATUS_FUSED3_OK     ( 0x04 )
#define QRCODE_STATUS_SUCCESS       ( QRCODE_STATUS_FUSED1_OK | QRCODE_STATUS_FUSED2_OK | QRCODE_STATUS_FUSED3_OK )

#define AUTH_CHIP_RESULT_FAIL        0 // For IOP_MFI_START_COPROCESSOR_TEST test

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
static uint16_t const product_id = 0x0F70;
static char const product_string_line1[] = { "IXWW22 v" };
static char const product_string_line2[] = { "Board Version: " };
static char const product_string_line3[] = { "VERSYSTEMPARTNUM 006-B3952-00" };


static uint8_t  recordSequenceId;
static uint8_t  recordDataSize;
static uint8_t  recordData[IOP_VIM_MAX_DATA_SIZE];
static uint8_t  iopDataQueue[IOP_MAX_QUEUE_SIZE][8];
static int8_t   iopDataHead = IOP_QUEUE_INVALID;
static int8_t   iopDataTail = IOP_QUEUE_INVALID;


//IOP proc
static uint16_t       IOPInstId           = 0;
static uint16_t       IOPSubId            = 0;
static uint16_t       IOPCaseId           = 0;
static bool           IOPDone             = TRUE;

//esn
static uint32_t       esn_id              = 0;
static uint32_t       EEPM_esn_id         = 0;
static IOP_esn_op     esn_operation       = IOP_ESN_OP_INVALID;

//Burn-in
IOP_BurnIn_op_stage_type            burnInStage            = IOP_BURNIN_STAGE_NOT_START;
static boolean                      burnInResult           = BURN_IN_FAIL;
static uint32_t                     burnInTime             = 0;
static uint32_t                     burnInTargetTime       = BURN_IN_QUAL_DFT_TIME;
static uint32_t                     burnInElapseTime       = 0;
static IOP_set_BurnIn_state_type    burnInState            = IOP_BURNIN_STATE_NONE;
static boolean                      burnInPassFlag         = FALSE;

//CAN ID test
static boolean CAN_ID_test_flag = FALSE;
static uint32_t CAN_test_ID[]   = { 0x4C0, 0x100, 0x200, 0x400, 0x110, 0x220, 0x440, 0x480, 0x111, 0x222, 0x444, 0x488, 0x4C7 };

//QRCODE
static uint8_t qrcode_write_status = 0;

/*--------------------------------------------------------------------
                                MACROS
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                              PROCEDURES
--------------------------------------------------------------------*/
static void storeCanData
    (
    uint8_t*  canData
    );

static void sendCanData
    (
    void
    );

static void iopToCanData
    (
    uint16_t  iopid,
    uint8_t*  iopRawData,
    uint8_t   iopDataSize
    );

static void packageIopToCanData
    (
    void*  data_ptr,
    uint16_t data_len
    );

static void iopProcInstCmd
    (
    uint16_t  inst_id,
    uint8_t*  data,
    uint16_t  size
    );

static void iopProcVIMCaseCmd
    (
    uint16_t case_id,
    uint8_t* data,
    uint16_t size
    );

static void packageIopData
    (
    uint8_t* rawData
    );

static void CanToIopParser
    (
    const uint8_t* canRawData
    );

static uint8_t setGPIOValue
    (
    uint8_t     port,
    uint8_t     pin,
    uint8_t     val
    );

static uint8_t getGPIOValue
    (
    uint8_t     port,
    uint8_t     pin,
    uint8_t   * output_lvl
    );

static void factory_create_task
    (
    void
    );

static void factory_test_task
    (
    void* arg
    );

static void IOP_BurnIn_Task
    (
    void* arg
    );

static void sendCanTestData
    (
    void
    );

static void esn_read_cb
    (
    bool    status,
    void*   data
    );

static void esn_write_cb
    (
    bool    status,
    void*   data
    );

static uint8 get_hw_id
    (
    uint8 * hw_id_data
    );

static void get_sku_id
    (
    uint8 * sku_id_data
    );

static void burnin_result_read_cb
    (
    bool    status,
    void*   data
    );

static void burnin_result_write_cb
    (
    bool    status,
    void*   data
    );

static void burnin_start_write_cb
    (
    bool    status,
    void*   data
    );

static void burnin_start_read_cb
    (
    bool    status,
    void*   data
    );

static void burnin_time_read_cb
    (
    bool    status,
    void*   data
    );

static void burnin_time_read_return_cb
    (
    bool    status,
    void*   data
    );

static void burnin_time_write_cb
    (
    bool    status,
    void*   data
    );

static void burnin_target_time_read_cb
    (
    bool    status,
    void*   data
    );

static void burnin_target_time_write_cb
    (
    bool    status,
    void*   data
    );

static void operation_mode_write_cb
    (
    bool    status,
    void*   data
    );

static void operation_mode_read_cb
    (
    bool    status,
    void*   data
    );

static void fused_data_1_write_cb
    (
    bool    status,
    void*   data
    );

static void fused_data_2_write_cb
    (
    bool    status,
    void*   data
    );

static void fused_data_3_write_cb
    (
    bool    status,
    void*   data
    );

/*********************************************************************
*
* @public
* FACTORY_init
*
* @brief Initial function to public to create factory test task.
*
*
*********************************************************************/

void FACTORY_init
    (
    void
    )
{
factory_create_task();
if( EEPM_get_start_burn_in( burnin_start_read_cb ) == pdFALSE )
    {
    PRINTF("EEPM_get_start_burn_in fail\n\r");
    }
if( EEPM_get_burn_in_time( burnin_time_read_cb ) == pdFALSE )
    {
    PRINTF("EEPM_get_burn_in_time fail\n\r");
    }
if( EEPM_get_burn_in_target_time( burnin_target_time_read_cb ) == pdFALSE )
    {
    PRINTF("EEPM_get_burn_in_target_time fail\n\r");
    }
}

/*********************************************************************
*
* @public
* factory_create_task
*
* @brief function to create factory task
*
*
*********************************************************************/
static void factory_create_task
    (
    void
    )
{
if( pdPASS == xTaskCreate( factory_test_task, "factory_test_task", configMINIMAL_STACK_SIZE * 2, NULL, TASK_PRIO_FAC_TEST, NULL ) )
    {
    PRINTF("%s ok\r\n", "factory_test_task" );
    }
else
    {
    PRINTF("%s fail\r\n", "factory_test_task" );
    }
if( pdPASS == xTaskCreate( IOP_BurnIn_Task, "IOP_BurnIn_Task", configMINIMAL_STACK_SIZE * 2, NULL, TASK_PRIO_BURN_IN, NULL ) )
    {
    PRINTF("%s ok\r\n", "IOP_BurnIn_Task" );
    }
else
    {
    PRINTF("%s fail\r\n", "IOP_BurnIn_Task" );
    }
}


/*********************************************************************
*
* @private
* getGPIOValue
*
* @brief function to get GPIO value on given port and pin
*
* @param port gpio port
* @param pin  gpio pin
*
*********************************************************************/
static uint8_t getGPIOValue
    (
    uint8_t     port,
    uint8_t     pin,
    uint8_t   * output_lvl
    )
{
GPIO_Type * gpio;

if( port >= PORT_1 && port <= PORT_6 )
    {
    gpio = ( GPIO_Type * )( GPIO1_BASE + 0x4000 * ( port - PORT_1 ) );
    }
else if( port >= PORT_7 && port <= PORT_12 )
    {
    gpio = ( GPIO_Type * )( GPIO7_BASE + 0x4000 * ( port - PORT_7 ) );
    }
else if( port == PORT_13 )
    {
    gpio = ( GPIO_Type * )( GPIO13_BASE );
    }
else
    {
    return E_NOT_OK;;
    }
if( pin <= MAX_PIN_NUM )
    {
    *output_lvl = ( uint8_t )GPIO_PinRead( gpio, pin );
    return E_OK;
    }
return E_NOT_OK;;
}

/*********************************************************************
*
* @private
* setGPIOValue
*
* @brief function to set GPIO value on given port and pin
*
* @param port gpio port
* @param pin  gpio pin
* @param val  target value to set
*
*********************************************************************/
static uint8_t setGPIOValue
    (
    uint8_t     port,
    uint8_t     pin,
    uint8_t     val
    )
{
GPIO_Type * gpio;

if( port >= PORT_1 && port <= PORT_6 )
    {
    gpio = ( GPIO_Type * )( GPIO1_BASE + 0x4000 * ( port - PORT_1 ) );
    }
else if( port >= PORT_7 && port <= PORT_12 )
    {
    gpio = ( GPIO_Type * )( GPIO7_BASE + 0x4000 * ( port - PORT_7 ) );
    }
else if( port == PORT_13 )
    {
    gpio = ( GPIO_Type * )( GPIO13_BASE );
    }
else
    {
    return E_NOT_OK;;
    }
if( pin <= MAX_PIN_NUM )
    {
    GPIO_PinWrite( gpio, pin, val );
    return E_OK;
    }
return E_NOT_OK;
}

/*********************************************************************
*
* @private
* queueIsFull
*
* @brief function use to check if iop data queue is full or not
*
*********************************************************************/
int queueIsFull
    (
    void
    )
{
if( ( iopDataHead == iopDataTail + 1 ) ||
    ( iopDataHead == 0 && iopDataTail == IOP_MAX_QUEUE_SIZE - 1 ) )
    {
    return true;
    }
return false;
}

/*********************************************************************
*
* @private
* queueIsFull
*
* @brief function use to check if iop data queue is empty or not
*
*********************************************************************/
int queueIsEmpty
    (
    void
    )
{
if( iopDataHead == IOP_QUEUE_INVALID )
    {
    return true;
    }
return false;
}

/*********************************************************************
*
* @private
* storeCanData
*
* @brief function to store CAN data into an queue per request.
*
*********************************************************************/
void storeCanData
    (
    uint8_t*  canData
    )
{
if( !queueIsFull() )
    {
    if( iopDataHead == IOP_QUEUE_INVALID )
        {
        iopDataHead = 0;
        }
    iopDataTail = ( iopDataTail + 1 ) % IOP_MAX_QUEUE_SIZE;
    memcpy( &iopDataQueue[iopDataTail][0], &canData[0], 8 );
    }
}

/*********************************************************************
*
* @private
* sendCanData
*
* @brief function to send CAN data out through CAN bus.
*
*********************************************************************/
void sendCanData
    (
    void
    )
{
static can_tmd_t l_p_tmd =
    {
    .identifier = TX7_FACT_INSP1_GA_CAN0_ID,
    .dlc        = IL_CAN0_TX7_FACT_INSP1_GA_TXFRM_LEN,
    .handle     = IL_CAN0_TX7_FACT_INSP1_GA_TXFRM_HANDLE,
    .options    = CAN_TXMSG_STANDARD
    };

if( !queueIsEmpty() )
    {
    l_p_tmd.p_data = (uint8_t *)&iopDataQueue[iopDataHead];
    can_transmit( CAN_CONTROLLER_2, &l_p_tmd );
    if( iopDataHead == iopDataTail )
        {
        iopDataHead = IOP_QUEUE_INVALID;
        iopDataTail = IOP_QUEUE_INVALID;
        }
    else
        {
        iopDataHead = ( iopDataHead + 1 ) % IOP_MAX_QUEUE_SIZE;
        }
    }
}

/*********************************************************************
*
* @private
* packageIopToCanData
*
* @brief function to package iop to CAN data
*
*********************************************************************/
static void packageIopToCanData
    (
    void*  data_ptr,
    uint16_t data_len
    )
{
uint8_t iopData[128];
switch ( IOPInstId )
    {
    case IOP_CMND_DATA:
        memcpy( &iopData[0], data_ptr, data_len );
        iopToCanData( IOP_CMND_DATA, iopData, data_len );
        break;

    case IOP_EVNT_DATA:
        memcpy( &iopData[0], data_ptr, data_len );
        iopToCanData( IOP_EVNT_DATA, iopData, data_len );
        break;

    case IOP_HWM_TIME_DATA:
        memcpy( &iopData[0], data_ptr, data_len );
        iopToCanData( IOP_HWM_TIME_DATA, iopData, data_len );
        break;

    case IOP_UNIT_ID_DATA:
        memcpy( &iopData[0], data_ptr, data_len );
        iopToCanData( IOP_UNIT_ID_DATA, iopData, data_len );
        break;

    case IOP_PGM_DATA:
        memcpy( &iopData[0], data_ptr, data_len );
        iopToCanData( IOP_PGM_DATA, iopData, data_len );
        break;

    case IOP_PRODUCT_RQST_EXTEND:
        memcpy( &iopData[0], data_ptr, data_len );
        iopToCanData( IOP_PRODUCT_DATA, iopData, data_len );
        break;

    case IOP_BT_ADDR_DATA:
        memcpy( &iopData[0], data_ptr, data_len );
        iopToCanData( IOP_BT_ADDR_DATA, iopData, data_len );
        break;

    case IOP_AUTO_BURN_IN:
        memcpy( &iopData[0], data_ptr, data_len );
        iopToCanData( IOP_AUTO_BURN_IN, iopData, data_len );
        break;

    case IOP_MFI_INST_RESPONSE:
        memcpy( &iopData[0], data_ptr, data_len );
        iopToCanData( IOP_MFI_INST_RESPONSE, iopData, data_len );
        break;

    case IOP_ANDROID_FDR_DEL_FILE:
        memcpy( &iopData[0], data_ptr, data_len );
        iopToCanData( IOP_ANDROID_FDR_DEL_FILE, iopData, data_len );
        break;

    case IOP_ANDROID_FDR_CHK_FILE:
         memcpy( &iopData[0], data_ptr, data_len );
        iopToCanData( IOP_ANDROID_FDR_CHK_FILE, iopData, data_len );
        break;

    default:
        iopToCanData( IOP_INV_INST_ID, iopData, 0 );
        break;
    }
IOPDone = true;
}

/*********************************************************************
*
* @private
* iopProcInstCmd
*
* @brief function to process instument id command
*
*********************************************************************/
static void iopProcInstCmd
    (
    uint16_t  inst_id,
    uint8_t*  data,
    uint16_t  size
    )
{
//Irregular IOP
IOPInstId = inst_id;
IOPSubId  = 0;
IOPCaseId = 0;
IOPDone   = false;

switch( inst_id )
    {
    case IOP_CMND_DATA:
        {
        uint16_t cmd_id = 0;
        memcpy( &cmd_id, &data[0], sizeof( uint16_t ) );
        switch( cmd_id )
            {
            case IOP_DOWN_LOAD_TIME:
                {
                snvs_lp_srtc_datetime_t datetime;
                uint8_t iop_data[8];

                RTC_get_datetime( &datetime );

                iop_data[0] = datetime.month;
                iop_data[1] = datetime.day;
                iop_data[2] = ( datetime.year & LOW_BYTE_MASK );
                iop_data[3] = ( datetime.year >> SHIFT_ONE_BYTE );
                iop_data[4] = ( datetime.hour & LOW_BYTE_MASK ) ;
                iop_data[5] = ( datetime.hour >> SHIFT_ONE_BYTE );
                iop_data[6] = datetime.minute;
                iop_data[7] = datetime.second;

                IOPInstId = IOP_HWM_TIME_DATA;
                packageIopToCanData( &iop_data, sizeof( iop_data ) );
                }
                break;

            case IOP_DOWN_LOAD_ID:
                {
                if( EEPM_get_ESN( esn_read_cb ) == pdFALSE )
                    {
                    PRINTF("EEPM_get_ESN fail\n\r");
                    }
                esn_operation = IOP_ESN_OP_INVALID;
                IOPDone = true;
                }
                break;

            case IOP_CLR_NONVOL_UNPROTECTED_ONLY:
                {
                EEPM_set_operation_mode( OPERATION_MODE_FACTORY, NULL );
                EW_reset_to_factory_default();
                IOPDone = true;
                }
                break;

            case IOP_TEST_CAN:
                {
                CAN_ID_test_flag = data[2];
                packageIopToCanData( &data[0], BIT_24_DATA_LEN );
                }
                break;

            case IOP_PREP_POWER_OFF:
                {

                IOPDone = true;
                }
                break;

            case IOP_BT_GET_BDADDR:
                {
                const uint8_t* local_bd_addr = BT_get_local_device_address();
                uint8_t bd_addr[BT_DEVICE_ADDRESS_LEN] = { 0 };
                memcpy( bd_addr, local_bd_addr, BT_DEVICE_ADDRESS_LEN );

                IOPInstId = IOP_BT_ADDR_DATA;
                packageIopToCanData( &bd_addr, BT_DEVICE_ADDRESS_LEN );
                IOPDone = true;
                }
                break;

            case IOP_BT_POWER_ON:
                {
                BT_set_enable_state( true );
                IOPDone = true;
                }
                break;

            case IOP_BT_POWER_OFF:
                {
                BT_set_enable_state( false );
                IOPDone = true;
                }
                break;

            case IOP_BT_SET_TEST_MODE:
                {
                BT_set_test_mode( true );
                IOPDone = true;
                }
                break;

            case IOP_BT_GET_TEST_MODE:
                {
                uint8_t data[8] = { 0x8C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00  };
                data[2] = BT_get_test_mode();

                IOPInstId = IOP_EVNT_DATA;
                packageIopToCanData( &data, sizeof( data ) );
                IOPDone = true;
                }
                break;

            case IOP_BT_CLEAR_PAIRINGS:
                {
                uint8_t num_paired_devices = 0;
                BT_device_info_t device_info = { 0 };
                if( BT_STATUS_OK == BT_get_num_paired_devices( &num_paired_devices ) )
                    {
                    for( uint8_t i = 0; i < num_paired_devices; ++i )
                        {
                        if( BT_STATUS_OK == BT_get_paired_device_info( 0, &device_info ) )
                            {
                            BT_delete_paired_device( device_info.bd_addr );
                            }
                        }
                    }
                IOPDone = true;
                }
                break;

            default:
                IOPDone = true;
                break;
            }
        }
        break;

    case IOP_HWM_TIME_DATA:
        {
        snvs_lp_srtc_datetime_t datetime;

        datetime.month  = data[0];
        datetime.day    = data[1];
        datetime.year   = data[2] + ( data[3] << SHIFT_ONE_BYTE );
        datetime.hour   = data[4] + ( data[5] << SHIFT_ONE_BYTE );
        datetime.minute = data[6];
        datetime.second = data[7];

        RTC_set_dateTime( &datetime );
        IOPDone = true;
        }
        break;

    case IOP_UNIT_ID_DATA:
        {
        memcpy( &esn_id, &data[0], sizeof( uint32_t ) );
        if( esn_id == ESN_REWRITE_ID )
            {
            if( EEPM_set_ESN( esn_id, esn_write_cb ) == pdFALSE )
                {
                PRINTF("EEPM_set_ESN fail\n\r");
                }
            }
        else
            {
            esn_operation = IOP_ESN_OP_WRITE;
            if( EEPM_get_ESN( esn_read_cb ) == pdFALSE )
                {
                PRINTF("EEPM_get_ESN fail\n\r");
                }
            }
        }
        break;
    case IOP_SYC_MODE_DATA:
        {
        uint8_t iopSubId = data[0];
        switch( iopSubId )
            {
            case SYC_MODE_NORMAL:
                {

                }
                break;
            case SYC_MODE_TEST:
                {
                WDG_switch( false ); // Disable WDG pulse, this will result to hardware reset
                }
                break;
            }
        IOPDone = true;
        break;
        }
    case IOP_PRODUCT_RQST_EXTEND:
        {
        uint8_t   iop_Data[66] = { 0 };
        uint16_t  sw_version;
        uint8_t   sw_version_ascii[5];
        uint8_t   hw_version[2];

        sw_version          = SW_VERSION;
        sw_version_ascii[0] = ASCII_BYTE_OFFSET + ( SW_VERSION / 1000 );
        sw_version_ascii[1] = ASCII_BYTE_OFFSET + ( SW_VERSION % 1000 / 100 );
        sw_version_ascii[2] = ASCII_BYTE_DOT;
        sw_version_ascii[3] = ASCII_BYTE_OFFSET + ( SW_VERSION % 100 / 10 );
        sw_version_ascii[4] = ASCII_BYTE_OFFSET + ( SW_VERSION % 10 );
        hw_version[0]       = ASCII_BYTE_OFFSET + ( PERIPHERAL_get_hw_id() / 10 );
        hw_version[1]       = ASCII_BYTE_OFFSET + ( PERIPHERAL_get_hw_id() % 10 );

        memcpy( &iop_Data[0],  &product_id, sizeof( product_id ) );
        memcpy( &iop_Data[2],  &sw_version, sizeof( sw_version ) );
        memcpy( &iop_Data[4],  &product_string_line1, sizeof( product_string_line1 ) );
        memcpy( &iop_Data[12], &sw_version_ascii, sizeof( sw_version_ascii ) );
        iop_Data[17] = ASCII_BYTE_NEXT_LINE;
        memcpy( &iop_Data[18], &product_string_line2, sizeof( product_string_line2 ) );
        memcpy( &iop_Data[33], &hw_version[0], sizeof( hw_version[0] ) );
        memcpy( &iop_Data[34], &hw_version[1], sizeof( hw_version[1] ) );
        iop_Data[35] = ASCII_BYTE_NEXT_LINE;
        memcpy( &iop_Data[36], &product_string_line3, sizeof( product_string_line3 ) );

        packageIopToCanData( &iop_Data[0], sizeof( iop_Data ) );
        }
        break;

    case IOP_BT_SET_BDADDR:
        {
        uint8_t* bd_addr = data;
        BT_set_local_device_address( bd_addr );
        IOPDone = true;
        }
        break;

    case IOP_BT_TX_CARRIER_FREQ:
        {
        BT_tx_channel_type_e channel_type = data[0];
        BT_set_tx_carrier_mode( true, channel_type );
        IOPDone = true;
        }
        break;

    case IOP_MFI_START_COPROCESSOR_TEST:
        {
        BT_spp_read_mfi_auth_chip_info();
        IOPDone = true;
        }
        break;

    case IOP_AUTO_BURN_IN:
        {
        switch( data[0] )
            {
            case IOP_AUTO_BURN_IN_OPERATION:
                {
                switch( data[1] )
                    {
                    case IOP_AUTO_BURN_IN_OPERATION_RESET_ALL:
                        IOPDone = true;
                        break;

                    case IOP_AUTO_BURN_IN_OPERATION_SET_START_FLAG:
                        {
                        if( EEPM_set_start_burn_in( data[2], burnin_start_write_cb ) == pdFALSE )
                            {
                            PRINTF("EEPM_set_start_burn_in fail\n\r");
                            }
                        else
                            {
                            if( data[2] == BURN_IN_START_FLAG )
                                {
                                burnInResult = BURN_IN_FAIL;
                                EEPM_set_burn_in_result( burnInResult, burnin_result_write_cb );
                                }
                            else
                                {
                                EEPM_set_burn_in_time( 0, burnin_time_write_cb );
                                EW_quit_test();
                                }
                            }
                        }
                        break;

                    case IOP_AUTO_BURN_IN_OPERATION_GET_RESULT:
                        {
                        if( EEPM_get_burn_in_result( burnin_result_read_cb ) == pdFALSE )
                            {
                            PRINTF("EEPM_get_burn_in_result fail\n\r");
                            }
                        }
                        break;
                    default:
                        IOPDone = true;
                        break;
                    }
                }
                break;

            case IOP_AUTO_BURN_IN_SET_TARTGET_TIME:
                {
                uint32_t req_burnin_time = 0;

                req_burnin_time = ( data[1] ) +
                                  ( data[2] << SHIFT_ONE_BYTE ) +
                                  ( data[3] << SHIFT_TWO_BYTES ) +
                                  ( data[4] << SHIFT_THREE_BYTES );

                EEPM_set_burn_in_target_time( req_burnin_time, burnin_target_time_write_cb );
                }
                break;

            case IOP_AUTO_BURN_IN_GET_ELAPSED_TIME:
                {
                if( EEPM_get_burn_in_time( burnin_time_read_return_cb ) == pdFALSE )
                    {
                    PRINTF("EEPM_get_burn_in_time fail\n\r");
                    }
                }
                break;

            default:
                IOPDone = true;
                break;
            }
        }
        break;

    case IOP_TEST_MODE_SWITCH_PAGE:
        {
        if( data[0] == 0 )
            {
            EW_quit_test();
            }
        else
            {
            EW_test_display_pattern( data[0] );
            }
        IOPDone = true;
        }
        break;

    case IOP_ANDROID_FDR_DEL_FILE:
        {
        EEPM_set_operation_mode( OPERATION_MODE_NORMAL, operation_mode_write_cb );
        }
        break;

    case IOP_ANDROID_FDR_CHK_FILE:
        {
        EEPM_get_operation_mode( operation_mode_read_cb );
        }
        break;

    default:
        IOPDone = true;
        break;
    }
}

/*********************************************************************
*
* @private
* iopProcInstCmd
*
* @brief function to process VIM id command
*
*********************************************************************/
static void iopProcVIMCaseCmd
    (
    uint16_t case_id,
    uint8_t* data,
    uint16_t size
    )
{
//Regular IOP
IOPInstId  = IOP_PGM_DATA;
IOPSubId = ( case_id >> SHIFT_ONE_BYTE ) | ( case_id & LOW_BYTE_MASK ) << SHIFT_ONE_BYTE ;
IOPDone    = false;

switch( IOPSubId )
    {
    case IOP_VIM_PKT_GPIO_CMD:
        {
        uint8 rtn_arry[6] = { 0, IOP_VIM_PKT_GPIO_CMD, data[0], data[1], data[2], E_NOT_OK };
        rtn_arry[5] = setGPIOValue( data[0], data[1], data[2] );
        packageIopToCanData( &rtn_arry, sizeof( rtn_arry ) );
        }
        break;

    case IOP_VIM_PKT_ADC_CHANNEL_CMD:
        {
        uint16_t voltage = DATA_INVALID_2BYTES;
        int32_t  temperature = DATA_INVALID_4BYTES;
        uint8_t  adc_instance = data[0];
        uint8_t  adc_channel  = data[1];
        uint8_t  rtn_arry[8]  = { 0, IOP_VIM_PKT_ADC_CHANNEL_DATA, data[0], data[1], 0, 0, 0, 0 };

        if( adc_instance == 1 ) // ADC1
            {
            switch( adc_channel )
                {
                case ADC_CHANNEL_NUM_VBATT_SEN:
                    voltage = PERIPHERAL_adc_get_vbatt();
                    break;
                case ADC_CHANNEL_NUM_PCBA_TEMP:
                    temperature = PERIPHERAL_adc_get_pcba_ntc_converted();
                    temperature += ABSOLUTE_TEMP_OFFSET;
                    break;
                case ADC_CHANNEL_NUM_TFT_TEMP:
                    temperature = PERIPHERAL_adc_get_tft_ntc_converted();
                    temperature += ABSOLUTE_TEMP_OFFSET;
                    break;
                default:
                    break;
                }
            }
        if( voltage != DATA_INVALID_2BYTES )
            {
            rtn_arry[4] = voltage & LOW_BYTE_MASK;
            rtn_arry[5] = voltage >> SHIFT_ONE_BYTE;
            }
        else if( temperature != DATA_INVALID_4BYTES )
            {
            rtn_arry[4] = ( temperature & 0x000000FF );
            rtn_arry[5] = ( temperature & 0x0000FF00 ) >> SHIFT_ONE_BYTE;
            rtn_arry[6] = ( temperature & 0x00FF0000 ) >> SHIFT_TWO_BYTES;
            rtn_arry[7] = ( temperature & 0xFF000000 ) >> SHIFT_THREE_BYTES;
            }
        packageIopToCanData( &rtn_arry, sizeof( rtn_arry ) );
        }
        break;

    case IOP_VIM_PKT_PWM_OUTPUT_CMD:
        {
        uint8_t rtn_arry[2] = { data[0], data[1] };
        PERIPHERAL_pwm_set_display_dutycycle( data[1] );
        packageIopToCanData( &rtn_arry, sizeof( rtn_arry ) );
        }
        break;

    /* GPIO read command for Factory test */
    case IOP_VIM_PKT_GPIO_STATUS_CMD:
        {
        uint8 rtn_arry[6] = { 0, IOP_VIM_PKT_GPIO_STATUS_DATA, data[0], data[1], STD_LOW, E_NOT_OK };
        rtn_arry[5] = getGPIOValue( data[0], data[1], &rtn_arry[4] );
        packageIopToCanData( &rtn_arry, sizeof( rtn_arry ) );
        }
        break;

    case IOP_VIM_PKT_PRODUCT_SKU_CMD:
        {
        uint8 type = data[0];
        uint8 rtn_arry[7];
        memset( &rtn_arry, DATA_INVALID_BYTE, sizeof( rtn_arry ) );
        rtn_arry[0] = 0;
        rtn_arry[1] = IOP_VIM_PKT_PRODUCT_SKU_DATA;
        rtn_arry[2] = type;
        switch( type )
            {
            case IOP_PRODUCT_HW_ID:
                {
                get_hw_id( &rtn_arry[3] );
                packageIopToCanData( &rtn_arry, sizeof( rtn_arry ) );
                }
                break;

            case IOP_PRODUCT_SKU_ID:
                {
                get_sku_id( &rtn_arry[3] );
                packageIopToCanData( &rtn_arry, sizeof( rtn_arry ) );
                }
                break;
            default:
                {
                packageIopToCanData( &rtn_arry, sizeof( rtn_arry ) );
                IOPDone = true;
                }
                break;
            }
        }
        break;

    case IOP_BT_ACCEPT_NEXT_PAIR_REQUEST:
        {
        BT_set_auto_pairing_once();
        IOPDone = true;
        }
        break;

    case IOP_BT_SET_TO_ACTIVE:
        {
        BT_set_discoverable_state( true );
        IOPDone = true;
        }
        break;

    case IOP_VIM_PKT_QRCODE_CMD:
        {
        uint8_t qrcode_fused_data_1[QRCODE_FUSED_DATA_LENGTH] = { 0 };
        uint8_t qrcode_fused_data_2[QRCODE_FUSED_DATA_LENGTH] = { 0 };
        uint8_t qrcode_fused_data_3[QRCODE_FUSED_DATA_LENGTH] = { 0 };

        memcpy( qrcode_fused_data_1, &data[0], QRCODE_FUSED_DATA_LENGTH );
        memcpy( qrcode_fused_data_2, &data[8], QRCODE_FUSED_DATA_LENGTH );
        memcpy( qrcode_fused_data_3, &data[16], QRCODE_FUSED_DATA_LENGTH );

        qrcode_write_status = QRCODE_STATUS_INVALID;

        EEPM_set_qrcode_fused_data_1( qrcode_fused_data_1, fused_data_1_write_cb );
        EEPM_set_qrcode_fused_data_2( qrcode_fused_data_2, fused_data_2_write_cb );
        EEPM_set_qrcode_fused_data_3( qrcode_fused_data_3, fused_data_3_write_cb );
        }
        break;

    default:
        IOPDone = true;
        break;
    }
}

/*********************************************************************
*
* @private
* packageIopData
*
* @brief Package function to transfer the Marine N2K raw data to IOP format
* data. This function is called in CanToIopParser when the parsing is done.
*
*********************************************************************/
static void packageIopData
    (
    uint8_t* rawData
    )
{
uint16_t  iop_InstID;
uint16_t  iop_SubID;

memcpy( &iop_InstID, &rawData[IOP_VIM_COMM_INST_ID_MSB_POS], sizeof( uint16_t ) );

// Handle by MCU
if( iop_InstID == IOP_PGM_DATA )
    {
    if( IOPDone == true )
        {
        memcpy( &iop_SubID, &rawData[IOP_VIM_COMM_SUB_ID_MSB_POS], sizeof( uint16_t ) );
        iopProcVIMCaseCmd( iop_SubID, &rawData[IOP_VIM_COMM_CASE_ID_MSB_POS], recordDataSize -  8 );
        }
    }
else
    {
    if( IOPDone == true )
        {
        iopProcInstCmd( iop_InstID, &rawData[IOP_VIM_COMM_SUB_ID_MSB_POS], recordDataSize - 6  );
        }
    }
}

/*********************************************************************
*
* @private
* CanToIopParser
*
* @brief Parser function to transfer the specific CAN format data from GND10
* and send it to A12.
*
* This function is called in ft_hook_receive when there's CAN data
* with Factory's CAN ID comes in.
*
*********************************************************************/
static void CanToIopParser
    (
    const uint8_t* canRawData
    )
{
uint8_t sequenceId;
uint8_t dataSize;

sequenceId = canRawData[0];
// If this is the first packet
if( sequenceId == 0 )
    {
    dataSize = firstCanDataLength;
    recordSequenceId = sequenceId + 1;
    recordDataSize = canRawData[1];

    memcpy( &recordData[0], &canRawData[2], dataSize );
    if( recordDataSize <= dataSize )
        {
        packageIopData( &recordData[0] );
        recordSequenceId = 0;
        }
    }
else
    {
    if( sequenceId == recordSequenceId )
        {
        dataSize = otherCanDataLength;
        recordSequenceId = sequenceId + 1;

        memcpy( &recordData[firstCanDataLength + ( sequenceId - 1 ) * otherCanDataLength], &canRawData[1], dataSize );
        if( ( firstCanDataLength + otherCanDataLength * sequenceId ) >= recordDataSize )
            {
            packageIopData( &recordData[0] );
            recordSequenceId = 0;
            }
        }
    }
}


/*********************************************************************
*
* @private
* iopToCanData
*
* @brief Package function to package IOP raw data to specific CAN message.
* data.
*
* This function is called in packageIopData if the factory related command
* needs to send back iop data.
*
*********************************************************************/
void iopToCanData
    (
    uint16_t  iopid,
    uint8_t*  iopRawData,
    uint8_t   iopDataSize
    )
{
uint8_t firstCanData[8];
uint8_t otherCanData[8];

firstCanData[0] = 0x00;
firstCanData[1] = iopDataSize + firstCanDataLength;    // Total Date Size
firstCanData[2] = 0xE5;
firstCanData[3] = 0x98;
firstCanData[4] = ( iopid & LOW_BYTE_MASK );
firstCanData[5] = ( iopid >> 8 );
firstCanData[6] = 0x02;
firstCanData[7] = 0x02;

storeCanData( &firstCanData[0] );

if( iopDataSize > 0 )
    {
    uint8_t totalRound = ( iopDataSize / otherCanDataLength ) + 1;
    uint8_t remainByte = otherCanDataLength - ( iopDataSize % otherCanDataLength );
    for( int i = 0; i < totalRound; i++ )
        {
        otherCanData[0] = i + 1;
        memcpy( &otherCanData[1], &iopRawData[0 + i * otherCanDataLength] , otherCanDataLength );
        if( i == ( totalRound - 1 ) )
            {
            memset( &otherCanData[8 - remainByte], 0xFF, remainByte );
            }
        storeCanData( &otherCanData[0] );
        }
    }
}

/*********************************************************************
*
* @private
* esn_read_cb
*
* @brief callback function for ESN read operation.
*
*********************************************************************/
static void esn_read_cb
    (
    bool    status,
    void*   data
    )
{
memcpy( &EEPM_esn_id, data, BIT_32_DATA_LEN );

if( status == pdTRUE )
    {
    if( esn_operation == IOP_ESN_OP_WRITE )
        {
        IOPInstId = IOP_UNIT_ID_DATA;
        if( EEPM_esn_id == ESN_REWRITE_ID )
            {
            if( EEPM_set_ESN( esn_id, esn_write_cb ) == pdFALSE )
                {
                PRINTF("EEPM_set_ESN fail\n\r");
                }
            esn_operation = IOP_ESN_OP_INVALID;
            }
        else
            {
            packageIopToCanData( &EEPM_esn_id, BIT_32_DATA_LEN );
            }
        }
    else
        {
        IOPInstId = IOP_UNIT_ID_DATA;
        packageIopToCanData( &EEPM_esn_id, BIT_32_DATA_LEN );
        }
    }
}

/*********************************************************************
*
* @private
* esn_write_cb
*
* @brief callback function for ESN write operation.
*
*********************************************************************/
static void esn_write_cb
    (
    bool    status,
    void*   data
    )
{
IOPInstId = IOP_UNIT_ID_DATA;
packageIopToCanData( &esn_id, BIT_32_DATA_LEN );
}

/*********************************************************************
*
* @private
* get_hw_id
*
* @brief get HW_ID depends on the gpio input
*
*********************************************************************/
static uint8 get_hw_id
    (
    uint8 * hw_id_data
    )
{
uint8 hw_id_dec = 0;

getGPIOValue( PORT_8, 18, &hw_id_data[0] ); // HW_ID3
getGPIOValue( PORT_8, 15, &hw_id_data[1] ); // HW_ID2
getGPIOValue( PORT_8, 14, &hw_id_data[2] ); // HW_ID1
getGPIOValue( PORT_8, 13, &hw_id_data[3] ); // HW_ID0

hw_id_dec = ( hw_id_data[0] << BIT_24_DATA_LEN ) +
            ( hw_id_data[1] << BIT_16_DATA_LEN ) +
            ( hw_id_data[2] << BIT_8_DATA_LEN  ) +
            ( hw_id_data[3] );

return hw_id_dec;
}

/*********************************************************************
*
* @private
* get_sku_id
*
* @brief get SKU_ID depends on the gpio input
*
*********************************************************************/
static void get_sku_id
    (
    uint8 * sku_id_data
    )
{
getGPIOValue( PORT_8, 26, &sku_id_data[0] ); // SKU_ID3
getGPIOValue( PORT_8, 22, &sku_id_data[1] ); // SKU_ID2
getGPIOValue( PORT_8, 20, &sku_id_data[2] ); // SKU_ID1
getGPIOValue( PORT_8, 19, &sku_id_data[3] ); // SKU_ID0
}

/*********************************************************************
*
* @private
* burnin_result_read_cb
*
* @brief callback function for burn in result read operation.
*
*********************************************************************/
static void burnin_result_read_cb
    (
    bool    status,
    void*   data
    )
{
if( status == TRUE )
    {
    uint8_t iop_Data[3];
    iop_Data[0] = IOP_AUTO_BURN_IN_OPERATION;
    iop_Data[1] = IOP_AUTO_BURN_IN_OPERATION_GET_RESULT;

    memcpy( &burnInResult, data, BIT_8_DATA_LEN );
    iop_Data[2] = burnInResult;

    packageIopToCanData( &iop_Data, sizeof( iop_Data ) );
    }
}

/*********************************************************************
*
* @private
* burnin_result_write_cb
*
* @brief callback function for burn in result read operation.
*
*********************************************************************/
static void burnin_result_write_cb
    (
    bool    status,
    void*   data
    )
{
if( status == TRUE )
    {
    PRINTF( "write burninresult = %d\r\n", (uint8 *)data );
    }
}

/*********************************************************************
*
* @private
* burnin_start_read_cb
*
* @brief callback function for burn in start flags read operation.
*
*********************************************************************/
static void burnin_start_read_cb
    (
    bool    status,
    void*   data
    )
{
if( status == TRUE )
    {
    memcpy( &burnInState, data, BIT_8_DATA_LEN );
    }
}

/*********************************************************************
*
* @private
* burnin_start_write_cb
*
* @brief callback function for burn in start flags write operation.
*
*********************************************************************/
static void burnin_start_write_cb
    (
    bool    status,
    void*   data
    )
{
if( status == TRUE )
    {
    uint8_t iop_data[3] ;
    memcpy( &burnInState, data, BIT_8_DATA_LEN );
    PRINTF( "write burnin start flag = %d\r\n", burnInState );

    iop_data[0] = IOP_AUTO_BURN_IN_OPERATION;
    iop_data[1] = IOP_AUTO_BURN_IN_OPERATION_SET_START_FLAG;
    iop_data[2] = burnInState;
    packageIopToCanData( &iop_data, sizeof( iop_data ) );
    }
}

/*********************************************************************
*
* @private
* burnin_time_read_cb
*
* @brief callback function for burn in time read operation.
*
*********************************************************************/
static void burnin_time_read_cb
    (
    bool    status,
    void*   data
    )
{
if( status == TRUE )
    {
    memcpy( &burnInElapseTime, data, BIT_32_DATA_LEN );
    }
}

/*********************************************************************
*
* @private
* burnin_time_read_cb
*
* @brief callback function for burn in time read operation and IOP return.
*
*********************************************************************/
static void burnin_time_read_return_cb
    (
    bool    status,
    void*   data
    )
{
if( status == TRUE )
    {
    uint8_t iop_Data[5];
    iop_Data[0] = IOP_AUTO_BURN_IN_GET_ELAPSED_TIME;
    memcpy( &iop_Data[1], data, BIT_32_DATA_LEN );

    packageIopToCanData( &iop_Data, sizeof( iop_Data ) );
    }
}

/*********************************************************************
*
* @private
* burnin_time_write_cb
*
* @brief callback function for burn in time write operation.
*
*********************************************************************/
static void burnin_time_write_cb
    (
    bool    status,
    void*   data
    )
{
if( status == TRUE )
    {
    uint32_t burn_in_elapse_time;
    memcpy( &burn_in_elapse_time, data, BIT_32_DATA_LEN );
    PRINTF( "write burnin time = %d\r\n", burn_in_elapse_time );
    }
else
    {
     PRINTF( "write burnin time fail" );
    }
}

/*********************************************************************
*
* @private
* burnin_target_time_read_cb
*
* @brief callback function for burn in target time read operation.
*
*********************************************************************/
static void burnin_target_time_read_cb
    (
    bool    status,
    void*   data
    )
{
if( status == TRUE )
    {
    memcpy( &burnInTargetTime, data, BIT_32_DATA_LEN );
    }
}

/*********************************************************************
*
* @private
* burnin_target_time_write_cb
*
* @brief callback function for burn in target time write operation.
*
*********************************************************************/
static void burnin_target_time_write_cb
    (
    bool    status,
    void*   data
    )
{
uint8_t  iop_Data[6];
iop_Data[0] = IOP_AUTO_BURN_IN_SET_TARTGET_TIME;

if( status == TRUE )
    {
    uint32_t req_burnin_time = 0;
    memcpy( &req_burnin_time, data, BIT_32_DATA_LEN );
    if( req_burnin_time >= BURN_IN_QUAL_MIN_TIME && req_burnin_time <= BURN_IN_QUAL_MAX_TIME )
        {
        burnInTargetTime = req_burnin_time;
        iop_Data[5] = pdTRUE;
        PRINTF( "write burnin target time = %d\r\n", burnInTargetTime );
        }
    else
        {
        iop_Data[5] = pdFALSE;
        }
    }
else
    {
    PRINTF( "write burnin time fail" );
    iop_Data[5] = pdFALSE;
    }
memcpy( &iop_Data[1], data, BIT_32_DATA_LEN );
packageIopToCanData( &iop_Data, sizeof( iop_Data ) );
}

/*********************************************************************
*
* @private
* operation_mode_write_cb
*
* @brief callback function for operation mode write operation.
*
*********************************************************************/
static void operation_mode_write_cb
    (
    bool    status,
    void*   data
    )
{
if( status == TRUE )
    {
    uint8_t operation_mode;
    uint8_t iop_Data;
    memcpy( &operation_mode, data, BIT_8_DATA_LEN );
    if( operation_mode == OPERATION_MODE_NORMAL )
        {
        iop_Data = FACTORY_RST_FLAG_EXIST;
        }
    else if( operation_mode == OPERATION_MODE_FACTORY )
        {
        iop_Data = FACTORY_RST_FLAG_NEXIST;
        }

    packageIopToCanData( &iop_Data, sizeof( iop_Data ) );
    }
}

/*********************************************************************
*
* @private
* operation_mode_read_cb
*
* @brief callback function for operation mode read operation.
*
*********************************************************************/
static void operation_mode_read_cb
    (
    bool    status,
    void*   data
    )
{
if( status == TRUE )
    {
    uint8_t iop_Data;
    uint8_t operation_mode;
    memcpy( &operation_mode, data, BIT_8_DATA_LEN );

    if( operation_mode == OPERATION_MODE_NORMAL )
        {
        iop_Data = FACTORY_RST_FLAG_EXIST;
        }
    else if( operation_mode == OPERATION_MODE_FACTORY )
        {
        iop_Data = FACTORY_RST_FLAG_NEXIST;
        }

    packageIopToCanData( &iop_Data, sizeof( iop_Data ) );
    }
}

/*********************************************************************
*
* @private
* fused_data_1_write_cb
*
* @brief callback function for qrcode fused data 1 write operation.
*
*********************************************************************/
static void fused_data_1_write_cb
    (
    bool    status,
    void*   data
    )
{
if( status == TRUE )
    {
    qrcode_write_status |= QRCODE_STATUS_FUSED1_OK;
    }
}

/*********************************************************************
*
* @private
* fused_data_2_write_cb
*
* @brief callback function for qrcode fused data 2 write operation.
*
*********************************************************************/
static void fused_data_2_write_cb
    (
    bool    status,
    void*   data
    )
{
if( status == TRUE )
    {
    qrcode_write_status |= QRCODE_STATUS_FUSED2_OK;
    }
}

/*********************************************************************
*
* @private
* fused_data_3_write_cb
*
* @brief callback function for qrcode fused data 3 write operation.
*
*********************************************************************/
static void fused_data_3_write_cb
    (
    bool    status,
    void*   data
    )
{
uint8 rtn_arry[3];
rtn_arry[0] = IOP_VIM_PKT_QRCODE_CMD >> SHIFT_ONE_BYTE;
rtn_arry[1] = IOP_VIM_PKT_QRCODE_CMD & LOW_BYTE_MASK;
rtn_arry[2] = E_NOT_OK;

if( status == TRUE )
    {
    qrcode_write_status |= QRCODE_STATUS_FUSED3_OK;
    }
if( qrcode_write_status == QRCODE_STATUS_SUCCESS )
    {
    rtn_arry[2] = E_OK;
    EW_notify_system_event_received( EnumSystemRxEventUNIT_ID_UPDATED );
    }
packageIopToCanData( &rtn_arry, sizeof( rtn_arry ) );
}
/*********************************************************************
*
* @private
* IOP_BurnIn_Task
*
* @brief This task manages the burn in related operation and write/read
* burn in parameter to control the overall burn in stage in factory
*
*********************************************************************/
static void IOP_BurnIn_Task
    (
    void* arg
    )

{
static int32_t curr_burnInVimTemp = 0;

while( TRUE )
    {
    if( IOP_BURNIN_STATE_SET == burnInState )
        {
        burnInStage = IOP_BURNIN_STAGE_START;
        burnInState = IOP_BURNIN_STATE_VALID;
        EW_start_burn_in();
        }
    else if( IOP_BURNIN_STATE_NONE == burnInState )
        {
        burnInStage = IOP_BURNIN_STAGE_NOT_START;
        }

    switch( burnInStage )
        {
        case IOP_BURNIN_STAGE_NOT_START:
            {
            if( burnInPassFlag )
                {
                EW_update_burn_in_time( burnInTime );
                EW_show_burn_in_result( true );
                }
            }
            break;
        case IOP_BURNIN_STAGE_START:
            {
            curr_burnInVimTemp = PERIPHERAL_adc_get_pcba_ntc_converted();
            if( curr_burnInVimTemp >= BURN_IN_QUAL_TEMP )
                {
                burnInStage = IOP_BURNIN_STAGE_RUNNING;
                }
            }
            break;
        case IOP_BURNIN_STAGE_RUNNING:
            {
            curr_burnInVimTemp = PERIPHERAL_adc_get_pcba_ntc_converted();
            if( curr_burnInVimTemp >= BURN_IN_QUAL_TEMP )
                {
                burnInTime++;
                EW_update_burn_in_time( burnInTime );
                if( burnInTime > burnInElapseTime )
                    {
                    EEPM_set_burn_in_time( burnInTime, burnin_time_write_cb );
                    burnInElapseTime = burnInTime;
                    }
                if( burnInTime >= burnInTargetTime )
                    {
                    burnInResult = BURN_IN_SUCCESS;
                    EEPM_set_burn_in_result( burnInResult, burnin_result_write_cb );
                    burnInState = IOP_BURNIN_STATE_NONE;
                    EEPM_set_start_burn_in( FALSE, burnin_start_write_cb );
                    burnInStage = IOP_BURNIN_STAGE_PASS;
                    EW_show_burn_in_result( true );
                    burnInPassFlag = TRUE;
                    }
                }
            else
                {
                burnInTime = 0;
                }
            }
            break;
        case IOP_BURNIN_STAGE_FAIL:
        case IOP_BURNIN_STAGE_PASS:
            {

            }
            break;

        }
    vTaskDelay( pdMS_TO_TICKS( BURN_IN_TASK_TIME ) );
    }
vTaskDelete( NULL );
}

static void sendCanTestData
    (
    void
    )
{
static uint8_t test_count   = 0;
static uint16_t test_period_counter = 0;
static uint8_t l_tx_data[8] = { 0xAA, 0xAA, 0xAA, 0xAA, 0x55, 0x55, 0x55, 0x55 };
static can_tmd_t l_p_tmd =
    {
    .dlc        = IL_CAN0_TX_DIAG_RELATED_TXFRM_LEN,
    .handle     = IL_CAN0_TX_DIAG_RELATED_TXFRM_HANDLE,
    .options    = CAN_TXMSG_STANDARD,
    .p_data     = l_tx_data,
    };

if( CAN_ID_test_flag )
    {
    l_p_tmd.identifier = CAN_test_ID[test_count];
    if( test_period_counter % CANID_TEST_SEND_CNT == 0 )
        {
        test_count ++;
        if( test_period_counter < CANID_TEST_MAX_TIME_CNT * CANID_TEST_MAX_ROUND )
            {
            can_transmit( CAN_CONTROLLER_2, &l_p_tmd );
            }
        else
            {
            CAN_ID_test_flag = false;
            test_period_counter = 0;
            }
        }
    if( test_count == ( sizeof( CAN_test_ID ) / sizeof( CAN_test_ID[0] ) ) )
        {
        test_count = 0;
        }
    test_period_counter ++;
    }
else
    {
    test_count = 0;
    test_period_counter = 0;
    }
}

/*********************************************************************
*
* @private
* factory_test_task
*
* @brief This task scans for the CAN message that stored in the queue
* if available and send out in the period of 10ms
*
*********************************************************************/
static void factory_test_task
    (
    void* arg
    )
{
while( true )
    {
    /* Periodically send CAN data that stored in the queue */
    sendCanData();

    sendCanTestData();

    vTaskDelay( pdMS_TO_TICKS( FACTORY_TASK_PERIOD_MS ) );
    }
vTaskDelete( NULL );
}

/*********************************************************************
*
* @private
* ft_hook_receive
*
* @brief hook function to receive data from can dll layer
*
*********************************************************************/
void ft_hook_receive
    (
    can_hw_inst_t       const hw_inst, //!< [in] CAN hardware instance
    can_rmd_t   const * const p_rmd    //!< [in] pointer to received message
    )
{
CanToIopParser( &p_rmd->data[0] );
}

/*********************************************************************
*
* @public
* FACTORY_handle_mfi_auth_chip_diag_result
*
* @brief Handle the MFi authentication chip diagnostic result
*
*********************************************************************/
void FACTORY_handle_mfi_auth_chip_diag_result
    (
    const bool result
    )
{
uint8_t success = result;

IOPInstId = IOP_MFI_INST_RESPONSE;
packageIopToCanData( &success, sizeof( uint8_t ) );
}

#ifdef __cplusplus
}
#endif
