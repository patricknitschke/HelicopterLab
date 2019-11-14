/*
 * heli_q8_d5p3_old.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "heli_q8_d5p3_old".
 *
 * Model version              : 1.113
 * Simulink Coder version : 8.9 (R2015b) 13-Aug-2015
 * C source code generated on : Thu Nov 14 02:51:08 2019
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "heli_q8_d5p3_old.h"
#include "heli_q8_d5p3_old_private.h"
#include "heli_q8_d5p3_old_dt.h"

t_stream heli_q8_d5p3_old_rtZt_stream = NULL;

/* Block signals (auto storage) */
B_heli_q8_d5p3_old_T heli_q8_d5p3_old_B;

/* Continuous states */
X_heli_q8_d5p3_old_T heli_q8_d5p3_old_X;

/* Block states (auto storage) */
DW_heli_q8_d5p3_old_T heli_q8_d5p3_old_DW;

/* Real-time model */
RT_MODEL_heli_q8_d5p3_old_T heli_q8_d5p3_old_M_;
RT_MODEL_heli_q8_d5p3_old_T *const heli_q8_d5p3_old_M = &heli_q8_d5p3_old_M_;
static void rate_monotonic_scheduler(void);

/*
 * Writes out MAT-file header.  Returns success or failure.
 * Returns:
 *      0 - success
 *      1 - failure
 */
int_T rt_WriteMat4FileHeader(FILE *fp, int32_T m, int32_T n, const char *name)
{
  typedef enum { ELITTLE_ENDIAN, EBIG_ENDIAN } ByteOrder;

  int16_T one = 1;
  ByteOrder byteOrder = (*((int8_T *)&one)==1) ? ELITTLE_ENDIAN : EBIG_ENDIAN;
  int32_T type = (byteOrder == ELITTLE_ENDIAN) ? 0: 1000;
  int32_T imagf = 0;
  int32_T name_len = (int32_T)strlen(name) + 1;
  if ((fwrite(&type, sizeof(int32_T), 1, fp) == 0) ||
      (fwrite(&m, sizeof(int32_T), 1, fp) == 0) ||
      (fwrite(&n, sizeof(int32_T), 1, fp) == 0) ||
      (fwrite(&imagf, sizeof(int32_T), 1, fp) == 0) ||
      (fwrite(&name_len, sizeof(int32_T), 1, fp) == 0) ||
      (fwrite(name, sizeof(char), name_len, fp) == 0)) {
    return(1);
  } else {
    return(0);
  }
}                                      /* end rt_WriteMat4FileHeader */

time_T rt_SimUpdateDiscreteEvents(
  int_T rtmNumSampTimes, void *rtmTimingData, int_T *rtmSampleHitPtr, int_T
  *rtmPerTaskSampleHits )
{
  rtmSampleHitPtr[1] = rtmStepTask(heli_q8_d5p3_old_M, 1);
  rtmSampleHitPtr[2] = rtmStepTask(heli_q8_d5p3_old_M, 2);
  UNUSED_PARAMETER(rtmNumSampTimes);
  UNUSED_PARAMETER(rtmTimingData);
  UNUSED_PARAMETER(rtmPerTaskSampleHits);
  return(-1);
}

/*
 *   This function updates active task flag for each subrate
 * and rate transition flags for tasks that exchange data.
 * The function assumes rate-monotonic multitasking scheduler.
 * The function must be called at model base rate so that
 * the generated code self-manages all its subrates and rate
 * transition flags.
 */
static void rate_monotonic_scheduler(void)
{
  /* To ensure a deterministic data transfer between two rates,
   * data is transferred at the priority of a fast task and the frequency
   * of the slow task.  The following flags indicate when the data transfer
   * happens.  That is, a rate interaction flag is set true when both rates
   * will run, and false otherwise.
   */

  /* tid 1 shares data with slower tid rate: 2 */
  if (heli_q8_d5p3_old_M->Timing.TaskCounters.TID[1] == 0) {
    heli_q8_d5p3_old_M->Timing.RateInteraction.TID1_2 =
      (heli_q8_d5p3_old_M->Timing.TaskCounters.TID[2] == 0);

    /* update PerTaskSampleHits matrix for non-inline sfcn */
    heli_q8_d5p3_old_M->Timing.perTaskSampleHits[5] =
      heli_q8_d5p3_old_M->Timing.RateInteraction.TID1_2;
  }

  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (heli_q8_d5p3_old_M->Timing.TaskCounters.TID[2])++;
  if ((heli_q8_d5p3_old_M->Timing.TaskCounters.TID[2]) > 4) {/* Sample time: [0.01s, 0.0s] */
    heli_q8_d5p3_old_M->Timing.TaskCounters.TID[2] = 0;
  }
}

