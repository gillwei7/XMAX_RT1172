/*******************************************************************************
*
* E M B E D D E D   W I Z A R D   P R O J E C T
*
*                                                Copyright (c) TARA Systems GmbH
*                                    written by Paul Banach and Manfred Schweyer
*
********************************************************************************
*
* This file was generated automatically by Embedded Wizard Studio.
*
* Please do not make any modifications of this file! The modifications are lost
* when the file is generated again by Embedded Wizard Studio!
*
* The template of this heading text can be found in the file 'head.ewt' in the
* directory 'Platforms' of your Embedded Wizard installation directory. If you
* wish to adapt this text, please copy the template file 'head.ewt' into your
* project directory and edit the copy only. Please avoid any modifications of
* the original template file!
*
* Version  : 11.00
* Profile  : iMX_RT
* Platform : NXP.iMX_RT_VGLite.RGBA8888
*
*******************************************************************************/

#include "ewlocale.h"
#include "_CoreSystemEvent.h"
#include "_DeviceInterfaceBluetoothDeviceClass.h"
#include "_DeviceInterfaceBtPairedDeviceInfo.h"
#include "_DeviceInterfaceBtmStatusContext.h"
#include "_DeviceInterfaceConnectionStatusContext.h"
#include "_DeviceInterfaceDateTime.h"
#include "_DeviceInterfaceMediaManagerDeviceClass.h"
#include "_DeviceInterfaceMotoConContext.h"
#include "_DeviceInterfaceNaviDataClass.h"
#include "_DeviceInterfaceNaviPoiDataClass.h"
#include "_DeviceInterfaceNaviTbtDataClass.h"
#include "_DeviceInterfaceNavigationDeviceClass.h"
#include "_DeviceInterfaceNotificationContext.h"
#include "_DeviceInterfaceNotificationDeviceClass.h"
#include "_DeviceInterfaceRtcTime.h"
#include "_DeviceInterfaceSystemData.h"
#include "_DeviceInterfaceSystemDeviceClass.h"
#include "_DeviceInterfaceVehicleDataClass.h"
#include "_DeviceInterfaceVehicleDeviceClass.h"
#include "_DeviceInterfaceWeatherDeviceClass.h"
#include "_FactoryTestContext.h"
#include "DeviceInterface.h"
#include "Enum.h"
#include "Strings.h"

/* Compressed strings for the language 'Default'. */
EW_CONST_STRING_PRAGMA static const unsigned int _StringsDefault0[] =
{
  0x0000023E, /* ratio 51.57 % */
  0xB8002500, 0x000A6452, 0x00C2003A, 0x80107390, 0x16750010, 0x20037002, 0x540044C9,
  0x30019400, 0x000021A7, 0x04160619, 0x1BC00680, 0x421C7700, 0x22D14894, 0x3B1B8CC5,
  0x91A29422, 0x0D364AE3, 0xF1000075, 0x9103C011, 0xBC264843, 0x9326A678, 0xEA8B14A1,
  0x82F1F9E4, 0x1B262748, 0x066001A6, 0x008C1E40, 0xB9C422A6, 0x85496831, 0x01926B49,
  0x8627B4B0, 0x4E1151A7, 0x88357AAD, 0x1136B544, 0xA00A457A, 0x65B1C6E8, 0x093DA29B,
  0xB7002D97, 0x6CACC538, 0xD82E6003, 0xEEC962BA, 0x644109EC, 0x15380011, 0x1779B1C2,
  0x1BC254EB, 0x206802F3, 0x864AC892, 0xA49EE10A, 0x5EC299A8, 0xAAAD54A9, 0x20D84844,
  0x3B2BD0C2, 0xBA70DE6A, 0xA3A0EAAF, 0x831C6E2F, 0xA1EBB73A, 0x5ECA2308, 0xED43D1FC,
  0x42AFA9AC, 0xEBBB9A11, 0x7F389C50, 0x95FE76C3, 0xA68FE268, 0x8BE54209, 0xA9D1EFDC,
  0x01540132, 0x74EC7930, 0x7E3F6300, 0xF556BE38, 0x0BCD92F2, 0xC00C873F, 0x119C544A,
  0x1EAFCB31, 0x9ECF72B6, 0x00000101, 0x00000000
};

/* Constant values used in this 'C' module only. */
static const XStringRes _Const0000 = { _StringsDefault0, 0x0002 };
static const XStringRes _Const0001 = { _StringsDefault0, 0x0014 };
static const XStringRes _Const0002 = { _StringsDefault0, 0x002D };
static const XStringRes _Const0003 = { _StringsDefault0, 0x003C };
static const XStringRes _Const0004 = { _StringsDefault0, 0x0053 };
static const XStringRes _Const0005 = { _StringsDefault0, 0x006B };
static const XStringRes _Const0006 = { _StringsDefault0, 0x0082 };
static const XStringRes _Const0007 = { _StringsDefault0, 0x0092 };
static const XStringRes _Const0008 = { _StringsDefault0, 0x009F };
static const XStringRes _Const0009 = { _StringsDefault0, 0x00B3 };
static const XStringRes _Const000A = { _StringsDefault0, 0x00CE };
static const XStringRes _Const000B = { _StringsDefault0, 0x00EC };
static const XStringRes _Const000C = { _StringsDefault0, 0x0100 };

#ifndef EW_DONT_CHECK_INDEX
  /* This function is used to check the indices when accessing an array.
     If you don't want this verification add the define EW_DONT_CHECK_INDEX
     to your Makefile or project settings. */
  static int EwCheckIndex( int aIndex, int aRange, const char* aFile, int aLine )
  {
    if (( aIndex < 0 ) || ( aIndex >= aRange ))
    {
      EwPrint( "[FATAL ERROR in %s:%d] Array index %d out of bounds %d",
                aFile, aLine, aIndex, aRange );
      EwPanic();
    }
    return aIndex;
  }

  #define EwCheckIndex( aIndex, aRange ) \
    EwCheckIndex( aIndex, aRange, __FILE__, __LINE__ )
#else
  #define EwCheckIndex( aIndex, aRange ) aIndex
#endif

/* User defined inline code: 'DeviceInterface::Inline' */
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include "ew_priv.h"
#include "display_support.h"
#include "EEPM_pub.h"
#include "PERIPHERAL_pub.h"
#include "VI_pub.h"
#include "MM_pub_ams_type.h"
#include "BT_pub.h"
#include "CM_pub.h"
#include "BC_motocon_pub.h"
#include "BC_motocon_pub_type.h"
#include "BC_ams_pub.h"
#include "NTF_pub.h"
#include "TEST_pub.h"
#include "NAVI_pub.h"
#include "Enum.h"
#include "ew_tacho.h"

/* Initializer for the class 'DeviceInterface::SystemDeviceClass' */
void DeviceInterfaceSystemDeviceClass__Init( DeviceInterfaceSystemDeviceClass _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  TemplatesDeviceClass__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( DeviceInterfaceSystemDeviceClass );

  /* ... then construct all embedded objects */
  CoreSystemEvent__Init( &_this->FactoryTestSystemEvent, &_this->_.XObject, 0 );
  CoreSystemEvent__Init( &_this->QrCodeSystemEvent, &_this->_.XObject, 0 );
  CoreSystemEvent__Init( &_this->OpeningSystemEvent, &_this->_.XObject, 0 );
  CoreSystemEvent__Init( &_this->InspectionDisplaySystemEvent, &_this->_.XObject, 0 );
  CoreSystemEvent__Init( &_this->InspectionModeSystemEvent, &_this->_.XObject, 0 );
  CoreSystemEvent__Init( &_this->SystemDataReceivedSystemEvent, &_this->_.XObject, 0 );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( DeviceInterfaceSystemDeviceClass );

  /* ... and initialize objects, variables, properties, etc. */
  _this->BrightnessLevel = 7;
  _this->InspectionMode = EnumInspectionModeNONE;
}

/* Re-Initializer for the class 'DeviceInterface::SystemDeviceClass' */
void DeviceInterfaceSystemDeviceClass__ReInit( DeviceInterfaceSystemDeviceClass _this )
{
  /* At first re-initialize the super class ... */
  TemplatesDeviceClass__ReInit( &_this->_.Super );

  /* ... then re-construct all embedded objects */
  CoreSystemEvent__ReInit( &_this->FactoryTestSystemEvent );
  CoreSystemEvent__ReInit( &_this->QrCodeSystemEvent );
  CoreSystemEvent__ReInit( &_this->OpeningSystemEvent );
  CoreSystemEvent__ReInit( &_this->InspectionDisplaySystemEvent );
  CoreSystemEvent__ReInit( &_this->InspectionModeSystemEvent );
  CoreSystemEvent__ReInit( &_this->SystemDataReceivedSystemEvent );
}

/* Finalizer method for the class 'DeviceInterface::SystemDeviceClass' */
void DeviceInterfaceSystemDeviceClass__Done( DeviceInterfaceSystemDeviceClass _this )
{
  /* Finalize this class */
  _this->_.Super._.VMT = EW_CLASS( TemplatesDeviceClass );

  /* Finalize all embedded objects */
  CoreSystemEvent__Done( &_this->FactoryTestSystemEvent );
  CoreSystemEvent__Done( &_this->QrCodeSystemEvent );
  CoreSystemEvent__Done( &_this->OpeningSystemEvent );
  CoreSystemEvent__Done( &_this->InspectionDisplaySystemEvent );
  CoreSystemEvent__Done( &_this->InspectionModeSystemEvent );
  CoreSystemEvent__Done( &_this->SystemDataReceivedSystemEvent );

  /* Don't forget to deinitialize the super class ... */
  TemplatesDeviceClass__Done( &_this->_.Super );
}

/* 'C' function for method : 'DeviceInterface::SystemDeviceClass.QuitTest()' */
void DeviceInterfaceSystemDeviceClass_QuitTest( DeviceInterfaceSystemDeviceClass _this )
{
  FactoryTestContext TestContext = EwNewObject( FactoryTestContext, 0 );

  TestContext->TestItem = EnumFactoryTestQuit;
  CoreSystemEvent_Trigger( &_this->FactoryTestSystemEvent, ((XObject)TestContext ), 
  0 );
}

/* Wrapper function for the non virtual method : 'DeviceInterface::SystemDeviceClass.QuitTest()' */
void DeviceInterfaceSystemDeviceClass__QuitTest( void* _this )
{
  DeviceInterfaceSystemDeviceClass_QuitTest((DeviceInterfaceSystemDeviceClass)_this );
}

/* This method is intended to be called by the device to notify the GUI application 
   about a particular system event. */
void DeviceInterfaceSystemDeviceClass_TestDisplayPattern( DeviceInterfaceSystemDeviceClass _this, 
  XInt32 aIdx )
{
  FactoryTestContext TestContext = EwNewObject( FactoryTestContext, 0 );

  TestContext->TestItem = EnumFactoryTestDisplay;
  TestContext->Data = aIdx - 1;
  CoreSystemEvent_Trigger( &_this->FactoryTestSystemEvent, ((XObject)TestContext ), 
  0 );
}

/* Wrapper function for the non virtual method : 'DeviceInterface::SystemDeviceClass.TestDisplayPattern()' */
void DeviceInterfaceSystemDeviceClass__TestDisplayPattern( void* _this, XInt32 aIdx )
{
  DeviceInterfaceSystemDeviceClass_TestDisplayPattern((DeviceInterfaceSystemDeviceClass)_this
  , aIdx );
}

/* 'C' function for method : 'DeviceInterface::SystemDeviceClass.NotifyEsnRead()' */
void DeviceInterfaceSystemDeviceClass_NotifyEsnRead( DeviceInterfaceSystemDeviceClass _this, 
  XString aESN )
{
  DeviceInterfaceSystemDeviceClass_OnSetESN( _this, aESN );
}

/* Wrapper function for the non virtual method : 'DeviceInterface::SystemDeviceClass.NotifyEsnRead()' */
void DeviceInterfaceSystemDeviceClass__NotifyEsnRead( void* _this, XString aESN )
{
  DeviceInterfaceSystemDeviceClass_NotifyEsnRead((DeviceInterfaceSystemDeviceClass)_this
  , aESN );
}

/* 'C' function for method : 'DeviceInterface::SystemDeviceClass.OnSetESN()' */
void DeviceInterfaceSystemDeviceClass_OnSetESN( DeviceInterfaceSystemDeviceClass _this, 
  XString value )
{
  if ( EwCompString( _this->ESN, value ) != 0 )
  {
    _this->ESN = EwShareString( value );
    EwNotifyRefObservers( EwNewRef( _this, DeviceInterfaceSystemDeviceClass_OnGetESN, 
      DeviceInterfaceSystemDeviceClass_OnSetESN ), 0 );
  }
}

/* 'C' function for method : 'DeviceInterface::SystemDeviceClass.OnGetESN()' */
XString DeviceInterfaceSystemDeviceClass_OnGetESN( DeviceInterfaceSystemDeviceClass _this )
{
  if ( !EwCompString( 0, _this->ESN ))
    ew_get_esn();

  return _this->ESN;
}

/* 'C' function for method : 'DeviceInterface::SystemDeviceClass.OnGetSoftwareVersion()' */
XString DeviceInterfaceSystemDeviceClass_OnGetSoftwareVersion( DeviceInterfaceSystemDeviceClass _this )
{
  XString software_version = 0;

  if ( !EwCompString( 0, _this->SoftwareVersion ))
  {
    {
      char version[8];
      ew_get_software_version( version );
      software_version = EwNewStringAnsi( version );
    }
    _this->SoftwareVersion = EwShareString( software_version );
  }

  return _this->SoftwareVersion;
}

/* 'C' function for method : 'DeviceInterface::SystemDeviceClass.ResetToFactoryDefault()' */
void DeviceInterfaceSystemDeviceClass_ResetToFactoryDefault( DeviceInterfaceSystemDeviceClass _this )
{
  _this->IsRunningFactoryReset = 1;
  EW_reset_to_factory_default();
}

/* 'C' function for method : 'DeviceInterface::SystemDeviceClass.RebootSystem()' */
void DeviceInterfaceSystemDeviceClass_RebootSystem( DeviceInterfaceSystemDeviceClass _this )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  ew_reboot_system();
}

/* 'C' function for method : 'DeviceInterface::SystemDeviceClass.SetTFTDutyCycle()' */
void DeviceInterfaceSystemDeviceClass_SetTFTDutyCycle( DeviceInterfaceSystemDeviceClass _this, 
  XInt32 aDutyCycle )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  PERIPHERAL_pwm_set_display_dutycycle( aDutyCycle );
}

/* 'C' function for method : 'DeviceInterface::SystemDeviceClass.StartBurnInTest()' */
void DeviceInterfaceSystemDeviceClass_StartBurnInTest( DeviceInterfaceSystemDeviceClass _this )
{
  FactoryTestContext TestContext;

  EwTrace( "%s", EwLoadString( &_Const0000 ));
  TestContext = EwNewObject( FactoryTestContext, 0 );
  TestContext->TestItem = EnumFactoryTestBurnInStart;
  CoreSystemEvent_Trigger( &_this->FactoryTestSystemEvent, ((XObject)TestContext ), 
  0 );
}

/* Wrapper function for the non virtual method : 'DeviceInterface::SystemDeviceClass.StartBurnInTest()' */
void DeviceInterfaceSystemDeviceClass__StartBurnInTest( void* _this )
{
  DeviceInterfaceSystemDeviceClass_StartBurnInTest((DeviceInterfaceSystemDeviceClass)_this );
}

/* 'C' function for method : 'DeviceInterface::SystemDeviceClass.UpdateBurnInTestTime()' */
void DeviceInterfaceSystemDeviceClass_UpdateBurnInTestTime( DeviceInterfaceSystemDeviceClass _this, 
  XUInt32 aTimeSec )
{
  FactoryTestContext TestContext = EwNewObject( FactoryTestContext, 0 );

  TestContext->TestItem = EnumFactoryTestBurnInTimeUpdate;
  TestContext->Data = (XInt32)aTimeSec;
  CoreSystemEvent_Trigger( &_this->FactoryTestSystemEvent, ((XObject)TestContext ), 
  0 );
}

/* Wrapper function for the non virtual method : 'DeviceInterface::SystemDeviceClass.UpdateBurnInTestTime()' */
void DeviceInterfaceSystemDeviceClass__UpdateBurnInTestTime( void* _this, XUInt32 
  aTimeSec )
{
  DeviceInterfaceSystemDeviceClass_UpdateBurnInTestTime((DeviceInterfaceSystemDeviceClass)_this
  , aTimeSec );
}

/* 'C' function for method : 'DeviceInterface::SystemDeviceClass.ShowBurnInTestResult()' */
void DeviceInterfaceSystemDeviceClass_ShowBurnInTestResult( DeviceInterfaceSystemDeviceClass _this, 
  XBool aResult )
{
  FactoryTestContext TestContext;

  EwTrace( "%s%b", EwLoadString( &_Const0001 ), aResult );
  TestContext = EwNewObject( FactoryTestContext, 0 );
  TestContext->TestItem = EnumFactoryTestBurnInResult;

  if ( aResult )
    TestContext->Data = 1;
  else
    TestContext->Data = 0;

  CoreSystemEvent_Trigger( &_this->FactoryTestSystemEvent, ((XObject)TestContext ), 
  0 );
}

/* Wrapper function for the non virtual method : 'DeviceInterface::SystemDeviceClass.ShowBurnInTestResult()' */
void DeviceInterfaceSystemDeviceClass__ShowBurnInTestResult( void* _this, XBool 
  aResult )
{
  DeviceInterfaceSystemDeviceClass_ShowBurnInTestResult((DeviceInterfaceSystemDeviceClass)_this
  , aResult );
}

/* This method is intended to be called by the device to notify the GUI application 
   about a particular system event. */
void DeviceInterfaceSystemDeviceClass_NotifyQrCodeReady( DeviceInterfaceSystemDeviceClass _this )
{
  CoreSystemEvent_Trigger( &_this->QrCodeSystemEvent, 0, 0 );
}

/* Wrapper function for the non virtual method : 'DeviceInterface::SystemDeviceClass.NotifyQrCodeReady()' */
void DeviceInterfaceSystemDeviceClass__NotifyQrCodeReady( void* _this )
{
  DeviceInterfaceSystemDeviceClass_NotifyQrCodeReady((DeviceInterfaceSystemDeviceClass)_this );
}

/* 'C' function for method : 'DeviceInterface::SystemDeviceClass.GetLocalTime()' */
DeviceInterfaceRtcTime DeviceInterfaceSystemDeviceClass_GetLocalTime( DeviceInterfaceSystemDeviceClass _this )
{
  DeviceInterfaceRtcTime CurrentLocalTime;
  XUInt16 RtcYear;
  XUInt8 RtcMonth;
  XUInt8 RtcDay;
  XUInt8 RtcHour;
  XUInt8 RtcMinute;
  XUInt8 RtcSecond;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  CurrentLocalTime = EwNewObject( DeviceInterfaceRtcTime, 0 );
  RtcYear = 0;
  RtcMonth = 0;
  RtcDay = 0;
  RtcHour = 0;
  RtcMinute = 0;
  RtcSecond = 0;
  {
    snvs_lp_srtc_datetime_t srtc_time;
    ew_get_rtc_time( &srtc_time );

    RtcYear = srtc_time.year;
    RtcMonth = srtc_time.month;
    RtcDay = srtc_time.day;
    RtcHour = srtc_time.hour;
    RtcMinute = srtc_time.minute;
    RtcSecond = srtc_time.second;
  }
  CurrentLocalTime->Year = RtcYear;
  CurrentLocalTime->Month = RtcMonth;
  CurrentLocalTime->Day = RtcDay;
  CurrentLocalTime->Hour = RtcHour;
  CurrentLocalTime->Minute = RtcMinute;
  CurrentLocalTime->Second = RtcSecond;
  return CurrentLocalTime;
}

/* This method is intended to be called by the device to notify the GUI application 
   about a particular system event. */
void DeviceInterfaceSystemDeviceClass_StartOpening( DeviceInterfaceSystemDeviceClass _this )
{
  CoreSystemEvent_Trigger( &_this->OpeningSystemEvent, 0, 0 );
}

/* Wrapper function for the non virtual method : 'DeviceInterface::SystemDeviceClass.StartOpening()' */
void DeviceInterfaceSystemDeviceClass__StartOpening( void* _this )
{
  DeviceInterfaceSystemDeviceClass_StartOpening((DeviceInterfaceSystemDeviceClass)_this );
}

/* 'C' function for method : 'DeviceInterface::SystemDeviceClass.IsKeyStateValid()' */
XBool DeviceInterfaceSystemDeviceClass_IsKeyStateValid( DeviceInterfaceSystemDeviceClass _this )
{
  XBool IsValid;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  IsValid = 1;
  IsValid = VI_is_key_state_valid();
  return IsValid;
}

/* 'C' function for method : 'DeviceInterface::SystemDeviceClass.IsTFTBacklightOn()' */
XBool DeviceInterfaceSystemDeviceClass_IsTFTBacklightOn( DeviceInterfaceSystemDeviceClass _this )
{
  XBool IsBacklightOn;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  IsBacklightOn = 0;
  IsBacklightOn = display_is_tft_backlight_on();
  return IsBacklightOn;
}

/* 'C' function for method : 'DeviceInterface::SystemDeviceClass.OnSetOperationMode()' */
void DeviceInterfaceSystemDeviceClass_OnSetOperationMode( DeviceInterfaceSystemDeviceClass _this, 
  XEnum value )
{
  if ( _this->OperationMode != value )
  {
    _this->OperationMode = value;
    ew_set_operation_mode( value );
  }
}

/* 'C' function for method : 'DeviceInterface::SystemDeviceClass.OnGetOperationMode()' */
XEnum DeviceInterfaceSystemDeviceClass_OnGetOperationMode( DeviceInterfaceSystemDeviceClass _this )
{
  XEnum Mode = EnumOperationModeNORMAL;

  {
    EnumOperationMode op_mode;
    if( EW_get_operation_mode( &op_mode ) )
    {
      Mode = op_mode;
    }
  }
  _this->OperationMode = Mode;
  return _this->OperationMode;
}

/* 'C' function for method : 'DeviceInterface::SystemDeviceClass.IsOperationModeReady()' */
XBool DeviceInterfaceSystemDeviceClass_IsOperationModeReady( DeviceInterfaceSystemDeviceClass _this )
{
  XBool IsOperationModeReady;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  IsOperationModeReady = 0;
  IsOperationModeReady = ew_is_operation_mode_ready();
  return IsOperationModeReady;
}

/* Notifiy the inspection display pattern to test */
void DeviceInterfaceSystemDeviceClass_NotifyInspectionRequest( DeviceInterfaceSystemDeviceClass _this, 
  XEnum aMode, XEnum aDisplayPattern )
{
  DeviceInterfaceSystemDeviceClass_OnSetInspectionDisplayPattern( _this, aDisplayPattern );
  DeviceInterfaceSystemDeviceClass_OnSetInspectionMode( _this, aMode );
}

/* Wrapper function for the non virtual method : 'DeviceInterface::SystemDeviceClass.NotifyInspectionRequest()' */
void DeviceInterfaceSystemDeviceClass__NotifyInspectionRequest( void* _this, XEnum 
  aMode, XEnum aDisplayPattern )
{
  DeviceInterfaceSystemDeviceClass_NotifyInspectionRequest((DeviceInterfaceSystemDeviceClass)_this
  , aMode, aDisplayPattern );
}

/* 'C' function for method : 'DeviceInterface::SystemDeviceClass.OnSetInspectionMode()' */
void DeviceInterfaceSystemDeviceClass_OnSetInspectionMode( DeviceInterfaceSystemDeviceClass _this, 
  XEnum value )
{
  _this->InspectionMode = value;
  CoreSystemEvent_Trigger( &_this->InspectionModeSystemEvent, 0, 0 );
}

/* 'C' function for method : 'DeviceInterface::SystemDeviceClass.OnSetInspectionDisplayPattern()' */
void DeviceInterfaceSystemDeviceClass_OnSetInspectionDisplayPattern( DeviceInterfaceSystemDeviceClass _this, 
  XEnum value )
{
  if ( _this->InspectionDisplayPattern != value )
  {
    _this->InspectionDisplayPattern = value;
    CoreSystemEvent_Trigger( &_this->InspectionDisplaySystemEvent, 0, 0 );
  }
}

/* 'C' function for method : 'DeviceInterface::SystemDeviceClass.SendInspectionResponse()' */
void DeviceInterfaceSystemDeviceClass_SendInspectionResponse( DeviceInterfaceSystemDeviceClass _this, 
  XEnum aMode, XUInt8 aRes )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  VI_send_inspection_response( aMode, aRes );
}

/* Get current home type from UI */
void DeviceInterfaceSystemDeviceClass_NotifyLastPageRead( DeviceInterfaceSystemDeviceClass _this )
{
  XEnum HomeGroup = EnumHomeGroupNONE;
  XEnum MeterDisplaySetting = EnumMeterDisplayTACHOMETER;
  XEnum NavigationViewSetting = EnumNavigationViewDEFAULT_VIEW;

  {
    HomeGroup = ew_get_last_home_group();
    MeterDisplaySetting = ew_get_meter_display_setting();
    NavigationViewSetting = ew_get_navigation_view_setting();
  }
  EwGetAutoObject( &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass )->CurrentMeterDisplay 
  = MeterDisplaySetting;

  switch ( NavigationViewSetting )
  {
    case EnumNavigationViewDEFAULT_VIEW :
      EwGetAutoObject( &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass )->CurrentHome 
      = EnumHomeTypeNAVI_DEFAULT_VIEW;
    break;

    case EnumNavigationViewTURN_BY_TURN :
      EwGetAutoObject( &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass )->CurrentHome 
      = EnumHomeTypeNAVI_TURN_BY_TURN;
    break;

    case EnumNavigationViewNEXT_TURN :
      EwGetAutoObject( &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass )->CurrentHome 
      = EnumHomeTypeNAVI_NEXT_TURN;
    break;

    default : 
      EwGetAutoObject( &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass )->CurrentHome 
      = EnumHomeTypeNAVI_DEFAULT_VIEW;
  }

  switch ( HomeGroup )
  {
    case EnumHomeGroupMETER :
      switch ( MeterDisplaySetting )
      {
        case EnumMeterDisplayTACHOMETER :
          _this->HomeType = EnumHomeTypeTACHO_VISUALIZER;
        break;

        case EnumMeterDisplayECHO_METER :
          _this->HomeType = EnumHomeTypeECO_VISUALIZER;
        break;

        case EnumMeterDisplaySPEED_METER :
          _this->HomeType = EnumHomeTypeSPEED_VISUALIZER;
        break;

        default : 
          _this->HomeType = EnumHomeTypeTACHO_VISUALIZER;
      }
    break;

    case EnumHomeGroupNAVIGATION :
      _this->HomeType = EwGetAutoObject( &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass )->CurrentHome;
    break;

    case EnumHomeGroupVEHICLE_INFO :
      _this->HomeType = EnumHomeTypeVEHICLE_INFO;
    break;

    default :; 
  }
}

