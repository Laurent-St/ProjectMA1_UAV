/*
 * arduinomega2560_wifiudpreceive.h
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

#ifndef RTW_HEADER_arduinomega2560_wifiudpreceive_h_
#define RTW_HEADER_arduinomega2560_wifiudpreceive_h_
#include <float.h>
#include <string.h>
#include <stddef.h>
#ifndef arduinomega2560_wifiudpreceive_COMMON_INCLUDES_
# define arduinomega2560_wifiudpreceive_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "dt_info.h"
#include "ext_work.h"
#include "MW_WiFiUDP.h"
#endif                                 /* arduinomega2560_wifiudpreceive_COMMON_INCLUDES_ */

#include "arduinomega2560_wifiudpreceive_types.h"

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

#define arduinomega2560_wifiudpreceive_M (arduinomega2560_wifiudprecei_M)

/* Block signals (auto storage) */
typedef struct {
  int16_T WiFiUDPReceive_o1[4];        /* '<Root>/WiFi UDP Receive' */
  uint16_T WiFiUDPReceive_o2;          /* '<Root>/WiFi UDP Receive' */
} B_arduinomega2560_wifiudprece_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_inter_T obj; /* '<Root>/WiFi UDP Receive' */
} DW_arduinomega2560_wifiudprec_T;

/* Real-time Model Data Structure */
struct tag_RTM_arduinomega2560_wifiu_T {
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
extern B_arduinomega2560_wifiudprece_T arduinomega2560_wifiudpreceiv_B;

/* Block states (auto storage) */
extern DW_arduinomega2560_wifiudprec_T arduinomega2560_wifiudprecei_DW;

/* Model entry point functions */
extern void arduinomega2560_wifiudpreceive_initialize(void);
extern void arduinomega2560_wifiudpreceive_step(void);
extern void arduinomega2560_wifiudpreceive_terminate(void);

/* Real-time Model object */
extern RT_MODEL_arduinomega2560_wifi_T *const arduinomega2560_wifiudprecei_M;

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
 * '<Root>' : 'arduinomega2560_wifiudpreceive'
 */
#endif                                 /* RTW_HEADER_arduinomega2560_wifiudpreceive_h_ */
