/*
 * test.c
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

#include "test_trc_ptr.h"
#include "test.h"
#include "test_private.h"

/* Block signals (auto storage) */
B_test_T test_B;

/* Block states (auto storage) */
DW_test_T test_DW;

/* Real-time model */
RT_MODEL_test_T test_M_;
RT_MODEL_test_T *const test_M = &test_M_;

/*
 * Output and update for action system:
 *    '<S43>/If Action Subsystem2'
 *    '<S43>/If Action Subsystem1'
 *    '<S43>/If Action Subsystem3'
 *    '<S40>/If Action Subsystem2'
 *    '<S40>/If Action Subsystem1'
 *    '<S40>/If Action Subsystem3'
 *    '<S6>/If Action Subsystem'
 *    '<S6>/If Action Subsystem1'
 *    '<S95>/If Action Subsystem4'
 *    '<S95>/If Action Subsystem6'
 */
void test_IfActionSubsystem2(real_T rtu_In1, real_T *rty_Out1)
{
  /* Inport: '<S49>/In1' */
  *rty_Out1 = rtu_In1;
}

/*
 * Output and update for action system:
 *    '<S102>/Torque Mode'
 *    '<S102>/Torque Mode1'
 *    '<S102>/ID_Mode'
 */
void test_TorqueMode(real_T *rty_Mode, real_T *rty_Out2, P_TorqueMode_test_T
                     *localP)
{
  /* SignalConversion: '<S104>/OutportBufferForMode' incorporates:
   *  Constant: '<S104>/Constant'
   */
  *rty_Mode = localP->Constant_Value;

  /* SignalConversion: '<S104>/OutportBufferForOut2' incorporates:
   *  Constant: '<S104>/Constant1'
   */
  *rty_Out2 = localP->Constant1_Value;
}

real_T rt_roundd_snf(real_T u)
{
  real_T y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

/* Model output function */
void test_output(void)
{
  real_T phase;
  real_T current_mod;
  boolean_T rEQ0;
  real_T q;
  int8_T rtAction;

  /* Clock: '<Root>/Clock' */
  test_B.Clock = test_M->Timing.t[0];

  /* Saturate: '<Root>/Saturation' */
  current_mod = test_B.Clock;
  phase = test_P.Saturation_LowerSat;
  q = test_P.Saturation_UpperSat;
  if (current_mod > q) {
    test_B.Saturation = q;
  } else if (current_mod < phase) {
    test_B.Saturation = phase;
  } else {
    test_B.Saturation = current_mod;
  }

  /* End of Saturate: '<Root>/Saturation' */

  /* Constant: '<Root>/Constant' */
  test_B.Constant = test_P.Constant_Value_j;

  /* Sum: '<Root>/Add' */
  test_B.Add = test_B.Saturation + test_B.Constant;

  /* S-Function (rti_commonblock): '<S10>/S-Function1' incorporates:
   *  Constant: '<S8>/NMT_CS'
   *  Constant: '<S8>/NMT_Node_ID'
   */
  /* This comment workarounds a code generation problem */

  /* dSPACE RTICAN TX Message Block: "NMTZeroMsg" Id:0 */
  {
    UInt32 CAN_Msg[8] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };

    Float32 delayTime = 0.0;

    /* ... Read status and timestamp info (previous message) */
    can_tp1_msg_read(can_type1_msg_M1[CANTP1_M1_C1_TX_STD_0X0]);

    /* Convert timestamp */
    if (can_type1_msg_M1[CANTP1_M1_C1_TX_STD_0X0]->processed) {
      can_type1_msg_M1[CANTP1_M1_C1_TX_STD_0X0]->timestamp =
        rtk_dsts_time_to_simtime_convert
        (can_type1_msg_M1[CANTP1_M1_C1_TX_STD_0X0]->timestamp);
    }

    /* Messages with timestamp zero have been received in pause/stop state
       and must not be handled.
     */
    if (can_type1_msg_M1[CANTP1_M1_C1_TX_STD_0X0]->timestamp > 0.0) {
      test_B.SFunction1_o1 = (real_T)can_type1_msg_M1[CANTP1_M1_C1_TX_STD_0X0]
        ->processed;
      test_B.SFunction1_o2 = (real_T)can_type1_msg_M1[CANTP1_M1_C1_TX_STD_0X0]
        ->timestamp;
      test_B.SFunction1_o3 = (real_T)can_type1_msg_M1[CANTP1_M1_C1_TX_STD_0X0]
        ->deltatime;
      test_B.SFunction1_o4 = (real_T)can_type1_msg_M1[CANTP1_M1_C1_TX_STD_0X0]
        ->delaytime;
    }

    /* ... Encode Simulink signals of TX and RM blocks*/
    {
      rtican_Signal_t CAN_Sgn;

      /* ...... "CS" (0|8, standard signal, unsigned int, little endian) */
      /* Add or substract 0.5 in order to round to nearest integer */
      CAN_Sgn.UnsignedSgn = (UInt32) (( test_P.NMT_CS_Value ) + 0.5);
      CAN_Sgn.UnsignedSgn &= 0x000000FF;
      CAN_Msg[0] |= CAN_Sgn.SgnBytes.Byte0;

      /* ...... "Node_ID" (8|8, standard signal, unsigned int, little endian) */
      /* Add or substract 0.5 in order to round to nearest integer */
      CAN_Sgn.UnsignedSgn = (UInt32) (( test_P.NMT_Node_ID_Value ) + 0.5);
      CAN_Sgn.UnsignedSgn &= 0x000000FF;
      CAN_Msg[1] |= CAN_Sgn.SgnBytes.Byte0;
    }

    /* ... Write the data to the CAN microcontroller and trigger the sending of the message */
    can_tp1_msg_send(can_type1_msg_M1[CANTP1_M1_C1_TX_STD_0X0], 2, &(CAN_Msg[0]),
                     delayTime);
  }

  /* S-Function (rti_commonblock): '<S9>/S-Function1' */
  /* This comment workarounds a code generation problem */

  /* S-Function (rti_commonblock): '<S11>/S-Function1' */
  /* This comment workarounds a code generation problem */
  {
    /* dSPACE I/O Board DS1401STDADCT4 #1 Unit:ADC Group:ADC */
    adc_tp4_single_new_read(ADC_TP4_1_MODULE_ADDR,
      ADC_TP4_CH1,
      (dsfloat *)&test_B.SFunction1);
  }

  /* S-Function (rti_commonblock): '<S12>/S-Function1' */
  /* This comment workarounds a code generation problem */
  {
    /* dSPACE I/O Board DS1401STDADCT4 #1 Unit:ADC Group:ADC */
    adc_tp4_single_new_read(ADC_TP4_1_MODULE_ADDR,
      ADC_TP4_CH2,
      (dsfloat *)&test_B.SFunction1_j);
  }

  /* S-Function (rti_commonblock): '<S13>/S-Function1' */
  /* This comment workarounds a code generation problem */
  {
    /* dSPACE I/O Board DS1401STDADCT4 #1 Unit:ADC Group:ADC */
    adc_tp4_single_new_read(ADC_TP4_1_MODULE_ADDR,
      ADC_TP4_CH3,
      (dsfloat *)&test_B.SFunction1_n);
  }

  /* S-Function (rti_commonblock): '<S20>/S-Function1' */
  /* This comment workarounds a code generation problem */

  /* dSPACE RTICAN RX Message Block: "N30_TPDO2" Id:819 */
  {
    UInt32 *CAN_Msg;

    /* ... Read status and timestamp info (previous message) */
    can_tp1_msg_read_from_mem(can_type1_msg_M1[CANTP1_M1_C1_RX_STD_0X333]);

    /* Convert timestamp */
    if (can_type1_msg_M1[CANTP1_M1_C1_RX_STD_0X333]->processed) {
      can_type1_msg_M1[CANTP1_M1_C1_RX_STD_0X333]->timestamp =
        rtk_dsts_time_to_simtime_convert
        (can_type1_msg_M1[CANTP1_M1_C1_RX_STD_0X333]->timestamp);
    }

    /* Messages with timestamp zero have been received in pause/stop state
       and must not be handled.
     */
    if (can_type1_msg_M1[CANTP1_M1_C1_RX_STD_0X333]->timestamp > 0.0) {
      if (can_type1_msg_M1[CANTP1_M1_C1_RX_STD_0X333]->processed) {
        test_B.SFunction1_o3_k = (real_T)
          can_type1_msg_M1[CANTP1_M1_C1_RX_STD_0X333]->processed;
        test_B.SFunction1_o4_h = (real_T)
          can_type1_msg_M1[CANTP1_M1_C1_RX_STD_0X333]->timestamp;
        test_B.SFunction1_o5 = (real_T)
          can_type1_msg_M1[CANTP1_M1_C1_RX_STD_0X333]->deltatime;
        CAN_Msg = can_type1_msg_M1[CANTP1_M1_C1_RX_STD_0X333]->data;

        /* ... Decode CAN Message */
        {
          rtican_Signal_t CAN_Sgn;

          /* ...... "Velocity_demand_value" (0|32, standard signal, signed int, little endian) */
          CAN_Sgn.SgnBytes.Byte0 = CAN_Msg[0];
          CAN_Sgn.SgnBytes.Byte1 = CAN_Msg[1];
          CAN_Sgn.SgnBytes.Byte2 = CAN_Msg[2];
          CAN_Sgn.SgnBytes.Byte3 = CAN_Msg[3];
          test_B.SFunction1_o1_f = ((real_T) CAN_Sgn.SignedSgn);

          /* ...... "Velocity_actual_value_averaged" (32|32, standard signal, signed int, little endian) */
          CAN_Sgn.SgnBytes.Byte0 = CAN_Msg[4];
          CAN_Sgn.SgnBytes.Byte1 = CAN_Msg[5];
          CAN_Sgn.SgnBytes.Byte2 = CAN_Msg[6];
          CAN_Sgn.SgnBytes.Byte3 = CAN_Msg[7];
          test_B.SFunction1_o2_g = ((real_T) CAN_Sgn.SignedSgn);
        }
      }
    }

    if (!can_type1_msg_M1[CANTP1_M1_C1_RX_STD_0X333]->processed) {
      /* ... set RX status to 0 because no new message has arrived */
      test_B.SFunction1_o3_k = 0.0;
    }
  }

  /* Gain: '<S2>/rpm2rad2' */
  test_B.rpm2rad2 = test_P.rpm2rad2_Gain * test_B.SFunction1_o2_g;

  /* Product: '<S2>/Divide1' incorporates:
   *  Constant: '<S8>/N_dri'
   */
  test_B.Divide1 = test_B.rpm2rad2 / test_P.N_dri_Value_o;

  /* S-Function (rti_commonblock): '<S21>/S-Function1' */
  /* This comment workarounds a code generation problem */

  /* dSPACE RTICAN RX Message Block: "N30_TPDO3" Id:820 */
  {
    UInt32 *CAN_Msg;

    /* ... Read status and timestamp info (previous message) */
    can_tp1_msg_read_from_mem(can_type1_msg_M1[CANTP1_M1_C1_RX_STD_0X334]);

    /* Convert timestamp */
    if (can_type1_msg_M1[CANTP1_M1_C1_RX_STD_0X334]->processed) {
      can_type1_msg_M1[CANTP1_M1_C1_RX_STD_0X334]->timestamp =
        rtk_dsts_time_to_simtime_convert
        (can_type1_msg_M1[CANTP1_M1_C1_RX_STD_0X334]->timestamp);
    }

    /* Messages with timestamp zero have been received in pause/stop state
       and must not be handled.
     */
    if (can_type1_msg_M1[CANTP1_M1_C1_RX_STD_0X334]->timestamp > 0.0) {
      if (can_type1_msg_M1[CANTP1_M1_C1_RX_STD_0X334]->processed) {
        test_B.SFunction1_o3_i = (real_T)
          can_type1_msg_M1[CANTP1_M1_C1_RX_STD_0X334]->processed;
        test_B.SFunction1_o4_h1 = (real_T)
          can_type1_msg_M1[CANTP1_M1_C1_RX_STD_0X334]->timestamp;
        test_B.SFunction1_o5_m = (real_T)
          can_type1_msg_M1[CANTP1_M1_C1_RX_STD_0X334]->deltatime;
        CAN_Msg = can_type1_msg_M1[CANTP1_M1_C1_RX_STD_0X334]->data;

        /* ... Decode CAN Message */
        {
          rtican_Signal_t CAN_Sgn;

          /* ...... "Current_demand_value" (0|32, standard signal, signed int, little endian) */
          CAN_Sgn.SgnBytes.Byte0 = CAN_Msg[0];
          CAN_Sgn.SgnBytes.Byte1 = CAN_Msg[1];
          CAN_Sgn.SgnBytes.Byte2 = CAN_Msg[2];
          CAN_Sgn.SgnBytes.Byte3 = CAN_Msg[3];
          test_B.SFunction1_o1_g = ((real_T) CAN_Sgn.SignedSgn);

          /* ...... "Current_actual_value_averaged" (32|32, standard signal, signed int, little endian) */
          CAN_Sgn.SgnBytes.Byte0 = CAN_Msg[4];
          CAN_Sgn.SgnBytes.Byte1 = CAN_Msg[5];
          CAN_Sgn.SgnBytes.Byte2 = CAN_Msg[6];
          CAN_Sgn.SgnBytes.Byte3 = CAN_Msg[7];
          test_B.SFunction1_o2_k = ((real_T) CAN_Sgn.SignedSgn);
        }
      }
    }

    if (!can_type1_msg_M1[CANTP1_M1_C1_RX_STD_0X334]->processed) {
      /* ... set RX status to 0 because no new message has arrived */
      test_B.SFunction1_o3_i = 0.0;
    }
  }

  /* Gain: '<S2>/mA2A' */
  test_B.mA2A = test_P.mA2A_Gain * test_B.SFunction1_o2_k;

  /* Gain: '<S2>/Motor torque Constant' */
  test_B.MotortorqueConstant = test_P.MotortorqueConstant_Gain * test_B.mA2A;

  /* Gain: '<S2>/Torque Constant1' */
  test_B.TorqueConstant1 = test_P.TorqueConstant1_Gain *
    test_B.MotortorqueConstant;

  /* Product: '<S2>/Divide2' incorporates:
   *  Constant: '<S8>/N_dri'
   */
  test_B.Divide2 = test_B.TorqueConstant1 * test_P.N_dri_Value_o;

  /* S-Function (rti_commonblock): '<S19>/S-Function1' */
  /* This comment workarounds a code generation problem */

  /* dSPACE RTICAN RX Message Block: "N30_TPDO0" Id:817 */
  {
    UInt32 *CAN_Msg;

    /* ... Read status and timestamp info (previous message) */
    can_tp1_msg_read_from_mem(can_type1_msg_M1[CANTP1_M1_C1_RX_STD_0X331]);

    /* Convert timestamp */
    if (can_type1_msg_M1[CANTP1_M1_C1_RX_STD_0X331]->processed) {
      can_type1_msg_M1[CANTP1_M1_C1_RX_STD_0X331]->timestamp =
        rtk_dsts_time_to_simtime_convert
        (can_type1_msg_M1[CANTP1_M1_C1_RX_STD_0X331]->timestamp);
    }

    /* Messages with timestamp zero have been received in pause/stop state
       and must not be handled.
     */
    if (can_type1_msg_M1[CANTP1_M1_C1_RX_STD_0X331]->timestamp > 0.0) {
      if (can_type1_msg_M1[CANTP1_M1_C1_RX_STD_0X331]->processed) {
        test_B.SFunction1_o5_c = (real_T)
          can_type1_msg_M1[CANTP1_M1_C1_RX_STD_0X331]->processed;
        test_B.SFunction1_o6 = (real_T)
          can_type1_msg_M1[CANTP1_M1_C1_RX_STD_0X331]->timestamp;
        test_B.SFunction1_o7 = (real_T)
          can_type1_msg_M1[CANTP1_M1_C1_RX_STD_0X331]->deltatime;
        CAN_Msg = can_type1_msg_M1[CANTP1_M1_C1_RX_STD_0X331]->data;

        /* ... Decode CAN Message */
        {
          rtican_Signal_t CAN_Sgn;

          /* ...... "Controlword" (0|16, standard signal, unsigned int, little endian) */
          CAN_Sgn.SgnBytes.Byte0 = CAN_Msg[0];
          CAN_Sgn.SgnBytes.Byte1 = CAN_Msg[1];
          CAN_Sgn.UnsignedSgn &= 0x0000FFFF;
          test_B.SFunction1_o1_o = ((real_T) CAN_Sgn.UnsignedSgn);

          /* ...... "Statusword" (16|16, standard signal, unsigned int, little endian) */
          CAN_Sgn.SgnBytes.Byte0 = CAN_Msg[2];
          CAN_Sgn.SgnBytes.Byte1 = CAN_Msg[3];
          CAN_Sgn.UnsignedSgn &= 0x0000FFFF;
          test_B.SFunction1_o2_gh = ((real_T) CAN_Sgn.UnsignedSgn);

          /* ...... "Modes_of_operation_display" (32|8, standard signal, signed int, little endian) */
          CAN_Sgn.SgnBytes.Byte0 = CAN_Msg[4];
          CAN_Sgn.SignedSgn &= 0x000000FF;
          if (CAN_Sgn.SignedSgn >> 7) {
            CAN_Sgn.SignedSgn |= 0xFFFFFF00;
          }

          test_B.SFunction1_o3_g = ((real_T) CAN_Sgn.SignedSgn);

          /* ...... "Error_code" (40|16, standard signal, unsigned int, little endian) */
          CAN_Sgn.SgnBytes.Byte0 = CAN_Msg[5];
          CAN_Sgn.SgnBytes.Byte1 = CAN_Msg[6];
          CAN_Sgn.UnsignedSgn &= 0x0000FFFF;
          test_B.SFunction1_o4_k = ((real_T) CAN_Sgn.UnsignedSgn);
        }
      }
    }

    if (!can_type1_msg_M1[CANTP1_M1_C1_RX_STD_0X331]->processed) {
      /* ... set RX status to 0 because no new message has arrived */
      test_B.SFunction1_o5_c = 0.0;
    }
  }

  /* S-Function (rti_commonblock): '<S25>/S-Function1' */
  /* This comment workarounds a code generation problem */

  /* dSPACE RTICAN RX Message Block: "N10_TPDO3" Id:788 */
  {
    UInt32 *CAN_Msg;

    /* ... Read status and timestamp info (previous message) */
    can_tp1_msg_read_from_mem(can_type1_msg_M1[CANTP1_M1_C1_RX_STD_0X314]);

    /* Convert timestamp */
    if (can_type1_msg_M1[CANTP1_M1_C1_RX_STD_0X314]->processed) {
      can_type1_msg_M1[CANTP1_M1_C1_RX_STD_0X314]->timestamp =
        rtk_dsts_time_to_simtime_convert
        (can_type1_msg_M1[CANTP1_M1_C1_RX_STD_0X314]->timestamp);
    }

    /* Messages with timestamp zero have been received in pause/stop state
       and must not be handled.
     */
    if (can_type1_msg_M1[CANTP1_M1_C1_RX_STD_0X314]->timestamp > 0.0) {
      if (can_type1_msg_M1[CANTP1_M1_C1_RX_STD_0X314]->processed) {
        test_B.SFunction1_o3_c = (real_T)
          can_type1_msg_M1[CANTP1_M1_C1_RX_STD_0X314]->processed;
        test_B.SFunction1_o4_a = (real_T)
          can_type1_msg_M1[CANTP1_M1_C1_RX_STD_0X314]->timestamp;
        test_B.SFunction1_o5_b = (real_T)
          can_type1_msg_M1[CANTP1_M1_C1_RX_STD_0X314]->deltatime;
        CAN_Msg = can_type1_msg_M1[CANTP1_M1_C1_RX_STD_0X314]->data;

        /* ... Decode CAN Message */
        {
          rtican_Signal_t CAN_Sgn;

          /* ...... "Current_demand_value" (0|32, standard signal, signed int, little endian) */
          CAN_Sgn.SgnBytes.Byte0 = CAN_Msg[0];
          CAN_Sgn.SgnBytes.Byte1 = CAN_Msg[1];
          CAN_Sgn.SgnBytes.Byte2 = CAN_Msg[2];
          CAN_Sgn.SgnBytes.Byte3 = CAN_Msg[3];
          test_B.SFunction1_o1_m = ((real_T) CAN_Sgn.SignedSgn);

          /* ...... "Current_actual_value_averaged" (32|32, standard signal, signed int, little endian) */
          CAN_Sgn.SgnBytes.Byte0 = CAN_Msg[4];
          CAN_Sgn.SgnBytes.Byte1 = CAN_Msg[5];
          CAN_Sgn.SgnBytes.Byte2 = CAN_Msg[6];
          CAN_Sgn.SgnBytes.Byte3 = CAN_Msg[7];
          test_B.SFunction1_o2_a = ((real_T) CAN_Sgn.SignedSgn);
        }
      }
    }

    if (!can_type1_msg_M1[CANTP1_M1_C1_RX_STD_0X314]->processed) {
      /* ... set RX status to 0 because no new message has arrived */
      test_B.SFunction1_o3_c = 0.0;
    }
  }

  /* Gain: '<S2>/mA2A2' */
  test_B.mA2A2 = test_P.mA2A2_Gain * test_B.SFunction1_o2_a;

  /* Gain: '<S2>/Motor torque Constant1' */
  test_B.MotortorqueConstant1 = test_P.MotortorqueConstant1_Gain * test_B.mA2A2;

  /* Gain: '<S2>/Torque Constant2' */
  test_B.TorqueConstant2 = test_P.TorqueConstant2_Gain *
    test_B.MotortorqueConstant1;

  /* Product: '<S2>/Divide3' incorporates:
   *  Constant: '<S8>/N_str'
   */
  test_B.Divide3 = test_B.TorqueConstant2 * test_P.N_str_Value;

  /* S-Function (rti_commonblock): '<S22>/S-Function1' */
  /* This comment workarounds a code generation problem */

  /* dSPACE RTICAN RX Message Block: "N10_TPDO0" Id:785 */
  {
    UInt32 *CAN_Msg;

    /* ... Read status and timestamp info (previous message) */
    can_tp1_msg_read_from_mem(can_type1_msg_M1[CANTP1_M1_C1_RX_STD_0X311]);

    /* Convert timestamp */
    if (can_type1_msg_M1[CANTP1_M1_C1_RX_STD_0X311]->processed) {
      can_type1_msg_M1[CANTP1_M1_C1_RX_STD_0X311]->timestamp =
        rtk_dsts_time_to_simtime_convert
        (can_type1_msg_M1[CANTP1_M1_C1_RX_STD_0X311]->timestamp);
    }

    /* Messages with timestamp zero have been received in pause/stop state
       and must not be handled.
     */
    if (can_type1_msg_M1[CANTP1_M1_C1_RX_STD_0X311]->timestamp > 0.0) {
      if (can_type1_msg_M1[CANTP1_M1_C1_RX_STD_0X311]->processed) {
        test_B.SFunction1_o5_d = (real_T)
          can_type1_msg_M1[CANTP1_M1_C1_RX_STD_0X311]->processed;
        test_B.SFunction1_o6_d = (real_T)
          can_type1_msg_M1[CANTP1_M1_C1_RX_STD_0X311]->timestamp;
        test_B.SFunction1_o7_k = (real_T)
          can_type1_msg_M1[CANTP1_M1_C1_RX_STD_0X311]->deltatime;
        CAN_Msg = can_type1_msg_M1[CANTP1_M1_C1_RX_STD_0X311]->data;

        /* ... Decode CAN Message */
        {
          rtican_Signal_t CAN_Sgn;

          /* ...... "Controlword" (0|16, standard signal, unsigned int, little endian) */
          CAN_Sgn.SgnBytes.Byte0 = CAN_Msg[0];
          CAN_Sgn.SgnBytes.Byte1 = CAN_Msg[1];
          CAN_Sgn.UnsignedSgn &= 0x0000FFFF;
          test_B.SFunction1_o1_b = ((real_T) CAN_Sgn.UnsignedSgn);

          /* ...... "Statusword" (16|16, standard signal, unsigned int, little endian) */
          CAN_Sgn.SgnBytes.Byte0 = CAN_Msg[2];
          CAN_Sgn.SgnBytes.Byte1 = CAN_Msg[3];
          CAN_Sgn.UnsignedSgn &= 0x0000FFFF;
          test_B.SFunction1_o2_m = ((real_T) CAN_Sgn.UnsignedSgn);

          /* ...... "Modes_of_operation_display" (32|8, standard signal, signed int, little endian) */
          CAN_Sgn.SgnBytes.Byte0 = CAN_Msg[4];
          CAN_Sgn.SignedSgn &= 0x000000FF;
          if (CAN_Sgn.SignedSgn >> 7) {
            CAN_Sgn.SignedSgn |= 0xFFFFFF00;
          }

          test_B.SFunction1_o3_i0 = ((real_T) CAN_Sgn.SignedSgn);

          /* ...... "Error_code" (40|16, standard signal, unsigned int, little endian) */
          CAN_Sgn.SgnBytes.Byte0 = CAN_Msg[5];
          CAN_Sgn.SgnBytes.Byte1 = CAN_Msg[6];
          CAN_Sgn.UnsignedSgn &= 0x0000FFFF;
          test_B.SFunction1_o4_ac = ((real_T) CAN_Sgn.UnsignedSgn);
        }
      }
    }

    if (!can_type1_msg_M1[CANTP1_M1_C1_RX_STD_0X311]->processed) {
      /* ... set RX status to 0 because no new message has arrived */
      test_B.SFunction1_o5_d = 0.0;
    }
  }

  /* S-Function (rti_commonblock): '<S23>/S-Function1' */
  /* This comment workarounds a code generation problem */

  /* dSPACE RTICAN RX Message Block: "N10_TPDO1" Id:786 */
  {
    UInt32 *CAN_Msg;

    /* ... Read status and timestamp info (previous message) */
    can_tp1_msg_read_from_mem(can_type1_msg_M1[CANTP1_M1_C1_RX_STD_0X312]);

    /* Convert timestamp */
    if (can_type1_msg_M1[CANTP1_M1_C1_RX_STD_0X312]->processed) {
      can_type1_msg_M1[CANTP1_M1_C1_RX_STD_0X312]->timestamp =
        rtk_dsts_time_to_simtime_convert
        (can_type1_msg_M1[CANTP1_M1_C1_RX_STD_0X312]->timestamp);
    }

    /* Messages with timestamp zero have been received in pause/stop state
       and must not be handled.
     */
    if (can_type1_msg_M1[CANTP1_M1_C1_RX_STD_0X312]->timestamp > 0.0) {
      if (can_type1_msg_M1[CANTP1_M1_C1_RX_STD_0X312]->processed) {
        test_B.SFunction1_o3_d = (real_T)
          can_type1_msg_M1[CANTP1_M1_C1_RX_STD_0X312]->processed;
        test_B.SFunction1_o4_kl = (real_T)
          can_type1_msg_M1[CANTP1_M1_C1_RX_STD_0X312]->timestamp;
        test_B.SFunction1_o5_e = (real_T)
          can_type1_msg_M1[CANTP1_M1_C1_RX_STD_0X312]->deltatime;
        CAN_Msg = can_type1_msg_M1[CANTP1_M1_C1_RX_STD_0X312]->data;

        /* ... Decode CAN Message */
        {
          rtican_Signal_t CAN_Sgn;

          /* ...... "Position_demand_value" (0|32, standard signal, signed int, little endian) */
          CAN_Sgn.SgnBytes.Byte0 = CAN_Msg[0];
          CAN_Sgn.SgnBytes.Byte1 = CAN_Msg[1];
          CAN_Sgn.SgnBytes.Byte2 = CAN_Msg[2];
          CAN_Sgn.SgnBytes.Byte3 = CAN_Msg[3];
          test_B.SFunction1_o1_d = ((real_T) CAN_Sgn.SignedSgn);

          /* ...... "Position_actual_value" (32|32, standard signal, signed int, little endian) */
          CAN_Sgn.SgnBytes.Byte0 = CAN_Msg[4];
          CAN_Sgn.SgnBytes.Byte1 = CAN_Msg[5];
          CAN_Sgn.SgnBytes.Byte2 = CAN_Msg[6];
          CAN_Sgn.SgnBytes.Byte3 = CAN_Msg[7];
          test_B.SFunction1_o2_ay = ((real_T) CAN_Sgn.SignedSgn);
        }
      }
    }

    if (!can_type1_msg_M1[CANTP1_M1_C1_RX_STD_0X312]->processed) {
      /* ... set RX status to 0 because no new message has arrived */
      test_B.SFunction1_o3_d = 0.0;
    }
  }

  /* S-Function (rti_commonblock): '<S24>/S-Function1' */
  /* This comment workarounds a code generation problem */

  /* dSPACE RTICAN RX Message Block: "N10_TPDO2" Id:787 */
  {
    UInt32 *CAN_Msg;

    /* ... Read status and timestamp info (previous message) */
    can_tp1_msg_read_from_mem(can_type1_msg_M1[CANTP1_M1_C1_RX_STD_0X313]);

    /* Convert timestamp */
    if (can_type1_msg_M1[CANTP1_M1_C1_RX_STD_0X313]->processed) {
      can_type1_msg_M1[CANTP1_M1_C1_RX_STD_0X313]->timestamp =
        rtk_dsts_time_to_simtime_convert
        (can_type1_msg_M1[CANTP1_M1_C1_RX_STD_0X313]->timestamp);
    }

    /* Messages with timestamp zero have been received in pause/stop state
       and must not be handled.
     */
    if (can_type1_msg_M1[CANTP1_M1_C1_RX_STD_0X313]->timestamp > 0.0) {
      if (can_type1_msg_M1[CANTP1_M1_C1_RX_STD_0X313]->processed) {
        test_B.SFunction1_o3_l = (real_T)
          can_type1_msg_M1[CANTP1_M1_C1_RX_STD_0X313]->processed;
        test_B.SFunction1_o4_l = (real_T)
          can_type1_msg_M1[CANTP1_M1_C1_RX_STD_0X313]->timestamp;
        test_B.SFunction1_o5_i = (real_T)
          can_type1_msg_M1[CANTP1_M1_C1_RX_STD_0X313]->deltatime;
        CAN_Msg = can_type1_msg_M1[CANTP1_M1_C1_RX_STD_0X313]->data;

        /* ... Decode CAN Message */
        {
          rtican_Signal_t CAN_Sgn;

          /* ...... "Velocity_demand_value" (0|32, standard signal, signed int, little endian) */
          CAN_Sgn.SgnBytes.Byte0 = CAN_Msg[0];
          CAN_Sgn.SgnBytes.Byte1 = CAN_Msg[1];
          CAN_Sgn.SgnBytes.Byte2 = CAN_Msg[2];
          CAN_Sgn.SgnBytes.Byte3 = CAN_Msg[3];
          test_B.SFunction1_o1_a = ((real_T) CAN_Sgn.SignedSgn);

          /* ...... "Velocity_actual_value_averaged" (32|32, standard signal, signed int, little endian) */
          CAN_Sgn.SgnBytes.Byte0 = CAN_Msg[4];
          CAN_Sgn.SgnBytes.Byte1 = CAN_Msg[5];
          CAN_Sgn.SgnBytes.Byte2 = CAN_Msg[6];
          CAN_Sgn.SgnBytes.Byte3 = CAN_Msg[7];
          test_B.SFunction1_o2_j = ((real_T) CAN_Sgn.SignedSgn);
        }
      }
    }

    if (!can_type1_msg_M1[CANTP1_M1_C1_RX_STD_0X313]->processed) {
      /* ... set RX status to 0 because no new message has arrived */
      test_B.SFunction1_o3_l = 0.0;
    }
  }

  /* Gain: '<S2>/rpm2rad3' */
  test_B.rpm2rad3 = test_P.rpm2rad3_Gain * test_B.SFunction1_o2_j;

  /* S-Function (rti_commonblock): '<S29>/S-Function1' */
  /* This comment workarounds a code generation problem */

  /* dSPACE RTICAN RX Message Block: "N20_TPDO3" Id:804 */
  {
    UInt32 *CAN_Msg;

    /* ... Read status and timestamp info (previous message) */
    can_tp1_msg_read_from_mem(can_type1_msg_M1[CANTP1_M1_C1_RX_STD_0X324]);

    /* Convert timestamp */
    if (can_type1_msg_M1[CANTP1_M1_C1_RX_STD_0X324]->processed) {
      can_type1_msg_M1[CANTP1_M1_C1_RX_STD_0X324]->timestamp =
        rtk_dsts_time_to_simtime_convert
        (can_type1_msg_M1[CANTP1_M1_C1_RX_STD_0X324]->timestamp);
    }

    /* Messages with timestamp zero have been received in pause/stop state
       and must not be handled.
     */
    if (can_type1_msg_M1[CANTP1_M1_C1_RX_STD_0X324]->timestamp > 0.0) {
      if (can_type1_msg_M1[CANTP1_M1_C1_RX_STD_0X324]->processed) {
        test_B.SFunction1_o3_m = (real_T)
          can_type1_msg_M1[CANTP1_M1_C1_RX_STD_0X324]->processed;
        test_B.SFunction1_o4_m = (real_T)
          can_type1_msg_M1[CANTP1_M1_C1_RX_STD_0X324]->timestamp;
        test_B.SFunction1_o5_f = (real_T)
          can_type1_msg_M1[CANTP1_M1_C1_RX_STD_0X324]->deltatime;
        CAN_Msg = can_type1_msg_M1[CANTP1_M1_C1_RX_STD_0X324]->data;

        /* ... Decode CAN Message */
        {
          rtican_Signal_t CAN_Sgn;

          /* ...... "Current_demand_value" (0|32, standard signal, signed int, little endian) */
          CAN_Sgn.SgnBytes.Byte0 = CAN_Msg[0];
          CAN_Sgn.SgnBytes.Byte1 = CAN_Msg[1];
          CAN_Sgn.SgnBytes.Byte2 = CAN_Msg[2];
          CAN_Sgn.SgnBytes.Byte3 = CAN_Msg[3];
          test_B.SFunction1_o1_bw = ((real_T) CAN_Sgn.SignedSgn);

          /* ...... "Current_actual_value_averaged" (32|32, standard signal, signed int, little endian) */
          CAN_Sgn.SgnBytes.Byte0 = CAN_Msg[4];
          CAN_Sgn.SgnBytes.Byte1 = CAN_Msg[5];
          CAN_Sgn.SgnBytes.Byte2 = CAN_Msg[6];
          CAN_Sgn.SgnBytes.Byte3 = CAN_Msg[7];
          test_B.SFunction1_o2_p = ((real_T) CAN_Sgn.SignedSgn);
        }
      }
    }

    if (!can_type1_msg_M1[CANTP1_M1_C1_RX_STD_0X324]->processed) {
      /* ... set RX status to 0 because no new message has arrived */
      test_B.SFunction1_o3_m = 0.0;
    }
  }

  /* Gain: '<S2>/mA2A1' */
  test_B.mA2A1 = test_P.mA2A1_Gain * test_B.SFunction1_o2_p;

  /* Gain: '<S2>/Motor torque Constant2' */
  test_B.MotortorqueConstant2 = test_P.MotortorqueConstant2_Gain * test_B.mA2A1;

  /* Gain: '<S2>/Torque Constant3' */
  test_B.TorqueConstant3 = test_P.TorqueConstant3_Gain *
    test_B.MotortorqueConstant2;

  /* Product: '<S2>/Divide4' incorporates:
   *  Constant: '<S8>/N_sus'
   */
  test_B.Divide4 = test_B.TorqueConstant3 * test_P.N_sus_Value;

  /* S-Function (rti_commonblock): '<S26>/S-Function1' */
  /* This comment workarounds a code generation problem */

  /* dSPACE RTICAN RX Message Block: "N20_TPDO0" Id:801 */
  {
    UInt32 *CAN_Msg;

    /* ... Read status and timestamp info (previous message) */
    can_tp1_msg_read_from_mem(can_type1_msg_M1[CANTP1_M1_C1_RX_STD_0X321]);

    /* Convert timestamp */
    if (can_type1_msg_M1[CANTP1_M1_C1_RX_STD_0X321]->processed) {
      can_type1_msg_M1[CANTP1_M1_C1_RX_STD_0X321]->timestamp =
        rtk_dsts_time_to_simtime_convert
        (can_type1_msg_M1[CANTP1_M1_C1_RX_STD_0X321]->timestamp);
    }

    /* Messages with timestamp zero have been received in pause/stop state
       and must not be handled.
     */
    if (can_type1_msg_M1[CANTP1_M1_C1_RX_STD_0X321]->timestamp > 0.0) {
      if (can_type1_msg_M1[CANTP1_M1_C1_RX_STD_0X321]->processed) {
        test_B.SFunction1_o5_n = (real_T)
          can_type1_msg_M1[CANTP1_M1_C1_RX_STD_0X321]->processed;
        test_B.SFunction1_o6_h = (real_T)
          can_type1_msg_M1[CANTP1_M1_C1_RX_STD_0X321]->timestamp;
        test_B.SFunction1_o7_f = (real_T)
          can_type1_msg_M1[CANTP1_M1_C1_RX_STD_0X321]->deltatime;
        CAN_Msg = can_type1_msg_M1[CANTP1_M1_C1_RX_STD_0X321]->data;

        /* ... Decode CAN Message */
        {
          rtican_Signal_t CAN_Sgn;

          /* ...... "Controlword" (0|16, standard signal, unsigned int, little endian) */
          CAN_Sgn.SgnBytes.Byte0 = CAN_Msg[0];
          CAN_Sgn.SgnBytes.Byte1 = CAN_Msg[1];
          CAN_Sgn.UnsignedSgn &= 0x0000FFFF;
          test_B.SFunction1_o1_dd = ((real_T) CAN_Sgn.UnsignedSgn);

          /* ...... "Statusword" (16|16, standard signal, unsigned int, little endian) */
          CAN_Sgn.SgnBytes.Byte0 = CAN_Msg[2];
          CAN_Sgn.SgnBytes.Byte1 = CAN_Msg[3];
          CAN_Sgn.UnsignedSgn &= 0x0000FFFF;
          test_B.SFunction1_o2_l = ((real_T) CAN_Sgn.UnsignedSgn);

          /* ...... "Modes_of_operation_display" (32|8, standard signal, signed int, little endian) */
          CAN_Sgn.SgnBytes.Byte0 = CAN_Msg[4];
          CAN_Sgn.SignedSgn &= 0x000000FF;
          if (CAN_Sgn.SignedSgn >> 7) {
            CAN_Sgn.SignedSgn |= 0xFFFFFF00;
          }

          test_B.SFunction1_o3_j = ((real_T) CAN_Sgn.SignedSgn);

          /* ...... "Error_code" (40|16, standard signal, unsigned int, little endian) */
          CAN_Sgn.SgnBytes.Byte0 = CAN_Msg[5];
          CAN_Sgn.SgnBytes.Byte1 = CAN_Msg[6];
          CAN_Sgn.UnsignedSgn &= 0x0000FFFF;
          test_B.SFunction1_o4_g = ((real_T) CAN_Sgn.UnsignedSgn);
        }
      }
    }

    if (!can_type1_msg_M1[CANTP1_M1_C1_RX_STD_0X321]->processed) {
      /* ... set RX status to 0 because no new message has arrived */
      test_B.SFunction1_o5_n = 0.0;
    }
  }

  /* S-Function (rti_commonblock): '<S27>/S-Function1' */
  /* This comment workarounds a code generation problem */

  /* dSPACE RTICAN RX Message Block: "N20_TPDO1" Id:802 */
  {
    UInt32 *CAN_Msg;

    /* ... Read status and timestamp info (previous message) */
    can_tp1_msg_read_from_mem(can_type1_msg_M1[CANTP1_M1_C1_RX_STD_0X322]);

    /* Convert timestamp */
    if (can_type1_msg_M1[CANTP1_M1_C1_RX_STD_0X322]->processed) {
      can_type1_msg_M1[CANTP1_M1_C1_RX_STD_0X322]->timestamp =
        rtk_dsts_time_to_simtime_convert
        (can_type1_msg_M1[CANTP1_M1_C1_RX_STD_0X322]->timestamp);
    }

    /* Messages with timestamp zero have been received in pause/stop state
       and must not be handled.
     */
    if (can_type1_msg_M1[CANTP1_M1_C1_RX_STD_0X322]->timestamp > 0.0) {
      if (can_type1_msg_M1[CANTP1_M1_C1_RX_STD_0X322]->processed) {
        test_B.SFunction1_o3_b = (real_T)
          can_type1_msg_M1[CANTP1_M1_C1_RX_STD_0X322]->processed;
        test_B.SFunction1_o4_a1 = (real_T)
          can_type1_msg_M1[CANTP1_M1_C1_RX_STD_0X322]->timestamp;
        test_B.SFunction1_o5_id = (real_T)
          can_type1_msg_M1[CANTP1_M1_C1_RX_STD_0X322]->deltatime;
        CAN_Msg = can_type1_msg_M1[CANTP1_M1_C1_RX_STD_0X322]->data;

        /* ... Decode CAN Message */
        {
          rtican_Signal_t CAN_Sgn;

          /* ...... "Position_demand_value" (0|32, standard signal, signed int, little endian) */
          CAN_Sgn.SgnBytes.Byte0 = CAN_Msg[0];
          CAN_Sgn.SgnBytes.Byte1 = CAN_Msg[1];
          CAN_Sgn.SgnBytes.Byte2 = CAN_Msg[2];
          CAN_Sgn.SgnBytes.Byte3 = CAN_Msg[3];
          test_B.SFunction1_o1_b0 = ((real_T) CAN_Sgn.SignedSgn);

          /* ...... "Position_actual_value" (32|32, standard signal, signed int, little endian) */
          CAN_Sgn.SgnBytes.Byte0 = CAN_Msg[4];
          CAN_Sgn.SgnBytes.Byte1 = CAN_Msg[5];
          CAN_Sgn.SgnBytes.Byte2 = CAN_Msg[6];
          CAN_Sgn.SgnBytes.Byte3 = CAN_Msg[7];
          test_B.SFunction1_o2_an = ((real_T) CAN_Sgn.SignedSgn);
        }
      }
    }

    if (!can_type1_msg_M1[CANTP1_M1_C1_RX_STD_0X322]->processed) {
      /* ... set RX status to 0 because no new message has arrived */
      test_B.SFunction1_o3_b = 0.0;
    }
  }

  /* S-Function (rti_commonblock): '<S28>/S-Function1' */
  /* This comment workarounds a code generation problem */

  /* dSPACE RTICAN RX Message Block: "N20_TPDO2" Id:803 */
  {
    UInt32 *CAN_Msg;

    /* ... Read status and timestamp info (previous message) */
    can_tp1_msg_read_from_mem(can_type1_msg_M1[CANTP1_M1_C1_RX_STD_0X323]);

    /* Convert timestamp */
    if (can_type1_msg_M1[CANTP1_M1_C1_RX_STD_0X323]->processed) {
      can_type1_msg_M1[CANTP1_M1_C1_RX_STD_0X323]->timestamp =
        rtk_dsts_time_to_simtime_convert
        (can_type1_msg_M1[CANTP1_M1_C1_RX_STD_0X323]->timestamp);
    }

    /* Messages with timestamp zero have been received in pause/stop state
       and must not be handled.
     */
    if (can_type1_msg_M1[CANTP1_M1_C1_RX_STD_0X323]->timestamp > 0.0) {
      if (can_type1_msg_M1[CANTP1_M1_C1_RX_STD_0X323]->processed) {
        test_B.SFunction1_o3_e = (real_T)
          can_type1_msg_M1[CANTP1_M1_C1_RX_STD_0X323]->processed;
        test_B.SFunction1_o4_md = (real_T)
          can_type1_msg_M1[CANTP1_M1_C1_RX_STD_0X323]->timestamp;
        test_B.SFunction1_o5_ck = (real_T)
          can_type1_msg_M1[CANTP1_M1_C1_RX_STD_0X323]->deltatime;
        CAN_Msg = can_type1_msg_M1[CANTP1_M1_C1_RX_STD_0X323]->data;

        /* ... Decode CAN Message */
        {
          rtican_Signal_t CAN_Sgn;

          /* ...... "Velocity_demand_value" (0|32, standard signal, signed int, little endian) */
          CAN_Sgn.SgnBytes.Byte0 = CAN_Msg[0];
          CAN_Sgn.SgnBytes.Byte1 = CAN_Msg[1];
          CAN_Sgn.SgnBytes.Byte2 = CAN_Msg[2];
          CAN_Sgn.SgnBytes.Byte3 = CAN_Msg[3];
          test_B.SFunction1_o1_gg = ((real_T) CAN_Sgn.SignedSgn);

          /* ...... "Velocity_actual_value_averaged" (32|32, standard signal, signed int, little endian) */
          CAN_Sgn.SgnBytes.Byte0 = CAN_Msg[4];
          CAN_Sgn.SgnBytes.Byte1 = CAN_Msg[5];
          CAN_Sgn.SgnBytes.Byte2 = CAN_Msg[6];
          CAN_Sgn.SgnBytes.Byte3 = CAN_Msg[7];
          test_B.SFunction1_o2_h = ((real_T) CAN_Sgn.SignedSgn);
        }
      }
    }

    if (!can_type1_msg_M1[CANTP1_M1_C1_RX_STD_0X323]->processed) {
      /* ... set RX status to 0 because no new message has arrived */
      test_B.SFunction1_o3_e = 0.0;
    }
  }

  /* Gain: '<S2>/rpm2rad1' */
  test_B.rpm2rad1 = test_P.rpm2rad1_Gain * test_B.SFunction1_o2_h;

  /* UnitDelay: '<S14>/d' */
  test_B.d = test_DW.d_DSTATE;

  /* Sum: '<S14>/Sum2' */
  test_B.Sum2 = 0.0 - test_B.d;

  /* Gain: '<S14>/gain' */
  current_mod = test_P.Ts;
  phase = 2.0 / current_mod;
  test_B.gain = phase * test_B.Sum2;

  /* UnitDelay: '<S14>/d1' */
  test_B.d1 = test_DW.d1_DSTATE;

  /* Sum: '<S14>/Sum1' */
  test_B.Sum1 = test_B.gain - test_B.d1;

  /* UnitDelay: '<S16>/d1' */
  test_B.d1_a = test_DW.d1_DSTATE_g;

  /* Sum: '<S16>/Sum3' */
  test_B.Sum3 = test_B.Sum1 + test_B.d1_a;

  /* Gain: '<S16>/gain' */
  test_B.gain_b = test_P.Ts * test_B.Sum3;

  /* Gain: '<S16>/gain2' incorporates:
   *  Constant: '<S8>/Wheel_acc_cutoff'
   */
  test_B.gain2 = test_P.gain2_Gain * test_P.Wheel_acc_cutoff_Value;

  /* Product: '<S16>/Product2' incorporates:
   *  Constant: '<S16>/Constant1'
   */
  test_B.Product2 = test_P.Constant1_Value_a / test_B.gain2;

  /* Gain: '<S16>/gain1' */
  test_B.gain1 = test_P.gain1_Gain * test_B.Product2;

  /* Sum: '<S16>/Sum1' incorporates:
   *  Constant: '<S16>/Constant'
   */
  test_B.Sum1_i = test_B.gain1 - test_P.Ts;

  /* UnitDelay: '<S16>/d' */
  test_B.d_f = test_DW.d_DSTATE_o;

  /* Product: '<S16>/Product11' */
  test_B.Product11 = test_B.Sum1_i * test_B.d_f;

  /* Sum: '<S16>/Sum2' */
  test_B.Sum2_m = test_B.gain_b + test_B.Product11;

  /* Sum: '<S16>/Sum4' incorporates:
   *  Constant: '<S16>/Constant'
   */
  test_B.Sum4 = test_B.gain1 + test_P.Ts;

  /* Product: '<S16>/Product1' */
  test_B.Product1 = test_B.Sum2_m / test_B.Sum4;

  /* S-Function (rti_commonblock): '<S30>/S-Function1' incorporates:
   *  Constant: '<S8>/Steering Input Mode'
   *  Constant: '<S8>/Sys_Ctrlword'
   */
  /* This comment workarounds a code generation problem */

  /* dSPACE RTICAN TX Message Block: "N10_RPDO0" Id:529 */
  {
    UInt32 CAN_Msg[8] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };

    Float32 delayTime = 0.0;

    /* ... Read status and timestamp info (previous message) */
    can_tp1_msg_read(can_type1_msg_M1[CANTP1_M1_C1_TX_STD_0X211]);

    /* Convert timestamp */
    if (can_type1_msg_M1[CANTP1_M1_C1_TX_STD_0X211]->processed) {
      can_type1_msg_M1[CANTP1_M1_C1_TX_STD_0X211]->timestamp =
        rtk_dsts_time_to_simtime_convert
        (can_type1_msg_M1[CANTP1_M1_C1_TX_STD_0X211]->timestamp);
    }

    /* Messages with timestamp zero have been received in pause/stop state
       and must not be handled.
     */
    if (can_type1_msg_M1[CANTP1_M1_C1_TX_STD_0X211]->timestamp > 0.0) {
      test_B.SFunction1_o1_l = (real_T)
        can_type1_msg_M1[CANTP1_M1_C1_TX_STD_0X211]->processed;
      test_B.SFunction1_o2_e = (real_T)
        can_type1_msg_M1[CANTP1_M1_C1_TX_STD_0X211]->timestamp;
      test_B.SFunction1_o3_ij = (real_T)
        can_type1_msg_M1[CANTP1_M1_C1_TX_STD_0X211]->deltatime;
      test_B.SFunction1_o4_d = (real_T)
        can_type1_msg_M1[CANTP1_M1_C1_TX_STD_0X211]->delaytime;
    }

    /* ... Encode Simulink signals of TX and RM blocks*/
    {
      rtican_Signal_t CAN_Sgn;

      /* ...... "Controlword" (0|16, standard signal, unsigned int, little endian) */
      /* Add or substract 0.5 in order to round to nearest integer */
      CAN_Sgn.UnsignedSgn = (UInt32) (( test_P.Sys_Ctrlword_Value ) + 0.5);
      CAN_Sgn.UnsignedSgn &= 0x0000FFFF;
      CAN_Msg[0] |= CAN_Sgn.SgnBytes.Byte0;
      CAN_Msg[1] |= CAN_Sgn.SgnBytes.Byte1;

      /* ...... "Modes_of_operation" (16|8, standard signal, signed int, little endian) */
      /* Add or substract 0.5 in order to round to nearest integer */
      if (( test_P.SteeringInputMode_Value ) < -0.5)
        CAN_Sgn.SignedSgn = (Int32) (( test_P.SteeringInputMode_Value ) - 0.5);
      else
        CAN_Sgn.SignedSgn = (Int32) (( test_P.SteeringInputMode_Value ) + 0.5);
      CAN_Sgn.SignedSgn &= 0x000000FF;
      CAN_Msg[2] |= CAN_Sgn.SgnBytes.Byte0;
    }

    /* ... Write the data to the CAN microcontroller and trigger the sending of the message */
    can_tp1_msg_send(can_type1_msg_M1[CANTP1_M1_C1_TX_STD_0X211], 3, &(CAN_Msg[0]),
                     delayTime);
  }

  /* S-Function (rti_commonblock): '<S32>/S-Function1' incorporates:
   *  Constant: '<S8>/Sys_Ctrlword'
   */
  /* This comment workarounds a code generation problem */

  /* dSPACE RTICAN TX Message Block: "N20_RPDO0" Id:545 */
  {
    UInt32 CAN_Msg[8] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };

    Float32 delayTime = 0.0;

    /* ... Read status and timestamp info (previous message) */
    can_tp1_msg_read(can_type1_msg_M1[CANTP1_M1_C1_TX_STD_0X221]);

    /* Convert timestamp */
    if (can_type1_msg_M1[CANTP1_M1_C1_TX_STD_0X221]->processed) {
      can_type1_msg_M1[CANTP1_M1_C1_TX_STD_0X221]->timestamp =
        rtk_dsts_time_to_simtime_convert
        (can_type1_msg_M1[CANTP1_M1_C1_TX_STD_0X221]->timestamp);
    }

    /* Messages with timestamp zero have been received in pause/stop state
       and must not be handled.
     */
    if (can_type1_msg_M1[CANTP1_M1_C1_TX_STD_0X221]->timestamp > 0.0) {
      test_B.SFunction1_o1_f2 = (real_T)
        can_type1_msg_M1[CANTP1_M1_C1_TX_STD_0X221]->processed;
      test_B.SFunction1_o2_n = (real_T)
        can_type1_msg_M1[CANTP1_M1_C1_TX_STD_0X221]->timestamp;
      test_B.SFunction1_o3_lq = (real_T)
        can_type1_msg_M1[CANTP1_M1_C1_TX_STD_0X221]->deltatime;
      test_B.SFunction1_o4_dm = (real_T)
        can_type1_msg_M1[CANTP1_M1_C1_TX_STD_0X221]->delaytime;
    }

    /* ... Encode Simulink signals of TX and RM blocks*/
    {
      rtican_Signal_t CAN_Sgn;

      /* ...... "Controlword" (0|16, standard signal, unsigned int, little endian) */
      /* Add or substract 0.5 in order to round to nearest integer */
      CAN_Sgn.UnsignedSgn = (UInt32) (( test_P.Sys_Ctrlword_Value ) + 0.5);
      CAN_Sgn.UnsignedSgn &= 0x0000FFFF;
      CAN_Msg[0] |= CAN_Sgn.SgnBytes.Byte0;
      CAN_Msg[1] |= CAN_Sgn.SgnBytes.Byte1;
    }

    /* ... Write the data to the CAN microcontroller and trigger the sending of the message */
    can_tp1_msg_send(can_type1_msg_M1[CANTP1_M1_C1_TX_STD_0X221], 2, &(CAN_Msg[0]),
                     delayTime);
  }

  /* SampleTimeMath: '<S62>/sample time'
   *
   * About '<S62>/sample time':
   *  y = K where K = ( w * Ts )
   */
  test_B.sampletime = test_P.sampletime_WtEt;

  /* Product: '<S62>/delta rise limit' incorporates:
   *  Constant: '<S8>/sus_pos_ref_ratelimit'
   */
  test_B.deltariselimit = test_P.sus_pos_ref_ratelimit_Value * test_B.sampletime;

  /* Product: '<S42>/Product1' incorporates:
   *  Constant: '<S42>/Sus_Target_pos'
   *  Constant: '<S8>/control_on//off'
   */
  test_B.Product1_l = test_P.control_onoff_Value * test_P.Sus_Target_pos_Value;

  /* Saturate: '<S42>/Saturation1' */
  current_mod = test_B.Product1_l;
  phase = test_P.Saturation1_LowerSat;
  q = test_P.Saturation1_UpperSat;
  if (current_mod > q) {
    test_B.Saturation1 = q;
  } else if (current_mod < phase) {
    test_B.Saturation1 = phase;
  } else {
    test_B.Saturation1 = current_mod;
  }

  /* End of Saturate: '<S42>/Saturation1' */

  /* UnitDelay: '<S62>/Delay Input2' */
  test_B.Yk1 = test_DW.DelayInput2_DSTATE;

  /* Sum: '<S62>/Difference Inputs1' */
  test_B.UkYk1 = test_B.Saturation1 - test_B.Yk1;

  /* RelationalOperator: '<S63>/LowerRelop1' */
  test_B.LowerRelop1 = (test_B.UkYk1 > test_B.deltariselimit);

  /* Gain: '<S42>/Gain' incorporates:
   *  Constant: '<S8>/sus_pos_ref_ratelimit'
   */
  test_B.Gain = test_P.Gain_Gain * test_P.sus_pos_ref_ratelimit_Value;

  /* Product: '<S62>/delta fall limit' */
  test_B.deltafalllimit = test_B.Gain * test_B.sampletime;

  /* RelationalOperator: '<S63>/UpperRelop' */
  test_B.UpperRelop = (test_B.UkYk1 < test_B.deltafalllimit);

  /* Switch: '<S63>/Switch' */
  if (test_B.UpperRelop) {
    test_B.Switch = test_B.deltafalllimit;
  } else {
    test_B.Switch = test_B.UkYk1;
  }

  /* End of Switch: '<S63>/Switch' */

  /* Switch: '<S63>/Switch2' */
  if (test_B.LowerRelop1) {
    test_B.Switch2 = test_B.deltariselimit;
  } else {
    test_B.Switch2 = test_B.Switch;
  }

  /* End of Switch: '<S63>/Switch2' */

  /* Sum: '<S62>/Difference Inputs2' */
  test_B.DifferenceInputs2 = test_B.Switch2 + test_B.Yk1;

  /* UnitDelay: '<S61>/d1' */
  test_B.d1_h = test_DW.d1_DSTATE_n;

  /* Sum: '<S61>/Sum3' */
  test_B.Sum3_j = test_B.DifferenceInputs2 + test_B.d1_h;

  /* Gain: '<S61>/gain' */
  test_B.gain_i = test_P.Ts * test_B.Sum3_j;

  /* Gain: '<S61>/gain2' incorporates:
   *  Constant: '<S8>/sus_pos_ref_cutoff'
   */
  test_B.gain2_k = test_P.gain2_Gain_d * test_P.sus_pos_ref_cutoff_Value;

  /* Product: '<S61>/Product2' incorporates:
   *  Constant: '<S61>/Constant1'
   */
  test_B.Product2_m = test_P.Constant1_Value_o / test_B.gain2_k;

  /* Gain: '<S61>/gain1' */
  test_B.gain1_j = test_P.gain1_Gain_a * test_B.Product2_m;

  /* Sum: '<S61>/Sum1' incorporates:
   *  Constant: '<S61>/Constant'
   */
  test_B.Sum1_d = test_B.gain1_j - test_P.Ts;

  /* UnitDelay: '<S61>/d' */
  test_B.d_e = test_DW.d_DSTATE_g;

  /* Product: '<S61>/Product11' */
  test_B.Product11_c = test_B.Sum1_d * test_B.d_e;

  /* Sum: '<S61>/Sum2' */
  test_B.Sum2_j = test_B.gain_i + test_B.Product11_c;

  /* Sum: '<S61>/Sum4' incorporates:
   *  Constant: '<S61>/Constant'
   */
  test_B.Sum4_n = test_B.gain1_j + test_P.Ts;

  /* Product: '<S61>/Product1' */
  test_B.Product1_lu = test_B.Sum2_j / test_B.Sum4_n;

  /* Product: '<S42>/Product3' incorporates:
   *  Constant: '<S8>/N_sus'
   */
  test_B.Product3 = test_B.Product1_lu * test_P.N_sus_Value;

  /* Product: '<S42>/Product5' incorporates:
   *  Constant: '<S42>/Constant1'
   *  Constant: '<S8>/cpt_sus'
   */
  test_B.Product5 = test_P.cpt_sus_Value / test_P.Constant1_Value_h;

  /* Product: '<S42>/Product4' */
  test_B.Product4 = test_B.Product3 * test_B.Product5;

  /* Rounding: '<S42>/Round1' */
  test_B.Round1 = rt_roundd_snf(test_B.Product4);

  /* DataTypeConversion: '<S42>/Data Type Conversion1' */
  test_B.DataTypeConversion1 = test_B.Round1;

  /* S-Function (rti_commonblock): '<S33>/S-Function1' */
  /* This comment workarounds a code generation problem */

  /* dSPACE RTICAN TX Message Block: "N20_RPDO1" Id:546 */
  {
    UInt32 CAN_Msg[8] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };

    Float32 delayTime = 0.0;

    /* ... Read status and timestamp info (previous message) */
    can_tp1_msg_read(can_type1_msg_M1[CANTP1_M1_C1_TX_STD_0X222]);

    /* Convert timestamp */
    if (can_type1_msg_M1[CANTP1_M1_C1_TX_STD_0X222]->processed) {
      can_type1_msg_M1[CANTP1_M1_C1_TX_STD_0X222]->timestamp =
        rtk_dsts_time_to_simtime_convert
        (can_type1_msg_M1[CANTP1_M1_C1_TX_STD_0X222]->timestamp);
    }

    /* Messages with timestamp zero have been received in pause/stop state
       and must not be handled.
     */
    if (can_type1_msg_M1[CANTP1_M1_C1_TX_STD_0X222]->timestamp > 0.0) {
      test_B.SFunction1_o1_p = (real_T)
        can_type1_msg_M1[CANTP1_M1_C1_TX_STD_0X222]->processed;
      test_B.SFunction1_o2_o = (real_T)
        can_type1_msg_M1[CANTP1_M1_C1_TX_STD_0X222]->timestamp;
      test_B.SFunction1_o3_gi = (real_T)
        can_type1_msg_M1[CANTP1_M1_C1_TX_STD_0X222]->deltatime;
      test_B.SFunction1_o4_p = (real_T)
        can_type1_msg_M1[CANTP1_M1_C1_TX_STD_0X222]->delaytime;
    }

    /* ... Encode Simulink signals of TX and RM blocks*/
    {
      rtican_Signal_t CAN_Sgn;

      /* ...... "Target_position" (0|32, standard signal, signed int, little endian) */
      /* Add or substract 0.5 in order to round to nearest integer */
      if (( test_B.DataTypeConversion1 ) < -0.5)
        CAN_Sgn.SignedSgn = (Int32) (( test_B.DataTypeConversion1 ) - 0.5);
      else
        CAN_Sgn.SignedSgn = (Int32) (( test_B.DataTypeConversion1 ) + 0.5);
      CAN_Msg[0] |= CAN_Sgn.SgnBytes.Byte0;
      CAN_Msg[1] |= CAN_Sgn.SgnBytes.Byte1;
      CAN_Msg[2] |= CAN_Sgn.SgnBytes.Byte2;
      CAN_Msg[3] |= CAN_Sgn.SgnBytes.Byte3;
    }

    /* ... Write the data to the CAN microcontroller and trigger the sending of the message */
    can_tp1_msg_send(can_type1_msg_M1[CANTP1_M1_C1_TX_STD_0X222], 4, &(CAN_Msg[0]),
                     delayTime);
  }

  /* Constant: '<S8>/Driving Input Mode' */
  test_B.DrivingInputMode = test_P.DrivingInputMode_Value;

  /* If: '<S102>/If' */
  if (test_B.DrivingInputMode == 0.0) {
    rtAction = 0;

    /* Outputs for IfAction SubSystem: '<S102>/Velocity Mode' incorporates:
     *  ActionPort: '<S106>/Action Port'
     */
    /* SignalConversion: '<S106>/OutportBufferForOut1' incorporates:
     *  Constant: '<S106>/Constant'
     */
    test_B.Merge = test_P.Constant_Value;

    /* End of Outputs for SubSystem: '<S102>/Velocity Mode' */
  } else if (test_B.DrivingInputMode == 1.0) {
    rtAction = 1;

    /* Outputs for IfAction SubSystem: '<S102>/Torque Mode' incorporates:
     *  ActionPort: '<S104>/Action Port'
     */
    test_TorqueMode(&test_B.Merge, &test_B.Merge1, &test_P.TorqueMode);

    /* End of Outputs for SubSystem: '<S102>/Torque Mode' */
  } else if (test_B.DrivingInputMode == 2.0) {
    rtAction = 2;

    /* Outputs for IfAction SubSystem: '<S102>/Torque Mode1' incorporates:
     *  ActionPort: '<S105>/Action Port'
     */
    test_TorqueMode(&test_B.Merge, &test_B.Merge1, &test_P.TorqueMode1);

    /* End of Outputs for SubSystem: '<S102>/Torque Mode1' */
  } else {
    rtAction = 3;

    /* Outputs for IfAction SubSystem: '<S102>/ID_Mode' incorporates:
     *  ActionPort: '<S103>/Action Port'
     */
    test_TorqueMode(&test_B.Merge, &test_B.Merge1, &test_P.ID_Mode);

    /* End of Outputs for SubSystem: '<S102>/ID_Mode' */
  }

  test_DW.If_ActiveSubsystem = rtAction;

  /* End of If: '<S102>/If' */

  /* SampleTimeMath: '<S56>/sample time'
   *
   * About '<S56>/sample time':
   *  y = K where K = ( w * Ts )
   */
  test_B.sampletime_d = test_P.sampletime_WtEt_j;

  /* Product: '<S56>/delta rise limit' incorporates:
   *  Constant: '<S8>/dri_vel_ref_ratelimit'
   */
  test_B.deltariselimit_n = test_P.dri_vel_ref_ratelimit_Value *
    test_B.sampletime_d;

  /* Product: '<S44>/Product3' incorporates:
   *  Constant: '<S8>/control_on//off'
   *  Constant: '<S8>/dri_target_vel_ref'
   */
  test_B.Product3_i = test_P.control_onoff_Value *
    test_P.dri_target_vel_ref_Value;

  /* Saturate: '<S44>/Saturation2' */
  current_mod = test_B.Product3_i;
  phase = test_P.Saturation2_LowerSat;
  q = test_P.Saturation2_UpperSat;
  if (current_mod > q) {
    test_B.Saturation2 = q;
  } else if (current_mod < phase) {
    test_B.Saturation2 = phase;
  } else {
    test_B.Saturation2 = current_mod;
  }

  /* End of Saturate: '<S44>/Saturation2' */

  /* UnitDelay: '<S56>/Delay Input2' */
  test_B.Yk1_e = test_DW.DelayInput2_DSTATE_a;

  /* Sum: '<S56>/Difference Inputs1' */
  test_B.UkYk1_m = test_B.Saturation2 - test_B.Yk1_e;

  /* RelationalOperator: '<S57>/LowerRelop1' */
  test_B.LowerRelop1_g = (test_B.UkYk1_m > test_B.deltariselimit_n);

  /* Gain: '<S44>/Gain1' incorporates:
   *  Constant: '<S8>/dri_vel_ref_ratelimit'
   */
  test_B.Gain1 = test_P.Gain1_Gain * test_P.dri_vel_ref_ratelimit_Value;

  /* Product: '<S56>/delta fall limit' */
  test_B.deltafalllimit_l = test_B.Gain1 * test_B.sampletime_d;

  /* RelationalOperator: '<S57>/UpperRelop' */
  test_B.UpperRelop_b = (test_B.UkYk1_m < test_B.deltafalllimit_l);

  /* Switch: '<S57>/Switch' */
  if (test_B.UpperRelop_b) {
    test_B.Switch_n = test_B.deltafalllimit_l;
  } else {
    test_B.Switch_n = test_B.UkYk1_m;
  }

  /* End of Switch: '<S57>/Switch' */

  /* Switch: '<S57>/Switch2' */
  if (test_B.LowerRelop1_g) {
    test_B.Switch2_a = test_B.deltariselimit_n;
  } else {
    test_B.Switch2_a = test_B.Switch_n;
  }

  /* End of Switch: '<S57>/Switch2' */

  /* Sum: '<S56>/Difference Inputs2' */
  test_B.DifferenceInputs2_a = test_B.Switch2_a + test_B.Yk1_e;

  /* UnitDelay: '<S55>/d1' */
  test_B.d1_m = test_DW.d1_DSTATE_e;

  /* Sum: '<S55>/Sum3' */
  test_B.Sum3_c = test_B.DifferenceInputs2_a + test_B.d1_m;

  /* Gain: '<S55>/gain' */
  test_B.gain_f = test_P.Ts * test_B.Sum3_c;

  /* Gain: '<S55>/gain2' incorporates:
   *  Constant: '<S8>/dri_vel_ref_cutoff'
   */
  test_B.gain2_o = test_P.gain2_Gain_a * test_P.dri_vel_ref_cutoff_Value;

  /* Product: '<S55>/Product2' incorporates:
   *  Constant: '<S55>/Constant1'
   */
  test_B.Product2_l = test_P.Constant1_Value_n / test_B.gain2_o;

  /* Gain: '<S55>/gain1' */
  test_B.gain1_b = test_P.gain1_Gain_k * test_B.Product2_l;

  /* Sum: '<S55>/Sum1' incorporates:
   *  Constant: '<S55>/Constant'
   */
  test_B.Sum1_o = test_B.gain1_b - test_P.Ts;

  /* UnitDelay: '<S55>/d' */
  test_B.d_fp = test_DW.d_DSTATE_c;

  /* Product: '<S55>/Product11' */
  test_B.Product11_m = test_B.Sum1_o * test_B.d_fp;

  /* Sum: '<S55>/Sum2' */
  test_B.Sum2_mm = test_B.gain_f + test_B.Product11_m;

  /* Sum: '<S55>/Sum4' incorporates:
   *  Constant: '<S55>/Constant'
   */
  test_B.Sum4_nc = test_B.gain1_b + test_P.Ts;

  /* Product: '<S55>/Product1' */
  test_B.Product1_j = test_B.Sum2_mm / test_B.Sum4_nc;

  /* Product: '<S44>/Product8' incorporates:
   *  Constant: '<S44>/Constant2'
   *  Constant: '<S8>/radius'
   */
  test_B.Product8 = test_P.Constant2_Value_c * test_P.radius_Value;

  /* Product: '<S44>/Product9' incorporates:
   *  Constant: '<S44>/Constant3'
   */
  test_B.Product9 = test_P.Constant3_Value_m / test_B.Product8;

  /* Product: '<S44>/Product6' */
  test_B.Product6 = test_B.Product1_j * test_B.Product9;

  /* Product: '<S44>/Product7' incorporates:
   *  Constant: '<S8>/N_dri'
   */
  test_B.Product7 = test_B.Product6 * test_P.N_dri_Value_o;

  /* Product: '<S44>/Product10' incorporates:
   *  Constant: '<S44>/Constant4'
   */
  test_B.Product10 = test_B.Product7 * test_P.Constant4_Value;

  /* DataTypeConversion: '<S44>/Data Type Conversion2' */
  test_B.DataTypeConversion2 = test_B.Product10;

  /* Gain: '<S8>/Gain' incorporates:
   *  Constant: '<S8>/control_on//off'
   */
  test_B.Gain_m = test_P.Ts * test_P.control_onoff_Value;

  /* Delay: '<S8>/Delay1' */
  test_B.Delay1 = test_DW.Delay1_DSTATE;

  /* Sum: '<S8>/Add' */
  test_B.Add_b = test_B.Gain_m + test_B.Delay1;

  /* Product: '<S8>/Product' incorporates:
   *  Constant: '<S8>/control_on//off'
   */
  test_B.Product = test_P.control_onoff_Value * test_B.Add_b;

  /* MATLAB Function: '<S43>/MATLAB Function' incorporates:
   *  Constant: '<S8>/control_on//off'
   *  Constant: '<S8>/dri_torque_ref_freq'
   *  Constant: '<S8>/dri_torque_ref_mag'
   */
  /* MATLAB Function '_Reference/_dri_motor_ref/Driving_Torque_Ref/MATLAB Function': '<S52>:1' */
  if (test_P.control_onoff_Value == 0.0) {
    /* '<S52>:1:6' */
    /* '<S52>:1:8' */
    test_B.y = 0.0;

    /* '<S52>:1:9' */
    test_DW.current_f = test_P.dri_torque_ref_freq_Value;
    test_DW.current_f_not_empty = true;

    /* '<S52>:1:10' */
    test_DW.next_f = test_P.dri_torque_ref_freq_Value;

    /* '<S52>:1:11' */
    test_DW.current_mag = test_P.dri_torque_ref_mag_Value;

    /* '<S52>:1:12' */
    test_DW.next_mag = test_P.dri_torque_ref_mag_Value;

    /* '<S52>:1:13' */
    test_DW.t0 = test_B.Product;

    /* '<S52>:1:14' */
    test_DW.prev_phase = 0.0;
  } else {
    if (!test_DW.current_f_not_empty) {
      /* '<S52>:1:17' */
      /* '<S52>:1:18' */
      test_DW.current_f = test_P.dri_torque_ref_freq_Value;
      test_DW.current_f_not_empty = true;

      /* '<S52>:1:19' */
      test_DW.next_f = test_P.dri_torque_ref_freq_Value;

      /* '<S52>:1:20' */
      test_DW.current_mag = test_P.dri_torque_ref_mag_Value;

      /* '<S52>:1:21' */
      test_DW.next_mag = test_P.dri_torque_ref_mag_Value;

      /* '<S52>:1:22' */
      test_DW.t0 = test_B.Product;

      /* '<S52>:1:23' */
      test_DW.prev_phase = 0.0;
    }

    if (test_P.dri_torque_ref_freq_Value != test_DW.current_f) {
      /* '<S52>:1:27' */
      /* '<S52>:1:28' */
      test_DW.next_f = test_P.dri_torque_ref_freq_Value;
    }

    if (test_P.dri_torque_ref_mag_Value != test_DW.current_mag) {
      /* '<S52>:1:30' */
      /* '<S52>:1:31' */
      test_DW.next_mag = test_P.dri_torque_ref_mag_Value;
    }

    /* '<S52>:1:35' */
    phase = 6.2831853071795862 * test_DW.current_f * (test_B.Product -
      test_DW.t0);

    /* '<S52>:1:36' */
    test_B.y = test_DW.current_mag * sin(phase);

    /* '<S52>:1:39' */
    if ((!rtIsInf(phase)) && (!rtIsNaN(phase))) {
      if (phase == 0.0) {
        current_mod = 0.0;
      } else {
        current_mod = fmod(phase, 6.2831853071795862);
        rEQ0 = (current_mod == 0.0);
        if (!rEQ0) {
          q = fabs(phase / 6.2831853071795862);
          rEQ0 = (fabs(q - floor(q + 0.5)) <= 2.2204460492503131E-16 * q);
        }

        if (rEQ0) {
          current_mod = 0.0;
        } else {
          if (phase < 0.0) {
            current_mod += 6.2831853071795862;
          }
        }
      }
    } else {
      current_mod = (rtNaN);
    }

    if (current_mod < test_DW.prev_phase) {
      /* '<S52>:1:42' */
      /* '<S52>:1:44' */
      test_DW.current_f = test_DW.next_f;

      /* '<S52>:1:45' */
      test_DW.current_mag = test_DW.next_mag;

      /* '<S52>:1:46' */
      test_DW.t0 = test_B.Product;
    }

    /* '<S52>:1:50' */
    test_DW.prev_phase = current_mod;
  }

  /* End of MATLAB Function: '<S43>/MATLAB Function' */

  /* SampleTimeMath: '<S53>/sample time'
   *
   * About '<S53>/sample time':
   *  y = K where K = ( w * Ts )
   */
  test_B.sampletime_i = test_P.sampletime_WtEt_m;

  /* Product: '<S53>/delta rise limit' incorporates:
   *  Constant: '<S8>/dri_vel_ref_ratelimit'
   */
  test_B.deltariselimit_b = test_P.dri_vel_ref_ratelimit_Value *
    test_B.sampletime_i;

  /* Product: '<S43>/Product3' incorporates:
   *  Constant: '<S8>/control_on//off'
   *  Constant: '<S8>/dri_target_vel_ref'
   */
  test_B.Product3_e = test_P.control_onoff_Value *
    test_P.dri_target_vel_ref_Value;

  /* Saturate: '<S43>/Saturation2' */
  current_mod = test_B.Product3_e;
  phase = test_P.Saturation2_LowerSat_n;
  q = test_P.Saturation2_UpperSat_l;
  if (current_mod > q) {
    test_B.Saturation2_d = q;
  } else if (current_mod < phase) {
    test_B.Saturation2_d = phase;
  } else {
    test_B.Saturation2_d = current_mod;
  }

  /* End of Saturate: '<S43>/Saturation2' */

  /* UnitDelay: '<S53>/Delay Input2' */
  test_B.Yk1_a = test_DW.DelayInput2_DSTATE_p;

  /* Sum: '<S53>/Difference Inputs1' */
  test_B.UkYk1_h = test_B.Saturation2_d - test_B.Yk1_a;

  /* RelationalOperator: '<S54>/LowerRelop1' */
  test_B.LowerRelop1_j = (test_B.UkYk1_h > test_B.deltariselimit_b);

  /* Gain: '<S43>/Gain1' incorporates:
   *  Constant: '<S8>/dri_vel_ref_ratelimit'
   */
  test_B.Gain1_i = test_P.Gain1_Gain_m * test_P.dri_vel_ref_ratelimit_Value;

  /* Product: '<S53>/delta fall limit' */
  test_B.deltafalllimit_i = test_B.Gain1_i * test_B.sampletime_i;

  /* RelationalOperator: '<S54>/UpperRelop' */
  test_B.UpperRelop_a = (test_B.UkYk1_h < test_B.deltafalllimit_i);

  /* Switch: '<S54>/Switch' */
  if (test_B.UpperRelop_a) {
    test_B.Switch_a = test_B.deltafalllimit_i;
  } else {
    test_B.Switch_a = test_B.UkYk1_h;
  }

  /* End of Switch: '<S54>/Switch' */

  /* Switch: '<S54>/Switch2' */
  if (test_B.LowerRelop1_j) {
    test_B.Switch2_o = test_B.deltariselimit_b;
  } else {
    test_B.Switch2_o = test_B.Switch_a;
  }

  /* End of Switch: '<S54>/Switch2' */

  /* Sum: '<S53>/Difference Inputs2' */
  test_B.DifferenceInputs2_n = test_B.Switch2_o + test_B.Yk1_a;

  /* UnitDelay: '<S51>/d1' */
  test_B.d1_k = test_DW.d1_DSTATE_p;

  /* Sum: '<S51>/Sum3' */
  test_B.Sum3_d = test_B.DifferenceInputs2_n + test_B.d1_k;

  /* Gain: '<S51>/gain' */
  test_B.gain_g = test_P.Ts * test_B.Sum3_d;

  /* Gain: '<S51>/gain2' incorporates:
   *  Constant: '<S8>/dri_vel_ref_cutoff'
   */
  test_B.gain2_oj = test_P.gain2_Gain_f * test_P.dri_vel_ref_cutoff_Value;

  /* Product: '<S51>/Product2' incorporates:
   *  Constant: '<S51>/Constant1'
   */
  test_B.Product2_k = test_P.Constant1_Value_d / test_B.gain2_oj;

  /* Gain: '<S51>/gain1' */
  test_B.gain1_l = test_P.gain1_Gain_o * test_B.Product2_k;

  /* Sum: '<S51>/Sum1' incorporates:
   *  Constant: '<S51>/Constant'
   */
  test_B.Sum1_n = test_B.gain1_l - test_P.Ts;

  /* UnitDelay: '<S51>/d' */
  test_B.d_g = test_DW.d_DSTATE_f;

  /* Product: '<S51>/Product11' */
  test_B.Product11_l = test_B.Sum1_n * test_B.d_g;

  /* Sum: '<S51>/Sum2' */
  test_B.Sum2_o = test_B.gain_g + test_B.Product11_l;

  /* Sum: '<S51>/Sum4' incorporates:
   *  Constant: '<S51>/Constant'
   */
  test_B.Sum4_b = test_B.gain1_l + test_P.Ts;

  /* Product: '<S51>/Product1' */
  test_B.Product1_f = test_B.Sum2_o / test_B.Sum4_b;

  /* If: '<S43>/If1' incorporates:
   *  Constant: '<S43>/Constant'
   */
  if (test_B.Merge1 == 1.0) {
    /* Outputs for IfAction SubSystem: '<S43>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S49>/Action Port'
     */
    test_IfActionSubsystem2(test_B.y, &test_B.Merge1_d);

    /* End of Outputs for SubSystem: '<S43>/If Action Subsystem2' */
  } else if (test_B.Merge1 == 2.0) {
    /* Outputs for IfAction SubSystem: '<S43>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S48>/Action Port'
     */
    test_IfActionSubsystem2(test_B.Product1_f, &test_B.Merge1_d);

    /* End of Outputs for SubSystem: '<S43>/If Action Subsystem1' */
  } else {
    /* Outputs for IfAction SubSystem: '<S43>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S50>/Action Port'
     */
    test_IfActionSubsystem2(test_P.Constant_Value_k, &test_B.Merge1_d);

    /* End of Outputs for SubSystem: '<S43>/If Action Subsystem3' */
  }

  /* End of If: '<S43>/If1' */

  /* If: '<S40>/If1' incorporates:
   *  Constant: '<S40>/Constant'
   */
  if (test_B.Merge == 9.0) {
    /* Outputs for IfAction SubSystem: '<S40>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S46>/Action Port'
     */
    test_IfActionSubsystem2(test_B.DataTypeConversion2, &test_B.Merge1_e);

    /* End of Outputs for SubSystem: '<S40>/If Action Subsystem2' */
  } else if (test_B.Merge == 10.0) {
    /* Outputs for IfAction SubSystem: '<S40>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S45>/Action Port'
     */
    test_IfActionSubsystem2(test_B.Merge1_d, &test_B.Merge1_e);

    /* End of Outputs for SubSystem: '<S40>/If Action Subsystem1' */
  } else {
    /* Outputs for IfAction SubSystem: '<S40>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S47>/Action Port'
     */
    test_IfActionSubsystem2(test_P.Constant_Value_h, &test_B.Merge1_e);

    /* End of Outputs for SubSystem: '<S40>/If Action Subsystem3' */
  }

  /* End of If: '<S40>/If1' */

  /* FromWorkspace: '<S39>/From Workspace' */
  {
    real_T *pDataValues = (real_T *) test_DW.FromWorkspace_PWORK.DataPtr;

    {
      int_T elIdx;
      for (elIdx = 0; elIdx < 9999; ++elIdx) {
        (&test_B.FromWorkspace[0])[elIdx] = pDataValues[0];
        pDataValues += 1;
      }
    }
  }

  /* Constant: '<S8>/ID_OnOff' */
  test_B.ID_OnOff = test_P.ID_OnOff_Value;

  /* Gain: '<S8>/Gain1' */
  test_B.Gain1_b = test_P.Ts * test_B.ID_OnOff;

  /* Delay: '<S8>/Delay2' */
  test_B.Delay2 = test_DW.Delay2_DSTATE;

  /* Sum: '<S8>/Add1' */
  test_B.Add1 = test_B.Gain1_b + test_B.Delay2;

  /* Product: '<S8>/Product1' */
  test_B.Product1_a = test_B.ID_OnOff * test_B.Add1;

  /* Gain: '<S39>/Gain1' */
  current_mod = test_P.Ts;
  phase = 1.0 / current_mod;
  test_B.Gain1_m = phase * test_B.Product1_a;

  /* Sum: '<S39>/Add' incorporates:
   *  Constant: '<S39>/Constant1'
   */
  test_B.Add_a = test_B.Gain1_m + test_P.Constant1_Value_c;

  /* Selector: '<S39>/Selector' */
  test_B.Selector = test_B.FromWorkspace[(int32_T)test_B.Add_a - 1];

  /* Switch: '<S39>/Switch' incorporates:
   *  Constant: '<S39>/Constant2'
   *  Constant: '<S39>/Constant3'
   */
  if (test_B.Product1_a > test_P.Switch_Threshold) {
    test_B.Switch_m = test_P.Constant2_Value;
  } else {
    test_B.Switch_m = test_P.Constant3_Value;
  }

  /* End of Switch: '<S39>/Switch' */

  /* Product: '<S39>/Divide1' */
  test_B.Divide1_a = test_B.Selector * test_B.Switch_m;

  /* Product: '<S39>/Divide2' */
  test_B.Divide2_l = test_B.Divide1_a * test_B.ID_OnOff;

  /* Gain: '<S39>/Torque Constant' */
  test_B.TorqueConstant = test_P.TorqueConstant_Gain * test_B.Divide2_l;

  /* Constant: '<S39>/Constant' */
  test_B.Constant_p = test_P.Constant_Value_g;

  /* Product: '<S39>/Divide' */
  test_B.Divide = test_B.TorqueConstant / test_B.Constant_p;

  /* Gain: '<S39>/Gain' */
  test_B.Gain_i = test_P.Gain_Gain_i * test_B.Divide;

  /* Product: '<S77>/Divide1' incorporates:
   *  Constant: '<S8>/dri_FF_OnOff'
   */
  test_B.Divide1_ad = test_B.Merge1_e * test_P.dri_FF_OnOff_Value;

  /* UnitDelay: '<S82>/d' */
  test_B.d_l = test_DW.d_DSTATE_cq;

  /* Sum: '<S82>/Sum2' */
  test_B.Sum2_i = test_B.Divide1_ad - test_B.d_l;

  /* Gain: '<S82>/gain' */
  current_mod = test_P.Ts;
  phase = 2.0 / current_mod;
  test_B.gain_gx = phase * test_B.Sum2_i;

  /* UnitDelay: '<S82>/d1' */
  test_B.d1_p = test_DW.d1_DSTATE_f;

  /* Sum: '<S82>/Sum1' */
  test_B.Sum1_i2 = test_B.gain_gx - test_B.d1_p;

  /* Product: '<S77>/Divide2' incorporates:
   *  Constant: '<S8>/wheel_Jn'
   */
  test_B.Divide2_n = test_P.wheel_Jn_Value * test_B.Sum1_i2;

  /* Product: '<S77>/Divide4' incorporates:
   *  Constant: '<S8>/wheel_Bn'
   */
  test_B.Divide4_c = test_P.wheel_Bn_Value * test_B.Divide1_ad;

  /* Sum: '<S77>/Add5' */
  test_B.Add5 = test_B.Divide2_n + test_B.Divide4_c;

  /* UnitDelay: '<S83>/d1' */
  test_B.d1_hw = test_DW.d1_DSTATE_ga;

  /* Sum: '<S83>/Sum3' */
  test_B.Sum3_p = test_B.Add5 + test_B.d1_hw;

  /* Gain: '<S83>/gain' */
  test_B.gain_n = test_P.Ts * test_B.Sum3_p;

  /* Gain: '<S83>/gain2' incorporates:
   *  Constant: '<S8>/dri_FF_CutOff'
   */
  test_B.gain2_d = test_P.gain2_Gain_n * test_P.dri_FF_CutOff_Value;

  /* Product: '<S83>/Product2' incorporates:
   *  Constant: '<S83>/Constant1'
   */
  test_B.Product2_h = test_P.Constant1_Value_k / test_B.gain2_d;

  /* Gain: '<S83>/gain1' */
  test_B.gain1_f = test_P.gain1_Gain_e * test_B.Product2_h;

  /* Sum: '<S83>/Sum1' incorporates:
   *  Constant: '<S83>/Constant'
   */
  test_B.Sum1_h = test_B.gain1_f - test_P.Ts;

  /* UnitDelay: '<S83>/d' */
  test_B.d_p = test_DW.d_DSTATE_h;

  /* Product: '<S83>/Product11' */
  test_B.Product11_j = test_B.Sum1_h * test_B.d_p;

  /* Sum: '<S83>/Sum2' */
  test_B.Sum2_e = test_B.gain_n + test_B.Product11_j;

  /* Sum: '<S83>/Sum4' incorporates:
   *  Constant: '<S83>/Constant'
   */
  test_B.Sum4_a = test_B.gain1_f + test_P.Ts;

  /* Product: '<S83>/Product1' */
  test_B.Product1_p = test_B.Sum2_e / test_B.Sum4_a;

  /* Product: '<S77>/Divide' incorporates:
   *  Constant: '<S8>/dri_FF_OnOff'
   */
  test_B.Divide_n = test_B.Product1_p * test_P.dri_FF_OnOff_Value;

  /* Saturate: '<S78>/Saturation' incorporates:
   *  Constant: '<S8>/dri_PID_zeta'
   */
  current_mod = test_P.dri_PID_zeta_Value;
  phase = test_P.Saturation_LowerSat_e;
  q = test_P.Saturation_UpperSat_c;
  if (current_mod > q) {
    test_B.Saturation_c = q;
  } else if (current_mod < phase) {
    test_B.Saturation_c = phase;
  } else {
    test_B.Saturation_c = current_mod;
  }

  /* End of Saturate: '<S78>/Saturation' */

  /* Gain: '<S78>/gain 1' */
  test_B.gain1_l0 = test_P.gain1_Gain_g * test_B.Saturation_c;

  /* Gain: '<S78>/gain ' incorporates:
   *  Constant: '<S8>/dri_PID_CutOff'
   */
  test_B.gain_o = test_P.gain_Gain * test_P.dri_PID_CutOff_Value;

  /* Product: '<S78>/Divide6' incorporates:
   *  Constant: '<S8>/wheel_Jn'
   */
  test_B.Divide6 = test_B.gain1_l0 * test_B.gain_o * test_P.wheel_Jn_Value;

  /* Sum: '<S78>/Add1' incorporates:
   *  Constant: '<S8>/wheel_Bn'
   */
  test_B.Add1_b = test_B.Divide6 - test_P.wheel_Bn_Value;

  /* Sum: '<S65>/Add1' */
  test_B.Add1_p = test_B.Merge1_e - test_B.Divide1;

  /* Product: '<S78>/Divide' incorporates:
   *  Constant: '<S8>/dri_PID_OnOff'
   */
  test_B.Divide_m = test_B.Add1_p * test_P.dri_PID_OnOff_Value;

  /* Product: '<S78>/Divide1' */
  test_B.Divide1_m = test_B.Add1_b * test_B.Divide_m;

  /* Product: '<S78>/Divide3' */
  test_B.Divide3_m = test_B.gain_o * test_B.gain_o;

  /* Product: '<S78>/Divide4' incorporates:
   *  Constant: '<S8>/wheel_Jn'
   */
  test_B.Divide4_n = test_B.Divide3_m * test_P.wheel_Jn_Value;

  /* Sum: '<S78>/Add' */
  test_B.Add_i = test_B.gain_o + test_B.Divide4_n;

  /* RelationalOperator: '<S85>/LowerRelop1' */
  test_B.LowerRelop1_e = (test_B.Divide4_n > test_B.Add_i);

  /* RelationalOperator: '<S85>/UpperRelop' incorporates:
   *  Constant: '<S78>/Constant1'
   */
  test_B.UpperRelop_g = (test_B.Divide4_n < test_P.Ts);

  /* Switch: '<S85>/Switch' incorporates:
   *  Constant: '<S78>/Constant1'
   */
  if (test_B.UpperRelop_g) {
    test_B.Switch_h = test_P.Ts;
  } else {
    test_B.Switch_h = test_B.Divide4_n;
  }

  /* End of Switch: '<S85>/Switch' */

  /* Switch: '<S85>/Switch2' */
  if (test_B.LowerRelop1_e) {
    test_B.Switch2_g = test_B.Add_i;
  } else {
    test_B.Switch2_g = test_B.Switch_h;
  }

  /* End of Switch: '<S85>/Switch2' */

  /* Product: '<S78>/Divide9' */
  test_B.Divide9 = test_B.gain_o * test_B.gain_o / test_B.Switch2_g;

  /* Product: '<S78>/Divide7' incorporates:
   *  Constant: '<S65>/Constant'
   */
  test_B.Divide7 = test_P.Constant_Value_n * test_B.Divide9;

  /* Sum: '<S78>/Sum2' */
  test_B.Sum2_h = test_B.Divide_m + test_B.Divide7;

  /* UnitDelay: '<S84>/d1' */
  test_B.d1_n = test_DW.d1_DSTATE_d;

  /* Sum: '<S84>/Sum1' */
  test_B.Sum1_f = test_B.Sum2_h + test_B.d1_n;

  /* Gain: '<S84>/gain' */
  phase = test_P.Ts;
  phase /= 2.0;
  test_B.gain_a = phase * test_B.Sum1_f;

  /* UnitDelay: '<S84>/d' */
  test_B.d_b = test_DW.d_DSTATE_p;

  /* Sum: '<S84>/Sum2' */
  test_B.Sum2_p = test_B.gain_a + test_B.d_b;

  /* Product: '<S78>/Divide2' */
  test_B.Divide2_c = test_B.Sum2_p * test_B.Divide4_n;

  /* Sum: '<S78>/Sum1' */
  test_B.Sum1_a = test_B.Divide1_m + test_B.Divide2_c;

  /* Product: '<S78>/Divide5' incorporates:
   *  Constant: '<S8>/dri_PID_OnOff'
   */
  test_B.Divide5 = test_B.Sum1_a * test_P.dri_PID_OnOff_Value;

  /* Delay: '<S76>/Delay' */
  test_B.Delay = test_DW.Delay_DSTATE;

  /* Product: '<S76>/Divide5' incorporates:
   *  Constant: '<S8>/dri_DOB_OnOff'
   */
  test_B.Divide5_a = test_B.Delay * test_P.dri_DOB_OnOff_Value;

  /* Product: '<S76>/Divide1' incorporates:
   *  Constant: '<S8>/dri_DOB_OnOff'
   */
  test_B.Divide1_l = test_B.Divide1 * test_P.dri_DOB_OnOff_Value;

  /* UnitDelay: '<S80>/d' */
  test_B.d_o = test_DW.d_DSTATE_fu;

  /* Sum: '<S80>/Sum2' */
  test_B.Sum2_g = test_B.Divide1_l - test_B.d_o;

  /* Gain: '<S80>/gain' */
  current_mod = test_P.Ts;
  phase = 2.0 / current_mod;
  test_B.gain_fg = phase * test_B.Sum2_g;

  /* UnitDelay: '<S80>/d1' */
  test_B.d1_h0 = test_DW.d1_DSTATE_fx;

  /* Sum: '<S80>/Sum1' */
  test_B.Sum1_is = test_B.gain_fg - test_B.d1_h0;

  /* Product: '<S76>/Divide2' incorporates:
   *  Constant: '<S8>/wheel_Jn'
   */
  test_B.Divide2_j = test_P.wheel_Jn_Value * test_B.Sum1_is;

  /* Product: '<S76>/Divide4' incorporates:
   *  Constant: '<S8>/wheel_Bn'
   */
  test_B.Divide4_i = test_P.wheel_Bn_Value * test_B.Divide1_l;

  /* Sum: '<S76>/Add2' */
  test_B.Add2 = test_B.Divide2_j + test_B.Divide4_i;

  /* Sum: '<S76>/Add1' */
  test_B.Add1_g = test_B.Add2 - test_B.Divide5_a;

  /* UnitDelay: '<S81>/d1' */
  test_B.d1_i = test_DW.d1_DSTATE_m;

  /* Sum: '<S81>/Sum3' */
  test_B.Sum3_k = test_B.Add1_g + test_B.d1_i;

  /* Gain: '<S81>/gain' */
  test_B.gain_ff = test_P.Ts * test_B.Sum3_k;

  /* Gain: '<S81>/gain2' incorporates:
   *  Constant: '<S8>/dri_DOB_CutOff'
   */
  test_B.gain2_p = test_P.gain2_Gain_m * test_P.dri_DOB_CutOff_Value;

  /* Product: '<S81>/Product2' incorporates:
   *  Constant: '<S81>/Constant1'
   */
  test_B.Product2_e = test_P.Constant1_Value_ax / test_B.gain2_p;

  /* Gain: '<S81>/gain1' */
  test_B.gain1_p = test_P.gain1_Gain_an * test_B.Product2_e;

  /* Sum: '<S81>/Sum1' incorporates:
   *  Constant: '<S81>/Constant'
   */
  test_B.Sum1_e = test_B.gain1_p - test_P.Ts;

  /* UnitDelay: '<S81>/d' */
  test_B.d_n = test_DW.d_DSTATE_m;

  /* Product: '<S81>/Product11' */
  test_B.Product11_i = test_B.Sum1_e * test_B.d_n;

  /* Sum: '<S81>/Sum2' */
  test_B.Sum2_c = test_B.gain_ff + test_B.Product11_i;

  /* Sum: '<S81>/Sum4' incorporates:
   *  Constant: '<S81>/Constant'
   */
  test_B.Sum4_m = test_B.gain1_p + test_P.Ts;

  /* Product: '<S81>/Product1' */
  test_B.Product1_l5 = test_B.Sum2_c / test_B.Sum4_m;

  /* Product: '<S76>/Divide6' incorporates:
   *  Constant: '<S8>/dri_DOB_OnOff'
   */
  test_B.Divide6_e = test_B.Product1_l5 * test_P.dri_DOB_OnOff_Value;

  /* Sum: '<S65>/Add' */
  test_B.Add_j = (test_B.Divide_n + test_B.Divide5) - test_B.Divide6_e;

  /* Product: '<S79>/Divide3' incorporates:
   *  Constant: '<S79>/Constant2'
   */
  test_B.Divide3_i = test_B.Add_j / test_P.Constant2_Value_p;

  /* Product: '<S79>/Divide1' incorporates:
   *  Constant: '<S79>/Constant1'
   */
  test_B.Divide1_g = test_B.Divide3_i * test_P.Constant1_Value_m;

  /* RelationalOperator: '<S86>/LowerRelop1' incorporates:
   *  Constant: '<S79>/Constant'
   */
  test_B.LowerRelop1_a = (test_B.Divide1_g > test_P.Constant_Value_ju);

  /* Gain: '<S79>/Gain1' incorporates:
   *  Constant: '<S79>/Constant'
   */
  test_B.Gain1_o = test_P.Gain1_Gain_f * test_P.Constant_Value_ju;

  /* RelationalOperator: '<S86>/UpperRelop' */
  test_B.UpperRelop_m = (test_B.Divide1_g < test_B.Gain1_o);

  /* Switch: '<S86>/Switch' */
  if (test_B.UpperRelop_m) {
    test_B.Switch_b = test_B.Gain1_o;
  } else {
    test_B.Switch_b = test_B.Divide1_g;
  }

  /* End of Switch: '<S86>/Switch' */

  /* Switch: '<S86>/Switch2' incorporates:
   *  Constant: '<S79>/Constant'
   */
  if (test_B.LowerRelop1_a) {
    test_B.Switch2_b = test_P.Constant_Value_ju;
  } else {
    test_B.Switch2_b = test_B.Switch_b;
  }

  /* End of Switch: '<S86>/Switch2' */

  /* Product: '<S79>/Divide' incorporates:
   *  Constant: '<S79>/Constant'
   */
  test_B.Divide_i = test_B.Switch2_b / test_P.Constant_Value_ju;

  /* Gain: '<S79>/Gain' */
  test_B.Gain_f = test_P.Gain_Gain_c * test_B.Divide_i;

  /* If: '<S6>/If' */
  if ((test_B.Merge1 == 1.0) || (test_B.Merge1 == 2.0)) {
    /* Outputs for IfAction SubSystem: '<S6>/If Action Subsystem' incorporates:
     *  ActionPort: '<S66>/Action Port'
     */
    test_IfActionSubsystem2(test_B.Gain_f, &test_B.Merge_m);

    /* End of Outputs for SubSystem: '<S6>/If Action Subsystem' */
  } else {
    /* Outputs for IfAction SubSystem: '<S6>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S67>/Action Port'
     */
    test_IfActionSubsystem2(test_B.Gain_i, &test_B.Merge_m);

    /* End of Outputs for SubSystem: '<S6>/If Action Subsystem1' */
  }

  /* End of If: '<S6>/If' */

  /* Product: '<S6>/Product' incorporates:
   *  Constant: '<S8>/control_on//off'
   */
  test_B.Product_h = test_P.control_onoff_Value * test_B.Merge_m;

  /* S-Function (rti_commonblock): '<S35>/S-Function1' */
  /* This comment workarounds a code generation problem */

  /* dSPACE RTICAN TX Message Block: "N30_RPDO1" Id:562 */
  {
    UInt32 CAN_Msg[8] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };

    Float32 delayTime = 0.0;

    /* ... Read status and timestamp info (previous message) */
    can_tp1_msg_read(can_type1_msg_M1[CANTP1_M1_C1_TX_STD_0X232]);

    /* Convert timestamp */
    if (can_type1_msg_M1[CANTP1_M1_C1_TX_STD_0X232]->processed) {
      can_type1_msg_M1[CANTP1_M1_C1_TX_STD_0X232]->timestamp =
        rtk_dsts_time_to_simtime_convert
        (can_type1_msg_M1[CANTP1_M1_C1_TX_STD_0X232]->timestamp);
    }

    /* Messages with timestamp zero have been received in pause/stop state
       and must not be handled.
     */
    if (can_type1_msg_M1[CANTP1_M1_C1_TX_STD_0X232]->timestamp > 0.0) {
      test_B.SFunction1_o1_fz = (real_T)
        can_type1_msg_M1[CANTP1_M1_C1_TX_STD_0X232]->processed;
      test_B.SFunction1_o2_i = (real_T)
        can_type1_msg_M1[CANTP1_M1_C1_TX_STD_0X232]->timestamp;
      test_B.SFunction1_o3_n = (real_T)
        can_type1_msg_M1[CANTP1_M1_C1_TX_STD_0X232]->deltatime;
      test_B.SFunction1_o4_m2 = (real_T)
        can_type1_msg_M1[CANTP1_M1_C1_TX_STD_0X232]->delaytime;
    }

    /* ... Encode Simulink signals of TX and RM blocks*/
    {
      rtican_Signal_t CAN_Sgn;

      /* ...... "Target_velocity" (0|32, standard signal, signed int, little endian) */
      /* Add or substract 0.5 in order to round to nearest integer */
      if (( test_B.Merge1_e ) < -0.5)
        CAN_Sgn.SignedSgn = (Int32) (( test_B.Merge1_e ) - 0.5);
      else
        CAN_Sgn.SignedSgn = (Int32) (( test_B.Merge1_e ) + 0.5);
      CAN_Msg[0] |= CAN_Sgn.SgnBytes.Byte0;
      CAN_Msg[1] |= CAN_Sgn.SgnBytes.Byte1;
      CAN_Msg[2] |= CAN_Sgn.SgnBytes.Byte2;
      CAN_Msg[3] |= CAN_Sgn.SgnBytes.Byte3;

      /* ...... "Target_torque" (32|16, standard signal, signed int, little endian) */
      /* Add or substract 0.5 in order to round to nearest integer */
      if (( test_B.Product_h ) < -0.5)
        CAN_Sgn.SignedSgn = (Int32) (( test_B.Product_h ) - 0.5);
      else
        CAN_Sgn.SignedSgn = (Int32) (( test_B.Product_h ) + 0.5);
      CAN_Sgn.SignedSgn &= 0x0000FFFF;
      CAN_Msg[4] |= CAN_Sgn.SgnBytes.Byte0;
      CAN_Msg[5] |= CAN_Sgn.SgnBytes.Byte1;
    }

    /* ... Write the data to the CAN microcontroller and trigger the sending of the message */
    can_tp1_msg_send(can_type1_msg_M1[CANTP1_M1_C1_TX_STD_0X232], 6, &(CAN_Msg[0]),
                     delayTime);
  }

  /* S-Function (rti_commonblock): '<S34>/S-Function1' incorporates:
   *  Constant: '<S8>/Sys_Ctrlword'
   */
  /* This comment workarounds a code generation problem */

  /* dSPACE RTICAN TX Message Block: "N30_RPDO0" Id:561 */
  {
    UInt32 CAN_Msg[8] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };

    Float32 delayTime = 0.0;

    /* ... Read status and timestamp info (previous message) */
    can_tp1_msg_read(can_type1_msg_M1[CANTP1_M1_C1_TX_STD_0X231]);

    /* Convert timestamp */
    if (can_type1_msg_M1[CANTP1_M1_C1_TX_STD_0X231]->processed) {
      can_type1_msg_M1[CANTP1_M1_C1_TX_STD_0X231]->timestamp =
        rtk_dsts_time_to_simtime_convert
        (can_type1_msg_M1[CANTP1_M1_C1_TX_STD_0X231]->timestamp);
    }

    /* Messages with timestamp zero have been received in pause/stop state
       and must not be handled.
     */
    if (can_type1_msg_M1[CANTP1_M1_C1_TX_STD_0X231]->timestamp > 0.0) {
      test_B.SFunction1_o1_a1 = (real_T)
        can_type1_msg_M1[CANTP1_M1_C1_TX_STD_0X231]->processed;
      test_B.SFunction1_o2_lw = (real_T)
        can_type1_msg_M1[CANTP1_M1_C1_TX_STD_0X231]->timestamp;
      test_B.SFunction1_o3_n1 = (real_T)
        can_type1_msg_M1[CANTP1_M1_C1_TX_STD_0X231]->deltatime;
      test_B.SFunction1_o4_k2 = (real_T)
        can_type1_msg_M1[CANTP1_M1_C1_TX_STD_0X231]->delaytime;
    }

    /* ... Encode Simulink signals of TX and RM blocks*/
    {
      rtican_Signal_t CAN_Sgn;

      /* ...... "Controlword" (0|16, standard signal, unsigned int, little endian) */
      /* Add or substract 0.5 in order to round to nearest integer */
      CAN_Sgn.UnsignedSgn = (UInt32) (( test_P.Sys_Ctrlword_Value ) + 0.5);
      CAN_Sgn.UnsignedSgn &= 0x0000FFFF;
      CAN_Msg[0] |= CAN_Sgn.SgnBytes.Byte0;
      CAN_Msg[1] |= CAN_Sgn.SgnBytes.Byte1;

      /* ...... "Modes_of_operation" (16|8, standard signal, signed int, little endian) */
      /* Add or substract 0.5 in order to round to nearest integer */
      if (( test_B.Merge ) < -0.5)
        CAN_Sgn.SignedSgn = (Int32) (( test_B.Merge ) - 0.5);
      else
        CAN_Sgn.SignedSgn = (Int32) (( test_B.Merge ) + 0.5);
      CAN_Sgn.SignedSgn &= 0x000000FF;
      CAN_Msg[2] |= CAN_Sgn.SgnBytes.Byte0;
    }

    /* ... Write the data to the CAN microcontroller and trigger the sending of the message */
    can_tp1_msg_send(can_type1_msg_M1[CANTP1_M1_C1_TX_STD_0X231], 3, &(CAN_Msg[0]),
                     delayTime);
  }

  /* SampleTimeMath: '<S59>/sample time'
   *
   * About '<S59>/sample time':
   *  y = K where K = ( w * Ts )
   */
  test_B.sampletime_l = test_P.sampletime_WtEt_k;

  /* Product: '<S59>/delta rise limit' incorporates:
   *  Constant: '<S8>/str_pos_ref_ratelimit'
   */
  test_B.deltariselimit_bb = test_P.str_pos_ref_ratelimit_Value *
    test_B.sampletime_l;

  /* Product: '<S41>/Product3' incorporates:
   *  Constant: '<S41>/Str_Target_pos'
   *  Constant: '<S8>/control_on//off'
   */
  test_B.Product3_k = test_P.control_onoff_Value * test_P.Str_Target_pos_Value;

  /* Saturate: '<S41>/Saturation' */
  current_mod = test_B.Product3_k;
  phase = test_P.Saturation_LowerSat_j;
  q = test_P.Saturation_UpperSat_b;
  if (current_mod > q) {
    test_B.Saturation_n = q;
  } else if (current_mod < phase) {
    test_B.Saturation_n = phase;
  } else {
    test_B.Saturation_n = current_mod;
  }

  /* End of Saturate: '<S41>/Saturation' */

  /* UnitDelay: '<S59>/Delay Input2' */
  test_B.Yk1_g = test_DW.DelayInput2_DSTATE_n;

  /* Sum: '<S59>/Difference Inputs1' */
  test_B.UkYk1_f = test_B.Saturation_n - test_B.Yk1_g;

  /* RelationalOperator: '<S60>/LowerRelop1' */
  test_B.LowerRelop1_o = (test_B.UkYk1_f > test_B.deltariselimit_bb);

  /* Gain: '<S41>/Gain' incorporates:
   *  Constant: '<S8>/str_pos_ref_ratelimit'
   */
  test_B.Gain_l = test_P.Gain_Gain_h * test_P.str_pos_ref_ratelimit_Value;

  /* Product: '<S59>/delta fall limit' */
  test_B.deltafalllimit_k = test_B.Gain_l * test_B.sampletime_l;

  /* RelationalOperator: '<S60>/UpperRelop' */
  test_B.UpperRelop_j = (test_B.UkYk1_f < test_B.deltafalllimit_k);

  /* Switch: '<S60>/Switch' */
  if (test_B.UpperRelop_j) {
    test_B.Switch_i = test_B.deltafalllimit_k;
  } else {
    test_B.Switch_i = test_B.UkYk1_f;
  }

  /* End of Switch: '<S60>/Switch' */

  /* Switch: '<S60>/Switch2' */
  if (test_B.LowerRelop1_o) {
    test_B.Switch2_gi = test_B.deltariselimit_bb;
  } else {
    test_B.Switch2_gi = test_B.Switch_i;
  }

  /* End of Switch: '<S60>/Switch2' */

  /* Sum: '<S59>/Difference Inputs2' */
  test_B.DifferenceInputs2_d = test_B.Switch2_gi + test_B.Yk1_g;

  /* UnitDelay: '<S58>/d1' */
  test_B.d1_ng = test_DW.d1_DSTATE_k;

  /* Sum: '<S58>/Sum3' */
  test_B.Sum3_m = test_B.DifferenceInputs2_d + test_B.d1_ng;

  /* Gain: '<S58>/gain' */
  test_B.gain_k = test_P.Ts * test_B.Sum3_m;

  /* Gain: '<S58>/gain2' incorporates:
   *  Constant: '<S8>/str_pos_ref_cutoff'
   */
  test_B.gain2_i = test_P.gain2_Gain_g * test_P.str_pos_ref_cutoff_Value;

  /* Product: '<S58>/Product2' incorporates:
   *  Constant: '<S58>/Constant1'
   */
  test_B.Product2_n = test_P.Constant1_Value_mn / test_B.gain2_i;

  /* Gain: '<S58>/gain1' */
  test_B.gain1_n = test_P.gain1_Gain_f * test_B.Product2_n;

  /* Sum: '<S58>/Sum1' incorporates:
   *  Constant: '<S58>/Constant'
   */
  test_B.Sum1_o1 = test_B.gain1_n - test_P.Ts;

  /* UnitDelay: '<S58>/d' */
  test_B.d_k = test_DW.d_DSTATE_ow;

  /* Product: '<S58>/Product11' */
  test_B.Product11_jy = test_B.Sum1_o1 * test_B.d_k;

  /* Sum: '<S58>/Sum2' */
  test_B.Sum2_me = test_B.gain_k + test_B.Product11_jy;

  /* Sum: '<S58>/Sum4' incorporates:
   *  Constant: '<S58>/Constant'
   */
  test_B.Sum4_k = test_B.gain1_n + test_P.Ts;

  /* Product: '<S58>/Product1' */
  test_B.Product1_js = test_B.Sum2_me / test_B.Sum4_k;

  /* Product: '<S41>/Product' incorporates:
   *  Constant: '<S8>/N_str'
   */
  test_B.Product_c = test_B.Product1_js * test_P.N_str_Value;

  /* Product: '<S41>/Product2' incorporates:
   *  Constant: '<S41>/Constant'
   *  Constant: '<S8>/cpt_str'
   */
  test_B.Product2_o = test_P.cpt_str_Value / test_P.Constant_Value_l;

  /* Product: '<S41>/Product1' */
  test_B.Product1_pc = test_B.Product_c * test_B.Product2_o;

  /* Rounding: '<S41>/Round' */
  test_B.Round = rt_roundd_snf(test_B.Product1_pc);

  /* DataTypeConversion: '<S41>/Data Type Conversion' */
  test_B.DataTypeConversion = test_B.Round;

  /* Saturate: '<S69>/Saturation' incorporates:
   *  Constant: '<S8>/str_PID_zeta'
   */
  current_mod = test_P.str_PID_zeta_Value;
  phase = test_P.Saturation_LowerSat_o;
  q = test_P.Saturation_UpperSat_h;
  if (current_mod > q) {
    test_B.Saturation_nv = q;
  } else if (current_mod < phase) {
    test_B.Saturation_nv = phase;
  } else {
    test_B.Saturation_nv = current_mod;
  }

  /* End of Saturate: '<S69>/Saturation' */

  /* Gain: '<S69>/gain 1' */
  test_B.gain1_h = test_P.gain1_Gain_fa * test_B.Saturation_nv;

  /* Gain: '<S69>/gain ' incorporates:
   *  Constant: '<S8>/str_PID_CutOff'
   */
  test_B.gain_km = test_P.gain_Gain_l * test_P.str_PID_CutOff_Value;

  /* Product: '<S69>/Divide6' incorporates:
   *  Constant: '<S8>/steer_Jn'
   */
  test_B.Divide6_ek = test_B.gain1_h * test_B.gain_km * test_P.steer_Jn_Value;

  /* Sum: '<S69>/Add1' incorporates:
   *  Constant: '<S8>/steer_Bn'
   */
  test_B.Add1_n = test_B.Divide6_ek - test_P.steer_Bn_Value;

  /* Product: '<S6>/Product1' incorporates:
   *  Constant: '<S8>/N_str'
   */
  test_B.Product1_pl = test_B.rpm2rad3 / test_P.N_str_Value;

  /* Sum: '<S6>/Add1' */
  test_B.Add1_j = test_B.y - test_B.Product1_pl;

  /* Product: '<S69>/Divide' incorporates:
   *  Constant: '<S8>/str_PID_OnOff'
   */
  test_B.Divide_b = test_B.Add1_j * test_P.str_PID_OnOff_Value;

  /* Product: '<S69>/Divide1' */
  test_B.Divide1_lp = test_B.Add1_n * test_B.Divide_b;

  /* Product: '<S69>/Divide3' */
  test_B.Divide3_b = test_B.gain_km * test_B.gain_km;

  /* Product: '<S69>/Divide4' incorporates:
   *  Constant: '<S8>/steer_Jn'
   */
  test_B.Divide4_j = test_B.Divide3_b * test_P.steer_Jn_Value;

  /* Sum: '<S69>/Add' */
  test_B.Add_l = test_B.gain_km + test_B.Divide4_j;

  /* RelationalOperator: '<S90>/LowerRelop1' */
  test_B.LowerRelop1_b = (test_B.Divide4_j > test_B.Add_l);

  /* RelationalOperator: '<S90>/UpperRelop' incorporates:
   *  Constant: '<S69>/Constant1'
   */
  test_B.UpperRelop_ab = (test_B.Divide4_j < test_P.Ts);

  /* Switch: '<S90>/Switch' incorporates:
   *  Constant: '<S69>/Constant1'
   */
  if (test_B.UpperRelop_ab) {
    test_B.Switch_b3 = test_P.Ts;
  } else {
    test_B.Switch_b3 = test_B.Divide4_j;
  }

  /* End of Switch: '<S90>/Switch' */

  /* Switch: '<S90>/Switch2' */
  if (test_B.LowerRelop1_b) {
    test_B.Switch2_bs = test_B.Add_l;
  } else {
    test_B.Switch2_bs = test_B.Switch_b3;
  }

  /* End of Switch: '<S90>/Switch2' */

  /* Product: '<S69>/Divide9' */
  test_B.Divide9_h = test_B.gain_km * test_B.gain_km / test_B.Switch2_bs;

  /* Product: '<S69>/Divide7' */
  test_B.Divide7_p = 0.0 * test_B.Divide9_h;

  /* Sum: '<S69>/Sum2' */
  test_B.Sum2_f = test_B.Divide_b + test_B.Divide7_p;

  /* UnitDelay: '<S89>/d1' */
  test_B.d1_f = test_DW.d1_DSTATE_j;

  /* Sum: '<S89>/Sum1' */
  test_B.Sum1_p = test_B.Sum2_f + test_B.d1_f;

  /* Gain: '<S89>/gain' */
  phase = test_P.Ts;
  phase /= 2.0;
  test_B.gain_os = phase * test_B.Sum1_p;

  /* UnitDelay: '<S89>/d' */
  test_B.d_j = test_DW.d_DSTATE_n;

  /* Sum: '<S89>/Sum2' */
  test_B.Sum2_a = test_B.gain_os + test_B.d_j;

  /* Product: '<S69>/Divide2' */
  test_B.Divide2_g = test_B.Sum2_a * test_B.Divide4_j;

  /* Sum: '<S69>/Sum1' */
  test_B.Sum1_g = test_B.Divide1_lp + test_B.Divide2_g;

  /* Product: '<S69>/Divide5' incorporates:
   *  Constant: '<S8>/str_PID_OnOff'
   */
  test_B.Divide5_p = test_B.Sum1_g * test_P.str_PID_OnOff_Value;

  /* Product: '<S70>/Divide3' incorporates:
   *  Constant: '<S70>/Constant2'
   */
  test_B.Divide3_c = test_B.Divide5_p / test_P.Constant2_Value_i;

  /* Product: '<S70>/Divide1' incorporates:
   *  Constant: '<S70>/Constant1'
   */
  test_B.Divide1_o = test_B.Divide3_c * test_P.Constant1_Value_axs;

  /* RelationalOperator: '<S91>/LowerRelop1' incorporates:
   *  Constant: '<S70>/Constant'
   */
  test_B.LowerRelop1_m = (test_B.Divide1_o > test_P.Constant_Value_a);

  /* Gain: '<S70>/Gain1' incorporates:
   *  Constant: '<S70>/Constant'
   */
  test_B.Gain1_j = test_P.Gain1_Gain_l * test_P.Constant_Value_a;

  /* RelationalOperator: '<S91>/UpperRelop' */
  test_B.UpperRelop_my = (test_B.Divide1_o < test_B.Gain1_j);

  /* Switch: '<S91>/Switch' */
  if (test_B.UpperRelop_my) {
    test_B.Switch_c = test_B.Gain1_j;
  } else {
    test_B.Switch_c = test_B.Divide1_o;
  }

  /* End of Switch: '<S91>/Switch' */

  /* Switch: '<S91>/Switch2' incorporates:
   *  Constant: '<S70>/Constant'
   */
  if (test_B.LowerRelop1_m) {
    test_B.Switch2_n = test_P.Constant_Value_a;
  } else {
    test_B.Switch2_n = test_B.Switch_c;
  }

  /* End of Switch: '<S91>/Switch2' */

  /* Product: '<S70>/Divide' incorporates:
   *  Constant: '<S70>/Constant'
   */
  test_B.Divide_bg = test_B.Switch2_n / test_P.Constant_Value_a;

  /* Gain: '<S70>/Gain' */
  test_B.Gain_j = test_P.Gain_Gain_k * test_B.Divide_bg;

  /* Sum: '<S6>/Add2' */
  test_B.Add2_f = test_B.Gain_i + test_B.Gain_j;

  /* S-Function (rti_commonblock): '<S31>/S-Function1' */
  /* This comment workarounds a code generation problem */

  /* dSPACE RTICAN TX Message Block: "N10_RPDO1" Id:530 */
  {
    UInt32 CAN_Msg[8] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };

    Float32 delayTime = 0.0;

    /* ... Read status and timestamp info (previous message) */
    can_tp1_msg_read(can_type1_msg_M1[CANTP1_M1_C1_TX_STD_0X212]);

    /* Convert timestamp */
    if (can_type1_msg_M1[CANTP1_M1_C1_TX_STD_0X212]->processed) {
      can_type1_msg_M1[CANTP1_M1_C1_TX_STD_0X212]->timestamp =
        rtk_dsts_time_to_simtime_convert
        (can_type1_msg_M1[CANTP1_M1_C1_TX_STD_0X212]->timestamp);
    }

    /* Messages with timestamp zero have been received in pause/stop state
       and must not be handled.
     */
    if (can_type1_msg_M1[CANTP1_M1_C1_TX_STD_0X212]->timestamp > 0.0) {
      test_B.SFunction1_o1_e = (real_T)
        can_type1_msg_M1[CANTP1_M1_C1_TX_STD_0X212]->processed;
      test_B.SFunction1_o2_iy = (real_T)
        can_type1_msg_M1[CANTP1_M1_C1_TX_STD_0X212]->timestamp;
      test_B.SFunction1_o3_o = (real_T)
        can_type1_msg_M1[CANTP1_M1_C1_TX_STD_0X212]->deltatime;
      test_B.SFunction1_o4_lg = (real_T)
        can_type1_msg_M1[CANTP1_M1_C1_TX_STD_0X212]->delaytime;
    }

    /* ... Encode Simulink signals of TX and RM blocks*/
    {
      rtican_Signal_t CAN_Sgn;

      /* ...... "Target_position" (0|32, standard signal, signed int, little endian) */
      /* Add or substract 0.5 in order to round to nearest integer */
      if (( test_B.DataTypeConversion ) < -0.5)
        CAN_Sgn.SignedSgn = (Int32) (( test_B.DataTypeConversion ) - 0.5);
      else
        CAN_Sgn.SignedSgn = (Int32) (( test_B.DataTypeConversion ) + 0.5);
      CAN_Msg[0] |= CAN_Sgn.SgnBytes.Byte0;
      CAN_Msg[1] |= CAN_Sgn.SgnBytes.Byte1;
      CAN_Msg[2] |= CAN_Sgn.SgnBytes.Byte2;
      CAN_Msg[3] |= CAN_Sgn.SgnBytes.Byte3;

      /* ...... "Target_torque" (32|16, standard signal, signed int, little endian) */
      /* Add or substract 0.5 in order to round to nearest integer */
      if (( test_B.Add2_f ) < -0.5)
        CAN_Sgn.SignedSgn = (Int32) (( test_B.Add2_f ) - 0.5);
      else
        CAN_Sgn.SignedSgn = (Int32) (( test_B.Add2_f ) + 0.5);
      CAN_Sgn.SignedSgn &= 0x0000FFFF;
      CAN_Msg[4] |= CAN_Sgn.SgnBytes.Byte0;
      CAN_Msg[5] |= CAN_Sgn.SgnBytes.Byte1;
    }

    /* ... Write the data to the CAN microcontroller and trigger the sending of the message */
    can_tp1_msg_send(can_type1_msg_M1[CANTP1_M1_C1_TX_STD_0X212], 6, &(CAN_Msg[0]),
                     delayTime);
  }

  /* Product: '<S89>/Divide' incorporates:
   *  Constant: '<S8>/str_PID_OnOff'
   */
  test_B.Divide_a = test_B.Sum2_a * test_P.str_PID_OnOff_Value;

  /* Sum: '<S6>/Add5' */
  test_B.Add5_l = test_B.Divide1_o + test_B.TorqueConstant;

  /* Constant: '<S6>/Constant1' */
  test_B.Constant1 = test_P.Constant1_Value_l;

  /* Product: '<S6>/Divide1' */
  test_B.Divide1_li = test_B.Add5_l / test_B.Constant1;

  /* Product: '<S84>/Divide' incorporates:
   *  Constant: '<S8>/dri_PID_OnOff'
   */
  test_B.Divide_k = test_B.Sum2_p * test_P.dri_PID_OnOff_Value;

  /* Product: '<S94>/Product' incorporates:
   *  Constant: '<S8>/cpt_str'
   *  Constant: '<S94>/Constant2'
   */
  test_B.Product_cn = test_P.Constant2_Value_il / test_P.cpt_str_Value;

  /* Product: '<S94>/Product1' */
  test_B.Product1_c = test_B.SFunction1_o2_ay * test_B.Product_cn;

  /* Product: '<S94>/Product2' incorporates:
   *  Constant: '<S8>/N_str'
   */
  test_B.Product2_j = test_B.Product1_c / test_P.N_str_Value;

  /* Product: '<S94>/Product3' incorporates:
   *  Constant: '<S8>/cpt_sus'
   *  Constant: '<S94>/Constant3'
   */
  test_B.Product3_j = test_P.Constant3_Value_o / test_P.cpt_sus_Value;

  /* Product: '<S94>/Product4' */
  test_B.Product4_e = test_B.SFunction1_o2_an * test_B.Product3_j;

  /* Product: '<S94>/Product5' incorporates:
   *  Constant: '<S8>/N_sus'
   */
  test_B.Product5_c = test_B.Product4_e / test_P.N_sus_Value;

  /* If: '<S95>/If2' incorporates:
   *  Constant: '<S95>/Constant1'
   */
  if (test_B.Merge == 9.0) {
    /* Outputs for IfAction SubSystem: '<S95>/If Action Subsystem5' incorporates:
     *  ActionPort: '<S98>/Action Port'
     */
    /* Product: '<S98>/Product' incorporates:
     *  Constant: '<S98>/Constant1'
     *  Constant: '<S98>/Constant5'
     */
    test_B.Product_i = test_P.Constant1_Value / test_P.Constant5_Value;

    /* Product: '<S98>/Product1' */
    test_B.Product1_cu = test_B.Merge1_e * test_B.Product_i;

    /* Product: '<S98>/Product2' incorporates:
     *  Constant: '<S98>/N_dri'
     */
    test_B.Merge2 = test_B.Product1_cu / test_P.N_dri_Value;

    /* End of Outputs for SubSystem: '<S95>/If Action Subsystem5' */
  } else if (test_B.Merge == 10.0) {
    /* Outputs for IfAction SubSystem: '<S95>/If Action Subsystem4' incorporates:
     *  ActionPort: '<S97>/Action Port'
     */
    test_IfActionSubsystem2(test_B.Merge1_e, &test_B.Merge2);

    /* End of Outputs for SubSystem: '<S95>/If Action Subsystem4' */
  } else {
    /* Outputs for IfAction SubSystem: '<S95>/If Action Subsystem6' incorporates:
     *  ActionPort: '<S99>/Action Port'
     */
    test_IfActionSubsystem2(test_P.Constant1_Value_e, &test_B.Merge2);

    /* End of Outputs for SubSystem: '<S95>/If Action Subsystem6' */
  }

  /* End of If: '<S95>/If2' */
  /* Product: '<S95>/Product' incorporates:
   *  Constant: '<S8>/cpt_str'
   *  Constant: '<S95>/Constant2'
   */
  test_B.Product_o = test_P.Constant2_Value_m / test_P.cpt_str_Value;

  /* Product: '<S95>/Product1' */
  test_B.Product1_fn = test_B.DataTypeConversion * test_B.Product_o;

  /* Product: '<S95>/Product2' incorporates:
   *  Constant: '<S8>/N_str'
   */
  test_B.Product2_kc = test_B.Product1_fn / test_P.N_str_Value;

  /* Product: '<S95>/Product3' incorporates:
   *  Constant: '<S8>/cpt_sus'
   *  Constant: '<S95>/Constant3'
   */
  test_B.Product3_d = test_P.Constant3_Value_b / test_P.cpt_sus_Value;

  /* Product: '<S95>/Product4' */
  test_B.Product4_ej = test_B.DataTypeConversion1 * test_B.Product3_d;

  /* Product: '<S95>/Product5' incorporates:
   *  Constant: '<S8>/N_sus'
   */
  test_B.Product5_e = test_B.Product4_ej / test_P.N_sus_Value;

  /* Sum: '<S96>/Add' incorporates:
   *  Constant: '<S8>/acc_bias'
   */
  test_B.Add_k = test_B.SFunction1_n - test_P.acc_bias_Value;

  /* Product: '<S100>/Divide2' incorporates:
   *  Constant: '<S100>/Constant'
   */
  test_B.Divide2_d = test_B.SFunction1 * test_P.Constant_Value_gq;

  /* Product: '<S100>/Divide1' incorporates:
   *  Constant: '<S100>/Ample Gain'
   *  Constant: '<S100>/V'
   */
  test_B.Divide1_h = test_P.V_Value * test_P.AmpleGain_Value;

  /* Product: '<S100>/Divide3' */
  test_B.Divide3_d = test_B.Divide2_d / test_B.Divide1_h;

  /* Product: '<S100>/Divide4' incorporates:
   *  Constant: '<S8>/Load_cell_Gain'
   */
  test_B.Divide4_p = test_B.Divide3_d * test_P.Load_cell_Gain_Value;

  /* Sum: '<S96>/Add1' incorporates:
   *  Constant: '<S8>/Grf_x_bias'
   */
  test_B.Add1_i = test_B.Divide4_p - test_P.Grf_x_bias_Value;

  /* Product: '<S101>/Divide2' incorporates:
   *  Constant: '<S101>/Constant'
   */
  test_B.Divide2_n5 = test_B.SFunction1_j * test_P.Constant_Value_i;

  /* Product: '<S101>/Divide1' incorporates:
   *  Constant: '<S101>/Ample Gain'
   *  Constant: '<S101>/V'
   */
  test_B.Divide1_g2 = test_P.V_Value_d * test_P.AmpleGain_Value_n;

  /* Product: '<S101>/Divide3' */
  test_B.Divide3_p = test_B.Divide2_n5 / test_B.Divide1_g2;

  /* Product: '<S101>/Divide5' incorporates:
   *  Constant: '<S8>/Load_cell_Gain'
   */
  test_B.Divide5_e = test_B.Divide3_p * test_P.Load_cell_Gain_Value;

  /* Sum: '<S96>/Add2' incorporates:
   *  Constant: '<S8>/Grf_y_bias'
   */
  test_B.Add2_c = test_B.Divide5_e - test_P.Grf_y_bias_Value;

  /* Constant: '<S8>/Data_Logging' */
  test_B.Data_Logging = test_P.Data_Logging_Value;

  /* Constant: '<S8>/cpt_dri' */
  test_B.cpt_dri = test_P.cpt_dri_Value;

  /* Constant: '<S8>/str_DOB_OnOff' */
  test_B.str_DOB_OnOff = test_P.str_DOB_OnOff_Value;

  /* Constant: '<S8>/str_DOB_CutOff' */
  test_B.str_DOB_CutOff = test_P.str_DOB_CutOff_Value;
}

/* Model update function */
void test_update(void)
{
  /* Update for UnitDelay: '<S14>/d' */
  test_DW.d_DSTATE = 0.0;

  /* Update for UnitDelay: '<S14>/d1' */
  test_DW.d1_DSTATE = test_B.Sum1;

  /* Update for UnitDelay: '<S16>/d1' */
  test_DW.d1_DSTATE_g = test_B.Sum1;

  /* Update for UnitDelay: '<S16>/d' */
  test_DW.d_DSTATE_o = test_B.Product1;

  /* Update for UnitDelay: '<S62>/Delay Input2' */
  test_DW.DelayInput2_DSTATE = test_B.DifferenceInputs2;

  /* Update for UnitDelay: '<S61>/d1' */
  test_DW.d1_DSTATE_n = test_B.DifferenceInputs2;

  /* Update for UnitDelay: '<S61>/d' */
  test_DW.d_DSTATE_g = test_B.Product1_lu;

  /* Update for UnitDelay: '<S56>/Delay Input2' */
  test_DW.DelayInput2_DSTATE_a = test_B.DifferenceInputs2_a;

  /* Update for UnitDelay: '<S55>/d1' */
  test_DW.d1_DSTATE_e = test_B.DifferenceInputs2_a;

  /* Update for UnitDelay: '<S55>/d' */
  test_DW.d_DSTATE_c = test_B.Product1_j;

  /* Update for Delay: '<S8>/Delay1' */
  test_DW.Delay1_DSTATE = test_B.Product;

  /* Update for UnitDelay: '<S53>/Delay Input2' */
  test_DW.DelayInput2_DSTATE_p = test_B.DifferenceInputs2_n;

  /* Update for UnitDelay: '<S51>/d1' */
  test_DW.d1_DSTATE_p = test_B.DifferenceInputs2_n;

  /* Update for UnitDelay: '<S51>/d' */
  test_DW.d_DSTATE_f = test_B.Product1_f;

  /* Update for Delay: '<S8>/Delay2' */
  test_DW.Delay2_DSTATE = test_B.Product1_a;

  /* Update for UnitDelay: '<S82>/d' */
  test_DW.d_DSTATE_cq = test_B.Divide1_ad;

  /* Update for UnitDelay: '<S82>/d1' */
  test_DW.d1_DSTATE_f = test_B.Sum1_i2;

  /* Update for UnitDelay: '<S83>/d1' */
  test_DW.d1_DSTATE_ga = test_B.Add5;

  /* Update for UnitDelay: '<S83>/d' */
  test_DW.d_DSTATE_h = test_B.Product1_p;

  /* Update for UnitDelay: '<S84>/d1' */
  test_DW.d1_DSTATE_d = test_B.Sum2_h;

  /* Update for UnitDelay: '<S84>/d' */
  test_DW.d_DSTATE_p = test_B.Divide_k;

  /* Update for Delay: '<S76>/Delay' */
  test_DW.Delay_DSTATE = test_B.Add_j;

  /* Update for UnitDelay: '<S80>/d' */
  test_DW.d_DSTATE_fu = test_B.Divide1_l;

  /* Update for UnitDelay: '<S80>/d1' */
  test_DW.d1_DSTATE_fx = test_B.Sum1_is;

  /* Update for UnitDelay: '<S81>/d1' */
  test_DW.d1_DSTATE_m = test_B.Add1_g;

  /* Update for UnitDelay: '<S81>/d' */
  test_DW.d_DSTATE_m = test_B.Product1_l5;

  /* Update for UnitDelay: '<S59>/Delay Input2' */
  test_DW.DelayInput2_DSTATE_n = test_B.DifferenceInputs2_d;

  /* Update for UnitDelay: '<S58>/d1' */
  test_DW.d1_DSTATE_k = test_B.DifferenceInputs2_d;

  /* Update for UnitDelay: '<S58>/d' */
  test_DW.d_DSTATE_ow = test_B.Product1_js;

  /* Update for UnitDelay: '<S89>/d1' */
  test_DW.d1_DSTATE_j = test_B.Sum2_f;

  /* Update for UnitDelay: '<S89>/d' */
  test_DW.d_DSTATE_n = test_B.Divide_a;

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++test_M->Timing.clockTick0)) {
    ++test_M->Timing.clockTickH0;
  }

  test_M->Timing.t[0] = test_M->Timing.clockTick0 * test_M->Timing.stepSize0 +
    test_M->Timing.clockTickH0 * test_M->Timing.stepSize0 * 4294967296.0;

  {
    /* Update absolute timer for sample time: [0.01s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.01, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    test_M->Timing.clockTick1++;
    if (!test_M->Timing.clockTick1) {
      test_M->Timing.clockTickH1++;
    }
  }
}

/* Model initialize function */
void test_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)test_M, 0,
                sizeof(RT_MODEL_test_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&test_M->solverInfo, &test_M->Timing.simTimeStep);
    rtsiSetTPtr(&test_M->solverInfo, &rtmGetTPtr(test_M));
    rtsiSetStepSizePtr(&test_M->solverInfo, &test_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&test_M->solverInfo, (&rtmGetErrorStatus(test_M)));
    rtsiSetRTModelPtr(&test_M->solverInfo, test_M);
  }

  rtsiSetSimTimeStep(&test_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&test_M->solverInfo,"FixedStepDiscrete");
  rtmSetTPtr(test_M, &test_M->Timing.tArray[0]);
  test_M->Timing.stepSize0 = 0.01;

  /* block I/O */
  (void) memset(((void *) &test_B), 0,
                sizeof(B_test_T));

  /* states (dwork) */
  (void) memset((void *)&test_DW, 0,
                sizeof(DW_test_T));

  {
    /* user code (registration function declaration) */
    /*Initialize global TRC pointers. */
    test_rti_init_trc_pointers();
  }

  /* Start for If: '<S102>/If' */
  test_DW.If_ActiveSubsystem = -1;

  /* Start for FromWorkspace: '<S39>/From Workspace' */
  {
    static real_T pTimeValues0[] = { 4.0590492605963612E-14 } ;

    static real_T pDataValues0[] = { 1.035782755240044, 0.13019151993794872,
      1.0548778365160583, 0.26026996918415751, 1.0858668083725957,
      0.38988604862150356, 1.1274443985450744, 0.51828083997134644,
      1.177686345618504, 0.64412671170758262, 1.2339650931322783,
      0.76537816412775173, 1.2928605654592691, 0.87914273670568588,
      1.3500822615427905, 0.98158722734754988, 1.4004240464805378,
      1.0679001351829045, 1.4377782920916087, 1.1323367680488143,
      1.4552406535777005, 1.1683778231154796, 1.4453395841300156,
      1.1690340041670173, 1.4004240464805431, 1.1273265130069039,
      1.3132367468838106, 1.0369638636309571, 1.1776863456184878,
      0.89321718439226583, 0.98980839135177612, 0.69396718211468245,
      0.748869824482328, 0.44085555250542841, 0.45852599615477618,
      0.14042318978684099, 0.12788502014596068, -0.19493847111874318,
      -0.22772171010366385, -0.54644973372888417, -0.58651105131397929,
      -0.889082316224844, -0.92083262466724469, -1.1926437681423814,
      -1.19881671478117, -1.4240242553070055, -1.3872523889667707,
      -1.5507018556385745, -1.455700379357697, -1.5453980948832262,
      -1.3815996183092807, -1.3914921249488947, -1.1558121245179864,
      -1.0884673587958802, -0.787710411999592, -0.65633647627721792,
      -0.30861883034004162, -0.13775907433169526, 0.22772171010368611,
      0.40345620202328109, 0.74886982448244488, 0.88847161835529953,
      1.1722869947295302, 1.2344626746031391, 1.4186191384097977,
      1.3697726341693002, 1.4281738384265719, 1.2509840198704123,
      1.177686345618479, 0.87834079817005228, 0.69326013374399176,
      0.30503511859788274, 0.054865613210687093, -0.36408476066473267,
      -0.61151895421178737, -0.98738577032891583, -1.155812124518002,
      -1.4149011782165808, -1.4377782920915374, -1.5261442826405069,
      -1.3665152327026746, -1.2685972943057309, -0.93492743087270214,
      -0.68499903942032536, -0.23675098307180525, 0.082594896695794048,
      0.5443725576568661, 0.81976863574522707, 1.1776863456184377,
      1.2967421426289536, 1.4533735152450413, 1.3428685440911681,
      1.2576136461436609, 0.91547428573555367, 0.62807072937396113,
      0.13516595360252823, -0.23675098307178982, -0.734703968658123,
      -1.0293356096196526, -1.3694851560349126, -1.4391807198676174,
      -1.5054707088585906, -1.2800210863198282, -1.0588568289927562,
      -0.586511051314125, -0.18691321048778273, 0.37086984202646028,
      0.74997831055754538, 1.177686345618469, 1.3286635550561614,
      1.4522249039620285, 1.2580432141909075, 1.0357827552401584,
      0.54004674335855418, 0.10053070563096483, -0.49503029664539017,
      -0.89941847316540879, -1.3231259455953868, -1.437778292091489,
      -1.4889349782291028, -1.1988167147811311, -0.86973999627013254,
      -0.28175003406614157, 0.21554108117423046, 0.81064404617692087,
      1.1471312411458672, 1.4316015579892569, 1.3519905718332028,
      1.1776863456184279, 0.67102845141625389, 0.1733697811305229,
      -0.49373378930857903, -0.95579213373044536, -1.3897480289275539,
      -1.4556716450784986, -1.3953184546915511, -0.95579213373041827,
      -0.47147196071595832, 0.22772171010376285, 0.75267658125167747,
      1.2576136461436522, 1.3836897690610948, 1.3568162719938555,
      0.92087994485261393, 0.414902648501887, -0.31518839312013824,
      -0.86302189801317264, -1.3651570298154858, -1.4557003793576759,
      -1.3630030779019859, -0.84822275230162525, -0.27430398601701145,
      0.484485537219845, 1.0020931340872583, 1.4076644325753227,
      1.3492174398353682, 1.0858668083725245, 0.42421827692848363,
      -0.22772171010367373, -0.96068512970551045, -1.3395818493075793,
      -1.5137716134121004, -1.1830392034670809, -0.6760017168478718,
      0.12788502014594957, 0.76865696145923246, 1.3210254210656935,
      1.3825659513249009, 1.1776863456184838, 0.509619378584437,
      -0.19151828744050023, -0.97474485376967723, -1.3665152327026242,
      -1.4940509195371137, -1.0674000856622183, -0.45260539085422774,
      0.41490264850194564, 1.0272069853858299, 1.4377782920916038,
      1.2688628832619235, 0.810644046176871, -0.041015584211126881,
      -0.77226533224888416, -1.3881168506751831, -1.4391807198676907,
      -1.1443182514527785, -0.35315179230074978, 0.4291840507853068,
      1.1776863456184803, 1.3890148309421508, 1.2241633474703162,
      0.49317617287522708, -0.30861883034005011, -1.1349336696748449,
      -1.4430468946081263, -1.353519585279864, -0.65271161775993114,
      0.16405246275899521, 1.0293356096197122, 1.3722316059762065,
      1.2928605654593059, 0.57659349214159161, -0.26378129885382495,
      -1.1348093952257554, -1.4483505728618988, -1.3082156073095106,
      -0.52736438874367764, 0.34251022640530043, 1.1776863456185624,
      1.3891163551237387, 1.1157841607874102, 0.23166386039969653,
      -0.65271161775992281, -1.387737810235822, -1.4122136545356458,
      -0.94159460122289873, 0.054865613210678128, 0.89866841894857641,
      1.4377782920915503, 1.1861164371024422, 0.48448553721978238,
      -0.57809796556625614, -1.2712084867456279, -1.4933978018498197,
      -0.89941847316550183, 0.00063571317389858617, 1.0031432322900675,
      1.383815082681729, 1.1776863456184938, 0.24969528350793502,
      -0.70929019286049255, -1.4420846460640118, -1.3395818493075733,
      -0.67504001566122385, 0.44112855696320113, 1.1977487534104885,
      1.4186191384097342, 0.750761239417685, -0.22772171010371833,
      -1.2171884794800896, -1.4483505728620525, -1.012687151539436,
      0.082274052086257363, 1.003417058333492, 1.4552406535776043,
      0.94915579146909457, -0.0091463750542371183, -1.0964661689738009,
      -1.4557003793577761, -1.09322214542873, 0.0091463750542701925,
      0.97828942874420755, 1.4552406535776079, 0.92264542876761824,
      -0.082274052086159427, -1.1709125679174339, -1.4483505728619452,
      -0.95586778969742048, 0.22772171010373748, 1.1398074595249861,
      1.4186191384096909, 0.65777542607126493, -0.441128556963233,
      -1.3874253382022863, -1.3395818493075586, -0.53912236934032642,
      0.70929019286043271, 1.3557143673408407, 1.1776863456185516,
      0.069299394497803063, -1.0031432322900375, -1.5196003843927595,
      -0.8994184731653373, 0.21859014396947191, 1.2712084867457221,
      1.2971368801610454, 0.48448553721972903, -0.80836818550107781,
      -1.4377782920916191, -1.1558059937017391, 0.054865613210712309,
      1.0973507919455234, 1.4122136545356403, 0.54407328518721021,
      -0.65271161775990993, -1.4903533300106746, -1.1157841607873353,
      -0.017347763618596933, 1.1776863456185336, 1.3319081448120604,
      0.52736438874380787, -0.82399721577629148, -1.4483505728620147,
      -1.0534714756143144, 0.26378129885388762, 1.2409158650261194,
      1.2928605654593295, 0.16013253784557754, -1.0293356096197728,
      -1.5027441788300062, -0.652711617759908, 0.6138235218960022,
      1.4430468946081112, 0.9228149046898616, -0.30861883034000726,
      -1.4093259735442574, -1.2241633474702651, -0.10874542139782474,
      1.1776863456184534, 1.3035624181998031, 0.35315179230064431,
      -1.0433095667486212, -1.4391807198677067, -0.67473631942089873,
      0.77226533224887228, 1.390194070208346, 0.81064404617697339,
      -0.64551110459008854, -1.4377782920915105, -1.0262364941764393,
      0.41490264850177394, 1.3382244236869039, 1.0674000856622352,
      -0.34926632480246078, -1.366515232702727, -1.2027706765318877,
      0.19151828744054647, 1.2716163100927329, 1.1776863456184938,
      -0.20453216467389448, -1.3210254210658261, -1.2575530865404105,
      0.12788502014594888, 1.2567288735843483, 1.1830392034670498,
      -0.22271944272960292, -1.3395818493076368, -1.2140749563800999,
      0.22772171010384165, 1.3051676511105395, 1.0858668083725471,
      -0.40284524517638037, -1.40766443257531, -1.0533700314648591,
      0.48448553721977894, 1.3756173191281034, 0.84822275230161681,
      -0.72814430378110673, -1.4557003793577414, -0.72406665993026242,
      0.86302189801333284, 1.3691874920762994, 0.41490264850180031,
      -1.1341786814550261, -1.3568162719938683, -0.18171476567685391,
      1.2576136461436467, 1.1374750059650436, -0.22772171010372344,
      -1.4637532395295874, -0.955792133730518, 0.531742271783323,
      1.4556716450785845, 0.5442310794247488, -0.95579213373045468,
      -1.4572284819286119, -0.17336978113051607, 1.1889377638356,
      1.177686345618429, -0.3849871277058235, -1.4316015579893222,
      -0.8663253428214428, 0.81064404617689567, 1.3625293640369607,
      0.28175003406603955, -1.280626072237885, -1.1988167147811954,
      0.25458668863814521, 1.4377782920915059, 0.67384921579462809,
      -0.899418473165497, -1.4572102159097016, -0.10053070563090326,
      1.2567951537577555, 1.0357827552401506, -0.66214397536376457,
      -1.4522249039620809, -0.46911622345693565, 1.1776863456184616,
      1.1375116912334364, -0.37086984202659834, -1.5162128252925446,
      -0.5865110513141335, 1.0037744305990637, 1.2800210863197903,
      -0.31320158801883241, -1.4391807198676942, -0.72401124609260747,
      1.0293356096196937, 1.2308254061005535, -0.23675098307184872,
      -1.5060254370005177, -0.62807072937389141, 1.0037837872148778,
      1.2576136461436005, -0.40277063155041032, -1.4533735152450185,
      -0.5561150905711989, 1.1776863456184452, 1.0836615950725286,
      -0.54437255765692, -1.5123212096162606, -0.23675098307185632,
      1.2568233290714976, 0.93492743087263375, -0.90032289616763428,
      -1.3665152327026466, 0.0741121056229236, 1.4377782920916096,
      0.51087302480934793, -1.155812124518004, -1.2026555538608998,
      0.61151895421193647, 1.3625766771030725, 0.054865613210758966,
      -1.4686527360028307, -0.69326013374393691, 1.0282981079035971,
      1.1776863456185247, -0.645374289899419, -1.4281738384265144,
      -0.09029803308360064, 1.4186191384097773, 0.54429807097432825,
      -1.1722869947294523, -1.1433624156108992, 0.74886982448239825,
      1.3037221699553405, -0.22772171010379169, -1.5201927028930158,
      -0.30861883034018095, 1.2788759490001409, 0.78771041199955483,
      -1.1340912351346777, -1.1558121245180675, 0.614007701848837,
      1.3815996183093282, -0.29511469811992835, -1.4557003793577274,
      -0.29059636992664156, 1.3872523889667498, 0.57734027229214047,
      -1.198816714781195, -1.0532610982231179, 0.92083262466729787,
      1.1772526192293844, -0.58651105131411518, -1.4623880475344559,
      0.22772171010373454, 1.3897819951310932, 0.12788502014604453,
      -1.4901146684241171, -0.45852599615469036, 1.2568606094400159,
      0.74886982448242179, -1.2278493075923951, -0.98980839135173271,
      0.89926488449688025, 1.1776863456184696, -0.80809878706098515,
      -1.3132367468838284, 0.44729542114839055, 1.4004240464804367,
      -0.3491101507164826, -1.4453395841299956, 0.0011729436113865619,
      1.4552406535776004, 0.069602407758901835, -1.4377782920915687,
      -0.380432433966106, 1.4004240464804758, 0.40857758912812986,
      -1.350082261542799, -0.67455370466484721, 1.2928605654593,
      0.65811543050002264, -1.2339650931322912, -0.88144074662813532,
      1.1776863456184685, 0.82529446653957439, -1.1274443985450486,
      -1.0122447546015847, 1.08586680837258, 0.92302638924031621,
      -1.0548778365160496, -1.0797841731971509, 1.0357827552401679,
      0.96261592124327677, -1.0293356096196602, -1.0928177213680061,
      1.035782755240154, 0.94958237307251736, -1.0548778365160949,
      -1.0532281893650193, 1.085866808372546, 0.88204295447695646,
      -1.1274443985450591, -0.95549626666421328, 1.1776863456184978,
      0.75123894650350476, -1.2339650931322566, -0.788317230624646,
      1.2928605654594041, 0.54435190454009208, -1.3500822615426791,
      -0.53877938925276658, 1.4004240464805278, 0.25023063384144423,
      -1.4377782920915381, -0.19980420788350894, 1.4552406535776179,
      -0.13137474373597796, -1.4453395841300476, 0.2189083505919418,
      1.4004240464804341, -0.57749722127287739, -1.3132367468838542,
      0.67789698693638678, 1.1776863456184803, -1.0294666846216265,
      -0.98980839135173526, 1.0976475074676413, 0.74886982448236639,
      -1.3870624095647619, -0.45852599615477907, 1.3599128682993886,
      0.12788502014585112, -1.519983795255746, 0.22772171010371484,
      1.3321862474098451, -0.58651105131417092, -1.3074544193539035,
      0.92083262466730031, 0.92305929809849574, -1.1988167147811595,
      -0.707542072416772, 1.3872523889667006, 0.16039456980194708,
      -1.4557003793577612, 0.16491289799534806, 1.3815996183092361,
      -0.74420950197335967, -1.1558121245181157, 1.0038894350100847,
      0.78771041199955338, -1.4090777491246156, -0.30861883034005144,
      1.3899909027684587, -0.2277217101036676, -1.4339239700800257,
      0.7488698244824, 1.0131606154862653, -1.1722869947295176,
      -0.67449987109899989, 1.418619138409752, -0.0399037670410758,
      -1.4281738384265648, 0.51517248977477759, 1.1776863456184279,
      -1.1584999080283276, -0.69326013374405726, 1.3384509358780849,
      0.054865613210692235, -1.4927784772278314, 0.61151895421183255,
      1.0724537537362147, -1.1558121245180575, -0.64107482493411072,
      1.4377782920916458, -0.20431390574770464, -1.36651523270265,
      0.7701210960429653, 0.93492743087268049, -1.3870251291961482,
      -0.23675098307184089, 1.382119409491706, -0.544372557656904,
      -1.2138633951971021, 1.1776863456184858, 0.42591329044654,
      -1.4533735152449072, 0.27256883142569083, 1.2576136461437066,
      -1.1339855873395659, -0.62807072937388875, 1.3758236368757704,
      -0.2367509830718528, -1.361027206225252, 1.0293356096197301,
      0.59380944596800334, -1.4391807198677187, 0.18299978789420587,
      1.2800210863198915, -1.1339762307236698, -0.58651105131402725,
      1.3860110251679174, -0.370869842026528, -1.2677134913580177,
      1.1776863456184294, 0.33891442333237431, -1.4522249039621558,
      0.5319421752391521, 1.0357827552401526, -1.3869969538825058,
      -0.10053070563081196, 1.327008415785019, -0.89941847316541779,
      -0.80405101591920958, 1.4377782920915869, -0.3847884887628078,
      -1.1988167147811117, 1.1504242721133169, 0.28175003406601756,
      -1.4927311641614709, 0.81064404617697638, 0.73612354269675639,
      -1.4316015579892107, 0.25478532758125305, 1.1776863456184854,
      -1.3191395639603036, -0.17336978113045745, 1.3270266818039349,
      -0.95579213373053828, -0.67443287954935727, 1.4556716450785707,
      -0.66194407190811844, -0.95579213373033323, 1.3335514394049581,
      -0.2277217101037346, -1.2676768060896195, 1.257613646143604,
      0.051512965552237368, -1.3568162719937695, 1.0039768813304011,
      0.4149026485017856, -1.4993892922009791, 0.86302189801334028,
      0.59386485980554371, -1.4557003793577477, 0.59794250365651969,
      0.84822275230168265, -1.5058191192527788, 0.4844855372199377,
      0.92316823134012027, -1.4076644325752481, 0.27264344505173266,
      1.0858668083725367, -1.4353694512352848, 0.22772171010371353,
      1.0838731562553903, -1.3395818493076328, 0.092517642605166345,
      1.1830392034669606, -1.3869306737089961, 0.12788502014600911,
      1.1273512864157602, -1.3210254210657222, 0.074330364549315908,
      1.1776863456184214, -1.4018181102174172, 0.19151828744069138,
      1.0725688764072507, -1.3665152327027343, 0.21906452467786056,
      1.0674000856623069, -1.4684262238115902, 0.41490264850191649,
      0.89603469405174252, -1.4377782920916045, 0.51530930446543832,
      0.8106440461769221, -1.5203958703330613, 0.77226533224885685,
      0.54453451929626651, -1.4391807198676698, 0.91310776662404813,
      0.35315179230078103, -1.4337642183244119, 1.1776863456185114,
      -0.021456378726847185, -1.224163347470278, 1.2791241734196717,
      -0.30861883034028342, -1.0530167048143884, 1.4430468946080341,
      -0.74402532202059068, -0.65271161775996078, 1.3725423787054358,
      -1.029335609619747, -0.29033433797008151, 1.2928605654592347,
      -1.3711176651507677, 0.26378129885381613, 0.92326967548964889,
      -1.4483505728620656, 0.69379541565160563, 0.52736438874375846,
      -1.4621099449367405, 1.1776863456185143, -0.112854036506226,
      -1.1157841607872996, 1.3601515298859117, -0.65271161775992592,
      -0.67427508531180935, 1.4122136545356974, -1.2275525920702057,
      0.054865613210736186, 1.0256041935771123, -1.43777829209165,
      0.67816638537666762, 0.48448553721962528, -1.4273386802856318,
      1.2712084867456805, -0.34879194409423425, -0.89941847316536472,
      1.3893985842680106, -1.003143232290145, -0.19950119462253013,
      1.1776863456184736, -1.4859161674655328, 0.70929019286054074,
      0.40892056921564224, -1.3395818493075489, 1.2572235380776606,
      -0.44112855696326947, -0.78797722619582544, 1.4186191384097382,
      -1.2700092596496475, 0.22772171010373671, 0.82566598957261794,
      -1.4483505728620081, 1.0407107677927065, -0.082274052086266744,
      -1.0528472288922452, 1.45524065357764, -1.1084912288689051,
      0.0091463750543167958, 0.96302034530398273, -1.455700379357745,
      0.96626436884927847, -0.0091463750543276968, -1.0793575915936617,
      1.4552406535775826, -1.1336188584580891, 0.082274052086226443,
      0.88248535141478046, -1.4483505728620867, 1.0869866793555272,
      -0.22772171010377112, -0.88096303954227606, 1.4186191384097468,
      -1.3279505535351761, 0.44112855696327719, 0.5448382155364907,
      -1.3395818493075224, 1.3118828459393999, -0.70929019286055672,
      -0.37989708363247648, 1.1776863456184044, -1.5140168828063767,
      1.003143232290137, -0.13083751329847434, -0.89941847316540169,
      1.3631960017252014, -1.27120848674571, 0.44789616544159871,
      0.48448553721974807, -1.316318237227059, 1.4377782920915738,
      -1.0288702190732404, 0.05486561321074937, 0.81139280109818979,
      -1.4122136545356749, 1.2575360101111894, -0.6527116177599992,
      -0.36186566052418156, 1.1157841607873515, -1.5193181552484447,
      1.1776863456185462, -0.47271202653016109, -0.52736438874365266,
      1.1780138071847031, -1.4483505728620631, 1.0046075951010478,
      -0.26378129885393331, -0.70679529226608551, 1.2928605654592518,
      -1.5024334061008815, 1.0293356096197015, -0.29425426288362916,
      -0.65271161775987208, 1.2233177851551775, -1.4430468946080524,
      1.004731869550199, -0.3086188303401356, -0.62337797299980258,
      1.2241633474701847, -1.5192166310667587, 1.1776863456183744,
      -0.55938585090982362, -0.35315179230085608, 1.0141164513281435,
      -1.4391807198676618, 1.2579150505505554, -0.77226533224885985,
      -0.089186215913422476, 0.81064404617691777, -1.3990646833865563,
      1.4377782920915527, -1.1574087855105366, 0.41490264850178504,
      0.32240359072949965, -1.0674000856623684, 1.3638491194125963,
      -1.3665152327029224, 0.84454305364511262, -0.19151828744066315,
      -0.63982117870918676, 1.1776863456185318, -1.5127677514495259,
      1.3210254210658088, -0.89885876158396028, 0.1278850201459926,
      0.545799916723219, -1.1830392034670683, 1.3835698132874794,
      -1.3395818493076503, 0.830483329580988, -0.22772171010383632,
      -0.55442007705301821, 1.0858668083724969, -1.4794192399600732,
      1.4076644325752956, -1.1322949342119526, 0.48448553721983212,
      0.14410218589222856, -0.84822275230166078, 1.2328012777773198,
      -1.4557003793577841, 1.234955229690764, -0.86302189801333684,
      0.18498659299551695, 0.414902648501638, -1.0510817449771506,
      1.3568162719936807, -1.5138915691857173, 1.2576136461436593,
      -0.8828783813763631, 0.22772171010373191, 0.3412701605911389,
      -0.9557921337303471, 1.265116654566788, -1.455671645078475,
      1.2595462288027981, -0.955792133730412, 0.36353198918392482,
      0.17336978113049767, -0.80123025154079164, 1.1776863456183291,
      -1.4821923719576962, 1.4316015579891641, -1.2773330412704402,
      0.81064404617693675, -0.34574288129896963, -0.281750034065993,
      0.73953819614536, -1.1988167147810709, 1.3587331781044041,
      -1.43777829209162, 1.1929241454707431, -0.8994184731655066,
      0.36482849652080546, 0.10053070563079644, -0.6702485434831269,
      1.0357827552400485, -1.3882450143155185, 1.4522249039620709,
      -1.4588653551808586, 1.17768634561858, -0.88018011068225244,
      0.37086984202668194, 0.056711410363106618, -0.58651105131402959,
      0.92865502886818641, -1.280021086319902, 1.3752689087339929,
      -1.4391807198678228, 1.2392833559104064, -1.0293356096198547,
      0.60450216853350458, -0.23675098307193798, -0.26536775372710247,
      0.62807072937388531, -1.0456760858601803, 1.2576136461436973,
      -1.4730703442159516, 1.4533735152450495, -1.4269439427535768,
      1.1776863456184183, -0.94997043586982688, 0.54437255765680381,
      -0.21279669682045491, -0.23675098307188724, 0.55479723929565394,
      -0.93492743087262375, 1.1383954941810974, -1.366515232702662,
      1.3959424825157043, -1.437778292091487, 1.2846993780919198,
      -1.1558121245181248, 0.85718397020424575, -0.61151895421185354,
      0.23388296054012553, 0.054865613210535805, -0.43523691872232451,
      0.69326013374395412, -1.0085425982945573, 1.1776863456183679,
      -1.3811858199949796, 1.4281738384264413, -1.499974434293907,
      1.4186191384097075, -1.3646644747278753, 1.1722869947295187,
      -1.0186734184800681, 0.74886982448237061, -0.53365800214801551,
      0.22772171010375114, 0.0075572742070260622, -0.30861883034006332,
      0.52613467615250908, -0.78771041199959346, 0.9582655586711365,
      -1.1558121245179875, 1.2612903248241041, -1.3815996183093255,
      1.4151962947585519, -1.4557003793577941, 1.4205000555140115,
      -1.387252388966794, 1.2938224551825153, -1.1988167147813031,
      1.062441968017799, -0.92083262466735216, 0.75888051610009921,
      -0.586511051314065, 0.41624793360425388, -0.22772171010379758,
      0.064736670994190865, 0.1278850201458468, -0.27062498991138861,
      0.45852599615470968, -0.57105735262997093, 0.74886982448235218,
      -0.8241689822393431, 0.98980839135184451, -1.0234189845169082,
      1.1776863456184556, -1.1671656637555923, 1.3132367468837751,
      -1.2575283131315891, 1.4004240464805091, -1.2992358042916305,
      1.4453395841299379, -1.2985796232401934, 1.4552406535776168,
      -1.2625385681734598, 1.4377782920915385, -1.1981019353076048,
      1.4004240464805029, -1.1117890274721534, 1.3500822615426913,
      -1.0093445368302685, 1.2928605654592793, -0.8955799642523784,
      1.2339650931322539, -0.77432851183227314, 1.1776863456184916,
      -0.64848264009609913, 1.1274443985451252, -0.52008784874624892,
      1.0858668083725425, -0.39047176930888561, 1.0548778365160858,
      -0.2603933200625505, 1.0357827552401586, -0.13020180012464427,
      1.0293356096196626, 4.0590492605963612E-14, 1.035782755240044,
      0.13019151993794872, 1.0548778365160583, 0.26026996918415751,
      1.0858668083725957, 0.38988604862150356, 1.1274443985450744,
      0.51828083997134644, 1.177686345618504, 0.64412671170758262,
      1.2339650931322783, 0.76537816412775173, 1.2928605654592691,
      0.87914273670568588, 1.3500822615427905, 0.98158722734754988,
      1.4004240464805378, 1.0679001351829045, 1.4377782920916087,
      1.1323367680488143, 1.4552406535777005, 1.1683778231154796,
      1.4453395841300156, 1.1690340041670173, 1.4004240464805431,
      1.1273265130069039, 1.3132367468838106, 1.0369638636309571,
      1.1776863456184878, 0.89321718439226583, 0.98980839135177612,
      0.69396718211468245, 0.748869824482328, 0.44085555250542841,
      0.45852599615477618, 0.14042318978684099, 0.12788502014596068,
      -0.19493847111874318, -0.22772171010366385, -0.54644973372888417,
      -0.58651105131397929, -0.889082316224844, -0.92083262466724469,
      -1.1926437681423814, -1.19881671478117, -1.4240242553070055,
      -1.3872523889667707, -1.5507018556385745, -1.455700379357697,
      -1.5453980948832262, -1.3815996183092807, -1.3914921249488947,
      -1.1558121245179864, -1.0884673587958802, -0.787710411999592,
      -0.65633647627721792, -0.30861883034004162, -0.13775907433169526,
      0.22772171010368611, 0.40345620202328109, 0.74886982448244488,
      0.88847161835529953, 1.1722869947295302, 1.2344626746031391,
      1.4186191384097977, 1.3697726341693002, 1.4281738384265719,
      1.2509840198704123, 1.177686345618479, 0.87834079817005228,
      0.69326013374399176, 0.30503511859788274, 0.054865613210687093,
      -0.36408476066473267, -0.61151895421178737, -0.98738577032891583,
      -1.155812124518002, -1.4149011782165808, -1.4377782920915374,
      -1.5261442826405069, -1.3665152327026746, -1.2685972943057309,
      -0.93492743087270214, -0.68499903942032536, -0.23675098307180525,
      0.082594896695794048, 0.5443725576568661, 0.81976863574522707,
      1.1776863456184377, 1.2967421426289536, 1.4533735152450413,
      1.3428685440911681, 1.2576136461436609, 0.91547428573555367,
      0.62807072937396113, 0.13516595360252823, -0.23675098307178982,
      -0.734703968658123, -1.0293356096196526, -1.3694851560349126,
      -1.4391807198676174, -1.5054707088585906, -1.2800210863198282,
      -1.0588568289927562, -0.586511051314125, -0.18691321048778273,
      0.37086984202646028, 0.74997831055754538, 1.177686345618469,
      1.3286635550561614, 1.4522249039620285, 1.2580432141909075,
      1.0357827552401584, 0.54004674335855418, 0.10053070563096483,
      -0.49503029664539017, -0.89941847316540879, -1.3231259455953868,
      -1.437778292091489, -1.4889349782291028, -1.1988167147811311,
      -0.86973999627013254, -0.28175003406614157, 0.21554108117423046,
      0.81064404617692087, 1.1471312411458672, 1.4316015579892569,
      1.3519905718332028, 1.1776863456184279, 0.67102845141625389,
      0.1733697811305229, -0.49373378930857903, -0.95579213373044536,
      -1.3897480289275539, -1.4556716450784986, -1.3953184546915511,
      -0.95579213373041827, -0.47147196071595832, 0.22772171010376285,
      0.75267658125167747, 1.2576136461436522, 1.3836897690610948,
      1.3568162719938555, 0.92087994485261393, 0.414902648501887,
      -0.31518839312013824, -0.86302189801317264, -1.3651570298154858,
      -1.4557003793576759, -1.3630030779019859, -0.84822275230162525,
      -0.27430398601701145, 0.484485537219845, 1.0020931340872583,
      1.4076644325753227, 1.3492174398353682, 1.0858668083725245,
      0.42421827692848363, -0.22772171010367373, -0.96068512970551045,
      -1.3395818493075793, -1.5137716134121004, -1.1830392034670809,
      -0.6760017168478718, 0.12788502014594957, 0.76865696145923246,
      1.3210254210656935, 1.3825659513249009, 1.1776863456184838,
      0.509619378584437, -0.19151828744050023, -0.97474485376967723,
      -1.3665152327026242, -1.4940509195371137, -1.0674000856622183,
      -0.45260539085422774, 0.41490264850194564, 1.0272069853858299,
      1.4377782920916038, 1.2688628832619235, 0.810644046176871,
      -0.041015584211126881, -0.77226533224888416, -1.3881168506751831,
      -1.4391807198676907, -1.1443182514527785, -0.35315179230074978,
      0.4291840507853068, 1.1776863456184803, 1.3890148309421508,
      1.2241633474703162, 0.49317617287522708, -0.30861883034005011,
      -1.1349336696748449, -1.4430468946081263, -1.353519585279864,
      -0.65271161775993114, 0.16405246275899521, 1.0293356096197122,
      1.3722316059762065, 1.2928605654593059, 0.57659349214159161,
      -0.26378129885382495, -1.1348093952257554, -1.4483505728618988,
      -1.3082156073095106, -0.52736438874367764, 0.34251022640530043,
      1.1776863456185624, 1.3891163551237387, 1.1157841607874102,
      0.23166386039969653, -0.65271161775992281, -1.387737810235822,
      -1.4122136545356458, -0.94159460122289873, 0.054865613210678128,
      0.89866841894857641, 1.4377782920915503, 1.1861164371024422,
      0.48448553721978238, -0.57809796556625614, -1.2712084867456279,
      -1.4933978018498197, -0.89941847316550183, 0.00063571317389858617,
      1.0031432322900675, 1.383815082681729, 1.1776863456184938,
      0.24969528350793502, -0.70929019286049255, -1.4420846460640118,
      -1.3395818493075733, -0.67504001566122385, 0.44112855696320113,
      1.1977487534104885, 1.4186191384097342, 0.750761239417685,
      -0.22772171010371833, -1.2171884794800896, -1.4483505728620525,
      -1.012687151539436, 0.082274052086257363, 1.003417058333492,
      1.4552406535776043, 0.94915579146909457, -0.0091463750542371183,
      -1.0964661689738009, -1.4557003793577761, -1.09322214542873,
      0.0091463750542701925, 0.97828942874420755, 1.4552406535776079,
      0.92264542876761824, -0.082274052086159427, -1.1709125679174339,
      -1.4483505728619452, -0.95586778969742048, 0.22772171010373748,
      1.1398074595249861, 1.4186191384096909, 0.65777542607126493,
      -0.441128556963233, -1.3874253382022863, -1.3395818493075586,
      -0.53912236934032642, 0.70929019286043271, 1.3557143673408407,
      1.1776863456185516, 0.069299394497803063, -1.0031432322900375,
      -1.5196003843927595, -0.8994184731653373, 0.21859014396947191,
      1.2712084867457221, 1.2971368801610454, 0.48448553721972903,
      -0.80836818550107781, -1.4377782920916191, -1.1558059937017391,
      0.054865613210712309, 1.0973507919455234, 1.4122136545356403,
      0.54407328518721021, -0.65271161775990993, -1.4903533300106746,
      -1.1157841607873353, -0.017347763618596933, 1.1776863456185336,
      1.3319081448120604, 0.52736438874380787, -0.82399721577629148,
      -1.4483505728620147, -1.0534714756143144, 0.26378129885388762,
      1.2409158650261194, 1.2928605654593295, 0.16013253784557754,
      -1.0293356096197728, -1.5027441788300062, -0.652711617759908,
      0.6138235218960022, 1.4430468946081112, 0.9228149046898616,
      -0.30861883034000726, -1.4093259735442574, -1.2241633474702651,
      -0.10874542139782474, 1.1776863456184534, 1.3035624181998031,
      0.35315179230064431, -1.0433095667486212, -1.4391807198677067,
      -0.67473631942089873, 0.77226533224887228, 1.390194070208346,
      0.81064404617697339, -0.64551110459008854, -1.4377782920915105,
      -1.0262364941764393, 0.41490264850177394, 1.3382244236869039,
      1.0674000856622352, -0.34926632480246078, -1.366515232702727,
      -1.2027706765318877, 0.19151828744054647, 1.2716163100927329,
      1.1776863456184938, -0.20453216467389448, -1.3210254210658261,
      -1.2575530865404105, 0.12788502014594888, 1.2567288735843483,
      1.1830392034670498, -0.22271944272960292, -1.3395818493076368,
      -1.2140749563800999, 0.22772171010384165, 1.3051676511105395,
      1.0858668083725471, -0.40284524517638037, -1.40766443257531,
      -1.0533700314648591, 0.48448553721977894, 1.3756173191281034,
      0.84822275230161681, -0.72814430378110673, -1.4557003793577414,
      -0.72406665993026242, 0.86302189801333284, 1.3691874920762994,
      0.41490264850180031, -1.1341786814550261, -1.3568162719938683,
      -0.18171476567685391, 1.2576136461436467, 1.1374750059650436,
      -0.22772171010372344, -1.4637532395295874, -0.955792133730518,
      0.531742271783323, 1.4556716450785845, 0.5442310794247488,
      -0.95579213373045468, -1.4572284819286119, -0.17336978113051607,
      1.1889377638356, 1.177686345618429, -0.3849871277058235,
      -1.4316015579893222, -0.8663253428214428, 0.81064404617689567,
      1.3625293640369607, 0.28175003406603955, -1.280626072237885,
      -1.1988167147811954, 0.25458668863814521, 1.4377782920915059,
      0.67384921579462809, -0.899418473165497, -1.4572102159097016,
      -0.10053070563090326, 1.2567951537577555, 1.0357827552401506,
      -0.66214397536376457, -1.4522249039620809, -0.46911622345693565,
      1.1776863456184616, 1.1375116912334364, -0.37086984202659834,
      -1.5162128252925446, -0.5865110513141335, 1.0037744305990637,
      1.2800210863197903, -0.31320158801883241, -1.4391807198676942,
      -0.72401124609260747, 1.0293356096196937, 1.2308254061005535,
      -0.23675098307184872, -1.5060254370005177, -0.62807072937389141,
      1.0037837872148778, 1.2576136461436005, -0.40277063155041032,
      -1.4533735152450185, -0.5561150905711989, 1.1776863456184452,
      1.0836615950725286, -0.54437255765692, -1.5123212096162606,
      -0.23675098307185632, 1.2568233290714976, 0.93492743087263375,
      -0.90032289616763428, -1.3665152327026466, 0.0741121056229236,
      1.4377782920916096, 0.51087302480934793, -1.155812124518004,
      -1.2026555538608998, 0.61151895421193647, 1.3625766771030725,
      0.054865613210758966, -1.4686527360028307, -0.69326013374393691,
      1.0282981079035971, 1.1776863456185247, -0.645374289899419,
      -1.4281738384265144, -0.09029803308360064, 1.4186191384097773,
      0.54429807097432825, -1.1722869947294523, -1.1433624156108992,
      0.74886982448239825, 1.3037221699553405, -0.22772171010379169,
      -1.5201927028930158, -0.30861883034018095, 1.2788759490001409,
      0.78771041199955483, -1.1340912351346777, -1.1558121245180675,
      0.614007701848837, 1.3815996183093282, -0.29511469811992835,
      -1.4557003793577274, -0.29059636992664156, 1.3872523889667498,
      0.57734027229214047, -1.198816714781195, -1.0532610982231179,
      0.92083262466729787, 1.1772526192293844, -0.58651105131411518,
      -1.4623880475344559, 0.22772171010373454, 1.3897819951310932,
      0.12788502014604453, -1.4901146684241171, -0.45852599615469036,
      1.2568606094400159, 0.74886982448242179, -1.2278493075923951,
      -0.98980839135173271, 0.89926488449688025, 1.1776863456184696,
      -0.80809878706098515, -1.3132367468838284, 0.44729542114839055,
      1.4004240464804367, -0.3491101507164826, -1.4453395841299956,
      0.0011729436113865619, 1.4552406535776004, 0.069602407758901835,
      -1.4377782920915687, -0.380432433966106, 1.4004240464804758,
      0.40857758912812986, -1.350082261542799, -0.67455370466484721,
      1.2928605654593, 0.65811543050002264, -1.2339650931322912,
      -0.88144074662813532, 1.1776863456184685, 0.82529446653957439,
      -1.1274443985450486, -1.0122447546015847, 1.08586680837258,
      0.92302638924031621, -1.0548778365160496, -1.0797841731971509,
      1.0357827552401679, 0.96261592124327677, -1.0293356096196602,
      -1.0928177213680061, 1.035782755240154, 0.94958237307251736,
      -1.0548778365160949, -1.0532281893650193, 1.085866808372546,
      0.88204295447695646, -1.1274443985450591, -0.95549626666421328,
      1.1776863456184978, 0.75123894650350476, -1.2339650931322566,
      -0.788317230624646, 1.2928605654594041, 0.54435190454009208,
      -1.3500822615426791, -0.53877938925276658, 1.4004240464805278,
      0.25023063384144423, -1.4377782920915381, -0.19980420788350894,
      1.4552406535776179, -0.13137474373597796, -1.4453395841300476,
      0.2189083505919418, 1.4004240464804341, -0.57749722127287739,
      -1.3132367468838542, 0.67789698693638678, 1.1776863456184803,
      -1.0294666846216265, -0.98980839135173526, 1.0976475074676413,
      0.74886982448236639, -1.3870624095647619, -0.45852599615477907,
      1.3599128682993886, 0.12788502014585112, -1.519983795255746,
      0.22772171010371484, 1.3321862474098451, -0.58651105131417092,
      -1.3074544193539035, 0.92083262466730031, 0.92305929809849574,
      -1.1988167147811595, -0.707542072416772, 1.3872523889667006,
      0.16039456980194708, -1.4557003793577612, 0.16491289799534806,
      1.3815996183092361, -0.74420950197335967, -1.1558121245181157,
      1.0038894350100847, 0.78771041199955338, -1.4090777491246156,
      -0.30861883034005144, 1.3899909027684587, -0.2277217101036676,
      -1.4339239700800257, 0.7488698244824, 1.0131606154862653,
      -1.1722869947295176, -0.67449987109899989, 1.418619138409752,
      -0.0399037670410758, -1.4281738384265648, 0.51517248977477759,
      1.1776863456184279, -1.1584999080283276, -0.69326013374405726,
      1.3384509358780849, 0.054865613210692235, -1.4927784772278314,
      0.61151895421183255, 1.0724537537362147, -1.1558121245180575,
      -0.64107482493411072, 1.4377782920916458, -0.20431390574770464,
      -1.36651523270265, 0.7701210960429653, 0.93492743087268049,
      -1.3870251291961482, -0.23675098307184089, 1.382119409491706,
      -0.544372557656904, -1.2138633951971021, 1.1776863456184858,
      0.42591329044654, -1.4533735152449072, 0.27256883142569083,
      1.2576136461437066, -1.1339855873395659, -0.62807072937388875,
      1.3758236368757704, -0.2367509830718528, -1.361027206225252,
      1.0293356096197301, 0.59380944596800334, -1.4391807198677187,
      0.18299978789420587, 1.2800210863198915, -1.1339762307236698,
      -0.58651105131402725, 1.3860110251679174, -0.370869842026528,
      -1.2677134913580177, 1.1776863456184294, 0.33891442333237431,
      -1.4522249039621558, 0.5319421752391521, 1.0357827552401526,
      -1.3869969538825058, -0.10053070563081196, 1.327008415785019,
      -0.89941847316541779, -0.80405101591920958, 1.4377782920915869,
      -0.3847884887628078, -1.1988167147811117, 1.1504242721133169,
      0.28175003406601756, -1.4927311641614709, 0.81064404617697638,
      0.73612354269675639, -1.4316015579892107, 0.25478532758125305,
      1.1776863456184854, -1.3191395639603036, -0.17336978113045745,
      1.3270266818039349, -0.95579213373053828, -0.67443287954935727,
      1.4556716450785707, -0.66194407190811844, -0.95579213373033323,
      1.3335514394049581, -0.2277217101037346, -1.2676768060896195,
      1.257613646143604, 0.051512965552237368, -1.3568162719937695,
      1.0039768813304011, 0.4149026485017856, -1.4993892922009791,
      0.86302189801334028, 0.59386485980554371, -1.4557003793577477,
      0.59794250365651969, 0.84822275230168265, -1.5058191192527788,
      0.4844855372199377, 0.92316823134012027, -1.4076644325752481,
      0.27264344505173266, 1.0858668083725367, -1.4353694512352848,
      0.22772171010371353, 1.0838731562553903, -1.3395818493076328,
      0.092517642605166345, 1.1830392034669606, -1.3869306737089961,
      0.12788502014600911, 1.1273512864157602, -1.3210254210657222,
      0.074330364549315908, 1.1776863456184214, -1.4018181102174172,
      0.19151828744069138, 1.0725688764072507, -1.3665152327027343,
      0.21906452467786056, 1.0674000856623069, -1.4684262238115902,
      0.41490264850191649, 0.89603469405174252, -1.4377782920916045,
      0.51530930446543832, 0.8106440461769221, -1.5203958703330613,
      0.77226533224885685, 0.54453451929626651, -1.4391807198676698,
      0.91310776662404813, 0.35315179230078103, -1.4337642183244119,
      1.1776863456185114, -0.021456378726847185, -1.224163347470278,
      1.2791241734196717, -0.30861883034028342, -1.0530167048143884,
      1.4430468946080341, -0.74402532202059068, -0.65271161775996078,
      1.3725423787054358, -1.029335609619747, -0.29033433797008151,
      1.2928605654592347, -1.3711176651507677, 0.26378129885381613,
      0.92326967548964889, -1.4483505728620656, 0.69379541565160563,
      0.52736438874375846, -1.4621099449367405, 1.1776863456185143,
      -0.112854036506226, -1.1157841607872996, 1.3601515298859117,
      -0.65271161775992592, -0.67427508531180935, 1.4122136545356974,
      -1.2275525920702057, 0.054865613210736186, 1.0256041935771123,
      -1.43777829209165, 0.67816638537666762, 0.48448553721962528,
      -1.4273386802856318, 1.2712084867456805, -0.34879194409423425,
      -0.89941847316536472, 1.3893985842680106, -1.003143232290145,
      -0.19950119462253013, 1.1776863456184736, -1.4859161674655328,
      0.70929019286054074, 0.40892056921564224, -1.3395818493075489,
      1.2572235380776606, -0.44112855696326947, -0.78797722619582544,
      1.4186191384097382, -1.2700092596496475, 0.22772171010373671,
      0.82566598957261794, -1.4483505728620081, 1.0407107677927065,
      -0.082274052086266744, -1.0528472288922452, 1.45524065357764,
      -1.1084912288689051, 0.0091463750543167958, 0.96302034530398273,
      -1.455700379357745, 0.96626436884927847, -0.0091463750543276968,
      -1.0793575915936617, 1.4552406535775826, -1.1336188584580891,
      0.082274052086226443, 0.88248535141478046, -1.4483505728620867,
      1.0869866793555272, -0.22772171010377112, -0.88096303954227606,
      1.4186191384097468, -1.3279505535351761, 0.44112855696327719,
      0.5448382155364907, -1.3395818493075224, 1.3118828459393999,
      -0.70929019286055672, -0.37989708363247648, 1.1776863456184044,
      -1.5140168828063767, 1.003143232290137, -0.13083751329847434,
      -0.89941847316540169, 1.3631960017252014, -1.27120848674571,
      0.44789616544159871, 0.48448553721974807, -1.316318237227059,
      1.4377782920915738, -1.0288702190732404, 0.05486561321074937,
      0.81139280109818979, -1.4122136545356749, 1.2575360101111894,
      -0.6527116177599992, -0.36186566052418156, 1.1157841607873515,
      -1.5193181552484447, 1.1776863456185462, -0.47271202653016109,
      -0.52736438874365266, 1.1780138071847031, -1.4483505728620631,
      1.0046075951010478, -0.26378129885393331, -0.70679529226608551,
      1.2928605654592518, -1.5024334061008815, 1.0293356096197015,
      -0.29425426288362916, -0.65271161775987208, 1.2233177851551775,
      -1.4430468946080524, 1.004731869550199, -0.3086188303401356,
      -0.62337797299980258, 1.2241633474701847, -1.5192166310667587,
      1.1776863456183744, -0.55938585090982362, -0.35315179230085608,
      1.0141164513281435, -1.4391807198676618, 1.2579150505505554,
      -0.77226533224885985, -0.089186215913422476, 0.81064404617691777,
      -1.3990646833865563, 1.4377782920915527, -1.1574087855105366,
      0.41490264850178504, 0.32240359072949965, -1.0674000856623684,
      1.3638491194125963, -1.3665152327029224, 0.84454305364511262,
      -0.19151828744066315, -0.63982117870918676, 1.1776863456185318,
      -1.5127677514495259, 1.3210254210658088, -0.89885876158396028,
      0.1278850201459926, 0.545799916723219, -1.1830392034670683,
      1.3835698132874794, -1.3395818493076503, 0.830483329580988,
      -0.22772171010383632, -0.55442007705301821, 1.0858668083724969,
      -1.4794192399600732, 1.4076644325752956, -1.1322949342119526,
      0.48448553721983212, 0.14410218589222856, -0.84822275230166078,
      1.2328012777773198, -1.4557003793577841, 1.234955229690764,
      -0.86302189801333684, 0.18498659299551695, 0.414902648501638,
      -1.0510817449771506, 1.3568162719936807, -1.5138915691857173,
      1.2576136461436593, -0.8828783813763631, 0.22772171010373191,
      0.3412701605911389, -0.9557921337303471, 1.265116654566788,
      -1.455671645078475, 1.2595462288027981, -0.955792133730412,
      0.36353198918392482, 0.17336978113049767, -0.80123025154079164,
      1.1776863456183291, -1.4821923719576962, 1.4316015579891641,
      -1.2773330412704402, 0.81064404617693675, -0.34574288129896963,
      -0.281750034065993, 0.73953819614536, -1.1988167147810709,
      1.3587331781044041, -1.43777829209162, 1.1929241454707431,
      -0.8994184731655066, 0.36482849652080546, 0.10053070563079644,
      -0.6702485434831269, 1.0357827552400485, -1.3882450143155185,
      1.4522249039620709, -1.4588653551808586, 1.17768634561858,
      -0.88018011068225244, 0.37086984202668194, 0.056711410363106618,
      -0.58651105131402959, 0.92865502886818641, -1.280021086319902,
      1.3752689087339929, -1.4391807198678228, 1.2392833559104064,
      -1.0293356096198547, 0.60450216853350458, -0.23675098307193798,
      -0.26536775372710247, 0.62807072937388531, -1.0456760858601803,
      1.2576136461436973, -1.4730703442159516, 1.4533735152450495,
      -1.4269439427535768, 1.1776863456184183, -0.94997043586982688,
      0.54437255765680381, -0.21279669682045491, -0.23675098307188724,
      0.55479723929565394, -0.93492743087262375, 1.1383954941810974,
      -1.366515232702662, 1.3959424825157043, -1.437778292091487,
      1.2846993780919198, -1.1558121245181248, 0.85718397020424575,
      -0.61151895421185354, 0.23388296054012553, 0.054865613210535805,
      -0.43523691872232451, 0.69326013374395412, -1.0085425982945573,
      1.1776863456183679, -1.3811858199949796, 1.4281738384264413,
      -1.499974434293907, 1.4186191384097075, -1.3646644747278753,
      1.1722869947295187, -1.0186734184800681, 0.74886982448237061,
      -0.53365800214801551, 0.22772171010375114, 0.0075572742070260622,
      -0.30861883034006332, 0.52613467615250908, -0.78771041199959346,
      0.9582655586711365, -1.1558121245179875, 1.2612903248241041,
      -1.3815996183093255, 1.4151962947585519, -1.4557003793577941,
      1.4205000555140115, -1.387252388966794, 1.2938224551825153,
      -1.1988167147813031, 1.062441968017799, -0.92083262466735216,
      0.75888051610009921, -0.586511051314065, 0.41624793360425388,
      -0.22772171010379758, 0.064736670994190865, 0.1278850201458468,
      -0.27062498991138861, 0.45852599615470968, -0.57105735262997093,
      0.74886982448235218, -0.8241689822393431, 0.98980839135184451,
      -1.0234189845169082, 1.1776863456184556, -1.1671656637555923,
      1.3132367468837751, -1.2575283131315891, 1.4004240464805091,
      -1.2992358042916305, 1.4453395841299379, -1.2985796232401934,
      1.4552406535776168, -1.2625385681734598, 1.4377782920915385,
      -1.1981019353076048, 1.4004240464805029, -1.1117890274721534,
      1.3500822615426913, -1.0093445368302685, 1.2928605654592793,
      -0.8955799642523784, 1.2339650931322539, -0.77432851183227314,
      1.1776863456184916, -0.64848264009609913, 1.1274443985451252,
      -0.52008784874624892, 1.0858668083725425, -0.39047176930888561,
      1.0548778365160858, -0.2603933200625505, 1.0357827552401586,
      -0.13020180012464427, 1.0293356096196626, 4.0590492605963612E-14,
      1.035782755240044, 0.13019151993794872, 1.0548778365160583,
      0.26026996918415751, 1.0858668083725957, 0.38988604862150356,
      1.1274443985450744, 0.51828083997134644, 1.177686345618504,
      0.64412671170758262, 1.2339650931322783, 0.76537816412775173,
      1.2928605654592691, 0.87914273670568588, 1.3500822615427905,
      0.98158722734754988, 1.4004240464805378, 1.0679001351829045,
      1.4377782920916087, 1.1323367680488143, 1.4552406535777005,
      1.1683778231154796, 1.4453395841300156, 1.1690340041670173,
      1.4004240464805431, 1.1273265130069039, 1.3132367468838106,
      1.0369638636309571, 1.1776863456184878, 0.89321718439226583,
      0.98980839135177612, 0.69396718211468245, 0.748869824482328,
      0.44085555250542841, 0.45852599615477618, 0.14042318978684099,
      0.12788502014596068, -0.19493847111874318, -0.22772171010366385,
      -0.54644973372888417, -0.58651105131397929, -0.889082316224844,
      -0.92083262466724469, -1.1926437681423814, -1.19881671478117,
      -1.4240242553070055, -1.3872523889667707, -1.5507018556385745,
      -1.455700379357697, -1.5453980948832262, -1.3815996183092807,
      -1.3914921249488947, -1.1558121245179864, -1.0884673587958802,
      -0.787710411999592, -0.65633647627721792, -0.30861883034004162,
      -0.13775907433169526, 0.22772171010368611, 0.40345620202328109,
      0.74886982448244488, 0.88847161835529953, 1.1722869947295302,
      1.2344626746031391, 1.4186191384097977, 1.3697726341693002,
      1.4281738384265719, 1.2509840198704123, 1.177686345618479,
      0.87834079817005228, 0.69326013374399176, 0.30503511859788274,
      0.054865613210687093, -0.36408476066473267, -0.61151895421178737,
      -0.98738577032891583, -1.155812124518002, -1.4149011782165808,
      -1.4377782920915374, -1.5261442826405069, -1.3665152327026746,
      -1.2685972943057309, -0.93492743087270214, -0.68499903942032536,
      -0.23675098307180525, 0.082594896695794048, 0.5443725576568661,
      0.81976863574522707, 1.1776863456184377, 1.2967421426289536,
      1.4533735152450413, 1.3428685440911681, 1.2576136461436609,
      0.91547428573555367, 0.62807072937396113, 0.13516595360252823,
      -0.23675098307178982, -0.734703968658123, -1.0293356096196526,
      -1.3694851560349126, -1.4391807198676174, -1.5054707088585906,
      -1.2800210863198282, -1.0588568289927562, -0.586511051314125,
      -0.18691321048778273, 0.37086984202646028, 0.74997831055754538,
      1.177686345618469, 1.3286635550561614, 1.4522249039620285,
      1.2580432141909075, 1.0357827552401584, 0.54004674335855418,
      0.10053070563096483, -0.49503029664539017, -0.89941847316540879,
      -1.3231259455953868, -1.437778292091489, -1.4889349782291028,
      -1.1988167147811311, -0.86973999627013254, -0.28175003406614157,
      0.21554108117423046, 0.81064404617692087, 1.1471312411458672,
      1.4316015579892569, 1.3519905718332028, 1.1776863456184279,
      0.67102845141625389, 0.1733697811305229, -0.49373378930857903,
      -0.95579213373044536, -1.3897480289275539, -1.4556716450784986,
      -1.3953184546915511, -0.95579213373041827, -0.47147196071595832,
      0.22772171010376285, 0.75267658125167747, 1.2576136461436522,
      1.3836897690610948, 1.3568162719938555, 0.92087994485261393,
      0.414902648501887, -0.31518839312013824, -0.86302189801317264,
      -1.3651570298154858, -1.4557003793576759, -1.3630030779019859,
      -0.84822275230162525, -0.27430398601701145, 0.484485537219845,
      1.0020931340872583, 1.4076644325753227, 1.3492174398353682,
      1.0858668083725245, 0.42421827692848363, -0.22772171010367373,
      -0.96068512970551045, -1.3395818493075793, -1.5137716134121004,
      -1.1830392034670809, -0.6760017168478718, 0.12788502014594957,
      0.76865696145923246, 1.3210254210656935, 1.3825659513249009,
      1.1776863456184838, 0.509619378584437, -0.19151828744050023,
      -0.97474485376967723, -1.3665152327026242, -1.4940509195371137,
      -1.0674000856622183, -0.45260539085422774, 0.41490264850194564,
      1.0272069853858299, 1.4377782920916038, 1.2688628832619235,
      0.810644046176871, -0.041015584211126881, -0.77226533224888416,
      -1.3881168506751831, -1.4391807198676907, -1.1443182514527785,
      -0.35315179230074978, 0.4291840507853068, 1.1776863456184803,
      1.3890148309421508, 1.2241633474703162, 0.49317617287522708,
      -0.30861883034005011, -1.1349336696748449, -1.4430468946081263,
      -1.353519585279864, -0.65271161775993114, 0.16405246275899521,
      1.0293356096197122, 1.3722316059762065, 1.2928605654593059,
      0.57659349214159161, -0.26378129885382495, -1.1348093952257554,
      -1.4483505728618988, -1.3082156073095106, -0.52736438874367764,
      0.34251022640530043, 1.1776863456185624, 1.3891163551237387,
      1.1157841607874102, 0.23166386039969653, -0.65271161775992281,
      -1.387737810235822, -1.4122136545356458, -0.94159460122289873,
      0.054865613210678128, 0.89866841894857641, 1.4377782920915503,
      1.1861164371024422, 0.48448553721978238, -0.57809796556625614,
      -1.2712084867456279, -1.4933978018498197, -0.89941847316550183,
      0.00063571317389858617, 1.0031432322900675, 1.383815082681729,
      1.1776863456184938, 0.24969528350793502, -0.70929019286049255,
      -1.4420846460640118, -1.3395818493075733, -0.67504001566122385,
      0.44112855696320113, 1.1977487534104885, 1.4186191384097342,
      0.750761239417685, -0.22772171010371833, -1.2171884794800896,
      -1.4483505728620525, -1.012687151539436, 0.082274052086257363,
      1.003417058333492, 1.4552406535776043, 0.94915579146909457,
      -0.0091463750542371183, -1.0964661689738009, -1.4557003793577761,
      -1.09322214542873, 0.0091463750542701925, 0.97828942874420755,
      1.4552406535776079, 0.92264542876761824, -0.082274052086159427,
      -1.1709125679174339, -1.4483505728619452, -0.95586778969742048,
      0.22772171010373748, 1.1398074595249861, 1.4186191384096909,
      0.65777542607126493, -0.441128556963233, -1.3874253382022863,
      -1.3395818493075586, -0.53912236934032642, 0.70929019286043271,
      1.3557143673408407, 1.1776863456185516, 0.069299394497803063,
      -1.0031432322900375, -1.5196003843927595, -0.8994184731653373,
      0.21859014396947191, 1.2712084867457221, 1.2971368801610454,
      0.48448553721972903, -0.80836818550107781, -1.4377782920916191,
      -1.1558059937017391, 0.054865613210712309, 1.0973507919455234,
      1.4122136545356403, 0.54407328518721021, -0.65271161775990993,
      -1.4903533300106746, -1.1157841607873353, -0.017347763618596933,
      1.1776863456185336, 1.3319081448120604, 0.52736438874380787,
      -0.82399721577629148, -1.4483505728620147, -1.0534714756143144,
      0.26378129885388762, 1.2409158650261194, 1.2928605654593295,
      0.16013253784557754, -1.0293356096197728, -1.5027441788300062,
      -0.652711617759908, 0.6138235218960022, 1.4430468946081112,
      0.9228149046898616, -0.30861883034000726, -1.4093259735442574,
      -1.2241633474702651, -0.10874542139782474, 1.1776863456184534,
      1.3035624181998031, 0.35315179230064431, -1.0433095667486212,
      -1.4391807198677067, -0.67473631942089873, 0.77226533224887228,
      1.390194070208346, 0.81064404617697339, -0.64551110459008854,
      -1.4377782920915105, -1.0262364941764393, 0.41490264850177394,
      1.3382244236869039, 1.0674000856622352, -0.34926632480246078,
      -1.366515232702727, -1.2027706765318877, 0.19151828744054647,
      1.2716163100927329, 1.1776863456184938, -0.20453216467389448,
      -1.3210254210658261, -1.2575530865404105, 0.12788502014594888,
      1.2567288735843483, 1.1830392034670498, -0.22271944272960292,
      -1.3395818493076368, -1.2140749563800999, 0.22772171010384165,
      1.3051676511105395, 1.0858668083725471, -0.40284524517638037,
      -1.40766443257531, -1.0533700314648591, 0.48448553721977894,
      1.3756173191281034, 0.84822275230161681, -0.72814430378110673,
      -1.4557003793577414, -0.72406665993026242, 0.86302189801333284,
      1.3691874920762994, 0.41490264850180031, -1.1341786814550261,
      -1.3568162719938683, -0.18171476567685391, 1.2576136461436467,
      1.1374750059650436, -0.22772171010372344, -1.4637532395295874,
      -0.955792133730518, 0.531742271783323, 1.4556716450785845,
      0.5442310794247488, -0.95579213373045468, -1.4572284819286119,
      -0.17336978113051607, 1.1889377638356, 1.177686345618429,
      -0.3849871277058235, -1.4316015579893222, -0.8663253428214428,
      0.81064404617689567, 1.3625293640369607, 0.28175003406603955,
      -1.280626072237885, -1.1988167147811954, 0.25458668863814521,
      1.4377782920915059, 0.67384921579462809, -0.899418473165497,
      -1.4572102159097016, -0.10053070563090326, 1.2567951537577555,
      1.0357827552401506, -0.66214397536376457, -1.4522249039620809,
      -0.46911622345693565, 1.1776863456184616, 1.1375116912334364,
      -0.37086984202659834, -1.5162128252925446, -0.5865110513141335,
      1.0037744305990637, 1.2800210863197903, -0.31320158801883241,
      -1.4391807198676942, -0.72401124609260747, 1.0293356096196937,
      1.2308254061005535, -0.23675098307184872, -1.5060254370005177,
      -0.62807072937389141, 1.0037837872148778, 1.2576136461436005,
      -0.40277063155041032, -1.4533735152450185, -0.5561150905711989,
      1.1776863456184452, 1.0836615950725286, -0.54437255765692,
      -1.5123212096162606, -0.23675098307185632, 1.2568233290714976,
      0.93492743087263375, -0.90032289616763428, -1.3665152327026466,
      0.0741121056229236, 1.4377782920916096, 0.51087302480934793,
      -1.155812124518004, -1.2026555538608998, 0.61151895421193647,
      1.3625766771030725, 0.054865613210758966, -1.4686527360028307,
      -0.69326013374393691, 1.0282981079035971, 1.1776863456185247,
      -0.645374289899419, -1.4281738384265144, -0.09029803308360064,
      1.4186191384097773, 0.54429807097432825, -1.1722869947294523,
      -1.1433624156108992, 0.74886982448239825, 1.3037221699553405,
      -0.22772171010379169, -1.5201927028930158, -0.30861883034018095,
      1.2788759490001409, 0.78771041199955483, -1.1340912351346777,
      -1.1558121245180675, 0.614007701848837, 1.3815996183093282,
      -0.29511469811992835, -1.4557003793577274, -0.29059636992664156,
      1.3872523889667498, 0.57734027229214047, -1.198816714781195,
      -1.0532610982231179, 0.92083262466729787, 1.1772526192293844,
      -0.58651105131411518, -1.4623880475344559, 0.22772171010373454,
      1.3897819951310932, 0.12788502014604453, -1.4901146684241171,
      -0.45852599615469036, 1.2568606094400159, 0.74886982448242179,
      -1.2278493075923951, -0.98980839135173271, 0.89926488449688025,
      1.1776863456184696, -0.80809878706098515, -1.3132367468838284,
      0.44729542114839055, 1.4004240464804367, -0.3491101507164826,
      -1.4453395841299956, 0.0011729436113865619, 1.4552406535776004,
      0.069602407758901835, -1.4377782920915687, -0.380432433966106,
      1.4004240464804758, 0.40857758912812986, -1.350082261542799,
      -0.67455370466484721, 1.2928605654593, 0.65811543050002264,
      -1.2339650931322912, -0.88144074662813532, 1.1776863456184685,
      0.82529446653957439, -1.1274443985450486, -1.0122447546015847,
      1.08586680837258, 0.92302638924031621, -1.0548778365160496,
      -1.0797841731971509, 1.0357827552401679, 0.96261592124327677,
      -1.0293356096196602, -1.0928177213680061, 1.035782755240154,
      0.94958237307251736, -1.0548778365160949, -1.0532281893650193,
      1.085866808372546, 0.88204295447695646, -1.1274443985450591,
      -0.95549626666421328, 1.1776863456184978, 0.75123894650350476,
      -1.2339650931322566, -0.788317230624646, 1.2928605654594041,
      0.54435190454009208, -1.3500822615426791, -0.53877938925276658,
      1.4004240464805278, 0.25023063384144423, -1.4377782920915381,
      -0.19980420788350894, 1.4552406535776179, -0.13137474373597796,
      -1.4453395841300476, 0.2189083505919418, 1.4004240464804341,
      -0.57749722127287739, -1.3132367468838542, 0.67789698693638678,
      1.1776863456184803, -1.0294666846216265, -0.98980839135173526,
      1.0976475074676413, 0.74886982448236639, -1.3870624095647619,
      -0.45852599615477907, 1.3599128682993886, 0.12788502014585112,
      -1.519983795255746, 0.22772171010371484, 1.3321862474098451,
      -0.58651105131417092, -1.3074544193539035, 0.92083262466730031,
      0.92305929809849574, -1.1988167147811595, -0.707542072416772,
      1.3872523889667006, 0.16039456980194708, -1.4557003793577612,
      0.16491289799534806, 1.3815996183092361, -0.74420950197335967,
      -1.1558121245181157, 1.0038894350100847, 0.78771041199955338,
      -1.4090777491246156, -0.30861883034005144, 1.3899909027684587,
      -0.2277217101036676, -1.4339239700800257, 0.7488698244824,
      1.0131606154862653, -1.1722869947295176, -0.67449987109899989,
      1.418619138409752, -0.0399037670410758, -1.4281738384265648,
      0.51517248977477759, 1.1776863456184279, -1.1584999080283276,
      -0.69326013374405726, 1.3384509358780849, 0.054865613210692235,
      -1.4927784772278314, 0.61151895421183255, 1.0724537537362147,
      -1.1558121245180575, -0.64107482493411072, 1.4377782920916458,
      -0.20431390574770464, -1.36651523270265, 0.7701210960429653,
      0.93492743087268049, -1.3870251291961482, -0.23675098307184089,
      1.382119409491706, -0.544372557656904, -1.2138633951971021,
      1.1776863456184858, 0.42591329044654, -1.4533735152449072,
      0.27256883142569083, 1.2576136461437066, -1.1339855873395659,
      -0.62807072937388875, 1.3758236368757704, -0.2367509830718528,
      -1.361027206225252, 1.0293356096197301, 0.59380944596800334,
      -1.4391807198677187, 0.18299978789420587, 1.2800210863198915,
      -1.1339762307236698, -0.58651105131402725, 1.3860110251679174,
      -0.370869842026528, -1.2677134913580177, 1.1776863456184294,
      0.33891442333237431, -1.4522249039621558, 0.5319421752391521,
      1.0357827552401526, -1.3869969538825058, -0.10053070563081196,
      1.327008415785019, -0.89941847316541779, -0.80405101591920958,
      1.4377782920915869, -0.3847884887628078, -1.1988167147811117,
      1.1504242721133169, 0.28175003406601756, -1.4927311641614709,
      0.81064404617697638, 0.73612354269675639, -1.4316015579892107,
      0.25478532758125305, 1.1776863456184854, -1.3191395639603036,
      -0.17336978113045745, 1.3270266818039349, -0.95579213373053828,
      -0.67443287954935727, 1.4556716450785707, -0.66194407190811844,
      -0.95579213373033323, 1.3335514394049581, -0.2277217101037346,
      -1.2676768060896195, 1.257613646143604, 0.051512965552237368,
      -1.3568162719937695, 1.0039768813304011, 0.4149026485017856,
      -1.4993892922009791, 0.86302189801334028, 0.59386485980554371,
      -1.4557003793577477, 0.59794250365651969, 0.84822275230168265,
      -1.5058191192527788, 0.4844855372199377, 0.92316823134012027,
      -1.4076644325752481, 0.27264344505173266, 1.0858668083725367,
      -1.4353694512352848, 0.22772171010371353, 1.0838731562553903,
      -1.3395818493076328, 0.092517642605166345, 1.1830392034669606,
      -1.3869306737089961, 0.12788502014600911, 1.1273512864157602,
      -1.3210254210657222, 0.074330364549315908, 1.1776863456184214,
      -1.4018181102174172, 0.19151828744069138, 1.0725688764072507,
      -1.3665152327027343, 0.21906452467786056, 1.0674000856623069,
      -1.4684262238115902, 0.41490264850191649, 0.89603469405174252,
      -1.4377782920916045, 0.51530930446543832, 0.8106440461769221,
      -1.5203958703330613, 0.77226533224885685, 0.54453451929626651,
      -1.4391807198676698, 0.91310776662404813, 0.35315179230078103,
      -1.4337642183244119, 1.1776863456185114, -0.021456378726847185,
      -1.224163347470278, 1.2791241734196717, -0.30861883034028342,
      -1.0530167048143884, 1.4430468946080341, -0.74402532202059068,
      -0.65271161775996078, 1.3725423787054358, -1.029335609619747,
      -0.29033433797008151, 1.2928605654592347, -1.3711176651507677,
      0.26378129885381613, 0.92326967548964889, -1.4483505728620656,
      0.69379541565160563, 0.52736438874375846, -1.4621099449367405,
      1.1776863456185143, -0.112854036506226, -1.1157841607872996,
      1.3601515298859117, -0.65271161775992592, -0.67427508531180935,
      1.4122136545356974, -1.2275525920702057, 0.054865613210736186,
      1.0256041935771123, -1.43777829209165, 0.67816638537666762,
      0.48448553721962528, -1.4273386802856318, 1.2712084867456805,
      -0.34879194409423425, -0.89941847316536472, 1.3893985842680106,
      -1.003143232290145, -0.19950119462253013, 1.1776863456184736,
      -1.4859161674655328, 0.70929019286054074, 0.40892056921564224,
      -1.3395818493075489, 1.2572235380776606, -0.44112855696326947,
      -0.78797722619582544, 1.4186191384097382, -1.2700092596496475,
      0.22772171010373671, 0.82566598957261794, -1.4483505728620081,
      1.0407107677927065, -0.082274052086266744, -1.0528472288922452,
      1.45524065357764, -1.1084912288689051, 0.0091463750543167958,
      0.96302034530398273, -1.455700379357745, 0.96626436884927847,
      -0.0091463750543276968, -1.0793575915936617, 1.4552406535775826,
      -1.1336188584580891, 0.082274052086226443, 0.88248535141478046,
      -1.4483505728620867, 1.0869866793555272, -0.22772171010377112,
      -0.88096303954227606, 1.4186191384097468, -1.3279505535351761,
      0.44112855696327719, 0.5448382155364907, -1.3395818493075224,
      1.3118828459393999, -0.70929019286055672, -0.37989708363247648,
      1.1776863456184044, -1.5140168828063767, 1.003143232290137,
      -0.13083751329847434, -0.89941847316540169, 1.3631960017252014,
      -1.27120848674571, 0.44789616544159871, 0.48448553721974807,
      -1.316318237227059, 1.4377782920915738, -1.0288702190732404,
      0.05486561321074937, 0.81139280109818979, -1.4122136545356749,
      1.2575360101111894, -0.6527116177599992, -0.36186566052418156,
      1.1157841607873515, -1.5193181552484447, 1.1776863456185462,
      -0.47271202653016109, -0.52736438874365266, 1.1780138071847031,
      -1.4483505728620631, 1.0046075951010478, -0.26378129885393331,
      -0.70679529226608551, 1.2928605654592518, -1.5024334061008815,
      1.0293356096197015, -0.29425426288362916, -0.65271161775987208,
      1.2233177851551775, -1.4430468946080524, 1.004731869550199,
      -0.3086188303401356, -0.62337797299980258, 1.2241633474701847,
      -1.5192166310667587, 1.1776863456183744, -0.55938585090982362,
      -0.35315179230085608, 1.0141164513281435, -1.4391807198676618,
      1.2579150505505554, -0.77226533224885985, -0.089186215913422476,
      0.81064404617691777, -1.3990646833865563, 1.4377782920915527,
      -1.1574087855105366, 0.41490264850178504, 0.32240359072949965,
      -1.0674000856623684, 1.3638491194125963, -1.3665152327029224,
      0.84454305364511262, -0.19151828744066315, -0.63982117870918676,
      1.1776863456185318, -1.5127677514495259, 1.3210254210658088,
      -0.89885876158396028, 0.1278850201459926, 0.545799916723219,
      -1.1830392034670683, 1.3835698132874794, -1.3395818493076503,
      0.830483329580988, -0.22772171010383632, -0.55442007705301821,
      1.0858668083724969, -1.4794192399600732, 1.4076644325752956,
      -1.1322949342119526, 0.48448553721983212, 0.14410218589222856,
      -0.84822275230166078, 1.2328012777773198, -1.4557003793577841,
      1.234955229690764, -0.86302189801333684, 0.18498659299551695,
      0.414902648501638, -1.0510817449771506, 1.3568162719936807,
      -1.5138915691857173, 1.2576136461436593, -0.8828783813763631,
      0.22772171010373191, 0.3412701605911389, -0.9557921337303471,
      1.265116654566788, -1.455671645078475, 1.2595462288027981,
      -0.955792133730412, 0.36353198918392482, 0.17336978113049767,
      -0.80123025154079164, 1.1776863456183291, -1.4821923719576962,
      1.4316015579891641, -1.2773330412704402, 0.81064404617693675,
      -0.34574288129896963, -0.281750034065993, 0.73953819614536,
      -1.1988167147810709, 1.3587331781044041, -1.43777829209162,
      1.1929241454707431, -0.8994184731655066, 0.36482849652080546,
      0.10053070563079644, -0.6702485434831269, 1.0357827552400485,
      -1.3882450143155185, 1.4522249039620709, -1.4588653551808586,
      1.17768634561858, -0.88018011068225244, 0.37086984202668194,
      0.056711410363106618, -0.58651105131402959, 0.92865502886818641,
      -1.280021086319902, 1.3752689087339929, -1.4391807198678228,
      1.2392833559104064, -1.0293356096198547, 0.60450216853350458,
      -0.23675098307193798, -0.26536775372710247, 0.62807072937388531,
      -1.0456760858601803, 1.2576136461436973, -1.4730703442159516,
      1.4533735152450495, -1.4269439427535768, 1.1776863456184183,
      -0.94997043586982688, 0.54437255765680381, -0.21279669682045491,
      -0.23675098307188724, 0.55479723929565394, -0.93492743087262375,
      1.1383954941810974, -1.366515232702662, 1.3959424825157043,
      -1.437778292091487, 1.2846993780919198, -1.1558121245181248,
      0.85718397020424575, -0.61151895421185354, 0.23388296054012553,
      0.054865613210535805, -0.43523691872232451, 0.69326013374395412,
      -1.0085425982945573, 1.1776863456183679, -1.3811858199949796,
      1.4281738384264413, -1.499974434293907, 1.4186191384097075,
      -1.3646644747278753, 1.1722869947295187, -1.0186734184800681,
      0.74886982448237061, -0.53365800214801551, 0.22772171010375114,
      0.0075572742070260622, -0.30861883034006332, 0.52613467615250908,
      -0.78771041199959346, 0.9582655586711365, -1.1558121245179875,
      1.2612903248241041, -1.3815996183093255, 1.4151962947585519,
      -1.4557003793577941, 1.4205000555140115, -1.387252388966794,
      1.2938224551825153, -1.1988167147813031, 1.062441968017799,
      -0.92083262466735216, 0.75888051610009921, -0.586511051314065,
      0.41624793360425388, -0.22772171010379758, 0.064736670994190865,
      0.1278850201458468, -0.27062498991138861, 0.45852599615470968,
      -0.57105735262997093, 0.74886982448235218, -0.8241689822393431,
      0.98980839135184451, -1.0234189845169082, 1.1776863456184556,
      -1.1671656637555923, 1.3132367468837751, -1.2575283131315891,
      1.4004240464805091, -1.2992358042916305, 1.4453395841299379,
      -1.2985796232401934, 1.4552406535776168, -1.2625385681734598,
      1.4377782920915385, -1.1981019353076048, 1.4004240464805029,
      -1.1117890274721534, 1.3500822615426913, -1.0093445368302685,
      1.2928605654592793, -0.8955799642523784, 1.2339650931322539,
      -0.77432851183227314, 1.1776863456184916, -0.64848264009609913,
      1.1274443985451252, -0.52008784874624892, 1.0858668083725425,
      -0.39047176930888561, 1.0548778365160858, -0.2603933200625505,
      1.0357827552401586, -0.13020180012464427, 1.0293356096196626,
      4.0590492605963612E-14, 1.035782755240044, 0.13019151993794872,
      1.0548778365160583, 0.26026996918415751, 1.0858668083725957,
      0.38988604862150356, 1.1274443985450744, 0.51828083997134644,
      1.177686345618504, 0.64412671170758262, 1.2339650931322783,
      0.76537816412775173, 1.2928605654592691, 0.87914273670568588,
      1.3500822615427905, 0.98158722734754988, 1.4004240464805378,
      1.0679001351829045, 1.4377782920916087, 1.1323367680488143,
      1.4552406535777005, 1.1683778231154796, 1.4453395841300156,
      1.1690340041670173, 1.4004240464805431, 1.1273265130069039,
      1.3132367468838106, 1.0369638636309571, 1.1776863456184878,
      0.89321718439226583, 0.98980839135177612, 0.69396718211468245,
      0.748869824482328, 0.44085555250542841, 0.45852599615477618,
      0.14042318978684099, 0.12788502014596068, -0.19493847111874318,
      -0.22772171010366385, -0.54644973372888417, -0.58651105131397929,
      -0.889082316224844, -0.92083262466724469, -1.1926437681423814,
      -1.19881671478117, -1.4240242553070055, -1.3872523889667707,
      -1.5507018556385745, -1.455700379357697, -1.5453980948832262,
      -1.3815996183092807, -1.3914921249488947, -1.1558121245179864,
      -1.0884673587958802, -0.787710411999592, -0.65633647627721792,
      -0.30861883034004162, -0.13775907433169526, 0.22772171010368611,
      0.40345620202328109, 0.74886982448244488, 0.88847161835529953,
      1.1722869947295302, 1.2344626746031391, 1.4186191384097977,
      1.3697726341693002, 1.4281738384265719, 1.2509840198704123,
      1.177686345618479, 0.87834079817005228, 0.69326013374399176,
      0.30503511859788274, 0.054865613210687093, -0.36408476066473267,
      -0.61151895421178737, -0.98738577032891583, -1.155812124518002,
      -1.4149011782165808, -1.4377782920915374, -1.5261442826405069,
      -1.3665152327026746, -1.2685972943057309, -0.93492743087270214,
      -0.68499903942032536, -0.23675098307180525, 0.082594896695794048,
      0.5443725576568661, 0.81976863574522707, 1.1776863456184377,
      1.2967421426289536, 1.4533735152450413, 1.3428685440911681,
      1.2576136461436609, 0.91547428573555367, 0.62807072937396113,
      0.13516595360252823, -0.23675098307178982, -0.734703968658123,
      -1.0293356096196526, -1.3694851560349126, -1.4391807198676174,
      -1.5054707088585906, -1.2800210863198282, -1.0588568289927562,
      -0.586511051314125, -0.18691321048778273, 0.37086984202646028,
      0.74997831055754538, 1.177686345618469, 1.3286635550561614,
      1.4522249039620285, 1.2580432141909075, 1.0357827552401584,
      0.54004674335855418, 0.10053070563096483, -0.49503029664539017,
      -0.89941847316540879, -1.3231259455953868, -1.437778292091489,
      -1.4889349782291028, -1.1988167147811311, -0.86973999627013254,
      -0.28175003406614157, 0.21554108117423046, 0.81064404617692087,
      1.1471312411458672, 1.4316015579892569, 1.3519905718332028,
      1.1776863456184279, 0.67102845141625389, 0.1733697811305229,
      -0.49373378930857903, -0.95579213373044536, -1.3897480289275539,
      -1.4556716450784986, -1.3953184546915511, -0.95579213373041827,
      -0.47147196071595832, 0.22772171010376285, 0.75267658125167747,
      1.2576136461436522, 1.3836897690610948, 1.3568162719938555,
      0.92087994485261393, 0.414902648501887, -0.31518839312013824,
      -0.86302189801317264, -1.3651570298154858, -1.4557003793576759,
      -1.3630030779019859, -0.84822275230162525, -0.27430398601701145,
      0.484485537219845, 1.0020931340872583, 1.4076644325753227,
      1.3492174398353682, 1.0858668083725245, 0.42421827692848363,
      -0.22772171010367373, -0.96068512970551045, -1.3395818493075793,
      -1.5137716134121004, -1.1830392034670809, -0.6760017168478718,
      0.12788502014594957, 0.76865696145923246, 1.3210254210656935,
      1.3825659513249009, 1.1776863456184838, 0.509619378584437,
      -0.19151828744050023, -0.97474485376967723, -1.3665152327026242,
      -1.4940509195371137, -1.0674000856622183, -0.45260539085422774,
      0.41490264850194564, 1.0272069853858299, 1.4377782920916038,
      1.2688628832619235, 0.810644046176871, -0.041015584211126881,
      -0.77226533224888416, -1.3881168506751831, -1.4391807198676907,
      -1.1443182514527785, -0.35315179230074978, 0.4291840507853068,
      1.1776863456184803, 1.3890148309421508, 1.2241633474703162,
      0.49317617287522708, -0.30861883034005011, -1.1349336696748449,
      -1.4430468946081263, -1.353519585279864, -0.65271161775993114,
      0.16405246275899521, 1.0293356096197122, 1.3722316059762065,
      1.2928605654593059, 0.57659349214159161, -0.26378129885382495,
      -1.1348093952257554, -1.4483505728618988, -1.3082156073095106,
      -0.52736438874367764, 0.34251022640530043, 1.1776863456185624,
      1.3891163551237387, 1.1157841607874102, 0.23166386039969653,
      -0.65271161775992281, -1.387737810235822, -1.4122136545356458,
      -0.94159460122289873, 0.054865613210678128, 0.89866841894857641,
      1.4377782920915503, 1.1861164371024422, 0.48448553721978238,
      -0.57809796556625614, -1.2712084867456279, -1.4933978018498197,
      -0.89941847316550183, 0.00063571317389858617, 1.0031432322900675,
      1.383815082681729, 1.1776863456184938, 0.24969528350793502,
      -0.70929019286049255, -1.4420846460640118, -1.3395818493075733,
      -0.67504001566122385, 0.44112855696320113, 1.1977487534104885,
      1.4186191384097342, 0.750761239417685, -0.22772171010371833,
      -1.2171884794800896, -1.4483505728620525, -1.012687151539436,
      0.082274052086257363, 1.003417058333492, 1.4552406535776043,
      0.94915579146909457, -0.0091463750542371183, -1.0964661689738009,
      -1.4557003793577761, -1.09322214542873, 0.0091463750542701925,
      0.97828942874420755, 1.4552406535776079, 0.92264542876761824,
      -0.082274052086159427, -1.1709125679174339, -1.4483505728619452,
      -0.95586778969742048, 0.22772171010373748, 1.1398074595249861,
      1.4186191384096909, 0.65777542607126493, -0.441128556963233,
      -1.3874253382022863, -1.3395818493075586, -0.53912236934032642,
      0.70929019286043271, 1.3557143673408407, 1.1776863456185516,
      0.069299394497803063, -1.0031432322900375, -1.5196003843927595,
      -0.8994184731653373, 0.21859014396947191, 1.2712084867457221,
      1.2971368801610454, 0.48448553721972903, -0.80836818550107781,
      -1.4377782920916191, -1.1558059937017391, 0.054865613210712309,
      1.0973507919455234, 1.4122136545356403, 0.54407328518721021,
      -0.65271161775990993, -1.4903533300106746, -1.1157841607873353,
      -0.017347763618596933, 1.1776863456185336, 1.3319081448120604,
      0.52736438874380787, -0.82399721577629148, -1.4483505728620147,
      -1.0534714756143144, 0.26378129885388762, 1.2409158650261194,
      1.2928605654593295, 0.16013253784557754, -1.0293356096197728,
      -1.5027441788300062, -0.652711617759908, 0.6138235218960022,
      1.4430468946081112, 0.9228149046898616, -0.30861883034000726,
      -1.4093259735442574, -1.2241633474702651, -0.10874542139782474,
      1.1776863456184534, 1.3035624181998031, 0.35315179230064431,
      -1.0433095667486212, -1.4391807198677067, -0.67473631942089873,
      0.77226533224887228, 1.390194070208346, 0.81064404617697339,
      -0.64551110459008854, -1.4377782920915105, -1.0262364941764393,
      0.41490264850177394, 1.3382244236869039, 1.0674000856622352,
      -0.34926632480246078, -1.366515232702727, -1.2027706765318877,
      0.19151828744054647, 1.2716163100927329, 1.1776863456184938,
      -0.20453216467389448, -1.3210254210658261, -1.2575530865404105,
      0.12788502014594888, 1.2567288735843483, 1.1830392034670498,
      -0.22271944272960292, -1.3395818493076368, -1.2140749563800999,
      0.22772171010384165, 1.3051676511105395, 1.0858668083725471,
      -0.40284524517638037, -1.40766443257531, -1.0533700314648591,
      0.48448553721977894, 1.3756173191281034, 0.84822275230161681,
      -0.72814430378110673, -1.4557003793577414, -0.72406665993026242,
      0.86302189801333284, 1.3691874920762994, 0.41490264850180031,
      -1.1341786814550261, -1.3568162719938683, -0.18171476567685391,
      1.2576136461436467, 1.1374750059650436, -0.22772171010372344,
      -1.4637532395295874, -0.955792133730518, 0.531742271783323,
      1.4556716450785845, 0.5442310794247488, -0.95579213373045468,
      -1.4572284819286119, -0.17336978113051607, 1.1889377638356,
      1.177686345618429, -0.3849871277058235, -1.4316015579893222,
      -0.8663253428214428, 0.81064404617689567, 1.3625293640369607,
      0.28175003406603955, -1.280626072237885, -1.1988167147811954,
      0.25458668863814521, 1.4377782920915059, 0.67384921579462809,
      -0.899418473165497, -1.4572102159097016, -0.10053070563090326,
      1.2567951537577555, 1.0357827552401506, -0.66214397536376457,
      -1.4522249039620809, -0.46911622345693565, 1.1776863456184616,
      1.1375116912334364, -0.37086984202659834, -1.5162128252925446,
      -0.5865110513141335, 1.0037744305990637, 1.2800210863197903,
      -0.31320158801883241, -1.4391807198676942, -0.72401124609260747,
      1.0293356096196937, 1.2308254061005535, -0.23675098307184872,
      -1.5060254370005177, -0.62807072937389141, 1.0037837872148778,
      1.2576136461436005, -0.40277063155041032, -1.4533735152450185,
      -0.5561150905711989, 1.1776863456184452, 1.0836615950725286,
      -0.54437255765692, -1.5123212096162606, -0.23675098307185632,
      1.2568233290714976, 0.93492743087263375, -0.90032289616763428,
      -1.3665152327026466, 0.0741121056229236, 1.4377782920916096,
      0.51087302480934793, -1.155812124518004, -1.2026555538608998,
      0.61151895421193647, 1.3625766771030725, 0.054865613210758966,
      -1.4686527360028307, -0.69326013374393691, 1.0282981079035971,
      1.1776863456185247, -0.645374289899419, -1.4281738384265144,
      -0.09029803308360064, 1.4186191384097773, 0.54429807097432825,
      -1.1722869947294523, -1.1433624156108992, 0.74886982448239825,
      1.3037221699553405, -0.22772171010379169, -1.5201927028930158,
      -0.30861883034018095, 1.2788759490001409, 0.78771041199955483,
      -1.1340912351346777, -1.1558121245180675, 0.614007701848837,
      1.3815996183093282, -0.29511469811992835, -1.4557003793577274,
      -0.29059636992664156, 1.3872523889667498, 0.57734027229214047,
      -1.198816714781195, -1.0532610982231179, 0.92083262466729787,
      1.1772526192293844, -0.58651105131411518, -1.4623880475344559,
      0.22772171010373454, 1.3897819951310932, 0.12788502014604453,
      -1.4901146684241171, -0.45852599615469036, 1.2568606094400159,
      0.74886982448242179, -1.2278493075923951, -0.98980839135173271,
      0.89926488449688025, 1.1776863456184696, -0.80809878706098515,
      -1.3132367468838284, 0.44729542114839055, 1.4004240464804367,
      -0.3491101507164826, -1.4453395841299956, 0.0011729436113865619,
      1.4552406535776004, 0.069602407758901835, -1.4377782920915687,
      -0.380432433966106, 1.4004240464804758, 0.40857758912812986,
      -1.350082261542799, -0.67455370466484721, 1.2928605654593,
      0.65811543050002264, -1.2339650931322912, -0.88144074662813532,
      1.1776863456184685, 0.82529446653957439, -1.1274443985450486,
      -1.0122447546015847, 1.08586680837258, 0.92302638924031621,
      -1.0548778365160496, -1.0797841731971509, 1.0357827552401679,
      0.96261592124327677, -1.0293356096196602, -1.0928177213680061,
      1.035782755240154, 0.94958237307251736, -1.0548778365160949,
      -1.0532281893650193, 1.085866808372546, 0.88204295447695646,
      -1.1274443985450591, -0.95549626666421328, 1.1776863456184978,
      0.75123894650350476, -1.2339650931322566, -0.788317230624646,
      1.2928605654594041, 0.54435190454009208, -1.3500822615426791,
      -0.53877938925276658, 1.4004240464805278, 0.25023063384144423,
      -1.4377782920915381, -0.19980420788350894, 1.4552406535776179,
      -0.13137474373597796, -1.4453395841300476, 0.2189083505919418,
      1.4004240464804341, -0.57749722127287739, -1.3132367468838542,
      0.67789698693638678, 1.1776863456184803, -1.0294666846216265,
      -0.98980839135173526, 1.0976475074676413, 0.74886982448236639,
      -1.3870624095647619, -0.45852599615477907, 1.3599128682993886,
      0.12788502014585112, -1.519983795255746, 0.22772171010371484,
      1.3321862474098451, -0.58651105131417092, -1.3074544193539035,
      0.92083262466730031, 0.92305929809849574, -1.1988167147811595,
      -0.707542072416772, 1.3872523889667006, 0.16039456980194708,
      -1.4557003793577612, 0.16491289799534806, 1.3815996183092361,
      -0.74420950197335967, -1.1558121245181157, 1.0038894350100847,
      0.78771041199955338, -1.4090777491246156, -0.30861883034005144,
      1.3899909027684587, -0.2277217101036676, -1.4339239700800257,
      0.7488698244824, 1.0131606154862653, -1.1722869947295176,
      -0.67449987109899989, 1.418619138409752, -0.0399037670410758,
      -1.4281738384265648, 0.51517248977477759, 1.1776863456184279,
      -1.1584999080283276, -0.69326013374405726, 1.3384509358780849,
      0.054865613210692235, -1.4927784772278314, 0.61151895421183255,
      1.0724537537362147, -1.1558121245180575, -0.64107482493411072,
      1.4377782920916458, -0.20431390574770464, -1.36651523270265,
      0.7701210960429653, 0.93492743087268049, -1.3870251291961482,
      -0.23675098307184089, 1.382119409491706, -0.544372557656904,
      -1.2138633951971021, 1.1776863456184858, 0.42591329044654,
      -1.4533735152449072, 0.27256883142569083, 1.2576136461437066,
      -1.1339855873395659, -0.62807072937388875, 1.3758236368757704,
      -0.2367509830718528, -1.361027206225252, 1.0293356096197301,
      0.59380944596800334, -1.4391807198677187, 0.18299978789420587,
      1.2800210863198915, -1.1339762307236698, -0.58651105131402725,
      1.3860110251679174, -0.370869842026528, -1.2677134913580177,
      1.1776863456184294, 0.33891442333237431, -1.4522249039621558,
      0.5319421752391521, 1.0357827552401526, -1.3869969538825058,
      -0.10053070563081196, 1.327008415785019, -0.89941847316541779,
      -0.80405101591920958, 1.4377782920915869, -0.3847884887628078,
      -1.1988167147811117, 1.1504242721133169, 0.28175003406601756,
      -1.4927311641614709, 0.81064404617697638, 0.73612354269675639,
      -1.4316015579892107, 0.25478532758125305, 1.1776863456184854,
      -1.3191395639603036, -0.17336978113045745, 1.3270266818039349,
      -0.95579213373053828, -0.67443287954935727, 1.4556716450785707,
      -0.66194407190811844, -0.95579213373033323, 1.3335514394049581,
      -0.2277217101037346, -1.2676768060896195, 1.257613646143604,
      0.051512965552237368, -1.3568162719937695, 1.0039768813304011,
      0.4149026485017856, -1.4993892922009791, 0.86302189801334028,
      0.59386485980554371, -1.4557003793577477, 0.59794250365651969,
      0.84822275230168265, -1.5058191192527788, 0.4844855372199377,
      0.92316823134012027, -1.4076644325752481, 0.27264344505173266,
      1.0858668083725367, -1.4353694512352848, 0.22772171010371353,
      1.0838731562553903, -1.3395818493076328, 0.092517642605166345,
      1.1830392034669606, -1.3869306737089961, 0.12788502014600911,
      1.1273512864157602, -1.3210254210657222, 0.074330364549315908,
      1.1776863456184214, -1.4018181102174172, 0.19151828744069138,
      1.0725688764072507, -1.3665152327027343, 0.21906452467786056,
      1.0674000856623069, -1.4684262238115902, 0.41490264850191649,
      0.89603469405174252, -1.4377782920916045, 0.51530930446543832,
      0.8106440461769221, -1.5203958703330613, 0.77226533224885685,
      0.54453451929626651, -1.4391807198676698, 0.91310776662404813,
      0.35315179230078103, -1.4337642183244119, 1.1776863456185114,
      -0.021456378726847185, -1.224163347470278, 1.2791241734196717,
      -0.30861883034028342, -1.0530167048143884, 1.4430468946080341,
      -0.74402532202059068, -0.65271161775996078, 1.3725423787054358,
      -1.029335609619747, -0.29033433797008151, 1.2928605654592347,
      -1.3711176651507677, 0.26378129885381613, 0.92326967548964889,
      -1.4483505728620656, 0.69379541565160563, 0.52736438874375846,
      -1.4621099449367405, 1.1776863456185143, -0.112854036506226,
      -1.1157841607872996, 1.3601515298859117, -0.65271161775992592,
      -0.67427508531180935, 1.4122136545356974, -1.2275525920702057,
      0.054865613210736186, 1.0256041935771123, -1.43777829209165,
      0.67816638537666762, 0.48448553721962528, -1.4273386802856318,
      1.2712084867456805, -0.34879194409423425, -0.89941847316536472,
      1.3893985842680106, -1.003143232290145, -0.19950119462253013,
      1.1776863456184736, -1.4859161674655328, 0.70929019286054074,
      0.40892056921564224, -1.3395818493075489, 1.2572235380776606,
      -0.44112855696326947, -0.78797722619582544, 1.4186191384097382,
      -1.2700092596496475, 0.22772171010373671, 0.82566598957261794,
      -1.4483505728620081, 1.0407107677927065, -0.082274052086266744,
      -1.0528472288922452, 1.45524065357764, -1.1084912288689051,
      0.0091463750543167958, 0.96302034530398273, -1.455700379357745,
      0.96626436884927847, -0.0091463750543276968, -1.0793575915936617,
      1.4552406535775826, -1.1336188584580891, 0.082274052086226443,
      0.88248535141478046, -1.4483505728620867, 1.0869866793555272,
      -0.22772171010377112, -0.88096303954227606, 1.4186191384097468,
      -1.3279505535351761, 0.44112855696327719, 0.5448382155364907,
      -1.3395818493075224, 1.3118828459393999, -0.70929019286055672,
      -0.37989708363247648, 1.1776863456184044, -1.5140168828063767,
      1.003143232290137, -0.13083751329847434, -0.89941847316540169,
      1.3631960017252014, -1.27120848674571, 0.44789616544159871,
      0.48448553721974807, -1.316318237227059, 1.4377782920915738,
      -1.0288702190732404, 0.05486561321074937, 0.81139280109818979,
      -1.4122136545356749, 1.2575360101111894, -0.6527116177599992,
      -0.36186566052418156, 1.1157841607873515, -1.5193181552484447,
      1.1776863456185462, -0.47271202653016109, -0.52736438874365266,
      1.1780138071847031, -1.4483505728620631, 1.0046075951010478,
      -0.26378129885393331, -0.70679529226608551, 1.2928605654592518,
      -1.5024334061008815, 1.0293356096197015, -0.29425426288362916,
      -0.65271161775987208, 1.2233177851551775, -1.4430468946080524,
      1.004731869550199, -0.3086188303401356, -0.62337797299980258,
      1.2241633474701847, -1.5192166310667587, 1.1776863456183744,
      -0.55938585090982362, -0.35315179230085608, 1.0141164513281435,
      -1.4391807198676618, 1.2579150505505554, -0.77226533224885985,
      -0.089186215913422476, 0.81064404617691777, -1.3990646833865563,
      1.4377782920915527, -1.1574087855105366, 0.41490264850178504,
      0.32240359072949965, -1.0674000856623684, 1.3638491194125963,
      -1.3665152327029224, 0.84454305364511262, -0.19151828744066315,
      -0.63982117870918676, 1.1776863456185318, -1.5127677514495259,
      1.3210254210658088, -0.89885876158396028, 0.1278850201459926,
      0.545799916723219, -1.1830392034670683, 1.3835698132874794,
      -1.3395818493076503, 0.830483329580988, -0.22772171010383632,
      -0.55442007705301821, 1.0858668083724969, -1.4794192399600732,
      1.4076644325752956, -1.1322949342119526, 0.48448553721983212,
      0.14410218589222856, -0.84822275230166078, 1.2328012777773198,
      -1.4557003793577841, 1.234955229690764, -0.86302189801333684,
      0.18498659299551695, 0.414902648501638, -1.0510817449771506,
      1.3568162719936807, -1.5138915691857173, 1.2576136461436593,
      -0.8828783813763631, 0.22772171010373191, 0.3412701605911389,
      -0.9557921337303471, 1.265116654566788, -1.455671645078475,
      1.2595462288027981, -0.955792133730412, 0.36353198918392482,
      0.17336978113049767, -0.80123025154079164, 1.1776863456183291,
      -1.4821923719576962, 1.4316015579891641, -1.2773330412704402,
      0.81064404617693675, -0.34574288129896963, -0.281750034065993,
      0.73953819614536, -1.1988167147810709, 1.3587331781044041,
      -1.43777829209162, 1.1929241454707431, -0.8994184731655066,
      0.36482849652080546, 0.10053070563079644, -0.6702485434831269,
      1.0357827552400485, -1.3882450143155185, 1.4522249039620709,
      -1.4588653551808586, 1.17768634561858, -0.88018011068225244,
      0.37086984202668194, 0.056711410363106618, -0.58651105131402959,
      0.92865502886818641, -1.280021086319902, 1.3752689087339929,
      -1.4391807198678228, 1.2392833559104064, -1.0293356096198547,
      0.60450216853350458, -0.23675098307193798, -0.26536775372710247,
      0.62807072937388531, -1.0456760858601803, 1.2576136461436973,
      -1.4730703442159516, 1.4533735152450495, -1.4269439427535768,
      1.1776863456184183, -0.94997043586982688, 0.54437255765680381,
      -0.21279669682045491, -0.23675098307188724, 0.55479723929565394,
      -0.93492743087262375, 1.1383954941810974, -1.366515232702662,
      1.3959424825157043, -1.437778292091487, 1.2846993780919198,
      -1.1558121245181248, 0.85718397020424575, -0.61151895421185354,
      0.23388296054012553, 0.054865613210535805, -0.43523691872232451,
      0.69326013374395412, -1.0085425982945573, 1.1776863456183679,
      -1.3811858199949796, 1.4281738384264413, -1.499974434293907,
      1.4186191384097075, -1.3646644747278753, 1.1722869947295187,
      -1.0186734184800681, 0.74886982448237061, -0.53365800214801551,
      0.22772171010375114, 0.0075572742070260622, -0.30861883034006332,
      0.52613467615250908, -0.78771041199959346, 0.9582655586711365,
      -1.1558121245179875, 1.2612903248241041, -1.3815996183093255,
      1.4151962947585519, -1.4557003793577941, 1.4205000555140115,
      -1.387252388966794, 1.2938224551825153, -1.1988167147813031,
      1.062441968017799, -0.92083262466735216, 0.75888051610009921,
      -0.586511051314065, 0.41624793360425388, -0.22772171010379758,
      0.064736670994190865, 0.1278850201458468, -0.27062498991138861,
      0.45852599615470968, -0.57105735262997093, 0.74886982448235218,
      -0.8241689822393431, 0.98980839135184451, -1.0234189845169082,
      1.1776863456184556, -1.1671656637555923, 1.3132367468837751,
      -1.2575283131315891, 1.4004240464805091, -1.2992358042916305,
      1.4453395841299379, -1.2985796232401934, 1.4552406535776168,
      -1.2625385681734598, 1.4377782920915385, -1.1981019353076048,
      1.4004240464805029, -1.1117890274721534, 1.3500822615426913,
      -1.0093445368302685, 1.2928605654592793, -0.8955799642523784,
      1.2339650931322539, -0.77432851183227314, 1.1776863456184916,
      -0.64848264009609913, 1.1274443985451252, -0.52008784874624892,
      1.0858668083725425, -0.39047176930888561, 1.0548778365160858,
      -0.2603933200625505, 1.0357827552401586, -0.13020180012464427,
      1.0293356096196626, 4.0590492605963612E-14, 1.035782755240044,
      0.13019151993794872, 1.0548778365160583, 0.26026996918415751,
      1.0858668083725957, 0.38988604862150356, 1.1274443985450744,
      0.51828083997134644, 1.177686345618504, 0.64412671170758262,
      1.2339650931322783, 0.76537816412775173, 1.2928605654592691,
      0.87914273670568588, 1.3500822615427905, 0.98158722734754988,
      1.4004240464805378, 1.0679001351829045, 1.4377782920916087,
      1.1323367680488143, 1.4552406535777005, 1.1683778231154796,
      1.4453395841300156, 1.1690340041670173, 1.4004240464805431,
      1.1273265130069039, 1.3132367468838106, 1.0369638636309571,
      1.1776863456184878, 0.89321718439226583, 0.98980839135177612,
      0.69396718211468245, 0.748869824482328, 0.44085555250542841,
      0.45852599615477618, 0.14042318978684099, 0.12788502014596068,
      -0.19493847111874318, -0.22772171010366385, -0.54644973372888417,
      -0.58651105131397929, -0.889082316224844, -0.92083262466724469,
      -1.1926437681423814, -1.19881671478117, -1.4240242553070055,
      -1.3872523889667707, -1.5507018556385745, -1.455700379357697,
      -1.5453980948832262, -1.3815996183092807, -1.3914921249488947,
      -1.1558121245179864, -1.0884673587958802, -0.787710411999592,
      -0.65633647627721792, -0.30861883034004162, -0.13775907433169526,
      0.22772171010368611, 0.40345620202328109, 0.74886982448244488,
      0.88847161835529953, 1.1722869947295302, 1.2344626746031391,
      1.4186191384097977, 1.3697726341693002, 1.4281738384265719,
      1.2509840198704123, 1.177686345618479, 0.87834079817005228,
      0.69326013374399176, 0.30503511859788274, 0.054865613210687093,
      -0.36408476066473267, -0.61151895421178737, -0.98738577032891583,
      -1.155812124518002, -1.4149011782165808, -1.4377782920915374,
      -1.5261442826405069, -1.3665152327026746, -1.2685972943057309,
      -0.93492743087270214, -0.68499903942032536, -0.23675098307180525,
      0.082594896695794048, 0.5443725576568661, 0.81976863574522707,
      1.1776863456184377, 1.2967421426289536, 1.4533735152450413,
      1.3428685440911681, 1.2576136461436609, 0.91547428573555367,
      0.62807072937396113, 0.13516595360252823, -0.23675098307178982,
      -0.734703968658123, -1.0293356096196526, -1.3694851560349126,
      -1.4391807198676174, -1.5054707088585906, -1.2800210863198282,
      -1.0588568289927562, -0.586511051314125, -0.18691321048778273,
      0.37086984202646028, 0.74997831055754538, 1.177686345618469,
      1.3286635550561614, 1.4522249039620285, 1.2580432141909075,
      1.0357827552401584, 0.54004674335855418, 0.10053070563096483,
      -0.49503029664539017, -0.89941847316540879, -1.3231259455953868,
      -1.437778292091489, -1.4889349782291028, -1.1988167147811311,
      -0.86973999627013254, -0.28175003406614157, 0.21554108117423046,
      0.81064404617692087, 1.1471312411458672, 1.4316015579892569,
      1.3519905718332028, 1.1776863456184279, 0.67102845141625389,
      0.1733697811305229, -0.49373378930857903, -0.95579213373044536,
      -1.3897480289275539, -1.4556716450784986, -1.3953184546915511,
      -0.95579213373041827, -0.47147196071595832, 0.22772171010376285,
      0.75267658125167747, 1.2576136461436522, 1.3836897690610948,
      1.3568162719938555, 0.92087994485261393, 0.414902648501887,
      -0.31518839312013824, -0.86302189801317264, -1.3651570298154858,
      -1.4557003793576759, -1.3630030779019859, -0.84822275230162525,
      -0.27430398601701145, 0.484485537219845, 1.0020931340872583,
      1.4076644325753227, 1.3492174398353682, 1.0858668083725245,
      0.42421827692848363, -0.22772171010367373, -0.96068512970551045,
      -1.3395818493075793, -1.5137716134121004, -1.1830392034670809,
      -0.6760017168478718, 0.12788502014594957, 0.76865696145923246,
      1.3210254210656935, 1.3825659513249009, 1.1776863456184838,
      0.509619378584437, -0.19151828744050023, -0.97474485376967723,
      -1.3665152327026242, -1.4940509195371137, -1.0674000856622183,
      -0.45260539085422774, 0.41490264850194564, 1.0272069853858299,
      1.4377782920916038, 1.2688628832619235, 0.810644046176871,
      -0.041015584211126881, -0.77226533224888416, -1.3881168506751831,
      -1.4391807198676907, -1.1443182514527785, -0.35315179230074978,
      0.4291840507853068, 1.1776863456184803, 1.3890148309421508,
      1.2241633474703162, 0.49317617287522708, -0.30861883034005011,
      -1.1349336696748449, -1.4430468946081263, -1.353519585279864,
      -0.65271161775993114, 0.16405246275899521, 1.0293356096197122,
      1.3722316059762065, 1.2928605654593059, 0.57659349214159161,
      -0.26378129885382495, -1.1348093952257554, -1.4483505728618988,
      -1.3082156073095106, -0.52736438874367764, 0.34251022640530043,
      1.1776863456185624, 1.3891163551237387, 1.1157841607874102,
      0.23166386039969653, -0.65271161775992281, -1.387737810235822,
      -1.4122136545356458, -0.94159460122289873, 0.054865613210678128,
      0.89866841894857641, 1.4377782920915503, 1.1861164371024422,
      0.48448553721978238, -0.57809796556625614, -1.2712084867456279,
      -1.4933978018498197, -0.89941847316550183, 0.00063571317389858617,
      1.0031432322900675, 1.383815082681729, 1.1776863456184938,
      0.24969528350793502, -0.70929019286049255, -1.4420846460640118,
      -1.3395818493075733, -0.67504001566122385, 0.44112855696320113,
      1.1977487534104885, 1.4186191384097342, 0.750761239417685,
      -0.22772171010371833, -1.2171884794800896, -1.4483505728620525,
      -1.012687151539436, 0.082274052086257363, 1.003417058333492,
      1.4552406535776043, 0.94915579146909457, -0.0091463750542371183,
      -1.0964661689738009, -1.4557003793577761, -1.09322214542873,
      0.0091463750542701925, 0.97828942874420755, 1.4552406535776079,
      0.92264542876761824, -0.082274052086159427, -1.1709125679174339,
      -1.4483505728619452, -0.95586778969742048, 0.22772171010373748,
      1.1398074595249861, 1.4186191384096909, 0.65777542607126493,
      -0.441128556963233, -1.3874253382022863, -1.3395818493075586,
      -0.53912236934032642, 0.70929019286043271, 1.3557143673408407,
      1.1776863456185516, 0.069299394497803063, -1.0031432322900375,
      -1.5196003843927595, -0.8994184731653373, 0.21859014396947191,
      1.2712084867457221, 1.2971368801610454, 0.48448553721972903,
      -0.80836818550107781, -1.4377782920916191, -1.1558059937017391,
      0.054865613210712309, 1.0973507919455234, 1.4122136545356403,
      0.54407328518721021, -0.65271161775990993, -1.4903533300106746,
      -1.1157841607873353, -0.017347763618596933, 1.1776863456185336,
      1.3319081448120604, 0.52736438874380787, -0.82399721577629148,
      -1.4483505728620147, -1.0534714756143144, 0.26378129885388762,
      1.2409158650261194, 1.2928605654593295, 0.16013253784557754,
      -1.0293356096197728, -1.5027441788300062, -0.652711617759908,
      0.6138235218960022, 1.4430468946081112, 0.9228149046898616,
      -0.30861883034000726, -1.4093259735442574, -1.2241633474702651,
      -0.10874542139782474, 1.1776863456184534, 1.3035624181998031,
      0.35315179230064431, -1.0433095667486212, -1.4391807198677067,
      -0.67473631942089873, 0.77226533224887228, 1.390194070208346,
      0.81064404617697339, -0.64551110459008854, -1.4377782920915105,
      -1.0262364941764393, 0.41490264850177394, 1.3382244236869039,
      1.0674000856622352, -0.34926632480246078, -1.366515232702727,
      -1.2027706765318877, 0.19151828744054647, 1.2716163100927329,
      1.1776863456184938, -0.20453216467389448, -1.3210254210658261,
      -1.2575530865404105, 0.12788502014594888, 1.2567288735843483,
      1.1830392034670498, -0.22271944272960292, -1.3395818493076368,
      -1.2140749563800999, 0.22772171010384165, 1.3051676511105395,
      1.0858668083725471, -0.40284524517638037, -1.40766443257531,
      -1.0533700314648591, 0.48448553721977894, 1.3756173191281034,
      0.84822275230161681, -0.72814430378110673, -1.4557003793577414,
      -0.72406665993026242, 0.86302189801333284, 1.3691874920762994,
      0.41490264850180031, -1.1341786814550261, -1.3568162719938683,
      -0.18171476567685391, 1.2576136461436467, 1.1374750059650436,
      -0.22772171010372344, -1.4637532395295874, -0.955792133730518,
      0.531742271783323, 1.4556716450785845, 0.5442310794247488,
      -0.95579213373045468, -1.4572284819286119, -0.17336978113051607,
      1.1889377638356, 1.177686345618429, -0.3849871277058235,
      -1.4316015579893222, -0.8663253428214428, 0.81064404617689567,
      1.3625293640369607, 0.28175003406603955, -1.280626072237885,
      -1.1988167147811954, 0.25458668863814521, 1.4377782920915059,
      0.67384921579462809, -0.899418473165497, -1.4572102159097016,
      -0.10053070563090326, 1.2567951537577555, 1.0357827552401506,
      -0.66214397536376457, -1.4522249039620809, -0.46911622345693565,
      1.1776863456184616, 1.1375116912334364, -0.37086984202659834,
      -1.5162128252925446, -0.5865110513141335, 1.0037744305990637,
      1.2800210863197903, -0.31320158801883241, -1.4391807198676942,
      -0.72401124609260747, 1.0293356096196937, 1.2308254061005535,
      -0.23675098307184872, -1.5060254370005177, -0.62807072937389141,
      1.0037837872148778, 1.2576136461436005, -0.40277063155041032,
      -1.4533735152450185, -0.5561150905711989, 1.1776863456184452,
      1.0836615950725286, -0.54437255765692, -1.5123212096162606,
      -0.23675098307185632, 1.2568233290714976, 0.93492743087263375,
      -0.90032289616763428, -1.3665152327026466, 0.0741121056229236,
      1.4377782920916096, 0.51087302480934793, -1.155812124518004,
      -1.2026555538608998, 0.61151895421193647, 1.3625766771030725,
      0.054865613210758966, -1.4686527360028307, -0.69326013374393691,
      1.0282981079035971, 1.1776863456185247, -0.645374289899419,
      -1.4281738384265144, -0.09029803308360064, 1.4186191384097773,
      0.54429807097432825, -1.1722869947294523, -1.1433624156108992,
      0.74886982448239825, 1.3037221699553405, -0.22772171010379169,
      -1.5201927028930158, -0.30861883034018095, 1.2788759490001409,
      0.78771041199955483, -1.1340912351346777, -1.1558121245180675,
      0.614007701848837, 1.3815996183093282, -0.29511469811992835,
      -1.4557003793577274, -0.29059636992664156, 1.3872523889667498,
      0.57734027229214047, -1.198816714781195, -1.0532610982231179,
      0.92083262466729787, 1.1772526192293844, -0.58651105131411518,
      -1.4623880475344559, 0.22772171010373454, 1.3897819951310932,
      0.12788502014604453, -1.4901146684241171, -0.45852599615469036,
      1.2568606094400159, 0.74886982448242179, -1.2278493075923951,
      -0.98980839135173271, 0.89926488449688025, 1.1776863456184696,
      -0.80809878706098515, -1.3132367468838284, 0.44729542114839055,
      1.4004240464804367, -0.3491101507164826, -1.4453395841299956,
      0.0011729436113865619, 1.4552406535776004, 0.069602407758901835,
      -1.4377782920915687, -0.380432433966106, 1.4004240464804758,
      0.40857758912812986, -1.350082261542799, -0.67455370466484721,
      1.2928605654593, 0.65811543050002264, -1.2339650931322912,
      -0.88144074662813532, 1.1776863456184685, 0.82529446653957439,
      -1.1274443985450486, -1.0122447546015847, 1.08586680837258,
      0.92302638924031621, -1.0548778365160496, -1.0797841731971509,
      1.0357827552401679, 0.96261592124327677, -1.0293356096196602,
      -1.0928177213680061, 1.035782755240154, 0.94958237307251736,
      -1.0548778365160949, -1.0532281893650193, 1.085866808372546,
      0.88204295447695646, -1.1274443985450591, -0.95549626666421328,
      1.1776863456184978, 0.75123894650350476, -1.2339650931322566,
      -0.788317230624646, 1.2928605654594041, 0.54435190454009208,
      -1.3500822615426791, -0.53877938925276658, 1.4004240464805278,
      0.25023063384144423, -1.4377782920915381, -0.19980420788350894,
      1.4552406535776179, -0.13137474373597796, -1.4453395841300476,
      0.2189083505919418, 1.4004240464804341, -0.57749722127287739,
      -1.3132367468838542, 0.67789698693638678, 1.1776863456184803,
      -1.0294666846216265, -0.98980839135173526, 1.0976475074676413,
      0.74886982448236639, -1.3870624095647619, -0.45852599615477907,
      1.3599128682993886, 0.12788502014585112, -1.519983795255746,
      0.22772171010371484, 1.3321862474098451, -0.58651105131417092,
      -1.3074544193539035, 0.92083262466730031, 0.92305929809849574,
      -1.1988167147811595, -0.707542072416772, 1.3872523889667006,
      0.16039456980194708, -1.4557003793577612, 0.16491289799534806,
      1.3815996183092361, -0.74420950197335967, -1.1558121245181157,
      1.0038894350100847, 0.78771041199955338, -1.4090777491246156,
      -0.30861883034005144, 1.3899909027684587, -0.2277217101036676,
      -1.4339239700800257, 0.7488698244824, 1.0131606154862653,
      -1.1722869947295176, -0.67449987109899989, 1.418619138409752,
      -0.0399037670410758, -1.4281738384265648, 0.51517248977477759,
      1.1776863456184279, -1.1584999080283276, -0.69326013374405726,
      1.3384509358780849, 0.054865613210692235, -1.4927784772278314,
      0.61151895421183255, 1.0724537537362147, -1.1558121245180575,
      -0.64107482493411072, 1.4377782920916458, -0.20431390574770464,
      -1.36651523270265, 0.7701210960429653, 0.93492743087268049,
      -1.3870251291961482, -0.23675098307184089, 1.382119409491706,
      -0.544372557656904, -1.2138633951971021, 1.1776863456184858,
      0.42591329044654, -1.4533735152449072, 0.27256883142569083,
      1.2576136461437066, -1.1339855873395659, -0.62807072937388875,
      1.3758236368757704, -0.2367509830718528, -1.361027206225252,
      1.0293356096197301, 0.59380944596800334, -1.4391807198677187,
      0.18299978789420587, 1.2800210863198915, -1.1339762307236698,
      -0.58651105131402725, 1.3860110251679174, -0.370869842026528,
      -1.2677134913580177, 1.1776863456184294, 0.33891442333237431,
      -1.4522249039621558, 0.5319421752391521, 1.0357827552401526,
      -1.3869969538825058, -0.10053070563081196, 1.327008415785019,
      -0.89941847316541779, -0.80405101591920958, 1.4377782920915869,
      -0.3847884887628078, -1.1988167147811117, 1.1504242721133169,
      0.28175003406601756, -1.4927311641614709, 0.81064404617697638,
      0.73612354269675639, -1.4316015579892107, 0.25478532758125305,
      1.1776863456184854, -1.3191395639603036, -0.17336978113045745,
      1.3270266818039349, -0.95579213373053828, -0.67443287954935727,
      1.4556716450785707, -0.66194407190811844, -0.95579213373033323,
      1.3335514394049581, -0.2277217101037346, -1.2676768060896195,
      1.257613646143604, 0.051512965552237368, -1.3568162719937695,
      1.0039768813304011, 0.4149026485017856, -1.4993892922009791,
      0.86302189801334028, 0.59386485980554371, -1.4557003793577477,
      0.59794250365651969, 0.84822275230168265, -1.5058191192527788,
      0.4844855372199377, 0.92316823134012027, -1.4076644325752481,
      0.27264344505173266, 1.0858668083725367, -1.4353694512352848,
      0.22772171010371353, 1.0838731562553903, -1.3395818493076328,
      0.092517642605166345, 1.1830392034669606, -1.3869306737089961,
      0.12788502014600911, 1.1273512864157602, -1.3210254210657222,
      0.074330364549315908, 1.1776863456184214, -1.4018181102174172,
      0.19151828744069138, 1.0725688764072507, -1.3665152327027343,
      0.21906452467786056, 1.0674000856623069, -1.4684262238115902,
      0.41490264850191649, 0.89603469405174252, -1.4377782920916045,
      0.51530930446543832, 0.8106440461769221, -1.5203958703330613,
      0.77226533224885685, 0.54453451929626651, -1.4391807198676698,
      0.91310776662404813, 0.35315179230078103, -1.4337642183244119,
      1.1776863456185114, -0.021456378726847185, -1.224163347470278,
      1.2791241734196717, -0.30861883034028342, -1.0530167048143884,
      1.4430468946080341, -0.74402532202059068, -0.65271161775996078,
      1.3725423787054358, -1.029335609619747, -0.29033433797008151,
      1.2928605654592347, -1.3711176651507677, 0.26378129885381613,
      0.92326967548964889, -1.4483505728620656, 0.69379541565160563,
      0.52736438874375846, -1.4621099449367405, 1.1776863456185143,
      -0.112854036506226, -1.1157841607872996, 1.3601515298859117,
      -0.65271161775992592, -0.67427508531180935, 1.4122136545356974,
      -1.2275525920702057, 0.054865613210736186, 1.0256041935771123,
      -1.43777829209165, 0.67816638537666762, 0.48448553721962528,
      -1.4273386802856318, 1.2712084867456805, -0.34879194409423425,
      -0.89941847316536472, 1.3893985842680106, -1.003143232290145,
      -0.19950119462253013, 1.1776863456184736, -1.4859161674655328,
      0.70929019286054074, 0.40892056921564224, -1.3395818493075489,
      1.2572235380776606, -0.44112855696326947, -0.78797722619582544,
      1.4186191384097382, -1.2700092596496475, 0.22772171010373671,
      0.82566598957261794, -1.4483505728620081, 1.0407107677927065,
      -0.082274052086266744, -1.0528472288922452, 1.45524065357764,
      -1.1084912288689051, 0.0091463750543167958, 0.96302034530398273,
      -1.455700379357745, 0.96626436884927847, -0.0091463750543276968,
      -1.0793575915936617, 1.4552406535775826, -1.1336188584580891,
      0.082274052086226443, 0.88248535141478046, -1.4483505728620867,
      1.0869866793555272, -0.22772171010377112, -0.88096303954227606,
      1.4186191384097468, -1.3279505535351761, 0.44112855696327719,
      0.5448382155364907, -1.3395818493075224, 1.3118828459393999,
      -0.70929019286055672, -0.37989708363247648, 1.1776863456184044,
      -1.5140168828063767, 1.003143232290137, -0.13083751329847434,
      -0.89941847316540169, 1.3631960017252014, -1.27120848674571,
      0.44789616544159871, 0.48448553721974807, -1.316318237227059,
      1.4377782920915738, -1.0288702190732404, 0.05486561321074937,
      0.81139280109818979, -1.4122136545356749, 1.2575360101111894,
      -0.6527116177599992, -0.36186566052418156, 1.1157841607873515,
      -1.5193181552484447, 1.1776863456185462, -0.47271202653016109,
      -0.52736438874365266, 1.1780138071847031, -1.4483505728620631,
      1.0046075951010478, -0.26378129885393331, -0.70679529226608551,
      1.2928605654592518, -1.5024334061008815, 1.0293356096197015,
      -0.29425426288362916, -0.65271161775987208, 1.2233177851551775,
      -1.4430468946080524, 1.004731869550199, -0.3086188303401356,
      -0.62337797299980258, 1.2241633474701847, -1.5192166310667587,
      1.1776863456183744, -0.55938585090982362, -0.35315179230085608,
      1.0141164513281435, -1.4391807198676618, 1.2579150505505554,
      -0.77226533224885985, -0.089186215913422476, 0.81064404617691777,
      -1.3990646833865563, 1.4377782920915527, -1.1574087855105366,
      0.41490264850178504, 0.32240359072949965, -1.0674000856623684,
      1.3638491194125963, -1.3665152327029224, 0.84454305364511262,
      -0.19151828744066315, -0.63982117870918676, 1.1776863456185318,
      -1.5127677514495259, 1.3210254210658088, -0.89885876158396028,
      0.1278850201459926, 0.545799916723219, -1.1830392034670683,
      1.3835698132874794, -1.3395818493076503, 0.830483329580988,
      -0.22772171010383632, -0.55442007705301821, 1.0858668083724969,
      -1.4794192399600732, 1.4076644325752956, -1.1322949342119526,
      0.48448553721983212, 0.14410218589222856, -0.84822275230166078,
      1.2328012777773198, -1.4557003793577841, 1.234955229690764,
      -0.86302189801333684, 0.18498659299551695, 0.414902648501638,
      -1.0510817449771506, 1.3568162719936807, -1.5138915691857173,
      1.2576136461436593, -0.8828783813763631, 0.22772171010373191,
      0.3412701605911389, -0.9557921337303471, 1.265116654566788,
      -1.455671645078475, 1.2595462288027981, -0.955792133730412,
      0.36353198918392482, 0.17336978113049767, -0.80123025154079164,
      1.1776863456183291, -1.4821923719576962, 1.4316015579891641,
      -1.2773330412704402, 0.81064404617693675, -0.34574288129896963,
      -0.281750034065993, 0.73953819614536, -1.1988167147810709,
      1.3587331781044041, -1.43777829209162, 1.1929241454707431,
      -0.8994184731655066, 0.36482849652080546, 0.10053070563079644,
      -0.6702485434831269, 1.0357827552400485, -1.3882450143155185,
      1.4522249039620709, -1.4588653551808586, 1.17768634561858,
      -0.88018011068225244, 0.37086984202668194, 0.056711410363106618,
      -0.58651105131402959, 0.92865502886818641, -1.280021086319902,
      1.3752689087339929, -1.4391807198678228, 1.2392833559104064,
      -1.0293356096198547, 0.60450216853350458, -0.23675098307193798,
      -0.26536775372710247, 0.62807072937388531, -1.0456760858601803,
      1.2576136461436973, -1.4730703442159516, 1.4533735152450495,
      -1.4269439427535768, 1.1776863456184183, -0.94997043586982688,
      0.54437255765680381, -0.21279669682045491, -0.23675098307188724,
      0.55479723929565394, -0.93492743087262375, 1.1383954941810974,
      -1.366515232702662, 1.3959424825157043, -1.437778292091487,
      1.2846993780919198, -1.1558121245181248, 0.85718397020424575,
      -0.61151895421185354, 0.23388296054012553, 0.054865613210535805,
      -0.43523691872232451, 0.69326013374395412, -1.0085425982945573,
      1.1776863456183679, -1.3811858199949796, 1.4281738384264413,
      -1.499974434293907, 1.4186191384097075, -1.3646644747278753,
      1.1722869947295187, -1.0186734184800681, 0.74886982448237061,
      -0.53365800214801551, 0.22772171010375114, 0.0075572742070260622,
      -0.30861883034006332, 0.52613467615250908, -0.78771041199959346,
      0.9582655586711365, -1.1558121245179875, 1.2612903248241041,
      -1.3815996183093255, 1.4151962947585519, -1.4557003793577941,
      1.4205000555140115, -1.387252388966794, 1.2938224551825153,
      -1.1988167147813031, 1.062441968017799, -0.92083262466735216,
      0.75888051610009921, -0.586511051314065, 0.41624793360425388,
      -0.22772171010379758, 0.064736670994190865, 0.1278850201458468,
      -0.27062498991138861, 0.45852599615470968, -0.57105735262997093,
      0.74886982448235218, -0.8241689822393431, 0.98980839135184451,
      -1.0234189845169082, 1.1776863456184556, -1.1671656637555923,
      1.3132367468837751, -1.2575283131315891, 1.4004240464805091,
      -1.2992358042916305, 1.4453395841299379, -1.2985796232401934,
      1.4552406535776168, -1.2625385681734598, 1.4377782920915385,
      -1.1981019353076048, 1.4004240464805029, -1.1117890274721534,
      1.3500822615426913, -1.0093445368302685, 1.2928605654592793,
      -0.8955799642523784, 1.2339650931322539, -0.77432851183227314,
      1.1776863456184916, -0.64848264009609913, 1.1274443985451252,
      -0.52008784874624892, 1.0858668083725425, -0.39047176930888561,
      1.0548778365160858, -0.2603933200625505, 1.0357827552401586,
      -0.13020180012464427, 1.0293356096196626, 4.0590492605963612E-14,
      1.035782755240044, 0.13019151993794872, 1.0548778365160583,
      0.26026996918415751, 1.0858668083725957, 0.38988604862150356,
      1.1274443985450744, 0.51828083997134644, 1.177686345618504,
      0.64412671170758262, 1.2339650931322783, 0.76537816412775173,
      1.2928605654592691, 0.87914273670568588, 1.3500822615427905,
      0.98158722734754988, 1.4004240464805378, 1.0679001351829045,
      1.4377782920916087, 1.1323367680488143, 1.4552406535777005,
      1.1683778231154796, 1.4453395841300156, 1.1690340041670173,
      1.4004240464805431, 1.1273265130069039, 1.3132367468838106,
      1.0369638636309571, 1.1776863456184878, 0.89321718439226583,
      0.98980839135177612, 0.69396718211468245, 0.748869824482328,
      0.44085555250542841, 0.45852599615477618, 0.14042318978684099,
      0.12788502014596068, -0.19493847111874318, -0.22772171010366385,
      -0.54644973372888417, -0.58651105131397929, -0.889082316224844,
      -0.92083262466724469, -1.1926437681423814, -1.19881671478117,
      -1.4240242553070055, -1.3872523889667707, -1.5507018556385745,
      -1.455700379357697, -1.5453980948832262, -1.3815996183092807,
      -1.3914921249488947, -1.1558121245179864, -1.0884673587958802,
      -0.787710411999592, -0.65633647627721792, -0.30861883034004162,
      -0.13775907433169526, 0.22772171010368611, 0.40345620202328109,
      0.74886982448244488, 0.88847161835529953, 1.1722869947295302,
      1.2344626746031391, 1.4186191384097977, 1.3697726341693002,
      1.4281738384265719, 1.2509840198704123, 1.177686345618479,
      0.87834079817005228, 0.69326013374399176, 0.30503511859788274,
      0.054865613210687093, -0.36408476066473267, -0.61151895421178737,
      -0.98738577032891583, -1.155812124518002, -1.4149011782165808,
      -1.4377782920915374, -1.5261442826405069, -1.3665152327026746,
      -1.2685972943057309, -0.93492743087270214, -0.68499903942032536,
      -0.23675098307180525, 0.082594896695794048, 0.5443725576568661,
      0.81976863574522707, 1.1776863456184377, 1.2967421426289536,
      1.4533735152450413, 1.3428685440911681, 1.2576136461436609,
      0.91547428573555367, 0.62807072937396113, 0.13516595360252823,
      -0.23675098307178982, -0.734703968658123, -1.0293356096196526,
      -1.3694851560349126, -1.4391807198676174, -1.5054707088585906,
      -1.2800210863198282, -1.0588568289927562, -0.586511051314125,
      -0.18691321048778273, 0.37086984202646028, 0.74997831055754538,
      1.177686345618469, 1.3286635550561614, 1.4522249039620285,
      1.2580432141909075, 1.0357827552401584, 0.54004674335855418,
      0.10053070563096483, -0.49503029664539017, -0.89941847316540879,
      -1.3231259455953868, -1.437778292091489, -1.4889349782291028,
      -1.1988167147811311, -0.86973999627013254, -0.28175003406614157,
      0.21554108117423046, 0.81064404617692087, 1.1471312411458672,
      1.4316015579892569, 1.3519905718332028, 1.1776863456184279,
      0.67102845141625389, 0.1733697811305229, -0.49373378930857903,
      -0.95579213373044536, -1.3897480289275539, -1.4556716450784986,
      -1.3953184546915511, -0.95579213373041827, -0.47147196071595832,
      0.22772171010376285, 0.75267658125167747, 1.2576136461436522,
      1.3836897690610948, 1.3568162719938555, 0.92087994485261393,
      0.414902648501887, -0.31518839312013824, -0.86302189801317264,
      -1.3651570298154858, -1.4557003793576759, -1.3630030779019859,
      -0.84822275230162525, -0.27430398601701145, 0.484485537219845,
      1.0020931340872583, 1.4076644325753227, 1.3492174398353682,
      1.0858668083725245, 0.42421827692848363, -0.22772171010367373,
      -0.96068512970551045, -1.3395818493075793, -1.5137716134121004,
      -1.1830392034670809, -0.6760017168478718, 0.12788502014594957,
      0.76865696145923246, 1.3210254210656935, 1.3825659513249009,
      1.1776863456184838, 0.509619378584437, -0.19151828744050023,
      -0.97474485376967723, -1.3665152327026242, -1.4940509195371137,
      -1.0674000856622183, -0.45260539085422774, 0.41490264850194564,
      1.0272069853858299, 1.4377782920916038, 1.2688628832619235,
      0.810644046176871, -0.041015584211126881, -0.77226533224888416,
      -1.3881168506751831, -1.4391807198676907, -1.1443182514527785,
      -0.35315179230074978, 0.4291840507853068, 1.1776863456184803,
      1.3890148309421508, 1.2241633474703162, 0.49317617287522708,
      -0.30861883034005011, -1.1349336696748449, -1.4430468946081263,
      -1.353519585279864, -0.65271161775993114, 0.16405246275899521,
      1.0293356096197122, 1.3722316059762065, 1.2928605654593059,
      0.57659349214159161, -0.26378129885382495, -1.1348093952257554,
      -1.4483505728618988, -1.3082156073095106, -0.52736438874367764,
      0.34251022640530043, 1.1776863456185624, 1.3891163551237387,
      1.1157841607874102, 0.23166386039969653, -0.65271161775992281,
      -1.387737810235822, -1.4122136545356458, -0.94159460122289873,
      0.054865613210678128, 0.89866841894857641, 1.4377782920915503,
      1.1861164371024422, 0.48448553721978238, -0.57809796556625614,
      -1.2712084867456279, -1.4933978018498197, -0.89941847316550183,
      0.00063571317389858617, 1.0031432322900675, 1.383815082681729,
      1.1776863456184938, 0.24969528350793502, -0.70929019286049255,
      -1.4420846460640118, -1.3395818493075733, -0.67504001566122385,
      0.44112855696320113, 1.1977487534104885, 1.4186191384097342,
      0.750761239417685, -0.22772171010371833, -1.2171884794800896,
      -1.4483505728620525, -1.012687151539436, 0.082274052086257363,
      1.003417058333492, 1.4552406535776043, 0.94915579146909457,
      -0.0091463750542371183, -1.0964661689738009, -1.4557003793577761,
      -1.09322214542873, 0.0091463750542701925, 0.97828942874420755,
      1.4552406535776079, 0.92264542876761824, -0.082274052086159427,
      -1.1709125679174339, -1.4483505728619452, -0.95586778969742048,
      0.22772171010373748, 1.1398074595249861, 1.4186191384096909,
      0.65777542607126493, -0.441128556963233, -1.3874253382022863,
      -1.3395818493075586, -0.53912236934032642, 0.70929019286043271,
      1.3557143673408407, 1.1776863456185516, 0.069299394497803063,
      -1.0031432322900375, -1.5196003843927595, -0.8994184731653373,
      0.21859014396947191, 1.2712084867457221, 1.2971368801610454,
      0.48448553721972903, -0.80836818550107781, -1.4377782920916191,
      -1.1558059937017391, 0.054865613210712309, 1.0973507919455234,
      1.4122136545356403, 0.54407328518721021, -0.65271161775990993,
      -1.4903533300106746, -1.1157841607873353, -0.017347763618596933,
      1.1776863456185336, 1.3319081448120604, 0.52736438874380787,
      -0.82399721577629148, -1.4483505728620147, -1.0534714756143144,
      0.26378129885388762, 1.2409158650261194, 1.2928605654593295,
      0.16013253784557754, -1.0293356096197728, -1.5027441788300062,
      -0.652711617759908, 0.6138235218960022, 1.4430468946081112,
      0.9228149046898616, -0.30861883034000726, -1.4093259735442574,
      -1.2241633474702651, -0.10874542139782474, 1.1776863456184534,
      1.3035624181998031, 0.35315179230064431, -1.0433095667486212,
      -1.4391807198677067, -0.67473631942089873, 0.77226533224887228,
      1.390194070208346, 0.81064404617697339, -0.64551110459008854,
      -1.4377782920915105, -1.0262364941764393, 0.41490264850177394,
      1.3382244236869039, 1.0674000856622352, -0.34926632480246078,
      -1.366515232702727, -1.2027706765318877, 0.19151828744054647,
      1.2716163100927329, 1.1776863456184938, -0.20453216467389448,
      -1.3210254210658261, -1.2575530865404105, 0.12788502014594888,
      1.2567288735843483, 1.1830392034670498, -0.22271944272960292,
      -1.3395818493076368, -1.2140749563800999, 0.22772171010384165,
      1.3051676511105395, 1.0858668083725471, -0.40284524517638037,
      -1.40766443257531, -1.0533700314648591, 0.48448553721977894,
      1.3756173191281034, 0.84822275230161681, -0.72814430378110673,
      -1.4557003793577414, -0.72406665993026242, 0.86302189801333284,
      1.3691874920762994, 0.41490264850180031, -1.1341786814550261,
      -1.3568162719938683, -0.18171476567685391, 1.2576136461436467,
      1.1374750059650436, -0.22772171010372344, -1.4637532395295874,
      -0.955792133730518, 0.531742271783323, 1.4556716450785845,
      0.5442310794247488, -0.95579213373045468, -1.4572284819286119,
      -0.17336978113051607, 1.1889377638356, 1.177686345618429,
      -0.3849871277058235, -1.4316015579893222, -0.8663253428214428,
      0.81064404617689567, 1.3625293640369607, 0.28175003406603955,
      -1.280626072237885, -1.1988167147811954, 0.25458668863814521,
      1.4377782920915059, 0.67384921579462809, -0.899418473165497,
      -1.4572102159097016, -0.10053070563090326, 1.2567951537577555,
      1.0357827552401506, -0.66214397536376457, -1.4522249039620809,
      -0.46911622345693565, 1.1776863456184616, 1.1375116912334364,
      -0.37086984202659834, -1.5162128252925446, -0.5865110513141335,
      1.0037744305990637, 1.2800210863197903, -0.31320158801883241,
      -1.4391807198676942, -0.72401124609260747, 1.0293356096196937,
      1.2308254061005535, -0.23675098307184872, -1.5060254370005177,
      -0.62807072937389141, 1.0037837872148778, 1.2576136461436005,
      -0.40277063155041032, -1.4533735152450185, -0.5561150905711989,
      1.1776863456184452, 1.0836615950725286, -0.54437255765692,
      -1.5123212096162606, -0.23675098307185632, 1.2568233290714976,
      0.93492743087263375, -0.90032289616763428, -1.3665152327026466,
      0.0741121056229236, 1.4377782920916096, 0.51087302480934793,
      -1.155812124518004, -1.2026555538608998, 0.61151895421193647,
      1.3625766771030725, 0.054865613210758966, -1.4686527360028307,
      -0.69326013374393691, 1.0282981079035971, 1.1776863456185247,
      -0.645374289899419, -1.4281738384265144, -0.09029803308360064,
      1.4186191384097773, 0.54429807097432825, -1.1722869947294523,
      -1.1433624156108992, 0.74886982448239825, 1.3037221699553405,
      -0.22772171010379169, -1.5201927028930158, -0.30861883034018095,
      1.2788759490001409, 0.78771041199955483, -1.1340912351346777,
      -1.1558121245180675, 0.614007701848837, 1.3815996183093282,
      -0.29511469811992835, -1.4557003793577274, -0.29059636992664156,
      1.3872523889667498, 0.57734027229214047, -1.198816714781195,
      -1.0532610982231179, 0.92083262466729787, 1.1772526192293844,
      -0.58651105131411518, -1.4623880475344559, 0.22772171010373454,
      1.3897819951310932, 0.12788502014604453, -1.4901146684241171,
      -0.45852599615469036, 1.2568606094400159, 0.74886982448242179,
      -1.2278493075923951, -0.98980839135173271, 0.89926488449688025,
      1.1776863456184696, -0.80809878706098515, -1.3132367468838284,
      0.44729542114839055, 1.4004240464804367, -0.3491101507164826,
      -1.4453395841299956, 0.0011729436113865619, 1.4552406535776004,
      0.069602407758901835, -1.4377782920915687, -0.380432433966106,
      1.4004240464804758, 0.40857758912812986, -1.350082261542799,
      -0.67455370466484721, 1.2928605654593, 0.65811543050002264,
      -1.2339650931322912, -0.88144074662813532, 1.1776863456184685,
      0.82529446653957439, -1.1274443985450486, -1.0122447546015847,
      1.08586680837258, 0.92302638924031621, -1.0548778365160496,
      -1.0797841731971509, 1.0357827552401679, 0.96261592124327677,
      -1.0293356096196602, -1.0928177213680061, 1.035782755240154,
      0.94958237307251736, -1.0548778365160949, -1.0532281893650193,
      1.085866808372546, 0.88204295447695646, -1.1274443985450591,
      -0.95549626666421328, 1.1776863456184978, 0.75123894650350476,
      -1.2339650931322566, -0.788317230624646, 1.2928605654594041,
      0.54435190454009208, -1.3500822615426791, -0.53877938925276658,
      1.4004240464805278, 0.25023063384144423, -1.4377782920915381,
      -0.19980420788350894, 1.4552406535776179, -0.13137474373597796,
      -1.4453395841300476, 0.2189083505919418, 1.4004240464804341,
      -0.57749722127287739, -1.3132367468838542, 0.67789698693638678,
      1.1776863456184803, -1.0294666846216265, -0.98980839135173526,
      1.0976475074676413, 0.74886982448236639, -1.3870624095647619,
      -0.45852599615477907, 1.3599128682993886, 0.12788502014585112,
      -1.519983795255746, 0.22772171010371484, 1.3321862474098451,
      -0.58651105131417092, -1.3074544193539035, 0.92083262466730031,
      0.92305929809849574, -1.1988167147811595, -0.707542072416772,
      1.3872523889667006, 0.16039456980194708, -1.4557003793577612,
      0.16491289799534806, 1.3815996183092361, -0.74420950197335967,
      -1.1558121245181157, 1.0038894350100847, 0.78771041199955338,
      -1.4090777491246156, -0.30861883034005144, 1.3899909027684587,
      -0.2277217101036676, -1.4339239700800257, 0.7488698244824,
      1.0131606154862653, -1.1722869947295176, -0.67449987109899989,
      1.418619138409752, -0.0399037670410758, -1.4281738384265648,
      0.51517248977477759, 1.1776863456184279, -1.1584999080283276,
      -0.69326013374405726, 1.3384509358780849, 0.054865613210692235,
      -1.4927784772278314, 0.61151895421183255, 1.0724537537362147,
      -1.1558121245180575, -0.64107482493411072, 1.4377782920916458,
      -0.20431390574770464, -1.36651523270265, 0.7701210960429653,
      0.93492743087268049, -1.3870251291961482, -0.23675098307184089,
      1.382119409491706, -0.544372557656904, -1.2138633951971021,
      1.1776863456184858, 0.42591329044654, -1.4533735152449072,
      0.27256883142569083, 1.2576136461437066, -1.1339855873395659,
      -0.62807072937388875, 1.3758236368757704, -0.2367509830718528,
      -1.361027206225252, 1.0293356096197301, 0.59380944596800334,
      -1.4391807198677187, 0.18299978789420587, 1.2800210863198915,
      -1.1339762307236698, -0.58651105131402725, 1.3860110251679174,
      -0.370869842026528, -1.2677134913580177, 1.1776863456184294,
      0.33891442333237431, -1.4522249039621558, 0.5319421752391521,
      1.0357827552401526, -1.3869969538825058, -0.10053070563081196,
      1.327008415785019, -0.89941847316541779, -0.80405101591920958,
      1.4377782920915869, -0.3847884887628078, -1.1988167147811117,
      1.1504242721133169, 0.28175003406601756, -1.4927311641614709,
      0.81064404617697638, 0.73612354269675639, -1.4316015579892107,
      0.25478532758125305, 1.1776863456184854, -1.3191395639603036,
      -0.17336978113045745, 1.3270266818039349, -0.95579213373053828,
      -0.67443287954935727, 1.4556716450785707, -0.66194407190811844,
      -0.95579213373033323, 1.3335514394049581, -0.2277217101037346,
      -1.2676768060896195, 1.257613646143604, 0.051512965552237368,
      -1.3568162719937695, 1.0039768813304011, 0.4149026485017856,
      -1.4993892922009791, 0.86302189801334028, 0.59386485980554371,
      -1.4557003793577477, 0.59794250365651969, 0.84822275230168265,
      -1.5058191192527788, 0.4844855372199377, 0.92316823134012027,
      -1.4076644325752481, 0.27264344505173266, 1.0858668083725367,
      -1.4353694512352848, 0.22772171010371353, 1.0838731562553903,
      -1.3395818493076328, 0.092517642605166345, 1.1830392034669606,
      -1.3869306737089961, 0.12788502014600911, 1.1273512864157602,
      -1.3210254210657222, 0.074330364549315908, 1.1776863456184214,
      -1.4018181102174172, 0.19151828744069138, 1.0725688764072507,
      -1.3665152327027343, 0.21906452467786056, 1.0674000856623069,
      -1.4684262238115902, 0.41490264850191649, 0.89603469405174252,
      -1.4377782920916045, 0.51530930446543832, 0.8106440461769221,
      -1.5203958703330613, 0.77226533224885685, 0.54453451929626651,
      -1.4391807198676698, 0.91310776662404813, 0.35315179230078103,
      -1.4337642183244119, 1.1776863456185114, -0.021456378726847185,
      -1.224163347470278, 1.2791241734196717, -0.30861883034028342,
      -1.0530167048143884, 1.4430468946080341, -0.74402532202059068,
      -0.65271161775996078, 1.3725423787054358, -1.029335609619747,
      -0.29033433797008151, 1.2928605654592347, -1.3711176651507677,
      0.26378129885381613, 0.92326967548964889, -1.4483505728620656,
      0.69379541565160563, 0.52736438874375846, -1.4621099449367405,
      1.1776863456185143, -0.112854036506226, -1.1157841607872996,
      1.3601515298859117, -0.65271161775992592, -0.67427508531180935,
      1.4122136545356974, -1.2275525920702057, 0.054865613210736186,
      1.0256041935771123, -1.43777829209165, 0.67816638537666762,
      0.48448553721962528, -1.4273386802856318, 1.2712084867456805,
      -0.34879194409423425, -0.89941847316536472, 1.3893985842680106,
      -1.003143232290145, -0.19950119462253013, 1.1776863456184736,
      -1.4859161674655328, 0.70929019286054074, 0.40892056921564224,
      -1.3395818493075489, 1.2572235380776606, -0.44112855696326947,
      -0.78797722619582544, 1.4186191384097382, -1.2700092596496475,
      0.22772171010373671, 0.82566598957261794, -1.4483505728620081,
      1.0407107677927065, -0.082274052086266744, -1.0528472288922452,
      1.45524065357764, -1.1084912288689051, 0.0091463750543167958,
      0.96302034530398273, -1.455700379357745, 0.96626436884927847,
      -0.0091463750543276968, -1.0793575915936617, 1.4552406535775826,
      -1.1336188584580891, 0.082274052086226443, 0.88248535141478046,
      -1.4483505728620867, 1.0869866793555272, -0.22772171010377112,
      -0.88096303954227606, 1.4186191384097468, -1.3279505535351761,
      0.44112855696327719, 0.5448382155364907, -1.3395818493075224,
      1.3118828459393999, -0.70929019286055672, -0.37989708363247648,
      1.1776863456184044, -1.5140168828063767, 1.003143232290137,
      -0.13083751329847434, -0.89941847316540169, 1.3631960017252014,
      -1.27120848674571, 0.44789616544159871, 0.48448553721974807,
      -1.316318237227059, 1.4377782920915738, -1.0288702190732404,
      0.05486561321074937, 0.81139280109818979, -1.4122136545356749,
      1.2575360101111894, -0.6527116177599992, -0.36186566052418156,
      1.1157841607873515, -1.5193181552484447, 1.1776863456185462,
      -0.47271202653016109, -0.52736438874365266, 1.1780138071847031,
      -1.4483505728620631, 1.0046075951010478, -0.26378129885393331,
      -0.70679529226608551, 1.2928605654592518, -1.5024334061008815,
      1.0293356096197015, -0.29425426288362916, -0.65271161775987208,
      1.2233177851551775, -1.4430468946080524, 1.004731869550199,
      -0.3086188303401356, -0.62337797299980258, 1.2241633474701847,
      -1.5192166310667587, 1.1776863456183744, -0.55938585090982362,
      -0.35315179230085608, 1.0141164513281435, -1.4391807198676618,
      1.2579150505505554, -0.77226533224885985, -0.089186215913422476,
      0.81064404617691777, -1.3990646833865563, 1.4377782920915527,
      -1.1574087855105366, 0.41490264850178504, 0.32240359072949965,
      -1.0674000856623684, 1.3638491194125963, -1.3665152327029224,
      0.84454305364511262, -0.19151828744066315, -0.63982117870918676,
      1.1776863456185318, -1.5127677514495259, 1.3210254210658088,
      -0.89885876158396028, 0.1278850201459926, 0.545799916723219,
      -1.1830392034670683, 1.3835698132874794, -1.3395818493076503,
      0.830483329580988, -0.22772171010383632, -0.55442007705301821,
      1.0858668083724969, -1.4794192399600732, 1.4076644325752956,
      -1.1322949342119526, 0.48448553721983212, 0.14410218589222856,
      -0.84822275230166078, 1.2328012777773198, -1.4557003793577841,
      1.234955229690764, -0.86302189801333684, 0.18498659299551695,
      0.414902648501638, -1.0510817449771506, 1.3568162719936807,
      -1.5138915691857173, 1.2576136461436593, -0.8828783813763631,
      0.22772171010373191, 0.3412701605911389, -0.9557921337303471,
      1.265116654566788, -1.455671645078475, 1.2595462288027981,
      -0.955792133730412, 0.36353198918392482, 0.17336978113049767,
      -0.80123025154079164, 1.1776863456183291, -1.4821923719576962,
      1.4316015579891641, -1.2773330412704402, 0.81064404617693675,
      -0.34574288129896963, -0.281750034065993, 0.73953819614536,
      -1.1988167147810709, 1.3587331781044041, -1.43777829209162,
      1.1929241454707431, -0.8994184731655066, 0.36482849652080546,
      0.10053070563079644, -0.6702485434831269, 1.0357827552400485,
      -1.3882450143155185, 1.4522249039620709, -1.4588653551808586,
      1.17768634561858, -0.88018011068225244, 0.37086984202668194,
      0.056711410363106618, -0.58651105131402959, 0.92865502886818641,
      -1.280021086319902, 1.3752689087339929, -1.4391807198678228,
      1.2392833559104064, -1.0293356096198547, 0.60450216853350458,
      -0.23675098307193798, -0.26536775372710247, 0.62807072937388531,
      -1.0456760858601803, 1.2576136461436973, -1.4730703442159516,
      1.4533735152450495, -1.4269439427535768, 1.1776863456184183,
      -0.94997043586982688, 0.54437255765680381, -0.21279669682045491,
      -0.23675098307188724, 0.55479723929565394, -0.93492743087262375,
      1.1383954941810974, -1.366515232702662, 1.3959424825157043,
      -1.437778292091487, 1.2846993780919198, -1.1558121245181248,
      0.85718397020424575, -0.61151895421185354, 0.23388296054012553,
      0.054865613210535805, -0.43523691872232451, 0.69326013374395412,
      -1.0085425982945573, 1.1776863456183679, -1.3811858199949796,
      1.4281738384264413, -1.499974434293907, 1.4186191384097075,
      -1.3646644747278753, 1.1722869947295187, -1.0186734184800681,
      0.74886982448237061, -0.53365800214801551, 0.22772171010375114,
      0.0075572742070260622, -0.30861883034006332, 0.52613467615250908,
      -0.78771041199959346, 0.9582655586711365, -1.1558121245179875,
      1.2612903248241041, -1.3815996183093255, 1.4151962947585519,
      -1.4557003793577941, 1.4205000555140115, -1.387252388966794,
      1.2938224551825153, -1.1988167147813031, 1.062441968017799,
      -0.92083262466735216, 0.75888051610009921, -0.586511051314065,
      0.41624793360425388, -0.22772171010379758, 0.064736670994190865,
      0.1278850201458468, -0.27062498991138861, 0.45852599615470968,
      -0.57105735262997093, 0.74886982448235218, -0.8241689822393431,
      0.98980839135184451, -1.0234189845169082, 1.1776863456184556,
      -1.1671656637555923, 1.3132367468837751, -1.2575283131315891,
      1.4004240464805091, -1.2992358042916305, 1.4453395841299379,
      -1.2985796232401934, 1.4552406535776168, -1.2625385681734598,
      1.4377782920915385, -1.1981019353076048, 1.4004240464805029,
      -1.1117890274721534, 1.3500822615426913, -1.0093445368302685,
      1.2928605654592793, -0.8955799642523784, 1.2339650931322539,
      -0.77432851183227314, 1.1776863456184916, -0.64848264009609913,
      1.1274443985451252, -0.52008784874624892, 1.0858668083725425,
      -0.39047176930888561, 1.0548778365160858, -0.2603933200625505,
      1.0357827552401586, -0.13020180012464427, 1.0293356096196626,
      4.0590492605963612E-14, 1.035782755240044, 0.13019151993794872,
      1.0548778365160583, 0.26026996918415751, 1.0858668083725957,
      0.38988604862150356, 1.1274443985450744, 0.51828083997134644,
      1.177686345618504, 0.64412671170758262, 1.2339650931322783,
      0.76537816412775173, 1.2928605654592691, 0.87914273670568588,
      1.3500822615427905, 0.98158722734754988, 1.4004240464805378,
      1.0679001351829045, 1.4377782920916087, 1.1323367680488143,
      1.4552406535777005, 1.1683778231154796, 1.4453395841300156,
      1.1690340041670173, 1.4004240464805431, 1.1273265130069039,
      1.3132367468838106, 1.0369638636309571, 1.1776863456184878,
      0.89321718439226583, 0.98980839135177612, 0.69396718211468245,
      0.748869824482328, 0.44085555250542841, 0.45852599615477618,
      0.14042318978684099, 0.12788502014596068, -0.19493847111874318,
      -0.22772171010366385, -0.54644973372888417, -0.58651105131397929,
      -0.889082316224844, -0.92083262466724469, -1.1926437681423814,
      -1.19881671478117, -1.4240242553070055, -1.3872523889667707,
      -1.5507018556385745, -1.455700379357697, -1.5453980948832262,
      -1.3815996183092807, -1.3914921249488947, -1.1558121245179864,
      -1.0884673587958802, -0.787710411999592, -0.65633647627721792,
      -0.30861883034004162, -0.13775907433169526, 0.22772171010368611,
      0.40345620202328109, 0.74886982448244488, 0.88847161835529953,
      1.1722869947295302, 1.2344626746031391, 1.4186191384097977,
      1.3697726341693002, 1.4281738384265719, 1.2509840198704123,
      1.177686345618479, 0.87834079817005228, 0.69326013374399176,
      0.30503511859788274, 0.054865613210687093, -0.36408476066473267,
      -0.61151895421178737, -0.98738577032891583, -1.155812124518002,
      -1.4149011782165808, -1.4377782920915374, -1.5261442826405069,
      -1.3665152327026746, -1.2685972943057309, -0.93492743087270214,
      -0.68499903942032536, -0.23675098307180525, 0.082594896695794048,
      0.5443725576568661, 0.81976863574522707, 1.1776863456184377,
      1.2967421426289536, 1.4533735152450413, 1.3428685440911681,
      1.2576136461436609, 0.91547428573555367, 0.62807072937396113,
      0.13516595360252823, -0.23675098307178982, -0.734703968658123,
      -1.0293356096196526, -1.3694851560349126, -1.4391807198676174,
      -1.5054707088585906, -1.2800210863198282, -1.0588568289927562,
      -0.586511051314125, -0.18691321048778273, 0.37086984202646028,
      0.74997831055754538, 1.177686345618469, 1.3286635550561614,
      1.4522249039620285, 1.2580432141909075, 1.0357827552401584,
      0.54004674335855418, 0.10053070563096483, -0.49503029664539017,
      -0.89941847316540879, -1.3231259455953868, -1.437778292091489,
      -1.4889349782291028, -1.1988167147811311, -0.86973999627013254,
      -0.28175003406614157, 0.21554108117423046, 0.81064404617692087,
      1.1471312411458672, 1.4316015579892569, 1.3519905718332028,
      1.1776863456184279, 0.67102845141625389, 0.1733697811305229,
      -0.49373378930857903, -0.95579213373044536, -1.3897480289275539,
      -1.4556716450784986, -1.3953184546915511, -0.95579213373041827,
      -0.47147196071595832, 0.22772171010376285, 0.75267658125167747,
      1.2576136461436522, 1.3836897690610948, 1.3568162719938555,
      0.92087994485261393, 0.414902648501887, -0.31518839312013824,
      -0.86302189801317264, -1.3651570298154858, -1.4557003793576759,
      -1.3630030779019859, -0.84822275230162525, -0.27430398601701145,
      0.484485537219845, 1.0020931340872583, 1.4076644325753227,
      1.3492174398353682, 1.0858668083725245, 0.42421827692848363,
      -0.22772171010367373, -0.96068512970551045, -1.3395818493075793,
      -1.5137716134121004, -1.1830392034670809, -0.6760017168478718,
      0.12788502014594957, 0.76865696145923246, 1.3210254210656935,
      1.3825659513249009, 1.1776863456184838, 0.509619378584437,
      -0.19151828744050023, -0.97474485376967723, -1.3665152327026242,
      -1.4940509195371137, -1.0674000856622183, -0.45260539085422774,
      0.41490264850194564, 1.0272069853858299, 1.4377782920916038,
      1.2688628832619235, 0.810644046176871, -0.041015584211126881,
      -0.77226533224888416, -1.3881168506751831, -1.4391807198676907,
      -1.1443182514527785, -0.35315179230074978, 0.4291840507853068,
      1.1776863456184803, 1.3890148309421508, 1.2241633474703162,
      0.49317617287522708, -0.30861883034005011, -1.1349336696748449,
      -1.4430468946081263, -1.353519585279864, -0.65271161775993114,
      0.16405246275899521, 1.0293356096197122, 1.3722316059762065,
      1.2928605654593059, 0.57659349214159161, -0.26378129885382495,
      -1.1348093952257554, -1.4483505728618988, -1.3082156073095106,
      -0.52736438874367764, 0.34251022640530043, 1.1776863456185624,
      1.3891163551237387, 1.1157841607874102, 0.23166386039969653,
      -0.65271161775992281, -1.387737810235822, -1.4122136545356458,
      -0.94159460122289873, 0.054865613210678128, 0.89866841894857641,
      1.4377782920915503, 1.1861164371024422, 0.48448553721978238,
      -0.57809796556625614, -1.2712084867456279, -1.4933978018498197,
      -0.89941847316550183, 0.00063571317389858617, 1.0031432322900675,
      1.383815082681729, 1.1776863456184938, 0.24969528350793502,
      -0.70929019286049255, -1.4420846460640118, -1.3395818493075733,
      -0.67504001566122385, 0.44112855696320113, 1.1977487534104885,
      1.4186191384097342, 0.750761239417685, -0.22772171010371833,
      -1.2171884794800896, -1.4483505728620525, -1.012687151539436,
      0.082274052086257363, 1.003417058333492, 1.4552406535776043,
      0.94915579146909457, -0.0091463750542371183, -1.0964661689738009,
      -1.4557003793577761, -1.09322214542873, 0.0091463750542701925,
      0.97828942874420755, 1.4552406535776079, 0.92264542876761824,
      -0.082274052086159427, -1.1709125679174339, -1.4483505728619452,
      -0.95586778969742048, 0.22772171010373748, 1.1398074595249861,
      1.4186191384096909, 0.65777542607126493, -0.441128556963233,
      -1.3874253382022863, -1.3395818493075586, -0.53912236934032642,
      0.70929019286043271, 1.3557143673408407, 1.1776863456185516,
      0.069299394497803063, -1.0031432322900375, -1.5196003843927595,
      -0.8994184731653373, 0.21859014396947191, 1.2712084867457221,
      1.2971368801610454, 0.48448553721972903, -0.80836818550107781,
      -1.4377782920916191, -1.1558059937017391, 0.054865613210712309,
      1.0973507919455234, 1.4122136545356403, 0.54407328518721021,
      -0.65271161775990993, -1.4903533300106746, -1.1157841607873353,
      -0.017347763618596933, 1.1776863456185336, 1.3319081448120604,
      0.52736438874380787, -0.82399721577629148, -1.4483505728620147,
      -1.0534714756143144, 0.26378129885388762, 1.2409158650261194,
      1.2928605654593295, 0.16013253784557754, -1.0293356096197728,
      -1.5027441788300062, -0.652711617759908, 0.6138235218960022,
      1.4430468946081112, 0.9228149046898616, -0.30861883034000726,
      -1.4093259735442574, -1.2241633474702651, -0.10874542139782474,
      1.1776863456184534, 1.3035624181998031, 0.35315179230064431,
      -1.0433095667486212, -1.4391807198677067, -0.67473631942089873,
      0.77226533224887228, 1.390194070208346, 0.81064404617697339,
      -0.64551110459008854, -1.4377782920915105, -1.0262364941764393,
      0.41490264850177394, 1.3382244236869039, 1.0674000856622352,
      -0.34926632480246078, -1.366515232702727, -1.2027706765318877,
      0.19151828744054647, 1.2716163100927329, 1.1776863456184938,
      -0.20453216467389448, -1.3210254210658261, -1.2575530865404105,
      0.12788502014594888, 1.2567288735843483, 1.1830392034670498,
      -0.22271944272960292, -1.3395818493076368, -1.2140749563800999,
      0.22772171010384165, 1.3051676511105395, 1.0858668083725471,
      -0.40284524517638037, -1.40766443257531, -1.0533700314648591,
      0.48448553721977894, 1.3756173191281034, 0.84822275230161681,
      -0.72814430378110673, -1.4557003793577414, -0.72406665993026242,
      0.86302189801333284, 1.3691874920762994, 0.41490264850180031,
      -1.1341786814550261, -1.3568162719938683, -0.18171476567685391,
      1.2576136461436467, 1.1374750059650436, -0.22772171010372344,
      -1.4637532395295874, -0.955792133730518, 0.531742271783323,
      1.4556716450785845, 0.5442310794247488, -0.95579213373045468,
      -1.4572284819286119, -0.17336978113051607, 1.1889377638356,
      1.177686345618429, -0.3849871277058235, -1.4316015579893222,
      -0.8663253428214428, 0.81064404617689567, 1.3625293640369607,
      0.28175003406603955, -1.280626072237885, -1.1988167147811954,
      0.25458668863814521, 1.4377782920915059, 0.67384921579462809,
      -0.899418473165497, -1.4572102159097016, -0.10053070563090326,
      1.2567951537577555, 1.0357827552401506, -0.66214397536376457,
      -1.4522249039620809, -0.46911622345693565, 1.1776863456184616,
      1.1375116912334364, -0.37086984202659834, -1.5162128252925446,
      -0.5865110513141335, 1.0037744305990637, 1.2800210863197903,
      -0.31320158801883241, -1.4391807198676942, -0.72401124609260747,
      1.0293356096196937, 1.2308254061005535, -0.23675098307184872,
      -1.5060254370005177, -0.62807072937389141, 1.0037837872148778,
      1.2576136461436005, -0.40277063155041032, -1.4533735152450185,
      -0.5561150905711989, 1.1776863456184452, 1.0836615950725286,
      -0.54437255765692, -1.5123212096162606, -0.23675098307185632,
      1.2568233290714976, 0.93492743087263375, -0.90032289616763428,
      -1.3665152327026466, 0.0741121056229236, 1.4377782920916096,
      0.51087302480934793, -1.155812124518004, -1.2026555538608998,
      0.61151895421193647, 1.3625766771030725, 0.054865613210758966,
      -1.4686527360028307, -0.69326013374393691, 1.0282981079035971,
      1.1776863456185247, -0.645374289899419, -1.4281738384265144,
      -0.09029803308360064, 1.4186191384097773, 0.54429807097432825,
      -1.1722869947294523, -1.1433624156108992, 0.74886982448239825,
      1.3037221699553405, -0.22772171010379169, -1.5201927028930158,
      -0.30861883034018095, 1.2788759490001409, 0.78771041199955483,
      -1.1340912351346777, -1.1558121245180675, 0.614007701848837,
      1.3815996183093282, -0.29511469811992835, -1.4557003793577274,
      -0.29059636992664156, 1.3872523889667498, 0.57734027229214047,
      -1.198816714781195, -1.0532610982231179, 0.92083262466729787,
      1.1772526192293844, -0.58651105131411518, -1.4623880475344559,
      0.22772171010373454, 1.3897819951310932, 0.12788502014604453,
      -1.4901146684241171, -0.45852599615469036, 1.2568606094400159,
      0.74886982448242179, -1.2278493075923951, -0.98980839135173271,
      0.89926488449688025, 1.1776863456184696, -0.80809878706098515,
      -1.3132367468838284, 0.44729542114839055, 1.4004240464804367,
      -0.3491101507164826, -1.4453395841299956, 0.0011729436113865619,
      1.4552406535776004, 0.069602407758901835, -1.4377782920915687,
      -0.380432433966106, 1.4004240464804758, 0.40857758912812986,
      -1.350082261542799, -0.67455370466484721, 1.2928605654593,
      0.65811543050002264, -1.2339650931322912, -0.88144074662813532,
      1.1776863456184685, 0.82529446653957439, -1.1274443985450486,
      -1.0122447546015847, 1.08586680837258, 0.92302638924031621,
      -1.0548778365160496, -1.0797841731971509, 1.0357827552401679,
      0.96261592124327677, -1.0293356096196602, -1.0928177213680061,
      1.035782755240154, 0.94958237307251736, -1.0548778365160949,
      -1.0532281893650193, 1.085866808372546, 0.88204295447695646,
      -1.1274443985450591, -0.95549626666421328, 1.1776863456184978,
      0.75123894650350476, -1.2339650931322566, -0.788317230624646,
      1.2928605654594041, 0.54435190454009208, -1.3500822615426791,
      -0.53877938925276658, 1.4004240464805278, 0.25023063384144423,
      -1.4377782920915381, -0.19980420788350894, 1.4552406535776179,
      -0.13137474373597796, -1.4453395841300476, 0.2189083505919418,
      1.4004240464804341, -0.57749722127287739, -1.3132367468838542,
      0.67789698693638678, 1.1776863456184803, -1.0294666846216265,
      -0.98980839135173526, 1.0976475074676413, 0.74886982448236639,
      -1.3870624095647619, -0.45852599615477907, 1.3599128682993886,
      0.12788502014585112, -1.519983795255746, 0.22772171010371484,
      1.3321862474098451, -0.58651105131417092, -1.3074544193539035,
      0.92083262466730031, 0.92305929809849574, -1.1988167147811595,
      -0.707542072416772, 1.3872523889667006, 0.16039456980194708,
      -1.4557003793577612, 0.16491289799534806, 1.3815996183092361,
      -0.74420950197335967, -1.1558121245181157, 1.0038894350100847,
      0.78771041199955338, -1.4090777491246156, -0.30861883034005144,
      1.3899909027684587, -0.2277217101036676, -1.4339239700800257,
      0.7488698244824, 1.0131606154862653, -1.1722869947295176,
      -0.67449987109899989, 1.418619138409752, -0.0399037670410758,
      -1.4281738384265648, 0.51517248977477759, 1.1776863456184279,
      -1.1584999080283276, -0.69326013374405726, 1.3384509358780849,
      0.054865613210692235, -1.4927784772278314, 0.61151895421183255,
      1.0724537537362147, -1.1558121245180575, -0.64107482493411072,
      1.4377782920916458, -0.20431390574770464, -1.36651523270265,
      0.7701210960429653, 0.93492743087268049, -1.3870251291961482,
      -0.23675098307184089, 1.382119409491706, -0.544372557656904,
      -1.2138633951971021, 1.1776863456184858, 0.42591329044654,
      -1.4533735152449072, 0.27256883142569083, 1.2576136461437066,
      -1.1339855873395659, -0.62807072937388875, 1.3758236368757704,
      -0.2367509830718528, -1.361027206225252, 1.0293356096197301,
      0.59380944596800334, -1.4391807198677187, 0.18299978789420587,
      1.2800210863198915, -1.1339762307236698, -0.58651105131402725,
      1.3860110251679174, -0.370869842026528, -1.2677134913580177,
      1.1776863456184294, 0.33891442333237431, -1.4522249039621558,
      0.5319421752391521, 1.0357827552401526, -1.3869969538825058,
      -0.10053070563081196, 1.327008415785019, -0.89941847316541779,
      -0.80405101591920958, 1.4377782920915869, -0.3847884887628078,
      -1.1988167147811117, 1.1504242721133169, 0.28175003406601756,
      -1.4927311641614709, 0.81064404617697638, 0.73612354269675639,
      -1.4316015579892107, 0.25478532758125305, 1.1776863456184854,
      -1.3191395639603036, -0.17336978113045745, 1.3270266818039349,
      -0.95579213373053828, -0.67443287954935727, 1.4556716450785707,
      -0.66194407190811844, -0.95579213373033323, 1.3335514394049581,
      -0.2277217101037346, -1.2676768060896195, 1.257613646143604,
      0.051512965552237368, -1.3568162719937695, 1.0039768813304011,
      0.4149026485017856, -1.4993892922009791, 0.86302189801334028,
      0.59386485980554371, -1.4557003793577477, 0.59794250365651969,
      0.84822275230168265, -1.5058191192527788, 0.4844855372199377,
      0.92316823134012027, -1.4076644325752481, 0.27264344505173266,
      1.0858668083725367, -1.4353694512352848, 0.22772171010371353,
      1.0838731562553903, -1.3395818493076328, 0.092517642605166345,
      1.1830392034669606, -1.3869306737089961, 0.12788502014600911,
      1.1273512864157602, -1.3210254210657222, 0.074330364549315908,
      1.1776863456184214, -1.4018181102174172, 0.19151828744069138,
      1.0725688764072507, -1.3665152327027343, 0.21906452467786056,
      1.0674000856623069, -1.4684262238115902, 0.41490264850191649,
      0.89603469405174252, -1.4377782920916045, 0.51530930446543832,
      0.8106440461769221, -1.5203958703330613, 0.77226533224885685,
      0.54453451929626651, -1.4391807198676698, 0.91310776662404813,
      0.35315179230078103, -1.4337642183244119, 1.1776863456185114,
      -0.021456378726847185, -1.224163347470278, 1.2791241734196717,
      -0.30861883034028342, -1.0530167048143884, 1.4430468946080341,
      -0.74402532202059068, -0.65271161775996078, 1.3725423787054358,
      -1.029335609619747, -0.29033433797008151, 1.2928605654592347,
      -1.3711176651507677, 0.26378129885381613, 0.92326967548964889,
      -1.4483505728620656, 0.69379541565160563, 0.52736438874375846,
      -1.4621099449367405, 1.1776863456185143, -0.112854036506226,
      -1.1157841607872996, 1.3601515298859117, -0.65271161775992592,
      -0.67427508531180935, 1.4122136545356974, -1.2275525920702057,
      0.054865613210736186, 1.0256041935771123, -1.43777829209165,
      0.67816638537666762, 0.48448553721962528, -1.4273386802856318,
      1.2712084867456805, -0.34879194409423425, -0.89941847316536472,
      1.3893985842680106, -1.003143232290145, -0.19950119462253013,
      1.1776863456184736, -1.4859161674655328, 0.70929019286054074,
      0.40892056921564224, -1.3395818493075489, 1.2572235380776606,
      -0.44112855696326947, -0.78797722619582544, 1.4186191384097382,
      -1.2700092596496475, 0.22772171010373671, 0.82566598957261794,
      -1.4483505728620081, 1.0407107677927065, -0.082274052086266744,
      -1.0528472288922452, 1.45524065357764, -1.1084912288689051,
      0.0091463750543167958, 0.96302034530398273, -1.455700379357745,
      0.96626436884927847, -0.0091463750543276968, -1.0793575915936617,
      1.4552406535775826, -1.1336188584580891, 0.082274052086226443,
      0.88248535141478046, -1.4483505728620867, 1.0869866793555272,
      -0.22772171010377112, -0.88096303954227606, 1.4186191384097468,
      -1.3279505535351761, 0.44112855696327719, 0.5448382155364907,
      -1.3395818493075224, 1.3118828459393999, -0.70929019286055672,
      -0.37989708363247648, 1.1776863456184044, -1.5140168828063767,
      1.003143232290137, -0.13083751329847434, -0.89941847316540169,
      1.3631960017252014, -1.27120848674571, 0.44789616544159871,
      0.48448553721974807, -1.316318237227059, 1.4377782920915738,
      -1.0288702190732404, 0.05486561321074937, 0.81139280109818979,
      -1.4122136545356749, 1.2575360101111894, -0.6527116177599992,
      -0.36186566052418156, 1.1157841607873515, -1.5193181552484447,
      1.1776863456185462, -0.47271202653016109, -0.52736438874365266,
      1.1780138071847031, -1.4483505728620631, 1.0046075951010478,
      -0.26378129885393331, -0.70679529226608551, 1.2928605654592518,
      -1.5024334061008815, 1.0293356096197015, -0.29425426288362916,
      -0.65271161775987208, 1.2233177851551775, -1.4430468946080524,
      1.004731869550199, -0.3086188303401356, -0.62337797299980258,
      1.2241633474701847, -1.5192166310667587, 1.1776863456183744,
      -0.55938585090982362, -0.35315179230085608, 1.0141164513281435,
      -1.4391807198676618, 1.2579150505505554, -0.77226533224885985,
      -0.089186215913422476, 0.81064404617691777, -1.3990646833865563,
      1.4377782920915527, -1.1574087855105366, 0.41490264850178504,
      0.32240359072949965, -1.0674000856623684, 1.3638491194125963,
      -1.3665152327029224, 0.84454305364511262, -0.19151828744066315,
      -0.63982117870918676, 1.1776863456185318, -1.5127677514495259,
      1.3210254210658088, -0.89885876158396028, 0.1278850201459926,
      0.545799916723219, -1.1830392034670683, 1.3835698132874794,
      -1.3395818493076503, 0.830483329580988, -0.22772171010383632,
      -0.55442007705301821, 1.0858668083724969, -1.4794192399600732,
      1.4076644325752956, -1.1322949342119526, 0.48448553721983212,
      0.14410218589222856, -0.84822275230166078, 1.2328012777773198,
      -1.4557003793577841, 1.234955229690764, -0.86302189801333684,
      0.18498659299551695, 0.414902648501638, -1.0510817449771506,
      1.3568162719936807, -1.5138915691857173, 1.2576136461436593,
      -0.8828783813763631, 0.22772171010373191, 0.3412701605911389,
      -0.9557921337303471, 1.265116654566788, -1.455671645078475,
      1.2595462288027981, -0.955792133730412, 0.36353198918392482,
      0.17336978113049767, -0.80123025154079164, 1.1776863456183291,
      -1.4821923719576962, 1.4316015579891641, -1.2773330412704402,
      0.81064404617693675, -0.34574288129896963, -0.281750034065993,
      0.73953819614536, -1.1988167147810709, 1.3587331781044041,
      -1.43777829209162, 1.1929241454707431, -0.8994184731655066,
      0.36482849652080546, 0.10053070563079644, -0.6702485434831269,
      1.0357827552400485, -1.3882450143155185, 1.4522249039620709,
      -1.4588653551808586, 1.17768634561858, -0.88018011068225244,
      0.37086984202668194, 0.056711410363106618, -0.58651105131402959,
      0.92865502886818641, -1.280021086319902, 1.3752689087339929,
      -1.4391807198678228, 1.2392833559104064, -1.0293356096198547,
      0.60450216853350458, -0.23675098307193798, -0.26536775372710247,
      0.62807072937388531, -1.0456760858601803, 1.2576136461436973,
      -1.4730703442159516, 1.4533735152450495, -1.4269439427535768,
      1.1776863456184183, -0.94997043586982688, 0.54437255765680381,
      -0.21279669682045491, -0.23675098307188724, 0.55479723929565394,
      -0.93492743087262375, 1.1383954941810974, -1.366515232702662,
      1.3959424825157043, -1.437778292091487, 1.2846993780919198,
      -1.1558121245181248, 0.85718397020424575, -0.61151895421185354,
      0.23388296054012553, 0.054865613210535805, -0.43523691872232451,
      0.69326013374395412, -1.0085425982945573, 1.1776863456183679,
      -1.3811858199949796, 1.4281738384264413, -1.499974434293907,
      1.4186191384097075, -1.3646644747278753, 1.1722869947295187,
      -1.0186734184800681, 0.74886982448237061, -0.53365800214801551,
      0.22772171010375114, 0.0075572742070260622, -0.30861883034006332,
      0.52613467615250908, -0.78771041199959346, 0.9582655586711365,
      -1.1558121245179875, 1.2612903248241041, -1.3815996183093255,
      1.4151962947585519, -1.4557003793577941, 1.4205000555140115,
      -1.387252388966794, 1.2938224551825153, -1.1988167147813031,
      1.062441968017799, -0.92083262466735216, 0.75888051610009921,
      -0.586511051314065, 0.41624793360425388, -0.22772171010379758,
      0.064736670994190865, 0.1278850201458468, -0.27062498991138861,
      0.45852599615470968, -0.57105735262997093, 0.74886982448235218,
      -0.8241689822393431, 0.98980839135184451, -1.0234189845169082,
      1.1776863456184556, -1.1671656637555923, 1.3132367468837751,
      -1.2575283131315891, 1.4004240464805091, -1.2992358042916305,
      1.4453395841299379, -1.2985796232401934, 1.4552406535776168,
      -1.2625385681734598, 1.4377782920915385, -1.1981019353076048,
      1.4004240464805029, -1.1117890274721534, 1.3500822615426913,
      -1.0093445368302685, 1.2928605654592793, -0.8955799642523784,
      1.2339650931322539, -0.77432851183227314, 1.1776863456184916,
      -0.64848264009609913, 1.1274443985451252, -0.52008784874624892,
      1.0858668083725425, -0.39047176930888561, 1.0548778365160858,
      -0.2603933200625505, 1.0357827552401586, -0.13020180012464427,
      1.0293356096196626, 4.0590492605963612E-14, 1.035782755240044,
      0.13019151993794872, 1.0548778365160583, 0.26026996918415751,
      1.0858668083725957, 0.38988604862150356, 1.1274443985450744,
      0.51828083997134644, 1.177686345618504, 0.64412671170758262,
      1.2339650931322783, 0.76537816412775173, 1.2928605654592691,
      0.87914273670568588, 1.3500822615427905, 0.98158722734754988,
      1.4004240464805378, 1.0679001351829045, 1.4377782920916087,
      1.1323367680488143, 1.4552406535777005, 1.1683778231154796,
      1.4453395841300156, 1.1690340041670173, 1.4004240464805431,
      1.1273265130069039, 1.3132367468838106, 1.0369638636309571,
      1.1776863456184878, 0.89321718439226583, 0.98980839135177612,
      0.69396718211468245, 0.748869824482328, 0.44085555250542841,
      0.45852599615477618, 0.14042318978684099, 0.12788502014596068,
      -0.19493847111874318, -0.22772171010366385, -0.54644973372888417,
      -0.58651105131397929, -0.889082316224844, -0.92083262466724469,
      -1.1926437681423814, -1.19881671478117, -1.4240242553070055,
      -1.3872523889667707, -1.5507018556385745, -1.455700379357697,
      -1.5453980948832262, -1.3815996183092807, -1.3914921249488947,
      -1.1558121245179864, -1.0884673587958802, -0.787710411999592,
      -0.65633647627721792, -0.30861883034004162, -0.13775907433169526,
      0.22772171010368611, 0.40345620202328109, 0.74886982448244488,
      0.88847161835529953, 1.1722869947295302, 1.2344626746031391,
      1.4186191384097977, 1.3697726341693002, 1.4281738384265719,
      1.2509840198704123, 1.177686345618479, 0.87834079817005228,
      0.69326013374399176, 0.30503511859788274, 0.054865613210687093,
      -0.36408476066473267, -0.61151895421178737, -0.98738577032891583,
      -1.155812124518002, -1.4149011782165808, -1.4377782920915374,
      -1.5261442826405069, -1.3665152327026746, -1.2685972943057309,
      -0.93492743087270214, -0.68499903942032536, -0.23675098307180525,
      0.082594896695794048, 0.5443725576568661, 0.81976863574522707,
      1.1776863456184377, 1.2967421426289536, 1.4533735152450413,
      1.3428685440911681, 1.2576136461436609, 0.91547428573555367,
      0.62807072937396113, 0.13516595360252823, -0.23675098307178982,
      -0.734703968658123, -1.0293356096196526, -1.3694851560349126,
      -1.4391807198676174, -1.5054707088585906, -1.2800210863198282,
      -1.0588568289927562, -0.586511051314125, -0.18691321048778273,
      0.37086984202646028, 0.74997831055754538, 1.177686345618469,
      1.3286635550561614, 1.4522249039620285, 1.2580432141909075,
      1.0357827552401584, 0.54004674335855418, 0.10053070563096483,
      -0.49503029664539017, -0.89941847316540879, -1.3231259455953868,
      -1.437778292091489, -1.4889349782291028, -1.1988167147811311,
      -0.86973999627013254, -0.28175003406614157, 0.21554108117423046,
      0.81064404617692087, 1.1471312411458672, 1.4316015579892569,
      1.3519905718332028, 1.1776863456184279, 0.67102845141625389,
      0.1733697811305229, -0.49373378930857903, -0.95579213373044536,
      -1.3897480289275539, -1.4556716450784986, -1.3953184546915511,
      -0.95579213373041827, -0.47147196071595832, 0.22772171010376285,
      0.75267658125167747, 1.2576136461436522, 1.3836897690610948,
      1.3568162719938555, 0.92087994485261393, 0.414902648501887,
      -0.31518839312013824, -0.86302189801317264, -1.3651570298154858,
      -1.4557003793576759, -1.3630030779019859, -0.84822275230162525,
      -0.27430398601701145, 0.484485537219845, 1.0020931340872583,
      1.4076644325753227, 1.3492174398353682, 1.0858668083725245,
      0.42421827692848363, -0.22772171010367373, -0.96068512970551045,
      -1.3395818493075793, -1.5137716134121004, -1.1830392034670809,
      -0.6760017168478718, 0.12788502014594957, 0.76865696145923246,
      1.3210254210656935, 1.3825659513249009, 1.1776863456184838,
      0.509619378584437, -0.19151828744050023, -0.97474485376967723,
      -1.3665152327026242, -1.4940509195371137, -1.0674000856622183,
      -0.45260539085422774, 0.41490264850194564, 1.0272069853858299,
      1.4377782920916038, 1.2688628832619235, 0.810644046176871,
      -0.041015584211126881, -0.77226533224888416, -1.3881168506751831,
      -1.4391807198676907, -1.1443182514527785, -0.35315179230074978,
      0.4291840507853068, 1.1776863456184803, 1.3890148309421508,
      1.2241633474703162, 0.49317617287522708, -0.30861883034005011,
      -1.1349336696748449, -1.4430468946081263, -1.353519585279864,
      -0.65271161775993114, 0.16405246275899521, 1.0293356096197122,
      1.3722316059762065, 1.2928605654593059, 0.57659349214159161,
      -0.26378129885382495, -1.1348093952257554, -1.4483505728618988,
      -1.3082156073095106, -0.52736438874367764, 0.34251022640530043,
      1.1776863456185624, 1.3891163551237387, 1.1157841607874102,
      0.23166386039969653, -0.65271161775992281, -1.387737810235822,
      -1.4122136545356458, -0.94159460122289873, 0.054865613210678128,
      0.89866841894857641, 1.4377782920915503, 1.1861164371024422,
      0.48448553721978238, -0.57809796556625614, -1.2712084867456279,
      -1.4933978018498197, -0.89941847316550183, 0.00063571317389858617,
      1.0031432322900675, 1.383815082681729, 1.1776863456184938,
      0.24969528350793502, -0.70929019286049255, -1.4420846460640118,
      -1.3395818493075733, -0.67504001566122385, 0.44112855696320113,
      1.1977487534104885, 1.4186191384097342, 0.750761239417685,
      -0.22772171010371833, -1.2171884794800896, -1.4483505728620525,
      -1.012687151539436, 0.082274052086257363, 1.003417058333492,
      1.4552406535776043, 0.94915579146909457, -0.0091463750542371183,
      -1.0964661689738009, -1.4557003793577761, -1.09322214542873,
      0.0091463750542701925, 0.97828942874420755, 1.4552406535776079,
      0.92264542876761824, -0.082274052086159427, -1.1709125679174339,
      -1.4483505728619452, -0.95586778969742048, 0.22772171010373748,
      1.1398074595249861, 1.4186191384096909, 0.65777542607126493,
      -0.441128556963233, -1.3874253382022863, -1.3395818493075586,
      -0.53912236934032642, 0.70929019286043271, 1.3557143673408407,
      1.1776863456185516, 0.069299394497803063, -1.0031432322900375,
      -1.5196003843927595, -0.8994184731653373, 0.21859014396947191,
      1.2712084867457221, 1.2971368801610454, 0.48448553721972903,
      -0.80836818550107781, -1.4377782920916191, -1.1558059937017391,
      0.054865613210712309, 1.0973507919455234, 1.4122136545356403,
      0.54407328518721021, -0.65271161775990993, -1.4903533300106746,
      -1.1157841607873353, -0.017347763618596933, 1.1776863456185336,
      1.3319081448120604, 0.52736438874380787, -0.82399721577629148,
      -1.4483505728620147, -1.0534714756143144, 0.26378129885388762,
      1.2409158650261194, 1.2928605654593295, 0.16013253784557754,
      -1.0293356096197728, -1.5027441788300062, -0.652711617759908,
      0.6138235218960022, 1.4430468946081112, 0.9228149046898616,
      -0.30861883034000726, -1.4093259735442574, -1.2241633474702651,
      -0.10874542139782474, 1.1776863456184534, 1.3035624181998031,
      0.35315179230064431, -1.0433095667486212, -1.4391807198677067,
      -0.67473631942089873, 0.77226533224887228, 1.390194070208346,
      0.81064404617697339, -0.64551110459008854, -1.4377782920915105,
      -1.0262364941764393, 0.41490264850177394, 1.3382244236869039,
      1.0674000856622352, -0.34926632480246078, -1.366515232702727,
      -1.2027706765318877, 0.19151828744054647, 1.2716163100927329,
      1.1776863456184938, -0.20453216467389448, -1.3210254210658261,
      -1.2575530865404105, 0.12788502014594888, 1.2567288735843483,
      1.1830392034670498, -0.22271944272960292, -1.3395818493076368,
      -1.2140749563800999, 0.22772171010384165, 1.3051676511105395,
      1.0858668083725471, -0.40284524517638037, -1.40766443257531,
      -1.0533700314648591, 0.48448553721977894, 1.3756173191281034,
      0.84822275230161681, -0.72814430378110673, -1.4557003793577414,
      -0.72406665993026242, 0.86302189801333284, 1.3691874920762994,
      0.41490264850180031, -1.1341786814550261, -1.3568162719938683,
      -0.18171476567685391, 1.2576136461436467, 1.1374750059650436,
      -0.22772171010372344, -1.4637532395295874, -0.955792133730518,
      0.531742271783323, 1.4556716450785845, 0.5442310794247488,
      -0.95579213373045468, -1.4572284819286119, -0.17336978113051607,
      1.1889377638356, 1.177686345618429, -0.3849871277058235,
      -1.4316015579893222, -0.8663253428214428, 0.81064404617689567,
      1.3625293640369607, 0.28175003406603955, -1.280626072237885,
      -1.1988167147811954, 0.25458668863814521, 1.4377782920915059,
      0.67384921579462809, -0.899418473165497, -1.4572102159097016,
      -0.10053070563090326, 1.2567951537577555, 1.0357827552401506,
      -0.66214397536376457, -1.4522249039620809, -0.46911622345693565,
      1.1776863456184616, 1.1375116912334364, -0.37086984202659834,
      -1.5162128252925446, -0.5865110513141335, 1.0037744305990637,
      1.2800210863197903, -0.31320158801883241, -1.4391807198676942,
      -0.72401124609260747, 1.0293356096196937, 1.2308254061005535,
      -0.23675098307184872, -1.5060254370005177, -0.62807072937389141,
      1.0037837872148778, 1.2576136461436005, -0.40277063155041032,
      -1.4533735152450185, -0.5561150905711989, 1.1776863456184452,
      1.0836615950725286, -0.54437255765692, -1.5123212096162606,
      -0.23675098307185632, 1.2568233290714976, 0.93492743087263375,
      -0.90032289616763428, -1.3665152327026466, 0.0741121056229236,
      1.4377782920916096, 0.51087302480934793, -1.155812124518004,
      -1.2026555538608998, 0.61151895421193647, 1.3625766771030725,
      0.054865613210758966, -1.4686527360028307, -0.69326013374393691,
      1.0282981079035971, 1.1776863456185247, -0.645374289899419,
      -1.4281738384265144, -0.09029803308360064, 1.4186191384097773,
      0.54429807097432825, -1.1722869947294523, -1.1433624156108992,
      0.74886982448239825, 1.3037221699553405, -0.22772171010379169,
      -1.5201927028930158, -0.30861883034018095, 1.2788759490001409,
      0.78771041199955483, -1.1340912351346777, -1.1558121245180675,
      0.614007701848837, 1.3815996183093282, -0.29511469811992835,
      -1.4557003793577274, -0.29059636992664156, 1.3872523889667498,
      0.57734027229214047, -1.198816714781195, -1.0532610982231179,
      0.92083262466729787, 1.1772526192293844, -0.58651105131411518,
      -1.4623880475344559, 0.22772171010373454, 1.3897819951310932,
      0.12788502014604453, -1.4901146684241171, -0.45852599615469036,
      1.2568606094400159, 0.74886982448242179, -1.2278493075923951,
      -0.98980839135173271, 0.89926488449688025, 1.1776863456184696,
      -0.80809878706098515, -1.3132367468838284, 0.44729542114839055,
      1.4004240464804367, -0.3491101507164826, -1.4453395841299956,
      0.0011729436113865619, 1.4552406535776004, 0.069602407758901835,
      -1.4377782920915687, -0.380432433966106, 1.4004240464804758,
      0.40857758912812986, -1.350082261542799, -0.67455370466484721,
      1.2928605654593, 0.65811543050002264, -1.2339650931322912,
      -0.88144074662813532, 1.1776863456184685, 0.82529446653957439,
      -1.1274443985450486, -1.0122447546015847, 1.08586680837258,
      0.92302638924031621, -1.0548778365160496, -1.0797841731971509,
      1.0357827552401679, 0.96261592124327677, -1.0293356096196602,
      -1.0928177213680061, 1.035782755240154, 0.94958237307251736,
      -1.0548778365160949, -1.0532281893650193, 1.085866808372546,
      0.88204295447695646, -1.1274443985450591, -0.95549626666421328,
      1.1776863456184978, 0.75123894650350476, -1.2339650931322566,
      -0.788317230624646, 1.2928605654594041, 0.54435190454009208,
      -1.3500822615426791, -0.53877938925276658, 1.4004240464805278,
      0.25023063384144423, -1.4377782920915381, -0.19980420788350894,
      1.4552406535776179, -0.13137474373597796, -1.4453395841300476,
      0.2189083505919418, 1.4004240464804341, -0.57749722127287739,
      -1.3132367468838542, 0.67789698693638678, 1.1776863456184803,
      -1.0294666846216265, -0.98980839135173526, 1.0976475074676413,
      0.74886982448236639, -1.3870624095647619, -0.45852599615477907,
      1.3599128682993886, 0.12788502014585112, -1.519983795255746,
      0.22772171010371484, 1.3321862474098451, -0.58651105131417092,
      -1.3074544193539035, 0.92083262466730031, 0.92305929809849574,
      -1.1988167147811595, -0.707542072416772, 1.3872523889667006,
      0.16039456980194708, -1.4557003793577612, 0.16491289799534806,
      1.3815996183092361, -0.74420950197335967, -1.1558121245181157,
      1.0038894350100847, 0.78771041199955338, -1.4090777491246156,
      -0.30861883034005144, 1.3899909027684587, -0.2277217101036676,
      -1.4339239700800257, 0.7488698244824, 1.0131606154862653,
      -1.1722869947295176, -0.67449987109899989, 1.418619138409752,
      -0.0399037670410758, -1.4281738384265648, 0.51517248977477759,
      1.1776863456184279, -1.1584999080283276, -0.69326013374405726,
      1.3384509358780849, 0.054865613210692235, -1.4927784772278314,
      0.61151895421183255, 1.0724537537362147, -1.1558121245180575,
      -0.64107482493411072, 1.4377782920916458, -0.20431390574770464,
      -1.36651523270265, 0.7701210960429653, 0.93492743087268049,
      -1.3870251291961482, -0.23675098307184089, 1.382119409491706,
      -0.544372557656904, -1.2138633951971021, 1.1776863456184858,
      0.42591329044654, -1.4533735152449072, 0.27256883142569083,
      1.2576136461437066, -1.1339855873395659, -0.62807072937388875,
      1.3758236368757704, -0.2367509830718528, -1.361027206225252,
      1.0293356096197301, 0.59380944596800334, -1.4391807198677187,
      0.18299978789420587, 1.2800210863198915, -1.1339762307236698,
      -0.58651105131402725, 1.3860110251679174, -0.370869842026528,
      -1.2677134913580177, 1.1776863456184294, 0.33891442333237431,
      -1.4522249039621558, 0.5319421752391521, 1.0357827552401526,
      -1.3869969538825058, -0.10053070563081196, 1.327008415785019,
      -0.89941847316541779, -0.80405101591920958, 1.4377782920915869,
      -0.3847884887628078, -1.1988167147811117, 1.1504242721133169,
      0.28175003406601756, -1.4927311641614709, 0.81064404617697638,
      0.73612354269675639, -1.4316015579892107, 0.25478532758125305,
      1.1776863456184854, -1.3191395639603036, -0.17336978113045745,
      1.3270266818039349, -0.95579213373053828, -0.67443287954935727,
      1.4556716450785707, -0.66194407190811844, -0.95579213373033323,
      1.3335514394049581, -0.2277217101037346, -1.2676768060896195,
      1.257613646143604, 0.051512965552237368, -1.3568162719937695,
      1.0039768813304011, 0.4149026485017856, -1.4993892922009791,
      0.86302189801334028, 0.59386485980554371, -1.4557003793577477,
      0.59794250365651969, 0.84822275230168265, -1.5058191192527788,
      0.4844855372199377, 0.92316823134012027, -1.4076644325752481,
      0.27264344505173266, 1.0858668083725367, -1.4353694512352848,
      0.22772171010371353, 1.0838731562553903, -1.3395818493076328,
      0.092517642605166345, 1.1830392034669606, -1.3869306737089961,
      0.12788502014600911, 1.1273512864157602, -1.3210254210657222,
      0.074330364549315908, 1.1776863456184214, -1.4018181102174172,
      0.19151828744069138, 1.0725688764072507, -1.3665152327027343,
      0.21906452467786056, 1.0674000856623069, -1.4684262238115902,
      0.41490264850191649, 0.89603469405174252, -1.4377782920916045,
      0.51530930446543832, 0.8106440461769221, -1.5203958703330613,
      0.77226533224885685, 0.54453451929626651, -1.4391807198676698,
      0.91310776662404813, 0.35315179230078103, -1.4337642183244119,
      1.1776863456185114, -0.021456378726847185, -1.224163347470278,
      1.2791241734196717, -0.30861883034028342, -1.0530167048143884,
      1.4430468946080341, -0.74402532202059068, -0.65271161775996078,
      1.3725423787054358, -1.029335609619747, -0.29033433797008151,
      1.2928605654592347, -1.3711176651507677, 0.26378129885381613,
      0.92326967548964889, -1.4483505728620656, 0.69379541565160563,
      0.52736438874375846, -1.4621099449367405, 1.1776863456185143,
      -0.112854036506226, -1.1157841607872996, 1.3601515298859117,
      -0.65271161775992592, -0.67427508531180935, 1.4122136545356974,
      -1.2275525920702057, 0.054865613210736186, 1.0256041935771123,
      -1.43777829209165, 0.67816638537666762, 0.48448553721962528,
      -1.4273386802856318, 1.2712084867456805, -0.34879194409423425,
      -0.89941847316536472, 1.3893985842680106, -1.003143232290145,
      -0.19950119462253013, 1.1776863456184736, -1.4859161674655328,
      0.70929019286054074, 0.40892056921564224, -1.3395818493075489,
      1.2572235380776606, -0.44112855696326947, -0.78797722619582544,
      1.4186191384097382, -1.2700092596496475, 0.22772171010373671,
      0.82566598957261794, -1.4483505728620081, 1.0407107677927065,
      -0.082274052086266744, -1.0528472288922452, 1.45524065357764,
      -1.1084912288689051, 0.0091463750543167958, 0.96302034530398273,
      -1.455700379357745, 0.96626436884927847, -0.0091463750543276968,
      -1.0793575915936617, 1.4552406535775826, -1.1336188584580891,
      0.082274052086226443, 0.88248535141478046, -1.4483505728620867,
      1.0869866793555272, -0.22772171010377112, -0.88096303954227606,
      1.4186191384097468, -1.3279505535351761, 0.44112855696327719,
      0.5448382155364907, -1.3395818493075224, 1.3118828459393999,
      -0.70929019286055672, -0.37989708363247648, 1.1776863456184044,
      -1.5140168828063767, 1.003143232290137, -0.13083751329847434,
      -0.89941847316540169, 1.3631960017252014, -1.27120848674571,
      0.44789616544159871, 0.48448553721974807, -1.316318237227059,
      1.4377782920915738, -1.0288702190732404, 0.05486561321074937,
      0.81139280109818979, -1.4122136545356749, 1.2575360101111894,
      -0.6527116177599992, -0.36186566052418156, 1.1157841607873515,
      -1.5193181552484447, 1.1776863456185462, -0.47271202653016109,
      -0.52736438874365266, 1.1780138071847031, -1.4483505728620631,
      1.0046075951010478, -0.26378129885393331, -0.70679529226608551,
      1.2928605654592518, -1.5024334061008815, 1.0293356096197015,
      -0.29425426288362916, -0.65271161775987208, 1.2233177851551775,
      -1.4430468946080524, 1.004731869550199, -0.3086188303401356,
      -0.62337797299980258, 1.2241633474701847, -1.5192166310667587,
      1.1776863456183744, -0.55938585090982362, -0.35315179230085608,
      1.0141164513281435, -1.4391807198676618, 1.2579150505505554,
      -0.77226533224885985, -0.089186215913422476, 0.81064404617691777,
      -1.3990646833865563, 1.4377782920915527, -1.1574087855105366,
      0.41490264850178504, 0.32240359072949965, -1.0674000856623684,
      1.3638491194125963, -1.3665152327029224, 0.84454305364511262,
      -0.19151828744066315, -0.63982117870918676, 1.1776863456185318,
      -1.5127677514495259, 1.3210254210658088, -0.89885876158396028,
      0.1278850201459926, 0.545799916723219, -1.1830392034670683,
      1.3835698132874794, -1.3395818493076503, 0.830483329580988,
      -0.22772171010383632, -0.55442007705301821, 1.0858668083724969,
      -1.4794192399600732, 1.4076644325752956, -1.1322949342119526,
      0.48448553721983212, 0.14410218589222856, -0.84822275230166078,
      1.2328012777773198, -1.4557003793577841, 1.234955229690764,
      -0.86302189801333684, 0.18498659299551695, 0.414902648501638,
      -1.0510817449771506, 1.3568162719936807, -1.5138915691857173,
      1.2576136461436593, -0.8828783813763631, 0.22772171010373191,
      0.3412701605911389, -0.9557921337303471, 1.265116654566788,
      -1.455671645078475, 1.2595462288027981, -0.955792133730412,
      0.36353198918392482, 0.17336978113049767, -0.80123025154079164,
      1.1776863456183291, -1.4821923719576962, 1.4316015579891641,
      -1.2773330412704402, 0.81064404617693675, -0.34574288129896963,
      -0.281750034065993, 0.73953819614536, -1.1988167147810709,
      1.3587331781044041, -1.43777829209162, 1.1929241454707431,
      -0.8994184731655066, 0.36482849652080546, 0.10053070563079644,
      -0.6702485434831269, 1.0357827552400485, -1.3882450143155185,
      1.4522249039620709, -1.4588653551808586, 1.17768634561858,
      -0.88018011068225244, 0.37086984202668194, 0.056711410363106618,
      -0.58651105131402959, 0.92865502886818641, -1.280021086319902,
      1.3752689087339929, -1.4391807198678228, 1.2392833559104064,
      -1.0293356096198547, 0.60450216853350458, -0.23675098307193798,
      -0.26536775372710247, 0.62807072937388531, -1.0456760858601803,
      1.2576136461436973, -1.4730703442159516, 1.4533735152450495,
      -1.4269439427535768, 1.1776863456184183, -0.94997043586982688,
      0.54437255765680381, -0.21279669682045491, -0.23675098307188724,
      0.55479723929565394, -0.93492743087262375, 1.1383954941810974,
      -1.366515232702662, 1.3959424825157043, -1.437778292091487,
      1.2846993780919198, -1.1558121245181248, 0.85718397020424575,
      -0.61151895421185354, 0.23388296054012553, 0.054865613210535805,
      -0.43523691872232451, 0.69326013374395412, -1.0085425982945573,
      1.1776863456183679, -1.3811858199949796, 1.4281738384264413,
      -1.499974434293907, 1.4186191384097075, -1.3646644747278753,
      1.1722869947295187, -1.0186734184800681, 0.74886982448237061,
      -0.53365800214801551, 0.22772171010375114, 0.0075572742070260622,
      -0.30861883034006332, 0.52613467615250908, -0.78771041199959346,
      0.9582655586711365, -1.1558121245179875, 1.2612903248241041,
      -1.3815996183093255, 1.4151962947585519, -1.4557003793577941,
      1.4205000555140115, -1.387252388966794, 1.2938224551825153,
      -1.1988167147813031, 1.062441968017799, -0.92083262466735216,
      0.75888051610009921, -0.586511051314065, 0.41624793360425388,
      -0.22772171010379758, 0.064736670994190865, 0.1278850201458468,
      -0.27062498991138861, 0.45852599615470968, -0.57105735262997093,
      0.74886982448235218, -0.8241689822393431, 0.98980839135184451,
      -1.0234189845169082, 1.1776863456184556, -1.1671656637555923,
      1.3132367468837751, -1.2575283131315891, 1.4004240464805091,
      -1.2992358042916305, 1.4453395841299379, -1.2985796232401934,
      1.4552406535776168, -1.2625385681734598, 1.4377782920915385,
      -1.1981019353076048, 1.4004240464805029, -1.1117890274721534,
      1.3500822615426913, -1.0093445368302685, 1.2928605654592793,
      -0.8955799642523784, 1.2339650931322539, -0.77432851183227314,
      1.1776863456184916, -0.64848264009609913, 1.1274443985451252,
      -0.52008784874624892, 1.0858668083725425, -0.39047176930888561,
      1.0548778365160858, -0.2603933200625505, 1.0357827552401586,
      -0.13020180012464427, 1.0293356096196626, 4.0590492605963612E-14,
      1.035782755240044, 0.13019151993794872, 1.0548778365160583,
      0.26026996918415751, 1.0858668083725957, 0.38988604862150356,
      1.1274443985450744, 0.51828083997134644, 1.177686345618504,
      0.64412671170758262, 1.2339650931322783, 0.76537816412775173,
      1.2928605654592691, 0.87914273670568588, 1.3500822615427905,
      0.98158722734754988, 1.4004240464805378, 1.0679001351829045,
      1.4377782920916087, 1.1323367680488143, 1.4552406535777005,
      1.1683778231154796, 1.4453395841300156, 1.1690340041670173,
      1.4004240464805431, 1.1273265130069039, 1.3132367468838106,
      1.0369638636309571, 1.1776863456184878, 0.89321718439226583,
      0.98980839135177612, 0.69396718211468245, 0.748869824482328,
      0.44085555250542841, 0.45852599615477618, 0.14042318978684099,
      0.12788502014596068, -0.19493847111874318, -0.22772171010366385,
      -0.54644973372888417, -0.58651105131397929, -0.889082316224844,
      -0.92083262466724469, -1.1926437681423814, -1.19881671478117,
      -1.4240242553070055, -1.3872523889667707, -1.5507018556385745,
      -1.455700379357697, -1.5453980948832262, -1.3815996183092807,
      -1.3914921249488947, -1.1558121245179864, -1.0884673587958802,
      -0.787710411999592, -0.65633647627721792, -0.30861883034004162,
      -0.13775907433169526, 0.22772171010368611, 0.40345620202328109,
      0.74886982448244488, 0.88847161835529953, 1.1722869947295302,
      1.2344626746031391, 1.4186191384097977, 1.3697726341693002,
      1.4281738384265719, 1.2509840198704123, 1.177686345618479,
      0.87834079817005228, 0.69326013374399176, 0.30503511859788274,
      0.054865613210687093, -0.36408476066473267, -0.61151895421178737,
      -0.98738577032891583, -1.155812124518002, -1.4149011782165808,
      -1.4377782920915374, -1.5261442826405069, -1.3665152327026746,
      -1.2685972943057309, -0.93492743087270214, -0.68499903942032536,
      -0.23675098307180525, 0.082594896695794048, 0.5443725576568661,
      0.81976863574522707, 1.1776863456184377, 1.2967421426289536,
      1.4533735152450413, 1.3428685440911681, 1.2576136461436609,
      0.91547428573555367, 0.62807072937396113, 0.13516595360252823,
      -0.23675098307178982, -0.734703968658123, -1.0293356096196526,
      -1.3694851560349126, -1.4391807198676174, -1.5054707088585906,
      -1.2800210863198282, -1.0588568289927562, -0.586511051314125,
      -0.18691321048778273, 0.37086984202646028, 0.74997831055754538,
      1.177686345618469, 1.3286635550561614, 1.4522249039620285,
      1.2580432141909075, 1.0357827552401584, 0.54004674335855418,
      0.10053070563096483, -0.49503029664539017, -0.89941847316540879,
      -1.3231259455953868, -1.437778292091489, -1.4889349782291028,
      -1.1988167147811311, -0.86973999627013254, -0.28175003406614157,
      0.21554108117423046, 0.81064404617692087, 1.1471312411458672,
      1.4316015579892569, 1.3519905718332028, 1.1776863456184279,
      0.67102845141625389, 0.1733697811305229, -0.49373378930857903,
      -0.95579213373044536, -1.3897480289275539, -1.4556716450784986,
      -1.3953184546915511, -0.95579213373041827, -0.47147196071595832,
      0.22772171010376285, 0.75267658125167747, 1.2576136461436522,
      1.3836897690610948, 1.3568162719938555, 0.92087994485261393,
      0.414902648501887, -0.31518839312013824, -0.86302189801317264,
      -1.3651570298154858, -1.4557003793576759, -1.3630030779019859,
      -0.84822275230162525, -0.27430398601701145, 0.484485537219845,
      1.0020931340872583, 1.4076644325753227, 1.3492174398353682,
      1.0858668083725245, 0.42421827692848363, -0.22772171010367373,
      -0.96068512970551045, -1.3395818493075793, -1.5137716134121004,
      -1.1830392034670809, -0.6760017168478718, 0.12788502014594957,
      0.76865696145923246, 1.3210254210656935, 1.3825659513249009,
      1.1776863456184838, 0.509619378584437, -0.19151828744050023,
      -0.97474485376967723, -1.3665152327026242, -1.4940509195371137,
      -1.0674000856622183, -0.45260539085422774, 0.41490264850194564,
      1.0272069853858299, 1.4377782920916038, 1.2688628832619235,
      0.810644046176871, -0.041015584211126881, -0.77226533224888416,
      -1.3881168506751831, -1.4391807198676907, -1.1443182514527785,
      -0.35315179230074978, 0.4291840507853068, 1.1776863456184803,
      1.3890148309421508, 1.2241633474703162, 0.49317617287522708,
      -0.30861883034005011, -1.1349336696748449, -1.4430468946081263,
      -1.353519585279864, -0.65271161775993114, 0.16405246275899521,
      1.0293356096197122, 1.3722316059762065, 1.2928605654593059,
      0.57659349214159161, -0.26378129885382495, -1.1348093952257554,
      -1.4483505728618988, -1.3082156073095106, -0.52736438874367764,
      0.34251022640530043, 1.1776863456185624, 1.3891163551237387,
      1.1157841607874102, 0.23166386039969653, -0.65271161775992281,
      -1.387737810235822, -1.4122136545356458, -0.94159460122289873,
      0.054865613210678128, 0.89866841894857641, 1.4377782920915503,
      1.1861164371024422, 0.48448553721978238, -0.57809796556625614,
      -1.2712084867456279, -1.4933978018498197, -0.89941847316550183,
      0.00063571317389858617, 1.0031432322900675, 1.383815082681729,
      1.1776863456184938, 0.24969528350793502, -0.70929019286049255,
      -1.4420846460640118, -1.3395818493075733, -0.67504001566122385,
      0.44112855696320113, 1.1977487534104885, 1.4186191384097342,
      0.750761239417685, -0.22772171010371833, -1.2171884794800896,
      -1.4483505728620525, -1.012687151539436, 0.082274052086257363,
      1.003417058333492, 1.4552406535776043, 0.94915579146909457,
      -0.0091463750542371183, -1.0964661689738009, -1.4557003793577761,
      -1.09322214542873, 0.0091463750542701925, 0.97828942874420755,
      1.4552406535776079, 0.92264542876761824, -0.082274052086159427,
      -1.1709125679174339, -1.4483505728619452, -0.95586778969742048,
      0.22772171010373748, 1.1398074595249861, 1.4186191384096909,
      0.65777542607126493, -0.441128556963233, -1.3874253382022863,
      -1.3395818493075586, -0.53912236934032642, 0.70929019286043271,
      1.3557143673408407, 1.1776863456185516, 0.069299394497803063,
      -1.0031432322900375, -1.5196003843927595, -0.8994184731653373,
      0.21859014396947191, 1.2712084867457221, 1.2971368801610454,
      0.48448553721972903, -0.80836818550107781, -1.4377782920916191,
      -1.1558059937017391, 0.054865613210712309, 1.0973507919455234,
      1.4122136545356403, 0.54407328518721021, -0.65271161775990993,
      -1.4903533300106746, -1.1157841607873353, -0.017347763618596933,
      1.1776863456185336, 1.3319081448120604, 0.52736438874380787,
      -0.82399721577629148, -1.4483505728620147, -1.0534714756143144,
      0.26378129885388762, 1.2409158650261194, 1.2928605654593295,
      0.16013253784557754, -1.0293356096197728, -1.5027441788300062,
      -0.652711617759908, 0.6138235218960022, 1.4430468946081112,
      0.9228149046898616, -0.30861883034000726, -1.4093259735442574,
      -1.2241633474702651, -0.10874542139782474, 1.1776863456184534,
      1.3035624181998031, 0.35315179230064431, -1.0433095667486212,
      -1.4391807198677067, -0.67473631942089873, 0.77226533224887228,
      1.390194070208346, 0.81064404617697339, -0.64551110459008854,
      -1.4377782920915105, -1.0262364941764393, 0.41490264850177394,
      1.3382244236869039, 1.0674000856622352, -0.34926632480246078,
      -1.366515232702727, -1.2027706765318877, 0.19151828744054647,
      1.2716163100927329, 1.1776863456184938, -0.20453216467389448,
      -1.3210254210658261, -1.2575530865404105, 0.12788502014594888,
      1.2567288735843483, 1.1830392034670498, -0.22271944272960292,
      -1.3395818493076368, -1.2140749563800999, 0.22772171010384165,
      1.3051676511105395, 1.0858668083725471, -0.40284524517638037,
      -1.40766443257531, -1.0533700314648591, 0.48448553721977894,
      1.3756173191281034, 0.84822275230161681, -0.72814430378110673,
      -1.4557003793577414, -0.72406665993026242, 0.86302189801333284,
      1.3691874920762994, 0.41490264850180031, -1.1341786814550261,
      -1.3568162719938683, -0.18171476567685391, 1.2576136461436467,
      1.1374750059650436, -0.22772171010372344, -1.4637532395295874,
      -0.955792133730518, 0.531742271783323, 1.4556716450785845,
      0.5442310794247488, -0.95579213373045468, -1.4572284819286119,
      -0.17336978113051607, 1.1889377638356, 1.177686345618429,
      -0.3849871277058235, -1.4316015579893222, -0.8663253428214428,
      0.81064404617689567, 1.3625293640369607, 0.28175003406603955,
      -1.280626072237885, -1.1988167147811954, 0.25458668863814521,
      1.4377782920915059, 0.67384921579462809, -0.899418473165497,
      -1.4572102159097016, -0.10053070563090326, 1.2567951537577555,
      1.0357827552401506, -0.66214397536376457, -1.4522249039620809,
      -0.46911622345693565, 1.1776863456184616, 1.1375116912334364,
      -0.37086984202659834, -1.5162128252925446, -0.5865110513141335,
      1.0037744305990637, 1.2800210863197903, -0.31320158801883241,
      -1.4391807198676942, -0.72401124609260747, 1.0293356096196937,
      1.2308254061005535, -0.23675098307184872, -1.5060254370005177,
      -0.62807072937389141, 1.0037837872148778, 1.2576136461436005,
      -0.40277063155041032, -1.4533735152450185, -0.5561150905711989,
      1.1776863456184452, 1.0836615950725286, -0.54437255765692,
      -1.5123212096162606, -0.23675098307185632, 1.2568233290714976,
      0.93492743087263375, -0.90032289616763428, -1.3665152327026466,
      0.0741121056229236, 1.4377782920916096, 0.51087302480934793,
      -1.155812124518004, -1.2026555538608998, 0.61151895421193647,
      1.3625766771030725, 0.054865613210758966, -1.4686527360028307,
      -0.69326013374393691, 1.0282981079035971, 1.1776863456185247,
      -0.645374289899419, -1.4281738384265144, -0.09029803308360064,
      1.4186191384097773, 0.54429807097432825, -1.1722869947294523,
      -1.1433624156108992, 0.74886982448239825, 1.3037221699553405,
      -0.22772171010379169, -1.5201927028930158, -0.30861883034018095,
      1.2788759490001409, 0.78771041199955483, -1.1340912351346777,
      -1.1558121245180675, 0.614007701848837, 1.3815996183093282,
      -0.29511469811992835, -1.4557003793577274, -0.29059636992664156,
      1.3872523889667498, 0.57734027229214047, -1.198816714781195,
      -1.0532610982231179, 0.92083262466729787, 1.1772526192293844,
      -0.58651105131411518, -1.4623880475344559, 0.22772171010373454,
      1.3897819951310932, 0.12788502014604453, -1.4901146684241171,
      -0.45852599615469036, 1.2568606094400159, 0.74886982448242179,
      -1.2278493075923951, -0.98980839135173271, 0.89926488449688025,
      1.1776863456184696, -0.80809878706098515, -1.3132367468838284,
      0.44729542114839055, 1.4004240464804367, -0.3491101507164826,
      -1.4453395841299956, 0.0011729436113865619, 1.4552406535776004,
      0.069602407758901835, -1.4377782920915687, -0.380432433966106,
      1.4004240464804758, 0.40857758912812986, -1.350082261542799,
      -0.67455370466484721, 1.2928605654593, 0.65811543050002264,
      -1.2339650931322912, -0.88144074662813532, 1.1776863456184685,
      0.82529446653957439, -1.1274443985450486, -1.0122447546015847,
      1.08586680837258, 0.92302638924031621, -1.0548778365160496,
      -1.0797841731971509, 1.0357827552401679, 0.96261592124327677,
      -1.0293356096196602, -1.0928177213680061, 1.035782755240154,
      0.94958237307251736, -1.0548778365160949, -1.0532281893650193,
      1.085866808372546, 0.88204295447695646, -1.1274443985450591,
      -0.95549626666421328, 1.1776863456184978, 0.75123894650350476,
      -1.2339650931322566, -0.788317230624646, 1.2928605654594041,
      0.54435190454009208, -1.3500822615426791, -0.53877938925276658,
      1.4004240464805278, 0.25023063384144423, -1.4377782920915381,
      -0.19980420788350894, 1.4552406535776179, -0.13137474373597796,
      -1.4453395841300476, 0.2189083505919418, 1.4004240464804341,
      -0.57749722127287739, -1.3132367468838542, 0.67789698693638678,
      1.1776863456184803, -1.0294666846216265, -0.98980839135173526,
      1.0976475074676413, 0.74886982448236639, -1.3870624095647619,
      -0.45852599615477907, 1.3599128682993886, 0.12788502014585112,
      -1.519983795255746, 0.22772171010371484, 1.3321862474098451,
      -0.58651105131417092, -1.3074544193539035, 0.92083262466730031,
      0.92305929809849574, -1.1988167147811595, -0.707542072416772,
      1.3872523889667006, 0.16039456980194708, -1.4557003793577612,
      0.16491289799534806, 1.3815996183092361, -0.74420950197335967,
      -1.1558121245181157, 1.0038894350100847, 0.78771041199955338,
      -1.4090777491246156, -0.30861883034005144, 1.3899909027684587,
      -0.2277217101036676, -1.4339239700800257, 0.7488698244824,
      1.0131606154862653, -1.1722869947295176, -0.67449987109899989,
      1.418619138409752, -0.0399037670410758, -1.4281738384265648,
      0.51517248977477759, 1.1776863456184279, -1.1584999080283276,
      -0.69326013374405726, 1.3384509358780849, 0.054865613210692235,
      -1.4927784772278314, 0.61151895421183255, 1.0724537537362147,
      -1.1558121245180575, -0.64107482493411072, 1.4377782920916458,
      -0.20431390574770464, -1.36651523270265, 0.7701210960429653,
      0.93492743087268049, -1.3870251291961482, -0.23675098307184089,
      1.382119409491706, -0.544372557656904, -1.2138633951971021,
      1.1776863456184858, 0.42591329044654, -1.4533735152449072,
      0.27256883142569083, 1.2576136461437066, -1.1339855873395659,
      -0.62807072937388875, 1.3758236368757704, -0.2367509830718528,
      -1.361027206225252, 1.0293356096197301, 0.59380944596800334,
      -1.4391807198677187, 0.18299978789420587, 1.2800210863198915,
      -1.1339762307236698, -0.58651105131402725, 1.3860110251679174,
      -0.370869842026528, -1.2677134913580177, 1.1776863456184294,
      0.33891442333237431, -1.4522249039621558, 0.5319421752391521,
      1.0357827552401526, -1.3869969538825058, -0.10053070563081196,
      1.327008415785019, -0.89941847316541779, -0.80405101591920958,
      1.4377782920915869, -0.3847884887628078, -1.1988167147811117,
      1.1504242721133169, 0.28175003406601756, -1.4927311641614709,
      0.81064404617697638, 0.73612354269675639, -1.4316015579892107,
      0.25478532758125305, 1.1776863456184854, -1.3191395639603036,
      -0.17336978113045745, 1.3270266818039349, -0.95579213373053828,
      -0.67443287954935727, 1.4556716450785707, -0.66194407190811844,
      -0.95579213373033323, 1.3335514394049581, -0.2277217101037346,
      -1.2676768060896195, 1.257613646143604, 0.051512965552237368,
      -1.3568162719937695, 1.0039768813304011, 0.4149026485017856,
      -1.4993892922009791, 0.86302189801334028, 0.59386485980554371,
      -1.4557003793577477, 0.59794250365651969, 0.84822275230168265,
      -1.5058191192527788, 0.4844855372199377, 0.92316823134012027,
      -1.4076644325752481, 0.27264344505173266, 1.0858668083725367,
      -1.4353694512352848, 0.22772171010371353, 1.0838731562553903,
      -1.3395818493076328, 0.092517642605166345, 1.1830392034669606,
      -1.3869306737089961, 0.12788502014600911, 1.1273512864157602,
      -1.3210254210657222, 0.074330364549315908, 1.1776863456184214,
      -1.4018181102174172, 0.19151828744069138, 1.0725688764072507,
      -1.3665152327027343, 0.21906452467786056, 1.0674000856623069,
      -1.4684262238115902, 0.41490264850191649, 0.89603469405174252,
      -1.4377782920916045, 0.51530930446543832, 0.8106440461769221,
      -1.5203958703330613, 0.77226533224885685, 0.54453451929626651,
      -1.4391807198676698, 0.91310776662404813, 0.35315179230078103,
      -1.4337642183244119, 1.1776863456185114, -0.021456378726847185,
      -1.224163347470278, 1.2791241734196717, -0.30861883034028342,
      -1.0530167048143884, 1.4430468946080341, -0.74402532202059068,
      -0.65271161775996078, 1.3725423787054358, -1.029335609619747,
      -0.29033433797008151, 1.2928605654592347, -1.3711176651507677,
      0.26378129885381613, 0.92326967548964889, -1.4483505728620656,
      0.69379541565160563, 0.52736438874375846, -1.4621099449367405,
      1.1776863456185143, -0.112854036506226, -1.1157841607872996,
      1.3601515298859117, -0.65271161775992592, -0.67427508531180935,
      1.4122136545356974, -1.2275525920702057, 0.054865613210736186,
      1.0256041935771123, -1.43777829209165, 0.67816638537666762,
      0.48448553721962528, -1.4273386802856318, 1.2712084867456805,
      -0.34879194409423425, -0.89941847316536472, 1.3893985842680106,
      -1.003143232290145, -0.19950119462253013, 1.1776863456184736,
      -1.4859161674655328, 0.70929019286054074, 0.40892056921564224,
      -1.3395818493075489, 1.2572235380776606, -0.44112855696326947,
      -0.78797722619582544, 1.4186191384097382, -1.2700092596496475,
      0.22772171010373671, 0.82566598957261794, -1.4483505728620081,
      1.0407107677927065, -0.082274052086266744, -1.0528472288922452,
      1.45524065357764, -1.1084912288689051, 0.0091463750543167958,
      0.96302034530398273, -1.455700379357745, 0.96626436884927847,
      -0.0091463750543276968, -1.0793575915936617, 1.4552406535775826,
      -1.1336188584580891, 0.082274052086226443, 0.88248535141478046,
      -1.4483505728620867, 1.0869866793555272, -0.22772171010377112,
      -0.88096303954227606, 1.4186191384097468, -1.3279505535351761,
      0.44112855696327719, 0.5448382155364907, -1.3395818493075224,
      1.3118828459393999, -0.70929019286055672, -0.37989708363247648,
      1.1776863456184044, -1.5140168828063767, 1.003143232290137,
      -0.13083751329847434, -0.89941847316540169, 1.3631960017252014,
      -1.27120848674571, 0.44789616544159871, 0.48448553721974807,
      -1.316318237227059, 1.4377782920915738, -1.0288702190732404,
      0.05486561321074937, 0.81139280109818979, -1.4122136545356749,
      1.2575360101111894, -0.6527116177599992, -0.36186566052418156,
      1.1157841607873515, -1.5193181552484447, 1.1776863456185462,
      -0.47271202653016109, -0.52736438874365266, 1.1780138071847031,
      -1.4483505728620631, 1.0046075951010478, -0.26378129885393331,
      -0.70679529226608551, 1.2928605654592518, -1.5024334061008815,
      1.0293356096197015, -0.29425426288362916, -0.65271161775987208,
      1.2233177851551775, -1.4430468946080524, 1.004731869550199,
      -0.3086188303401356, -0.62337797299980258, 1.2241633474701847,
      -1.5192166310667587, 1.1776863456183744, -0.55938585090982362,
      -0.35315179230085608, 1.0141164513281435, -1.4391807198676618,
      1.2579150505505554, -0.77226533224885985, -0.089186215913422476,
      0.81064404617691777, -1.3990646833865563, 1.4377782920915527,
      -1.1574087855105366, 0.41490264850178504, 0.32240359072949965,
      -1.0674000856623684, 1.3638491194125963, -1.3665152327029224,
      0.84454305364511262, -0.19151828744066315, -0.63982117870918676,
      1.1776863456185318, -1.5127677514495259, 1.3210254210658088,
      -0.89885876158396028, 0.1278850201459926, 0.545799916723219,
      -1.1830392034670683, 1.3835698132874794, -1.3395818493076503,
      0.830483329580988, -0.22772171010383632, -0.55442007705301821,
      1.0858668083724969, -1.4794192399600732, 1.4076644325752956,
      -1.1322949342119526, 0.48448553721983212, 0.14410218589222856,
      -0.84822275230166078, 1.2328012777773198, -1.4557003793577841,
      1.234955229690764, -0.86302189801333684, 0.18498659299551695,
      0.414902648501638, -1.0510817449771506, 1.3568162719936807,
      -1.5138915691857173, 1.2576136461436593, -0.8828783813763631,
      0.22772171010373191, 0.3412701605911389, -0.9557921337303471,
      1.265116654566788, -1.455671645078475, 1.2595462288027981,
      -0.955792133730412, 0.36353198918392482, 0.17336978113049767,
      -0.80123025154079164, 1.1776863456183291, -1.4821923719576962,
      1.4316015579891641, -1.2773330412704402, 0.81064404617693675,
      -0.34574288129896963, -0.281750034065993, 0.73953819614536,
      -1.1988167147810709, 1.3587331781044041, -1.43777829209162,
      1.1929241454707431, -0.8994184731655066, 0.36482849652080546,
      0.10053070563079644, -0.6702485434831269, 1.0357827552400485,
      -1.3882450143155185, 1.4522249039620709, -1.4588653551808586,
      1.17768634561858, -0.88018011068225244, 0.37086984202668194,
      0.056711410363106618, -0.58651105131402959, 0.92865502886818641,
      -1.280021086319902, 1.3752689087339929, -1.4391807198678228,
      1.2392833559104064, -1.0293356096198547, 0.60450216853350458,
      -0.23675098307193798, -0.26536775372710247, 0.62807072937388531,
      -1.0456760858601803, 1.2576136461436973, -1.4730703442159516,
      1.4533735152450495, -1.4269439427535768, 1.1776863456184183,
      -0.94997043586982688, 0.54437255765680381, -0.21279669682045491,
      -0.23675098307188724, 0.55479723929565394, -0.93492743087262375,
      1.1383954941810974, -1.366515232702662, 1.3959424825157043,
      -1.437778292091487, 1.2846993780919198, -1.1558121245181248,
      0.85718397020424575, -0.61151895421185354, 0.23388296054012553,
      0.054865613210535805, -0.43523691872232451, 0.69326013374395412,
      -1.0085425982945573, 1.1776863456183679, -1.3811858199949796,
      1.4281738384264413, -1.499974434293907, 1.4186191384097075,
      -1.3646644747278753, 1.1722869947295187, -1.0186734184800681,
      0.74886982448237061, -0.53365800214801551, 0.22772171010375114,
      0.0075572742070260622, -0.30861883034006332, 0.52613467615250908,
      -0.78771041199959346, 0.9582655586711365, -1.1558121245179875,
      1.2612903248241041, -1.3815996183093255, 1.4151962947585519,
      -1.4557003793577941, 1.4205000555140115, -1.387252388966794,
      1.2938224551825153, -1.1988167147813031, 1.062441968017799,
      -0.92083262466735216, 0.75888051610009921, -0.586511051314065,
      0.41624793360425388, -0.22772171010379758, 0.064736670994190865,
      0.1278850201458468, -0.27062498991138861, 0.45852599615470968,
      -0.57105735262997093, 0.74886982448235218, -0.8241689822393431,
      0.98980839135184451, -1.0234189845169082, 1.1776863456184556,
      -1.1671656637555923, 1.3132367468837751, -1.2575283131315891,
      1.4004240464805091, -1.2992358042916305, 1.4453395841299379,
      -1.2985796232401934, 1.4552406535776168, -1.2625385681734598,
      1.4377782920915385, -1.1981019353076048, 1.4004240464805029,
      -1.1117890274721534, 1.3500822615426913, -1.0093445368302685,
      1.2928605654592793, -0.8955799642523784, 1.2339650931322539,
      -0.77432851183227314, 1.1776863456184916, -0.64848264009609913,
      1.1274443985451252, -0.52008784874624892, 1.0858668083725425,
      -0.39047176930888561, 1.0548778365160858, -0.2603933200625505,
      1.0357827552401586, -0.13020180012464427, 1.0293356096196626,
      4.0590492605963612E-14, 1.035782755240044, 0.13019151993794872,
      1.0548778365160583, 0.26026996918415751, 1.0858668083725957,
      0.38988604862150356, 1.1274443985450744, 0.51828083997134644,
      1.177686345618504, 0.64412671170758262, 1.2339650931322783,
      0.76537816412775173, 1.2928605654592691, 0.87914273670568588,
      1.3500822615427905, 0.98158722734754988, 1.4004240464805378,
      1.0679001351829045, 1.4377782920916087, 1.1323367680488143,
      1.4552406535777005, 1.1683778231154796, 1.4453395841300156,
      1.1690340041670173, 1.4004240464805431, 1.1273265130069039,
      1.3132367468838106, 1.0369638636309571, 1.1776863456184878,
      0.89321718439226583, 0.98980839135177612, 0.69396718211468245,
      0.748869824482328, 0.44085555250542841, 0.45852599615477618,
      0.14042318978684099, 0.12788502014596068, -0.19493847111874318,
      -0.22772171010366385, -0.54644973372888417, -0.58651105131397929,
      -0.889082316224844, -0.92083262466724469, -1.1926437681423814,
      -1.19881671478117, -1.4240242553070055, -1.3872523889667707,
      -1.5507018556385745, -1.455700379357697, -1.5453980948832262,
      -1.3815996183092807, -1.3914921249488947, -1.1558121245179864,
      -1.0884673587958802, -0.787710411999592, -0.65633647627721792,
      -0.30861883034004162, -0.13775907433169526, 0.22772171010368611,
      0.40345620202328109, 0.74886982448244488, 0.88847161835529953,
      1.1722869947295302, 1.2344626746031391, 1.4186191384097977,
      1.3697726341693002, 1.4281738384265719, 1.2509840198704123,
      1.177686345618479, 0.87834079817005228, 0.69326013374399176,
      0.30503511859788274, 0.054865613210687093, -0.36408476066473267,
      -0.61151895421178737, -0.98738577032891583, -1.155812124518002,
      -1.4149011782165808, -1.4377782920915374, -1.5261442826405069,
      -1.3665152327026746, -1.2685972943057309, -0.93492743087270214,
      -0.68499903942032536, -0.23675098307180525, 0.082594896695794048,
      0.5443725576568661, 0.81976863574522707, 1.1776863456184377,
      1.2967421426289536, 1.4533735152450413, 1.3428685440911681,
      1.2576136461436609, 0.91547428573555367, 0.62807072937396113,
      0.13516595360252823, -0.23675098307178982, -0.734703968658123,
      -1.0293356096196526, -1.3694851560349126, -1.4391807198676174,
      -1.5054707088585906, -1.2800210863198282, -1.0588568289927562,
      -0.586511051314125, -0.18691321048778273, 0.37086984202646028,
      0.74997831055754538, 1.177686345618469, 1.3286635550561614,
      1.4522249039620285, 1.2580432141909075, 1.0357827552401584,
      0.54004674335855418, 0.10053070563096483, -0.49503029664539017,
      -0.89941847316540879, -1.3231259455953868, -1.437778292091489,
      -1.4889349782291028, -1.1988167147811311, -0.86973999627013254,
      -0.28175003406614157, 0.21554108117423046, 0.81064404617692087,
      1.1471312411458672, 1.4316015579892569, 1.3519905718332028,
      1.1776863456184279, 0.67102845141625389, 0.1733697811305229,
      -0.49373378930857903, -0.95579213373044536, -1.3897480289275539,
      -1.4556716450784986, -1.3953184546915511, -0.95579213373041827,
      -0.47147196071595832, 0.22772171010376285, 0.75267658125167747,
      1.2576136461436522, 1.3836897690610948, 1.3568162719938555,
      0.92087994485261393, 0.414902648501887, -0.31518839312013824,
      -0.86302189801317264, -1.3651570298154858, -1.4557003793576759,
      -1.3630030779019859, -0.84822275230162525, -0.27430398601701145,
      0.484485537219845, 1.0020931340872583, 1.4076644325753227,
      1.3492174398353682, 1.0858668083725245, 0.42421827692848363,
      -0.22772171010367373, -0.96068512970551045, -1.3395818493075793,
      -1.5137716134121004, -1.1830392034670809, -0.6760017168478718,
      0.12788502014594957, 0.76865696145923246, 1.3210254210656935,
      1.3825659513249009, 1.1776863456184838, 0.509619378584437,
      -0.19151828744050023, -0.97474485376967723, -1.3665152327026242,
      -1.4940509195371137, -1.0674000856622183, -0.45260539085422774,
      0.41490264850194564, 1.0272069853858299, 1.4377782920916038,
      1.2688628832619235, 0.810644046176871, -0.041015584211126881,
      -0.77226533224888416, -1.3881168506751831, -1.4391807198676907,
      -1.1443182514527785, -0.35315179230074978, 0.4291840507853068,
      1.1776863456184803, 1.3890148309421508, 1.2241633474703162,
      0.49317617287522708, -0.30861883034005011, -1.1349336696748449,
      -1.4430468946081263, -1.353519585279864, -0.65271161775993114,
      0.16405246275899521, 1.0293356096197122, 1.3722316059762065,
      1.2928605654593059, 0.57659349214159161, -0.26378129885382495,
      -1.1348093952257554, -1.4483505728618988, -1.3082156073095106,
      -0.52736438874367764, 0.34251022640530043, 1.1776863456185624,
      1.3891163551237387, 1.1157841607874102, 0.23166386039969653,
      -0.65271161775992281, -1.387737810235822, -1.4122136545356458,
      -0.94159460122289873, 0.054865613210678128, 0.89866841894857641,
      1.4377782920915503, 1.1861164371024422, 0.48448553721978238,
      -0.57809796556625614, -1.2712084867456279, -1.4933978018498197,
      -0.89941847316550183, 0.00063571317389858617, 1.0031432322900675,
      1.383815082681729, 1.1776863456184938, 0.24969528350793502,
      -0.70929019286049255, -1.4420846460640118, -1.3395818493075733,
      -0.67504001566122385, 0.44112855696320113, 1.1977487534104885,
      1.4186191384097342, 0.750761239417685, -0.22772171010371833,
      -1.2171884794800896, -1.4483505728620525, -1.012687151539436,
      0.082274052086257363, 1.003417058333492, 1.4552406535776043,
      0.94915579146909457, -0.0091463750542371183, -1.0964661689738009,
      -1.4557003793577761, -1.09322214542873, 0.0091463750542701925,
      0.97828942874420755, 1.4552406535776079, 0.92264542876761824,
      -0.082274052086159427, -1.1709125679174339, -1.4483505728619452,
      -0.95586778969742048, 0.22772171010373748, 1.1398074595249861,
      1.4186191384096909, 0.65777542607126493, -0.441128556963233,
      -1.3874253382022863, -1.3395818493075586, -0.53912236934032642,
      0.70929019286043271, 1.3557143673408407, 1.1776863456185516,
      0.069299394497803063, -1.0031432322900375, -1.5196003843927595,
      -0.8994184731653373, 0.21859014396947191, 1.2712084867457221,
      1.2971368801610454, 0.48448553721972903, -0.80836818550107781,
      -1.4377782920916191, -1.1558059937017391, 0.054865613210712309,
      1.0973507919455234, 1.4122136545356403, 0.54407328518721021,
      -0.65271161775990993, -1.4903533300106746, -1.1157841607873353,
      -0.017347763618596933, 1.1776863456185336, 1.3319081448120604,
      0.52736438874380787, -0.82399721577629148, -1.4483505728620147,
      -1.0534714756143144, 0.26378129885388762, 1.2409158650261194,
      1.2928605654593295, 0.16013253784557754, -1.0293356096197728,
      -1.5027441788300062, -0.652711617759908, 0.6138235218960022,
      1.4430468946081112, 0.9228149046898616, -0.30861883034000726,
      -1.4093259735442574, -1.2241633474702651, -0.10874542139782474,
      1.1776863456184534, 1.3035624181998031, 0.35315179230064431,
      -1.0433095667486212, -1.4391807198677067, -0.67473631942089873,
      0.77226533224887228, 1.390194070208346, 0.81064404617697339,
      -0.64551110459008854, -1.4377782920915105, -1.0262364941764393,
      0.41490264850177394, 1.3382244236869039, 1.0674000856622352,
      -0.34926632480246078, -1.366515232702727, -1.2027706765318877,
      0.19151828744054647, 1.2716163100927329, 1.1776863456184938,
      -0.20453216467389448, -1.3210254210658261, -1.2575530865404105,
      0.12788502014594888, 1.2567288735843483, 1.1830392034670498,
      -0.22271944272960292, -1.3395818493076368, -1.2140749563800999,
      0.22772171010384165, 1.3051676511105395, 1.0858668083725471,
      -0.40284524517638037, -1.40766443257531, -1.0533700314648591,
      0.48448553721977894, 1.3756173191281034, 0.84822275230161681,
      -0.72814430378110673, -1.4557003793577414, -0.72406665993026242,
      0.86302189801333284, 1.3691874920762994, 0.41490264850180031,
      -1.1341786814550261, -1.3568162719938683, -0.18171476567685391,
      1.2576136461436467, 1.1374750059650436, -0.22772171010372344,
      -1.4637532395295874, -0.955792133730518, 0.531742271783323,
      1.4556716450785845, 0.5442310794247488, -0.95579213373045468,
      -1.4572284819286119, -0.17336978113051607, 1.1889377638356,
      1.177686345618429, -0.3849871277058235, -1.4316015579893222,
      -0.8663253428214428, 0.81064404617689567, 1.3625293640369607,
      0.28175003406603955, -1.280626072237885, -1.1988167147811954,
      0.25458668863814521, 1.4377782920915059, 0.67384921579462809,
      -0.899418473165497, -1.4572102159097016, -0.10053070563090326,
      1.2567951537577555, 1.0357827552401506, -0.66214397536376457,
      -1.4522249039620809, -0.46911622345693565, 1.1776863456184616,
      1.1375116912334364, -0.37086984202659834, -1.5162128252925446,
      -0.5865110513141335, 1.0037744305990637, 1.2800210863197903,
      -0.31320158801883241, -1.4391807198676942, -0.72401124609260747,
      1.0293356096196937, 1.2308254061005535, -0.23675098307184872,
      -1.5060254370005177, -0.62807072937389141, 1.0037837872148778,
      1.2576136461436005, -0.40277063155041032, -1.4533735152450185,
      -0.5561150905711989, 1.1776863456184452, 1.0836615950725286,
      -0.54437255765692, -1.5123212096162606, -0.23675098307185632,
      1.2568233290714976, 0.93492743087263375, -0.90032289616763428,
      -1.3665152327026466, 0.0741121056229236, 1.4377782920916096,
      0.51087302480934793, -1.155812124518004, -1.2026555538608998,
      0.61151895421193647, 1.3625766771030725, 0.054865613210758966,
      -1.4686527360028307, -0.69326013374393691, 1.0282981079035971,
      1.1776863456185247, -0.645374289899419, -1.4281738384265144,
      -0.09029803308360064, 1.4186191384097773, 0.54429807097432825,
      -1.1722869947294523, -1.1433624156108992, 0.74886982448239825,
      1.3037221699553405, -0.22772171010379169, -1.5201927028930158,
      -0.30861883034018095, 1.2788759490001409, 0.78771041199955483,
      -1.1340912351346777, -1.1558121245180675, 0.614007701848837,
      1.3815996183093282, -0.29511469811992835, -1.4557003793577274,
      -0.29059636992664156, 1.3872523889667498, 0.57734027229214047,
      -1.198816714781195, -1.0532610982231179, 0.92083262466729787,
      1.1772526192293844, -0.58651105131411518, -1.4623880475344559,
      0.22772171010373454, 1.3897819951310932, 0.12788502014604453,
      -1.4901146684241171, -0.45852599615469036, 1.2568606094400159,
      0.74886982448242179, -1.2278493075923951, -0.98980839135173271,
      0.89926488449688025, 1.1776863456184696, -0.80809878706098515,
      -1.3132367468838284, 0.44729542114839055, 1.4004240464804367,
      -0.3491101507164826, -1.4453395841299956, 0.0011729436113865619,
      1.4552406535776004, 0.069602407758901835, -1.4377782920915687,
      -0.380432433966106, 1.4004240464804758, 0.40857758912812986,
      -1.350082261542799, -0.67455370466484721, 1.2928605654593,
      0.65811543050002264, -1.2339650931322912, -0.88144074662813532,
      1.1776863456184685, 0.82529446653957439, -1.1274443985450486,
      -1.0122447546015847, 1.08586680837258, 0.92302638924031621,
      -1.0548778365160496, -1.0797841731971509, 1.0357827552401679,
      0.96261592124327677, -1.0293356096196602, -1.0928177213680061,
      1.035782755240154, 0.94958237307251736, -1.0548778365160949,
      -1.0532281893650193, 1.085866808372546, 0.88204295447695646,
      -1.1274443985450591, -0.95549626666421328, 1.1776863456184978,
      0.75123894650350476, -1.2339650931322566, -0.788317230624646,
      1.2928605654594041, 0.54435190454009208, -1.3500822615426791,
      -0.53877938925276658, 1.4004240464805278, 0.25023063384144423,
      -1.4377782920915381, -0.19980420788350894, 1.4552406535776179,
      -0.13137474373597796, -1.4453395841300476, 0.2189083505919418,
      1.4004240464804341, -0.57749722127287739, -1.3132367468838542,
      0.67789698693638678, 1.1776863456184803, -1.0294666846216265,
      -0.98980839135173526, 1.0976475074676413, 0.74886982448236639,
      -1.3870624095647619, -0.45852599615477907, 1.3599128682993886,
      0.12788502014585112, -1.519983795255746, 0.22772171010371484,
      1.3321862474098451, -0.58651105131417092, -1.3074544193539035,
      0.92083262466730031, 0.92305929809849574, -1.1988167147811595,
      -0.707542072416772, 1.3872523889667006, 0.16039456980194708,
      -1.4557003793577612, 0.16491289799534806, 1.3815996183092361,
      -0.74420950197335967, -1.1558121245181157, 1.0038894350100847,
      0.78771041199955338, -1.4090777491246156, -0.30861883034005144,
      1.3899909027684587, -0.2277217101036676, -1.4339239700800257,
      0.7488698244824, 1.0131606154862653, -1.1722869947295176,
      -0.67449987109899989, 1.418619138409752, -0.0399037670410758,
      -1.4281738384265648, 0.51517248977477759, 1.1776863456184279,
      -1.1584999080283276, -0.69326013374405726, 1.3384509358780849,
      0.054865613210692235, -1.4927784772278314, 0.61151895421183255,
      1.0724537537362147, -1.1558121245180575, -0.64107482493411072,
      1.4377782920916458, -0.20431390574770464, -1.36651523270265,
      0.7701210960429653, 0.93492743087268049, -1.3870251291961482,
      -0.23675098307184089, 1.382119409491706, -0.544372557656904,
      -1.2138633951971021, 1.1776863456184858, 0.42591329044654,
      -1.4533735152449072, 0.27256883142569083, 1.2576136461437066,
      -1.1339855873395659, -0.62807072937388875, 1.3758236368757704,
      -0.2367509830718528, -1.361027206225252, 1.0293356096197301,
      0.59380944596800334, -1.4391807198677187, 0.18299978789420587,
      1.2800210863198915, -1.1339762307236698, -0.58651105131402725,
      1.3860110251679174, -0.370869842026528, -1.2677134913580177,
      1.1776863456184294, 0.33891442333237431, -1.4522249039621558,
      0.5319421752391521, 1.0357827552401526, -1.3869969538825058,
      -0.10053070563081196, 1.327008415785019, -0.89941847316541779,
      -0.80405101591920958, 1.4377782920915869, -0.3847884887628078,
      -1.1988167147811117, 1.1504242721133169, 0.28175003406601756,
      -1.4927311641614709, 0.81064404617697638, 0.73612354269675639,
      -1.4316015579892107, 0.25478532758125305, 1.1776863456184854,
      -1.3191395639603036, -0.17336978113045745, 1.3270266818039349,
      -0.95579213373053828, -0.67443287954935727, 1.4556716450785707,
      -0.66194407190811844, -0.95579213373033323, 1.3335514394049581,
      -0.2277217101037346, -1.2676768060896195, 1.257613646143604,
      0.051512965552237368, -1.3568162719937695, 1.0039768813304011,
      0.4149026485017856, -1.4993892922009791, 0.86302189801334028,
      0.59386485980554371, -1.4557003793577477, 0.59794250365651969,
      0.84822275230168265, -1.5058191192527788, 0.4844855372199377,
      0.92316823134012027, -1.4076644325752481, 0.27264344505173266,
      1.0858668083725367, -1.4353694512352848, 0.22772171010371353,
      1.0838731562553903, -1.3395818493076328, 0.092517642605166345,
      1.1830392034669606, -1.3869306737089961, 0.12788502014600911,
      1.1273512864157602, -1.3210254210657222, 0.074330364549315908,
      1.1776863456184214, -1.4018181102174172, 0.19151828744069138,
      1.0725688764072507, -1.3665152327027343, 0.21906452467786056,
      1.0674000856623069, -1.4684262238115902, 0.41490264850191649,
      0.89603469405174252, -1.4377782920916045, 0.51530930446543832,
      0.8106440461769221, -1.5203958703330613, 0.77226533224885685,
      0.54453451929626651, -1.4391807198676698, 0.91310776662404813,
      0.35315179230078103, -1.4337642183244119, 1.1776863456185114,
      -0.021456378726847185, -1.224163347470278, 1.2791241734196717,
      -0.30861883034028342, -1.0530167048143884, 1.4430468946080341,
      -0.74402532202059068, -0.65271161775996078, 1.3725423787054358,
      -1.029335609619747, -0.29033433797008151, 1.2928605654592347,
      -1.3711176651507677, 0.26378129885381613, 0.92326967548964889,
      -1.4483505728620656, 0.69379541565160563, 0.52736438874375846,
      -1.4621099449367405, 1.1776863456185143, -0.112854036506226,
      -1.1157841607872996, 1.3601515298859117, -0.65271161775992592,
      -0.67427508531180935, 1.4122136545356974, -1.2275525920702057,
      0.054865613210736186, 1.0256041935771123, -1.43777829209165,
      0.67816638537666762, 0.48448553721962528, -1.4273386802856318,
      1.2712084867456805, -0.34879194409423425, -0.89941847316536472,
      1.3893985842680106, -1.003143232290145, -0.19950119462253013,
      1.1776863456184736, -1.4859161674655328, 0.70929019286054074,
      0.40892056921564224, -1.3395818493075489, 1.2572235380776606,
      -0.44112855696326947, -0.78797722619582544, 1.4186191384097382,
      -1.2700092596496475, 0.22772171010373671, 0.82566598957261794,
      -1.4483505728620081, 1.0407107677927065, -0.082274052086266744,
      -1.0528472288922452, 1.45524065357764, -1.1084912288689051,
      0.0091463750543167958, 0.96302034530398273, -1.455700379357745,
      0.96626436884927847, -0.0091463750543276968, -1.0793575915936617,
      1.4552406535775826, -1.1336188584580891, 0.082274052086226443,
      0.88248535141478046, -1.4483505728620867, 1.0869866793555272,
      -0.22772171010377112, -0.88096303954227606, 1.4186191384097468,
      -1.3279505535351761, 0.44112855696327719, 0.5448382155364907,
      -1.3395818493075224, 1.3118828459393999, -0.70929019286055672,
      -0.37989708363247648, 1.1776863456184044, -1.5140168828063767,
      1.003143232290137, -0.13083751329847434, -0.89941847316540169,
      1.3631960017252014, -1.27120848674571, 0.44789616544159871,
      0.48448553721974807, -1.316318237227059, 1.4377782920915738,
      -1.0288702190732404, 0.05486561321074937, 0.81139280109818979,
      -1.4122136545356749, 1.2575360101111894, -0.6527116177599992,
      -0.36186566052418156, 1.1157841607873515, -1.5193181552484447,
      1.1776863456185462, -0.47271202653016109, -0.52736438874365266,
      1.1780138071847031, -1.4483505728620631, 1.0046075951010478,
      -0.26378129885393331, -0.70679529226608551, 1.2928605654592518,
      -1.5024334061008815, 1.0293356096197015, -0.29425426288362916,
      -0.65271161775987208, 1.2233177851551775, -1.4430468946080524,
      1.004731869550199, -0.3086188303401356, -0.62337797299980258,
      1.2241633474701847, -1.5192166310667587, 1.1776863456183744,
      -0.55938585090982362, -0.35315179230085608, 1.0141164513281435,
      -1.4391807198676618, 1.2579150505505554, -0.77226533224885985,
      -0.089186215913422476, 0.81064404617691777, -1.3990646833865563,
      1.4377782920915527, -1.1574087855105366, 0.41490264850178504,
      0.32240359072949965, -1.0674000856623684, 1.3638491194125963,
      -1.3665152327029224, 0.84454305364511262, -0.19151828744066315,
      -0.63982117870918676, 1.1776863456185318, -1.5127677514495259,
      1.3210254210658088, -0.89885876158396028, 0.1278850201459926,
      0.545799916723219, -1.1830392034670683, 1.3835698132874794,
      -1.3395818493076503, 0.830483329580988, -0.22772171010383632,
      -0.55442007705301821, 1.0858668083724969, -1.4794192399600732,
      1.4076644325752956, -1.1322949342119526, 0.48448553721983212,
      0.14410218589222856, -0.84822275230166078, 1.2328012777773198,
      -1.4557003793577841, 1.234955229690764, -0.86302189801333684,
      0.18498659299551695, 0.414902648501638, -1.0510817449771506,
      1.3568162719936807, -1.5138915691857173, 1.2576136461436593,
      -0.8828783813763631, 0.22772171010373191, 0.3412701605911389,
      -0.9557921337303471, 1.265116654566788, -1.455671645078475,
      1.2595462288027981, -0.955792133730412, 0.36353198918392482,
      0.17336978113049767, -0.80123025154079164, 1.1776863456183291,
      -1.4821923719576962, 1.4316015579891641, -1.2773330412704402,
      0.81064404617693675, -0.34574288129896963, -0.281750034065993,
      0.73953819614536, -1.1988167147810709, 1.3587331781044041,
      -1.43777829209162, 1.1929241454707431, -0.8994184731655066,
      0.36482849652080546, 0.10053070563079644, -0.6702485434831269,
      1.0357827552400485, -1.3882450143155185, 1.4522249039620709,
      -1.4588653551808586, 1.17768634561858, -0.88018011068225244,
      0.37086984202668194, 0.056711410363106618, -0.58651105131402959,
      0.92865502886818641, -1.280021086319902, 1.3752689087339929,
      -1.4391807198678228, 1.2392833559104064, -1.0293356096198547,
      0.60450216853350458, -0.23675098307193798, -0.26536775372710247,
      0.62807072937388531, -1.0456760858601803, 1.2576136461436973,
      -1.4730703442159516, 1.4533735152450495, -1.4269439427535768,
      1.1776863456184183, -0.94997043586982688, 0.54437255765680381,
      -0.21279669682045491, -0.23675098307188724, 0.55479723929565394,
      -0.93492743087262375, 1.1383954941810974, -1.366515232702662,
      1.3959424825157043, -1.437778292091487, 1.2846993780919198,
      -1.1558121245181248, 0.85718397020424575, -0.61151895421185354,
      0.23388296054012553, 0.054865613210535805, -0.43523691872232451,
      0.69326013374395412, -1.0085425982945573, 1.1776863456183679,
      -1.3811858199949796, 1.4281738384264413, -1.499974434293907,
      1.4186191384097075, -1.3646644747278753, 1.1722869947295187,
      -1.0186734184800681, 0.74886982448237061, -0.53365800214801551,
      0.22772171010375114, 0.0075572742070260622, -0.30861883034006332,
      0.52613467615250908, -0.78771041199959346, 0.9582655586711365,
      -1.1558121245179875, 1.2612903248241041, -1.3815996183093255,
      1.4151962947585519, -1.4557003793577941, 1.4205000555140115,
      -1.387252388966794, 1.2938224551825153, -1.1988167147813031,
      1.062441968017799, -0.92083262466735216, 0.75888051610009921,
      -0.586511051314065, 0.41624793360425388, -0.22772171010379758,
      0.064736670994190865, 0.1278850201458468, -0.27062498991138861,
      0.45852599615470968, -0.57105735262997093, 0.74886982448235218,
      -0.8241689822393431, 0.98980839135184451, -1.0234189845169082,
      1.1776863456184556, -1.1671656637555923, 1.3132367468837751,
      -1.2575283131315891, 1.4004240464805091, -1.2992358042916305,
      1.4453395841299379, -1.2985796232401934, 1.4552406535776168,
      -1.2625385681734598, 1.4377782920915385, -1.1981019353076048,
      1.4004240464805029, -1.1117890274721534, 1.3500822615426913,
      -1.0093445368302685, 1.2928605654592793, -0.8955799642523784,
      1.2339650931322539, -0.77432851183227314, 1.1776863456184916,
      -0.64848264009609913, 1.1274443985451252, -0.52008784874624892,
      1.0858668083725425, -0.39047176930888561, 1.0548778365160858,
      -0.2603933200625505, 1.0357827552401586, -0.13020180012464427,
      1.0293356096196626 } ;

    test_DW.FromWorkspace_PWORK.TimePtr = (void *) pTimeValues0;
    test_DW.FromWorkspace_PWORK.DataPtr = (void *) pDataValues0;
    test_DW.FromWorkspace_IWORK.PrevIndex = 0;
  }

  /* InitializeConditions for UnitDelay: '<S14>/d' */
  test_DW.d_DSTATE = test_P.d_InitialCondition;

  /* InitializeConditions for UnitDelay: '<S14>/d1' */
  test_DW.d1_DSTATE = test_P.d1_InitialCondition;

  /* InitializeConditions for UnitDelay: '<S16>/d1' */
  test_DW.d1_DSTATE_g = test_P.d1_InitialCondition_g;

  /* InitializeConditions for UnitDelay: '<S16>/d' */
  test_DW.d_DSTATE_o = test_P.d_InitialCondition_a;

  /* InitializeConditions for UnitDelay: '<S62>/Delay Input2' */
  test_DW.DelayInput2_DSTATE = test_P.DelayInput2_InitialCondition;

  /* InitializeConditions for UnitDelay: '<S61>/d1' */
  test_DW.d1_DSTATE_n = test_P.d1_InitialCondition_f;

  /* InitializeConditions for UnitDelay: '<S61>/d' */
  test_DW.d_DSTATE_g = test_P.d_InitialCondition_o;

  /* InitializeConditions for UnitDelay: '<S56>/Delay Input2' */
  test_DW.DelayInput2_DSTATE_a = test_P.DelayInput2_InitialCondition_d;

  /* InitializeConditions for UnitDelay: '<S55>/d1' */
  test_DW.d1_DSTATE_e = test_P.d1_InitialCondition_l;

  /* InitializeConditions for UnitDelay: '<S55>/d' */
  test_DW.d_DSTATE_c = test_P.d_InitialCondition_p;

  /* InitializeConditions for Delay: '<S8>/Delay1' */
  test_DW.Delay1_DSTATE = test_P.Delay1_InitialCondition;

  /* InitializeConditions for UnitDelay: '<S53>/Delay Input2' */
  test_DW.DelayInput2_DSTATE_p = test_P.DelayInput2_InitialCondition_c;

  /* InitializeConditions for UnitDelay: '<S51>/d1' */
  test_DW.d1_DSTATE_p = test_P.d1_InitialCondition_lb;

  /* InitializeConditions for UnitDelay: '<S51>/d' */
  test_DW.d_DSTATE_f = test_P.d_InitialCondition_k;

  /* InitializeConditions for Delay: '<S8>/Delay2' */
  test_DW.Delay2_DSTATE = test_P.Delay2_InitialCondition;

  /* InitializeConditions for UnitDelay: '<S82>/d' */
  test_DW.d_DSTATE_cq = test_P.d_InitialCondition_c;

  /* InitializeConditions for UnitDelay: '<S82>/d1' */
  test_DW.d1_DSTATE_f = test_P.d1_InitialCondition_i;

  /* InitializeConditions for UnitDelay: '<S83>/d1' */
  test_DW.d1_DSTATE_ga = test_P.d1_InitialCondition_gm;

  /* InitializeConditions for UnitDelay: '<S83>/d' */
  test_DW.d_DSTATE_h = test_P.d_InitialCondition_j;

  /* InitializeConditions for UnitDelay: '<S84>/d1' */
  test_DW.d1_DSTATE_d = test_P.d1_InitialCondition_a;

  /* InitializeConditions for UnitDelay: '<S84>/d' */
  test_DW.d_DSTATE_p = test_P.d_InitialCondition_m;

  /* InitializeConditions for Delay: '<S76>/Delay' */
  test_DW.Delay_DSTATE = test_P.Delay_InitialCondition;

  /* InitializeConditions for UnitDelay: '<S80>/d' */
  test_DW.d_DSTATE_fu = test_P.d_InitialCondition_d;

  /* InitializeConditions for UnitDelay: '<S80>/d1' */
  test_DW.d1_DSTATE_fx = test_P.d1_InitialCondition_j;

  /* InitializeConditions for UnitDelay: '<S81>/d1' */
  test_DW.d1_DSTATE_m = test_P.d1_InitialCondition_c;

  /* InitializeConditions for UnitDelay: '<S81>/d' */
  test_DW.d_DSTATE_m = test_P.d_InitialCondition_cw;

  /* InitializeConditions for UnitDelay: '<S59>/Delay Input2' */
  test_DW.DelayInput2_DSTATE_n = test_P.DelayInput2_InitialCondition_a;

  /* InitializeConditions for UnitDelay: '<S58>/d1' */
  test_DW.d1_DSTATE_k = test_P.d1_InitialCondition_p;

  /* InitializeConditions for UnitDelay: '<S58>/d' */
  test_DW.d_DSTATE_ow = test_P.d_InitialCondition_mx;

  /* InitializeConditions for UnitDelay: '<S89>/d1' */
  test_DW.d1_DSTATE_j = test_P.d1_InitialCondition_h;

  /* InitializeConditions for UnitDelay: '<S89>/d' */
  test_DW.d_DSTATE_n = test_P.d_InitialCondition_h;

  /* SystemInitialize for Merge: '<S102>/Merge1' */
  test_B.Merge1 = test_P.Merge1_InitialOutput;

  /* SystemInitialize for MATLAB Function: '<S43>/MATLAB Function' */
  test_DW.current_f_not_empty = false;
}

/* Model terminate function */
void test_terminate(void)
{
  /* Terminate for S-Function (rti_commonblock): '<S10>/S-Function1' incorporates:
   *  Constant: '<S8>/NMT_CS'
   *  Constant: '<S8>/NMT_Node_ID'
   */

  /* dSPACE RTICAN TX Message Block: "NMTZeroMsg" Id:0 */
  {
    /* ... Set the message into sleep mode */
    while ((rtican_type1_tq_error[0][0] = can_tp1_msg_sleep
            (can_type1_msg_M1[CANTP1_M1_C1_TX_STD_0X0])) ==
           DSMCOM_BUFFER_OVERFLOW) ;
  }

  /* Terminate for S-Function (rti_commonblock): '<S20>/S-Function1' */

  /* dSPACE RTICAN RX Message Block: "N30_TPDO2" Id:819 */
  {
    /* ... Set the message into sleep mode */
    while ((rtican_type1_tq_error[0][5] = can_tp1_msg_sleep
            (can_type1_msg_M1[CANTP1_M1_C1_RX_STD_0X333])) ==
           DSMCOM_BUFFER_OVERFLOW) ;
  }

  /* Terminate for S-Function (rti_commonblock): '<S21>/S-Function1' */

  /* dSPACE RTICAN RX Message Block: "N30_TPDO3" Id:820 */
  {
    /* ... Set the message into sleep mode */
    while ((rtican_type1_tq_error[0][5] = can_tp1_msg_sleep
            (can_type1_msg_M1[CANTP1_M1_C1_RX_STD_0X334])) ==
           DSMCOM_BUFFER_OVERFLOW) ;
  }

  /* Terminate for S-Function (rti_commonblock): '<S19>/S-Function1' */

  /* dSPACE RTICAN RX Message Block: "N30_TPDO0" Id:817 */
  {
    /* ... Set the message into sleep mode */
    while ((rtican_type1_tq_error[0][5] = can_tp1_msg_sleep
            (can_type1_msg_M1[CANTP1_M1_C1_RX_STD_0X331])) ==
           DSMCOM_BUFFER_OVERFLOW) ;
  }

  /* Terminate for S-Function (rti_commonblock): '<S25>/S-Function1' */

  /* dSPACE RTICAN RX Message Block: "N10_TPDO3" Id:788 */
  {
    /* ... Set the message into sleep mode */
    while ((rtican_type1_tq_error[0][3] = can_tp1_msg_sleep
            (can_type1_msg_M1[CANTP1_M1_C1_RX_STD_0X314])) ==
           DSMCOM_BUFFER_OVERFLOW) ;
  }

  /* Terminate for S-Function (rti_commonblock): '<S22>/S-Function1' */

  /* dSPACE RTICAN RX Message Block: "N10_TPDO0" Id:785 */
  {
    /* ... Set the message into sleep mode */
    while ((rtican_type1_tq_error[0][2] = can_tp1_msg_sleep
            (can_type1_msg_M1[CANTP1_M1_C1_RX_STD_0X311])) ==
           DSMCOM_BUFFER_OVERFLOW) ;
  }

  /* Terminate for S-Function (rti_commonblock): '<S23>/S-Function1' */

  /* dSPACE RTICAN RX Message Block: "N10_TPDO1" Id:786 */
  {
    /* ... Set the message into sleep mode */
    while ((rtican_type1_tq_error[0][2] = can_tp1_msg_sleep
            (can_type1_msg_M1[CANTP1_M1_C1_RX_STD_0X312])) ==
           DSMCOM_BUFFER_OVERFLOW) ;
  }

  /* Terminate for S-Function (rti_commonblock): '<S24>/S-Function1' */

  /* dSPACE RTICAN RX Message Block: "N10_TPDO2" Id:787 */
  {
    /* ... Set the message into sleep mode */
    while ((rtican_type1_tq_error[0][3] = can_tp1_msg_sleep
            (can_type1_msg_M1[CANTP1_M1_C1_RX_STD_0X313])) ==
           DSMCOM_BUFFER_OVERFLOW) ;
  }

  /* Terminate for S-Function (rti_commonblock): '<S29>/S-Function1' */

  /* dSPACE RTICAN RX Message Block: "N20_TPDO3" Id:804 */
  {
    /* ... Set the message into sleep mode */
    while ((rtican_type1_tq_error[0][4] = can_tp1_msg_sleep
            (can_type1_msg_M1[CANTP1_M1_C1_RX_STD_0X324])) ==
           DSMCOM_BUFFER_OVERFLOW) ;
  }

  /* Terminate for S-Function (rti_commonblock): '<S26>/S-Function1' */

  /* dSPACE RTICAN RX Message Block: "N20_TPDO0" Id:801 */
  {
    /* ... Set the message into sleep mode */
    while ((rtican_type1_tq_error[0][3] = can_tp1_msg_sleep
            (can_type1_msg_M1[CANTP1_M1_C1_RX_STD_0X321])) ==
           DSMCOM_BUFFER_OVERFLOW) ;
  }

  /* Terminate for S-Function (rti_commonblock): '<S27>/S-Function1' */

  /* dSPACE RTICAN RX Message Block: "N20_TPDO1" Id:802 */
  {
    /* ... Set the message into sleep mode */
    while ((rtican_type1_tq_error[0][4] = can_tp1_msg_sleep
            (can_type1_msg_M1[CANTP1_M1_C1_RX_STD_0X322])) ==
           DSMCOM_BUFFER_OVERFLOW) ;
  }

  /* Terminate for S-Function (rti_commonblock): '<S28>/S-Function1' */

  /* dSPACE RTICAN RX Message Block: "N20_TPDO2" Id:803 */
  {
    /* ... Set the message into sleep mode */
    while ((rtican_type1_tq_error[0][4] = can_tp1_msg_sleep
            (can_type1_msg_M1[CANTP1_M1_C1_RX_STD_0X323])) ==
           DSMCOM_BUFFER_OVERFLOW) ;
  }

  /* Terminate for S-Function (rti_commonblock): '<S30>/S-Function1' incorporates:
   *  Constant: '<S8>/Steering Input Mode'
   *  Constant: '<S8>/Sys_Ctrlword'
   */

  /* dSPACE RTICAN TX Message Block: "N10_RPDO0" Id:529 */
  {
    /* ... Set the message into sleep mode */
    while ((rtican_type1_tq_error[0][0] = can_tp1_msg_sleep
            (can_type1_msg_M1[CANTP1_M1_C1_TX_STD_0X211])) ==
           DSMCOM_BUFFER_OVERFLOW) ;
  }

  /* Terminate for S-Function (rti_commonblock): '<S32>/S-Function1' incorporates:
   *  Constant: '<S8>/Sys_Ctrlword'
   */

  /* dSPACE RTICAN TX Message Block: "N20_RPDO0" Id:545 */
  {
    /* ... Set the message into sleep mode */
    while ((rtican_type1_tq_error[0][1] = can_tp1_msg_sleep
            (can_type1_msg_M1[CANTP1_M1_C1_TX_STD_0X221])) ==
           DSMCOM_BUFFER_OVERFLOW) ;
  }

  /* Terminate for S-Function (rti_commonblock): '<S33>/S-Function1' */

  /* dSPACE RTICAN TX Message Block: "N20_RPDO1" Id:546 */
  {
    /* ... Set the message into sleep mode */
    while ((rtican_type1_tq_error[0][1] = can_tp1_msg_sleep
            (can_type1_msg_M1[CANTP1_M1_C1_TX_STD_0X222])) ==
           DSMCOM_BUFFER_OVERFLOW) ;
  }

  /* Terminate for S-Function (rti_commonblock): '<S35>/S-Function1' */

  /* dSPACE RTICAN TX Message Block: "N30_RPDO1" Id:562 */
  {
    /* ... Set the message into sleep mode */
    while ((rtican_type1_tq_error[0][2] = can_tp1_msg_sleep
            (can_type1_msg_M1[CANTP1_M1_C1_TX_STD_0X232])) ==
           DSMCOM_BUFFER_OVERFLOW) ;
  }

  /* Terminate for S-Function (rti_commonblock): '<S34>/S-Function1' incorporates:
   *  Constant: '<S8>/Sys_Ctrlword'
   */

  /* dSPACE RTICAN TX Message Block: "N30_RPDO0" Id:561 */
  {
    /* ... Set the message into sleep mode */
    while ((rtican_type1_tq_error[0][1] = can_tp1_msg_sleep
            (can_type1_msg_M1[CANTP1_M1_C1_TX_STD_0X231])) ==
           DSMCOM_BUFFER_OVERFLOW) ;
  }

  /* Terminate for S-Function (rti_commonblock): '<S31>/S-Function1' */

  /* dSPACE RTICAN TX Message Block: "N10_RPDO1" Id:530 */
  {
    /* ... Set the message into sleep mode */
    while ((rtican_type1_tq_error[0][0] = can_tp1_msg_sleep
            (can_type1_msg_M1[CANTP1_M1_C1_TX_STD_0X212])) ==
           DSMCOM_BUFFER_OVERFLOW) ;
  }
}
