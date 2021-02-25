/*********************************************************************
* @file
* vi_rx.c
*
* @brief
* Vehicle information module - process received data
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
#include "ewrte.h"
#include "fsl_debug_console.h"
#include "vi_priv.h"
#include "VI_pub.h"
#include "EW_pub.h"

/*--------------------------------------------------------------------
                           LITERAL CONSTANTS
--------------------------------------------------------------------*/
#define VEHICLE_DRIVER_DISTRACTION_MODE_LIMIT       ( 3 ) /* km/h */

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
static rx_ecu_info_struct           rx_ecu_info;
static rx_brightness_control_struct rx_brightness_control;
static rx_unit_setting_struct       rx_unit_setting;
static rx_fuel_rate_struct          rx_fuel_rate;
static rx_odo_trip_struct           rx_odo_trip;
static rx_vehicle_info_struct       rx_vehicle_info;
static rx_heater_status_struct      rx_grip_warmer_status;
static rx_heater_status_struct      rx_seat_heater_status;
static rx_maintenance_trip_struct   rx_maintenance_trip;
static rx_tacho_setting_struct      rx_tacho_setting;

static uint32_t rx_vehicle_supported_features = 0;
static uint8_t  rx_vehicle_supported_features_response = VEHICLE_NEGATIVE_RESPONSE_ID;
static uint8_t  rx_vehicle_info_reset_response = VEHICLE_NEGATIVE_RESPONSE_ID;

static bool     is_dd_mode_activated = false;

/*--------------------------------------------------------------------
                                MACROS
--------------------------------------------------------------------*/
#define set_bit( data, offset )   ( ( data ) |=  ( 1 << ( offset ) ) )
#define clear_bit( data, offset ) ( ( data ) &= ~( 1 << ( offset ) ) )

/*--------------------------------------------------------------------
                              PROCEDURES
--------------------------------------------------------------------*/
/*********************************************************************
*
* @private
* process_ecu_indicate_status
*
* @param signal_id The CAN signal id
* @param data The received CAN data
*
*********************************************************************/
static void process_ecu_indicate_status
    (
    const uint16_t signal_id,
    const uint32_t data
    )
{
switch( signal_id )
    {
    case IL_CAN0_ECU_INDCT_EG_SPD_RXSIG_HANDLE:
        rx_ecu_info.engine_speed = data;
        break;
    case IL_CAN0_ECU_INDCT_TC_MODE_RXSIG_HANDLE:
        rx_ecu_info.tc_mode = ( uint8_t )data;
        break;
    default:
        PRINTF( "%s unknown signal id: 0x%x\r\n", __FUNCTION__, signal_id );
        break;
    }
}

/*********************************************************************
*
* @private
* process_ecu_legacy_com_data
*
* @param signal_id The CAN signal id
* @param data The received CAN data
*
*********************************************************************/
static void process_ecu_legacy_com_data
    (
    const uint16_t signal_id,
    const uint32_t data
    )
{
switch( signal_id )
    {
    case IL_CAN0_ECU_COM_DATA_RXSIG_HANDLE: /* VVA */
        rx_ecu_info.vva_indicator = ( vva_indicator_enum )data;
        break;
    default:
        PRINTF( "%s unknown signal id: 0x%x\r\n", __FUNCTION__, signal_id );
        break;
    }
}

/*********************************************************************
*
* @private
* process_supported_function_response_flag
*
* @param signal_id The CAN signal id
* @param data The received CAN data
*
*********************************************************************/
static void process_supported_function_response_flag
    (
    const uint16_t signal_id,
    const uint32_t data
    )
{
switch( signal_id )
    {
    case IL_CAN0_RES_SUPPT_SVC_ID_RXSIG_HANDLE:
        rx_vehicle_supported_features_response = ( uint8_t )data;
        if( VEHICLE_NEGATIVE_RESPONSE_ID == rx_vehicle_supported_features_response )
            {
            PRINTF( "feature req neg res\r\n" );
            }
        break;
    case IL_CAN0_RES_SUPPT_DATA_1_RXSIG_HANDLE: /* TCFS */
        if( VEHICLE_FEATURE_LIST_POSITIVE_RESPONSE_ID == rx_vehicle_supported_features_response )
            {
            rx_tacho_setting.fullscale = ( uint8_t )data;
            }
        else
            {
            PRINTF( "feature req neg sid: %x\r\n", data );
            }
        break;
    case IL_CAN0_RES_SUPPT_DATA_2_RXSIG_HANDLE: /* BRZEGR */
        if( VEHICLE_FEATURE_LIST_POSITIVE_RESPONSE_ID == rx_vehicle_supported_features_response )
            {
            rx_tacho_setting.redzone = ( uint8_t )data;
            }
        else
            {
            PRINTF( "feature req neg rs: %x\r\n", data );
            }
        break;
    case IL_CAN0_RES_SUPPT_DATA_3_RXSIG_HANDLE: /* SFL byte 0 */
        if( VEHICLE_FEATURE_LIST_POSITIVE_RESPONSE_ID == rx_vehicle_supported_features_response )
            {
            rx_vehicle_supported_features = ( rx_vehicle_supported_features & 0xFFFFFF00 ) | ( data & 0xff );
            }
        break;
    case IL_CAN0_RES_SUPPT_DATA_4_RXSIG_HANDLE: /* SFL byte 1 */
        if( VEHICLE_FEATURE_LIST_POSITIVE_RESPONSE_ID == rx_vehicle_supported_features_response )
            {
            rx_vehicle_supported_features = ( rx_vehicle_supported_features & 0xFFFF00FF ) | ( ( data & 0xff ) << 8 );
            }
        break;
    case IL_CAN0_RES_SUPPT_DATA_5_RXSIG_HANDLE: /* SFL byte 2 */
        if( VEHICLE_FEATURE_LIST_POSITIVE_RESPONSE_ID == rx_vehicle_supported_features_response )
            {
            rx_vehicle_supported_features = ( rx_vehicle_supported_features & 0xFF00FFFF ) | ( ( data & 0xff ) << 16 );
            }
        break;
    case IL_CAN0_RES_SUPPT_DATA_6_RXSIG_HANDLE: /* SFL byte 3 */
        if( VEHICLE_FEATURE_LIST_POSITIVE_RESPONSE_ID == rx_vehicle_supported_features_response )
            {
            rx_vehicle_supported_features = ( rx_vehicle_supported_features & 0x00FFFFFF ) | ( ( data & 0xff ) << 24 );
            }
        break;
    case IL_CAN0_RES_SUPPT_DATA_7_RXSIG_HANDLE: /* SFL byte 4 */
        /* reserved */
        break;
    default:
        PRINTF( "%s unknown signal id: 0x%x\r\n", __FUNCTION__, signal_id );
        break;
    }
}

