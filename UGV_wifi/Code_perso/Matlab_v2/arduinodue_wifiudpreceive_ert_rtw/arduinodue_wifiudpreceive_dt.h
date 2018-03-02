/*
 * arduinodue_wifiudpreceive_dt.h
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

#include "ext_types.h"

/* data type size table */
static uint_T rtDataTypeSizes[] = {
  sizeof(real_T),
  sizeof(real32_T),
  sizeof(int8_T),
  sizeof(uint8_T),
  sizeof(int16_T),
  sizeof(uint16_T),
  sizeof(int32_T),
  sizeof(uint32_T),
  sizeof(boolean_T),
  sizeof(fcn_call_T),
  sizeof(int_T),
  sizeof(pointer_T),
  sizeof(action_T),
  2*sizeof(uint32_T),
  sizeof(codertarget_arduinobase_inter_T)
};

/* data type name table */
static const char_T * rtDataTypeNames[] = {
  "real_T",
  "real32_T",
  "int8_T",
  "uint8_T",
  "int16_T",
  "uint16_T",
  "int32_T",
  "uint32_T",
  "boolean_T",
  "fcn_call_T",
  "int_T",
  "pointer_T",
  "action_T",
  "timer_uint32_pair_T",
  "codertarget_arduinobase_inter_T"
};

/* data type transitions for block I/O structure */
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&arduinodue_wifiudpreceive_B.WiFiUDPReceive_o1[0]), 4, 0, 4 },

  { (char_T *)(&arduinodue_wifiudpreceive_B.WiFiUDPReceive_o2), 5, 0, 1 }
  ,

  { (char_T *)(&arduinodue_wifiudpreceive_DW.Scope_PWORK.LoggedData), 11, 0, 1 },

  { (char_T *)(&arduinodue_wifiudpreceive_DW.obj), 14, 0, 1 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  4U,
  rtBTransitions
};

/* [EOF] arduinodue_wifiudpreceive_dt.h */
