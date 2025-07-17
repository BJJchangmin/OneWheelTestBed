/*
 * test.h
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

#ifndef RTW_HEADER_test_h_
#define RTW_HEADER_test_h_
#include <math.h>
#include <string.h>
#ifndef test_COMMON_INCLUDES_
# define test_COMMON_INCLUDES_
#include <brtenv.h>
#include <rtkernel.h>
#include <rti_assert.h>
#include <rtidefineddatatypes.h>
#include <rtican_ds1401.h>
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                                 /* test_COMMON_INCLUDES_ */

#include "test_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rtGetNaN.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  (rtmGetTPtr((rtm))[0])
#endif

/* Block signals (auto storage) */
typedef struct {
  real_T Clock;                        /* '<Root>/Clock' */
  real_T Saturation;                   /* '<Root>/Saturation' */
  real_T Constant;                     /* '<Root>/Constant' */
  real_T Add;                          /* '<Root>/Add' */
  real_T SFunction1_o1;                /* '<S10>/S-Function1' */
  real_T SFunction1_o2;                /* '<S10>/S-Function1' */
  real_T SFunction1_o3;                /* '<S10>/S-Function1' */
  real_T SFunction1_o4;                /* '<S10>/S-Function1' */
  real_T SFunction1;                   /* '<S11>/S-Function1' */
  real_T SFunction1_j;                 /* '<S12>/S-Function1' */
  real_T SFunction1_n;                 /* '<S13>/S-Function1' */
  real_T SFunction1_o1_f;              /* '<S20>/S-Function1' */
  real_T SFunction1_o2_g;              /* '<S20>/S-Function1' */
  real_T SFunction1_o3_k;              /* '<S20>/S-Function1' */
  real_T SFunction1_o4_h;              /* '<S20>/S-Function1' */
  real_T SFunction1_o5;                /* '<S20>/S-Function1' */
  real_T rpm2rad2;                     /* '<S2>/rpm2rad2' */
  real_T Divide1;                      /* '<S2>/Divide1' */
  real_T SFunction1_o1_g;              /* '<S21>/S-Function1' */
  real_T SFunction1_o2_k;              /* '<S21>/S-Function1' */
  real_T SFunction1_o3_i;              /* '<S21>/S-Function1' */
  real_T SFunction1_o4_h1;             /* '<S21>/S-Function1' */
  real_T SFunction1_o5_m;              /* '<S21>/S-Function1' */
  real_T mA2A;                         /* '<S2>/mA2A' */
  real_T MotortorqueConstant;          /* '<S2>/Motor torque Constant' */
  real_T TorqueConstant1;              /* '<S2>/Torque Constant1' */
  real_T Divide2;                      /* '<S2>/Divide2' */
  real_T SFunction1_o1_o;              /* '<S19>/S-Function1' */
  real_T SFunction1_o2_gh;             /* '<S19>/S-Function1' */
  real_T SFunction1_o3_g;              /* '<S19>/S-Function1' */
  real_T SFunction1_o4_k;              /* '<S19>/S-Function1' */
  real_T SFunction1_o5_c;              /* '<S19>/S-Function1' */
  real_T SFunction1_o6;                /* '<S19>/S-Function1' */
  real_T SFunction1_o7;                /* '<S19>/S-Function1' */
  real_T SFunction1_o1_m;              /* '<S25>/S-Function1' */
  real_T SFunction1_o2_a;              /* '<S25>/S-Function1' */
  real_T SFunction1_o3_c;              /* '<S25>/S-Function1' */
  real_T SFunction1_o4_a;              /* '<S25>/S-Function1' */
  real_T SFunction1_o5_b;              /* '<S25>/S-Function1' */
  real_T mA2A2;                        /* '<S2>/mA2A2' */
  real_T MotortorqueConstant1;         /* '<S2>/Motor torque Constant1' */
  real_T TorqueConstant2;              /* '<S2>/Torque Constant2' */
  real_T Divide3;                      /* '<S2>/Divide3' */
  real_T SFunction1_o1_b;              /* '<S22>/S-Function1' */
  real_T SFunction1_o2_m;              /* '<S22>/S-Function1' */
  real_T SFunction1_o3_i0;             /* '<S22>/S-Function1' */
  real_T SFunction1_o4_ac;             /* '<S22>/S-Function1' */
  real_T SFunction1_o5_d;              /* '<S22>/S-Function1' */
  real_T SFunction1_o6_d;              /* '<S22>/S-Function1' */
  real_T SFunction1_o7_k;              /* '<S22>/S-Function1' */
  real_T SFunction1_o1_d;              /* '<S23>/S-Function1' */
  real_T SFunction1_o2_ay;             /* '<S23>/S-Function1' */
  real_T SFunction1_o3_d;              /* '<S23>/S-Function1' */
  real_T SFunction1_o4_kl;             /* '<S23>/S-Function1' */
  real_T SFunction1_o5_e;              /* '<S23>/S-Function1' */
  real_T SFunction1_o1_a;              /* '<S24>/S-Function1' */
  real_T SFunction1_o2_j;              /* '<S24>/S-Function1' */
  real_T SFunction1_o3_l;              /* '<S24>/S-Function1' */
  real_T SFunction1_o4_l;              /* '<S24>/S-Function1' */
  real_T SFunction1_o5_i;              /* '<S24>/S-Function1' */
  real_T rpm2rad3;                     /* '<S2>/rpm2rad3' */
  real_T SFunction1_o1_bw;             /* '<S29>/S-Function1' */
  real_T SFunction1_o2_p;              /* '<S29>/S-Function1' */
  real_T SFunction1_o3_m;              /* '<S29>/S-Function1' */
  real_T SFunction1_o4_m;              /* '<S29>/S-Function1' */
  real_T SFunction1_o5_f;              /* '<S29>/S-Function1' */
  real_T mA2A1;                        /* '<S2>/mA2A1' */
  real_T MotortorqueConstant2;         /* '<S2>/Motor torque Constant2' */
  real_T TorqueConstant3;              /* '<S2>/Torque Constant3' */
  real_T Divide4;                      /* '<S2>/Divide4' */
  real_T SFunction1_o1_dd;             /* '<S26>/S-Function1' */
  real_T SFunction1_o2_l;              /* '<S26>/S-Function1' */
  real_T SFunction1_o3_j;              /* '<S26>/S-Function1' */
  real_T SFunction1_o4_g;              /* '<S26>/S-Function1' */
  real_T SFunction1_o5_n;              /* '<S26>/S-Function1' */
  real_T SFunction1_o6_h;              /* '<S26>/S-Function1' */
  real_T SFunction1_o7_f;              /* '<S26>/S-Function1' */
  real_T SFunction1_o1_b0;             /* '<S27>/S-Function1' */
  real_T SFunction1_o2_an;             /* '<S27>/S-Function1' */
  real_T SFunction1_o3_b;              /* '<S27>/S-Function1' */
  real_T SFunction1_o4_a1;             /* '<S27>/S-Function1' */
  real_T SFunction1_o5_id;             /* '<S27>/S-Function1' */
  real_T SFunction1_o1_gg;             /* '<S28>/S-Function1' */
  real_T SFunction1_o2_h;              /* '<S28>/S-Function1' */
  real_T SFunction1_o3_e;              /* '<S28>/S-Function1' */
  real_T SFunction1_o4_md;             /* '<S28>/S-Function1' */
  real_T SFunction1_o5_ck;             /* '<S28>/S-Function1' */
  real_T rpm2rad1;                     /* '<S2>/rpm2rad1' */
  real_T d;                            /* '<S14>/d' */
  real_T Sum2;                         /* '<S14>/Sum2' */
  real_T gain;                         /* '<S14>/gain' */
  real_T d1;                           /* '<S14>/d1' */
  real_T Sum1;                         /* '<S14>/Sum1' */
  real_T d1_a;                         /* '<S16>/d1' */
  real_T Sum3;                         /* '<S16>/Sum3' */
  real_T gain_b;                       /* '<S16>/gain' */
  real_T gain2;                        /* '<S16>/gain2' */
  real_T Product2;                     /* '<S16>/Product2' */
  real_T gain1;                        /* '<S16>/gain1' */
  real_T Sum1_i;                       /* '<S16>/Sum1' */
  real_T d_f;                          /* '<S16>/d' */
  real_T Product11;                    /* '<S16>/Product11' */
  real_T Sum2_m;                       /* '<S16>/Sum2' */
  real_T Sum4;                         /* '<S16>/Sum4' */
  real_T Product1;                     /* '<S16>/Product1' */
  real_T SFunction1_o1_l;              /* '<S30>/S-Function1' */
  real_T SFunction1_o2_e;              /* '<S30>/S-Function1' */
  real_T SFunction1_o3_ij;             /* '<S30>/S-Function1' */
  real_T SFunction1_o4_d;              /* '<S30>/S-Function1' */
  real_T SFunction1_o1_f2;             /* '<S32>/S-Function1' */
  real_T SFunction1_o2_n;              /* '<S32>/S-Function1' */
  real_T SFunction1_o3_lq;             /* '<S32>/S-Function1' */
  real_T SFunction1_o4_dm;             /* '<S32>/S-Function1' */
  real_T sampletime;                   /* '<S62>/sample time' */
  real_T deltariselimit;               /* '<S62>/delta rise limit' */
  real_T Product1_l;                   /* '<S42>/Product1' */
  real_T Saturation1;                  /* '<S42>/Saturation1' */
  real_T Yk1;                          /* '<S62>/Delay Input2' */
  real_T UkYk1;                        /* '<S62>/Difference Inputs1' */
  real_T Gain;                         /* '<S42>/Gain' */
  real_T deltafalllimit;               /* '<S62>/delta fall limit' */
  real_T Switch;                       /* '<S63>/Switch' */
  real_T Switch2;                      /* '<S63>/Switch2' */
  real_T DifferenceInputs2;            /* '<S62>/Difference Inputs2' */
  real_T d1_h;                         /* '<S61>/d1' */
  real_T Sum3_j;                       /* '<S61>/Sum3' */
  real_T gain_i;                       /* '<S61>/gain' */
  real_T gain2_k;                      /* '<S61>/gain2' */
  real_T Product2_m;                   /* '<S61>/Product2' */
  real_T gain1_j;                      /* '<S61>/gain1' */
  real_T Sum1_d;                       /* '<S61>/Sum1' */
  real_T d_e;                          /* '<S61>/d' */
  real_T Product11_c;                  /* '<S61>/Product11' */
  real_T Sum2_j;                       /* '<S61>/Sum2' */
  real_T Sum4_n;                       /* '<S61>/Sum4' */
  real_T Product1_lu;                  /* '<S61>/Product1' */
  real_T Product3;                     /* '<S42>/Product3' */
  real_T Product5;                     /* '<S42>/Product5' */
  real_T Product4;                     /* '<S42>/Product4' */
  real_T Round1;                       /* '<S42>/Round1' */
  real_T DataTypeConversion1;          /* '<S42>/Data Type Conversion1' */
  real_T SFunction1_o1_p;              /* '<S33>/S-Function1' */
  real_T SFunction1_o2_o;              /* '<S33>/S-Function1' */
  real_T SFunction1_o3_gi;             /* '<S33>/S-Function1' */
  real_T SFunction1_o4_p;              /* '<S33>/S-Function1' */
  real_T DrivingInputMode;             /* '<S8>/Driving Input Mode' */
  real_T Merge;                        /* '<S87>/Merge' */
  real_T sampletime_d;                 /* '<S56>/sample time' */
  real_T deltariselimit_n;             /* '<S56>/delta rise limit' */
  real_T Product3_i;                   /* '<S44>/Product3' */
  real_T Saturation2;                  /* '<S44>/Saturation2' */
  real_T Yk1_e;                        /* '<S56>/Delay Input2' */
  real_T UkYk1_m;                      /* '<S56>/Difference Inputs1' */
  real_T Gain1;                        /* '<S44>/Gain1' */
  real_T deltafalllimit_l;             /* '<S56>/delta fall limit' */
  real_T Switch_n;                     /* '<S57>/Switch' */
  real_T Switch2_a;                    /* '<S57>/Switch2' */
  real_T DifferenceInputs2_a;          /* '<S56>/Difference Inputs2' */
  real_T d1_m;                         /* '<S55>/d1' */
  real_T Sum3_c;                       /* '<S55>/Sum3' */
  real_T gain_f;                       /* '<S55>/gain' */
  real_T gain2_o;                      /* '<S55>/gain2' */
  real_T Product2_l;                   /* '<S55>/Product2' */
  real_T gain1_b;                      /* '<S55>/gain1' */
  real_T Sum1_o;                       /* '<S55>/Sum1' */
  real_T d_fp;                         /* '<S55>/d' */
  real_T Product11_m;                  /* '<S55>/Product11' */
  real_T Sum2_mm;                      /* '<S55>/Sum2' */
  real_T Sum4_nc;                      /* '<S55>/Sum4' */
  real_T Product1_j;                   /* '<S55>/Product1' */
  real_T Product8;                     /* '<S44>/Product8' */
  real_T Product9;                     /* '<S44>/Product9' */
  real_T Product6;                     /* '<S44>/Product6' */
  real_T Product7;                     /* '<S44>/Product7' */
  real_T Product10;                    /* '<S44>/Product10' */
  real_T DataTypeConversion2;          /* '<S44>/Data Type Conversion2' */
  real_T Merge1;                       /* '<S87>/Merge1' */
  real_T Gain_m;                       /* '<S8>/Gain' */
  real_T Delay1;                       /* '<S8>/Delay1' */
  real_T Add_b;                        /* '<S8>/Add' */
  real_T Product;                      /* '<S8>/Product' */
  real_T sampletime_i;                 /* '<S53>/sample time' */
  real_T deltariselimit_b;             /* '<S53>/delta rise limit' */
  real_T Product3_e;                   /* '<S43>/Product3' */
  real_T Saturation2_d;                /* '<S43>/Saturation2' */
  real_T Yk1_a;                        /* '<S53>/Delay Input2' */
  real_T UkYk1_h;                      /* '<S53>/Difference Inputs1' */
  real_T Gain1_i;                      /* '<S43>/Gain1' */
  real_T deltafalllimit_i;             /* '<S53>/delta fall limit' */
  real_T Switch_a;                     /* '<S54>/Switch' */
  real_T Switch2_o;                    /* '<S54>/Switch2' */
  real_T DifferenceInputs2_n;          /* '<S53>/Difference Inputs2' */
  real_T d1_k;                         /* '<S51>/d1' */
  real_T Sum3_d;                       /* '<S51>/Sum3' */
  real_T gain_g;                       /* '<S51>/gain' */
  real_T gain2_oj;                     /* '<S51>/gain2' */
  real_T Product2_k;                   /* '<S51>/Product2' */
  real_T gain1_l;                      /* '<S51>/gain1' */
  real_T Sum1_n;                       /* '<S51>/Sum1' */
  real_T d_g;                          /* '<S51>/d' */
  real_T Product11_l;                  /* '<S51>/Product11' */
  real_T Sum2_o;                       /* '<S51>/Sum2' */
  real_T Sum4_b;                       /* '<S51>/Sum4' */
  real_T Product1_f;                   /* '<S51>/Product1' */
  real_T Merge1_d;                     /* '<S43>/Merge1' */
  real_T Merge1_e;                     /* '<S40>/Merge1' */
  real_T FromWorkspace[9999];          /* '<S39>/From Workspace' */
  real_T ID_OnOff;                     /* '<S8>/ID_OnOff' */
  real_T Gain1_b;                      /* '<S8>/Gain1' */
  real_T Delay2;                       /* '<S8>/Delay2' */
  real_T Add1;                         /* '<S8>/Add1' */
  real_T Product1_a;                   /* '<S8>/Product1' */
  real_T Gain1_m;                      /* '<S39>/Gain1' */
  real_T Add_a;                        /* '<S39>/Add' */
  real_T Selector;                     /* '<S39>/Selector' */
  real_T Switch_m;                     /* '<S39>/Switch' */
  real_T Divide1_a;                    /* '<S39>/Divide1' */
  real_T Divide2_l;                    /* '<S39>/Divide2' */
  real_T TorqueConstant;               /* '<S39>/Torque Constant' */
  real_T Constant_p;                   /* '<S39>/Constant' */
  real_T Divide;                       /* '<S39>/Divide' */
  real_T Gain_i;                       /* '<S39>/Gain' */
  real_T Divide1_ad;                   /* '<S68>/Divide1' */
  real_T d_l;                          /* '<S73>/d' */
  real_T Sum2_i;                       /* '<S73>/Sum2' */
  real_T gain_gx;                      /* '<S73>/gain' */
  real_T d1_p;                         /* '<S73>/d1' */
  real_T Sum1_i2;                      /* '<S73>/Sum1' */
  real_T Divide2_n;                    /* '<S68>/Divide2' */
  real_T Divide4_c;                    /* '<S68>/Divide4' */
  real_T Add5;                         /* '<S68>/Add5' */
  real_T d1_hw;                        /* '<S74>/d1' */
  real_T Sum3_p;                       /* '<S74>/Sum3' */
  real_T gain_n;                       /* '<S74>/gain' */
  real_T gain2_d;                      /* '<S74>/gain2' */
  real_T Product2_h;                   /* '<S74>/Product2' */
  real_T gain1_f;                      /* '<S74>/gain1' */
  real_T Sum1_h;                       /* '<S74>/Sum1' */
  real_T d_p;                          /* '<S74>/d' */
  real_T Product11_j;                  /* '<S74>/Product11' */
  real_T Sum2_e;                       /* '<S74>/Sum2' */
  real_T Sum4_a;                       /* '<S74>/Sum4' */
  real_T Product1_p;                   /* '<S74>/Product1' */
  real_T Divide_n;                     /* '<S68>/Divide' */
  real_T Saturation_c;                 /* '<S69>/Saturation' */
  real_T gain1_l0;                     /* '<S69>/gain 1' */
  real_T gain_o;                       /* '<S69>/gain ' */
  real_T Divide6;                      /* '<S69>/Divide6' */
  real_T Add1_b;                       /* '<S69>/Add1' */
  real_T Add1_p;                       /* '<S64>/Add1' */
  real_T Divide_m;                     /* '<S69>/Divide' */
  real_T Divide1_m;                    /* '<S69>/Divide1' */
  real_T Divide3_m;                    /* '<S69>/Divide3' */
  real_T Divide4_n;                    /* '<S69>/Divide4' */
  real_T Add_i;                        /* '<S69>/Add' */
  real_T Switch_h;                     /* '<S76>/Switch' */
  real_T Switch2_g;                    /* '<S76>/Switch2' */
  real_T Divide9;                      /* '<S69>/Divide9' */
  real_T Divide7;                      /* '<S69>/Divide7' */
  real_T Sum2_h;                       /* '<S69>/Sum2' */
  real_T d1_n;                         /* '<S75>/d1' */
  real_T Sum1_f;                       /* '<S75>/Sum1' */
  real_T gain_a;                       /* '<S75>/gain' */
  real_T d_b;                          /* '<S75>/d' */
  real_T Sum2_p;                       /* '<S75>/Sum2' */
  real_T Divide2_c;                    /* '<S69>/Divide2' */
  real_T Sum1_a;                       /* '<S69>/Sum1' */
  real_T Divide5;                      /* '<S69>/Divide5' */
  real_T Delay;                        /* '<S67>/Delay' */
  real_T Divide5_a;                    /* '<S67>/Divide5' */
  real_T Divide1_l;                    /* '<S67>/Divide1' */
  real_T d_o;                          /* '<S71>/d' */
  real_T Sum2_g;                       /* '<S71>/Sum2' */
  real_T gain_fg;                      /* '<S71>/gain' */
  real_T d1_h0;                        /* '<S71>/d1' */
  real_T Sum1_is;                      /* '<S71>/Sum1' */
  real_T Divide2_j;                    /* '<S67>/Divide2' */
  real_T Divide4_i;                    /* '<S67>/Divide4' */
  real_T Add2;                         /* '<S67>/Add2' */
  real_T Add1_g;                       /* '<S67>/Add1' */
  real_T d1_i;                         /* '<S72>/d1' */
  real_T Sum3_k;                       /* '<S72>/Sum3' */
  real_T gain_ff;                      /* '<S72>/gain' */
  real_T gain2_p;                      /* '<S72>/gain2' */
  real_T Product2_e;                   /* '<S72>/Product2' */
  real_T gain1_p;                      /* '<S72>/gain1' */
  real_T Sum1_e;                       /* '<S72>/Sum1' */
  real_T d_n;                          /* '<S72>/d' */
  real_T Product11_i;                  /* '<S72>/Product11' */
  real_T Sum2_c;                       /* '<S72>/Sum2' */
  real_T Sum4_m;                       /* '<S72>/Sum4' */
  real_T Product1_l5;                  /* '<S72>/Product1' */
  real_T Divide6_e;                    /* '<S67>/Divide6' */
  real_T Add_j;                        /* '<S64>/Add' */
  real_T Divide3_i;                    /* '<S70>/Divide3' */
  real_T Divide1_g;                    /* '<S70>/Divide1' */
  real_T Gain1_o;                      /* '<S70>/Gain1' */
  real_T Switch_b;                     /* '<S77>/Switch' */
  real_T Switch2_b;                    /* '<S77>/Switch2' */
  real_T Divide_i;                     /* '<S70>/Divide' */
  real_T Gain_f;                       /* '<S70>/Gain' */
  real_T Merge_m;                      /* '<S6>/Merge' */
  real_T Product_h;                    /* '<S6>/Product' */
  real_T SFunction1_o1_fz;             /* '<S35>/S-Function1' */
  real_T SFunction1_o2_i;              /* '<S35>/S-Function1' */
  real_T SFunction1_o3_n;              /* '<S35>/S-Function1' */
  real_T SFunction1_o4_m2;             /* '<S35>/S-Function1' */
  real_T SFunction1_o1_a1;             /* '<S34>/S-Function1' */
  real_T SFunction1_o2_lw;             /* '<S34>/S-Function1' */
  real_T SFunction1_o3_n1;             /* '<S34>/S-Function1' */
  real_T SFunction1_o4_k2;             /* '<S34>/S-Function1' */
  real_T sampletime_l;                 /* '<S59>/sample time' */
  real_T deltariselimit_bb;            /* '<S59>/delta rise limit' */
  real_T Product3_k;                   /* '<S41>/Product3' */
  real_T Saturation_n;                 /* '<S41>/Saturation' */
  real_T Yk1_g;                        /* '<S59>/Delay Input2' */
  real_T UkYk1_f;                      /* '<S59>/Difference Inputs1' */
  real_T Gain_l;                       /* '<S41>/Gain' */
  real_T deltafalllimit_k;             /* '<S59>/delta fall limit' */
  real_T Switch_i;                     /* '<S60>/Switch' */
  real_T Switch2_gi;                   /* '<S60>/Switch2' */
  real_T DifferenceInputs2_d;          /* '<S59>/Difference Inputs2' */
  real_T d1_ng;                        /* '<S58>/d1' */
  real_T Sum3_m;                       /* '<S58>/Sum3' */
  real_T gain_k;                       /* '<S58>/gain' */
  real_T gain2_i;                      /* '<S58>/gain2' */
  real_T Product2_n;                   /* '<S58>/Product2' */
  real_T gain1_n;                      /* '<S58>/gain1' */
  real_T Sum1_o1;                      /* '<S58>/Sum1' */
  real_T d_k;                          /* '<S58>/d' */
  real_T Product11_jy;                 /* '<S58>/Product11' */
  real_T Sum2_me;                      /* '<S58>/Sum2' */
  real_T Sum4_k;                       /* '<S58>/Sum4' */
  real_T Product1_js;                  /* '<S58>/Product1' */
  real_T Product_c;                    /* '<S41>/Product' */
  real_T Product2_o;                   /* '<S41>/Product2' */
  real_T Product1_pc;                  /* '<S41>/Product1' */
  real_T Round;                        /* '<S41>/Round' */
  real_T DataTypeConversion;           /* '<S41>/Data Type Conversion' */
  real_T SFunction1_o1_e;              /* '<S31>/S-Function1' */
  real_T SFunction1_o2_iy;             /* '<S31>/S-Function1' */
  real_T SFunction1_o3_o;              /* '<S31>/S-Function1' */
  real_T SFunction1_o4_lg;             /* '<S31>/S-Function1' */
  real_T Divide_k;                     /* '<S75>/Divide' */
  real_T Product_cn;                   /* '<S79>/Product' */
  real_T Product1_c;                   /* '<S79>/Product1' */
  real_T Product2_j;                   /* '<S79>/Product2' */
  real_T Product3_j;                   /* '<S79>/Product3' */
  real_T Product4_e;                   /* '<S79>/Product4' */
  real_T Product5_c;                   /* '<S79>/Product5' */
  real_T Merge2;                       /* '<S80>/Merge2' */
  real_T Product_o;                    /* '<S80>/Product' */
  real_T Product1_fn;                  /* '<S80>/Product1' */
  real_T Product2_kc;                  /* '<S80>/Product2' */
  real_T Product3_d;                   /* '<S80>/Product3' */
  real_T Product4_ej;                  /* '<S80>/Product4' */
  real_T Product5_e;                   /* '<S80>/Product5' */
  real_T Add_k;                        /* '<S81>/Add' */
  real_T Divide2_d;                    /* '<S85>/Divide2' */
  real_T Divide1_h;                    /* '<S85>/Divide1' */
  real_T Divide3_d;                    /* '<S85>/Divide3' */
  real_T Divide4_p;                    /* '<S85>/Divide4' */
  real_T Add1_i;                       /* '<S81>/Add1' */
  real_T Divide2_n5;                   /* '<S86>/Divide2' */
  real_T Divide1_g2;                   /* '<S86>/Divide1' */
  real_T Divide3_p;                    /* '<S86>/Divide3' */
  real_T Divide5_e;                    /* '<S86>/Divide5' */
  real_T Add2_c;                       /* '<S81>/Add2' */
  real_T Data_Logging;                 /* '<S8>/Data_Logging' */
  real_T cpt_dri;                      /* '<S8>/cpt_dri' */
  real_T Product_i;                    /* '<S83>/Product' */
  real_T Product1_cu;                  /* '<S83>/Product1' */
  real_T y;                            /* '<S43>/MATLAB Function' */
  boolean_T LowerRelop1;               /* '<S63>/LowerRelop1' */
  boolean_T UpperRelop;                /* '<S63>/UpperRelop' */
  boolean_T LowerRelop1_g;             /* '<S57>/LowerRelop1' */
  boolean_T UpperRelop_b;              /* '<S57>/UpperRelop' */
  boolean_T LowerRelop1_j;             /* '<S54>/LowerRelop1' */
  boolean_T UpperRelop_a;              /* '<S54>/UpperRelop' */
  boolean_T LowerRelop1_e;             /* '<S76>/LowerRelop1' */
  boolean_T UpperRelop_g;              /* '<S76>/UpperRelop' */
  boolean_T LowerRelop1_a;             /* '<S77>/LowerRelop1' */
  boolean_T UpperRelop_m;              /* '<S77>/UpperRelop' */
  boolean_T LowerRelop1_o;             /* '<S60>/LowerRelop1' */
  boolean_T UpperRelop_j;              /* '<S60>/UpperRelop' */
} B_test_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T d_DSTATE;                     /* '<S14>/d' */
  real_T d1_DSTATE;                    /* '<S14>/d1' */
  real_T d1_DSTATE_g;                  /* '<S16>/d1' */
  real_T d_DSTATE_o;                   /* '<S16>/d' */
  real_T DelayInput2_DSTATE;           /* '<S62>/Delay Input2' */
  real_T d1_DSTATE_n;                  /* '<S61>/d1' */
  real_T d_DSTATE_g;                   /* '<S61>/d' */
  real_T DelayInput2_DSTATE_a;         /* '<S56>/Delay Input2' */
  real_T d1_DSTATE_e;                  /* '<S55>/d1' */
  real_T d_DSTATE_c;                   /* '<S55>/d' */
  real_T Delay1_DSTATE;                /* '<S8>/Delay1' */
  real_T DelayInput2_DSTATE_p;         /* '<S53>/Delay Input2' */
  real_T d1_DSTATE_p;                  /* '<S51>/d1' */
  real_T d_DSTATE_f;                   /* '<S51>/d' */
  real_T Delay2_DSTATE;                /* '<S8>/Delay2' */
  real_T d_DSTATE_cq;                  /* '<S73>/d' */
  real_T d1_DSTATE_f;                  /* '<S73>/d1' */
  real_T d1_DSTATE_ga;                 /* '<S74>/d1' */
  real_T d_DSTATE_h;                   /* '<S74>/d' */
  real_T d1_DSTATE_d;                  /* '<S75>/d1' */
  real_T d_DSTATE_p;                   /* '<S75>/d' */
  real_T Delay_DSTATE;                 /* '<S67>/Delay' */
  real_T d_DSTATE_fu;                  /* '<S71>/d' */
  real_T d1_DSTATE_fx;                 /* '<S71>/d1' */
  real_T d1_DSTATE_m;                  /* '<S72>/d1' */
  real_T d_DSTATE_m;                   /* '<S72>/d' */
  real_T DelayInput2_DSTATE_n;         /* '<S59>/Delay Input2' */
  real_T d1_DSTATE_k;                  /* '<S58>/d1' */
  real_T d_DSTATE_ow;                  /* '<S58>/d' */
  real_T current_f;                    /* '<S43>/MATLAB Function' */
  real_T next_f;                       /* '<S43>/MATLAB Function' */
  real_T current_mag;                  /* '<S43>/MATLAB Function' */
  real_T next_mag;                     /* '<S43>/MATLAB Function' */
  real_T t0;                           /* '<S43>/MATLAB Function' */
  real_T prev_phase;                   /* '<S43>/MATLAB Function' */
  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<Root>/Scope' */

  struct {
    void *TimePtr;
    void *DataPtr;
    void *RSimInfoPtr;
  } FromWorkspace_PWORK;               /* '<S39>/From Workspace' */

  struct {
    void *LoggedData;
  } Scope_PWORK_c;                     /* '<S5>/Scope' */

  struct {
    void *LoggedData;
  } ID_Target_Torque_PWORK;            /* '<S7>/ID_Target_Torque' */

  struct {
    void *LoggedData;
  } ID_idx_PWORK;                      /* '<S7>/ID_idx' */

  struct {
    void *LoggedData;
  } dri_ctrl_Total_PWORK;              /* '<S78>/dri_ctrl_Total' */

  struct {
    void *LoggedData;
  } dri_ctrl_FF_PWORK;                 /* '<S78>/dri_ctrl_FF' */

  struct {
    void *LoggedData;
  } dri_ctrl_dhat_PWORK;               /* '<S78>/dri_ctrl_dhat' */

  struct {
    void *LoggedData;
  } dri_ctrl_PID_PWORK;                /* '<S78>/dri_ctrl_PID' */

  struct {
    void *LoggedData;
  } str_pos_act_PWORK;                 /* '<S79>/str_pos_act' */

  struct {
    void *LoggedData;
  } sus_pos_act_PWORK;                 /* '<S79>/sus_pos_act' */

  struct {
    void *LoggedData;
  } dri_vel_act_PWORK;                 /* '<S79>/dri_vel_act' */

  struct {
    void *LoggedData;
  } dri_current_act_PWORK;             /* '<S79>/dri_current_act' */

  struct {
    void *LoggedData;
  } Sensor_wheel_torque_PWORK;         /* '<S79>/Sensor_wheel_torque' */

  struct {
    void *LoggedData;
  } str_load_torque_PWORK;             /* '<S79>/str_load_torque' */

  struct {
    void *LoggedData;
  } str_vel_act_PWORK;                 /* '<S79>/str_vel_act' */

  struct {
    void *LoggedData;
  } sus_current_act_PWORK;             /* '<S79>/sus_current_act' */

  struct {
    void *LoggedData;
  } str_current_act_PWORK;             /* '<S79>/str_current_act' */

  struct {
    void *LoggedData;
  } sus_load_torque_PWORK;             /* '<S79>/sus_load_torque' */

  struct {
    void *LoggedData;
  } Sensor_wheel_angacc_PWORK;         /* '<S79>/Sensor_wheel_angacc' */

  struct {
    void *LoggedData;
  } Sensor_wheel_angvel_PWORK;         /* '<S79>/Sensor_wheel_angvel' */

  struct {
    void *LoggedData;
  } dri_target_vel_PWORK;              /* '<S80>/dri_target_vel' */

  struct {
    void *LoggedData;
  } str_target_pos_PWORK;              /* '<S80>/str_target_pos' */

  struct {
    void *LoggedData;
  } sus_target_pos_PWORK;              /* '<S80>/sus_target_pos' */

  struct {
    void *LoggedData;
  } Acc_x_PWORK;                       /* '<S81>/Acc_x' */

  struct {
    void *LoggedData;
  } grf_x_PWORK;                       /* '<S81>/grf_x' */

  struct {
    void *LoggedData;
  } grf_y_PWORK;                       /* '<S81>/grf_y' */

  int_T SFunction1_IWORK[2];           /* '<S9>/S-Function1' */
  struct {
    int_T PrevIndex;
  } FromWorkspace_IWORK;               /* '<S39>/From Workspace' */

  int8_T If_ActiveSubsystem;           /* '<S87>/If' */
  boolean_T current_f_not_empty;       /* '<S43>/MATLAB Function' */
} DW_test_T;