/*
 * This function updates continuous states using the ODE1 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE1_IntgData *id = (ODE1_IntgData *)rtsiGetSolverData(si);
  real_T *f0 = id->f[0];
  int_T i;
  int_T nXc = 5;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);
  rtsiSetdX(si, f0);
  heli_q8_d5p3_old_derivatives();
  rtsiSetT(si, tnew);
  for (i = 0; i < nXc; ++i) {
    x[i] += h * f0[i];
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model output function for TID0 */
void heli_q8_d5p3_old_output0(void)    /* Sample time: [0.0s, 0.0s] */
{
  /* local block i/o variables */
  real_T rtb_HILReadEncoderTimebase_o1;
  real_T rtb_HILReadEncoderTimebase_o2;
  real_T rtb_HILReadEncoderTimebase_o3;
  real_T rtb_TmpSignalConversionAtnoiset[5];
  t_stream_ptr rtb_StreamCall1_o1;
  t_stream_ptr rtb_StreamFormattedWrite_o1;
  real32_T rtb_StreamRead1_o2[10];
  int32_T rtb_StreamFormattedWrite_o2;
  int32_T rtb_StreamCall1_o3;
  int32_T rtb_StreamRead1_o5;
  boolean_T rtb_StreamRead1_o3;
  real_T rtb_Switch[10];
  real_T rtb_Sum3[2];
  int32_T i;
  real_T tmp[5];
  real_T tmp_0[6];
  real_T tmp_1[6];
  real_T tmp_2[36];
  int32_T i_0;
  int32_T i_1;
  real_T tmp_3[9];
  real_T tmp_4[3];
  real_T u0;
  if (rtmIsMajorTimeStep(heli_q8_d5p3_old_M)) {
    /* set solver stop time */
    if (!(heli_q8_d5p3_old_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&heli_q8_d5p3_old_M->solverInfo,
                            ((heli_q8_d5p3_old_M->Timing.clockTickH0 + 1) *
        heli_q8_d5p3_old_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&heli_q8_d5p3_old_M->solverInfo,
                            ((heli_q8_d5p3_old_M->Timing.clockTick0 + 1) *
        heli_q8_d5p3_old_M->Timing.stepSize0 +
        heli_q8_d5p3_old_M->Timing.clockTickH0 *
        heli_q8_d5p3_old_M->Timing.stepSize0 * 4294967296.0));
    }

    {                                  /* Sample time: [0.0s, 0.0s] */
      rate_monotonic_scheduler();
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(heli_q8_d5p3_old_M)) {
    heli_q8_d5p3_old_M->Timing.t[0] = rtsiGetT(&heli_q8_d5p3_old_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(heli_q8_d5p3_old_M)) {
    /* S-Function (hil_read_encoder_timebase_block): '<S2>/HIL Read Encoder Timebase' */

    /* S-Function Block: heli_q8_d5p3_old/Heli 3D/HIL Read Encoder Timebase (hil_read_encoder_timebase_block) */
    {
      t_error result;
      result = hil_task_read_encoder
        (heli_q8_d5p3_old_DW.HILReadEncoderTimebase_Task, 1,
         &heli_q8_d5p3_old_DW.HILReadEncoderTimebase_Buffer[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_d5p3_old_M, _rt_error_message);
      } else {
        rtb_HILReadEncoderTimebase_o1 =
          heli_q8_d5p3_old_DW.HILReadEncoderTimebase_Buffer[0];
        rtb_HILReadEncoderTimebase_o2 =
          heli_q8_d5p3_old_DW.HILReadEncoderTimebase_Buffer[1];
        rtb_HILReadEncoderTimebase_o3 =
          heli_q8_d5p3_old_DW.HILReadEncoderTimebase_Buffer[2];
      }
    }

    /* UnitDelay: '<S5>/Unit Delay1' */
    for (i = 0; i < 6; i++) {
      heli_q8_d5p3_old_B.UnitDelay1[i] = heli_q8_d5p3_old_DW.UnitDelay1_DSTATE[i];
    }

    /* End of UnitDelay: '<S5>/Unit Delay1' */

    /* Constant: '<S5>/A_d' */
    memcpy(&heli_q8_d5p3_old_B.A_d[0], &heli_q8_d5p3_old_P.A_d[0], 36U * sizeof
           (real_T));

    /* Constant: '<S5>/B_d' */
    memcpy(&heli_q8_d5p3_old_B.B_d[0], &heli_q8_d5p3_old_P.B_d[0], 12U * sizeof
           (real_T));

    /* Constant: '<S5>/Q_d' */
    memcpy(&heli_q8_d5p3_old_B.Q_d[0], &heli_q8_d5p3_old_P.Q_d[0], 36U * sizeof
           (real_T));

    /* RateTransition: '<S4>/Rate Transition: x' */
    if (heli_q8_d5p3_old_M->Timing.RateInteraction.TID1_2) {
      heli_q8_d5p3_old_B.RateTransitionx =
        heli_q8_d5p3_old_DW.RateTransitionx_Buffer0;
    }

    /* End of RateTransition: '<S4>/Rate Transition: x' */

    /* DeadZone: '<S4>/Dead Zone: x' */
    if (heli_q8_d5p3_old_B.RateTransitionx > heli_q8_d5p3_old_P.DeadZonex_End) {
      u0 = heli_q8_d5p3_old_B.RateTransitionx - heli_q8_d5p3_old_P.DeadZonex_End;
    } else if (heli_q8_d5p3_old_B.RateTransitionx >=
               heli_q8_d5p3_old_P.DeadZonex_Start) {
      u0 = 0.0;
    } else {
      u0 = heli_q8_d5p3_old_B.RateTransitionx -
        heli_q8_d5p3_old_P.DeadZonex_Start;
    }

    /* End of DeadZone: '<S4>/Dead Zone: x' */

    /* Gain: '<S4>/Joystick_gain_x' incorporates:
     *  Gain: '<S4>/Gain: x'
     */
    heli_q8_d5p3_old_B.Joystick_gain_x = heli_q8_d5p3_old_P.Gainx_Gain * u0 *
      heli_q8_d5p3_old_P.Joystick_gain_x;

    /* RateTransition: '<S4>/Rate Transition: y' */
    if (heli_q8_d5p3_old_M->Timing.RateInteraction.TID1_2) {
      heli_q8_d5p3_old_B.RateTransitiony =
        heli_q8_d5p3_old_DW.RateTransitiony_Buffer0;
    }

    /* End of RateTransition: '<S4>/Rate Transition: y' */

    /* DeadZone: '<S4>/Dead Zone: y' */
    if (heli_q8_d5p3_old_B.RateTransitiony > heli_q8_d5p3_old_P.DeadZoney_End) {
      u0 = heli_q8_d5p3_old_B.RateTransitiony - heli_q8_d5p3_old_P.DeadZoney_End;
    } else if (heli_q8_d5p3_old_B.RateTransitiony >=
               heli_q8_d5p3_old_P.DeadZoney_Start) {
      u0 = 0.0;
    } else {
      u0 = heli_q8_d5p3_old_B.RateTransitiony -
        heli_q8_d5p3_old_P.DeadZoney_Start;
    }

    /* End of DeadZone: '<S4>/Dead Zone: y' */

    /* Gain: '<S4>/Joystick_gain_y' incorporates:
     *  Gain: '<S4>/Gain: y'
     */
    heli_q8_d5p3_old_B.Joystick_gain_y = heli_q8_d5p3_old_P.Gainy_Gain * u0 *
      heli_q8_d5p3_old_P.Joystick_gain_y;

    /* Gain: '<S12>/F*r' incorporates:
     *  SignalConversion: '<S12>/TmpSignal ConversionAtF*rInport1'
     */
    heli_q8_d5p3_old_B.Fr[0] = 0.0;
    heli_q8_d5p3_old_B.Fr[0] += heli_q8_d5p3_old_P.F[0] *
      heli_q8_d5p3_old_B.Joystick_gain_x;
    heli_q8_d5p3_old_B.Fr[0] += heli_q8_d5p3_old_P.F[2] *
      heli_q8_d5p3_old_B.Joystick_gain_y;
    heli_q8_d5p3_old_B.Fr[1] = 0.0;
    heli_q8_d5p3_old_B.Fr[1] += heli_q8_d5p3_old_P.F[1] *
      heli_q8_d5p3_old_B.Joystick_gain_x;
    heli_q8_d5p3_old_B.Fr[1] += heli_q8_d5p3_old_P.F[3] *
      heli_q8_d5p3_old_B.Joystick_gain_y;

    /* Sum: '<S2>/Sum1' incorporates:
     *  Constant: '<S2>/Constant2'
     *  Gain: '<S2>/Pitch: Count to rad'
     */
    heli_q8_d5p3_old_B.Sum1 = heli_q8_d5p3_old_P.PitchCounttorad_Gain *
      rtb_HILReadEncoderTimebase_o2 + heli_q8_d5p3_old_P.Constant2_Value_b;

    /* Sum: '<S2>/Sum2' incorporates:
     *  Constant: '<S2>/Constant1'
     *  Gain: '<S2>/Elevation: Count to rad'
     */
    heli_q8_d5p3_old_B.Sum2 = heli_q8_d5p3_old_P.ElevationCounttorad_Gain *
      rtb_HILReadEncoderTimebase_o3 + heli_q8_d5p3_old_P.Constant1_Value;
  }

  /* TransferFcn: '<S2>/Pitch: Transfer Fcn' */
  heli_q8_d5p3_old_B.PitchTransferFcn = 0.0;
  heli_q8_d5p3_old_B.PitchTransferFcn += heli_q8_d5p3_old_P.PitchTransferFcn_C *
    heli_q8_d5p3_old_X.PitchTransferFcn_CSTATE;
  heli_q8_d5p3_old_B.PitchTransferFcn += heli_q8_d5p3_old_P.PitchTransferFcn_D *
    heli_q8_d5p3_old_B.Sum1;

  /* TransferFcn: '<S2>/Elevation: Transfer Fcn' */
  heli_q8_d5p3_old_B.ElevationTransferFcn = 0.0;
  heli_q8_d5p3_old_B.ElevationTransferFcn +=
    heli_q8_d5p3_old_P.ElevationTransferFcn_C *
    heli_q8_d5p3_old_X.ElevationTransferFcn_CSTATE;
  heli_q8_d5p3_old_B.ElevationTransferFcn +=
    heli_q8_d5p3_old_P.ElevationTransferFcn_D * heli_q8_d5p3_old_B.Sum2;

  /* SignalConversion: '<S12>/TmpSignal ConversionAtK*xInport1' incorporates:
   *  Integrator: '<S6>/Integrate -> [gamma,zeta]'
   */
  tmp[0] = heli_q8_d5p3_old_B.Sum1;
  tmp[1] = heli_q8_d5p3_old_B.PitchTransferFcn;
  tmp[2] = heli_q8_d5p3_old_B.ElevationTransferFcn;
  tmp[3] = heli_q8_d5p3_old_X.Integrategammazeta_CSTATE[0];
  tmp[4] = heli_q8_d5p3_old_X.Integrategammazeta_CSTATE[1];

  /* Sum: '<S12>/Sum3' incorporates:
   *  Gain: '<S12>/K*x'
   *  SignalConversion: '<S12>/TmpSignal ConversionAtK*xInport1'
   */
  for (i = 0; i < 2; i++) {
    u0 = 0.0;
    for (i_0 = 0; i_0 < 5; i_0++) {
      u0 += heli_q8_d5p3_old_P.K[(i_0 << 1) + i] * tmp[i_0];
    }

    rtb_Sum3[i] = heli_q8_d5p3_old_B.Fr[i] - u0;
  }

  /* End of Sum: '<S12>/Sum3' */
  if (rtmIsMajorTimeStep(heli_q8_d5p3_old_M)) {
    /* UnitDelay: '<S5>/Unit Delay2' */
    memcpy(&heli_q8_d5p3_old_B.UnitDelay2[0],
           &heli_q8_d5p3_old_DW.UnitDelay2_DSTATE[0], 36U * sizeof(real_T));
  }

  /* MATLAB Function: '<S5>/Kalman prediction step' */
  /* MATLAB Function 'Kalman filter/Kalman prediction step': '<S11>:1' */
  /*  Task 5.3 */
  /* '<S11>:1:6' */
  /* '<S11>:1:7' */
  for (i = 0; i < 6; i++) {
    tmp_0[i] = 0.0;
    tmp_1[i] = 0.0;
    tmp_1[i] += heli_q8_d5p3_old_B.B_d[i] * rtb_Sum3[0];
    tmp_1[i] += heli_q8_d5p3_old_B.B_d[i + 6] * rtb_Sum3[1];
    for (i_0 = 0; i_0 < 6; i_0++) {
      tmp_0[i] += heli_q8_d5p3_old_B.A_d[6 * i_0 + i] *
        heli_q8_d5p3_old_B.UnitDelay1[i_0];
      tmp_2[i + 6 * i_0] = 0.0;
      for (i_1 = 0; i_1 < 6; i_1++) {
        tmp_2[i + 6 * i_0] += heli_q8_d5p3_old_B.A_d[6 * i_1 + i] *
          heli_q8_d5p3_old_B.UnitDelay2[6 * i_0 + i_1];
      }
    }

    heli_q8_d5p3_old_B.x_k2[i] = tmp_0[i] + tmp_1[i];
  }

  for (i = 0; i < 6; i++) {
    for (i_0 = 0; i_0 < 6; i_0++) {
      u0 = 0.0;
      for (i_1 = 0; i_1 < 6; i_1++) {
        u0 += tmp_2[6 * i_1 + i] * heli_q8_d5p3_old_B.A_d[6 * i_1 + i_0];
      }

      heli_q8_d5p3_old_B.P_k2[i + 6 * i_0] = heli_q8_d5p3_old_B.Q_d[6 * i_0 + i]
        + u0;
    }
  }

  /* End of MATLAB Function: '<S5>/Kalman prediction step' */
  if (rtmIsMajorTimeStep(heli_q8_d5p3_old_M)) {
    /* Gain: '<S2>/Travel: Count to rad' */
    heli_q8_d5p3_old_B.TravelCounttorad =
      heli_q8_d5p3_old_P.TravelCounttorad_Gain * rtb_HILReadEncoderTimebase_o1;
  }

  /* TransferFcn: '<S2>/Travel: Transfer Fcn' */
  heli_q8_d5p3_old_B.TravelTransferFcn = 0.0;
  heli_q8_d5p3_old_B.TravelTransferFcn += heli_q8_d5p3_old_P.TravelTransferFcn_C
    * heli_q8_d5p3_old_X.TravelTransferFcn_CSTATE;
  heli_q8_d5p3_old_B.TravelTransferFcn += heli_q8_d5p3_old_P.TravelTransferFcn_D
    * heli_q8_d5p3_old_B.TravelCounttorad;
  if (rtmIsMajorTimeStep(heli_q8_d5p3_old_M)) {
    /* S-Function (stream_call_block): '<S9>/Stream Call1' */

    /* S-Function Block: heli_q8_d5p3_old/IMU System/IMU/Stream Call1 (stream_call_block) */
    {
      t_error result = 0;
      t_boolean close_flag = (heli_q8_d5p3_old_P.Constant_Value != 0);
      rtb_StreamCall1_o1 = NULL;
      switch (heli_q8_d5p3_old_DW.StreamCall1_State) {
       case STREAM_CALL_STATE_NOT_CONNECTED:
        {
          if (!close_flag) {
            /* Make sure URI is null-terminated */
            if (string_length((char *) heli_q8_d5p3_old_P.StringConstant_Value,
                              255) == 255) {
              rtmSetErrorStatus(heli_q8_d5p3_old_M,
                                "URI passed to Stream Call block is not null-terminated!");
              result = -QERR_STRING_NOT_TERMINATED;
            } else {
              result = stream_connect((char *)
                heli_q8_d5p3_old_P.StringConstant_Value, true,
                heli_q8_d5p3_old_P.StreamCall1_SendBufferSize,
                heli_q8_d5p3_old_P.StreamCall1_ReceiveBufferSize,
                &heli_q8_d5p3_old_DW.StreamCall1_Stream);
              if (result == 0) {
                heli_q8_d5p3_old_DW.StreamCall1_State =
                  STREAM_CALL_STATE_CONNECTED;
                stream_set_byte_order(heli_q8_d5p3_old_DW.StreamCall1_Stream,
                                      (t_stream_byte_order)
                                      heli_q8_d5p3_old_P.StreamCall1_Endian);
                rtb_StreamCall1_o1 = &heli_q8_d5p3_old_DW.StreamCall1_Stream;
              } else if (result == -QERR_WOULD_BLOCK) {
                heli_q8_d5p3_old_DW.StreamCall1_State =
                  STREAM_CALL_STATE_CONNECTING;
                result = 0;
              }
            }
          }
          break;
        }

       case STREAM_CALL_STATE_CONNECTING:
        {
          if (!close_flag) {
            const t_timeout timeout = { 0, 0, false };/* zero seconds */

            result = stream_poll(heli_q8_d5p3_old_DW.StreamCall1_Stream,
                                 &timeout, STREAM_POLL_CONNECT);
            if (result > 0) {
              heli_q8_d5p3_old_DW.StreamCall1_State =
                STREAM_CALL_STATE_CONNECTED;
              stream_set_byte_order(heli_q8_d5p3_old_DW.StreamCall1_Stream,
                                    (t_stream_byte_order)
                                    heli_q8_d5p3_old_P.StreamCall1_Endian);
              rtb_StreamCall1_o1 = &heli_q8_d5p3_old_DW.StreamCall1_Stream;
              result = 0;
              break;
            } else if (result == 0) {
              break;
            }
          }

          /* Fall through deliberately */
        }

       case STREAM_CALL_STATE_CONNECTED:
        {
          rtb_StreamCall1_o1 = &heli_q8_d5p3_old_DW.StreamCall1_Stream;
          if (!close_flag) {
            break;
          }

          /* Fall through deliberately */
        }

       default:
        {
          t_error close_result = stream_close
            (heli_q8_d5p3_old_DW.StreamCall1_Stream);
          if (close_result == 0) {
            heli_q8_d5p3_old_DW.StreamCall1_State =
              STREAM_CALL_STATE_NOT_CONNECTED;
            heli_q8_d5p3_old_DW.StreamCall1_Stream = NULL;
            rtb_StreamCall1_o1 = NULL;
          } else if (result == 0) {
            result = close_result;
          }
          break;
        }
      }

      heli_q8_d5p3_old_B.StreamCall1_o2 = heli_q8_d5p3_old_DW.StreamCall1_State;
      rtb_StreamCall1_o3 = (int32_T) result;
    }

    /* S-Function (stream_formatted_write_block): '<S9>/Stream Formatted Write' */
    {
      t_error result;
      if (rtb_StreamCall1_o1 != NULL) {
        result = stream_print_utf8_char_array(*rtb_StreamCall1_o1,
          heli_q8_d5p3_old_P.StreamFormattedWrite_MaxUnits,
          &rtb_StreamFormattedWrite_o2, "%c\n"
          , (char) heli_q8_d5p3_old_P.Constant1_Value_f
          );
        if (result > 0) {
          result = stream_flush(*rtb_StreamCall1_o1);
        }

        if (result == -QERR_WOULD_BLOCK) {
          result = 0;
        }
      }

      rtb_StreamFormattedWrite_o1 = rtb_StreamCall1_o1;
    }

    /* S-Function (stream_read_block): '<S9>/Stream Read1' */
    /* S-Function Block: heli_q8_d5p3_old/IMU System/IMU/Stream Read1 (stream_read_block) */
    {
      t_error result;
      memset(&rtb_StreamRead1_o2[0], 0, 10 * sizeof(real32_T));
      if (rtb_StreamFormattedWrite_o1 != NULL) {
        result = stream_receive_unit_array(*rtb_StreamFormattedWrite_o1,
          &rtb_StreamRead1_o2[0], sizeof(real32_T), 10);
        rtb_StreamRead1_o3 = (result > 0);
        if (result > 0 || result == -QERR_WOULD_BLOCK) {
          result = 0;
        }
      } else {
        rtb_StreamRead1_o3 = false;
        result = 0;
      }

      rtb_StreamRead1_o5 = (int32_T) result;
    }

    /* Switch: '<S9>/Switch' incorporates:
     *  Constant: '<S9>/Constant2'
     *  DataTypeConversion: '<S9>/Data Type Conversion'
     */
    for (i = 0; i < 10; i++) {
      if (rtb_StreamRead1_o3) {
        rtb_Switch[i] = rtb_StreamRead1_o2[i];
      } else {
        rtb_Switch[i] = heli_q8_d5p3_old_P.Constant2_Value;
      }
    }

    /* End of Switch: '<S9>/Switch' */

    /* Gain: '<S9>/Gain2' incorporates:
     *  SignalConversion: '<S9>/TmpSignal ConversionAtGain2Inport1'
     */
    for (i = 0; i < 3; i++) {
      heli_q8_d5p3_old_B.Gain2[i] = 0.0;
      heli_q8_d5p3_old_B.Gain2[i] += heli_q8_d5p3_old_P.Gain2_Gain[i] *
        rtb_Switch[0];
      heli_q8_d5p3_old_B.Gain2[i] += heli_q8_d5p3_old_P.Gain2_Gain[i + 3] *
        rtb_Switch[2];
      heli_q8_d5p3_old_B.Gain2[i] += heli_q8_d5p3_old_P.Gain2_Gain[i + 6] *
        rtb_Switch[1];
    }

    /* End of Gain: '<S9>/Gain2' */

    /* Trigonometry: '<S10>/Trigonometric Function1' incorporates:
     *  Product: '<S10>/Divide1'
     *  Product: '<S10>/Product'
     *  Product: '<S10>/Product1'
     *  Sqrt: '<S10>/Sqrt'
     *  Sum: '<S10>/Add'
     */
    heli_q8_d5p3_old_B.TrigonometricFunction1 = atan(heli_q8_d5p3_old_B.Gain2[1]
      / sqrt(heli_q8_d5p3_old_B.Gain2[0] * heli_q8_d5p3_old_B.Gain2[0] +
             heli_q8_d5p3_old_B.Gain2[2] * heli_q8_d5p3_old_B.Gain2[2]));

    /* MATLAB Function: '<S3>/Gyro vector to [pitch rate, elevation rate, travle rate]' incorporates:
     *  SignalConversion: '<S8>/TmpSignal ConversionAt SFunction Inport2'
     */
    /* MATLAB Function 'IMU System/Gyro vector to [pitch rate, elevation rate, travle rate]': '<S8>:1' */
    /* '<S8>:1:3' */
    /* '<S8>:1:4' */
    /* psi = euler_angles(3); */
    /* '<S8>:1:8' */
    /* '<S8>:1:11' */
    tmp_3[0] = 1.0;
    tmp_3[3] = sin(heli_q8_d5p3_old_B.Sum1) * tan(heli_q8_d5p3_old_B.Sum2);
    tmp_3[6] = cos(heli_q8_d5p3_old_B.Sum1) * tan(heli_q8_d5p3_old_B.Sum2);
    tmp_3[1] = 0.0;
    tmp_3[4] = cos(heli_q8_d5p3_old_B.Sum1);
    tmp_3[7] = -sin(heli_q8_d5p3_old_B.Sum1);
    tmp_3[2] = 0.0;
    tmp_3[5] = sin(heli_q8_d5p3_old_B.Sum1) / cos(heli_q8_d5p3_old_B.Sum2);
    tmp_3[8] = cos(heli_q8_d5p3_old_B.Sum1) / cos(heli_q8_d5p3_old_B.Sum2);

    /* Gain: '<S9>/Gain1' incorporates:
     *  MATLAB Function: '<S3>/Gyro vector to [pitch rate, elevation rate, travle rate]'
     */
    for (i = 0; i < 3; i++) {
      tmp_4[i] = heli_q8_d5p3_old_P.Gain1_Gain[i + 6] * rtb_Switch[5] +
        (heli_q8_d5p3_old_P.Gain1_Gain[i + 3] * rtb_Switch[4] +
         heli_q8_d5p3_old_P.Gain1_Gain[i] * rtb_Switch[3]);
    }

    /* End of Gain: '<S9>/Gain1' */

    /* MATLAB Function: '<S3>/Gyro vector to [pitch rate, elevation rate, travle rate]' */
    for (i = 0; i < 3; i++) {
      heli_q8_d5p3_old_B.euler_rates[i] = 0.0;
      heli_q8_d5p3_old_B.euler_rates[i] += tmp_3[i] * tmp_4[0];
      heli_q8_d5p3_old_B.euler_rates[i] += tmp_3[i + 3] * tmp_4[1];
      heli_q8_d5p3_old_B.euler_rates[i] += tmp_3[i + 6] * tmp_4[2];
    }

    /* Trigonometry: '<S10>/Trigonometric Function' incorporates:
     *  Product: '<S10>/Divide'
     */
    heli_q8_d5p3_old_B.TrigonometricFunction = atan(heli_q8_d5p3_old_B.Gain2[0] /
      heli_q8_d5p3_old_B.Gain2[2]);

    /* SignalConversion: '<Root>/TmpSignal ConversionAtnoise to fileInport1' */
    rtb_TmpSignalConversionAtnoiset[0] = heli_q8_d5p3_old_B.euler_rates[0];
    rtb_TmpSignalConversionAtnoiset[1] = heli_q8_d5p3_old_B.euler_rates[1];
    rtb_TmpSignalConversionAtnoiset[2] = heli_q8_d5p3_old_B.euler_rates[2];
    rtb_TmpSignalConversionAtnoiset[3] =
      heli_q8_d5p3_old_B.TrigonometricFunction;
    rtb_TmpSignalConversionAtnoiset[4] =
      heli_q8_d5p3_old_B.TrigonometricFunction1;

    /* ToFile: '<Root>/noise to file' */
    if (rtmIsMajorTimeStep(heli_q8_d5p3_old_M)) {
      {
        if (!(++heli_q8_d5p3_old_DW.noisetofile_IWORK.Decimation % 1) &&
            (heli_q8_d5p3_old_DW.noisetofile_IWORK.Count*6)+1 < 100000000 ) {
          FILE *fp = (FILE *) heli_q8_d5p3_old_DW.noisetofile_PWORK.FilePtr;
          if (fp != (NULL)) {
            real_T u[6];
            heli_q8_d5p3_old_DW.noisetofile_IWORK.Decimation = 0;
            u[0] = heli_q8_d5p3_old_M->Timing.t[1];
            u[1] = rtb_TmpSignalConversionAtnoiset[0];
            u[2] = rtb_TmpSignalConversionAtnoiset[1];
            u[3] = rtb_TmpSignalConversionAtnoiset[2];
            u[4] = rtb_TmpSignalConversionAtnoiset[3];
            u[5] = rtb_TmpSignalConversionAtnoiset[4];
            if (fwrite(u, sizeof(real_T), 6, fp) != 6) {
              rtmSetErrorStatus(heli_q8_d5p3_old_M,
                                "Error writing to MAT-file noise.mat");
              return;
            }

            if (((++heli_q8_d5p3_old_DW.noisetofile_IWORK.Count)*6)+1 >=
                100000000) {
              (void)fprintf(stdout,
                            "*** The ToFile block will stop logging data before\n"
                            "    the simulation has ended, because it has reached\n"
                            "    the maximum number of elements (100000000)\n"
                            "    allowed in MAT-file noise.mat.\n");
            }
          }
        }
      }
    }

    /* Constant: '<S6>/V_s0' */
    heli_q8_d5p3_old_B.V_s0[0] = heli_q8_d5p3_old_P.V_s0_Value[0];
    heli_q8_d5p3_old_B.V_s0[1] = heli_q8_d5p3_old_P.V_s0_Value[1];
  }

  /* Sum: '<S6>/Sum1' */
  heli_q8_d5p3_old_B.Sum1_e[0] = rtb_Sum3[0] + heli_q8_d5p3_old_B.V_s0[0];
  heli_q8_d5p3_old_B.Sum1_e[1] = rtb_Sum3[1] + heli_q8_d5p3_old_B.V_s0[1];
  if (rtmIsMajorTimeStep(heli_q8_d5p3_old_M)) {
  }

  /* Gain: '<S1>/Front gain' incorporates:
   *  Sum: '<S1>/Add'
   */
  u0 = (heli_q8_d5p3_old_B.Sum1_e[0] - heli_q8_d5p3_old_B.Sum1_e[1]) *
    heli_q8_d5p3_old_P.Frontgain_Gain;

  /* Saturate: '<S2>/Front motor: Saturation' */
  if (u0 > heli_q8_d5p3_old_P.FrontmotorSaturation_UpperSat) {
    heli_q8_d5p3_old_B.FrontmotorSaturation =
      heli_q8_d5p3_old_P.FrontmotorSaturation_UpperSat;
  } else if (u0 < heli_q8_d5p3_old_P.FrontmotorSaturation_LowerSat) {
    heli_q8_d5p3_old_B.FrontmotorSaturation =
      heli_q8_d5p3_old_P.FrontmotorSaturation_LowerSat;
  } else {
    heli_q8_d5p3_old_B.FrontmotorSaturation = u0;
  }

  /* End of Saturate: '<S2>/Front motor: Saturation' */

  /* Gain: '<S1>/Back gain' incorporates:
   *  Sum: '<S1>/Subtract'
   */
  u0 = (heli_q8_d5p3_old_B.Sum1_e[1] + heli_q8_d5p3_old_B.Sum1_e[0]) *
    heli_q8_d5p3_old_P.Backgain_Gain;

  /* Saturate: '<S2>/Back motor: Saturation' */
  if (u0 > heli_q8_d5p3_old_P.BackmotorSaturation_UpperSat) {
    heli_q8_d5p3_old_B.BackmotorSaturation =
      heli_q8_d5p3_old_P.BackmotorSaturation_UpperSat;
  } else if (u0 < heli_q8_d5p3_old_P.BackmotorSaturation_LowerSat) {
    heli_q8_d5p3_old_B.BackmotorSaturation =
      heli_q8_d5p3_old_P.BackmotorSaturation_LowerSat;
  } else {
    heli_q8_d5p3_old_B.BackmotorSaturation = u0;
  }

  /* End of Saturate: '<S2>/Back motor: Saturation' */
  if (rtmIsMajorTimeStep(heli_q8_d5p3_old_M)) {
    /* S-Function (hil_write_analog_block): '<S2>/HIL Write Analog' */

    /* S-Function Block: heli_q8_d5p3_old/Heli 3D/HIL Write Analog (hil_write_analog_block) */
    {
      t_error result;
      heli_q8_d5p3_old_DW.HILWriteAnalog_Buffer[0] =
        heli_q8_d5p3_old_B.FrontmotorSaturation;
      heli_q8_d5p3_old_DW.HILWriteAnalog_Buffer[1] =
        heli_q8_d5p3_old_B.BackmotorSaturation;
      result = hil_write_analog(heli_q8_d5p3_old_DW.HILInitialize_Card,
        heli_q8_d5p3_old_P.HILWriteAnalog_channels, 2,
        &heli_q8_d5p3_old_DW.HILWriteAnalog_Buffer[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_d5p3_old_M, _rt_error_message);
      }
    }

    /* S-Function (stop_with_error_block): '<S9>/Stop with Call Error' */

    /* S-Function Block: heli_q8_d5p3_old/IMU System/IMU/Stop with Call Error (stop_with_error_block) */
    {
      if (rtb_StreamCall1_o3 < 0) {
        msg_get_error_messageA(NULL, rtb_StreamCall1_o3, _rt_error_message,
          sizeof(_rt_error_message));
        rtmSetErrorStatus(heli_q8_d5p3_old_M, _rt_error_message);
        return;
      }
    }

    /* S-Function (stop_with_error_block): '<S9>/Stop with Read Error' */

    /* S-Function Block: heli_q8_d5p3_old/IMU System/IMU/Stop with Read Error (stop_with_error_block) */
    {
      if (rtb_StreamRead1_o5 < 0) {
        msg_get_error_messageA(NULL, rtb_StreamRead1_o5, _rt_error_message,
          sizeof(_rt_error_message));
        rtmSetErrorStatus(heli_q8_d5p3_old_M, _rt_error_message);
        return;
      }
    }
  }

  /* Sum: '<S6>/Sum3' */
  heli_q8_d5p3_old_B.Sum3[0] = heli_q8_d5p3_old_B.Sum1 -
    heli_q8_d5p3_old_B.Joystick_gain_x;
  heli_q8_d5p3_old_B.Sum3[1] = heli_q8_d5p3_old_B.ElevationTransferFcn -
    heli_q8_d5p3_old_B.Joystick_gain_y;
}

/* Model update function for TID0 */
void heli_q8_d5p3_old_update0(void)    /* Sample time: [0.0s, 0.0s] */
{
  int32_T i;
  if (rtmIsMajorTimeStep(heli_q8_d5p3_old_M)) {
    /* Update for UnitDelay: '<S5>/Unit Delay1' */
    for (i = 0; i < 6; i++) {
      heli_q8_d5p3_old_DW.UnitDelay1_DSTATE[i] = heli_q8_d5p3_old_B.x_k2[i];
    }

    /* End of Update for UnitDelay: '<S5>/Unit Delay1' */

    /* Update for UnitDelay: '<S5>/Unit Delay2' */
    memcpy(&heli_q8_d5p3_old_DW.UnitDelay2_DSTATE[0], &heli_q8_d5p3_old_B.P_k2[0],
           36U * sizeof(real_T));
  }

  if (rtmIsMajorTimeStep(heli_q8_d5p3_old_M)) {
    rt_ertODEUpdateContinuousStates(&heli_q8_d5p3_old_M->solverInfo);
  }

  /* Update absolute time */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++heli_q8_d5p3_old_M->Timing.clockTick0)) {
    ++heli_q8_d5p3_old_M->Timing.clockTickH0;
  }

  heli_q8_d5p3_old_M->Timing.t[0] = rtsiGetSolverStopTime
    (&heli_q8_d5p3_old_M->solverInfo);

  /* Update absolute time */
  /* The "clockTick1" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick1"
   * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick1 and the high bits
   * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++heli_q8_d5p3_old_M->Timing.clockTick1)) {
    ++heli_q8_d5p3_old_M->Timing.clockTickH1;
  }

  heli_q8_d5p3_old_M->Timing.t[1] = heli_q8_d5p3_old_M->Timing.clockTick1 *
    heli_q8_d5p3_old_M->Timing.stepSize1 +
    heli_q8_d5p3_old_M->Timing.clockTickH1 *
    heli_q8_d5p3_old_M->Timing.stepSize1 * 4294967296.0;
}

/* Derivatives for root system: '<Root>' */
void heli_q8_d5p3_old_derivatives(void)
{
  XDot_heli_q8_d5p3_old_T *_rtXdot;
  _rtXdot = ((XDot_heli_q8_d5p3_old_T *) heli_q8_d5p3_old_M->ModelData.derivs);

  /* Derivatives for TransferFcn: '<S2>/Pitch: Transfer Fcn' */
  _rtXdot->PitchTransferFcn_CSTATE = 0.0;
  _rtXdot->PitchTransferFcn_CSTATE += heli_q8_d5p3_old_P.PitchTransferFcn_A *
    heli_q8_d5p3_old_X.PitchTransferFcn_CSTATE;
  _rtXdot->PitchTransferFcn_CSTATE += heli_q8_d5p3_old_B.Sum1;

  /* Derivatives for TransferFcn: '<S2>/Elevation: Transfer Fcn' */
  _rtXdot->ElevationTransferFcn_CSTATE = 0.0;
  _rtXdot->ElevationTransferFcn_CSTATE +=
    heli_q8_d5p3_old_P.ElevationTransferFcn_A *
    heli_q8_d5p3_old_X.ElevationTransferFcn_CSTATE;
  _rtXdot->ElevationTransferFcn_CSTATE += heli_q8_d5p3_old_B.Sum2;

  /* Derivatives for Integrator: '<S6>/Integrate -> [gamma,zeta]' */
  _rtXdot->Integrategammazeta_CSTATE[0] = heli_q8_d5p3_old_B.Sum3[0];
  _rtXdot->Integrategammazeta_CSTATE[1] = heli_q8_d5p3_old_B.Sum3[1];

  /* Derivatives for TransferFcn: '<S2>/Travel: Transfer Fcn' */
  _rtXdot->TravelTransferFcn_CSTATE = 0.0;
  _rtXdot->TravelTransferFcn_CSTATE += heli_q8_d5p3_old_P.TravelTransferFcn_A *
    heli_q8_d5p3_old_X.TravelTransferFcn_CSTATE;
  _rtXdot->TravelTransferFcn_CSTATE += heli_q8_d5p3_old_B.TravelCounttorad;
}

/* Model output function for TID2 */
void heli_q8_d5p3_old_output2(void)    /* Sample time: [0.01s, 0.0s] */
{
  /* S-Function (game_controller_block): '<S4>/Game Controller' */

  /* S-Function Block: heli_q8_d5p3_old/Joystick1/Game Controller (game_controller_block) */
  {
    if (heli_q8_d5p3_old_P.GameController_Enabled) {
      t_game_controller_states state;
      t_boolean new_data;
      t_error result;
      result = game_controller_poll
        (heli_q8_d5p3_old_DW.GameController_Controller, &state, &new_data);
      if (result == 0) {
        heli_q8_d5p3_old_B.GameController_o4 = state.x;
        heli_q8_d5p3_old_B.GameController_o5 = state.y;
      }
    } else {
      heli_q8_d5p3_old_B.GameController_o4 = 0;
      heli_q8_d5p3_old_B.GameController_o5 = 0;
    }
  }
}

/* Model update function for TID2 */
void heli_q8_d5p3_old_update2(void)    /* Sample time: [0.01s, 0.0s] */
{
  /* Update for RateTransition: '<S4>/Rate Transition: x' */
  heli_q8_d5p3_old_DW.RateTransitionx_Buffer0 =
    heli_q8_d5p3_old_B.GameController_o4;

  /* Update for RateTransition: '<S4>/Rate Transition: y' */
  heli_q8_d5p3_old_DW.RateTransitiony_Buffer0 =
    heli_q8_d5p3_old_B.GameController_o5;

  /* Update absolute time */
  /* The "clockTick2" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick2"
   * and "Timing.stepSize2". Size of "clockTick2" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick2 and the high bits
   * Timing.clockTickH2. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++heli_q8_d5p3_old_M->Timing.clockTick2)) {
    ++heli_q8_d5p3_old_M->Timing.clockTickH2;
  }

  heli_q8_d5p3_old_M->Timing.t[2] = heli_q8_d5p3_old_M->Timing.clockTick2 *
    heli_q8_d5p3_old_M->Timing.stepSize2 +
    heli_q8_d5p3_old_M->Timing.clockTickH2 *
    heli_q8_d5p3_old_M->Timing.stepSize2 * 4294967296.0;
}

/* Model output wrapper function for compatibility with a static main program */
void heli_q8_d5p3_old_output(int_T tid)
{
  switch (tid) {
   case 0 :
    heli_q8_d5p3_old_output0();
    break;

   case 2 :
    heli_q8_d5p3_old_output2();
    break;

   default :
    break;
  }
}

/* Model update wrapper function for compatibility with a static main program */
void heli_q8_d5p3_old_update(int_T tid)
{
  switch (tid) {
   case 0 :
    heli_q8_d5p3_old_update0();
    break;

   case 2 :
    heli_q8_d5p3_old_update2();
    break;

   default :
    break;
  }
}

/* Model initialize function */
void heli_q8_d5p3_old_initialize(void)
{
  /* Start for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: heli_q8_d5p3_old/HIL Initialize (hil_initialize_block) */
  {
    t_int result;
    t_boolean is_switching;
    result = hil_open("q8_usb", "0", &heli_q8_d5p3_old_DW.HILInitialize_Card);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(heli_q8_d5p3_old_M, _rt_error_message);
      return;
    }

    is_switching = false;
    result = hil_set_card_specific_options
      (heli_q8_d5p3_old_DW.HILInitialize_Card, "update_rate=normal;decimation=1",
       32);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(heli_q8_d5p3_old_M, _rt_error_message);
      return;
    }

    result = hil_watchdog_clear(heli_q8_d5p3_old_DW.HILInitialize_Card);
    if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(heli_q8_d5p3_old_M, _rt_error_message);
      return;
    }

    if ((heli_q8_d5p3_old_P.HILInitialize_set_analog_input_ && !is_switching) ||
        (heli_q8_d5p3_old_P.HILInitialize_set_analog_inpu_m && is_switching)) {
      {
        int_T i1;
        real_T *dw_AIMinimums = &heli_q8_d5p3_old_DW.HILInitialize_AIMinimums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AIMinimums[i1] = heli_q8_d5p3_old_P.HILInitialize_analog_input_mini;
        }
      }

      {
        int_T i1;
        real_T *dw_AIMaximums = &heli_q8_d5p3_old_DW.HILInitialize_AIMaximums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AIMaximums[i1] = heli_q8_d5p3_old_P.HILInitialize_analog_input_maxi;
        }
      }

      result = hil_set_analog_input_ranges
        (heli_q8_d5p3_old_DW.HILInitialize_Card,
         heli_q8_d5p3_old_P.HILInitialize_analog_input_chan, 8U,
         &heli_q8_d5p3_old_DW.HILInitialize_AIMinimums[0],
         &heli_q8_d5p3_old_DW.HILInitialize_AIMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_d5p3_old_M, _rt_error_message);
        return;
      }
    }

    if ((heli_q8_d5p3_old_P.HILInitialize_set_analog_output && !is_switching) ||
        (heli_q8_d5p3_old_P.HILInitialize_set_analog_outp_b && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOMinimums = &heli_q8_d5p3_old_DW.HILInitialize_AOMinimums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOMinimums[i1] = heli_q8_d5p3_old_P.HILInitialize_analog_output_min;
        }
      }

      {
        int_T i1;
        real_T *dw_AOMaximums = &heli_q8_d5p3_old_DW.HILInitialize_AOMaximums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOMaximums[i1] = heli_q8_d5p3_old_P.HILInitialize_analog_output_max;
        }
      }

      result = hil_set_analog_output_ranges
        (heli_q8_d5p3_old_DW.HILInitialize_Card,
         heli_q8_d5p3_old_P.HILInitialize_analog_output_cha, 8U,
         &heli_q8_d5p3_old_DW.HILInitialize_AOMinimums[0],
         &heli_q8_d5p3_old_DW.HILInitialize_AOMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_d5p3_old_M, _rt_error_message);
        return;
      }
    }

    if ((heli_q8_d5p3_old_P.HILInitialize_set_analog_outp_e && !is_switching) ||
        (heli_q8_d5p3_old_P.HILInitialize_set_analog_outp_j && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOVoltages = &heli_q8_d5p3_old_DW.HILInitialize_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = heli_q8_d5p3_old_P.HILInitialize_initial_analog_ou;
        }
      }

      result = hil_write_analog(heli_q8_d5p3_old_DW.HILInitialize_Card,
        heli_q8_d5p3_old_P.HILInitialize_analog_output_cha, 8U,
        &heli_q8_d5p3_old_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_d5p3_old_M, _rt_error_message);
        return;
      }
    }

    if (heli_q8_d5p3_old_P.HILInitialize_set_analog_outp_p) {
      {
        int_T i1;
        real_T *dw_AOVoltages = &heli_q8_d5p3_old_DW.HILInitialize_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = heli_q8_d5p3_old_P.HILInitialize_watchdog_analog_o;
        }
      }

      result = hil_watchdog_set_analog_expiration_state
        (heli_q8_d5p3_old_DW.HILInitialize_Card,
         heli_q8_d5p3_old_P.HILInitialize_analog_output_cha, 8U,
         &heli_q8_d5p3_old_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_d5p3_old_M, _rt_error_message);
        return;
      }
    }

    if ((heli_q8_d5p3_old_P.HILInitialize_set_encoder_param && !is_switching) ||
        (heli_q8_d5p3_old_P.HILInitialize_set_encoder_par_m && is_switching)) {
      {
        int_T i1;
        int32_T *dw_QuadratureModes =
          &heli_q8_d5p3_old_DW.HILInitialize_QuadratureModes[0];
        for (i1=0; i1 < 8; i1++) {
          dw_QuadratureModes[i1] = heli_q8_d5p3_old_P.HILInitialize_quadrature;
        }
      }

      result = hil_set_encoder_quadrature_mode
        (heli_q8_d5p3_old_DW.HILInitialize_Card,
         heli_q8_d5p3_old_P.HILInitialize_encoder_channels, 8U,
         (t_encoder_quadrature_mode *)
         &heli_q8_d5p3_old_DW.HILInitialize_QuadratureModes[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_d5p3_old_M, _rt_error_message);
        return;
      }
    }

    if ((heli_q8_d5p3_old_P.HILInitialize_set_encoder_count && !is_switching) ||
        (heli_q8_d5p3_old_P.HILInitialize_set_encoder_cou_k && is_switching)) {
      {
        int_T i1;
        int32_T *dw_InitialEICounts =
          &heli_q8_d5p3_old_DW.HILInitialize_InitialEICounts[0];
        for (i1=0; i1 < 8; i1++) {
          dw_InitialEICounts[i1] =
            heli_q8_d5p3_old_P.HILInitialize_initial_encoder_c;
        }
      }

      result = hil_set_encoder_counts(heli_q8_d5p3_old_DW.HILInitialize_Card,
        heli_q8_d5p3_old_P.HILInitialize_encoder_channels, 8U,
        &heli_q8_d5p3_old_DW.HILInitialize_InitialEICounts[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_d5p3_old_M, _rt_error_message);
        return;
      }
    }

    if ((heli_q8_d5p3_old_P.HILInitialize_set_pwm_params_at && !is_switching) ||
        (heli_q8_d5p3_old_P.HILInitialize_set_pwm_params__f && is_switching)) {
      uint32_T num_duty_cycle_modes = 0;
      uint32_T num_frequency_modes = 0;

      {
        int_T i1;
        int32_T *dw_POModeValues =
          &heli_q8_d5p3_old_DW.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POModeValues[i1] = heli_q8_d5p3_old_P.HILInitialize_pwm_modes;
        }
      }

      result = hil_set_pwm_mode(heli_q8_d5p3_old_DW.HILInitialize_Card,
        heli_q8_d5p3_old_P.HILInitialize_pwm_channels, 8U, (t_pwm_mode *)
        &heli_q8_d5p3_old_DW.HILInitialize_POModeValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_d5p3_old_M, _rt_error_message);
        return;
      }

      {
        int_T i1;
        const uint32_T *p_HILInitialize_pwm_channels =
          heli_q8_d5p3_old_P.HILInitialize_pwm_channels;
        int32_T *dw_POModeValues =
          &heli_q8_d5p3_old_DW.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          if (dw_POModeValues[i1] == PWM_DUTY_CYCLE_MODE || dw_POModeValues[i1] ==
              PWM_ONE_SHOT_MODE || dw_POModeValues[i1] == PWM_TIME_MODE) {
            heli_q8_d5p3_old_DW.HILInitialize_POSortedChans[num_duty_cycle_modes]
              = p_HILInitialize_pwm_channels[i1];
            heli_q8_d5p3_old_DW.HILInitialize_POSortedFreqs[num_duty_cycle_modes]
              = heli_q8_d5p3_old_P.HILInitialize_pwm_frequency;
            num_duty_cycle_modes++;
          } else {
            heli_q8_d5p3_old_DW.HILInitialize_POSortedChans[7U -
              num_frequency_modes] = p_HILInitialize_pwm_channels[i1];
            heli_q8_d5p3_old_DW.HILInitialize_POSortedFreqs[7U -
              num_frequency_modes] =
              heli_q8_d5p3_old_P.HILInitialize_pwm_frequency;
            num_frequency_modes++;
          }
        }
      }

      if (num_duty_cycle_modes > 0) {
        result = hil_set_pwm_frequency(heli_q8_d5p3_old_DW.HILInitialize_Card,
          &heli_q8_d5p3_old_DW.HILInitialize_POSortedChans[0],
          num_duty_cycle_modes,
          &heli_q8_d5p3_old_DW.HILInitialize_POSortedFreqs[0]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(heli_q8_d5p3_old_M, _rt_error_message);
          return;
        }
      }

      if (num_frequency_modes > 0) {
        result = hil_set_pwm_duty_cycle(heli_q8_d5p3_old_DW.HILInitialize_Card,
          &heli_q8_d5p3_old_DW.HILInitialize_POSortedChans[num_duty_cycle_modes],
          num_frequency_modes,
          &heli_q8_d5p3_old_DW.HILInitialize_POSortedFreqs[num_duty_cycle_modes]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(heli_q8_d5p3_old_M, _rt_error_message);
          return;
        }
      }

      {
        int_T i1;
        int32_T *dw_POModeValues =
          &heli_q8_d5p3_old_DW.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POModeValues[i1] =
            heli_q8_d5p3_old_P.HILInitialize_pwm_configuration;
        }
      }

      {
        int_T i1;
        int32_T *dw_POAlignValues =
          &heli_q8_d5p3_old_DW.HILInitialize_POAlignValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POAlignValues[i1] = heli_q8_d5p3_old_P.HILInitialize_pwm_alignment;
        }
      }

      {
        int_T i1;
        int32_T *dw_POPolarityVals =
          &heli_q8_d5p3_old_DW.HILInitialize_POPolarityVals[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POPolarityVals[i1] = heli_q8_d5p3_old_P.HILInitialize_pwm_polarity;
        }
      }

      result = hil_set_pwm_configuration(heli_q8_d5p3_old_DW.HILInitialize_Card,
        heli_q8_d5p3_old_P.HILInitialize_pwm_channels, 8U,
        (t_pwm_configuration *) &heli_q8_d5p3_old_DW.HILInitialize_POModeValues
        [0],
        (t_pwm_alignment *) &heli_q8_d5p3_old_DW.HILInitialize_POAlignValues[0],
        (t_pwm_polarity *) &heli_q8_d5p3_old_DW.HILInitialize_POPolarityVals[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_d5p3_old_M, _rt_error_message);
        return;
      }

      {
        int_T i1;
        real_T *dw_POSortedFreqs =
          &heli_q8_d5p3_old_DW.HILInitialize_POSortedFreqs[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POSortedFreqs[i1] =
            heli_q8_d5p3_old_P.HILInitialize_pwm_leading_deadb;
        }
      }

      {
        int_T i1;
        real_T *dw_POValues = &heli_q8_d5p3_old_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = heli_q8_d5p3_old_P.HILInitialize_pwm_trailing_dead;
        }
      }

      result = hil_set_pwm_deadband(heli_q8_d5p3_old_DW.HILInitialize_Card,
        heli_q8_d5p3_old_P.HILInitialize_pwm_channels, 8U,
        &heli_q8_d5p3_old_DW.HILInitialize_POSortedFreqs[0],
        &heli_q8_d5p3_old_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_d5p3_old_M, _rt_error_message);
        return;
      }
    }

    if ((heli_q8_d5p3_old_P.HILInitialize_set_pwm_outputs_a && !is_switching) ||
        (heli_q8_d5p3_old_P.HILInitialize_set_pwm_outputs_g && is_switching)) {
      {
        int_T i1;
        real_T *dw_POValues = &heli_q8_d5p3_old_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = heli_q8_d5p3_old_P.HILInitialize_initial_pwm_outpu;
        }
      }

      result = hil_write_pwm(heli_q8_d5p3_old_DW.HILInitialize_Card,
        heli_q8_d5p3_old_P.HILInitialize_pwm_channels, 8U,
        &heli_q8_d5p3_old_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_d5p3_old_M, _rt_error_message);
        return;
      }
    }

    if (heli_q8_d5p3_old_P.HILInitialize_set_pwm_outputs_o) {
      {
        int_T i1;
        real_T *dw_POValues = &heli_q8_d5p3_old_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = heli_q8_d5p3_old_P.HILInitialize_watchdog_pwm_outp;
        }
      }

      result = hil_watchdog_set_pwm_expiration_state
        (heli_q8_d5p3_old_DW.HILInitialize_Card,
         heli_q8_d5p3_old_P.HILInitialize_pwm_channels, 8U,
         &heli_q8_d5p3_old_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_d5p3_old_M, _rt_error_message);
        return;
      }
    }
  }

  /* Start for S-Function (hil_read_encoder_timebase_block): '<S2>/HIL Read Encoder Timebase' */

  /* S-Function Block: heli_q8_d5p3_old/Heli 3D/HIL Read Encoder Timebase (hil_read_encoder_timebase_block) */
  {
    t_error result;
    result = hil_task_create_encoder_reader
      (heli_q8_d5p3_old_DW.HILInitialize_Card,
       heli_q8_d5p3_old_P.HILReadEncoderTimebase_samples_,
       heli_q8_d5p3_old_P.HILReadEncoderTimebase_channels, 3,
       &heli_q8_d5p3_old_DW.HILReadEncoderTimebase_Task);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(heli_q8_d5p3_old_M, _rt_error_message);
    }
  }

  /* Start for Constant: '<S5>/A_d' */
  memcpy(&heli_q8_d5p3_old_B.A_d[0], &heli_q8_d5p3_old_P.A_d[0], 36U * sizeof
         (real_T));

  /* Start for Constant: '<S5>/B_d' */
  memcpy(&heli_q8_d5p3_old_B.B_d[0], &heli_q8_d5p3_old_P.B_d[0], 12U * sizeof
         (real_T));

  /* Start for Constant: '<S5>/Q_d' */
  memcpy(&heli_q8_d5p3_old_B.Q_d[0], &heli_q8_d5p3_old_P.Q_d[0], 36U * sizeof
         (real_T));

  /* Start for RateTransition: '<S4>/Rate Transition: x' */
  heli_q8_d5p3_old_B.RateTransitionx = heli_q8_d5p3_old_P.RateTransitionx_X0;

  /* Start for RateTransition: '<S4>/Rate Transition: y' */
  heli_q8_d5p3_old_B.RateTransitiony = heli_q8_d5p3_old_P.RateTransitiony_X0;

  /* Start for S-Function (stream_call_block): '<S9>/Stream Call1' */

  /* S-Function Block: heli_q8_d5p3_old/IMU System/IMU/Stream Call1 (stream_call_block) */
  {
    heli_q8_d5p3_old_DW.StreamCall1_State = STREAM_CALL_STATE_NOT_CONNECTED;
    heli_q8_d5p3_old_DW.StreamCall1_Stream = NULL;
  }

  /* Start for ToFile: '<Root>/noise to file' */
  {
    FILE *fp = (NULL);
    char fileName[509] = "noise.mat";
    if ((fp = fopen(fileName, "wb")) == (NULL)) {
      rtmSetErrorStatus(heli_q8_d5p3_old_M, "Error creating .mat file noise.mat");
      return;
    }

    if (rt_WriteMat4FileHeader(fp,6,0,"noise")) {
      rtmSetErrorStatus(heli_q8_d5p3_old_M,
                        "Error writing mat file header to file noise.mat");
      return;
    }

    heli_q8_d5p3_old_DW.noisetofile_IWORK.Count = 0;
    heli_q8_d5p3_old_DW.noisetofile_IWORK.Decimation = -1;
    heli_q8_d5p3_old_DW.noisetofile_PWORK.FilePtr = fp;
  }

  /* Start for S-Function (game_controller_block): '<S4>/Game Controller' */

  /* S-Function Block: heli_q8_d5p3_old/Joystick1/Game Controller (game_controller_block) */
  {
    if (heli_q8_d5p3_old_P.GameController_Enabled) {
      t_double deadzone[6];
      t_double saturation[6];
      t_int index;
      t_error result;
      for (index = 0; index < 6; index++) {
        deadzone[index] = -1;
      }

      for (index = 0; index < 6; index++) {
        saturation[index] = -1;
      }

      result = game_controller_open
        (heli_q8_d5p3_old_P.GameController_ControllerNumber,
         heli_q8_d5p3_old_P.GameController_BufferSize, deadzone, saturation,
         heli_q8_d5p3_old_P.GameController_AutoCenter, 0, 1.0,
         &heli_q8_d5p3_old_DW.GameController_Controller);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_d5p3_old_M, _rt_error_message);
      }
    }
  }

  {
    int32_T i;

    /* InitializeConditions for UnitDelay: '<S5>/Unit Delay1' */
    for (i = 0; i < 6; i++) {
      heli_q8_d5p3_old_DW.UnitDelay1_DSTATE[i] =
        heli_q8_d5p3_old_P.UnitDelay1_InitialCondition[i];
    }

    /* End of InitializeConditions for UnitDelay: '<S5>/Unit Delay1' */

    /* InitializeConditions for RateTransition: '<S4>/Rate Transition: x' */
    heli_q8_d5p3_old_DW.RateTransitionx_Buffer0 =
      heli_q8_d5p3_old_P.RateTransitionx_X0;

    /* InitializeConditions for RateTransition: '<S4>/Rate Transition: y' */
    heli_q8_d5p3_old_DW.RateTransitiony_Buffer0 =
      heli_q8_d5p3_old_P.RateTransitiony_X0;

    /* InitializeConditions for TransferFcn: '<S2>/Pitch: Transfer Fcn' */
    heli_q8_d5p3_old_X.PitchTransferFcn_CSTATE = 0.0;

    /* InitializeConditions for TransferFcn: '<S2>/Elevation: Transfer Fcn' */
    heli_q8_d5p3_old_X.ElevationTransferFcn_CSTATE = 0.0;

    /* InitializeConditions for Integrator: '<S6>/Integrate -> [gamma,zeta]' */
    heli_q8_d5p3_old_X.Integrategammazeta_CSTATE[0] =
      heli_q8_d5p3_old_P.Integrategammazeta_IC;
    heli_q8_d5p3_old_X.Integrategammazeta_CSTATE[1] =
      heli_q8_d5p3_old_P.Integrategammazeta_IC;

    /* InitializeConditions for UnitDelay: '<S5>/Unit Delay2' */
    memcpy(&heli_q8_d5p3_old_DW.UnitDelay2_DSTATE[0],
           &heli_q8_d5p3_old_P.UnitDelay2_InitialCondition[0], 36U * sizeof
           (real_T));

    /* InitializeConditions for TransferFcn: '<S2>/Travel: Transfer Fcn' */
    heli_q8_d5p3_old_X.TravelTransferFcn_CSTATE = 0.0;
  }
}

