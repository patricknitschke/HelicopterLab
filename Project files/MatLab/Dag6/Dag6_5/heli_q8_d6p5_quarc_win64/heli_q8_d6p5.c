/*
 * heli_q8_d6p5.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "heli_q8_d6p5".
 *
 * Model version              : 1.170
 * Simulink Coder version : 8.9 (R2015b) 13-Aug-2015
 * C source code generated on : Sun Nov 17 11:47:39 2019
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "heli_q8_d6p5.h"
#include "heli_q8_d6p5_private.h"
#include "heli_q8_d6p5_dt.h"

t_stream heli_q8_d6p5_rtZt_stream = NULL;

/* Block signals (auto storage) */
B_heli_q8_d6p5_T heli_q8_d6p5_B;

/* Continuous states */
X_heli_q8_d6p5_T heli_q8_d6p5_X;

/* Block states (auto storage) */
DW_heli_q8_d6p5_T heli_q8_d6p5_DW;

/* Real-time model */
RT_MODEL_heli_q8_d6p5_T heli_q8_d6p5_M_;
RT_MODEL_heli_q8_d6p5_T *const heli_q8_d6p5_M = &heli_q8_d6p5_M_;

/* Forward declaration for local functions */
static void heli_q8_d6p5_invNxN(const real_T x[25], real_T y[25]);
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
  rtmSampleHitPtr[1] = rtmStepTask(heli_q8_d6p5_M, 1);
  rtmSampleHitPtr[2] = rtmStepTask(heli_q8_d6p5_M, 2);
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
  if (heli_q8_d6p5_M->Timing.TaskCounters.TID[1] == 0) {
    heli_q8_d6p5_M->Timing.RateInteraction.TID1_2 =
      (heli_q8_d6p5_M->Timing.TaskCounters.TID[2] == 0);

    /* update PerTaskSampleHits matrix for non-inline sfcn */
    heli_q8_d6p5_M->Timing.perTaskSampleHits[5] =
      heli_q8_d6p5_M->Timing.RateInteraction.TID1_2;
  }

  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (heli_q8_d6p5_M->Timing.TaskCounters.TID[2])++;
  if ((heli_q8_d6p5_M->Timing.TaskCounters.TID[2]) > 4) {/* Sample time: [0.01s, 0.0s] */
    heli_q8_d6p5_M->Timing.TaskCounters.TID[2] = 0;
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
  heli_q8_d6p5_derivatives();
  rtsiSetT(si, tnew);
  for (i = 0; i < nXc; ++i) {
    x[i] += h * f0[i];
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Function for MATLAB Function: '<S11>/Kalman prediction step' */
static void heli_q8_d6p5_invNxN(const real_T x[25], real_T y[25])
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
void heli_q8_d6p5_output0(void)        /* Sample time: [0.0s, 0.0s] */
{
  /* local block i/o variables */
  real_T rtb_HILReadEncoderTimebase_o1;
  real_T rtb_HILReadEncoderTimebase_o2;
  real_T rtb_HILReadEncoderTimebase_o3;
  real_T rtb_TmpSignalConversionAtToFile[11];
  t_stream_ptr rtb_StreamCall1_o1;
  t_stream_ptr rtb_StreamFormattedWrite_o1;
  real32_T rtb_StreamRead1_o2[10];
  int32_T rtb_StreamFormattedWrite_o2;
  int32_T rtb_StreamCall1_o3;
  int32_T rtb_StreamRead1_o5;
  boolean_T rtb_StreamRead1_o3;
  real_T K[30];
  real_T P_hat_k1[36];
  static const int8_T I[36] = { 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0,
    0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1 };

  real_T rtb_Switch[10];
  int32_T i;
  real_T tmp[25];
  real_T tmp_0[25];
  real_T tmp_1[9];
  real_T tmp_2[3];
  real_T tmp_3[5];
  real_T I_0[6];
  real_T K_0[6];
  real_T I_1[36];
  real_T I_2[36];
  real_T K_1[30];
  real_T K_2[36];
  int32_T i_0;
  real_T tmp_4[5];
  int32_T i_1;
  real_T rtb_TmpSignalConversionAtFrIn_0;
  real_T rtb_TmpSignalConversionAtFrIn_1;
  real_T u0;
  if (rtmIsMajorTimeStep(heli_q8_d6p5_M)) {
    /* set solver stop time */
    if (!(heli_q8_d6p5_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&heli_q8_d6p5_M->solverInfo,
                            ((heli_q8_d6p5_M->Timing.clockTickH0 + 1) *
        heli_q8_d6p5_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&heli_q8_d6p5_M->solverInfo,
                            ((heli_q8_d6p5_M->Timing.clockTick0 + 1) *
        heli_q8_d6p5_M->Timing.stepSize0 + heli_q8_d6p5_M->Timing.clockTickH0 *
        heli_q8_d6p5_M->Timing.stepSize0 * 4294967296.0));
    }

    {                                  /* Sample time: [0.0s, 0.0s] */
      rate_monotonic_scheduler();
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(heli_q8_d6p5_M)) {
    heli_q8_d6p5_M->Timing.t[0] = rtsiGetT(&heli_q8_d6p5_M->solverInfo);
  }

  /* Reset subsysRan breadcrumbs */
  srClearBC(heli_q8_d6p5_DW.Kalmanfilter_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(heli_q8_d6p5_DW.PitchElevationController_Subsys);
  if (rtmIsMajorTimeStep(heli_q8_d6p5_M)) {
    /* S-Function (hil_read_encoder_timebase_block): '<S2>/HIL Read Encoder Timebase' */

    /* S-Function Block: heli_q8_d6p5/Heli 3D/HIL Read Encoder Timebase (hil_read_encoder_timebase_block) */
    {
      t_error result;
      result = hil_task_read_encoder(heli_q8_d6p5_DW.HILReadEncoderTimebase_Task,
        1, &heli_q8_d6p5_DW.HILReadEncoderTimebase_Buffer[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_d6p5_M, _rt_error_message);
      } else {
        rtb_HILReadEncoderTimebase_o1 =
          heli_q8_d6p5_DW.HILReadEncoderTimebase_Buffer[0];
        rtb_HILReadEncoderTimebase_o2 =
          heli_q8_d6p5_DW.HILReadEncoderTimebase_Buffer[1];
        rtb_HILReadEncoderTimebase_o3 =
          heli_q8_d6p5_DW.HILReadEncoderTimebase_Buffer[2];
      }
    }

    /* S-Function (stream_call_block): '<S9>/Stream Call1' */

    /* S-Function Block: heli_q8_d6p5/IMU System/IMU/Stream Call1 (stream_call_block) */
    {
      t_error result = 0;
      t_boolean close_flag = (heli_q8_d6p5_P.Constant_Value != 0);
      rtb_StreamCall1_o1 = NULL;
      switch (heli_q8_d6p5_DW.StreamCall1_State) {
       case STREAM_CALL_STATE_NOT_CONNECTED:
        {
          if (!close_flag) {
            /* Make sure URI is null-terminated */
            if (string_length((char *) heli_q8_d6p5_P.StringConstant_Value, 255)
                == 255) {
              rtmSetErrorStatus(heli_q8_d6p5_M,
                                "URI passed to Stream Call block is not null-terminated!");
              result = -QERR_STRING_NOT_TERMINATED;
            } else {
              result = stream_connect((char *)
                heli_q8_d6p5_P.StringConstant_Value, true,
                heli_q8_d6p5_P.StreamCall1_SendBufferSize,
                heli_q8_d6p5_P.StreamCall1_ReceiveBufferSize,
                &heli_q8_d6p5_DW.StreamCall1_Stream);
              if (result == 0) {
                heli_q8_d6p5_DW.StreamCall1_State = STREAM_CALL_STATE_CONNECTED;
                stream_set_byte_order(heli_q8_d6p5_DW.StreamCall1_Stream,
                                      (t_stream_byte_order)
                                      heli_q8_d6p5_P.StreamCall1_Endian);
                rtb_StreamCall1_o1 = &heli_q8_d6p5_DW.StreamCall1_Stream;
              } else if (result == -QERR_WOULD_BLOCK) {
                heli_q8_d6p5_DW.StreamCall1_State = STREAM_CALL_STATE_CONNECTING;
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

            result = stream_poll(heli_q8_d6p5_DW.StreamCall1_Stream, &timeout,
                                 STREAM_POLL_CONNECT);
            if (result > 0) {
              heli_q8_d6p5_DW.StreamCall1_State = STREAM_CALL_STATE_CONNECTED;
              stream_set_byte_order(heli_q8_d6p5_DW.StreamCall1_Stream,
                                    (t_stream_byte_order)
                                    heli_q8_d6p5_P.StreamCall1_Endian);
              rtb_StreamCall1_o1 = &heli_q8_d6p5_DW.StreamCall1_Stream;
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
          rtb_StreamCall1_o1 = &heli_q8_d6p5_DW.StreamCall1_Stream;
          if (!close_flag) {
            break;
          }

          /* Fall through deliberately */
        }

       default:
        {
          t_error close_result = stream_close(heli_q8_d6p5_DW.StreamCall1_Stream);
          if (close_result == 0) {
            heli_q8_d6p5_DW.StreamCall1_State = STREAM_CALL_STATE_NOT_CONNECTED;
            heli_q8_d6p5_DW.StreamCall1_Stream = NULL;
            rtb_StreamCall1_o1 = NULL;
          } else if (result == 0) {
            result = close_result;
          }
          break;
        }
      }

      heli_q8_d6p5_B.StreamCall1_o2 = heli_q8_d6p5_DW.StreamCall1_State;
      rtb_StreamCall1_o3 = (int32_T) result;
    }

    /* S-Function (stream_formatted_write_block): '<S9>/Stream Formatted Write' */
    {
      t_error result;
      if (rtb_StreamCall1_o1 != NULL) {
        result = stream_print_utf8_char_array(*rtb_StreamCall1_o1,
          heli_q8_d6p5_P.StreamFormattedWrite_MaxUnits,
          &rtb_StreamFormattedWrite_o2, "%c\n"
          , (char) heli_q8_d6p5_P.Constant1_Value
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
    /* S-Function Block: heli_q8_d6p5/IMU System/IMU/Stream Read1 (stream_read_block) */
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
        rtb_Switch[i] = heli_q8_d6p5_P.Constant2_Value;
      }
    }

    /* End of Switch: '<S9>/Switch' */

    /* Gain: '<S9>/Gain2' incorporates:
     *  SignalConversion: '<S9>/TmpSignal ConversionAtGain2Inport1'
     */
    for (i = 0; i < 3; i++) {
      heli_q8_d6p5_B.Gain2[i] = 0.0;
      heli_q8_d6p5_B.Gain2[i] += heli_q8_d6p5_P.Gain2_Gain[i] * rtb_Switch[0];
      heli_q8_d6p5_B.Gain2[i] += heli_q8_d6p5_P.Gain2_Gain[i + 3] * rtb_Switch[2];
      heli_q8_d6p5_B.Gain2[i] += heli_q8_d6p5_P.Gain2_Gain[i + 6] * rtb_Switch[1];
    }

    /* End of Gain: '<S9>/Gain2' */

    /* Trigonometry: '<S10>/Trigonometric Function1' incorporates:
     *  Product: '<S10>/Divide1'
     *  Product: '<S10>/Product'
     *  Product: '<S10>/Product1'
     *  Sqrt: '<S10>/Sqrt'
     *  Sum: '<S10>/Add'
     */
    heli_q8_d6p5_B.TrigonometricFunction1 = atan(heli_q8_d6p5_B.Gain2[1] / sqrt
      (heli_q8_d6p5_B.Gain2[0] * heli_q8_d6p5_B.Gain2[0] + heli_q8_d6p5_B.Gain2
       [2] * heli_q8_d6p5_B.Gain2[2]));

    /* Sum: '<S2>/Sum1' incorporates:
     *  Constant: '<S2>/Constant2'
     *  Gain: '<S2>/Pitch: Count to rad'
     */
    heli_q8_d6p5_B.Sum1 = heli_q8_d6p5_P.PitchCounttorad_Gain *
      rtb_HILReadEncoderTimebase_o2 + heli_q8_d6p5_P.Constant2_Value_b;

    /* Sum: '<S2>/Sum2' incorporates:
     *  Constant: '<S2>/Constant4'
     *  Gain: '<S2>/Elevation: Count to rad'
     */
    heli_q8_d6p5_B.Sum2 = heli_q8_d6p5_P.ElevationCounttorad_Gain *
      rtb_HILReadEncoderTimebase_o3 + heli_q8_d6p5_P.Constant4_Value;

    /* Gain: '<S2>/Travel: Count to rad' */
    heli_q8_d6p5_B.TravelCounttorad = heli_q8_d6p5_P.TravelCounttorad_Gain *
      rtb_HILReadEncoderTimebase_o1;

    /* MATLAB Function: '<S3>/Gyro vector to [pitch rate, elevation rate, travle rate]' incorporates:
     *  SignalConversion: '<S8>/TmpSignal ConversionAt SFunction Inport2'
     */
    /* MATLAB Function 'IMU System/Gyro vector to [pitch rate, elevation rate, travle rate]': '<S8>:1' */
    /* '<S8>:1:3' */
    /* '<S8>:1:4' */
    /* psi = euler_angles(3); */
    /* '<S8>:1:8' */
    /* '<S8>:1:11' */
    tmp_1[0] = 1.0;
    tmp_1[3] = sin(heli_q8_d6p5_B.Sum1) * tan(heli_q8_d6p5_B.Sum2);
    tmp_1[6] = cos(heli_q8_d6p5_B.Sum1) * tan(heli_q8_d6p5_B.Sum2);
    tmp_1[1] = 0.0;
    tmp_1[4] = cos(heli_q8_d6p5_B.Sum1);
    tmp_1[7] = -sin(heli_q8_d6p5_B.Sum1);
    tmp_1[2] = 0.0;
    tmp_1[5] = sin(heli_q8_d6p5_B.Sum1) / cos(heli_q8_d6p5_B.Sum2);
    tmp_1[8] = cos(heli_q8_d6p5_B.Sum1) / cos(heli_q8_d6p5_B.Sum2);

    /* Gain: '<S9>/Gain1' incorporates:
     *  MATLAB Function: '<S3>/Gyro vector to [pitch rate, elevation rate, travle rate]'
     */
    for (i = 0; i < 3; i++) {
      tmp_2[i] = heli_q8_d6p5_P.Gain1_Gain[i + 6] * rtb_Switch[5] +
        (heli_q8_d6p5_P.Gain1_Gain[i + 3] * rtb_Switch[4] +
         heli_q8_d6p5_P.Gain1_Gain[i] * rtb_Switch[3]);
    }

    /* End of Gain: '<S9>/Gain1' */

    /* MATLAB Function: '<S3>/Gyro vector to [pitch rate, elevation rate, travle rate]' */
    for (i = 0; i < 3; i++) {
      heli_q8_d6p5_B.euler_rates[i] = 0.0;
      heli_q8_d6p5_B.euler_rates[i] += tmp_1[i] * tmp_2[0];
      heli_q8_d6p5_B.euler_rates[i] += tmp_1[i + 3] * tmp_2[1];
      heli_q8_d6p5_B.euler_rates[i] += tmp_1[i + 6] * tmp_2[2];
    }

    /* Trigonometry: '<S10>/Trigonometric Function' incorporates:
     *  Product: '<S10>/Divide'
     */
    heli_q8_d6p5_B.TrigonometricFunction = atan(heli_q8_d6p5_B.Gain2[0] /
      heli_q8_d6p5_B.Gain2[2]);

    /* RateTransition: '<S4>/Rate Transition: x' */
    if (heli_q8_d6p5_M->Timing.RateInteraction.TID1_2) {
      heli_q8_d6p5_B.RateTransitionx = heli_q8_d6p5_DW.RateTransitionx_Buffer0;
    }

    /* End of RateTransition: '<S4>/Rate Transition: x' */

    /* DeadZone: '<S4>/Dead Zone: x' */
    if (heli_q8_d6p5_B.RateTransitionx > heli_q8_d6p5_P.DeadZonex_End) {
      u0 = heli_q8_d6p5_B.RateTransitionx - heli_q8_d6p5_P.DeadZonex_End;
    } else if (heli_q8_d6p5_B.RateTransitionx >= heli_q8_d6p5_P.DeadZonex_Start)
    {
      u0 = 0.0;
    } else {
      u0 = heli_q8_d6p5_B.RateTransitionx - heli_q8_d6p5_P.DeadZonex_Start;
    }

    /* End of DeadZone: '<S4>/Dead Zone: x' */

    /* Gain: '<S4>/Joystick_gain_x' incorporates:
     *  Gain: '<S4>/Gain: x'
     */
    heli_q8_d6p5_B.Joystick_gain_x = heli_q8_d6p5_P.Gainx_Gain * u0 *
      heli_q8_d6p5_P.Joystick_gain_x;

    /* RateTransition: '<S4>/Rate Transition: y' */
    if (heli_q8_d6p5_M->Timing.RateInteraction.TID1_2) {
      heli_q8_d6p5_B.RateTransitiony = heli_q8_d6p5_DW.RateTransitiony_Buffer0;
    }

    /* End of RateTransition: '<S4>/Rate Transition: y' */

    /* DeadZone: '<S4>/Dead Zone: y' */
    if (heli_q8_d6p5_B.RateTransitiony > heli_q8_d6p5_P.DeadZoney_End) {
      u0 = heli_q8_d6p5_B.RateTransitiony - heli_q8_d6p5_P.DeadZoney_End;
    } else if (heli_q8_d6p5_B.RateTransitiony >= heli_q8_d6p5_P.DeadZoney_Start)
    {
      u0 = 0.0;
    } else {
      u0 = heli_q8_d6p5_B.RateTransitiony - heli_q8_d6p5_P.DeadZoney_Start;
    }

    /* End of DeadZone: '<S4>/Dead Zone: y' */

    /* Gain: '<S4>/Joystick_gain_y' incorporates:
     *  Gain: '<S4>/Gain: y'
     */
    heli_q8_d6p5_B.Joystick_gain_y = heli_q8_d6p5_P.Gainy_Gain * u0 *
      heli_q8_d6p5_P.Joystick_gain_y;
  }

  /* TransferFcn: '<S2>/Pitch: Transfer Fcn' */
  heli_q8_d6p5_B.PitchTransferFcn = 0.0;
  heli_q8_d6p5_B.PitchTransferFcn += heli_q8_d6p5_P.PitchTransferFcn_C *
    heli_q8_d6p5_X.PitchTransferFcn_CSTATE;
  heli_q8_d6p5_B.PitchTransferFcn += heli_q8_d6p5_P.PitchTransferFcn_D *
    heli_q8_d6p5_B.Sum1;

  /* TransferFcn: '<S2>/Elevation: Transfer Fcn' */
  heli_q8_d6p5_B.ElevationTransferFcn = 0.0;
  heli_q8_d6p5_B.ElevationTransferFcn += heli_q8_d6p5_P.ElevationTransferFcn_C *
    heli_q8_d6p5_X.ElevationTransferFcn_CSTATE;
  heli_q8_d6p5_B.ElevationTransferFcn += heli_q8_d6p5_P.ElevationTransferFcn_D *
    heli_q8_d6p5_B.Sum2;

  /* TransferFcn: '<S2>/Travel: Transfer Fcn' */
  heli_q8_d6p5_B.TravelTransferFcn = 0.0;
  heli_q8_d6p5_B.TravelTransferFcn += heli_q8_d6p5_P.TravelTransferFcn_C *
    heli_q8_d6p5_X.TravelTransferFcn_CSTATE;
  heli_q8_d6p5_B.TravelTransferFcn += heli_q8_d6p5_P.TravelTransferFcn_D *
    heli_q8_d6p5_B.TravelCounttorad;
  if (rtmIsMajorTimeStep(heli_q8_d6p5_M)) {
    /* Switch: '<S3>/Switch' incorporates:
     *  Constant: '<S3>/Enable_now'
     *  Memory: '<S3>/Memory'
     */
    if (rtb_StreamRead1_o3) {
      heli_q8_d6p5_B.Switch = heli_q8_d6p5_P.Enable_now_Value;
    } else {
      heli_q8_d6p5_B.Switch = heli_q8_d6p5_DW.Memory_PreviousInput;
    }

    /* End of Switch: '<S3>/Switch' */

    /* Outputs for Enabled SubSystem: '<Root>/Kalman filter' incorporates:
     *  EnablePort: '<S5>/Enable'
     */
    if (rtmIsMajorTimeStep(heli_q8_d6p5_M)) {
      if (heli_q8_d6p5_B.Switch > 0.0) {
        if (!heli_q8_d6p5_DW.Kalmanfilter_MODE) {
          heli_q8_d6p5_DW.Kalmanfilter_MODE = true;
        }
      } else {
        if (heli_q8_d6p5_DW.Kalmanfilter_MODE) {
          heli_q8_d6p5_DW.Kalmanfilter_MODE = false;
        }
      }
    }

    if (heli_q8_d6p5_DW.Kalmanfilter_MODE) {
      /* MATLAB Function: '<S11>/Kalman prediction step' incorporates:
       *  Constant: '<S11>/A_d'
       *  Constant: '<S11>/B_d'
       *  Constant: '<S11>/C_d'
       *  Constant: '<S11>/Q_d'
       *  Constant: '<S11>/R_d'
       *  SignalConversion: '<S14>/TmpSignal ConversionAt SFunction Inport9'
       *  UnitDelay: '<S11>/Unit Delay1'
       *  UnitDelay: '<S11>/Unit Delay2'
       *  UnitDelay: '<S5>/Provide initial cond.'
       */
      /* MATLAB Function 'Kalman filter/Kalman prediction & correction/Kalman prediction step': '<S14>:1' */
      /*  Task 5.3 */
      /* '<S14>:1:5' */
      for (i = 0; i < 5; i++) {
        for (i_1 = 0; i_1 < 6; i_1++) {
          K_1[i + 5 * i_1] = 0.0;
          for (i_0 = 0; i_0 < 6; i_0++) {
            K_1[i + 5 * i_1] += heli_q8_d6p5_P.C_d[5 * i_0 + i] *
              heli_q8_d6p5_DW.UnitDelay2_DSTATE[6 * i_1 + i_0];
          }
        }
      }

      for (i = 0; i < 5; i++) {
        for (i_1 = 0; i_1 < 5; i_1++) {
          u0 = 0.0;
          for (i_0 = 0; i_0 < 6; i_0++) {
            u0 += K_1[5 * i_0 + i] * heli_q8_d6p5_P.C_d[5 * i_0 + i_1];
          }

          tmp[i + 5 * i_1] = heli_q8_d6p5_P.R_d[5 * i_1 + i] + u0;
        }
      }

      heli_q8_d6p5_invNxN(tmp, tmp_0);
      for (i = 0; i < 6; i++) {
        for (i_1 = 0; i_1 < 5; i_1++) {
          K_1[i + 6 * i_1] = 0.0;
          for (i_0 = 0; i_0 < 6; i_0++) {
            K_1[i + 6 * i_1] += heli_q8_d6p5_DW.UnitDelay2_DSTATE[6 * i_0 + i] *
              heli_q8_d6p5_P.C_d[5 * i_0 + i_1];
          }
        }
      }

      for (i = 0; i < 6; i++) {
        for (i_1 = 0; i_1 < 5; i_1++) {
          K[i + 6 * i_1] = 0.0;
          for (i_0 = 0; i_0 < 5; i_0++) {
            K[i + 6 * i_1] += K_1[6 * i_0 + i] * tmp_0[5 * i_1 + i_0];
          }
        }
      }

      /* '<S14>:1:6' */
      if (rtb_StreamRead1_o3) {
        /* '<S14>:1:7' */
        /* '<S14>:1:8' */
        for (i = 0; i < 6; i++) {
          for (i_1 = 0; i_1 < 6; i_1++) {
            u0 = 0.0;
            for (i_0 = 0; i_0 < 5; i_0++) {
              u0 += K[6 * i_0 + i] * heli_q8_d6p5_P.C_d[5 * i_1 + i_0];
            }

            P_hat_k1[i + 6 * i_1] = (real_T)I[6 * i_1 + i] - u0;
          }
        }

        /* SignalConversion: '<S14>/TmpSignal ConversionAt SFunction Inport9' incorporates:
         *  Constant: '<S11>/C_d'
         */
        tmp_3[0] = heli_q8_d6p5_B.euler_rates[0];
        tmp_3[1] = heli_q8_d6p5_B.euler_rates[1];
        tmp_3[2] = heli_q8_d6p5_B.euler_rates[2];
        tmp_3[3] = heli_q8_d6p5_B.TrigonometricFunction;
        tmp_3[4] = heli_q8_d6p5_B.TrigonometricFunction1;

        /* '<S14>:1:9' */
        for (i = 0; i < 6; i++) {
          I_0[i] = 0.0;
          for (i_1 = 0; i_1 < 6; i_1++) {
            I_0[i] += P_hat_k1[6 * i_1 + i] *
              heli_q8_d6p5_DW.UnitDelay1_DSTATE[i_1];
          }

          K_0[i] = 0.0;
          for (i_1 = 0; i_1 < 5; i_1++) {
            K_0[i] += K[6 * i_1 + i] * tmp_3[i_1];
          }

          heli_q8_d6p5_B.x_hat_k1[i] = I_0[i] + K_0[i];
          for (i_1 = 0; i_1 < 6; i_1++) {
            u0 = 0.0;
            for (i_0 = 0; i_0 < 5; i_0++) {
              u0 += K[6 * i_0 + i] * heli_q8_d6p5_P.C_d[5 * i_1 + i_0];
            }

            I_1[i + 6 * i_1] = (real_T)I[6 * i_1 + i] - u0;
          }
        }

        for (i = 0; i < 6; i++) {
          for (i_1 = 0; i_1 < 6; i_1++) {
            P_hat_k1[i + 6 * i_1] = 0.0;
            for (i_0 = 0; i_0 < 6; i_0++) {
              P_hat_k1[i + 6 * i_1] += I_1[6 * i_0 + i] *
                heli_q8_d6p5_DW.UnitDelay2_DSTATE[6 * i_1 + i_0];
            }

            u0 = 0.0;
            for (i_0 = 0; i_0 < 5; i_0++) {
              u0 += K[6 * i_0 + i_1] * heli_q8_d6p5_P.C_d[5 * i + i_0];
            }

            I_2[i + 6 * i_1] = (real_T)I[6 * i + i_1] - u0;
          }

          for (i_1 = 0; i_1 < 5; i_1++) {
            K_1[i + 6 * i_1] = 0.0;
            for (i_0 = 0; i_0 < 5; i_0++) {
              K_1[i + 6 * i_1] += K[6 * i_0 + i] * heli_q8_d6p5_P.R_d[5 * i_1 +
                i_0];
            }
          }
        }

        for (i = 0; i < 6; i++) {
          for (i_1 = 0; i_1 < 6; i_1++) {
            I_1[i + 6 * i_1] = 0.0;
            for (i_0 = 0; i_0 < 6; i_0++) {
              I_1[i + 6 * i_1] += P_hat_k1[6 * i_0 + i] * I_2[6 * i_1 + i_0];
            }

            K_2[i + 6 * i_1] = 0.0;
            for (i_0 = 0; i_0 < 5; i_0++) {
              K_2[i + 6 * i_1] += K_1[6 * i_0 + i] * K[6 * i_0 + i_1];
            }
          }
        }

        for (i = 0; i < 6; i++) {
          for (i_1 = 0; i_1 < 6; i_1++) {
            P_hat_k1[i_1 + 6 * i] = I_1[6 * i + i_1] + K_2[6 * i + i_1];
          }
        }
      } else {
        /* '<S14>:1:11' */
        for (i = 0; i < 6; i++) {
          heli_q8_d6p5_B.x_hat_k1[i] = heli_q8_d6p5_DW.UnitDelay1_DSTATE[i];
        }

        /* '<S14>:1:12' */
        memcpy(&P_hat_k1[0], &heli_q8_d6p5_DW.UnitDelay2_DSTATE[0], 36U * sizeof
               (real_T));
      }

      /* '<S14>:1:14' */
      /* '<S14>:1:15' */
      for (i = 0; i < 6; i++) {
        I_0[i] = 0.0;
        K_0[i] = 0.0;
        K_0[i] += heli_q8_d6p5_P.B_d[i] *
          heli_q8_d6p5_DW.Provideinitialcond_DSTATE[0];
        K_0[i] += heli_q8_d6p5_P.B_d[i + 6] *
          heli_q8_d6p5_DW.Provideinitialcond_DSTATE[1];
        for (i_1 = 0; i_1 < 6; i_1++) {
          I_0[i] += heli_q8_d6p5_P.A_d[6 * i_1 + i] *
            heli_q8_d6p5_B.x_hat_k1[i_1];
          I_1[i + 6 * i_1] = 0.0;
          for (i_0 = 0; i_0 < 6; i_0++) {
            I_1[i + 6 * i_1] += heli_q8_d6p5_P.A_d[6 * i_0 + i] * P_hat_k1[6 *
              i_1 + i_0];
          }
        }

        heli_q8_d6p5_B.x_bar_k2[i] = I_0[i] + K_0[i];
      }

      for (i = 0; i < 6; i++) {
        for (i_1 = 0; i_1 < 6; i_1++) {
          u0 = 0.0;
          for (i_0 = 0; i_0 < 6; i_0++) {
            u0 += I_1[6 * i_0 + i] * heli_q8_d6p5_P.A_d[6 * i_0 + i_1];
          }

          heli_q8_d6p5_B.P_bar_k2[i + 6 * i_1] = heli_q8_d6p5_P.Q_d[6 * i_1 + i]
            + u0;
        }
      }

      /* End of MATLAB Function: '<S11>/Kalman prediction step' */

      /* SignalConversion: '<S5>/TmpSignal ConversionAtTo FileInport1' */
      for (i = 0; i < 6; i++) {
        rtb_TmpSignalConversionAtToFile[i] = heli_q8_d6p5_B.x_hat_k1[i];
      }

      rtb_TmpSignalConversionAtToFile[6] = heli_q8_d6p5_B.euler_rates[0];
      rtb_TmpSignalConversionAtToFile[7] = heli_q8_d6p5_B.euler_rates[1];
      rtb_TmpSignalConversionAtToFile[8] = heli_q8_d6p5_B.euler_rates[2];
      rtb_TmpSignalConversionAtToFile[9] = heli_q8_d6p5_B.TrigonometricFunction;
      rtb_TmpSignalConversionAtToFile[10] =
        heli_q8_d6p5_B.TrigonometricFunction1;

      /* End of SignalConversion: '<S5>/TmpSignal ConversionAtTo FileInport1' */

      /* ToFile: '<S5>/To File' */
      if (rtmIsMajorTimeStep(heli_q8_d6p5_M)) {
        {
          if (!(++heli_q8_d6p5_DW.ToFile_IWORK.Decimation % 1) &&
              (heli_q8_d6p5_DW.ToFile_IWORK.Count*12)+1 < 100000000 ) {
            FILE *fp = (FILE *) heli_q8_d6p5_DW.ToFile_PWORK.FilePtr;
            if (fp != (NULL)) {
              real_T u[12];
              heli_q8_d6p5_DW.ToFile_IWORK.Decimation = 0;
              u[0] = heli_q8_d6p5_M->Timing.t[1];
              u[1] = rtb_TmpSignalConversionAtToFile[0];
              u[2] = rtb_TmpSignalConversionAtToFile[1];
              u[3] = rtb_TmpSignalConversionAtToFile[2];
              u[4] = rtb_TmpSignalConversionAtToFile[3];
              u[5] = rtb_TmpSignalConversionAtToFile[4];
              u[6] = rtb_TmpSignalConversionAtToFile[5];
              u[7] = rtb_TmpSignalConversionAtToFile[6];
              u[8] = rtb_TmpSignalConversionAtToFile[7];
              u[9] = rtb_TmpSignalConversionAtToFile[8];
              u[10] = rtb_TmpSignalConversionAtToFile[9];
              u[11] = rtb_TmpSignalConversionAtToFile[10];
              if (fwrite(u, sizeof(real_T), 12, fp) != 12) {
                rtmSetErrorStatus(heli_q8_d6p5_M,
                                  "Error writing to MAT-file Kalman_vs_IMU.mat");
                return;
              }

              if (((++heli_q8_d6p5_DW.ToFile_IWORK.Count)*12)+1 >= 100000000) {
                (void)fprintf(stdout,
                              "*** The ToFile block will stop logging data before\n"
                              "    the simulation has ended, because it has reached\n"
                              "    the maximum number of elements (100000000)\n"
                              "    allowed in MAT-file Kalman_vs_IMU.mat.\n");
              }
            }
          }
        }
      }

      /* SignalConversion: '<S5>/TmpSignal ConversionAtTo File1Inport1' */
      for (i = 0; i < 6; i++) {
        rtb_TmpSignalConversionAtToFile[i] = heli_q8_d6p5_B.x_hat_k1[i];
      }

      rtb_TmpSignalConversionAtToFile[6] = heli_q8_d6p5_B.PitchTransferFcn;
      rtb_TmpSignalConversionAtToFile[7] = heli_q8_d6p5_B.ElevationTransferFcn;
      rtb_TmpSignalConversionAtToFile[8] = heli_q8_d6p5_B.TravelTransferFcn;
      rtb_TmpSignalConversionAtToFile[9] = heli_q8_d6p5_B.Sum1;
      rtb_TmpSignalConversionAtToFile[10] = heli_q8_d6p5_B.Sum2;

      /* End of SignalConversion: '<S5>/TmpSignal ConversionAtTo File1Inport1' */

      /* ToFile: '<S5>/To File1' */
      if (rtmIsMajorTimeStep(heli_q8_d6p5_M)) {
        {
          if (!(++heli_q8_d6p5_DW.ToFile1_IWORK.Decimation % 1) &&
              (heli_q8_d6p5_DW.ToFile1_IWORK.Count*12)+1 < 100000000 ) {
            FILE *fp = (FILE *) heli_q8_d6p5_DW.ToFile1_PWORK.FilePtr;
            if (fp != (NULL)) {
              real_T u[12];
              heli_q8_d6p5_DW.ToFile1_IWORK.Decimation = 0;
              u[0] = heli_q8_d6p5_M->Timing.t[1];
              u[1] = rtb_TmpSignalConversionAtToFile[0];
              u[2] = rtb_TmpSignalConversionAtToFile[1];
              u[3] = rtb_TmpSignalConversionAtToFile[2];
              u[4] = rtb_TmpSignalConversionAtToFile[3];
              u[5] = rtb_TmpSignalConversionAtToFile[4];
              u[6] = rtb_TmpSignalConversionAtToFile[5];
              u[7] = rtb_TmpSignalConversionAtToFile[6];
              u[8] = rtb_TmpSignalConversionAtToFile[7];
              u[9] = rtb_TmpSignalConversionAtToFile[8];
              u[10] = rtb_TmpSignalConversionAtToFile[9];
              u[11] = rtb_TmpSignalConversionAtToFile[10];
              if (fwrite(u, sizeof(real_T), 12, fp) != 12) {
                rtmSetErrorStatus(heli_q8_d6p5_M,
                                  "Error writing to MAT-file Kalman_vs_encoder.mat");
                return;
              }

              if (((++heli_q8_d6p5_DW.ToFile1_IWORK.Count)*12)+1 >= 100000000) {
                (void)fprintf(stdout,
                              "*** The ToFile block will stop logging data before\n"
                              "    the simulation has ended, because it has reached\n"
                              "    the maximum number of elements (100000000)\n"
                              "    allowed in MAT-file Kalman_vs_encoder.mat.\n");
              }
            }
          }
        }
      }

      if (rtmIsMajorTimeStep(heli_q8_d6p5_M)) {
        srUpdateBC(heli_q8_d6p5_DW.Kalmanfilter_SubsysRanBC);
      }
    }

    /* End of Outputs for SubSystem: '<Root>/Kalman filter' */

    /* Outputs for Enabled SubSystem: '<Root>/Pitch & Elevation Controller' incorporates:
     *  EnablePort: '<S6>/Enable'
     */
    if (rtmIsMajorTimeStep(heli_q8_d6p5_M)) {
      if (heli_q8_d6p5_B.Switch > 0.0) {
        if (!heli_q8_d6p5_DW.PitchElevationController_MODE) {
          heli_q8_d6p5_DW.PitchElevationController_MODE = true;
        }
      } else {
        if (heli_q8_d6p5_DW.PitchElevationController_MODE) {
          heli_q8_d6p5_DW.PitchElevationController_MODE = false;
        }
      }
    }

    /* End of Outputs for SubSystem: '<Root>/Pitch & Elevation Controller' */
  }

  /* Outputs for Enabled SubSystem: '<Root>/Pitch & Elevation Controller' incorporates:
   *  EnablePort: '<S6>/Enable'
   */
  if (heli_q8_d6p5_DW.PitchElevationController_MODE) {
    if (rtmIsMajorTimeStep(heli_q8_d6p5_M)) {
      /* SignalConversion: '<S16>/TmpSignal ConversionAtF*rInport1' */
      rtb_TmpSignalConversionAtFrIn_0 = heli_q8_d6p5_B.Joystick_gain_x;
      rtb_TmpSignalConversionAtFrIn_1 = heli_q8_d6p5_B.Joystick_gain_y;

      /* Gain: '<S16>/F*r' incorporates:
       *  SignalConversion: '<S16>/TmpSignal ConversionAtF*rInport1'
       */
      heli_q8_d6p5_B.Fr[0] = 0.0;
      heli_q8_d6p5_B.Fr[0] += heli_q8_d6p5_P.F[0] *
        heli_q8_d6p5_B.Joystick_gain_x;
      heli_q8_d6p5_B.Fr[0] += heli_q8_d6p5_P.F[2] *
        heli_q8_d6p5_B.Joystick_gain_y;
      heli_q8_d6p5_B.Fr[1] = 0.0;
      heli_q8_d6p5_B.Fr[1] += heli_q8_d6p5_P.F[1] *
        heli_q8_d6p5_B.Joystick_gain_x;
      heli_q8_d6p5_B.Fr[1] += heli_q8_d6p5_P.F[3] *
        heli_q8_d6p5_B.Joystick_gain_y;
    }

    /* SignalConversion: '<S16>/TmpSignal ConversionAtK*xInport1' incorporates:
     *  Integrator: '<S6>/Integrate -> [gamma,zeta]'
     */
    tmp_4[2] = heli_q8_d6p5_B.x_hat_k1[3];
    tmp_4[0] = heli_q8_d6p5_B.x_hat_k1[0];
    tmp_4[3] = heli_q8_d6p5_X.Integrategammazeta_CSTATE[0];
    tmp_4[1] = heli_q8_d6p5_B.x_hat_k1[1];
    tmp_4[4] = heli_q8_d6p5_X.Integrategammazeta_CSTATE[1];

    /* Sum: '<S16>/Sum3' incorporates:
     *  Gain: '<S16>/K*x'
     *  SignalConversion: '<S16>/TmpSignal ConversionAtK*xInport1'
     */
    for (i = 0; i < 2; i++) {
      u0 = 0.0;
      for (i_1 = 0; i_1 < 5; i_1++) {
        u0 += heli_q8_d6p5_P.K_feedback[(i_1 << 1) + i] * tmp_4[i_1];
      }

      heli_q8_d6p5_B.Sum3[i] = heli_q8_d6p5_B.Fr[i] - u0;
    }

    /* End of Sum: '<S16>/Sum3' */
    if (rtmIsMajorTimeStep(heli_q8_d6p5_M)) {
      /* Constant: '<S6>/V_s0' */
      heli_q8_d6p5_B.V_s0[0] = heli_q8_d6p5_P.V_s0_Value[0];
      heli_q8_d6p5_B.V_s0[1] = heli_q8_d6p5_P.V_s0_Value[1];

      /* Sum: '<S6>/Sum3' */
      heli_q8_d6p5_B.Sum3_k[0] = heli_q8_d6p5_B.x_hat_k1[0] -
        rtb_TmpSignalConversionAtFrIn_0;
      heli_q8_d6p5_B.Sum3_k[1] = heli_q8_d6p5_B.x_hat_k1[3] -
        rtb_TmpSignalConversionAtFrIn_1;
    }

    /* Sum: '<S6>/Sum1' */
    heli_q8_d6p5_B.Sum1_e[0] = heli_q8_d6p5_B.Sum3[0] + heli_q8_d6p5_B.V_s0[0];
    heli_q8_d6p5_B.Sum1_e[1] = heli_q8_d6p5_B.Sum3[1] + heli_q8_d6p5_B.V_s0[1];
    if (rtmIsMajorTimeStep(heli_q8_d6p5_M)) {
      srUpdateBC(heli_q8_d6p5_DW.PitchElevationController_Subsys);
    }
  }

  /* End of Outputs for SubSystem: '<Root>/Pitch & Elevation Controller' */
  if (rtmIsMajorTimeStep(heli_q8_d6p5_M)) {
  }

  /* Gain: '<S1>/Front gain' incorporates:
   *  Sum: '<S1>/Add'
   */
  u0 = (heli_q8_d6p5_B.Sum1_e[0] - heli_q8_d6p5_B.Sum1_e[1]) *
    heli_q8_d6p5_P.Frontgain_Gain;

  /* Saturate: '<S2>/Front motor: Saturation' */
  if (u0 > heli_q8_d6p5_P.FrontmotorSaturation_UpperSat) {
    heli_q8_d6p5_B.FrontmotorSaturation =
      heli_q8_d6p5_P.FrontmotorSaturation_UpperSat;
  } else if (u0 < heli_q8_d6p5_P.FrontmotorSaturation_LowerSat) {
    heli_q8_d6p5_B.FrontmotorSaturation =
      heli_q8_d6p5_P.FrontmotorSaturation_LowerSat;
  } else {
    heli_q8_d6p5_B.FrontmotorSaturation = u0;
  }

  /* End of Saturate: '<S2>/Front motor: Saturation' */

  /* Gain: '<S1>/Back gain' incorporates:
   *  Sum: '<S1>/Subtract'
   */
  u0 = (heli_q8_d6p5_B.Sum1_e[1] + heli_q8_d6p5_B.Sum1_e[0]) *
    heli_q8_d6p5_P.Backgain_Gain;

  /* Saturate: '<S2>/Back motor: Saturation' */
  if (u0 > heli_q8_d6p5_P.BackmotorSaturation_UpperSat) {
    heli_q8_d6p5_B.BackmotorSaturation =
      heli_q8_d6p5_P.BackmotorSaturation_UpperSat;
  } else if (u0 < heli_q8_d6p5_P.BackmotorSaturation_LowerSat) {
    heli_q8_d6p5_B.BackmotorSaturation =
      heli_q8_d6p5_P.BackmotorSaturation_LowerSat;
  } else {
    heli_q8_d6p5_B.BackmotorSaturation = u0;
  }

  /* End of Saturate: '<S2>/Back motor: Saturation' */
  if (rtmIsMajorTimeStep(heli_q8_d6p5_M)) {
    /* S-Function (hil_write_analog_block): '<S2>/HIL Write Analog' */

    /* S-Function Block: heli_q8_d6p5/Heli 3D/HIL Write Analog (hil_write_analog_block) */
    {
      t_error result;
      heli_q8_d6p5_DW.HILWriteAnalog_Buffer[0] =
        heli_q8_d6p5_B.FrontmotorSaturation;
      heli_q8_d6p5_DW.HILWriteAnalog_Buffer[1] =
        heli_q8_d6p5_B.BackmotorSaturation;
      result = hil_write_analog(heli_q8_d6p5_DW.HILInitialize_Card,
        heli_q8_d6p5_P.HILWriteAnalog_channels, 2,
        &heli_q8_d6p5_DW.HILWriteAnalog_Buffer[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_d6p5_M, _rt_error_message);
      }
    }

    /* S-Function (stop_with_error_block): '<S9>/Stop with Call Error' */

    /* S-Function Block: heli_q8_d6p5/IMU System/IMU/Stop with Call Error (stop_with_error_block) */
    {
      if (rtb_StreamCall1_o3 < 0) {
        msg_get_error_messageA(NULL, rtb_StreamCall1_o3, _rt_error_message,
          sizeof(_rt_error_message));
        rtmSetErrorStatus(heli_q8_d6p5_M, _rt_error_message);
        return;
      }
    }

    /* S-Function (stop_with_error_block): '<S9>/Stop with Read Error' */

    /* S-Function Block: heli_q8_d6p5/IMU System/IMU/Stop with Read Error (stop_with_error_block) */
    {
      if (rtb_StreamRead1_o5 < 0) {
        msg_get_error_messageA(NULL, rtb_StreamRead1_o5, _rt_error_message,
          sizeof(_rt_error_message));
        rtmSetErrorStatus(heli_q8_d6p5_M, _rt_error_message);
        return;
      }
    }
  }
}

/* Model update function for TID0 */
void heli_q8_d6p5_update0(void)        /* Sample time: [0.0s, 0.0s] */
{
  int32_T i;
  if (rtmIsMajorTimeStep(heli_q8_d6p5_M)) {
    /* Update for Memory: '<S3>/Memory' */
    heli_q8_d6p5_DW.Memory_PreviousInput = heli_q8_d6p5_B.Switch;

    /* Update for Enabled SubSystem: '<Root>/Kalman filter' incorporates:
     *  Update for EnablePort: '<S5>/Enable'
     */
    if (heli_q8_d6p5_DW.Kalmanfilter_MODE) {
      /* Update for UnitDelay: '<S11>/Unit Delay1' */
      for (i = 0; i < 6; i++) {
        heli_q8_d6p5_DW.UnitDelay1_DSTATE[i] = heli_q8_d6p5_B.x_bar_k2[i];
      }

      /* End of Update for UnitDelay: '<S11>/Unit Delay1' */

      /* Update for UnitDelay: '<S5>/Provide initial cond.' */
      heli_q8_d6p5_DW.Provideinitialcond_DSTATE[0] = heli_q8_d6p5_B.Sum3[0];
      heli_q8_d6p5_DW.Provideinitialcond_DSTATE[1] = heli_q8_d6p5_B.Sum3[1];

      /* Update for UnitDelay: '<S11>/Unit Delay2' */
      memcpy(&heli_q8_d6p5_DW.UnitDelay2_DSTATE[0], &heli_q8_d6p5_B.P_bar_k2[0],
             36U * sizeof(real_T));
    }

    /* End of Update for SubSystem: '<Root>/Kalman filter' */
  }

  if (rtmIsMajorTimeStep(heli_q8_d6p5_M)) {
    rt_ertODEUpdateContinuousStates(&heli_q8_d6p5_M->solverInfo);
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
  if (!(++heli_q8_d6p5_M->Timing.clockTick0)) {
    ++heli_q8_d6p5_M->Timing.clockTickH0;
  }

  heli_q8_d6p5_M->Timing.t[0] = rtsiGetSolverStopTime
    (&heli_q8_d6p5_M->solverInfo);

  /* Update absolute time */
  /* The "clockTick1" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick1"
   * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick1 and the high bits
   * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++heli_q8_d6p5_M->Timing.clockTick1)) {
    ++heli_q8_d6p5_M->Timing.clockTickH1;
  }

  heli_q8_d6p5_M->Timing.t[1] = heli_q8_d6p5_M->Timing.clockTick1 *
    heli_q8_d6p5_M->Timing.stepSize1 + heli_q8_d6p5_M->Timing.clockTickH1 *
    heli_q8_d6p5_M->Timing.stepSize1 * 4294967296.0;
}

/* Derivatives for root system: '<Root>' */
void heli_q8_d6p5_derivatives(void)
{
  XDot_heli_q8_d6p5_T *_rtXdot;
  _rtXdot = ((XDot_heli_q8_d6p5_T *) heli_q8_d6p5_M->ModelData.derivs);

  /* Derivatives for TransferFcn: '<S2>/Pitch: Transfer Fcn' */
  _rtXdot->PitchTransferFcn_CSTATE = 0.0;
  _rtXdot->PitchTransferFcn_CSTATE += heli_q8_d6p5_P.PitchTransferFcn_A *
    heli_q8_d6p5_X.PitchTransferFcn_CSTATE;
  _rtXdot->PitchTransferFcn_CSTATE += heli_q8_d6p5_B.Sum1;

  /* Derivatives for TransferFcn: '<S2>/Elevation: Transfer Fcn' */
  _rtXdot->ElevationTransferFcn_CSTATE = 0.0;
  _rtXdot->ElevationTransferFcn_CSTATE += heli_q8_d6p5_P.ElevationTransferFcn_A *
    heli_q8_d6p5_X.ElevationTransferFcn_CSTATE;
  _rtXdot->ElevationTransferFcn_CSTATE += heli_q8_d6p5_B.Sum2;

  /* Derivatives for TransferFcn: '<S2>/Travel: Transfer Fcn' */
  _rtXdot->TravelTransferFcn_CSTATE = 0.0;
  _rtXdot->TravelTransferFcn_CSTATE += heli_q8_d6p5_P.TravelTransferFcn_A *
    heli_q8_d6p5_X.TravelTransferFcn_CSTATE;
  _rtXdot->TravelTransferFcn_CSTATE += heli_q8_d6p5_B.TravelCounttorad;

  /* Derivatives for Enabled SubSystem: '<Root>/Pitch & Elevation Controller' */
  if (heli_q8_d6p5_DW.PitchElevationController_MODE) {
    /* Derivatives for Integrator: '<S6>/Integrate -> [gamma,zeta]' */
    _rtXdot->Integrategammazeta_CSTATE[0] = heli_q8_d6p5_B.Sum3_k[0];
    _rtXdot->Integrategammazeta_CSTATE[1] = heli_q8_d6p5_B.Sum3_k[1];
  } else {
    {
      real_T *dx;
      int_T i;
      dx = &(((XDot_heli_q8_d6p5_T *) heli_q8_d6p5_M->ModelData.derivs)
             ->Integrategammazeta_CSTATE[0]);
      for (i=0; i < 2; i++) {
        dx[i] = 0.0;
      }
    }
  }

  /* End of Derivatives for SubSystem: '<Root>/Pitch & Elevation Controller' */
}

/* Model output function for TID2 */
void heli_q8_d6p5_output2(void)        /* Sample time: [0.01s, 0.0s] */
{
  /* S-Function (game_controller_block): '<S4>/Game Controller' */

  /* S-Function Block: heli_q8_d6p5/Joystick1/Game Controller (game_controller_block) */
  {
    if (heli_q8_d6p5_P.GameController_Enabled) {
      t_game_controller_states state;
      t_boolean new_data;
      t_error result;
      result = game_controller_poll(heli_q8_d6p5_DW.GameController_Controller,
        &state, &new_data);
      if (result == 0) {
        heli_q8_d6p5_B.GameController_o4 = state.x;
        heli_q8_d6p5_B.GameController_o5 = state.y;
      }
    } else {
      heli_q8_d6p5_B.GameController_o4 = 0;
      heli_q8_d6p5_B.GameController_o5 = 0;
    }
  }
}

/* Model update function for TID2 */
void heli_q8_d6p5_update2(void)        /* Sample time: [0.01s, 0.0s] */
{
  /* Update for RateTransition: '<S4>/Rate Transition: x' */
  heli_q8_d6p5_DW.RateTransitionx_Buffer0 = heli_q8_d6p5_B.GameController_o4;

  /* Update for RateTransition: '<S4>/Rate Transition: y' */
  heli_q8_d6p5_DW.RateTransitiony_Buffer0 = heli_q8_d6p5_B.GameController_o5;

  /* Update absolute time */
  /* The "clockTick2" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick2"
   * and "Timing.stepSize2". Size of "clockTick2" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick2 and the high bits
   * Timing.clockTickH2. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++heli_q8_d6p5_M->Timing.clockTick2)) {
    ++heli_q8_d6p5_M->Timing.clockTickH2;
  }

  heli_q8_d6p5_M->Timing.t[2] = heli_q8_d6p5_M->Timing.clockTick2 *
    heli_q8_d6p5_M->Timing.stepSize2 + heli_q8_d6p5_M->Timing.clockTickH2 *
    heli_q8_d6p5_M->Timing.stepSize2 * 4294967296.0;
}

/* Model output wrapper function for compatibility with a static main program */
void heli_q8_d6p5_output(int_T tid)
{
  switch (tid) {
   case 0 :
    heli_q8_d6p5_output0();
    break;

   case 2 :
    heli_q8_d6p5_output2();
    break;

   default :
    break;
  }
}

/* Model update wrapper function for compatibility with a static main program */
void heli_q8_d6p5_update(int_T tid)
{
  switch (tid) {
   case 0 :
    heli_q8_d6p5_update0();
    break;

   case 2 :
    heli_q8_d6p5_update2();
    break;

   default :
    break;
  }
}

/* Model initialize function */
void heli_q8_d6p5_initialize(void)
{
  {
    int32_T i;

    /* Start for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

    /* S-Function Block: heli_q8_d6p5/HIL Initialize (hil_initialize_block) */
    {
      t_int result;
      t_boolean is_switching;
      result = hil_open("q8_usb", "0", &heli_q8_d6p5_DW.HILInitialize_Card);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_d6p5_M, _rt_error_message);
        return;
      }

      is_switching = false;
      result = hil_set_card_specific_options(heli_q8_d6p5_DW.HILInitialize_Card,
        "update_rate=normal;decimation=1", 32);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_d6p5_M, _rt_error_message);
        return;
      }

      result = hil_watchdog_clear(heli_q8_d6p5_DW.HILInitialize_Card);
      if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_d6p5_M, _rt_error_message);
        return;
      }

      if ((heli_q8_d6p5_P.HILInitialize_set_analog_input_ && !is_switching) ||
          (heli_q8_d6p5_P.HILInitialize_set_analog_inpu_m && is_switching)) {
        {
          int_T i1;
          real_T *dw_AIMinimums = &heli_q8_d6p5_DW.HILInitialize_AIMinimums[0];
          for (i1=0; i1 < 8; i1++) {
            dw_AIMinimums[i1] = heli_q8_d6p5_P.HILInitialize_analog_input_mini;
          }
        }

        {
          int_T i1;
          real_T *dw_AIMaximums = &heli_q8_d6p5_DW.HILInitialize_AIMaximums[0];
          for (i1=0; i1 < 8; i1++) {
            dw_AIMaximums[i1] = heli_q8_d6p5_P.HILInitialize_analog_input_maxi;
          }
        }

        result = hil_set_analog_input_ranges(heli_q8_d6p5_DW.HILInitialize_Card,
          heli_q8_d6p5_P.HILInitialize_analog_input_chan, 8U,
          &heli_q8_d6p5_DW.HILInitialize_AIMinimums[0],
          &heli_q8_d6p5_DW.HILInitialize_AIMaximums[0]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(heli_q8_d6p5_M, _rt_error_message);
          return;
        }
      }

      if ((heli_q8_d6p5_P.HILInitialize_set_analog_output && !is_switching) ||
          (heli_q8_d6p5_P.HILInitialize_set_analog_outp_b && is_switching)) {
        {
          int_T i1;
          real_T *dw_AOMinimums = &heli_q8_d6p5_DW.HILInitialize_AOMinimums[0];
          for (i1=0; i1 < 8; i1++) {
            dw_AOMinimums[i1] = heli_q8_d6p5_P.HILInitialize_analog_output_min;
          }
        }

        {
          int_T i1;
          real_T *dw_AOMaximums = &heli_q8_d6p5_DW.HILInitialize_AOMaximums[0];
          for (i1=0; i1 < 8; i1++) {
            dw_AOMaximums[i1] = heli_q8_d6p5_P.HILInitialize_analog_output_max;
          }
        }

        result = hil_set_analog_output_ranges(heli_q8_d6p5_DW.HILInitialize_Card,
          heli_q8_d6p5_P.HILInitialize_analog_output_cha, 8U,
          &heli_q8_d6p5_DW.HILInitialize_AOMinimums[0],
          &heli_q8_d6p5_DW.HILInitialize_AOMaximums[0]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(heli_q8_d6p5_M, _rt_error_message);
          return;
        }
      }

      if ((heli_q8_d6p5_P.HILInitialize_set_analog_outp_e && !is_switching) ||
          (heli_q8_d6p5_P.HILInitialize_set_analog_outp_j && is_switching)) {
        {
          int_T i1;
          real_T *dw_AOVoltages = &heli_q8_d6p5_DW.HILInitialize_AOVoltages[0];
          for (i1=0; i1 < 8; i1++) {
            dw_AOVoltages[i1] = heli_q8_d6p5_P.HILInitialize_initial_analog_ou;
          }
        }

        result = hil_write_analog(heli_q8_d6p5_DW.HILInitialize_Card,
          heli_q8_d6p5_P.HILInitialize_analog_output_cha, 8U,
          &heli_q8_d6p5_DW.HILInitialize_AOVoltages[0]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(heli_q8_d6p5_M, _rt_error_message);
          return;
        }
      }

      if (heli_q8_d6p5_P.HILInitialize_set_analog_outp_p) {
        {
          int_T i1;
          real_T *dw_AOVoltages = &heli_q8_d6p5_DW.HILInitialize_AOVoltages[0];
          for (i1=0; i1 < 8; i1++) {
            dw_AOVoltages[i1] = heli_q8_d6p5_P.HILInitialize_watchdog_analog_o;
          }
        }

        result = hil_watchdog_set_analog_expiration_state
          (heli_q8_d6p5_DW.HILInitialize_Card,
           heli_q8_d6p5_P.HILInitialize_analog_output_cha, 8U,
           &heli_q8_d6p5_DW.HILInitialize_AOVoltages[0]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(heli_q8_d6p5_M, _rt_error_message);
          return;
        }
      }

      if ((heli_q8_d6p5_P.HILInitialize_set_encoder_param && !is_switching) ||
          (heli_q8_d6p5_P.HILInitialize_set_encoder_par_m && is_switching)) {
        {
          int_T i1;
          int32_T *dw_QuadratureModes =
            &heli_q8_d6p5_DW.HILInitialize_QuadratureModes[0];
          for (i1=0; i1 < 8; i1++) {
            dw_QuadratureModes[i1] = heli_q8_d6p5_P.HILInitialize_quadrature;
          }
        }

        result = hil_set_encoder_quadrature_mode
          (heli_q8_d6p5_DW.HILInitialize_Card,
           heli_q8_d6p5_P.HILInitialize_encoder_channels, 8U,
           (t_encoder_quadrature_mode *)
           &heli_q8_d6p5_DW.HILInitialize_QuadratureModes[0]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(heli_q8_d6p5_M, _rt_error_message);
          return;
        }
      }

      if ((heli_q8_d6p5_P.HILInitialize_set_encoder_count && !is_switching) ||
          (heli_q8_d6p5_P.HILInitialize_set_encoder_cou_k && is_switching)) {
        {
          int_T i1;
          int32_T *dw_InitialEICounts =
            &heli_q8_d6p5_DW.HILInitialize_InitialEICounts[0];
          for (i1=0; i1 < 8; i1++) {
            dw_InitialEICounts[i1] =
              heli_q8_d6p5_P.HILInitialize_initial_encoder_c;
          }
        }

        result = hil_set_encoder_counts(heli_q8_d6p5_DW.HILInitialize_Card,
          heli_q8_d6p5_P.HILInitialize_encoder_channels, 8U,
          &heli_q8_d6p5_DW.HILInitialize_InitialEICounts[0]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(heli_q8_d6p5_M, _rt_error_message);
          return;
        }
      }

      if ((heli_q8_d6p5_P.HILInitialize_set_pwm_params_at && !is_switching) ||
          (heli_q8_d6p5_P.HILInitialize_set_pwm_params__f && is_switching)) {
        uint32_T num_duty_cycle_modes = 0;
        uint32_T num_frequency_modes = 0;

        {
          int_T i1;
          int32_T *dw_POModeValues =
            &heli_q8_d6p5_DW.HILInitialize_POModeValues[0];
          for (i1=0; i1 < 8; i1++) {
            dw_POModeValues[i1] = heli_q8_d6p5_P.HILInitialize_pwm_modes;
          }
        }

        result = hil_set_pwm_mode(heli_q8_d6p5_DW.HILInitialize_Card,
          heli_q8_d6p5_P.HILInitialize_pwm_channels, 8U, (t_pwm_mode *)
          &heli_q8_d6p5_DW.HILInitialize_POModeValues[0]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(heli_q8_d6p5_M, _rt_error_message);
          return;
        }

        {
          int_T i1;
          const uint32_T *p_HILInitialize_pwm_channels =
            heli_q8_d6p5_P.HILInitialize_pwm_channels;
          int32_T *dw_POModeValues =
            &heli_q8_d6p5_DW.HILInitialize_POModeValues[0];
          for (i1=0; i1 < 8; i1++) {
            if (dw_POModeValues[i1] == PWM_DUTY_CYCLE_MODE || dw_POModeValues[i1]
                == PWM_ONE_SHOT_MODE || dw_POModeValues[i1] == PWM_TIME_MODE) {
              heli_q8_d6p5_DW.HILInitialize_POSortedChans[num_duty_cycle_modes] =
                p_HILInitialize_pwm_channels[i1];
              heli_q8_d6p5_DW.HILInitialize_POSortedFreqs[num_duty_cycle_modes] =
                heli_q8_d6p5_P.HILInitialize_pwm_frequency;
              num_duty_cycle_modes++;
            } else {
              heli_q8_d6p5_DW.HILInitialize_POSortedChans[7U -
                num_frequency_modes] = p_HILInitialize_pwm_channels[i1];
              heli_q8_d6p5_DW.HILInitialize_POSortedFreqs[7U -
                num_frequency_modes] =
                heli_q8_d6p5_P.HILInitialize_pwm_frequency;
              num_frequency_modes++;
            }
          }
        }

        if (num_duty_cycle_modes > 0) {
          result = hil_set_pwm_frequency(heli_q8_d6p5_DW.HILInitialize_Card,
            &heli_q8_d6p5_DW.HILInitialize_POSortedChans[0],
            num_duty_cycle_modes, &heli_q8_d6p5_DW.HILInitialize_POSortedFreqs[0]);
          if (result < 0) {
            msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
              (_rt_error_message));
            rtmSetErrorStatus(heli_q8_d6p5_M, _rt_error_message);
            return;
          }
        }

        if (num_frequency_modes > 0) {
          result = hil_set_pwm_duty_cycle(heli_q8_d6p5_DW.HILInitialize_Card,
            &heli_q8_d6p5_DW.HILInitialize_POSortedChans[num_duty_cycle_modes],
            num_frequency_modes,
            &heli_q8_d6p5_DW.HILInitialize_POSortedFreqs[num_duty_cycle_modes]);
          if (result < 0) {
            msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
              (_rt_error_message));
            rtmSetErrorStatus(heli_q8_d6p5_M, _rt_error_message);
            return;
          }
        }

        {
          int_T i1;
          int32_T *dw_POModeValues =
            &heli_q8_d6p5_DW.HILInitialize_POModeValues[0];
          for (i1=0; i1 < 8; i1++) {
            dw_POModeValues[i1] = heli_q8_d6p5_P.HILInitialize_pwm_configuration;
          }
        }

        {
          int_T i1;
          int32_T *dw_POAlignValues =
            &heli_q8_d6p5_DW.HILInitialize_POAlignValues[0];
          for (i1=0; i1 < 8; i1++) {
            dw_POAlignValues[i1] = heli_q8_d6p5_P.HILInitialize_pwm_alignment;
          }
        }

        {
          int_T i1;
          int32_T *dw_POPolarityVals =
            &heli_q8_d6p5_DW.HILInitialize_POPolarityVals[0];
          for (i1=0; i1 < 8; i1++) {
            dw_POPolarityVals[i1] = heli_q8_d6p5_P.HILInitialize_pwm_polarity;
          }
        }

        result = hil_set_pwm_configuration(heli_q8_d6p5_DW.HILInitialize_Card,
          heli_q8_d6p5_P.HILInitialize_pwm_channels, 8U,
          (t_pwm_configuration *) &heli_q8_d6p5_DW.HILInitialize_POModeValues[0],
          (t_pwm_alignment *) &heli_q8_d6p5_DW.HILInitialize_POAlignValues[0],
          (t_pwm_polarity *) &heli_q8_d6p5_DW.HILInitialize_POPolarityVals[0]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(heli_q8_d6p5_M, _rt_error_message);
          return;
        }

        {
          int_T i1;
          real_T *dw_POSortedFreqs =
            &heli_q8_d6p5_DW.HILInitialize_POSortedFreqs[0];
          for (i1=0; i1 < 8; i1++) {
            dw_POSortedFreqs[i1] =
              heli_q8_d6p5_P.HILInitialize_pwm_leading_deadb;
          }
        }

        {
          int_T i1;
          real_T *dw_POValues = &heli_q8_d6p5_DW.HILInitialize_POValues[0];
          for (i1=0; i1 < 8; i1++) {
            dw_POValues[i1] = heli_q8_d6p5_P.HILInitialize_pwm_trailing_dead;
          }
        }

        result = hil_set_pwm_deadband(heli_q8_d6p5_DW.HILInitialize_Card,
          heli_q8_d6p5_P.HILInitialize_pwm_channels, 8U,
          &heli_q8_d6p5_DW.HILInitialize_POSortedFreqs[0],
          &heli_q8_d6p5_DW.HILInitialize_POValues[0]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(heli_q8_d6p5_M, _rt_error_message);
          return;
        }
      }

      if ((heli_q8_d6p5_P.HILInitialize_set_pwm_outputs_a && !is_switching) ||
          (heli_q8_d6p5_P.HILInitialize_set_pwm_outputs_g && is_switching)) {
        {
          int_T i1;
          real_T *dw_POValues = &heli_q8_d6p5_DW.HILInitialize_POValues[0];
          for (i1=0; i1 < 8; i1++) {
            dw_POValues[i1] = heli_q8_d6p5_P.HILInitialize_initial_pwm_outpu;
          }
        }

        result = hil_write_pwm(heli_q8_d6p5_DW.HILInitialize_Card,
          heli_q8_d6p5_P.HILInitialize_pwm_channels, 8U,
          &heli_q8_d6p5_DW.HILInitialize_POValues[0]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(heli_q8_d6p5_M, _rt_error_message);
          return;
        }
      }

      if (heli_q8_d6p5_P.HILInitialize_set_pwm_outputs_o) {
        {
          int_T i1;
          real_T *dw_POValues = &heli_q8_d6p5_DW.HILInitialize_POValues[0];
          for (i1=0; i1 < 8; i1++) {
            dw_POValues[i1] = heli_q8_d6p5_P.HILInitialize_watchdog_pwm_outp;
          }
        }

        result = hil_watchdog_set_pwm_expiration_state
          (heli_q8_d6p5_DW.HILInitialize_Card,
           heli_q8_d6p5_P.HILInitialize_pwm_channels, 8U,
           &heli_q8_d6p5_DW.HILInitialize_POValues[0]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(heli_q8_d6p5_M, _rt_error_message);
          return;
        }
      }
    }

    /* Start for S-Function (hil_read_encoder_timebase_block): '<S2>/HIL Read Encoder Timebase' */

    /* S-Function Block: heli_q8_d6p5/Heli 3D/HIL Read Encoder Timebase (hil_read_encoder_timebase_block) */
    {
      t_error result;
      result = hil_task_create_encoder_reader(heli_q8_d6p5_DW.HILInitialize_Card,
        heli_q8_d6p5_P.HILReadEncoderTimebase_samples_,
        heli_q8_d6p5_P.HILReadEncoderTimebase_channels, 3,
        &heli_q8_d6p5_DW.HILReadEncoderTimebase_Task);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_d6p5_M, _rt_error_message);
      }
    }

    /* Start for S-Function (stream_call_block): '<S9>/Stream Call1' */

    /* S-Function Block: heli_q8_d6p5/IMU System/IMU/Stream Call1 (stream_call_block) */
    {
      heli_q8_d6p5_DW.StreamCall1_State = STREAM_CALL_STATE_NOT_CONNECTED;
      heli_q8_d6p5_DW.StreamCall1_Stream = NULL;
    }

    /* Start for RateTransition: '<S4>/Rate Transition: x' */
    heli_q8_d6p5_B.RateTransitionx = heli_q8_d6p5_P.RateTransitionx_X0;

    /* Start for RateTransition: '<S4>/Rate Transition: y' */
    heli_q8_d6p5_B.RateTransitiony = heli_q8_d6p5_P.RateTransitiony_X0;

    /* Start for Enabled SubSystem: '<Root>/Kalman filter' */
    heli_q8_d6p5_DW.Kalmanfilter_MODE = false;

    /* Start for ToFile: '<S5>/To File' */
    {
      FILE *fp = (NULL);
      char fileName[509] = "Kalman_vs_IMU.mat";
      if ((fp = fopen(fileName, "wb")) == (NULL)) {
        rtmSetErrorStatus(heli_q8_d6p5_M,
                          "Error creating .mat file Kalman_vs_IMU.mat");
        return;
      }

      if (rt_WriteMat4FileHeader(fp,12,0,"Kalman_vs_IMU")) {
        rtmSetErrorStatus(heli_q8_d6p5_M,
                          "Error writing mat file header to file Kalman_vs_IMU.mat");
        return;
      }

      heli_q8_d6p5_DW.ToFile_IWORK.Count = 0;
      heli_q8_d6p5_DW.ToFile_IWORK.Decimation = -1;
      heli_q8_d6p5_DW.ToFile_PWORK.FilePtr = fp;
    }

    /* Start for ToFile: '<S5>/To File1' */
    {
      FILE *fp = (NULL);
      char fileName[509] = "Kalman_vs_encoder.mat";
      if ((fp = fopen(fileName, "wb")) == (NULL)) {
        rtmSetErrorStatus(heli_q8_d6p5_M,
                          "Error creating .mat file Kalman_vs_encoder.mat");
        return;
      }

      if (rt_WriteMat4FileHeader(fp,12,0,"Kalman_vs_encoder")) {
        rtmSetErrorStatus(heli_q8_d6p5_M,
                          "Error writing mat file header to file Kalman_vs_encoder.mat");
        return;
      }

      heli_q8_d6p5_DW.ToFile1_IWORK.Count = 0;
      heli_q8_d6p5_DW.ToFile1_IWORK.Decimation = -1;
      heli_q8_d6p5_DW.ToFile1_PWORK.FilePtr = fp;
    }

    /* InitializeConditions for Enabled SubSystem: '<Root>/Kalman filter' */
    /* InitializeConditions for UnitDelay: '<S11>/Unit Delay1' */
    for (i = 0; i < 6; i++) {
      heli_q8_d6p5_DW.UnitDelay1_DSTATE[i] =
        heli_q8_d6p5_P.UnitDelay1_InitialCondition[i];
    }

    /* End of InitializeConditions for UnitDelay: '<S11>/Unit Delay1' */

    /* InitializeConditions for UnitDelay: '<S5>/Provide initial cond.' */
    heli_q8_d6p5_DW.Provideinitialcond_DSTATE[0] =
      heli_q8_d6p5_P.Provideinitialcond_InitialCondi[0];
    heli_q8_d6p5_DW.Provideinitialcond_DSTATE[1] =
      heli_q8_d6p5_P.Provideinitialcond_InitialCondi[1];

    /* InitializeConditions for UnitDelay: '<S11>/Unit Delay2' */
    memcpy(&heli_q8_d6p5_DW.UnitDelay2_DSTATE[0],
           &heli_q8_d6p5_P.UnitDelay2_InitialCondition[0], 36U * sizeof(real_T));

    /* End of InitializeConditions for SubSystem: '<Root>/Kalman filter' */

    /* Start for Enabled SubSystem: '<Root>/Pitch & Elevation Controller' */
    heli_q8_d6p5_DW.PitchElevationController_MODE = false;

    /* End of Start for SubSystem: '<Root>/Pitch & Elevation Controller' */

    /* InitializeConditions for Enabled SubSystem: '<Root>/Pitch & Elevation Controller' */
    /* InitializeConditions for Integrator: '<S6>/Integrate -> [gamma,zeta]' */
    heli_q8_d6p5_X.Integrategammazeta_CSTATE[0] =
      heli_q8_d6p5_P.Integrategammazeta_IC;
    heli_q8_d6p5_X.Integrategammazeta_CSTATE[1] =
      heli_q8_d6p5_P.Integrategammazeta_IC;

    /* End of InitializeConditions for SubSystem: '<Root>/Pitch & Elevation Controller' */
    /* Start for S-Function (game_controller_block): '<S4>/Game Controller' */

    /* S-Function Block: heli_q8_d6p5/Joystick1/Game Controller (game_controller_block) */
    {
      if (heli_q8_d6p5_P.GameController_Enabled) {
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
          (heli_q8_d6p5_P.GameController_ControllerNumber,
           heli_q8_d6p5_P.GameController_BufferSize, deadzone, saturation,
           heli_q8_d6p5_P.GameController_AutoCenter, 0, 1.0,
           &heli_q8_d6p5_DW.GameController_Controller);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(heli_q8_d6p5_M, _rt_error_message);
        }
      }
    }
  }

  /* InitializeConditions for RateTransition: '<S4>/Rate Transition: x' */
  heli_q8_d6p5_DW.RateTransitionx_Buffer0 = heli_q8_d6p5_P.RateTransitionx_X0;

  /* InitializeConditions for RateTransition: '<S4>/Rate Transition: y' */
  heli_q8_d6p5_DW.RateTransitiony_Buffer0 = heli_q8_d6p5_P.RateTransitiony_X0;

  /* InitializeConditions for TransferFcn: '<S2>/Pitch: Transfer Fcn' */
  heli_q8_d6p5_X.PitchTransferFcn_CSTATE = 0.0;

  /* InitializeConditions for TransferFcn: '<S2>/Elevation: Transfer Fcn' */
  heli_q8_d6p5_X.ElevationTransferFcn_CSTATE = 0.0;

  /* InitializeConditions for TransferFcn: '<S2>/Travel: Transfer Fcn' */
  heli_q8_d6p5_X.TravelTransferFcn_CSTATE = 0.0;

  /* InitializeConditions for Memory: '<S3>/Memory' */
  heli_q8_d6p5_DW.Memory_PreviousInput = heli_q8_d6p5_P.Memory_X0;
}

/* Model terminate function */
void heli_q8_d6p5_terminate(void)
{
  /* Terminate for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: heli_q8_d6p5/HIL Initialize (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    t_uint32 num_final_analog_outputs = 0;
    t_uint32 num_final_pwm_outputs = 0;
    hil_task_stop_all(heli_q8_d6p5_DW.HILInitialize_Card);
    hil_monitor_stop_all(heli_q8_d6p5_DW.HILInitialize_Card);
    is_switching = false;
    if ((heli_q8_d6p5_P.HILInitialize_set_analog_out_ex && !is_switching) ||
        (heli_q8_d6p5_P.HILInitialize_set_analog_outp_c && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOVoltages = &heli_q8_d6p5_DW.HILInitialize_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = heli_q8_d6p5_P.HILInitialize_final_analog_outp;
        }
      }

      num_final_analog_outputs = 8U;
    }

    if ((heli_q8_d6p5_P.HILInitialize_set_pwm_output_ap && !is_switching) ||
        (heli_q8_d6p5_P.HILInitialize_set_pwm_outputs_p && is_switching)) {
      {
        int_T i1;
        real_T *dw_POValues = &heli_q8_d6p5_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = heli_q8_d6p5_P.HILInitialize_final_pwm_outputs;
        }
      }

      num_final_pwm_outputs = 8U;
    }

    if (0
        || num_final_analog_outputs > 0
        || num_final_pwm_outputs > 0
        ) {
      /* Attempt to write the final outputs atomically (due to firmware issue in old Q2-USB). Otherwise write channels individually */
      result = hil_write(heli_q8_d6p5_DW.HILInitialize_Card
                         , heli_q8_d6p5_P.HILInitialize_analog_output_cha,
                         num_final_analog_outputs
                         , heli_q8_d6p5_P.HILInitialize_pwm_channels,
                         num_final_pwm_outputs
                         , NULL, 0
                         , NULL, 0
                         , &heli_q8_d6p5_DW.HILInitialize_AOVoltages[0]
                         , &heli_q8_d6p5_DW.HILInitialize_POValues[0]
                         , (t_boolean *) NULL
                         , NULL
                         );
      if (result == -QERR_HIL_WRITE_NOT_SUPPORTED) {
        t_error local_result;
        result = 0;

        /* The hil_write operation is not supported by this card. Write final outputs for each channel type */
        if (num_final_analog_outputs > 0) {
          local_result = hil_write_analog(heli_q8_d6p5_DW.HILInitialize_Card,
            heli_q8_d6p5_P.HILInitialize_analog_output_cha,
            num_final_analog_outputs, &heli_q8_d6p5_DW.HILInitialize_AOVoltages
            [0]);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (num_final_pwm_outputs > 0) {
          local_result = hil_write_pwm(heli_q8_d6p5_DW.HILInitialize_Card,
            heli_q8_d6p5_P.HILInitialize_pwm_channels, num_final_pwm_outputs,
            &heli_q8_d6p5_DW.HILInitialize_POValues[0]);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(heli_q8_d6p5_M, _rt_error_message);
        }
      }
    }

    hil_task_delete_all(heli_q8_d6p5_DW.HILInitialize_Card);
    hil_monitor_delete_all(heli_q8_d6p5_DW.HILInitialize_Card);
    hil_close(heli_q8_d6p5_DW.HILInitialize_Card);
    heli_q8_d6p5_DW.HILInitialize_Card = NULL;
  }

  /* Terminate for S-Function (stream_call_block): '<S9>/Stream Call1' */

  /* S-Function Block: heli_q8_d6p5/IMU System/IMU/Stream Call1 (stream_call_block) */
  {
    if (heli_q8_d6p5_DW.StreamCall1_Stream != NULL) {
      stream_close(heli_q8_d6p5_DW.StreamCall1_Stream);
      heli_q8_d6p5_DW.StreamCall1_Stream = NULL;
    }
  }

  /* Terminate for Enabled SubSystem: '<Root>/Kalman filter' */

  /* Terminate for ToFile: '<S5>/To File' */
  {
    FILE *fp = (FILE *) heli_q8_d6p5_DW.ToFile_PWORK.FilePtr;
    if (fp != (NULL)) {
      char fileName[509] = "Kalman_vs_IMU.mat";
      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(heli_q8_d6p5_M,
                          "Error closing MAT-file Kalman_vs_IMU.mat");
        return;
      }

      if ((fp = fopen(fileName, "r+b")) == (NULL)) {
        rtmSetErrorStatus(heli_q8_d6p5_M,
                          "Error reopening MAT-file Kalman_vs_IMU.mat");
        return;
      }

      if (rt_WriteMat4FileHeader(fp, 12, heli_q8_d6p5_DW.ToFile_IWORK.Count,
           "Kalman_vs_IMU")) {
        rtmSetErrorStatus(heli_q8_d6p5_M,
                          "Error writing header for Kalman_vs_IMU to MAT-file Kalman_vs_IMU.mat");
      }

      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(heli_q8_d6p5_M,
                          "Error closing MAT-file Kalman_vs_IMU.mat");
        return;
      }

      heli_q8_d6p5_DW.ToFile_PWORK.FilePtr = (NULL);
    }
  }

  /* Terminate for ToFile: '<S5>/To File1' */
  {
    FILE *fp = (FILE *) heli_q8_d6p5_DW.ToFile1_PWORK.FilePtr;
    if (fp != (NULL)) {
      char fileName[509] = "Kalman_vs_encoder.mat";
      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(heli_q8_d6p5_M,
                          "Error closing MAT-file Kalman_vs_encoder.mat");
        return;
      }

      if ((fp = fopen(fileName, "r+b")) == (NULL)) {
        rtmSetErrorStatus(heli_q8_d6p5_M,
                          "Error reopening MAT-file Kalman_vs_encoder.mat");
        return;
      }

      if (rt_WriteMat4FileHeader(fp, 12, heli_q8_d6p5_DW.ToFile1_IWORK.Count,
           "Kalman_vs_encoder")) {
        rtmSetErrorStatus(heli_q8_d6p5_M,
                          "Error writing header for Kalman_vs_encoder to MAT-file Kalman_vs_encoder.mat");
      }

      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(heli_q8_d6p5_M,
                          "Error closing MAT-file Kalman_vs_encoder.mat");
        return;
      }

      heli_q8_d6p5_DW.ToFile1_PWORK.FilePtr = (NULL);
    }
  }

  /* End of Terminate for SubSystem: '<Root>/Kalman filter' */

  /* Terminate for S-Function (game_controller_block): '<S4>/Game Controller' */

  /* S-Function Block: heli_q8_d6p5/Joystick1/Game Controller (game_controller_block) */
  {
    if (heli_q8_d6p5_P.GameController_Enabled) {
      game_controller_close(heli_q8_d6p5_DW.GameController_Controller);
      heli_q8_d6p5_DW.GameController_Controller = NULL;
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
  heli_q8_d6p5_output(tid);
}

void MdlUpdate(int_T tid)
{
  if (tid == 1)
    tid = 0;
  heli_q8_d6p5_update(tid);
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
  heli_q8_d6p5_initialize();
}

void MdlTerminate(void)
{
  heli_q8_d6p5_terminate();
}

/* Registration function */
RT_MODEL_heli_q8_d6p5_T *heli_q8_d6p5(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* non-finite (run-time) assignments */
  heli_q8_d6p5_P.Constant2_Value = rtNaN;

  /* initialize real-time model */
  (void) memset((void *)heli_q8_d6p5_M, 0,
                sizeof(RT_MODEL_heli_q8_d6p5_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&heli_q8_d6p5_M->solverInfo,
                          &heli_q8_d6p5_M->Timing.simTimeStep);
    rtsiSetTPtr(&heli_q8_d6p5_M->solverInfo, &rtmGetTPtr(heli_q8_d6p5_M));
    rtsiSetStepSizePtr(&heli_q8_d6p5_M->solverInfo,
                       &heli_q8_d6p5_M->Timing.stepSize0);
    rtsiSetdXPtr(&heli_q8_d6p5_M->solverInfo, &heli_q8_d6p5_M->ModelData.derivs);
    rtsiSetContStatesPtr(&heli_q8_d6p5_M->solverInfo, (real_T **)
                         &heli_q8_d6p5_M->ModelData.contStates);
    rtsiSetNumContStatesPtr(&heli_q8_d6p5_M->solverInfo,
      &heli_q8_d6p5_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&heli_q8_d6p5_M->solverInfo,
      &heli_q8_d6p5_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&heli_q8_d6p5_M->solverInfo,
      &heli_q8_d6p5_M->ModelData.periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&heli_q8_d6p5_M->solverInfo,
      &heli_q8_d6p5_M->ModelData.periodicContStateRanges);
    rtsiSetErrorStatusPtr(&heli_q8_d6p5_M->solverInfo, (&rtmGetErrorStatus
      (heli_q8_d6p5_M)));
    rtsiSetRTModelPtr(&heli_q8_d6p5_M->solverInfo, heli_q8_d6p5_M);
  }

  rtsiSetSimTimeStep(&heli_q8_d6p5_M->solverInfo, MAJOR_TIME_STEP);
  heli_q8_d6p5_M->ModelData.intgData.f[0] = heli_q8_d6p5_M->ModelData.odeF[0];
  heli_q8_d6p5_M->ModelData.contStates = ((real_T *) &heli_q8_d6p5_X);
  rtsiSetSolverData(&heli_q8_d6p5_M->solverInfo, (void *)
                    &heli_q8_d6p5_M->ModelData.intgData);
  rtsiSetSolverName(&heli_q8_d6p5_M->solverInfo,"ode1");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = heli_q8_d6p5_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    mdlTsMap[2] = 2;
    heli_q8_d6p5_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    heli_q8_d6p5_M->Timing.sampleTimes =
      (&heli_q8_d6p5_M->Timing.sampleTimesArray[0]);
    heli_q8_d6p5_M->Timing.offsetTimes =
      (&heli_q8_d6p5_M->Timing.offsetTimesArray[0]);

    /* task periods */
    heli_q8_d6p5_M->Timing.sampleTimes[0] = (0.0);
    heli_q8_d6p5_M->Timing.sampleTimes[1] = (0.002);
    heli_q8_d6p5_M->Timing.sampleTimes[2] = (0.01);

    /* task offsets */
    heli_q8_d6p5_M->Timing.offsetTimes[0] = (0.0);
    heli_q8_d6p5_M->Timing.offsetTimes[1] = (0.0);
    heli_q8_d6p5_M->Timing.offsetTimes[2] = (0.0);
  }

  rtmSetTPtr(heli_q8_d6p5_M, &heli_q8_d6p5_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = heli_q8_d6p5_M->Timing.sampleHitArray;
    int_T *mdlPerTaskSampleHits = heli_q8_d6p5_M->Timing.perTaskSampleHitsArray;
    heli_q8_d6p5_M->Timing.perTaskSampleHits = (&mdlPerTaskSampleHits[0]);
    mdlSampleHits[0] = 1;
    heli_q8_d6p5_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(heli_q8_d6p5_M, -1);
  heli_q8_d6p5_M->Timing.stepSize0 = 0.002;
  heli_q8_d6p5_M->Timing.stepSize1 = 0.002;
  heli_q8_d6p5_M->Timing.stepSize2 = 0.01;

  /* External mode info */
  heli_q8_d6p5_M->Sizes.checksums[0] = (2635934938U);
  heli_q8_d6p5_M->Sizes.checksums[1] = (2361613546U);
  heli_q8_d6p5_M->Sizes.checksums[2] = (636252762U);
  heli_q8_d6p5_M->Sizes.checksums[3] = (3806466203U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[8];
    heli_q8_d6p5_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = (sysRanDType *)&heli_q8_d6p5_DW.Kalmanfilter_SubsysRanBC;
    systemRan[6] = (sysRanDType *)&heli_q8_d6p5_DW.Kalmanfilter_SubsysRanBC;
    systemRan[7] = (sysRanDType *)
      &heli_q8_d6p5_DW.PitchElevationController_Subsys;
    rteiSetModelMappingInfoPtr(heli_q8_d6p5_M->extModeInfo,
      &heli_q8_d6p5_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(heli_q8_d6p5_M->extModeInfo,
                        heli_q8_d6p5_M->Sizes.checksums);
    rteiSetTPtr(heli_q8_d6p5_M->extModeInfo, rtmGetTPtr(heli_q8_d6p5_M));
  }

  heli_q8_d6p5_M->solverInfoPtr = (&heli_q8_d6p5_M->solverInfo);
  heli_q8_d6p5_M->Timing.stepSize = (0.002);
  rtsiSetFixedStepSize(&heli_q8_d6p5_M->solverInfo, 0.002);
  rtsiSetSolverMode(&heli_q8_d6p5_M->solverInfo, SOLVER_MODE_MULTITASKING);

  /* block I/O */
  heli_q8_d6p5_M->ModelData.blockIO = ((void *) &heli_q8_d6p5_B);
  (void) memset(((void *) &heli_q8_d6p5_B), 0,
                sizeof(B_heli_q8_d6p5_T));

  {
    int32_T i;
    for (i = 0; i < 6; i++) {
      heli_q8_d6p5_B.x_bar_k2[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      heli_q8_d6p5_B.x_hat_k1[i] = 0.0;
    }

    for (i = 0; i < 36; i++) {
      heli_q8_d6p5_B.P_bar_k2[i] = 0.0;
    }

    heli_q8_d6p5_B.Gain2[0] = 0.0;
    heli_q8_d6p5_B.Gain2[1] = 0.0;
    heli_q8_d6p5_B.Gain2[2] = 0.0;
    heli_q8_d6p5_B.TrigonometricFunction1 = 0.0;
    heli_q8_d6p5_B.Sum1 = 0.0;
    heli_q8_d6p5_B.Sum2 = 0.0;
    heli_q8_d6p5_B.TravelCounttorad = 0.0;
    heli_q8_d6p5_B.TrigonometricFunction = 0.0;
    heli_q8_d6p5_B.RateTransitionx = 0.0;
    heli_q8_d6p5_B.Joystick_gain_x = 0.0;
    heli_q8_d6p5_B.RateTransitiony = 0.0;
    heli_q8_d6p5_B.Joystick_gain_y = 0.0;
    heli_q8_d6p5_B.PitchTransferFcn = 0.0;
    heli_q8_d6p5_B.ElevationTransferFcn = 0.0;
    heli_q8_d6p5_B.TravelTransferFcn = 0.0;
    heli_q8_d6p5_B.Switch = 0.0;
    heli_q8_d6p5_B.FrontmotorSaturation = 0.0;
    heli_q8_d6p5_B.BackmotorSaturation = 0.0;
    heli_q8_d6p5_B.GameController_o4 = 0.0;
    heli_q8_d6p5_B.GameController_o5 = 0.0;
    heli_q8_d6p5_B.Fr[0] = 0.0;
    heli_q8_d6p5_B.Fr[1] = 0.0;
    heli_q8_d6p5_B.Sum3[0] = 0.0;
    heli_q8_d6p5_B.Sum3[1] = 0.0;
    heli_q8_d6p5_B.V_s0[0] = 0.0;
    heli_q8_d6p5_B.V_s0[1] = 0.0;
    heli_q8_d6p5_B.Sum1_e[0] = 0.0;
    heli_q8_d6p5_B.Sum1_e[1] = 0.0;
    heli_q8_d6p5_B.Sum3_k[0] = 0.0;
    heli_q8_d6p5_B.Sum3_k[1] = 0.0;
    heli_q8_d6p5_B.euler_rates[0] = 0.0;
    heli_q8_d6p5_B.euler_rates[1] = 0.0;
    heli_q8_d6p5_B.euler_rates[2] = 0.0;
  }

  /* parameters */
  heli_q8_d6p5_M->ModelData.defaultParam = ((real_T *)&heli_q8_d6p5_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &heli_q8_d6p5_X;
    heli_q8_d6p5_M->ModelData.contStates = (x);
    (void) memset((void *)&heli_q8_d6p5_X, 0,
                  sizeof(X_heli_q8_d6p5_T));
  }

  /* states (dwork) */
  heli_q8_d6p5_M->ModelData.dwork = ((void *) &heli_q8_d6p5_DW);
  (void) memset((void *)&heli_q8_d6p5_DW, 0,
                sizeof(DW_heli_q8_d6p5_T));

  {
    int32_T i;
    for (i = 0; i < 6; i++) {
      heli_q8_d6p5_DW.UnitDelay1_DSTATE[i] = 0.0;
    }
  }

  heli_q8_d6p5_DW.Provideinitialcond_DSTATE[0] = 0.0;
  heli_q8_d6p5_DW.Provideinitialcond_DSTATE[1] = 0.0;

  {
    int32_T i;
    for (i = 0; i < 36; i++) {
      heli_q8_d6p5_DW.UnitDelay2_DSTATE[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      heli_q8_d6p5_DW.HILInitialize_AIMinimums[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      heli_q8_d6p5_DW.HILInitialize_AIMaximums[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      heli_q8_d6p5_DW.HILInitialize_AOMinimums[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      heli_q8_d6p5_DW.HILInitialize_AOMaximums[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      heli_q8_d6p5_DW.HILInitialize_AOVoltages[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      heli_q8_d6p5_DW.HILInitialize_FilterFrequency[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      heli_q8_d6p5_DW.HILInitialize_POSortedFreqs[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      heli_q8_d6p5_DW.HILInitialize_POValues[i] = 0.0;
    }
  }

  heli_q8_d6p5_DW.RateTransitionx_Buffer0 = 0.0;
  heli_q8_d6p5_DW.RateTransitiony_Buffer0 = 0.0;
  heli_q8_d6p5_DW.Memory_PreviousInput = 0.0;
  heli_q8_d6p5_DW.HILWriteAnalog_Buffer[0] = 0.0;
  heli_q8_d6p5_DW.HILWriteAnalog_Buffer[1] = 0.0;

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    heli_q8_d6p5_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 25;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.B = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.P = &rtPTransTable;
  }

  /* Initialize Sizes */
  heli_q8_d6p5_M->Sizes.numContStates = (5);/* Number of continuous states */
  heli_q8_d6p5_M->Sizes.numPeriodicContStates = (0);/* Number of periodic continuous states */
  heli_q8_d6p5_M->Sizes.numY = (0);    /* Number of model outputs */
  heli_q8_d6p5_M->Sizes.numU = (0);    /* Number of model inputs */
  heli_q8_d6p5_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  heli_q8_d6p5_M->Sizes.numSampTimes = (3);/* Number of sample times */
  heli_q8_d6p5_M->Sizes.numBlocks = (109);/* Number of blocks */
  heli_q8_d6p5_M->Sizes.numBlockIO = (28);/* Number of block outputs */
  heli_q8_d6p5_M->Sizes.numBlockPrms = (621);/* Sum of parameter "widths" */
  return heli_q8_d6p5_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
