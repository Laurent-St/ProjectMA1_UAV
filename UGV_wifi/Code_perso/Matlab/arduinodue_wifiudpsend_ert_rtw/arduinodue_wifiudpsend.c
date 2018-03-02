/*
 * File: arduinodue_wifiudpsend.c
 *
 * Code generated for Simulink model 'arduinodue_wifiudpsend'.
 *
 * Model version                  : 1.18
 * Simulink Coder version         : 8.10 (R2016a) 10-Feb-2016
 * C/C++ source code generated on : Thu Nov 23 22:10:28 2017
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "arduinodue_wifiudpsend.h"
#include "arduinodue_wifiudpsend_private.h"

/* Block states (auto storage) */
DW_arduinodue_wifiudpsend_T arduinodue_wifiudpsend_DW;

/* Real-time model */
RT_MODEL_arduinodue_wifiudpse_T arduinodue_wifiudpsend_M_;
RT_MODEL_arduinodue_wifiudpse_T *const arduinodue_wifiudpsend_M =
  &arduinodue_wifiudpsend_M_;

/* Model step function */
void arduinodue_wifiudpsend_step(void)
{
  uint8_T rtb_FixPtSum1;

  /* S-Function (arduinowifiudpsend_sfcn): '<S2>/S-Function' incorporates:
   *  UnitDelay: '<S1>/Output'
   */
  MW_WifiUDPFinalWrite(arduinodue_wifiudpsend_P.SFunction_p1,
                       arduinodue_wifiudpsend_DW.Output_DSTATE,
                       arduinodue_wifiudpsend_P.SFunction_p3,
                       arduinodue_wifiudpsend_P.SFunction_p4,
                       arduinodue_wifiudpsend_P.SFunction_p5,
                       arduinodue_wifiudpsend_P.SFunction_p6,
                       arduinodue_wifiudpsend_P.SFunction_p7);

  /* Sum: '<S3>/FixPt Sum1' incorporates:
   *  Constant: '<S3>/FixPt Constant'
   *  UnitDelay: '<S1>/Output'
   */
  rtb_FixPtSum1 = (uint8_T)((uint32_T)arduinodue_wifiudpsend_DW.Output_DSTATE +
    arduinodue_wifiudpsend_P.FixPtConstant_Value);

  /* Switch: '<S4>/FixPt Switch' */
  if (rtb_FixPtSum1 > arduinodue_wifiudpsend_P.CounterLimited_uplimit) {
    /* Update for UnitDelay: '<S1>/Output' incorporates:
     *  Constant: '<S4>/Constant'
     */
    arduinodue_wifiudpsend_DW.Output_DSTATE =
      arduinodue_wifiudpsend_P.Constant_Value;
  } else {
    /* Update for UnitDelay: '<S1>/Output' */
    arduinodue_wifiudpsend_DW.Output_DSTATE = rtb_FixPtSum1;
  }

  /* End of Switch: '<S4>/FixPt Switch' */
}

/* Model initialize function */
void arduinodue_wifiudpsend_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(arduinodue_wifiudpsend_M, (NULL));

  /* states (dwork) */
  (void) memset((void *)&arduinodue_wifiudpsend_DW, 0,
                sizeof(DW_arduinodue_wifiudpsend_T));

  /* Start for S-Function (arduinowifiudpsend_sfcn): '<S2>/S-Function' */
  MW_WifiAndUDPBegin(arduinodue_wifiudpsend_P.SFunction_p1,
                     arduinodue_wifiudpsend_P.SFunction_p2);

  /* InitializeConditions for UnitDelay: '<S1>/Output' */
  arduinodue_wifiudpsend_DW.Output_DSTATE =
    arduinodue_wifiudpsend_P.Output_InitialCondition;
}

/* Model terminate function */
void arduinodue_wifiudpsend_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