/* Wrapper function for the non virtual method : 'DeviceInterface::SystemDeviceClass.NotifyLastPageRead()' */
void DeviceInterfaceSystemDeviceClass__NotifyLastPageRead( void* _this )
{
  DeviceInterfaceSystemDeviceClass_NotifyLastPageRead((DeviceInterfaceSystemDeviceClass)_this );
}

/* Get current home type from UI */
void DeviceInterfaceSystemDeviceClass_UpdateLastPage( DeviceInterfaceSystemDeviceClass _this )
{
  XEnum HomeGroup;
  XEnum NavigationViewSetting;
  XEnum MeterDisplaySetting;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  switch ( EwGetAutoObject( &DeviceInterfaceSystemDevice, DeviceInterfaceSystemDeviceClass )->HomeType )
  {
    case EnumHomeTypeTACHO_VISUALIZER :
    case EnumHomeTypeECO_VISUALIZER :
    case EnumHomeTypeSPEED_VISUALIZER :
      HomeGroup = EnumHomeGroupMETER;
    break;

    case EnumHomeTypeNAVI_DEFAULT_VIEW :
    case EnumHomeTypeNAVI_TURN_BY_TURN :
    case EnumHomeTypeNAVI_NEXT_TURN :
      HomeGroup = EnumHomeGroupNAVIGATION;
    break;

    case EnumHomeTypeVEHICLE_INFO :
      HomeGroup = EnumHomeGroupVEHICLE_INFO;
    break;

    default : 
      HomeGroup = EnumHomeGroupMETER;
  }

  switch ( EwGetAutoObject( &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass )->CurrentHome )
  {
    case EnumHomeTypeNAVI_DEFAULT_VIEW :
      NavigationViewSetting = EnumNavigationViewDEFAULT_VIEW;
    break;

    case EnumHomeTypeNAVI_TURN_BY_TURN :
      NavigationViewSetting = EnumNavigationViewTURN_BY_TURN;
    break;

    case EnumHomeTypeNAVI_NEXT_TURN :
      NavigationViewSetting = EnumNavigationViewNEXT_TURN;
    break;

    default : 
      NavigationViewSetting = EnumNavigationViewDEFAULT_VIEW;
  }

  MeterDisplaySetting = EwGetAutoObject( &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass )->CurrentMeterDisplay;
  ew_set_last_page( HomeGroup, MeterDisplaySetting, NavigationViewSetting );
}

/* Wrapper function for the non virtual method : 'DeviceInterface::SystemDeviceClass.UpdateLastPage()' */
void DeviceInterfaceSystemDeviceClass__UpdateLastPage( void* _this )
{
  DeviceInterfaceSystemDeviceClass_UpdateLastPage((DeviceInterfaceSystemDeviceClass)_this );
}

/* 'C' function for method : 'DeviceInterface::SystemDeviceClass.OnSetHomeType()' */
void DeviceInterfaceSystemDeviceClass_OnSetHomeType( DeviceInterfaceSystemDeviceClass _this, 
  XEnum value )
{
  if ( _this->HomeType != value )
  {
    XEnum HomeGroup;
    XEnum NavigationViewSetting;
    XEnum MeterDisplaySetting;
    _this->HomeType = value;

    switch ( value )
    {
      case EnumHomeTypeTACHO_VISUALIZER :
      case EnumHomeTypeECO_VISUALIZER :
      case EnumHomeTypeSPEED_VISUALIZER :
        HomeGroup = EnumHomeGroupMETER;
      break;

      case EnumHomeTypeNAVI_DEFAULT_VIEW :
      case EnumHomeTypeNAVI_TURN_BY_TURN :
      case EnumHomeTypeNAVI_NEXT_TURN :
        HomeGroup = EnumHomeGroupNAVIGATION;
      break;

      case EnumHomeTypeVEHICLE_INFO :
        HomeGroup = EnumHomeGroupVEHICLE_INFO;
      break;

      default : 
        HomeGroup = EnumHomeGroupMETER;
    }

    switch ( EwGetAutoObject( &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass )->CurrentHome )
    {
      case EnumHomeTypeNAVI_DEFAULT_VIEW :
        NavigationViewSetting = EnumNavigationViewDEFAULT_VIEW;
      break;

      case EnumHomeTypeNAVI_TURN_BY_TURN :
        NavigationViewSetting = EnumNavigationViewTURN_BY_TURN;
      break;

      case EnumHomeTypeNAVI_NEXT_TURN :
        NavigationViewSetting = EnumNavigationViewNEXT_TURN;
      break;

      default : 
        NavigationViewSetting = EnumNavigationViewDEFAULT_VIEW;
    }

    MeterDisplaySetting = EwGetAutoObject( &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass )->CurrentMeterDisplay;
    ew_set_last_page( HomeGroup, MeterDisplaySetting, NavigationViewSetting );
  }
}

/* 'C' function for method : 'DeviceInterface::SystemDeviceClass.SetKeyTriggerMode()' */
void DeviceInterfaceSystemDeviceClass_SetKeyTriggerMode( DeviceInterfaceSystemDeviceClass _this, 
  XEnum aKey, XEnum aMode )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  VI_key_set_trigger_mode( aKey, aMode );
}

/* 'C' function for method : 'DeviceInterface::SystemDeviceClass.SetMagicKeyEnabled()' */
void DeviceInterfaceSystemDeviceClass_SetMagicKeyEnabled( DeviceInterfaceSystemDeviceClass _this, 
  XBool aEnabled )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  VI_key_set_magic_key_enabled( aEnabled );
}

/* 'C' function for method : 'DeviceInterface::SystemDeviceClass.NotifyTimeRequest()' */
void DeviceInterfaceSystemDeviceClass_NotifyTimeRequest( DeviceInterfaceSystemDeviceClass _this )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  {
    BC_motocon_set_request_from_clock();
    BC_motocon_send_vehicle_setting_request();
  }
}

/* 'C' function for method : 'DeviceInterface::SystemDeviceClass.SetRtcTime()' */
void DeviceInterfaceSystemDeviceClass_SetRtcTime( DeviceInterfaceSystemDeviceClass _this, 
  DeviceInterfaceRtcTime aNewTime )
{
  XUInt16 NewTimeYear;
  XUInt8 NewTimeMonth;
  XUInt8 NewTimeDay;
  XUInt8 NewTimeHour;
  XUInt8 NewTimeMinute;
  XUInt8 NewTimeSecond;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  NewTimeYear = aNewTime->Year;
  NewTimeMonth = aNewTime->Month;
  NewTimeDay = aNewTime->Day;
  NewTimeHour = aNewTime->Hour;
  NewTimeMinute = aNewTime->Minute;
  NewTimeSecond = aNewTime->Second;
  {
    snvs_lp_srtc_datetime_t srtc_time;
    srtc_time.year = NewTimeYear;
    srtc_time.month = NewTimeMonth;
    srtc_time.day = NewTimeDay;
    srtc_time.hour = NewTimeHour;
    srtc_time.minute = NewTimeMinute;
    srtc_time.second = NewTimeSecond;
    ew_set_rtc_time( &srtc_time );
  }
}

/* 'C' function for method : 'DeviceInterface::SystemDeviceClass.SendManualAdjTimeToMeter()' */
void DeviceInterfaceSystemDeviceClass_SendManualAdjTimeToMeter( DeviceInterfaceSystemDeviceClass _this )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  VI_clock_send_rtc_time_to_meter();
}

/* 'C' function for method : 'DeviceInterface::SystemDeviceClass.OnSetIsClockAutoAdj()' */
void DeviceInterfaceSystemDeviceClass_OnSetIsClockAutoAdj( DeviceInterfaceSystemDeviceClass _this, 
  XBool value )
{
  if ( _this->IsClockAutoAdj != value )
  {
    XBool ClockAutoAdjStatus;
    _this->IsClockAutoAdj = value;
    ClockAutoAdjStatus = value;
    ew_set_clk_auto_adj( ClockAutoAdjStatus );
  }
}

/* 'C' function for method : 'DeviceInterface::SystemDeviceClass.OnGetIsClockAutoAdj()' */
XBool DeviceInterfaceSystemDeviceClass_OnGetIsClockAutoAdj( DeviceInterfaceSystemDeviceClass _this )
{
  XBool ClockAutoAdjStatus = 0;

  ClockAutoAdjStatus = EW_get_clk_auto_adj();
  _this->IsClockAutoAdj = ClockAutoAdjStatus;
  return _this->IsClockAutoAdj;
}

/* This method is intended to be called by the device to notify the GUI application 
   about a particular system event. */
void DeviceInterfaceSystemDeviceClass_NotifySystemEventReceived( DeviceInterfaceSystemDeviceClass _this, 
  XEnum aSystemRxEvent )
{
  DeviceInterfaceSystemData SystemDataContext = EwNewObject( DeviceInterfaceSystemData, 
    0 );

  SystemDataContext->RxEvent = aSystemRxEvent;
  CoreSystemEvent_Trigger( &_this->SystemDataReceivedSystemEvent, ((XObject)SystemDataContext ), 
  0 );
}

/* Wrapper function for the non virtual method : 'DeviceInterface::SystemDeviceClass.NotifySystemEventReceived()' */
void DeviceInterfaceSystemDeviceClass__NotifySystemEventReceived( void* _this, XEnum 
  aSystemRxEvent )
{
  DeviceInterfaceSystemDeviceClass_NotifySystemEventReceived((DeviceInterfaceSystemDeviceClass)_this
  , aSystemRxEvent );
}

/* 'C' function for method : 'DeviceInterface::SystemDeviceClass.StartOTA()' */
void DeviceInterfaceSystemDeviceClass_StartOTA( DeviceInterfaceSystemDeviceClass _this )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  ew_start_ota();
}

/* 'C' function for method : 'DeviceInterface::SystemDeviceClass.OnGetIsSoftwareUpdateEnabled()' */
XBool DeviceInterfaceSystemDeviceClass_OnGetIsSoftwareUpdateEnabled( DeviceInterfaceSystemDeviceClass _this )
{
  XBool IsEnabled = 0;

  {
    bc_motocon_ota_update_info_t* ota_update_info = BC_motocon_get_ota_update_info();
    IsEnabled = ota_update_info->enable;
  }
  _this->IsSoftwareUpdateEnabled = IsEnabled;
  return _this->IsSoftwareUpdateEnabled;
}

/* 'C' function for method : 'DeviceInterface::SystemDeviceClass.SaveLastStatus()' */
void DeviceInterfaceSystemDeviceClass_SaveLastStatus( DeviceInterfaceSystemDeviceClass _this )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  ew_save_last_status();
}

/* 'C' function for method : 'DeviceInterface::SystemDeviceClass.SendSystemCommand()' */
void DeviceInterfaceSystemDeviceClass_SendSystemCommand( DeviceInterfaceSystemDeviceClass _this, 
  XEnum aCmd )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  ew_send_system_command( aCmd );
}

/* 'C' function for method : 'DeviceInterface::SystemDeviceClass.GetSystemStatus()' */
XInt32 DeviceInterfaceSystemDeviceClass_GetSystemStatus( DeviceInterfaceSystemDeviceClass _this, 
  XEnum aStatusType )
{
  XInt32 Status;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  Status = 0;
  Status = ew_system_get_status( aStatusType );
  return Status;
}

/* 'C' function for method : 'DeviceInterface::SystemDeviceClass.ChangeLanguage()' */
void DeviceInterfaceSystemDeviceClass_ChangeLanguage( DeviceInterfaceSystemDeviceClass _this, 
  XEnum aLanguage )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  EwTrace( "%s%e", EwLoadString( &_Const0002 ), aLanguage );

  switch ( aLanguage )
  {
    case EnumLanguageENGLISH :
      EwSetLanguage( Default );
    break;

    case EnumLanguageFRENCH :
      EwSetLanguage( French );
    break;

    case EnumLanguageGERMAN :
      EwSetLanguage( German );
    break;

    case EnumLanguageITALIAN :
      EwSetLanguage( Italian );
    break;

    case EnumLanguageJAPANESE :
      EwSetLanguage( Japanese );
    break;

    case EnumLanguageSPANISH :
      EwSetLanguage( Spanish );
    break;

    case EnumLanguageTRADITIONAL_CHINESE :
      EwSetLanguage( TraditionalChinese );
    break;

    case EnumLanguageSIMPLIFIED_CHINESE :
      EwSetLanguage( SimplifiedChinese );
    break;

    case EnumLanguageGREEK :
      EwSetLanguage( Greek );
    break;

    case EnumLanguageFINNISH :
      EwSetLanguage( Finnish );
    break;

    case EnumLanguageHINDI :
      EwSetLanguage( Hindi );
    break;

    case EnumLanguageINDONESIAN :
      EwSetLanguage( Indonesian );
    break;

    case EnumLanguagePOLISH :
      EwSetLanguage( Polish );
    break;

    case EnumLanguagePORTUGUESE_BRAZIL :
      EwSetLanguage( PortugueseBrazil );
    break;

    case EnumLanguageTHAI :
      EwSetLanguage( Thai );
    break;

    case EnumLanguageVIETNAMESE :
      EwSetLanguage( Vietnamese );
    break;

    case EnumLanguageKOREAN :
      EwSetLanguage( Korean );
    break;

    case EnumLanguageMALAY :
      EwSetLanguage( Malay );
    break;

    default : 
      EwSetLanguage( Default );
  }
}

/* Variants derived from the class : 'DeviceInterface::SystemDeviceClass' */
EW_DEFINE_CLASS_VARIANTS( DeviceInterfaceSystemDeviceClass )
EW_END_OF_CLASS_VARIANTS( DeviceInterfaceSystemDeviceClass )

/* Virtual Method Table (VMT) for the class : 'DeviceInterface::SystemDeviceClass' */
EW_DEFINE_CLASS( DeviceInterfaceSystemDeviceClass, TemplatesDeviceClass, CurrentAdjustTime, 
                 FactoryTestSystemEvent, FactoryTestSystemEvent, FactoryTestSystemEvent, 
                 SoftwareVersion, BrightnessLevel, "DeviceInterface::SystemDeviceClass" )
EW_END_OF_CLASS( DeviceInterfaceSystemDeviceClass )

/* User defined auto object: 'DeviceInterface::SystemDevice' */
EW_DEFINE_AUTOOBJECT( DeviceInterfaceSystemDevice, DeviceInterfaceSystemDeviceClass )

/* Initializer for the auto object 'DeviceInterface::SystemDevice' */
void DeviceInterfaceSystemDevice__Init( DeviceInterfaceSystemDeviceClass _this )
{
  EW_UNUSED_ARG( _this );
}

/* Table with links to derived variants of the auto object : 'DeviceInterface::SystemDevice' */
EW_DEFINE_AUTOOBJECT_VARIANTS( DeviceInterfaceSystemDevice )
EW_END_OF_AUTOOBJECT_VARIANTS( DeviceInterfaceSystemDevice )

/* Initializer for the class 'DeviceInterface::NavigationDeviceClass' */
void DeviceInterfaceNavigationDeviceClass__Init( DeviceInterfaceNavigationDeviceClass _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  TemplatesDeviceClass__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( DeviceInterfaceNavigationDeviceClass );

  /* ... then construct all embedded objects */
  CoreSystemEvent__Init( &_this->MapUpdateEvent, &_this->_.XObject, 0 );
  CoreSystemEvent__Init( &_this->CurRdUpdateEvent, &_this->_.XObject, 0 );
  CoreSystemEvent__Init( &_this->ETAUpdateEvent, &_this->_.XObject, 0 );
  CoreSystemEvent__Init( &_this->DayNightModeUpdateEvent, &_this->_.XObject, 0 );
  CoreSystemEvent__Init( &_this->SpeedLimitUpdateEvent, &_this->_.XObject, 0 );
  CoreSystemEvent__Init( &_this->NavigationAlertUpdateEvent, &_this->_.XObject, 0 );
  CoreSystemEvent__Init( &_this->NavigatingStatusUpdateEvent, &_this->_.XObject, 0 );
  CoreSystemEvent__Init( &_this->TbtListUpdateEvent, &_this->_.XObject, 0 );
  CoreSystemEvent__Init( &_this->RouteCalProgressUpdateEvent, &_this->_.XObject, 0 );
  CoreSystemEvent__Init( &_this->ZoomLevelUpdateEventHandler, &_this->_.XObject, 0 );
  CoreSystemEvent__Init( &_this->DialogEventUpdateEvent, &_this->_.XObject, 0 );
  CoreSystemEvent__Init( &_this->ViaPointUpdateEvent, &_this->_.XObject, 0 );
  CoreSystemEvent__Init( &_this->AlertDistanceUpdateEvent, &_this->_.XObject, 0 );
  CoreSystemEvent__Init( &_this->ConnectStatusUpdateEvent, &_this->_.XObject, 0 );
  CoreSystemEvent__Init( &_this->DisconnectStatusUpdateEvent, &_this->_.XObject, 0 );
  CoreSystemEvent__Init( &_this->PoiListUpdateEvent, &_this->_.XObject, 0 );
  CoreSystemEvent__Init( &_this->BtThroughputStatusUpdateEvent, &_this->_.XObject, 0 );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( DeviceInterfaceNavigationDeviceClass );

  /* ... and initialize objects, variables, properties, etc. */
  _this->CurrentHome = EnumHomeTypeNAVI_DEFAULT_VIEW;
  _this->IsZoomInOutStatusReceived = 1;
}

/* Re-Initializer for the class 'DeviceInterface::NavigationDeviceClass' */
void DeviceInterfaceNavigationDeviceClass__ReInit( DeviceInterfaceNavigationDeviceClass _this )
{
  /* At first re-initialize the super class ... */
  TemplatesDeviceClass__ReInit( &_this->_.Super );

  /* ... then re-construct all embedded objects */
  CoreSystemEvent__ReInit( &_this->MapUpdateEvent );
  CoreSystemEvent__ReInit( &_this->CurRdUpdateEvent );
  CoreSystemEvent__ReInit( &_this->ETAUpdateEvent );
  CoreSystemEvent__ReInit( &_this->DayNightModeUpdateEvent );
  CoreSystemEvent__ReInit( &_this->SpeedLimitUpdateEvent );
  CoreSystemEvent__ReInit( &_this->NavigationAlertUpdateEvent );
  CoreSystemEvent__ReInit( &_this->NavigatingStatusUpdateEvent );
  CoreSystemEvent__ReInit( &_this->TbtListUpdateEvent );
  CoreSystemEvent__ReInit( &_this->RouteCalProgressUpdateEvent );
  CoreSystemEvent__ReInit( &_this->ZoomLevelUpdateEventHandler );
  CoreSystemEvent__ReInit( &_this->DialogEventUpdateEvent );
  CoreSystemEvent__ReInit( &_this->ViaPointUpdateEvent );
  CoreSystemEvent__ReInit( &_this->AlertDistanceUpdateEvent );
  CoreSystemEvent__ReInit( &_this->ConnectStatusUpdateEvent );
  CoreSystemEvent__ReInit( &_this->DisconnectStatusUpdateEvent );
  CoreSystemEvent__ReInit( &_this->PoiListUpdateEvent );
  CoreSystemEvent__ReInit( &_this->BtThroughputStatusUpdateEvent );
}

/* Finalizer method for the class 'DeviceInterface::NavigationDeviceClass' */
void DeviceInterfaceNavigationDeviceClass__Done( DeviceInterfaceNavigationDeviceClass _this )
{
  /* Finalize this class */
  _this->_.Super._.VMT = EW_CLASS( TemplatesDeviceClass );

  /* Finalize all embedded objects */
  CoreSystemEvent__Done( &_this->MapUpdateEvent );
  CoreSystemEvent__Done( &_this->CurRdUpdateEvent );
  CoreSystemEvent__Done( &_this->ETAUpdateEvent );
  CoreSystemEvent__Done( &_this->DayNightModeUpdateEvent );
  CoreSystemEvent__Done( &_this->SpeedLimitUpdateEvent );
  CoreSystemEvent__Done( &_this->NavigationAlertUpdateEvent );
  CoreSystemEvent__Done( &_this->NavigatingStatusUpdateEvent );
  CoreSystemEvent__Done( &_this->TbtListUpdateEvent );
  CoreSystemEvent__Done( &_this->RouteCalProgressUpdateEvent );
  CoreSystemEvent__Done( &_this->ZoomLevelUpdateEventHandler );
  CoreSystemEvent__Done( &_this->DialogEventUpdateEvent );
  CoreSystemEvent__Done( &_this->ViaPointUpdateEvent );
  CoreSystemEvent__Done( &_this->AlertDistanceUpdateEvent );
  CoreSystemEvent__Done( &_this->ConnectStatusUpdateEvent );
  CoreSystemEvent__Done( &_this->DisconnectStatusUpdateEvent );
  CoreSystemEvent__Done( &_this->PoiListUpdateEvent );
  CoreSystemEvent__Done( &_this->BtThroughputStatusUpdateEvent );

  /* Don't forget to deinitialize the super class ... */
  TemplatesDeviceClass__Done( &_this->_.Super );
}

/* This method is intended to be called by the device to notify the GUI application 
   about a particular system event. */
void DeviceInterfaceNavigationDeviceClass_NotifyMapUpdate( DeviceInterfaceNavigationDeviceClass _this )
{
  CoreSystemEvent_Trigger( &_this->MapUpdateEvent, 0, 1 );
}

/* Wrapper function for the non virtual method : 'DeviceInterface::NavigationDeviceClass.NotifyMapUpdate()' */
void DeviceInterfaceNavigationDeviceClass__NotifyMapUpdate( void* _this )
{
  DeviceInterfaceNavigationDeviceClass_NotifyMapUpdate((DeviceInterfaceNavigationDeviceClass)_this );
}

/* 'C' function for method : 'DeviceInterface::NavigationDeviceClass.IsMapFrameReady()' */
XBool DeviceInterfaceNavigationDeviceClass_IsMapFrameReady( DeviceInterfaceNavigationDeviceClass _this )
{
  XBool IsMapFrameReady;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  IsMapFrameReady = 0;
  IsMapFrameReady = ew_navi_is_map_frame_ready();
  return IsMapFrameReady;
}

/* This method is intended to be called by the device to notify the GUI application 
   about a particular system event. */
void DeviceInterfaceNavigationDeviceClass_NotifyCurRdUpdate( DeviceInterfaceNavigationDeviceClass _this )
{
  CoreSystemEvent_Trigger( &_this->CurRdUpdateEvent, 0, 0 );
}

/* Wrapper function for the non virtual method : 'DeviceInterface::NavigationDeviceClass.NotifyCurRdUpdate()' */
void DeviceInterfaceNavigationDeviceClass__NotifyCurRdUpdate( void* _this )
{
  DeviceInterfaceNavigationDeviceClass_NotifyCurRdUpdate((DeviceInterfaceNavigationDeviceClass)_this );
}

/* This method is intended to be called by the device to notify the GUI application 
   about a particular system event. */
void DeviceInterfaceNavigationDeviceClass_NotifyETAUpdate( DeviceInterfaceNavigationDeviceClass _this )
{
  CoreSystemEvent_Trigger( &_this->ETAUpdateEvent, 0, 0 );
}

/* Wrapper function for the non virtual method : 'DeviceInterface::NavigationDeviceClass.NotifyETAUpdate()' */
void DeviceInterfaceNavigationDeviceClass__NotifyETAUpdate( void* _this )
{
  DeviceInterfaceNavigationDeviceClass_NotifyETAUpdate((DeviceInterfaceNavigationDeviceClass)_this );
}

/* This method is intended to be called by the device to notify the GUI application 
   about a particular system event. */
void DeviceInterfaceNavigationDeviceClass_NotifyDayNightModeUpdate( DeviceInterfaceNavigationDeviceClass _this )
{
  CoreSystemEvent_Trigger( &_this->DayNightModeUpdateEvent, 0, 0 );
}

/* Wrapper function for the non virtual method : 'DeviceInterface::NavigationDeviceClass.NotifyDayNightModeUpdate()' */
void DeviceInterfaceNavigationDeviceClass__NotifyDayNightModeUpdate( void* _this )
{
  DeviceInterfaceNavigationDeviceClass_NotifyDayNightModeUpdate((DeviceInterfaceNavigationDeviceClass)_this );
}

/* This method is intended to be called by the device to notify the GUI application 
   about a particular system event. */
void DeviceInterfaceNavigationDeviceClass_NotifySpeedLimitUpdate( DeviceInterfaceNavigationDeviceClass _this )
{
  CoreSystemEvent_Trigger( &_this->SpeedLimitUpdateEvent, 0, 0 );
}

/* Wrapper function for the non virtual method : 'DeviceInterface::NavigationDeviceClass.NotifySpeedLimitUpdate()' */
void DeviceInterfaceNavigationDeviceClass__NotifySpeedLimitUpdate( void* _this )
{
  DeviceInterfaceNavigationDeviceClass_NotifySpeedLimitUpdate((DeviceInterfaceNavigationDeviceClass)_this );
}

/* This method is intended to be called by the device to notify the GUI application 
   about a particular system event. */
void DeviceInterfaceNavigationDeviceClass_NotifyNaviAlertUpdate( DeviceInterfaceNavigationDeviceClass _this )
{
  CoreSystemEvent_Trigger( &_this->NavigationAlertUpdateEvent, 0, 0 );
}

/* Wrapper function for the non virtual method : 'DeviceInterface::NavigationDeviceClass.NotifyNaviAlertUpdate()' */
void DeviceInterfaceNavigationDeviceClass__NotifyNaviAlertUpdate( void* _this )
{
  DeviceInterfaceNavigationDeviceClass_NotifyNaviAlertUpdate((DeviceInterfaceNavigationDeviceClass)_this );
}

/* 'C' function for method : 'DeviceInterface::NavigationDeviceClass.GetNaviData()' */
DeviceInterfaceNaviDataClass DeviceInterfaceNavigationDeviceClass_GetNaviData( DeviceInterfaceNavigationDeviceClass _this, 
  XEnum aDataType )
{
  DeviceInterfaceNaviDataClass NaviData;
  XInt32 NaviDataType;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  NaviData = EwNewObject( DeviceInterfaceNaviDataClass, 0 );
  NaviDataType = aDataType;
  {
    navi_data_type* navi_obj = NULL;
    #if( !UNIT_TEST_NAVI )
      navi_obj = NAVI_get_navi_obj();
    #else
      navi_obj = TEST_get_navi_obj();
    #endif

    switch( NaviDataType )
    {
      case EnumNaviDataTypeCURRENT_ROAD:
        NaviData->CurrentRoad = EwNewStringUtf8( ( const unsigned char* )navi_obj->current_road, ( int )strlen( navi_obj->current_road ) );
        break;
      case EnumNaviDataTypeETA:
        NaviData->ETA = navi_obj->eta;
        break;
      case EnumNaviDataTypeSPEED_LIMIT:
        NaviData->SpeedLimit = navi_obj->speed_limit;
        break;
      case EnumNaviDataTypeDAYNIGHT:
        NaviData->DayNightMode = navi_obj->daynight;
        break;
      case EnumNaviDataTypeNAVI_EVENT:
        {
          navi_event_type navi_event_obj;
          bool is_event_retrieved = NAVI_get_event( &navi_event_obj );
          if( is_event_retrieved )
          {
            NaviData->NaviEventType = navi_event_obj.event_type;
            NaviData->NaviCameraType = navi_event_obj.camera_type;
            NaviData->NaviEventDist = EwNewStringUtf8( ( const unsigned char* )navi_event_obj.dist, ( int )strlen( navi_event_obj.dist ) );
            NaviData->NaviEventSpeed = EwNewStringUtf8( ( const unsigned char* )navi_event_obj.speed, ( int )strlen( navi_event_obj.speed ) );
            NaviData->NaviEventDesc = EwNewStringUtf8( ( const unsigned char* )navi_event_obj.desc, ( int )strlen( navi_event_obj.desc ) );
            NaviData->NaviEventVisibility = navi_event_obj.visibility;
          }
          else
          {
            NaviData = NULL;
          }
        }
        break;
      case EnumNaviDataTypeNAVI_ROUTE_CAL_PROGRESS:
        NaviData->RouteCalProgress = navi_obj->route_cal_progress;
        break;
      case EnumNaviDataTypeVIA_POINT:
        NaviData->ViaPoints = navi_obj->via_points;
        break;
      case EnumNaviDataTypeHOME:
        NaviData->IsHomeSet = (bool)navi_obj->is_home_set;
        break;
      case EnumNaviDataTypeOFFICE:
        NaviData->IsOfficeSet = (bool)navi_obj->is_office_set;
        break;
      case EnumNaviDataTypeZOOM_LEVEL:
        NaviData->ZoomLevel = EwNewStringUtf8( ( const unsigned char* )navi_obj->zoom_level, ( int )strlen( navi_obj->zoom_level ) );
        break;
      default:
        break;
    }
  }
  return NaviData;
}

