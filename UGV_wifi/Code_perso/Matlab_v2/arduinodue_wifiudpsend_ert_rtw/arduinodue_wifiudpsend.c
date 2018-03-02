/*
 * arduinodue_wifiudpsend.c
 *
 * Code generation for model "arduinodue_wifiudpsend".
 *
 * Model version              : 1.27
 * Simulink Coder version : 8.13 (R2017b) 24-Jul-2017
 * C source code generated on : Sat Dec 16 13:15:40 2017
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "arduinodue_wifiudpsend.h"
#include "arduinodue_wifiudpsend_private.h"
#define arduinodue_wifiu_remoteipoctet1 ((uint8_T)192U)
#define arduinodue_wifiu_remoteipoctet2 ((uint8_T)168U)
#define arduinodue_wifiu_remoteipoctet3 ((uint8_T)0U)
#define arduinodue_wifiu_remoteipoctet4 ((uint8_T)13U)
#define arduinodue_wifiudp_wifiUDPIndex ((uint8_T)0U)
#define arduinodue_wifiudpse_remoteport (444.0)
#define arduinodue_wifiudpsen_localport (333.0)

/* Block states (auto storage) */
DW_arduinodue_wifiudpsend_T arduinodue_wifiudpsend_DW;

/* Real-time model */
RT_MODEL_arduinodue_wifiudpse_T arduinodue_wifiudpsend_M_;
RT_MODEL_arduinodue_wifiudpse_T *const arduinodue_wifiudpsend_M =
  &arduinodue_wifiudpsend_M_;

/* Model step function */
void arduinodue_wifiudpsend_step(void)
{
  uint8_T dataInp[2];
  uint8_T rtb_FixPtSum1;
  real_T rtb_PulseGenerator;

  /* DiscretePulseGenerator: '<Root>/Pulse Generator' */
  rtb_PulseGenerator = (arduinodue_wifiudpsend_DW.clockTickCounter <
                        arduinodue_wifiudpsend_P.PulseGenerator_Duty) &&
    (arduinodue_wifiudpsend_DW.clockTickCounter >= 0) ?
    arduinodue_wifiudpsend_P.PulseGenerator_Amp : 0.0;
  if (arduinodue_wifiudpsend_DW.clockTickCounter >=
      arduinodue_wifiudpsend_P.PulseGenerator_Period - 1.0) {
    arduinodue_wifiudpsend_DW.clockTickCounter = 0;
  } else {
    arduinodue_wifiudpsend_DW.clockTickCounter++;
  }

  /* End of DiscretePulseGenerator: '<Root>/Pulse Generator' */

  /* Start for MATLABSystem: '<Root>/WiFi UDP Send' incorporates:
   *  UnitDelay: '<S1>/Output'
   */
  dataInp[0] = arduinodue_wifiudpsend_DW.Output_DSTATE;

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
  MW_WifiUDPFinalWrite(arduinodue_wifiudp_wifiUDPIndex, dataInp,
                       arduinodue_wifiu_remoteipoctet1,
                       arduinodue_wifiu_remoteipoctet2,
                       arduinodue_wifiu_remoteipoctet3,
                       arduinodue_wifiu_remoteipoctet4, (uint16_T)
                       arduinodue_wifiudpse_remoteport, 2U);

  /* Sum: '<S2>/FixPt Sum1' incorporates:
   *  Constant: '<S2>/FixPt Constant'
   *  UnitDelay: '<S1>/Output'
   */
  rtb_FixPtSum1 = (uint8_T)((uint32_T)arduinodue_wifiudpsend_DW.Output_DSTATE +
    arduinodue_wifiudpsend_P.FixPtConstant_Value);

  /* Switch: '<S3>/FixPt Switch' */
  if (rtb_FixPtSum1 > arduinodue_wifiudpsend_P.CounterLimited1_uplimit) {
    /* Update for UnitDelay: '<S1>/Output' incorporates:
     *  Constant: '<S3>/Constant'
     */
    arduinodue_wifiudpsend_DW.Output_DSTATE =
      arduinodue_wifiudpsend_P.Constant_Value;
  } else {
    /* Update for UnitDelay: '<S1>/Output' */
    arduinodue_wifiudpsend_DW.Output_DSTATE = rtb_FixPtSum1;
  }

  /* End of Switch: '<S3>/FixPt Switch' */
}

/* Model initialize function */
void arduinodue_wifiudpsend_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize error status */
  rtmSetErrorStatus(arduinodue_wifiudpsend_M, (NULL));

  /* states (dwork) */
  (void) memset((void *)&arduinodue_wifiudpsend_DW, 0,
                sizeof(DW_arduinodue_wifiudpsend_T));

  /* Start for MATLABSystem: '<Root>/WiFi UDP Send' */
  arduinodue_wifiudpsend_DW.obj.isInitialized = 0;
  arduinodue_wifiudpsend_DW.obj.isInitialized = 1;
  MW_WifiAndUDPBegin(arduinodue_wifiudp_wifiUDPIndex,
                     arduinodue_wifiu_remoteipoctet1,
                     arduinodue_wifiu_remoteipoctet2,
                     arduinodue_wifiu_remoteipoctet3,
                     arduinodue_wifiu_remoteipoctet4, (uint16_T)
                     arduinodue_wifiudpse_remoteport, (uint16_T)
                     arduinodue_wifiudpsen_localport, 1U);

  /* InitializeConditions for UnitDelay: '<S1>/Output' */
  arduinodue_wifiudpsend_DW.Output_DSTATE =
    arduinodue_wifiudpsend_P.Output_InitialCondition;

  /* InitializeConditions for DiscretePulseGenerator: '<Root>/Pulse Generator' */
  arduinodue_wifiudpsend_DW.clockTickCounter = 0;
}

/* Model terminate function */
void arduinodue_wifiudpsend_terminate(void)
{
  /* Start for MATLABSystem: '<Root>/WiFi UDP Send' */
  if (arduinodue_wifiudpsend_DW.obj.isInitialized == 1) {
    arduinodue_wifiudpsend_DW.obj.isInitialized = 2;
  }

  /* End of Start for MATLABSystem: '<Root>/WiFi UDP Send' */
}