/*********************************************************************
*
* @private
* process_brightness_control_response
*
* @param signal_id The CAN signal id
* @param data The received CAN data
*
*********************************************************************/
static void process_brightness_control_response
    (
    const uint16_t signal_id,
    const uint32_t data
    )
{
switch( signal_id )
    {
    case IL_CAN0_BRTNSS_CTRL_MT_TFT_DUTY_RXSIG_HANDLE:
        rx_brightness_control.tft_duty = ( uint16_t )data;
        /* TODO: set TFT pwm duty cycle */
        break;
    case IL_CAN0_BRTNSS_CTRL_LCD_LV_RXSIG_HANDLE:
        rx_brightness_control.lcd_brightness_level = ( uint8_t )data;
        EW_notify_vi_data_received( EnumVehicleRxTypeMETER_BRIGHTNESS_LEVEL );
        break;
    case IL_CAN0_BRTNSS_CTRL_TFT_LV_RXSIG_HANDLE:
        rx_brightness_control.tft_brightness_level = ( uint8_t )data;
        EW_notify_vi_data_received( EnumVehicleRxTypeTFT_BRIGHTNESS_LEVEL );
        break;
    default:
        PRINTF( "%s unknown signal id: 0x%x\r\n", __FUNCTION__, signal_id );
        break;
    }
}

/*********************************************************************
*
* @private
* process_meter_function_control_response
*
* @param signal_id The CAN signal id
* @param data The received CAN data
*
*********************************************************************/
static void process_meter_function_control_response
    (
    const uint16_t signal_id,
    const uint32_t data
    )
{
switch( signal_id )
    {
    case IL_CAN0_RES_MT_FUNC_CNT_DATA_1_RXSIG_HANDLE:
        rx_vehicle_info_reset_response = data;
        if( VEHICLE_NEGATIVE_RESPONSE_ID == rx_vehicle_info_reset_response )
            {
            PRINTF( "reset or set odo/trip req neg res\r\n" );
            }
        break;
    case IL_CAN0_RES_MT_FUNC_CNT_DATA_2_RXSIG_HANDLE:
        if( RESET_VEHICLE_INFO_RESPONSE_ID == rx_vehicle_info_reset_response )
            {
            /* TODO: notify HMI */
            }
        else if( CHANGE_ODO_TRIP_RESPONSE_ID == rx_vehicle_info_reset_response )
            {
            /* TODO: notify HMI */
            }
        else
            {
            PRINTF( "Err: invalid res 0x%x\r\n", data );
            }
        break;
    case IL_CAN0_RES_MT_FUNC_CNT_SVC_ID_RXSIG_HANDLE:
        if( RESET_VEHICLE_INFO_RESPONSE_ID == rx_vehicle_info_reset_response )
            {
            /* TODO: notify HMI */
            }
        else if( CHANGE_ODO_TRIP_RESPONSE_ID == rx_vehicle_info_reset_response )
            {
            /* TODO: notify HMI */
            }
        else
            {
            PRINTF( "Err: invalid res 0x%x\r\n", data );
            }
        break;
    default:
        PRINTF( "%s unknown signal id: 0x%x\r\n", __FUNCTION__, signal_id );
        break;
    }
}