/* 'C' function for method : 'DeviceInterface::NavigationDeviceClass.IsRouteGuidanceStarted()' */
XBool DeviceInterfaceNavigationDeviceClass_IsRouteGuidanceStarted( DeviceInterfaceNavigationDeviceClass _this )
{
  XBool IsNavigating;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  IsNavigating = 0;
  IsNavigating = NAVI_get_navigation_status();
  return IsNavigating;
}

/* This method is intended to be called by the device to notify the GUI application 
   about a particular system event. */
void DeviceInterfaceNavigationDeviceClass_NotifyNavigatingStatusUpdate( DeviceInterfaceNavigationDeviceClass _this )
{
  CoreSystemEvent_Trigger( &_this->NavigatingStatusUpdateEvent, 0, 0 );
}

/* Wrapper function for the non virtual method : 'DeviceInterface::NavigationDeviceClass.NotifyNavigatingStatusUpdate()' */
void DeviceInterfaceNavigationDeviceClass__NotifyNavigatingStatusUpdate( void* _this )
{
  DeviceInterfaceNavigationDeviceClass_NotifyNavigatingStatusUpdate((DeviceInterfaceNavigationDeviceClass)_this );
}

/* This method is intended to be called by the device to notify the GUI application 
   about a particular system event. */
void DeviceInterfaceNavigationDeviceClass_NotifyTbtListUpdate( DeviceInterfaceNavigationDeviceClass _this )
{
  CoreSystemEvent_Trigger( &_this->TbtListUpdateEvent, 0, 0 );
}

/* Wrapper function for the non virtual method : 'DeviceInterface::NavigationDeviceClass.NotifyTbtListUpdate()' */
void DeviceInterfaceNavigationDeviceClass__NotifyTbtListUpdate( void* _this )
{
  DeviceInterfaceNavigationDeviceClass_NotifyTbtListUpdate((DeviceInterfaceNavigationDeviceClass)_this );
}

/* 'C' function for method : 'DeviceInterface::NavigationDeviceClass.GetNaviTbtData()' */
DeviceInterfaceNaviTbtDataClass DeviceInterfaceNavigationDeviceClass_GetNaviTbtData( DeviceInterfaceNavigationDeviceClass _this, 
  XInt32 aTbtItemIdx )
{
  DeviceInterfaceNaviTbtDataClass NaviTbtData;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  NaviTbtData = EwNewObject( DeviceInterfaceNaviTbtDataClass, 0 );
  {
    uint32_t icon_idx;
    float distance;
    char* dist_unit;
    char* description;
    NAVI_get_tbt_item( aTbtItemIdx, &icon_idx, &distance, &dist_unit, &description );
    NaviTbtData->IconIdx = icon_idx;
    NaviTbtData->Distance = distance;
    NaviTbtData->DistUnit = EwNewStringUtf8( ( const unsigned char* )dist_unit, ( int )strlen( dist_unit ) );
    NaviTbtData->TbtDescription = EwNewStringUtf8( ( const unsigned char* )description, ( int )strlen( description ) );
  }
  return NaviTbtData;
}

/* 'C' function for method : 'DeviceInterface::NavigationDeviceClass.StopMapFrameRequest()' */
void DeviceInterfaceNavigationDeviceClass_StopMapFrameRequest( DeviceInterfaceNavigationDeviceClass _this )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  NAVI_stop_map_update();
}

/* This method is intended to be called by the device to notify the GUI application 
   about a particular system event. */
void DeviceInterfaceNavigationDeviceClass_NotifyRouteCalProgressUpdate( DeviceInterfaceNavigationDeviceClass _this )
{
  CoreSystemEvent_Trigger( &_this->RouteCalProgressUpdateEvent, 0, 0 );
}

/* Wrapper function for the non virtual method : 'DeviceInterface::NavigationDeviceClass.NotifyRouteCalProgressUpdate()' */
void DeviceInterfaceNavigationDeviceClass__NotifyRouteCalProgressUpdate( void* _this )
{
  DeviceInterfaceNavigationDeviceClass_NotifyRouteCalProgressUpdate((DeviceInterfaceNavigationDeviceClass)_this );
}

/* This method is intended to be called by the device to notify the GUI application 
   about a particular system event. */
void DeviceInterfaceNavigationDeviceClass_NotifyZoomLevelUpdate( DeviceInterfaceNavigationDeviceClass _this )
{
  _this->IsZoomInOutStatusReceived = 1;
  CoreSystemEvent_Trigger( &_this->ZoomLevelUpdateEventHandler, 0, 0 );
}

/* Wrapper function for the non virtual method : 'DeviceInterface::NavigationDeviceClass.NotifyZoomLevelUpdate()' */
void DeviceInterfaceNavigationDeviceClass__NotifyZoomLevelUpdate( void* _this )
{
  DeviceInterfaceNavigationDeviceClass_NotifyZoomLevelUpdate((DeviceInterfaceNavigationDeviceClass)_this );
}

/* This method is intended to be called by the device to notify the GUI application 
   about a particular system event. */
void DeviceInterfaceNavigationDeviceClass_NotifyDialogEventUpdate( DeviceInterfaceNavigationDeviceClass _this )
{
  CoreSystemEvent_Trigger( &_this->DialogEventUpdateEvent, 0, 0 );
}

/* Wrapper function for the non virtual method : 'DeviceInterface::NavigationDeviceClass.NotifyDialogEventUpdate()' */
void DeviceInterfaceNavigationDeviceClass__NotifyDialogEventUpdate( void* _this )
{
  DeviceInterfaceNavigationDeviceClass_NotifyDialogEventUpdate((DeviceInterfaceNavigationDeviceClass)_this );
}

/* 'C' function for method : 'DeviceInterface::NavigationDeviceClass.GetNaviDialogType()' */
XEnum DeviceInterfaceNavigationDeviceClass_GetNaviDialogType( DeviceInterfaceNavigationDeviceClass _this )
{
  XEnum NaviDialog;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  NaviDialog = EnumNaviDialogTypeDIALOG_OK;
  {
    #if( !UNIT_TEST_NAVI )
      NaviDialog = NAVI_get_dialog_type();
    #else
      NaviDialog = TEST_navi_get_dialog_type();
    #endif
  }
  return NaviDialog;
}

/* 'C' function for method : 'DeviceInterface::NavigationDeviceClass.GetNaviDialogMessage()' */
XString DeviceInterfaceNavigationDeviceClass_GetNaviDialogMessage( DeviceInterfaceNavigationDeviceClass _this )
{
  XString NaviDialogMessage;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  NaviDialogMessage = 0;
  {
    navi_dialog_type* navi_dialog_obj = NULL;
    navi_dialog_obj = NAVI_get_navi_dialog_obj();
    NaviDialogMessage  = EwNewStringUtf8( ( const unsigned char* )navi_dialog_obj->dialog_message, ( int )strlen( navi_dialog_obj->dialog_message ) );
  }
  return NaviDialogMessage;
}

/* 'C' function for method : 'DeviceInterface::NavigationDeviceClass.SendSelectedDialog()' */
void DeviceInterfaceNavigationDeviceClass_SendSelectedDialog( DeviceInterfaceNavigationDeviceClass _this, 
  XEnum aNewButtonType )
{
  XEnum ButtonType;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  ButtonType = aNewButtonType;
  NAVI_send_selected_dialog( ButtonType );
}

/* This method is intended to be called by the device to notify the GUI application 
   about a particular system event. */
void DeviceInterfaceNavigationDeviceClass_NotifyViaPointUpdate( DeviceInterfaceNavigationDeviceClass _this )
{
  CoreSystemEvent_Trigger( &_this->ViaPointUpdateEvent, 0, 0 );
}

/* Wrapper function for the non virtual method : 'DeviceInterface::NavigationDeviceClass.NotifyViaPointUpdate()' */
void DeviceInterfaceNavigationDeviceClass__NotifyViaPointUpdate( void* _this )
{
  DeviceInterfaceNavigationDeviceClass_NotifyViaPointUpdate((DeviceInterfaceNavigationDeviceClass)_this );
}

/* 'C' function for method : 'DeviceInterface::NavigationDeviceClass.GetNaviConnectStatus()' */
XBool DeviceInterfaceNavigationDeviceClass_GetNaviConnectStatus( DeviceInterfaceNavigationDeviceClass _this )
{
  XBool IsNaviAppConnected;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  IsNaviAppConnected = 0;
  IsNaviAppConnected = NAVI_get_connect_status();
  return IsNaviAppConnected;
}

/* 'C' function for method : 'DeviceInterface::NavigationDeviceClass.StopRoute()' */
void DeviceInterfaceNavigationDeviceClass_StopRoute( DeviceInterfaceNavigationDeviceClass _this )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  NAVI_send_stop_route_request();
}

/* 'C' function for method : 'DeviceInterface::NavigationDeviceClass.SkipNextStop()' */
void DeviceInterfaceNavigationDeviceClass_SkipNextStop( DeviceInterfaceNavigationDeviceClass _this )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  NAVI_send_skip_next_waypoint_request();
}

/* 'C' function for method : 'DeviceInterface::NavigationDeviceClass.GoHome()' */
void DeviceInterfaceNavigationDeviceClass_GoHome( DeviceInterfaceNavigationDeviceClass _this, 
  XEnum aRouteOption )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  NAVI_send_go_home_request( aRouteOption );
}

/* 'C' function for method : 'DeviceInterface::NavigationDeviceClass.GoOffice()' */
void DeviceInterfaceNavigationDeviceClass_GoOffice( DeviceInterfaceNavigationDeviceClass _this, 
  XEnum aRouteOption )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  NAVI_send_go_office_request( aRouteOption );
}

/* 'C' function for method : 'DeviceInterface::NavigationDeviceClass.ZoomInRequest()' */
void DeviceInterfaceNavigationDeviceClass_ZoomInRequest( DeviceInterfaceNavigationDeviceClass _this )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  NAVI_send_zoom_in_request();
}

/* 'C' function for method : 'DeviceInterface::NavigationDeviceClass.ZoomOutRequest()' */
void DeviceInterfaceNavigationDeviceClass_ZoomOutRequest( DeviceInterfaceNavigationDeviceClass _this )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  NAVI_send_zoom_out_request();
}

/* 'C' function for method : 'DeviceInterface::NavigationDeviceClass.GetZoomInOutStatus()' */
XEnum DeviceInterfaceNavigationDeviceClass_GetZoomInOutStatus( DeviceInterfaceNavigationDeviceClass _this )
{
  XEnum ZoomInOutStatus;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  ZoomInOutStatus = EnumNaviZoomInOutStatusTypeREACH_MAXIMUM;
  ZoomInOutStatus = NAVI_get_zoom_inout_status();
  return ZoomInOutStatus;
}

/* This method is intended to be called by the device to notify the GUI application 
   about a particular system event. */
void DeviceInterfaceNavigationDeviceClass_NotifyAlertDistanceUpdate( DeviceInterfaceNavigationDeviceClass _this )
{
  CoreSystemEvent_Trigger( &_this->AlertDistanceUpdateEvent, 0, 0 );
}

/* Wrapper function for the non virtual method : 'DeviceInterface::NavigationDeviceClass.NotifyAlertDistanceUpdate()' */
void DeviceInterfaceNavigationDeviceClass__NotifyAlertDistanceUpdate( void* _this )
{
  DeviceInterfaceNavigationDeviceClass_NotifyAlertDistanceUpdate((DeviceInterfaceNavigationDeviceClass)_this );
}

/* 'C' function for method : 'DeviceInterface::NavigationDeviceClass.GetAlertDistance()' */
XString DeviceInterfaceNavigationDeviceClass_GetAlertDistance( DeviceInterfaceNavigationDeviceClass _this )
{
  XString Dist;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  Dist = 0;
  {
    char* dist;
    NAVI_get_alert_distance( &dist );
    Dist = EwNewStringUtf8( ( const unsigned char* )dist, ( int )strlen( dist ) );
  }
  return Dist;
}

/* This method is intended to be called by the device to notify the GUI application 
   about a particular system event. */
void DeviceInterfaceNavigationDeviceClass_NotifyNaviConnectUpdate( DeviceInterfaceNavigationDeviceClass _this )
{
  CoreSystemEvent_Trigger( &_this->ConnectStatusUpdateEvent, 0, 0 );
}

/* Wrapper function for the non virtual method : 'DeviceInterface::NavigationDeviceClass.NotifyNaviConnectUpdate()' */
void DeviceInterfaceNavigationDeviceClass__NotifyNaviConnectUpdate( void* _this )
{
  DeviceInterfaceNavigationDeviceClass_NotifyNaviConnectUpdate((DeviceInterfaceNavigationDeviceClass)_this );
}

/* This method is intended to be called by the device to notify the GUI application 
   about a particular system event. */
void DeviceInterfaceNavigationDeviceClass_NotifyNaviDisconnectUpdate( DeviceInterfaceNavigationDeviceClass _this )
{
  CoreSystemEvent_Trigger( &_this->DisconnectStatusUpdateEvent, 0, 0 );
}

/* Wrapper function for the non virtual method : 'DeviceInterface::NavigationDeviceClass.NotifyNaviDisconnectUpdate()' */
void DeviceInterfaceNavigationDeviceClass__NotifyNaviDisconnectUpdate( void* _this )
{
  DeviceInterfaceNavigationDeviceClass_NotifyNaviDisconnectUpdate((DeviceInterfaceNavigationDeviceClass)_this );
}

/* 'C' function for method : 'DeviceInterface::NavigationDeviceClass.StartMapFrameRequest()' */
void DeviceInterfaceNavigationDeviceClass_StartMapFrameRequest( DeviceInterfaceNavigationDeviceClass _this )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  NAVI_start_map_update();
}

/* 'C' function for method : 'DeviceInterface::NavigationDeviceClass.IsTbtMessageDisplayed()' */
XBool DeviceInterfaceNavigationDeviceClass_IsTbtMessageDisplayed( DeviceInterfaceNavigationDeviceClass _this )
{
  XBool ShowTbtMessage;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  ShowTbtMessage = 0;
  ShowTbtMessage = NAVI_is_tbt_message_displayed();
  return ShowTbtMessage;
}

/* 'C' function for method : 'DeviceInterface::NavigationDeviceClass.GetTbtListSize()' */
XInt32 DeviceInterfaceNavigationDeviceClass_GetTbtListSize( DeviceInterfaceNavigationDeviceClass _this )
{
  XInt32 TbtListSize;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  TbtListSize = 0;
  TbtListSize = NAVI_get_tbt_list_size();
  return TbtListSize;
}

/* This method is intended to be called by the device to notify the GUI application 
   about a particular system event. */
void DeviceInterfaceNavigationDeviceClass_NotifyPoiListUpdate( DeviceInterfaceNavigationDeviceClass _this )
{
  CoreSystemEvent_Trigger( &_this->PoiListUpdateEvent, 0, 0 );
}

/* Wrapper function for the non virtual method : 'DeviceInterface::NavigationDeviceClass.NotifyPoiListUpdate()' */
void DeviceInterfaceNavigationDeviceClass__NotifyPoiListUpdate( void* _this )
{
  DeviceInterfaceNavigationDeviceClass_NotifyPoiListUpdate((DeviceInterfaceNavigationDeviceClass)_this );
}

/* 'C' function for method : 'DeviceInterface::NavigationDeviceClass.GetPoiListSize()' */
XInt32 DeviceInterfaceNavigationDeviceClass_GetPoiListSize( DeviceInterfaceNavigationDeviceClass _this )
{
  XInt32 PoiListSize;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  PoiListSize = 0;
  PoiListSize = NAVI_get_poi_list_size();
  return PoiListSize;
}

/* 'C' function for method : 'DeviceInterface::NavigationDeviceClass.GetNaviPoiData()' */
DeviceInterfaceNaviPoiDataClass DeviceInterfaceNavigationDeviceClass_GetNaviPoiData( DeviceInterfaceNavigationDeviceClass _this, 
  XInt32 aPoiItemIdx )
{
  DeviceInterfaceNaviPoiDataClass NaviPoiData;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  NaviPoiData = EwNewObject( DeviceInterfaceNaviPoiDataClass, 0 );
  {
    float distance;
    char* dist_unit;
    char* description;
    NAVI_get_poi_item( aPoiItemIdx, &distance, &dist_unit, &description );
    NaviPoiData->Distance = distance;
    NaviPoiData->DistUnit = EwNewStringUtf8( ( const unsigned char* )dist_unit, ( int )strlen( dist_unit ) );
    NaviPoiData->PoiTitle = EwNewStringUtf8( ( const unsigned char* )description, ( int )strlen( description ) );
  }
  return NaviPoiData;
}

/* 'C' function for method : 'DeviceInterface::NavigationDeviceClass.PoiListRequest()' */
void DeviceInterfaceNavigationDeviceClass_PoiListRequest( DeviceInterfaceNavigationDeviceClass _this, 
  XEnum PoiListType, XBool aEnabled )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  NAVI_poi_list_request( PoiListType, aEnabled );
}

/* 'C' function for method : 'DeviceInterface::NavigationDeviceClass.StartRoute()' */
void DeviceInterfaceNavigationDeviceClass_StartRoute( DeviceInterfaceNavigationDeviceClass _this, 
  XInt32 aPoiIdx, XEnum aRouteOptionType )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  NAVI_send_start_route_request( aPoiIdx, aRouteOptionType );
}

/* 'C' function for method : 'DeviceInterface::NavigationDeviceClass.GetNaviDialogTimeOut()' */
XInt32 DeviceInterfaceNavigationDeviceClass_GetNaviDialogTimeOut( DeviceInterfaceNavigationDeviceClass _this )
{
  XInt32 NaviDialogTimeOut;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  NaviDialogTimeOut = 0;
  {
    navi_dialog_type* navi_dialog_obj = NULL;
    navi_dialog_obj = NAVI_get_navi_dialog_obj();
    NaviDialogTimeOut = navi_dialog_obj->timeout;
  }
  return NaviDialogTimeOut;
}

/* 'C' function for method : 'DeviceInterface::NavigationDeviceClass.GetNaviDialogDefaultButton()' */
XEnum DeviceInterfaceNavigationDeviceClass_GetNaviDialogDefaultButton( DeviceInterfaceNavigationDeviceClass _this )
{
  XEnum DefaultButton;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  DefaultButton = EnumNaviButtonTypeOK;
  {
    navi_dialog_type* navi_dialog_obj = NULL;
    navi_dialog_obj = NAVI_get_navi_dialog_obj();
    DefaultButton = navi_dialog_obj->default_selected_button;
  }
  return DefaultButton;
}

/* 'C' function for method : 'DeviceInterface::NavigationDeviceClass.OnGetNaviAppSppConnected()' */
XBool DeviceInterfaceNavigationDeviceClass_OnGetNaviAppSppConnected( DeviceInterfaceNavigationDeviceClass _this )
{
  XBool IsNaviAppSppConnected;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  IsNaviAppSppConnected = 0;
  IsNaviAppSppConnected = CM_get_spp_connection_status( CM_APP_NAVILITE );
  return IsNaviAppSppConnected;
}

/* This method is intended to be called by the device to notify the GUI application 
   about a particular system event. */
void DeviceInterfaceNavigationDeviceClass_NotifyBtThroughputStatusUpdate( DeviceInterfaceNavigationDeviceClass _this )
{
  CoreSystemEvent_Trigger( &_this->BtThroughputStatusUpdateEvent, 0, 0 );
}

/* Wrapper function for the non virtual method : 'DeviceInterface::NavigationDeviceClass.NotifyBtThroughputStatusUpdate()' */
void DeviceInterfaceNavigationDeviceClass__NotifyBtThroughputStatusUpdate( void* _this )
{
  DeviceInterfaceNavigationDeviceClass_NotifyBtThroughputStatusUpdate((DeviceInterfaceNavigationDeviceClass)_this );
}

/* 'C' function for method : 'DeviceInterface::NavigationDeviceClass.GetBtThroughputUIMode()' */
XEnum DeviceInterfaceNavigationDeviceClass_GetBtThroughputUIMode( DeviceInterfaceNavigationDeviceClass _this )
{
  XEnum BtThroughputUIMode;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  BtThroughputUIMode = EnumNaviBtThroughputUIModeBUSY;
  {
    #if( !UNIT_TEST_NAVI )
      BtThroughputUIMode = NAVI_get_navi_bt_throughput_ui_mode();
    #else
      BtThroughputUIMode = TEST_get_bt_throughput_status();
    #endif
  }
  return BtThroughputUIMode;
}

/* 'C' function for method : 'DeviceInterface::NavigationDeviceClass.StopContentRequest()' */
void DeviceInterfaceNavigationDeviceClass_StopContentRequest( DeviceInterfaceNavigationDeviceClass _this )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  NAVI_stop_content_update();
}

/* 'C' function for method : 'DeviceInterface::NavigationDeviceClass.StartContentRequest()' */
void DeviceInterfaceNavigationDeviceClass_StartContentRequest( DeviceInterfaceNavigationDeviceClass _this )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  NAVI_start_content_update();
}

/* 'C' function for method : 'DeviceInterface::NavigationDeviceClass.IsJcvReceived()' */
XBool DeviceInterfaceNavigationDeviceClass_IsJcvReceived( DeviceInterfaceNavigationDeviceClass _this )
{
  XBool ShowJcv;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  ShowJcv = 0;
  ShowJcv = NAVI_is_Jcv_recevied();
  return ShowJcv;
}

/* 'C' function for method : 'DeviceInterface::NavigationDeviceClass.IsReRouteAlertReceived()' */
XBool DeviceInterfaceNavigationDeviceClass_IsReRouteAlertReceived( DeviceInterfaceNavigationDeviceClass _this )
{
  XBool ReRouteEventStatus;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  ReRouteEventStatus = 0;
  ReRouteEventStatus = NAVI_is_specified_event_received( EnumNaviAlertTypeTRAFFIC, EnumNaviCameraTypeTYPE_UNDEFINED );
  return ReRouteEventStatus;
}

/* 'C' function for method : 'DeviceInterface::NavigationDeviceClass.RemoteReRouteAlert()' */
void DeviceInterfaceNavigationDeviceClass_RemoteReRouteAlert( DeviceInterfaceNavigationDeviceClass _this )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  NAVI_remove_specified_event( EnumNaviAlertTypeTRAFFIC, EnumNaviCameraTypeTYPE_UNDEFINED );
}

/* 'C' function for method : 'DeviceInterface::NavigationDeviceClass.IsSpeedingAlertReceived()' */
XBool DeviceInterfaceNavigationDeviceClass_IsSpeedingAlertReceived( DeviceInterfaceNavigationDeviceClass _this )
{
  XBool SpeedingEventStatus;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  SpeedingEventStatus = 0;
  SpeedingEventStatus = NAVI_is_specified_event_received( EnumNaviAlertTypeSPEED, EnumNaviCameraTypeTYPE_UNDEFINED );
  return SpeedingEventStatus;
}

/* 'C' function for method : 'DeviceInterface::NavigationDeviceClass.GetRerouteAlertMessage()' */
XString DeviceInterfaceNavigationDeviceClass_GetRerouteAlertMessage( DeviceInterfaceNavigationDeviceClass _this )
{
  XString Message;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  Message = 0;
  {
    char* reroute_message;
    NAVI_get_reroute_alert_message( &reroute_message );
    Message = EwNewStringUtf8( ( const unsigned char* )reroute_message, ( int )strlen( reroute_message ) );
  }
  return Message;
}

/* 'C' function for method : 'DeviceInterface::NavigationDeviceClass.GetAlertDisplayStatus()' */
XBool DeviceInterfaceNavigationDeviceClass_GetAlertDisplayStatus( DeviceInterfaceNavigationDeviceClass _this )
{
  XBool AlertDisplayStatus;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  AlertDisplayStatus = 0;
  AlertDisplayStatus = NAVI_get_alert_display_status();
  return AlertDisplayStatus;
}

/* 'C' function for method : 'DeviceInterface::NavigationDeviceClass.EnableAlertDisplayFlag()' */
void DeviceInterfaceNavigationDeviceClass_EnableAlertDisplayFlag( DeviceInterfaceNavigationDeviceClass _this )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  NAVI_enable_alert_display_flag();
}

/* 'C' function for method : 'DeviceInterface::NavigationDeviceClass.RemoveSpeedingAlert()' */
void DeviceInterfaceNavigationDeviceClass_RemoveSpeedingAlert( DeviceInterfaceNavigationDeviceClass _this )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  NAVI_remove_specified_event( EnumNaviAlertTypeSPEED, EnumNaviCameraTypeTYPE_UNDEFINED );
}

/* 'C' function for method : 'DeviceInterface::NavigationDeviceClass.GetAppInitStatus()' */
XBool DeviceInterfaceNavigationDeviceClass_GetAppInitStatus( DeviceInterfaceNavigationDeviceClass _this )
{
  XBool IsNaviAppInit;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  IsNaviAppInit = 0;
  IsNaviAppInit = NAVI_get_app_init_status();
  return IsNaviAppInit;
}

/* 'C' function for method : 'DeviceInterface::NavigationDeviceClass.ResetDialogObject()' */
void DeviceInterfaceNavigationDeviceClass_ResetDialogObject( DeviceInterfaceNavigationDeviceClass _this )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  NAVI_reset_dialog_object();
}

/* Variants derived from the class : 'DeviceInterface::NavigationDeviceClass' */
EW_DEFINE_CLASS_VARIANTS( DeviceInterfaceNavigationDeviceClass )
EW_END_OF_CLASS_VARIANTS( DeviceInterfaceNavigationDeviceClass )

