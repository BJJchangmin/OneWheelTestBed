/*********************** dSPACE target specific file *************************

   Include file test_rti.c:

   Definition of functions and variables for the system I/O and for
   the hardware and software interrupts used.

   RTI1401 7.9 (02-Nov-2017)
   Sun Jul 20 19:48:44 2025

   Copyright 2025, dSPACE GmbH. All rights reserved.

 *****************************************************************************/

#if !(defined(__RTI_SIMENGINE__) || defined(RTIMP_FRAME))
# error This file may be included only by the RTI(-MP) simulation engine.
#endif

/* Include the model header file. */
#include "test.h"
#include "test_private.h"

/* Defines for block output and parameter structure existence */
#define RTI_rtB_STRUCTURE_EXISTS       1
#define RTI_rtP_STRUCTURE_EXISTS       1
#define RTB_STRUCTURE_NAME             test_B
#define RTP_STRUCTURE_NAME             test_P

/* dSPACE generated includes for header files */
#include <brtenv.h>
#include <rtkernel.h>
#include <rti_assert.h>
#include <rtidefineddatatypes.h>
#include <rtican_ds1401.h>
#ifndef dsRtmGetNumSampleTimes
# define dsRtmGetNumSampleTimes(rtm)   2
#endif

#ifndef dsRtmGetTPtr
# define dsRtmGetTPtr(rtm)             ((rtm)->Timing.t)
#endif

#ifndef dsRtmSetTaskTime
# define dsRtmSetTaskTime(rtm, sti, val) (dsRtmGetTPtr((rtm))[sti] = (val))
#endif

/****** Definitions: task functions for timer tasks *********************/

/* Timer Task 1. (Base rate). */
static void rti_TIMERA(rtk_p_task_control_block task)
{
  /* Task entry code BEGIN */
  /* -- None. -- */
  /* Task entry code END */

  /* Task code. */
  baseRateService(task);

  /* Task exit code BEGIN */
  /* -- None. -- */
  /* Task exit code END */
}

/* ===== Declarations of RTI blocks ======================================== */

/* dSPACE I/O Board DS1_RTICAN #1 */

/* ...  definition of channel struct */
can_tp1_canChannel* can_type1_channel_M1_C1;

/* declare pointers to CAN message structures for support of TX-Custom code */
can_tp1_canMsg* CANTP1_TX_SPMSG_M1_C1_STD;
can_tp1_canMsg* CANTP1_TX_SPMSG_M1_C1_XTD;

/* ... definition of message variable for the RTICAN blocks */
can_tp1_canMsg* can_type1_msg_M1[CANTP1_M1_NUMMSG];

/* dSPACE I/O Board RTICAN_GLOBAL #0 */

/* ===== Definition of interface functions for simulation engine =========== */
#if GRTINTERFACE == 1
#ifdef MULTITASKING
# define dsIsSampleHit(RTM,sti)        rtmGetSampleHitPtr(RTM)[sti]
#else
# define dsIsSampleHit(RTM,sti)        rtmIsSampleHit(RTM,sti,0)
#endif

#else
#ifndef rtmStepTask
# define rtmStepTask(rtm, idx)         ((rtm)->Timing.TaskCounters.TID[(idx)] == 0)
#endif

# define dsIsSampleHit(RTM,sti)        rtmStepTask(RTM, sti)
#endif

#undef __INLINE
#if defined(_INLINE)
# define __INLINE                      static inline
#else
# define __INLINE                      static
#endif

/*Define additional variables*/
static time_T dsTFinal = -1.0;

#define dsGetTFinal(rtm)               (dsTFinal)

static time_T dsStepSize = 0.01;

# define dsGetStepSize(rtm)            (dsStepSize)

static void rti_mdl_initialize_host_services(void)
{
  ts_timestamp_type ts = { 0, 0 };

  host_service(1, &ts);
  DsDaq_Init(0, 32, 1);
}

