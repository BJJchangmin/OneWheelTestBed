/*
 * test_private.h
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

#ifndef RTW_HEADER_test_private_h_
#define RTW_HEADER_test_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "test.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmIsMajorTimeStep
# define rtmIsMajorTimeStep(rtm)       (((rtm)->Timing.simTimeStep) == MAJOR_TIME_STEP)
#endif

#ifndef rtmIsMinorTimeStep
# define rtmIsMinorTimeStep(rtm)       (((rtm)->Timing.simTimeStep) == MINOR_TIME_STEP)
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               ((rtm)->Timing.t)
#endif

#ifndef rtmSetTPtr
# define rtmSetTPtr(rtm, val)          ((rtm)->Timing.t = (val))
#endif

/* Used by FromWorkspace Block: '<S39>/From Workspace' */
#ifndef rtInterpolate
# define rtInterpolate(v1,v2,f1,f2)    (((v1)==(v2))?((double)(v1)): (((f1)*((double)(v1)))+((f2)*((double)(v2)))))
#endif

#ifndef rtRound
# define rtRound(v)                    ( ((v) >= 0) ? floor((v) + 0.5) : ceil((v) - 0.5) )
#endif

/* ...  variable for information on a CAN channel */
extern can_tp1_canChannel* can_type1_channel_M1_C1;

/* ... definition of message variable for the RTICAN blocks */
#define CANTP1_M1_NUMMSG               18

extern can_tp1_canMsg* can_type1_msg_M1[CANTP1_M1_NUMMSG];

/* ... variable for taskqueue error checking                  */
extern Int32 rtican_type1_tq_error[CAN_TYPE1_NUM_MODULES]
  [CAN_TYPE1_NUM_TASKQUEUES];

/* Declaration of user indices (CAN_Type1_M1) */
#define CANTP1_M1_C1_TX_STD_0X0        0
#define TX_C1_STD_0X0                  0
#undef TX_C1_STD_0X0
#define CANTP1_M1_C1_TX_STD_0X211      1
#define TX_C1_STD_0X211                1
#undef TX_C1_STD_0X211
#define CANTP1_M1_C1_TX_STD_0X221      2
#define TX_C1_STD_0X221                2
#undef TX_C1_STD_0X221
#define CANTP1_M1_C1_TX_STD_0X222      3
#define TX_C1_STD_0X222                3
#undef TX_C1_STD_0X222
#define CANTP1_M1_C1_TX_STD_0X232      4
#define TX_C1_STD_0X232                4
#undef TX_C1_STD_0X232
#define CANTP1_M1_C1_TX_STD_0X231      5
#define TX_C1_STD_0X231                5
#undef TX_C1_STD_0X231
#define CANTP1_M1_C1_TX_STD_0X212      6
#define TX_C1_STD_0X212                6
#undef TX_C1_STD_0X212
#define CANTP1_M1_C1_RX_STD_0X333      7
#define RX_C1_STD_0X333                7
#undef RX_C1_STD_0X333
#define CANTP1_M1_C1_RX_STD_0X334      8
#define RX_C1_STD_0X334                8
#undef RX_C1_STD_0X334
#define CANTP1_M1_C1_RX_STD_0X331      9
#define RX_C1_STD_0X331                9
#undef RX_C1_STD_0X331
#define CANTP1_M1_C1_RX_STD_0X314      10
#define RX_C1_STD_0X314                10
#undef RX_C1_STD_0X314
#define CANTP1_M1_C1_RX_STD_0X311      11
#define RX_C1_STD_0X311                11
#undef RX_C1_STD_0X311
#define CANTP1_M1_C1_RX_STD_0X312      12
#define RX_C1_STD_0X312                12
#undef RX_C1_STD_0X312
#define CANTP1_M1_C1_RX_STD_0X313      13
#define RX_C1_STD_0X313                13
#undef RX_C1_STD_0X313
#define CANTP1_M1_C1_RX_STD_0X324      14
#define RX_C1_STD_0X324                14
#undef RX_C1_STD_0X324
#define CANTP1_M1_C1_RX_STD_0X321      15
#define RX_C1_STD_0X321                15
#undef RX_C1_STD_0X321
#define CANTP1_M1_C1_RX_STD_0X322      16
#define RX_C1_STD_0X322                16
#undef RX_C1_STD_0X322
#define CANTP1_M1_C1_RX_STD_0X323      17
#define RX_C1_STD_0X323                17
#undef RX_C1_STD_0X323

/* predefine needed TX-definition code to support TX-Custom code */
extern can_tp1_canMsg* CANTP1_TX_SPMSG_M1_C1_STD;
extern can_tp1_canMsg* CANTP1_TX_SPMSG_M1_C1_XTD;
extern real_T rt_roundd_snf(real_T u);
extern void test_IfActionSubsystem2(real_T rtu_In1, real_T *rty_Out1);
extern void test_TorqueMode(real_T *rty_Mode, real_T *rty_Out2,
  P_TorqueMode_test_T *localP);

#endif                                 /* RTW_HEADER_test_private_h_ */