/* Virtual Method Table (VMT) for the class : 'DeviceInterface::NavigationDeviceClass' */
EW_DEFINE_CLASS( DeviceInterfaceNavigationDeviceClass, TemplatesDeviceClass, MapUpdateEvent, 
                 MapUpdateEvent, MapUpdateEvent, MapUpdateEvent, CurrentSelectPoiIdx, 
                 CurrentSelectPoiIdx, "DeviceInterface::NavigationDeviceClass" )
EW_END_OF_CLASS( DeviceInterfaceNavigationDeviceClass )

/* User defined auto object: 'DeviceInterface::NavigationDevice' */
EW_DEFINE_AUTOOBJECT( DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass )

/* Initializer for the auto object 'DeviceInterface::NavigationDevice' */
void DeviceInterfaceNavigationDevice__Init( DeviceInterfaceNavigationDeviceClass _this )
{
  EW_UNUSED_ARG( _this );
}

/* Table with links to derived variants of the auto object : 'DeviceInterface::NavigationDevice' */
EW_DEFINE_AUTOOBJECT_VARIANTS( DeviceInterfaceNavigationDevice )
EW_END_OF_AUTOOBJECT_VARIANTS( DeviceInterfaceNavigationDevice )

/* Initializer for the class 'DeviceInterface::MediaManagerDeviceClass' */
void DeviceInterfaceMediaManagerDeviceClass__Init( DeviceInterfaceMediaManagerDeviceClass _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  TemplatesDeviceClass__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( DeviceInterfaceMediaManagerDeviceClass );

  /* ... then construct all embedded objects */
  CoreSystemEvent__Init( &_this->NotifyPlayBackTimeChangedSystemEvent, &_this->_.XObject, 0 );
  CoreSystemEvent__Init( &_this->NotifyMotoConMusicUpdatedSystemEvent, &_this->_.XObject, 0 );
  CoreSystemEvent__Init( &_this->NotifyAmsBleConnectedStatusSystemEvent, &_this->_.XObject, 0 );
  CoreSystemEvent__Init( &_this->NotifyMediaVolumeUpdateSystemEvent, &_this->_.XObject, 0 );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( DeviceInterfaceMediaManagerDeviceClass );
}

/* Re-Initializer for the class 'DeviceInterface::MediaManagerDeviceClass' */
void DeviceInterfaceMediaManagerDeviceClass__ReInit( DeviceInterfaceMediaManagerDeviceClass _this )
{
  /* At first re-initialize the super class ... */
  TemplatesDeviceClass__ReInit( &_this->_.Super );

  /* ... then re-construct all embedded objects */
  CoreSystemEvent__ReInit( &_this->NotifyPlayBackTimeChangedSystemEvent );
  CoreSystemEvent__ReInit( &_this->NotifyMotoConMusicUpdatedSystemEvent );
  CoreSystemEvent__ReInit( &_this->NotifyAmsBleConnectedStatusSystemEvent );
  CoreSystemEvent__ReInit( &_this->NotifyMediaVolumeUpdateSystemEvent );
}

/* Finalizer method for the class 'DeviceInterface::MediaManagerDeviceClass' */
void DeviceInterfaceMediaManagerDeviceClass__Done( DeviceInterfaceMediaManagerDeviceClass _this )
{
  /* Finalize this class */
  _this->_.Super._.VMT = EW_CLASS( TemplatesDeviceClass );

  /* Finalize all embedded objects */
  CoreSystemEvent__Done( &_this->NotifyPlayBackTimeChangedSystemEvent );
  CoreSystemEvent__Done( &_this->NotifyMotoConMusicUpdatedSystemEvent );
  CoreSystemEvent__Done( &_this->NotifyAmsBleConnectedStatusSystemEvent );
  CoreSystemEvent__Done( &_this->NotifyMediaVolumeUpdateSystemEvent );

  /* Don't forget to deinitialize the super class ... */
  TemplatesDeviceClass__Done( &_this->_.Super );
}

/* 'C' function for method : 'DeviceInterface::MediaManagerDeviceClass.OnSetTitle()' */
void DeviceInterfaceMediaManagerDeviceClass_OnSetTitle( DeviceInterfaceMediaManagerDeviceClass _this, 
  XString value )
{
  if ( _this->IsTitleReceived || _this->IsInit )
    _this->Title = EwShareString( value );
  else
    _this->Title = EwShareString( EwLoadString( &StringsGEN_THREE_HYPHENS ));

  EwNotifyRefObservers( EwNewRef( _this, DeviceInterfaceMediaManagerDeviceClass_OnGetTitle, 
    DeviceInterfaceMediaManagerDeviceClass_OnSetTitle ), 0 );
}

/* 'C' function for method : 'DeviceInterface::MediaManagerDeviceClass.OnSetAlbum()' */
void DeviceInterfaceMediaManagerDeviceClass_OnSetAlbum( DeviceInterfaceMediaManagerDeviceClass _this, 
  XString value )
{
  if ( _this->IsAlbumReceived || _this->IsInit )
    _this->Album = EwShareString( value );
  else
    _this->Album = EwShareString( EwLoadString( &StringsGEN_THREE_HYPHENS ));

  EwNotifyRefObservers( EwNewRef( _this, DeviceInterfaceMediaManagerDeviceClass_OnGetAlbum, 
    DeviceInterfaceMediaManagerDeviceClass_OnSetAlbum ), 0 );
}

/* 'C' function for method : 'DeviceInterface::MediaManagerDeviceClass.OnSetArtist()' */
void DeviceInterfaceMediaManagerDeviceClass_OnSetArtist( DeviceInterfaceMediaManagerDeviceClass _this, 
  XString value )
{
  if ( _this->IsArtistReceived || _this->IsInit )
    _this->Artist = EwShareString( value );
  else
    _this->Artist = EwShareString( EwLoadString( &StringsGEN_THREE_HYPHENS ));

  EwNotifyRefObservers( EwNewRef( _this, DeviceInterfaceMediaManagerDeviceClass_OnGetArtist, 
    DeviceInterfaceMediaManagerDeviceClass_OnSetArtist ), 0 );
}

/* 'C' function for method : 'DeviceInterface::MediaManagerDeviceClass.SendRemoteCommand()' */
void DeviceInterfaceMediaManagerDeviceClass_SendRemoteCommand( DeviceInterfaceMediaManagerDeviceClass _this, 
  XEnum MusicCommandType )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  {
    ams_remote_command cmd = AMS_REMOTE_COMMAND_CNT;

    switch( MusicCommandType )
    {
      case EnumMusicControlTypePlay:
        cmd = AMS_REMOTE_COMMAND_PLAY;
        break;
      case EnumMusicControlTypePause:
        cmd = AMS_REMOTE_COMMAND_PAUSE;
        break;
      case EnumMusicControlTypeNextTrack:
        cmd = AMS_REMOTE_COMMAND_NEXT_TRACK;
        break;
      case EnumMusicControlTypePrevTrack:
        cmd = AMS_REMOTE_COMMAND_PREVIOUS_TRACK;
        break;
      case EnumMusicControlTypeVolumeUp:
        cmd = AMS_REMOTE_COMMAND_VOLUME_UP;
        break;
      case EnumMusicControlTypeVolumeDown:
        cmd = AMS_REMOTE_COMMAND_VOLUME_DOWN;
        break;
      default:
        break;
    }
    ew_send_command( cmd );
  }
}

/* 'C' function for method : 'DeviceInterface::MediaManagerDeviceClass.NotifyTitleChanged()' */
void DeviceInterfaceMediaManagerDeviceClass_NotifyTitleChanged( DeviceInterfaceMediaManagerDeviceClass _this, 
  XString aTitle )
{
  EwTrace( "%s", EwConcatString( EwLoadString( &_Const0003 ), aTitle ));
  _this->IsTitleReceived = 1;
  DeviceInterfaceMediaManagerDeviceClass_OnSetTitle( _this, aTitle );
}

/* Wrapper function for the non virtual method : 'DeviceInterface::MediaManagerDeviceClass.NotifyTitleChanged()' */
void DeviceInterfaceMediaManagerDeviceClass__NotifyTitleChanged( void* _this, XString 
  aTitle )
{
  DeviceInterfaceMediaManagerDeviceClass_NotifyTitleChanged((DeviceInterfaceMediaManagerDeviceClass)_this
  , aTitle );
}

/* 'C' function for method : 'DeviceInterface::MediaManagerDeviceClass.NotifyArtistChanged()' */
void DeviceInterfaceMediaManagerDeviceClass_NotifyArtistChanged( DeviceInterfaceMediaManagerDeviceClass _this, 
  XString aArtist )
{
  EwTrace( "%s", EwConcatString( EwLoadString( &_Const0004 ), aArtist ));
  _this->IsArtistReceived = 1;
  DeviceInterfaceMediaManagerDeviceClass_OnSetArtist( _this, aArtist );
}

/* Wrapper function for the non virtual method : 'DeviceInterface::MediaManagerDeviceClass.NotifyArtistChanged()' */
void DeviceInterfaceMediaManagerDeviceClass__NotifyArtistChanged( void* _this, XString 
  aArtist )
{
  DeviceInterfaceMediaManagerDeviceClass_NotifyArtistChanged((DeviceInterfaceMediaManagerDeviceClass)_this
  , aArtist );
}

/* 'C' function for method : 'DeviceInterface::MediaManagerDeviceClass.NotifyAlbumChanged()' */
void DeviceInterfaceMediaManagerDeviceClass_NotifyAlbumChanged( DeviceInterfaceMediaManagerDeviceClass _this, 
  XString aAlbum )
{
  EwTrace( "%s", EwConcatString( EwLoadString( &_Const0005 ), aAlbum ));
  _this->IsAlbumReceived = 1;
  DeviceInterfaceMediaManagerDeviceClass_OnSetAlbum( _this, aAlbum );
}

/* Wrapper function for the non virtual method : 'DeviceInterface::MediaManagerDeviceClass.NotifyAlbumChanged()' */
void DeviceInterfaceMediaManagerDeviceClass__NotifyAlbumChanged( void* _this, XString 
  aAlbum )
{
  DeviceInterfaceMediaManagerDeviceClass_NotifyAlbumChanged((DeviceInterfaceMediaManagerDeviceClass)_this
  , aAlbum );
}

/* 'C' function for method : 'DeviceInterface::MediaManagerDeviceClass.GetPlayBackStateInfo()' */
XInt32 DeviceInterfaceMediaManagerDeviceClass_GetPlayBackStateInfo( DeviceInterfaceMediaManagerDeviceClass _this )
{
  XInt32 PlayBackState;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  PlayBackState = 0;
  {
    mm_media_player_obj* mp_state = NULL;
    mp_state = ew_get_media_player_state();
    PlayBackState = mp_state->playback_state;
  }
  return PlayBackState;
}

/* 'C' function for method : 'DeviceInterface::MediaManagerDeviceClass.GetPlaybackInfo()' */
void DeviceInterfaceMediaManagerDeviceClass_GetPlaybackInfo( DeviceInterfaceMediaManagerDeviceClass _this )
{
  XInt32 ela_time = 0;
  XInt32 dur = 0;

  {
    mm_media_player_obj* mp_state = NULL;
    mp_state = ew_get_media_player_state();
    ela_time = mp_state->current_elapsed_time_sec;
    dur = mp_state->duration_sec;
  }
  _this->ElapsedTimeSec = ela_time;
  _this->DurationTimeSec = dur;
}

/* 'C' function for method : 'DeviceInterface::MediaManagerDeviceClass.GetTrackInfo()' */
void DeviceInterfaceMediaManagerDeviceClass_GetTrackInfo( DeviceInterfaceMediaManagerDeviceClass _this )
{
  XString media_artist = 0;
  XString media_album = 0;
  XString media_title = 0;

  {
    mm_media_player_obj* mp_state = NULL;
    mp_state = ew_get_media_player_state();
    media_artist = EwNewStringUtf8( ( const unsigned char* )mp_state->str.track_artist, ( int )strlen( mp_state->str.track_artist ) );
    media_album = EwNewStringUtf8( ( const unsigned char* )mp_state->str.track_album, ( int )strlen( mp_state->str.track_album ) );
    media_title = EwNewStringUtf8( ( const unsigned char* )mp_state->str.track_title, ( int )strlen( mp_state->str.track_title ) );
  }
  DeviceInterfaceMediaManagerDeviceClass_OnSetArtist( _this, media_artist );
  DeviceInterfaceMediaManagerDeviceClass_OnSetAlbum( _this, media_album );
  DeviceInterfaceMediaManagerDeviceClass_OnSetTitle( _this, media_title );
}

/* This method is intended to be called by the device to notify the GUI application 
   about a particular system event. */
void DeviceInterfaceMediaManagerDeviceClass_NotifyPlayBackTimeChanged( DeviceInterfaceMediaManagerDeviceClass _this, 
  XInt32 aElapsedTimeSec, XInt32 aDurationTimeSec )
{
  EwTrace( "%s%i", EwLoadString( &_Const0006 ), aElapsedTimeSec );
  EwTrace( "%s%i", EwLoadString( &_Const0007 ), aDurationTimeSec );
  _this->ElapsedTimeSec = aElapsedTimeSec;
  _this->DurationTimeSec = aDurationTimeSec;
  CoreSystemEvent_Trigger( &_this->NotifyPlayBackTimeChangedSystemEvent, 0, 0 );
}

/* Wrapper function for the non virtual method : 'DeviceInterface::MediaManagerDeviceClass.NotifyPlayBackTimeChanged()' */
void DeviceInterfaceMediaManagerDeviceClass__NotifyPlayBackTimeChanged( void* _this, 
  XInt32 aElapsedTimeSec, XInt32 aDurationTimeSec )
{
  DeviceInterfaceMediaManagerDeviceClass_NotifyPlayBackTimeChanged((DeviceInterfaceMediaManagerDeviceClass)_this
  , aElapsedTimeSec, aDurationTimeSec );
}

/* This method is intended to be called by the device to notify the GUI application 
   about a particular system event. */
void DeviceInterfaceMediaManagerDeviceClass_NotfiyMotoConMusicInfoUpdated( DeviceInterfaceMediaManagerDeviceClass _this )
{
  _this->IsTitleReceived = 1;
  _this->IsAlbumReceived = 1;
  _this->IsArtistReceived = 1;
  CoreSystemEvent_Trigger( &_this->NotifyMotoConMusicUpdatedSystemEvent, 0, 0 );
}

/* Wrapper function for the non virtual method : 'DeviceInterface::MediaManagerDeviceClass.NotfiyMotoConMusicInfoUpdated()' */
void DeviceInterfaceMediaManagerDeviceClass__NotfiyMotoConMusicInfoUpdated( void* _this )
{
  DeviceInterfaceMediaManagerDeviceClass_NotfiyMotoConMusicInfoUpdated((DeviceInterfaceMediaManagerDeviceClass)_this );
}

/* 'C' function for method : 'DeviceInterface::MediaManagerDeviceClass.IsAmsConnected()' */
XBool DeviceInterfaceMediaManagerDeviceClass_IsAmsConnected( DeviceInterfaceMediaManagerDeviceClass _this )
{
  XBool AmsConnected;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  AmsConnected = 0;
  AmsConnected = BC_ams_is_ams_connected();
  return AmsConnected;
}

/* This method is intended to be called by the device to notify the GUI application 
   about a particular system event. */
void DeviceInterfaceMediaManagerDeviceClass_NotifyAmsBleConnectedStatusChanged( DeviceInterfaceMediaManagerDeviceClass _this )
{
  CoreSystemEvent_Trigger( &_this->NotifyAmsBleConnectedStatusSystemEvent, 0, 0 );
}

/* Wrapper function for the non virtual method : 'DeviceInterface::MediaManagerDeviceClass.NotifyAmsBleConnectedStatusChanged()' */
void DeviceInterfaceMediaManagerDeviceClass__NotifyAmsBleConnectedStatusChanged( void* _this )
{
  DeviceInterfaceMediaManagerDeviceClass_NotifyAmsBleConnectedStatusChanged((DeviceInterfaceMediaManagerDeviceClass)_this );
}

/* This method is intended to be called by the device to notify the GUI application 
   about a particular system event. */
void DeviceInterfaceMediaManagerDeviceClass_NotifyMediaVolumeUpdated( DeviceInterfaceMediaManagerDeviceClass _this )
{
  CoreSystemEvent_Trigger( &_this->NotifyMediaVolumeUpdateSystemEvent, 0, 0 );
}

/* Wrapper function for the non virtual method : 'DeviceInterface::MediaManagerDeviceClass.NotifyMediaVolumeUpdated()' */
void DeviceInterfaceMediaManagerDeviceClass__NotifyMediaVolumeUpdated( void* _this )
{
  DeviceInterfaceMediaManagerDeviceClass_NotifyMediaVolumeUpdated((DeviceInterfaceMediaManagerDeviceClass)_this );
}

/* 'C' function for method : 'DeviceInterface::MediaManagerDeviceClass.GetVolume()' */
XFloat DeviceInterfaceMediaManagerDeviceClass_GetVolume( DeviceInterfaceMediaManagerDeviceClass _this )
{
  XFloat Volume;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  Volume = 0.000000f;
  {
    mm_media_player_obj* mp_state = NULL;
    mp_state = ew_get_media_player_state();
    Volume = mp_state->playback_volume;
  }
  return Volume;
}

/* Default onget method for the property 'Title' */
XString DeviceInterfaceMediaManagerDeviceClass_OnGetTitle( DeviceInterfaceMediaManagerDeviceClass _this )
{
  return _this->Title;
}

/* Default onget method for the property 'Album' */
XString DeviceInterfaceMediaManagerDeviceClass_OnGetAlbum( DeviceInterfaceMediaManagerDeviceClass _this )
{
  return _this->Album;
}

/* Default onget method for the property 'Artist' */
XString DeviceInterfaceMediaManagerDeviceClass_OnGetArtist( DeviceInterfaceMediaManagerDeviceClass _this )
{
  return _this->Artist;
}

/* Variants derived from the class : 'DeviceInterface::MediaManagerDeviceClass' */
EW_DEFINE_CLASS_VARIANTS( DeviceInterfaceMediaManagerDeviceClass )
EW_END_OF_CLASS_VARIANTS( DeviceInterfaceMediaManagerDeviceClass )

/* Virtual Method Table (VMT) for the class : 'DeviceInterface::MediaManagerDeviceClass' */
EW_DEFINE_CLASS( DeviceInterfaceMediaManagerDeviceClass, TemplatesDeviceClass, NotifyPlayBackTimeChangedSystemEvent, 
                 NotifyPlayBackTimeChangedSystemEvent, NotifyPlayBackTimeChangedSystemEvent, 
                 NotifyPlayBackTimeChangedSystemEvent, Title, DurationTimeSec, "DeviceInterface::MediaManagerDeviceClass" )
EW_END_OF_CLASS( DeviceInterfaceMediaManagerDeviceClass )

/* User defined auto object: 'DeviceInterface::MediaManagerDevice' */
EW_DEFINE_AUTOOBJECT( DeviceInterfaceMediaManagerDevice, DeviceInterfaceMediaManagerDeviceClass )

/* Initializer for the auto object 'DeviceInterface::MediaManagerDevice' */
void DeviceInterfaceMediaManagerDevice__Init( DeviceInterfaceMediaManagerDeviceClass _this )
{
  EW_UNUSED_ARG( _this );
}

/* Table with links to derived variants of the auto object : 'DeviceInterface::MediaManagerDevice' */
EW_DEFINE_AUTOOBJECT_VARIANTS( DeviceInterfaceMediaManagerDevice )
EW_END_OF_AUTOOBJECT_VARIANTS( DeviceInterfaceMediaManagerDevice )

/* Initializer for the class 'DeviceInterface::BluetoothDeviceClass' */
void DeviceInterfaceBluetoothDeviceClass__Init( DeviceInterfaceBluetoothDeviceClass _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  TemplatesDeviceClass__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( DeviceInterfaceBluetoothDeviceClass );

  /* ... then construct all embedded objects */
  CoreSystemEvent__Init( &_this->MotoConSystemEvent, &_this->_.XObject, 0 );
  CoreSystemEvent__Init( &_this->BtmStatusEvent, &_this->_.XObject, 0 );
  CoreSystemEvent__Init( &_this->ConnectionStatusEvent, &_this->_.XObject, 0 );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( DeviceInterfaceBluetoothDeviceClass );

  /* ... and initialize objects, variables, properties, etc. */
  _this->LogLevel = 3;
}

/* Re-Initializer for the class 'DeviceInterface::BluetoothDeviceClass' */
void DeviceInterfaceBluetoothDeviceClass__ReInit( DeviceInterfaceBluetoothDeviceClass _this )
{
  /* At first re-initialize the super class ... */
  TemplatesDeviceClass__ReInit( &_this->_.Super );

  /* ... then re-construct all embedded objects */
  CoreSystemEvent__ReInit( &_this->MotoConSystemEvent );
  CoreSystemEvent__ReInit( &_this->BtmStatusEvent );
  CoreSystemEvent__ReInit( &_this->ConnectionStatusEvent );
}

/* Finalizer method for the class 'DeviceInterface::BluetoothDeviceClass' */
void DeviceInterfaceBluetoothDeviceClass__Done( DeviceInterfaceBluetoothDeviceClass _this )
{
  /* Finalize this class */
  _this->_.Super._.VMT = EW_CLASS( TemplatesDeviceClass );

  /* Finalize all embedded objects */
  CoreSystemEvent__Done( &_this->MotoConSystemEvent );
  CoreSystemEvent__Done( &_this->BtmStatusEvent );
  CoreSystemEvent__Done( &_this->ConnectionStatusEvent );

  /* Don't forget to deinitialize the super class ... */
  TemplatesDeviceClass__Done( &_this->_.Super );
}

/* 'C' function for method : 'DeviceInterface::BluetoothDeviceClass.GetPairedDeviceList()' */
void DeviceInterfaceBluetoothDeviceClass_GetPairedDeviceList( DeviceInterfaceBluetoothDeviceClass _this )
{
  XInt32 DevIdx;
  XString DevName = 0;
  XUInt64 DevAddr = 0;

  for ( DevIdx = 0; DevIdx < _this->PairedDeviceNum; DevIdx++ )
  {
    DeviceInterfaceBtPairedDeviceInfo DevInfo;
    {
      BT_device_info_t device_info;
      uint8_t* stuffed_str = NULL;
      int32_t  stuffed_str_len;

      if( BT_STATUS_OK == BT_get_paired_device_info( DevIdx, &device_info ) )
      {
        stuffed_str_len = ew_handle_special_characters( device_info.device_name, &stuffed_str );
        if( ( 0 < stuffed_str_len ) && ( NULL != stuffed_str ) )
        {
          DevName = EwNewStringUtf8( stuffed_str, stuffed_str_len );
        }

        DevAddr = 0;
        for( int32_t i = 0; i < BT_DEVICE_ADDRESS_LEN; i++ )
        {
          DevAddr = ( DevAddr << 8 ) | device_info.bd_addr[i];
        }
      }
    }
    DevInfo = EwNewObject( DeviceInterfaceBtPairedDeviceInfo, 0 );
    DevInfo->DeviceName = EwShareString( DevName );
    DevInfo->DeviceAddress = DevAddr;
    _this->PairedDeviceList[ EwCheckIndex( DevIdx, 8 )] = DevInfo;
  }
}

/* 'C' function for method : 'DeviceInterface::BluetoothDeviceClass.OnSetDiscoverable()' */
void DeviceInterfaceBluetoothDeviceClass_OnSetDiscoverable( DeviceInterfaceBluetoothDeviceClass _this, 
  XBool value )
{
  if ( _this->Discoverable != value )
  {
    _this->Discoverable = value;
    BT_set_discoverable_state( (bool)value );
  }
}

/* 'C' function for method : 'DeviceInterface::BluetoothDeviceClass.OnSetBluetoothEnabled()' */
void DeviceInterfaceBluetoothDeviceClass_OnSetBluetoothEnabled( DeviceInterfaceBluetoothDeviceClass _this, 
  XBool value )
{
  if ( _this->BluetoothEnabled != value )
  {
    _this->BluetoothEnabled = value;
    BT_set_enable_state( (bool)value );
  }
}

/* 'C' function for method : 'DeviceInterface::BluetoothDeviceClass.OnGetBluetoothEnabled()' */
XBool DeviceInterfaceBluetoothDeviceClass_OnGetBluetoothEnabled( DeviceInterfaceBluetoothDeviceClass _this )
{
  XBool EnableStatus = 0;

  EnableStatus = BT_get_enable_state();
  _this->BluetoothEnabled = EnableStatus;
  return _this->BluetoothEnabled;
}

/* 'C' function for method : 'DeviceInterface::BluetoothDeviceClass.OnSetAutoConnect()' */
void DeviceInterfaceBluetoothDeviceClass_OnSetAutoConnect( DeviceInterfaceBluetoothDeviceClass _this, 
  XBool value )
{
  if ( _this->AutoConnect != value )
  {
    _this->AutoConnect = value;
    CM_set_auto_connect_state( value );
  }
}

/* 'C' function for method : 'DeviceInterface::BluetoothDeviceClass.OnGetAutoConnect()' */
XBool DeviceInterfaceBluetoothDeviceClass_OnGetAutoConnect( DeviceInterfaceBluetoothDeviceClass _this )
{
  XBool IsAutoConnect = 0;

  IsAutoConnect = CM_get_auto_connect_state();
  _this->AutoConnect = IsAutoConnect;
  return _this->AutoConnect;
}

/* 'C' function for method : 'DeviceInterface::BluetoothDeviceClass.UnpairDevice()' */
void DeviceInterfaceBluetoothDeviceClass_UnpairDevice( DeviceInterfaceBluetoothDeviceClass _this, 
  XUInt64 aDeviceAddress )
{
  XUInt64 DevAddr;

  DeviceInterfaceBluetoothDeviceClass_DeleteFromPairedDeviceList( _this, aDeviceAddress );
  DevAddr = aDeviceAddress;
  {
    uint8_t bd_addr[BT_DEVICE_ADDRESS_LEN];
    for( int32_t i = 0; i < BT_DEVICE_ADDRESS_LEN; i++ )
    {
      bd_addr[BT_DEVICE_ADDRESS_LEN - i - 1] = DevAddr >> ( 8*i );
    }
    BT_delete_paired_device( bd_addr );
  }
}

/* 'C' function for method : 'DeviceInterface::BluetoothDeviceClass.OnGetLocalDeviceName()' */
XString DeviceInterfaceBluetoothDeviceClass_OnGetLocalDeviceName( DeviceInterfaceBluetoothDeviceClass _this )
{
  XString LocalDevName;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  LocalDevName = 0;
  {
    const uint8_t* device_name = BT_get_local_device_name();
    LocalDevName = EwNewStringUtf8( device_name, (int)strlen( (char*)device_name ) );
  }
  return LocalDevName;
}

/* 'C' function for method : 'DeviceInterface::BluetoothDeviceClass.OnGetLocalDeviceAddress()' */
XString DeviceInterfaceBluetoothDeviceClass_OnGetLocalDeviceAddress( DeviceInterfaceBluetoothDeviceClass _this )
{
  XString DeviceAddr = 0;

  {
    const uint8_t* bd_addr = BT_get_local_device_address();
    char bd_addr_display[32];
    snprintf( bd_addr_display, 32, "%02x:%02x:%02x:%02x:%02x:%02x", bd_addr[0], bd_addr[1], bd_addr[2], bd_addr[3], bd_addr[4], bd_addr[5] );
    DeviceAddr = EwNewStringAnsi( (const char*)bd_addr_display );
  }
  _this->LocalDeviceAddress = EwShareString( DeviceAddr );
  return _this->LocalDeviceAddress;
}