/*********************************************************************
*
* @private
* process_vehicle_info
*
* @param signal_id The CAN signal id
* @param data The received CAN data
*
*********************************************************************/
static void process_vehicle_info
    (
    const uint16_t signal_id,
    const uint32_t data
    )
{
switch( signal_id )
    {
    case IL_CAN0_VEHICLE_INFO_MILE_UNIT_RXSIG_HANDLE:
        rx_unit_setting.mileage_unit = ( mileage_unit_enum )data;
        break;
    case IL_CAN0_VEHICLE_INFO_PRESS_UNIT_RXSIG_HANDLE:
        rx_unit_setting.pressure_unit = ( pressure_unit_enum )data;
        break;
    case IL_CAN0_VEHICLE_INFO_TEMP_UNIT_RXSIG_HANDLE:
        rx_unit_setting.temperature_unit = ( temperature_unit_enum )data;
        break;
    case IL_CAN0_VEHICLE_INFO_FUEL_CON_UNIT_RXSIG_HANDLE:
        rx_unit_setting.fuel_unit = ( fuel_unit_enum )data;
        break;
    default:
        PRINTF( "%s unknown signal id: 0x%x\r\n", __FUNCTION__, signal_id );
        break;
    }
}

/*********************************************************************
*
* @private
* process_function_software_status
*
* @param signal_id The CAN signal id
* @param data The received CAN data
*
*********************************************************************/
static void process_function_software_status
    (
    const uint16_t signal_id,
    const uint32_t data
    )
{
switch( signal_id )
    {
    case IL_CAN0_FUNC_SW_1_RXSIG_HANDLE:
        vi_key_status_changed( CoreKeyCodeUp, ( int )data );
        break;
    case IL_CAN0_FUNC_SW_2_RXSIG_HANDLE:
        vi_key_status_changed( CoreKeyCodeDown, ( int )data );
        break;
    case IL_CAN0_FUNC_SW_5_RXSIG_HANDLE:
        vi_key_status_changed( CoreKeyCodeOk, ( int )data );
        break;
    case IL_CAN0_FUNC_SW_6_RXSIG_HANDLE:
        vi_key_status_changed( CoreKeyCodeHome, ( int )data );
        break;
    default:
        PRINTF( "%s unknown signal id: 0x%x\r\n", __FUNCTION__, signal_id );
        break;
    }
}

/*********************************************************************
*
* @private
* process_fuel_rate
*
* @param signal_id The CAN signal id
* @param data The received CAN data
*
*********************************************************************/
static void process_fuel_rate
    (
    const uint16_t signal_id,
    const uint32_t data
    )
{
switch( signal_id )
    {
    case IL_CAN0_FUEL_RATE_AVE_RXSIG_HANDLE:
        rx_fuel_rate.average_consumption = ( uint16_t )data;
        break;
    case IL_CAN0_FUEL_RATE_AVG_SPD_RXSIG_HANDLE:
        rx_fuel_rate.average_speed_km = ( uint16_t )data;
        break;
    case IL_CAN0_FUEL_RATE_INST_RXSIG_HANDLE:
        rx_fuel_rate.instant_consumption = ( uint16_t )data;
        break;
    case IL_CAN0_FUEL_RATE_RANGE_DIST_RXSIG_HANDLE:
        rx_fuel_rate.range_distance_km = ( uint16_t )data;
        break;
    default:
        PRINTF( "%s unknown signal id: 0x%x\r\n", __FUNCTION__, signal_id );
        break;
    }
}

/*********************************************************************
*
* @private
* process_odo_trip_value
*
* @param signal_id The CAN signal id
* @param data The received CAN data
*
*********************************************************************/
static void process_odo_trip_value
    (
    const uint16_t signal_id,
    const uint32_t data
    )
{
switch( signal_id )
    {
    case IL_CAN0_ODO_TRIP_ODOMETER_RXSIG_HANDLE:
        rx_odo_trip.odo_value_km = data;
        break;
    case IL_CAN0_ODO_TRIP1_METER_RXSIG_HANDLE:
        rx_odo_trip.trip1_value_km = data;
        break;
    case IL_CAN0_ODO_TRIP2_METER_RXSIG_HANDLE:
        rx_odo_trip.trip2_value_km = data;
        break;
    default:
        PRINTF( "%s unknown signal id: 0x%x\r\n", __FUNCTION__, signal_id );
        break;
    }
}

/*********************************************************************
*
* @private
* process_reprogram_info_response
*
* @param signal_id The CAN signal id
* @param data The received CAN data
*
*********************************************************************/
static void process_reprogram_info_response
    (
    const uint16_t signal_id,
    const uint32_t data
    )
{
switch( signal_id )
    {
    default:
        PRINTF( "%s unknown signal id: 0x%x\r\n", __FUNCTION__, signal_id );
        break;
    }
}

