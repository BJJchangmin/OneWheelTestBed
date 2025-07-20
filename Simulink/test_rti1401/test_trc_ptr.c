/***************************************************************************

   Source file test_trc_ptr.c:

   Definition of function that initializes the global TRC pointers

   RTI1401 7.9 (02-Nov-2017)
   Sun Jul 20 19:48:44 2025

   Copyright 2025, dSPACE GmbH. All rights reserved.

 *****************************************************************************/

/* Include header file. */
#include "test_trc_ptr.h"
#include "test.h"
#include "test_private.h"

/* Compiler options to turn off optimization. */
#if !defined(DS_OPTIMIZE_INIT_TRC_POINTERS)
#ifdef _MCCPPC

#pragma options -nOt -nOr -nOi -nOx

#endif

#ifdef __GNUC__

#pragma GCC optimize ("O0")

#endif

#ifdef _MSC_VER

#pragma optimize ("", off)

#endif
#endif

/* Definition of Global pointers to data type transitions (for TRC-file access) */
volatile real_T *p_0_test_real_T_0 = NULL;
volatile boolean_T *p_0_test_boolean_T_1 = NULL;
volatile real_T *p_1_test_real_T_0 = NULL;
volatile uint32_T *p_1_test_uint32_T_1 = NULL;
volatile real_T *p_1_test_real_T_2 = NULL;
volatile real_T *p_1_test_real_T_3 = NULL;
volatile real_T *p_1_test_real_T_4 = NULL;
volatile real_T *p_2_test_real_T_0 = NULL;
volatile int_T *p_2_test_int_T_2 = NULL;
volatile int8_T *p_2_test_int8_T_3 = NULL;
volatile boolean_T *p_2_test_boolean_T_4 = NULL;

/*
 *  Declare the functions, that initially assign TRC pointers
 */
static void rti_init_trc_pointers_0(void);

/* Global pointers to data type transitions are separated in different functions to avoid overloading */
static void rti_init_trc_pointers_0(void)
{
  p_0_test_real_T_0 = &test_B.Clock;
  p_0_test_boolean_T_1 = &test_B.LowerRelop1;
  p_1_test_real_T_0 = &test_P.Ts;
  p_1_test_uint32_T_1 = &test_P.Delay1_DelayLength;
  p_1_test_real_T_2 = &test_P.ID_Mode.Constant_Value;
  p_1_test_real_T_3 = &test_P.TorqueMode1.Constant_Value;
  p_1_test_real_T_4 = &test_P.TorqueMode.Constant_Value;
  p_2_test_real_T_0 = &test_DW.d_DSTATE;
  p_2_test_int_T_2 = &test_DW.SFunction1_IWORK[0];
  p_2_test_int8_T_3 = &test_DW.If_ActiveSubsystem;
  p_2_test_boolean_T_4 = &test_DW.current_f_not_empty;
}

void test_rti_init_trc_pointers(void)
{
  rti_init_trc_pointers_0();
}
