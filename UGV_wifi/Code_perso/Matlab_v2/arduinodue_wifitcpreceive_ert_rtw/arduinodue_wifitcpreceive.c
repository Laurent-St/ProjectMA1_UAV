/*
 * arduinodue_wifitcpreceive.c
 *
 * Code generation for model "arduinodue_wifitcpreceive".
 *
 * Model version              : 1.36
 * Simulink Coder version : 8.13 (R2017b) 24-Jul-2017
 * C source code generated on : Sat Dec 16 19:34:23 2017
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "arduinodue_wifitcpreceive.h"
#include "arduinodue_wifitcpreceive_private.h"
#define arduinodue_w_wifiTCPServerIndex ((uint8_T)0U)
#define arduinodue_wifit_floatprecision (2.0)
#define arduinodue_wifit_remoteipoctet1 ((uint8_T)192U)
#define arduinodue_wifit_remoteipoctet2 ((uint8_T)168U)
#define arduinodue_wifit_remoteipoctet3 ((uint8_T)1U)
#define arduinodue_wifit_remoteipoctet4 ((uint8_T)2U)
#define arduinodue_wifitcpre_serverport (50000.0)
#define arduinodue_wifitcprec_DataSize_ (5.0)
#define arduinodue_wifitcprec_PinNumber (9.0)

/* Block states (auto storage) */
DW_arduinodue_wifitcpreceive_T arduinodue_wifitcpreceive_DW;

/* Real-time model */
RT_MODEL_arduinodue_wifitcpre_T arduinodue_wifitcpreceive_M_;
RT_MODEL_arduinodue_wifitcpre_T *const arduinodue_wifitcpreceive_M =
  &arduinodue_wifitcpreceive_M_;

/* Model step function */
void arduinodue_wifitcpreceive_step(void)
{
  int32_T b_varargout_2;
  uint8_T b_varargout_1[5];
  char_T tmp[5];

  /* MATLABSystem: '<Root>/WiFi TCP//IP Receive' */
  if (arduinodue_wifitcpreceive_DW.obj_b.TunablePropsChanged) {
    arduinodue_wifitcpreceive_DW.obj_b.TunablePropsChanged = false;
  }

  MW_WifiTCPFinalread(arduinodue_w_wifiTCPServerIndex, b_varargout_1, (uint16_T)
                      arduinodue_wifitcprec_DataSize_, &b_varargout_2,
                      arduinodue_wifitcpreceive_DW.obj_b.isServer_, 1000U);

  /* DataTypeConversion: '<S1>/Data Type Conversion' incorporates:
   *  MATLABSystem: '<Root>/WiFi TCP//IP Receive'
   */
  if (b_varargout_2 < 0) {
    b_varargout_2 = 0;
  } else {
    if (b_varargout_2 > 255) {
      b_varargout_2 = 255;
    }
  }

  /* MATLABSystem: '<S1>/Digital Output' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion'
   */
  writeDigitalPin((uint8_T)arduinodue_wifitcprec_PinNumber, (uint8_T)
                  b_varargout_2);

  /* MATLABSystem: '<Root>/Serial Transmit' */
  tmp[0] = 'D';
  tmp[1] = 'a';
  tmp[2] = 't';
  tmp[3] = 'a';
  tmp[4] = '\x00';
  MW_Serial_write(arduinodue_wifitcpreceive_DW.obj.port, b_varargout_1, 5.0,
                  arduinodue_wifitcpreceive_DW.obj.dataSizeInBytes,
                  arduinodue_wifitcpreceive_DW.obj.sendModeEnum,
                  arduinodue_wifitcpreceive_DW.obj.dataType,
                  arduinodue_wifitcpreceive_DW.obj.sendFormatEnum,
                  arduinodue_wifit_floatprecision, tmp);
}

/* Model initialize function */
void arduinodue_wifitcpreceive_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(arduinodue_wifitcpreceive_M, (NULL));

  /* states (dwork) */
  (void) memset((void *)&arduinodue_wifitcpreceive_DW, 0,
                sizeof(DW_arduinodue_wifitcpreceive_T));

  /* Start for MATLABSystem: '<Root>/WiFi TCP//IP Receive' */
  arduinodue_wifitcpreceive_DW.obj_b.isInitialized = 0;
  arduinodue_wifitcpreceive_DW.obj_b.isInitialized = 1;
  if (arduinodue_wifitcpreceive_DW.obj_b.isInitialized == 1) {
    arduinodue_wifitcpreceive_DW.obj_b.TunablePropsChanged = true;
  }

  arduinodue_wifitcpreceive_DW.obj_b.isServer_ = 1.0;
  MW_WifiAndWifiTCPServerBegin(arduinodue_w_wifiTCPServerIndex,
    arduinodue_wifitcpre_serverport,
    arduinodue_wifitcpreceive_DW.obj_b.isServer_,
    arduinodue_wifit_remoteipoctet1, arduinodue_wifit_remoteipoctet2,
    arduinodue_wifit_remoteipoctet3, arduinodue_wifit_remoteipoctet4);
  arduinodue_wifitcpreceive_DW.obj_b.TunablePropsChanged = false;

  /* End of Start for MATLABSystem: '<Root>/WiFi TCP//IP Receive' */

  /* Start for MATLABSystem: '<S1>/Digital Output' */
  arduinodue_wifitcpreceive_DW.obj_j.isInitialized = 0;
  arduinodue_wifitcpreceive_DW.obj_j.isInitialized = 1;
  digitalIOSetup((uint8_T)arduinodue_wifitcprec_PinNumber, true);

  /* Start for MATLABSystem: '<Root>/Serial Transmit' */
  arduinodue_wifitcpreceive_DW.obj.isInitialized = 0;
  arduinodue_wifitcpreceive_DW.obj.isInitialized = 1;
  arduinodue_wifitcpreceive_DW.obj.port = 0.0;
  arduinodue_wifitcpreceive_DW.obj.dataSizeInBytes = 1.0;
  arduinodue_wifitcpreceive_DW.obj.dataType = 0.0;
  arduinodue_wifitcpreceive_DW.obj.sendModeEnum = 2.0;
  arduinodue_wifitcpreceive_DW.obj.sendFormatEnum = 0.0;
}

/* Model terminate function */
void arduinodue_wifitcpreceive_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/WiFi TCP//IP Receive' */
  if (arduinodue_wifitcpreceive_DW.obj_b.isInitialized == 1) {
    arduinodue_wifitcpreceive_DW.obj_b.isInitialized = 2;
  }

  /* End of Terminate for MATLABSystem: '<Root>/WiFi TCP//IP Receive' */

  /* Terminate for MATLABSystem: '<S1>/Digital Output' */
  if (arduinodue_wifitcpreceive_DW.obj_j.isInitialized == 1) {
    arduinodue_wifitcpreceive_DW.obj_j.isInitialized = 2;
  }

  /* End of Terminate for MATLABSystem: '<S1>/Digital Output' */

  /* Terminate for MATLABSystem: '<Root>/Serial Transmit' */
  if (arduinodue_wifitcpreceive_DW.obj.isInitialized == 1) {
    arduinodue_wifitcpreceive_DW.obj.isInitialized = 2;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Serial Transmit' */
}