static void rti_mdl_initialize_io_boards(void)
{
  /* Registering of RTI products and modules at VCM */
  {
    vcm_module_register(VCM_MID_RTI1401, (void *) 0,
                        VCM_TXT_RTI1401, 7, 9, 0,
                        VCM_VERSION_RELEASE, 0, 0, 0, VCM_CTRL_NO_ST);

    {
      vcm_module_descriptor_type* msg_mod_ptr;
      msg_mod_ptr = vcm_module_register(VCM_MID_MATLAB, (void *) 0,
        VCM_TXT_MATLAB, 9, 3, 0,
        VCM_VERSION_RELEASE, 0, 0, 0, VCM_CTRL_NO_ST);
      vcm_module_register(VCM_MID_SIMULINK, msg_mod_ptr,
                          VCM_TXT_SIMULINK, 9, 0, 0,
                          VCM_VERSION_RELEASE, 0, 0, 0, VCM_CTRL_NO_ST);
      vcm_module_register(VCM_MID_RTW, msg_mod_ptr,
                          VCM_TXT_RTW, 8, 13, 0,
                          VCM_VERSION_RELEASE, 0, 0, 0, VCM_CTRL_NO_ST);
      vcm_module_register(VCM_MID_STATEFLOW, msg_mod_ptr,
                          VCM_TXT_STATEFLOW, 9, 0, 0,
                          VCM_VERSION_RELEASE, 0, 0, 0, VCM_CTRL_NO_ST);
      vcm_module_register(VCM_MID_STATEFLOW_CODER, msg_mod_ptr,
                          VCM_TXT_STATEFLOW_CODER, 8, 13, 0,
                          VCM_VERSION_RELEASE, 0, 0, 0, VCM_CTRL_NO_ST);
    }

    vcm_module_register(VCM_MID_RTICAN, (void *) 0,
                        VCM_TXT_RTICAN, 3, 4, 5,
                        VCM_VERSION_RELEASE, 0, 0, 0, VCM_CTRL_NO_ST);
  }

  /* dSPACE I/O Board DS1401STDADCT4 #1 */
  adc_tp4_init(ADC_TP4_1_MODULE_ADDR);

  /* dSPACE I/O Board DS1401STDADCT4 #1 Unit:ADC */
  adc_tp4_single_init2(ADC_TP4_1_MODULE_ADDR,
                       ADC_TP4_CH1,
                       ADC_TP4_INPUT_VOLTAGE_RANGE_2,
                       ADC_TP4_TRIG_SW,
                       0.0);
  adc_tp4_single_init2(ADC_TP4_1_MODULE_ADDR,
                       ADC_TP4_CH2,
                       ADC_TP4_INPUT_VOLTAGE_RANGE_2,
                       ADC_TP4_TRIG_SW,
                       0.0);
  adc_tp4_single_init2(ADC_TP4_1_MODULE_ADDR,
                       ADC_TP4_CH3,
                       ADC_TP4_INPUT_VOLTAGE_RANGE_2,
                       ADC_TP4_TRIG_SW,
                       0.0);

  /* dSPACE I/O Board DS1_RTICAN #1 */
  /* Initialization of DS1501 board */
  can_tp1_communication_init(can_tp1_address_table[0].module_addr,
    CAN_TP1_INT_ENABLE);

  /* dSPACE RTICAN MASTER SETUP Block */
  /* ... Initialize the CAN communication: 500 kbit/s */
  can_type1_channel_M1_C1 = can_tp1_channel_init(can_tp1_address_table[0].
    module_addr, 0, (500 * 1000), CAN_TP1_STD, CAN_TP1_NO_SUBINT);
  can_tp1_channel_termination_set(can_type1_channel_M1_C1,
    CAN_TP1_TERMINATION_ON);

  /* ... Initialize TX message structs for custom code  */
  CANTP1_TX_SPMSG_M1_C1_STD = can_tp1_msg_tx_register(can_type1_channel_M1_C1, 3,
    1050, CAN_TP1_STD, CAN_TP1_TIMECOUNT_INFO | CAN_TP1_DELAYCOUNT_INFO |
    CAN_TP1_MSG_INFO, CAN_TP1_NO_SUBINT, 0, CAN_TP1_TRIGGER_MSG,
    CAN_TP1_TIMEOUT_NORMAL);
  CANTP1_TX_SPMSG_M1_C1_XTD = can_tp1_msg_tx_register(can_type1_channel_M1_C1, 3,
    1100, CAN_TP1_EXT, CAN_TP1_TIMECOUNT_INFO | CAN_TP1_DELAYCOUNT_INFO |
    CAN_TP1_MSG_INFO, CAN_TP1_NO_SUBINT, 0, CAN_TP1_TRIGGER_MSG,
    CAN_TP1_TIMEOUT_NORMAL);

  /* dSPACE RTICAN MASTER SETUP Block */
  /* ... Initialize the Partial Networking Settings */

  /* dSPACE RTICAN TX Message Block: "NMTZeroMsg" Id:0 */
  /* ... Register message */
  can_type1_msg_M1[CANTP1_M1_C1_TX_STD_0X0] = can_tp1_msg_tx_register
    (can_type1_channel_M1_C1, 0, 0, CAN_TP1_STD, (CAN_TP1_TIMECOUNT_INFO|
      CAN_TP1_TIMECOUNT_INFO|CAN_TP1_TIMECOUNT_INFO|CAN_TP1_DELAYCOUNT_INFO),
     CAN_TP1_NO_SUBINT, 0, CAN_TP1_TRIGGER_MSG, CAN_TP1_TIMEOUT_NORMAL);

  /* dSPACE RTICAN TX Message Block: "N10_RPDO0" Id:529 */
  /* ... Register message */
  can_type1_msg_M1[CANTP1_M1_C1_TX_STD_0X211] = can_tp1_msg_tx_register
    (can_type1_channel_M1_C1, 0, 529, CAN_TP1_STD, (CAN_TP1_TIMECOUNT_INFO|
      CAN_TP1_TIMECOUNT_INFO|CAN_TP1_TIMECOUNT_INFO|CAN_TP1_DELAYCOUNT_INFO),
     CAN_TP1_NO_SUBINT, 0, CAN_TP1_TRIGGER_MSG, CAN_TP1_TIMEOUT_NORMAL);

  /* dSPACE RTICAN TX Message Block: "N20_RPDO0" Id:545 */
  /* ... Register message */
  can_type1_msg_M1[CANTP1_M1_C1_TX_STD_0X221] = can_tp1_msg_tx_register
    (can_type1_channel_M1_C1, 1, 545, CAN_TP1_STD, (CAN_TP1_TIMECOUNT_INFO|
      CAN_TP1_TIMECOUNT_INFO|CAN_TP1_TIMECOUNT_INFO|CAN_TP1_DELAYCOUNT_INFO),
     CAN_TP1_NO_SUBINT, 0, CAN_TP1_TRIGGER_MSG, CAN_TP1_TIMEOUT_NORMAL);

  /* dSPACE RTICAN TX Message Block: "N20_RPDO1" Id:546 */
  /* ... Register message */
  can_type1_msg_M1[CANTP1_M1_C1_TX_STD_0X222] = can_tp1_msg_tx_register
    (can_type1_channel_M1_C1, 1, 546, CAN_TP1_STD, (CAN_TP1_TIMECOUNT_INFO|
      CAN_TP1_TIMECOUNT_INFO|CAN_TP1_TIMECOUNT_INFO|CAN_TP1_DELAYCOUNT_INFO),
     CAN_TP1_NO_SUBINT, 0, CAN_TP1_TRIGGER_MSG, CAN_TP1_TIMEOUT_NORMAL);

  /* dSPACE RTICAN TX Message Block: "N30_RPDO1" Id:562 */
  /* ... Register message */
  can_type1_msg_M1[CANTP1_M1_C1_TX_STD_0X232] = can_tp1_msg_tx_register
    (can_type1_channel_M1_C1, 2, 562, CAN_TP1_STD, (CAN_TP1_TIMECOUNT_INFO|
      CAN_TP1_TIMECOUNT_INFO|CAN_TP1_TIMECOUNT_INFO|CAN_TP1_DELAYCOUNT_INFO),
     CAN_TP1_NO_SUBINT, 0, CAN_TP1_TRIGGER_MSG, CAN_TP1_TIMEOUT_NORMAL);

  /* dSPACE RTICAN TX Message Block: "N30_RPDO0" Id:561 */
  /* ... Register message */
  can_type1_msg_M1[CANTP1_M1_C1_TX_STD_0X231] = can_tp1_msg_tx_register
    (can_type1_channel_M1_C1, 1, 561, CAN_TP1_STD, (CAN_TP1_TIMECOUNT_INFO|
      CAN_TP1_TIMECOUNT_INFO|CAN_TP1_TIMECOUNT_INFO|CAN_TP1_DELAYCOUNT_INFO),
     CAN_TP1_NO_SUBINT, 0, CAN_TP1_TRIGGER_MSG, CAN_TP1_TIMEOUT_NORMAL);

  /* dSPACE RTICAN TX Message Block: "N10_RPDO1" Id:530 */
  /* ... Register message */
  can_type1_msg_M1[CANTP1_M1_C1_TX_STD_0X212] = can_tp1_msg_tx_register
    (can_type1_channel_M1_C1, 0, 530, CAN_TP1_STD, (CAN_TP1_TIMECOUNT_INFO|
      CAN_TP1_TIMECOUNT_INFO|CAN_TP1_TIMECOUNT_INFO|CAN_TP1_DELAYCOUNT_INFO),
     CAN_TP1_NO_SUBINT, 0, CAN_TP1_TRIGGER_MSG, CAN_TP1_TIMEOUT_NORMAL);

  /* dSPACE RTICAN RX Message Block: "N30_TPDO2" Id:819 */
  /* ... Register message */
  can_type1_msg_M1[CANTP1_M1_C1_RX_STD_0X333] = can_tp1_msg_rx_register
    (can_type1_channel_M1_C1, 5, 819, CAN_TP1_STD, (CAN_TP1_DATA_INFO|
      CAN_TP1_DATA_INFO|CAN_TP1_TIMECOUNT_INFO|CAN_TP1_TIMECOUNT_INFO),
     CAN_TP1_NO_SUBINT);

  /* dSPACE RTICAN RX Message Block: "N30_TPDO3" Id:820 */
  /* ... Register message */
  can_type1_msg_M1[CANTP1_M1_C1_RX_STD_0X334] = can_tp1_msg_rx_register
    (can_type1_channel_M1_C1, 5, 820, CAN_TP1_STD, (CAN_TP1_DATA_INFO|
      CAN_TP1_DATA_INFO|CAN_TP1_TIMECOUNT_INFO|CAN_TP1_TIMECOUNT_INFO),
     CAN_TP1_NO_SUBINT);

  /* dSPACE RTICAN RX Message Block: "N30_TPDO0" Id:817 */
  /* ... Register message */
  can_type1_msg_M1[CANTP1_M1_C1_RX_STD_0X331] = can_tp1_msg_rx_register
    (can_type1_channel_M1_C1, 5, 817, CAN_TP1_STD, (CAN_TP1_DATA_INFO|
      CAN_TP1_DATA_INFO|CAN_TP1_TIMECOUNT_INFO|CAN_TP1_TIMECOUNT_INFO),
     CAN_TP1_NO_SUBINT);

  /* dSPACE RTICAN RX Message Block: "N10_TPDO3" Id:788 */
  /* ... Register message */
  can_type1_msg_M1[CANTP1_M1_C1_RX_STD_0X314] = can_tp1_msg_rx_register
    (can_type1_channel_M1_C1, 3, 788, CAN_TP1_STD, (CAN_TP1_DATA_INFO|
      CAN_TP1_DATA_INFO|CAN_TP1_TIMECOUNT_INFO|CAN_TP1_TIMECOUNT_INFO),
     CAN_TP1_NO_SUBINT);

  /* dSPACE RTICAN RX Message Block: "N10_TPDO0" Id:785 */
  /* ... Register message */
  can_type1_msg_M1[CANTP1_M1_C1_RX_STD_0X311] = can_tp1_msg_rx_register
    (can_type1_channel_M1_C1, 2, 785, CAN_TP1_STD, (CAN_TP1_DATA_INFO|
      CAN_TP1_DATA_INFO|CAN_TP1_TIMECOUNT_INFO|CAN_TP1_TIMECOUNT_INFO),
     CAN_TP1_NO_SUBINT);

  /* dSPACE RTICAN RX Message Block: "N10_TPDO1" Id:786 */
  /* ... Register message */
  can_type1_msg_M1[CANTP1_M1_C1_RX_STD_0X312] = can_tp1_msg_rx_register
    (can_type1_channel_M1_C1, 2, 786, CAN_TP1_STD, (CAN_TP1_DATA_INFO|
      CAN_TP1_DATA_INFO|CAN_TP1_TIMECOUNT_INFO|CAN_TP1_TIMECOUNT_INFO),
     CAN_TP1_NO_SUBINT);

  /* dSPACE RTICAN RX Message Block: "N10_TPDO2" Id:787 */
  /* ... Register message */
  can_type1_msg_M1[CANTP1_M1_C1_RX_STD_0X313] = can_tp1_msg_rx_register
    (can_type1_channel_M1_C1, 3, 787, CAN_TP1_STD, (CAN_TP1_DATA_INFO|
      CAN_TP1_DATA_INFO|CAN_TP1_TIMECOUNT_INFO|CAN_TP1_TIMECOUNT_INFO),
     CAN_TP1_NO_SUBINT);

  /* dSPACE RTICAN RX Message Block: "N20_TPDO3" Id:804 */
  /* ... Register message */
  can_type1_msg_M1[CANTP1_M1_C1_RX_STD_0X324] = can_tp1_msg_rx_register
    (can_type1_channel_M1_C1, 4, 804, CAN_TP1_STD, (CAN_TP1_DATA_INFO|
      CAN_TP1_DATA_INFO|CAN_TP1_TIMECOUNT_INFO|CAN_TP1_TIMECOUNT_INFO),
     CAN_TP1_NO_SUBINT);

  /* dSPACE RTICAN RX Message Block: "N20_TPDO0" Id:801 */
  /* ... Register message */
  can_type1_msg_M1[CANTP1_M1_C1_RX_STD_0X321] = can_tp1_msg_rx_register
    (can_type1_channel_M1_C1, 3, 801, CAN_TP1_STD, (CAN_TP1_DATA_INFO|
      CAN_TP1_DATA_INFO|CAN_TP1_TIMECOUNT_INFO|CAN_TP1_TIMECOUNT_INFO),
     CAN_TP1_NO_SUBINT);

  /* dSPACE RTICAN RX Message Block: "N20_TPDO1" Id:802 */
  /* ... Register message */
  can_type1_msg_M1[CANTP1_M1_C1_RX_STD_0X322] = can_tp1_msg_rx_register
    (can_type1_channel_M1_C1, 4, 802, CAN_TP1_STD, (CAN_TP1_DATA_INFO|
      CAN_TP1_DATA_INFO|CAN_TP1_TIMECOUNT_INFO|CAN_TP1_TIMECOUNT_INFO),
     CAN_TP1_NO_SUBINT);

  /* dSPACE RTICAN RX Message Block: "N20_TPDO2" Id:803 */
  /* ... Register message */
  can_type1_msg_M1[CANTP1_M1_C1_RX_STD_0X323] = can_tp1_msg_rx_register
    (can_type1_channel_M1_C1, 4, 803, CAN_TP1_STD, (CAN_TP1_DATA_INFO|
      CAN_TP1_DATA_INFO|CAN_TP1_TIMECOUNT_INFO|CAN_TP1_TIMECOUNT_INFO),
     CAN_TP1_NO_SUBINT);

  /* dSPACE RTICAN RX Message Block: "N30_TPDO2" Id:819 */
  test_B.SFunction1_o3_k = 0;          /* processed - flag */
  test_B.SFunction1_o4_h = 0;          /* timestamp */
  test_B.SFunction1_o5 = 0;            /* deltatime */

  /* dSPACE RTICAN RX Message Block: "N30_TPDO3" Id:820 */
  test_B.SFunction1_o3_i = 0;          /* processed - flag */
  test_B.SFunction1_o4_h1 = 0;         /* timestamp */
  test_B.SFunction1_o5_m = 0;          /* deltatime */

  /* dSPACE RTICAN RX Message Block: "N30_TPDO0" Id:817 */
  test_B.SFunction1_o5_c = 0;          /* processed - flag */
  test_B.SFunction1_o6 = 0;            /* timestamp */
  test_B.SFunction1_o7 = 0;            /* deltatime */

  /* dSPACE RTICAN RX Message Block: "N10_TPDO3" Id:788 */
  test_B.SFunction1_o3_c = 0;          /* processed - flag */
  test_B.SFunction1_o4_a = 0;          /* timestamp */
  test_B.SFunction1_o5_b = 0;          /* deltatime */

  /* dSPACE RTICAN RX Message Block: "N10_TPDO0" Id:785 */
  test_B.SFunction1_o5_d = 0;          /* processed - flag */
  test_B.SFunction1_o6_d = 0;          /* timestamp */
  test_B.SFunction1_o7_k = 0;          /* deltatime */

  /* dSPACE RTICAN RX Message Block: "N10_TPDO1" Id:786 */
  test_B.SFunction1_o3_d = 0;          /* processed - flag */
  test_B.SFunction1_o4_kl = 0;         /* timestamp */
  test_B.SFunction1_o5_e = 0;          /* deltatime */

  /* dSPACE RTICAN RX Message Block: "N10_TPDO2" Id:787 */
  test_B.SFunction1_o3_l = 0;          /* processed - flag */
  test_B.SFunction1_o4_l = 0;          /* timestamp */
  test_B.SFunction1_o5_i = 0;          /* deltatime */

  /* dSPACE RTICAN RX Message Block: "N20_TPDO3" Id:804 */
  test_B.SFunction1_o3_m = 0;          /* processed - flag */
  test_B.SFunction1_o4_m = 0;          /* timestamp */
  test_B.SFunction1_o5_f = 0;          /* deltatime */

  /* dSPACE RTICAN RX Message Block: "N20_TPDO0" Id:801 */
  test_B.SFunction1_o5_n = 0;          /* processed - flag */
  test_B.SFunction1_o6_h = 0;          /* timestamp */
  test_B.SFunction1_o7_f = 0;          /* deltatime */

  /* dSPACE RTICAN RX Message Block: "N20_TPDO1" Id:802 */
  test_B.SFunction1_o3_b = 0;          /* processed - flag */
  test_B.SFunction1_o4_a1 = 0;         /* timestamp */
  test_B.SFunction1_o5_id = 0;         /* deltatime */

  /* dSPACE RTICAN RX Message Block: "N20_TPDO2" Id:803 */
  test_B.SFunction1_o3_e = 0;          /* processed - flag */
  test_B.SFunction1_o4_md = 0;         /* timestamp */
  test_B.SFunction1_o5_ck = 0;         /* deltatime */

  /* dSPACE RTICAN TX Message Block: "NMTZeroMsg" Id:0 */
  /* Messages with timestamp zero have been received in pause/stop state
     and must not be handled.
   */
  if (can_type1_msg_M1[CANTP1_M1_C1_TX_STD_0X0]->timestamp > 0.0) {
    test_B.SFunction1_o1 = 0;          /* processed - flag */
    test_B.SFunction1_o2 = 0;          /* timestamp */
    test_B.SFunction1_o3 = 0;          /* deltatime */
    test_B.SFunction1_o4 = 0;          /* delaytime */
  }

  /* dSPACE RTICAN TX Message Block: "N10_RPDO0" Id:529 */
  /* Messages with timestamp zero have been received in pause/stop state
     and must not be handled.
   */
  if (can_type1_msg_M1[CANTP1_M1_C1_TX_STD_0X211]->timestamp > 0.0) {
    test_B.SFunction1_o1_l = 0;        /* processed - flag */
    test_B.SFunction1_o2_e = 0;        /* timestamp */
    test_B.SFunction1_o3_ij = 0;       /* deltatime */
    test_B.SFunction1_o4_d = 0;        /* delaytime */
  }

  /* dSPACE RTICAN TX Message Block: "N20_RPDO0" Id:545 */
  /* Messages with timestamp zero have been received in pause/stop state
     and must not be handled.
   */
  if (can_type1_msg_M1[CANTP1_M1_C1_TX_STD_0X221]->timestamp > 0.0) {
    test_B.SFunction1_o1_f2 = 0;       /* processed - flag */
    test_B.SFunction1_o2_n = 0;        /* timestamp */
    test_B.SFunction1_o3_lq = 0;       /* deltatime */
    test_B.SFunction1_o4_dm = 0;       /* delaytime */
  }

  /* dSPACE RTICAN TX Message Block: "N20_RPDO1" Id:546 */
  /* Messages with timestamp zero have been received in pause/stop state
     and must not be handled.
   */
  if (can_type1_msg_M1[CANTP1_M1_C1_TX_STD_0X222]->timestamp > 0.0) {
    test_B.SFunction1_o1_p = 0;        /* processed - flag */
    test_B.SFunction1_o2_o = 0;        /* timestamp */
    test_B.SFunction1_o3_gi = 0;       /* deltatime */
    test_B.SFunction1_o4_p = 0;        /* delaytime */
  }

  /* dSPACE RTICAN TX Message Block: "N30_RPDO1" Id:562 */
  /* Messages with timestamp zero have been received in pause/stop state
     and must not be handled.
   */
  if (can_type1_msg_M1[CANTP1_M1_C1_TX_STD_0X232]->timestamp > 0.0) {
    test_B.SFunction1_o1_fz = 0;       /* processed - flag */
    test_B.SFunction1_o2_i = 0;        /* timestamp */
    test_B.SFunction1_o3_n = 0;        /* deltatime */
    test_B.SFunction1_o4_m2 = 0;       /* delaytime */
  }

  /* dSPACE RTICAN TX Message Block: "N30_RPDO0" Id:561 */
  /* Messages with timestamp zero have been received in pause/stop state
     and must not be handled.
   */
  if (can_type1_msg_M1[CANTP1_M1_C1_TX_STD_0X231]->timestamp > 0.0) {
    test_B.SFunction1_o1_a1 = 0;       /* processed - flag */
    test_B.SFunction1_o2_lw = 0;       /* timestamp */
    test_B.SFunction1_o3_n1 = 0;       /* deltatime */
    test_B.SFunction1_o4_k2 = 0;       /* delaytime */
  }

  /* dSPACE RTICAN TX Message Block: "N10_RPDO1" Id:530 */
  /* Messages with timestamp zero have been received in pause/stop state
     and must not be handled.
   */
  if (can_type1_msg_M1[CANTP1_M1_C1_TX_STD_0X212]->timestamp > 0.0) {
    test_B.SFunction1_o1_e = 0;        /* processed - flag */
    test_B.SFunction1_o2_iy = 0;       /* timestamp */
    test_B.SFunction1_o3_o = 0;        /* deltatime */
    test_B.SFunction1_o4_lg = 0;       /* delaytime */
  }

  /* dSPACE I/O Board RTICAN_GLOBAL #0 */
}