/*********************************************************************
*
* @private
* process_vehicle_info_2
*
* @param signal_id The CAN signal id
* @param data The received CAN data
*
*********************************************************************/
static void process_vehicle_info_2
    (
    const uint16_t signal_id,
    const uint32_t data
    )
{
switch( signal_id )
    {
    case IL_CAN0_VEHICLE_INFO_2_APS_ANG_TRAN_RXSIG_HANDLE:
        rx_vehicle_info.aps_angle_deg = ( uint16_t )data;
        /* TODO: notify HMI tachometer */
        break;
    case IL_CAN0_VEHICLE_INFO_2_SPD_REAL_RXSIG_HANDLE:
        rx_vehicle_info.vehicle_speed_real = ( uint16_t )data;
        /* TODO: notify HMI speed visualizer */
        if( is_dd_mode_activated && ( VEHICLE_DRIVER_DISTRACTION_MODE_LIMIT > rx_vehicle_info.vehicle_speed_real ) )
            {
            is_dd_mode_activated = false;
            EW_notify_dd_mode_state_changed();
            }
        else if( !is_dd_mode_activated && ( VEHICLE_DRIVER_DISTRACTION_MODE_LIMIT <= rx_vehicle_info.vehicle_speed_real ) )
            {
            is_dd_mode_activated = true;
            EW_notify_dd_mode_state_changed();
            }
        else
            {
            // empty
            }
        break;
    case IL_CAN0_VEHICLE_INFO_2_SPD_REAL_MT_RXSIG_HANDLE:
        rx_vehicle_info.vehicle_speed_meter = ( uint16_t )data;
        break;
    default:
        PRINTF( "%s unknown signal id: 0x%x\r\n", __FUNCTION__, signal_id );
        break;
    }
}

/*********************************************************************
*
* @private
* process_vehicle_info_3
*
* @param signal_id The CAN signal id
* @param data The received CAN data
*
*********************************************************************/
static void process_vehicle_info_3
    (
    const uint16_t signal_id,
    const uint32_t data
    )
{
switch( signal_id )
    {
    case IL_CAN0_VEHICLE_INFO_3_FUEL_CON_RXSIG_HANDLE:
        rx_vehicle_info.fuel_cons = ( uint16_t )data;
        break;
    case IL_CAN0_VEHICLE_INFO_3_CLK_ADJST_RXSIG_HANDLE:
        rx_vehicle_info.clock_adj_status = ( bool )data;
        /* TODO: respond to meter the current UNIX time */
        break;
    case IL_CAN0_VEHICLE_INFO_3_AIR_RXSIG_HANDLE:
        rx_vehicle_info.air_temperature = ( int8_t )data;
        break;
    case IL_CAN0_VEHICLE_INFO_3_COOLANT_RXSIG_HANDLE:
        rx_vehicle_info.coolant_temperature = ( int8_t )data;
        break;
    case IL_CAN0_VEHICLE_INFO_3_BAT_RXSIG_HANDLE:
        rx_vehicle_info.battery_voltage = ( uint8_t )data;
        break;
    case IL_CAN0_VEHICLE_INFO_3_CRUISE_RXSIG_HANDLE:
        rx_vehicle_info.cruise_speed = ( uint8_t )data;
        break;
    default:
        PRINTF( "%s unknown signal id: 0x%x\r\n", __FUNCTION__, signal_id );
        break;
    }
}

/*********************************************************************
*
* @private
* process_vehicle_info_4
*
* @param signal_id The CAN signal id
* @param data The received CAN data
*
*********************************************************************/
static void process_vehicle_info_4
    (
    const uint16_t signal_id,
    const uint32_t data
    )
{
switch( signal_id )
    {
    case IL_CAN0_VEHICLE_INFO_4_FTRIP_RXSIG_HANDLE:
        rx_vehicle_info.fuel_tripmeter_km = ( uint16_t )data;
        break;
    case IL_CAN0_VEHICLE_INFO_4_LOW_FUEL_WRN_RXSIG_HANDLE:
        rx_vehicle_info.low_fuel_warning = ( bool )data;
        break;
    case IL_CAN0_VEHICLE_INFO_4_FUEL_RSV_RXSIG_HANDLE:
        rx_vehicle_info.fuel_reserve = ( bool )data;
        break;
    case IL_CAN0_VEHICLE_INFO_4_ODO_TRIP_DIS_RXSIG_HANDLE:
        rx_vehicle_info.odo_trip_display = ( odo_trip_display_enum )data;
        break;
    case IL_CAN0_VEHICLE_INFO_4_FTRIP_HRD_RST_RXSIG_HANDLE:
        rx_vehicle_info.fuel_trip_hard_reset = ( bool )data;
        break;
    default:
        PRINTF( "%s unknown signal id: 0x%x\r\n", __FUNCTION__, signal_id );
        break;
    }
}

/*********************************************************************
*
* @private
* process_maintenance_trip
*
* @param signal_id The CAN signal id
* @param data The received CAN data
*
*********************************************************************/
static void process_maintenance_trip
    (
    const uint16_t signal_id,
    const uint32_t data
    )
{
switch( signal_id )
    {
    case IL_CAN0_MAINT_TRIP_1_RXSIG_HANDLE:
        rx_maintenance_trip.trip1_km = data;
        break;
    case IL_CAN0_MAINT_TRIP_2_RXSIG_HANDLE:
        rx_maintenance_trip.trip2_km = data;
        break;
    case IL_CAN0_MAINT_TRIP_3_RXSIG_HANDLE:
        rx_maintenance_trip.trip3_km = data;
        break;
    default:
        PRINTF( "%s unknown signal id: 0x%x\r\n", __FUNCTION__, signal_id );
        break;
    }
}