/* Model terminate function */
void heli_q8_d5p3_old_terminate(void)
{
  /* Terminate for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: heli_q8_d5p3_old/HIL Initialize (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    t_uint32 num_final_analog_outputs = 0;
    t_uint32 num_final_pwm_outputs = 0;
    hil_task_stop_all(heli_q8_d5p3_old_DW.HILInitialize_Card);
    hil_monitor_stop_all(heli_q8_d5p3_old_DW.HILInitialize_Card);
    is_switching = false;
    if ((heli_q8_d5p3_old_P.HILInitialize_set_analog_out_ex && !is_switching) ||
        (heli_q8_d5p3_old_P.HILInitialize_set_analog_outp_c && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOVoltages = &heli_q8_d5p3_old_DW.HILInitialize_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = heli_q8_d5p3_old_P.HILInitialize_final_analog_outp;
        }
      }

      num_final_analog_outputs = 8U;
    }

    if ((heli_q8_d5p3_old_P.HILInitialize_set_pwm_output_ap && !is_switching) ||
        (heli_q8_d5p3_old_P.HILInitialize_set_pwm_outputs_p && is_switching)) {
      {
        int_T i1;
        real_T *dw_POValues = &heli_q8_d5p3_old_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = heli_q8_d5p3_old_P.HILInitialize_final_pwm_outputs;
        }
      }

      num_final_pwm_outputs = 8U;
    }

    if (0
        || num_final_analog_outputs > 0
        || num_final_pwm_outputs > 0
        ) {
      /* Attempt to write the final outputs atomically (due to firmware issue in old Q2-USB). Otherwise write channels individually */
      result = hil_write(heli_q8_d5p3_old_DW.HILInitialize_Card
                         , heli_q8_d5p3_old_P.HILInitialize_analog_output_cha,
                         num_final_analog_outputs
                         , heli_q8_d5p3_old_P.HILInitialize_pwm_channels,
                         num_final_pwm_outputs
                         , NULL, 0
                         , NULL, 0
                         , &heli_q8_d5p3_old_DW.HILInitialize_AOVoltages[0]
                         , &heli_q8_d5p3_old_DW.HILInitialize_POValues[0]
                         , (t_boolean *) NULL
                         , NULL
                         );
      if (result == -QERR_HIL_WRITE_NOT_SUPPORTED) {
        t_error local_result;
        result = 0;

        /* The hil_write operation is not supported by this card. Write final outputs for each channel type */
        if (num_final_analog_outputs > 0) {
          local_result = hil_write_analog(heli_q8_d5p3_old_DW.HILInitialize_Card,
            heli_q8_d5p3_old_P.HILInitialize_analog_output_cha,
            num_final_analog_outputs,
            &heli_q8_d5p3_old_DW.HILInitialize_AOVoltages[0]);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (num_final_pwm_outputs > 0) {
          local_result = hil_write_pwm(heli_q8_d5p3_old_DW.HILInitialize_Card,
            heli_q8_d5p3_old_P.HILInitialize_pwm_channels, num_final_pwm_outputs,
            &heli_q8_d5p3_old_DW.HILInitialize_POValues[0]);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(heli_q8_d5p3_old_M, _rt_error_message);
        }
      }
    }

    hil_task_delete_all(heli_q8_d5p3_old_DW.HILInitialize_Card);
    hil_monitor_delete_all(heli_q8_d5p3_old_DW.HILInitialize_Card);
    hil_close(heli_q8_d5p3_old_DW.HILInitialize_Card);
    heli_q8_d5p3_old_DW.HILInitialize_Card = NULL;
  }

  /* Terminate for S-Function (stream_call_block): '<S9>/Stream Call1' */

  /* S-Function Block: heli_q8_d5p3_old/IMU System/IMU/Stream Call1 (stream_call_block) */
  {
    if (heli_q8_d5p3_old_DW.StreamCall1_Stream != NULL) {
      stream_close(heli_q8_d5p3_old_DW.StreamCall1_Stream);
      heli_q8_d5p3_old_DW.StreamCall1_Stream = NULL;
    }
  }

  /* Terminate for ToFile: '<Root>/noise to file' */
  {
    FILE *fp = (FILE *) heli_q8_d5p3_old_DW.noisetofile_PWORK.FilePtr;
    if (fp != (NULL)) {
      char fileName[509] = "noise.mat";
      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(heli_q8_d5p3_old_M, "Error closing MAT-file noise.mat");
        return;
      }

      if ((fp = fopen(fileName, "r+b")) == (NULL)) {
        rtmSetErrorStatus(heli_q8_d5p3_old_M,
                          "Error reopening MAT-file noise.mat");
        return;
      }

      if (rt_WriteMat4FileHeader(fp, 6,
           heli_q8_d5p3_old_DW.noisetofile_IWORK.Count, "noise")) {
        rtmSetErrorStatus(heli_q8_d5p3_old_M,
                          "Error writing header for noise to MAT-file noise.mat");
      }

      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(heli_q8_d5p3_old_M, "Error closing MAT-file noise.mat");
        return;
      }

      heli_q8_d5p3_old_DW.noisetofile_PWORK.FilePtr = (NULL);
    }
  }

  /* Terminate for S-Function (game_controller_block): '<S4>/Game Controller' */

  /* S-Function Block: heli_q8_d5p3_old/Joystick1/Game Controller (game_controller_block) */
  {
    if (heli_q8_d5p3_old_P.GameController_Enabled) {
      game_controller_close(heli_q8_d5p3_old_DW.GameController_Controller);
      heli_q8_d5p3_old_DW.GameController_Controller = NULL;
    }
  }
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/