/* Function rti_mdl_slave_load() is empty */
#define rti_mdl_slave_load()

/* Function rti_mdl_rtk_initialize() is empty */
#define rti_mdl_rtk_initialize()

static void rti_mdl_initialize_io_units(void)
{
  /* dSPACE I/O Board DS1_RTICAN #1 */
  /* Start CAN controller */
  can_tp1_channel_start(can_type1_channel_M1_C1, CAN_TP1_INT_DISABLE);

  /* Set the type1CAN error level */
  rtican_type1_error_level = 0;

  /* ... Reset all taskqueue-specific error variables */
  rtican_type1_tq_err_all_reset(0);

  /* ... Clear all message data buffers */
  can_tp1_all_data_clear(can_tp1_address_table[0].module_addr);

  {
    static UInt32 numInit = 0;
    if (numInit != 0) {
      /* ... Wake message up */
      while ((rtican_type1_tq_error[0][0] = can_tp1_msg_wakeup
              (can_type1_msg_M1[CANTP1_M1_C1_TX_STD_0X0])) ==
             DSMCOM_BUFFER_OVERFLOW) ;
    }

    ++numInit;
  }

  {
    static UInt32 numInit = 0;
    if (numInit != 0) {
      /* ... Wake message up */
      while ((rtican_type1_tq_error[0][0] = can_tp1_msg_wakeup
              (can_type1_msg_M1[CANTP1_M1_C1_TX_STD_0X211])) ==
             DSMCOM_BUFFER_OVERFLOW) ;
    }

    ++numInit;
  }

  {
    static UInt32 numInit = 0;
    if (numInit != 0) {
      /* ... Wake message up */
      while ((rtican_type1_tq_error[0][1] = can_tp1_msg_wakeup
              (can_type1_msg_M1[CANTP1_M1_C1_TX_STD_0X221])) ==
             DSMCOM_BUFFER_OVERFLOW) ;
    }

    ++numInit;
  }

  {
    static UInt32 numInit = 0;
    if (numInit != 0) {
      /* ... Wake message up */
      while ((rtican_type1_tq_error[0][1] = can_tp1_msg_wakeup
              (can_type1_msg_M1[CANTP1_M1_C1_TX_STD_0X222])) ==
             DSMCOM_BUFFER_OVERFLOW) ;
    }

    ++numInit;
  }

  {
    static UInt32 numInit = 0;
    if (numInit != 0) {
      /* ... Wake message up */
      while ((rtican_type1_tq_error[0][2] = can_tp1_msg_wakeup
              (can_type1_msg_M1[CANTP1_M1_C1_TX_STD_0X232])) ==
             DSMCOM_BUFFER_OVERFLOW) ;
    }

    ++numInit;
  }

  {
    static UInt32 numInit = 0;
    if (numInit != 0) {
      /* ... Wake message up */
      while ((rtican_type1_tq_error[0][1] = can_tp1_msg_wakeup
              (can_type1_msg_M1[CANTP1_M1_C1_TX_STD_0X231])) ==
             DSMCOM_BUFFER_OVERFLOW) ;
    }

    ++numInit;
  }

  {
    static UInt32 numInit = 0;
    if (numInit != 0) {
      /* ... Wake message up */
      while ((rtican_type1_tq_error[0][0] = can_tp1_msg_wakeup
              (can_type1_msg_M1[CANTP1_M1_C1_TX_STD_0X212])) ==
             DSMCOM_BUFFER_OVERFLOW) ;
    }

    ++numInit;
  }

  {
    static UInt32 numInit = 0;
    if (numInit != 0) {
      /* ... Wake message up */
      while ((rtican_type1_tq_error[0][5] = can_tp1_msg_wakeup
              (can_type1_msg_M1[CANTP1_M1_C1_RX_STD_0X333])) ==
             DSMCOM_BUFFER_OVERFLOW) ;
    }

    ++numInit;
  }

  {
    static UInt32 numInit = 0;
    if (numInit != 0) {
      /* ... Wake message up */
      while ((rtican_type1_tq_error[0][5] = can_tp1_msg_wakeup
              (can_type1_msg_M1[CANTP1_M1_C1_RX_STD_0X334])) ==
             DSMCOM_BUFFER_OVERFLOW) ;
    }

    ++numInit;
  }

  {
    static UInt32 numInit = 0;
    if (numInit != 0) {
      /* ... Wake message up */
      while ((rtican_type1_tq_error[0][5] = can_tp1_msg_wakeup
              (can_type1_msg_M1[CANTP1_M1_C1_RX_STD_0X331])) ==
             DSMCOM_BUFFER_OVERFLOW) ;
    }

    ++numInit;
  }

  {
    static UInt32 numInit = 0;
    if (numInit != 0) {
      /* ... Wake message up */
      while ((rtican_type1_tq_error[0][3] = can_tp1_msg_wakeup
              (can_type1_msg_M1[CANTP1_M1_C1_RX_STD_0X314])) ==
             DSMCOM_BUFFER_OVERFLOW) ;
    }

    ++numInit;
  }

  {
    static UInt32 numInit = 0;
    if (numInit != 0) {
      /* ... Wake message up */
      while ((rtican_type1_tq_error[0][2] = can_tp1_msg_wakeup
              (can_type1_msg_M1[CANTP1_M1_C1_RX_STD_0X311])) ==
             DSMCOM_BUFFER_OVERFLOW) ;
    }

    ++numInit;
  }

  {
    static UInt32 numInit = 0;
    if (numInit != 0) {
      /* ... Wake message up */
      while ((rtican_type1_tq_error[0][2] = can_tp1_msg_wakeup
              (can_type1_msg_M1[CANTP1_M1_C1_RX_STD_0X312])) ==
             DSMCOM_BUFFER_OVERFLOW) ;
    }

    ++numInit;
  }

  {
    static UInt32 numInit = 0;
    if (numInit != 0) {
      /* ... Wake message up */
      while ((rtican_type1_tq_error[0][3] = can_tp1_msg_wakeup
              (can_type1_msg_M1[CANTP1_M1_C1_RX_STD_0X313])) ==
             DSMCOM_BUFFER_OVERFLOW) ;
    }

    ++numInit;
  }

  {
    static UInt32 numInit = 0;
    if (numInit != 0) {
      /* ... Wake message up */
      while ((rtican_type1_tq_error[0][4] = can_tp1_msg_wakeup
              (can_type1_msg_M1[CANTP1_M1_C1_RX_STD_0X324])) ==
             DSMCOM_BUFFER_OVERFLOW) ;
    }

    ++numInit;
  }

  {
    static UInt32 numInit = 0;
    if (numInit != 0) {
      /* ... Wake message up */
      while ((rtican_type1_tq_error[0][3] = can_tp1_msg_wakeup
              (can_type1_msg_M1[CANTP1_M1_C1_RX_STD_0X321])) ==
             DSMCOM_BUFFER_OVERFLOW) ;
    }

    ++numInit;
  }

  {
    static UInt32 numInit = 0;
    if (numInit != 0) {
      /* ... Wake message up */
      while ((rtican_type1_tq_error[0][4] = can_tp1_msg_wakeup
              (can_type1_msg_M1[CANTP1_M1_C1_RX_STD_0X322])) ==
             DSMCOM_BUFFER_OVERFLOW) ;
    }

    ++numInit;
  }

  {
    static UInt32 numInit = 0;
    if (numInit != 0) {
      /* ... Wake message up */
      while ((rtican_type1_tq_error[0][4] = can_tp1_msg_wakeup
              (can_type1_msg_M1[CANTP1_M1_C1_RX_STD_0X323])) ==
             DSMCOM_BUFFER_OVERFLOW) ;
    }

    ++numInit;
  }
}