/* 'C' function for method : 'DeviceInterface::BluetoothDeviceClass.ConnectPairedDevice()' */
void DeviceInterfaceBluetoothDeviceClass_ConnectPairedDevice( DeviceInterfaceBluetoothDeviceClass _this, 
  XUInt64 aDeviceAddress )
{
  XUInt64 DevAddr;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  DevAddr = aDeviceAddress;
  {
    uint8_t bd_addr[BT_DEVICE_ADDRESS_LEN];
    for( int32_t i = 0; i < BT_DEVICE_ADDRESS_LEN; i++ )
    {
      bd_addr[BT_DEVICE_ADDRESS_LEN - i - 1] = DevAddr >> ( 8*i );
    }
    CM_connect( bd_addr );
  }
}

/* 'C' function for method : 'DeviceInterface::BluetoothDeviceClass.DisconnectPairedDevice()' */
void DeviceInterfaceBluetoothDeviceClass_DisconnectPairedDevice( DeviceInterfaceBluetoothDeviceClass _this, 
  XUInt64 aDeviceAddress )
{
  XUInt64 DevAddr;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  DevAddr = aDeviceAddress;
  {
    uint8_t bd_addr[BT_DEVICE_ADDRESS_LEN];
    for( int32_t i = 0; i < BT_DEVICE_ADDRESS_LEN; i++ )
    {
      bd_addr[BT_DEVICE_ADDRESS_LEN - i - 1] = DevAddr >> ( 8*i );
    }
    CM_disconnect( bd_addr );
  }
}

/* 'C' function for method : 'DeviceInterface::BluetoothDeviceClass.OnGetIsPairedDeviceNumMax()' */
XBool DeviceInterfaceBluetoothDeviceClass_OnGetIsPairedDeviceNumMax( DeviceInterfaceBluetoothDeviceClass _this )
{
  XBool is_max_paired_device = 0;

  BT_is_paired_device_max_num_reached( (bool*)&is_max_paired_device );
  _this->IsPairedDeviceNumMax = is_max_paired_device;
  return _this->IsPairedDeviceNumMax;
}

/* 'C' function for method : 'DeviceInterface::BluetoothDeviceClass.IsMotoconConnected()' */
XBool DeviceInterfaceBluetoothDeviceClass_IsMotoconConnected( DeviceInterfaceBluetoothDeviceClass _this )
{
  XBool MotoconConnected;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  MotoconConnected = 0;
  MotoconConnected = BC_motocon_is_connected();
  return MotoconConnected;
}

/* 'C' function for method : 'DeviceInterface::BluetoothDeviceClass.NotifyMotoConEventReceived()' */
void DeviceInterfaceBluetoothDeviceClass_NotifyMotoConEventReceived( DeviceInterfaceBluetoothDeviceClass _this, 
  XEnum aEvent )
{
  DeviceInterfaceMotoConContext MotoConContext = EwNewObject( DeviceInterfaceMotoConContext, 
    0 );

  MotoConContext->RxEvent = aEvent;
  CoreSystemEvent_Trigger( &_this->MotoConSystemEvent, ((XObject)MotoConContext ), 
  0 );
}

/* Wrapper function for the non virtual method : 'DeviceInterface::BluetoothDeviceClass.NotifyMotoConEventReceived()' */
void DeviceInterfaceBluetoothDeviceClass__NotifyMotoConEventReceived( void* _this, 
  XEnum aEvent )
{
  DeviceInterfaceBluetoothDeviceClass_NotifyMotoConEventReceived((DeviceInterfaceBluetoothDeviceClass)_this
  , aEvent );
}

/* 'C' function for method : 'DeviceInterface::BluetoothDeviceClass.GetBtcPasskey()' */
XUInt32 DeviceInterfaceBluetoothDeviceClass_GetBtcPasskey( DeviceInterfaceBluetoothDeviceClass _this )
{
  XUInt32 Passkey;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  Passkey = 0;
  Passkey = ew_get_btc_passkey();
  return Passkey;
}

/* 'C' function for method : 'DeviceInterface::BluetoothDeviceClass.GetBtcPairingDeviceName()' */
XString DeviceInterfaceBluetoothDeviceClass_GetBtcPairingDeviceName( DeviceInterfaceBluetoothDeviceClass _this )
{
  XString PairingDeviceName;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  PairingDeviceName = 0;
  {
    uint8_t* btc_pairing_device_name;
    ew_bt_get_btc_connecting_device_name( &btc_pairing_device_name );

    uint8_t *stuffed_str = NULL;
    int32_t stuffed_str_len = ew_handle_special_characters( btc_pairing_device_name, &stuffed_str );
    if( stuffed_str_len > 0 && stuffed_str != NULL )
    {
      PairingDeviceName = EwNewStringUtf8( stuffed_str, stuffed_str_len );
    }
  }
  return PairingDeviceName;
}

/* 'C' function for method : 'DeviceInterface::BluetoothDeviceClass.SendMotoConCommand()' */
void DeviceInterfaceBluetoothDeviceClass_SendMotoConCommand( DeviceInterfaceBluetoothDeviceClass _this, 
  XEnum aTxCmd )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  ew_send_motocon_command( aTxCmd );
}

/* Wrapper function for the non virtual method : 'DeviceInterface::BluetoothDeviceClass.SendMotoConCommand()' */
void DeviceInterfaceBluetoothDeviceClass__SendMotoConCommand( void* _this, XEnum 
  aTxCmd )
{
  DeviceInterfaceBluetoothDeviceClass_SendMotoConCommand((DeviceInterfaceBluetoothDeviceClass)_this
  , aTxCmd );
}

/* 'C' function for method : 'DeviceInterface::BluetoothDeviceClass.NotifyBtmStatus()' */
void DeviceInterfaceBluetoothDeviceClass_NotifyBtmStatus( DeviceInterfaceBluetoothDeviceClass _this, 
  XEnum aStatus )
{
  DeviceInterfaceBtmStatusContext BtmStatusContext;

  EwTrace( "%s%e", EwLoadString( &_Const0008 ), aStatus );
  BtmStatusContext = EwNewObject( DeviceInterfaceBtmStatusContext, 0 );
  BtmStatusContext->Status = aStatus;
  CoreSystemEvent_Trigger( &_this->BtmStatusEvent, ((XObject)BtmStatusContext ), 
  0 );
}

/* Wrapper function for the non virtual method : 'DeviceInterface::BluetoothDeviceClass.NotifyBtmStatus()' */
void DeviceInterfaceBluetoothDeviceClass__NotifyBtmStatus( void* _this, XEnum aStatus )
{
  DeviceInterfaceBluetoothDeviceClass_NotifyBtmStatus((DeviceInterfaceBluetoothDeviceClass)_this
  , aStatus );
}

/* 'C' function for method : 'DeviceInterface::BluetoothDeviceClass.NotifyConnectionStatus()' */
void DeviceInterfaceBluetoothDeviceClass_NotifyConnectionStatus( DeviceInterfaceBluetoothDeviceClass _this, 
  XEnum aStatus )
{
  EwTrace( "%s%e", EwLoadString( &_Const0009 ), aStatus );

  switch ( aStatus )
  {
    case EnumConnectionStatusPAIRED_DEVICE_CHANGED :
      EwPostSignal( EwNewSlot( _this, DeviceInterfaceBluetoothDeviceClass_OnPairedDeviceListUpdatedSlot ), 
        ((XObject)_this ));
    break;

    case EnumConnectionStatusCONNECTED_APP_CHANGED :
      EwPostSignal( EwNewSlot( _this, DeviceInterfaceBluetoothDeviceClass_OnConnectedAppStatusUpdatedSlot ), 
        ((XObject)_this ));
    break;

    default : 
    {
      DeviceInterfaceConnectionStatusContext ConnectionStatusContext = EwNewObject( 
        DeviceInterfaceConnectionStatusContext, 0 );
      ConnectionStatusContext->Status = aStatus;
      CoreSystemEvent_Trigger( &_this->ConnectionStatusEvent, ((XObject)ConnectionStatusContext ), 
      0 );
    }
  }
}

/* Wrapper function for the non virtual method : 'DeviceInterface::BluetoothDeviceClass.NotifyConnectionStatus()' */
void DeviceInterfaceBluetoothDeviceClass__NotifyConnectionStatus( void* _this, XEnum 
  aStatus )
{
  DeviceInterfaceBluetoothDeviceClass_NotifyConnectionStatus((DeviceInterfaceBluetoothDeviceClass)_this
  , aStatus );
}

/* 'C' function for method : 'DeviceInterface::BluetoothDeviceClass.IsPairingDeviceYamahaAppSPPConnected()' */
XBool DeviceInterfaceBluetoothDeviceClass_IsPairingDeviceYamahaAppSPPConnected( DeviceInterfaceBluetoothDeviceClass _this )
{
  XBool Connected;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  Connected = 0;
  Connected = CM_get_spp_connection_status( CM_APP_YCONNECT );
  return Connected;
}

/* 'C' function for method : 'DeviceInterface::BluetoothDeviceClass.OnPairedDeviceListUpdatedSlot()' */
void DeviceInterfaceBluetoothDeviceClass_OnPairedDeviceListUpdatedSlot( DeviceInterfaceBluetoothDeviceClass _this, 
  XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  _this->PairedDeviceNum = DeviceInterfaceBluetoothDeviceClass_GetPairedDeviceNum( 
  _this );

  if ( 0 < _this->PairedDeviceNum )
  {
    DeviceInterfaceBluetoothDeviceClass_GetPairedDeviceList( _this );
    EwSignal( EwNewSlot( _this, DeviceInterfaceBluetoothDeviceClass_OnConnectedAppStatusUpdatedSlot ), 
      ((XObject)_this ));
  }
  else
    DeviceInterfaceBluetoothDeviceClass_NotifyConnectionStatus( _this, EnumConnectionStatusPAIRED_DEVICE_LIST_UPDATED );
}

/* 'C' function for method : 'DeviceInterface::BluetoothDeviceClass.OnConnectedAppStatusUpdatedSlot()' */
void DeviceInterfaceBluetoothDeviceClass_OnConnectedAppStatusUpdatedSlot( DeviceInterfaceBluetoothDeviceClass _this, 
  XObject sender )
{
  XInt32 i;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  for ( i = 0; i < _this->PairedDeviceNum; i++ )
  {
    _this->PairedDeviceList[ EwCheckIndex( i, 8 )]->IsNaviAppConnected = DeviceInterfaceBluetoothDeviceClass_GetNaviAppStatus( 
    _this, _this->PairedDeviceList[ EwCheckIndex( i, 8 )]->DeviceAddress );
    _this->PairedDeviceList[ EwCheckIndex( i, 8 )]->IsYamahaAppConnected = DeviceInterfaceBluetoothDeviceClass_GetYamahaAppStatus( 
    _this, _this->PairedDeviceList[ EwCheckIndex( i, 8 )]->DeviceAddress );
  }

  DeviceInterfaceBluetoothDeviceClass_NotifyConnectionStatus( _this, EnumConnectionStatusPAIRED_DEVICE_LIST_UPDATED );
}

/* 'C' function for method : 'DeviceInterface::BluetoothDeviceClass.GetPairedDeviceNum()' */
XInt32 DeviceInterfaceBluetoothDeviceClass_GetPairedDeviceNum( DeviceInterfaceBluetoothDeviceClass _this )
{
  XInt32 Num;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  Num = 0;
  {
    uint8_t paired_device_num = 0;
    if( BT_STATUS_OK == BT_get_num_paired_devices( &paired_device_num ) )
    {
      Num = paired_device_num;
    }
  }

  if ( 8 < Num )
    Num = 8;

  return Num;
}

/* 'C' function for method : 'DeviceInterface::BluetoothDeviceClass.GetNaviAppStatus()' */
XBool DeviceInterfaceBluetoothDeviceClass_GetNaviAppStatus( DeviceInterfaceBluetoothDeviceClass _this, 
  XUInt64 aAddress )
{
  XBool IsNaviAppConnected;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  IsNaviAppConnected = 0;
  {
    uint8_t bd_addr[BT_DEVICE_ADDRESS_LEN];
    for( int32_t i = 0; i < BT_DEVICE_ADDRESS_LEN; i++ )
    {
      bd_addr[i] = aAddress >> ( 8 * i );
    }
    IsNaviAppConnected = CM_get_app_connection_status( CM_APP_NAVILITE, bd_addr );
  }
  return IsNaviAppConnected;
}

/* 'C' function for method : 'DeviceInterface::BluetoothDeviceClass.GetYamahaAppStatus()' */
XBool DeviceInterfaceBluetoothDeviceClass_GetYamahaAppStatus( DeviceInterfaceBluetoothDeviceClass _this, 
  XUInt64 aAddress )
{
  XBool IsYamahaAppConnected;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  IsYamahaAppConnected = 0;
  {
    uint8_t bd_addr[BT_DEVICE_ADDRESS_LEN];
    for( int32_t i = 0; i < BT_DEVICE_ADDRESS_LEN; i++ )
    {
      bd_addr[i] = aAddress >> ( 8*i );
    }
    IsYamahaAppConnected = CM_get_app_connection_status( CM_APP_YCONNECT, bd_addr );
  }
  return IsYamahaAppConnected;
}

/* 'C' function for method : 'DeviceInterface::BluetoothDeviceClass.ConfirmPasskey()' */
void DeviceInterfaceBluetoothDeviceClass_ConfirmPasskey( DeviceInterfaceBluetoothDeviceClass _this, 
  XBool aResult )
{
  XBool aConfirmedResult;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  aConfirmedResult = aResult;
  BT_accept_pairing( aConfirmedResult );
}

/* 'C' function for method : 'DeviceInterface::BluetoothDeviceClass.OnGetBtSoftwareVersion()' */
XString DeviceInterfaceBluetoothDeviceClass_OnGetBtSoftwareVersion( DeviceInterfaceBluetoothDeviceClass _this )
{
  XString bt_sw_version = 0;

  {
    uint8_t major = 0;
    uint8_t minor = 0;
    BT_get_sw_version( &major, &minor );

    char version[32];
    snprintf( version, 32, "%1u.%u", major, minor );
    bt_sw_version = EwNewStringAnsi( version );
  }
  _this->BtSoftwareVersion = EwShareString( bt_sw_version );
  return _this->BtSoftwareVersion;
}

/* 'C' function for method : 'DeviceInterface::BluetoothDeviceClass.OnSetLogLevel()' */
void DeviceInterfaceBluetoothDeviceClass_OnSetLogLevel( DeviceInterfaceBluetoothDeviceClass _this, 
  XInt32 value )
{
  if ( _this->LogLevel != value )
  {
    XInt32 BtLogLevel;
    _this->LogLevel = value;
    BtLogLevel = value;
    BT_set_log_level( BtLogLevel );
  }
}

/* 'C' function for method : 'DeviceInterface::BluetoothDeviceClass.DeleteFromPairedDeviceList()' */
void DeviceInterfaceBluetoothDeviceClass_DeleteFromPairedDeviceList( DeviceInterfaceBluetoothDeviceClass _this, 
  XUInt64 aDeviceAddress )
{
  XInt32 i;
  XInt32 FoundIdx = -1;

  for ( i = 0; i < _this->PairedDeviceNum; i++ )
    if ( _this->PairedDeviceList[ EwCheckIndex( i, 8 )]->DeviceAddress == aDeviceAddress )
    {
      FoundIdx = i;
      break;
    }

  if ( 0 <= FoundIdx )
  {
    for ( i = FoundIdx; i < ( _this->PairedDeviceNum - 1 ); i++ )
    {
      _this->PairedDeviceList[ EwCheckIndex( i, 8 )]->DeviceName = EwShareString( 
      _this->PairedDeviceList[ EwCheckIndex( i + 1, 8 )]->DeviceName );
      _this->PairedDeviceList[ EwCheckIndex( i, 8 )]->DeviceAddress = _this->PairedDeviceList[ 
      EwCheckIndex( i + 1, 8 )]->DeviceAddress;
      _this->PairedDeviceList[ EwCheckIndex( i, 8 )]->IsNaviAppConnected = _this->PairedDeviceList[ 
      EwCheckIndex( i + 1, 8 )]->IsNaviAppConnected;
      _this->PairedDeviceList[ EwCheckIndex( i, 8 )]->IsYamahaAppConnected = _this->PairedDeviceList[ 
      EwCheckIndex( i + 1, 8 )]->IsYamahaAppConnected;
    }

    _this->PairedDeviceNum--;
    DeviceInterfaceBluetoothDeviceClass_NotifyConnectionStatus( _this, EnumConnectionStatusPAIRED_DEVICE_LIST_UPDATED );
  }
}

/* 'C' function for method : 'DeviceInterface::BluetoothDeviceClass.UpdateBtFirmware()' */
void DeviceInterfaceBluetoothDeviceClass_UpdateBtFirmware( DeviceInterfaceBluetoothDeviceClass _this )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  BT_update_firmware();
}

/* Variants derived from the class : 'DeviceInterface::BluetoothDeviceClass' */
EW_DEFINE_CLASS_VARIANTS( DeviceInterfaceBluetoothDeviceClass )
EW_END_OF_CLASS_VARIANTS( DeviceInterfaceBluetoothDeviceClass )

/* Virtual Method Table (VMT) for the class : 'DeviceInterface::BluetoothDeviceClass' */
EW_DEFINE_CLASS( DeviceInterfaceBluetoothDeviceClass, TemplatesDeviceClass, PairedDeviceList, 
                 MotoConSystemEvent, MotoConSystemEvent, MotoConSystemEvent, LocalDeviceAddress, 
                 PairedDeviceNum, "DeviceInterface::BluetoothDeviceClass" )
EW_END_OF_CLASS( DeviceInterfaceBluetoothDeviceClass )

/* User defined auto object: 'DeviceInterface::BluetoothDevice' */
EW_DEFINE_AUTOOBJECT( DeviceInterfaceBluetoothDevice, DeviceInterfaceBluetoothDeviceClass )

/* Initializer for the auto object 'DeviceInterface::BluetoothDevice' */
void DeviceInterfaceBluetoothDevice__Init( DeviceInterfaceBluetoothDeviceClass _this )
{
  EW_UNUSED_ARG( _this );
}

/* Table with links to derived variants of the auto object : 'DeviceInterface::BluetoothDevice' */
EW_DEFINE_AUTOOBJECT_VARIANTS( DeviceInterfaceBluetoothDevice )
EW_END_OF_AUTOOBJECT_VARIANTS( DeviceInterfaceBluetoothDevice )

/* Initializer for the class 'DeviceInterface::BtPairedDeviceInfo' */
void DeviceInterfaceBtPairedDeviceInfo__Init( DeviceInterfaceBtPairedDeviceInfo _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  XObject__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( DeviceInterfaceBtPairedDeviceInfo );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( DeviceInterfaceBtPairedDeviceInfo );
}

/* Re-Initializer for the class 'DeviceInterface::BtPairedDeviceInfo' */
void DeviceInterfaceBtPairedDeviceInfo__ReInit( DeviceInterfaceBtPairedDeviceInfo _this )
{
  /* At first re-initialize the super class ... */
  XObject__ReInit( &_this->_.Super );
}

/* Finalizer method for the class 'DeviceInterface::BtPairedDeviceInfo' */
void DeviceInterfaceBtPairedDeviceInfo__Done( DeviceInterfaceBtPairedDeviceInfo _this )
{
  /* Finalize this class */
  _this->_.Super._.VMT = EW_CLASS( XObject );

  /* Don't forget to deinitialize the super class ... */
  XObject__Done( &_this->_.Super );
}

/* Variants derived from the class : 'DeviceInterface::BtPairedDeviceInfo' */
EW_DEFINE_CLASS_VARIANTS( DeviceInterfaceBtPairedDeviceInfo )
EW_END_OF_CLASS_VARIANTS( DeviceInterfaceBtPairedDeviceInfo )

/* Virtual Method Table (VMT) for the class : 'DeviceInterface::BtPairedDeviceInfo' */
EW_DEFINE_CLASS( DeviceInterfaceBtPairedDeviceInfo, XObject, DeviceName, DeviceName, 
                 DeviceName, DeviceName, DeviceName, DeviceAddress, "DeviceInterface::BtPairedDeviceInfo" )
EW_END_OF_CLASS( DeviceInterfaceBtPairedDeviceInfo )

/* Initializer for the class 'DeviceInterface::RtcTime' */
void DeviceInterfaceRtcTime__Init( DeviceInterfaceRtcTime _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  XObject__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( DeviceInterfaceRtcTime );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( DeviceInterfaceRtcTime );
}

/* Re-Initializer for the class 'DeviceInterface::RtcTime' */
void DeviceInterfaceRtcTime__ReInit( DeviceInterfaceRtcTime _this )
{
  /* At first re-initialize the super class ... */
  XObject__ReInit( &_this->_.Super );
}

/* Finalizer method for the class 'DeviceInterface::RtcTime' */
void DeviceInterfaceRtcTime__Done( DeviceInterfaceRtcTime _this )
{
  /* Finalize this class */
  _this->_.Super._.VMT = EW_CLASS( XObject );

  /* Don't forget to deinitialize the super class ... */
  XObject__Done( &_this->_.Super );
}

/* Variants derived from the class : 'DeviceInterface::RtcTime' */
EW_DEFINE_CLASS_VARIANTS( DeviceInterfaceRtcTime )
EW_END_OF_CLASS_VARIANTS( DeviceInterfaceRtcTime )

/* Virtual Method Table (VMT) for the class : 'DeviceInterface::RtcTime' */
EW_DEFINE_CLASS( DeviceInterfaceRtcTime, XObject, _.VMT, _.VMT, _.VMT, _.VMT, _.VMT, 
                 _.VMT, "DeviceInterface::RtcTime" )
EW_END_OF_CLASS( DeviceInterfaceRtcTime )

/* Initializer for the class 'DeviceInterface::VehicleDeviceClass' */
void DeviceInterfaceVehicleDeviceClass__Init( DeviceInterfaceVehicleDeviceClass _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  TemplatesDeviceClass__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( DeviceInterfaceVehicleDeviceClass );

  /* ... then construct all embedded objects */
  CoreSystemEvent__Init( &_this->DDModeStateChangedSystemEvent, &_this->_.XObject, 0 );
  CoreSystemEvent__Init( &_this->VehicleDataReceivedSystemEvent, &_this->_.XObject, 0 );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( DeviceInterfaceVehicleDeviceClass );

  /* ... and initialize objects, variables, properties, etc. */
  _this->CurrentMeterDisplay = EnumMeterDisplayTACHOMETER;
}

/* Re-Initializer for the class 'DeviceInterface::VehicleDeviceClass' */
void DeviceInterfaceVehicleDeviceClass__ReInit( DeviceInterfaceVehicleDeviceClass _this )
{
  /* At first re-initialize the super class ... */
  TemplatesDeviceClass__ReInit( &_this->_.Super );

  /* ... then re-construct all embedded objects */
  CoreSystemEvent__ReInit( &_this->DDModeStateChangedSystemEvent );
  CoreSystemEvent__ReInit( &_this->VehicleDataReceivedSystemEvent );
}

/* Finalizer method for the class 'DeviceInterface::VehicleDeviceClass' */
void DeviceInterfaceVehicleDeviceClass__Done( DeviceInterfaceVehicleDeviceClass _this )
{
  /* Finalize this class */
  _this->_.Super._.VMT = EW_CLASS( TemplatesDeviceClass );

  /* Finalize all embedded objects */
  CoreSystemEvent__Done( &_this->DDModeStateChangedSystemEvent );
  CoreSystemEvent__Done( &_this->VehicleDataReceivedSystemEvent );

  /* Don't forget to deinitialize the super class ... */
  TemplatesDeviceClass__Done( &_this->_.Super );
}

/* This method is intended to be called by the device to notify the GUI application 
   about a particular system event. */
void DeviceInterfaceVehicleDeviceClass_NotifyDDModeStateChanged( DeviceInterfaceVehicleDeviceClass _this )
{
  CoreSystemEvent_Trigger( &_this->DDModeStateChangedSystemEvent, 0, 0 );
}

/* Wrapper function for the non virtual method : 'DeviceInterface::VehicleDeviceClass.NotifyDDModeStateChanged()' */
void DeviceInterfaceVehicleDeviceClass__NotifyDDModeStateChanged( void* _this )
{
  DeviceInterfaceVehicleDeviceClass_NotifyDDModeStateChanged((DeviceInterfaceVehicleDeviceClass)_this );
}

/* 'C' function for method : 'DeviceInterface::VehicleDeviceClass.OnGetDDModeActivated()' */
XBool DeviceInterfaceVehicleDeviceClass_OnGetDDModeActivated( DeviceInterfaceVehicleDeviceClass _this )
{
  XBool IsActivated;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  IsActivated = 0;
  IsActivated = VI_is_dd_mode_activated();
  return IsActivated;
}

/* 'C' function for method : 'DeviceInterface::VehicleDeviceClass.IsVehicleFunctionSupported()' */
XBool DeviceInterfaceVehicleDeviceClass_IsVehicleFunctionSupported( DeviceInterfaceVehicleDeviceClass _this, 
  XEnum aVehicleFeature )
{
  XBool IsSupported;
  XInt32 FeatureId;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  IsSupported = 0;
  FeatureId = aVehicleFeature;
  IsSupported = VI_is_function_supported( FeatureId );
  return IsSupported;
}

/* 'C' function for method : 'DeviceInterface::VehicleDeviceClass.SetData()' */
void DeviceInterfaceVehicleDeviceClass_SetData( DeviceInterfaceVehicleDeviceClass _this, 
  XEnum aVehicleTxType, XUInt32 aData )
{
  XInt32 TxTypeId;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  TxTypeId = aVehicleTxType;
  VI_set_tx_data( TxTypeId, aData );
}

