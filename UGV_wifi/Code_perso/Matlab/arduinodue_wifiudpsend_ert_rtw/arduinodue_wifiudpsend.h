/*
 * File: arduinodue_wifiudpsend.h
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

#ifndef RTW_HEADER_arduinodue_wifiudpsend_h_
#define RTW_HEADER_arduinodue_wifiudpsend_h_
#include <stddef.h>
#include <string.h>
#ifndef arduinodue_wifiudpsend_COMMON_INCLUDES_
# define arduinodue_wifiudpsend_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "arduino_wifiudpsend_lct.h"
#endif                                 /* arduinodue_wifiudpsend_COMMON_INCLUDES_ */

#include "arduinodue_wifiudpsend_types.h"
#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  uint8_T Output_DSTATE;               /* '<S1>/Output' */
} DW_arduinodue_wifiudpsend_T;

/* Parameters (auto storage) */
struct P_arduinodue_wifiudpsend_T_ {
  uint8_T CounterLimited_uplimit;      /* Mask Parameter: CounterLimited_uplimit
                                        * Referenced by: '<S4>/FixPt Switch'
                                        */
  uint32_T SFunction_p2;               /* Computed Parameter: SFunction_p2
                                        * Referenced by: '<S2>/S-Function'
                                        */
  uint32_T SFunction_p7;               /* Computed Parameter: SFunction_p7
                                        * Referenced by: '<S2>/S-Function'
                                        */
  uint8_T Constant_Value;              /* Computed Parameter: Constant_Value
                                        * Referenced by: '<S4>/Constant'
                                        */
  uint8_T Output_InitialCondition;     /* Computed Parameter: Output_InitialCondition
                                        * Referenced by: '<S1>/Output'
                                        */
  uint8_T SFunction_p1;                /* Computed Parameter: SFunction_p1
                                        * Referenced by: '<S2>/S-Function'
                                        */
  uint8_T SFunction_p3;                /* Computed Parameter: SFunction_p3
                                        * Referenced by: '<S2>/S-Function'
                                        */
  uint8_T SFunction_p4;                /* Computed Parameter: SFunction_p4
                                        * Referenced by: '<S2>/S-Function'
                                        */
  uint8_T SFunction_p5;                /* Computed Parameter: SFunction_p5
                                        * Referenced by: '<S2>/S-Function'
                                        */
  uint8_T SFunction_p6;                /* Computed Parameter: SFunction_p6
                                        * Referenced by: '<S2>/S-Function'
                                        */
  uint8_T FixPtConstant_Value;         /* Computed Parameter: FixPtConstant_Value
                                        * Referenced by: '<S3>/FixPt Constant'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_arduinodue_wifiudpsen_T {
  const char_T *errorStatus;
};

/* Block parameters (auto storage) */
extern P_arduinodue_wifiudpsend_T arduinodue_wifiudpsend_P;

/* Block states (auto storage) */
extern DW_arduinodue_wifiudpsend_T arduinodue_wifiudpsend_DW;

/* Model entry point functions */
extern void arduinodue_wifiudpsend_initialize(void);
extern void arduinodue_wifiudpsend_step(void);
extern void arduinodue_wifiudpsend_terminate(void);

/* Real-time Model object */
extern RT_MODEL_arduinodue_wifiudpse_T *const arduinodue_wifiudpsend_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S1>/Data Type Propagation' : Unused code path elimination
 * Block '<S3>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S4>/FixPt Data Type Duplicate1' : Unused code path elimination
 * Block '<S2>/Data Type Conversion' : Eliminate redundant data type conversion
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'arduinodue_wifiudpsend'
 * '<S1>'   : 'arduinodue_wifiudpsend/Counter Limited'
 * '<S2>'   : 'arduinodue_wifiudpsend/WiFi UDP Send'
 * '<S3>'   : 'arduinodue_wifiudpsend/Counter Limited/Increment Real World'
 * '<S4>'   : 'arduinodue_wifiudpsend/Counter Limited/Wrap To Zero'
 */
#endif                                 /* RTW_HEADER_arduinodue_wifiudpsend_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