/* Solver interface called by GRT_Main */
#ifndef USE_GENERATED_SOLVER

void rt_ODECreateIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEDestroyIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEUpdateContinuousStates(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

#endif

void MdlOutputs(int_T tid)
{
  if (tid == 1)
    tid = 0;
  heli_q8_d5p3_old_output(tid);
}

void MdlUpdate(int_T tid)
{
  if (tid == 1)
    tid = 0;
  heli_q8_d5p3_old_update(tid);
}

void MdlInitializeSizes(void)
{
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
}

void MdlStart(void)
{
  heli_q8_d5p3_old_initialize();
}

void MdlTerminate(void)
{
  heli_q8_d5p3_old_terminate();
}

/* Registration function */
RT_MODEL_heli_q8_d5p3_old_T *heli_q8_d5p3_old(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* non-finite (run-time) assignments */
  heli_q8_d5p3_old_P.Constant2_Value = rtNaN;

  /* initialize real-time model */
  (void) memset((void *)heli_q8_d5p3_old_M, 0,
                sizeof(RT_MODEL_heli_q8_d5p3_old_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&heli_q8_d5p3_old_M->solverInfo,
                          &heli_q8_d5p3_old_M->Timing.simTimeStep);
    rtsiSetTPtr(&heli_q8_d5p3_old_M->solverInfo, &rtmGetTPtr(heli_q8_d5p3_old_M));
    rtsiSetStepSizePtr(&heli_q8_d5p3_old_M->solverInfo,
                       &heli_q8_d5p3_old_M->Timing.stepSize0);
    rtsiSetdXPtr(&heli_q8_d5p3_old_M->solverInfo,
                 &heli_q8_d5p3_old_M->ModelData.derivs);
    rtsiSetContStatesPtr(&heli_q8_d5p3_old_M->solverInfo, (real_T **)
                         &heli_q8_d5p3_old_M->ModelData.contStates);
    rtsiSetNumContStatesPtr(&heli_q8_d5p3_old_M->solverInfo,
      &heli_q8_d5p3_old_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&heli_q8_d5p3_old_M->solverInfo,
      &heli_q8_d5p3_old_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&heli_q8_d5p3_old_M->solverInfo,
      &heli_q8_d5p3_old_M->ModelData.periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&heli_q8_d5p3_old_M->solverInfo,
      &heli_q8_d5p3_old_M->ModelData.periodicContStateRanges);
    rtsiSetErrorStatusPtr(&heli_q8_d5p3_old_M->solverInfo, (&rtmGetErrorStatus
      (heli_q8_d5p3_old_M)));
    rtsiSetRTModelPtr(&heli_q8_d5p3_old_M->solverInfo, heli_q8_d5p3_old_M);
  }

  rtsiSetSimTimeStep(&heli_q8_d5p3_old_M->solverInfo, MAJOR_TIME_STEP);
  heli_q8_d5p3_old_M->ModelData.intgData.f[0] =
    heli_q8_d5p3_old_M->ModelData.odeF[0];
  heli_q8_d5p3_old_M->ModelData.contStates = ((real_T *) &heli_q8_d5p3_old_X);
  rtsiSetSolverData(&heli_q8_d5p3_old_M->solverInfo, (void *)
                    &heli_q8_d5p3_old_M->ModelData.intgData);
  rtsiSetSolverName(&heli_q8_d5p3_old_M->solverInfo,"ode1");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = heli_q8_d5p3_old_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    mdlTsMap[2] = 2;
    heli_q8_d5p3_old_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    heli_q8_d5p3_old_M->Timing.sampleTimes =
      (&heli_q8_d5p3_old_M->Timing.sampleTimesArray[0]);
    heli_q8_d5p3_old_M->Timing.offsetTimes =
      (&heli_q8_d5p3_old_M->Timing.offsetTimesArray[0]);

    /* task periods */
    heli_q8_d5p3_old_M->Timing.sampleTimes[0] = (0.0);
    heli_q8_d5p3_old_M->Timing.sampleTimes[1] = (0.002);
    heli_q8_d5p3_old_M->Timing.sampleTimes[2] = (0.01);

    /* task offsets */
    heli_q8_d5p3_old_M->Timing.offsetTimes[0] = (0.0);
    heli_q8_d5p3_old_M->Timing.offsetTimes[1] = (0.0);
    heli_q8_d5p3_old_M->Timing.offsetTimes[2] = (0.0);
  }

  rtmSetTPtr(heli_q8_d5p3_old_M, &heli_q8_d5p3_old_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = heli_q8_d5p3_old_M->Timing.sampleHitArray;
    int_T *mdlPerTaskSampleHits =
      heli_q8_d5p3_old_M->Timing.perTaskSampleHitsArray;
    heli_q8_d5p3_old_M->Timing.perTaskSampleHits = (&mdlPerTaskSampleHits[0]);
    mdlSampleHits[0] = 1;
    heli_q8_d5p3_old_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(heli_q8_d5p3_old_M, -1);
  heli_q8_d5p3_old_M->Timing.stepSize0 = 0.002;
  heli_q8_d5p3_old_M->Timing.stepSize1 = 0.002;
  heli_q8_d5p3_old_M->Timing.stepSize2 = 0.01;

  /* External mode info */
  heli_q8_d5p3_old_M->Sizes.checksums[0] = (2849901800U);
  heli_q8_d5p3_old_M->Sizes.checksums[1] = (140512230U);
  heli_q8_d5p3_old_M->Sizes.checksums[2] = (3112153293U);
  heli_q8_d5p3_old_M->Sizes.checksums[3] = (2152022075U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[5];
    heli_q8_d5p3_old_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(heli_q8_d5p3_old_M->extModeInfo,
      &heli_q8_d5p3_old_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(heli_q8_d5p3_old_M->extModeInfo,
                        heli_q8_d5p3_old_M->Sizes.checksums);
    rteiSetTPtr(heli_q8_d5p3_old_M->extModeInfo, rtmGetTPtr(heli_q8_d5p3_old_M));
  }

  heli_q8_d5p3_old_M->solverInfoPtr = (&heli_q8_d5p3_old_M->solverInfo);
  heli_q8_d5p3_old_M->Timing.stepSize = (0.002);
  rtsiSetFixedStepSize(&heli_q8_d5p3_old_M->solverInfo, 0.002);
  rtsiSetSolverMode(&heli_q8_d5p3_old_M->solverInfo, SOLVER_MODE_MULTITASKING);

  /* block I/O */
  heli_q8_d5p3_old_M->ModelData.blockIO = ((void *) &heli_q8_d5p3_old_B);
  (void) memset(((void *) &heli_q8_d5p3_old_B), 0,
                sizeof(B_heli_q8_d5p3_old_T));

  {
    int32_T i;
    for (i = 0; i < 6; i++) {
      heli_q8_d5p3_old_B.UnitDelay1[i] = 0.0;
    }

    for (i = 0; i < 36; i++) {
      heli_q8_d5p3_old_B.A_d[i] = 0.0;
    }

    for (i = 0; i < 12; i++) {
      heli_q8_d5p3_old_B.B_d[i] = 0.0;
    }

    for (i = 0; i < 36; i++) {
      heli_q8_d5p3_old_B.Q_d[i] = 0.0;
    }

    for (i = 0; i < 36; i++) {
      heli_q8_d5p3_old_B.UnitDelay2[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      heli_q8_d5p3_old_B.x_k2[i] = 0.0;
    }

    for (i = 0; i < 36; i++) {
      heli_q8_d5p3_old_B.P_k2[i] = 0.0;
    }

    heli_q8_d5p3_old_B.RateTransitionx = 0.0;
    heli_q8_d5p3_old_B.Joystick_gain_x = 0.0;
    heli_q8_d5p3_old_B.RateTransitiony = 0.0;
    heli_q8_d5p3_old_B.Joystick_gain_y = 0.0;
    heli_q8_d5p3_old_B.Fr[0] = 0.0;
    heli_q8_d5p3_old_B.Fr[1] = 0.0;
    heli_q8_d5p3_old_B.Sum1 = 0.0;
    heli_q8_d5p3_old_B.PitchTransferFcn = 0.0;
    heli_q8_d5p3_old_B.Sum2 = 0.0;
    heli_q8_d5p3_old_B.ElevationTransferFcn = 0.0;
    heli_q8_d5p3_old_B.TravelCounttorad = 0.0;
    heli_q8_d5p3_old_B.TravelTransferFcn = 0.0;
    heli_q8_d5p3_old_B.Gain2[0] = 0.0;
    heli_q8_d5p3_old_B.Gain2[1] = 0.0;
    heli_q8_d5p3_old_B.Gain2[2] = 0.0;
    heli_q8_d5p3_old_B.TrigonometricFunction1 = 0.0;
    heli_q8_d5p3_old_B.TrigonometricFunction = 0.0;
    heli_q8_d5p3_old_B.V_s0[0] = 0.0;
    heli_q8_d5p3_old_B.V_s0[1] = 0.0;
    heli_q8_d5p3_old_B.Sum1_e[0] = 0.0;
    heli_q8_d5p3_old_B.Sum1_e[1] = 0.0;
    heli_q8_d5p3_old_B.FrontmotorSaturation = 0.0;
    heli_q8_d5p3_old_B.BackmotorSaturation = 0.0;
    heli_q8_d5p3_old_B.GameController_o4 = 0.0;
    heli_q8_d5p3_old_B.GameController_o5 = 0.0;
    heli_q8_d5p3_old_B.Sum3[0] = 0.0;
    heli_q8_d5p3_old_B.Sum3[1] = 0.0;
    heli_q8_d5p3_old_B.euler_rates[0] = 0.0;
    heli_q8_d5p3_old_B.euler_rates[1] = 0.0;
    heli_q8_d5p3_old_B.euler_rates[2] = 0.0;
  }

  /* parameters */
  heli_q8_d5p3_old_M->ModelData.defaultParam = ((real_T *)&heli_q8_d5p3_old_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &heli_q8_d5p3_old_X;
    heli_q8_d5p3_old_M->ModelData.contStates = (x);
    (void) memset((void *)&heli_q8_d5p3_old_X, 0,
                  sizeof(X_heli_q8_d5p3_old_T));
  }

  /* states (dwork) */
  heli_q8_d5p3_old_M->ModelData.dwork = ((void *) &heli_q8_d5p3_old_DW);
  (void) memset((void *)&heli_q8_d5p3_old_DW, 0,
                sizeof(DW_heli_q8_d5p3_old_T));

  {
    int32_T i;
    for (i = 0; i < 6; i++) {
      heli_q8_d5p3_old_DW.UnitDelay1_DSTATE[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 36; i++) {
      heli_q8_d5p3_old_DW.UnitDelay2_DSTATE[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      heli_q8_d5p3_old_DW.HILInitialize_AIMinimums[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      heli_q8_d5p3_old_DW.HILInitialize_AIMaximums[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      heli_q8_d5p3_old_DW.HILInitialize_AOMinimums[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      heli_q8_d5p3_old_DW.HILInitialize_AOMaximums[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      heli_q8_d5p3_old_DW.HILInitialize_AOVoltages[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      heli_q8_d5p3_old_DW.HILInitialize_FilterFrequency[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      heli_q8_d5p3_old_DW.HILInitialize_POSortedFreqs[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      heli_q8_d5p3_old_DW.HILInitialize_POValues[i] = 0.0;
    }
  }

  heli_q8_d5p3_old_DW.RateTransitionx_Buffer0 = 0.0;
  heli_q8_d5p3_old_DW.RateTransitiony_Buffer0 = 0.0;
  heli_q8_d5p3_old_DW.HILWriteAnalog_Buffer[0] = 0.0;
  heli_q8_d5p3_old_DW.HILWriteAnalog_Buffer[1] = 0.0;

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    heli_q8_d5p3_old_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 25;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.B = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.P = &rtPTransTable;
  }

  /* Initialize Sizes */
  heli_q8_d5p3_old_M->Sizes.numContStates = (5);/* Number of continuous states */
  heli_q8_d5p3_old_M->Sizes.numPeriodicContStates = (0);/* Number of periodic continuous states */
  heli_q8_d5p3_old_M->Sizes.numY = (0);/* Number of model outputs */
  heli_q8_d5p3_old_M->Sizes.numU = (0);/* Number of model inputs */
  heli_q8_d5p3_old_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  heli_q8_d5p3_old_M->Sizes.numSampTimes = (3);/* Number of sample times */
  heli_q8_d5p3_old_M->Sizes.numBlocks = (98);/* Number of blocks */
  heli_q8_d5p3_old_M->Sizes.numBlockIO = (30);/* Number of block outputs */
  heli_q8_d5p3_old_M->Sizes.numBlockPrms = (562);/* Sum of parameter "widths" */
  return heli_q8_d5p3_old_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