/*********************************************************************
*
* @private
* process_heater_status
*
* @param signal_id The CAN signal id
* @param data The received CAN data
*
*********************************************************************/
static void process_heater_status
    (
    const uint16_t signal_id,
    const uint32_t data
    )
{
switch( signal_id )
    {
    case IL_CAN0_HEATER_STAT_GRIP_WARM_LO_RXSIG_HANDLE:
        rx_grip_warmer_status.value_low = ( uint8_t )data;
        break;
    case IL_CAN0_HEATER_STAT_GRIP_WARM_MID_RXSIG_HANDLE:
        rx_grip_warmer_status.value_middle = ( uint8_t )data;
        break;
    case IL_CAN0_HEATER_STAT_GRIP_WARM_HI_RXSIG_HANDLE:
        rx_grip_warmer_status.value_high = ( uint8_t )data;
        break;
    case IL_CAN0_HEATER_STAT_RIDER_SEAT_WARM_LO_RXSIG_HANDLE:
        rx_seat_heater_status.value_low = ( uint8_t )data;
        break;
    case IL_CAN0_HEATER_STAT_RIDER_SEAT_WARM_MID_RXSIG_HANDLE:
        rx_seat_heater_status.value_middle = ( uint8_t )data;
        break;
    case IL_CAN0_HEATER_STAT_RIDER_SEAT_WARM_HI_RXSIG_HANDLE:
        rx_seat_heater_status.value_high = ( uint8_t )data;
        break;
    case IL_CAN0_HEATER_STAT_CRNT_GW_STAT_RXSIG_HANDLE:
        rx_grip_warmer_status.setting = ( heater_setting_enum )data;
        break;
    case IL_CAN0_HEATER_STAT_CRNT_SH_STAT_RXSIG_HANDLE:
        rx_seat_heater_status.setting = ( heater_setting_enum )data;
        break;
    default:
        PRINTF( "%s unknown signal id: 0x%x\r\n", __FUNCTION__, signal_id );
        break;
    }
}

/*********************************************************************
*
* @private
* process_factory_inspection_request
*
* @param signal_id The CAN signal id
* @param data The received CAN data
*
*********************************************************************/
static void process_factory_inspection_request
    (
    const uint16_t signal_id,
    const uint32_t data
    )
{
switch( signal_id )
    {
    default:
        PRINTF( "%s unknown signal id: 0x%x\r\n", __FUNCTION__, signal_id );
        break;
    }
}

/*********************************************************************
*
* @public
* VI_notify_vehicle_data_changed
*
* @param message_frame The received CAN message frame id
* @param signal_id The CAN signal id
* @param data The received CAN data
*
*********************************************************************/
void VI_notify_vehicle_data_changed
    (
    const il_rx_frm_index_t message_frame_id,
    const uint16_t          signal_id,
    const uint32_t          data
    )
{
PRINTF( "vi 0x%x 0x%x 0x%x\r\n", message_frame_id, signal_id, data );
switch( message_frame_id )
    {
    case IL_CAN0_RX0_ECU_INDCT_STAT_IDX:
        process_ecu_indicate_status( signal_id, data );
        break;
    case IL_CAN0_RX1_ECU_COM_DATA_IDX:
        process_ecu_legacy_com_data( signal_id, data );
        break;
    case IL_CAN0_RX2_RES_SUPPORT_IDX:
        process_supported_function_response_flag( signal_id, data );
        break;
    case IL_CAN0_RX3_BRGTHNSS_CTRL_IDX:
        process_brightness_control_response( signal_id, data );
        break;
    case IL_CAN0_RX4_RES_MT_FUNC_CNT_IDX:
        process_meter_function_control_response( signal_id, data );
        break;
    case IL_CAN0_RX5_VEHICLE_INFO_IDX:
        process_vehicle_info( signal_id, data );
        break;
    case IL_CAN0_RX6_FUNCSW_STAT_IDX:
        process_function_software_status( signal_id, data );
        break;
    case IL_CAN0_RX7_FUEL_RATE_IDX:
        process_fuel_rate( signal_id, data );
        break;
    case IL_CAN0_RX8_ODO_TRIP_IDX:
        process_odo_trip_value( signal_id, data );
        break;
    case IL_CAN0_RX9_RES_RPRGRM_INFO_IDX:
        process_reprogram_info_response( signal_id, data );
        break;
    case IL_CAN0_RXA_VEHICLE_INFO_2_IDX:
        process_vehicle_info_2( signal_id, data );
        break;
    case IL_CAN0_RXB_VEHICLE_INFO_3_IDX:
        process_vehicle_info_3( signal_id, data );
        break;
    case IL_CAN0_RXC_VEHICLE_INFO_4_IDX:
        process_vehicle_info_4( signal_id, data );
        break;
    case IL_CAN0_RXD_MAINT_TRIP_IDX:
        process_maintenance_trip( signal_id, data );
        break;
    case IL_CAN0_RXE_HEATER_STAT_IDX:
        process_heater_status( signal_id, data );
        break;
    case IL_CAN0_RXF_FACT_INSP_NS_REQ_IDX:
        process_factory_inspection_request( signal_id, data );
        break;
    default:
        PRINTF( "unknown message frame id: 0x%x\r\n", message_frame_id );
        break;
    }
}

