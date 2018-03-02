/*
 * arduinodue_wifitcpreceive.h
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

#ifndef RTW_HEADER_arduinodue_wifitcpreceive_h_
#define RTW_HEADER_arduinodue_wifitcpreceive_h_
#include <stddef.h>
#include <string.h>
#ifndef arduinodue_wifitcpreceive_COMMON_INCLUDES_
# define arduinodue_wifitcpreceive_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "MW_SerialWrite.h"
#include "MW_WiFiTCP.h"
#include "MW_digitalio.h"
#endif                                 /* arduinodue_wifitcpreceive_COMMON_INCLUDES_ */

#include "arduinodue_wifitcpreceive_types.h"
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
  codertarget_arduinobase_int_b_T obj; /* '<Root>/Serial Transmit' */
  codertarget_arduinobase_inter_T obj_b;/* '<Root>/WiFi TCP//IP Receive' */
  codertarget_arduinobase_block_T obj_j;/* '<S1>/Digital Output' */
} DW_arduinodue_wifitcpreceive_T;

/* Real-time Model Data Structure */
struct tag_RTM_arduinodue_wifitcprec_T {
  const char_T *errorStatus;
};

/* Block states (auto storage) */
extern DW_arduinodue_wifitcpreceive_T arduinodue_wifitcpreceive_DW;

/* Model entry point functions */
extern void arduinodue_wifitcpreceive_initialize(void);
extern void arduinodue_wifitcpreceive_step(void);
extern void arduinodue_wifitcpreceive_terminate(void);

/* Real-time Model object */
extern RT_MODEL_arduinodue_wifitcpre_T *const arduinodue_wifitcpreceive_M;

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
 * '<Root>' : 'arduinodue_wifitcpreceive'
 * '<S1>'   : 'arduinodue_wifitcpreceive/Digital Output'
 */
#endif                                 /* RTW_HEADER_arduinodue_wifitcpreceive_h_ */
