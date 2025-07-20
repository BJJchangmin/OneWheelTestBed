/*
 * test.h
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
  real_T Merge;                        /* '<S102>/Merge' */
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
  real_T Merge1;                       /* '<S102>/Merge1' */
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
  real_T Divide1_ad;                   /* '<S77>/Divide1' */
  real_T d_l;                          /* '<S82>/d' */
  real_T Sum2_i;                       /* '<S82>/Sum2' */
  real_T gain_gx;                      /* '<S82>/gain' */
  real_T d1_p;                         /* '<S82>/d1' */
  real_T Sum1_i2;                      /* '<S82>/Sum1' */
  real_T Divide2_n;                    /* '<S77>/Divide2' */
  real_T Divide4_c;                    /* '<S77>/Divide4' */
  real_T Add5;                         /* '<S77>/Add5' */
  real_T d1_hw;                        /* '<S83>/d1' */
  real_T Sum3_p;                       /* '<S83>/Sum3' */
  real_T gain_n;                       /* '<S83>/gain' */
  real_T gain2_d;                      /* '<S83>/gain2' */
  real_T Product2_h;                   /* '<S83>/Product2' */
  real_T gain1_f;                      /* '<S83>/gain1' */
  real_T Sum1_h;                       /* '<S83>/Sum1' */
  real_T d_p;                          /* '<S83>/d' */
  real_T Product11_j;                  /* '<S83>/Product11' */
  real_T Sum2_e;                       /* '<S83>/Sum2' */
  real_T Sum4_a;                       /* '<S83>/Sum4' */
  real_T Product1_p;                   /* '<S83>/Product1' */
  real_T Divide_n;                     /* '<S77>/Divide' */
  real_T Saturation_c;                 /* '<S78>/Saturation' */
  real_T gain1_l0;                     /* '<S78>/gain 1' */
  real_T gain_o;                       /* '<S78>/gain ' */
  real_T Divide6;                      /* '<S78>/Divide6' */
  real_T Add1_b;                       /* '<S78>/Add1' */
  real_T Add1_p;                       /* '<S65>/Add1' */
  real_T Divide_m;                     /* '<S78>/Divide' */
  real_T Divide1_m;                    /* '<S78>/Divide1' */
  real_T Divide3_m;                    /* '<S78>/Divide3' */
  real_T Divide4_n;                    /* '<S78>/Divide4' */
  real_T Add_i;                        /* '<S78>/Add' */
  real_T Switch_h;                     /* '<S85>/Switch' */
  real_T Switch2_g;                    /* '<S85>/Switch2' */
  real_T Divide9;                      /* '<S78>/Divide9' */
  real_T Divide7;                      /* '<S78>/Divide7' */
  real_T Sum2_h;                       /* '<S78>/Sum2' */
  real_T d1_n;                         /* '<S84>/d1' */
  real_T Sum1_f;                       /* '<S84>/Sum1' */
  real_T gain_a;                       /* '<S84>/gain' */
  real_T d_b;                          /* '<S84>/d' */
  real_T Sum2_p;                       /* '<S84>/Sum2' */
  real_T Divide2_c;                    /* '<S78>/Divide2' */
  real_T Sum1_a;                       /* '<S78>/Sum1' */
  real_T Divide5;                      /* '<S78>/Divide5' */
  real_T Delay;                        /* '<S76>/Delay' */
  real_T Divide5_a;                    /* '<S76>/Divide5' */
  real_T Divide1_l;                    /* '<S76>/Divide1' */
  real_T d_o;                          /* '<S80>/d' */
  real_T Sum2_g;                       /* '<S80>/Sum2' */
  real_T gain_fg;                      /* '<S80>/gain' */
  real_T d1_h0;                        /* '<S80>/d1' */
  real_T Sum1_is;                      /* '<S80>/Sum1' */
  real_T Divide2_j;                    /* '<S76>/Divide2' */
  real_T Divide4_i;                    /* '<S76>/Divide4' */
  real_T Add2;                         /* '<S76>/Add2' */
  real_T Add1_g;                       /* '<S76>/Add1' */
  real_T d1_i;                         /* '<S81>/d1' */
  real_T Sum3_k;                       /* '<S81>/Sum3' */
  real_T gain_ff;                      /* '<S81>/gain' */
  real_T gain2_p;                      /* '<S81>/gain2' */
  real_T Product2_e;                   /* '<S81>/Product2' */
  real_T gain1_p;                      /* '<S81>/gain1' */
  real_T Sum1_e;                       /* '<S81>/Sum1' */
  real_T d_n;                          /* '<S81>/d' */
  real_T Product11_i;                  /* '<S81>/Product11' */
  real_T Sum2_c;                       /* '<S81>/Sum2' */
  real_T Sum4_m;                       /* '<S81>/Sum4' */
  real_T Product1_l5;                  /* '<S81>/Product1' */
  real_T Divide6_e;                    /* '<S76>/Divide6' */
  real_T Add_j;                        /* '<S65>/Add' */
  real_T Divide3_i;                    /* '<S79>/Divide3' */
  real_T Divide1_g;                    /* '<S79>/Divide1' */
  real_T Gain1_o;                      /* '<S79>/Gain1' */
  real_T Switch_b;                     /* '<S86>/Switch' */
  real_T Switch2_b;                    /* '<S86>/Switch2' */
  real_T Divide_i;                     /* '<S79>/Divide' */
  real_T Gain_f;                       /* '<S79>/Gain' */
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
  real_T Saturation_nv;                /* '<S69>/Saturation' */
  real_T gain1_h;                      /* '<S69>/gain 1' */
  real_T gain_km;                      /* '<S69>/gain ' */
  real_T Divide6_ek;                   /* '<S69>/Divide6' */
  real_T Add1_n;                       /* '<S69>/Add1' */
  real_T Product1_pl;                  /* '<S6>/Product1' */
  real_T Add1_j;                       /* '<S6>/Add1' */
  real_T Divide_b;                     /* '<S69>/Divide' */
  real_T Divide1_lp;                   /* '<S69>/Divide1' */
  real_T Divide3_b;                    /* '<S69>/Divide3' */
  real_T Divide4_j;                    /* '<S69>/Divide4' */
  real_T Add_l;                        /* '<S69>/Add' */
  real_T Switch_b3;                    /* '<S90>/Switch' */
  real_T Switch2_bs;                   /* '<S90>/Switch2' */
  real_T Divide9_h;                    /* '<S69>/Divide9' */
  real_T Divide7_p;                    /* '<S69>/Divide7' */
  real_T Sum2_f;                       /* '<S69>/Sum2' */
  real_T d1_f;                         /* '<S89>/d1' */
  real_T Sum1_p;                       /* '<S89>/Sum1' */
  real_T gain_os;                      /* '<S89>/gain' */
  real_T d_j;                          /* '<S89>/d' */
  real_T Sum2_a;                       /* '<S89>/Sum2' */
  real_T Divide2_g;                    /* '<S69>/Divide2' */
  real_T Sum1_g;                       /* '<S69>/Sum1' */
  real_T Divide5_p;                    /* '<S69>/Divide5' */
  real_T Divide3_c;                    /* '<S70>/Divide3' */
  real_T Divide1_o;                    /* '<S70>/Divide1' */
  real_T Gain1_j;                      /* '<S70>/Gain1' */
  real_T Switch_c;                     /* '<S91>/Switch' */
  real_T Switch2_n;                    /* '<S91>/Switch2' */
  real_T Divide_bg;                    /* '<S70>/Divide' */
  real_T Gain_j;                       /* '<S70>/Gain' */
  real_T Add2_f;                       /* '<S6>/Add2' */
  real_T SFunction1_o1_e;              /* '<S31>/S-Function1' */
  real_T SFunction1_o2_iy;             /* '<S31>/S-Function1' */
  real_T SFunction1_o3_o;              /* '<S31>/S-Function1' */
  real_T SFunction1_o4_lg;             /* '<S31>/S-Function1' */
  real_T Divide_a;                     /* '<S89>/Divide' */
  real_T Add5_l;                       /* '<S6>/Add5' */
  real_T Constant1;                    /* '<S6>/Constant1' */
  real_T Divide1_li;                   /* '<S6>/Divide1' */
  real_T Divide_k;                     /* '<S84>/Divide' */
  real_T Product_cn;                   /* '<S94>/Product' */
  real_T Product1_c;                   /* '<S94>/Product1' */
  real_T Product2_j;                   /* '<S94>/Product2' */
  real_T Product3_j;                   /* '<S94>/Product3' */
  real_T Product4_e;                   /* '<S94>/Product4' */
  real_T Product5_c;                   /* '<S94>/Product5' */
  real_T Merge2;                       /* '<S95>/Merge2' */
  real_T Product_o;                    /* '<S95>/Product' */
  real_T Product1_fn;                  /* '<S95>/Product1' */
  real_T Product2_kc;                  /* '<S95>/Product2' */
  real_T Product3_d;                   /* '<S95>/Product3' */
  real_T Product4_ej;                  /* '<S95>/Product4' */
  real_T Product5_e;                   /* '<S95>/Product5' */
  real_T Add_k;                        /* '<S96>/Add' */
  real_T Divide2_d;                    /* '<S100>/Divide2' */
  real_T Divide1_h;                    /* '<S100>/Divide1' */
  real_T Divide3_d;                    /* '<S100>/Divide3' */
  real_T Divide4_p;                    /* '<S100>/Divide4' */
  real_T Add1_i;                       /* '<S96>/Add1' */
  real_T Divide2_n5;                   /* '<S101>/Divide2' */
  real_T Divide1_g2;                   /* '<S101>/Divide1' */
  real_T Divide3_p;                    /* '<S101>/Divide3' */
  real_T Divide5_e;                    /* '<S101>/Divide5' */
  real_T Add2_c;                       /* '<S96>/Add2' */
  real_T Data_Logging;                 /* '<S8>/Data_Logging' */
  real_T cpt_dri;                      /* '<S8>/cpt_dri' */
  real_T str_DOB_OnOff;                /* '<S8>/str_DOB_OnOff' */
  real_T str_DOB_CutOff;               /* '<S8>/str_DOB_CutOff' */
  real_T Product_i;                    /* '<S98>/Product' */
  real_T Product1_cu;                  /* '<S98>/Product1' */
  real_T y;                            /* '<S43>/MATLAB Function' */
  boolean_T LowerRelop1;               /* '<S63>/LowerRelop1' */
  boolean_T UpperRelop;                /* '<S63>/UpperRelop' */
  boolean_T LowerRelop1_g;             /* '<S57>/LowerRelop1' */
  boolean_T UpperRelop_b;              /* '<S57>/UpperRelop' */
  boolean_T LowerRelop1_j;             /* '<S54>/LowerRelop1' */
  boolean_T UpperRelop_a;              /* '<S54>/UpperRelop' */
  boolean_T LowerRelop1_e;             /* '<S85>/LowerRelop1' */
  boolean_T UpperRelop_g;              /* '<S85>/UpperRelop' */
  boolean_T LowerRelop1_a;             /* '<S86>/LowerRelop1' */
  boolean_T UpperRelop_m;              /* '<S86>/UpperRelop' */
  boolean_T LowerRelop1_o;             /* '<S60>/LowerRelop1' */
  boolean_T UpperRelop_j;              /* '<S60>/UpperRelop' */
  boolean_T LowerRelop1_b;             /* '<S90>/LowerRelop1' */
  boolean_T UpperRelop_ab;             /* '<S90>/UpperRelop' */
  boolean_T LowerRelop1_m;             /* '<S91>/LowerRelop1' */
  boolean_T UpperRelop_my;             /* '<S91>/UpperRelop' */
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
  real_T d_DSTATE_cq;                  /* '<S82>/d' */
  real_T d1_DSTATE_f;                  /* '<S82>/d1' */
  real_T d1_DSTATE_ga;                 /* '<S83>/d1' */
  real_T d_DSTATE_h;                   /* '<S83>/d' */
  real_T d1_DSTATE_d;                  /* '<S84>/d1' */
  real_T d_DSTATE_p;                   /* '<S84>/d' */
  real_T Delay_DSTATE;                 /* '<S76>/Delay' */
  real_T d_DSTATE_fu;                  /* '<S80>/d' */
  real_T d1_DSTATE_fx;                 /* '<S80>/d1' */
  real_T d1_DSTATE_m;                  /* '<S81>/d1' */
  real_T d_DSTATE_m;                   /* '<S81>/d' */
  real_T DelayInput2_DSTATE_n;         /* '<S59>/Delay Input2' */
  real_T d1_DSTATE_k;                  /* '<S58>/d1' */
  real_T d_DSTATE_ow;                  /* '<S58>/d' */
  real_T d1_DSTATE_j;                  /* '<S89>/d1' */
  real_T d_DSTATE_n;                   /* '<S89>/d' */
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
  } Closed_ID_Toruqe_PWORK;            /* '<S6>/Closed_ID_Toruqe' */

  struct {
    void *LoggedData;
  } ID_Target_Torque_PWORK;            /* '<S7>/ID_Target_Torque' */

  struct {
    void *LoggedData;
  } ID_idx_PWORK;                      /* '<S7>/ID_idx' */

  struct {
    void *LoggedData;
  } dri_ctrl_Total_PWORK;              /* '<S93>/dri_ctrl_Total' */

  struct {
    void *LoggedData;
  } dri_ctrl_FF_PWORK;                 /* '<S93>/dri_ctrl_FF' */

  struct {
    void *LoggedData;
  } dri_ctrl_dhat_PWORK;               /* '<S93>/dri_ctrl_dhat' */

  struct {
    void *LoggedData;
  } dri_ctrl_PID_PWORK;                /* '<S93>/dri_ctrl_PID' */

  struct {
    void *LoggedData;
  } str_pos_act_PWORK;                 /* '<S94>/str_pos_act' */

  struct {
    void *LoggedData;
  } sus_pos_act_PWORK;                 /* '<S94>/sus_pos_act' */

  struct {
    void *LoggedData;
  } dri_vel_act_PWORK;                 /* '<S94>/dri_vel_act' */

  struct {
    void *LoggedData;
  } dri_current_act_PWORK;             /* '<S94>/dri_current_act' */

  struct {
    void *LoggedData;
  } Sensor_wheel_torque_PWORK;         /* '<S94>/Sensor_wheel_torque' */

  struct {
    void *LoggedData;
  } str_load_torque_PWORK;             /* '<S94>/str_load_torque' */

  struct {
    void *LoggedData;
  } str_vel_act_PWORK;                 /* '<S94>/str_vel_act' */

  struct {
    void *LoggedData;
  } sus_current_act_PWORK;             /* '<S94>/sus_current_act' */

  struct {
    void *LoggedData;
  } str_current_act_PWORK;             /* '<S94>/str_current_act' */

  struct {
    void *LoggedData;
  } sus_load_torque_PWORK;             /* '<S94>/sus_load_torque' */

  struct {
    void *LoggedData;
  } Sensor_wheel_angacc_PWORK;         /* '<S94>/Sensor_wheel_angacc' */

  struct {
    void *LoggedData;
  } Sensor_wheel_angvel_PWORK;         /* '<S94>/Sensor_wheel_angvel' */

  struct {
    void *LoggedData;
  } dri_target_vel_PWORK;              /* '<S95>/dri_target_vel' */

  struct {
    void *LoggedData;
  } str_target_pos_PWORK;              /* '<S95>/str_target_pos' */

  struct {
    void *LoggedData;
  } sus_target_pos_PWORK;              /* '<S95>/sus_target_pos' */

  struct {
    void *LoggedData;
  } Acc_x_PWORK;                       /* '<S96>/Acc_x' */

  struct {
    void *LoggedData;
  } grf_x_PWORK;                       /* '<S96>/grf_x' */

  struct {
    void *LoggedData;
  } grf_y_PWORK;                       /* '<S96>/grf_y' */

  int_T SFunction1_IWORK[2];           /* '<S9>/S-Function1' */
  struct {
    int_T PrevIndex;
  } FromWorkspace_IWORK;               /* '<S39>/From Workspace' */

  int8_T If_ActiveSubsystem;           /* '<S102>/If' */
  boolean_T current_f_not_empty;       /* '<S43>/MATLAB Function' */
} DW_test_T;