/*********************************************************************
*
* @public
* VI_is_dd_mode_activated
*
* Return if the driver distraction mode is activated
*
* @return The driver distraction mode activated status
*
*********************************************************************/
bool VI_is_dd_mode_activated
    (
    void
    )
{
bool is_activated = false;
if( VEHICLE_DRIVER_DISTRACTION_MODE_LIMIT <= rx_vehicle_info.vehicle_speed_real )
    {
    is_activated = true;
    }
return is_activated;
}

/*********************************************************************
*
* @public
* VI_is_feature_supported
*
* Return if the vehicle feature is supported
*
* @return The vehicle feature supported or not
*
*********************************************************************/
bool VI_is_feature_supported
    (
    vehicle_feature_enum feature
    )
{
return ( ( rx_vehicle_supported_features >> feature ) & 0x1 );
}

/*********************************************************************
*
* @public
* VI_get_rx_data_uint
*
* Get vehicle rx data of uint32 type and validity
*
* @param rx_type Rx data type
* @param data The pointer to the rx data
* @return Vehicle rx data validity
*
*********************************************************************/
bool VI_get_rx_data_uint
    (
    EnumVehicleRxType rx_type,
    uint32_t*         data
    )
{
bool validity = true;

switch( rx_type )
    {
    case EnumVehicleRxTypeENGINE_SPEED:
        *data = rx_ecu_info.engine_speed;
        break;
    case EnumVehicleRxTypeTC_MODE:
        *data = rx_ecu_info.tc_mode;
        break;
    case EnumVehicleRxTypeVVA_INDICATOR:
        *data = rx_ecu_info.vva_indicator;
        break;
    case EnumVehicleRxTypeTFT_BRIGHTNESS_LEVEL:
        *data = rx_brightness_control.tft_brightness_level;
        break;
    case EnumVehicleRxTypeMETER_BRIGHTNESS_LEVEL:
        *data = rx_brightness_control.lcd_brightness_level;
        break;
    case EnumVehicleRxTypeMILEAGE_UNIT:
        *data = rx_unit_setting.mileage_unit;
        break;
    case EnumVehicleRxTypePRESSURE_UNIT:
        *data = rx_unit_setting.pressure_unit;
        break;
    case EnumVehicleRxTypeTEMPERATURE_UNIT:
        *data = rx_unit_setting.temperature_unit;
        break;
    case EnumVehicleRxTypeFUEL_CONSUMPTION_UNIT:
        *data = rx_unit_setting.fuel_unit;
        break;
    case EnumVehicleRxTypeRANGE_DISTANCE:
        if( INVALID_RANGE_DISTANCE != rx_fuel_rate.range_distance_km )
            {
            *data = rx_fuel_rate.range_distance_km;
            }
        else
            {
            validity = false;
            }
        break;
    case EnumVehicleRxTypeAVERAGE_SPEED:
        if( INVALID_AVERAGE_SPEED != rx_fuel_rate.average_speed_km )
            {
            *data = rx_fuel_rate.average_speed_km;
            }
        else
            {
            validity = false;
            }
        break;
    case EnumVehicleRxTypeAPS_ANGLE:
        *data = ( rx_vehicle_info.aps_angle_deg * 125 ) >> 10;
        break;
    case EnumVehicleRxTypeVEHICLE_SPEED_REAL:
        *data = rx_vehicle_info.vehicle_speed_real;
        break;
    case EnumVehicleRxTypeVEHICLE_SPEED_METER:
        *data = rx_vehicle_info.vehicle_speed_meter;
        break;
    case EnumVehicleRxTypeCLOCK_ADJUSTMENT_STATUS:
        *data = rx_vehicle_info.clock_adj_status;
        break;
    case EnumVehicleRxTypeCRUISE_SPEED:
        if( INVALID_CRUISE_SPEED != rx_vehicle_info.cruise_speed )
            {
            *data = rx_vehicle_info.cruise_speed;
            }
        else
            {
            validity = false;
            }
        break;
    case EnumVehicleRxTypeLOW_FUEL_WARNING:
        *data = rx_vehicle_info.low_fuel_warning;
        break;
    case EnumVehicleRxTypeFUEL_RESERVE:
        *data = rx_vehicle_info.fuel_reserve;
        break;
    case EnumVehicleRxTypeODO_TRIP_DISPLAY:
        *data = rx_vehicle_info.odo_trip_display;
        break;
    case EnumVehicleRxTypeF_TRIP_HARD_RESET:
        *data = rx_vehicle_info.fuel_trip_hard_reset;
        break;
    case EnumVehicleRxTypeMAINTENANCE_TRIP1:
        if( INVALID_MAINTENANCE_TRIP != rx_maintenance_trip.trip1_km )
            {
            *data = rx_maintenance_trip.trip1_km;
            }
        else
            {
            validity = false;
            }
        break;
    case EnumVehicleRxTypeMAINTENANCE_TRIP2:
        if( INVALID_MAINTENANCE_TRIP != rx_maintenance_trip.trip2_km )
            {
            *data = rx_maintenance_trip.trip2_km;
            }
        else
            {
            validity = false;
            }
        break;
    case EnumVehicleRxTypeMAINTENANCE_TRIP3:
        if( INVALID_MAINTENANCE_TRIP != rx_maintenance_trip.trip3_km )
            {
            *data = rx_maintenance_trip.trip3_km;
            }
        else
            {
            validity = false;
            }
        break;
    case EnumVehicleRxTypeGRIP_WARMER_VALUE_LOW:
        if( INVALID_HEATER_VALUE != rx_grip_warmer_status.value_low )
            {
            *data = rx_grip_warmer_status.value_low;
            }
        else
            {
            validity = false;
            }
        break;
    case EnumVehicleRxTypeGRIP_WARMER_VALUE_MIDDLE:
        if( INVALID_HEATER_VALUE != rx_grip_warmer_status.value_middle )
            {
            *data = rx_grip_warmer_status.value_middle;
            }
        else
            {
            validity = false;
            }
        break;
    case EnumVehicleRxTypeGRIP_WARMER_VALUE_HIGH:
        if( INVALID_HEATER_VALUE != rx_grip_warmer_status.value_high )
            {
            *data = rx_grip_warmer_status.value_high;
            }
        else
            {
            validity = false;
            }
        break;
    case EnumVehicleRxTypeSEAT_HEATER_VALUE_LOW:
        if( INVALID_HEATER_VALUE != rx_seat_heater_status.value_low )
            {
            *data = rx_seat_heater_status.value_low;
            }
        else
            {
            validity = false;
            }
        break;
    case EnumVehicleRxTypeSEAT_HEATER_VALUE_MIDDLE:
        if( INVALID_HEATER_VALUE != rx_seat_heater_status.value_middle )
            {
            *data = rx_seat_heater_status.value_middle;
            }
        else
            {
            validity = false;
            }
        break;
    case EnumVehicleRxTypeSEAT_HEATER_VALUE_HIGH:
        if( INVALID_HEATER_VALUE != rx_seat_heater_status.value_high )
            {
            *data = rx_seat_heater_status.value_high;
            }
        else
            {
            validity = false;
            }
        break;
    case EnumVehicleRxTypeGRIP_WARMER_STATUS:
        *data = rx_grip_warmer_status.setting;
        break;
    case EnumVehicleRxTypeHEAT_SEATERS_TATUS:
        *data = rx_seat_heater_status.setting;
        break;
    default:
        PRINTF( "Err: %s invalid rx type %d\r\n", __FUNCTION__, rx_type );
        validity = false;
        break;
    }
return validity;
}

