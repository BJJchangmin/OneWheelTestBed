/*********************** dSPACE target specific file *************************

   Header file test_trc_ptr.h:

   Declaration of function that initializes the global TRC pointers

   RTI1401 7.9 (02-Nov-2017)
   Sun Jul 20 19:48:44 2025

   Copyright 2025, dSPACE GmbH. All rights reserved.

 *****************************************************************************/
#ifndef RTI_HEADER_test_trc_ptr_h_
#define RTI_HEADER_test_trc_ptr_h_

/* Include the model header file. */
#include "test.h"
#include "test_private.h"
#ifdef EXTERN_C
#undef EXTERN_C
#endif

#ifdef __cplusplus
#define EXTERN_C                       extern "C"
#else
#define EXTERN_C                       extern
#endif

/*
 *  Declare the global TRC pointers
 */
EXTERN_C volatile real_T *p_0_test_real_T_0;
EXTERN_C volatile boolean_T *p_0_test_boolean_T_1;
EXTERN_C volatile real_T *p_1_test_real_T_0;
EXTERN_C volatile uint32_T *p_1_test_uint32_T_1;
EXTERN_C volatile real_T *p_1_test_real_T_2;
EXTERN_C volatile real_T *p_1_test_real_T_3;
EXTERN_C volatile real_T *p_1_test_real_T_4;
EXTERN_C volatile real_T *p_2_test_real_T_0;
EXTERN_C volatile int_T *p_2_test_int_T_2;
EXTERN_C volatile int8_T *p_2_test_int8_T_3;
EXTERN_C volatile boolean_T *p_2_test_boolean_T_4;

/*
 *  Declare the general function for TRC pointer initialization
 */
EXTERN_C void test_rti_init_trc_pointers(void);

#endif                                 /* RTI_HEADER_test_trc_ptr_h_ */
