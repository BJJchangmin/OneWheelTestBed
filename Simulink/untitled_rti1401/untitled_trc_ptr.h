/*********************** dSPACE target specific file *************************

   Header file untitled_trc_ptr.h:

   Declaration of function that initializes the global TRC pointers

   RTI1401 7.9 (02-Nov-2017)
   Mon Mar 17 15:34:04 2025

   Copyright 2025, dSPACE GmbH. All rights reserved.

 *****************************************************************************/
#ifndef RTI_HEADER_untitled_trc_ptr_h_
#define RTI_HEADER_untitled_trc_ptr_h_

/* Include the model header file. */
#include "untitled.h"
#include "untitled_private.h"
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
EXTERN_C volatile real_T *p_0_untitled_real_T_0;
EXTERN_C volatile real_T *p_1_untitled_real_T_0;

/*
 *  Declare the general function for TRC pointer initialization
 */
EXTERN_C void untitled_rti_init_trc_pointers(void);

#endif                                 /* RTI_HEADER_untitled_trc_ptr_h_ */