/*********************************************************************
*
* @public
* VI_get_rx_data_float
*
* Return vehicle rx data of float type
*
* @param rx_type Rx data type
* @param data The pointer to the rx data
* @return Vehicle rx data validity
*
*********************************************************************/
bool VI_get_rx_data_float
    (
    EnumVehicleRxType rx_type,
    float*            data
    )
{
bool validity = true;

switch( rx_type )
    {
    case EnumVehicleRxTypeFUEL_RATE_INSTANT:
        if( INVALID_INSTANT_CONSUMPTION != rx_fuel_rate.instant_consumption )
            {
            *data = rx_fuel_rate.instant_consumption * 0.1;
            }
        else
            {
            validity = false;
            }
        break;
    case EnumVehicleRxTypeFUEL_RATE_AVERAGE:
        if( INVALID_AVERAGE_CONSUMPTION != rx_fuel_rate.average_consumption )
            {
            *data = rx_fuel_rate.average_consumption * 0.1;
            }
        else
            {
            validity = false;
            }
        break;
    case EnumVehicleRxTypeODOMETER_VALUE:
        if( INVALID_ODO_VALUE != rx_odo_trip.odo_value_km )
            {
            *data = rx_odo_trip.odo_value_km * 0.1;
            }
        else
            {
            validity = false;
            }
        break;
    case EnumVehicleRxTypeTRIP1_VALUE:
        if( INVALID_TRIP1_VALUE != rx_odo_trip.trip1_value_km )
            {
            *data = rx_odo_trip.trip1_value_km * 0.1;
            }
        else
            {
            validity = false;
            }
        break;
    case EnumVehicleRxTypeTRIP2_VALUE:
        if( INVALID_TRIP2_VALUE != rx_odo_trip.trip2_value_km )
            {
            *data = rx_odo_trip.trip2_value_km * 0.1;
            }
        else
            {
            validity = false;
            }
        break;
    case EnumVehicleRxTypeFUEL_CONSUMPTION:
        if( INVALID_FUEL_CONS != rx_vehicle_info.fuel_cons )
            {
            *data = rx_vehicle_info.fuel_cons * 0.1;
            }
        else
            {
            validity = false;
            }
        break;
    case EnumVehicleRxTypeAIR_TEMPERATURE:
        if( INVALID_AIR_TEMPERATURE != rx_vehicle_info.air_temperature )
            {
            *data = rx_vehicle_info.air_temperature * 160 / 256.0 - 30;
            }
        else
            {
            validity = false;
            }
        break;
    case EnumVehicleRxTypeCOOLANT_TEMPERATURE:
        if( INVALID_COOLANT_TEMPERATURE != rx_vehicle_info.coolant_temperature )
            {
            *data = rx_vehicle_info.coolant_temperature * 160 / 256.0 - 30;
            }
        else
            {
            validity = false;
            }
        break;
    case EnumVehicleRxTypeBATTERY_VOLTAGE:
        if( INVALID_BATTERY_VOLTAGE != rx_vehicle_info.battery_voltage )
            {
            *data = rx_vehicle_info.battery_voltage * 18.75 / 256.0;
            }
        else
            {
            validity = false;
            }
        break;
    case EnumVehicleRxTypeF_TRIP:
        if( INVALID_FUEL_TRIPMETER != rx_vehicle_info.fuel_tripmeter_km )
            {
            *data = rx_vehicle_info.fuel_tripmeter_km * 0.1;
            }
        else
            {
            validity = false;
            }
        break;
    default:
        PRINTF( "Err: %s invalid rx type %d\r\n", __FUNCTION__, rx_type );
        validity = false;
        break;
    }
return validity;
}

