/******************************************************************************

   Include file untitled_usr.c:

   Definition of functions for user-defined initialization,
   system I/O, and background process code.

   RTI1401 7.9 (02-Nov-2017)
   Mon Mar 17 15:32:42 2025

   Copyright 2017, dSPACE GmbH. All rights reserved. Brand names
   or product names are trademarks or registered trademarks of their
   respective companies or organizations.

 *****************************************************************************/

/* ========================================================================= */
/* =====  Define file version macro. Never change this value.  ============= */
/* ========================================================================= */
#define USER_CODE_FILE_VERSION 5
/* ========================================================================= */

/* Insert #include directives for header files here. */


#if defined(_INLINE)
# define __INLINE static inline
#else
# define __INLINE static
#endif


static void usr_initialize(void)
{
}


__INLINE void usr_sample_input(void)
{
}


__INLINE void usr_input(void)
{
}


__INLINE void usr_output(void)
{
}


static void usr_terminate(void)
{
}


static void usr_background(void)
{
}


#undef __INLINE

/****** [EOF] ****************************************************************/