/* Function rti_mdl_acknowledge_interrupts() is empty */
#define rti_mdl_acknowledge_interrupts()

/* Function rti_mdl_timetables_register() is empty */
#define rti_mdl_timetables_register()

/* Function rti_mdl_timesync_simstate() is empty */
#define rti_mdl_timesync_simstate()

/* Function rti_mdl_timesync_baserate() is empty */
#define rti_mdl_timesync_baserate()

static void rti_mdl_background(void)
{
  /* DsDaq background call */
  DsDaq_Background(0);

  /* dSPACE I/O Board DS1_RTICAN #1 */
  {
    real_T bg_code_exec_time;
    static real_T bg_code_last_exec_time = 0.0;
    bg_code_exec_time = RTLIB_TIC_READ();
    if ((bg_code_exec_time - bg_code_last_exec_time) > 0.25 ||
        (bg_code_exec_time - bg_code_last_exec_time) < 0) {
      /* ... Check taskqueue-specific error variables */
      rtican_type1_tq_err_all_chk(can_tp1_address_table[0].module_addr, 0);
      bg_code_last_exec_time = bg_code_exec_time;
    }
  }

  /* copy DPMEM - buffers in background */
  {
    /* call update function for CAN Tp1 CAN interface (module number: 1) */
    can_tp1_msg_copy_all_to_mem(can_tp1_address_table[0].module_addr);
  }
}

__INLINE void rti_mdl_sample_input(void)
{
  /* Calls for base sample time: [0.01, 0] */
  /* dSPACE I/O Board DS1401STDADCT4 #1 Unit:ADC */

  /* dSPACE I/O Board DS1401STDADCT4 #1 Unit:ADC Group:ADC */
  adc_tp4_sw_trigger(ADC_TP4_1_MODULE_ADDR, ADC_TP4_CONV_START_1|
                     ADC_TP4_CONV_START_2|ADC_TP4_CONV_START_3);

  /* dSPACE I/O Board DS1_RTICAN #1 Unit:DEFAULT */
  /* call update function for CAN Tp1 CAN interface (module number: 1) */
  can_tp1_msg_copy_all_to_mem(can_tp1_address_table[0].module_addr);
}

static void rti_mdl_daq_service()
{
  /* dSPACE Host Service */
  host_service(1, rtk_current_task_absolute_time_ptr_get());
  DsDaq_Service(0, 0, 1, (DsDaqSTimestampStruct *)
                rtk_current_task_absolute_time_ptr_get());
}

#undef __INLINE

/****** [EOF] ****************************************************************/
