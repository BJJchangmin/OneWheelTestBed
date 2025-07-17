/*
 * test.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "test".
 *
 * Model version              : 1.61
 * Simulink Coder version : 8.13 (R2017b) 24-Jul-2017
 * C source code generated on : Wed Jul 16 20:12:22 2025
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
 *    '<S80>/If Action Subsystem4'
 *    '<S80>/If Action Subsystem6'
 */
void test_IfActionSubsystem2(real_T rtu_In1, real_T *rty_Out1)
{
  /* Inport: '<S49>/In1' */
  *rty_Out1 = rtu_In1;
}

/*
 * Output and update for action system:
 *    '<S87>/Torque Mode'
 *    '<S87>/Torque Mode1'
 *    '<S87>/ID_Mode'
 */
void test_TorqueMode(real_T *rty_Mode, real_T *rty_Out2, P_TorqueMode_test_T
                     *localP)
{
  /* SignalConversion: '<S89>/OutportBufferForMode' incorporates:
   *  Constant: '<S89>/Constant'
   */
  *rty_Mode = localP->Constant_Value;

  /* SignalConversion: '<S89>/OutportBufferForOut2' incorporates:
   *  Constant: '<S89>/Constant1'
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

  /* If: '<S87>/If' */
  if (test_B.DrivingInputMode == 0.0) {
    rtAction = 0;

    /* Outputs for IfAction SubSystem: '<S87>/Velocity Mode' incorporates:
     *  ActionPort: '<S91>/Action Port'
     */
    /* SignalConversion: '<S91>/OutportBufferForOut1' incorporates:
     *  Constant: '<S91>/Constant'
     */
    test_B.Merge = test_P.Constant_Value;

    /* End of Outputs for SubSystem: '<S87>/Velocity Mode' */
  } else if (test_B.DrivingInputMode == 1.0) {
    rtAction = 1;

    /* Outputs for IfAction SubSystem: '<S87>/Torque Mode' incorporates:
     *  ActionPort: '<S89>/Action Port'
     */
    test_TorqueMode(&test_B.Merge, &test_B.Merge1, &test_P.TorqueMode);

    /* End of Outputs for SubSystem: '<S87>/Torque Mode' */
  } else if (test_B.DrivingInputMode == 2.0) {
    rtAction = 2;

    /* Outputs for IfAction SubSystem: '<S87>/Torque Mode1' incorporates:
     *  ActionPort: '<S90>/Action Port'
     */
    test_TorqueMode(&test_B.Merge, &test_B.Merge1, &test_P.TorqueMode1);

    /* End of Outputs for SubSystem: '<S87>/Torque Mode1' */
  } else {
    rtAction = 3;

    /* Outputs for IfAction SubSystem: '<S87>/ID_Mode' incorporates:
     *  ActionPort: '<S88>/Action Port'
     */
    test_TorqueMode(&test_B.Merge, &test_B.Merge1, &test_P.ID_Mode);

    /* End of Outputs for SubSystem: '<S87>/ID_Mode' */
  }

  test_DW.If_ActiveSubsystem = rtAction;

  /* End of If: '<S87>/If' */

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

  /* Product: '<S68>/Divide1' incorporates:
   *  Constant: '<S8>/dri_FF_OnOff'
   */
  test_B.Divide1_ad = test_B.Merge1_e * test_P.dri_FF_OnOff_Value;

  /* UnitDelay: '<S73>/d' */
  test_B.d_l = test_DW.d_DSTATE_cq;

  /* Sum: '<S73>/Sum2' */
  test_B.Sum2_i = test_B.Divide1_ad - test_B.d_l;

  /* Gain: '<S73>/gain' */
  current_mod = test_P.Ts;
  phase = 2.0 / current_mod;
  test_B.gain_gx = phase * test_B.Sum2_i;

  /* UnitDelay: '<S73>/d1' */
  test_B.d1_p = test_DW.d1_DSTATE_f;

  /* Sum: '<S73>/Sum1' */
  test_B.Sum1_i2 = test_B.gain_gx - test_B.d1_p;

  /* Product: '<S68>/Divide2' incorporates:
   *  Constant: '<S8>/wheel_Jn'
   */
  test_B.Divide2_n = test_P.wheel_Jn_Value * test_B.Sum1_i2;

  /* Product: '<S68>/Divide4' incorporates:
   *  Constant: '<S8>/wheel_Bn'
   */
  test_B.Divide4_c = test_P.wheel_Bn_Value * test_B.Divide1_ad;

  /* Sum: '<S68>/Add5' */
  test_B.Add5 = test_B.Divide2_n + test_B.Divide4_c;

  /* UnitDelay: '<S74>/d1' */
  test_B.d1_hw = test_DW.d1_DSTATE_ga;

  /* Sum: '<S74>/Sum3' */
  test_B.Sum3_p = test_B.Add5 + test_B.d1_hw;

  /* Gain: '<S74>/gain' */
  test_B.gain_n = test_P.Ts * test_B.Sum3_p;

  /* Gain: '<S74>/gain2' incorporates:
   *  Constant: '<S8>/dri_FF_CutOff'
   */
  test_B.gain2_d = test_P.gain2_Gain_n * test_P.dri_FF_CutOff_Value;

  /* Product: '<S74>/Product2' incorporates:
   *  Constant: '<S74>/Constant1'
   */
  test_B.Product2_h = test_P.Constant1_Value_k / test_B.gain2_d;

  /* Gain: '<S74>/gain1' */
  test_B.gain1_f = test_P.gain1_Gain_e * test_B.Product2_h;

  /* Sum: '<S74>/Sum1' incorporates:
   *  Constant: '<S74>/Constant'
   */
  test_B.Sum1_h = test_B.gain1_f - test_P.Ts;

  /* UnitDelay: '<S74>/d' */
  test_B.d_p = test_DW.d_DSTATE_h;

  /* Product: '<S74>/Product11' */
  test_B.Product11_j = test_B.Sum1_h * test_B.d_p;

  /* Sum: '<S74>/Sum2' */
  test_B.Sum2_e = test_B.gain_n + test_B.Product11_j;

  /* Sum: '<S74>/Sum4' incorporates:
   *  Constant: '<S74>/Constant'
   */
  test_B.Sum4_a = test_B.gain1_f + test_P.Ts;

  /* Product: '<S74>/Product1' */
  test_B.Product1_p = test_B.Sum2_e / test_B.Sum4_a;

  /* Product: '<S68>/Divide' incorporates:
   *  Constant: '<S8>/dri_FF_OnOff'
   */
  test_B.Divide_n = test_B.Product1_p * test_P.dri_FF_OnOff_Value;

  /* Saturate: '<S69>/Saturation' incorporates:
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

  /* End of Saturate: '<S69>/Saturation' */

  /* Gain: '<S69>/gain 1' */
  test_B.gain1_l0 = test_P.gain1_Gain_g * test_B.Saturation_c;

  /* Gain: '<S69>/gain ' incorporates:
   *  Constant: '<S8>/dri_PID_CutOff'
   */
  test_B.gain_o = test_P.gain_Gain * test_P.dri_PID_CutOff_Value;

  /* Product: '<S69>/Divide6' incorporates:
   *  Constant: '<S8>/wheel_Jn'
   */
  test_B.Divide6 = test_B.gain1_l0 * test_B.gain_o * test_P.wheel_Jn_Value;

  /* Sum: '<S69>/Add1' incorporates:
   *  Constant: '<S8>/wheel_Bn'
   */
  test_B.Add1_b = test_B.Divide6 - test_P.wheel_Bn_Value;

  /* Sum: '<S64>/Add1' */
  test_B.Add1_p = test_B.Merge1_e - test_B.Divide1;

  /* Product: '<S69>/Divide' incorporates:
   *  Constant: '<S8>/dri_PID_OnOff'
   */
  test_B.Divide_m = test_B.Add1_p * test_P.dri_PID_OnOff_Value;

  /* Product: '<S69>/Divide1' */
  test_B.Divide1_m = test_B.Add1_b * test_B.Divide_m;

  /* Product: '<S69>/Divide3' */
  test_B.Divide3_m = test_B.gain_o * test_B.gain_o;

  /* Product: '<S69>/Divide4' incorporates:
   *  Constant: '<S8>/wheel_Jn'
   */
  test_B.Divide4_n = test_B.Divide3_m * test_P.wheel_Jn_Value;

  /* Sum: '<S69>/Add' */
  test_B.Add_i = test_B.gain_o + test_B.Divide4_n;

  /* RelationalOperator: '<S76>/LowerRelop1' */
  test_B.LowerRelop1_e = (test_B.Divide4_n > test_B.Add_i);

  /* RelationalOperator: '<S76>/UpperRelop' incorporates:
   *  Constant: '<S69>/Constant1'
   */
  test_B.UpperRelop_g = (test_B.Divide4_n < test_P.Ts);

  /* Switch: '<S76>/Switch' incorporates:
   *  Constant: '<S69>/Constant1'
   */
  if (test_B.UpperRelop_g) {
    test_B.Switch_h = test_P.Ts;
  } else {
    test_B.Switch_h = test_B.Divide4_n;
  }

  /* End of Switch: '<S76>/Switch' */

  /* Switch: '<S76>/Switch2' */
  if (test_B.LowerRelop1_e) {
    test_B.Switch2_g = test_B.Add_i;
  } else {
    test_B.Switch2_g = test_B.Switch_h;
  }

  /* End of Switch: '<S76>/Switch2' */

  /* Product: '<S69>/Divide9' */
  test_B.Divide9 = test_B.gain_o * test_B.gain_o / test_B.Switch2_g;

  /* Product: '<S69>/Divide7' incorporates:
   *  Constant: '<S64>/Constant'
   */
  test_B.Divide7 = test_P.Constant_Value_n * test_B.Divide9;

  /* Sum: '<S69>/Sum2' */
  test_B.Sum2_h = test_B.Divide_m + test_B.Divide7;

  /* UnitDelay: '<S75>/d1' */
  test_B.d1_n = test_DW.d1_DSTATE_d;

  /* Sum: '<S75>/Sum1' */
  test_B.Sum1_f = test_B.Sum2_h + test_B.d1_n;

  /* Gain: '<S75>/gain' */
  phase = test_P.Ts;
  phase /= 2.0;
  test_B.gain_a = phase * test_B.Sum1_f;

  /* UnitDelay: '<S75>/d' */
  test_B.d_b = test_DW.d_DSTATE_p;

  /* Sum: '<S75>/Sum2' */
  test_B.Sum2_p = test_B.gain_a + test_B.d_b;

  /* Product: '<S69>/Divide2' */
  test_B.Divide2_c = test_B.Sum2_p * test_B.Divide4_n;

  /* Sum: '<S69>/Sum1' */
  test_B.Sum1_a = test_B.Divide1_m + test_B.Divide2_c;

  /* Product: '<S69>/Divide5' incorporates:
   *  Constant: '<S8>/dri_PID_OnOff'
   */
  test_B.Divide5 = test_B.Sum1_a * test_P.dri_PID_OnOff_Value;

  /* Delay: '<S67>/Delay' */
  test_B.Delay = test_DW.Delay_DSTATE;

  /* Product: '<S67>/Divide5' incorporates:
   *  Constant: '<S8>/dri_DOB_OnOff'
   */
  test_B.Divide5_a = test_B.Delay * test_P.dri_DOB_OnOff_Value;

  /* Product: '<S67>/Divide1' incorporates:
   *  Constant: '<S8>/dri_DOB_OnOff'
   */
  test_B.Divide1_l = test_B.Divide1 * test_P.dri_DOB_OnOff_Value;

  /* UnitDelay: '<S71>/d' */
  test_B.d_o = test_DW.d_DSTATE_fu;

  /* Sum: '<S71>/Sum2' */
  test_B.Sum2_g = test_B.Divide1_l - test_B.d_o;

  /* Gain: '<S71>/gain' */
  current_mod = test_P.Ts;
  phase = 2.0 / current_mod;
  test_B.gain_fg = phase * test_B.Sum2_g;

  /* UnitDelay: '<S71>/d1' */
  test_B.d1_h0 = test_DW.d1_DSTATE_fx;

  /* Sum: '<S71>/Sum1' */
  test_B.Sum1_is = test_B.gain_fg - test_B.d1_h0;

  /* Product: '<S67>/Divide2' incorporates:
   *  Constant: '<S8>/wheel_Jn'
   */
  test_B.Divide2_j = test_P.wheel_Jn_Value * test_B.Sum1_is;

  /* Product: '<S67>/Divide4' incorporates:
   *  Constant: '<S8>/wheel_Bn'
   */
  test_B.Divide4_i = test_P.wheel_Bn_Value * test_B.Divide1_l;

  /* Sum: '<S67>/Add2' */
  test_B.Add2 = test_B.Divide2_j + test_B.Divide4_i;

  /* Sum: '<S67>/Add1' */
  test_B.Add1_g = test_B.Add2 - test_B.Divide5_a;

  /* UnitDelay: '<S72>/d1' */
  test_B.d1_i = test_DW.d1_DSTATE_m;

  /* Sum: '<S72>/Sum3' */
  test_B.Sum3_k = test_B.Add1_g + test_B.d1_i;

  /* Gain: '<S72>/gain' */
  test_B.gain_ff = test_P.Ts * test_B.Sum3_k;

  /* Gain: '<S72>/gain2' incorporates:
   *  Constant: '<S8>/dri_DOB_CutOff'
   */
  test_B.gain2_p = test_P.gain2_Gain_m * test_P.dri_DOB_CutOff_Value;

  /* Product: '<S72>/Product2' incorporates:
   *  Constant: '<S72>/Constant1'
   */
  test_B.Product2_e = test_P.Constant1_Value_ax / test_B.gain2_p;

  /* Gain: '<S72>/gain1' */
  test_B.gain1_p = test_P.gain1_Gain_an * test_B.Product2_e;

  /* Sum: '<S72>/Sum1' incorporates:
   *  Constant: '<S72>/Constant'
   */
  test_B.Sum1_e = test_B.gain1_p - test_P.Ts;

  /* UnitDelay: '<S72>/d' */
  test_B.d_n = test_DW.d_DSTATE_m;

  /* Product: '<S72>/Product11' */
  test_B.Product11_i = test_B.Sum1_e * test_B.d_n;

  /* Sum: '<S72>/Sum2' */
  test_B.Sum2_c = test_B.gain_ff + test_B.Product11_i;

  /* Sum: '<S72>/Sum4' incorporates:
   *  Constant: '<S72>/Constant'
   */
  test_B.Sum4_m = test_B.gain1_p + test_P.Ts;

  /* Product: '<S72>/Product1' */
  test_B.Product1_l5 = test_B.Sum2_c / test_B.Sum4_m;

  /* Product: '<S67>/Divide6' incorporates:
   *  Constant: '<S8>/dri_DOB_OnOff'
   */
  test_B.Divide6_e = test_B.Product1_l5 * test_P.dri_DOB_OnOff_Value;

  /* Sum: '<S64>/Add' */
  test_B.Add_j = (test_B.Divide_n + test_B.Divide5) - test_B.Divide6_e;

  /* Product: '<S70>/Divide3' incorporates:
   *  Constant: '<S70>/Constant2'
   */
  test_B.Divide3_i = test_B.Add_j / test_P.Constant2_Value_p;

  /* Product: '<S70>/Divide1' incorporates:
   *  Constant: '<S70>/Constant1'
   */
  test_B.Divide1_g = test_B.Divide3_i * test_P.Constant1_Value_m;

  /* RelationalOperator: '<S77>/LowerRelop1' incorporates:
   *  Constant: '<S70>/Constant'
   */
  test_B.LowerRelop1_a = (test_B.Divide1_g > test_P.Constant_Value_ju);

  /* Gain: '<S70>/Gain1' incorporates:
   *  Constant: '<S70>/Constant'
   */
  test_B.Gain1_o = test_P.Gain1_Gain_f * test_P.Constant_Value_ju;

  /* RelationalOperator: '<S77>/UpperRelop' */
  test_B.UpperRelop_m = (test_B.Divide1_g < test_B.Gain1_o);

  /* Switch: '<S77>/Switch' */
  if (test_B.UpperRelop_m) {
    test_B.Switch_b = test_B.Gain1_o;
  } else {
    test_B.Switch_b = test_B.Divide1_g;
  }

  /* End of Switch: '<S77>/Switch' */

  /* Switch: '<S77>/Switch2' incorporates:
   *  Constant: '<S70>/Constant'
   */
  if (test_B.LowerRelop1_a) {
    test_B.Switch2_b = test_P.Constant_Value_ju;
  } else {
    test_B.Switch2_b = test_B.Switch_b;
  }

  /* End of Switch: '<S77>/Switch2' */

  /* Product: '<S70>/Divide' incorporates:
   *  Constant: '<S70>/Constant'
   */
  test_B.Divide_i = test_B.Switch2_b / test_P.Constant_Value_ju;

  /* Gain: '<S70>/Gain' */
  test_B.Gain_f = test_P.Gain_Gain_c * test_B.Divide_i;

  /* If: '<S6>/If' */
  if ((test_B.Merge1 == 1.0) || (test_B.Merge1 == 2.0)) {
    /* Outputs for IfAction SubSystem: '<S6>/If Action Subsystem' incorporates:
     *  ActionPort: '<S65>/Action Port'
     */
    test_IfActionSubsystem2(test_B.Gain_f, &test_B.Merge_m);

    /* End of Outputs for SubSystem: '<S6>/If Action Subsystem' */
  } else {
    /* Outputs for IfAction SubSystem: '<S6>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S66>/Action Port'
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
      if (( test_B.Gain_i ) < -0.5)
        CAN_Sgn.SignedSgn = (Int32) (( test_B.Gain_i ) - 0.5);
      else
        CAN_Sgn.SignedSgn = (Int32) (( test_B.Gain_i ) + 0.5);
      CAN_Sgn.SignedSgn &= 0x0000FFFF;
      CAN_Msg[4] |= CAN_Sgn.SgnBytes.Byte0;
      CAN_Msg[5] |= CAN_Sgn.SgnBytes.Byte1;
    }

    /* ... Write the data to the CAN microcontroller and trigger the sending of the message */
    can_tp1_msg_send(can_type1_msg_M1[CANTP1_M1_C1_TX_STD_0X212], 6, &(CAN_Msg[0]),
                     delayTime);
  }

  /* Product: '<S75>/Divide' incorporates:
   *  Constant: '<S8>/dri_PID_OnOff'
   */
  test_B.Divide_k = test_B.Sum2_p * test_P.dri_PID_OnOff_Value;

  /* Product: '<S79>/Product' incorporates:
   *  Constant: '<S79>/Constant2'
   *  Constant: '<S8>/cpt_str'
   */
  test_B.Product_cn = test_P.Constant2_Value_i / test_P.cpt_str_Value;

  /* Product: '<S79>/Product1' */
  test_B.Product1_c = test_B.SFunction1_o2_ay * test_B.Product_cn;

  /* Product: '<S79>/Product2' incorporates:
   *  Constant: '<S8>/N_str'
   */
  test_B.Product2_j = test_B.Product1_c / test_P.N_str_Value;

  /* Product: '<S79>/Product3' incorporates:
   *  Constant: '<S79>/Constant3'
   *  Constant: '<S8>/cpt_sus'
   */
  test_B.Product3_j = test_P.Constant3_Value_o / test_P.cpt_sus_Value;

  /* Product: '<S79>/Product4' */
  test_B.Product4_e = test_B.SFunction1_o2_an * test_B.Product3_j;

  /* Product: '<S79>/Product5' incorporates:
   *  Constant: '<S8>/N_sus'
   */
  test_B.Product5_c = test_B.Product4_e / test_P.N_sus_Value;

  /* If: '<S80>/If2' incorporates:
   *  Constant: '<S80>/Constant1'
   */
  if (test_B.Merge == 9.0) {
    /* Outputs for IfAction SubSystem: '<S80>/If Action Subsystem5' incorporates:
     *  ActionPort: '<S83>/Action Port'
     */
    /* Product: '<S83>/Product' incorporates:
     *  Constant: '<S83>/Constant1'
     *  Constant: '<S83>/Constant5'
     */
    test_B.Product_i = test_P.Constant1_Value / test_P.Constant5_Value;

    /* Product: '<S83>/Product1' */
    test_B.Product1_cu = test_B.Merge1_e * test_B.Product_i;

    /* Product: '<S83>/Product2' incorporates:
     *  Constant: '<S83>/N_dri'
     */
    test_B.Merge2 = test_B.Product1_cu / test_P.N_dri_Value;

    /* End of Outputs for SubSystem: '<S80>/If Action Subsystem5' */
  } else if (test_B.Merge == 10.0) {
    /* Outputs for IfAction SubSystem: '<S80>/If Action Subsystem4' incorporates:
     *  ActionPort: '<S82>/Action Port'
     */
    test_IfActionSubsystem2(test_B.Merge1_e, &test_B.Merge2);

    /* End of Outputs for SubSystem: '<S80>/If Action Subsystem4' */
  } else {
    /* Outputs for IfAction SubSystem: '<S80>/If Action Subsystem6' incorporates:
     *  ActionPort: '<S84>/Action Port'
     */
    test_IfActionSubsystem2(test_P.Constant1_Value_e, &test_B.Merge2);

    /* End of Outputs for SubSystem: '<S80>/If Action Subsystem6' */
  }

  /* End of If: '<S80>/If2' */
  /* Product: '<S80>/Product' incorporates:
   *  Constant: '<S80>/Constant2'
   *  Constant: '<S8>/cpt_str'
   */
  test_B.Product_o = test_P.Constant2_Value_m / test_P.cpt_str_Value;

  /* Product: '<S80>/Product1' */
  test_B.Product1_fn = test_B.DataTypeConversion * test_B.Product_o;

  /* Product: '<S80>/Product2' incorporates:
   *  Constant: '<S8>/N_str'
   */
  test_B.Product2_kc = test_B.Product1_fn / test_P.N_str_Value;

  /* Product: '<S80>/Product3' incorporates:
   *  Constant: '<S80>/Constant3'
   *  Constant: '<S8>/cpt_sus'
   */
  test_B.Product3_d = test_P.Constant3_Value_b / test_P.cpt_sus_Value;

  /* Product: '<S80>/Product4' */
  test_B.Product4_ej = test_B.DataTypeConversion1 * test_B.Product3_d;

  /* Product: '<S80>/Product5' incorporates:
   *  Constant: '<S8>/N_sus'
   */
  test_B.Product5_e = test_B.Product4_ej / test_P.N_sus_Value;

  /* Sum: '<S81>/Add' incorporates:
   *  Constant: '<S8>/acc_bias'
   */
  test_B.Add_k = test_B.SFunction1_n - test_P.acc_bias_Value;

  /* Product: '<S85>/Divide2' incorporates:
   *  Constant: '<S85>/Constant'
   */
  test_B.Divide2_d = test_B.SFunction1 * test_P.Constant_Value_gq;

  /* Product: '<S85>/Divide1' incorporates:
   *  Constant: '<S85>/Ample Gain'
   *  Constant: '<S85>/V'
   */
  test_B.Divide1_h = test_P.V_Value * test_P.AmpleGain_Value;

  /* Product: '<S85>/Divide3' */
  test_B.Divide3_d = test_B.Divide2_d / test_B.Divide1_h;

  /* Product: '<S85>/Divide4' incorporates:
   *  Constant: '<S8>/Load_cell_Gain'
   */
  test_B.Divide4_p = test_B.Divide3_d * test_P.Load_cell_Gain_Value;

  /* Sum: '<S81>/Add1' incorporates:
   *  Constant: '<S8>/Grf_x_bias'
   */
  test_B.Add1_i = test_B.Divide4_p - test_P.Grf_x_bias_Value;

  /* Product: '<S86>/Divide2' incorporates:
   *  Constant: '<S86>/Constant'
   */
  test_B.Divide2_n5 = test_B.SFunction1_j * test_P.Constant_Value_i;

  /* Product: '<S86>/Divide1' incorporates:
   *  Constant: '<S86>/Ample Gain'
   *  Constant: '<S86>/V'
   */
  test_B.Divide1_g2 = test_P.V_Value_d * test_P.AmpleGain_Value_n;

  /* Product: '<S86>/Divide3' */
  test_B.Divide3_p = test_B.Divide2_n5 / test_B.Divide1_g2;

  /* Product: '<S86>/Divide5' incorporates:
   *  Constant: '<S8>/Load_cell_Gain'
   */
  test_B.Divide5_e = test_B.Divide3_p * test_P.Load_cell_Gain_Value;

  /* Sum: '<S81>/Add2' incorporates:
   *  Constant: '<S8>/Grf_y_bias'
   */
  test_B.Add2_c = test_B.Divide5_e - test_P.Grf_y_bias_Value;

  /* Constant: '<S8>/Data_Logging' */
  test_B.Data_Logging = test_P.Data_Logging_Value;

  /* Constant: '<S8>/cpt_dri' */
  test_B.cpt_dri = test_P.cpt_dri_Value;
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

  /* Update for UnitDelay: '<S73>/d' */
  test_DW.d_DSTATE_cq = test_B.Divide1_ad;

  /* Update for UnitDelay: '<S73>/d1' */
  test_DW.d1_DSTATE_f = test_B.Sum1_i2;

  /* Update for UnitDelay: '<S74>/d1' */
  test_DW.d1_DSTATE_ga = test_B.Add5;

  /* Update for UnitDelay: '<S74>/d' */
  test_DW.d_DSTATE_h = test_B.Product1_p;

  /* Update for UnitDelay: '<S75>/d1' */
  test_DW.d1_DSTATE_d = test_B.Sum2_h;

  /* Update for UnitDelay: '<S75>/d' */
  test_DW.d_DSTATE_p = test_B.Divide_k;

  /* Update for Delay: '<S67>/Delay' */
  test_DW.Delay_DSTATE = test_B.Add_j;

  /* Update for UnitDelay: '<S71>/d' */
  test_DW.d_DSTATE_fu = test_B.Divide1_l;

  /* Update for UnitDelay: '<S71>/d1' */
  test_DW.d1_DSTATE_fx = test_B.Sum1_is;

  /* Update for UnitDelay: '<S72>/d1' */
  test_DW.d1_DSTATE_m = test_B.Add1_g;

  /* Update for UnitDelay: '<S72>/d' */
  test_DW.d_DSTATE_m = test_B.Product1_l5;

  /* Update for UnitDelay: '<S59>/Delay Input2' */
  test_DW.DelayInput2_DSTATE_n = test_B.DifferenceInputs2_d;

  /* Update for UnitDelay: '<S58>/d1' */
  test_DW.d1_DSTATE_k = test_B.DifferenceInputs2_d;

  /* Update for UnitDelay: '<S58>/d' */
  test_DW.d_DSTATE_ow = test_B.Product1_js;

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

  /* Start for If: '<S87>/If' */
  test_DW.If_ActiveSubsystem = -1;

  /* Start for FromWorkspace: '<S39>/From Workspace' */
  {
    static real_T pTimeValues0[] = { 3.1039788463383945E-14 } ;

    static real_T pDataValues0[] = { 0.79206916577179853, 0.099558221129019631,
      0.80667128674757416, 0.199029976434944, 0.83036873581433812,
      0.29814815482820867, 0.86216336359329238, 0.39633240703691208,
      0.90058367606120915, 0.49256748542344564, 0.94362036533644833,
      0.58528918433298671, 0.988658079468853, 0.67228562218670107,
      1.0324158470621341, 0.75062552679518524, 1.070912506132176,
      0.81662951513986826, 1.0994775174818185, 0.86590458733144637,
      1.1128310880300063, 0.89346539414713155, 1.1052596819817768,
      0.89396717965713091, 1.07091250613218, 0.862073215828809,
      1.0042398652640905, 0.792972366306026, 0.90058367606119671,
      0.68304843512349755, 0.75691229926900538, 0.53068078632299254,
      0.572665159898251, 0.33712483426885709, 0.35063752647129953,
      0.10738243924876077, 0.097794427170440526, -0.14907059556139185,
      -0.17414013125574296, -0.41787332579267622, -0.44850845100480774,
      -0.67988647711311612, -0.70416612474554019, -0.91202170505005653,
      -0.91674219365618881, -1.0889597246465339, -1.06084006215106,
      -1.1858308307824394, -1.113182643038239, -1.181775013734232,
      -1.0565173551776854, -1.0640822131962138, -0.88385633051375456,
      -0.83235739202037917, -0.602366785646747, -0.50190436421199025,
      -0.2360026349659142, -0.10534517448894345, 0.17414013125576,
      0.30852533095897972, 0.57266515989834033, 0.67941947285993509,
      0.89645476067552332, 0.94400086881416534, 1.0848263999604337,
      1.0474731908353474, 1.0921329352673788, 0.95663483872443311,
      0.90058367606118994, 0.67167237507121658, 0.53014010227481734,
      0.23326214951602803, 0.041956057161113669, -0.27841775815538383,
      -0.46763214145607279, -0.7550597067221122, -0.88385633051376644,
      -1.0819832539303267, -1.0994775174817641, -1.1670515102545056,
      -1.0449822367726336, -0.97010381329261786, -0.71494450596147829,
      -0.52382279485083716, -0.18104486940785111, 0.063160803355607226,
      0.41628489703172117, 0.62688189792282079, 0.90058367606115841,
      0.99162634436331765, 1.1114032763638553, 1.0268994748932465,
      0.96170455293338786, 0.70006857144483525, 0.48028938128597032,
      0.10336219981369807, -0.18104486940783929, -0.56183244662091769,
      -0.78713899559149925, -1.0472533546149334, -1.1005499622517076,
      -1.1512423067742164, -0.97883965424457464, -0.80971404570034322,
      -0.44850845100491915, -0.14293363154948094, 0.28360634978494026,
      0.573512825720476, 0.90058367606118239, 1.0160368362194176,
      1.1105249265591985, 0.96203304614598828, 0.79206916577188591,
      0.41297692139183562, 0.076876421953090759, -0.37855257978765133,
      -0.68779059712648927, -1.0118021936905899, -1.0994775174817271,
      -1.1385973362928434, -0.91674219365615928, -0.66509529126539557,
      -0.21545590840352008, 0.16482553266264685, 0.61990427060588082,
      0.877218007935075, 1.0947541325800203, 1.0338751431665669,
      0.90058367606115086, 0.51313940402419422, 0.13257689145275281,
      -0.37756113300067812, -0.73089986697034071, -1.062748492709306,
      -1.1131606697659109, -1.0670082300582451, -0.73089986697032,
      -0.36053738172396815, 0.17414013125581868, 0.57557620919245933,
      0.96170455293338131, 1.0581157057526021, 1.0375653844658896,
      0.704202310769646, 0.31727849591320778, -0.24102641826834106,
      -0.65995792201007331, -1.0439436110353717, -1.113182643038223,
      -1.042296471336813, -0.64864092823065467, -0.2097618716600676,
      0.37048894022694034, 0.76630651430202112, 1.0764492719693646,
      1.0317545128152819, 0.8303687358142835, 0.32440221176884043,
      -0.17414013125575051, -0.73464156977480222, -1.0243861200587372,
      -1.1575900573151359, -0.904677037945415, -0.516942489354255,
      0.097794427170432047, 0.58779649993941308, 1.0101959102267071,
      1.057256315719042, 0.90058367606119372, 0.38970893656456951,
      -0.14645516098391195, -0.74539312347092967, -1.0449822367725952,
      -1.1425095267048517, -0.81624712432993185, -0.34611000477088011,
      0.31727849591325258, 0.785511224118576, 1.0994775174818148,
      0.97030691072970643, 0.61990427060584263, -0.03136485851439115,
      -0.59055584230797031, -1.061501121104552, -1.1005499622517636,
      -0.8750668981697719, -0.27005725293586752, 0.32819956824758761,
      0.90058367606119094, 1.062187811896939, 0.9361249127714184,
      0.37713472043399721, -0.23600263496592072, -0.86789045328076386,
      -1.1035064488179791, -1.0350443887434257, -0.49913241358112387,
      0.12545188328629048, 0.78713899559154465, 1.0493535810406287,
      0.98865807946888118, 0.4409244351670995, -0.20171511088821911,
      -0.867795419878519, -1.1075622027767462, -1.0004001702955081,
      -0.40327865021575354, 0.26191958489817097, 0.90058367606125378,
      1.0622654480358003, 0.85324671119037265, 0.17715471677623856,
      -0.49913241358111748, -1.0612112666509228, -1.0799280887625529,
      -0.72004293034692268, 0.041956057161106813, 0.68721702625479386,
      1.0994775174817739, 0.90703021660775, 0.37048894022689244,
      -0.44207491484478423, -0.97210060751136274, -1.1420100837675093,
      -0.68779059712656032, 0.00048613360356950717, 0.76710953057475761,
      1.05821153381544, 0.90058367606120127, 0.19094345209430327,
      -0.54239838277567087, -1.102770611696009, -1.0243861200587328,
      -0.51620707079975947, 0.33733360238362448, 0.915925517313903,
      1.0848263999603851, 0.57411153602528864, -0.17414013125578462,
      -0.93079119019065681, -1.1075622027768637, -0.77440782176545109,
      0.06291545159537329, 0.76731892696090587, 1.1128310880299328,
      0.72582501700577828, -0.0069942868061813272, -0.83847412921525954,
      -1.1131826430382996, -0.8359934053278526, 0.0069942868062066186,
      0.74810368080439416, 1.1128310880299357, 0.70555238670464937,
      -0.062915451595298391, -0.89540372840744953, -1.107562202776782,
      -0.73095772153332161, 0.17414013125579927, 0.871617469048519,
      1.084826399960352, 0.50300473758390862, -0.33733360238364885,
      -1.0609723174488073, -1.0243861200587214, -0.41227004714260262,
      0.54239838277562513, 1.0367227514959372, 0.90058367606124534,
      0.052993654615967063, -0.76710953057473474, -1.1620473527709339,
      -0.68779059712643453, 0.1671571689178315, 0.97210060751143468,
      0.9919282024760937, 0.37048894022685169, -0.61816390655964781,
      -1.0994775174818265, -0.88385164224250656, 0.041956057161132945,
      0.83915060560540033, 1.0799280887625486, 0.41605604161374909,
      -0.49913241358110771, -1.1396819582434572, -0.85324671119031548,
      -0.013265936884809421, 0.90058367606123169, 1.0185179930915758,
      0.40327865021585318, -0.63011551794657594, -1.1075622027768348,
      -0.80559583429329928, 0.20171511088826702, 0.94893566149056208,
      0.98865807946889916, 0.12245429364661815, -0.787138995591591,
      -1.149157313222946, -0.49913241358110622, 0.4693944579204723,
      1.1035064488179676, 0.705681985939306, -0.23600263496588794,
      -1.0777198621220794, -0.93612491277137944, -0.083158263421865983,
      0.90058367606117051, 0.99684184921161434, 0.27005725293578686,
      -0.79782496280776927, -1.1005499622517758, -0.51597483249833442,
      0.59055584230796121, 1.0630895831005, 0.6199042706059209,
      -0.49362613880418543, -1.0994775174817435, -0.78476908378198318,
      0.31727849591312129, 1.02334808870175, 0.81624712432994473,
      -0.26708601308423474, -1.0449822367726738, -0.91976581146556136,
      0.14645516098394734, 0.97241247242385476, 0.90058367606120127,
      -0.15640694945650757, -1.0101959102268083, -0.96165824264854949,
      0.0977944271704315, 0.96102796215273711, 0.90467703794539123,
      -0.17031486796969636, -1.0243861200587812, -0.928410260761253,
      0.17414013125587893, 0.99806938026100089, 0.83036873581430082,
      -0.30805812866429094, -1.0764492719693548, -0.80551825935548049,
      0.37048894022688983, 1.0519426558038438, 0.64864092823064834,
      -0.55681623230319943, -1.113182643038273, -0.55369803406431839,
      0.65995792201019587, 1.0470257292348173, 0.3172784959131415,
      -0.86731310934796124, -1.0375653844658994, -0.13895835022347655,
      0.961704552933377, 0.86983382809091581, -0.17414013125578856,
      -1.1193407125814494, -0.73089986697039622, 0.4066264431284235,
      1.1131606697659766, 0.41617670779539623, -0.73089986697034781,
      -1.1143511920630564, -0.13257689145274762, 0.90918770175663532,
      0.90058367606115175, -0.29440192118680625, -1.09475413258007,
      -0.6624840856869858, 0.61990427060586151, 1.041934219557676,
      0.21545590840344206, -0.97930229053485351, -0.91674219365620846,
      0.19468393837034637, 1.09947751748174, 0.51529645913706867,
      -0.68779059712655666, -1.1143372239309484, -0.076876421953043672,
      0.961078646991225, 0.79206916577188, -0.50634539292523184,
      -1.1105249265592385, -0.35873593558471556, 0.90058367606117673,
      0.8698618815314515, -0.28360634978504584, -1.1594568664001814,
      -0.4485084510049257, 0.76759221163457825, 0.97883965424454555,
      -0.23950709672028364, -1.1005499622517665, -0.55365565877669987,
      0.78713899559153067, 0.941219428194541, -0.18104486940788436,
      -1.1516665106474548, -0.480289381285917, 0.76759936669373019,
      0.96170455293334178, -0.30800107118560793, -1.1114032763638377,
      -0.4252644810250345, 0.90058367606116418, 0.82868239623193374,
      -0.41628489703176247, -1.15648092500067, -0.18104486940789014,
      0.96110019281938075, 0.71494450596142589, -0.68848221471642634,
      -1.0449822367726123, 0.05667396312341217, 1.0994775174818192,
      0.39066760720714849, -0.88385633051376777, -0.91967777648186477,
      0.46763214145618681, 1.041970400137644, 0.041956057161168632,
      -1.1230873863551061, -0.53014010227477537, 0.78634561192628027,
      0.90058367606122491, -0.49352151580543818, -1.0921329352673346,
      -0.06905143706392991, 1.084826399960418, 0.41622793662742752,
      -0.89645476067546359, -0.874335964878923, 0.57266515989830469,
      0.99696401231879006, -0.17414013125584074, -1.1625003022123064,
      -0.23600263496602075, 0.97796396100010785, 0.60236678564671853,
      -0.86724623863240069, -0.88385633051381651, 0.46953530141381661,
      1.0565173551777216, -0.2256759456211217, -1.1131826430382623,
      -0.22222075347331416, 1.0608400621510443, 0.44149550234104867,
      -0.91674219365620813, -0.80543495746473737, 0.70416612474558082,
      0.90025200294011765, -0.44850845100491171, -1.1182967422322312,
      0.17414013125579703, 1.0627744668649539, 0.097794427170504655,
      -1.1394994523243251, -0.35063752647123386, 0.96112870133648287,
      0.57266515989832256, -0.93894358815889056, -0.75691229926897219,
      0.68767314696820259, 0.90058367606118273, -0.61795789598781226,
      -1.0042398652641042, 0.34204943970171048, 1.070912506132099,
      -0.26696658584201616, -1.1052596819817615, 0.00089695687929560635,
      1.11283108802993, 0.053225370639160233, -1.0994775174817881,
      -0.29091892009172815, 1.0709125061321287, 0.31244168580386406,
      -1.0324158470621405, -0.51583518592017741, 0.98865807946887663,
      0.5032647409706057, -0.9436203653364581, -0.67404292389210352,
      0.90058367606118206, 0.63110753323614521, -0.86216336359327261,
      -0.77406951822474135, 0.830368735814326, 0.70584370941906538,
      -0.8066712867475675, -0.82571730891546857, 0.79206916577189324,
      0.73611805742132941, -0.787138995591505, -0.835684139869652,
      0.79206916577188258, 0.72615122646721919, -0.80667128674760213,
      -0.80540979186736772, 0.83036873581429993, 0.67450343577649619,
      -0.86216336359328061, -0.73067361568439848, 0.90058367606120437,
      0.57447684144385669, -0.94362036533643168, -0.602830823418847,
      0.98865807946895623, 0.41626910347183521, -1.0324158470620488,
      -0.41200776825211566, 1.0709125061321685, 0.1913528376434574,
      -1.0994775174817646, -0.1527914530873892, 1.1128310880299432,
      -0.10046303932751256, -1.1052596819818012, 0.16740050339383789,
      1.0709125061320968, -0.44161552214984745, -1.004239865264124,
      0.51839181353959, 0.90058367606119094, -0.787239229416538,
      -0.75691229926897419, 0.83937750571054937, 0.57266515989828026,
      -1.0606947837848182, -0.3506375264713017, 1.0399333698760034,
      0.09779442717035676, -1.1623405493132177, 0.17414013125578195,
      1.0187306597839993, -0.44850845100495434, -0.99981808538827943,
      0.70416612474558271, 0.70586887501649676, -0.91674219365618093,
      -0.54106158478929633, 1.0608400621510063, 0.12265467102501838,
      -1.1131826430382883, 0.12610986317291323, 1.0565173551776512,
      -0.569101383861981, -0.88385633051385326, 0.76768015618418239,
      0.60236678564671731, -1.0775300434482356, -0.23600263496592172,
      1.0629342197641156, -0.17414013125574584, -1.0965300947670786,
      0.572665159898306, 0.77476988243067368, -0.89645476067551366,
      -0.51579401907570588, 1.0848263999603986, -0.030514645384352088,
      -1.0921329352673732, 0.39395543335718292, 0.90058367606115086,
      -0.88591169437460371, -0.53014010227486741, 1.023521303906771,
      0.041956057161117596, -1.1415364825859888, 0.46763214145610732,
      0.82011169403357609, -0.88385633051380874, -0.49023368965549646,
      1.0994775174818467, -0.15624004557177415, -1.0449822367726149,
      0.58891613226815, 0.71494450596146164, -1.0606662752676428,
      -0.18104486940787837, 1.0569148425524812, -0.41628489703175015,
      -0.928248478680137, 0.90058367606119516, 0.32569839857676597,
      -1.1114032763637527, 0.208434988737293, 0.96170455293342283,
      -0.86716544914202121, -0.48028938128591503, 1.0521004281991186,
      -0.18104486940788744, -1.04078551064284, 0.78713899559155853,
      0.45408957632847319, -1.1005499622517849, 0.13994101427203981,
      0.97883965424462316, -0.86715829408280642, -0.44850845100484449,
      1.0598907839519369, -0.28360634978499205, -0.96942796397966069,
      0.90058367606115208, 0.25916985313652158, -1.1105249265592958,
      0.40677931047699872, 0.79206916577188158, -1.0606447294395633,
      -0.076876421952973853, 1.0147711414826619, -0.687790597126496,
      -0.614862541585278, 1.0994775174818019, -0.29425002081861779,
      -0.9167421936561444, 0.8797362080866542, 0.21545590840342521,
      -1.1415003020058307, 0.61990427060592324, 0.56291800323869612,
      -1.0947541325799848, 0.19483583873860533, 0.90058367606119483,
      -1.0087537842049383, -0.13257689145270277, 1.014785109614774,
      -0.73089986697041176, -0.51574279024362624, 1.1131606697659659,
      -0.5061925255767965, -0.730899866970255, 1.0197746301332034,
      -0.17414013125579708, -0.969399910539121, 0.96170455293334445,
      0.039392267775240346, -1.0375653844658239, 0.76774702689971852,
      0.31727849591313023, -1.1465918116831018, 0.65995792201020154,
      0.45413195161600406, -1.1131826430382779, 0.45725014985498569,
      0.64864092823069863, -1.151508738252125, 0.37048894022701123,
      0.70595217690715084, -1.0764492719693075, 0.2084920462160309,
      0.83036873581429294, -1.0976354627093357, 0.17414013125578096,
      0.82884417831294566, -1.0243861200587783, 0.0707487855215978,
      0.904677037945323, -1.0605940446009974, 0.097794427170477566,
      0.86209216020028734, -1.0101959102267288, 0.056840867008300412,
      0.900583676061146, -1.0719785548721428, 0.14645516098405814,
      0.82019972901730953, -1.0449822367726793, 0.16751993063601103,
      0.81624712432999957, -1.1229141711500397, 0.31727849591323032,
      0.6852030013336855, -1.0994775174818154, 0.39406005635592345,
      0.61990427060588171, -1.1626556655488118, 0.59055584230794944,
      0.41640875005008615, -1.1005499622517476, 0.69825888035956629,
      0.27005725293589145, -1.0964079316598445, 0.9005836760612147,
      -0.016407819026412557, -0.93612491277138921, 0.97815377967386663,
      -0.23600263496609913, -0.80524806838747365, 1.1035064488179087,
      -0.568960540368687, -0.49913241358114657, 1.0495912307747453,
      -0.7871389955915713, -0.22202037609476824, 0.98865807946882667,
      -1.0485017439388227, 0.20171511088821237, 0.70602975184502581,
      -1.1075622027768739, 0.5305494354982867, 0.40327865021581538,
      -1.1180840755398607, 0.90058367606121681, -0.0863001455635846,
      -0.85324671119028817, 1.0401158757951092, -0.49913241358111987,
      -0.51562212406197194, 1.0799280887625922, -0.93871668805368691,
      0.041956057161151208, 0.7842855597942624, -1.09947751748185,
      0.51859782411156941, 0.37048894022677237, -1.091494284924307,
      0.97210060751140293, -0.26672325136617919, -0.68779059712645552,
      1.0624812703225963, -0.7671095305748169, -0.15255973706428777,
      0.90058367606118583, -1.136288833944231, 0.54239838277570773,
      0.31270396469431472, -1.0243861200587141, 0.96140623500056421,
      -0.33733360238367671, -0.60257082003210183, 1.0848263999603882,
      -0.97118355149678948, 0.17414013125579869, 0.63139163908494322,
      -1.10756220277683, 0.79583764595912865, -0.062915451595380451,
      -0.80511846915289342, 1.1128310880299601, -0.84766976325269228,
      0.0069942868062422567, 0.73642732287951629, -1.1131826430382759,
      0.73890804676709543, -0.0069942868062505921, -0.82539109945397671,
      1.1128310880299161, -0.866885009409127, 0.062915451595349642,
      0.67484173931718516, -1.10756220277689, 0.83122510774246217,
      -0.174140131255825, -0.67367761847350538, 1.0848263999603949,
      -1.0154915997621936, 0.3373336023836826, 0.41664098835143409,
      -1.0243861200586939, 1.0032045292477765, -0.54239838277572,
      -0.29050953454248207, 0.90058367606113288, -1.1577776162637,
      0.76710953057481091, -0.10005221605177451, -0.68779059712648383,
      1.0424440013192717, -0.97210060751142557, 0.34250883239651669,
      0.37048894022686624, -1.0065962990559865, 1.0994775174817919,
      -0.78678310870306623, 0.041956057161161291, 0.62047684789861579,
      -1.0799280887625751, 0.96164518420267442, -0.49913241358117594,
      -0.27672079922437415, 0.85324671119032791, -1.1618315304841049,
      0.90058367606124134, -0.36148566734659382, -0.4032786502157345,
      0.900834087847126, -1.1075622027768721, 0.76822933743021316,
      -0.201715110888302, -0.54049051761524192, 0.98865807946883977,
      -1.1489196634889096, 0.78713899559153655, -0.22501796573454,
      -0.49913241358107874, 0.935478306295136, -1.1035064488179227,
      0.76832437083250515, -0.23600263496598609, -0.47670080288220207,
      0.93612491277131793, -1.1617538943451686, 0.90058367606110989,
      -0.42776565069574751, -0.27005725293594879, 0.77550081572152152,
      -1.1005499622517416, 0.96193503865630725, -0.59055584230795177,
      -0.068201223933793673, 0.61990427060587838, -1.0698729931779549,
      1.0994775174817757, -0.88507730656688111, 0.31727849591312979,
      0.24654392232255859, -0.81624712433004665, 1.0429434442566916,
      -1.0449822367728232, 0.64582704102273325, -0.14645516098403655,
      -0.4892750190129076, 0.90058367606123035, -1.1568223981672847,
      1.010195910226795, -0.6873625823877344, 0.097794427170464951,
      0.41737640690599109, -0.90467703794540533, 1.0580239748668963,
      -1.0243861200587916, 0.635075487326638, -0.17414013125587485,
      -0.423968294217014, 0.83036873581426252, -1.1313205952635854,
      1.0764492719693439, -0.8658725967503168, 0.37048894022693052,
      0.11019578921170421, -0.64864092823068187, 0.94273038888853888,
      -1.1131826430383056, 0.94437752858705493, -0.65995792201019887,
      0.14146033582010123, 0.31727849591301732, -0.80376839321782123,
      1.037565384465756, -1.1576817882008428, 0.96170455293338675,
      -0.67514229164074835, 0.174140131255795, 0.26097129927557683,
      -0.73089986697026554, 0.96744214760989689, -1.1131606697658929,
      0.96318241026096341, -0.73089986697031528, 0.27799505055241314,
      0.13257689145273355, -0.61270548647237022, 0.90058367606107526,
      -1.1334412256147091, 1.0947541325799492, -0.976784090383278,
      0.61990427060589282, -0.26439161511097681, -0.21545590840340648,
      0.56552920881704, -0.9167421936561132, 1.0390312538445445,
      -1.0994775174818272, 0.91223611124233317, -0.687790597126564,
      0.27898649733943953, 0.076876421952962, -0.51254300384003826,
      0.79206916577180186, -1.0615991285942203, 1.110524926559231,
      -1.1156029186677157, 0.90058367606126721, -0.67307890816878135,
      0.28360634978510979, 0.043367549101199186, -0.44850845100484621,
      0.71014796325214258, -0.978839654244631, 1.0516762243259947,
      -1.1005499622518646, 0.9476872721667815, -0.78713899559165368,
      0.46226636417268, -0.18104486940795259, -0.2029282822619019,
      0.48028938128591242, -0.79963465389307931, 0.96170455293341583,
      -1.1264655573416102, 1.1114032763638617, -1.0911924268115589,
      0.90058367606114353, -0.72644798037104419, 0.41628489703167354,
      -0.16272688580387731, -0.18104486940791381, 0.42425671240255897,
      -0.71494450596141834, 0.87053773084436881, -1.044982236772624,
      1.067485427806127, -1.0994775174817255, 0.98241717148205654,
      -0.88385633051386026, 0.65549362427383506, -0.46763214145612336,
      0.17885167570715482, 0.041956057160997977, -0.33282823196413053,
      0.53014010227478847, -0.77123845751936748, 0.900583676061105,
      -1.0562009211726315, 1.0921329352672788, -1.1470392732835761,
      1.0848263999603647, -1.043566951262493, 0.89645476067551433,
      -0.7789855553082875, 0.57266515989828348, -0.40809141340730604,
      0.17414013125580974, 0.0057790920406669893, -0.23600263496593082,
      0.40233828176368353, -0.60236678564674806, 0.73279130957204563,
      -0.88385633051375534, 0.96451613074784437, -1.0565173551777198,
      1.0822089312859517, -1.1131826430383132, 1.0862647483342442,
      -1.0608400621510781, 0.98939364219839421, -0.91674219365629073,
      0.81245562260184645, -0.70416612474562235, 0.5803203946647818,
      -0.4485084510048733, 0.3183072433444295, -0.17414013125584524,
      0.049504513113204779, 0.097794427170353443, -0.20694852169694425,
      0.35063752647124863, -0.43669091671703664, 0.57266515989826938,
      -0.63024686877126246, 0.75691229926905768, -0.78261451757175338,
      0.90058367606117207, -0.89253844875427657, 1.0042398652640634,
      -0.96163929827709771, 1.0709125061321543, -0.99353326210536463,
      1.1052596819817173, -0.99303147659544211, 1.1128310880299426,
      -0.96547066977970464, 1.099477517481765, -0.91619559758816849,
      1.0709125061321494, -0.85019160924341153, 1.0324158470620581,
      -0.77185170463491137, 0.98865807946886086, -0.68485526678123065,
      0.94362036533642957, -0.59213356787173832, 0.90058367606119949,
      -0.49589848948525234, 0.86216336359333123, -0.39771423727654331,
      0.83036873581429727, -0.29859605888326551, 0.80667128674759514,
      -0.1991243035772445, 0.79206916577188613, -0.09956608244825739,
      0.78713899559150691, -3.1039788463383945E-14, -0.79206916577179853,
      -0.099558221129019631, -0.80667128674757416, -0.199029976434944,
      -0.83036873581433812, -0.29814815482820867, -0.86216336359329238,
      -0.39633240703691208, -0.90058367606120915, -0.49256748542344564,
      -0.94362036533644833, -0.58528918433298671, -0.988658079468853,
      -0.67228562218670107, -1.0324158470621341, -0.75062552679518524,
      -1.070912506132176, -0.81662951513986826, -1.0994775174818185,
      -0.86590458733144637, -1.1128310880300063, -0.89346539414713155,
      -1.1052596819817768, -0.89396717965713091, -1.07091250613218,
      -0.862073215828809, -1.0042398652640905, -0.792972366306026,
      -0.90058367606119671, -0.68304843512349755, -0.75691229926900538,
      -0.53068078632299254, -0.572665159898251, -0.33712483426885709,
      -0.35063752647129953, -0.10738243924876077, -0.097794427170440526,
      0.14907059556139185, 0.17414013125574296, 0.41787332579267622,
      0.44850845100480774, 0.67988647711311612, 0.70416612474554019,
      0.91202170505005653, 0.91674219365618881, 1.0889597246465339,
      1.06084006215106, 1.1858308307824394, 1.113182643038239, 1.181775013734232,
      1.0565173551776854, 1.0640822131962138, 0.88385633051375456,
      0.83235739202037917, 0.602366785646747, 0.50190436421199025,
      0.2360026349659142, 0.10534517448894345, -0.17414013125576,
      -0.30852533095897972, -0.57266515989834033, -0.67941947285993509,
      -0.89645476067552332, -0.94400086881416534, -1.0848263999604337,
      -1.0474731908353474, -1.0921329352673788, -0.95663483872443311,
      -0.90058367606118994, -0.67167237507121658, -0.53014010227481734,
      -0.23326214951602803, -0.041956057161113669, 0.27841775815538383,
      0.46763214145607279, 0.7550597067221122, 0.88385633051376644,
      1.0819832539303267, 1.0994775174817641, 1.1670515102545056,
      1.0449822367726336, 0.97010381329261786, 0.71494450596147829,
      0.52382279485083716, 0.18104486940785111, -0.063160803355607226,
      -0.41628489703172117, -0.62688189792282079, -0.90058367606115841,
      -0.99162634436331765, -1.1114032763638553, -1.0268994748932465,
      -0.96170455293338786, -0.70006857144483525, -0.48028938128597032,
      -0.10336219981369807, 0.18104486940783929, 0.56183244662091769,
      0.78713899559149925, 1.0472533546149334, 1.1005499622517076,
      1.1512423067742164, 0.97883965424457464, 0.80971404570034322,
      0.44850845100491915, 0.14293363154948094, -0.28360634978494026,
      -0.573512825720476, -0.90058367606118239, -1.0160368362194176,
      -1.1105249265591985, -0.96203304614598828, -0.79206916577188591,
      -0.41297692139183562, -0.076876421953090759, 0.37855257978765133,
      0.68779059712648927, 1.0118021936905899, 1.0994775174817271,
      1.1385973362928434, 0.91674219365615928, 0.66509529126539557,
      0.21545590840352008, -0.16482553266264685, -0.61990427060588082,
      -0.877218007935075, -1.0947541325800203, -1.0338751431665669,
      -0.90058367606115086, -0.51313940402419422, -0.13257689145275281,
      0.37756113300067812, 0.73089986697034071, 1.062748492709306,
      1.1131606697659109, 1.0670082300582451, 0.73089986697032,
      0.36053738172396815, -0.17414013125581868, -0.57557620919245933,
      -0.96170455293338131, -1.0581157057526021, -1.0375653844658896,
      -0.704202310769646, -0.31727849591320778, 0.24102641826834106,
      0.65995792201007331, 1.0439436110353717, 1.113182643038223,
      1.042296471336813, 0.64864092823065467, 0.2097618716600676,
      -0.37048894022694034, -0.76630651430202112, -1.0764492719693646,
      -1.0317545128152819, -0.8303687358142835, -0.32440221176884043,
      0.17414013125575051, 0.73464156977480222, 1.0243861200587372,
      1.1575900573151359, 0.904677037945415, 0.516942489354255,
      -0.097794427170432047, -0.58779649993941308, -1.0101959102267071,
      -1.057256315719042, -0.90058367606119372, -0.38970893656456951,
      0.14645516098391195, 0.74539312347092967, 1.0449822367725952,
      1.1425095267048517, 0.81624712432993185, 0.34611000477088011,
      -0.31727849591325258, -0.785511224118576, -1.0994775174818148,
      -0.97030691072970643, -0.61990427060584263, 0.03136485851439115,
      0.59055584230797031, 1.061501121104552, 1.1005499622517636,
      0.8750668981697719, 0.27005725293586752, -0.32819956824758761,
      -0.90058367606119094, -1.062187811896939, -0.9361249127714184,
      -0.37713472043399721, 0.23600263496592072, 0.86789045328076386,
      1.1035064488179791, 1.0350443887434257, 0.49913241358112387,
      -0.12545188328629048, -0.78713899559154465, -1.0493535810406287,
      -0.98865807946888118, -0.4409244351670995, 0.20171511088821911,
      0.867795419878519, 1.1075622027767462, 1.0004001702955081,
      0.40327865021575354, -0.26191958489817097, -0.90058367606125378,
      -1.0622654480358003, -0.85324671119037265, -0.17715471677623856,
      0.49913241358111748, 1.0612112666509228, 1.0799280887625529,
      0.72004293034692268, -0.041956057161106813, -0.68721702625479386,
      -1.0994775174817739, -0.90703021660775, -0.37048894022689244,
      0.44207491484478423, 0.97210060751136274, 1.1420100837675093,
      0.68779059712656032, -0.00048613360356950717, -0.76710953057475761,
      -1.05821153381544, -0.90058367606120127, -0.19094345209430327,
      0.54239838277567087, 1.102770611696009, 1.0243861200587328,
      0.51620707079975947, -0.33733360238362448, -0.915925517313903,
      -1.0848263999603851, -0.57411153602528864, 0.17414013125578462,
      0.93079119019065681, 1.1075622027768637, 0.77440782176545109,
      -0.06291545159537329, -0.76731892696090587, -1.1128310880299328,
      -0.72582501700577828, 0.0069942868061813272, 0.83847412921525954,
      1.1131826430382996, 0.8359934053278526, -0.0069942868062066186,
      -0.74810368080439416, -1.1128310880299357, -0.70555238670464937,
      0.062915451595298391, 0.89540372840744953, 1.107562202776782,
      0.73095772153332161, -0.17414013125579927, -0.871617469048519,
      -1.084826399960352, -0.50300473758390862, 0.33733360238364885,
      1.0609723174488073, 1.0243861200587214, 0.41227004714260262,
      -0.54239838277562513, -1.0367227514959372, -0.90058367606124534,
      -0.052993654615967063, 0.76710953057473474, 1.1620473527709339,
      0.68779059712643453, -0.1671571689178315, -0.97210060751143468,
      -0.9919282024760937, -0.37048894022685169, 0.61816390655964781,
      1.0994775174818265, 0.88385164224250656, -0.041956057161132945,
      -0.83915060560540033, -1.0799280887625486, -0.41605604161374909,
      0.49913241358110771, 1.1396819582434572, 0.85324671119031548,
      0.013265936884809421, -0.90058367606123169, -1.0185179930915758,
      -0.40327865021585318, 0.63011551794657594, 1.1075622027768348,
      0.80559583429329928, -0.20171511088826702, -0.94893566149056208,
      -0.98865807946889916, -0.12245429364661815, 0.787138995591591,
      1.149157313222946, 0.49913241358110622, -0.4693944579204723,
      -1.1035064488179676, -0.705681985939306, 0.23600263496588794,
      1.0777198621220794, 0.93612491277137944, 0.083158263421865983,
      -0.90058367606117051, -0.99684184921161434, -0.27005725293578686,
      0.79782496280776927, 1.1005499622517758, 0.51597483249833442,
      -0.59055584230796121, -1.0630895831005, -0.6199042706059209,
      0.49362613880418543, 1.0994775174817435, 0.78476908378198318,
      -0.31727849591312129, -1.02334808870175, -0.81624712432994473,
      0.26708601308423474, 1.0449822367726738, 0.91976581146556136,
      -0.14645516098394734, -0.97241247242385476, -0.90058367606120127,
      0.15640694945650757, 1.0101959102268083, 0.96165824264854949,
      -0.0977944271704315, -0.96102796215273711, -0.90467703794539123,
      0.17031486796969636, 1.0243861200587812, 0.928410260761253,
      -0.17414013125587893, -0.99806938026100089, -0.83036873581430082,
      0.30805812866429094, 1.0764492719693548, 0.80551825935548049,
      -0.37048894022688983, -1.0519426558038438, -0.64864092823064834,
      0.55681623230319943, 1.113182643038273, 0.55369803406431839,
      -0.65995792201019587, -1.0470257292348173, -0.3172784959131415,
      0.86731310934796124, 1.0375653844658994, 0.13895835022347655,
      -0.961704552933377, -0.86983382809091581, 0.17414013125578856,
      1.1193407125814494, 0.73089986697039622, -0.4066264431284235,
      -1.1131606697659766, -0.41617670779539623, 0.73089986697034781,
      1.1143511920630564, 0.13257689145274762, -0.90918770175663532,
      -0.90058367606115175, 0.29440192118680625, 1.09475413258007,
      0.6624840856869858, -0.61990427060586151, -1.041934219557676,
      -0.21545590840344206, 0.97930229053485351, 0.91674219365620846,
      -0.19468393837034637, -1.09947751748174, -0.51529645913706867,
      0.68779059712655666, 1.1143372239309484, 0.076876421953043672,
      -0.961078646991225, -0.79206916577188, 0.50634539292523184,
      1.1105249265592385, 0.35873593558471556, -0.90058367606117673,
      -0.8698618815314515, 0.28360634978504584, 1.1594568664001814,
      0.4485084510049257, -0.76759221163457825, -0.97883965424454555,
      0.23950709672028364, 1.1005499622517665, 0.55365565877669987,
      -0.78713899559153067, -0.941219428194541, 0.18104486940788436,
      1.1516665106474548, 0.480289381285917, -0.76759936669373019,
      -0.96170455293334178, 0.30800107118560793, 1.1114032763638377,
      0.4252644810250345, -0.90058367606116418, -0.82868239623193374,
      0.41628489703176247, 1.15648092500067, 0.18104486940789014,
      -0.96110019281938075, -0.71494450596142589, 0.68848221471642634,
      1.0449822367726123, -0.05667396312341217, -1.0994775174818192,
      -0.39066760720714849, 0.88385633051376777, 0.91967777648186477,
      -0.46763214145618681, -1.041970400137644, -0.041956057161168632,
      1.1230873863551061, 0.53014010227477537, -0.78634561192628027,
      -0.90058367606122491, 0.49352151580543818, 1.0921329352673346,
      0.06905143706392991, -1.084826399960418, -0.41622793662742752,
      0.89645476067546359, 0.874335964878923, -0.57266515989830469,
      -0.99696401231879006, 0.17414013125584074, 1.1625003022123064,
      0.23600263496602075, -0.97796396100010785, -0.60236678564671853,
      0.86724623863240069, 0.88385633051381651, -0.46953530141381661,
      -1.0565173551777216, 0.2256759456211217, 1.1131826430382623,
      0.22222075347331416, -1.0608400621510443, -0.44149550234104867,
      0.91674219365620813, 0.80543495746473737, -0.70416612474558082,
      -0.90025200294011765, 0.44850845100491171, 1.1182967422322312,
      -0.17414013125579703, -1.0627744668649539, -0.097794427170504655,
      1.1394994523243251, 0.35063752647123386, -0.96112870133648287,
      -0.57266515989832256, 0.93894358815889056, 0.75691229926897219,
      -0.68767314696820259, -0.90058367606118273, 0.61795789598781226,
      1.0042398652641042, -0.34204943970171048, -1.070912506132099,
      0.26696658584201616, 1.1052596819817615, -0.00089695687929560635,
      -1.11283108802993, -0.053225370639160233, 1.0994775174817881,
      0.29091892009172815, -1.0709125061321287, -0.31244168580386406,
      1.0324158470621405, 0.51583518592017741, -0.98865807946887663,
      -0.5032647409706057, 0.9436203653364581, 0.67404292389210352,
      -0.90058367606118206, -0.63110753323614521, 0.86216336359327261,
      0.77406951822474135, -0.830368735814326, -0.70584370941906538,
      0.8066712867475675, 0.82571730891546857, -0.79206916577189324,
      -0.73611805742132941, 0.787138995591505, 0.835684139869652,
      -0.79206916577188258, -0.72615122646721919, 0.80667128674760213,
      0.80540979186736772, -0.83036873581429993, -0.67450343577649619,
      0.86216336359328061, 0.73067361568439848, -0.90058367606120437,
      -0.57447684144385669, 0.94362036533643168, 0.602830823418847,
      -0.98865807946895623, -0.41626910347183521, 1.0324158470620488,
      0.41200776825211566, -1.0709125061321685, -0.1913528376434574,
      1.0994775174817646, 0.1527914530873892, -1.1128310880299432,
      0.10046303932751256, 1.1052596819818012, -0.16740050339383789,
      -1.0709125061320968, 0.44161552214984745, 1.004239865264124,
      -0.51839181353959, -0.90058367606119094, 0.787239229416538,
      0.75691229926897419, -0.83937750571054937, -0.57266515989828026,
      1.0606947837848182, 0.3506375264713017, -1.0399333698760034,
      -0.09779442717035676, 1.1623405493132177, -0.17414013125578195,
      -1.0187306597839993, 0.44850845100495434, 0.99981808538827943,
      -0.70416612474558271, -0.70586887501649676, 0.91674219365618093,
      0.54106158478929633, -1.0608400621510063, -0.12265467102501838,
      1.1131826430382883, -0.12610986317291323, -1.0565173551776512,
      0.569101383861981, 0.88385633051385326, -0.76768015618418239,
      -0.60236678564671731, 1.0775300434482356, 0.23600263496592172,
      -1.0629342197641156, 0.17414013125574584, 1.0965300947670786,
      -0.572665159898306, -0.77476988243067368, 0.89645476067551366,
      0.51579401907570588, -1.0848263999603986, 0.030514645384352088,
      1.0921329352673732, -0.39395543335718292, -0.90058367606115086,
      0.88591169437460371, 0.53014010227486741, -1.023521303906771,
      -0.041956057161117596, 1.1415364825859888, -0.46763214145610732,
      -0.82011169403357609, 0.88385633051380874, 0.49023368965549646,
      -1.0994775174818467, 0.15624004557177415, 1.0449822367726149,
      -0.58891613226815, -0.71494450596146164, 1.0606662752676428,
      0.18104486940787837, -1.0569148425524812, 0.41628489703175015,
      0.928248478680137, -0.90058367606119516, -0.32569839857676597,
      1.1114032763637527, -0.208434988737293, -0.96170455293342283,
      0.86716544914202121, 0.48028938128591503, -1.0521004281991186,
      0.18104486940788744, 1.04078551064284, -0.78713899559155853,
      -0.45408957632847319, 1.1005499622517849, -0.13994101427203981,
      -0.97883965424462316, 0.86715829408280642, 0.44850845100484449,
      -1.0598907839519369, 0.28360634978499205, 0.96942796397966069,
      -0.90058367606115208, -0.25916985313652158, 1.1105249265592958,
      -0.40677931047699872, -0.79206916577188158, 1.0606447294395633,
      0.076876421952973853, -1.0147711414826619, 0.687790597126496,
      0.614862541585278, -1.0994775174818019, 0.29425002081861779,
      0.9167421936561444, -0.8797362080866542, -0.21545590840342521,
      1.1415003020058307, -0.61990427060592324, -0.56291800323869612,
      1.0947541325799848, -0.19483583873860533, -0.90058367606119483,
      1.0087537842049383, 0.13257689145270277, -1.014785109614774,
      0.73089986697041176, 0.51574279024362624, -1.1131606697659659,
      0.5061925255767965, 0.730899866970255, -1.0197746301332034,
      0.17414013125579708, 0.969399910539121, -0.96170455293334445,
      -0.039392267775240346, 1.0375653844658239, -0.76774702689971852,
      -0.31727849591313023, 1.1465918116831018, -0.65995792201020154,
      -0.45413195161600406, 1.1131826430382779, -0.45725014985498569,
      -0.64864092823069863, 1.151508738252125, -0.37048894022701123,
      -0.70595217690715084, 1.0764492719693075, -0.2084920462160309,
      -0.83036873581429294, 1.0976354627093357, -0.17414013125578096,
      -0.82884417831294566, 1.0243861200587783, -0.0707487855215978,
      -0.904677037945323, 1.0605940446009974, -0.097794427170477566,
      -0.86209216020028734, 1.0101959102267288, -0.056840867008300412,
      -0.900583676061146, 1.0719785548721428, -0.14645516098405814,
      -0.82019972901730953, 1.0449822367726793, -0.16751993063601103,
      -0.81624712432999957, 1.1229141711500397, -0.31727849591323032,
      -0.6852030013336855, 1.0994775174818154, -0.39406005635592345,
      -0.61990427060588171, 1.1626556655488118, -0.59055584230794944,
      -0.41640875005008615, 1.1005499622517476, -0.69825888035956629,
      -0.27005725293589145, 1.0964079316598445, -0.9005836760612147,
      0.016407819026412557, 0.93612491277138921, -0.97815377967386663,
      0.23600263496609913, 0.80524806838747365, -1.1035064488179087,
      0.568960540368687, 0.49913241358114657, -1.0495912307747453,
      0.7871389955915713, 0.22202037609476824, -0.98865807946882667,
      1.0485017439388227, -0.20171511088821237, -0.70602975184502581,
      1.1075622027768739, -0.5305494354982867, -0.40327865021581538,
      1.1180840755398607, -0.90058367606121681, 0.0863001455635846,
      0.85324671119028817, -1.0401158757951092, 0.49913241358111987,
      0.51562212406197194, -1.0799280887625922, 0.93871668805368691,
      -0.041956057161151208, -0.7842855597942624, 1.09947751748185,
      -0.51859782411156941, -0.37048894022677237, 1.091494284924307,
      -0.97210060751140293, 0.26672325136617919, 0.68779059712645552,
      -1.0624812703225963, 0.7671095305748169, 0.15255973706428777,
      -0.90058367606118583, 1.136288833944231, -0.54239838277570773,
      -0.31270396469431472, 1.0243861200587141, -0.96140623500056421,
      0.33733360238367671, 0.60257082003210183, -1.0848263999603882,
      0.97118355149678948, -0.17414013125579869, -0.63139163908494322,
      1.10756220277683, -0.79583764595912865, 0.062915451595380451,
      0.80511846915289342, -1.1128310880299601, 0.84766976325269228,
      -0.0069942868062422567, -0.73642732287951629, 1.1131826430382759,
      -0.73890804676709543, 0.0069942868062505921, 0.82539109945397671,
      -1.1128310880299161, 0.866885009409127, -0.062915451595349642,
      -0.67484173931718516, 1.10756220277689, -0.83122510774246217,
      0.174140131255825, 0.67367761847350538, -1.0848263999603949,
      1.0154915997621936, -0.3373336023836826, -0.41664098835143409,
      1.0243861200586939, -1.0032045292477765, 0.54239838277572,
      0.29050953454248207, -0.90058367606113288, 1.1577776162637,
      -0.76710953057481091, 0.10005221605177451, 0.68779059712648383,
      -1.0424440013192717, 0.97210060751142557, -0.34250883239651669,
      -0.37048894022686624, 1.0065962990559865, -1.0994775174817919,
      0.78678310870306623, -0.041956057161161291, -0.62047684789861579,
      1.0799280887625751, -0.96164518420267442, 0.49913241358117594,
      0.27672079922437415, -0.85324671119032791, 1.1618315304841049,
      -0.90058367606124134, 0.36148566734659382, 0.4032786502157345,
      -0.900834087847126, 1.1075622027768721, -0.76822933743021316,
      0.201715110888302, 0.54049051761524192, -0.98865807946883977,
      1.1489196634889096, -0.78713899559153655, 0.22501796573454,
      0.49913241358107874, -0.935478306295136, 1.1035064488179227,
      -0.76832437083250515, 0.23600263496598609, 0.47670080288220207,
      -0.93612491277131793, 1.1617538943451686, -0.90058367606110989,
      0.42776565069574751, 0.27005725293594879, -0.77550081572152152,
      1.1005499622517416, -0.96193503865630725, 0.59055584230795177,
      0.068201223933793673, -0.61990427060587838, 1.0698729931779549,
      -1.0994775174817757, 0.88507730656688111, -0.31727849591312979,
      -0.24654392232255859, 0.81624712433004665, -1.0429434442566916,
      1.0449822367728232, -0.64582704102273325, 0.14645516098403655,
      0.4892750190129076, -0.90058367606123035, 1.1568223981672847,
      -1.010195910226795, 0.6873625823877344, -0.097794427170464951,
      -0.41737640690599109, 0.90467703794540533, -1.0580239748668963,
      1.0243861200587916, -0.635075487326638, 0.17414013125587485,
      0.423968294217014, -0.83036873581426252, 1.1313205952635854,
      -1.0764492719693439, 0.8658725967503168, -0.37048894022693052,
      -0.11019578921170421, 0.64864092823068187, -0.94273038888853888,
      1.1131826430383056, -0.94437752858705493, 0.65995792201019887,
      -0.14146033582010123, -0.31727849591301732, 0.80376839321782123,
      -1.037565384465756, 1.1576817882008428, -0.96170455293338675,
      0.67514229164074835, -0.174140131255795, -0.26097129927557683,
      0.73089986697026554, -0.96744214760989689, 1.1131606697658929,
      -0.96318241026096341, 0.73089986697031528, -0.27799505055241314,
      -0.13257689145273355, 0.61270548647237022, -0.90058367606107526,
      1.1334412256147091, -1.0947541325799492, 0.976784090383278,
      -0.61990427060589282, 0.26439161511097681, 0.21545590840340648,
      -0.56552920881704, 0.9167421936561132, -1.0390312538445445,
      1.0994775174818272, -0.91223611124233317, 0.687790597126564,
      -0.27898649733943953, -0.076876421952962, 0.51254300384003826,
      -0.79206916577180186, 1.0615991285942203, -1.110524926559231,
      1.1156029186677157, -0.90058367606126721, 0.67307890816878135,
      -0.28360634978510979, -0.043367549101199186, 0.44850845100484621,
      -0.71014796325214258, 0.978839654244631, -1.0516762243259947,
      1.1005499622518646, -0.9476872721667815, 0.78713899559165368,
      -0.46226636417268, 0.18104486940795259, 0.2029282822619019,
      -0.48028938128591242, 0.79963465389307931, -0.96170455293341583,
      1.1264655573416102, -1.1114032763638617, 1.0911924268115589,
      -0.90058367606114353, 0.72644798037104419, -0.41628489703167354,
      0.16272688580387731, 0.18104486940791381, -0.42425671240255897,
      0.71494450596141834, -0.87053773084436881, 1.044982236772624,
      -1.067485427806127, 1.0994775174817255, -0.98241717148205654,
      0.88385633051386026, -0.65549362427383506, 0.46763214145612336,
      -0.17885167570715482, -0.041956057160997977, 0.33282823196413053,
      -0.53014010227478847, 0.77123845751936748, -0.900583676061105,
      1.0562009211726315, -1.0921329352672788, 1.1470392732835761,
      -1.0848263999603647, 1.043566951262493, -0.89645476067551433,
      0.7789855553082875, -0.57266515989828348, 0.40809141340730604,
      -0.17414013125580974, -0.0057790920406669893, 0.23600263496593082,
      -0.40233828176368353, 0.60236678564674806, -0.73279130957204563,
      0.88385633051375534, -0.96451613074784437, 1.0565173551777198,
      -1.0822089312859517, 1.1131826430383132, -1.0862647483342442,
      1.0608400621510781, -0.98939364219839421, 0.91674219365629073,
      -0.81245562260184645, 0.70416612474562235, -0.5803203946647818,
      0.4485084510048733, -0.3183072433444295, 0.17414013125584524,
      -0.049504513113204779, -0.097794427170353443, 0.20694852169694425,
      -0.35063752647124863, 0.43669091671703664, -0.57266515989826938,
      0.63024686877126246, -0.75691229926905768, 0.78261451757175338,
      -0.90058367606117207, 0.89253844875427657, -1.0042398652640634,
      0.96163929827709771, -1.0709125061321543, 0.99353326210536463,
      -1.1052596819817173, 0.99303147659544211, -1.1128310880299426,
      0.96547066977970464, -1.099477517481765, 0.91619559758816849,
      -1.0709125061321494, 0.85019160924341153, -1.0324158470620581,
      0.77185170463491137, -0.98865807946886086, 0.68485526678123065,
      -0.94362036533642957, 0.59213356787173832, -0.90058367606119949,
      0.49589848948525234, -0.86216336359333123, 0.39771423727654331,
      -0.83036873581429727, 0.29859605888326551, -0.80667128674759514,
      0.1991243035772445, -0.79206916577188613, 0.09956608244825739,
      -0.78713899559150691, 3.1039788463383945E-14, 0.79206916577179853,
      0.099558221129019631, 0.80667128674757416, 0.199029976434944,
      0.83036873581433812, 0.29814815482820867, 0.86216336359329238,
      0.39633240703691208, 0.90058367606120915, 0.49256748542344564,
      0.94362036533644833, 0.58528918433298671, 0.988658079468853,
      0.67228562218670107, 1.0324158470621341, 0.75062552679518524,
      1.070912506132176, 0.81662951513986826, 1.0994775174818185,
      0.86590458733144637, 1.1128310880300063, 0.89346539414713155,
      1.1052596819817768, 0.89396717965713091, 1.07091250613218,
      0.862073215828809, 1.0042398652640905, 0.792972366306026,
      0.90058367606119671, 0.68304843512349755, 0.75691229926900538,
      0.53068078632299254, 0.572665159898251, 0.33712483426885709,
      0.35063752647129953, 0.10738243924876077, 0.097794427170440526,
      -0.14907059556139185, -0.17414013125574296, -0.41787332579267622,
      -0.44850845100480774, -0.67988647711311612, -0.70416612474554019,
      -0.91202170505005653, -0.91674219365618881, -1.0889597246465339,
      -1.06084006215106, -1.1858308307824394, -1.113182643038239,
      -1.181775013734232, -1.0565173551776854, -1.0640822131962138,
      -0.88385633051375456, -0.83235739202037917, -0.602366785646747,
      -0.50190436421199025, -0.2360026349659142, -0.10534517448894345,
      0.17414013125576, 0.30852533095897972, 0.57266515989834033,
      0.67941947285993509, 0.89645476067552332, 0.94400086881416534,
      1.0848263999604337, 1.0474731908353474, 1.0921329352673788,
      0.95663483872443311, 0.90058367606118994, 0.67167237507121658,
      0.53014010227481734, 0.23326214951602803, 0.041956057161113669,
      -0.27841775815538383, -0.46763214145607279, -0.7550597067221122,
      -0.88385633051376644, -1.0819832539303267, -1.0994775174817641,
      -1.1670515102545056, -1.0449822367726336, -0.97010381329261786,
      -0.71494450596147829, -0.52382279485083716, -0.18104486940785111,
      0.063160803355607226, 0.41628489703172117, 0.62688189792282079,
      0.90058367606115841, 0.99162634436331765, 1.1114032763638553,
      1.0268994748932465, 0.96170455293338786, 0.70006857144483525,
      0.48028938128597032, 0.10336219981369807, -0.18104486940783929,
      -0.56183244662091769, -0.78713899559149925, -1.0472533546149334,
      -1.1005499622517076, -1.1512423067742164, -0.97883965424457464,
      -0.80971404570034322, -0.44850845100491915, -0.14293363154948094,
      0.28360634978494026, 0.573512825720476, 0.90058367606118239,
      1.0160368362194176, 1.1105249265591985, 0.96203304614598828,
      0.79206916577188591, 0.41297692139183562, 0.076876421953090759,
      -0.37855257978765133, -0.68779059712648927, -1.0118021936905899,
      -1.0994775174817271, -1.1385973362928434, -0.91674219365615928,
      -0.66509529126539557, -0.21545590840352008, 0.16482553266264685,
      0.61990427060588082, 0.877218007935075, 1.0947541325800203,
      1.0338751431665669, 0.90058367606115086, 0.51313940402419422,
      0.13257689145275281, -0.37756113300067812, -0.73089986697034071,
      -1.062748492709306, -1.1131606697659109, -1.0670082300582451,
      -0.73089986697032, -0.36053738172396815, 0.17414013125581868,
      0.57557620919245933, 0.96170455293338131, 1.0581157057526021,
      1.0375653844658896, 0.704202310769646, 0.31727849591320778,
      -0.24102641826834106, -0.65995792201007331, -1.0439436110353717,
      -1.113182643038223, -1.042296471336813, -0.64864092823065467,
      -0.2097618716600676, 0.37048894022694034, 0.76630651430202112,
      1.0764492719693646, 1.0317545128152819, 0.8303687358142835,
      0.32440221176884043, -0.17414013125575051, -0.73464156977480222,
      -1.0243861200587372, -1.1575900573151359, -0.904677037945415,
      -0.516942489354255, 0.097794427170432047, 0.58779649993941308,
      1.0101959102267071, 1.057256315719042, 0.90058367606119372,
      0.38970893656456951, -0.14645516098391195, -0.74539312347092967,
      -1.0449822367725952, -1.1425095267048517, -0.81624712432993185,
      -0.34611000477088011, 0.31727849591325258, 0.785511224118576,
      1.0994775174818148, 0.97030691072970643, 0.61990427060584263,
      -0.03136485851439115, -0.59055584230797031, -1.061501121104552,
      -1.1005499622517636, -0.8750668981697719, -0.27005725293586752,
      0.32819956824758761, 0.90058367606119094, 1.062187811896939,
      0.9361249127714184, 0.37713472043399721, -0.23600263496592072,
      -0.86789045328076386, -1.1035064488179791, -1.0350443887434257,
      -0.49913241358112387, 0.12545188328629048, 0.78713899559154465,
      1.0493535810406287, 0.98865807946888118, 0.4409244351670995,
      -0.20171511088821911, -0.867795419878519, -1.1075622027767462,
      -1.0004001702955081, -0.40327865021575354, 0.26191958489817097,
      0.90058367606125378, 1.0622654480358003, 0.85324671119037265,
      0.17715471677623856, -0.49913241358111748, -1.0612112666509228,
      -1.0799280887625529, -0.72004293034692268, 0.041956057161106813,
      0.68721702625479386, 1.0994775174817739, 0.90703021660775,
      0.37048894022689244, -0.44207491484478423, -0.97210060751136274,
      -1.1420100837675093, -0.68779059712656032, 0.00048613360356950717,
      0.76710953057475761, 1.05821153381544, 0.90058367606120127,
      0.19094345209430327, -0.54239838277567087, -1.102770611696009,
      -1.0243861200587328, -0.51620707079975947, 0.33733360238362448,
      0.915925517313903, 1.0848263999603851, 0.57411153602528864,
      -0.17414013125578462, -0.93079119019065681, -1.1075622027768637,
      -0.77440782176545109, 0.06291545159537329, 0.76731892696090587,
      1.1128310880299328, 0.72582501700577828, -0.0069942868061813272,
      -0.83847412921525954, -1.1131826430382996, -0.8359934053278526,
      0.0069942868062066186, 0.74810368080439416, 1.1128310880299357,
      0.70555238670464937, -0.062915451595298391, -0.89540372840744953,
      -1.107562202776782, -0.73095772153332161, 0.17414013125579927,
      0.871617469048519, 1.084826399960352, 0.50300473758390862,
      -0.33733360238364885, -1.0609723174488073, -1.0243861200587214,
      -0.41227004714260262, 0.54239838277562513, 1.0367227514959372,
      0.90058367606124534, 0.052993654615967063, -0.76710953057473474,
      -1.1620473527709339, -0.68779059712643453, 0.1671571689178315,
      0.97210060751143468, 0.9919282024760937, 0.37048894022685169,
      -0.61816390655964781, -1.0994775174818265, -0.88385164224250656,
      0.041956057161132945, 0.83915060560540033, 1.0799280887625486,
      0.41605604161374909, -0.49913241358110771, -1.1396819582434572,
      -0.85324671119031548, -0.013265936884809421, 0.90058367606123169,
      1.0185179930915758, 0.40327865021585318, -0.63011551794657594,
      -1.1075622027768348, -0.80559583429329928, 0.20171511088826702,
      0.94893566149056208, 0.98865807946889916, 0.12245429364661815,
      -0.787138995591591, -1.149157313222946, -0.49913241358110622,
      0.4693944579204723, 1.1035064488179676, 0.705681985939306,
      -0.23600263496588794, -1.0777198621220794, -0.93612491277137944,
      -0.083158263421865983, 0.90058367606117051, 0.99684184921161434,
      0.27005725293578686, -0.79782496280776927, -1.1005499622517758,
      -0.51597483249833442, 0.59055584230796121, 1.0630895831005,
      0.6199042706059209, -0.49362613880418543, -1.0994775174817435,
      -0.78476908378198318, 0.31727849591312129, 1.02334808870175,
      0.81624712432994473, -0.26708601308423474, -1.0449822367726738,
      -0.91976581146556136, 0.14645516098394734, 0.97241247242385476,
      0.90058367606120127, -0.15640694945650757, -1.0101959102268083,
      -0.96165824264854949, 0.0977944271704315, 0.96102796215273711,
      0.90467703794539123, -0.17031486796969636, -1.0243861200587812,
      -0.928410260761253, 0.17414013125587893, 0.99806938026100089,
      0.83036873581430082, -0.30805812866429094, -1.0764492719693548,
      -0.80551825935548049, 0.37048894022688983, 1.0519426558038438,
      0.64864092823064834, -0.55681623230319943, -1.113182643038273,
      -0.55369803406431839, 0.65995792201019587, 1.0470257292348173,
      0.3172784959131415, -0.86731310934796124, -1.0375653844658994,
      -0.13895835022347655, 0.961704552933377, 0.86983382809091581,
      -0.17414013125578856, -1.1193407125814494, -0.73089986697039622,
      0.4066264431284235, 1.1131606697659766, 0.41617670779539623,
      -0.73089986697034781, -1.1143511920630564, -0.13257689145274762,
      0.90918770175663532, 0.90058367606115175, -0.29440192118680625,
      -1.09475413258007, -0.6624840856869858, 0.61990427060586151,
      1.041934219557676, 0.21545590840344206, -0.97930229053485351,
      -0.91674219365620846, 0.19468393837034637, 1.09947751748174,
      0.51529645913706867, -0.68779059712655666, -1.1143372239309484,
      -0.076876421953043672, 0.961078646991225, 0.79206916577188,
      -0.50634539292523184, -1.1105249265592385, -0.35873593558471556,
      0.90058367606117673, 0.8698618815314515, -0.28360634978504584,
      -1.1594568664001814, -0.4485084510049257, 0.76759221163457825,
      0.97883965424454555, -0.23950709672028364, -1.1005499622517665,
      -0.55365565877669987, 0.78713899559153067, 0.941219428194541,
      -0.18104486940788436, -1.1516665106474548, -0.480289381285917,
      0.76759936669373019, 0.96170455293334178, -0.30800107118560793,
      -1.1114032763638377, -0.4252644810250345, 0.90058367606116418,
      0.82868239623193374, -0.41628489703176247, -1.15648092500067,
      -0.18104486940789014, 0.96110019281938075, 0.71494450596142589,
      -0.68848221471642634, -1.0449822367726123, 0.05667396312341217,
      1.0994775174818192, 0.39066760720714849, -0.88385633051376777,
      -0.91967777648186477, 0.46763214145618681, 1.041970400137644,
      0.041956057161168632, -1.1230873863551061, -0.53014010227477537,
      0.78634561192628027, 0.90058367606122491, -0.49352151580543818,
      -1.0921329352673346, -0.06905143706392991, 1.084826399960418,
      0.41622793662742752, -0.89645476067546359, -0.874335964878923,
      0.57266515989830469, 0.99696401231879006, -0.17414013125584074,
      -1.1625003022123064, -0.23600263496602075, 0.97796396100010785,
      0.60236678564671853, -0.86724623863240069, -0.88385633051381651,
      0.46953530141381661, 1.0565173551777216, -0.2256759456211217,
      -1.1131826430382623, -0.22222075347331416, 1.0608400621510443,
      0.44149550234104867, -0.91674219365620813, -0.80543495746473737,
      0.70416612474558082, 0.90025200294011765, -0.44850845100491171,
      -1.1182967422322312, 0.17414013125579703, 1.0627744668649539,
      0.097794427170504655, -1.1394994523243251, -0.35063752647123386,
      0.96112870133648287, 0.57266515989832256, -0.93894358815889056,
      -0.75691229926897219, 0.68767314696820259, 0.90058367606118273,
      -0.61795789598781226, -1.0042398652641042, 0.34204943970171048,
      1.070912506132099, -0.26696658584201616, -1.1052596819817615,
      0.00089695687929560635, 1.11283108802993, 0.053225370639160233,
      -1.0994775174817881, -0.29091892009172815, 1.0709125061321287,
      0.31244168580386406, -1.0324158470621405, -0.51583518592017741,
      0.98865807946887663, 0.5032647409706057, -0.9436203653364581,
      -0.67404292389210352, 0.90058367606118206, 0.63110753323614521,
      -0.86216336359327261, -0.77406951822474135, 0.830368735814326,
      0.70584370941906538, -0.8066712867475675, -0.82571730891546857,
      0.79206916577189324, 0.73611805742132941, -0.787138995591505,
      -0.835684139869652, 0.79206916577188258, 0.72615122646721919,
      -0.80667128674760213, -0.80540979186736772, 0.83036873581429993,
      0.67450343577649619, -0.86216336359328061, -0.73067361568439848,
      0.90058367606120437, 0.57447684144385669, -0.94362036533643168,
      -0.602830823418847, 0.98865807946895623, 0.41626910347183521,
      -1.0324158470620488, -0.41200776825211566, 1.0709125061321685,
      0.1913528376434574, -1.0994775174817646, -0.1527914530873892,
      1.1128310880299432, -0.10046303932751256, -1.1052596819818012,
      0.16740050339383789, 1.0709125061320968, -0.44161552214984745,
      -1.004239865264124, 0.51839181353959, 0.90058367606119094,
      -0.787239229416538, -0.75691229926897419, 0.83937750571054937,
      0.57266515989828026, -1.0606947837848182, -0.3506375264713017,
      1.0399333698760034, 0.09779442717035676, -1.1623405493132177,
      0.17414013125578195, 1.0187306597839993, -0.44850845100495434,
      -0.99981808538827943, 0.70416612474558271, 0.70586887501649676,
      -0.91674219365618093, -0.54106158478929633, 1.0608400621510063,
      0.12265467102501838, -1.1131826430382883, 0.12610986317291323,
      1.0565173551776512, -0.569101383861981, -0.88385633051385326,
      0.76768015618418239, 0.60236678564671731, -1.0775300434482356,
      -0.23600263496592172, 1.0629342197641156, -0.17414013125574584,
      -1.0965300947670786, 0.572665159898306, 0.77476988243067368,
      -0.89645476067551366, -0.51579401907570588, 1.0848263999603986,
      -0.030514645384352088, -1.0921329352673732, 0.39395543335718292,
      0.90058367606115086, -0.88591169437460371, -0.53014010227486741,
      1.023521303906771, 0.041956057161117596, -1.1415364825859888,
      0.46763214145610732, 0.82011169403357609, -0.88385633051380874,
      -0.49023368965549646, 1.0994775174818467, -0.15624004557177415,
      -1.0449822367726149, 0.58891613226815, 0.71494450596146164,
      -1.0606662752676428, -0.18104486940787837, 1.0569148425524812,
      -0.41628489703175015, -0.928248478680137, 0.90058367606119516,
      0.32569839857676597, -1.1114032763637527, 0.208434988737293,
      0.96170455293342283, -0.86716544914202121, -0.48028938128591503,
      1.0521004281991186, -0.18104486940788744, -1.04078551064284,
      0.78713899559155853, 0.45408957632847319, -1.1005499622517849,
      0.13994101427203981, 0.97883965424462316, -0.86715829408280642,
      -0.44850845100484449, 1.0598907839519369, -0.28360634978499205,
      -0.96942796397966069, 0.90058367606115208, 0.25916985313652158,
      -1.1105249265592958, 0.40677931047699872, 0.79206916577188158,
      -1.0606447294395633, -0.076876421952973853, 1.0147711414826619,
      -0.687790597126496, -0.614862541585278, 1.0994775174818019,
      -0.29425002081861779, -0.9167421936561444, 0.8797362080866542,
      0.21545590840342521, -1.1415003020058307, 0.61990427060592324,
      0.56291800323869612, -1.0947541325799848, 0.19483583873860533,
      0.90058367606119483, -1.0087537842049383, -0.13257689145270277,
      1.014785109614774, -0.73089986697041176, -0.51574279024362624,
      1.1131606697659659, -0.5061925255767965, -0.730899866970255,
      1.0197746301332034, -0.17414013125579708, -0.969399910539121,
      0.96170455293334445, 0.039392267775240346, -1.0375653844658239,
      0.76774702689971852, 0.31727849591313023, -1.1465918116831018,
      0.65995792201020154, 0.45413195161600406, -1.1131826430382779,
      0.45725014985498569, 0.64864092823069863, -1.151508738252125,
      0.37048894022701123, 0.70595217690715084, -1.0764492719693075,
      0.2084920462160309, 0.83036873581429294, -1.0976354627093357,
      0.17414013125578096, 0.82884417831294566, -1.0243861200587783,
      0.0707487855215978, 0.904677037945323, -1.0605940446009974,
      0.097794427170477566, 0.86209216020028734, -1.0101959102267288,
      0.056840867008300412, 0.900583676061146, -1.0719785548721428,
      0.14645516098405814, 0.82019972901730953, -1.0449822367726793,
      0.16751993063601103, 0.81624712432999957, -1.1229141711500397,
      0.31727849591323032, 0.6852030013336855, -1.0994775174818154,
      0.39406005635592345, 0.61990427060588171, -1.1626556655488118,
      0.59055584230794944, 0.41640875005008615, -1.1005499622517476,
      0.69825888035956629, 0.27005725293589145, -1.0964079316598445,
      0.9005836760612147, -0.016407819026412557, -0.93612491277138921,
      0.97815377967386663, -0.23600263496609913, -0.80524806838747365,
      1.1035064488179087, -0.568960540368687, -0.49913241358114657,
      1.0495912307747453, -0.7871389955915713, -0.22202037609476824,
      0.98865807946882667, -1.0485017439388227, 0.20171511088821237,
      0.70602975184502581, -1.1075622027768739, 0.5305494354982867,
      0.40327865021581538, -1.1180840755398607, 0.90058367606121681,
      -0.0863001455635846, -0.85324671119028817, 1.0401158757951092,
      -0.49913241358111987, -0.51562212406197194, 1.0799280887625922,
      -0.93871668805368691, 0.041956057161151208, 0.7842855597942624,
      -1.09947751748185, 0.51859782411156941, 0.37048894022677237,
      -1.091494284924307, 0.97210060751140293, -0.26672325136617919,
      -0.68779059712645552, 1.0624812703225963, -0.7671095305748169,
      -0.15255973706428777, 0.90058367606118583, -1.136288833944231,
      0.54239838277570773, 0.31270396469431472, -1.0243861200587141,
      0.96140623500056421, -0.33733360238367671, -0.60257082003210183,
      1.0848263999603882, -0.97118355149678948, 0.17414013125579869,
      0.63139163908494322, -1.10756220277683, 0.79583764595912865,
      -0.062915451595380451, -0.80511846915289342, 1.1128310880299601,
      -0.84766976325269228, 0.0069942868062422567, 0.73642732287951629,
      -1.1131826430382759, 0.73890804676709543, -0.0069942868062505921,
      -0.82539109945397671, 1.1128310880299161, -0.866885009409127,
      0.062915451595349642, 0.67484173931718516, -1.10756220277689,
      0.83122510774246217, -0.174140131255825, -0.67367761847350538,
      1.0848263999603949, -1.0154915997621936, 0.3373336023836826,
      0.41664098835143409, -1.0243861200586939, 1.0032045292477765,
      -0.54239838277572, -0.29050953454248207, 0.90058367606113288,
      -1.1577776162637, 0.76710953057481091, -0.10005221605177451,
      -0.68779059712648383, 1.0424440013192717, -0.97210060751142557,
      0.34250883239651669, 0.37048894022686624, -1.0065962990559865,
      1.0994775174817919, -0.78678310870306623, 0.041956057161161291,
      0.62047684789861579, -1.0799280887625751, 0.96164518420267442,
      -0.49913241358117594, -0.27672079922437415, 0.85324671119032791,
      -1.1618315304841049, 0.90058367606124134, -0.36148566734659382,
      -0.4032786502157345, 0.900834087847126, -1.1075622027768721,
      0.76822933743021316, -0.201715110888302, -0.54049051761524192,
      0.98865807946883977, -1.1489196634889096, 0.78713899559153655,
      -0.22501796573454, -0.49913241358107874, 0.935478306295136,
      -1.1035064488179227, 0.76832437083250515, -0.23600263496598609,
      -0.47670080288220207, 0.93612491277131793, -1.1617538943451686,
      0.90058367606110989, -0.42776565069574751, -0.27005725293594879,
      0.77550081572152152, -1.1005499622517416, 0.96193503865630725,
      -0.59055584230795177, -0.068201223933793673, 0.61990427060587838,
      -1.0698729931779549, 1.0994775174817757, -0.88507730656688111,
      0.31727849591312979, 0.24654392232255859, -0.81624712433004665,
      1.0429434442566916, -1.0449822367728232, 0.64582704102273325,
      -0.14645516098403655, -0.4892750190129076, 0.90058367606123035,
      -1.1568223981672847, 1.010195910226795, -0.6873625823877344,
      0.097794427170464951, 0.41737640690599109, -0.90467703794540533,
      1.0580239748668963, -1.0243861200587916, 0.635075487326638,
      -0.17414013125587485, -0.423968294217014, 0.83036873581426252,
      -1.1313205952635854, 1.0764492719693439, -0.8658725967503168,
      0.37048894022693052, 0.11019578921170421, -0.64864092823068187,
      0.94273038888853888, -1.1131826430383056, 0.94437752858705493,
      -0.65995792201019887, 0.14146033582010123, 0.31727849591301732,
      -0.80376839321782123, 1.037565384465756, -1.1576817882008428,
      0.96170455293338675, -0.67514229164074835, 0.174140131255795,
      0.26097129927557683, -0.73089986697026554, 0.96744214760989689,
      -1.1131606697658929, 0.96318241026096341, -0.73089986697031528,
      0.27799505055241314, 0.13257689145273355, -0.61270548647237022,
      0.90058367606107526, -1.1334412256147091, 1.0947541325799492,
      -0.976784090383278, 0.61990427060589282, -0.26439161511097681,
      -0.21545590840340648, 0.56552920881704, -0.9167421936561132,
      1.0390312538445445, -1.0994775174818272, 0.91223611124233317,
      -0.687790597126564, 0.27898649733943953, 0.076876421952962,
      -0.51254300384003826, 0.79206916577180186, -1.0615991285942203,
      1.110524926559231, -1.1156029186677157, 0.90058367606126721,
      -0.67307890816878135, 0.28360634978510979, 0.043367549101199186,
      -0.44850845100484621, 0.71014796325214258, -0.978839654244631,
      1.0516762243259947, -1.1005499622518646, 0.9476872721667815,
      -0.78713899559165368, 0.46226636417268, -0.18104486940795259,
      -0.2029282822619019, 0.48028938128591242, -0.79963465389307931,
      0.96170455293341583, -1.1264655573416102, 1.1114032763638617,
      -1.0911924268115589, 0.90058367606114353, -0.72644798037104419,
      0.41628489703167354, -0.16272688580387731, -0.18104486940791381,
      0.42425671240255897, -0.71494450596141834, 0.87053773084436881,
      -1.044982236772624, 1.067485427806127, -1.0994775174817255,
      0.98241717148205654, -0.88385633051386026, 0.65549362427383506,
      -0.46763214145612336, 0.17885167570715482, 0.041956057160997977,
      -0.33282823196413053, 0.53014010227478847, -0.77123845751936748,
      0.900583676061105, -1.0562009211726315, 1.0921329352672788,
      -1.1470392732835761, 1.0848263999603647, -1.043566951262493,
      0.89645476067551433, -0.7789855553082875, 0.57266515989828348,
      -0.40809141340730604, 0.17414013125580974, 0.0057790920406669893,
      -0.23600263496593082, 0.40233828176368353, -0.60236678564674806,
      0.73279130957204563, -0.88385633051375534, 0.96451613074784437,
      -1.0565173551777198, 1.0822089312859517, -1.1131826430383132,
      1.0862647483342442, -1.0608400621510781, 0.98939364219839421,
      -0.91674219365629073, 0.81245562260184645, -0.70416612474562235,
      0.5803203946647818, -0.4485084510048733, 0.3183072433444295,
      -0.17414013125584524, 0.049504513113204779, 0.097794427170353443,
      -0.20694852169694425, 0.35063752647124863, -0.43669091671703664,
      0.57266515989826938, -0.63024686877126246, 0.75691229926905768,
      -0.78261451757175338, 0.90058367606117207, -0.89253844875427657,
      1.0042398652640634, -0.96163929827709771, 1.0709125061321543,
      -0.99353326210536463, 1.1052596819817173, -0.99303147659544211,
      1.1128310880299426, -0.96547066977970464, 1.099477517481765,
      -0.91619559758816849, 1.0709125061321494, -0.85019160924341153,
      1.0324158470620581, -0.77185170463491137, 0.98865807946886086,
      -0.68485526678123065, 0.94362036533642957, -0.59213356787173832,
      0.90058367606119949, -0.49589848948525234, 0.86216336359333123,
      -0.39771423727654331, 0.83036873581429727, -0.29859605888326551,
      0.80667128674759514, -0.1991243035772445, 0.79206916577188613,
      -0.09956608244825739, 0.78713899559150691, -3.1039788463383945E-14,
      -0.79206916577179853, -0.099558221129019631, -0.80667128674757416,
      -0.199029976434944, -0.83036873581433812, -0.29814815482820867,
      -0.86216336359329238, -0.39633240703691208, -0.90058367606120915,
      -0.49256748542344564, -0.94362036533644833, -0.58528918433298671,
      -0.988658079468853, -0.67228562218670107, -1.0324158470621341,
      -0.75062552679518524, -1.070912506132176, -0.81662951513986826,
      -1.0994775174818185, -0.86590458733144637, -1.1128310880300063,
      -0.89346539414713155, -1.1052596819817768, -0.89396717965713091,
      -1.07091250613218, -0.862073215828809, -1.0042398652640905,
      -0.792972366306026, -0.90058367606119671, -0.68304843512349755,
      -0.75691229926900538, -0.53068078632299254, -0.572665159898251,
      -0.33712483426885709, -0.35063752647129953, -0.10738243924876077,
      -0.097794427170440526, 0.14907059556139185, 0.17414013125574296,
      0.41787332579267622, 0.44850845100480774, 0.67988647711311612,
      0.70416612474554019, 0.91202170505005653, 0.91674219365618881,
      1.0889597246465339, 1.06084006215106, 1.1858308307824394,
      1.113182643038239, 1.181775013734232, 1.0565173551776854,
      1.0640822131962138, 0.88385633051375456, 0.83235739202037917,
      0.602366785646747, 0.50190436421199025, 0.2360026349659142,
      0.10534517448894345, -0.17414013125576, -0.30852533095897972,
      -0.57266515989834033, -0.67941947285993509, -0.89645476067552332,
      -0.94400086881416534, -1.0848263999604337, -1.0474731908353474,
      -1.0921329352673788, -0.95663483872443311, -0.90058367606118994,
      -0.67167237507121658, -0.53014010227481734, -0.23326214951602803,
      -0.041956057161113669, 0.27841775815538383, 0.46763214145607279,
      0.7550597067221122, 0.88385633051376644, 1.0819832539303267,
      1.0994775174817641, 1.1670515102545056, 1.0449822367726336,
      0.97010381329261786, 0.71494450596147829, 0.52382279485083716,
      0.18104486940785111, -0.063160803355607226, -0.41628489703172117,
      -0.62688189792282079, -0.90058367606115841, -0.99162634436331765,
      -1.1114032763638553, -1.0268994748932465, -0.96170455293338786,
      -0.70006857144483525, -0.48028938128597032, -0.10336219981369807,
      0.18104486940783929, 0.56183244662091769, 0.78713899559149925,
      1.0472533546149334, 1.1005499622517076, 1.1512423067742164,
      0.97883965424457464, 0.80971404570034322, 0.44850845100491915,
      0.14293363154948094, -0.28360634978494026, -0.573512825720476,
      -0.90058367606118239, -1.0160368362194176, -1.1105249265591985,
      -0.96203304614598828, -0.79206916577188591, -0.41297692139183562,
      -0.076876421953090759, 0.37855257978765133, 0.68779059712648927,
      1.0118021936905899, 1.0994775174817271, 1.1385973362928434,
      0.91674219365615928, 0.66509529126539557, 0.21545590840352008,
      -0.16482553266264685, -0.61990427060588082, -0.877218007935075,
      -1.0947541325800203, -1.0338751431665669, -0.90058367606115086,
      -0.51313940402419422, -0.13257689145275281, 0.37756113300067812,
      0.73089986697034071, 1.062748492709306, 1.1131606697659109,
      1.0670082300582451, 0.73089986697032, 0.36053738172396815,
      -0.17414013125581868, -0.57557620919245933, -0.96170455293338131,
      -1.0581157057526021, -1.0375653844658896, -0.704202310769646,
      -0.31727849591320778, 0.24102641826834106, 0.65995792201007331,
      1.0439436110353717, 1.113182643038223, 1.042296471336813,
      0.64864092823065467, 0.2097618716600676, -0.37048894022694034,
      -0.76630651430202112, -1.0764492719693646, -1.0317545128152819,
      -0.8303687358142835, -0.32440221176884043, 0.17414013125575051,
      0.73464156977480222, 1.0243861200587372, 1.1575900573151359,
      0.904677037945415, 0.516942489354255, -0.097794427170432047,
      -0.58779649993941308, -1.0101959102267071, -1.057256315719042,
      -0.90058367606119372, -0.38970893656456951, 0.14645516098391195,
      0.74539312347092967, 1.0449822367725952, 1.1425095267048517,
      0.81624712432993185, 0.34611000477088011, -0.31727849591325258,
      -0.785511224118576, -1.0994775174818148, -0.97030691072970643,
      -0.61990427060584263, 0.03136485851439115, 0.59055584230797031,
      1.061501121104552, 1.1005499622517636, 0.8750668981697719,
      0.27005725293586752, -0.32819956824758761, -0.90058367606119094,
      -1.062187811896939, -0.9361249127714184, -0.37713472043399721,
      0.23600263496592072, 0.86789045328076386, 1.1035064488179791,
      1.0350443887434257, 0.49913241358112387, -0.12545188328629048,
      -0.78713899559154465, -1.0493535810406287, -0.98865807946888118,
      -0.4409244351670995, 0.20171511088821911, 0.867795419878519,
      1.1075622027767462, 1.0004001702955081, 0.40327865021575354,
      -0.26191958489817097, -0.90058367606125378, -1.0622654480358003,
      -0.85324671119037265, -0.17715471677623856, 0.49913241358111748,
      1.0612112666509228, 1.0799280887625529, 0.72004293034692268,
      -0.041956057161106813, -0.68721702625479386, -1.0994775174817739,
      -0.90703021660775, -0.37048894022689244, 0.44207491484478423,
      0.97210060751136274, 1.1420100837675093, 0.68779059712656032,
      -0.00048613360356950717, -0.76710953057475761, -1.05821153381544,
      -0.90058367606120127, -0.19094345209430327, 0.54239838277567087,
      1.102770611696009, 1.0243861200587328, 0.51620707079975947,
      -0.33733360238362448, -0.915925517313903, -1.0848263999603851,
      -0.57411153602528864, 0.17414013125578462, 0.93079119019065681,
      1.1075622027768637, 0.77440782176545109, -0.06291545159537329,
      -0.76731892696090587, -1.1128310880299328, -0.72582501700577828,
      0.0069942868061813272, 0.83847412921525954, 1.1131826430382996,
      0.8359934053278526, -0.0069942868062066186, -0.74810368080439416,
      -1.1128310880299357, -0.70555238670464937, 0.062915451595298391,
      0.89540372840744953, 1.107562202776782, 0.73095772153332161,
      -0.17414013125579927, -0.871617469048519, -1.084826399960352,
      -0.50300473758390862, 0.33733360238364885, 1.0609723174488073,
      1.0243861200587214, 0.41227004714260262, -0.54239838277562513,
      -1.0367227514959372, -0.90058367606124534, -0.052993654615967063,
      0.76710953057473474, 1.1620473527709339, 0.68779059712643453,
      -0.1671571689178315, -0.97210060751143468, -0.9919282024760937,
      -0.37048894022685169, 0.61816390655964781, 1.0994775174818265,
      0.88385164224250656, -0.041956057161132945, -0.83915060560540033,
      -1.0799280887625486, -0.41605604161374909, 0.49913241358110771,
      1.1396819582434572, 0.85324671119031548, 0.013265936884809421,
      -0.90058367606123169, -1.0185179930915758, -0.40327865021585318,
      0.63011551794657594, 1.1075622027768348, 0.80559583429329928,
      -0.20171511088826702, -0.94893566149056208, -0.98865807946889916,
      -0.12245429364661815, 0.787138995591591, 1.149157313222946,
      0.49913241358110622, -0.4693944579204723, -1.1035064488179676,
      -0.705681985939306, 0.23600263496588794, 1.0777198621220794,
      0.93612491277137944, 0.083158263421865983, -0.90058367606117051,
      -0.99684184921161434, -0.27005725293578686, 0.79782496280776927,
      1.1005499622517758, 0.51597483249833442, -0.59055584230796121,
      -1.0630895831005, -0.6199042706059209, 0.49362613880418543,
      1.0994775174817435, 0.78476908378198318, -0.31727849591312129,
      -1.02334808870175, -0.81624712432994473, 0.26708601308423474,
      1.0449822367726738, 0.91976581146556136, -0.14645516098394734,
      -0.97241247242385476, -0.90058367606120127, 0.15640694945650757,
      1.0101959102268083, 0.96165824264854949, -0.0977944271704315,
      -0.96102796215273711, -0.90467703794539123, 0.17031486796969636,
      1.0243861200587812, 0.928410260761253, -0.17414013125587893,
      -0.99806938026100089, -0.83036873581430082, 0.30805812866429094,
      1.0764492719693548, 0.80551825935548049, -0.37048894022688983,
      -1.0519426558038438, -0.64864092823064834, 0.55681623230319943,
      1.113182643038273, 0.55369803406431839, -0.65995792201019587,
      -1.0470257292348173, -0.3172784959131415, 0.86731310934796124,
      1.0375653844658994, 0.13895835022347655, -0.961704552933377,
      -0.86983382809091581, 0.17414013125578856, 1.1193407125814494,
      0.73089986697039622, -0.4066264431284235, -1.1131606697659766,
      -0.41617670779539623, 0.73089986697034781, 1.1143511920630564,
      0.13257689145274762, -0.90918770175663532, -0.90058367606115175,
      0.29440192118680625, 1.09475413258007, 0.6624840856869858,
      -0.61990427060586151, -1.041934219557676, -0.21545590840344206,
      0.97930229053485351, 0.91674219365620846, -0.19468393837034637,
      -1.09947751748174, -0.51529645913706867, 0.68779059712655666,
      1.1143372239309484, 0.076876421953043672, -0.961078646991225,
      -0.79206916577188, 0.50634539292523184, 1.1105249265592385,
      0.35873593558471556, -0.90058367606117673, -0.8698618815314515,
      0.28360634978504584, 1.1594568664001814, 0.4485084510049257,
      -0.76759221163457825, -0.97883965424454555, 0.23950709672028364,
      1.1005499622517665, 0.55365565877669987, -0.78713899559153067,
      -0.941219428194541, 0.18104486940788436, 1.1516665106474548,
      0.480289381285917, -0.76759936669373019, -0.96170455293334178,
      0.30800107118560793, 1.1114032763638377, 0.4252644810250345,
      -0.90058367606116418, -0.82868239623193374, 0.41628489703176247,
      1.15648092500067, 0.18104486940789014, -0.96110019281938075,
      -0.71494450596142589, 0.68848221471642634, 1.0449822367726123,
      -0.05667396312341217, -1.0994775174818192, -0.39066760720714849,
      0.88385633051376777, 0.91967777648186477, -0.46763214145618681,
      -1.041970400137644, -0.041956057161168632, 1.1230873863551061,
      0.53014010227477537, -0.78634561192628027, -0.90058367606122491,
      0.49352151580543818, 1.0921329352673346, 0.06905143706392991,
      -1.084826399960418, -0.41622793662742752, 0.89645476067546359,
      0.874335964878923, -0.57266515989830469, -0.99696401231879006,
      0.17414013125584074, 1.1625003022123064, 0.23600263496602075,
      -0.97796396100010785, -0.60236678564671853, 0.86724623863240069,
      0.88385633051381651, -0.46953530141381661, -1.0565173551777216,
      0.2256759456211217, 1.1131826430382623, 0.22222075347331416,
      -1.0608400621510443, -0.44149550234104867, 0.91674219365620813,
      0.80543495746473737, -0.70416612474558082, -0.90025200294011765,
      0.44850845100491171, 1.1182967422322312, -0.17414013125579703,
      -1.0627744668649539, -0.097794427170504655, 1.1394994523243251,
      0.35063752647123386, -0.96112870133648287, -0.57266515989832256,
      0.93894358815889056, 0.75691229926897219, -0.68767314696820259,
      -0.90058367606118273, 0.61795789598781226, 1.0042398652641042,
      -0.34204943970171048, -1.070912506132099, 0.26696658584201616,
      1.1052596819817615, -0.00089695687929560635, -1.11283108802993,
      -0.053225370639160233, 1.0994775174817881, 0.29091892009172815,
      -1.0709125061321287, -0.31244168580386406, 1.0324158470621405,
      0.51583518592017741, -0.98865807946887663, -0.5032647409706057,
      0.9436203653364581, 0.67404292389210352, -0.90058367606118206,
      -0.63110753323614521, 0.86216336359327261, 0.77406951822474135,
      -0.830368735814326, -0.70584370941906538, 0.8066712867475675,
      0.82571730891546857, -0.79206916577189324, -0.73611805742132941,
      0.787138995591505, 0.835684139869652, -0.79206916577188258,
      -0.72615122646721919, 0.80667128674760213, 0.80540979186736772,
      -0.83036873581429993, -0.67450343577649619, 0.86216336359328061,
      0.73067361568439848, -0.90058367606120437, -0.57447684144385669,
      0.94362036533643168, 0.602830823418847, -0.98865807946895623,
      -0.41626910347183521, 1.0324158470620488, 0.41200776825211566,
      -1.0709125061321685, -0.1913528376434574, 1.0994775174817646,
      0.1527914530873892, -1.1128310880299432, 0.10046303932751256,
      1.1052596819818012, -0.16740050339383789, -1.0709125061320968,
      0.44161552214984745, 1.004239865264124, -0.51839181353959,
      -0.90058367606119094, 0.787239229416538, 0.75691229926897419,
      -0.83937750571054937, -0.57266515989828026, 1.0606947837848182,
      0.3506375264713017, -1.0399333698760034, -0.09779442717035676,
      1.1623405493132177, -0.17414013125578195, -1.0187306597839993,
      0.44850845100495434, 0.99981808538827943, -0.70416612474558271,
      -0.70586887501649676, 0.91674219365618093, 0.54106158478929633,
      -1.0608400621510063, -0.12265467102501838, 1.1131826430382883,
      -0.12610986317291323, -1.0565173551776512, 0.569101383861981,
      0.88385633051385326, -0.76768015618418239, -0.60236678564671731,
      1.0775300434482356, 0.23600263496592172, -1.0629342197641156,
      0.17414013125574584, 1.0965300947670786, -0.572665159898306,
      -0.77476988243067368, 0.89645476067551366, 0.51579401907570588,
      -1.0848263999603986, 0.030514645384352088, 1.0921329352673732,
      -0.39395543335718292, -0.90058367606115086, 0.88591169437460371,
      0.53014010227486741, -1.023521303906771, -0.041956057161117596,
      1.1415364825859888, -0.46763214145610732, -0.82011169403357609,
      0.88385633051380874, 0.49023368965549646, -1.0994775174818467,
      0.15624004557177415, 1.0449822367726149, -0.58891613226815,
      -0.71494450596146164, 1.0606662752676428, 0.18104486940787837,
      -1.0569148425524812, 0.41628489703175015, 0.928248478680137,
      -0.90058367606119516, -0.32569839857676597, 1.1114032763637527,
      -0.208434988737293, -0.96170455293342283, 0.86716544914202121,
      0.48028938128591503, -1.0521004281991186, 0.18104486940788744,
      1.04078551064284, -0.78713899559155853, -0.45408957632847319,
      1.1005499622517849, -0.13994101427203981, -0.97883965424462316,
      0.86715829408280642, 0.44850845100484449, -1.0598907839519369,
      0.28360634978499205, 0.96942796397966069, -0.90058367606115208,
      -0.25916985313652158, 1.1105249265592958, -0.40677931047699872,
      -0.79206916577188158, 1.0606447294395633, 0.076876421952973853,
      -1.0147711414826619, 0.687790597126496, 0.614862541585278,
      -1.0994775174818019, 0.29425002081861779, 0.9167421936561444,
      -0.8797362080866542, -0.21545590840342521, 1.1415003020058307,
      -0.61990427060592324, -0.56291800323869612, 1.0947541325799848,
      -0.19483583873860533, -0.90058367606119483, 1.0087537842049383,
      0.13257689145270277, -1.014785109614774, 0.73089986697041176,
      0.51574279024362624, -1.1131606697659659, 0.5061925255767965,
      0.730899866970255, -1.0197746301332034, 0.17414013125579708,
      0.969399910539121, -0.96170455293334445, -0.039392267775240346,
      1.0375653844658239, -0.76774702689971852, -0.31727849591313023,
      1.1465918116831018, -0.65995792201020154, -0.45413195161600406,
      1.1131826430382779, -0.45725014985498569, -0.64864092823069863,
      1.151508738252125, -0.37048894022701123, -0.70595217690715084,
      1.0764492719693075, -0.2084920462160309, -0.83036873581429294,
      1.0976354627093357, -0.17414013125578096, -0.82884417831294566,
      1.0243861200587783, -0.0707487855215978, -0.904677037945323,
      1.0605940446009974, -0.097794427170477566, -0.86209216020028734,
      1.0101959102267288, -0.056840867008300412, -0.900583676061146,
      1.0719785548721428, -0.14645516098405814, -0.82019972901730953,
      1.0449822367726793, -0.16751993063601103, -0.81624712432999957,
      1.1229141711500397, -0.31727849591323032, -0.6852030013336855,
      1.0994775174818154, -0.39406005635592345, -0.61990427060588171,
      1.1626556655488118, -0.59055584230794944, -0.41640875005008615,
      1.1005499622517476, -0.69825888035956629, -0.27005725293589145,
      1.0964079316598445, -0.9005836760612147, 0.016407819026412557,
      0.93612491277138921, -0.97815377967386663, 0.23600263496609913,
      0.80524806838747365, -1.1035064488179087, 0.568960540368687,
      0.49913241358114657, -1.0495912307747453, 0.7871389955915713,
      0.22202037609476824, -0.98865807946882667, 1.0485017439388227,
      -0.20171511088821237, -0.70602975184502581, 1.1075622027768739,
      -0.5305494354982867, -0.40327865021581538, 1.1180840755398607,
      -0.90058367606121681, 0.0863001455635846, 0.85324671119028817,
      -1.0401158757951092, 0.49913241358111987, 0.51562212406197194,
      -1.0799280887625922, 0.93871668805368691, -0.041956057161151208,
      -0.7842855597942624, 1.09947751748185, -0.51859782411156941,
      -0.37048894022677237, 1.091494284924307, -0.97210060751140293,
      0.26672325136617919, 0.68779059712645552, -1.0624812703225963,
      0.7671095305748169, 0.15255973706428777, -0.90058367606118583,
      1.136288833944231, -0.54239838277570773, -0.31270396469431472,
      1.0243861200587141, -0.96140623500056421, 0.33733360238367671,
      0.60257082003210183, -1.0848263999603882, 0.97118355149678948,
      -0.17414013125579869, -0.63139163908494322, 1.10756220277683,
      -0.79583764595912865, 0.062915451595380451, 0.80511846915289342,
      -1.1128310880299601, 0.84766976325269228, -0.0069942868062422567,
      -0.73642732287951629, 1.1131826430382759, -0.73890804676709543,
      0.0069942868062505921, 0.82539109945397671, -1.1128310880299161,
      0.866885009409127, -0.062915451595349642, -0.67484173931718516,
      1.10756220277689, -0.83122510774246217, 0.174140131255825,
      0.67367761847350538, -1.0848263999603949, 1.0154915997621936,
      -0.3373336023836826, -0.41664098835143409, 1.0243861200586939,
      -1.0032045292477765, 0.54239838277572, 0.29050953454248207,
      -0.90058367606113288, 1.1577776162637, -0.76710953057481091,
      0.10005221605177451, 0.68779059712648383, -1.0424440013192717,
      0.97210060751142557, -0.34250883239651669, -0.37048894022686624,
      1.0065962990559865, -1.0994775174817919, 0.78678310870306623,
      -0.041956057161161291, -0.62047684789861579, 1.0799280887625751,
      -0.96164518420267442, 0.49913241358117594, 0.27672079922437415,
      -0.85324671119032791, 1.1618315304841049, -0.90058367606124134,
      0.36148566734659382, 0.4032786502157345, -0.900834087847126,
      1.1075622027768721, -0.76822933743021316, 0.201715110888302,
      0.54049051761524192, -0.98865807946883977, 1.1489196634889096,
      -0.78713899559153655, 0.22501796573454, 0.49913241358107874,
      -0.935478306295136, 1.1035064488179227, -0.76832437083250515,
      0.23600263496598609, 0.47670080288220207, -0.93612491277131793,
      1.1617538943451686, -0.90058367606110989, 0.42776565069574751,
      0.27005725293594879, -0.77550081572152152, 1.1005499622517416,
      -0.96193503865630725, 0.59055584230795177, 0.068201223933793673,
      -0.61990427060587838, 1.0698729931779549, -1.0994775174817757,
      0.88507730656688111, -0.31727849591312979, -0.24654392232255859,
      0.81624712433004665, -1.0429434442566916, 1.0449822367728232,
      -0.64582704102273325, 0.14645516098403655, 0.4892750190129076,
      -0.90058367606123035, 1.1568223981672847, -1.010195910226795,
      0.6873625823877344, -0.097794427170464951, -0.41737640690599109,
      0.90467703794540533, -1.0580239748668963, 1.0243861200587916,
      -0.635075487326638, 0.17414013125587485, 0.423968294217014,
      -0.83036873581426252, 1.1313205952635854, -1.0764492719693439,
      0.8658725967503168, -0.37048894022693052, -0.11019578921170421,
      0.64864092823068187, -0.94273038888853888, 1.1131826430383056,
      -0.94437752858705493, 0.65995792201019887, -0.14146033582010123,
      -0.31727849591301732, 0.80376839321782123, -1.037565384465756,
      1.1576817882008428, -0.96170455293338675, 0.67514229164074835,
      -0.174140131255795, -0.26097129927557683, 0.73089986697026554,
      -0.96744214760989689, 1.1131606697658929, -0.96318241026096341,
      0.73089986697031528, -0.27799505055241314, -0.13257689145273355,
      0.61270548647237022, -0.90058367606107526, 1.1334412256147091,
      -1.0947541325799492, 0.976784090383278, -0.61990427060589282,
      0.26439161511097681, 0.21545590840340648, -0.56552920881704,
      0.9167421936561132, -1.0390312538445445, 1.0994775174818272,
      -0.91223611124233317, 0.687790597126564, -0.27898649733943953,
      -0.076876421952962, 0.51254300384003826, -0.79206916577180186,
      1.0615991285942203, -1.110524926559231, 1.1156029186677157,
      -0.90058367606126721, 0.67307890816878135, -0.28360634978510979,
      -0.043367549101199186, 0.44850845100484621, -0.71014796325214258,
      0.978839654244631, -1.0516762243259947, 1.1005499622518646,
      -0.9476872721667815, 0.78713899559165368, -0.46226636417268,
      0.18104486940795259, 0.2029282822619019, -0.48028938128591242,
      0.79963465389307931, -0.96170455293341583, 1.1264655573416102,
      -1.1114032763638617, 1.0911924268115589, -0.90058367606114353,
      0.72644798037104419, -0.41628489703167354, 0.16272688580387731,
      0.18104486940791381, -0.42425671240255897, 0.71494450596141834,
      -0.87053773084436881, 1.044982236772624, -1.067485427806127,
      1.0994775174817255, -0.98241717148205654, 0.88385633051386026,
      -0.65549362427383506, 0.46763214145612336, -0.17885167570715482,
      -0.041956057160997977, 0.33282823196413053, -0.53014010227478847,
      0.77123845751936748, -0.900583676061105, 1.0562009211726315,
      -1.0921329352672788, 1.1470392732835761, -1.0848263999603647,
      1.043566951262493, -0.89645476067551433, 0.7789855553082875,
      -0.57266515989828348, 0.40809141340730604, -0.17414013125580974,
      -0.0057790920406669893, 0.23600263496593082, -0.40233828176368353,
      0.60236678564674806, -0.73279130957204563, 0.88385633051375534,
      -0.96451613074784437, 1.0565173551777198, -1.0822089312859517,
      1.1131826430383132, -1.0862647483342442, 1.0608400621510781,
      -0.98939364219839421, 0.91674219365629073, -0.81245562260184645,
      0.70416612474562235, -0.5803203946647818, 0.4485084510048733,
      -0.3183072433444295, 0.17414013125584524, -0.049504513113204779,
      -0.097794427170353443, 0.20694852169694425, -0.35063752647124863,
      0.43669091671703664, -0.57266515989826938, 0.63024686877126246,
      -0.75691229926905768, 0.78261451757175338, -0.90058367606117207,
      0.89253844875427657, -1.0042398652640634, 0.96163929827709771,
      -1.0709125061321543, 0.99353326210536463, -1.1052596819817173,
      0.99303147659544211, -1.1128310880299426, 0.96547066977970464,
      -1.099477517481765, 0.91619559758816849, -1.0709125061321494,
      0.85019160924341153, -1.0324158470620581, 0.77185170463491137,
      -0.98865807946886086, 0.68485526678123065, -0.94362036533642957,
      0.59213356787173832, -0.90058367606119949, 0.49589848948525234,
      -0.86216336359333123, 0.39771423727654331, -0.83036873581429727,
      0.29859605888326551, -0.80667128674759514, 0.1991243035772445,
      -0.79206916577188613, 0.09956608244825739, -0.78713899559150691,
      3.1039788463383945E-14, 0.79206916577179853, 0.099558221129019631,
      0.80667128674757416, 0.199029976434944, 0.83036873581433812,
      0.29814815482820867, 0.86216336359329238, 0.39633240703691208,
      0.90058367606120915, 0.49256748542344564, 0.94362036533644833,
      0.58528918433298671, 0.988658079468853, 0.67228562218670107,
      1.0324158470621341, 0.75062552679518524, 1.070912506132176,
      0.81662951513986826, 1.0994775174818185, 0.86590458733144637,
      1.1128310880300063, 0.89346539414713155, 1.1052596819817768,
      0.89396717965713091, 1.07091250613218, 0.862073215828809,
      1.0042398652640905, 0.792972366306026, 0.90058367606119671,
      0.68304843512349755, 0.75691229926900538, 0.53068078632299254,
      0.572665159898251, 0.33712483426885709, 0.35063752647129953,
      0.10738243924876077, 0.097794427170440526, -0.14907059556139185,
      -0.17414013125574296, -0.41787332579267622, -0.44850845100480774,
      -0.67988647711311612, -0.70416612474554019, -0.91202170505005653,
      -0.91674219365618881, -1.0889597246465339, -1.06084006215106,
      -1.1858308307824394, -1.113182643038239, -1.181775013734232,
      -1.0565173551776854, -1.0640822131962138, -0.88385633051375456,
      -0.83235739202037917, -0.602366785646747, -0.50190436421199025,
      -0.2360026349659142, -0.10534517448894345, 0.17414013125576,
      0.30852533095897972, 0.57266515989834033, 0.67941947285993509,
      0.89645476067552332, 0.94400086881416534, 1.0848263999604337,
      1.0474731908353474, 1.0921329352673788, 0.95663483872443311,
      0.90058367606118994, 0.67167237507121658, 0.53014010227481734,
      0.23326214951602803, 0.041956057161113669, -0.27841775815538383,
      -0.46763214145607279, -0.7550597067221122, -0.88385633051376644,
      -1.0819832539303267, -1.0994775174817641, -1.1670515102545056,
      -1.0449822367726336, -0.97010381329261786, -0.71494450596147829,
      -0.52382279485083716, -0.18104486940785111, 0.063160803355607226,
      0.41628489703172117, 0.62688189792282079, 0.90058367606115841,
      0.99162634436331765, 1.1114032763638553, 1.0268994748932465,
      0.96170455293338786, 0.70006857144483525, 0.48028938128597032,
      0.10336219981369807, -0.18104486940783929, -0.56183244662091769,
      -0.78713899559149925, -1.0472533546149334, -1.1005499622517076,
      -1.1512423067742164, -0.97883965424457464, -0.80971404570034322,
      -0.44850845100491915, -0.14293363154948094, 0.28360634978494026,
      0.573512825720476, 0.90058367606118239, 1.0160368362194176,
      1.1105249265591985, 0.96203304614598828, 0.79206916577188591,
      0.41297692139183562, 0.076876421953090759, -0.37855257978765133,
      -0.68779059712648927, -1.0118021936905899, -1.0994775174817271,
      -1.1385973362928434, -0.91674219365615928, -0.66509529126539557,
      -0.21545590840352008, 0.16482553266264685, 0.61990427060588082,
      0.877218007935075, 1.0947541325800203, 1.0338751431665669,
      0.90058367606115086, 0.51313940402419422, 0.13257689145275281,
      -0.37756113300067812, -0.73089986697034071, -1.062748492709306,
      -1.1131606697659109, -1.0670082300582451, -0.73089986697032,
      -0.36053738172396815, 0.17414013125581868, 0.57557620919245933,
      0.96170455293338131, 1.0581157057526021, 1.0375653844658896,
      0.704202310769646, 0.31727849591320778, -0.24102641826834106,
      -0.65995792201007331, -1.0439436110353717, -1.113182643038223,
      -1.042296471336813, -0.64864092823065467, -0.2097618716600676,
      0.37048894022694034, 0.76630651430202112, 1.0764492719693646,
      1.0317545128152819, 0.8303687358142835, 0.32440221176884043,
      -0.17414013125575051, -0.73464156977480222, -1.0243861200587372,
      -1.1575900573151359, -0.904677037945415, -0.516942489354255,
      0.097794427170432047, 0.58779649993941308, 1.0101959102267071,
      1.057256315719042, 0.90058367606119372, 0.38970893656456951,
      -0.14645516098391195, -0.74539312347092967, -1.0449822367725952,
      -1.1425095267048517, -0.81624712432993185, -0.34611000477088011,
      0.31727849591325258, 0.785511224118576, 1.0994775174818148,
      0.97030691072970643, 0.61990427060584263, -0.03136485851439115,
      -0.59055584230797031, -1.061501121104552, -1.1005499622517636,
      -0.8750668981697719, -0.27005725293586752, 0.32819956824758761,
      0.90058367606119094, 1.062187811896939, 0.9361249127714184,
      0.37713472043399721, -0.23600263496592072, -0.86789045328076386,
      -1.1035064488179791, -1.0350443887434257, -0.49913241358112387,
      0.12545188328629048, 0.78713899559154465, 1.0493535810406287,
      0.98865807946888118, 0.4409244351670995, -0.20171511088821911,
      -0.867795419878519, -1.1075622027767462, -1.0004001702955081,
      -0.40327865021575354, 0.26191958489817097, 0.90058367606125378,
      1.0622654480358003, 0.85324671119037265, 0.17715471677623856,
      -0.49913241358111748, -1.0612112666509228, -1.0799280887625529,
      -0.72004293034692268, 0.041956057161106813, 0.68721702625479386,
      1.0994775174817739, 0.90703021660775, 0.37048894022689244,
      -0.44207491484478423, -0.97210060751136274, -1.1420100837675093,
      -0.68779059712656032, 0.00048613360356950717, 0.76710953057475761,
      1.05821153381544, 0.90058367606120127, 0.19094345209430327,
      -0.54239838277567087, -1.102770611696009, -1.0243861200587328,
      -0.51620707079975947, 0.33733360238362448, 0.915925517313903,
      1.0848263999603851, 0.57411153602528864, -0.17414013125578462,
      -0.93079119019065681, -1.1075622027768637, -0.77440782176545109,
      0.06291545159537329, 0.76731892696090587, 1.1128310880299328,
      0.72582501700577828, -0.0069942868061813272, -0.83847412921525954,
      -1.1131826430382996, -0.8359934053278526, 0.0069942868062066186,
      0.74810368080439416, 1.1128310880299357, 0.70555238670464937,
      -0.062915451595298391, -0.89540372840744953, -1.107562202776782,
      -0.73095772153332161, 0.17414013125579927, 0.871617469048519,
      1.084826399960352, 0.50300473758390862, -0.33733360238364885,
      -1.0609723174488073, -1.0243861200587214, -0.41227004714260262,
      0.54239838277562513, 1.0367227514959372, 0.90058367606124534,
      0.052993654615967063, -0.76710953057473474, -1.1620473527709339,
      -0.68779059712643453, 0.1671571689178315, 0.97210060751143468,
      0.9919282024760937, 0.37048894022685169, -0.61816390655964781,
      -1.0994775174818265, -0.88385164224250656, 0.041956057161132945,
      0.83915060560540033, 1.0799280887625486, 0.41605604161374909,
      -0.49913241358110771, -1.1396819582434572, -0.85324671119031548,
      -0.013265936884809421, 0.90058367606123169, 1.0185179930915758,
      0.40327865021585318, -0.63011551794657594, -1.1075622027768348,
      -0.80559583429329928, 0.20171511088826702, 0.94893566149056208,
      0.98865807946889916, 0.12245429364661815, -0.787138995591591,
      -1.149157313222946, -0.49913241358110622, 0.4693944579204723,
      1.1035064488179676, 0.705681985939306, -0.23600263496588794,
      -1.0777198621220794, -0.93612491277137944, -0.083158263421865983,
      0.90058367606117051, 0.99684184921161434, 0.27005725293578686,
      -0.79782496280776927, -1.1005499622517758, -0.51597483249833442,
      0.59055584230796121, 1.0630895831005, 0.6199042706059209,
      -0.49362613880418543, -1.0994775174817435, -0.78476908378198318,
      0.31727849591312129, 1.02334808870175, 0.81624712432994473,
      -0.26708601308423474, -1.0449822367726738, -0.91976581146556136,
      0.14645516098394734, 0.97241247242385476, 0.90058367606120127,
      -0.15640694945650757, -1.0101959102268083, -0.96165824264854949,
      0.0977944271704315, 0.96102796215273711, 0.90467703794539123,
      -0.17031486796969636, -1.0243861200587812, -0.928410260761253,
      0.17414013125587893, 0.99806938026100089, 0.83036873581430082,
      -0.30805812866429094, -1.0764492719693548, -0.80551825935548049,
      0.37048894022688983, 1.0519426558038438, 0.64864092823064834,
      -0.55681623230319943, -1.113182643038273, -0.55369803406431839,
      0.65995792201019587, 1.0470257292348173, 0.3172784959131415,
      -0.86731310934796124, -1.0375653844658994, -0.13895835022347655,
      0.961704552933377, 0.86983382809091581, -0.17414013125578856,
      -1.1193407125814494, -0.73089986697039622, 0.4066264431284235,
      1.1131606697659766, 0.41617670779539623, -0.73089986697034781,
      -1.1143511920630564, -0.13257689145274762, 0.90918770175663532,
      0.90058367606115175, -0.29440192118680625, -1.09475413258007,
      -0.6624840856869858, 0.61990427060586151, 1.041934219557676,
      0.21545590840344206, -0.97930229053485351, -0.91674219365620846,
      0.19468393837034637, 1.09947751748174, 0.51529645913706867,
      -0.68779059712655666, -1.1143372239309484, -0.076876421953043672,
      0.961078646991225, 0.79206916577188, -0.50634539292523184,
      -1.1105249265592385, -0.35873593558471556, 0.90058367606117673,
      0.8698618815314515, -0.28360634978504584, -1.1594568664001814,
      -0.4485084510049257, 0.76759221163457825, 0.97883965424454555,
      -0.23950709672028364, -1.1005499622517665, -0.55365565877669987,
      0.78713899559153067, 0.941219428194541, -0.18104486940788436,
      -1.1516665106474548, -0.480289381285917, 0.76759936669373019,
      0.96170455293334178, -0.30800107118560793, -1.1114032763638377,
      -0.4252644810250345, 0.90058367606116418, 0.82868239623193374,
      -0.41628489703176247, -1.15648092500067, -0.18104486940789014,
      0.96110019281938075, 0.71494450596142589, -0.68848221471642634,
      -1.0449822367726123, 0.05667396312341217, 1.0994775174818192,
      0.39066760720714849, -0.88385633051376777, -0.91967777648186477,
      0.46763214145618681, 1.041970400137644, 0.041956057161168632,
      -1.1230873863551061, -0.53014010227477537, 0.78634561192628027,
      0.90058367606122491, -0.49352151580543818, -1.0921329352673346,
      -0.06905143706392991, 1.084826399960418, 0.41622793662742752,
      -0.89645476067546359, -0.874335964878923, 0.57266515989830469,
      0.99696401231879006, -0.17414013125584074, -1.1625003022123064,
      -0.23600263496602075, 0.97796396100010785, 0.60236678564671853,
      -0.86724623863240069, -0.88385633051381651, 0.46953530141381661,
      1.0565173551777216, -0.2256759456211217, -1.1131826430382623,
      -0.22222075347331416, 1.0608400621510443, 0.44149550234104867,
      -0.91674219365620813, -0.80543495746473737, 0.70416612474558082,
      0.90025200294011765, -0.44850845100491171, -1.1182967422322312,
      0.17414013125579703, 1.0627744668649539, 0.097794427170504655,
      -1.1394994523243251, -0.35063752647123386, 0.96112870133648287,
      0.57266515989832256, -0.93894358815889056, -0.75691229926897219,
      0.68767314696820259, 0.90058367606118273, -0.61795789598781226,
      -1.0042398652641042, 0.34204943970171048, 1.070912506132099,
      -0.26696658584201616, -1.1052596819817615, 0.00089695687929560635,
      1.11283108802993, 0.053225370639160233, -1.0994775174817881,
      -0.29091892009172815, 1.0709125061321287, 0.31244168580386406,
      -1.0324158470621405, -0.51583518592017741, 0.98865807946887663,
      0.5032647409706057, -0.9436203653364581, -0.67404292389210352,
      0.90058367606118206, 0.63110753323614521, -0.86216336359327261,
      -0.77406951822474135, 0.830368735814326, 0.70584370941906538,
      -0.8066712867475675, -0.82571730891546857, 0.79206916577189324,
      0.73611805742132941, -0.787138995591505, -0.835684139869652,
      0.79206916577188258, 0.72615122646721919, -0.80667128674760213,
      -0.80540979186736772, 0.83036873581429993, 0.67450343577649619,
      -0.86216336359328061, -0.73067361568439848, 0.90058367606120437,
      0.57447684144385669, -0.94362036533643168, -0.602830823418847,
      0.98865807946895623, 0.41626910347183521, -1.0324158470620488,
      -0.41200776825211566, 1.0709125061321685, 0.1913528376434574,
      -1.0994775174817646, -0.1527914530873892, 1.1128310880299432,
      -0.10046303932751256, -1.1052596819818012, 0.16740050339383789,
      1.0709125061320968, -0.44161552214984745, -1.004239865264124,
      0.51839181353959, 0.90058367606119094, -0.787239229416538,
      -0.75691229926897419, 0.83937750571054937, 0.57266515989828026,
      -1.0606947837848182, -0.3506375264713017, 1.0399333698760034,
      0.09779442717035676, -1.1623405493132177, 0.17414013125578195,
      1.0187306597839993, -0.44850845100495434, -0.99981808538827943,
      0.70416612474558271, 0.70586887501649676, -0.91674219365618093,
      -0.54106158478929633, 1.0608400621510063, 0.12265467102501838,
      -1.1131826430382883, 0.12610986317291323, 1.0565173551776512,
      -0.569101383861981, -0.88385633051385326, 0.76768015618418239,
      0.60236678564671731, -1.0775300434482356, -0.23600263496592172,
      1.0629342197641156, -0.17414013125574584, -1.0965300947670786,
      0.572665159898306, 0.77476988243067368, -0.89645476067551366,
      -0.51579401907570588, 1.0848263999603986, -0.030514645384352088,
      -1.0921329352673732, 0.39395543335718292, 0.90058367606115086,
      -0.88591169437460371, -0.53014010227486741, 1.023521303906771,
      0.041956057161117596, -1.1415364825859888, 0.46763214145610732,
      0.82011169403357609, -0.88385633051380874, -0.49023368965549646,
      1.0994775174818467, -0.15624004557177415, -1.0449822367726149,
      0.58891613226815, 0.71494450596146164, -1.0606662752676428,
      -0.18104486940787837, 1.0569148425524812, -0.41628489703175015,
      -0.928248478680137, 0.90058367606119516, 0.32569839857676597,
      -1.1114032763637527, 0.208434988737293, 0.96170455293342283,
      -0.86716544914202121, -0.48028938128591503, 1.0521004281991186,
      -0.18104486940788744, -1.04078551064284, 0.78713899559155853,
      0.45408957632847319, -1.1005499622517849, 0.13994101427203981,
      0.97883965424462316, -0.86715829408280642, -0.44850845100484449,
      1.0598907839519369, -0.28360634978499205, -0.96942796397966069,
      0.90058367606115208, 0.25916985313652158, -1.1105249265592958,
      0.40677931047699872, 0.79206916577188158, -1.0606447294395633,
      -0.076876421952973853, 1.0147711414826619, -0.687790597126496,
      -0.614862541585278, 1.0994775174818019, -0.29425002081861779,
      -0.9167421936561444, 0.8797362080866542, 0.21545590840342521,
      -1.1415003020058307, 0.61990427060592324, 0.56291800323869612,
      -1.0947541325799848, 0.19483583873860533, 0.90058367606119483,
      -1.0087537842049383, -0.13257689145270277, 1.014785109614774,
      -0.73089986697041176, -0.51574279024362624, 1.1131606697659659,
      -0.5061925255767965, -0.730899866970255, 1.0197746301332034,
      -0.17414013125579708, -0.969399910539121, 0.96170455293334445,
      0.039392267775240346, -1.0375653844658239, 0.76774702689971852,
      0.31727849591313023, -1.1465918116831018, 0.65995792201020154,
      0.45413195161600406, -1.1131826430382779, 0.45725014985498569,
      0.64864092823069863, -1.151508738252125, 0.37048894022701123,
      0.70595217690715084, -1.0764492719693075, 0.2084920462160309,
      0.83036873581429294, -1.0976354627093357, 0.17414013125578096,
      0.82884417831294566, -1.0243861200587783, 0.0707487855215978,
      0.904677037945323, -1.0605940446009974, 0.097794427170477566,
      0.86209216020028734, -1.0101959102267288, 0.056840867008300412,
      0.900583676061146, -1.0719785548721428, 0.14645516098405814,
      0.82019972901730953, -1.0449822367726793, 0.16751993063601103,
      0.81624712432999957, -1.1229141711500397, 0.31727849591323032,
      0.6852030013336855, -1.0994775174818154, 0.39406005635592345,
      0.61990427060588171, -1.1626556655488118, 0.59055584230794944,
      0.41640875005008615, -1.1005499622517476, 0.69825888035956629,
      0.27005725293589145, -1.0964079316598445, 0.9005836760612147,
      -0.016407819026412557, -0.93612491277138921, 0.97815377967386663,
      -0.23600263496609913, -0.80524806838747365, 1.1035064488179087,
      -0.568960540368687, -0.49913241358114657, 1.0495912307747453,
      -0.7871389955915713, -0.22202037609476824, 0.98865807946882667,
      -1.0485017439388227, 0.20171511088821237, 0.70602975184502581,
      -1.1075622027768739, 0.5305494354982867, 0.40327865021581538,
      -1.1180840755398607, 0.90058367606121681, -0.0863001455635846,
      -0.85324671119028817, 1.0401158757951092, -0.49913241358111987,
      -0.51562212406197194, 1.0799280887625922, -0.93871668805368691,
      0.041956057161151208, 0.7842855597942624, -1.09947751748185,
      0.51859782411156941, 0.37048894022677237, -1.091494284924307,
      0.97210060751140293, -0.26672325136617919, -0.68779059712645552,
      1.0624812703225963, -0.7671095305748169, -0.15255973706428777,
      0.90058367606118583, -1.136288833944231, 0.54239838277570773,
      0.31270396469431472, -1.0243861200587141, 0.96140623500056421,
      -0.33733360238367671, -0.60257082003210183, 1.0848263999603882,
      -0.97118355149678948, 0.17414013125579869, 0.63139163908494322,
      -1.10756220277683, 0.79583764595912865, -0.062915451595380451,
      -0.80511846915289342, 1.1128310880299601, -0.84766976325269228,
      0.0069942868062422567, 0.73642732287951629, -1.1131826430382759,
      0.73890804676709543, -0.0069942868062505921, -0.82539109945397671,
      1.1128310880299161, -0.866885009409127, 0.062915451595349642,
      0.67484173931718516, -1.10756220277689, 0.83122510774246217,
      -0.174140131255825, -0.67367761847350538, 1.0848263999603949,
      -1.0154915997621936, 0.3373336023836826, 0.41664098835143409,
      -1.0243861200586939, 1.0032045292477765, -0.54239838277572,
      -0.29050953454248207, 0.90058367606113288, -1.1577776162637,
      0.76710953057481091, -0.10005221605177451, -0.68779059712648383,
      1.0424440013192717, -0.97210060751142557, 0.34250883239651669,
      0.37048894022686624, -1.0065962990559865, 1.0994775174817919,
      -0.78678310870306623, 0.041956057161161291, 0.62047684789861579,
      -1.0799280887625751, 0.96164518420267442, -0.49913241358117594,
      -0.27672079922437415, 0.85324671119032791, -1.1618315304841049,
      0.90058367606124134, -0.36148566734659382, -0.4032786502157345,
      0.900834087847126, -1.1075622027768721, 0.76822933743021316,
      -0.201715110888302, -0.54049051761524192, 0.98865807946883977,
      -1.1489196634889096, 0.78713899559153655, -0.22501796573454,
      -0.49913241358107874, 0.935478306295136, -1.1035064488179227,
      0.76832437083250515, -0.23600263496598609, -0.47670080288220207,
      0.93612491277131793, -1.1617538943451686, 0.90058367606110989,
      -0.42776565069574751, -0.27005725293594879, 0.77550081572152152,
      -1.1005499622517416, 0.96193503865630725, -0.59055584230795177,
      -0.068201223933793673, 0.61990427060587838, -1.0698729931779549,
      1.0994775174817757, -0.88507730656688111, 0.31727849591312979,
      0.24654392232255859, -0.81624712433004665, 1.0429434442566916,
      -1.0449822367728232, 0.64582704102273325, -0.14645516098403655,
      -0.4892750190129076, 0.90058367606123035, -1.1568223981672847,
      1.010195910226795, -0.6873625823877344, 0.097794427170464951,
      0.41737640690599109, -0.90467703794540533, 1.0580239748668963,
      -1.0243861200587916, 0.635075487326638, -0.17414013125587485,
      -0.423968294217014, 0.83036873581426252, -1.1313205952635854,
      1.0764492719693439, -0.8658725967503168, 0.37048894022693052,
      0.11019578921170421, -0.64864092823068187, 0.94273038888853888,
      -1.1131826430383056, 0.94437752858705493, -0.65995792201019887,
      0.14146033582010123, 0.31727849591301732, -0.80376839321782123,
      1.037565384465756, -1.1576817882008428, 0.96170455293338675,
      -0.67514229164074835, 0.174140131255795, 0.26097129927557683,
      -0.73089986697026554, 0.96744214760989689, -1.1131606697658929,
      0.96318241026096341, -0.73089986697031528, 0.27799505055241314,
      0.13257689145273355, -0.61270548647237022, 0.90058367606107526,
      -1.1334412256147091, 1.0947541325799492, -0.976784090383278,
      0.61990427060589282, -0.26439161511097681, -0.21545590840340648,
      0.56552920881704, -0.9167421936561132, 1.0390312538445445,
      -1.0994775174818272, 0.91223611124233317, -0.687790597126564,
      0.27898649733943953, 0.076876421952962, -0.51254300384003826,
      0.79206916577180186, -1.0615991285942203, 1.110524926559231,
      -1.1156029186677157, 0.90058367606126721, -0.67307890816878135,
      0.28360634978510979, 0.043367549101199186, -0.44850845100484621,
      0.71014796325214258, -0.978839654244631, 1.0516762243259947,
      -1.1005499622518646, 0.9476872721667815, -0.78713899559165368,
      0.46226636417268, -0.18104486940795259, -0.2029282822619019,
      0.48028938128591242, -0.79963465389307931, 0.96170455293341583,
      -1.1264655573416102, 1.1114032763638617, -1.0911924268115589,
      0.90058367606114353, -0.72644798037104419, 0.41628489703167354,
      -0.16272688580387731, -0.18104486940791381, 0.42425671240255897,
      -0.71494450596141834, 0.87053773084436881, -1.044982236772624,
      1.067485427806127, -1.0994775174817255, 0.98241717148205654,
      -0.88385633051386026, 0.65549362427383506, -0.46763214145612336,
      0.17885167570715482, 0.041956057160997977, -0.33282823196413053,
      0.53014010227478847, -0.77123845751936748, 0.900583676061105,
      -1.0562009211726315, 1.0921329352672788, -1.1470392732835761,
      1.0848263999603647, -1.043566951262493, 0.89645476067551433,
      -0.7789855553082875, 0.57266515989828348, -0.40809141340730604,
      0.17414013125580974, 0.0057790920406669893, -0.23600263496593082,
      0.40233828176368353, -0.60236678564674806, 0.73279130957204563,
      -0.88385633051375534, 0.96451613074784437, -1.0565173551777198,
      1.0822089312859517, -1.1131826430383132, 1.0862647483342442,
      -1.0608400621510781, 0.98939364219839421, -0.91674219365629073,
      0.81245562260184645, -0.70416612474562235, 0.5803203946647818,
      -0.4485084510048733, 0.3183072433444295, -0.17414013125584524,
      0.049504513113204779, 0.097794427170353443, -0.20694852169694425,
      0.35063752647124863, -0.43669091671703664, 0.57266515989826938,
      -0.63024686877126246, 0.75691229926905768, -0.78261451757175338,
      0.90058367606117207, -0.89253844875427657, 1.0042398652640634,
      -0.96163929827709771, 1.0709125061321543, -0.99353326210536463,
      1.1052596819817173, -0.99303147659544211, 1.1128310880299426,
      -0.96547066977970464, 1.099477517481765, -0.91619559758816849,
      1.0709125061321494, -0.85019160924341153, 1.0324158470620581,
      -0.77185170463491137, 0.98865807946886086, -0.68485526678123065,
      0.94362036533642957, -0.59213356787173832, 0.90058367606119949,
      -0.49589848948525234, 0.86216336359333123, -0.39771423727654331,
      0.83036873581429727, -0.29859605888326551, 0.80667128674759514,
      -0.1991243035772445, 0.79206916577188613, -0.09956608244825739,
      0.78713899559150691, -3.1039788463383945E-14, -0.79206916577179853,
      -0.099558221129019631, -0.80667128674757416, -0.199029976434944,
      -0.83036873581433812, -0.29814815482820867, -0.86216336359329238,
      -0.39633240703691208, -0.90058367606120915, -0.49256748542344564,
      -0.94362036533644833, -0.58528918433298671, -0.988658079468853,
      -0.67228562218670107, -1.0324158470621341, -0.75062552679518524,
      -1.070912506132176, -0.81662951513986826, -1.0994775174818185,
      -0.86590458733144637, -1.1128310880300063, -0.89346539414713155,
      -1.1052596819817768, -0.89396717965713091, -1.07091250613218,
      -0.862073215828809, -1.0042398652640905, -0.792972366306026,
      -0.90058367606119671, -0.68304843512349755, -0.75691229926900538,
      -0.53068078632299254, -0.572665159898251, -0.33712483426885709,
      -0.35063752647129953, -0.10738243924876077, -0.097794427170440526,
      0.14907059556139185, 0.17414013125574296, 0.41787332579267622,
      0.44850845100480774, 0.67988647711311612, 0.70416612474554019,
      0.91202170505005653, 0.91674219365618881, 1.0889597246465339,
      1.06084006215106, 1.1858308307824394, 1.113182643038239, 1.181775013734232,
      1.0565173551776854, 1.0640822131962138, 0.88385633051375456,
      0.83235739202037917, 0.602366785646747, 0.50190436421199025,
      0.2360026349659142, 0.10534517448894345, -0.17414013125576,
      -0.30852533095897972, -0.57266515989834033, -0.67941947285993509,
      -0.89645476067552332, -0.94400086881416534, -1.0848263999604337,
      -1.0474731908353474, -1.0921329352673788, -0.95663483872443311,
      -0.90058367606118994, -0.67167237507121658, -0.53014010227481734,
      -0.23326214951602803, -0.041956057161113669, 0.27841775815538383,
      0.46763214145607279, 0.7550597067221122, 0.88385633051376644,
      1.0819832539303267, 1.0994775174817641, 1.1670515102545056,
      1.0449822367726336, 0.97010381329261786, 0.71494450596147829,
      0.52382279485083716, 0.18104486940785111, -0.063160803355607226,
      -0.41628489703172117, -0.62688189792282079, -0.90058367606115841,
      -0.99162634436331765, -1.1114032763638553, -1.0268994748932465,
      -0.96170455293338786, -0.70006857144483525, -0.48028938128597032,
      -0.10336219981369807, 0.18104486940783929, 0.56183244662091769,
      0.78713899559149925, 1.0472533546149334, 1.1005499622517076,
      1.1512423067742164, 0.97883965424457464, 0.80971404570034322,
      0.44850845100491915, 0.14293363154948094, -0.28360634978494026,
      -0.573512825720476, -0.90058367606118239, -1.0160368362194176,
      -1.1105249265591985, -0.96203304614598828, -0.79206916577188591,
      -0.41297692139183562, -0.076876421953090759, 0.37855257978765133,
      0.68779059712648927, 1.0118021936905899, 1.0994775174817271,
      1.1385973362928434, 0.91674219365615928, 0.66509529126539557,
      0.21545590840352008, -0.16482553266264685, -0.61990427060588082,
      -0.877218007935075, -1.0947541325800203, -1.0338751431665669,
      -0.90058367606115086, -0.51313940402419422, -0.13257689145275281,
      0.37756113300067812, 0.73089986697034071, 1.062748492709306,
      1.1131606697659109, 1.0670082300582451, 0.73089986697032,
      0.36053738172396815, -0.17414013125581868, -0.57557620919245933,
      -0.96170455293338131, -1.0581157057526021, -1.0375653844658896,
      -0.704202310769646, -0.31727849591320778, 0.24102641826834106,
      0.65995792201007331, 1.0439436110353717, 1.113182643038223,
      1.042296471336813, 0.64864092823065467, 0.2097618716600676,
      -0.37048894022694034, -0.76630651430202112, -1.0764492719693646,
      -1.0317545128152819, -0.8303687358142835, -0.32440221176884043,
      0.17414013125575051, 0.73464156977480222, 1.0243861200587372,
      1.1575900573151359, 0.904677037945415, 0.516942489354255,
      -0.097794427170432047, -0.58779649993941308, -1.0101959102267071,
      -1.057256315719042, -0.90058367606119372, -0.38970893656456951,
      0.14645516098391195, 0.74539312347092967, 1.0449822367725952,
      1.1425095267048517, 0.81624712432993185, 0.34611000477088011,
      -0.31727849591325258, -0.785511224118576, -1.0994775174818148,
      -0.97030691072970643, -0.61990427060584263, 0.03136485851439115,
      0.59055584230797031, 1.061501121104552, 1.1005499622517636,
      0.8750668981697719, 0.27005725293586752, -0.32819956824758761,
      -0.90058367606119094, -1.062187811896939, -0.9361249127714184,
      -0.37713472043399721, 0.23600263496592072, 0.86789045328076386,
      1.1035064488179791, 1.0350443887434257, 0.49913241358112387,
      -0.12545188328629048, -0.78713899559154465, -1.0493535810406287,
      -0.98865807946888118, -0.4409244351670995, 0.20171511088821911,
      0.867795419878519, 1.1075622027767462, 1.0004001702955081,
      0.40327865021575354, -0.26191958489817097, -0.90058367606125378,
      -1.0622654480358003, -0.85324671119037265, -0.17715471677623856,
      0.49913241358111748, 1.0612112666509228, 1.0799280887625529,
      0.72004293034692268, -0.041956057161106813, -0.68721702625479386,
      -1.0994775174817739, -0.90703021660775, -0.37048894022689244,
      0.44207491484478423, 0.97210060751136274, 1.1420100837675093,
      0.68779059712656032, -0.00048613360356950717, -0.76710953057475761,
      -1.05821153381544, -0.90058367606120127, -0.19094345209430327,
      0.54239838277567087, 1.102770611696009, 1.0243861200587328,
      0.51620707079975947, -0.33733360238362448, -0.915925517313903,
      -1.0848263999603851, -0.57411153602528864, 0.17414013125578462,
      0.93079119019065681, 1.1075622027768637, 0.77440782176545109,
      -0.06291545159537329, -0.76731892696090587, -1.1128310880299328,
      -0.72582501700577828, 0.0069942868061813272, 0.83847412921525954,
      1.1131826430382996, 0.8359934053278526, -0.0069942868062066186,
      -0.74810368080439416, -1.1128310880299357, -0.70555238670464937,
      0.062915451595298391, 0.89540372840744953, 1.107562202776782,
      0.73095772153332161, -0.17414013125579927, -0.871617469048519,
      -1.084826399960352, -0.50300473758390862, 0.33733360238364885,
      1.0609723174488073, 1.0243861200587214, 0.41227004714260262,
      -0.54239838277562513, -1.0367227514959372, -0.90058367606124534,
      -0.052993654615967063, 0.76710953057473474, 1.1620473527709339,
      0.68779059712643453, -0.1671571689178315, -0.97210060751143468,
      -0.9919282024760937, -0.37048894022685169, 0.61816390655964781,
      1.0994775174818265, 0.88385164224250656, -0.041956057161132945,
      -0.83915060560540033, -1.0799280887625486, -0.41605604161374909,
      0.49913241358110771, 1.1396819582434572, 0.85324671119031548,
      0.013265936884809421, -0.90058367606123169, -1.0185179930915758,
      -0.40327865021585318, 0.63011551794657594, 1.1075622027768348,
      0.80559583429329928, -0.20171511088826702, -0.94893566149056208,
      -0.98865807946889916, -0.12245429364661815, 0.787138995591591,
      1.149157313222946, 0.49913241358110622, -0.4693944579204723,
      -1.1035064488179676, -0.705681985939306, 0.23600263496588794,
      1.0777198621220794, 0.93612491277137944, 0.083158263421865983,
      -0.90058367606117051, -0.99684184921161434, -0.27005725293578686,
      0.79782496280776927, 1.1005499622517758, 0.51597483249833442,
      -0.59055584230796121, -1.0630895831005, -0.6199042706059209,
      0.49362613880418543, 1.0994775174817435, 0.78476908378198318,
      -0.31727849591312129, -1.02334808870175, -0.81624712432994473,
      0.26708601308423474, 1.0449822367726738, 0.91976581146556136,
      -0.14645516098394734, -0.97241247242385476, -0.90058367606120127,
      0.15640694945650757, 1.0101959102268083, 0.96165824264854949,
      -0.0977944271704315, -0.96102796215273711, -0.90467703794539123,
      0.17031486796969636, 1.0243861200587812, 0.928410260761253,
      -0.17414013125587893, -0.99806938026100089, -0.83036873581430082,
      0.30805812866429094, 1.0764492719693548, 0.80551825935548049,
      -0.37048894022688983, -1.0519426558038438, -0.64864092823064834,
      0.55681623230319943, 1.113182643038273, 0.55369803406431839,
      -0.65995792201019587, -1.0470257292348173, -0.3172784959131415,
      0.86731310934796124, 1.0375653844658994, 0.13895835022347655,
      -0.961704552933377, -0.86983382809091581, 0.17414013125578856,
      1.1193407125814494, 0.73089986697039622, -0.4066264431284235,
      -1.1131606697659766, -0.41617670779539623, 0.73089986697034781,
      1.1143511920630564, 0.13257689145274762, -0.90918770175663532,
      -0.90058367606115175, 0.29440192118680625, 1.09475413258007,
      0.6624840856869858, -0.61990427060586151, -1.041934219557676,
      -0.21545590840344206, 0.97930229053485351, 0.91674219365620846,
      -0.19468393837034637, -1.09947751748174, -0.51529645913706867,
      0.68779059712655666, 1.1143372239309484, 0.076876421953043672,
      -0.961078646991225, -0.79206916577188, 0.50634539292523184,
      1.1105249265592385, 0.35873593558471556, -0.90058367606117673,
      -0.8698618815314515, 0.28360634978504584, 1.1594568664001814,
      0.4485084510049257, -0.76759221163457825, -0.97883965424454555,
      0.23950709672028364, 1.1005499622517665, 0.55365565877669987,
      -0.78713899559153067, -0.941219428194541, 0.18104486940788436,
      1.1516665106474548, 0.480289381285917, -0.76759936669373019,
      -0.96170455293334178, 0.30800107118560793, 1.1114032763638377,
      0.4252644810250345, -0.90058367606116418, -0.82868239623193374,
      0.41628489703176247, 1.15648092500067, 0.18104486940789014,
      -0.96110019281938075, -0.71494450596142589, 0.68848221471642634,
      1.0449822367726123, -0.05667396312341217, -1.0994775174818192,
      -0.39066760720714849, 0.88385633051376777, 0.91967777648186477,
      -0.46763214145618681, -1.041970400137644, -0.041956057161168632,
      1.1230873863551061, 0.53014010227477537, -0.78634561192628027,
      -0.90058367606122491, 0.49352151580543818, 1.0921329352673346,
      0.06905143706392991, -1.084826399960418, -0.41622793662742752,
      0.89645476067546359, 0.874335964878923, -0.57266515989830469,
      -0.99696401231879006, 0.17414013125584074, 1.1625003022123064,
      0.23600263496602075, -0.97796396100010785, -0.60236678564671853,
      0.86724623863240069, 0.88385633051381651, -0.46953530141381661,
      -1.0565173551777216, 0.2256759456211217, 1.1131826430382623,
      0.22222075347331416, -1.0608400621510443, -0.44149550234104867,
      0.91674219365620813, 0.80543495746473737, -0.70416612474558082,
      -0.90025200294011765, 0.44850845100491171, 1.1182967422322312,
      -0.17414013125579703, -1.0627744668649539, -0.097794427170504655,
      1.1394994523243251, 0.35063752647123386, -0.96112870133648287,
      -0.57266515989832256, 0.93894358815889056, 0.75691229926897219,
      -0.68767314696820259, -0.90058367606118273, 0.61795789598781226,
      1.0042398652641042, -0.34204943970171048, -1.070912506132099,
      0.26696658584201616, 1.1052596819817615, -0.00089695687929560635,
      -1.11283108802993, -0.053225370639160233, 1.0994775174817881,
      0.29091892009172815, -1.0709125061321287, -0.31244168580386406,
      1.0324158470621405, 0.51583518592017741, -0.98865807946887663,
      -0.5032647409706057, 0.9436203653364581, 0.67404292389210352,
      -0.90058367606118206, -0.63110753323614521, 0.86216336359327261,
      0.77406951822474135, -0.830368735814326, -0.70584370941906538,
      0.8066712867475675, 0.82571730891546857, -0.79206916577189324,
      -0.73611805742132941, 0.787138995591505, 0.835684139869652,
      -0.79206916577188258, -0.72615122646721919, 0.80667128674760213,
      0.80540979186736772, -0.83036873581429993, -0.67450343577649619,
      0.86216336359328061, 0.73067361568439848, -0.90058367606120437,
      -0.57447684144385669, 0.94362036533643168, 0.602830823418847,
      -0.98865807946895623, -0.41626910347183521, 1.0324158470620488,
      0.41200776825211566, -1.0709125061321685, -0.1913528376434574,
      1.0994775174817646, 0.1527914530873892, -1.1128310880299432,
      0.10046303932751256, 1.1052596819818012, -0.16740050339383789,
      -1.0709125061320968, 0.44161552214984745, 1.004239865264124,
      -0.51839181353959, -0.90058367606119094, 0.787239229416538,
      0.75691229926897419, -0.83937750571054937, -0.57266515989828026,
      1.0606947837848182, 0.3506375264713017, -1.0399333698760034,
      -0.09779442717035676, 1.1623405493132177, -0.17414013125578195,
      -1.0187306597839993, 0.44850845100495434, 0.99981808538827943,
      -0.70416612474558271, -0.70586887501649676, 0.91674219365618093,
      0.54106158478929633, -1.0608400621510063, -0.12265467102501838,
      1.1131826430382883, -0.12610986317291323, -1.0565173551776512,
      0.569101383861981, 0.88385633051385326, -0.76768015618418239,
      -0.60236678564671731, 1.0775300434482356, 0.23600263496592172,
      -1.0629342197641156, 0.17414013125574584, 1.0965300947670786,
      -0.572665159898306, -0.77476988243067368, 0.89645476067551366,
      0.51579401907570588, -1.0848263999603986, 0.030514645384352088,
      1.0921329352673732, -0.39395543335718292, -0.90058367606115086,
      0.88591169437460371, 0.53014010227486741, -1.023521303906771,
      -0.041956057161117596, 1.1415364825859888, -0.46763214145610732,
      -0.82011169403357609, 0.88385633051380874, 0.49023368965549646,
      -1.0994775174818467, 0.15624004557177415, 1.0449822367726149,
      -0.58891613226815, -0.71494450596146164, 1.0606662752676428,
      0.18104486940787837, -1.0569148425524812, 0.41628489703175015,
      0.928248478680137, -0.90058367606119516, -0.32569839857676597,
      1.1114032763637527, -0.208434988737293, -0.96170455293342283,
      0.86716544914202121, 0.48028938128591503, -1.0521004281991186,
      0.18104486940788744, 1.04078551064284, -0.78713899559155853,
      -0.45408957632847319, 1.1005499622517849, -0.13994101427203981,
      -0.97883965424462316, 0.86715829408280642, 0.44850845100484449,
      -1.0598907839519369, 0.28360634978499205, 0.96942796397966069,
      -0.90058367606115208, -0.25916985313652158, 1.1105249265592958,
      -0.40677931047699872, -0.79206916577188158, 1.0606447294395633,
      0.076876421952973853, -1.0147711414826619, 0.687790597126496,
      0.614862541585278, -1.0994775174818019, 0.29425002081861779,
      0.9167421936561444, -0.8797362080866542, -0.21545590840342521,
      1.1415003020058307, -0.61990427060592324, -0.56291800323869612,
      1.0947541325799848, -0.19483583873860533, -0.90058367606119483,
      1.0087537842049383, 0.13257689145270277, -1.014785109614774,
      0.73089986697041176, 0.51574279024362624, -1.1131606697659659,
      0.5061925255767965, 0.730899866970255, -1.0197746301332034,
      0.17414013125579708, 0.969399910539121, -0.96170455293334445,
      -0.039392267775240346, 1.0375653844658239, -0.76774702689971852,
      -0.31727849591313023, 1.1465918116831018, -0.65995792201020154,
      -0.45413195161600406, 1.1131826430382779, -0.45725014985498569,
      -0.64864092823069863, 1.151508738252125, -0.37048894022701123,
      -0.70595217690715084, 1.0764492719693075, -0.2084920462160309,
      -0.83036873581429294, 1.0976354627093357, -0.17414013125578096,
      -0.82884417831294566, 1.0243861200587783, -0.0707487855215978,
      -0.904677037945323, 1.0605940446009974, -0.097794427170477566,
      -0.86209216020028734, 1.0101959102267288, -0.056840867008300412,
      -0.900583676061146, 1.0719785548721428, -0.14645516098405814,
      -0.82019972901730953, 1.0449822367726793, -0.16751993063601103,
      -0.81624712432999957, 1.1229141711500397, -0.31727849591323032,
      -0.6852030013336855, 1.0994775174818154, -0.39406005635592345,
      -0.61990427060588171, 1.1626556655488118, -0.59055584230794944,
      -0.41640875005008615, 1.1005499622517476, -0.69825888035956629,
      -0.27005725293589145, 1.0964079316598445, -0.9005836760612147,
      0.016407819026412557, 0.93612491277138921, -0.97815377967386663,
      0.23600263496609913, 0.80524806838747365, -1.1035064488179087,
      0.568960540368687, 0.49913241358114657, -1.0495912307747453,
      0.7871389955915713, 0.22202037609476824, -0.98865807946882667,
      1.0485017439388227, -0.20171511088821237, -0.70602975184502581,
      1.1075622027768739, -0.5305494354982867, -0.40327865021581538,
      1.1180840755398607, -0.90058367606121681, 0.0863001455635846,
      0.85324671119028817, -1.0401158757951092, 0.49913241358111987,
      0.51562212406197194, -1.0799280887625922, 0.93871668805368691,
      -0.041956057161151208, -0.7842855597942624, 1.09947751748185,
      -0.51859782411156941, -0.37048894022677237, 1.091494284924307,
      -0.97210060751140293, 0.26672325136617919, 0.68779059712645552,
      -1.0624812703225963, 0.7671095305748169, 0.15255973706428777,
      -0.90058367606118583, 1.136288833944231, -0.54239838277570773,
      -0.31270396469431472, 1.0243861200587141, -0.96140623500056421,
      0.33733360238367671, 0.60257082003210183, -1.0848263999603882,
      0.97118355149678948, -0.17414013125579869, -0.63139163908494322,
      1.10756220277683, -0.79583764595912865, 0.062915451595380451,
      0.80511846915289342, -1.1128310880299601, 0.84766976325269228,
      -0.0069942868062422567, -0.73642732287951629, 1.1131826430382759,
      -0.73890804676709543, 0.0069942868062505921, 0.82539109945397671,
      -1.1128310880299161, 0.866885009409127, -0.062915451595349642,
      -0.67484173931718516, 1.10756220277689, -0.83122510774246217,
      0.174140131255825, 0.67367761847350538, -1.0848263999603949,
      1.0154915997621936, -0.3373336023836826, -0.41664098835143409,
      1.0243861200586939, -1.0032045292477765, 0.54239838277572,
      0.29050953454248207, -0.90058367606113288, 1.1577776162637,
      -0.76710953057481091, 0.10005221605177451, 0.68779059712648383,
      -1.0424440013192717, 0.97210060751142557, -0.34250883239651669,
      -0.37048894022686624, 1.0065962990559865, -1.0994775174817919,
      0.78678310870306623, -0.041956057161161291, -0.62047684789861579,
      1.0799280887625751, -0.96164518420267442, 0.49913241358117594,
      0.27672079922437415, -0.85324671119032791, 1.1618315304841049,
      -0.90058367606124134, 0.36148566734659382, 0.4032786502157345,
      -0.900834087847126, 1.1075622027768721, -0.76822933743021316,
      0.201715110888302, 0.54049051761524192, -0.98865807946883977,
      1.1489196634889096, -0.78713899559153655, 0.22501796573454,
      0.49913241358107874, -0.935478306295136, 1.1035064488179227,
      -0.76832437083250515, 0.23600263496598609, 0.47670080288220207,
      -0.93612491277131793, 1.1617538943451686, -0.90058367606110989,
      0.42776565069574751, 0.27005725293594879, -0.77550081572152152,
      1.1005499622517416, -0.96193503865630725, 0.59055584230795177,
      0.068201223933793673, -0.61990427060587838, 1.0698729931779549,
      -1.0994775174817757, 0.88507730656688111, -0.31727849591312979,
      -0.24654392232255859, 0.81624712433004665, -1.0429434442566916,
      1.0449822367728232, -0.64582704102273325, 0.14645516098403655,
      0.4892750190129076, -0.90058367606123035, 1.1568223981672847,
      -1.010195910226795, 0.6873625823877344, -0.097794427170464951,
      -0.41737640690599109, 0.90467703794540533, -1.0580239748668963,
      1.0243861200587916, -0.635075487326638, 0.17414013125587485,
      0.423968294217014, -0.83036873581426252, 1.1313205952635854,
      -1.0764492719693439, 0.8658725967503168, -0.37048894022693052,
      -0.11019578921170421, 0.64864092823068187, -0.94273038888853888,
      1.1131826430383056, -0.94437752858705493, 0.65995792201019887,
      -0.14146033582010123, -0.31727849591301732, 0.80376839321782123,
      -1.037565384465756, 1.1576817882008428, -0.96170455293338675,
      0.67514229164074835, -0.174140131255795, -0.26097129927557683,
      0.73089986697026554, -0.96744214760989689, 1.1131606697658929,
      -0.96318241026096341, 0.73089986697031528, -0.27799505055241314,
      -0.13257689145273355, 0.61270548647237022, -0.90058367606107526,
      1.1334412256147091, -1.0947541325799492, 0.976784090383278,
      -0.61990427060589282, 0.26439161511097681, 0.21545590840340648,
      -0.56552920881704, 0.9167421936561132, -1.0390312538445445,
      1.0994775174818272, -0.91223611124233317, 0.687790597126564,
      -0.27898649733943953, -0.076876421952962, 0.51254300384003826,
      -0.79206916577180186, 1.0615991285942203, -1.110524926559231,
      1.1156029186677157, -0.90058367606126721, 0.67307890816878135,
      -0.28360634978510979, -0.043367549101199186, 0.44850845100484621,
      -0.71014796325214258, 0.978839654244631, -1.0516762243259947,
      1.1005499622518646, -0.9476872721667815, 0.78713899559165368,
      -0.46226636417268, 0.18104486940795259, 0.2029282822619019,
      -0.48028938128591242, 0.79963465389307931, -0.96170455293341583,
      1.1264655573416102, -1.1114032763638617, 1.0911924268115589,
      -0.90058367606114353, 0.72644798037104419, -0.41628489703167354,
      0.16272688580387731, 0.18104486940791381, -0.42425671240255897,
      0.71494450596141834, -0.87053773084436881, 1.044982236772624,
      -1.067485427806127, 1.0994775174817255, -0.98241717148205654,
      0.88385633051386026, -0.65549362427383506, 0.46763214145612336,
      -0.17885167570715482, -0.041956057160997977, 0.33282823196413053,
      -0.53014010227478847, 0.77123845751936748, -0.900583676061105,
      1.0562009211726315, -1.0921329352672788, 1.1470392732835761,
      -1.0848263999603647, 1.043566951262493, -0.89645476067551433,
      0.7789855553082875, -0.57266515989828348, 0.40809141340730604,
      -0.17414013125580974, -0.0057790920406669893, 0.23600263496593082,
      -0.40233828176368353, 0.60236678564674806, -0.73279130957204563,
      0.88385633051375534, -0.96451613074784437, 1.0565173551777198,
      -1.0822089312859517, 1.1131826430383132, -1.0862647483342442,
      1.0608400621510781, -0.98939364219839421, 0.91674219365629073,
      -0.81245562260184645, 0.70416612474562235, -0.5803203946647818,
      0.4485084510048733, -0.3183072433444295, 0.17414013125584524,
      -0.049504513113204779, -0.097794427170353443, 0.20694852169694425,
      -0.35063752647124863, 0.43669091671703664, -0.57266515989826938,
      0.63024686877126246, -0.75691229926905768, 0.78261451757175338,
      -0.90058367606117207, 0.89253844875427657, -1.0042398652640634,
      0.96163929827709771, -1.0709125061321543, 0.99353326210536463,
      -1.1052596819817173, 0.99303147659544211, -1.1128310880299426,
      0.96547066977970464, -1.099477517481765, 0.91619559758816849,
      -1.0709125061321494, 0.85019160924341153, -1.0324158470620581,
      0.77185170463491137, -0.98865807946886086, 0.68485526678123065,
      -0.94362036533642957, 0.59213356787173832, -0.90058367606119949,
      0.49589848948525234, -0.86216336359333123, 0.39771423727654331,
      -0.83036873581429727, 0.29859605888326551, -0.80667128674759514,
      0.1991243035772445, -0.79206916577188613, 0.09956608244825739,
      -0.78713899559150691, 3.1039788463383945E-14, 0.79206916577179853,
      0.099558221129019631, 0.80667128674757416, 0.199029976434944,
      0.83036873581433812, 0.29814815482820867, 0.86216336359329238,
      0.39633240703691208, 0.90058367606120915, 0.49256748542344564,
      0.94362036533644833, 0.58528918433298671, 0.988658079468853,
      0.67228562218670107, 1.0324158470621341, 0.75062552679518524,
      1.070912506132176, 0.81662951513986826, 1.0994775174818185,
      0.86590458733144637, 1.1128310880300063, 0.89346539414713155,
      1.1052596819817768, 0.89396717965713091, 1.07091250613218,
      0.862073215828809, 1.0042398652640905, 0.792972366306026,
      0.90058367606119671, 0.68304843512349755, 0.75691229926900538,
      0.53068078632299254, 0.572665159898251, 0.33712483426885709,
      0.35063752647129953, 0.10738243924876077, 0.097794427170440526,
      -0.14907059556139185, -0.17414013125574296, -0.41787332579267622,
      -0.44850845100480774, -0.67988647711311612, -0.70416612474554019,
      -0.91202170505005653, -0.91674219365618881, -1.0889597246465339,
      -1.06084006215106, -1.1858308307824394, -1.113182643038239,
      -1.181775013734232, -1.0565173551776854, -1.0640822131962138,
      -0.88385633051375456, -0.83235739202037917, -0.602366785646747,
      -0.50190436421199025, -0.2360026349659142, -0.10534517448894345,
      0.17414013125576, 0.30852533095897972, 0.57266515989834033,
      0.67941947285993509, 0.89645476067552332, 0.94400086881416534,
      1.0848263999604337, 1.0474731908353474, 1.0921329352673788,
      0.95663483872443311, 0.90058367606118994, 0.67167237507121658,
      0.53014010227481734, 0.23326214951602803, 0.041956057161113669,
      -0.27841775815538383, -0.46763214145607279, -0.7550597067221122,
      -0.88385633051376644, -1.0819832539303267, -1.0994775174817641,
      -1.1670515102545056, -1.0449822367726336, -0.97010381329261786,
      -0.71494450596147829, -0.52382279485083716, -0.18104486940785111,
      0.063160803355607226, 0.41628489703172117, 0.62688189792282079,
      0.90058367606115841, 0.99162634436331765, 1.1114032763638553,
      1.0268994748932465, 0.96170455293338786, 0.70006857144483525,
      0.48028938128597032, 0.10336219981369807, -0.18104486940783929,
      -0.56183244662091769, -0.78713899559149925, -1.0472533546149334,
      -1.1005499622517076, -1.1512423067742164, -0.97883965424457464,
      -0.80971404570034322, -0.44850845100491915, -0.14293363154948094,
      0.28360634978494026, 0.573512825720476, 0.90058367606118239,
      1.0160368362194176, 1.1105249265591985, 0.96203304614598828,
      0.79206916577188591, 0.41297692139183562, 0.076876421953090759,
      -0.37855257978765133, -0.68779059712648927, -1.0118021936905899,
      -1.0994775174817271, -1.1385973362928434, -0.91674219365615928,
      -0.66509529126539557, -0.21545590840352008, 0.16482553266264685,
      0.61990427060588082, 0.877218007935075, 1.0947541325800203,
      1.0338751431665669, 0.90058367606115086, 0.51313940402419422,
      0.13257689145275281, -0.37756113300067812, -0.73089986697034071,
      -1.062748492709306, -1.1131606697659109, -1.0670082300582451,
      -0.73089986697032, -0.36053738172396815, 0.17414013125581868,
      0.57557620919245933, 0.96170455293338131, 1.0581157057526021,
      1.0375653844658896, 0.704202310769646, 0.31727849591320778,
      -0.24102641826834106, -0.65995792201007331, -1.0439436110353717,
      -1.113182643038223, -1.042296471336813, -0.64864092823065467,
      -0.2097618716600676, 0.37048894022694034, 0.76630651430202112,
      1.0764492719693646, 1.0317545128152819, 0.8303687358142835,
      0.32440221176884043, -0.17414013125575051, -0.73464156977480222,
      -1.0243861200587372, -1.1575900573151359, -0.904677037945415,
      -0.516942489354255, 0.097794427170432047, 0.58779649993941308,
      1.0101959102267071, 1.057256315719042, 0.90058367606119372,
      0.38970893656456951, -0.14645516098391195, -0.74539312347092967,
      -1.0449822367725952, -1.1425095267048517, -0.81624712432993185,
      -0.34611000477088011, 0.31727849591325258, 0.785511224118576,
      1.0994775174818148, 0.97030691072970643, 0.61990427060584263,
      -0.03136485851439115, -0.59055584230797031, -1.061501121104552,
      -1.1005499622517636, -0.8750668981697719, -0.27005725293586752,
      0.32819956824758761, 0.90058367606119094, 1.062187811896939,
      0.9361249127714184, 0.37713472043399721, -0.23600263496592072,
      -0.86789045328076386, -1.1035064488179791, -1.0350443887434257,
      -0.49913241358112387, 0.12545188328629048, 0.78713899559154465,
      1.0493535810406287, 0.98865807946888118, 0.4409244351670995,
      -0.20171511088821911, -0.867795419878519, -1.1075622027767462,
      -1.0004001702955081, -0.40327865021575354, 0.26191958489817097,
      0.90058367606125378, 1.0622654480358003, 0.85324671119037265,
      0.17715471677623856, -0.49913241358111748, -1.0612112666509228,
      -1.0799280887625529, -0.72004293034692268, 0.041956057161106813,
      0.68721702625479386, 1.0994775174817739, 0.90703021660775,
      0.37048894022689244, -0.44207491484478423, -0.97210060751136274,
      -1.1420100837675093, -0.68779059712656032, 0.00048613360356950717,
      0.76710953057475761, 1.05821153381544, 0.90058367606120127,
      0.19094345209430327, -0.54239838277567087, -1.102770611696009,
      -1.0243861200587328, -0.51620707079975947, 0.33733360238362448,
      0.915925517313903, 1.0848263999603851, 0.57411153602528864,
      -0.17414013125578462, -0.93079119019065681, -1.1075622027768637,
      -0.77440782176545109, 0.06291545159537329, 0.76731892696090587,
      1.1128310880299328, 0.72582501700577828, -0.0069942868061813272,
      -0.83847412921525954, -1.1131826430382996, -0.8359934053278526,
      0.0069942868062066186, 0.74810368080439416, 1.1128310880299357,
      0.70555238670464937, -0.062915451595298391, -0.89540372840744953,
      -1.107562202776782, -0.73095772153332161, 0.17414013125579927,
      0.871617469048519, 1.084826399960352, 0.50300473758390862,
      -0.33733360238364885, -1.0609723174488073, -1.0243861200587214,
      -0.41227004714260262, 0.54239838277562513, 1.0367227514959372,
      0.90058367606124534, 0.052993654615967063, -0.76710953057473474,
      -1.1620473527709339, -0.68779059712643453, 0.1671571689178315,
      0.97210060751143468, 0.9919282024760937, 0.37048894022685169,
      -0.61816390655964781, -1.0994775174818265, -0.88385164224250656,
      0.041956057161132945, 0.83915060560540033, 1.0799280887625486,
      0.41605604161374909, -0.49913241358110771, -1.1396819582434572,
      -0.85324671119031548, -0.013265936884809421, 0.90058367606123169,
      1.0185179930915758, 0.40327865021585318, -0.63011551794657594,
      -1.1075622027768348, -0.80559583429329928, 0.20171511088826702,
      0.94893566149056208, 0.98865807946889916, 0.12245429364661815,
      -0.787138995591591, -1.149157313222946, -0.49913241358110622,
      0.4693944579204723, 1.1035064488179676, 0.705681985939306,
      -0.23600263496588794, -1.0777198621220794, -0.93612491277137944,
      -0.083158263421865983, 0.90058367606117051, 0.99684184921161434,
      0.27005725293578686, -0.79782496280776927, -1.1005499622517758,
      -0.51597483249833442, 0.59055584230796121, 1.0630895831005,
      0.6199042706059209, -0.49362613880418543, -1.0994775174817435,
      -0.78476908378198318, 0.31727849591312129, 1.02334808870175,
      0.81624712432994473, -0.26708601308423474, -1.0449822367726738,
      -0.91976581146556136, 0.14645516098394734, 0.97241247242385476,
      0.90058367606120127, -0.15640694945650757, -1.0101959102268083,
      -0.96165824264854949, 0.0977944271704315, 0.96102796215273711,
      0.90467703794539123, -0.17031486796969636, -1.0243861200587812,
      -0.928410260761253, 0.17414013125587893, 0.99806938026100089,
      0.83036873581430082, -0.30805812866429094, -1.0764492719693548,
      -0.80551825935548049, 0.37048894022688983, 1.0519426558038438,
      0.64864092823064834, -0.55681623230319943, -1.113182643038273,
      -0.55369803406431839, 0.65995792201019587, 1.0470257292348173,
      0.3172784959131415, -0.86731310934796124, -1.0375653844658994,
      -0.13895835022347655, 0.961704552933377, 0.86983382809091581,
      -0.17414013125578856, -1.1193407125814494, -0.73089986697039622,
      0.4066264431284235, 1.1131606697659766, 0.41617670779539623,
      -0.73089986697034781, -1.1143511920630564, -0.13257689145274762,
      0.90918770175663532, 0.90058367606115175, -0.29440192118680625,
      -1.09475413258007, -0.6624840856869858, 0.61990427060586151,
      1.041934219557676, 0.21545590840344206, -0.97930229053485351,
      -0.91674219365620846, 0.19468393837034637, 1.09947751748174,
      0.51529645913706867, -0.68779059712655666, -1.1143372239309484,
      -0.076876421953043672, 0.961078646991225, 0.79206916577188,
      -0.50634539292523184, -1.1105249265592385, -0.35873593558471556,
      0.90058367606117673, 0.8698618815314515, -0.28360634978504584,
      -1.1594568664001814, -0.4485084510049257, 0.76759221163457825,
      0.97883965424454555, -0.23950709672028364, -1.1005499622517665,
      -0.55365565877669987, 0.78713899559153067, 0.941219428194541,
      -0.18104486940788436, -1.1516665106474548, -0.480289381285917,
      0.76759936669373019, 0.96170455293334178, -0.30800107118560793,
      -1.1114032763638377, -0.4252644810250345, 0.90058367606116418,
      0.82868239623193374, -0.41628489703176247, -1.15648092500067,
      -0.18104486940789014, 0.96110019281938075, 0.71494450596142589,
      -0.68848221471642634, -1.0449822367726123, 0.05667396312341217,
      1.0994775174818192, 0.39066760720714849, -0.88385633051376777,
      -0.91967777648186477, 0.46763214145618681, 1.041970400137644,
      0.041956057161168632, -1.1230873863551061, -0.53014010227477537,
      0.78634561192628027, 0.90058367606122491, -0.49352151580543818,
      -1.0921329352673346, -0.06905143706392991, 1.084826399960418,
      0.41622793662742752, -0.89645476067546359, -0.874335964878923,
      0.57266515989830469, 0.99696401231879006, -0.17414013125584074,
      -1.1625003022123064, -0.23600263496602075, 0.97796396100010785,
      0.60236678564671853, -0.86724623863240069, -0.88385633051381651,
      0.46953530141381661, 1.0565173551777216, -0.2256759456211217,
      -1.1131826430382623, -0.22222075347331416, 1.0608400621510443,
      0.44149550234104867, -0.91674219365620813, -0.80543495746473737,
      0.70416612474558082, 0.90025200294011765, -0.44850845100491171,
      -1.1182967422322312, 0.17414013125579703, 1.0627744668649539,
      0.097794427170504655, -1.1394994523243251, -0.35063752647123386,
      0.96112870133648287, 0.57266515989832256, -0.93894358815889056,
      -0.75691229926897219, 0.68767314696820259, 0.90058367606118273,
      -0.61795789598781226, -1.0042398652641042, 0.34204943970171048,
      1.070912506132099, -0.26696658584201616, -1.1052596819817615,
      0.00089695687929560635, 1.11283108802993, 0.053225370639160233,
      -1.0994775174817881, -0.29091892009172815, 1.0709125061321287,
      0.31244168580386406, -1.0324158470621405, -0.51583518592017741,
      0.98865807946887663, 0.5032647409706057, -0.9436203653364581,
      -0.67404292389210352, 0.90058367606118206, 0.63110753323614521,
      -0.86216336359327261, -0.77406951822474135, 0.830368735814326,
      0.70584370941906538, -0.8066712867475675, -0.82571730891546857,
      0.79206916577189324, 0.73611805742132941, -0.787138995591505,
      -0.835684139869652, 0.79206916577188258, 0.72615122646721919,
      -0.80667128674760213, -0.80540979186736772, 0.83036873581429993,
      0.67450343577649619, -0.86216336359328061, -0.73067361568439848,
      0.90058367606120437, 0.57447684144385669, -0.94362036533643168,
      -0.602830823418847, 0.98865807946895623, 0.41626910347183521,
      -1.0324158470620488, -0.41200776825211566, 1.0709125061321685,
      0.1913528376434574, -1.0994775174817646, -0.1527914530873892,
      1.1128310880299432, -0.10046303932751256, -1.1052596819818012,
      0.16740050339383789, 1.0709125061320968, -0.44161552214984745,
      -1.004239865264124, 0.51839181353959, 0.90058367606119094,
      -0.787239229416538, -0.75691229926897419, 0.83937750571054937,
      0.57266515989828026, -1.0606947837848182, -0.3506375264713017,
      1.0399333698760034, 0.09779442717035676, -1.1623405493132177,
      0.17414013125578195, 1.0187306597839993, -0.44850845100495434,
      -0.99981808538827943, 0.70416612474558271, 0.70586887501649676,
      -0.91674219365618093, -0.54106158478929633, 1.0608400621510063,
      0.12265467102501838, -1.1131826430382883, 0.12610986317291323,
      1.0565173551776512, -0.569101383861981, -0.88385633051385326,
      0.76768015618418239, 0.60236678564671731, -1.0775300434482356,
      -0.23600263496592172, 1.0629342197641156, -0.17414013125574584,
      -1.0965300947670786, 0.572665159898306, 0.77476988243067368,
      -0.89645476067551366, -0.51579401907570588, 1.0848263999603986,
      -0.030514645384352088, -1.0921329352673732, 0.39395543335718292,
      0.90058367606115086, -0.88591169437460371, -0.53014010227486741,
      1.023521303906771, 0.041956057161117596, -1.1415364825859888,
      0.46763214145610732, 0.82011169403357609, -0.88385633051380874,
      -0.49023368965549646, 1.0994775174818467, -0.15624004557177415,
      -1.0449822367726149, 0.58891613226815, 0.71494450596146164,
      -1.0606662752676428, -0.18104486940787837, 1.0569148425524812,
      -0.41628489703175015, -0.928248478680137, 0.90058367606119516,
      0.32569839857676597, -1.1114032763637527, 0.208434988737293,
      0.96170455293342283, -0.86716544914202121, -0.48028938128591503,
      1.0521004281991186, -0.18104486940788744, -1.04078551064284,
      0.78713899559155853, 0.45408957632847319, -1.1005499622517849,
      0.13994101427203981, 0.97883965424462316, -0.86715829408280642,
      -0.44850845100484449, 1.0598907839519369, -0.28360634978499205,
      -0.96942796397966069, 0.90058367606115208, 0.25916985313652158,
      -1.1105249265592958, 0.40677931047699872, 0.79206916577188158,
      -1.0606447294395633, -0.076876421952973853, 1.0147711414826619,
      -0.687790597126496, -0.614862541585278, 1.0994775174818019,
      -0.29425002081861779, -0.9167421936561444, 0.8797362080866542,
      0.21545590840342521, -1.1415003020058307, 0.61990427060592324,
      0.56291800323869612, -1.0947541325799848, 0.19483583873860533,
      0.90058367606119483, -1.0087537842049383, -0.13257689145270277,
      1.014785109614774, -0.73089986697041176, -0.51574279024362624,
      1.1131606697659659, -0.5061925255767965, -0.730899866970255,
      1.0197746301332034, -0.17414013125579708, -0.969399910539121,
      0.96170455293334445, 0.039392267775240346, -1.0375653844658239,
      0.76774702689971852, 0.31727849591313023, -1.1465918116831018,
      0.65995792201020154, 0.45413195161600406, -1.1131826430382779,
      0.45725014985498569, 0.64864092823069863, -1.151508738252125,
      0.37048894022701123, 0.70595217690715084, -1.0764492719693075,
      0.2084920462160309, 0.83036873581429294, -1.0976354627093357,
      0.17414013125578096, 0.82884417831294566, -1.0243861200587783,
      0.0707487855215978, 0.904677037945323, -1.0605940446009974,
      0.097794427170477566, 0.86209216020028734, -1.0101959102267288,
      0.056840867008300412, 0.900583676061146, -1.0719785548721428,
      0.14645516098405814, 0.82019972901730953, -1.0449822367726793,
      0.16751993063601103, 0.81624712432999957, -1.1229141711500397,
      0.31727849591323032, 0.6852030013336855, -1.0994775174818154,
      0.39406005635592345, 0.61990427060588171, -1.1626556655488118,
      0.59055584230794944, 0.41640875005008615, -1.1005499622517476,
      0.69825888035956629, 0.27005725293589145, -1.0964079316598445,
      0.9005836760612147, -0.016407819026412557, -0.93612491277138921,
      0.97815377967386663, -0.23600263496609913, -0.80524806838747365,
      1.1035064488179087, -0.568960540368687, -0.49913241358114657,
      1.0495912307747453, -0.7871389955915713, -0.22202037609476824,
      0.98865807946882667, -1.0485017439388227, 0.20171511088821237,
      0.70602975184502581, -1.1075622027768739, 0.5305494354982867,
      0.40327865021581538, -1.1180840755398607, 0.90058367606121681,
      -0.0863001455635846, -0.85324671119028817, 1.0401158757951092,
      -0.49913241358111987, -0.51562212406197194, 1.0799280887625922,
      -0.93871668805368691, 0.041956057161151208, 0.7842855597942624,
      -1.09947751748185, 0.51859782411156941, 0.37048894022677237,
      -1.091494284924307, 0.97210060751140293, -0.26672325136617919,
      -0.68779059712645552, 1.0624812703225963, -0.7671095305748169,
      -0.15255973706428777, 0.90058367606118583, -1.136288833944231,
      0.54239838277570773, 0.31270396469431472, -1.0243861200587141,
      0.96140623500056421, -0.33733360238367671, -0.60257082003210183,
      1.0848263999603882, -0.97118355149678948, 0.17414013125579869,
      0.63139163908494322, -1.10756220277683, 0.79583764595912865,
      -0.062915451595380451, -0.80511846915289342, 1.1128310880299601,
      -0.84766976325269228, 0.0069942868062422567, 0.73642732287951629,
      -1.1131826430382759, 0.73890804676709543, -0.0069942868062505921,
      -0.82539109945397671, 1.1128310880299161, -0.866885009409127,
      0.062915451595349642, 0.67484173931718516, -1.10756220277689,
      0.83122510774246217, -0.174140131255825, -0.67367761847350538,
      1.0848263999603949, -1.0154915997621936, 0.3373336023836826,
      0.41664098835143409, -1.0243861200586939, 1.0032045292477765,
      -0.54239838277572, -0.29050953454248207, 0.90058367606113288,
      -1.1577776162637, 0.76710953057481091, -0.10005221605177451,
      -0.68779059712648383, 1.0424440013192717, -0.97210060751142557,
      0.34250883239651669, 0.37048894022686624, -1.0065962990559865,
      1.0994775174817919, -0.78678310870306623, 0.041956057161161291,
      0.62047684789861579, -1.0799280887625751, 0.96164518420267442,
      -0.49913241358117594, -0.27672079922437415, 0.85324671119032791,
      -1.1618315304841049, 0.90058367606124134, -0.36148566734659382,
      -0.4032786502157345, 0.900834087847126, -1.1075622027768721,
      0.76822933743021316, -0.201715110888302, -0.54049051761524192,
      0.98865807946883977, -1.1489196634889096, 0.78713899559153655,
      -0.22501796573454, -0.49913241358107874, 0.935478306295136,
      -1.1035064488179227, 0.76832437083250515, -0.23600263496598609,
      -0.47670080288220207, 0.93612491277131793, -1.1617538943451686,
      0.90058367606110989, -0.42776565069574751, -0.27005725293594879,
      0.77550081572152152, -1.1005499622517416, 0.96193503865630725,
      -0.59055584230795177, -0.068201223933793673, 0.61990427060587838,
      -1.0698729931779549, 1.0994775174817757, -0.88507730656688111,
      0.31727849591312979, 0.24654392232255859, -0.81624712433004665,
      1.0429434442566916, -1.0449822367728232, 0.64582704102273325,
      -0.14645516098403655, -0.4892750190129076, 0.90058367606123035,
      -1.1568223981672847, 1.010195910226795, -0.6873625823877344,
      0.097794427170464951, 0.41737640690599109, -0.90467703794540533,
      1.0580239748668963, -1.0243861200587916, 0.635075487326638,
      -0.17414013125587485, -0.423968294217014, 0.83036873581426252,
      -1.1313205952635854, 1.0764492719693439, -0.8658725967503168,
      0.37048894022693052, 0.11019578921170421, -0.64864092823068187,
      0.94273038888853888, -1.1131826430383056, 0.94437752858705493,
      -0.65995792201019887, 0.14146033582010123, 0.31727849591301732,
      -0.80376839321782123, 1.037565384465756, -1.1576817882008428,
      0.96170455293338675, -0.67514229164074835, 0.174140131255795,
      0.26097129927557683, -0.73089986697026554, 0.96744214760989689,
      -1.1131606697658929, 0.96318241026096341, -0.73089986697031528,
      0.27799505055241314, 0.13257689145273355, -0.61270548647237022,
      0.90058367606107526, -1.1334412256147091, 1.0947541325799492,
      -0.976784090383278, 0.61990427060589282, -0.26439161511097681,
      -0.21545590840340648, 0.56552920881704, -0.9167421936561132,
      1.0390312538445445, -1.0994775174818272, 0.91223611124233317,
      -0.687790597126564, 0.27898649733943953, 0.076876421952962,
      -0.51254300384003826, 0.79206916577180186, -1.0615991285942203,
      1.110524926559231, -1.1156029186677157, 0.90058367606126721,
      -0.67307890816878135, 0.28360634978510979, 0.043367549101199186,
      -0.44850845100484621, 0.71014796325214258, -0.978839654244631,
      1.0516762243259947, -1.1005499622518646, 0.9476872721667815,
      -0.78713899559165368, 0.46226636417268, -0.18104486940795259,
      -0.2029282822619019, 0.48028938128591242, -0.79963465389307931,
      0.96170455293341583, -1.1264655573416102, 1.1114032763638617,
      -1.0911924268115589, 0.90058367606114353, -0.72644798037104419,
      0.41628489703167354, -0.16272688580387731, -0.18104486940791381,
      0.42425671240255897, -0.71494450596141834, 0.87053773084436881,
      -1.044982236772624, 1.067485427806127, -1.0994775174817255,
      0.98241717148205654, -0.88385633051386026, 0.65549362427383506,
      -0.46763214145612336, 0.17885167570715482, 0.041956057160997977,
      -0.33282823196413053, 0.53014010227478847, -0.77123845751936748,
      0.900583676061105, -1.0562009211726315, 1.0921329352672788,
      -1.1470392732835761, 1.0848263999603647, -1.043566951262493,
      0.89645476067551433, -0.7789855553082875, 0.57266515989828348,
      -0.40809141340730604, 0.17414013125580974, 0.0057790920406669893,
      -0.23600263496593082, 0.40233828176368353, -0.60236678564674806,
      0.73279130957204563, -0.88385633051375534, 0.96451613074784437,
      -1.0565173551777198, 1.0822089312859517, -1.1131826430383132,
      1.0862647483342442, -1.0608400621510781, 0.98939364219839421,
      -0.91674219365629073, 0.81245562260184645, -0.70416612474562235,
      0.5803203946647818, -0.4485084510048733, 0.3183072433444295,
      -0.17414013125584524, 0.049504513113204779, 0.097794427170353443,
      -0.20694852169694425, 0.35063752647124863, -0.43669091671703664,
      0.57266515989826938, -0.63024686877126246, 0.75691229926905768,
      -0.78261451757175338, 0.90058367606117207, -0.89253844875427657,
      1.0042398652640634, -0.96163929827709771, 1.0709125061321543,
      -0.99353326210536463, 1.1052596819817173, -0.99303147659544211,
      1.1128310880299426, -0.96547066977970464, 1.099477517481765,
      -0.91619559758816849, 1.0709125061321494, -0.85019160924341153,
      1.0324158470620581, -0.77185170463491137, 0.98865807946886086,
      -0.68485526678123065, 0.94362036533642957, -0.59213356787173832,
      0.90058367606119949, -0.49589848948525234, 0.86216336359333123,
      -0.39771423727654331, 0.83036873581429727, -0.29859605888326551,
      0.80667128674759514, -0.1991243035772445, 0.79206916577188613,
      -0.09956608244825739, 0.78713899559150691, -3.1039788463383945E-14,
      -0.79206916577179853, -0.099558221129019631, -0.80667128674757416,
      -0.199029976434944, -0.83036873581433812, -0.29814815482820867,
      -0.86216336359329238, -0.39633240703691208, -0.90058367606120915,
      -0.49256748542344564, -0.94362036533644833, -0.58528918433298671,
      -0.988658079468853, -0.67228562218670107, -1.0324158470621341,
      -0.75062552679518524, -1.070912506132176, -0.81662951513986826,
      -1.0994775174818185, -0.86590458733144637, -1.1128310880300063,
      -0.89346539414713155, -1.1052596819817768, -0.89396717965713091,
      -1.07091250613218, -0.862073215828809, -1.0042398652640905,
      -0.792972366306026, -0.90058367606119671, -0.68304843512349755,
      -0.75691229926900538, -0.53068078632299254, -0.572665159898251,
      -0.33712483426885709, -0.35063752647129953, -0.10738243924876077,
      -0.097794427170440526, 0.14907059556139185, 0.17414013125574296,
      0.41787332579267622, 0.44850845100480774, 0.67988647711311612,
      0.70416612474554019, 0.91202170505005653, 0.91674219365618881,
      1.0889597246465339, 1.06084006215106, 1.1858308307824394,
      1.113182643038239, 1.181775013734232, 1.0565173551776854,
      1.0640822131962138, 0.88385633051375456, 0.83235739202037917,
      0.602366785646747, 0.50190436421199025, 0.2360026349659142,
      0.10534517448894345, -0.17414013125576, -0.30852533095897972,
      -0.57266515989834033, -0.67941947285993509, -0.89645476067552332,
      -0.94400086881416534, -1.0848263999604337, -1.0474731908353474,
      -1.0921329352673788, -0.95663483872443311, -0.90058367606118994,
      -0.67167237507121658, -0.53014010227481734, -0.23326214951602803,
      -0.041956057161113669, 0.27841775815538383, 0.46763214145607279,
      0.7550597067221122, 0.88385633051376644, 1.0819832539303267,
      1.0994775174817641, 1.1670515102545056, 1.0449822367726336,
      0.97010381329261786, 0.71494450596147829, 0.52382279485083716,
      0.18104486940785111, -0.063160803355607226, -0.41628489703172117,
      -0.62688189792282079, -0.90058367606115841, -0.99162634436331765,
      -1.1114032763638553, -1.0268994748932465, -0.96170455293338786,
      -0.70006857144483525, -0.48028938128597032, -0.10336219981369807,
      0.18104486940783929, 0.56183244662091769, 0.78713899559149925,
      1.0472533546149334, 1.1005499622517076, 1.1512423067742164,
      0.97883965424457464, 0.80971404570034322, 0.44850845100491915,
      0.14293363154948094, -0.28360634978494026, -0.573512825720476,
      -0.90058367606118239, -1.0160368362194176, -1.1105249265591985,
      -0.96203304614598828, -0.79206916577188591, -0.41297692139183562,
      -0.076876421953090759, 0.37855257978765133, 0.68779059712648927,
      1.0118021936905899, 1.0994775174817271, 1.1385973362928434,
      0.91674219365615928, 0.66509529126539557, 0.21545590840352008,
      -0.16482553266264685, -0.61990427060588082, -0.877218007935075,
      -1.0947541325800203, -1.0338751431665669, -0.90058367606115086,
      -0.51313940402419422, -0.13257689145275281, 0.37756113300067812,
      0.73089986697034071, 1.062748492709306, 1.1131606697659109,
      1.0670082300582451, 0.73089986697032, 0.36053738172396815,
      -0.17414013125581868, -0.57557620919245933, -0.96170455293338131,
      -1.0581157057526021, -1.0375653844658896, -0.704202310769646,
      -0.31727849591320778, 0.24102641826834106, 0.65995792201007331,
      1.0439436110353717, 1.113182643038223, 1.042296471336813,
      0.64864092823065467, 0.2097618716600676, -0.37048894022694034,
      -0.76630651430202112, -1.0764492719693646, -1.0317545128152819,
      -0.8303687358142835, -0.32440221176884043, 0.17414013125575051,
      0.73464156977480222, 1.0243861200587372, 1.1575900573151359,
      0.904677037945415, 0.516942489354255, -0.097794427170432047,
      -0.58779649993941308, -1.0101959102267071, -1.057256315719042,
      -0.90058367606119372, -0.38970893656456951, 0.14645516098391195,
      0.74539312347092967, 1.0449822367725952, 1.1425095267048517,
      0.81624712432993185, 0.34611000477088011, -0.31727849591325258,
      -0.785511224118576, -1.0994775174818148, -0.97030691072970643,
      -0.61990427060584263, 0.03136485851439115, 0.59055584230797031,
      1.061501121104552, 1.1005499622517636, 0.8750668981697719,
      0.27005725293586752, -0.32819956824758761, -0.90058367606119094,
      -1.062187811896939, -0.9361249127714184, -0.37713472043399721,
      0.23600263496592072, 0.86789045328076386, 1.1035064488179791,
      1.0350443887434257, 0.49913241358112387, -0.12545188328629048,
      -0.78713899559154465, -1.0493535810406287, -0.98865807946888118,
      -0.4409244351670995, 0.20171511088821911, 0.867795419878519,
      1.1075622027767462, 1.0004001702955081, 0.40327865021575354,
      -0.26191958489817097, -0.90058367606125378, -1.0622654480358003,
      -0.85324671119037265, -0.17715471677623856, 0.49913241358111748,
      1.0612112666509228, 1.0799280887625529, 0.72004293034692268,
      -0.041956057161106813, -0.68721702625479386, -1.0994775174817739,
      -0.90703021660775, -0.37048894022689244, 0.44207491484478423,
      0.97210060751136274, 1.1420100837675093, 0.68779059712656032,
      -0.00048613360356950717, -0.76710953057475761, -1.05821153381544,
      -0.90058367606120127, -0.19094345209430327, 0.54239838277567087,
      1.102770611696009, 1.0243861200587328, 0.51620707079975947,
      -0.33733360238362448, -0.915925517313903, -1.0848263999603851,
      -0.57411153602528864, 0.17414013125578462, 0.93079119019065681,
      1.1075622027768637, 0.77440782176545109, -0.06291545159537329,
      -0.76731892696090587, -1.1128310880299328, -0.72582501700577828,
      0.0069942868061813272, 0.83847412921525954, 1.1131826430382996,
      0.8359934053278526, -0.0069942868062066186, -0.74810368080439416,
      -1.1128310880299357, -0.70555238670464937, 0.062915451595298391,
      0.89540372840744953, 1.107562202776782, 0.73095772153332161,
      -0.17414013125579927, -0.871617469048519, -1.084826399960352,
      -0.50300473758390862, 0.33733360238364885, 1.0609723174488073,
      1.0243861200587214, 0.41227004714260262, -0.54239838277562513,
      -1.0367227514959372, -0.90058367606124534, -0.052993654615967063,
      0.76710953057473474, 1.1620473527709339, 0.68779059712643453,
      -0.1671571689178315, -0.97210060751143468, -0.9919282024760937,
      -0.37048894022685169, 0.61816390655964781, 1.0994775174818265,
      0.88385164224250656, -0.041956057161132945, -0.83915060560540033,
      -1.0799280887625486, -0.41605604161374909, 0.49913241358110771,
      1.1396819582434572, 0.85324671119031548, 0.013265936884809421,
      -0.90058367606123169, -1.0185179930915758, -0.40327865021585318,
      0.63011551794657594, 1.1075622027768348, 0.80559583429329928,
      -0.20171511088826702, -0.94893566149056208, -0.98865807946889916,
      -0.12245429364661815, 0.787138995591591, 1.149157313222946,
      0.49913241358110622, -0.4693944579204723, -1.1035064488179676,
      -0.705681985939306, 0.23600263496588794, 1.0777198621220794,
      0.93612491277137944, 0.083158263421865983, -0.90058367606117051,
      -0.99684184921161434, -0.27005725293578686, 0.79782496280776927,
      1.1005499622517758, 0.51597483249833442, -0.59055584230796121,
      -1.0630895831005, -0.6199042706059209, 0.49362613880418543,
      1.0994775174817435, 0.78476908378198318, -0.31727849591312129,
      -1.02334808870175, -0.81624712432994473, 0.26708601308423474,
      1.0449822367726738, 0.91976581146556136, -0.14645516098394734,
      -0.97241247242385476, -0.90058367606120127, 0.15640694945650757,
      1.0101959102268083, 0.96165824264854949, -0.0977944271704315,
      -0.96102796215273711, -0.90467703794539123, 0.17031486796969636,
      1.0243861200587812, 0.928410260761253, -0.17414013125587893,
      -0.99806938026100089, -0.83036873581430082, 0.30805812866429094,
      1.0764492719693548, 0.80551825935548049, -0.37048894022688983,
      -1.0519426558038438, -0.64864092823064834, 0.55681623230319943,
      1.113182643038273, 0.55369803406431839, -0.65995792201019587,
      -1.0470257292348173, -0.3172784959131415, 0.86731310934796124,
      1.0375653844658994, 0.13895835022347655, -0.961704552933377,
      -0.86983382809091581, 0.17414013125578856, 1.1193407125814494,
      0.73089986697039622, -0.4066264431284235, -1.1131606697659766,
      -0.41617670779539623, 0.73089986697034781, 1.1143511920630564,
      0.13257689145274762, -0.90918770175663532, -0.90058367606115175,
      0.29440192118680625, 1.09475413258007, 0.6624840856869858,
      -0.61990427060586151, -1.041934219557676, -0.21545590840344206,
      0.97930229053485351, 0.91674219365620846, -0.19468393837034637,
      -1.09947751748174, -0.51529645913706867, 0.68779059712655666,
      1.1143372239309484, 0.076876421953043672, -0.961078646991225,
      -0.79206916577188, 0.50634539292523184, 1.1105249265592385,
      0.35873593558471556, -0.90058367606117673, -0.8698618815314515,
      0.28360634978504584, 1.1594568664001814, 0.4485084510049257,
      -0.76759221163457825, -0.97883965424454555, 0.23950709672028364,
      1.1005499622517665, 0.55365565877669987, -0.78713899559153067,
      -0.941219428194541, 0.18104486940788436, 1.1516665106474548,
      0.480289381285917, -0.76759936669373019, -0.96170455293334178,
      0.30800107118560793, 1.1114032763638377, 0.4252644810250345,
      -0.90058367606116418, -0.82868239623193374, 0.41628489703176247,
      1.15648092500067, 0.18104486940789014, -0.96110019281938075,
      -0.71494450596142589, 0.68848221471642634, 1.0449822367726123,
      -0.05667396312341217, -1.0994775174818192, -0.39066760720714849,
      0.88385633051376777, 0.91967777648186477, -0.46763214145618681,
      -1.041970400137644, -0.041956057161168632, 1.1230873863551061,
      0.53014010227477537, -0.78634561192628027, -0.90058367606122491,
      0.49352151580543818, 1.0921329352673346, 0.06905143706392991,
      -1.084826399960418, -0.41622793662742752, 0.89645476067546359,
      0.874335964878923, -0.57266515989830469, -0.99696401231879006,
      0.17414013125584074, 1.1625003022123064, 0.23600263496602075,
      -0.97796396100010785, -0.60236678564671853, 0.86724623863240069,
      0.88385633051381651, -0.46953530141381661, -1.0565173551777216,
      0.2256759456211217, 1.1131826430382623, 0.22222075347331416,
      -1.0608400621510443, -0.44149550234104867, 0.91674219365620813,
      0.80543495746473737, -0.70416612474558082, -0.90025200294011765,
      0.44850845100491171, 1.1182967422322312, -0.17414013125579703,
      -1.0627744668649539, -0.097794427170504655, 1.1394994523243251,
      0.35063752647123386, -0.96112870133648287, -0.57266515989832256,
      0.93894358815889056, 0.75691229926897219, -0.68767314696820259,
      -0.90058367606118273, 0.61795789598781226, 1.0042398652641042,
      -0.34204943970171048, -1.070912506132099, 0.26696658584201616,
      1.1052596819817615, -0.00089695687929560635, -1.11283108802993,
      -0.053225370639160233, 1.0994775174817881, 0.29091892009172815,
      -1.0709125061321287, -0.31244168580386406, 1.0324158470621405,
      0.51583518592017741, -0.98865807946887663, -0.5032647409706057,
      0.9436203653364581, 0.67404292389210352, -0.90058367606118206,
      -0.63110753323614521, 0.86216336359327261, 0.77406951822474135,
      -0.830368735814326, -0.70584370941906538, 0.8066712867475675,
      0.82571730891546857, -0.79206916577189324, -0.73611805742132941,
      0.787138995591505, 0.835684139869652, -0.79206916577188258,
      -0.72615122646721919, 0.80667128674760213, 0.80540979186736772,
      -0.83036873581429993, -0.67450343577649619, 0.86216336359328061,
      0.73067361568439848, -0.90058367606120437, -0.57447684144385669,
      0.94362036533643168, 0.602830823418847, -0.98865807946895623,
      -0.41626910347183521, 1.0324158470620488, 0.41200776825211566,
      -1.0709125061321685, -0.1913528376434574, 1.0994775174817646,
      0.1527914530873892, -1.1128310880299432, 0.10046303932751256,
      1.1052596819818012, -0.16740050339383789, -1.0709125061320968,
      0.44161552214984745, 1.004239865264124, -0.51839181353959,
      -0.90058367606119094, 0.787239229416538, 0.75691229926897419,
      -0.83937750571054937, -0.57266515989828026, 1.0606947837848182,
      0.3506375264713017, -1.0399333698760034, -0.09779442717035676,
      1.1623405493132177, -0.17414013125578195, -1.0187306597839993,
      0.44850845100495434, 0.99981808538827943, -0.70416612474558271,
      -0.70586887501649676, 0.91674219365618093, 0.54106158478929633,
      -1.0608400621510063, -0.12265467102501838, 1.1131826430382883,
      -0.12610986317291323, -1.0565173551776512, 0.569101383861981,
      0.88385633051385326, -0.76768015618418239, -0.60236678564671731,
      1.0775300434482356, 0.23600263496592172, -1.0629342197641156,
      0.17414013125574584, 1.0965300947670786, -0.572665159898306,
      -0.77476988243067368, 0.89645476067551366, 0.51579401907570588,
      -1.0848263999603986, 0.030514645384352088, 1.0921329352673732,
      -0.39395543335718292, -0.90058367606115086, 0.88591169437460371,
      0.53014010227486741, -1.023521303906771, -0.041956057161117596,
      1.1415364825859888, -0.46763214145610732, -0.82011169403357609,
      0.88385633051380874, 0.49023368965549646, -1.0994775174818467,
      0.15624004557177415, 1.0449822367726149, -0.58891613226815,
      -0.71494450596146164, 1.0606662752676428, 0.18104486940787837,
      -1.0569148425524812, 0.41628489703175015, 0.928248478680137,
      -0.90058367606119516, -0.32569839857676597, 1.1114032763637527,
      -0.208434988737293, -0.96170455293342283, 0.86716544914202121,
      0.48028938128591503, -1.0521004281991186, 0.18104486940788744,
      1.04078551064284, -0.78713899559155853, -0.45408957632847319,
      1.1005499622517849, -0.13994101427203981, -0.97883965424462316,
      0.86715829408280642, 0.44850845100484449, -1.0598907839519369,
      0.28360634978499205, 0.96942796397966069, -0.90058367606115208,
      -0.25916985313652158, 1.1105249265592958, -0.40677931047699872,
      -0.79206916577188158, 1.0606447294395633, 0.076876421952973853,
      -1.0147711414826619, 0.687790597126496, 0.614862541585278,
      -1.0994775174818019, 0.29425002081861779, 0.9167421936561444,
      -0.8797362080866542, -0.21545590840342521, 1.1415003020058307,
      -0.61990427060592324, -0.56291800323869612, 1.0947541325799848,
      -0.19483583873860533, -0.90058367606119483, 1.0087537842049383,
      0.13257689145270277, -1.014785109614774, 0.73089986697041176,
      0.51574279024362624, -1.1131606697659659, 0.5061925255767965,
      0.730899866970255, -1.0197746301332034, 0.17414013125579708,
      0.969399910539121, -0.96170455293334445, -0.039392267775240346,
      1.0375653844658239, -0.76774702689971852, -0.31727849591313023,
      1.1465918116831018, -0.65995792201020154, -0.45413195161600406,
      1.1131826430382779, -0.45725014985498569, -0.64864092823069863,
      1.151508738252125, -0.37048894022701123, -0.70595217690715084,
      1.0764492719693075, -0.2084920462160309, -0.83036873581429294,
      1.0976354627093357, -0.17414013125578096, -0.82884417831294566,
      1.0243861200587783, -0.0707487855215978, -0.904677037945323,
      1.0605940446009974, -0.097794427170477566, -0.86209216020028734,
      1.0101959102267288, -0.056840867008300412, -0.900583676061146,
      1.0719785548721428, -0.14645516098405814, -0.82019972901730953,
      1.0449822367726793, -0.16751993063601103, -0.81624712432999957,
      1.1229141711500397, -0.31727849591323032, -0.6852030013336855,
      1.0994775174818154, -0.39406005635592345, -0.61990427060588171,
      1.1626556655488118, -0.59055584230794944, -0.41640875005008615,
      1.1005499622517476, -0.69825888035956629, -0.27005725293589145,
      1.0964079316598445, -0.9005836760612147, 0.016407819026412557,
      0.93612491277138921, -0.97815377967386663, 0.23600263496609913,
      0.80524806838747365, -1.1035064488179087, 0.568960540368687,
      0.49913241358114657, -1.0495912307747453, 0.7871389955915713,
      0.22202037609476824, -0.98865807946882667, 1.0485017439388227,
      -0.20171511088821237, -0.70602975184502581, 1.1075622027768739,
      -0.5305494354982867, -0.40327865021581538, 1.1180840755398607,
      -0.90058367606121681, 0.0863001455635846, 0.85324671119028817,
      -1.0401158757951092, 0.49913241358111987, 0.51562212406197194,
      -1.0799280887625922, 0.93871668805368691, -0.041956057161151208,
      -0.7842855597942624, 1.09947751748185, -0.51859782411156941,
      -0.37048894022677237, 1.091494284924307, -0.97210060751140293,
      0.26672325136617919, 0.68779059712645552, -1.0624812703225963,
      0.7671095305748169, 0.15255973706428777, -0.90058367606118583,
      1.136288833944231, -0.54239838277570773, -0.31270396469431472,
      1.0243861200587141, -0.96140623500056421, 0.33733360238367671,
      0.60257082003210183, -1.0848263999603882, 0.97118355149678948,
      -0.17414013125579869, -0.63139163908494322, 1.10756220277683,
      -0.79583764595912865, 0.062915451595380451, 0.80511846915289342,
      -1.1128310880299601, 0.84766976325269228, -0.0069942868062422567,
      -0.73642732287951629, 1.1131826430382759, -0.73890804676709543,
      0.0069942868062505921, 0.82539109945397671, -1.1128310880299161,
      0.866885009409127, -0.062915451595349642, -0.67484173931718516,
      1.10756220277689, -0.83122510774246217, 0.174140131255825,
      0.67367761847350538, -1.0848263999603949, 1.0154915997621936,
      -0.3373336023836826, -0.41664098835143409, 1.0243861200586939,
      -1.0032045292477765, 0.54239838277572, 0.29050953454248207,
      -0.90058367606113288, 1.1577776162637, -0.76710953057481091,
      0.10005221605177451, 0.68779059712648383, -1.0424440013192717,
      0.97210060751142557, -0.34250883239651669, -0.37048894022686624,
      1.0065962990559865, -1.0994775174817919, 0.78678310870306623,
      -0.041956057161161291, -0.62047684789861579, 1.0799280887625751,
      -0.96164518420267442, 0.49913241358117594, 0.27672079922437415,
      -0.85324671119032791, 1.1618315304841049, -0.90058367606124134,
      0.36148566734659382, 0.4032786502157345, -0.900834087847126,
      1.1075622027768721, -0.76822933743021316, 0.201715110888302,
      0.54049051761524192, -0.98865807946883977, 1.1489196634889096,
      -0.78713899559153655, 0.22501796573454, 0.49913241358107874,
      -0.935478306295136, 1.1035064488179227, -0.76832437083250515,
      0.23600263496598609, 0.47670080288220207, -0.93612491277131793,
      1.1617538943451686, -0.90058367606110989, 0.42776565069574751,
      0.27005725293594879, -0.77550081572152152, 1.1005499622517416,
      -0.96193503865630725, 0.59055584230795177, 0.068201223933793673,
      -0.61990427060587838, 1.0698729931779549, -1.0994775174817757,
      0.88507730656688111, -0.31727849591312979, -0.24654392232255859,
      0.81624712433004665, -1.0429434442566916, 1.0449822367728232,
      -0.64582704102273325, 0.14645516098403655, 0.4892750190129076,
      -0.90058367606123035, 1.1568223981672847, -1.010195910226795,
      0.6873625823877344, -0.097794427170464951, -0.41737640690599109,
      0.90467703794540533, -1.0580239748668963, 1.0243861200587916,
      -0.635075487326638, 0.17414013125587485, 0.423968294217014,
      -0.83036873581426252, 1.1313205952635854, -1.0764492719693439,
      0.8658725967503168, -0.37048894022693052, -0.11019578921170421,
      0.64864092823068187, -0.94273038888853888, 1.1131826430383056,
      -0.94437752858705493, 0.65995792201019887, -0.14146033582010123,
      -0.31727849591301732, 0.80376839321782123, -1.037565384465756,
      1.1576817882008428, -0.96170455293338675, 0.67514229164074835,
      -0.174140131255795, -0.26097129927557683, 0.73089986697026554,
      -0.96744214760989689, 1.1131606697658929, -0.96318241026096341,
      0.73089986697031528, -0.27799505055241314, -0.13257689145273355,
      0.61270548647237022, -0.90058367606107526, 1.1334412256147091,
      -1.0947541325799492, 0.976784090383278, -0.61990427060589282,
      0.26439161511097681, 0.21545590840340648, -0.56552920881704,
      0.9167421936561132, -1.0390312538445445, 1.0994775174818272,
      -0.91223611124233317, 0.687790597126564, -0.27898649733943953,
      -0.076876421952962, 0.51254300384003826, -0.79206916577180186,
      1.0615991285942203, -1.110524926559231, 1.1156029186677157,
      -0.90058367606126721, 0.67307890816878135, -0.28360634978510979,
      -0.043367549101199186, 0.44850845100484621, -0.71014796325214258,
      0.978839654244631, -1.0516762243259947, 1.1005499622518646,
      -0.9476872721667815, 0.78713899559165368, -0.46226636417268,
      0.18104486940795259, 0.2029282822619019, -0.48028938128591242,
      0.79963465389307931, -0.96170455293341583, 1.1264655573416102,
      -1.1114032763638617, 1.0911924268115589, -0.90058367606114353,
      0.72644798037104419, -0.41628489703167354, 0.16272688580387731,
      0.18104486940791381, -0.42425671240255897, 0.71494450596141834,
      -0.87053773084436881, 1.044982236772624, -1.067485427806127,
      1.0994775174817255, -0.98241717148205654, 0.88385633051386026,
      -0.65549362427383506, 0.46763214145612336, -0.17885167570715482,
      -0.041956057160997977, 0.33282823196413053, -0.53014010227478847,
      0.77123845751936748, -0.900583676061105, 1.0562009211726315,
      -1.0921329352672788, 1.1470392732835761, -1.0848263999603647,
      1.043566951262493, -0.89645476067551433, 0.7789855553082875,
      -0.57266515989828348, 0.40809141340730604, -0.17414013125580974,
      -0.0057790920406669893, 0.23600263496593082, -0.40233828176368353,
      0.60236678564674806, -0.73279130957204563, 0.88385633051375534,
      -0.96451613074784437, 1.0565173551777198, -1.0822089312859517,
      1.1131826430383132, -1.0862647483342442, 1.0608400621510781,
      -0.98939364219839421, 0.91674219365629073, -0.81245562260184645,
      0.70416612474562235, -0.5803203946647818, 0.4485084510048733,
      -0.3183072433444295, 0.17414013125584524, -0.049504513113204779,
      -0.097794427170353443, 0.20694852169694425, -0.35063752647124863,
      0.43669091671703664, -0.57266515989826938, 0.63024686877126246,
      -0.75691229926905768, 0.78261451757175338, -0.90058367606117207,
      0.89253844875427657, -1.0042398652640634, 0.96163929827709771,
      -1.0709125061321543, 0.99353326210536463, -1.1052596819817173,
      0.99303147659544211, -1.1128310880299426, 0.96547066977970464,
      -1.099477517481765, 0.91619559758816849, -1.0709125061321494,
      0.85019160924341153, -1.0324158470620581, 0.77185170463491137,
      -0.98865807946886086, 0.68485526678123065, -0.94362036533642957,
      0.59213356787173832, -0.90058367606119949, 0.49589848948525234,
      -0.86216336359333123, 0.39771423727654331, -0.83036873581429727,
      0.29859605888326551, -0.80667128674759514, 0.1991243035772445,
      -0.79206916577188613, 0.09956608244825739, -0.78713899559150691,
      3.1039788463383945E-14, 0.79206916577179853, 0.099558221129019631,
      0.80667128674757416, 0.199029976434944, 0.83036873581433812,
      0.29814815482820867, 0.86216336359329238, 0.39633240703691208,
      0.90058367606120915, 0.49256748542344564, 0.94362036533644833,
      0.58528918433298671, 0.988658079468853, 0.67228562218670107,
      1.0324158470621341, 0.75062552679518524, 1.070912506132176,
      0.81662951513986826, 1.0994775174818185, 0.86590458733144637,
      1.1128310880300063, 0.89346539414713155, 1.1052596819817768,
      0.89396717965713091, 1.07091250613218, 0.862073215828809,
      1.0042398652640905, 0.792972366306026, 0.90058367606119671,
      0.68304843512349755, 0.75691229926900538, 0.53068078632299254,
      0.572665159898251, 0.33712483426885709, 0.35063752647129953,
      0.10738243924876077, 0.097794427170440526, -0.14907059556139185,
      -0.17414013125574296, -0.41787332579267622, -0.44850845100480774,
      -0.67988647711311612, -0.70416612474554019, -0.91202170505005653,
      -0.91674219365618881, -1.0889597246465339, -1.06084006215106,
      -1.1858308307824394, -1.113182643038239, -1.181775013734232,
      -1.0565173551776854, -1.0640822131962138, -0.88385633051375456,
      -0.83235739202037917, -0.602366785646747, -0.50190436421199025,
      -0.2360026349659142, -0.10534517448894345, 0.17414013125576,
      0.30852533095897972, 0.57266515989834033, 0.67941947285993509,
      0.89645476067552332, 0.94400086881416534, 1.0848263999604337,
      1.0474731908353474, 1.0921329352673788, 0.95663483872443311,
      0.90058367606118994, 0.67167237507121658, 0.53014010227481734,
      0.23326214951602803, 0.041956057161113669, -0.27841775815538383,
      -0.46763214145607279, -0.7550597067221122, -0.88385633051376644,
      -1.0819832539303267, -1.0994775174817641, -1.1670515102545056,
      -1.0449822367726336, -0.97010381329261786, -0.71494450596147829,
      -0.52382279485083716, -0.18104486940785111, 0.063160803355607226,
      0.41628489703172117, 0.62688189792282079, 0.90058367606115841,
      0.99162634436331765, 1.1114032763638553, 1.0268994748932465,
      0.96170455293338786, 0.70006857144483525, 0.48028938128597032,
      0.10336219981369807, -0.18104486940783929, -0.56183244662091769,
      -0.78713899559149925, -1.0472533546149334, -1.1005499622517076,
      -1.1512423067742164, -0.97883965424457464, -0.80971404570034322,
      -0.44850845100491915, -0.14293363154948094, 0.28360634978494026,
      0.573512825720476, 0.90058367606118239, 1.0160368362194176,
      1.1105249265591985, 0.96203304614598828, 0.79206916577188591,
      0.41297692139183562, 0.076876421953090759, -0.37855257978765133,
      -0.68779059712648927, -1.0118021936905899, -1.0994775174817271,
      -1.1385973362928434, -0.91674219365615928, -0.66509529126539557,
      -0.21545590840352008, 0.16482553266264685, 0.61990427060588082,
      0.877218007935075, 1.0947541325800203, 1.0338751431665669,
      0.90058367606115086, 0.51313940402419422, 0.13257689145275281,
      -0.37756113300067812, -0.73089986697034071, -1.062748492709306,
      -1.1131606697659109, -1.0670082300582451, -0.73089986697032,
      -0.36053738172396815, 0.17414013125581868, 0.57557620919245933,
      0.96170455293338131, 1.0581157057526021, 1.0375653844658896,
      0.704202310769646, 0.31727849591320778, -0.24102641826834106,
      -0.65995792201007331, -1.0439436110353717, -1.113182643038223,
      -1.042296471336813, -0.64864092823065467, -0.2097618716600676,
      0.37048894022694034, 0.76630651430202112, 1.0764492719693646,
      1.0317545128152819, 0.8303687358142835, 0.32440221176884043,
      -0.17414013125575051, -0.73464156977480222, -1.0243861200587372,
      -1.1575900573151359, -0.904677037945415, -0.516942489354255,
      0.097794427170432047, 0.58779649993941308, 1.0101959102267071,
      1.057256315719042, 0.90058367606119372, 0.38970893656456951,
      -0.14645516098391195, -0.74539312347092967, -1.0449822367725952,
      -1.1425095267048517, -0.81624712432993185, -0.34611000477088011,
      0.31727849591325258, 0.785511224118576, 1.0994775174818148,
      0.97030691072970643, 0.61990427060584263, -0.03136485851439115,
      -0.59055584230797031, -1.061501121104552, -1.1005499622517636,
      -0.8750668981697719, -0.27005725293586752, 0.32819956824758761,
      0.90058367606119094, 1.062187811896939, 0.9361249127714184,
      0.37713472043399721, -0.23600263496592072, -0.86789045328076386,
      -1.1035064488179791, -1.0350443887434257, -0.49913241358112387,
      0.12545188328629048, 0.78713899559154465, 1.0493535810406287,
      0.98865807946888118, 0.4409244351670995, -0.20171511088821911,
      -0.867795419878519, -1.1075622027767462, -1.0004001702955081,
      -0.40327865021575354, 0.26191958489817097, 0.90058367606125378,
      1.0622654480358003, 0.85324671119037265, 0.17715471677623856,
      -0.49913241358111748, -1.0612112666509228, -1.0799280887625529,
      -0.72004293034692268, 0.041956057161106813, 0.68721702625479386,
      1.0994775174817739, 0.90703021660775, 0.37048894022689244,
      -0.44207491484478423, -0.97210060751136274, -1.1420100837675093,
      -0.68779059712656032, 0.00048613360356950717, 0.76710953057475761,
      1.05821153381544, 0.90058367606120127, 0.19094345209430327,
      -0.54239838277567087, -1.102770611696009, -1.0243861200587328,
      -0.51620707079975947, 0.33733360238362448, 0.915925517313903,
      1.0848263999603851, 0.57411153602528864, -0.17414013125578462,
      -0.93079119019065681, -1.1075622027768637, -0.77440782176545109,
      0.06291545159537329, 0.76731892696090587, 1.1128310880299328,
      0.72582501700577828, -0.0069942868061813272, -0.83847412921525954,
      -1.1131826430382996, -0.8359934053278526, 0.0069942868062066186,
      0.74810368080439416, 1.1128310880299357, 0.70555238670464937,
      -0.062915451595298391, -0.89540372840744953, -1.107562202776782,
      -0.73095772153332161, 0.17414013125579927, 0.871617469048519,
      1.084826399960352, 0.50300473758390862, -0.33733360238364885,
      -1.0609723174488073, -1.0243861200587214, -0.41227004714260262,
      0.54239838277562513, 1.0367227514959372, 0.90058367606124534,
      0.052993654615967063, -0.76710953057473474, -1.1620473527709339,
      -0.68779059712643453, 0.1671571689178315, 0.97210060751143468,
      0.9919282024760937, 0.37048894022685169, -0.61816390655964781,
      -1.0994775174818265, -0.88385164224250656, 0.041956057161132945,
      0.83915060560540033, 1.0799280887625486, 0.41605604161374909,
      -0.49913241358110771, -1.1396819582434572, -0.85324671119031548,
      -0.013265936884809421, 0.90058367606123169, 1.0185179930915758,
      0.40327865021585318, -0.63011551794657594, -1.1075622027768348,
      -0.80559583429329928, 0.20171511088826702, 0.94893566149056208,
      0.98865807946889916, 0.12245429364661815, -0.787138995591591,
      -1.149157313222946, -0.49913241358110622, 0.4693944579204723,
      1.1035064488179676, 0.705681985939306, -0.23600263496588794,
      -1.0777198621220794, -0.93612491277137944, -0.083158263421865983,
      0.90058367606117051, 0.99684184921161434, 0.27005725293578686,
      -0.79782496280776927, -1.1005499622517758, -0.51597483249833442,
      0.59055584230796121, 1.0630895831005, 0.6199042706059209,
      -0.49362613880418543, -1.0994775174817435, -0.78476908378198318,
      0.31727849591312129, 1.02334808870175, 0.81624712432994473,
      -0.26708601308423474, -1.0449822367726738, -0.91976581146556136,
      0.14645516098394734, 0.97241247242385476, 0.90058367606120127,
      -0.15640694945650757, -1.0101959102268083, -0.96165824264854949,
      0.0977944271704315, 0.96102796215273711, 0.90467703794539123,
      -0.17031486796969636, -1.0243861200587812, -0.928410260761253,
      0.17414013125587893, 0.99806938026100089, 0.83036873581430082,
      -0.30805812866429094, -1.0764492719693548, -0.80551825935548049,
      0.37048894022688983, 1.0519426558038438, 0.64864092823064834,
      -0.55681623230319943, -1.113182643038273, -0.55369803406431839,
      0.65995792201019587, 1.0470257292348173, 0.3172784959131415,
      -0.86731310934796124, -1.0375653844658994, -0.13895835022347655,
      0.961704552933377, 0.86983382809091581, -0.17414013125578856,
      -1.1193407125814494, -0.73089986697039622, 0.4066264431284235,
      1.1131606697659766, 0.41617670779539623, -0.73089986697034781,
      -1.1143511920630564, -0.13257689145274762, 0.90918770175663532,
      0.90058367606115175, -0.29440192118680625, -1.09475413258007,
      -0.6624840856869858, 0.61990427060586151, 1.041934219557676,
      0.21545590840344206, -0.97930229053485351, -0.91674219365620846,
      0.19468393837034637, 1.09947751748174, 0.51529645913706867,
      -0.68779059712655666, -1.1143372239309484, -0.076876421953043672,
      0.961078646991225, 0.79206916577188, -0.50634539292523184,
      -1.1105249265592385, -0.35873593558471556, 0.90058367606117673,
      0.8698618815314515, -0.28360634978504584, -1.1594568664001814,
      -0.4485084510049257, 0.76759221163457825, 0.97883965424454555,
      -0.23950709672028364, -1.1005499622517665, -0.55365565877669987,
      0.78713899559153067, 0.941219428194541, -0.18104486940788436,
      -1.1516665106474548, -0.480289381285917, 0.76759936669373019,
      0.96170455293334178, -0.30800107118560793, -1.1114032763638377,
      -0.4252644810250345, 0.90058367606116418, 0.82868239623193374,
      -0.41628489703176247, -1.15648092500067, -0.18104486940789014,
      0.96110019281938075, 0.71494450596142589, -0.68848221471642634,
      -1.0449822367726123, 0.05667396312341217, 1.0994775174818192,
      0.39066760720714849, -0.88385633051376777, -0.91967777648186477,
      0.46763214145618681, 1.041970400137644, 0.041956057161168632,
      -1.1230873863551061, -0.53014010227477537, 0.78634561192628027,
      0.90058367606122491, -0.49352151580543818, -1.0921329352673346,
      -0.06905143706392991, 1.084826399960418, 0.41622793662742752,
      -0.89645476067546359, -0.874335964878923, 0.57266515989830469,
      0.99696401231879006, -0.17414013125584074, -1.1625003022123064,
      -0.23600263496602075, 0.97796396100010785, 0.60236678564671853,
      -0.86724623863240069, -0.88385633051381651, 0.46953530141381661,
      1.0565173551777216, -0.2256759456211217, -1.1131826430382623,
      -0.22222075347331416, 1.0608400621510443, 0.44149550234104867,
      -0.91674219365620813, -0.80543495746473737, 0.70416612474558082,
      0.90025200294011765, -0.44850845100491171, -1.1182967422322312,
      0.17414013125579703, 1.0627744668649539, 0.097794427170504655,
      -1.1394994523243251, -0.35063752647123386, 0.96112870133648287,
      0.57266515989832256, -0.93894358815889056, -0.75691229926897219,
      0.68767314696820259, 0.90058367606118273, -0.61795789598781226,
      -1.0042398652641042, 0.34204943970171048, 1.070912506132099,
      -0.26696658584201616, -1.1052596819817615, 0.00089695687929560635,
      1.11283108802993, 0.053225370639160233, -1.0994775174817881,
      -0.29091892009172815, 1.0709125061321287, 0.31244168580386406,
      -1.0324158470621405, -0.51583518592017741, 0.98865807946887663,
      0.5032647409706057, -0.9436203653364581, -0.67404292389210352,
      0.90058367606118206, 0.63110753323614521, -0.86216336359327261,
      -0.77406951822474135, 0.830368735814326, 0.70584370941906538,
      -0.8066712867475675, -0.82571730891546857, 0.79206916577189324,
      0.73611805742132941, -0.787138995591505, -0.835684139869652,
      0.79206916577188258, 0.72615122646721919, -0.80667128674760213,
      -0.80540979186736772, 0.83036873581429993, 0.67450343577649619,
      -0.86216336359328061, -0.73067361568439848, 0.90058367606120437,
      0.57447684144385669, -0.94362036533643168, -0.602830823418847,
      0.98865807946895623, 0.41626910347183521, -1.0324158470620488,
      -0.41200776825211566, 1.0709125061321685, 0.1913528376434574,
      -1.0994775174817646, -0.1527914530873892, 1.1128310880299432,
      -0.10046303932751256, -1.1052596819818012, 0.16740050339383789,
      1.0709125061320968, -0.44161552214984745, -1.004239865264124,
      0.51839181353959, 0.90058367606119094, -0.787239229416538,
      -0.75691229926897419, 0.83937750571054937, 0.57266515989828026,
      -1.0606947837848182, -0.3506375264713017, 1.0399333698760034,
      0.09779442717035676, -1.1623405493132177, 0.17414013125578195,
      1.0187306597839993, -0.44850845100495434, -0.99981808538827943,
      0.70416612474558271, 0.70586887501649676, -0.91674219365618093,
      -0.54106158478929633, 1.0608400621510063, 0.12265467102501838,
      -1.1131826430382883, 0.12610986317291323, 1.0565173551776512,
      -0.569101383861981, -0.88385633051385326, 0.76768015618418239,
      0.60236678564671731, -1.0775300434482356, -0.23600263496592172,
      1.0629342197641156, -0.17414013125574584, -1.0965300947670786,
      0.572665159898306, 0.77476988243067368, -0.89645476067551366,
      -0.51579401907570588, 1.0848263999603986, -0.030514645384352088,
      -1.0921329352673732, 0.39395543335718292, 0.90058367606115086,
      -0.88591169437460371, -0.53014010227486741, 1.023521303906771,
      0.041956057161117596, -1.1415364825859888, 0.46763214145610732,
      0.82011169403357609, -0.88385633051380874, -0.49023368965549646,
      1.0994775174818467, -0.15624004557177415, -1.0449822367726149,
      0.58891613226815, 0.71494450596146164, -1.0606662752676428,
      -0.18104486940787837, 1.0569148425524812, -0.41628489703175015,
      -0.928248478680137, 0.90058367606119516, 0.32569839857676597,
      -1.1114032763637527, 0.208434988737293, 0.96170455293342283,
      -0.86716544914202121, -0.48028938128591503, 1.0521004281991186,
      -0.18104486940788744, -1.04078551064284, 0.78713899559155853,
      0.45408957632847319, -1.1005499622517849, 0.13994101427203981,
      0.97883965424462316, -0.86715829408280642, -0.44850845100484449,
      1.0598907839519369, -0.28360634978499205, -0.96942796397966069,
      0.90058367606115208, 0.25916985313652158, -1.1105249265592958,
      0.40677931047699872, 0.79206916577188158, -1.0606447294395633,
      -0.076876421952973853, 1.0147711414826619, -0.687790597126496,
      -0.614862541585278, 1.0994775174818019, -0.29425002081861779,
      -0.9167421936561444, 0.8797362080866542, 0.21545590840342521,
      -1.1415003020058307, 0.61990427060592324, 0.56291800323869612,
      -1.0947541325799848, 0.19483583873860533, 0.90058367606119483,
      -1.0087537842049383, -0.13257689145270277, 1.014785109614774,
      -0.73089986697041176, -0.51574279024362624, 1.1131606697659659,
      -0.5061925255767965, -0.730899866970255, 1.0197746301332034,
      -0.17414013125579708, -0.969399910539121, 0.96170455293334445,
      0.039392267775240346, -1.0375653844658239, 0.76774702689971852,
      0.31727849591313023, -1.1465918116831018, 0.65995792201020154,
      0.45413195161600406, -1.1131826430382779, 0.45725014985498569,
      0.64864092823069863, -1.151508738252125, 0.37048894022701123,
      0.70595217690715084, -1.0764492719693075, 0.2084920462160309,
      0.83036873581429294, -1.0976354627093357, 0.17414013125578096,
      0.82884417831294566, -1.0243861200587783, 0.0707487855215978,
      0.904677037945323, -1.0605940446009974, 0.097794427170477566,
      0.86209216020028734, -1.0101959102267288, 0.056840867008300412,
      0.900583676061146, -1.0719785548721428, 0.14645516098405814,
      0.82019972901730953, -1.0449822367726793, 0.16751993063601103,
      0.81624712432999957, -1.1229141711500397, 0.31727849591323032,
      0.6852030013336855, -1.0994775174818154, 0.39406005635592345,
      0.61990427060588171, -1.1626556655488118, 0.59055584230794944,
      0.41640875005008615, -1.1005499622517476, 0.69825888035956629,
      0.27005725293589145, -1.0964079316598445, 0.9005836760612147,
      -0.016407819026412557, -0.93612491277138921, 0.97815377967386663,
      -0.23600263496609913, -0.80524806838747365, 1.1035064488179087,
      -0.568960540368687, -0.49913241358114657, 1.0495912307747453,
      -0.7871389955915713, -0.22202037609476824, 0.98865807946882667,
      -1.0485017439388227, 0.20171511088821237, 0.70602975184502581,
      -1.1075622027768739, 0.5305494354982867, 0.40327865021581538,
      -1.1180840755398607, 0.90058367606121681, -0.0863001455635846,
      -0.85324671119028817, 1.0401158757951092, -0.49913241358111987,
      -0.51562212406197194, 1.0799280887625922, -0.93871668805368691,
      0.041956057161151208, 0.7842855597942624, -1.09947751748185,
      0.51859782411156941, 0.37048894022677237, -1.091494284924307,
      0.97210060751140293, -0.26672325136617919, -0.68779059712645552,
      1.0624812703225963, -0.7671095305748169, -0.15255973706428777,
      0.90058367606118583, -1.136288833944231, 0.54239838277570773,
      0.31270396469431472, -1.0243861200587141, 0.96140623500056421,
      -0.33733360238367671, -0.60257082003210183, 1.0848263999603882,
      -0.97118355149678948, 0.17414013125579869, 0.63139163908494322,
      -1.10756220277683, 0.79583764595912865, -0.062915451595380451,
      -0.80511846915289342, 1.1128310880299601, -0.84766976325269228,
      0.0069942868062422567, 0.73642732287951629, -1.1131826430382759,
      0.73890804676709543, -0.0069942868062505921, -0.82539109945397671,
      1.1128310880299161, -0.866885009409127, 0.062915451595349642,
      0.67484173931718516, -1.10756220277689, 0.83122510774246217,
      -0.174140131255825, -0.67367761847350538, 1.0848263999603949,
      -1.0154915997621936, 0.3373336023836826, 0.41664098835143409,
      -1.0243861200586939, 1.0032045292477765, -0.54239838277572,
      -0.29050953454248207, 0.90058367606113288, -1.1577776162637,
      0.76710953057481091, -0.10005221605177451, -0.68779059712648383,
      1.0424440013192717, -0.97210060751142557, 0.34250883239651669,
      0.37048894022686624, -1.0065962990559865, 1.0994775174817919,
      -0.78678310870306623, 0.041956057161161291, 0.62047684789861579,
      -1.0799280887625751, 0.96164518420267442, -0.49913241358117594,
      -0.27672079922437415, 0.85324671119032791, -1.1618315304841049,
      0.90058367606124134, -0.36148566734659382, -0.4032786502157345,
      0.900834087847126, -1.1075622027768721, 0.76822933743021316,
      -0.201715110888302, -0.54049051761524192, 0.98865807946883977,
      -1.1489196634889096, 0.78713899559153655, -0.22501796573454,
      -0.49913241358107874, 0.935478306295136, -1.1035064488179227,
      0.76832437083250515, -0.23600263496598609, -0.47670080288220207,
      0.93612491277131793, -1.1617538943451686, 0.90058367606110989,
      -0.42776565069574751, -0.27005725293594879, 0.77550081572152152,
      -1.1005499622517416, 0.96193503865630725, -0.59055584230795177,
      -0.068201223933793673, 0.61990427060587838, -1.0698729931779549,
      1.0994775174817757, -0.88507730656688111, 0.31727849591312979,
      0.24654392232255859, -0.81624712433004665, 1.0429434442566916,
      -1.0449822367728232, 0.64582704102273325, -0.14645516098403655,
      -0.4892750190129076, 0.90058367606123035, -1.1568223981672847,
      1.010195910226795, -0.6873625823877344, 0.097794427170464951,
      0.41737640690599109, -0.90467703794540533, 1.0580239748668963,
      -1.0243861200587916, 0.635075487326638, -0.17414013125587485,
      -0.423968294217014, 0.83036873581426252, -1.1313205952635854,
      1.0764492719693439, -0.8658725967503168, 0.37048894022693052,
      0.11019578921170421, -0.64864092823068187, 0.94273038888853888,
      -1.1131826430383056, 0.94437752858705493, -0.65995792201019887,
      0.14146033582010123, 0.31727849591301732, -0.80376839321782123,
      1.037565384465756, -1.1576817882008428, 0.96170455293338675,
      -0.67514229164074835, 0.174140131255795, 0.26097129927557683,
      -0.73089986697026554, 0.96744214760989689, -1.1131606697658929,
      0.96318241026096341, -0.73089986697031528, 0.27799505055241314,
      0.13257689145273355, -0.61270548647237022, 0.90058367606107526,
      -1.1334412256147091, 1.0947541325799492, -0.976784090383278,
      0.61990427060589282, -0.26439161511097681, -0.21545590840340648,
      0.56552920881704, -0.9167421936561132, 1.0390312538445445,
      -1.0994775174818272, 0.91223611124233317, -0.687790597126564,
      0.27898649733943953, 0.076876421952962, -0.51254300384003826,
      0.79206916577180186, -1.0615991285942203, 1.110524926559231,
      -1.1156029186677157, 0.90058367606126721, -0.67307890816878135,
      0.28360634978510979, 0.043367549101199186, -0.44850845100484621,
      0.71014796325214258, -0.978839654244631, 1.0516762243259947,
      -1.1005499622518646, 0.9476872721667815, -0.78713899559165368,
      0.46226636417268, -0.18104486940795259, -0.2029282822619019,
      0.48028938128591242, -0.79963465389307931, 0.96170455293341583,
      -1.1264655573416102, 1.1114032763638617, -1.0911924268115589,
      0.90058367606114353, -0.72644798037104419, 0.41628489703167354,
      -0.16272688580387731, -0.18104486940791381, 0.42425671240255897,
      -0.71494450596141834, 0.87053773084436881, -1.044982236772624,
      1.067485427806127, -1.0994775174817255, 0.98241717148205654,
      -0.88385633051386026, 0.65549362427383506, -0.46763214145612336,
      0.17885167570715482, 0.041956057160997977, -0.33282823196413053,
      0.53014010227478847, -0.77123845751936748, 0.900583676061105,
      -1.0562009211726315, 1.0921329352672788, -1.1470392732835761,
      1.0848263999603647, -1.043566951262493, 0.89645476067551433,
      -0.7789855553082875, 0.57266515989828348, -0.40809141340730604,
      0.17414013125580974, 0.0057790920406669893, -0.23600263496593082,
      0.40233828176368353, -0.60236678564674806, 0.73279130957204563,
      -0.88385633051375534, 0.96451613074784437, -1.0565173551777198,
      1.0822089312859517, -1.1131826430383132, 1.0862647483342442,
      -1.0608400621510781, 0.98939364219839421, -0.91674219365629073,
      0.81245562260184645, -0.70416612474562235, 0.5803203946647818,
      -0.4485084510048733, 0.3183072433444295, -0.17414013125584524,
      0.049504513113204779, 0.097794427170353443, -0.20694852169694425,
      0.35063752647124863, -0.43669091671703664, 0.57266515989826938,
      -0.63024686877126246, 0.75691229926905768, -0.78261451757175338,
      0.90058367606117207, -0.89253844875427657, 1.0042398652640634,
      -0.96163929827709771, 1.0709125061321543, -0.99353326210536463,
      1.1052596819817173, -0.99303147659544211, 1.1128310880299426,
      -0.96547066977970464, 1.099477517481765, -0.91619559758816849,
      1.0709125061321494, -0.85019160924341153, 1.0324158470620581,
      -0.77185170463491137, 0.98865807946886086, -0.68485526678123065,
      0.94362036533642957, -0.59213356787173832, 0.90058367606119949,
      -0.49589848948525234, 0.86216336359333123, -0.39771423727654331,
      0.83036873581429727, -0.29859605888326551, 0.80667128674759514,
      -0.1991243035772445, 0.79206916577188613, -0.09956608244825739,
      0.78713899559150691, -3.1039788463383945E-14, -0.79206916577179853,
      -0.099558221129019631, -0.80667128674757416, -0.199029976434944,
      -0.83036873581433812, -0.29814815482820867, -0.86216336359329238,
      -0.39633240703691208, -0.90058367606120915, -0.49256748542344564,
      -0.94362036533644833, -0.58528918433298671, -0.988658079468853,
      -0.67228562218670107, -1.0324158470621341, -0.75062552679518524,
      -1.070912506132176, -0.81662951513986826, -1.0994775174818185,
      -0.86590458733144637, -1.1128310880300063, -0.89346539414713155,
      -1.1052596819817768, -0.89396717965713091, -1.07091250613218,
      -0.862073215828809, -1.0042398652640905, -0.792972366306026,
      -0.90058367606119671, -0.68304843512349755, -0.75691229926900538,
      -0.53068078632299254, -0.572665159898251, -0.33712483426885709,
      -0.35063752647129953, -0.10738243924876077, -0.097794427170440526,
      0.14907059556139185, 0.17414013125574296, 0.41787332579267622,
      0.44850845100480774, 0.67988647711311612, 0.70416612474554019,
      0.91202170505005653, 0.91674219365618881, 1.0889597246465339,
      1.06084006215106, 1.1858308307824394, 1.113182643038239, 1.181775013734232,
      1.0565173551776854, 1.0640822131962138, 0.88385633051375456,
      0.83235739202037917, 0.602366785646747, 0.50190436421199025,
      0.2360026349659142, 0.10534517448894345, -0.17414013125576,
      -0.30852533095897972, -0.57266515989834033, -0.67941947285993509,
      -0.89645476067552332, -0.94400086881416534, -1.0848263999604337,
      -1.0474731908353474, -1.0921329352673788, -0.95663483872443311,
      -0.90058367606118994, -0.67167237507121658, -0.53014010227481734,
      -0.23326214951602803, -0.041956057161113669, 0.27841775815538383,
      0.46763214145607279, 0.7550597067221122, 0.88385633051376644,
      1.0819832539303267, 1.0994775174817641, 1.1670515102545056,
      1.0449822367726336, 0.97010381329261786, 0.71494450596147829,
      0.52382279485083716, 0.18104486940785111, -0.063160803355607226,
      -0.41628489703172117, -0.62688189792282079, -0.90058367606115841,
      -0.99162634436331765, -1.1114032763638553, -1.0268994748932465,
      -0.96170455293338786, -0.70006857144483525, -0.48028938128597032,
      -0.10336219981369807, 0.18104486940783929, 0.56183244662091769,
      0.78713899559149925, 1.0472533546149334, 1.1005499622517076,
      1.1512423067742164, 0.97883965424457464, 0.80971404570034322,
      0.44850845100491915, 0.14293363154948094, -0.28360634978494026,
      -0.573512825720476, -0.90058367606118239, -1.0160368362194176,
      -1.1105249265591985, -0.96203304614598828, -0.79206916577188591,
      -0.41297692139183562, -0.076876421953090759, 0.37855257978765133,
      0.68779059712648927, 1.0118021936905899, 1.0994775174817271,
      1.1385973362928434, 0.91674219365615928, 0.66509529126539557,
      0.21545590840352008, -0.16482553266264685, -0.61990427060588082,
      -0.877218007935075, -1.0947541325800203, -1.0338751431665669,
      -0.90058367606115086, -0.51313940402419422, -0.13257689145275281,
      0.37756113300067812, 0.73089986697034071, 1.062748492709306,
      1.1131606697659109, 1.0670082300582451, 0.73089986697032,
      0.36053738172396815, -0.17414013125581868, -0.57557620919245933,
      -0.96170455293338131, -1.0581157057526021, -1.0375653844658896,
      -0.704202310769646, -0.31727849591320778, 0.24102641826834106,
      0.65995792201007331, 1.0439436110353717, 1.113182643038223,
      1.042296471336813, 0.64864092823065467, 0.2097618716600676,
      -0.37048894022694034, -0.76630651430202112, -1.0764492719693646,
      -1.0317545128152819, -0.8303687358142835, -0.32440221176884043,
      0.17414013125575051, 0.73464156977480222, 1.0243861200587372,
      1.1575900573151359, 0.904677037945415, 0.516942489354255,
      -0.097794427170432047, -0.58779649993941308, -1.0101959102267071,
      -1.057256315719042, -0.90058367606119372, -0.38970893656456951,
      0.14645516098391195, 0.74539312347092967, 1.0449822367725952,
      1.1425095267048517, 0.81624712432993185, 0.34611000477088011,
      -0.31727849591325258, -0.785511224118576, -1.0994775174818148,
      -0.97030691072970643, -0.61990427060584263, 0.03136485851439115,
      0.59055584230797031, 1.061501121104552, 1.1005499622517636,
      0.8750668981697719, 0.27005725293586752, -0.32819956824758761,
      -0.90058367606119094, -1.062187811896939, -0.9361249127714184,
      -0.37713472043399721, 0.23600263496592072, 0.86789045328076386,
      1.1035064488179791, 1.0350443887434257, 0.49913241358112387,
      -0.12545188328629048, -0.78713899559154465, -1.0493535810406287,
      -0.98865807946888118, -0.4409244351670995, 0.20171511088821911,
      0.867795419878519, 1.1075622027767462, 1.0004001702955081,
      0.40327865021575354, -0.26191958489817097, -0.90058367606125378,
      -1.0622654480358003, -0.85324671119037265, -0.17715471677623856,
      0.49913241358111748, 1.0612112666509228, 1.0799280887625529,
      0.72004293034692268, -0.041956057161106813, -0.68721702625479386,
      -1.0994775174817739, -0.90703021660775, -0.37048894022689244,
      0.44207491484478423, 0.97210060751136274, 1.1420100837675093,
      0.68779059712656032, -0.00048613360356950717, -0.76710953057475761,
      -1.05821153381544, -0.90058367606120127, -0.19094345209430327,
      0.54239838277567087, 1.102770611696009, 1.0243861200587328,
      0.51620707079975947, -0.33733360238362448, -0.915925517313903,
      -1.0848263999603851, -0.57411153602528864, 0.17414013125578462,
      0.93079119019065681, 1.1075622027768637, 0.77440782176545109,
      -0.06291545159537329, -0.76731892696090587, -1.1128310880299328,
      -0.72582501700577828, 0.0069942868061813272, 0.83847412921525954,
      1.1131826430382996, 0.8359934053278526, -0.0069942868062066186,
      -0.74810368080439416, -1.1128310880299357, -0.70555238670464937,
      0.062915451595298391, 0.89540372840744953, 1.107562202776782,
      0.73095772153332161, -0.17414013125579927, -0.871617469048519,
      -1.084826399960352, -0.50300473758390862, 0.33733360238364885,
      1.0609723174488073, 1.0243861200587214, 0.41227004714260262,
      -0.54239838277562513, -1.0367227514959372, -0.90058367606124534,
      -0.052993654615967063, 0.76710953057473474, 1.1620473527709339,
      0.68779059712643453, -0.1671571689178315, -0.97210060751143468,
      -0.9919282024760937, -0.37048894022685169, 0.61816390655964781,
      1.0994775174818265, 0.88385164224250656, -0.041956057161132945,
      -0.83915060560540033, -1.0799280887625486, -0.41605604161374909,
      0.49913241358110771, 1.1396819582434572, 0.85324671119031548,
      0.013265936884809421, -0.90058367606123169, -1.0185179930915758,
      -0.40327865021585318, 0.63011551794657594, 1.1075622027768348,
      0.80559583429329928, -0.20171511088826702, -0.94893566149056208,
      -0.98865807946889916, -0.12245429364661815, 0.787138995591591,
      1.149157313222946, 0.49913241358110622, -0.4693944579204723,
      -1.1035064488179676, -0.705681985939306, 0.23600263496588794,
      1.0777198621220794, 0.93612491277137944, 0.083158263421865983,
      -0.90058367606117051, -0.99684184921161434, -0.27005725293578686,
      0.79782496280776927, 1.1005499622517758, 0.51597483249833442,
      -0.59055584230796121, -1.0630895831005, -0.6199042706059209,
      0.49362613880418543, 1.0994775174817435, 0.78476908378198318,
      -0.31727849591312129, -1.02334808870175, -0.81624712432994473,
      0.26708601308423474, 1.0449822367726738, 0.91976581146556136,
      -0.14645516098394734, -0.97241247242385476, -0.90058367606120127,
      0.15640694945650757, 1.0101959102268083, 0.96165824264854949,
      -0.0977944271704315, -0.96102796215273711, -0.90467703794539123,
      0.17031486796969636, 1.0243861200587812, 0.928410260761253,
      -0.17414013125587893, -0.99806938026100089, -0.83036873581430082,
      0.30805812866429094, 1.0764492719693548, 0.80551825935548049,
      -0.37048894022688983, -1.0519426558038438, -0.64864092823064834,
      0.55681623230319943, 1.113182643038273, 0.55369803406431839,
      -0.65995792201019587, -1.0470257292348173, -0.3172784959131415,
      0.86731310934796124, 1.0375653844658994, 0.13895835022347655,
      -0.961704552933377, -0.86983382809091581, 0.17414013125578856,
      1.1193407125814494, 0.73089986697039622, -0.4066264431284235,
      -1.1131606697659766, -0.41617670779539623, 0.73089986697034781,
      1.1143511920630564, 0.13257689145274762, -0.90918770175663532,
      -0.90058367606115175, 0.29440192118680625, 1.09475413258007,
      0.6624840856869858, -0.61990427060586151, -1.041934219557676,
      -0.21545590840344206, 0.97930229053485351, 0.91674219365620846,
      -0.19468393837034637, -1.09947751748174, -0.51529645913706867,
      0.68779059712655666, 1.1143372239309484, 0.076876421953043672,
      -0.961078646991225, -0.79206916577188, 0.50634539292523184,
      1.1105249265592385, 0.35873593558471556, -0.90058367606117673,
      -0.8698618815314515, 0.28360634978504584, 1.1594568664001814,
      0.4485084510049257, -0.76759221163457825, -0.97883965424454555,
      0.23950709672028364, 1.1005499622517665, 0.55365565877669987,
      -0.78713899559153067, -0.941219428194541, 0.18104486940788436,
      1.1516665106474548, 0.480289381285917, -0.76759936669373019,
      -0.96170455293334178, 0.30800107118560793, 1.1114032763638377,
      0.4252644810250345, -0.90058367606116418, -0.82868239623193374,
      0.41628489703176247, 1.15648092500067, 0.18104486940789014,
      -0.96110019281938075, -0.71494450596142589, 0.68848221471642634,
      1.0449822367726123, -0.05667396312341217, -1.0994775174818192,
      -0.39066760720714849, 0.88385633051376777, 0.91967777648186477,
      -0.46763214145618681, -1.041970400137644, -0.041956057161168632,
      1.1230873863551061, 0.53014010227477537, -0.78634561192628027,
      -0.90058367606122491, 0.49352151580543818, 1.0921329352673346,
      0.06905143706392991, -1.084826399960418, -0.41622793662742752,
      0.89645476067546359, 0.874335964878923, -0.57266515989830469,
      -0.99696401231879006, 0.17414013125584074, 1.1625003022123064,
      0.23600263496602075, -0.97796396100010785, -0.60236678564671853,
      0.86724623863240069, 0.88385633051381651, -0.46953530141381661,
      -1.0565173551777216, 0.2256759456211217, 1.1131826430382623,
      0.22222075347331416, -1.0608400621510443, -0.44149550234104867,
      0.91674219365620813, 0.80543495746473737, -0.70416612474558082,
      -0.90025200294011765, 0.44850845100491171, 1.1182967422322312,
      -0.17414013125579703, -1.0627744668649539, -0.097794427170504655,
      1.1394994523243251, 0.35063752647123386, -0.96112870133648287,
      -0.57266515989832256, 0.93894358815889056, 0.75691229926897219,
      -0.68767314696820259, -0.90058367606118273, 0.61795789598781226,
      1.0042398652641042, -0.34204943970171048, -1.070912506132099,
      0.26696658584201616, 1.1052596819817615, -0.00089695687929560635,
      -1.11283108802993, -0.053225370639160233, 1.0994775174817881,
      0.29091892009172815, -1.0709125061321287, -0.31244168580386406,
      1.0324158470621405, 0.51583518592017741, -0.98865807946887663,
      -0.5032647409706057, 0.9436203653364581, 0.67404292389210352,
      -0.90058367606118206, -0.63110753323614521, 0.86216336359327261,
      0.77406951822474135, -0.830368735814326, -0.70584370941906538,
      0.8066712867475675, 0.82571730891546857, -0.79206916577189324,
      -0.73611805742132941, 0.787138995591505, 0.835684139869652,
      -0.79206916577188258, -0.72615122646721919, 0.80667128674760213,
      0.80540979186736772, -0.83036873581429993, -0.67450343577649619,
      0.86216336359328061, 0.73067361568439848, -0.90058367606120437,
      -0.57447684144385669, 0.94362036533643168, 0.602830823418847,
      -0.98865807946895623, -0.41626910347183521, 1.0324158470620488,
      0.41200776825211566, -1.0709125061321685, -0.1913528376434574,
      1.0994775174817646, 0.1527914530873892, -1.1128310880299432,
      0.10046303932751256, 1.1052596819818012, -0.16740050339383789,
      -1.0709125061320968, 0.44161552214984745, 1.004239865264124,
      -0.51839181353959, -0.90058367606119094, 0.787239229416538,
      0.75691229926897419, -0.83937750571054937, -0.57266515989828026,
      1.0606947837848182, 0.3506375264713017, -1.0399333698760034,
      -0.09779442717035676, 1.1623405493132177, -0.17414013125578195,
      -1.0187306597839993, 0.44850845100495434, 0.99981808538827943,
      -0.70416612474558271, -0.70586887501649676, 0.91674219365618093,
      0.54106158478929633, -1.0608400621510063, -0.12265467102501838,
      1.1131826430382883, -0.12610986317291323, -1.0565173551776512,
      0.569101383861981, 0.88385633051385326, -0.76768015618418239,
      -0.60236678564671731, 1.0775300434482356, 0.23600263496592172,
      -1.0629342197641156, 0.17414013125574584, 1.0965300947670786,
      -0.572665159898306, -0.77476988243067368, 0.89645476067551366,
      0.51579401907570588, -1.0848263999603986, 0.030514645384352088,
      1.0921329352673732, -0.39395543335718292, -0.90058367606115086,
      0.88591169437460371, 0.53014010227486741, -1.023521303906771,
      -0.041956057161117596, 1.1415364825859888, -0.46763214145610732,
      -0.82011169403357609, 0.88385633051380874, 0.49023368965549646,
      -1.0994775174818467, 0.15624004557177415, 1.0449822367726149,
      -0.58891613226815, -0.71494450596146164, 1.0606662752676428,
      0.18104486940787837, -1.0569148425524812, 0.41628489703175015,
      0.928248478680137, -0.90058367606119516, -0.32569839857676597,
      1.1114032763637527, -0.208434988737293, -0.96170455293342283,
      0.86716544914202121, 0.48028938128591503, -1.0521004281991186,
      0.18104486940788744, 1.04078551064284, -0.78713899559155853,
      -0.45408957632847319, 1.1005499622517849, -0.13994101427203981,
      -0.97883965424462316, 0.86715829408280642, 0.44850845100484449,
      -1.0598907839519369, 0.28360634978499205, 0.96942796397966069,
      -0.90058367606115208, -0.25916985313652158, 1.1105249265592958,
      -0.40677931047699872, -0.79206916577188158, 1.0606447294395633,
      0.076876421952973853, -1.0147711414826619, 0.687790597126496,
      0.614862541585278, -1.0994775174818019, 0.29425002081861779,
      0.9167421936561444, -0.8797362080866542, -0.21545590840342521,
      1.1415003020058307, -0.61990427060592324, -0.56291800323869612,
      1.0947541325799848, -0.19483583873860533, -0.90058367606119483,
      1.0087537842049383, 0.13257689145270277, -1.014785109614774,
      0.73089986697041176, 0.51574279024362624, -1.1131606697659659,
      0.5061925255767965, 0.730899866970255, -1.0197746301332034,
      0.17414013125579708, 0.969399910539121, -0.96170455293334445,
      -0.039392267775240346, 1.0375653844658239, -0.76774702689971852,
      -0.31727849591313023, 1.1465918116831018, -0.65995792201020154,
      -0.45413195161600406, 1.1131826430382779, -0.45725014985498569,
      -0.64864092823069863, 1.151508738252125, -0.37048894022701123,
      -0.70595217690715084, 1.0764492719693075, -0.2084920462160309,
      -0.83036873581429294, 1.0976354627093357, -0.17414013125578096,
      -0.82884417831294566, 1.0243861200587783, -0.0707487855215978,
      -0.904677037945323, 1.0605940446009974, -0.097794427170477566,
      -0.86209216020028734, 1.0101959102267288, -0.056840867008300412,
      -0.900583676061146, 1.0719785548721428, -0.14645516098405814,
      -0.82019972901730953, 1.0449822367726793, -0.16751993063601103,
      -0.81624712432999957, 1.1229141711500397, -0.31727849591323032,
      -0.6852030013336855, 1.0994775174818154, -0.39406005635592345,
      -0.61990427060588171, 1.1626556655488118, -0.59055584230794944,
      -0.41640875005008615, 1.1005499622517476, -0.69825888035956629,
      -0.27005725293589145, 1.0964079316598445, -0.9005836760612147,
      0.016407819026412557, 0.93612491277138921, -0.97815377967386663,
      0.23600263496609913, 0.80524806838747365, -1.1035064488179087,
      0.568960540368687, 0.49913241358114657, -1.0495912307747453,
      0.7871389955915713, 0.22202037609476824, -0.98865807946882667,
      1.0485017439388227, -0.20171511088821237, -0.70602975184502581,
      1.1075622027768739, -0.5305494354982867, -0.40327865021581538,
      1.1180840755398607, -0.90058367606121681, 0.0863001455635846,
      0.85324671119028817, -1.0401158757951092, 0.49913241358111987,
      0.51562212406197194, -1.0799280887625922, 0.93871668805368691,
      -0.041956057161151208, -0.7842855597942624, 1.09947751748185,
      -0.51859782411156941, -0.37048894022677237, 1.091494284924307,
      -0.97210060751140293, 0.26672325136617919, 0.68779059712645552,
      -1.0624812703225963, 0.7671095305748169, 0.15255973706428777,
      -0.90058367606118583, 1.136288833944231, -0.54239838277570773,
      -0.31270396469431472, 1.0243861200587141, -0.96140623500056421,
      0.33733360238367671, 0.60257082003210183, -1.0848263999603882,
      0.97118355149678948, -0.17414013125579869, -0.63139163908494322,
      1.10756220277683, -0.79583764595912865, 0.062915451595380451,
      0.80511846915289342, -1.1128310880299601, 0.84766976325269228,
      -0.0069942868062422567, -0.73642732287951629, 1.1131826430382759,
      -0.73890804676709543, 0.0069942868062505921, 0.82539109945397671,
      -1.1128310880299161, 0.866885009409127, -0.062915451595349642,
      -0.67484173931718516, 1.10756220277689, -0.83122510774246217,
      0.174140131255825, 0.67367761847350538, -1.0848263999603949,
      1.0154915997621936, -0.3373336023836826, -0.41664098835143409,
      1.0243861200586939, -1.0032045292477765, 0.54239838277572,
      0.29050953454248207, -0.90058367606113288, 1.1577776162637,
      -0.76710953057481091, 0.10005221605177451, 0.68779059712648383,
      -1.0424440013192717, 0.97210060751142557, -0.34250883239651669,
      -0.37048894022686624, 1.0065962990559865, -1.0994775174817919,
      0.78678310870306623, -0.041956057161161291, -0.62047684789861579,
      1.0799280887625751, -0.96164518420267442, 0.49913241358117594,
      0.27672079922437415, -0.85324671119032791, 1.1618315304841049,
      -0.90058367606124134, 0.36148566734659382, 0.4032786502157345,
      -0.900834087847126, 1.1075622027768721, -0.76822933743021316,
      0.201715110888302, 0.54049051761524192, -0.98865807946883977,
      1.1489196634889096, -0.78713899559153655, 0.22501796573454,
      0.49913241358107874, -0.935478306295136, 1.1035064488179227,
      -0.76832437083250515, 0.23600263496598609, 0.47670080288220207,
      -0.93612491277131793, 1.1617538943451686, -0.90058367606110989,
      0.42776565069574751, 0.27005725293594879, -0.77550081572152152,
      1.1005499622517416, -0.96193503865630725, 0.59055584230795177,
      0.068201223933793673, -0.61990427060587838, 1.0698729931779549,
      -1.0994775174817757, 0.88507730656688111, -0.31727849591312979,
      -0.24654392232255859, 0.81624712433004665, -1.0429434442566916,
      1.0449822367728232, -0.64582704102273325, 0.14645516098403655,
      0.4892750190129076, -0.90058367606123035, 1.1568223981672847,
      -1.010195910226795, 0.6873625823877344, -0.097794427170464951,
      -0.41737640690599109, 0.90467703794540533, -1.0580239748668963,
      1.0243861200587916, -0.635075487326638, 0.17414013125587485,
      0.423968294217014, -0.83036873581426252, 1.1313205952635854,
      -1.0764492719693439, 0.8658725967503168, -0.37048894022693052,
      -0.11019578921170421, 0.64864092823068187, -0.94273038888853888,
      1.1131826430383056, -0.94437752858705493, 0.65995792201019887,
      -0.14146033582010123, -0.31727849591301732, 0.80376839321782123,
      -1.037565384465756, 1.1576817882008428, -0.96170455293338675,
      0.67514229164074835, -0.174140131255795, -0.26097129927557683,
      0.73089986697026554, -0.96744214760989689, 1.1131606697658929,
      -0.96318241026096341, 0.73089986697031528, -0.27799505055241314,
      -0.13257689145273355, 0.61270548647237022, -0.90058367606107526,
      1.1334412256147091, -1.0947541325799492, 0.976784090383278,
      -0.61990427060589282, 0.26439161511097681, 0.21545590840340648,
      -0.56552920881704, 0.9167421936561132, -1.0390312538445445,
      1.0994775174818272, -0.91223611124233317, 0.687790597126564,
      -0.27898649733943953, -0.076876421952962, 0.51254300384003826,
      -0.79206916577180186, 1.0615991285942203, -1.110524926559231,
      1.1156029186677157, -0.90058367606126721, 0.67307890816878135,
      -0.28360634978510979, -0.043367549101199186, 0.44850845100484621,
      -0.71014796325214258, 0.978839654244631, -1.0516762243259947,
      1.1005499622518646, -0.9476872721667815, 0.78713899559165368,
      -0.46226636417268, 0.18104486940795259, 0.2029282822619019,
      -0.48028938128591242, 0.79963465389307931, -0.96170455293341583,
      1.1264655573416102, -1.1114032763638617, 1.0911924268115589,
      -0.90058367606114353, 0.72644798037104419, -0.41628489703167354,
      0.16272688580387731, 0.18104486940791381, -0.42425671240255897,
      0.71494450596141834, -0.87053773084436881, 1.044982236772624,
      -1.067485427806127, 1.0994775174817255, -0.98241717148205654,
      0.88385633051386026, -0.65549362427383506, 0.46763214145612336,
      -0.17885167570715482, -0.041956057160997977, 0.33282823196413053,
      -0.53014010227478847, 0.77123845751936748, -0.900583676061105,
      1.0562009211726315, -1.0921329352672788, 1.1470392732835761,
      -1.0848263999603647, 1.043566951262493, -0.89645476067551433,
      0.7789855553082875, -0.57266515989828348, 0.40809141340730604,
      -0.17414013125580974, -0.0057790920406669893, 0.23600263496593082,
      -0.40233828176368353, 0.60236678564674806, -0.73279130957204563,
      0.88385633051375534, -0.96451613074784437, 1.0565173551777198,
      -1.0822089312859517, 1.1131826430383132, -1.0862647483342442,
      1.0608400621510781, -0.98939364219839421, 0.91674219365629073,
      -0.81245562260184645, 0.70416612474562235, -0.5803203946647818,
      0.4485084510048733, -0.3183072433444295, 0.17414013125584524,
      -0.049504513113204779, -0.097794427170353443, 0.20694852169694425,
      -0.35063752647124863, 0.43669091671703664, -0.57266515989826938,
      0.63024686877126246, -0.75691229926905768, 0.78261451757175338,
      -0.90058367606117207, 0.89253844875427657, -1.0042398652640634,
      0.96163929827709771, -1.0709125061321543, 0.99353326210536463,
      -1.1052596819817173, 0.99303147659544211, -1.1128310880299426,
      0.96547066977970464, -1.099477517481765, 0.91619559758816849,
      -1.0709125061321494, 0.85019160924341153, -1.0324158470620581,
      0.77185170463491137, -0.98865807946886086, 0.68485526678123065,
      -0.94362036533642957, 0.59213356787173832, -0.90058367606119949,
      0.49589848948525234, -0.86216336359333123, 0.39771423727654331,
      -0.83036873581429727, 0.29859605888326551, -0.80667128674759514,
      0.1991243035772445, -0.79206916577188613, 0.09956608244825739,
      -0.78713899559150691 } ;

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

  /* InitializeConditions for UnitDelay: '<S73>/d' */
  test_DW.d_DSTATE_cq = test_P.d_InitialCondition_c;

  /* InitializeConditions for UnitDelay: '<S73>/d1' */
  test_DW.d1_DSTATE_f = test_P.d1_InitialCondition_i;

  /* InitializeConditions for UnitDelay: '<S74>/d1' */
  test_DW.d1_DSTATE_ga = test_P.d1_InitialCondition_gm;

  /* InitializeConditions for UnitDelay: '<S74>/d' */
  test_DW.d_DSTATE_h = test_P.d_InitialCondition_j;

  /* InitializeConditions for UnitDelay: '<S75>/d1' */
  test_DW.d1_DSTATE_d = test_P.d1_InitialCondition_a;

  /* InitializeConditions for UnitDelay: '<S75>/d' */
  test_DW.d_DSTATE_p = test_P.d_InitialCondition_m;

  /* InitializeConditions for Delay: '<S67>/Delay' */
  test_DW.Delay_DSTATE = test_P.Delay_InitialCondition;

  /* InitializeConditions for UnitDelay: '<S71>/d' */
  test_DW.d_DSTATE_fu = test_P.d_InitialCondition_d;

  /* InitializeConditions for UnitDelay: '<S71>/d1' */
  test_DW.d1_DSTATE_fx = test_P.d1_InitialCondition_j;

  /* InitializeConditions for UnitDelay: '<S72>/d1' */
  test_DW.d1_DSTATE_m = test_P.d1_InitialCondition_c;

  /* InitializeConditions for UnitDelay: '<S72>/d' */
  test_DW.d_DSTATE_m = test_P.d_InitialCondition_cw;

  /* InitializeConditions for UnitDelay: '<S59>/Delay Input2' */
  test_DW.DelayInput2_DSTATE_n = test_P.DelayInput2_InitialCondition_a;

  /* InitializeConditions for UnitDelay: '<S58>/d1' */
  test_DW.d1_DSTATE_k = test_P.d1_InitialCondition_p;

  /* InitializeConditions for UnitDelay: '<S58>/d' */
  test_DW.d_DSTATE_ow = test_P.d_InitialCondition_mx;

  /* SystemInitialize for Merge: '<S87>/Merge1' */
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
