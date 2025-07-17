/***************************************************************************

   Source file untitled_trc_ptr.c:

   Definition of function that initializes the global TRC pointers

   RTI1401 7.9 (02-Nov-2017)
   Mon Mar 17 15:34:04 2025

   Copyright 2025, dSPACE GmbH. All rights reserved.

 *****************************************************************************/

/* Include header file. */
#include "untitled_trc_ptr.h"
#include "untitled.h"
#include "untitled_private.h"

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
volatile real_T *p_0_untitled_real_T_0 = NULL;
volatile real_T *p_1_untitled_real_T_0 = NULL;

/*
 *  Declare the functions, that initially assign TRC pointers
 */
static void rti_init_trc_pointers_0(void);

/* Global pointers to data type transitions are separated in different functions to avoid overloading */
static void rti_init_trc_pointers_0(void)
{
  p_0_untitled_real_T_0 = &untitled_B.Clock;
  p_1_untitled_real_T_0 = &untitled_P.Constant_Value;
}

void untitled_rti_init_trc_pointers(void)
{
  rti_init_trc_pointers_0();
}
