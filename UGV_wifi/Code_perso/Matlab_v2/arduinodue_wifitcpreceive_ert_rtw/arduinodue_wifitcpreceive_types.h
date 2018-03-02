/*
 * arduinodue_wifitcpreceive_types.h
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

#ifndef RTW_HEADER_arduinodue_wifitcpreceive_types_h_
#define RTW_HEADER_arduinodue_wifitcpreceive_types_h_
#include "rtwtypes.h"
#ifndef typedef_codertarget_arduinobase_inter_T
#define typedef_codertarget_arduinobase_inter_T

typedef struct {
  int32_T isInitialized;
  boolean_T TunablePropsChanged;
  real_T isServer_;
} codertarget_arduinobase_inter_T;

#endif                                 /*typedef_codertarget_arduinobase_inter_T*/

#ifndef typedef_codertarget_arduinobase_block_T
#define typedef_codertarget_arduinobase_block_T

typedef struct {
  int32_T isInitialized;
} codertarget_arduinobase_block_T;

#endif                                 /*typedef_codertarget_arduinobase_block_T*/

#ifndef typedef_cell_wrap_arduinodue_wifitcpr_T
#define typedef_cell_wrap_arduinodue_wifitcpr_T

typedef struct {
  uint32_T f1[8];
} cell_wrap_arduinodue_wifitcpr_T;

#endif                                 /*typedef_cell_wrap_arduinodue_wifitcpr_T*/

#ifndef typedef_codertarget_arduinobase_int_b_T
#define typedef_codertarget_arduinobase_int_b_T

typedef struct {
  int32_T isInitialized;
  cell_wrap_arduinodue_wifitcpr_T inputVarSize;
  real_T port;
  real_T dataSizeInBytes;
  real_T dataType;
  real_T sendModeEnum;
  real_T sendFormatEnum;
} codertarget_arduinobase_int_b_T;

#endif                                 /*typedef_codertarget_arduinobase_int_b_T*/

/* Forward declaration for rtModel */
typedef struct tag_RTM_arduinodue_wifitcprec_T RT_MODEL_arduinodue_wifitcpre_T;

#endif                                 /* RTW_HEADER_arduinodue_wifitcpreceive_types_h_ */
