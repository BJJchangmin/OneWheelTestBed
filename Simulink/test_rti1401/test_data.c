/*
 * test_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "test".
 *
 * Model version              : 1.68
 * Simulink Coder version : 8.13 (R2017b) 24-Jul-2017
 * C source code generated on : Sun Jul 20 19:48:44 2025
 *
 * Target selection: rti1401.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Custom Processor->Custom
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "test.h"
#include "test_private.h"

/* Block parameters (auto storage) */
P_test_T test_P = {
  /* Variable: Ts
   * Referenced by:
   *   '<S8>/Gain'
   *   '<S8>/Gain1'
   *   '<S14>/gain'
   *   '<S16>/Constant'
   *   '<S16>/gain'
   *   '<S39>/Gain1'
   *   '<S69>/Constant1'
   *   '<S58>/Constant'
   *   '<S58>/gain'
   *   '<S61>/Constant'
   *   '<S61>/gain'
   *   '<S78>/Constant1'
   *   '<S89>/gain'
   *   '<S51>/Constant'
   *   '<S51>/gain'
   *   '<S55>/Constant'
   *   '<S55>/gain'
   *   '<S80>/gain'
   *   '<S81>/Constant'
   *   '<S81>/gain'
   *   '<S82>/gain'
   *   '<S83>/Constant'
   *   '<S83>/gain'
   *   '<S84>/gain'
   */
  0.01,

  /* Expression: 1
   * Referenced by: '<S39>/Constant3'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S39>/Constant2'
   */
  0.0,

  /* Expression: 2*pi
   * Referenced by: '<S98>/Constant1'
   */
  6.2831853071795862,

  /* Expression: 60
   * Referenced by: '<S98>/Constant5'
   */
  60.0,

  /* Expression: 190
   * Referenced by: '<S98>/N_dri'
   */
  190.0,

  /* Expression: 9
   * Referenced by: '<S106>/Constant'
   */
  9.0,

  /* Expression: 0.5
   * Referenced by: '<Root>/Saturation'
   */
  0.5,

  /* Expression: -0.5
   * Referenced by: '<Root>/Saturation'
   */
  -0.5,

  /* Expression: 1
   * Referenced by: '<Root>/Constant'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S8>/NMT_CS'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S8>/NMT_Node_ID'
   */
  0.0,

  /* Expression: 2*pi/60
   * Referenced by: '<S2>/rpm2rad2'
   */
  0.10471975511965977,

  /* Expression: 190
   * Referenced by: '<S8>/N_dri'
   */
  190.0,

  /* Expression: 0.001
   * Referenced by: '<S2>/mA2A'
   */
  0.001,

  /* Expression: 51
   * Referenced by: '<S2>/Motor torque Constant'
   */
  51.0,

  /* Expression: 0.001
   * Referenced by: '<S2>/Torque Constant1'
   */
  0.001,

  /* Expression: 0.001
   * Referenced by: '<S2>/mA2A2'
   */
  0.001,

  /* Expression: 51
   * Referenced by: '<S2>/Motor torque Constant1'
   */
  51.0,

  /* Expression: 0.001
   * Referenced by: '<S2>/Torque Constant2'
   */
  0.001,

  /* Expression: 318
   * Referenced by: '<S8>/N_str'
   */
  318.0,

  /* Expression: 2*pi/60
   * Referenced by: '<S2>/rpm2rad3'
   */
  0.10471975511965977,

  /* Expression: 0.001
   * Referenced by: '<S2>/mA2A1'
   */
  0.001,

  /* Expression: 13.7
   * Referenced by: '<S2>/Motor torque Constant2'
   */
  13.7,

  /* Expression: 0.001
   * Referenced by: '<S2>/Torque Constant3'
   */
  0.001,

  /* Expression: 756
   * Referenced by: '<S8>/N_sus'
   */
  756.0,

  /* Expression: 2*pi/60
   * Referenced by: '<S2>/rpm2rad1'
   */
  0.10471975511965977,

  /* Expression: 0
   * Referenced by: '<S14>/d'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S14>/d1'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S16>/Constant1'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S16>/d1'
   */
  0.0,

  /* Expression: 100
   * Referenced by: '<S8>/Wheel_acc_cutoff'
   */
  100.0,

  /* Expression: 2*pi
   * Referenced by: '<S16>/gain2'
   */
  6.2831853071795862,

  /* Expression: 2
   * Referenced by: '<S16>/gain1'
   */
  2.0,

  /* Expression: 0
   * Referenced by: '<S16>/d'
   */
  0.0,

  /* Expression: 6
   * Referenced by: '<S8>/Sys_Ctrlword'
   */
  6.0,

  /* Expression: 8
   * Referenced by: '<S8>/Steering Input Mode'
   */
  8.0,

  /* Expression: 10
   * Referenced by: '<S8>/sus_pos_ref_ratelimit'
   */
  10.0,

  /* Computed Parameter: sampletime_WtEt
   * Referenced by: '<S62>/sample time'
   */
  0.01,

  /* Expression: 0
   * Referenced by: '<S8>/control_on//off'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S42>/Sus_Target_pos'
   */
  0.0,

  /* Expression: 20
   * Referenced by: '<S42>/Saturation1'
   */
  20.0,

  /* Expression: -20
   * Referenced by: '<S42>/Saturation1'
   */
  -20.0,

  /* Expression: 0
   * Referenced by: '<S62>/Delay Input2'
   */
  0.0,

  /* Expression: -1
   * Referenced by: '<S42>/Gain'
   */
  -1.0,

  /* Expression: 0
   * Referenced by: '<S61>/d1'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S61>/Constant1'
   */
  1.0,

  /* Expression: 0.5
   * Referenced by: '<S8>/sus_pos_ref_cutoff'
   */
  0.5,

  /* Expression: 2*pi
   * Referenced by: '<S61>/gain2'
   */
  6.2831853071795862,

  /* Expression: 2
   * Referenced by: '<S61>/gain1'
   */
  2.0,

  /* Expression: 0
   * Referenced by: '<S61>/d'
   */
  0.0,

  /* Expression: 500*4
   * Referenced by: '<S8>/cpt_sus'
   */
  2000.0,

  /* Expression: 360
   * Referenced by: '<S42>/Constant1'
   */
  360.0,

  /* Expression: 0
   * Referenced by: '<S8>/Driving Input Mode'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S40>/Constant'
   */
  0.0,

  /* Expression: 30
   * Referenced by: '<S8>/dri_vel_ref_ratelimit'
   */
  30.0,

  /* Computed Parameter: sampletime_WtEt_j
   * Referenced by: '<S56>/sample time'
   */
  0.01,

  /* Expression: 0
   * Referenced by: '<S8>/dri_target_vel_ref'
   */
  0.0,

  /* Expression: 10
   * Referenced by: '<S44>/Saturation2'
   */
  10.0,

  /* Expression: -10
   * Referenced by: '<S44>/Saturation2'
   */
  -10.0,

  /* Expression: 0
   * Referenced by: '<S56>/Delay Input2'
   */
  0.0,

  /* Expression: -1
   * Referenced by: '<S44>/Gain1'
   */
  -1.0,

  /* Expression: 0
   * Referenced by: '<S55>/d1'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S55>/Constant1'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S8>/dri_vel_ref_cutoff'
   */
  1.0,

  /* Expression: 2*pi
   * Referenced by: '<S55>/gain2'
   */
  6.2831853071795862,

  /* Expression: 2
   * Referenced by: '<S55>/gain1'
   */
  2.0,

  /* Expression: 0
   * Referenced by: '<S55>/d'
   */
  0.0,

  /* Expression: 360
   * Referenced by: '<S44>/Constant3'
   */
  360.0,

  /* Expression: 2*pi
   * Referenced by: '<S44>/Constant2'
   */
  6.2831853071795862,

  /* Expression: 0.15
   * Referenced by: '<S8>/radius'
   */
  0.15,

  /* Expression: 60/360
   * Referenced by: '<S44>/Constant4'
   */
  0.16666666666666666,

  /* Computed Parameter: Merge1_InitialOutput
   * Referenced by: '<S102>/Merge1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S43>/Constant'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S8>/Delay1'
   */
  0.0,

  /* Expression: 0.1
   * Referenced by: '<S8>/dri_torque_ref_freq'
   */
  0.1,

  /* Expression: 0
   * Referenced by: '<S8>/dri_torque_ref_mag'
   */
  0.0,

  /* Computed Parameter: sampletime_WtEt_m
   * Referenced by: '<S53>/sample time'
   */
  0.01,

  /* Expression: 10
   * Referenced by: '<S43>/Saturation2'
   */
  10.0,

  /* Expression: -10
   * Referenced by: '<S43>/Saturation2'
   */
  -10.0,

  /* Expression: 0
   * Referenced by: '<S53>/Delay Input2'
   */
  0.0,

  /* Expression: -1
   * Referenced by: '<S43>/Gain1'
   */
  -1.0,

  /* Expression: 0
   * Referenced by: '<S51>/d1'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S51>/Constant1'
   */
  1.0,

  /* Expression: 2*pi
   * Referenced by: '<S51>/gain2'
   */
  6.2831853071795862,

  /* Expression: 2
   * Referenced by: '<S51>/gain1'
   */
  2.0,

  /* Expression: 0
   * Referenced by: '<S51>/d'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S8>/ID_OnOff'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S8>/Delay2'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S39>/Constant1'
   */
  1.0,

  /* Expression: 120
   * Referenced by: '<S39>/Switch'
   */
  120.0,

  /* Expression: 51
   * Referenced by: '<S39>/Torque Constant'
   */
  51.0,

  /* Expression: 55.08
   * Referenced by: '<S39>/Constant'
   */
  55.08,

  /* Expression: 1000
   * Referenced by: '<S39>/Gain'
   */
  1000.0,

  /* Expression: 55.08
   * Referenced by: '<S79>/Constant'
   */
  55.08,

  /* Expression: 0.4
   * Referenced by: '<S8>/wheel_Jn'
   */
  0.4,

  /* Expression: 0
   * Referenced by: '<S8>/dri_FF_OnOff'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S82>/d'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S82>/d1'
   */
  0.0,

  /* Expression: 2.016
   * Referenced by: '<S8>/wheel_Bn'
   */
  2.016,

  /* Expression: 0
   * Referenced by: '<S83>/d1'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S83>/Constant1'
   */
  1.0,

  /* Expression: 0.1
   * Referenced by: '<S8>/dri_FF_CutOff'
   */
  0.1,

  /* Expression: 2*pi
   * Referenced by: '<S83>/gain2'
   */
  6.2831853071795862,

  /* Expression: 2
   * Referenced by: '<S83>/gain1'
   */
  2.0,

  /* Expression: 0
   * Referenced by: '<S83>/d'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S8>/dri_PID_zeta'
   */
  1.0,

  /* Expression: 3
   * Referenced by: '<S78>/Saturation'
   */
  3.0,

  /* Expression: 0.5
   * Referenced by: '<S78>/Saturation'
   */
  0.5,

  /* Expression: 2
   * Referenced by: '<S78>/gain 1'
   */
  2.0,

  /* Expression: 0.1
   * Referenced by: '<S8>/dri_PID_CutOff'
   */
  0.1,

  /* Expression: 2*pi
   * Referenced by: '<S78>/gain '
   */
  6.2831853071795862,

  /* Expression: 0
   * Referenced by: '<S8>/dri_PID_OnOff'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S65>/Constant'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S84>/d1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S84>/d'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S76>/Delay'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S8>/dri_DOB_OnOff'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S80>/d'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S80>/d1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S81>/d1'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S81>/Constant1'
   */
  1.0,

  /* Expression: 0.1
   * Referenced by: '<S8>/dri_DOB_CutOff'
   */
  0.1,

  /* Expression: 2*pi
   * Referenced by: '<S81>/gain2'
   */
  6.2831853071795862,

  /* Expression: 2
   * Referenced by: '<S81>/gain1'
   */
  2.0,

  /* Expression: 0
   * Referenced by: '<S81>/d'
   */
  0.0,

  /* Expression: 190
   * Referenced by: '<S79>/Constant2'
   */
  190.0,

  /* Expression: 1000
   * Referenced by: '<S79>/Constant1'
   */
  1000.0,

  /* Expression: -1
   * Referenced by: '<S79>/Gain1'
   */
  -1.0,

  /* Expression: 1000
   * Referenced by: '<S79>/Gain'
   */
  1000.0,

  /* Expression: 10
   * Referenced by: '<S8>/str_pos_ref_ratelimit'
   */
  10.0,

  /* Computed Parameter: sampletime_WtEt_k
   * Referenced by: '<S59>/sample time'
   */
  0.01,

  /* Expression: 0
   * Referenced by: '<S41>/Str_Target_pos'
   */
  0.0,

  /* Expression: 20
   * Referenced by: '<S41>/Saturation'
   */
  20.0,

  /* Expression: -20
   * Referenced by: '<S41>/Saturation'
   */
  -20.0,

  /* Expression: 0
   * Referenced by: '<S59>/Delay Input2'
   */
  0.0,

  /* Expression: -1
   * Referenced by: '<S41>/Gain'
   */
  -1.0,

  /* Expression: 0
   * Referenced by: '<S58>/d1'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S58>/Constant1'
   */
  1.0,

  /* Expression: 0.5
   * Referenced by: '<S8>/str_pos_ref_cutoff'
   */
  0.5,

  /* Expression: 2*pi
   * Referenced by: '<S58>/gain2'
   */
  6.2831853071795862,

  /* Expression: 2
   * Referenced by: '<S58>/gain1'
   */
  2.0,

  /* Expression: 0
   * Referenced by: '<S58>/d'
   */
  0.0,

  /* Expression: 2048*4
   * Referenced by: '<S8>/cpt_str'
   */
  8192.0,

  /* Expression: 360
   * Referenced by: '<S41>/Constant'
   */
  360.0,

  /* Expression: 55.08
   * Referenced by: '<S70>/Constant'
   */
  55.08,

  /* Expression: 1
   * Referenced by: '<S8>/str_PID_zeta'
   */
  1.0,

  /* Expression: 3
   * Referenced by: '<S69>/Saturation'
   */
  3.0,

  /* Expression: 0.5
   * Referenced by: '<S69>/Saturation'
   */
  0.5,

  /* Expression: 2
   * Referenced by: '<S69>/gain 1'
   */
  2.0,

  /* Expression: 0.1
   * Referenced by: '<S8>/str_PID_CutOff'
   */
  0.1,

  /* Expression: 2*pi
   * Referenced by: '<S69>/gain '
   */
  6.2831853071795862,

  /* Expression: 2.64
   * Referenced by: '<S8>/steer_Jn'
   */
  2.64,

  /* Expression: 18.5
   * Referenced by: '<S8>/steer_Bn'
   */
  18.5,

  /* Expression: 0
   * Referenced by: '<S8>/str_PID_OnOff'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S89>/d1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S89>/d'
   */
  0.0,

  /* Expression: 315
   * Referenced by: '<S70>/Constant2'
   */
  315.0,

  /* Expression: 1000
   * Referenced by: '<S70>/Constant1'
   */
  1000.0,

  /* Expression: -1
   * Referenced by: '<S70>/Gain1'
   */
  -1.0,

  /* Expression: 1000
   * Referenced by: '<S70>/Gain'
   */
  1000.0,

  /* Expression: 1000
   * Referenced by: '<S6>/Constant1'
   */
  1000.0,

  /* Expression: 360
   * Referenced by: '<S94>/Constant2'
   */
  360.0,

  /* Expression: 360
   * Referenced by: '<S94>/Constant3'
   */
  360.0,

  /* Expression: 0
   * Referenced by: '<S95>/Constant1'
   */
  0.0,

  /* Expression: 360
   * Referenced by: '<S95>/Constant2'
   */
  360.0,

  /* Expression: 360
   * Referenced by: '<S95>/Constant3'
   */
  360.0,

  /* Expression: 0
   * Referenced by: '<S8>/acc_bias'
   */
  0.0,

  /* Expression: 300
   * Referenced by: '<S100>/Constant'
   */
  300.0,

  /* Expression: 0.0161
   * Referenced by: '<S100>/V'
   */
  0.0161,

  /* Expression: 600
   * Referenced by: '<S100>/Ample Gain'
   */
  600.0,

  /* Expression: 1
   * Referenced by: '<S8>/Load_cell_Gain'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S8>/Grf_x_bias'
   */
  0.0,

  /* Expression: 300
   * Referenced by: '<S101>/Constant'
   */
  300.0,

  /* Expression: 0.0161
   * Referenced by: '<S101>/V'
   */
  0.0161,

  /* Expression: 600
   * Referenced by: '<S101>/Ample Gain'
   */
  600.0,

  /* Expression: 0
   * Referenced by: '<S8>/Grf_y_bias'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S8>/Data_Logging'
   */
  0.0,

  /* Expression: 2048*4
   * Referenced by: '<S8>/cpt_dri'
   */
  8192.0,

  /* Expression: 0
   * Referenced by: '<S8>/str_DOB_OnOff'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S8>/str_DOB_CutOff'
   */
  0.0,

  /* Computed Parameter: Delay1_DelayLength
   * Referenced by: '<S8>/Delay1'
   */
  1U,

  /* Computed Parameter: Delay2_DelayLength
   * Referenced by: '<S8>/Delay2'
   */
  1U,

  /* Computed Parameter: Delay_DelayLength
   * Referenced by: '<S76>/Delay'
   */
  1U,

  /* Start of '<S102>/ID_Mode' */
  {
    /* Expression: 10
     * Referenced by: '<S103>/Constant'
     */
    10.0,

    /* Expression: 3
     * Referenced by: '<S103>/Constant1'
     */
    3.0
  }
  ,

  /* End of '<S102>/ID_Mode' */

  /* Start of '<S102>/Torque Mode1' */
  {
    /* Expression: 10
     * Referenced by: '<S105>/Constant'
     */
    10.0,

    /* Expression: 2
     * Referenced by: '<S105>/Constant1'
     */
    2.0
  }
  ,

  /* End of '<S102>/Torque Mode1' */

  /* Start of '<S102>/Torque Mode' */
  {
    /* Expression: 10
     * Referenced by: '<S104>/Constant'
     */
    10.0,

    /* Expression: 1
     * Referenced by: '<S104>/Constant1'
     */
    1.0
  }
  /* End of '<S102>/Torque Mode' */
};
