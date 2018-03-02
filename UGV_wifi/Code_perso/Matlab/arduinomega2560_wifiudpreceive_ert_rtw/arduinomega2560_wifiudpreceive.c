/*
 * arduinomega2560_wifiudpreceive.c
 *
 * Code generation for model "arduinomega2560_wifiudpreceive".
 *
 * Model version              : 1.33
 * Simulink Coder version : 8.13 (R2017b) 24-Jul-2017
 * C source code generated on : Sun Dec 10 12:30:53 2017
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "arduinomega2560_wifiudpreceive.h"
#include "arduinomega2560_wifiudpreceive_private.h"
#include "arduinomega2560_wifiudpreceive_dt.h"
#define arduinomega2560_wi_wifiUDPIndex ((uint8_T)0U)
#define arduinomega2560_wifiu_localport (333.0)

/* Block signals (auto storage) */
B_arduinomega2560_wifiudprece_T arduinomega2560_wifiudpreceiv_B;

/* Block states (auto storage) */
DW_arduinomega2560_wifiudprec_T arduinomega2560_wifiudprecei_DW;

/* Real-time model */
RT_MODEL_arduinomega2560_wifi_T arduinomega2560_wifiudprecei_M_;
RT_MODEL_arduinomega2560_wifi_T *const arduinomega2560_wifiudprecei_M =
  &arduinomega2560_wifiudprecei_M_;

/* Model step function */
void arduinomega2560_wifiudpreceive_step(void)
{
  uint16_T b_varargout_2;
  int16_T b_varargout_1[4];

  /* MATLABSystem: '<Root>/WiFi UDP Receive' */
  MW_WifiUDPFinalRead(arduinomega2560_wi_wifiUDPIndex, b_varargout_1, 8U, 2U,
                      &b_varargout_2);
  arduinomega2560_wifiudpreceiv_B.WiFiUDPReceive_o1[0] = b_varargout_1[0];
  arduinomega2560_wifiudpreceiv_B.WiFiUDPReceive_o1[1] = b_varargout_1[1];
  arduinomega2560_wifiudpreceiv_B.WiFiUDPReceive_o1[2] = b_varargout_1[2];
  arduinomega2560_wifiudpreceiv_B.WiFiUDPReceive_o1[3] = b_varargout_1[3];
  arduinomega2560_wifiudpreceiv_B.WiFiUDPReceive_o2 = b_varargout_2;

  /* External mode */
  rtExtModeUploadCheckTrigger(1);

  {                                    /* Sample time: [0.5s, 0.0s] */
    rtExtModeUpload(0, arduinomega2560_wifiudprecei_M->Timing.taskTime0);
  }

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.5s, 0.0s] */
    if ((rtmGetTFinal(arduinomega2560_wifiudprecei_M)!=-1) &&
        !((rtmGetTFinal(arduinomega2560_wifiudprecei_M)-
           arduinomega2560_wifiudprecei_M->Timing.taskTime0) >
          arduinomega2560_wifiudprecei_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(arduinomega2560_wifiudprecei_M, "Simulation finished");
    }

    if (rtmGetStopRequested(arduinomega2560_wifiudprecei_M)) {
      rtmSetErrorStatus(arduinomega2560_wifiudprecei_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  arduinomega2560_wifiudprecei_M->Timing.taskTime0 =
    (++arduinomega2560_wifiudprecei_M->Timing.clockTick0) *
    arduinomega2560_wifiudprecei_M->Timing.stepSize0;
}

/* Model initialize function */
void arduinomega2560_wifiudpreceive_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)arduinomega2560_wifiudprecei_M, 0,
                sizeof(RT_MODEL_arduinomega2560_wifi_T));
  rtmSetTFinal(arduinomega2560_wifiudprecei_M, -1);
  arduinomega2560_wifiudprecei_M->Timing.stepSize0 = 0.5;

  /* External mode info */
  arduinomega2560_wifiudprecei_M->Sizes.checksums[0] = (3398164093U);
  arduinomega2560_wifiudprecei_M->Sizes.checksums[1] = (1028376500U);
  arduinomega2560_wifiudprecei_M->Sizes.checksums[2] = (1911327118U);
  arduinomega2560_wifiudprecei_M->Sizes.checksums[3] = (735556029U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[2];
    arduinomega2560_wifiudprecei_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(arduinomega2560_wifiudprecei_M->extModeInfo,
      &arduinomega2560_wifiudprecei_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(arduinomega2560_wifiudprecei_M->extModeInfo,
                        arduinomega2560_wifiudprecei_M->Sizes.checksums);
    rteiSetTPtr(arduinomega2560_wifiudprecei_M->extModeInfo, rtmGetTPtr
                (arduinomega2560_wifiudprecei_M));
  }

  /* block I/O */
  (void) memset(((void *) &arduinomega2560_wifiudpreceiv_B), 0,
                sizeof(B_arduinomega2560_wifiudprece_T));

  /* states (dwork) */
  (void) memset((void *)&arduinomega2560_wifiudprecei_DW, 0,
                sizeof(DW_arduinomega2560_wifiudprec_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    arduinomega2560_wifiudprecei_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 15;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;
  }

  /* Start for MATLABSystem: '<Root>/WiFi UDP Receive' */
  arduinomega2560_wifiudprecei_DW.obj.isInitialized = 0;
  arduinomega2560_wifiudprecei_DW.obj.isInitialized = 1;
  MW_WifiAndUDPBegin(arduinomega2560_wi_wifiUDPIndex, 0.0, 0.0, 0.0, 0.0, 0.0,
                     arduinomega2560_wifiu_localport, 0U);
}

/* Model terminate function */
void arduinomega2560_wifiudpreceive_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/WiFi UDP Receive' */
  if (arduinomega2560_wifiudprecei_DW.obj.isInitialized == 1) {
    arduinomega2560_wifiudprecei_DW.obj.isInitialized = 2;
  }

  /* End of Terminate for MATLABSystem: '<Root>/WiFi UDP Receive' */
}