/* 'C' function for method : 'DeviceInterface::VehicleDeviceClass.GetData()' */
DeviceInterfaceVehicleDataClass DeviceInterfaceVehicleDeviceClass_GetData( DeviceInterfaceVehicleDeviceClass _this, 
  XEnum aVehicleRxType )
{
  DeviceInterfaceVehicleDataClass VehicleData;
  XInt32 RxTypeId;
  XBool Valid;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  VehicleData = EwNewObject( DeviceInterfaceVehicleDataClass, 0 );

  if (((((((((((((((( EnumVehicleRxTypeFUEL_RATE_INSTANT == aVehicleRxType ) || 
      ( EnumVehicleRxTypeFUEL_RATE_AVERAGE == aVehicleRxType )) || ( EnumVehicleRxTypeODOMETER_VALUE 
      == aVehicleRxType )) || ( EnumVehicleRxTypeTRIP1_VALUE == aVehicleRxType )) 
      || ( EnumVehicleRxTypeTRIP2_VALUE == aVehicleRxType )) || ( EnumVehicleRxTypeFUEL_CONSUMPTION 
      == aVehicleRxType )) || ( EnumVehicleRxTypeAIR_TEMPERATURE == aVehicleRxType )) 
      || ( EnumVehicleRxTypeCOOLANT_TEMPERATURE == aVehicleRxType )) || ( EnumVehicleRxTypeBATTERY_VOLTAGE 
      == aVehicleRxType )) || ( EnumVehicleRxTypeTRIP_F_VALUE == aVehicleRxType )) 
      || ( EnumVehicleRxTypeTIRE_FRONT == aVehicleRxType )) || ( EnumVehicleRxTypeTIRE_REAR 
      == aVehicleRxType )) || ( EnumVehicleRxTypeTIRE_FRONT_LEFT == aVehicleRxType )) 
      || ( EnumVehicleRxTypeTIRE_FRONT_RIGHT == aVehicleRxType )) || ( EnumVehicleRxTypeFUEL_RATE_AVERAGE_UNIT_CONVERTED 
      == aVehicleRxType )) || ( EnumVehicleRxTypeFUEL_RATE_INSTANT_UNIT_CONVERTED 
      == aVehicleRxType ))
    VehicleData->DataType = EnumDataTypeFLOAT;

  RxTypeId = aVehicleRxType;
  Valid = 0;

  if ( EnumDataTypeFLOAT == VehicleData->DataType )
  {
    XFloat RxData = 0.000000f;
    {
      float rx_data = 0;
      Valid = VI_get_rx_data_float( RxTypeId, &rx_data );
      if( Valid )
      {
        RxData = rx_data;
      }
    }
    VehicleData->DataFloat = RxData;
  }
  else
  {
    XUInt32 RxData = 0;
    {
      uint32_t rx_data = 0;
      Valid = VI_get_rx_data_uint( RxTypeId, &rx_data );
      if( Valid )
      {
        RxData = rx_data;
      }
    }
    VehicleData->DataUInt32 = RxData;
  }

  VehicleData->Valid = Valid;
  return VehicleData;
}

/* This method is intended to be called by the device to notify the GUI application 
   about a particular system event. */
void DeviceInterfaceVehicleDeviceClass_NotifyDataReceived( DeviceInterfaceVehicleDeviceClass _this, 
  XEnum aRxType )
{
  DeviceInterfaceVehicleDataClass VehicleData = EwNewObject( DeviceInterfaceVehicleDataClass, 
    0 );

  VehicleData->RxType = aRxType;
  CoreSystemEvent_Trigger( &_this->VehicleDataReceivedSystemEvent, ((XObject)VehicleData ), 
  0 );
}

/* Wrapper function for the non virtual method : 'DeviceInterface::VehicleDeviceClass.NotifyDataReceived()' */
void DeviceInterfaceVehicleDeviceClass__NotifyDataReceived( void* _this, XEnum aRxType )
{
  DeviceInterfaceVehicleDeviceClass_NotifyDataReceived((DeviceInterfaceVehicleDeviceClass)_this
  , aRxType );
}

/* 'C' function for method : 'DeviceInterface::VehicleDeviceClass.ClampDataUInt32()' */
XUInt32 DeviceInterfaceVehicleDeviceClass_ClampDataUInt32( DeviceInterfaceVehicleDeviceClass _this, 
  XUInt32 aData, XUInt32 aMin, XUInt32 aMax )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  if ( aData < aMin )
    aData = aMin;
  else
    if ( aData > aMax )
      aData = aMax;

  return aData;
}

/* 'C' function for method : 'DeviceInterface::VehicleDeviceClass.ClampDataFloat()' */
XFloat DeviceInterfaceVehicleDeviceClass_ClampDataFloat( DeviceInterfaceVehicleDeviceClass _this, 
  XFloat aData, XFloat aMin, XFloat aMax )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  if ( aData < aMin )
    aData = aMin;
  else
    if ( aData > aMax )
      aData = aMax;

  return aData;
}

/* 'C' function for method : 'DeviceInterface::VehicleDeviceClass.RoundDownDataFloat()' */
XFloat DeviceInterfaceVehicleDeviceClass_RoundDownDataFloat( DeviceInterfaceVehicleDeviceClass _this, 
  XFloat aData, XFloat aResolution )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  return (XInt32)( aData / aResolution ) * aResolution;
}

/* 'C' function for method : 'DeviceInterface::VehicleDeviceClass.OnGetMileageUnit()' */
XEnum DeviceInterfaceVehicleDeviceClass_OnGetMileageUnit( DeviceInterfaceVehicleDeviceClass _this )
{
  DeviceInterfaceVehicleDataClass VehicleData = DeviceInterfaceVehicleDeviceClass_GetData( 
    EwGetAutoObject( &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass ), 
    EnumVehicleRxTypeMILEAGE_UNIT );

  if ( 1 == VehicleData->DataUInt32 )
    _this->MileageUnit = EnumMileageSettingItemMILE;
  else
    _this->MileageUnit = EnumMileageSettingItemKM;

  return _this->MileageUnit;
}

/* 'C' function for method : 'DeviceInterface::VehicleDeviceClass.OnGetFuelConsumptionUnit()' */
XEnum DeviceInterfaceVehicleDeviceClass_OnGetFuelConsumptionUnit( DeviceInterfaceVehicleDeviceClass _this )
{
  DeviceInterfaceVehicleDataClass VehicleData = DeviceInterfaceVehicleDeviceClass_GetData( 
    EwGetAutoObject( &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass ), 
    EnumVehicleRxTypeFUEL_CONSUMPTION_UNIT );

  if ( 4 > VehicleData->DataUInt32 )
    _this->FuelConsumptionUnit = (XEnum)VehicleData->DataUInt32;

  return _this->FuelConsumptionUnit;
}

/* 'C' function for method : 'DeviceInterface::VehicleDeviceClass.OnGetAvgSpeedStr()' */
XString DeviceInterfaceVehicleDeviceClass_OnGetAvgSpeedStr( DeviceInterfaceVehicleDeviceClass _this )
{
  DeviceInterfaceVehicleDataClass VehicleData = DeviceInterfaceVehicleDeviceClass_GetData( 
    EwGetAutoObject( &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass ), 
    EnumVehicleRxTypeAVERAGE_SPEED );

  if ( VehicleData->Valid )
  {
    if ( EnumMileageSettingItemMILE == DeviceInterfaceVehicleDeviceClass_OnGetMileageUnit( 
        _this ))
      VehicleData->DataUInt32 = (XInt32)( VehicleData->DataUInt32 * 0.625000f );

    VehicleData->DataUInt32 = DeviceInterfaceVehicleDeviceClass_ClampDataUInt32( 
    EwGetAutoObject( &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass ), 
    VehicleData->DataUInt32, 0, 999 );
    _this->AvgSpeedStr = EwShareString( EwNewStringUInt( VehicleData->DataUInt32, 
    0, 1 ));
  }
  else
    _this->AvgSpeedStr = EwShareString( EwLoadString( &StringsGEN_THREE_HYPHENS ));

  return _this->AvgSpeedStr;
}

/* 'C' function for method : 'DeviceInterface::VehicleDeviceClass.OnGetAvgFuelRateStr()' */
XString DeviceInterfaceVehicleDeviceClass_OnGetAvgFuelRateStr( DeviceInterfaceVehicleDeviceClass _this )
{
  DeviceInterfaceVehicleDataClass VehicleData = DeviceInterfaceVehicleDeviceClass_GetData( 
    EwGetAutoObject( &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass ), 
    EnumVehicleRxTypeFUEL_RATE_AVERAGE );

  if ( VehicleData->Valid )
  {
    VehicleData->DataFloat = DeviceInterfaceVehicleDeviceClass_ConvertFuelRate( 
    _this, VehicleData->DataFloat );

    switch ( DeviceInterfaceVehicleDeviceClass_OnGetFuelConsumptionUnit( _this ))
    {
      case EnumMeterFuelConsumptionUnitKM_PER_LITER :
        VehicleData->DataFloat = DeviceInterfaceVehicleDeviceClass_ClampDataFloat( 
        EwGetAutoObject( &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass ), 
        VehicleData->DataFloat, 0.000000f, 99.900002f );
      break;

      case EnumMeterFuelConsumptionUnitMILE_PER_US_GAL :
      case EnumMeterFuelConsumptionUnitMILE_PER_IMPERIAL_GAL :
        VehicleData->DataFloat = DeviceInterfaceVehicleDeviceClass_ClampDataFloat( 
        EwGetAutoObject( &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass ), 
        VehicleData->DataFloat, 0.000000f, 199.899994f );
      break;

      case EnumMeterFuelConsumptionUnitL_PER_100KM :
        VehicleData->DataFloat = DeviceInterfaceVehicleDeviceClass_ClampDataFloat( 
        EwGetAutoObject( &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass ), 
        VehicleData->DataFloat, 1.000000f, 99.900002f );
      break;

      default :; 
    }

    _this->AvgFuelRateStr = EwShareString( EwNewStringFloat( VehicleData->DataFloat, 
    0, 1 ));
  }
  else
    _this->AvgFuelRateStr = EwShareString( EwLoadString( &StringsGEN_THREE_HYPHENS ));

  return _this->AvgFuelRateStr;
}

/* 'C' function for method : 'DeviceInterface::VehicleDeviceClass.OnGetFuelConStr()' */
XString DeviceInterfaceVehicleDeviceClass_OnGetFuelConStr( DeviceInterfaceVehicleDeviceClass _this )
{
  DeviceInterfaceVehicleDataClass VehicleData = DeviceInterfaceVehicleDeviceClass_GetData( 
    EwGetAutoObject( &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass ), 
    EnumVehicleRxTypeFUEL_CONSUMPTION );

  if ( VehicleData->Valid )
  {
    VehicleData->DataFloat = DeviceInterfaceVehicleDeviceClass_ConvertFuelCons( 
    _this, VehicleData->DataFloat );
    VehicleData->DataFloat = DeviceInterfaceVehicleDeviceClass_ClampDataFloat( EwGetAutoObject( 
    &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass ), VehicleData->DataFloat, 
    0.000000f, 99.900002f );
    _this->FuelConStr = EwShareString( EwNewStringFloat( VehicleData->DataFloat, 
    0, 1 ));
  }
  else
    _this->FuelConStr = EwShareString( EwLoadString( &StringsGEN_THREE_HYPHENS ));

  return _this->FuelConStr;
}

/* 'C' function for method : 'DeviceInterface::VehicleDeviceClass.OnGetTripTimeHourStr()' */
XString DeviceInterfaceVehicleDeviceClass_OnGetTripTimeHourStr( DeviceInterfaceVehicleDeviceClass _this )
{
  DeviceInterfaceVehicleDataClass VehicleData = DeviceInterfaceVehicleDeviceClass_GetData( 
    EwGetAutoObject( &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass ), 
    EnumVehicleRxTypeTRIP_TIME );

  if ( VehicleData->Valid )
  {
    XUInt32 TripTimeHour = VehicleData->DataUInt32 / 3600;

    if ( 99 < TripTimeHour )
      TripTimeHour = 99;

    _this->TripTimeHourStr = EwShareString( EwNewStringUInt( TripTimeHour, 0, 10 ));
  }
  else
    _this->TripTimeHourStr = EwShareString( EwLoadString( &StringsGEN_THREE_HYPHENS ));

  return _this->TripTimeHourStr;
}

/* 'C' function for method : 'DeviceInterface::VehicleDeviceClass.OnGetTripTimeMinuteStr()' */
XString DeviceInterfaceVehicleDeviceClass_OnGetTripTimeMinuteStr( DeviceInterfaceVehicleDeviceClass _this )
{
  DeviceInterfaceVehicleDataClass VehicleData = DeviceInterfaceVehicleDeviceClass_GetData( 
    EwGetAutoObject( &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass ), 
    EnumVehicleRxTypeTRIP_TIME );

  if ( VehicleData->Valid )
  {
    XUInt32 TripTimeHour = VehicleData->DataUInt32 / 3600;
    XUInt32 TripTimeMinute;

    if ( 99 < TripTimeHour )
      TripTimeHour = 99;

    TripTimeMinute = ( VehicleData->DataUInt32 / 60 ) - ( TripTimeHour * 60 );

    if ( 99 < TripTimeMinute )
      TripTimeMinute = 99;

    _this->TripTimeMinuteStr = EwShareString( EwNewStringUInt( TripTimeMinute, 2, 
    10 ));
  }
  else
    _this->TripTimeMinuteStr = EwShareString( EwLoadString( &StringsGEN_THREE_HYPHENS ));

  return _this->TripTimeMinuteStr;
}

/* 'C' function for method : 'DeviceInterface::VehicleDeviceClass.OnGetTemperatureUnit()' */
XEnum DeviceInterfaceVehicleDeviceClass_OnGetTemperatureUnit( DeviceInterfaceVehicleDeviceClass _this )
{
  DeviceInterfaceVehicleDataClass VehicleData = DeviceInterfaceVehicleDeviceClass_GetData( 
    EwGetAutoObject( &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass ), 
    EnumVehicleRxTypeTEMPERATURE_UNIT );

  _this->TemperatureUnit = (XEnum)VehicleData->DataUInt32;
  return _this->TemperatureUnit;
}

/* 'C' function for method : 'DeviceInterface::VehicleDeviceClass.OnGetCoolantTemperatureStr()' */
XString DeviceInterfaceVehicleDeviceClass_OnGetCoolantTemperatureStr( DeviceInterfaceVehicleDeviceClass _this )
{
  DeviceInterfaceVehicleDataClass VehicleData = DeviceInterfaceVehicleDeviceClass_GetData( 
    EwGetAutoObject( &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass ), 
    EnumVehicleRxTypeCOOLANT_TEMPERATURE );

  if ( VehicleData->Valid )
  {
    if ( 128.750000f == VehicleData->DataFloat )
      _this->CoolantTemperatureStr = EwShareString( EwLoadString( &StringsGEN_HIGH_ABBREVIATION ));
    else
    {
      XFloat CoolantTemperature;

      if ( EnumTemperatureSettingItemTEMP_F == DeviceInterfaceVehicleDeviceClass_OnGetTemperatureUnit( 
          _this ))
      {
        CoolantTemperature = ( VehicleData->DataFloat * 1.800000f ) + 32;
        CoolantTemperature = DeviceInterfaceVehicleDeviceClass_ClampDataFloat( EwGetAutoObject( 
        &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass ), CoolantTemperature, 
        -22.000000f, 263.000000f );
      }
      else
        CoolantTemperature = DeviceInterfaceVehicleDeviceClass_ClampDataFloat( EwGetAutoObject( 
        &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass ), VehicleData->DataFloat, 
        -30.000000f, 128.000000f );

      CoolantTemperature = EwMathFloor( CoolantTemperature );
      _this->CoolantTemperatureStr = EwShareString( EwNewStringFloat( CoolantTemperature, 
      0, 0 ));
    }
  }
  else
    _this->CoolantTemperatureStr = EwShareString( EwLoadString( &StringsGEN_THREE_HYPHENS ));

  return _this->CoolantTemperatureStr;
}

/* 'C' function for method : 'DeviceInterface::VehicleDeviceClass.OnGetInstantFuelRateStr()' */
XString DeviceInterfaceVehicleDeviceClass_OnGetInstantFuelRateStr( DeviceInterfaceVehicleDeviceClass _this )
{
  DeviceInterfaceVehicleDataClass VehicleData = DeviceInterfaceVehicleDeviceClass_GetData( 
    EwGetAutoObject( &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass ), 
    EnumVehicleRxTypeFUEL_RATE_INSTANT );

  if ( VehicleData->Valid )
  {
    VehicleData->DataFloat = DeviceInterfaceVehicleDeviceClass_ConvertFuelRate( 
    _this, VehicleData->DataFloat );

    switch ( DeviceInterfaceVehicleDeviceClass_OnGetFuelConsumptionUnit( _this ))
    {
      case EnumMeterFuelConsumptionUnitKM_PER_LITER :
        VehicleData->DataFloat = DeviceInterfaceVehicleDeviceClass_ClampDataFloat( 
        EwGetAutoObject( &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass ), 
        VehicleData->DataFloat, 0.000000f, 99.900002f );
      break;

      case EnumMeterFuelConsumptionUnitMILE_PER_US_GAL :
      case EnumMeterFuelConsumptionUnitMILE_PER_IMPERIAL_GAL :
        VehicleData->DataFloat = DeviceInterfaceVehicleDeviceClass_ClampDataFloat( 
        EwGetAutoObject( &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass ), 
        VehicleData->DataFloat, 0.000000f, 199.899994f );
      break;

      case EnumMeterFuelConsumptionUnitL_PER_100KM :
        VehicleData->DataFloat = DeviceInterfaceVehicleDeviceClass_ClampDataFloat( 
        EwGetAutoObject( &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass ), 
        VehicleData->DataFloat, 1.000000f, 99.900002f );
      break;

      default :; 
    }

    _this->InstantFuelRateStr = EwShareString( EwNewStringFloat( VehicleData->DataFloat, 
    0, 1 ));
  }
  else
    _this->InstantFuelRateStr = EwShareString( EwLoadString( &StringsGEN_THREE_HYPHENS ));

  return _this->InstantFuelRateStr;
}

/* 'C' function for method : 'DeviceInterface::VehicleDeviceClass.ConvertFuelCons()' */
XFloat DeviceInterfaceVehicleDeviceClass_ConvertFuelCons( DeviceInterfaceVehicleDeviceClass _this, 
  XFloat aFuelCons )
{
  XFloat ConvertedFuelCons = aFuelCons;

  switch ( DeviceInterfaceVehicleDeviceClass_OnGetFuelConsumptionUnit( _this ))
  {
    case EnumMeterFuelConsumptionUnitMILE_PER_US_GAL :
    {
      ConvertedFuelCons = aFuelCons * 0.264000f;
      ConvertedFuelCons = DeviceInterfaceVehicleDeviceClass_RoundDownDataFloat( 
      EwGetAutoObject( &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass ), 
      ConvertedFuelCons, 0.100000f );
    }
    break;

    case EnumMeterFuelConsumptionUnitMILE_PER_IMPERIAL_GAL :
    {
      ConvertedFuelCons = aFuelCons * 0.220000f;
      ConvertedFuelCons = DeviceInterfaceVehicleDeviceClass_RoundDownDataFloat( 
      EwGetAutoObject( &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass ), 
      ConvertedFuelCons, 0.100000f );
    }
    break;

    default :; 
  }

  return ConvertedFuelCons;
}

/* 'C' function for method : 'DeviceInterface::VehicleDeviceClass.OnGetRangeStr()' */
XString DeviceInterfaceVehicleDeviceClass_OnGetRangeStr( DeviceInterfaceVehicleDeviceClass _this )
{
  DeviceInterfaceVehicleDataClass VehicleData = DeviceInterfaceVehicleDeviceClass_GetData( 
    EwGetAutoObject( &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass ), 
    EnumVehicleRxTypeRANGE_DISTANCE );

  if ( VehicleData->Valid )
  {
    if ( 0 == VehicleData->DataUInt32 )
      _this->RangeStr = EwShareString( EwLoadString( &StringsGEN_LOW_ABBREVIATION ));
    else
    {
      if ( EnumMileageSettingItemMILE == DeviceInterfaceVehicleDeviceClass_OnGetMileageUnit( 
          _this ))
        VehicleData->DataUInt32 = (XInt32)( VehicleData->DataUInt32 * 0.625000f );

      VehicleData->DataUInt32 = DeviceInterfaceVehicleDeviceClass_ClampDataUInt32( 
      EwGetAutoObject( &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass ), 
      VehicleData->DataUInt32, 0, 999 );
      _this->RangeStr = EwShareString( EwNewStringUInt( VehicleData->DataUInt32, 
      0, 1 ));
    }
  }
  else
    _this->RangeStr = EwShareString( EwLoadString( &StringsGEN_THREE_HYPHENS ));

  return _this->RangeStr;
}

/* 'C' function for method : 'DeviceInterface::VehicleDeviceClass.OnGetBatteryStr()' */
XString DeviceInterfaceVehicleDeviceClass_OnGetBatteryStr( DeviceInterfaceVehicleDeviceClass _this )
{
  DeviceInterfaceVehicleDataClass VehicleData = DeviceInterfaceVehicleDeviceClass_GetData( 
    EwGetAutoObject( &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass ), 
    EnumVehicleRxTypeBATTERY_VOLTAGE );

  if ( VehicleData->Valid )
  {
    VehicleData->DataFloat = DeviceInterfaceVehicleDeviceClass_ClampDataFloat( EwGetAutoObject( 
    &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass ), VehicleData->DataFloat, 
    9.000000f, 16.000000f );
    VehicleData->DataFloat = DeviceInterfaceVehicleDeviceClass_RoundDownDataFloat( 
    EwGetAutoObject( &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass ), 
    VehicleData->DataFloat, 0.100000f );
    _this->BatteryStr = EwShareString( EwNewStringFloat( VehicleData->DataFloat, 
    0, 1 ));
  }
  else
    _this->BatteryStr = EwShareString( EwLoadString( &StringsGEN_THREE_HYPHENS ));

  return _this->BatteryStr;
}

/* 'C' function for method : 'DeviceInterface::VehicleDeviceClass.OnGetPressureUnit()' */
XEnum DeviceInterfaceVehicleDeviceClass_OnGetPressureUnit( DeviceInterfaceVehicleDeviceClass _this )
{
  DeviceInterfaceVehicleDataClass VehicleData = DeviceInterfaceVehicleDeviceClass_GetData( 
    EwGetAutoObject( &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass ), 
    EnumVehicleRxTypePRESSURE_UNIT );

  _this->PressureUnit = (XEnum)VehicleData->DataUInt32;
  return _this->PressureUnit;
}

/* 'C' function for method : 'DeviceInterface::VehicleDeviceClass.ConvertFuelRate()' */
XFloat DeviceInterfaceVehicleDeviceClass_ConvertFuelRate( DeviceInterfaceVehicleDeviceClass _this, 
  XFloat aFuelRate )
{
  XFloat ConvertedFuelRate = aFuelRate;

  switch ( DeviceInterfaceVehicleDeviceClass_OnGetFuelConsumptionUnit( _this ))
  {
    case EnumMeterFuelConsumptionUnitMILE_PER_US_GAL :
    {
      ConvertedFuelRate = aFuelRate * 2.367000f;
      ConvertedFuelRate = DeviceInterfaceVehicleDeviceClass_RoundDownDataFloat( 
      EwGetAutoObject( &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass ), 
      ConvertedFuelRate, 0.100000f );
    }
    break;

    case EnumMeterFuelConsumptionUnitMILE_PER_IMPERIAL_GAL :
    {
      ConvertedFuelRate = aFuelRate * 2.841000f;
      ConvertedFuelRate = DeviceInterfaceVehicleDeviceClass_RoundDownDataFloat( 
      EwGetAutoObject( &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass ), 
      ConvertedFuelRate, 0.100000f );
    }
    break;

    case EnumMeterFuelConsumptionUnitL_PER_100KM :
      if ( 0.000000f < aFuelRate )
      {
        ConvertedFuelRate = 100 / aFuelRate;
        ConvertedFuelRate = DeviceInterfaceVehicleDeviceClass_RoundDownDataFloat( 
        EwGetAutoObject( &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass ), 
        ConvertedFuelRate, 0.100000f );
      }
      else
        ConvertedFuelRate = 99.900002f;
    break;

    default :; 
  }

  return ConvertedFuelRate;
}

/* 'C' function for method : 'DeviceInterface::VehicleDeviceClass.OnGetAirTemperatureStr()' */
XString DeviceInterfaceVehicleDeviceClass_OnGetAirTemperatureStr( DeviceInterfaceVehicleDeviceClass _this )
{
  DeviceInterfaceVehicleDataClass VehicleData = DeviceInterfaceVehicleDeviceClass_GetData( 
    EwGetAutoObject( &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass ), 
    EnumVehicleRxTypeAIR_TEMPERATURE );

  if ( VehicleData->Valid )
  {
    XFloat AirTemperature;

    if ( EnumTemperatureSettingItemTEMP_F == DeviceInterfaceVehicleDeviceClass_OnGetTemperatureUnit( 
        _this ))
    {
      AirTemperature = ( VehicleData->DataFloat * 1.800000f ) + 32;
      AirTemperature = DeviceInterfaceVehicleDeviceClass_ClampDataFloat( EwGetAutoObject( 
      &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass ), AirTemperature, 
      -22.000000f, 263.000000f );
    }
    else
      AirTemperature = DeviceInterfaceVehicleDeviceClass_ClampDataFloat( EwGetAutoObject( 
      &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass ), VehicleData->DataFloat, 
      -30.000000f, 128.000000f );

    AirTemperature = EwMathFloor( AirTemperature );
    _this->AirTemperatureStr = EwShareString( EwNewStringFloat( AirTemperature, 
    0, 0 ));
  }
  else
    _this->AirTemperatureStr = EwShareString( EwLoadString( &StringsGEN_THREE_HYPHENS ));

  return _this->AirTemperatureStr;
}

/* 'C' function for method : 'DeviceInterface::VehicleDeviceClass.OnGetCruiseSpeedStr()' */
XString DeviceInterfaceVehicleDeviceClass_OnGetCruiseSpeedStr( DeviceInterfaceVehicleDeviceClass _this )
{
  DeviceInterfaceVehicleDataClass VehicleData = DeviceInterfaceVehicleDeviceClass_GetData( 
    EwGetAutoObject( &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass ), 
    EnumVehicleRxTypeCRUISE_SPEED );

  if ( VehicleData->Valid )
  {
    if ( EnumMileageSettingItemMILE == DeviceInterfaceVehicleDeviceClass_OnGetMileageUnit( 
        _this ))
      VehicleData->DataUInt32 = (XInt32)( VehicleData->DataUInt32 * 0.625000f );

    VehicleData->DataUInt32 = DeviceInterfaceVehicleDeviceClass_ClampDataUInt32( 
    EwGetAutoObject( &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass ), 
    VehicleData->DataUInt32, 0, 999 );
    _this->CruiseSpeedStr = EwShareString( EwNewStringUInt( VehicleData->DataUInt32, 
    0, 1 ));
  }
  else
    _this->CruiseSpeedStr = EwShareString( EwLoadString( &StringsGEN_THREE_HYPHENS ));

  return _this->CruiseSpeedStr;
}

/* 'C' function for method : 'DeviceInterface::VehicleDeviceClass.OnGetLowFuelWarning()' */
XBool DeviceInterfaceVehicleDeviceClass_OnGetLowFuelWarning( DeviceInterfaceVehicleDeviceClass _this )
{
  DeviceInterfaceVehicleDataClass VehicleData = DeviceInterfaceVehicleDeviceClass_GetData( 
    EwGetAutoObject( &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass ), 
    EnumVehicleRxTypeLOW_FUEL_WARNING );

  if ( VehicleData->Valid )
    _this->LowFuelWarning = !!VehicleData->DataUInt32;

  return _this->LowFuelWarning;
}