/* Parameters for system: '<S87>/Torque Mode' */
struct P_TorqueMode_test_T_ {
  real_T Constant_Value;               /* Expression: 10
                                        * Referenced by: '<S89>/Constant'
                                        */
  real_T Constant1_Value;              /* Expression: 1
                                        * Referenced by: '<S89>/Constant1'
                                        */
};

/* Parameters (auto storage) */
struct P_test_T_ {
  real_T Ts;                           /* Variable: Ts
                                        * Referenced by:
                                        *   '<S8>/Gain'
                                        *   '<S8>/Gain1'
                                        *   '<S14>/gain'
                                        *   '<S16>/Constant'
                                        *   '<S16>/gain'
                                        *   '<S39>/Gain1'
                                        *   '<S58>/Constant'
                                        *   '<S58>/gain'
                                        *   '<S61>/Constant'
                                        *   '<S61>/gain'
                                        *   '<S69>/Constant1'
                                        *   '<S51>/Constant'
                                        *   '<S51>/gain'
                                        *   '<S55>/Constant'
                                        *   '<S55>/gain'
                                        *   '<S71>/gain'
                                        *   '<S72>/Constant'
                                        *   '<S72>/gain'
                                        *   '<S73>/gain'
                                        *   '<S74>/Constant'
                                        *   '<S74>/gain'
                                        *   '<S75>/gain'
                                        */
  real_T Constant3_Value;              /* Expression: 1
                                        * Referenced by: '<S39>/Constant3'
                                        */
  real_T Constant2_Value;              /* Expression: 0
                                        * Referenced by: '<S39>/Constant2'
                                        */
  real_T Constant1_Value;              /* Expression: 2*pi
                                        * Referenced by: '<S83>/Constant1'
                                        */
  real_T Constant5_Value;              /* Expression: 60
                                        * Referenced by: '<S83>/Constant5'
                                        */
  real_T N_dri_Value;                  /* Expression: 190
                                        * Referenced by: '<S83>/N_dri'
                                        */
  real_T Constant_Value;               /* Expression: 9
                                        * Referenced by: '<S91>/Constant'
                                        */
  real_T Saturation_UpperSat;          /* Expression: 0.5
                                        * Referenced by: '<Root>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: -0.5
                                        * Referenced by: '<Root>/Saturation'
                                        */
  real_T Constant_Value_j;             /* Expression: 1
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T NMT_CS_Value;                 /* Expression: 0
                                        * Referenced by: '<S8>/NMT_CS'
                                        */
  real_T NMT_Node_ID_Value;            /* Expression: 0
                                        * Referenced by: '<S8>/NMT_Node_ID'
                                        */
  real_T rpm2rad2_Gain;                /* Expression: 2*pi/60
                                        * Referenced by: '<S2>/rpm2rad2'
                                        */
  real_T N_dri_Value_o;                /* Expression: 190
                                        * Referenced by: '<S8>/N_dri'
                                        */
  real_T mA2A_Gain;                    /* Expression: 0.001
                                        * Referenced by: '<S2>/mA2A'
                                        */
  real_T MotortorqueConstant_Gain;     /* Expression: 51
                                        * Referenced by: '<S2>/Motor torque Constant'
                                        */
  real_T TorqueConstant1_Gain;         /* Expression: 0.001
                                        * Referenced by: '<S2>/Torque Constant1'
                                        */
  real_T mA2A2_Gain;                   /* Expression: 0.001
                                        * Referenced by: '<S2>/mA2A2'
                                        */
  real_T MotortorqueConstant1_Gain;    /* Expression: 51
                                        * Referenced by: '<S2>/Motor torque Constant1'
                                        */
  real_T TorqueConstant2_Gain;         /* Expression: 0.001
                                        * Referenced by: '<S2>/Torque Constant2'
                                        */
  real_T N_str_Value;                  /* Expression: 318
                                        * Referenced by: '<S8>/N_str'
                                        */
  real_T rpm2rad3_Gain;                /* Expression: 2*pi/60
                                        * Referenced by: '<S2>/rpm2rad3'
                                        */
  real_T mA2A1_Gain;                   /* Expression: 0.001
                                        * Referenced by: '<S2>/mA2A1'
                                        */
  real_T MotortorqueConstant2_Gain;    /* Expression: 13.7
                                        * Referenced by: '<S2>/Motor torque Constant2'
                                        */
  real_T TorqueConstant3_Gain;         /* Expression: 0.001
                                        * Referenced by: '<S2>/Torque Constant3'
                                        */
  real_T N_sus_Value;                  /* Expression: 756
                                        * Referenced by: '<S8>/N_sus'
                                        */
  real_T rpm2rad1_Gain;                /* Expression: 2*pi/60
                                        * Referenced by: '<S2>/rpm2rad1'
                                        */
  real_T d_InitialCondition;           /* Expression: 0
                                        * Referenced by: '<S14>/d'
                                        */
  real_T d1_InitialCondition;          /* Expression: 0
                                        * Referenced by: '<S14>/d1'
                                        */
  real_T Constant1_Value_a;            /* Expression: 1
                                        * Referenced by: '<S16>/Constant1'
                                        */
  real_T d1_InitialCondition_g;        /* Expression: 0
                                        * Referenced by: '<S16>/d1'
                                        */
  real_T Wheel_acc_cutoff_Value;       /* Expression: 100
                                        * Referenced by: '<S8>/Wheel_acc_cutoff'
                                        */
  real_T gain2_Gain;                   /* Expression: 2*pi
                                        * Referenced by: '<S16>/gain2'
                                        */
  real_T gain1_Gain;                   /* Expression: 2
                                        * Referenced by: '<S16>/gain1'
                                        */
  real_T d_InitialCondition_a;         /* Expression: 0
                                        * Referenced by: '<S16>/d'
                                        */
  real_T Sys_Ctrlword_Value;           /* Expression: 6
                                        * Referenced by: '<S8>/Sys_Ctrlword'
                                        */
  real_T SteeringInputMode_Value;      /* Expression: 8
                                        * Referenced by: '<S8>/Steering Input Mode'
                                        */
  real_T sus_pos_ref_ratelimit_Value;  /* Expression: 10
                                        * Referenced by: '<S8>/sus_pos_ref_ratelimit'
                                        */
  real_T sampletime_WtEt;              /* Computed Parameter: sampletime_WtEt
                                        * Referenced by: '<S62>/sample time'
                                        */
  real_T control_onoff_Value;          /* Expression: 0
                                        * Referenced by: '<S8>/control_on//off'
                                        */
  real_T Sus_Target_pos_Value;         /* Expression: 0
                                        * Referenced by: '<S42>/Sus_Target_pos'
                                        */
  real_T Saturation1_UpperSat;         /* Expression: 20
                                        * Referenced by: '<S42>/Saturation1'
                                        */
  real_T Saturation1_LowerSat;         /* Expression: -20
                                        * Referenced by: '<S42>/Saturation1'
                                        */
  real_T DelayInput2_InitialCondition; /* Expression: 0
                                        * Referenced by: '<S62>/Delay Input2'
                                        */
  real_T Gain_Gain;                    /* Expression: -1
                                        * Referenced by: '<S42>/Gain'
                                        */
  real_T d1_InitialCondition_f;        /* Expression: 0
                                        * Referenced by: '<S61>/d1'
                                        */
  real_T Constant1_Value_o;            /* Expression: 1
                                        * Referenced by: '<S61>/Constant1'
                                        */
  real_T sus_pos_ref_cutoff_Value;     /* Expression: 0.5
                                        * Referenced by: '<S8>/sus_pos_ref_cutoff'
                                        */
  real_T gain2_Gain_d;                 /* Expression: 2*pi
                                        * Referenced by: '<S61>/gain2'
                                        */
  real_T gain1_Gain_a;                 /* Expression: 2
                                        * Referenced by: '<S61>/gain1'
                                        */
  real_T d_InitialCondition_o;         /* Expression: 0
                                        * Referenced by: '<S61>/d'
                                        */
  real_T cpt_sus_Value;                /* Expression: 500*4
                                        * Referenced by: '<S8>/cpt_sus'
                                        */
  real_T Constant1_Value_h;            /* Expression: 360
                                        * Referenced by: '<S42>/Constant1'
                                        */
  real_T DrivingInputMode_Value;       /* Expression: 0
                                        * Referenced by: '<S8>/Driving Input Mode'
                                        */
  real_T Constant_Value_h;             /* Expression: 0
                                        * Referenced by: '<S40>/Constant'
                                        */
  real_T dri_vel_ref_ratelimit_Value;  /* Expression: 30
                                        * Referenced by: '<S8>/dri_vel_ref_ratelimit'
                                        */
  real_T sampletime_WtEt_j;            /* Computed Parameter: sampletime_WtEt_j
                                        * Referenced by: '<S56>/sample time'
                                        */
  real_T dri_target_vel_ref_Value;     /* Expression: 0
                                        * Referenced by: '<S8>/dri_target_vel_ref'
                                        */
  real_T Saturation2_UpperSat;         /* Expression: 10
                                        * Referenced by: '<S44>/Saturation2'
                                        */
  real_T Saturation2_LowerSat;         /* Expression: -10
                                        * Referenced by: '<S44>/Saturation2'
                                        */
  real_T DelayInput2_InitialCondition_d;/* Expression: 0
                                         * Referenced by: '<S56>/Delay Input2'
                                         */
  real_T Gain1_Gain;                   /* Expression: -1
                                        * Referenced by: '<S44>/Gain1'
                                        */
  real_T d1_InitialCondition_l;        /* Expression: 0
                                        * Referenced by: '<S55>/d1'
                                        */
  real_T Constant1_Value_n;            /* Expression: 1
                                        * Referenced by: '<S55>/Constant1'
                                        */
  real_T dri_vel_ref_cutoff_Value;     /* Expression: 1
                                        * Referenced by: '<S8>/dri_vel_ref_cutoff'
                                        */
  real_T gain2_Gain_a;                 /* Expression: 2*pi
                                        * Referenced by: '<S55>/gain2'
                                        */
  real_T gain1_Gain_k;                 /* Expression: 2
                                        * Referenced by: '<S55>/gain1'
                                        */
  real_T d_InitialCondition_p;         /* Expression: 0
                                        * Referenced by: '<S55>/d'
                                        */
  real_T Constant3_Value_m;            /* Expression: 360
                                        * Referenced by: '<S44>/Constant3'
                                        */
  real_T Constant2_Value_c;            /* Expression: 2*pi
                                        * Referenced by: '<S44>/Constant2'
                                        */
  real_T radius_Value;                 /* Expression: 0.15
                                        * Referenced by: '<S8>/radius'
                                        */
  real_T Constant4_Value;              /* Expression: 60/360
                                        * Referenced by: '<S44>/Constant4'
                                        */
  real_T Merge1_InitialOutput;         /* Computed Parameter: Merge1_InitialOutput
                                        * Referenced by: '<S87>/Merge1'
                                        */
  real_T Constant_Value_k;             /* Expression: 0
                                        * Referenced by: '<S43>/Constant'
                                        */
  real_T Delay1_InitialCondition;      /* Expression: 0
                                        * Referenced by: '<S8>/Delay1'
                                        */
  real_T dri_torque_ref_freq_Value;    /* Expression: 0.1
                                        * Referenced by: '<S8>/dri_torque_ref_freq'
                                        */
  real_T dri_torque_ref_mag_Value;     /* Expression: 0.01
                                        * Referenced by: '<S8>/dri_torque_ref_mag'
                                        */
  real_T sampletime_WtEt_m;            /* Computed Parameter: sampletime_WtEt_m
                                        * Referenced by: '<S53>/sample time'
                                        */
  real_T Saturation2_UpperSat_l;       /* Expression: 10
                                        * Referenced by: '<S43>/Saturation2'
                                        */
  real_T Saturation2_LowerSat_n;       /* Expression: -10
                                        * Referenced by: '<S43>/Saturation2'
                                        */
  real_T DelayInput2_InitialCondition_c;/* Expression: 0
                                         * Referenced by: '<S53>/Delay Input2'
                                         */
  real_T Gain1_Gain_m;                 /* Expression: -1
                                        * Referenced by: '<S43>/Gain1'
                                        */
  real_T d1_InitialCondition_lb;       /* Expression: 0
                                        * Referenced by: '<S51>/d1'
                                        */
  real_T Constant1_Value_d;            /* Expression: 1
                                        * Referenced by: '<S51>/Constant1'
                                        */
  real_T gain2_Gain_f;                 /* Expression: 2*pi
                                        * Referenced by: '<S51>/gain2'
                                        */
  real_T gain1_Gain_o;                 /* Expression: 2
                                        * Referenced by: '<S51>/gain1'
                                        */
  real_T d_InitialCondition_k;         /* Expression: 0
                                        * Referenced by: '<S51>/d'
                                        */
  real_T ID_OnOff_Value;               /* Expression: 0
                                        * Referenced by: '<S8>/ID_OnOff'
                                        */
  real_T Delay2_InitialCondition;      /* Expression: 0
                                        * Referenced by: '<S8>/Delay2'
                                        */
  real_T Constant1_Value_c;            /* Expression: 1
                                        * Referenced by: '<S39>/Constant1'
                                        */
  real_T Switch_Threshold;             /* Expression: 120
                                        * Referenced by: '<S39>/Switch'
                                        */
  real_T TorqueConstant_Gain;          /* Expression: 51
                                        * Referenced by: '<S39>/Torque Constant'
                                        */
  real_T Constant_Value_g;             /* Expression: 55.08
                                        * Referenced by: '<S39>/Constant'
                                        */
  real_T Gain_Gain_i;                  /* Expression: 1000
                                        * Referenced by: '<S39>/Gain'
                                        */
  real_T Constant_Value_ju;            /* Expression: 55.08
                                        * Referenced by: '<S70>/Constant'
                                        */
  real_T wheel_Jn_Value;               /* Expression: 0.4
                                        * Referenced by: '<S8>/wheel_Jn'
                                        */
  real_T dri_FF_OnOff_Value;           /* Expression: 0
                                        * Referenced by: '<S8>/dri_FF_OnOff'
                                        */
  real_T d_InitialCondition_c;         /* Expression: 0
                                        * Referenced by: '<S73>/d'
                                        */
  real_T d1_InitialCondition_i;        /* Expression: 0
                                        * Referenced by: '<S73>/d1'
                                        */
  real_T wheel_Bn_Value;               /* Expression: 2.016
                                        * Referenced by: '<S8>/wheel_Bn'
                                        */
  real_T d1_InitialCondition_gm;       /* Expression: 0
                                        * Referenced by: '<S74>/d1'
                                        */
  real_T Constant1_Value_k;            /* Expression: 1
                                        * Referenced by: '<S74>/Constant1'
                                        */
  real_T dri_FF_CutOff_Value;          /* Expression: 0.1
                                        * Referenced by: '<S8>/dri_FF_CutOff'
                                        */
  real_T gain2_Gain_n;                 /* Expression: 2*pi
                                        * Referenced by: '<S74>/gain2'
                                        */
  real_T gain1_Gain_e;                 /* Expression: 2
                                        * Referenced by: '<S74>/gain1'
                                        */
  real_T d_InitialCondition_j;         /* Expression: 0
                                        * Referenced by: '<S74>/d'
                                        */
  real_T dri_PID_zeta_Value;           /* Expression: 1
                                        * Referenced by: '<S8>/dri_PID_zeta'
                                        */
  real_T Saturation_UpperSat_c;        /* Expression: 3
                                        * Referenced by: '<S69>/Saturation'
                                        */
  real_T Saturation_LowerSat_e;        /* Expression: 0.5
                                        * Referenced by: '<S69>/Saturation'
                                        */
  real_T gain1_Gain_g;                 /* Expression: 2
                                        * Referenced by: '<S69>/gain 1'
                                        */
  real_T dri_PID_CutOff_Value;         /* Expression: 0.1
                                        * Referenced by: '<S8>/dri_PID_CutOff'
                                        */
  real_T gain_Gain;                    /* Expression: 2*pi
                                        * Referenced by: '<S69>/gain '
                                        */
  real_T dri_PID_OnOff_Value;          /* Expression: 0
                                        * Referenced by: '<S8>/dri_PID_OnOff'
                                        */
  real_T Constant_Value_n;             /* Expression: 0
                                        * Referenced by: '<S64>/Constant'
                                        */
  real_T d1_InitialCondition_a;        /* Expression: 0
                                        * Referenced by: '<S75>/d1'
                                        */
  real_T d_InitialCondition_m;         /* Expression: 0
                                        * Referenced by: '<S75>/d'
                                        */
  real_T Delay_InitialCondition;       /* Expression: 0
                                        * Referenced by: '<S67>/Delay'
                                        */
  real_T dri_DOB_OnOff_Value;          /* Expression: 0
                                        * Referenced by: '<S8>/dri_DOB_OnOff'
                                        */
  real_T d_InitialCondition_d;         /* Expression: 0
                                        * Referenced by: '<S71>/d'
                                        */
  real_T d1_InitialCondition_j;        /* Expression: 0
                                        * Referenced by: '<S71>/d1'
                                        */
  real_T d1_InitialCondition_c;        /* Expression: 0
                                        * Referenced by: '<S72>/d1'
                                        */
  real_T Constant1_Value_ax;           /* Expression: 1
                                        * Referenced by: '<S72>/Constant1'
                                        */
  real_T dri_DOB_CutOff_Value;         /* Expression: 0.1
                                        * Referenced by: '<S8>/dri_DOB_CutOff'
                                        */
  real_T gain2_Gain_m;                 /* Expression: 2*pi
                                        * Referenced by: '<S72>/gain2'
                                        */
  real_T gain1_Gain_an;                /* Expression: 2
                                        * Referenced by: '<S72>/gain1'
                                        */
  real_T d_InitialCondition_cw;        /* Expression: 0
                                        * Referenced by: '<S72>/d'
                                        */
  real_T Constant2_Value_p;            /* Expression: 190
                                        * Referenced by: '<S70>/Constant2'
                                        */
  real_T Constant1_Value_m;            /* Expression: 1000
                                        * Referenced by: '<S70>/Constant1'
                                        */
  real_T Gain1_Gain_f;                 /* Expression: -1
                                        * Referenced by: '<S70>/Gain1'
                                        */
  real_T Gain_Gain_c;                  /* Expression: 1000
                                        * Referenced by: '<S70>/Gain'
                                        */
  real_T str_pos_ref_ratelimit_Value;  /* Expression: 10
                                        * Referenced by: '<S8>/str_pos_ref_ratelimit'
                                        */
  real_T sampletime_WtEt_k;            /* Computed Parameter: sampletime_WtEt_k
                                        * Referenced by: '<S59>/sample time'
                                        */
  real_T Str_Target_pos_Value;         /* Expression: 0
                                        * Referenced by: '<S41>/Str_Target_pos'
                                        */
  real_T Saturation_UpperSat_b;        /* Expression: 20
                                        * Referenced by: '<S41>/Saturation'
                                        */
  real_T Saturation_LowerSat_j;        /* Expression: -20
                                        * Referenced by: '<S41>/Saturation'
                                        */
  real_T DelayInput2_InitialCondition_a;/* Expression: 0
                                         * Referenced by: '<S59>/Delay Input2'
                                         */
  real_T Gain_Gain_h;                  /* Expression: -1
                                        * Referenced by: '<S41>/Gain'
                                        */
  real_T d1_InitialCondition_p;        /* Expression: 0
                                        * Referenced by: '<S58>/d1'
                                        */
  real_T Constant1_Value_mn;           /* Expression: 1
                                        * Referenced by: '<S58>/Constant1'
                                        */
  real_T str_pos_ref_cutoff_Value;     /* Expression: 0.5
                                        * Referenced by: '<S8>/str_pos_ref_cutoff'
                                        */
  real_T gain2_Gain_g;                 /* Expression: 2*pi
                                        * Referenced by: '<S58>/gain2'
                                        */
  real_T gain1_Gain_f;                 /* Expression: 2
                                        * Referenced by: '<S58>/gain1'
                                        */
  real_T d_InitialCondition_mx;        /* Expression: 0
                                        * Referenced by: '<S58>/d'
                                        */
  real_T cpt_str_Value;                /* Expression: 2048*4
                                        * Referenced by: '<S8>/cpt_str'
                                        */
  real_T Constant_Value_l;             /* Expression: 360
                                        * Referenced by: '<S41>/Constant'
                                        */
  real_T Constant2_Value_i;            /* Expression: 360
                                        * Referenced by: '<S79>/Constant2'
                                        */
  real_T Constant3_Value_o;            /* Expression: 360
                                        * Referenced by: '<S79>/Constant3'
                                        */
  real_T Constant1_Value_e;            /* Expression: 0
                                        * Referenced by: '<S80>/Constant1'
                                        */
  real_T Constant2_Value_m;            /* Expression: 360
                                        * Referenced by: '<S80>/Constant2'
                                        */
  real_T Constant3_Value_b;            /* Expression: 360
                                        * Referenced by: '<S80>/Constant3'
                                        */
  real_T acc_bias_Value;               /* Expression: 0
                                        * Referenced by: '<S8>/acc_bias'
                                        */
  real_T Constant_Value_gq;            /* Expression: 300
                                        * Referenced by: '<S85>/Constant'
                                        */
  real_T V_Value;                      /* Expression: 0.0161
                                        * Referenced by: '<S85>/V'
                                        */
  real_T AmpleGain_Value;              /* Expression: 600
                                        * Referenced by: '<S85>/Ample Gain'
                                        */
  real_T Load_cell_Gain_Value;         /* Expression: 1
                                        * Referenced by: '<S8>/Load_cell_Gain'
                                        */
  real_T Grf_x_bias_Value;             /* Expression: 0
                                        * Referenced by: '<S8>/Grf_x_bias'
                                        */
  real_T Constant_Value_i;             /* Expression: 300
                                        * Referenced by: '<S86>/Constant'
                                        */
  real_T V_Value_d;                    /* Expression: 0.0161
                                        * Referenced by: '<S86>/V'
                                        */
  real_T AmpleGain_Value_n;            /* Expression: 600
                                        * Referenced by: '<S86>/Ample Gain'
                                        */
  real_T Grf_y_bias_Value;             /* Expression: 0
                                        * Referenced by: '<S8>/Grf_y_bias'
                                        */
  real_T Data_Logging_Value;           /* Expression: 0
                                        * Referenced by: '<S8>/Data_Logging'
                                        */
  real_T cpt_dri_Value;                /* Expression: 2048*4
                                        * Referenced by: '<S8>/cpt_dri'
                                        */
  uint32_T Delay1_DelayLength;         /* Computed Parameter: Delay1_DelayLength
                                        * Referenced by: '<S8>/Delay1'
                                        */
  uint32_T Delay2_DelayLength;         /* Computed Parameter: Delay2_DelayLength
                                        * Referenced by: '<S8>/Delay2'
                                        */
  uint32_T Delay_DelayLength;          /* Computed Parameter: Delay_DelayLength
                                        * Referenced by: '<S67>/Delay'
                                        */
  P_TorqueMode_test_T ID_Mode;         /* '<S87>/ID_Mode' */
  P_TorqueMode_test_T TorqueMode1;     /* '<S87>/Torque Mode1' */
  P_TorqueMode_test_T TorqueMode;      /* '<S87>/Torque Mode' */
};

