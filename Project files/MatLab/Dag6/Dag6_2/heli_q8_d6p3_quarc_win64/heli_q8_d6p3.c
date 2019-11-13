/*
 * heli_q8_d6p3.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "heli_q8_d6p3".
 *
 * Model version              : 1.125
 * Simulink Coder version : 8.9 (R2015b) 13-Aug-2015
 * C source code generated on : Fri Nov 08 19:30:34 2019
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "heli_q8_d6p3.h"
#include "heli_q8_d6p3_private.h"
#include "heli_q8_d6p3_dt.h"

t_stream heli_q8_d6p3_rtZt_stream = NULL;

/* Block signals (auto storage) */
B_heli_q8_d6p3_T heli_q8_d6p3_B;

/* Continuous states */
X_heli_q8_d6p3_T heli_q8_d6p3_X;

/* Block states (auto storage) */
DW_heli_q8_d6p3_T heli_q8_d6p3_DW;

/* Real-time model */
RT_MODEL_heli_q8_d6p3_T heli_q8_d6p3_M_;
RT_MODEL_heli_q8_d6p3_T *const heli_q8_d6p3_M = &heli_q8_d6p3_M_;

/* Forward declaration for local functions */
static void heli_q8_d6p3_invNxN(const real_T x[25], real_T y[25]);
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
  rtmSampleHitPtr[1] = rtmStepTask(heli_q8_d6p3_M, 1);
  rtmSampleHitPtr[2] = rtmStepTask(heli_q8_d6p3_M, 2);
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
  if (heli_q8_d6p3_M->Timing.TaskCounters.TID[1] == 0) {
    heli_q8_d6p3_M->Timing.RateInteraction.TID1_2 =
      (heli_q8_d6p3_M->Timing.TaskCounters.TID[2] == 0);

    /* update PerTaskSampleHits matrix for non-inline sfcn */
    heli_q8_d6p3_M->Timing.perTaskSampleHits[5] =
      heli_q8_d6p3_M->Timing.RateInteraction.TID1_2;
  }

  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (heli_q8_d6p3_M->Timing.TaskCounters.TID[2])++;
  if ((heli_q8_d6p3_M->Timing.TaskCounters.TID[2]) > 4) {/* Sample time: [0.01s, 0.0s] */
    heli_q8_d6p3_M->Timing.TaskCounters.TID[2] = 0;
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
  heli_q8_d6p3_derivatives();
  rtsiSetT(si, tnew);
  for (i = 0; i < nXc; ++i) {
    x[i] += h * f0[i];
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Function for MATLAB Function: '<Root>/Estimator' */
static void heli_q8_d6p3_invNxN(const real_T x[25], real_T y[25])
{
  int8_T p[5];
  real_T A[25];
  int8_T ipiv[5];
  int32_T b_j;
  real_T smax;
  real_T s;
  int32_T iy;
  int32_T c_ix;
  int32_T d;
  int32_T ijA;
  int32_T jBcol;
  int32_T kAcol;
  int32_T c_i;
  for (b_j = 0; b_j < 25; b_j++) {
    y[b_j] = 0.0;
    A[b_j] = x[b_j];
  }

  for (b_j = 0; b_j < 5; b_j++) {
    ipiv[b_j] = (int8_T)(1 + b_j);
  }

  for (b_j = 0; b_j < 4; b_j++) {
    jBcol = b_j * 6;
    iy = 0;
    kAcol = jBcol;
    smax = fabs(A[jBcol]);
    for (c_i = 2; c_i <= 5 - b_j; c_i++) {
      kAcol++;
      s = fabs(A[kAcol]);
      if (s > smax) {
        iy = c_i - 1;
        smax = s;
      }
    }

    if (A[jBcol + iy] != 0.0) {
      if (iy != 0) {
        ipiv[b_j] = (int8_T)((b_j + iy) + 1);
        kAcol = b_j;
        iy += b_j;
        for (c_i = 0; c_i < 5; c_i++) {
          smax = A[kAcol];
          A[kAcol] = A[iy];
          A[iy] = smax;
          kAcol += 5;
          iy += 5;
        }
      }

      iy = (jBcol - b_j) + 5;
      for (kAcol = jBcol + 1; kAcol + 1 <= iy; kAcol++) {
        A[kAcol] /= A[jBcol];
      }
    }

    iy = jBcol;
    kAcol = jBcol + 5;
    for (c_i = 1; c_i <= 4 - b_j; c_i++) {
      smax = A[kAcol];
      if (A[kAcol] != 0.0) {
        c_ix = jBcol + 1;
        d = (iy - b_j) + 10;
        for (ijA = 6 + iy; ijA + 1 <= d; ijA++) {
          A[ijA] += A[c_ix] * -smax;
          c_ix++;
        }
      }

      kAcol += 5;
      iy += 5;
    }
  }

  for (b_j = 0; b_j < 5; b_j++) {
    p[b_j] = (int8_T)(1 + b_j);
  }

  if (ipiv[0] > 1) {
    jBcol = p[ipiv[0] - 1];
    p[ipiv[0] - 1] = p[0];
    p[0] = (int8_T)jBcol;
  }

  if (ipiv[1] > 2) {
    jBcol = p[ipiv[1] - 1];
    p[ipiv[1] - 1] = p[1];
    p[1] = (int8_T)jBcol;
  }

  if (ipiv[2] > 3) {
    jBcol = p[ipiv[2] - 1];
    p[ipiv[2] - 1] = p[2];
    p[2] = (int8_T)jBcol;
  }

  if (ipiv[3] > 4) {
    jBcol = p[ipiv[3] - 1];
    p[ipiv[3] - 1] = p[3];
    p[3] = (int8_T)jBcol;
  }

  for (b_j = 0; b_j < 5; b_j++) {
    jBcol = p[b_j] - 1;
    y[b_j + 5 * (p[b_j] - 1)] = 1.0;
    for (iy = b_j; iy + 1 < 6; iy++) {
      if (y[5 * jBcol + iy] != 0.0) {
        for (kAcol = iy + 1; kAcol + 1 < 6; kAcol++) {
          y[kAcol + 5 * jBcol] -= y[5 * jBcol + iy] * A[5 * iy + kAcol];
        }
      }
    }
  }

  for (b_j = 0; b_j < 5; b_j++) {
    jBcol = 5 * b_j;
    for (iy = 4; iy >= 0; iy += -1) {
      kAcol = 5 * iy;
      if (y[iy + jBcol] != 0.0) {
        y[iy + jBcol] /= A[iy + kAcol];
        for (c_i = 0; c_i + 1 <= iy; c_i++) {
          y[c_i + jBcol] -= y[iy + jBcol] * A[c_i + kAcol];
        }
      }
    }
  }
}

/* Model output function for TID0 */
void heli_q8_d6p3_output0(void)        /* Sample time: [0.0s, 0.0s] */
{
  /* local block i/o variables */
  real_T rtb_HILReadEncoderTimebase_o1;
  real_T rtb_HILReadEncoderTimebase_o2;
  real_T rtb_HILReadEncoderTimebase_o3;
  real_T rtb_TmpSignalConversionAtEstima[12];
  real_T rtb_TmpSignalConversionAty_IMUI[5];
  t_stream_ptr rtb_StreamCall1_o1;
  t_stream_ptr rtb_StreamFormattedWrite_o1;
  real32_T rtb_StreamRead1_o2[10];
  int32_T rtb_StreamFormattedWrite_o2;
  int32_T rtb_StreamCall1_o3;
  int32_T rtb_StreamRead1_o5;
  real_T K[30];
  real_T x_hat[6];
  real_T P_hat[36];
  static const int8_T I[36] = { 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0,
    0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1 };

  real_T rtb_Switch[10];
  real_T rtb_TmpSignalConversionAtSFunct[3];
  int32_T i;
  real_T tmp[25];
  real_T tmp_0[25];
  real_T tmp_1[5];
  real_T tmp_2[9];
  real_T tmp_3[3];
  real_T tmp_4[5];
  real_T I_0[6];
  real_T K_0[6];
  real_T I_1[36];
  real_T I_2[36];
  real_T K_1[30];
  real_T K_2[36];
  int32_T i_0;
  int32_T i_1;
  real_T u0;
  if (rtmIsMajorTimeStep(heli_q8_d6p3_M)) {
    /* set solver stop time */
    if (!(heli_q8_d6p3_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&heli_q8_d6p3_M->solverInfo,
                            ((heli_q8_d6p3_M->Timing.clockTickH0 + 1) *
        heli_q8_d6p3_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&heli_q8_d6p3_M->solverInfo,
                            ((heli_q8_d6p3_M->Timing.clockTick0 + 1) *
        heli_q8_d6p3_M->Timing.stepSize0 + heli_q8_d6p3_M->Timing.clockTickH0 *
        heli_q8_d6p3_M->Timing.stepSize0 * 4294967296.0));
    }

    {                                  /* Sample time: [0.0s, 0.0s] */
      rate_monotonic_scheduler();
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(heli_q8_d6p3_M)) {
    heli_q8_d6p3_M->Timing.t[0] = rtsiGetT(&heli_q8_d6p3_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(heli_q8_d6p3_M)) {
    /* S-Function (hil_read_encoder_timebase_block): '<S4>/HIL Read Encoder Timebase' */

    /* S-Function Block: heli_q8_d6p3/Heli 3D/HIL Read Encoder Timebase (hil_read_encoder_timebase_block) */
    {
      t_error result;
      result = hil_task_read_encoder(heli_q8_d6p3_DW.HILReadEncoderTimebase_Task,
        1, &heli_q8_d6p3_DW.HILReadEncoderTimebase_Buffer[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_d6p3_M, _rt_error_message);
      } else {
        rtb_HILReadEncoderTimebase_o1 =
          heli_q8_d6p3_DW.HILReadEncoderTimebase_Buffer[0];
        rtb_HILReadEncoderTimebase_o2 =
          heli_q8_d6p3_DW.HILReadEncoderTimebase_Buffer[1];
        rtb_HILReadEncoderTimebase_o3 =
          heli_q8_d6p3_DW.HILReadEncoderTimebase_Buffer[2];
      }
    }

    /* Constant: '<Root>/A_d' */
    memcpy(&heli_q8_d6p3_B.A_d[0], &heli_q8_d6p3_P.A_d[0], 36U * sizeof(real_T));

    /* UnitDelay: '<Root>/Unit Delay' */
    for (i = 0; i < 6; i++) {
      heli_q8_d6p3_B.UnitDelay[i] = heli_q8_d6p3_DW.UnitDelay_DSTATE[i];
    }

    /* End of UnitDelay: '<Root>/Unit Delay' */

    /* Constant: '<Root>/B_d' */
    memcpy(&heli_q8_d6p3_B.B_d[0], &heli_q8_d6p3_P.B_d[0], 12U * sizeof(real_T));

    /* RateTransition: '<S6>/Rate Transition: x' */
    if (heli_q8_d6p3_M->Timing.RateInteraction.TID1_2) {
      heli_q8_d6p3_B.RateTransitionx = heli_q8_d6p3_DW.RateTransitionx_Buffer0;
    }

    /* End of RateTransition: '<S6>/Rate Transition: x' */

    /* DeadZone: '<S6>/Dead Zone: x' */
    if (heli_q8_d6p3_B.RateTransitionx > heli_q8_d6p3_P.DeadZonex_End) {
      u0 = heli_q8_d6p3_B.RateTransitionx - heli_q8_d6p3_P.DeadZonex_End;
    } else if (heli_q8_d6p3_B.RateTransitionx >= heli_q8_d6p3_P.DeadZonex_Start)
    {
      u0 = 0.0;
    } else {
      u0 = heli_q8_d6p3_B.RateTransitionx - heli_q8_d6p3_P.DeadZonex_Start;
    }

    /* End of DeadZone: '<S6>/Dead Zone: x' */

    /* Gain: '<S6>/Joystick_gain_x' incorporates:
     *  Gain: '<S6>/Gain: x'
     */
    heli_q8_d6p3_B.Joystick_gain_x = heli_q8_d6p3_P.Gainx_Gain * u0 *
      heli_q8_d6p3_P.Joystick_gain_x;

    /* RateTransition: '<S6>/Rate Transition: y' */
    if (heli_q8_d6p3_M->Timing.RateInteraction.TID1_2) {
      heli_q8_d6p3_B.RateTransitiony = heli_q8_d6p3_DW.RateTransitiony_Buffer0;
    }

    /* End of RateTransition: '<S6>/Rate Transition: y' */

    /* DeadZone: '<S6>/Dead Zone: y' */
    if (heli_q8_d6p3_B.RateTransitiony > heli_q8_d6p3_P.DeadZoney_End) {
      u0 = heli_q8_d6p3_B.RateTransitiony - heli_q8_d6p3_P.DeadZoney_End;
    } else if (heli_q8_d6p3_B.RateTransitiony >= heli_q8_d6p3_P.DeadZoney_Start)
    {
      u0 = 0.0;
    } else {
      u0 = heli_q8_d6p3_B.RateTransitiony - heli_q8_d6p3_P.DeadZoney_Start;
    }

    /* End of DeadZone: '<S6>/Dead Zone: y' */

    /* Gain: '<S6>/Joystick_gain_y' incorporates:
     *  Gain: '<S6>/Gain: y'
     */
    heli_q8_d6p3_B.Joystick_gain_y = heli_q8_d6p3_P.Gainy_Gain * u0 *
      heli_q8_d6p3_P.Joystick_gain_y;

    /* Gain: '<S10>/F*r' incorporates:
     *  SignalConversion: '<S10>/TmpSignal ConversionAtF*rInport1'
     */
    heli_q8_d6p3_B.Fr[0] = 0.0;
    heli_q8_d6p3_B.Fr[0] += heli_q8_d6p3_P.F[0] * heli_q8_d6p3_B.Joystick_gain_x;
    heli_q8_d6p3_B.Fr[0] += heli_q8_d6p3_P.F[2] * heli_q8_d6p3_B.Joystick_gain_y;
    heli_q8_d6p3_B.Fr[1] = 0.0;
    heli_q8_d6p3_B.Fr[1] += heli_q8_d6p3_P.F[1] * heli_q8_d6p3_B.Joystick_gain_x;
    heli_q8_d6p3_B.Fr[1] += heli_q8_d6p3_P.F[3] * heli_q8_d6p3_B.Joystick_gain_y;

    /* Sum: '<S4>/Sum1' incorporates:
     *  Constant: '<S4>/00'
     *  Gain: '<S4>/Pitch: Count to rad'
     */
    heli_q8_d6p3_B.Sum1 = heli_q8_d6p3_P.PitchCounttorad_Gain *
      rtb_HILReadEncoderTimebase_o2 + heli_q8_d6p3_P.u0_Value;

    /* Sum: '<S4>/Sum2' incorporates:
     *  Constant: '<S4>/0'
     *  Gain: '<S4>/Elevation: Count to rad'
     */
    heli_q8_d6p3_B.Sum2 = heli_q8_d6p3_P.ElevationCounttorad_Gain *
      rtb_HILReadEncoderTimebase_o3 + heli_q8_d6p3_P.u_Value;
  }

  /* TransferFcn: '<S4>/Pitch: Transfer Fcn' */
  heli_q8_d6p3_B.PitchTransferFcn = 0.0;
  heli_q8_d6p3_B.PitchTransferFcn += heli_q8_d6p3_P.PitchTransferFcn_C *
    heli_q8_d6p3_X.PitchTransferFcn_CSTATE;
  heli_q8_d6p3_B.PitchTransferFcn += heli_q8_d6p3_P.PitchTransferFcn_D *
    heli_q8_d6p3_B.Sum1;

  /* TransferFcn: '<S4>/Elevation: Transfer Fcn' */
  heli_q8_d6p3_B.ElevationTransferFcn = 0.0;
  heli_q8_d6p3_B.ElevationTransferFcn += heli_q8_d6p3_P.ElevationTransferFcn_C *
    heli_q8_d6p3_X.ElevationTransferFcn_CSTATE;
  heli_q8_d6p3_B.ElevationTransferFcn += heli_q8_d6p3_P.ElevationTransferFcn_D *
    heli_q8_d6p3_B.Sum2;
  if (rtmIsMajorTimeStep(heli_q8_d6p3_M)) {
    /* Constant: '<S9>/0' */
    heli_q8_d6p3_B.u = heli_q8_d6p3_P.u_Value_g;

    /* Constant: '<S9>/1' */
    heli_q8_d6p3_B.u_o = heli_q8_d6p3_P.u_Value_d;
  }

  /* SignalConversion: '<S10>/TmpSignal ConversionAtK*xInport1' */
  tmp_1[0] = heli_q8_d6p3_B.Sum1;
  tmp_1[1] = heli_q8_d6p3_B.PitchTransferFcn;
  tmp_1[2] = heli_q8_d6p3_B.ElevationTransferFcn;

  /* ManualSwitch: '<S9>/..' */
  if (heli_q8_d6p3_P._CurrentSetting == 1) {
    /* SignalConversion: '<S10>/TmpSignal ConversionAtK*xInport1' */
    tmp_1[3] = heli_q8_d6p3_B.u;
  } else {
    /* SignalConversion: '<S10>/TmpSignal ConversionAtK*xInport1' incorporates:
     *  Integrator: '<S11>/Integrator'
     */
    tmp_1[3] = heli_q8_d6p3_X.Integrator_CSTATE[0];
  }

  /* End of ManualSwitch: '<S9>/..' */

  /* ManualSwitch: '<S9>/.' */
  if (heli_q8_d6p3_P._CurrentSetting_a == 1) {
    /* SignalConversion: '<S10>/TmpSignal ConversionAtK*xInport1' */
    tmp_1[4] = heli_q8_d6p3_B.u_o;
  } else {
    /* SignalConversion: '<S10>/TmpSignal ConversionAtK*xInport1' incorporates:
     *  Integrator: '<S11>/Integrator'
     */
    tmp_1[4] = heli_q8_d6p3_X.Integrator_CSTATE[1];
  }

  /* End of ManualSwitch: '<S9>/.' */

  /* Sum: '<S10>/Sum3' incorporates:
   *  Gain: '<S10>/K*x'
   */
  for (i = 0; i < 2; i++) {
    u0 = 0.0;
    for (i_0 = 0; i_0 < 5; i_0++) {
      u0 += heli_q8_d6p3_P.K_x[(i_0 << 1) + i] * tmp_1[i_0];
    }

    heli_q8_d6p3_B.Sum3[i] = heli_q8_d6p3_B.Fr[i] - u0;
  }

  /* End of Sum: '<S10>/Sum3' */
  if (rtmIsMajorTimeStep(heli_q8_d6p3_M)) {
    /* Constant: '<Root>/C_d' */
    memcpy(&heli_q8_d6p3_B.C_d[0], &heli_q8_d6p3_P.C_d[0], 30U * sizeof(real_T));

    /* S-Function (stream_call_block): '<S5>/Stream Call1' */

    /* S-Function Block: heli_q8_d6p3/IMU/Stream Call1 (stream_call_block) */
    {
      t_error result = 0;
      t_boolean close_flag = (heli_q8_d6p3_P.Constant_Value != 0);
      rtb_StreamCall1_o1 = NULL;
      switch (heli_q8_d6p3_DW.StreamCall1_State) {
       case STREAM_CALL_STATE_NOT_CONNECTED:
        {
          if (!close_flag) {
            /* Make sure URI is null-terminated */
            if (string_length((char *) heli_q8_d6p3_P.StringConstant_Value, 255)
                == 255) {
              rtmSetErrorStatus(heli_q8_d6p3_M,
                                "URI passed to Stream Call block is not null-terminated!");
              result = -QERR_STRING_NOT_TERMINATED;
            } else {
              result = stream_connect((char *)
                heli_q8_d6p3_P.StringConstant_Value, true,
                heli_q8_d6p3_P.StreamCall1_SendBufferSize,
                heli_q8_d6p3_P.StreamCall1_ReceiveBufferSize,
                &heli_q8_d6p3_DW.StreamCall1_Stream);
              if (result == 0) {
                heli_q8_d6p3_DW.StreamCall1_State = STREAM_CALL_STATE_CONNECTED;
                stream_set_byte_order(heli_q8_d6p3_DW.StreamCall1_Stream,
                                      (t_stream_byte_order)
                                      heli_q8_d6p3_P.StreamCall1_Endian);
                rtb_StreamCall1_o1 = &heli_q8_d6p3_DW.StreamCall1_Stream;
              } else if (result == -QERR_WOULD_BLOCK) {
                heli_q8_d6p3_DW.StreamCall1_State = STREAM_CALL_STATE_CONNECTING;
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

            result = stream_poll(heli_q8_d6p3_DW.StreamCall1_Stream, &timeout,
                                 STREAM_POLL_CONNECT);
            if (result > 0) {
              heli_q8_d6p3_DW.StreamCall1_State = STREAM_CALL_STATE_CONNECTED;
              stream_set_byte_order(heli_q8_d6p3_DW.StreamCall1_Stream,
                                    (t_stream_byte_order)
                                    heli_q8_d6p3_P.StreamCall1_Endian);
              rtb_StreamCall1_o1 = &heli_q8_d6p3_DW.StreamCall1_Stream;
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
          rtb_StreamCall1_o1 = &heli_q8_d6p3_DW.StreamCall1_Stream;
          if (!close_flag) {
            break;
          }

          /* Fall through deliberately */
        }

       default:
        {
          t_error close_result = stream_close(heli_q8_d6p3_DW.StreamCall1_Stream);
          if (close_result == 0) {
            heli_q8_d6p3_DW.StreamCall1_State = STREAM_CALL_STATE_NOT_CONNECTED;
            heli_q8_d6p3_DW.StreamCall1_Stream = NULL;
            rtb_StreamCall1_o1 = NULL;
          } else if (result == 0) {
            result = close_result;
          }
          break;
        }
      }

      heli_q8_d6p3_B.StreamCall1_o2 = heli_q8_d6p3_DW.StreamCall1_State;
      rtb_StreamCall1_o3 = (int32_T) result;
    }

    /* S-Function (stream_formatted_write_block): '<S5>/Stream Formatted Write' */
    {
      t_error result;
      if (rtb_StreamCall1_o1 != NULL) {
        result = stream_print_utf8_char_array(*rtb_StreamCall1_o1,
          heli_q8_d6p3_P.StreamFormattedWrite_MaxUnits,
          &rtb_StreamFormattedWrite_o2, "%c\n"
          , (char) heli_q8_d6p3_P.Constant1_Value
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

    /* S-Function (stream_read_block): '<S5>/Stream Read1' */
    /* S-Function Block: heli_q8_d6p3/IMU/Stream Read1 (stream_read_block) */
    {
      t_error result;
      memset(&rtb_StreamRead1_o2[0], 0, 10 * sizeof(real32_T));
      if (rtb_StreamFormattedWrite_o1 != NULL) {
        result = stream_receive_unit_array(*rtb_StreamFormattedWrite_o1,
          &rtb_StreamRead1_o2[0], sizeof(real32_T), 10);
        heli_q8_d6p3_B.StreamRead1_o3 = (result > 0);
        if (result > 0 || result == -QERR_WOULD_BLOCK) {
          result = 0;
        }
      } else {
        heli_q8_d6p3_B.StreamRead1_o3 = false;
        result = 0;
      }

      rtb_StreamRead1_o5 = (int32_T) result;
    }

    /* Switch: '<S5>/Switch' incorporates:
     *  Constant: '<S5>/Constant2'
     *  DataTypeConversion: '<S5>/Data Type Conversion'
     */
    for (i = 0; i < 10; i++) {
      if (heli_q8_d6p3_B.StreamRead1_o3) {
        rtb_Switch[i] = rtb_StreamRead1_o2[i];
      } else {
        rtb_Switch[i] = heli_q8_d6p3_P.Constant2_Value;
      }
    }

    /* End of Switch: '<S5>/Switch' */

    /* Gain: '<S4>/Travel: Count to rad' */
    heli_q8_d6p3_B.TravelCounttorad = heli_q8_d6p3_P.TravelCounttorad_Gain *
      rtb_HILReadEncoderTimebase_o1;

    /* MATLAB Function: '<Root>/Gyro vector to [pitch rate, elevation rate, travle rate]' incorporates:
     *  SignalConversion: '<S3>/TmpSignal ConversionAt SFunction Inport2'
     */
    /* MATLAB Function 'Gyro vector to [pitch rate, elevation rate, travle rate]': '<S3>:1' */
    /* '<S3>:1:3' */
    /* '<S3>:1:4' */
    /* psi = euler_angles(3); */
    /* '<S3>:1:8' */
    /* '<S3>:1:11' */
    tmp_2[0] = 1.0;
    tmp_2[3] = sin(heli_q8_d6p3_B.Sum1) * tan(heli_q8_d6p3_B.Sum2);
    tmp_2[6] = cos(heli_q8_d6p3_B.Sum1) * tan(heli_q8_d6p3_B.Sum2);
    tmp_2[1] = 0.0;
    tmp_2[4] = cos(heli_q8_d6p3_B.Sum1);
    tmp_2[7] = -sin(heli_q8_d6p3_B.Sum1);
    tmp_2[2] = 0.0;
    tmp_2[5] = sin(heli_q8_d6p3_B.Sum1) / cos(heli_q8_d6p3_B.Sum2);
    tmp_2[8] = cos(heli_q8_d6p3_B.Sum1) / cos(heli_q8_d6p3_B.Sum2);

    /* Gain: '<S5>/Gain1' incorporates:
     *  MATLAB Function: '<Root>/Gyro vector to [pitch rate, elevation rate, travle rate]'
     */
    for (i = 0; i < 3; i++) {
      tmp_3[i] = heli_q8_d6p3_P.Gain1_Gain[i + 6] * rtb_Switch[5] +
        (heli_q8_d6p3_P.Gain1_Gain[i + 3] * rtb_Switch[4] +
         heli_q8_d6p3_P.Gain1_Gain[i] * rtb_Switch[3]);
    }

    /* End of Gain: '<S5>/Gain1' */
    for (i = 0; i < 3; i++) {
      /* MATLAB Function: '<Root>/Gyro vector to [pitch rate, elevation rate, travle rate]' */
      heli_q8_d6p3_B.euler_rates[i] = 0.0;
      heli_q8_d6p3_B.euler_rates[i] += tmp_2[i] * tmp_3[0];
      heli_q8_d6p3_B.euler_rates[i] += tmp_2[i + 3] * tmp_3[1];
      heli_q8_d6p3_B.euler_rates[i] += tmp_2[i + 6] * tmp_3[2];

      /* Gain: '<S5>/Gain2' incorporates:
       *  SignalConversion: '<S5>/TmpSignal ConversionAtGain2Inport1'
       */
      rtb_TmpSignalConversionAtSFunct[i] = heli_q8_d6p3_P.Gain2_Gain[i + 6] *
        rtb_Switch[1] + (heli_q8_d6p3_P.Gain2_Gain[i + 3] * rtb_Switch[2] +
                         heli_q8_d6p3_P.Gain2_Gain[i] * rtb_Switch[0]);
    }

    /* Trigonometry: '<S8>/Trigonometric Function' incorporates:
     *  Product: '<S8>/Divide'
     */
    heli_q8_d6p3_B.TrigonometricFunction = atan(rtb_TmpSignalConversionAtSFunct
      [1] / rtb_TmpSignalConversionAtSFunct[2]);

    /* Trigonometry: '<S8>/Trigonometric Function1' incorporates:
     *  Product: '<S8>/Divide1'
     *  Product: '<S8>/Product'
     *  Product: '<S8>/Product1'
     *  Sqrt: '<S8>/Sqrt'
     *  Sum: '<S8>/Add'
     */
    heli_q8_d6p3_B.TrigonometricFunction1 = atan
      (rtb_TmpSignalConversionAtSFunct[0] / sqrt
       (rtb_TmpSignalConversionAtSFunct[1] * rtb_TmpSignalConversionAtSFunct[1]
        + rtb_TmpSignalConversionAtSFunct[2] * rtb_TmpSignalConversionAtSFunct[2]));

    /* UnitDelay: '<Root>/Unit Delay1' incorporates:
     *  Constant: '<Root>/Q_d'
     */
    memcpy(&heli_q8_d6p3_B.UnitDelay1[0], &heli_q8_d6p3_DW.UnitDelay1_DSTATE[0],
           36U * sizeof(real_T));

    /* Constant: '<Root>/Q_d' incorporates:
     *  UnitDelay: '<Root>/Unit Delay1'
     */
    memcpy(&heli_q8_d6p3_B.Q_d[0], &heli_q8_d6p3_P.Q_d[0], 36U * sizeof(real_T));

    /* Constant: '<Root>/R_d' */
    memcpy(&heli_q8_d6p3_B.R_d[0], &heli_q8_d6p3_P.R_d[0], 25U * sizeof(real_T));
  }

  /* MATLAB Function: '<Root>/Estimator' incorporates:
   *  SignalConversion: '<S2>/TmpSignal ConversionAt SFunction Inport6'
   */
  /* MATLAB Function 'Estimator': '<S2>:1' */
  /* '<S2>:1:3' */
  /* '<S2>:1:4' */
  for (i = 0; i < 5; i++) {
    for (i_0 = 0; i_0 < 6; i_0++) {
      K_1[i + 5 * i_0] = 0.0;
      for (i_1 = 0; i_1 < 6; i_1++) {
        K_1[i + 5 * i_0] += heli_q8_d6p3_B.C_d[5 * i_1 + i] *
          heli_q8_d6p3_B.UnitDelay1[6 * i_0 + i_1];
      }
    }
  }

  for (i = 0; i < 5; i++) {
    for (i_0 = 0; i_0 < 5; i_0++) {
      u0 = 0.0;
      for (i_1 = 0; i_1 < 6; i_1++) {
        u0 += K_1[5 * i_1 + i] * heli_q8_d6p3_B.C_d[5 * i_1 + i_0];
      }

      tmp[i + 5 * i_0] = heli_q8_d6p3_B.R_d[5 * i_0 + i] + u0;
    }
  }

  heli_q8_d6p3_invNxN(tmp, tmp_0);
  for (i = 0; i < 6; i++) {
    for (i_0 = 0; i_0 < 5; i_0++) {
      K_1[i + 6 * i_0] = 0.0;
      for (i_1 = 0; i_1 < 6; i_1++) {
        K_1[i + 6 * i_0] += heli_q8_d6p3_B.UnitDelay1[6 * i_1 + i] *
          heli_q8_d6p3_B.C_d[5 * i_1 + i_0];
      }
    }
  }

  for (i = 0; i < 6; i++) {
    for (i_0 = 0; i_0 < 5; i_0++) {
      K[i + 6 * i_0] = 0.0;
      for (i_1 = 0; i_1 < 5; i_1++) {
        K[i + 6 * i_0] += K_1[6 * i_1 + i] * tmp_0[5 * i_0 + i_1];
      }
    }
  }

  if (heli_q8_d6p3_B.StreamRead1_o3) {
    /* '<S2>:1:5' */
    /* '<S2>:1:6' */
    for (i = 0; i < 6; i++) {
      for (i_0 = 0; i_0 < 6; i_0++) {
        u0 = 0.0;
        for (i_1 = 0; i_1 < 5; i_1++) {
          u0 += K[6 * i_1 + i] * heli_q8_d6p3_B.C_d[5 * i_0 + i_1];
        }

        P_hat[i + 6 * i_0] = (real_T)I[6 * i_0 + i] - u0;
      }
    }

    /* SignalConversion: '<S2>/TmpSignal ConversionAt SFunction Inport6' */
    tmp_4[0] = heli_q8_d6p3_B.euler_rates[0];
    tmp_4[1] = heli_q8_d6p3_B.euler_rates[1];
    tmp_4[2] = heli_q8_d6p3_B.euler_rates[2];
    tmp_4[3] = heli_q8_d6p3_B.TrigonometricFunction;
    tmp_4[4] = heli_q8_d6p3_B.TrigonometricFunction1;

    /* '<S2>:1:7' */
    for (i = 0; i < 6; i++) {
      I_0[i] = 0.0;
      for (i_0 = 0; i_0 < 6; i_0++) {
        I_0[i] += P_hat[6 * i_0 + i] * heli_q8_d6p3_B.UnitDelay[i_0];
      }

      K_0[i] = 0.0;
      for (i_0 = 0; i_0 < 5; i_0++) {
        K_0[i] += K[6 * i_0 + i] * tmp_4[i_0];
      }

      x_hat[i] = I_0[i] + K_0[i];
      for (i_0 = 0; i_0 < 6; i_0++) {
        u0 = 0.0;
        for (i_1 = 0; i_1 < 5; i_1++) {
          u0 += K[6 * i_1 + i] * heli_q8_d6p3_B.C_d[5 * i_0 + i_1];
        }

        I_1[i + 6 * i_0] = (real_T)I[6 * i_0 + i] - u0;
      }
    }

    for (i = 0; i < 6; i++) {
      for (i_0 = 0; i_0 < 6; i_0++) {
        P_hat[i + 6 * i_0] = 0.0;
        for (i_1 = 0; i_1 < 6; i_1++) {
          P_hat[i + 6 * i_0] += I_1[6 * i_1 + i] * heli_q8_d6p3_B.UnitDelay1[6 *
            i_0 + i_1];
        }

        u0 = 0.0;
        for (i_1 = 0; i_1 < 5; i_1++) {
          u0 += K[6 * i_1 + i_0] * heli_q8_d6p3_B.C_d[5 * i + i_1];
        }

        I_2[i + 6 * i_0] = (real_T)I[6 * i + i_0] - u0;
      }

      for (i_0 = 0; i_0 < 5; i_0++) {
        K_1[i + 6 * i_0] = 0.0;
        for (i_1 = 0; i_1 < 5; i_1++) {
          K_1[i + 6 * i_0] += K[6 * i_1 + i] * heli_q8_d6p3_B.R_d[5 * i_0 + i_1];
        }
      }
    }

    for (i = 0; i < 6; i++) {
      for (i_0 = 0; i_0 < 6; i_0++) {
        I_1[i + 6 * i_0] = 0.0;
        for (i_1 = 0; i_1 < 6; i_1++) {
          I_1[i + 6 * i_0] += P_hat[6 * i_1 + i] * I_2[6 * i_0 + i_1];
        }

        K_2[i + 6 * i_0] = 0.0;
        for (i_1 = 0; i_1 < 5; i_1++) {
          K_2[i + 6 * i_0] += K_1[6 * i_1 + i] * K[6 * i_1 + i_0];
        }
      }
    }

    for (i = 0; i < 6; i++) {
      for (i_0 = 0; i_0 < 6; i_0++) {
        P_hat[i_0 + 6 * i] = I_1[6 * i + i_0] + K_2[6 * i + i_0];
      }
    }
  } else {
    /* '<S2>:1:9' */
    for (i = 0; i < 6; i++) {
      x_hat[i] = heli_q8_d6p3_B.UnitDelay[i];
    }

    /* '<S2>:1:10' */
    memcpy(&P_hat[0], &heli_q8_d6p3_B.UnitDelay1[0], 36U * sizeof(real_T));
  }

  /* '<S2>:1:12' */
  /* '<S2>:1:13' */
  for (i = 0; i < 6; i++) {
    I_0[i] = 0.0;
    K_0[i] = 0.0;
    K_0[i] += heli_q8_d6p3_B.B_d[i] * heli_q8_d6p3_B.Sum3[0];
    K_0[i] += heli_q8_d6p3_B.B_d[i + 6] * heli_q8_d6p3_B.Sum3[1];
    for (i_0 = 0; i_0 < 6; i_0++) {
      I_0[i] += heli_q8_d6p3_B.A_d[6 * i_0 + i] * x_hat[i_0];
      I_1[i + 6 * i_0] = 0.0;
      for (i_1 = 0; i_1 < 6; i_1++) {
        I_1[i + 6 * i_0] += heli_q8_d6p3_B.A_d[6 * i_1 + i] * P_hat[6 * i_0 +
          i_1];
      }
    }

    heli_q8_d6p3_B.x_2[i] = I_0[i] + K_0[i];
  }

  for (i = 0; i < 6; i++) {
    for (i_0 = 0; i_0 < 6; i_0++) {
      u0 = 0.0;
      for (i_1 = 0; i_1 < 6; i_1++) {
        u0 += I_1[6 * i_1 + i] * heli_q8_d6p3_B.A_d[6 * i_1 + i_0];
      }

      heli_q8_d6p3_B.P_2[i + 6 * i_0] = heli_q8_d6p3_B.Q_d[6 * i_0 + i] + u0;
    }
  }

  /* End of MATLAB Function: '<Root>/Estimator' */

  /* TransferFcn: '<S4>/Travel: Transfer Fcn' */
  heli_q8_d6p3_B.TravelTransferFcn = 0.0;
  heli_q8_d6p3_B.TravelTransferFcn += heli_q8_d6p3_P.TravelTransferFcn_C *
    heli_q8_d6p3_X.TravelTransferFcn_CSTATE;
  heli_q8_d6p3_B.TravelTransferFcn += heli_q8_d6p3_P.TravelTransferFcn_D *
    heli_q8_d6p3_B.TravelCounttorad;
  if (rtmIsMajorTimeStep(heli_q8_d6p3_M)) {
    /* SignalConversion: '<Root>/TmpSignal ConversionAtEstimated stateInport1' */
    for (i = 0; i < 6; i++) {
      rtb_TmpSignalConversionAtEstima[i] = heli_q8_d6p3_B.x_2[i];
    }

    rtb_TmpSignalConversionAtEstima[6] = heli_q8_d6p3_B.Sum1;
    rtb_TmpSignalConversionAtEstima[7] = heli_q8_d6p3_B.PitchTransferFcn;
    rtb_TmpSignalConversionAtEstima[8] = heli_q8_d6p3_B.Sum2;
    rtb_TmpSignalConversionAtEstima[9] = heli_q8_d6p3_B.ElevationTransferFcn;
    rtb_TmpSignalConversionAtEstima[10] = heli_q8_d6p3_B.TravelCounttorad;
    rtb_TmpSignalConversionAtEstima[11] = heli_q8_d6p3_B.TravelTransferFcn;

    /* End of SignalConversion: '<Root>/TmpSignal ConversionAtEstimated stateInport1' */

    /* ToFile: '<Root>/Estimated state' */
    if (rtmIsMajorTimeStep(heli_q8_d6p3_M)) {
      {
        if (!(++heli_q8_d6p3_DW.Estimatedstate_IWORK.Decimation % 1) &&
            (heli_q8_d6p3_DW.Estimatedstate_IWORK.Count*13)+1 < 100000000 ) {
          FILE *fp = (FILE *) heli_q8_d6p3_DW.Estimatedstate_PWORK.FilePtr;
          if (fp != (NULL)) {
            real_T u[13];
            heli_q8_d6p3_DW.Estimatedstate_IWORK.Decimation = 0;
            u[0] = heli_q8_d6p3_M->Timing.t[1];
            u[1] = rtb_TmpSignalConversionAtEstima[0];
            u[2] = rtb_TmpSignalConversionAtEstima[1];
            u[3] = rtb_TmpSignalConversionAtEstima[2];
            u[4] = rtb_TmpSignalConversionAtEstima[3];
            u[5] = rtb_TmpSignalConversionAtEstima[4];
            u[6] = rtb_TmpSignalConversionAtEstima[5];
            u[7] = rtb_TmpSignalConversionAtEstima[6];
            u[8] = rtb_TmpSignalConversionAtEstima[7];
            u[9] = rtb_TmpSignalConversionAtEstima[8];
            u[10] = rtb_TmpSignalConversionAtEstima[9];
            u[11] = rtb_TmpSignalConversionAtEstima[10];
            u[12] = rtb_TmpSignalConversionAtEstima[11];
            if (fwrite(u, sizeof(real_T), 13, fp) != 13) {
              rtmSetErrorStatus(heli_q8_d6p3_M,
                                "Error writing to MAT-file Day6p2.mat");
              return;
            }

            if (((++heli_q8_d6p3_DW.Estimatedstate_IWORK.Count)*13)+1 >=
                100000000) {
              (void)fprintf(stdout,
                            "*** The ToFile block will stop logging data before\n"
                            "    the simulation has ended, because it has reached\n"
                            "    the maximum number of elements (100000000)\n"
                            "    allowed in MAT-file Day6p2.mat.\n");
            }
          }
        }
      }
    }

    /* SignalConversion: '<Root>/TmpSignal ConversionAty_IMUInport1' */
    rtb_TmpSignalConversionAty_IMUI[0] = heli_q8_d6p3_B.euler_rates[0];
    rtb_TmpSignalConversionAty_IMUI[1] = heli_q8_d6p3_B.euler_rates[1];
    rtb_TmpSignalConversionAty_IMUI[2] = heli_q8_d6p3_B.euler_rates[2];
    rtb_TmpSignalConversionAty_IMUI[3] = heli_q8_d6p3_B.TrigonometricFunction;
    rtb_TmpSignalConversionAty_IMUI[4] = heli_q8_d6p3_B.TrigonometricFunction1;

    /* ToFile: '<Root>/y_IMU' */
    if (rtmIsMajorTimeStep(heli_q8_d6p3_M)) {
      {
        if (!(++heli_q8_d6p3_DW.y_IMU_IWORK.Decimation % 1) &&
            (heli_q8_d6p3_DW.y_IMU_IWORK.Count*6)+1 < 100000000 ) {
          FILE *fp = (FILE *) heli_q8_d6p3_DW.y_IMU_PWORK.FilePtr;
          if (fp != (NULL)) {
            real_T u[6];
            heli_q8_d6p3_DW.y_IMU_IWORK.Decimation = 0;
            u[0] = heli_q8_d6p3_M->Timing.t[1];
            u[1] = rtb_TmpSignalConversionAty_IMUI[0];
            u[2] = rtb_TmpSignalConversionAty_IMUI[1];
            u[3] = rtb_TmpSignalConversionAty_IMUI[2];
            u[4] = rtb_TmpSignalConversionAty_IMUI[3];
            u[5] = rtb_TmpSignalConversionAty_IMUI[4];
            if (fwrite(u, sizeof(real_T), 6, fp) != 6) {
              rtmSetErrorStatus(heli_q8_d6p3_M,
                                "Error writing to MAT-file Day6p1.mat");
              return;
            }

            if (((++heli_q8_d6p3_DW.y_IMU_IWORK.Count)*6)+1 >= 100000000) {
              (void)fprintf(stdout,
                            "*** The ToFile block will stop logging data before\n"
                            "    the simulation has ended, because it has reached\n"
                            "    the maximum number of elements (100000000)\n"
                            "    allowed in MAT-file Day6p1.mat.\n");
            }
          }
        }
      }
    }

    /* Constant: '<S7>/V_s0' */
    heli_q8_d6p3_B.V_s0[0] = heli_q8_d6p3_P.V_s0_Value[0];
    heli_q8_d6p3_B.V_s0[1] = heli_q8_d6p3_P.V_s0_Value[1];
  }

  /* Sum: '<S7>/Sum1' */
  heli_q8_d6p3_B.Sum1_d[0] = heli_q8_d6p3_B.V_s0[0] + heli_q8_d6p3_B.Sum3[0];
  heli_q8_d6p3_B.Sum1_d[1] = heli_q8_d6p3_B.V_s0[1] + heli_q8_d6p3_B.Sum3[1];
  if (rtmIsMajorTimeStep(heli_q8_d6p3_M)) {
  }

  /* Gain: '<S1>/Front gain' incorporates:
   *  Sum: '<S1>/Add'
   */
  u0 = (heli_q8_d6p3_B.Sum1_d[0] - heli_q8_d6p3_B.Sum1_d[1]) *
    heli_q8_d6p3_P.Frontgain_Gain;

  /* Saturate: '<S4>/Front motor: Saturation' */
  if (u0 > heli_q8_d6p3_P.FrontmotorSaturation_UpperSat) {
    heli_q8_d6p3_B.FrontmotorSaturation =
      heli_q8_d6p3_P.FrontmotorSaturation_UpperSat;
  } else if (u0 < heli_q8_d6p3_P.FrontmotorSaturation_LowerSat) {
    heli_q8_d6p3_B.FrontmotorSaturation =
      heli_q8_d6p3_P.FrontmotorSaturation_LowerSat;
  } else {
    heli_q8_d6p3_B.FrontmotorSaturation = u0;
  }

  /* End of Saturate: '<S4>/Front motor: Saturation' */

  /* Gain: '<S1>/Back gain' incorporates:
   *  Sum: '<S1>/Subtract'
   */
  u0 = (heli_q8_d6p3_B.Sum1_d[1] + heli_q8_d6p3_B.Sum1_d[0]) *
    heli_q8_d6p3_P.Backgain_Gain;

  /* Saturate: '<S4>/Back motor: Saturation' */
  if (u0 > heli_q8_d6p3_P.BackmotorSaturation_UpperSat) {
    heli_q8_d6p3_B.BackmotorSaturation =
      heli_q8_d6p3_P.BackmotorSaturation_UpperSat;
  } else if (u0 < heli_q8_d6p3_P.BackmotorSaturation_LowerSat) {
    heli_q8_d6p3_B.BackmotorSaturation =
      heli_q8_d6p3_P.BackmotorSaturation_LowerSat;
  } else {
    heli_q8_d6p3_B.BackmotorSaturation = u0;
  }

  /* End of Saturate: '<S4>/Back motor: Saturation' */
  if (rtmIsMajorTimeStep(heli_q8_d6p3_M)) {
    /* S-Function (hil_write_analog_block): '<S4>/HIL Write Analog' */

    /* S-Function Block: heli_q8_d6p3/Heli 3D/HIL Write Analog (hil_write_analog_block) */
    {
      t_error result;
      heli_q8_d6p3_DW.HILWriteAnalog_Buffer[0] =
        heli_q8_d6p3_B.FrontmotorSaturation;
      heli_q8_d6p3_DW.HILWriteAnalog_Buffer[1] =
        heli_q8_d6p3_B.BackmotorSaturation;
      result = hil_write_analog(heli_q8_d6p3_DW.HILInitialize_Card,
        heli_q8_d6p3_P.HILWriteAnalog_channels, 2,
        &heli_q8_d6p3_DW.HILWriteAnalog_Buffer[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_d6p3_M, _rt_error_message);
      }
    }

    /* S-Function (stop_with_error_block): '<S5>/Stop with Call Error' */

    /* S-Function Block: heli_q8_d6p3/IMU/Stop with Call Error (stop_with_error_block) */
    {
      if (rtb_StreamCall1_o3 < 0) {
        msg_get_error_messageA(NULL, rtb_StreamCall1_o3, _rt_error_message,
          sizeof(_rt_error_message));
        rtmSetErrorStatus(heli_q8_d6p3_M, _rt_error_message);
        return;
      }
    }

    /* S-Function (stop_with_error_block): '<S5>/Stop with Read Error' */

    /* S-Function Block: heli_q8_d6p3/IMU/Stop with Read Error (stop_with_error_block) */
    {
      if (rtb_StreamRead1_o5 < 0) {
        msg_get_error_messageA(NULL, rtb_StreamRead1_o5, _rt_error_message,
          sizeof(_rt_error_message));
        rtmSetErrorStatus(heli_q8_d6p3_M, _rt_error_message);
        return;
      }
    }
  }

  /* Sum: '<S11>/Sum2' */
  heli_q8_d6p3_B.Sum2_k[0] = heli_q8_d6p3_B.Sum1 -
    heli_q8_d6p3_B.Joystick_gain_x;
  heli_q8_d6p3_B.Sum2_k[1] = heli_q8_d6p3_B.ElevationTransferFcn -
    heli_q8_d6p3_B.Joystick_gain_y;
  if (rtmIsMajorTimeStep(heli_q8_d6p3_M)) {
  }
}

/* Model update function for TID0 */
void heli_q8_d6p3_update0(void)        /* Sample time: [0.0s, 0.0s] */
{
  int32_T i;
  if (rtmIsMajorTimeStep(heli_q8_d6p3_M)) {
    /* Update for UnitDelay: '<Root>/Unit Delay' */
    for (i = 0; i < 6; i++) {
      heli_q8_d6p3_DW.UnitDelay_DSTATE[i] = heli_q8_d6p3_B.x_2[i];
    }

    /* End of Update for UnitDelay: '<Root>/Unit Delay' */

    /* Update for UnitDelay: '<Root>/Unit Delay1' */
    memcpy(&heli_q8_d6p3_DW.UnitDelay1_DSTATE[0], &heli_q8_d6p3_B.P_2[0], 36U *
           sizeof(real_T));
  }

  if (rtmIsMajorTimeStep(heli_q8_d6p3_M)) {
    rt_ertODEUpdateContinuousStates(&heli_q8_d6p3_M->solverInfo);
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
  if (!(++heli_q8_d6p3_M->Timing.clockTick0)) {
    ++heli_q8_d6p3_M->Timing.clockTickH0;
  }

  heli_q8_d6p3_M->Timing.t[0] = rtsiGetSolverStopTime
    (&heli_q8_d6p3_M->solverInfo);

  /* Update absolute time */
  /* The "clockTick1" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick1"
   * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick1 and the high bits
   * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++heli_q8_d6p3_M->Timing.clockTick1)) {
    ++heli_q8_d6p3_M->Timing.clockTickH1;
  }

  heli_q8_d6p3_M->Timing.t[1] = heli_q8_d6p3_M->Timing.clockTick1 *
    heli_q8_d6p3_M->Timing.stepSize1 + heli_q8_d6p3_M->Timing.clockTickH1 *
    heli_q8_d6p3_M->Timing.stepSize1 * 4294967296.0;
}

/* Derivatives for root system: '<Root>' */
void heli_q8_d6p3_derivatives(void)
{
  XDot_heli_q8_d6p3_T *_rtXdot;
  _rtXdot = ((XDot_heli_q8_d6p3_T *) heli_q8_d6p3_M->ModelData.derivs);

  /* Derivatives for TransferFcn: '<S4>/Pitch: Transfer Fcn' */
  _rtXdot->PitchTransferFcn_CSTATE = 0.0;
  _rtXdot->PitchTransferFcn_CSTATE += heli_q8_d6p3_P.PitchTransferFcn_A *
    heli_q8_d6p3_X.PitchTransferFcn_CSTATE;
  _rtXdot->PitchTransferFcn_CSTATE += heli_q8_d6p3_B.Sum1;

  /* Derivatives for TransferFcn: '<S4>/Elevation: Transfer Fcn' */
  _rtXdot->ElevationTransferFcn_CSTATE = 0.0;
  _rtXdot->ElevationTransferFcn_CSTATE += heli_q8_d6p3_P.ElevationTransferFcn_A *
    heli_q8_d6p3_X.ElevationTransferFcn_CSTATE;
  _rtXdot->ElevationTransferFcn_CSTATE += heli_q8_d6p3_B.Sum2;

  /* Derivatives for Integrator: '<S11>/Integrator' */
  _rtXdot->Integrator_CSTATE[0] = heli_q8_d6p3_B.Sum2_k[0];
  _rtXdot->Integrator_CSTATE[1] = heli_q8_d6p3_B.Sum2_k[1];

  /* Derivatives for TransferFcn: '<S4>/Travel: Transfer Fcn' */
  _rtXdot->TravelTransferFcn_CSTATE = 0.0;
  _rtXdot->TravelTransferFcn_CSTATE += heli_q8_d6p3_P.TravelTransferFcn_A *
    heli_q8_d6p3_X.TravelTransferFcn_CSTATE;
  _rtXdot->TravelTransferFcn_CSTATE += heli_q8_d6p3_B.TravelCounttorad;
}

/* Model output function for TID2 */
void heli_q8_d6p3_output2(void)        /* Sample time: [0.01s, 0.0s] */
{
  /* S-Function (game_controller_block): '<S6>/Game Controller' */

  /* S-Function Block: heli_q8_d6p3/Joystick/Game Controller (game_controller_block) */
  {
    if (heli_q8_d6p3_P.GameController_Enabled) {
      t_game_controller_states state;
      t_boolean new_data;
      t_error result;
      result = game_controller_poll(heli_q8_d6p3_DW.GameController_Controller,
        &state, &new_data);
      if (result == 0) {
        heli_q8_d6p3_B.GameController_o4 = state.x;
        heli_q8_d6p3_B.GameController_o5 = state.y;
      }
    } else {
      heli_q8_d6p3_B.GameController_o4 = 0;
      heli_q8_d6p3_B.GameController_o5 = 0;
    }
  }
}

/* Model update function for TID2 */
void heli_q8_d6p3_update2(void)        /* Sample time: [0.01s, 0.0s] */
{
  /* Update for RateTransition: '<S6>/Rate Transition: x' */
  heli_q8_d6p3_DW.RateTransitionx_Buffer0 = heli_q8_d6p3_B.GameController_o4;

  /* Update for RateTransition: '<S6>/Rate Transition: y' */
  heli_q8_d6p3_DW.RateTransitiony_Buffer0 = heli_q8_d6p3_B.GameController_o5;

  /* Update absolute time */
  /* The "clockTick2" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick2"
   * and "Timing.stepSize2". Size of "clockTick2" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick2 and the high bits
   * Timing.clockTickH2. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++heli_q8_d6p3_M->Timing.clockTick2)) {
    ++heli_q8_d6p3_M->Timing.clockTickH2;
  }

  heli_q8_d6p3_M->Timing.t[2] = heli_q8_d6p3_M->Timing.clockTick2 *
    heli_q8_d6p3_M->Timing.stepSize2 + heli_q8_d6p3_M->Timing.clockTickH2 *
    heli_q8_d6p3_M->Timing.stepSize2 * 4294967296.0;
}

/* Model output wrapper function for compatibility with a static main program */
void heli_q8_d6p3_output(int_T tid)
{
  switch (tid) {
   case 0 :
    heli_q8_d6p3_output0();
    break;

   case 2 :
    heli_q8_d6p3_output2();
    break;

   default :
    break;
  }
}

/* Model update wrapper function for compatibility with a static main program */
void heli_q8_d6p3_update(int_T tid)
{
  switch (tid) {
   case 0 :
    heli_q8_d6p3_update0();
    break;

   case 2 :
    heli_q8_d6p3_update2();
    break;

   default :
    break;
  }
}

/* Model initialize function */
void heli_q8_d6p3_initialize(void)
{
  /* Start for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: heli_q8_d6p3/HIL Initialize (hil_initialize_block) */
  {
    t_int result;
    t_boolean is_switching;
    result = hil_open("q8_usb", "0", &heli_q8_d6p3_DW.HILInitialize_Card);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(heli_q8_d6p3_M, _rt_error_message);
      return;
    }

    is_switching = false;
    result = hil_set_card_specific_options(heli_q8_d6p3_DW.HILInitialize_Card,
      "update_rate=normal;decimation=1", 32);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(heli_q8_d6p3_M, _rt_error_message);
      return;
    }

    result = hil_watchdog_clear(heli_q8_d6p3_DW.HILInitialize_Card);
    if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(heli_q8_d6p3_M, _rt_error_message);
      return;
    }

    if ((heli_q8_d6p3_P.HILInitialize_set_analog_input_ && !is_switching) ||
        (heli_q8_d6p3_P.HILInitialize_set_analog_inpu_m && is_switching)) {
      {
        int_T i1;
        real_T *dw_AIMinimums = &heli_q8_d6p3_DW.HILInitialize_AIMinimums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AIMinimums[i1] = heli_q8_d6p3_P.HILInitialize_analog_input_mini;
        }
      }

      {
        int_T i1;
        real_T *dw_AIMaximums = &heli_q8_d6p3_DW.HILInitialize_AIMaximums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AIMaximums[i1] = heli_q8_d6p3_P.HILInitialize_analog_input_maxi;
        }
      }

      result = hil_set_analog_input_ranges(heli_q8_d6p3_DW.HILInitialize_Card,
        heli_q8_d6p3_P.HILInitialize_analog_input_chan, 8U,
        &heli_q8_d6p3_DW.HILInitialize_AIMinimums[0],
        &heli_q8_d6p3_DW.HILInitialize_AIMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_d6p3_M, _rt_error_message);
        return;
      }
    }

    if ((heli_q8_d6p3_P.HILInitialize_set_analog_output && !is_switching) ||
        (heli_q8_d6p3_P.HILInitialize_set_analog_outp_b && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOMinimums = &heli_q8_d6p3_DW.HILInitialize_AOMinimums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOMinimums[i1] = heli_q8_d6p3_P.HILInitialize_analog_output_min;
        }
      }

      {
        int_T i1;
        real_T *dw_AOMaximums = &heli_q8_d6p3_DW.HILInitialize_AOMaximums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOMaximums[i1] = heli_q8_d6p3_P.HILInitialize_analog_output_max;
        }
      }

      result = hil_set_analog_output_ranges(heli_q8_d6p3_DW.HILInitialize_Card,
        heli_q8_d6p3_P.HILInitialize_analog_output_cha, 8U,
        &heli_q8_d6p3_DW.HILInitialize_AOMinimums[0],
        &heli_q8_d6p3_DW.HILInitialize_AOMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_d6p3_M, _rt_error_message);
        return;
      }
    }

    if ((heli_q8_d6p3_P.HILInitialize_set_analog_outp_e && !is_switching) ||
        (heli_q8_d6p3_P.HILInitialize_set_analog_outp_j && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOVoltages = &heli_q8_d6p3_DW.HILInitialize_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = heli_q8_d6p3_P.HILInitialize_initial_analog_ou;
        }
      }

      result = hil_write_analog(heli_q8_d6p3_DW.HILInitialize_Card,
        heli_q8_d6p3_P.HILInitialize_analog_output_cha, 8U,
        &heli_q8_d6p3_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_d6p3_M, _rt_error_message);
        return;
      }
    }

    if (heli_q8_d6p3_P.HILInitialize_set_analog_outp_p) {
      {
        int_T i1;
        real_T *dw_AOVoltages = &heli_q8_d6p3_DW.HILInitialize_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = heli_q8_d6p3_P.HILInitialize_watchdog_analog_o;
        }
      }

      result = hil_watchdog_set_analog_expiration_state
        (heli_q8_d6p3_DW.HILInitialize_Card,
         heli_q8_d6p3_P.HILInitialize_analog_output_cha, 8U,
         &heli_q8_d6p3_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_d6p3_M, _rt_error_message);
        return;
      }
    }

    if ((heli_q8_d6p3_P.HILInitialize_set_encoder_param && !is_switching) ||
        (heli_q8_d6p3_P.HILInitialize_set_encoder_par_m && is_switching)) {
      {
        int_T i1;
        int32_T *dw_QuadratureModes =
          &heli_q8_d6p3_DW.HILInitialize_QuadratureModes[0];
        for (i1=0; i1 < 8; i1++) {
          dw_QuadratureModes[i1] = heli_q8_d6p3_P.HILInitialize_quadrature;
        }
      }

      result = hil_set_encoder_quadrature_mode
        (heli_q8_d6p3_DW.HILInitialize_Card,
         heli_q8_d6p3_P.HILInitialize_encoder_channels, 8U,
         (t_encoder_quadrature_mode *)
         &heli_q8_d6p3_DW.HILInitialize_QuadratureModes[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_d6p3_M, _rt_error_message);
        return;
      }
    }

    if ((heli_q8_d6p3_P.HILInitialize_set_encoder_count && !is_switching) ||
        (heli_q8_d6p3_P.HILInitialize_set_encoder_cou_k && is_switching)) {
      {
        int_T i1;
        int32_T *dw_InitialEICounts =
          &heli_q8_d6p3_DW.HILInitialize_InitialEICounts[0];
        for (i1=0; i1 < 8; i1++) {
          dw_InitialEICounts[i1] =
            heli_q8_d6p3_P.HILInitialize_initial_encoder_c;
        }
      }

      result = hil_set_encoder_counts(heli_q8_d6p3_DW.HILInitialize_Card,
        heli_q8_d6p3_P.HILInitialize_encoder_channels, 8U,
        &heli_q8_d6p3_DW.HILInitialize_InitialEICounts[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_d6p3_M, _rt_error_message);
        return;
      }
    }

    if ((heli_q8_d6p3_P.HILInitialize_set_pwm_params_at && !is_switching) ||
        (heli_q8_d6p3_P.HILInitialize_set_pwm_params__f && is_switching)) {
      uint32_T num_duty_cycle_modes = 0;
      uint32_T num_frequency_modes = 0;

      {
        int_T i1;
        int32_T *dw_POModeValues = &heli_q8_d6p3_DW.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POModeValues[i1] = heli_q8_d6p3_P.HILInitialize_pwm_modes;
        }
      }

      result = hil_set_pwm_mode(heli_q8_d6p3_DW.HILInitialize_Card,
        heli_q8_d6p3_P.HILInitialize_pwm_channels, 8U, (t_pwm_mode *)
        &heli_q8_d6p3_DW.HILInitialize_POModeValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_d6p3_M, _rt_error_message);
        return;
      }

      {
        int_T i1;
        const uint32_T *p_HILInitialize_pwm_channels =
          heli_q8_d6p3_P.HILInitialize_pwm_channels;
        int32_T *dw_POModeValues = &heli_q8_d6p3_DW.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          if (dw_POModeValues[i1] == PWM_DUTY_CYCLE_MODE || dw_POModeValues[i1] ==
              PWM_ONE_SHOT_MODE || dw_POModeValues[i1] == PWM_TIME_MODE) {
            heli_q8_d6p3_DW.HILInitialize_POSortedChans[num_duty_cycle_modes] =
              p_HILInitialize_pwm_channels[i1];
            heli_q8_d6p3_DW.HILInitialize_POSortedFreqs[num_duty_cycle_modes] =
              heli_q8_d6p3_P.HILInitialize_pwm_frequency;
            num_duty_cycle_modes++;
          } else {
            heli_q8_d6p3_DW.HILInitialize_POSortedChans[7U - num_frequency_modes]
              = p_HILInitialize_pwm_channels[i1];
            heli_q8_d6p3_DW.HILInitialize_POSortedFreqs[7U - num_frequency_modes]
              = heli_q8_d6p3_P.HILInitialize_pwm_frequency;
            num_frequency_modes++;
          }
        }
      }

      if (num_duty_cycle_modes > 0) {
        result = hil_set_pwm_frequency(heli_q8_d6p3_DW.HILInitialize_Card,
          &heli_q8_d6p3_DW.HILInitialize_POSortedChans[0], num_duty_cycle_modes,
          &heli_q8_d6p3_DW.HILInitialize_POSortedFreqs[0]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(heli_q8_d6p3_M, _rt_error_message);
          return;
        }
      }

      if (num_frequency_modes > 0) {
        result = hil_set_pwm_duty_cycle(heli_q8_d6p3_DW.HILInitialize_Card,
          &heli_q8_d6p3_DW.HILInitialize_POSortedChans[num_duty_cycle_modes],
          num_frequency_modes,
          &heli_q8_d6p3_DW.HILInitialize_POSortedFreqs[num_duty_cycle_modes]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(heli_q8_d6p3_M, _rt_error_message);
          return;
        }
      }

      {
        int_T i1;
        int32_T *dw_POModeValues = &heli_q8_d6p3_DW.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POModeValues[i1] = heli_q8_d6p3_P.HILInitialize_pwm_configuration;
        }
      }

      {
        int_T i1;
        int32_T *dw_POAlignValues =
          &heli_q8_d6p3_DW.HILInitialize_POAlignValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POAlignValues[i1] = heli_q8_d6p3_P.HILInitialize_pwm_alignment;
        }
      }

      {
        int_T i1;
        int32_T *dw_POPolarityVals =
          &heli_q8_d6p3_DW.HILInitialize_POPolarityVals[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POPolarityVals[i1] = heli_q8_d6p3_P.HILInitialize_pwm_polarity;
        }
      }

      result = hil_set_pwm_configuration(heli_q8_d6p3_DW.HILInitialize_Card,
        heli_q8_d6p3_P.HILInitialize_pwm_channels, 8U,
        (t_pwm_configuration *) &heli_q8_d6p3_DW.HILInitialize_POModeValues[0],
        (t_pwm_alignment *) &heli_q8_d6p3_DW.HILInitialize_POAlignValues[0],
        (t_pwm_polarity *) &heli_q8_d6p3_DW.HILInitialize_POPolarityVals[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_d6p3_M, _rt_error_message);
        return;
      }

      {
        int_T i1;
        real_T *dw_POSortedFreqs = &heli_q8_d6p3_DW.HILInitialize_POSortedFreqs
          [0];
        for (i1=0; i1 < 8; i1++) {
          dw_POSortedFreqs[i1] = heli_q8_d6p3_P.HILInitialize_pwm_leading_deadb;
        }
      }

      {
        int_T i1;
        real_T *dw_POValues = &heli_q8_d6p3_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = heli_q8_d6p3_P.HILInitialize_pwm_trailing_dead;
        }
      }

      result = hil_set_pwm_deadband(heli_q8_d6p3_DW.HILInitialize_Card,
        heli_q8_d6p3_P.HILInitialize_pwm_channels, 8U,
        &heli_q8_d6p3_DW.HILInitialize_POSortedFreqs[0],
        &heli_q8_d6p3_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_d6p3_M, _rt_error_message);
        return;
      }
    }

    if ((heli_q8_d6p3_P.HILInitialize_set_pwm_outputs_a && !is_switching) ||
        (heli_q8_d6p3_P.HILInitialize_set_pwm_outputs_g && is_switching)) {
      {
        int_T i1;
        real_T *dw_POValues = &heli_q8_d6p3_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = heli_q8_d6p3_P.HILInitialize_initial_pwm_outpu;
        }
      }

      result = hil_write_pwm(heli_q8_d6p3_DW.HILInitialize_Card,
        heli_q8_d6p3_P.HILInitialize_pwm_channels, 8U,
        &heli_q8_d6p3_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_d6p3_M, _rt_error_message);
        return;
      }
    }

    if (heli_q8_d6p3_P.HILInitialize_set_pwm_outputs_o) {
      {
        int_T i1;
        real_T *dw_POValues = &heli_q8_d6p3_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = heli_q8_d6p3_P.HILInitialize_watchdog_pwm_outp;
        }
      }

      result = hil_watchdog_set_pwm_expiration_state
        (heli_q8_d6p3_DW.HILInitialize_Card,
         heli_q8_d6p3_P.HILInitialize_pwm_channels, 8U,
         &heli_q8_d6p3_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_d6p3_M, _rt_error_message);
        return;
      }
    }
  }

  /* Start for S-Function (hil_read_encoder_timebase_block): '<S4>/HIL Read Encoder Timebase' */

  /* S-Function Block: heli_q8_d6p3/Heli 3D/HIL Read Encoder Timebase (hil_read_encoder_timebase_block) */
  {
    t_error result;
    result = hil_task_create_encoder_reader(heli_q8_d6p3_DW.HILInitialize_Card,
      heli_q8_d6p3_P.HILReadEncoderTimebase_samples_,
      heli_q8_d6p3_P.HILReadEncoderTimebase_channels, 3,
      &heli_q8_d6p3_DW.HILReadEncoderTimebase_Task);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(heli_q8_d6p3_M, _rt_error_message);
    }
  }

  /* Start for Constant: '<Root>/A_d' */
  memcpy(&heli_q8_d6p3_B.A_d[0], &heli_q8_d6p3_P.A_d[0], 36U * sizeof(real_T));

  /* Start for Constant: '<Root>/B_d' */
  memcpy(&heli_q8_d6p3_B.B_d[0], &heli_q8_d6p3_P.B_d[0], 12U * sizeof(real_T));

  /* Start for RateTransition: '<S6>/Rate Transition: x' */
  heli_q8_d6p3_B.RateTransitionx = heli_q8_d6p3_P.RateTransitionx_X0;

  /* Start for RateTransition: '<S6>/Rate Transition: y' */
  heli_q8_d6p3_B.RateTransitiony = heli_q8_d6p3_P.RateTransitiony_X0;

  /* Start for Constant: '<Root>/C_d' */
  memcpy(&heli_q8_d6p3_B.C_d[0], &heli_q8_d6p3_P.C_d[0], 30U * sizeof(real_T));

  /* Start for S-Function (stream_call_block): '<S5>/Stream Call1' */

  /* S-Function Block: heli_q8_d6p3/IMU/Stream Call1 (stream_call_block) */
  {
    heli_q8_d6p3_DW.StreamCall1_State = STREAM_CALL_STATE_NOT_CONNECTED;
    heli_q8_d6p3_DW.StreamCall1_Stream = NULL;
  }

  /* Start for Constant: '<Root>/Q_d' */
  memcpy(&heli_q8_d6p3_B.Q_d[0], &heli_q8_d6p3_P.Q_d[0], 36U * sizeof(real_T));

  /* Start for Constant: '<Root>/R_d' */
  memcpy(&heli_q8_d6p3_B.R_d[0], &heli_q8_d6p3_P.R_d[0], 25U * sizeof(real_T));

  /* Start for ToFile: '<Root>/Estimated state' */
  {
    FILE *fp = (NULL);
    char fileName[509] = "Day6p2.mat";
    if ((fp = fopen(fileName, "wb")) == (NULL)) {
      rtmSetErrorStatus(heli_q8_d6p3_M, "Error creating .mat file Day6p2.mat");
      return;
    }

    if (rt_WriteMat4FileHeader(fp,13,0,"ans")) {
      rtmSetErrorStatus(heli_q8_d6p3_M,
                        "Error writing mat file header to file Day6p2.mat");
      return;
    }

    heli_q8_d6p3_DW.Estimatedstate_IWORK.Count = 0;
    heli_q8_d6p3_DW.Estimatedstate_IWORK.Decimation = -1;
    heli_q8_d6p3_DW.Estimatedstate_PWORK.FilePtr = fp;
  }

  /* Start for ToFile: '<Root>/y_IMU' */
  {
    FILE *fp = (NULL);
    char fileName[509] = "Day6p1.mat";
    if ((fp = fopen(fileName, "wb")) == (NULL)) {
      rtmSetErrorStatus(heli_q8_d6p3_M, "Error creating .mat file Day6p1.mat");
      return;
    }

    if (rt_WriteMat4FileHeader(fp,6,0,"ans")) {
      rtmSetErrorStatus(heli_q8_d6p3_M,
                        "Error writing mat file header to file Day6p1.mat");
      return;
    }

    heli_q8_d6p3_DW.y_IMU_IWORK.Count = 0;
    heli_q8_d6p3_DW.y_IMU_IWORK.Decimation = -1;
    heli_q8_d6p3_DW.y_IMU_PWORK.FilePtr = fp;
  }

  /* Start for S-Function (game_controller_block): '<S6>/Game Controller' */

  /* S-Function Block: heli_q8_d6p3/Joystick/Game Controller (game_controller_block) */
  {
    if (heli_q8_d6p3_P.GameController_Enabled) {
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
        (heli_q8_d6p3_P.GameController_ControllerNumber,
         heli_q8_d6p3_P.GameController_BufferSize, deadzone, saturation,
         heli_q8_d6p3_P.GameController_AutoCenter, 0, 1.0,
         &heli_q8_d6p3_DW.GameController_Controller);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_d6p3_M, _rt_error_message);
      }
    }
  }

  {
    int32_T i;

    /* InitializeConditions for UnitDelay: '<Root>/Unit Delay' */
    for (i = 0; i < 6; i++) {
      heli_q8_d6p3_DW.UnitDelay_DSTATE[i] =
        heli_q8_d6p3_P.UnitDelay_InitialCondition[i];
    }

    /* End of InitializeConditions for UnitDelay: '<Root>/Unit Delay' */

    /* InitializeConditions for RateTransition: '<S6>/Rate Transition: x' */
    heli_q8_d6p3_DW.RateTransitionx_Buffer0 = heli_q8_d6p3_P.RateTransitionx_X0;

    /* InitializeConditions for RateTransition: '<S6>/Rate Transition: y' */
    heli_q8_d6p3_DW.RateTransitiony_Buffer0 = heli_q8_d6p3_P.RateTransitiony_X0;

    /* InitializeConditions for TransferFcn: '<S4>/Pitch: Transfer Fcn' */
    heli_q8_d6p3_X.PitchTransferFcn_CSTATE = 0.0;

    /* InitializeConditions for TransferFcn: '<S4>/Elevation: Transfer Fcn' */
    heli_q8_d6p3_X.ElevationTransferFcn_CSTATE = 0.0;

    /* InitializeConditions for Integrator: '<S11>/Integrator' */
    heli_q8_d6p3_X.Integrator_CSTATE[0] = heli_q8_d6p3_P.Integrator_IC;
    heli_q8_d6p3_X.Integrator_CSTATE[1] = heli_q8_d6p3_P.Integrator_IC;

    /* InitializeConditions for UnitDelay: '<Root>/Unit Delay1' */
    memcpy(&heli_q8_d6p3_DW.UnitDelay1_DSTATE[0],
           &heli_q8_d6p3_P.UnitDelay1_InitialCondition[0], 36U * sizeof(real_T));

    /* InitializeConditions for TransferFcn: '<S4>/Travel: Transfer Fcn' */
    heli_q8_d6p3_X.TravelTransferFcn_CSTATE = 0.0;
  }
}

