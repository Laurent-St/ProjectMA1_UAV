/*
 * arduinomega2560_wifiudpsend.c
 *
 * Code generation for model "arduinomega2560_wifiudpsend".
 *
 * Model version              : 1.26
 * Simulink Coder version : 8.13 (R2017b) 24-Jul-2017
 * C source code generated on : Sun Dec 10 13:19:03 2017
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "arduinomega2560_wifiudpsend.h"
#include "arduinomega2560_wifiudpsend_private.h"
#define arduinomega2560__remoteipoctet1 ((uint8_T)192U)
#define arduinomega2560__remoteipoctet2 ((uint8_T)168U)
#define arduinomega2560__remoteipoctet3 ((uint8_T)0U)
#define arduinomega2560__remoteipoctet4 ((uint8_T)13U)
#define arduinomega2560_wi_wifiUDPIndex ((uint8_T)0U)
#define arduinomega2560_wifi_remoteport (444.0)
#define arduinomega2560_wifiu_localport (333.0)

/* Block states (auto storage) */
DW_arduinomega2560_wifiudpsen_T arduinomega2560_wifiudpsend_DW;

/* Real-time model */
RT_MODEL_arduinomega2560_wifi_T arduinomega2560_wifiudpsend_M_;
RT_MODEL_arduinomega2560_wifi_T *const arduinomega2560_wifiudpsend_M =
  &arduinomega2560_wifiudpsend_M_;

/* Model step function */
void arduinomega2560_wifiudpsend_step(void)
{
  uint8_T dataInp[2];
  uint8_T rtb_FixPtSum1;
  real_T rtb_PulseGenerator;

  /* DiscretePulseGenerator: '<Root>/Pulse Generator' */
  rtb_PulseGenerator = (arduinomega2560_wifiudpsend_DW.clockTickCounter <
                        arduinomega2560_wifiudpsend_P.PulseGenerator_Duty) &&
    (arduinomega2560_wifiudpsend_DW.clockTickCounter >= 0) ?
    arduinomega2560_wifiudpsend_P.PulseGenerator_Amp : 0.0;
  if (arduinomega2560_wifiudpsend_DW.clockTickCounter >=
      arduinomega2560_wifiudpsend_P.PulseGenerator_Period - 1.0) {
    arduinomega2560_wifiudpsend_DW.clockTickCounter = 0;
  } else {
    arduinomega2560_wifiudpsend_DW.clockTickCounter++;
  }

  /* End of DiscretePulseGenerator: '<Root>/Pulse Generator' */

  /* Start for MATLABSystem: '<Root>/WiFi UDP Send' incorporates:
   *  UnitDelay: '<S1>/Output'
   */
  dataInp[0] = arduinomega2560_wifiudpsend_DW.Output_DSTATE;

  /* DataTypeConversion: '<Root>/Data Type Conversion' */
  rtb_PulseGenerator = floor(rtb_PulseGenerator);
  if (rtIsNaN(rtb_PulseGenerator) || rtIsInf(rtb_PulseGenerator)) {
    rtb_PulseGenerator = 0.0;
  } else {
    rtb_PulseGenerator = fmod(rtb_PulseGenerator, 256.0);
  }

  /* Start for MATLABSystem: '<Root>/WiFi UDP Send' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion'
   */
  dataInp[1] = (uint8_T)(rtb_PulseGenerator < 0.0 ? (int32_T)(uint8_T)-(int8_T)
    (uint8_T)-rtb_PulseGenerator : (int32_T)(uint8_T)rtb_PulseGenerator);
  MW_WifiUDPFinalWrite(arduinomega2560_wi_wifiUDPIndex, dataInp,
                       arduinomega2560__remoteipoctet1,
                       arduinomega2560__remoteipoctet2,
                       arduinomega2560__remoteipoctet3,
                       arduinomega2560__remoteipoctet4, (uint16_T)
                       arduinomega2560_wifi_remoteport, 2U);

  /* Sum: '<S2>/FixPt Sum1' incorporates:
   *  Constant: '<S2>/FixPt Constant'
   *  UnitDelay: '<S1>/Output'
   */
  rtb_FixPtSum1 = (uint8_T)((uint32_T)
    arduinomega2560_wifiudpsend_DW.Output_DSTATE +
    arduinomega2560_wifiudpsend_P.FixPtConstant_Value);

  /* Switch: '<S3>/FixPt Switch' */
  if (rtb_FixPtSum1 > arduinomega2560_wifiudpsend_P.CounterLimited1_uplimit) {
    /* Update for UnitDelay: '<S1>/Output' incorporates:
     *  Constant: '<S3>/Constant'
     */
    arduinomega2560_wifiudpsend_DW.Output_DSTATE =
      arduinomega2560_wifiudpsend_P.Constant_Value;
  } else {
    /* Update for UnitDelay: '<S1>/Output' */
    arduinomega2560_wifiudpsend_DW.Output_DSTATE = rtb_FixPtSum1;
  }

  /* End of Switch: '<S3>/FixPt Switch' */
}

/* Model initialize function */
void arduinomega2560_wifiudpsend_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize error status */
  rtmSetErrorStatus(arduinomega2560_wifiudpsend_M, (NULL));

  /* states (dwork) */
  (void) memset((void *)&arduinomega2560_wifiudpsend_DW, 0,
                sizeof(DW_arduinomega2560_wifiudpsen_T));

  /* Start for MATLABSystem: '<Root>/WiFi UDP Send' */
  arduinomega2560_wifiudpsend_DW.obj.isInitialized = 0;
  arduinomega2560_wifiudpsend_DW.obj.isInitialized = 1;
  MW_WifiAndUDPBegin(arduinomega2560_wi_wifiUDPIndex,
                     arduinomega2560__remoteipoctet1,
                     arduinomega2560__remoteipoctet2,
                     arduinomega2560__remoteipoctet3,
                     arduinomega2560__remoteipoctet4, (uint16_T)
                     arduinomega2560_wifi_remoteport, (uint16_T)
                     arduinomega2560_wifiu_localport, 1U);

  /* InitializeConditions for UnitDelay: '<S1>/Output' */
  arduinomega2560_wifiudpsend_DW.Output_DSTATE =
    arduinomega2560_wifiudpsend_P.Output_InitialCondition;

  /* InitializeConditions for DiscretePulseGenerator: '<Root>/Pulse Generator' */
  arduinomega2560_wifiudpsend_DW.clockTickCounter = 0;
}

/* Model terminate function */
void arduinomega2560_wifiudpsend_terminate(void)
{
  /* Start for MATLABSystem: '<Root>/WiFi UDP Send' */
  if (arduinomega2560_wifiudpsend_DW.obj.isInitialized == 1) {
    arduinomega2560_wifiudpsend_DW.obj.isInitialized = 2;
  }

  /* End of Start for MATLABSystem: '<Root>/WiFi UDP Send' */
}