/* 'C' function for method : 'DeviceInterface::VehicleDeviceClass.OnGetTireFrontPressureStr()' */
XString DeviceInterfaceVehicleDeviceClass_OnGetTireFrontPressureStr( DeviceInterfaceVehicleDeviceClass _this )
{
  _this->TireFrontPressureStr = EwShareString( DeviceInterfaceVehicleDeviceClass_GetTirePressureStr( 
  _this, EnumVehicleRxTypeTIRE_FRONT ));
  return _this->TireFrontPressureStr;
}

/* 'C' function for method : 'DeviceInterface::VehicleDeviceClass.RoundDownDataUint32()' */
XUInt32 DeviceInterfaceVehicleDeviceClass_RoundDownDataUint32( DeviceInterfaceVehicleDeviceClass _this, 
  XUInt32 aData, XUInt32 aResolution )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  return ( aData / aResolution ) * aResolution;
}

/* 'C' function for method : 'DeviceInterface::VehicleDeviceClass.GetTirePressureStr()' */
XString DeviceInterfaceVehicleDeviceClass_GetTirePressureStr( DeviceInterfaceVehicleDeviceClass _this, 
  XEnum aTireType )
{
  if ( DeviceInterfaceVehicleDeviceClass_OnGetTireSensorEquipped( _this ))
  {
    DeviceInterfaceVehicleDataClass VehicleData = DeviceInterfaceVehicleDeviceClass_GetData( 
      EwGetAutoObject( &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass ), 
      aTireType );

    if ( 0.000000f < VehicleData->DataFloat )
      switch ( DeviceInterfaceVehicleDeviceClass_OnGetPressureUnit( _this ))
      {
        case EnumPressureSettingItemPSI :
        {
          VehicleData->DataFloat = EwMathFloor( VehicleData->DataFloat );
          _this->TireFrontPressureStr = EwShareString( EwNewStringFloat( VehicleData->DataFloat, 
          0, 0 ));
        }
        break;

        case EnumPressureSettingItemKPA :
        {
          XUInt32 pressure;
          VehicleData->DataFloat /= 0.145000f;
          pressure = DeviceInterfaceVehicleDeviceClass_RoundDownDataUint32( EwGetAutoObject( 
          &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass ), (XInt32)VehicleData->DataFloat, 
          10 );
          _this->TireFrontPressureStr = EwShareString( EwNewStringUInt( pressure, 
          0, 10 ));
        }
        break;

        case EnumPressureSettingItemKGF_PER_CM2 :
        {
          VehicleData->DataFloat /= 14.200000f;
          VehicleData->DataFloat = DeviceInterfaceVehicleDeviceClass_RoundDownDataFloat( 
          EwGetAutoObject( &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass ), 
          VehicleData->DataFloat, 0.100000f );
          _this->TireFrontPressureStr = EwShareString( EwNewStringFloat( VehicleData->DataFloat, 
          0, 1 ));
        }
        break;

        default :; 
      }
    else
      _this->TireFrontPressureStr = EwShareString( EwLoadString( &StringsGEN_THREE_HYPHENS ));
  }
  else
    _this->TireFrontPressureStr = EwShareString( EwLoadString( &StringsGEN_THREE_HYPHENS ));

  return _this->TireFrontPressureStr;
}

/* 'C' function for method : 'DeviceInterface::VehicleDeviceClass.OnGetTireRearPressureStr()' */
XString DeviceInterfaceVehicleDeviceClass_OnGetTireRearPressureStr( DeviceInterfaceVehicleDeviceClass _this )
{
  _this->TireRearPressureStr = EwShareString( DeviceInterfaceVehicleDeviceClass_GetTirePressureStr( 
  _this, EnumVehicleRxTypeTIRE_REAR ));
  return _this->TireRearPressureStr;
}

/* 'C' function for method : 'DeviceInterface::VehicleDeviceClass.OnGetTireSensorEquipped()' */
XBool DeviceInterfaceVehicleDeviceClass_OnGetTireSensorEquipped( DeviceInterfaceVehicleDeviceClass _this )
{
  DeviceInterfaceVehicleDataClass VehicleData = DeviceInterfaceVehicleDeviceClass_GetData( 
    EwGetAutoObject( &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass ), 
    EnumVehicleRxTypeTIRE_SENSOR_EQUIPPED );

  _this->TireSensorEquipped = !!VehicleData->DataUInt32;
  return _this->TireSensorEquipped;
}

/* 'C' function for method : 'DeviceInterface::VehicleDeviceClass.OnGetEngineIdling()' */
XBool DeviceInterfaceVehicleDeviceClass_OnGetEngineIdling( DeviceInterfaceVehicleDeviceClass _this )
{
  XBool IsEngineIdling;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  IsEngineIdling = 0;
  IsEngineIdling = VI_is_engine_idling();
  return IsEngineIdling;
}

/* 'C' function for method : 'DeviceInterface::VehicleDeviceClass.OnGetIsTimeoutError2Detected()' */
XBool DeviceInterfaceVehicleDeviceClass_OnGetIsTimeoutError2Detected( DeviceInterfaceVehicleDeviceClass _this )
{
  XBool IsError2Detected;
  DeviceInterfaceVehicleDataClass VehicleData;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  IsError2Detected = 0;
  VehicleData = DeviceInterfaceVehicleDeviceClass_GetData( EwGetAutoObject( &DeviceInterfaceVehicleDevice, 
  DeviceInterfaceVehicleDeviceClass ), EnumVehicleRxTypeTIMEOUT_ERROR2_DETECTED );

  if ( !!VehicleData->DataUInt32 )
    IsError2Detected = 1;

  return IsError2Detected;
}

/* 'C' function for method : 'DeviceInterface::VehicleDeviceClass.OnGetIsHeaterStatusTimeoutErr1Detected()' */
XBool DeviceInterfaceVehicleDeviceClass_OnGetIsHeaterStatusTimeoutErr1Detected( DeviceInterfaceVehicleDeviceClass _this )
{
  XBool Detected;
  DeviceInterfaceVehicleDataClass VehicleData;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  Detected = 0;
  VehicleData = DeviceInterfaceVehicleDeviceClass_GetData( EwGetAutoObject( &DeviceInterfaceVehicleDevice, 
  DeviceInterfaceVehicleDeviceClass ), EnumVehicleRxTypeHEATER_STATUS_TIMEOUT_ERR1 );

  if ( !!VehicleData->DataUInt32 )
    Detected = 1;

  return Detected;
}

/* 'C' function for method : 'DeviceInterface::VehicleDeviceClass.OnGetIsResReprogramInfoTimeoutErr1Detected()' */
XBool DeviceInterfaceVehicleDeviceClass_OnGetIsResReprogramInfoTimeoutErr1Detected( DeviceInterfaceVehicleDeviceClass _this )
{
  XBool Detected;
  DeviceInterfaceVehicleDataClass VehicleData;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  Detected = 0;
  VehicleData = DeviceInterfaceVehicleDeviceClass_GetData( EwGetAutoObject( &DeviceInterfaceVehicleDevice, 
  DeviceInterfaceVehicleDeviceClass ), EnumVehicleRxTypeRES_REPGROGRAM_INFO_TIMEOUT_ERR1 );

  if ( !!VehicleData->DataUInt32 )
    Detected = 1;

  return Detected;
}

/* 'C' function for method : 'DeviceInterface::VehicleDeviceClass.SetTachoColorbaseRect()' */
void DeviceInterfaceVehicleDeviceClass_SetTachoColorbaseRect( DeviceInterfaceVehicleDeviceClass _this, 
  XRect aUpperColorbaseRect, XRect aLowerColorbaseRect )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  {
    ew_tacho_set_colorbase_bounds( aUpperColorbaseRect.Point1.X, aUpperColorbaseRect.Point1.Y, aUpperColorbaseRect.Point2.X, aUpperColorbaseRect.Point2.Y,
                                   aLowerColorbaseRect.Point1.X, aLowerColorbaseRect.Point1.Y, aLowerColorbaseRect.Point2.X, aLowerColorbaseRect.Point2.Y );
  }
}

/* 'C' function for method : 'DeviceInterface::VehicleDeviceClass.SetTachoYMask()' */
void DeviceInterfaceVehicleDeviceClass_SetTachoYMask( DeviceInterfaceVehicleDeviceClass _this, 
  XInt32 aUpperMaskY1, XInt32 aUpperMaskY2, XInt32 aLowerMaskY1, XInt32 aLowerMaskY2 )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  ew_tacho_set_y_mask( aUpperMaskY1, aUpperMaskY2, aLowerMaskY1, aLowerMaskY2 );
}

/* Variants derived from the class : 'DeviceInterface::VehicleDeviceClass' */
EW_DEFINE_CLASS_VARIANTS( DeviceInterfaceVehicleDeviceClass )
EW_END_OF_CLASS_VARIANTS( DeviceInterfaceVehicleDeviceClass )

/* Virtual Method Table (VMT) for the class : 'DeviceInterface::VehicleDeviceClass' */
EW_DEFINE_CLASS( DeviceInterfaceVehicleDeviceClass, TemplatesDeviceClass, DDModeStateChangedSystemEvent, 
                 DDModeStateChangedSystemEvent, DDModeStateChangedSystemEvent, DDModeStateChangedSystemEvent, 
                 AvgSpeedStr, PressureUnit, "DeviceInterface::VehicleDeviceClass" )
EW_END_OF_CLASS( DeviceInterfaceVehicleDeviceClass )

/* User defined auto object: 'DeviceInterface::VehicleDevice' */
EW_DEFINE_AUTOOBJECT( DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass )

/* Initializer for the auto object 'DeviceInterface::VehicleDevice' */
void DeviceInterfaceVehicleDevice__Init( DeviceInterfaceVehicleDeviceClass _this )
{
  EW_UNUSED_ARG( _this );
}

/* Table with links to derived variants of the auto object : 'DeviceInterface::VehicleDevice' */
EW_DEFINE_AUTOOBJECT_VARIANTS( DeviceInterfaceVehicleDevice )
EW_END_OF_AUTOOBJECT_VARIANTS( DeviceInterfaceVehicleDevice )

/* Initializer for the class 'DeviceInterface::WeatherDeviceClass' */
void DeviceInterfaceWeatherDeviceClass__Init( DeviceInterfaceWeatherDeviceClass _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  TemplatesDeviceClass__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( DeviceInterfaceWeatherDeviceClass );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( DeviceInterfaceWeatherDeviceClass );
}

/* Re-Initializer for the class 'DeviceInterface::WeatherDeviceClass' */
void DeviceInterfaceWeatherDeviceClass__ReInit( DeviceInterfaceWeatherDeviceClass _this )
{
  /* At first re-initialize the super class ... */
  TemplatesDeviceClass__ReInit( &_this->_.Super );
}

/* Finalizer method for the class 'DeviceInterface::WeatherDeviceClass' */
void DeviceInterfaceWeatherDeviceClass__Done( DeviceInterfaceWeatherDeviceClass _this )
{
  /* Finalize this class */
  _this->_.Super._.VMT = EW_CLASS( TemplatesDeviceClass );

  /* Don't forget to deinitialize the super class ... */
  TemplatesDeviceClass__Done( &_this->_.Super );
}

/* 'C' function for method : 'DeviceInterface::WeatherDeviceClass.GetWeatherInfo()' */
void DeviceInterfaceWeatherDeviceClass_GetWeatherInfo( DeviceInterfaceWeatherDeviceClass _this, 
  XInt32 aWeaItemIdx )
{
  XInt32 WTime = 0;
  XInt32 WType = 0;
  XInt32 WTemp = 0;
  XInt32 TempMin = 0;
  XInt32 TempMax = 0;
  XInt32 RainProb = 0;
  DeviceInterfaceVehicleDataClass VehicleData = DeviceInterfaceVehicleDeviceClass_GetData( 
    EwGetAutoObject( &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass ), 
    EnumVehicleRxTypeTEMPERATURE_UNIT );
  XEnum WeaTempType = (XEnum)VehicleData->DataUInt32;

  {
    bc_motocon_weather_info_t* w_obj = NULL;
    #if( !UNIT_TEST_WEA )
      w_obj = ew_get_weather_info_obj( aWeaItemIdx );
    #else
      w_obj = TEST_get_weather_obj( aWeaItemIdx );
    #endif

    WTime = w_obj->time;
    WTemp = (int)w_obj->temperature;
    TempMin = (int)w_obj->temperature_min;
    TempMax = (int)w_obj->temperature_max;
    RainProb = w_obj->rain_probability;

    switch( w_obj->type )
    {
      case BC_MOTOCON_WEATHER_SUNNY:
        WType = EnumWeatherIconTypeSUNNY;
        break;
      case BC_MOTOCON_WEATHER_PARTLY_CLOUDY_DAY:
        WType = EnumWeatherIconTypePARTLY_CLOUDY_DAY;
        break;
      case BC_MOTOCON_WEATHER_CLOUDY_DAY:
        WType = EnumWeatherIconTypeCLOUDY_DAY;
        break;
      case BC_MOTOCON_WEATHER_RAIN:
        WType = EnumWeatherIconTypeRAIN;
        break;
      case BC_MOTOCON_WEATHER_SNOW:
        WType = EnumWeatherIconTypeSNOW;
        break;
      case BC_MOTOCON_WEATHER_WIND:
        WType = EnumWeatherIconTypeWIND;
        break;
      case BC_MOTOCON_WEATHER_RAIN_STORM_MIX:
        WType = EnumWeatherIconTypeRAIN_STORM_MIX;
        break;
      case BC_MOTOCON_WEATHER_RAIN_SNOW_MIX:
        WType = EnumWeatherIconTypeRAIN_SNOW_MIX;
        break;
      case BC_MOTOCON_WEATHER_FOG:
        WType = EnumWeatherIconTypeFOG;
        break;
      case BC_MOTOCON_WEATHER_SMOG:
        WType = EnumWeatherIconTypeSMOG;
        break;
      case BC_MOTOCON_WEATHER_HAIL:
        WType = EnumWeatherIconTypeHAIL;
        break;
      case BC_MOTOCON_WEATHER_SCATTERED_SHOWERS_DAY:
        WType = EnumWeatherIconTypeSCATTERED_SHOWERS_DAY;
        break;
      case BC_MOTOCON_WEATHER_SCATTERED_STORM_DAY:
        WType = EnumWeatherIconTypeSCATTERED_STORM_DAY;
        break;
      case BC_MOTOCON_WEATHER_NO_DATA:
        WType = EnumWeatherIconTypeNO_DATA;
        break;
      case BC_MOTOCON_WEATHER_RAIN_LIGHT:
        WType = EnumWeatherIconTypeRAIN_LIGHT;
        break;
      case BC_MOTOCON_WEATHER_RAIN_HEAVY:
        WType = EnumWeatherIconTypeRAIN_HEAVY;
        break;
      case BC_MOTOCON_WEATHER_SNOW_LIGHT:
        WType = EnumWeatherIconTypeSNOW_LIGHT;
        break;
      case BC_MOTOCON_WEATHER_SNOW_HEAVY:
        WType = EnumWeatherIconTypeSNOW_HEAVY;
        break;
      case BC_MOTOCON_WEATHER_RAIN_SNOW_MIX_LIGHT:
        WType = EnumWeatherIconTypeRAIN_SNOW_MIX_LIGHT;
        break;
      case BC_MOTOCON_WEATHER_RAIN_SNOW_MIX_HEAVY:
        WType = EnumWeatherIconTypeRAIN_SNOW_MIX_HEAVY;
        break;
      case BC_MOTOCON_WEATHER_CLOUDY:
        WType = EnumWeatherIconTypeCLOUDY;
        break;
      case BC_MOTOCON_WEATHER_CLEAR:
        WType = EnumWeatherIconTypeCLEAR;
        break;
      case BC_MOTOCON_WEATHER_PARTLY_CLOUDY_NIGHT:
        WType = EnumWeatherIconTypePARTLY_CLOUDY_NIGHT;
        break;
      case BC_MOTOCON_WEATHER_CLOUDY_NIGHT:
        WType = EnumWeatherIconTypeCLOUDY_NIGHT;
        break;
      case BC_MOTOCON_WEATHER_SCATTERED_SHOWERS_NIGHT:
        WType = EnumWeatherIconTypeSCATTERED_SHOWERS_NIGHT;
        break;
      case BC_MOTOCON_WEATHER_SCATTERED_STORM_NIGHT:
        WType = EnumWeatherIconTypeSCATTERED_STORM_NIGHT;
        break;
      default:
        EwPrint( "Unexpected weather type is received\r\n" );
        break;
    }
  }
  _this->WeatherTime = WTime;
  _this->WeatherType = WType;
  _this->Temperature = DeviceInterfaceWeatherDeviceClass_ConvertTemperature( _this, 
  WeaTempType, WTemp );
  _this->MinTemperature = DeviceInterfaceWeatherDeviceClass_ConvertTemperature( 
  _this, WeaTempType, TempMin );
  _this->MaxTemperature = DeviceInterfaceWeatherDeviceClass_ConvertTemperature( 
  _this, WeaTempType, TempMax );
  _this->RainProbability = RainProb;
}

/* This method is intended to be called by the device to notify the GUI application 
   about a particular system event. */
void DeviceInterfaceWeatherDeviceClass_NotifyWeatherInfoUpdated( DeviceInterfaceWeatherDeviceClass _this )
{
  DeviceInterfaceWeatherDeviceClass_OnSetIsWeatherInfoReceived( _this, 1 );
}

/* Wrapper function for the non virtual method : 'DeviceInterface::WeatherDeviceClass.NotifyWeatherInfoUpdated()' */
void DeviceInterfaceWeatherDeviceClass__NotifyWeatherInfoUpdated( void* _this )
{
  DeviceInterfaceWeatherDeviceClass_NotifyWeatherInfoUpdated((DeviceInterfaceWeatherDeviceClass)_this );
}

/* 'C' function for method : 'DeviceInterface::WeatherDeviceClass.GetWeatherLoc()' */
void DeviceInterfaceWeatherDeviceClass_GetWeatherLoc( DeviceInterfaceWeatherDeviceClass _this )
{
  XString CurrentLoc = 0;

  {
    char* cur_loc;
    #if( !UNIT_TEST_WEA )
      ew_get_weather_loc( &cur_loc );
    #else
      TEST_weather_location( &cur_loc );
    #endif
    CurrentLoc = EwNewStringUtf8( (const unsigned char*) cur_loc, (int)strlen( cur_loc ) );
  }
  _this->WeatherLocation = EwShareString( CurrentLoc );
}

/* 'C' function for method : 'DeviceInterface::WeatherDeviceClass.SendWeatherInfoRequest()' */
void DeviceInterfaceWeatherDeviceClass_SendWeatherInfoRequest( DeviceInterfaceWeatherDeviceClass _this )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  ew_send_weather_info_req();
}

/* 'C' function for method : 'DeviceInterface::WeatherDeviceClass.SendVehicleSettingRequest()' */
void DeviceInterfaceWeatherDeviceClass_SendVehicleSettingRequest( DeviceInterfaceWeatherDeviceClass _this )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  ew_send_vehicle_setting_req();
}

/* 'C' function for method : 'DeviceInterface::WeatherDeviceClass.GetWeekDay()' */
void DeviceInterfaceWeatherDeviceClass_GetWeekDay( DeviceInterfaceWeatherDeviceClass _this )
{
  XInt32 NewWeekDay = 0;

  {
    int week_day;
    #if( !UNIT_TEST_WEA )
      week_day = ew_get_weather_week_day();
    #else
      week_day = TEST_weather_weekday();
    #endif
    NewWeekDay = week_day;
  }
  _this->WeekDay = NewWeekDay;
}

/* 'C' function for method : 'DeviceInterface::WeatherDeviceClass.OnSetIsWeatherInfoReceived()' */
void DeviceInterfaceWeatherDeviceClass_OnSetIsWeatherInfoReceived( DeviceInterfaceWeatherDeviceClass _this, 
  XBool value )
{
  _this->IsWeatherInfoReceived = value;
  EwNotifyRefObservers( EwNewRef( _this, DeviceInterfaceWeatherDeviceClass_OnGetIsWeatherInfoReceived, 
    DeviceInterfaceWeatherDeviceClass_OnSetIsWeatherInfoReceived ), 0 );
}

/* 'C' function for method : 'DeviceInterface::WeatherDeviceClass.ConvertTemperature()' */
XInt32 DeviceInterfaceWeatherDeviceClass_ConvertTemperature( DeviceInterfaceWeatherDeviceClass _this, 
  XEnum aTempUnit, XInt32 aTemperature )
{
  XInt32 Temp;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  Temp = aTemperature;

  if ( EnumTemperatureSettingItemTEMP_F == aTempUnit )
    Temp = (( aTemperature * 9 ) + 160 ) / 5;

  return Temp;
}

/* Default onget method for the property 'IsWeatherInfoReceived' */
XBool DeviceInterfaceWeatherDeviceClass_OnGetIsWeatherInfoReceived( DeviceInterfaceWeatherDeviceClass _this )
{
  return _this->IsWeatherInfoReceived;
}

/* Variants derived from the class : 'DeviceInterface::WeatherDeviceClass' */
EW_DEFINE_CLASS_VARIANTS( DeviceInterfaceWeatherDeviceClass )
EW_END_OF_CLASS_VARIANTS( DeviceInterfaceWeatherDeviceClass )

/* Virtual Method Table (VMT) for the class : 'DeviceInterface::WeatherDeviceClass' */
EW_DEFINE_CLASS( DeviceInterfaceWeatherDeviceClass, TemplatesDeviceClass, WeatherLocation, 
                 WeatherLocation, WeatherLocation, WeatherLocation, WeatherLocation, 
                 WeatherTime, "DeviceInterface::WeatherDeviceClass" )
EW_END_OF_CLASS( DeviceInterfaceWeatherDeviceClass )

/* User defined auto object: 'DeviceInterface::WeatherDevice' */
EW_DEFINE_AUTOOBJECT( DeviceInterfaceWeatherDevice, DeviceInterfaceWeatherDeviceClass )

/* Initializer for the auto object 'DeviceInterface::WeatherDevice' */
void DeviceInterfaceWeatherDevice__Init( DeviceInterfaceWeatherDeviceClass _this )
{
  EW_UNUSED_ARG( _this );
}

/* Table with links to derived variants of the auto object : 'DeviceInterface::WeatherDevice' */
EW_DEFINE_AUTOOBJECT_VARIANTS( DeviceInterfaceWeatherDevice )
EW_END_OF_AUTOOBJECT_VARIANTS( DeviceInterfaceWeatherDevice )

/* Initializer for the class 'DeviceInterface::VehicleDataClass' */
void DeviceInterfaceVehicleDataClass__Init( DeviceInterfaceVehicleDataClass _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  XObject__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( DeviceInterfaceVehicleDataClass );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( DeviceInterfaceVehicleDataClass );

  /* ... and initialize objects, variables, properties, etc. */
  _this->DataType = EnumDataTypeUINT32;
}

/* Re-Initializer for the class 'DeviceInterface::VehicleDataClass' */
void DeviceInterfaceVehicleDataClass__ReInit( DeviceInterfaceVehicleDataClass _this )
{
  /* At first re-initialize the super class ... */
  XObject__ReInit( &_this->_.Super );
}

/* Finalizer method for the class 'DeviceInterface::VehicleDataClass' */
void DeviceInterfaceVehicleDataClass__Done( DeviceInterfaceVehicleDataClass _this )
{
  /* Finalize this class */
  _this->_.Super._.VMT = EW_CLASS( XObject );

  /* Don't forget to deinitialize the super class ... */
  XObject__Done( &_this->_.Super );
}

/* Variants derived from the class : 'DeviceInterface::VehicleDataClass' */
EW_DEFINE_CLASS_VARIANTS( DeviceInterfaceVehicleDataClass )
EW_END_OF_CLASS_VARIANTS( DeviceInterfaceVehicleDataClass )

/* Virtual Method Table (VMT) for the class : 'DeviceInterface::VehicleDataClass' */
EW_DEFINE_CLASS( DeviceInterfaceVehicleDataClass, XObject, _.VMT, _.VMT, _.VMT, 
                 _.VMT, _.VMT, _.VMT, "DeviceInterface::VehicleDataClass" )
EW_END_OF_CLASS( DeviceInterfaceVehicleDataClass )

/* Initializer for the class 'DeviceInterface::NaviDataClass' */
void DeviceInterfaceNaviDataClass__Init( DeviceInterfaceNaviDataClass _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  XObject__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( DeviceInterfaceNaviDataClass );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( DeviceInterfaceNaviDataClass );
}

/* Re-Initializer for the class 'DeviceInterface::NaviDataClass' */
void DeviceInterfaceNaviDataClass__ReInit( DeviceInterfaceNaviDataClass _this )
{
  /* At first re-initialize the super class ... */
  XObject__ReInit( &_this->_.Super );
}

/* Finalizer method for the class 'DeviceInterface::NaviDataClass' */
void DeviceInterfaceNaviDataClass__Done( DeviceInterfaceNaviDataClass _this )
{
  /* Finalize this class */
  _this->_.Super._.VMT = EW_CLASS( XObject );

  /* Don't forget to deinitialize the super class ... */
  XObject__Done( &_this->_.Super );
}

/* Variants derived from the class : 'DeviceInterface::NaviDataClass' */
EW_DEFINE_CLASS_VARIANTS( DeviceInterfaceNaviDataClass )
EW_END_OF_CLASS_VARIANTS( DeviceInterfaceNaviDataClass )

/* Virtual Method Table (VMT) for the class : 'DeviceInterface::NaviDataClass' */
EW_DEFINE_CLASS( DeviceInterfaceNaviDataClass, XObject, CurrentRoad, CurrentRoad, 
                 CurrentRoad, CurrentRoad, CurrentRoad, ETA, "DeviceInterface::NaviDataClass" )
EW_END_OF_CLASS( DeviceInterfaceNaviDataClass )

/* Initializer for the class 'DeviceInterface::MotoConContext' */
void DeviceInterfaceMotoConContext__Init( DeviceInterfaceMotoConContext _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  XObject__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( DeviceInterfaceMotoConContext );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( DeviceInterfaceMotoConContext );
}

/* Re-Initializer for the class 'DeviceInterface::MotoConContext' */
void DeviceInterfaceMotoConContext__ReInit( DeviceInterfaceMotoConContext _this )
{
  /* At first re-initialize the super class ... */
  XObject__ReInit( &_this->_.Super );
}

/* Finalizer method for the class 'DeviceInterface::MotoConContext' */
void DeviceInterfaceMotoConContext__Done( DeviceInterfaceMotoConContext _this )
{
  /* Finalize this class */
  _this->_.Super._.VMT = EW_CLASS( XObject );

  /* Don't forget to deinitialize the super class ... */
  XObject__Done( &_this->_.Super );
}

/* Variants derived from the class : 'DeviceInterface::MotoConContext' */
EW_DEFINE_CLASS_VARIANTS( DeviceInterfaceMotoConContext )
EW_END_OF_CLASS_VARIANTS( DeviceInterfaceMotoConContext )

/* Virtual Method Table (VMT) for the class : 'DeviceInterface::MotoConContext' */
EW_DEFINE_CLASS( DeviceInterfaceMotoConContext, XObject, _.VMT, _.VMT, _.VMT, _.VMT, 
                 _.VMT, _.VMT, "DeviceInterface::MotoConContext" )
EW_END_OF_CLASS( DeviceInterfaceMotoConContext )