/* Real-time Model Data Structure */
struct tag_RTM_test_T {
  const char_T *errorStatus;
  RTWSolverInfo solverInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Block parameters (auto storage) */
extern P_test_T test_P;

/* Block signals (auto storage) */
extern B_test_T test_B;

/* Block states (auto storage) */
extern DW_test_T test_DW;

/* Model entry point functions */
extern void test_initialize(void);
extern void test_output(void);
extern void test_update(void);
extern void test_terminate(void);

/* Real-time Model object */
extern RT_MODEL_test_T *const test_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'test'
 * '<S1>'   : 'test/Can Setting'
 * '<S2>'   : 'test/Hardware ActValue'
 * '<S3>'   : 'test/Plant'
 * '<S4>'   : 'test/RTI Data'
 * '<S5>'   : 'test/_Reference'
 * '<S6>'   : 'test/__Controller'
 * '<S7>'   : 'test/__Data Plotting'
 * '<S8>'   : 'test/__System_Setting'
 * '<S9>'   : 'test/Can Setting/CAN_TYPE1_SETUP_M1_C1'
 * '<S10>'  : 'test/Can Setting/NMTZeroMsg'
 * '<S11>'  : 'test/Hardware ActValue/ADC_TYPE4_BL1'
 * '<S12>'  : 'test/Hardware ActValue/ADC_TYPE4_BL2'
 * '<S13>'  : 'test/Hardware ActValue/ADC_TYPE4_BL3'
 * '<S14>'  : 'test/Hardware ActValue/Dot'
 * '<S15>'  : 'test/Hardware ActValue/Driving Motor RX'
 * '<S16>'  : 'test/Hardware ActValue/LPF'
 * '<S17>'  : 'test/Hardware ActValue/Sterring MotorRX'
 * '<S18>'  : 'test/Hardware ActValue/Suspension Motor RX'
 * '<S19>'  : 'test/Hardware ActValue/Driving Motor RX/N30_TPDO0'
 * '<S20>'  : 'test/Hardware ActValue/Driving Motor RX/N30_TPDO2'
 * '<S21>'  : 'test/Hardware ActValue/Driving Motor RX/N30_TPDO3'
 * '<S22>'  : 'test/Hardware ActValue/Sterring MotorRX/N10_TPDO0'
 * '<S23>'  : 'test/Hardware ActValue/Sterring MotorRX/N10_TPDO1'
 * '<S24>'  : 'test/Hardware ActValue/Sterring MotorRX/N10_TPDO2'
 * '<S25>'  : 'test/Hardware ActValue/Sterring MotorRX/N10_TPDO3'
 * '<S26>'  : 'test/Hardware ActValue/Suspension Motor RX/N20_TPDO0'
 * '<S27>'  : 'test/Hardware ActValue/Suspension Motor RX/N20_TPDO1'
 * '<S28>'  : 'test/Hardware ActValue/Suspension Motor RX/N20_TPDO2'
 * '<S29>'  : 'test/Hardware ActValue/Suspension Motor RX/N20_TPDO3'
 * '<S30>'  : 'test/Plant/N10_RPDO0'
 * '<S31>'  : 'test/Plant/N10_RPDO1'
 * '<S32>'  : 'test/Plant/N20_RPDO0'
 * '<S33>'  : 'test/Plant/N20_RPDO1'
 * '<S34>'  : 'test/Plant/N30_RPDO0'
 * '<S35>'  : 'test/Plant/N30_RPDO1'
 * '<S36>'  : 'test/RTI Data/RTI Data Store'
 * '<S37>'  : 'test/RTI Data/RTI Data Store/RTI Data Store'
 * '<S38>'  : 'test/RTI Data/RTI Data Store/RTI Data Store/RTI Data Store'
 * '<S39>'  : 'test/_Reference/_ID_ref'
 * '<S40>'  : 'test/_Reference/_dri_motor_ref'
 * '<S41>'  : 'test/_Reference/_str_motor_ref'
 * '<S42>'  : 'test/_Reference/_sus_motor_ref'
 * '<S43>'  : 'test/_Reference/_dri_motor_ref/Driving_Torque_Ref'
 * '<S44>'  : 'test/_Reference/_dri_motor_ref/Driving_Vel_Ref'
 * '<S45>'  : 'test/_Reference/_dri_motor_ref/If Action Subsystem1'
 * '<S46>'  : 'test/_Reference/_dri_motor_ref/If Action Subsystem2'
 * '<S47>'  : 'test/_Reference/_dri_motor_ref/If Action Subsystem3'
 * '<S48>'  : 'test/_Reference/_dri_motor_ref/Driving_Torque_Ref/If Action Subsystem1'
 * '<S49>'  : 'test/_Reference/_dri_motor_ref/Driving_Torque_Ref/If Action Subsystem2'
 * '<S50>'  : 'test/_Reference/_dri_motor_ref/Driving_Torque_Ref/If Action Subsystem3'
 * '<S51>'  : 'test/_Reference/_dri_motor_ref/Driving_Torque_Ref/LPF'
 * '<S52>'  : 'test/_Reference/_dri_motor_ref/Driving_Torque_Ref/MATLAB Function'
 * '<S53>'  : 'test/_Reference/_dri_motor_ref/Driving_Torque_Ref/Rate Limiter Dynamic1'
 * '<S54>'  : 'test/_Reference/_dri_motor_ref/Driving_Torque_Ref/Rate Limiter Dynamic1/Saturation Dynamic'
 * '<S55>'  : 'test/_Reference/_dri_motor_ref/Driving_Vel_Ref/LPF'
 * '<S56>'  : 'test/_Reference/_dri_motor_ref/Driving_Vel_Ref/Rate Limiter Dynamic1'
 * '<S57>'  : 'test/_Reference/_dri_motor_ref/Driving_Vel_Ref/Rate Limiter Dynamic1/Saturation Dynamic'
 * '<S58>'  : 'test/_Reference/_str_motor_ref/LPF1'
 * '<S59>'  : 'test/_Reference/_str_motor_ref/Rate Limiter Dynamic'
 * '<S60>'  : 'test/_Reference/_str_motor_ref/Rate Limiter Dynamic/Saturation Dynamic'
 * '<S61>'  : 'test/_Reference/_sus_motor_ref/LPF2'
 * '<S62>'  : 'test/_Reference/_sus_motor_ref/Rate Limiter Dynamic'
 * '<S63>'  : 'test/_Reference/_sus_motor_ref/Rate Limiter Dynamic/Saturation Dynamic'
 * '<S64>'  : 'test/__Controller/Driving Wheel Control'
 * '<S65>'  : 'test/__Controller/If Action Subsystem'
 * '<S66>'  : 'test/__Controller/If Action Subsystem1'
 * '<S67>'  : 'test/__Controller/Driving Wheel Control/DOB(omega)'
 * '<S68>'  : 'test/__Controller/Driving Wheel Control/Feedforward(omega)'
 * '<S69>'  : 'test/__Controller/Driving Wheel Control/Poleplacement(PI)1'
 * '<S70>'  : 'test/__Controller/Driving Wheel Control/Subsystem'
 * '<S71>'  : 'test/__Controller/Driving Wheel Control/DOB(omega)/Dot2'
 * '<S72>'  : 'test/__Controller/Driving Wheel Control/DOB(omega)/LPF'
 * '<S73>'  : 'test/__Controller/Driving Wheel Control/Feedforward(omega)/Dot2'
 * '<S74>'  : 'test/__Controller/Driving Wheel Control/Feedforward(omega)/LPF'
 * '<S75>'  : 'test/__Controller/Driving Wheel Control/Poleplacement(PI)1/Integrator1'
 * '<S76>'  : 'test/__Controller/Driving Wheel Control/Poleplacement(PI)1/Saturation Dynamic'
 * '<S77>'  : 'test/__Controller/Driving Wheel Control/Subsystem/Saturation Dynamic'
 * '<S78>'  : 'test/__Data Plotting/__Drive_Ctrl_Plot'
 * '<S79>'  : 'test/__Data Plotting/__Motor_Feedback_Plot'
 * '<S80>'  : 'test/__Data Plotting/__Reference_Plot'
 * '<S81>'  : 'test/__Data Plotting/__Sensor_Plot'
 * '<S82>'  : 'test/__Data Plotting/__Reference_Plot/If Action Subsystem4'
 * '<S83>'  : 'test/__Data Plotting/__Reference_Plot/If Action Subsystem5'
 * '<S84>'  : 'test/__Data Plotting/__Reference_Plot/If Action Subsystem6'
 * '<S85>'  : 'test/__Data Plotting/__Sensor_Plot/Subsystem'
 * '<S86>'  : 'test/__Data Plotting/__Sensor_Plot/Subsystem1'
 * '<S87>'  : 'test/__System_Setting/Subsystem'
 * '<S88>'  : 'test/__System_Setting/Subsystem/ID_Mode'
 * '<S89>'  : 'test/__System_Setting/Subsystem/Torque Mode'
 * '<S90>'  : 'test/__System_Setting/Subsystem/Torque Mode1'
 * '<S91>'  : 'test/__System_Setting/Subsystem/Velocity Mode'
 */
#endif                                 /* RTW_HEADER_test_h_ */