/* Parameters for system: '<S102>/Torque Mode' */
struct P_TorqueMode_test_T_ {
  real_T Constant_Value;               /* Expression: 10
                                        * Referenced by: '<S104>/Constant'
                                        */
  real_T Constant1_Value;              /* Expression: 1
                                        * Referenced by: '<S104>/Constant1'
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
  real_T Constant3_Value;              /* Expression: 1
                                        * Referenced by: '<S39>/Constant3'
                                        */
  real_T Constant2_Value;              /* Expression: 0
                                        * Referenced by: '<S39>/Constant2'
                                        */
  real_T Constant1_Value;              /* Expression: 2*pi
                                        * Referenced by: '<S98>/Constant1'
                                        */
  real_T Constant5_Value;              /* Expression: 60
                                        * Referenced by: '<S98>/Constant5'
                                        */
  real_T N_dri_Value;                  /* Expression: 190
                                        * Referenced by: '<S98>/N_dri'
                                        */
  real_T Constant_Value;               /* Expression: 9
                                        * Referenced by: '<S106>/Constant'
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
                                        * Referenced by: '<S102>/Merge1'
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
  real_T dri_torque_ref_mag_Value;     /* Expression: 0
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
                                        * Referenced by: '<S79>/Constant'
                                        */
  real_T wheel_Jn_Value;               /* Expression: 0.4
                                        * Referenced by: '<S8>/wheel_Jn'
                                        */
  real_T dri_FF_OnOff_Value;           /* Expression: 0
                                        * Referenced by: '<S8>/dri_FF_OnOff'
                                        */
  real_T d_InitialCondition_c;         /* Expression: 0
                                        * Referenced by: '<S82>/d'
                                        */
  real_T d1_InitialCondition_i;        /* Expression: 0
                                        * Referenced by: '<S82>/d1'
                                        */
  real_T wheel_Bn_Value;               /* Expression: 2.016
                                        * Referenced by: '<S8>/wheel_Bn'
                                        */
  real_T d1_InitialCondition_gm;       /* Expression: 0
                                        * Referenced by: '<S83>/d1'
                                        */
  real_T Constant1_Value_k;            /* Expression: 1
                                        * Referenced by: '<S83>/Constant1'
                                        */
  real_T dri_FF_CutOff_Value;          /* Expression: 0.1
                                        * Referenced by: '<S8>/dri_FF_CutOff'
                                        */
  real_T gain2_Gain_n;                 /* Expression: 2*pi
                                        * Referenced by: '<S83>/gain2'
                                        */
  real_T gain1_Gain_e;                 /* Expression: 2
                                        * Referenced by: '<S83>/gain1'
                                        */
  real_T d_InitialCondition_j;         /* Expression: 0
                                        * Referenced by: '<S83>/d'
                                        */
  real_T dri_PID_zeta_Value;           /* Expression: 1
                                        * Referenced by: '<S8>/dri_PID_zeta'
                                        */
  real_T Saturation_UpperSat_c;        /* Expression: 3
                                        * Referenced by: '<S78>/Saturation'
                                        */
  real_T Saturation_LowerSat_e;        /* Expression: 0.5
                                        * Referenced by: '<S78>/Saturation'
                                        */
  real_T gain1_Gain_g;                 /* Expression: 2
                                        * Referenced by: '<S78>/gain 1'
                                        */
  real_T dri_PID_CutOff_Value;         /* Expression: 0.1
                                        * Referenced by: '<S8>/dri_PID_CutOff'
                                        */
  real_T gain_Gain;                    /* Expression: 2*pi
                                        * Referenced by: '<S78>/gain '
                                        */
  real_T dri_PID_OnOff_Value;          /* Expression: 0
                                        * Referenced by: '<S8>/dri_PID_OnOff'
                                        */
  real_T Constant_Value_n;             /* Expression: 0
                                        * Referenced by: '<S65>/Constant'
                                        */
  real_T d1_InitialCondition_a;        /* Expression: 0
                                        * Referenced by: '<S84>/d1'
                                        */
  real_T d_InitialCondition_m;         /* Expression: 0
                                        * Referenced by: '<S84>/d'
                                        */
  real_T Delay_InitialCondition;       /* Expression: 0
                                        * Referenced by: '<S76>/Delay'
                                        */
  real_T dri_DOB_OnOff_Value;          /* Expression: 0
                                        * Referenced by: '<S8>/dri_DOB_OnOff'
                                        */
  real_T d_InitialCondition_d;         /* Expression: 0
                                        * Referenced by: '<S80>/d'
                                        */
  real_T d1_InitialCondition_j;        /* Expression: 0
                                        * Referenced by: '<S80>/d1'
                                        */
  real_T d1_InitialCondition_c;        /* Expression: 0
                                        * Referenced by: '<S81>/d1'
                                        */
  real_T Constant1_Value_ax;           /* Expression: 1
                                        * Referenced by: '<S81>/Constant1'
                                        */
  real_T dri_DOB_CutOff_Value;         /* Expression: 0.1
                                        * Referenced by: '<S8>/dri_DOB_CutOff'
                                        */
  real_T gain2_Gain_m;                 /* Expression: 2*pi
                                        * Referenced by: '<S81>/gain2'
                                        */
  real_T gain1_Gain_an;                /* Expression: 2
                                        * Referenced by: '<S81>/gain1'
                                        */
  real_T d_InitialCondition_cw;        /* Expression: 0
                                        * Referenced by: '<S81>/d'
                                        */
  real_T Constant2_Value_p;            /* Expression: 190
                                        * Referenced by: '<S79>/Constant2'
                                        */
  real_T Constant1_Value_m;            /* Expression: 1000
                                        * Referenced by: '<S79>/Constant1'
                                        */
  real_T Gain1_Gain_f;                 /* Expression: -1
                                        * Referenced by: '<S79>/Gain1'
                                        */
  real_T Gain_Gain_c;                  /* Expression: 1000
                                        * Referenced by: '<S79>/Gain'
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
  real_T Constant_Value_a;             /* Expression: 55.08
                                        * Referenced by: '<S70>/Constant'
                                        */
  real_T str_PID_zeta_Value;           /* Expression: 1
                                        * Referenced by: '<S8>/str_PID_zeta'
                                        */
  real_T Saturation_UpperSat_h;        /* Expression: 3
                                        * Referenced by: '<S69>/Saturation'
                                        */
  real_T Saturation_LowerSat_o;        /* Expression: 0.5
                                        * Referenced by: '<S69>/Saturation'
                                        */
  real_T gain1_Gain_fa;                /* Expression: 2
                                        * Referenced by: '<S69>/gain 1'
                                        */
  real_T str_PID_CutOff_Value;         /* Expression: 0.1
                                        * Referenced by: '<S8>/str_PID_CutOff'
                                        */
  real_T gain_Gain_l;                  /* Expression: 2*pi
                                        * Referenced by: '<S69>/gain '
                                        */
  real_T steer_Jn_Value;               /* Expression: 2.64
                                        * Referenced by: '<S8>/steer_Jn'
                                        */
  real_T steer_Bn_Value;               /* Expression: 18.5
                                        * Referenced by: '<S8>/steer_Bn'
                                        */
  real_T str_PID_OnOff_Value;          /* Expression: 0
                                        * Referenced by: '<S8>/str_PID_OnOff'
                                        */
  real_T d1_InitialCondition_h;        /* Expression: 0
                                        * Referenced by: '<S89>/d1'
                                        */
  real_T d_InitialCondition_h;         /* Expression: 0
                                        * Referenced by: '<S89>/d'
                                        */
  real_T Constant2_Value_i;            /* Expression: 315
                                        * Referenced by: '<S70>/Constant2'
                                        */
  real_T Constant1_Value_axs;          /* Expression: 1000
                                        * Referenced by: '<S70>/Constant1'
                                        */
  real_T Gain1_Gain_l;                 /* Expression: -1
                                        * Referenced by: '<S70>/Gain1'
                                        */
  real_T Gain_Gain_k;                  /* Expression: 1000
                                        * Referenced by: '<S70>/Gain'
                                        */
  real_T Constant1_Value_l;            /* Expression: 1000
                                        * Referenced by: '<S6>/Constant1'
                                        */
  real_T Constant2_Value_il;           /* Expression: 360
                                        * Referenced by: '<S94>/Constant2'
                                        */
  real_T Constant3_Value_o;            /* Expression: 360
                                        * Referenced by: '<S94>/Constant3'
                                        */
  real_T Constant1_Value_e;            /* Expression: 0
                                        * Referenced by: '<S95>/Constant1'
                                        */
  real_T Constant2_Value_m;            /* Expression: 360
                                        * Referenced by: '<S95>/Constant2'
                                        */
  real_T Constant3_Value_b;            /* Expression: 360
                                        * Referenced by: '<S95>/Constant3'
                                        */
  real_T acc_bias_Value;               /* Expression: 0
                                        * Referenced by: '<S8>/acc_bias'
                                        */
  real_T Constant_Value_gq;            /* Expression: 300
                                        * Referenced by: '<S100>/Constant'
                                        */
  real_T V_Value;                      /* Expression: 0.0161
                                        * Referenced by: '<S100>/V'
                                        */
  real_T AmpleGain_Value;              /* Expression: 600
                                        * Referenced by: '<S100>/Ample Gain'
                                        */
  real_T Load_cell_Gain_Value;         /* Expression: 1
                                        * Referenced by: '<S8>/Load_cell_Gain'
                                        */
  real_T Grf_x_bias_Value;             /* Expression: 0
                                        * Referenced by: '<S8>/Grf_x_bias'
                                        */
  real_T Constant_Value_i;             /* Expression: 300
                                        * Referenced by: '<S101>/Constant'
                                        */
  real_T V_Value_d;                    /* Expression: 0.0161
                                        * Referenced by: '<S101>/V'
                                        */
  real_T AmpleGain_Value_n;            /* Expression: 600
                                        * Referenced by: '<S101>/Ample Gain'
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
  real_T str_DOB_OnOff_Value;          /* Expression: 0
                                        * Referenced by: '<S8>/str_DOB_OnOff'
                                        */
  real_T str_DOB_CutOff_Value;         /* Expression: 0
                                        * Referenced by: '<S8>/str_DOB_CutOff'
                                        */
  uint32_T Delay1_DelayLength;         /* Computed Parameter: Delay1_DelayLength
                                        * Referenced by: '<S8>/Delay1'
                                        */
  uint32_T Delay2_DelayLength;         /* Computed Parameter: Delay2_DelayLength
                                        * Referenced by: '<S8>/Delay2'
                                        */
  uint32_T Delay_DelayLength;          /* Computed Parameter: Delay_DelayLength
                                        * Referenced by: '<S76>/Delay'
                                        */
  P_TorqueMode_test_T ID_Mode;         /* '<S102>/ID_Mode' */
  P_TorqueMode_test_T TorqueMode1;     /* '<S102>/Torque Mode1' */
  P_TorqueMode_test_T TorqueMode;      /* '<S102>/Torque Mode' */
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
 * '<S64>'  : 'test/__Controller/DOB(theta)'
 * '<S65>'  : 'test/__Controller/Driving Wheel Control'
 * '<S66>'  : 'test/__Controller/If Action Subsystem'
 * '<S67>'  : 'test/__Controller/If Action Subsystem1'
 * '<S68>'  : 'test/__Controller/Lag compensator(zeta)'
 * '<S69>'  : 'test/__Controller/Poleplacement(PI)1'
 * '<S70>'  : 'test/__Controller/Steering system'
 * '<S71>'  : 'test/__Controller/Subsystem1'
 * '<S72>'  : 'test/__Controller/DOB(theta)/Dot'
 * '<S73>'  : 'test/__Controller/DOB(theta)/Dot1'
 * '<S74>'  : 'test/__Controller/DOB(theta)/Dot2'
 * '<S75>'  : 'test/__Controller/DOB(theta)/Second order LPF'
 * '<S76>'  : 'test/__Controller/Driving Wheel Control/DOB(omega)'
 * '<S77>'  : 'test/__Controller/Driving Wheel Control/Feedforward(omega)'
 * '<S78>'  : 'test/__Controller/Driving Wheel Control/Poleplacement(PI)1'
 * '<S79>'  : 'test/__Controller/Driving Wheel Control/Subsystem'
 * '<S80>'  : 'test/__Controller/Driving Wheel Control/DOB(omega)/Dot2'
 * '<S81>'  : 'test/__Controller/Driving Wheel Control/DOB(omega)/LPF'
 * '<S82>'  : 'test/__Controller/Driving Wheel Control/Feedforward(omega)/Dot2'
 * '<S83>'  : 'test/__Controller/Driving Wheel Control/Feedforward(omega)/LPF'
 * '<S84>'  : 'test/__Controller/Driving Wheel Control/Poleplacement(PI)1/Integrator1'
 * '<S85>'  : 'test/__Controller/Driving Wheel Control/Poleplacement(PI)1/Saturation Dynamic'
 * '<S86>'  : 'test/__Controller/Driving Wheel Control/Subsystem/Saturation Dynamic'
 * '<S87>'  : 'test/__Controller/Lag compensator(zeta)/Dot1'
 * '<S88>'  : 'test/__Controller/Lag compensator(zeta)/a//(s+p)'
 * '<S89>'  : 'test/__Controller/Poleplacement(PI)1/Integrator1'
 * '<S90>'  : 'test/__Controller/Poleplacement(PI)1/Saturation Dynamic'
 * '<S91>'  : 'test/__Controller/Steering system/Saturation Dynamic'
 * '<S92>'  : 'test/__Controller/Subsystem1/Saturation Dynamic'
 * '<S93>'  : 'test/__Data Plotting/__Drive_Ctrl_Plot'
 * '<S94>'  : 'test/__Data Plotting/__Motor_Feedback_Plot'
 * '<S95>'  : 'test/__Data Plotting/__Reference_Plot'
 * '<S96>'  : 'test/__Data Plotting/__Sensor_Plot'
 * '<S97>'  : 'test/__Data Plotting/__Reference_Plot/If Action Subsystem4'
 * '<S98>'  : 'test/__Data Plotting/__Reference_Plot/If Action Subsystem5'
 * '<S99>'  : 'test/__Data Plotting/__Reference_Plot/If Action Subsystem6'
 * '<S100>' : 'test/__Data Plotting/__Sensor_Plot/Subsystem'
 * '<S101>' : 'test/__Data Plotting/__Sensor_Plot/Subsystem1'
 * '<S102>' : 'test/__System_Setting/Subsystem'
 * '<S103>' : 'test/__System_Setting/Subsystem/ID_Mode'
 * '<S104>' : 'test/__System_Setting/Subsystem/Torque Mode'
 * '<S105>' : 'test/__System_Setting/Subsystem/Torque Mode1'
 * '<S106>' : 'test/__System_Setting/Subsystem/Velocity Mode'
 */
#endif                                 /* RTW_HEADER_test_h_ */