/* Initializer for the class 'DeviceInterface::NotificationDeviceClass' */
void DeviceInterfaceNotificationDeviceClass__Init( DeviceInterfaceNotificationDeviceClass _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  TemplatesDeviceClass__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( DeviceInterfaceNotificationDeviceClass );

  /* ... then construct all embedded objects */
  CoreSystemEvent__Init( &_this->NotificationListUpdatedSystemEvent, &_this->_.XObject, 0 );
  CoreSystemEvent__Init( &_this->PhoneCallStateChangedSystemEvent, &_this->_.XObject, 0 );
  CoreSystemEvent__Init( &_this->PhoneCallVolumeChangedSystemEvent, &_this->_.XObject, 0 );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( DeviceInterfaceNotificationDeviceClass );
}

/* Re-Initializer for the class 'DeviceInterface::NotificationDeviceClass' */
void DeviceInterfaceNotificationDeviceClass__ReInit( DeviceInterfaceNotificationDeviceClass _this )
{
  /* At first re-initialize the super class ... */
  TemplatesDeviceClass__ReInit( &_this->_.Super );

  /* ... then re-construct all embedded objects */
  CoreSystemEvent__ReInit( &_this->NotificationListUpdatedSystemEvent );
  CoreSystemEvent__ReInit( &_this->PhoneCallStateChangedSystemEvent );
  CoreSystemEvent__ReInit( &_this->PhoneCallVolumeChangedSystemEvent );
}

/* Finalizer method for the class 'DeviceInterface::NotificationDeviceClass' */
void DeviceInterfaceNotificationDeviceClass__Done( DeviceInterfaceNotificationDeviceClass _this )
{
  /* Finalize this class */
  _this->_.Super._.VMT = EW_CLASS( TemplatesDeviceClass );

  /* Finalize all embedded objects */
  CoreSystemEvent__Done( &_this->NotificationListUpdatedSystemEvent );
  CoreSystemEvent__Done( &_this->PhoneCallStateChangedSystemEvent );
  CoreSystemEvent__Done( &_this->PhoneCallVolumeChangedSystemEvent );

  /* Don't forget to deinitialize the super class ... */
  TemplatesDeviceClass__Done( &_this->_.Super );
}

/* This method is intended to be called by the device to notify the GUI application 
   about an alternation of its setting or state value. */
XBool DeviceInterfaceNotificationDeviceClass_IsPhoneCallStateActive( DeviceInterfaceNotificationDeviceClass _this )
{
  return (XBool)( EnumPhoneCallStateACTIVE == DeviceInterfaceNotificationDeviceClass_GetPhoneCallState( 
    _this ));
}

/* Wrapper function for the non virtual method : 'DeviceInterface::NotificationDeviceClass.IsPhoneCallStateActive()' */
XBool DeviceInterfaceNotificationDeviceClass__IsPhoneCallStateActive( void* _this )
{
  return DeviceInterfaceNotificationDeviceClass_IsPhoneCallStateActive((DeviceInterfaceNotificationDeviceClass)_this );
}

/* This method is intended to be called by the device to notify the GUI application 
   about a particular system event. */
void DeviceInterfaceNotificationDeviceClass_NotifyPhoneCallStateChanged( DeviceInterfaceNotificationDeviceClass _this )
{
  EwTrace( "%s", EwLoadString( &_Const000A ));
  CoreSystemEvent_Trigger( &_this->PhoneCallStateChangedSystemEvent, 0, 0 );
}

/* Wrapper function for the non virtual method : 'DeviceInterface::NotificationDeviceClass.NotifyPhoneCallStateChanged()' */
void DeviceInterfaceNotificationDeviceClass__NotifyPhoneCallStateChanged( void* _this )
{
  DeviceInterfaceNotificationDeviceClass_NotifyPhoneCallStateChanged((DeviceInterfaceNotificationDeviceClass)_this );
}

/* This method is intended to be called by the device to notify the GUI application 
   about a particular system event. */
void DeviceInterfaceNotificationDeviceClass_NotifyListUpdated( DeviceInterfaceNotificationDeviceClass _this )
{
  EwTrace( "%s", EwLoadString( &_Const000B ));
  CoreSystemEvent_Trigger( &_this->NotificationListUpdatedSystemEvent, 0, 0 );
}

/* Wrapper function for the non virtual method : 'DeviceInterface::NotificationDeviceClass.NotifyListUpdated()' */
void DeviceInterfaceNotificationDeviceClass__NotifyListUpdated( void* _this )
{
  DeviceInterfaceNotificationDeviceClass_NotifyListUpdated((DeviceInterfaceNotificationDeviceClass)_this );
}

/* 'C' function for method : 'DeviceInterface::NotificationDeviceClass.GetNotificationAtItem()' */
DeviceInterfaceNotificationContext DeviceInterfaceNotificationDeviceClass_GetNotificationAtItem( DeviceInterfaceNotificationDeviceClass _this, 
  XUInt32 aItemNo )
{
  DeviceInterfaceNotificationContext NotificationItem;
  XUInt32 Uid;
  XUInt16 CallRepetition;
  XUInt32 Category;
  XString Title;
  XString Subtitle;
  XString Message;
  XString ReceivedHour;
  XString ReceivedMinute;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  NotificationItem = EwNewObject( DeviceInterfaceNotificationContext, 0 );
  NotificationItem->ReceivedTime = EwNewObject( DeviceInterfaceDateTime, 0 );
  Uid = 0;
  CallRepetition = 0;
  Category = 0;
  Title = 0;
  Subtitle = 0;
  Message = 0;
  ReceivedHour = 0;
  ReceivedMinute = 0;
  {
    uint32_t notification_uid;
    uint16_t call_repetition;
    uint8_t  notification_title[NOTIFICATION_TITLE_MAX_LEN];
    uint8_t  notification_subtitle[NOTIFICATION_SUBTITLE_MAX_LEN];
    uint8_t  notification_message[NOTIFICATION_MESSAGE_MAX_LEN];
    notification_time_t received_time;
    EnumNotificationCategory notification_category;

    NTF_get_notification_at_idx( aItemNo, &notification_uid, &call_repetition,
                                 notification_title, NOTIFICATION_TITLE_MAX_LEN,
                                 notification_subtitle, NOTIFICATION_SUBTITLE_MAX_LEN,
                                 notification_message, NOTIFICATION_MESSAGE_MAX_LEN,
                                 &notification_category, &received_time );

    Uid = notification_uid;
    CallRepetition = call_repetition;

    uint8_t *stuffed_str = NULL;
    int stuffed_str_len = ew_handle_special_characters( notification_title, &stuffed_str );
    if( stuffed_str_len > 0 && stuffed_str != NULL )
    {
      Title = EwNewStringUtf8( stuffed_str, stuffed_str_len );
    }

    stuffed_str_len = ew_handle_special_characters( notification_subtitle, &stuffed_str );
    if( stuffed_str_len > 0 && stuffed_str != NULL )
    {
      Subtitle = EwNewStringUtf8( stuffed_str, stuffed_str_len );
    }

    stuffed_str_len = ew_handle_special_characters( notification_message, &stuffed_str );
    if( stuffed_str_len > 0 && stuffed_str != NULL )
    {
      Message = EwNewStringUtf8( stuffed_str, stuffed_str_len );
    }

    Category = notification_category;
    ReceivedHour = EwNewStringUInt( received_time.hour, 1, 10 );
    ReceivedMinute = EwNewStringUInt( received_time.minute, 2, 10 );
  }
  NotificationItem->Uid = Uid;
  NotificationItem->CallRepetition = CallRepetition;
  NotificationItem->Title = EwShareString( Title );
  NotificationItem->Subtitle = EwShareString( Subtitle );
  NotificationItem->Message = EwShareString( Message );
  NotificationItem->Category = (XEnum)Category;
  NotificationItem->ReceivedTime->Hour = EwShareString( ReceivedHour );
  NotificationItem->ReceivedTime->Minute = EwShareString( ReceivedMinute );
  return NotificationItem;
}

/* 'C' function for method : 'DeviceInterface::NotificationDeviceClass.OnGetNotificationNum()' */
XUInt32 DeviceInterfaceNotificationDeviceClass_OnGetNotificationNum( DeviceInterfaceNotificationDeviceClass _this )
{
  XUInt32 Num = 0;

  Num = NTF_get_notification_num();
  _this->NotificationNum = Num;
  return _this->NotificationNum;
}

/* 'C' function for method : 'DeviceInterface::NotificationDeviceClass.GetIncomingCallCaller()' */
XString DeviceInterfaceNotificationDeviceClass_GetIncomingCallCaller( DeviceInterfaceNotificationDeviceClass _this )
{
  XString Caller;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  Caller = 0;
  {
    uint8_t* phone_caller;
    uint8_t *stuffed_str = NULL;

    NTF_get_incoming_call_caller( &phone_caller );
    int stuffed_str_len = ew_handle_special_characters( phone_caller, &stuffed_str );
    if( stuffed_str_len > 0 && stuffed_str != NULL )
    {
      Caller = EwNewStringUtf8( stuffed_str, stuffed_str_len );
    }
  }
  return Caller;
}

/* Get active call duration in ms */
XUInt32 DeviceInterfaceNotificationDeviceClass_GetActiveCallDuration( DeviceInterfaceNotificationDeviceClass _this )
{
  XUInt32 DurationMS;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  DurationMS = 0;
  DurationMS = NTF_get_active_call_duration();
  return DurationMS;
}

/* 'C' function for method : 'DeviceInterface::NotificationDeviceClass.GetPhoneCallState()' */
XEnum DeviceInterfaceNotificationDeviceClass_GetPhoneCallState( DeviceInterfaceNotificationDeviceClass _this )
{
  XEnum PhoneCallState;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  PhoneCallState = EnumPhoneCallStateIDLE;
  {
    int32_t phone_call_state = NTF_get_phonecall_state();
    PhoneCallState = (EnumPhoneCallState)phone_call_state;
  }
  return PhoneCallState;
}

/* 'C' function for method : 'DeviceInterface::NotificationDeviceClass.AnswerPhoneCall()' */
void DeviceInterfaceNotificationDeviceClass_AnswerPhoneCall( DeviceInterfaceNotificationDeviceClass _this )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  NTF_answer_call();
}

/* 'C' function for method : 'DeviceInterface::NotificationDeviceClass.DeclinePhoneCall()' */
void DeviceInterfaceNotificationDeviceClass_DeclinePhoneCall( DeviceInterfaceNotificationDeviceClass _this )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  NTF_decline_call();
}

/* This method is intended to be called by the device to notify the GUI application 
   about an alternation of its setting or state value. */
XBool DeviceInterfaceNotificationDeviceClass_IsPhoneCallVolumeControllable( DeviceInterfaceNotificationDeviceClass _this )
{
  XBool Controllable;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  Controllable = 0;
  Controllable = NTF_is_phonecall_volume_controllable();
  return Controllable;
}

/* Wrapper function for the non virtual method : 'DeviceInterface::NotificationDeviceClass.IsPhoneCallVolumeControllable()' */
XBool DeviceInterfaceNotificationDeviceClass__IsPhoneCallVolumeControllable( void* _this )
{
  return DeviceInterfaceNotificationDeviceClass_IsPhoneCallVolumeControllable((DeviceInterfaceNotificationDeviceClass)_this );
}

/* 'C' function for method : 'DeviceInterface::NotificationDeviceClass.PhoneCallVolumeControl()' */
void DeviceInterfaceNotificationDeviceClass_PhoneCallVolumeControl( DeviceInterfaceNotificationDeviceClass _this, 
  XEnum aControl )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  NTF_phonecall_volume_control( aControl );
}

/* This method is intended to be called by the device to notify the GUI application 
   about a particular system event. */
void DeviceInterfaceNotificationDeviceClass_NotifyPhoneCallVolumeChanged( DeviceInterfaceNotificationDeviceClass _this )
{
  EwTrace( "%s", EwLoadString( &_Const000C ));
  CoreSystemEvent_Trigger( &_this->PhoneCallVolumeChangedSystemEvent, 0, 0 );
}

/* Wrapper function for the non virtual method : 'DeviceInterface::NotificationDeviceClass.NotifyPhoneCallVolumeChanged()' */
void DeviceInterfaceNotificationDeviceClass__NotifyPhoneCallVolumeChanged( void* _this )
{
  DeviceInterfaceNotificationDeviceClass_NotifyPhoneCallVolumeChanged((DeviceInterfaceNotificationDeviceClass)_this );
}

/* 'C' function for method : 'DeviceInterface::NotificationDeviceClass.GetPhoneCallVolume()' */
XUInt32 DeviceInterfaceNotificationDeviceClass_GetPhoneCallVolume( DeviceInterfaceNotificationDeviceClass _this )
{
  XUInt32 PhoneCallVolume;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  PhoneCallVolume = 0;
  PhoneCallVolume = BC_motocon_get_phonecall_volume();
  return PhoneCallVolume;
}

/* 'C' function for method : 'DeviceInterface::NotificationDeviceClass.GetNotificationNumOfCategory()' */
XInt32 DeviceInterfaceNotificationDeviceClass_GetNotificationNumOfCategory( DeviceInterfaceNotificationDeviceClass _this, 
  XEnum aCategory )
{
  XInt32 Num;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  Num = 0;
  Num = NTF_get_notification_num_of_category( aCategory );
  return Num;
}

/* 'C' function for method : 'DeviceInterface::NotificationDeviceClass.GetActiveCallCaller()' */
XString DeviceInterfaceNotificationDeviceClass_GetActiveCallCaller( DeviceInterfaceNotificationDeviceClass _this )
{
  XString Caller;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  Caller = 0;
  {
    uint8_t* phone_caller;
    uint8_t* stuffed_str = NULL;

    NTF_get_active_call_caller( &phone_caller );
    int stuffed_str_len = ew_handle_special_characters( phone_caller, &stuffed_str );
    if( stuffed_str_len > 0 && stuffed_str != NULL )
    {
      Caller = EwNewStringUtf8( stuffed_str, stuffed_str_len );
    }
  }
  return Caller;
}

/* 'C' function for method : 'DeviceInterface::NotificationDeviceClass.CallNative()' */
XInt32 DeviceInterfaceNotificationDeviceClass_CallNative( DeviceInterfaceNotificationDeviceClass _this, 
  XEnum aCmd, XUInt32 aData )
{
  XInt32 result;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  result = 0;
  result = NTF_call_native( aCmd, aData );
  return result;
}

/* Variants derived from the class : 'DeviceInterface::NotificationDeviceClass' */
EW_DEFINE_CLASS_VARIANTS( DeviceInterfaceNotificationDeviceClass )
EW_END_OF_CLASS_VARIANTS( DeviceInterfaceNotificationDeviceClass )

/* Virtual Method Table (VMT) for the class : 'DeviceInterface::NotificationDeviceClass' */
EW_DEFINE_CLASS( DeviceInterfaceNotificationDeviceClass, TemplatesDeviceClass, NotificationListUpdatedSystemEvent, 
                 NotificationListUpdatedSystemEvent, NotificationListUpdatedSystemEvent, 
                 NotificationListUpdatedSystemEvent, NotificationNum, NotificationNum, 
                 "DeviceInterface::NotificationDeviceClass" )
EW_END_OF_CLASS( DeviceInterfaceNotificationDeviceClass )

/* User defined auto object: 'DeviceInterface::NotificationDevice' */
EW_DEFINE_AUTOOBJECT( DeviceInterfaceNotificationDevice, DeviceInterfaceNotificationDeviceClass )

/* Initializer for the auto object 'DeviceInterface::NotificationDevice' */
void DeviceInterfaceNotificationDevice__Init( DeviceInterfaceNotificationDeviceClass _this )
{
  EW_UNUSED_ARG( _this );
}

/* Table with links to derived variants of the auto object : 'DeviceInterface::NotificationDevice' */
EW_DEFINE_AUTOOBJECT_VARIANTS( DeviceInterfaceNotificationDevice )
EW_END_OF_AUTOOBJECT_VARIANTS( DeviceInterfaceNotificationDevice )

/* Initializer for the class 'DeviceInterface::DateTime' */
void DeviceInterfaceDateTime__Init( DeviceInterfaceDateTime _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  XObject__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( DeviceInterfaceDateTime );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( DeviceInterfaceDateTime );
}

/* Re-Initializer for the class 'DeviceInterface::DateTime' */
void DeviceInterfaceDateTime__ReInit( DeviceInterfaceDateTime _this )
{
  /* At first re-initialize the super class ... */
  XObject__ReInit( &_this->_.Super );
}

/* Finalizer method for the class 'DeviceInterface::DateTime' */
void DeviceInterfaceDateTime__Done( DeviceInterfaceDateTime _this )
{
  /* Finalize this class */
  _this->_.Super._.VMT = EW_CLASS( XObject );

  /* Don't forget to deinitialize the super class ... */
  XObject__Done( &_this->_.Super );
}

/* Variants derived from the class : 'DeviceInterface::DateTime' */
EW_DEFINE_CLASS_VARIANTS( DeviceInterfaceDateTime )
EW_END_OF_CLASS_VARIANTS( DeviceInterfaceDateTime )

/* Virtual Method Table (VMT) for the class : 'DeviceInterface::DateTime' */
EW_DEFINE_CLASS( DeviceInterfaceDateTime, XObject, Hour, Hour, Hour, Hour, Hour, 
                 _.VMT, "DeviceInterface::DateTime" )
EW_END_OF_CLASS( DeviceInterfaceDateTime )

/* Initializer for the class 'DeviceInterface::NotificationContext' */
void DeviceInterfaceNotificationContext__Init( DeviceInterfaceNotificationContext _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  XObject__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( DeviceInterfaceNotificationContext );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( DeviceInterfaceNotificationContext );
}

/* Re-Initializer for the class 'DeviceInterface::NotificationContext' */
void DeviceInterfaceNotificationContext__ReInit( DeviceInterfaceNotificationContext _this )
{
  /* At first re-initialize the super class ... */
  XObject__ReInit( &_this->_.Super );
}

/* Finalizer method for the class 'DeviceInterface::NotificationContext' */
void DeviceInterfaceNotificationContext__Done( DeviceInterfaceNotificationContext _this )
{
  /* Finalize this class */
  _this->_.Super._.VMT = EW_CLASS( XObject );

  /* Don't forget to deinitialize the super class ... */
  XObject__Done( &_this->_.Super );
}

/* Variants derived from the class : 'DeviceInterface::NotificationContext' */
EW_DEFINE_CLASS_VARIANTS( DeviceInterfaceNotificationContext )
EW_END_OF_CLASS_VARIANTS( DeviceInterfaceNotificationContext )

/* Virtual Method Table (VMT) for the class : 'DeviceInterface::NotificationContext' */
EW_DEFINE_CLASS( DeviceInterfaceNotificationContext, XObject, ReceivedTime, Title, 
                 Title, Title, Title, Uid, "DeviceInterface::NotificationContext" )
EW_END_OF_CLASS( DeviceInterfaceNotificationContext )

/* Initializer for the class 'DeviceInterface::SystemData' */
void DeviceInterfaceSystemData__Init( DeviceInterfaceSystemData _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  XObject__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( DeviceInterfaceSystemData );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( DeviceInterfaceSystemData );
}

/* Re-Initializer for the class 'DeviceInterface::SystemData' */
void DeviceInterfaceSystemData__ReInit( DeviceInterfaceSystemData _this )
{
  /* At first re-initialize the super class ... */
  XObject__ReInit( &_this->_.Super );
}

/* Finalizer method for the class 'DeviceInterface::SystemData' */
void DeviceInterfaceSystemData__Done( DeviceInterfaceSystemData _this )
{
  /* Finalize this class */
  _this->_.Super._.VMT = EW_CLASS( XObject );

  /* Don't forget to deinitialize the super class ... */
  XObject__Done( &_this->_.Super );
}

/* Variants derived from the class : 'DeviceInterface::SystemData' */
EW_DEFINE_CLASS_VARIANTS( DeviceInterfaceSystemData )
EW_END_OF_CLASS_VARIANTS( DeviceInterfaceSystemData )

/* Virtual Method Table (VMT) for the class : 'DeviceInterface::SystemData' */
EW_DEFINE_CLASS( DeviceInterfaceSystemData, XObject, _.VMT, _.VMT, _.VMT, _.VMT, 
                 _.VMT, _.VMT, "DeviceInterface::SystemData" )
EW_END_OF_CLASS( DeviceInterfaceSystemData )

/* Initializer for the class 'DeviceInterface::NaviTbtDataClass' */
void DeviceInterfaceNaviTbtDataClass__Init( DeviceInterfaceNaviTbtDataClass _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  XObject__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( DeviceInterfaceNaviTbtDataClass );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( DeviceInterfaceNaviTbtDataClass );
}

/* Re-Initializer for the class 'DeviceInterface::NaviTbtDataClass' */
void DeviceInterfaceNaviTbtDataClass__ReInit( DeviceInterfaceNaviTbtDataClass _this )
{
  /* At first re-initialize the super class ... */
  XObject__ReInit( &_this->_.Super );
}

/* Finalizer method for the class 'DeviceInterface::NaviTbtDataClass' */
void DeviceInterfaceNaviTbtDataClass__Done( DeviceInterfaceNaviTbtDataClass _this )
{
  /* Finalize this class */
  _this->_.Super._.VMT = EW_CLASS( XObject );

  /* Don't forget to deinitialize the super class ... */
  XObject__Done( &_this->_.Super );
}

/* Variants derived from the class : 'DeviceInterface::NaviTbtDataClass' */
EW_DEFINE_CLASS_VARIANTS( DeviceInterfaceNaviTbtDataClass )
EW_END_OF_CLASS_VARIANTS( DeviceInterfaceNaviTbtDataClass )

/* Virtual Method Table (VMT) for the class : 'DeviceInterface::NaviTbtDataClass' */
EW_DEFINE_CLASS( DeviceInterfaceNaviTbtDataClass, XObject, DistUnit, DistUnit, DistUnit, 
                 DistUnit, DistUnit, IconIdx, "DeviceInterface::NaviTbtDataClass" )
EW_END_OF_CLASS( DeviceInterfaceNaviTbtDataClass )

/* Initializer for the class 'DeviceInterface::NaviPoiDataClass' */
void DeviceInterfaceNaviPoiDataClass__Init( DeviceInterfaceNaviPoiDataClass _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  XObject__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( DeviceInterfaceNaviPoiDataClass );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( DeviceInterfaceNaviPoiDataClass );
}

/* Re-Initializer for the class 'DeviceInterface::NaviPoiDataClass' */
void DeviceInterfaceNaviPoiDataClass__ReInit( DeviceInterfaceNaviPoiDataClass _this )
{
  /* At first re-initialize the super class ... */
  XObject__ReInit( &_this->_.Super );
}

/* Finalizer method for the class 'DeviceInterface::NaviPoiDataClass' */
void DeviceInterfaceNaviPoiDataClass__Done( DeviceInterfaceNaviPoiDataClass _this )
{
  /* Finalize this class */
  _this->_.Super._.VMT = EW_CLASS( XObject );

  /* Don't forget to deinitialize the super class ... */
  XObject__Done( &_this->_.Super );
}

/* Variants derived from the class : 'DeviceInterface::NaviPoiDataClass' */
EW_DEFINE_CLASS_VARIANTS( DeviceInterfaceNaviPoiDataClass )
EW_END_OF_CLASS_VARIANTS( DeviceInterfaceNaviPoiDataClass )

/* Virtual Method Table (VMT) for the class : 'DeviceInterface::NaviPoiDataClass' */
EW_DEFINE_CLASS( DeviceInterfaceNaviPoiDataClass, XObject, DistUnit, DistUnit, DistUnit, 
                 DistUnit, DistUnit, Distance, "DeviceInterface::NaviPoiDataClass" )
EW_END_OF_CLASS( DeviceInterfaceNaviPoiDataClass )

/* Initializer for the class 'DeviceInterface::BtmStatusContext' */
void DeviceInterfaceBtmStatusContext__Init( DeviceInterfaceBtmStatusContext _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  XObject__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( DeviceInterfaceBtmStatusContext );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( DeviceInterfaceBtmStatusContext );
}

/* Re-Initializer for the class 'DeviceInterface::BtmStatusContext' */
void DeviceInterfaceBtmStatusContext__ReInit( DeviceInterfaceBtmStatusContext _this )
{
  /* At first re-initialize the super class ... */
  XObject__ReInit( &_this->_.Super );
}

/* Finalizer method for the class 'DeviceInterface::BtmStatusContext' */
void DeviceInterfaceBtmStatusContext__Done( DeviceInterfaceBtmStatusContext _this )
{
  /* Finalize this class */
  _this->_.Super._.VMT = EW_CLASS( XObject );

  /* Don't forget to deinitialize the super class ... */
  XObject__Done( &_this->_.Super );
}

/* Variants derived from the class : 'DeviceInterface::BtmStatusContext' */
EW_DEFINE_CLASS_VARIANTS( DeviceInterfaceBtmStatusContext )
EW_END_OF_CLASS_VARIANTS( DeviceInterfaceBtmStatusContext )

/* Virtual Method Table (VMT) for the class : 'DeviceInterface::BtmStatusContext' */
EW_DEFINE_CLASS( DeviceInterfaceBtmStatusContext, XObject, _.VMT, _.VMT, _.VMT, 
                 _.VMT, _.VMT, _.VMT, "DeviceInterface::BtmStatusContext" )
EW_END_OF_CLASS( DeviceInterfaceBtmStatusContext )

/* Initializer for the class 'DeviceInterface::ConnectionStatusContext' */
void DeviceInterfaceConnectionStatusContext__Init( DeviceInterfaceConnectionStatusContext _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  XObject__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( DeviceInterfaceConnectionStatusContext );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( DeviceInterfaceConnectionStatusContext );
}

/* Re-Initializer for the class 'DeviceInterface::ConnectionStatusContext' */
void DeviceInterfaceConnectionStatusContext__ReInit( DeviceInterfaceConnectionStatusContext _this )
{
  /* At first re-initialize the super class ... */
  XObject__ReInit( &_this->_.Super );
}

/* Finalizer method for the class 'DeviceInterface::ConnectionStatusContext' */
void DeviceInterfaceConnectionStatusContext__Done( DeviceInterfaceConnectionStatusContext _this )
{
  /* Finalize this class */
  _this->_.Super._.VMT = EW_CLASS( XObject );

  /* Don't forget to deinitialize the super class ... */
  XObject__Done( &_this->_.Super );
}

/* Variants derived from the class : 'DeviceInterface::ConnectionStatusContext' */
EW_DEFINE_CLASS_VARIANTS( DeviceInterfaceConnectionStatusContext )
EW_END_OF_CLASS_VARIANTS( DeviceInterfaceConnectionStatusContext )

/* Virtual Method Table (VMT) for the class : 'DeviceInterface::ConnectionStatusContext' */
EW_DEFINE_CLASS( DeviceInterfaceConnectionStatusContext, XObject, _.VMT, _.VMT, 
                 _.VMT, _.VMT, _.VMT, _.VMT, "DeviceInterface::ConnectionStatusContext" )
EW_END_OF_CLASS( DeviceInterfaceConnectionStatusContext )

/* Embedded Wizard */
