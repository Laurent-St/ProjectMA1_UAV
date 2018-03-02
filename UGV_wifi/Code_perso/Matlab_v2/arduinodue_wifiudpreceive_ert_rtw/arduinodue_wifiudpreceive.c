/*
 * arduinodue_wifiudpreceive.c
 *
 * Code generation for model "arduinodue_wifiudpreceive".
 *
 * Model version              : 1.38
 * Simulink Coder version : 8.13 (R2017b) 24-Jul-2017
 * C source code generated on : Mon Dec 18 20:57:57 2017
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "arduinodue_wifiudpreceive.h"
#include "arduinodue_wifiudpreceive_private.h"
#include "arduinodue_wifiudpreceive_dt.h"
#define arduinodue_wifiudp_wifiUDPIndex ((uint8_T)0U)
#define arduinodue_wifiudprec_localport (333.0)

/* Block signals (auto storage) */
B_arduinodue_wifiudpreceive_T arduinodue_wifiudpreceive_B;

/* Block states (auto storage) */
DW_arduinodue_wifiudpreceive_T arduinodue_wifiudpreceive_DW;

/* Real-time model */
RT_MODEL_arduinodue_wifiudpre_T arduinodue_wifiudpreceive_M_;
RT_MODEL_arduinodue_wifiudpre_T *const arduinodue_wifiudpreceive_M =
  &arduinodue_wifiudpreceive_M_;

/* Model step function */
void arduinodue_wifiudpreceive_step(void)
{
  uint16_T b_varargout_2;
  int16_T b_varargout_1[4];

  /* Start for MATLABSystem: '<Root>/WiFi UDP Receive' */
  MW_WifiUDPFinalRead(arduinodue_wifiudp_wifiUDPIndex, b_varargout_1, 8U, 2U,
                      &b_varargout_2);

  /* MATLABSystem: '<Root>/WiFi UDP Receive' */
  arduinodue_wifiudpreceive_B.WiFiUDPReceive_o1[0] = b_varargout_1[0];
  arduinodue_wifiudpreceive_B.WiFiUDPReceive_o1[1] = b_varargout_1[1];
  arduinodue_wifiudpreceive_B.WiFiUDPReceive_o1[2] = b_varargout_1[2];
  arduinodue_wifiudpreceive_B.WiFiUDPReceive_o1[3] = b_varargout_1[3];
  arduinodue_wifiudpreceive_B.WiFiUDPReceive_o2 = b_varargout_2;

  /* External mode */
  rtExtModeUploadCheckTrigger(1);

  {                                    /* Sample time: [0.5s, 0.0s] */
    rtExtModeUpload(0, arduinodue_wifiudpreceive_M->Timing.taskTime0);
  }

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.5s, 0.0s] */
    if ((rtmGetTFinal(arduinodue_wifiudpreceive_M)!=-1) &&
        !((rtmGetTFinal(arduinodue_wifiudpreceive_M)-
           arduinodue_wifiudpreceive_M->Timing.taskTime0) >
          arduinodue_wifiudpreceive_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(arduinodue_wifiudpreceive_M, "Simulation finished");
    }

    if (rtmGetStopRequested(arduinodue_wifiudpreceive_M)) {
      rtmSetErrorStatus(arduinodue_wifiudpreceive_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  arduinodue_wifiudpreceive_M->Timing.taskTime0 =
    (++arduinodue_wifiudpreceive_M->Timing.clockTick0) *
    arduinodue_wifiudpreceive_M->Timing.stepSize0;
}

/* Model initialize function */
void arduinodue_wifiudpreceive_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)arduinodue_wifiudpreceive_M, 0,
                sizeof(RT_MODEL_arduinodue_wifiudpre_T));
  rtmSetTFinal(arduinodue_wifiudpreceive_M, -1);
  arduinodue_wifiudpreceive_M->Timing.stepSize0 = 0.5;

  /* External mode info */
  arduinodue_wifiudpreceive_M->Sizes.checksums[0] = (4276367905U);
  arduinodue_wifiudpreceive_M->Sizes.checksums[1] = (3167913560U);
  arduinodue_wifiudpreceive_M->Sizes.checksums[2] = (3841767187U);
  arduinodue_wifiudpreceive_M->Sizes.checksums[3] = (2439879436U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[2];
    arduinodue_wifiudpreceive_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(arduinodue_wifiudpreceive_M->extModeInfo,
      &arduinodue_wifiudpreceive_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(arduinodue_wifiudpreceive_M->extModeInfo,
                        arduinodue_wifiudpreceive_M->Sizes.checksums);
    rteiSetTPtr(arduinodue_wifiudpreceive_M->extModeInfo, rtmGetTPtr
                (arduinodue_wifiudpreceive_M));
  }

  /* block I/O */
  (void) memset(((void *) &arduinodue_wifiudpreceive_B), 0,
                sizeof(B_arduinodue_wifiudpreceive_T));

  /* states (dwork) */
  (void) memset((void *)&arduinodue_wifiudpreceive_DW, 0,
                sizeof(DW_arduinodue_wifiudpreceive_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    arduinodue_wifiudpreceive_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 15;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;
  }

  /* Start for MATLABSystem: '<Root>/WiFi UDP Receive' */
  arduinodue_wifiudpreceive_DW.obj.isInitialized = 0;
  arduinodue_wifiudpreceive_DW.obj.isInitialized = 1;
  MW_WifiAndUDPBegin(arduinodue_wifiudp_wifiUDPIndex, 0.0, 0.0, 0.0, 0.0, 0.0,
                     arduinodue_wifiudprec_localport, 0U);
}

/* Model terminate function */
void arduinodue_wifiudpreceive_terminate(void)
{
  /* Start for MATLABSystem: '<Root>/WiFi UDP Receive' */
  if (arduinodue_wifiudpreceive_DW.obj.isInitialized == 1) {
    arduinodue_wifiudpreceive_DW.obj.isInitialized = 2;
  }

  /* End of Start for MATLABSystem: '<Root>/WiFi UDP Receive' */
}
