/*
 * heli_q8_d2p3_dt.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "heli_q8_d2p3".
 *
 * Model version              : 1.87
 * Simulink Coder version : 8.9 (R2015b) 13-Aug-2015
 * C source code generated on : Tue Nov 12 06:02:07 2019
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
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
  sizeof(t_game_controller),
  sizeof(t_card),
  sizeof(t_task)
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
  "t_game_controller",
  "t_card",
  "t_task"
};

/* data type transitions for block I/O structure */
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&heli_q8_d2p3_B.RateTransitionx), 0, 0, 21 }
  ,

  { (char_T *)(&heli_q8_d2p3_DW.HILInitialize_AIMinimums[0]), 0, 0, 68 },

  { (char_T *)(&heli_q8_d2p3_DW.GameController_Controller), 14, 0, 1 },

  { (char_T *)(&heli_q8_d2p3_DW.HILInitialize_Card), 15, 0, 1 },

  { (char_T *)(&heli_q8_d2p3_DW.HILReadEncoderTimebase_Task), 16, 0, 1 },

  { (char_T *)(&heli_q8_d2p3_DW.ToFile_PWORK.FilePtr), 11, 0, 13 },

  { (char_T *)(&heli_q8_d2p3_DW.HILInitialize_ClockModes[0]), 6, 0, 46 },

  { (char_T *)(&heli_q8_d2p3_DW.HILInitialize_POSortedChans[0]), 7, 0, 8 },

  { (char_T *)(&heli_q8_d2p3_DW.ToFile_IWORK.Count), 10, 0, 1 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  9U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&heli_q8_d2p3_P.Joystick_gain_x), 0, 0, 21 },

  { (char_T *)(&heli_q8_d2p3_P.HILReadEncoderTimebase_clock), 6, 0, 10 },

  { (char_T *)(&heli_q8_d2p3_P.HILInitialize_analog_input_chan[0]), 7, 0, 39 },

  { (char_T *)(&heli_q8_d2p3_P.HILInitialize_active), 8, 0, 35 },

  { (char_T *)(&heli_q8_d2p3_P.RateTransitionx_X0), 0, 0, 36 },

  { (char_T *)(&heli_q8_d2p3_P.GameController_BufferSize), 5, 0, 1 },

  { (char_T *)(&heli_q8_d2p3_P.GameController_ControllerNumber), 3, 0, 1 },

  { (char_T *)(&heli_q8_d2p3_P.HILReadEncoderTimebase_Active), 8, 0, 4 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  8U,
  rtPTransitions
};

/* [EOF] heli_q8_d2p3_dt.h */
