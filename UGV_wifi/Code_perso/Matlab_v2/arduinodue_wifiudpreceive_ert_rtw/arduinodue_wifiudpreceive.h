/*
 * arduinodue_wifiudpreceive.h
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

#ifndef RTW_HEADER_arduinodue_wifiudpreceive_h_
#define RTW_HEADER_arduinodue_wifiudpreceive_h_
#include <float.h>
#include <string.h>
#include <stddef.h>
#ifndef arduinodue_wifiudpreceive_COMMON_INCLUDES_
# define arduinodue_wifiudpreceive_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "dt_info.h"
#include "ext_work.h"
#include "MW_WiFiUDP.h"
#endif                                 /* arduinodue_wifiudpreceive_COMMON_INCLUDES_ */

#include "arduinodue_wifiudpreceive_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWExtModeInfo
# define rtmGetRTWExtModeInfo(rtm)     ((rtm)->extModeInfo)
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

/* Block signals (auto storage) */
typedef struct {
  int16_T WiFiUDPReceive_o1[4];        /* '<Root>/WiFi UDP Receive' */
  uint16_T WiFiUDPReceive_o2;          /* '<Root>/WiFi UDP Receive' */
} B_arduinodue_wifiudpreceive_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<Root>/Scope' */

  codertarget_arduinobase_inter_T obj; /* '<Root>/WiFi UDP Receive' */
} DW_arduinodue_wifiudpreceive_T;

/* Real-time Model Data Structure */
struct tag_RTM_arduinodue_wifiudprec_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T taskTime0;
    uint32_T clockTick0;
    time_T stepSize0;
    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block signals (auto storage) */
extern B_arduinodue_wifiudpreceive_T arduinodue_wifiudpreceive_B;

/* Block states (auto storage) */
extern DW_arduinodue_wifiudpreceive_T arduinodue_wifiudpreceive_DW;

/* Model entry point functions */
extern void arduinodue_wifiudpreceive_initialize(void);
extern void arduinodue_wifiudpreceive_step(void);
extern void arduinodue_wifiudpreceive_terminate(void);

/* Real-time Model object */
extern RT_MODEL_arduinodue_wifiudpre_T *const arduinodue_wifiudpreceive_M;

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
 * '<Root>' : 'arduinodue_wifiudpreceive'
 */
#endif                                 /* RTW_HEADER_arduinodue_wifiudpreceive_h_ */