/*********************************************************************
*
* @public
* VI_is_feature_supported
*
* Set the vehicle feature supported or not
*
*********************************************************************/
void VI_set_feature_supported
    (
    vehicle_feature_enum feature,
    bool supported
    )
{
if( supported )
    {
    set_bit( rx_vehicle_supported_features, feature );
    }
else
    {
    clear_bit( rx_vehicle_supported_features, feature );
    }
}

/*********************************************************************
*
* @private
* vi_rx_init_data
*
* Set initial value of rx data defined in CAN requirement spec
*
*********************************************************************/
void vi_rx_init_data
    (
    void
    )
{
rx_unit_setting.fuel_unit = FUEL_UNIT_L_100KM;

rx_unit_setting.mileage_unit     = MILEAGE_UNIT_KM;
rx_unit_setting.pressure_unit    = PRESSURE_UNIT_PSI;
rx_unit_setting.temperature_unit = TEMPERATURE_UNIT_DEG_C;
rx_unit_setting.fuel_unit        = FUEL_UNIT_L_100KM;

rx_fuel_rate.instant_consumption = INVALID_INSTANT_CONSUMPTION;
rx_fuel_rate.average_consumption = INVALID_AVERAGE_CONSUMPTION;
rx_fuel_rate.range_distance_km   = INVALID_RANGE_DISTANCE;
rx_fuel_rate.average_speed_km    = INVALID_AVERAGE_SPEED;

rx_odo_trip.odo_value_km   = INVALID_ODO_VALUE;
rx_odo_trip.trip1_value_km = INVALID_TRIP1_VALUE;
rx_odo_trip.trip2_value_km = INVALID_TRIP2_VALUE;

rx_vehicle_info.fuel_cons           = INVALID_FUEL_CONS;
rx_vehicle_info.air_temperature     = INVALID_AIR_TEMPERATURE;
rx_vehicle_info.coolant_temperature = INVALID_COOLANT_TEMPERATURE;
rx_vehicle_info.battery_voltage     = INVALID_BATTERY_VOLTAGE;
rx_vehicle_info.cruise_speed        = INVALID_CRUISE_SPEED;
rx_vehicle_info.fuel_tripmeter_km   = INVALID_FUEL_TRIPMETER;
rx_vehicle_info.odo_trip_display    = ODO_TRIP_DISPLAY_ODO;

rx_maintenance_trip.trip1_km = INVALID_MAINTENANCE_TRIP;
rx_maintenance_trip.trip2_km = INVALID_MAINTENANCE_TRIP;
rx_maintenance_trip.trip3_km = INVALID_MAINTENANCE_TRIP;

rx_ecu_info.tc_mode = TCS_MODE_ON;

rx_grip_warmer_status.value_low    = DEFAULT_GRIP_WARMER_LOW_VALUE;
rx_grip_warmer_status.value_middle = DEFAULT_GRIP_WARMER_MIDDLE_VALUE;
rx_grip_warmer_status.value_high   = DEFAULT_GRIP_WARMER_HIGH_VALUE;
rx_grip_warmer_status.setting      = HEATER_SETTING_OFF;

rx_seat_heater_status.value_low    = DEFAULT_SEAT_HEATER_LOW_VALUE;
rx_seat_heater_status.value_middle = DEFAULT_SEAT_HEATER_MIDDLE_VALUE;
rx_seat_heater_status.value_high   = DEFAULT_SEAT_HEATER_HIGH_VALUE;
rx_seat_heater_status.setting      = HEATER_SETTING_OFF;

rx_vehicle_info.clock_adj_status   = false;

rx_brightness_control.lcd_brightness_level = DEFALUT_LCD_BRIGHTNESS_LEVEL;
rx_brightness_control.tft_brightness_level = DEFALUT_TFT_BRIGHTNESS_LEVEL;
rx_brightness_control.tft_duty             = DEFALUT_TFT_DUTY;

rx_tacho_setting.fullscale = DEFAULT_TACHO_FULLSCALE;
rx_tacho_setting.redzone   = DEFAULT_TACHO_REDZONE;

set_bit( rx_vehicle_supported_features, VEHICLE_FEATURE_OIL_TRIP );
set_bit( rx_vehicle_supported_features, VEHICLE_FEATURE_CURRENT_FUEL );
set_bit( rx_vehicle_supported_features, VEHICLE_FEATURE_AVG_FUEL );
set_bit( rx_vehicle_supported_features, VEHICLE_FEATURE_TRIP_TIME );
}