/* Model terminate function */
void heli_q8_d6p3_terminate(void)
{
  /* Terminate for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: heli_q8_d6p3/HIL Initialize (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    t_uint32 num_final_analog_outputs = 0;
    t_uint32 num_final_pwm_outputs = 0;
    hil_task_stop_all(heli_q8_d6p3_DW.HILInitialize_Card);
    hil_monitor_stop_all(heli_q8_d6p3_DW.HILInitialize_Card);
    is_switching = false;
    if ((heli_q8_d6p3_P.HILInitialize_set_analog_out_ex && !is_switching) ||
        (heli_q8_d6p3_P.HILInitialize_set_analog_outp_c && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOVoltages = &heli_q8_d6p3_DW.HILInitialize_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = heli_q8_d6p3_P.HILInitialize_final_analog_outp;
        }
      }

      num_final_analog_outputs = 8U;
    }

    if ((heli_q8_d6p3_P.HILInitialize_set_pwm_output_ap && !is_switching) ||
        (heli_q8_d6p3_P.HILInitialize_set_pwm_outputs_p && is_switching)) {
      {
        int_T i1;
        real_T *dw_POValues = &heli_q8_d6p3_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = heli_q8_d6p3_P.HILInitialize_final_pwm_outputs;
        }
      }

      num_final_pwm_outputs = 8U;
    }

    if (0
        || num_final_analog_outputs > 0
        || num_final_pwm_outputs > 0
        ) {
      /* Attempt to write the final outputs atomically (due to firmware issue in old Q2-USB). Otherwise write channels individually */
      result = hil_write(heli_q8_d6p3_DW.HILInitialize_Card
                         , heli_q8_d6p3_P.HILInitialize_analog_output_cha,
                         num_final_analog_outputs
                         , heli_q8_d6p3_P.HILInitialize_pwm_channels,
                         num_final_pwm_outputs
                         , NULL, 0
                         , NULL, 0
                         , &heli_q8_d6p3_DW.HILInitialize_AOVoltages[0]
                         , &heli_q8_d6p3_DW.HILInitialize_POValues[0]
                         , (t_boolean *) NULL
                         , NULL
                         );
      if (result == -QERR_HIL_WRITE_NOT_SUPPORTED) {
        t_error local_result;
        result = 0;

        /* The hil_write operation is not supported by this card. Write final outputs for each channel type */
        if (num_final_analog_outputs > 0) {
          local_result = hil_write_analog(heli_q8_d6p3_DW.HILInitialize_Card,
            heli_q8_d6p3_P.HILInitialize_analog_output_cha,
            num_final_analog_outputs, &heli_q8_d6p3_DW.HILInitialize_AOVoltages
            [0]);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (num_final_pwm_outputs > 0) {
          local_result = hil_write_pwm(heli_q8_d6p3_DW.HILInitialize_Card,
            heli_q8_d6p3_P.HILInitialize_pwm_channels, num_final_pwm_outputs,
            &heli_q8_d6p3_DW.HILInitialize_POValues[0]);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(heli_q8_d6p3_M, _rt_error_message);
        }
      }
    }

    hil_task_delete_all(heli_q8_d6p3_DW.HILInitialize_Card);
    hil_monitor_delete_all(heli_q8_d6p3_DW.HILInitialize_Card);
    hil_close(heli_q8_d6p3_DW.HILInitialize_Card);
    heli_q8_d6p3_DW.HILInitialize_Card = NULL;
  }

  /* Terminate for S-Function (stream_call_block): '<S5>/Stream Call1' */

  /* S-Function Block: heli_q8_d6p3/IMU/Stream Call1 (stream_call_block) */
  {
    if (heli_q8_d6p3_DW.StreamCall1_Stream != NULL) {
      stream_close(heli_q8_d6p3_DW.StreamCall1_Stream);
      heli_q8_d6p3_DW.StreamCall1_Stream = NULL;
    }
  }

  /* Terminate for ToFile: '<Root>/Estimated state' */
  {
    FILE *fp = (FILE *) heli_q8_d6p3_DW.Estimatedstate_PWORK.FilePtr;
    if (fp != (NULL)) {
      char fileName[509] = "Day6p2.mat";
      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(heli_q8_d6p3_M, "Error closing MAT-file Day6p2.mat");
        return;
      }

      if ((fp = fopen(fileName, "r+b")) == (NULL)) {
        rtmSetErrorStatus(heli_q8_d6p3_M, "Error reopening MAT-file Day6p2.mat");
        return;
      }

      if (rt_WriteMat4FileHeader(fp, 13,
           heli_q8_d6p3_DW.Estimatedstate_IWORK.Count, "ans")) {
        rtmSetErrorStatus(heli_q8_d6p3_M,
                          "Error writing header for ans to MAT-file Day6p2.mat");
      }

      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(heli_q8_d6p3_M, "Error closing MAT-file Day6p2.mat");
        return;
      }

      heli_q8_d6p3_DW.Estimatedstate_PWORK.FilePtr = (NULL);
    }
  }

  /* Terminate for ToFile: '<Root>/y_IMU' */
  {
    FILE *fp = (FILE *) heli_q8_d6p3_DW.y_IMU_PWORK.FilePtr;
    if (fp != (NULL)) {
      char fileName[509] = "Day6p1.mat";
      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(heli_q8_d6p3_M, "Error closing MAT-file Day6p1.mat");
        return;
      }

      if ((fp = fopen(fileName, "r+b")) == (NULL)) {
        rtmSetErrorStatus(heli_q8_d6p3_M, "Error reopening MAT-file Day6p1.mat");
        return;
      }

      if (rt_WriteMat4FileHeader(fp, 6, heli_q8_d6p3_DW.y_IMU_IWORK.Count, "ans"))
      {
        rtmSetErrorStatus(heli_q8_d6p3_M,
                          "Error writing header for ans to MAT-file Day6p1.mat");
      }

      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(heli_q8_d6p3_M, "Error closing MAT-file Day6p1.mat");
        return;
      }

      heli_q8_d6p3_DW.y_IMU_PWORK.FilePtr = (NULL);
    }
  }

  /* Terminate for S-Function (game_controller_block): '<S6>/Game Controller' */

  /* S-Function Block: heli_q8_d6p3/Joystick/Game Controller (game_controller_block) */
  {
    if (heli_q8_d6p3_P.GameController_Enabled) {
      game_controller_close(heli_q8_d6p3_DW.GameController_Controller);
      heli_q8_d6p3_DW.GameController_Controller = NULL;
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
  heli_q8_d6p3_output(tid);
}

void MdlUpdate(int_T tid)
{
  if (tid == 1)
    tid = 0;
  heli_q8_d6p3_update(tid);
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
  heli_q8_d6p3_initialize();
}

void MdlTerminate(void)
{
  heli_q8_d6p3_terminate();
}

/* Registration function */
RT_MODEL_heli_q8_d6p3_T *heli_q8_d6p3(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* non-finite (run-time) assignments */
  heli_q8_d6p3_P.Constant2_Value = rtNaN;

  /* initialize real-time model */
  (void) memset((void *)heli_q8_d6p3_M, 0,
                sizeof(RT_MODEL_heli_q8_d6p3_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&heli_q8_d6p3_M->solverInfo,
                          &heli_q8_d6p3_M->Timing.simTimeStep);
    rtsiSetTPtr(&heli_q8_d6p3_M->solverInfo, &rtmGetTPtr(heli_q8_d6p3_M));
    rtsiSetStepSizePtr(&heli_q8_d6p3_M->solverInfo,
                       &heli_q8_d6p3_M->Timing.stepSize0);
    rtsiSetdXPtr(&heli_q8_d6p3_M->solverInfo, &heli_q8_d6p3_M->ModelData.derivs);
    rtsiSetContStatesPtr(&heli_q8_d6p3_M->solverInfo, (real_T **)
                         &heli_q8_d6p3_M->ModelData.contStates);
    rtsiSetNumContStatesPtr(&heli_q8_d6p3_M->solverInfo,
      &heli_q8_d6p3_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&heli_q8_d6p3_M->solverInfo,
      &heli_q8_d6p3_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&heli_q8_d6p3_M->solverInfo,
      &heli_q8_d6p3_M->ModelData.periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&heli_q8_d6p3_M->solverInfo,
      &heli_q8_d6p3_M->ModelData.periodicContStateRanges);
    rtsiSetErrorStatusPtr(&heli_q8_d6p3_M->solverInfo, (&rtmGetErrorStatus
      (heli_q8_d6p3_M)));
    rtsiSetRTModelPtr(&heli_q8_d6p3_M->solverInfo, heli_q8_d6p3_M);
  }

  rtsiSetSimTimeStep(&heli_q8_d6p3_M->solverInfo, MAJOR_TIME_STEP);
  heli_q8_d6p3_M->ModelData.intgData.f[0] = heli_q8_d6p3_M->ModelData.odeF[0];
  heli_q8_d6p3_M->ModelData.contStates = ((real_T *) &heli_q8_d6p3_X);
  rtsiSetSolverData(&heli_q8_d6p3_M->solverInfo, (void *)
                    &heli_q8_d6p3_M->ModelData.intgData);
  rtsiSetSolverName(&heli_q8_d6p3_M->solverInfo,"ode1");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = heli_q8_d6p3_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    mdlTsMap[2] = 2;
    heli_q8_d6p3_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    heli_q8_d6p3_M->Timing.sampleTimes =
      (&heli_q8_d6p3_M->Timing.sampleTimesArray[0]);
    heli_q8_d6p3_M->Timing.offsetTimes =
      (&heli_q8_d6p3_M->Timing.offsetTimesArray[0]);

    /* task periods */
    heli_q8_d6p3_M->Timing.sampleTimes[0] = (0.0);
    heli_q8_d6p3_M->Timing.sampleTimes[1] = (0.002);
    heli_q8_d6p3_M->Timing.sampleTimes[2] = (0.01);

    /* task offsets */
    heli_q8_d6p3_M->Timing.offsetTimes[0] = (0.0);
    heli_q8_d6p3_M->Timing.offsetTimes[1] = (0.0);
    heli_q8_d6p3_M->Timing.offsetTimes[2] = (0.0);
  }

  rtmSetTPtr(heli_q8_d6p3_M, &heli_q8_d6p3_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = heli_q8_d6p3_M->Timing.sampleHitArray;
    int_T *mdlPerTaskSampleHits = heli_q8_d6p3_M->Timing.perTaskSampleHitsArray;
    heli_q8_d6p3_M->Timing.perTaskSampleHits = (&mdlPerTaskSampleHits[0]);
    mdlSampleHits[0] = 1;
    heli_q8_d6p3_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(heli_q8_d6p3_M, -1);
  heli_q8_d6p3_M->Timing.stepSize0 = 0.002;
  heli_q8_d6p3_M->Timing.stepSize1 = 0.002;
  heli_q8_d6p3_M->Timing.stepSize2 = 0.01;

  /* External mode info */
  heli_q8_d6p3_M->Sizes.checksums[0] = (4073760419U);
  heli_q8_d6p3_M->Sizes.checksums[1] = (48061876U);
  heli_q8_d6p3_M->Sizes.checksums[2] = (2857659216U);
  heli_q8_d6p3_M->Sizes.checksums[3] = (745453510U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[5];
    heli_q8_d6p3_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(heli_q8_d6p3_M->extModeInfo,
      &heli_q8_d6p3_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(heli_q8_d6p3_M->extModeInfo,
                        heli_q8_d6p3_M->Sizes.checksums);
    rteiSetTPtr(heli_q8_d6p3_M->extModeInfo, rtmGetTPtr(heli_q8_d6p3_M));
  }

  heli_q8_d6p3_M->solverInfoPtr = (&heli_q8_d6p3_M->solverInfo);
  heli_q8_d6p3_M->Timing.stepSize = (0.002);
  rtsiSetFixedStepSize(&heli_q8_d6p3_M->solverInfo, 0.002);
  rtsiSetSolverMode(&heli_q8_d6p3_M->solverInfo, SOLVER_MODE_MULTITASKING);

  /* block I/O */
  heli_q8_d6p3_M->ModelData.blockIO = ((void *) &heli_q8_d6p3_B);
  (void) memset(((void *) &heli_q8_d6p3_B), 0,
                sizeof(B_heli_q8_d6p3_T));

  {
    int32_T i;
    for (i = 0; i < 36; i++) {
      heli_q8_d6p3_B.A_d[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      heli_q8_d6p3_B.UnitDelay[i] = 0.0;
    }

    for (i = 0; i < 12; i++) {
      heli_q8_d6p3_B.B_d[i] = 0.0;
    }

    for (i = 0; i < 30; i++) {
      heli_q8_d6p3_B.C_d[i] = 0.0;
    }

    for (i = 0; i < 36; i++) {
      heli_q8_d6p3_B.UnitDelay1[i] = 0.0;
    }

    for (i = 0; i < 36; i++) {
      heli_q8_d6p3_B.Q_d[i] = 0.0;
    }

    for (i = 0; i < 25; i++) {
      heli_q8_d6p3_B.R_d[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      heli_q8_d6p3_B.x_2[i] = 0.0;
    }

    for (i = 0; i < 36; i++) {
      heli_q8_d6p3_B.P_2[i] = 0.0;
    }

    heli_q8_d6p3_B.RateTransitionx = 0.0;
    heli_q8_d6p3_B.Joystick_gain_x = 0.0;
    heli_q8_d6p3_B.RateTransitiony = 0.0;
    heli_q8_d6p3_B.Joystick_gain_y = 0.0;
    heli_q8_d6p3_B.Fr[0] = 0.0;
    heli_q8_d6p3_B.Fr[1] = 0.0;
    heli_q8_d6p3_B.Sum1 = 0.0;
    heli_q8_d6p3_B.PitchTransferFcn = 0.0;
    heli_q8_d6p3_B.Sum2 = 0.0;
    heli_q8_d6p3_B.ElevationTransferFcn = 0.0;
    heli_q8_d6p3_B.u = 0.0;
    heli_q8_d6p3_B.u_o = 0.0;
    heli_q8_d6p3_B.Sum3[0] = 0.0;
    heli_q8_d6p3_B.Sum3[1] = 0.0;
    heli_q8_d6p3_B.TravelCounttorad = 0.0;
    heli_q8_d6p3_B.TrigonometricFunction = 0.0;
    heli_q8_d6p3_B.TrigonometricFunction1 = 0.0;
    heli_q8_d6p3_B.TravelTransferFcn = 0.0;
    heli_q8_d6p3_B.V_s0[0] = 0.0;
    heli_q8_d6p3_B.V_s0[1] = 0.0;
    heli_q8_d6p3_B.Sum1_d[0] = 0.0;
    heli_q8_d6p3_B.Sum1_d[1] = 0.0;
    heli_q8_d6p3_B.FrontmotorSaturation = 0.0;
    heli_q8_d6p3_B.BackmotorSaturation = 0.0;
    heli_q8_d6p3_B.GameController_o4 = 0.0;
    heli_q8_d6p3_B.GameController_o5 = 0.0;
    heli_q8_d6p3_B.Sum2_k[0] = 0.0;
    heli_q8_d6p3_B.Sum2_k[1] = 0.0;
    heli_q8_d6p3_B.euler_rates[0] = 0.0;
    heli_q8_d6p3_B.euler_rates[1] = 0.0;
    heli_q8_d6p3_B.euler_rates[2] = 0.0;
  }

  /* parameters */
  heli_q8_d6p3_M->ModelData.defaultParam = ((real_T *)&heli_q8_d6p3_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &heli_q8_d6p3_X;
    heli_q8_d6p3_M->ModelData.contStates = (x);
    (void) memset((void *)&heli_q8_d6p3_X, 0,
                  sizeof(X_heli_q8_d6p3_T));
  }

  /* states (dwork) */
  heli_q8_d6p3_M->ModelData.dwork = ((void *) &heli_q8_d6p3_DW);
  (void) memset((void *)&heli_q8_d6p3_DW, 0,
                sizeof(DW_heli_q8_d6p3_T));

  {
    int32_T i;
    for (i = 0; i < 6; i++) {
      heli_q8_d6p3_DW.UnitDelay_DSTATE[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 36; i++) {
      heli_q8_d6p3_DW.UnitDelay1_DSTATE[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      heli_q8_d6p3_DW.HILInitialize_AIMinimums[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      heli_q8_d6p3_DW.HILInitialize_AIMaximums[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      heli_q8_d6p3_DW.HILInitialize_AOMinimums[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      heli_q8_d6p3_DW.HILInitialize_AOMaximums[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      heli_q8_d6p3_DW.HILInitialize_AOVoltages[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      heli_q8_d6p3_DW.HILInitialize_FilterFrequency[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      heli_q8_d6p3_DW.HILInitialize_POSortedFreqs[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      heli_q8_d6p3_DW.HILInitialize_POValues[i] = 0.0;
    }
  }

  heli_q8_d6p3_DW.RateTransitionx_Buffer0 = 0.0;
  heli_q8_d6p3_DW.RateTransitiony_Buffer0 = 0.0;
  heli_q8_d6p3_DW.HILWriteAnalog_Buffer[0] = 0.0;
  heli_q8_d6p3_DW.HILWriteAnalog_Buffer[1] = 0.0;

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    heli_q8_d6p3_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 25;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.B = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.P = &rtPTransTable;
  }

  /* Initialize Sizes */
  heli_q8_d6p3_M->Sizes.numContStates = (5);/* Number of continuous states */
  heli_q8_d6p3_M->Sizes.numPeriodicContStates = (0);/* Number of periodic continuous states */
  heli_q8_d6p3_M->Sizes.numY = (0);    /* Number of model outputs */
  heli_q8_d6p3_M->Sizes.numU = (0);    /* Number of model inputs */
  heli_q8_d6p3_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  heli_q8_d6p3_M->Sizes.numSampTimes = (3);/* Number of sample times */
  heli_q8_d6p3_M->Sizes.numBlocks = (101);/* Number of blocks */
  heli_q8_d6p3_M->Sizes.numBlockIO = (35);/* Number of block outputs */
  heli_q8_d6p3_M->Sizes.numBlockPrms = (621);/* Sum of parameter "widths" */
  return heli_q8_d6p3_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
