/*****************************************************************************************************************************/
/* RTICANMM_MAIN_CAN_ID_TABLE */
/*                                                                                                                           */
/*   AUTHOR(S):                                                                                                              */
/*      U. Homann                                                                                                              */
/*      M. Eikermann                                                                                                              */
/*                                                                                                                           */
/*                                                                                                                           */
/*   RTICANMM Date: 27-Sep-2017 12:11:30                                                                                     */
/*   RTICANMM Version: 4.6.736965.5079861111                                                                                     */
/*                                                                                                                           */
/*  Copyright 2025, dSPACE GmbH. All rights reserved.                                                                    */
/*      Brand names or product names are trademarks or registered trademarks of their respective companies or organizations. */
/*                                                                                                                           */
/* ***************************************************************************************************************************/




/* NMTZeroMsg */
((UInt32*) IDPTR_MEM_R)[0] = (UInt32) RTICANMM_MAIN_CAN_copy_NMTZeroMsg;
CANMMCAN_MIDTXSW[0] = 0;
CANMMCAN_RXCNT[0] = 0;
CANMMCAN_MIDRX[0] = 0x0;
CANMMCAN_MIDTXS[0] = 0x0;
CANMMCAN_RXMT[0] = RTICANMM_MESSAGE_TYPE_STD;
CANMMCAN_MIDFRX[0] = 0;  /* 0: standard, 1:extended */ 
CANMMCAN_MIDFTXS[0] = 0;  /* 0: standard, 1:extended */ 
CANMMCAN_MIDFTX[0] = 0;  /* 0: standard, 1:extended */ 



/* GFC */
((UInt32*) IDPTR_MEM_R)[1] = (UInt32) RTICANMM_MAIN_CAN_copy_GFC;
CANMMCAN_MIDTXSW[1] = 0;
CANMMCAN_RXCNT[1] = 0;
CANMMCAN_MIDRX[1] = 0x1;
CANMMCAN_MIDTXS[1] = 0x1;
CANMMCAN_RXMT[1] = RTICANMM_MESSAGE_TYPE_STD;
CANMMCAN_MIDFRX[1] = 0;  /* 0: standard, 1:extended */ 
CANMMCAN_MIDFTXS[1] = 0;  /* 0: standard, 1:extended */ 
CANMMCAN_MIDFTX[1] = 0;  /* 0: standard, 1:extended */ 



/* FM_MasterPrioLevel */
((UInt32*) IDPTR_MEM_R)[2] = (UInt32) RTICANMM_MAIN_CAN_copy_FM_MasterPrioLevel;
CANMMCAN_MIDTXSW[2] = 0;
CANMMCAN_RXCNT[2] = 0;
CANMMCAN_MIDRX[2] = 0x71;
CANMMCAN_MIDTXS[2] = 0x71;
CANMMCAN_RXMT[2] = RTICANMM_MESSAGE_TYPE_STD;
CANMMCAN_MIDFRX[2] = 0;  /* 0: standard, 1:extended */ 
CANMMCAN_MIDFTXS[2] = 0;  /* 0: standard, 1:extended */ 
CANMMCAN_MIDFTX[2] = 0;  /* 0: standard, 1:extended */ 



/* FM_TriggerTimeSlot */
((UInt32*) IDPTR_MEM_R)[3] = (UInt32) RTICANMM_MAIN_CAN_copy_FM_TriggerTimeSlot;
CANMMCAN_MIDTXSW[3] = 0;
CANMMCAN_RXCNT[3] = 0;
CANMMCAN_MIDRX[3] = 0x72;
CANMMCAN_MIDTXS[3] = 0x72;
CANMMCAN_RXMT[3] = RTICANMM_MESSAGE_TYPE_STD;
CANMMCAN_MIDFRX[3] = 0;  /* 0: standard, 1:extended */ 
CANMMCAN_MIDFTXS[3] = 0;  /* 0: standard, 1:extended */ 
CANMMCAN_MIDFTX[3] = 0;  /* 0: standard, 1:extended */ 



/* FM_ReqPrioLevel */
((UInt32*) IDPTR_MEM_R)[4] = (UInt32) RTICANMM_MAIN_CAN_copy_FM_ReqPrioLevel;
CANMMCAN_MIDTXSW[4] = 0;
CANMMCAN_RXCNT[4] = 0;
CANMMCAN_MIDRX[4] = 0x73;
CANMMCAN_MIDTXS[4] = 0x73;
CANMMCAN_RXMT[4] = RTICANMM_MESSAGE_TYPE_STD;
CANMMCAN_MIDFRX[4] = 0;  /* 0: standard, 1:extended */ 
CANMMCAN_MIDFTXS[4] = 0;  /* 0: standard, 1:extended */ 
CANMMCAN_MIDFTX[4] = 0;  /* 0: standard, 1:extended */ 



/* FM_RspMasterCapable */
((UInt32*) IDPTR_MEM_R)[5] = (UInt32) RTICANMM_MAIN_CAN_copy_FM_RspMasterCapable;
CANMMCAN_MIDTXSW[5] = 0;
CANMMCAN_RXCNT[5] = 0;
CANMMCAN_MIDRX[5] = 0x74;
CANMMCAN_MIDTXS[5] = 0x74;
CANMMCAN_RXMT[5] = RTICANMM_MESSAGE_TYPE_STD;
CANMMCAN_MIDFRX[5] = 0;  /* 0: standard, 1:extended */ 
CANMMCAN_MIDFTXS[5] = 0;  /* 0: standard, 1:extended */ 
CANMMCAN_MIDFTX[5] = 0;  /* 0: standard, 1:extended */ 



/* FM_ReqMasterCapable */
((UInt32*) IDPTR_MEM_R)[6] = (UInt32) RTICANMM_MAIN_CAN_copy_FM_ReqMasterCapable;
CANMMCAN_MIDTXSW[6] = 0;
CANMMCAN_RXCNT[6] = 0;
CANMMCAN_MIDRX[6] = 0x75;
CANMMCAN_MIDTXS[6] = 0x75;
CANMMCAN_RXMT[6] = RTICANMM_MESSAGE_TYPE_STD;
CANMMCAN_MIDFRX[6] = 0;  /* 0: standard, 1:extended */ 
CANMMCAN_MIDFTXS[6] = 0;  /* 0: standard, 1:extended */ 
CANMMCAN_MIDFTX[6] = 0;  /* 0: standard, 1:extended */ 



/* FM_ForceReset */
((UInt32*) IDPTR_MEM_R)[7] = (UInt32) RTICANMM_MAIN_CAN_copy_FM_ForceReset;
CANMMCAN_MIDTXSW[7] = 0;
CANMMCAN_RXCNT[7] = 0;
CANMMCAN_MIDRX[7] = 0x76;
CANMMCAN_MIDTXS[7] = 0x76;
CANMMCAN_RXMT[7] = RTICANMM_MESSAGE_TYPE_STD;
CANMMCAN_MIDFRX[7] = 0;  /* 0: standard, 1:extended */ 
CANMMCAN_MIDFTXS[7] = 0;  /* 0: standard, 1:extended */ 
CANMMCAN_MIDFTX[7] = 0;  /* 0: standard, 1:extended */ 



/* RED_IndicateActiveCANLine */
((UInt32*) IDPTR_MEM_R)[8] = (UInt32) RTICANMM_MAIN_CAN_copy_RED_IndicateActiveCANLine;
CANMMCAN_MIDTXSW[8] = 0;
CANMMCAN_RXCNT[8] = 0;
CANMMCAN_MIDRX[8] = 0x7F;
CANMMCAN_MIDTXS[8] = 0x7F;
CANMMCAN_RXMT[8] = RTICANMM_MESSAGE_TYPE_STD;
CANMMCAN_MIDFRX[8] = 0;  /* 0: standard, 1:extended */ 
CANMMCAN_MIDFTXS[8] = 0;  /* 0: standard, 1:extended */ 
CANMMCAN_MIDFTX[8] = 0;  /* 0: standard, 1:extended */ 



/* SYNC */
((UInt32*) IDPTR_MEM_R)[9] = (UInt32) RTICANMM_MAIN_CAN_copy_SYNC;
CANMMCAN_MIDTXSW[9] = 0;
CANMMCAN_RXCNT[9] = 0;
CANMMCAN_MIDRX[9] = 0x80;
CANMMCAN_MIDTXS[9] = 0x80;
CANMMCAN_RXMT[9] = RTICANMM_MESSAGE_TYPE_STD;
CANMMCAN_MIDFRX[9] = 0;  /* 0: standard, 1:extended */ 
CANMMCAN_MIDFTXS[9] = 0;  /* 0: standard, 1:extended */ 
CANMMCAN_MIDFTX[9] = 0;  /* 0: standard, 1:extended */ 



/* EMCY_010 */
((UInt32*) IDPTR_MEM_R)[10] = (UInt32) RTICANMM_MAIN_CAN_copy_EMCY_010;
CANMMCAN_MIDTXSW[10] = 0;
CANMMCAN_RXCNT[10] = 0;
CANMMCAN_MIDRX[10] = 0x8A;
CANMMCAN_MIDTXS[10] = 0x8A;
CANMMCAN_RXMT[10] = RTICANMM_MESSAGE_TYPE_STD;
CANMMCAN_MIDFRX[10] = 0;  /* 0: standard, 1:extended */ 
CANMMCAN_MIDFTXS[10] = 0;  /* 0: standard, 1:extended */ 
CANMMCAN_MIDFTX[10] = 0;  /* 0: standard, 1:extended */ 



/* EMCY_020 */
((UInt32*) IDPTR_MEM_R)[11] = (UInt32) RTICANMM_MAIN_CAN_copy_EMCY_020;
CANMMCAN_MIDTXSW[11] = 0;
CANMMCAN_RXCNT[11] = 0;
CANMMCAN_MIDRX[11] = 0x94;
CANMMCAN_MIDTXS[11] = 0x94;
CANMMCAN_RXMT[11] = RTICANMM_MESSAGE_TYPE_STD;
CANMMCAN_MIDFRX[11] = 0;  /* 0: standard, 1:extended */ 
CANMMCAN_MIDFTXS[11] = 0;  /* 0: standard, 1:extended */ 
CANMMCAN_MIDFTX[11] = 0;  /* 0: standard, 1:extended */ 



/* EMCY_030 */
((UInt32*) IDPTR_MEM_R)[12] = (UInt32) RTICANMM_MAIN_CAN_copy_EMCY_030;
CANMMCAN_MIDTXSW[12] = 0;
CANMMCAN_RXCNT[12] = 0;
CANMMCAN_MIDRX[12] = 0x9E;
CANMMCAN_MIDTXS[12] = 0x9E;
CANMMCAN_RXMT[12] = RTICANMM_MESSAGE_TYPE_STD;
CANMMCAN_MIDFRX[12] = 0;  /* 0: standard, 1:extended */ 
CANMMCAN_MIDFTXS[12] = 0;  /* 0: standard, 1:extended */ 
CANMMCAN_MIDFTX[12] = 0;  /* 0: standard, 1:extended */ 



/* TIME */
((UInt32*) IDPTR_MEM_R)[13] = (UInt32) RTICANMM_MAIN_CAN_copy_TIME;
CANMMCAN_MIDTXSW[13] = 0;
CANMMCAN_RXCNT[13] = 0;
CANMMCAN_MIDRX[13] = 0x100;
CANMMCAN_MIDTXS[13] = 0x100;
CANMMCAN_RXMT[13] = RTICANMM_MESSAGE_TYPE_STD;
CANMMCAN_MIDFRX[13] = 0;  /* 0: standard, 1:extended */ 
CANMMCAN_MIDFTXS[13] = 0;  /* 0: standard, 1:extended */ 
CANMMCAN_MIDFTX[13] = 0;  /* 0: standard, 1:extended */ 



/* N10_RPDO0 */
((UInt32*) IDPTR_MEM_R)[14] = (UInt32) RTICANMM_MAIN_CAN_copy_N10_RPDO0;
CANMMCAN_MIDTXSW[14] = 0;
CANMMCAN_RXCNT[14] = 0;
CANMMCAN_MIDRX[14] = 0x211;
CANMMCAN_MIDTXS[14] = 0x211;
CANMMCAN_RXMT[14] = RTICANMM_MESSAGE_TYPE_STD;
CANMMCAN_MIDFRX[14] = 0;  /* 0: standard, 1:extended */ 
CANMMCAN_MIDFTXS[14] = 0;  /* 0: standard, 1:extended */ 
CANMMCAN_MIDFTX[14] = 0;  /* 0: standard, 1:extended */ 



/* N10_RPDO1 */
((UInt32*) IDPTR_MEM_R)[15] = (UInt32) RTICANMM_MAIN_CAN_copy_N10_RPDO1;
CANMMCAN_MIDTXSW[15] = 0;
CANMMCAN_RXCNT[15] = 0;
CANMMCAN_MIDRX[15] = 0x212;
CANMMCAN_MIDTXS[15] = 0x212;
CANMMCAN_RXMT[15] = RTICANMM_MESSAGE_TYPE_STD;
CANMMCAN_MIDFRX[15] = 0;  /* 0: standard, 1:extended */ 
CANMMCAN_MIDFTXS[15] = 0;  /* 0: standard, 1:extended */ 
CANMMCAN_MIDFTX[15] = 0;  /* 0: standard, 1:extended */ 



/* N20_RPDO0 */
((UInt32*) IDPTR_MEM_R)[16] = (UInt32) RTICANMM_MAIN_CAN_copy_N20_RPDO0;
CANMMCAN_MIDTXSW[16] = 0;
CANMMCAN_RXCNT[16] = 0;
CANMMCAN_MIDRX[16] = 0x221;
CANMMCAN_MIDTXS[16] = 0x221;
CANMMCAN_RXMT[16] = RTICANMM_MESSAGE_TYPE_STD;
CANMMCAN_MIDFRX[16] = 0;  /* 0: standard, 1:extended */ 
CANMMCAN_MIDFTXS[16] = 0;  /* 0: standard, 1:extended */ 
CANMMCAN_MIDFTX[16] = 0;  /* 0: standard, 1:extended */ 



/* N20_RPDO1 */
((UInt32*) IDPTR_MEM_R)[17] = (UInt32) RTICANMM_MAIN_CAN_copy_N20_RPDO1;
CANMMCAN_MIDTXSW[17] = 0;
CANMMCAN_RXCNT[17] = 0;
CANMMCAN_MIDRX[17] = 0x222;
CANMMCAN_MIDTXS[17] = 0x222;
CANMMCAN_RXMT[17] = RTICANMM_MESSAGE_TYPE_STD;
CANMMCAN_MIDFRX[17] = 0;  /* 0: standard, 1:extended */ 
CANMMCAN_MIDFTXS[17] = 0;  /* 0: standard, 1:extended */ 
CANMMCAN_MIDFTX[17] = 0;  /* 0: standard, 1:extended */ 



/* N20_RPDO2 */
((UInt32*) IDPTR_MEM_R)[18] = (UInt32) RTICANMM_MAIN_CAN_copy_N20_RPDO2;
CANMMCAN_MIDTXSW[18] = 0;
CANMMCAN_RXCNT[18] = 0;
CANMMCAN_MIDRX[18] = 0x223;
CANMMCAN_MIDTXS[18] = 0x223;
CANMMCAN_RXMT[18] = RTICANMM_MESSAGE_TYPE_STD;
CANMMCAN_MIDFRX[18] = 0;  /* 0: standard, 1:extended */ 
CANMMCAN_MIDFTXS[18] = 0;  /* 0: standard, 1:extended */ 
CANMMCAN_MIDFTX[18] = 0;  /* 0: standard, 1:extended */ 



/* N20_RPDO3 */
((UInt32*) IDPTR_MEM_R)[19] = (UInt32) RTICANMM_MAIN_CAN_copy_N20_RPDO3;
CANMMCAN_MIDTXSW[19] = 0;
CANMMCAN_RXCNT[19] = 0;
CANMMCAN_MIDRX[19] = 0x224;
CANMMCAN_MIDTXS[19] = 0x224;
CANMMCAN_RXMT[19] = RTICANMM_MESSAGE_TYPE_STD;
CANMMCAN_MIDFRX[19] = 0;  /* 0: standard, 1:extended */ 
CANMMCAN_MIDFTXS[19] = 0;  /* 0: standard, 1:extended */ 
CANMMCAN_MIDFTX[19] = 0;  /* 0: standard, 1:extended */ 



/* N30_RPDO0 */
((UInt32*) IDPTR_MEM_R)[20] = (UInt32) RTICANMM_MAIN_CAN_copy_N30_RPDO0;
CANMMCAN_MIDTXSW[20] = 0;
CANMMCAN_RXCNT[20] = 0;
CANMMCAN_MIDRX[20] = 0x231;
CANMMCAN_MIDTXS[20] = 0x231;
CANMMCAN_RXMT[20] = RTICANMM_MESSAGE_TYPE_STD;
CANMMCAN_MIDFRX[20] = 0;  /* 0: standard, 1:extended */ 
CANMMCAN_MIDFTXS[20] = 0;  /* 0: standard, 1:extended */ 
CANMMCAN_MIDFTX[20] = 0;  /* 0: standard, 1:extended */ 



/* N30_RPDO1 */
((UInt32*) IDPTR_MEM_R)[21] = (UInt32) RTICANMM_MAIN_CAN_copy_N30_RPDO1;
CANMMCAN_MIDTXSW[21] = 0;
CANMMCAN_RXCNT[21] = 0;
CANMMCAN_MIDRX[21] = 0x232;
CANMMCAN_MIDTXS[21] = 0x232;
CANMMCAN_RXMT[21] = RTICANMM_MESSAGE_TYPE_STD;
CANMMCAN_MIDFRX[21] = 0;  /* 0: standard, 1:extended */ 
CANMMCAN_MIDFTXS[21] = 0;  /* 0: standard, 1:extended */ 
CANMMCAN_MIDFTX[21] = 0;  /* 0: standard, 1:extended */ 



/* N30_RPDO2 */
((UInt32*) IDPTR_MEM_R)[22] = (UInt32) RTICANMM_MAIN_CAN_copy_N30_RPDO2;
CANMMCAN_MIDTXSW[22] = 0;
CANMMCAN_RXCNT[22] = 0;
CANMMCAN_MIDRX[22] = 0x233;
CANMMCAN_MIDTXS[22] = 0x233;
CANMMCAN_RXMT[22] = RTICANMM_MESSAGE_TYPE_STD;
CANMMCAN_MIDFRX[22] = 0;  /* 0: standard, 1:extended */ 
CANMMCAN_MIDFTXS[22] = 0;  /* 0: standard, 1:extended */ 
CANMMCAN_MIDFTX[22] = 0;  /* 0: standard, 1:extended */ 



/* N30_RPDO3 */
((UInt32*) IDPTR_MEM_R)[23] = (UInt32) RTICANMM_MAIN_CAN_copy_N30_RPDO3;
CANMMCAN_MIDTXSW[23] = 0;
CANMMCAN_RXCNT[23] = 0;
CANMMCAN_MIDRX[23] = 0x234;
CANMMCAN_MIDTXS[23] = 0x234;
CANMMCAN_RXMT[23] = RTICANMM_MESSAGE_TYPE_STD;
CANMMCAN_MIDFRX[23] = 0;  /* 0: standard, 1:extended */ 
CANMMCAN_MIDFTXS[23] = 0;  /* 0: standard, 1:extended */ 
CANMMCAN_MIDFTX[23] = 0;  /* 0: standard, 1:extended */ 



/* N10_TPDO0 */
((UInt32*) IDPTR_MEM_R)[24] = (UInt32) RTICANMM_MAIN_CAN_copy_N10_TPDO0;
CANMMCAN_MIDTXSW[24] = 0;
CANMMCAN_RXCNT[24] = 0;
CANMMCAN_MIDRX[24] = 0x311;
CANMMCAN_MIDTXS[24] = 0x311;
CANMMCAN_RXMT[24] = RTICANMM_MESSAGE_TYPE_STD;
CANMMCAN_MIDFRX[24] = 0;  /* 0: standard, 1:extended */ 
CANMMCAN_MIDFTXS[24] = 0;  /* 0: standard, 1:extended */ 
CANMMCAN_MIDFTX[24] = 0;  /* 0: standard, 1:extended */ 



/* N10_TPDO1 */
((UInt32*) IDPTR_MEM_R)[25] = (UInt32) RTICANMM_MAIN_CAN_copy_N10_TPDO1;
CANMMCAN_MIDTXSW[25] = 0;
CANMMCAN_RXCNT[25] = 0;
CANMMCAN_MIDRX[25] = 0x312;
CANMMCAN_MIDTXS[25] = 0x312;
CANMMCAN_RXMT[25] = RTICANMM_MESSAGE_TYPE_STD;
CANMMCAN_MIDFRX[25] = 0;  /* 0: standard, 1:extended */ 
CANMMCAN_MIDFTXS[25] = 0;  /* 0: standard, 1:extended */ 
CANMMCAN_MIDFTX[25] = 0;  /* 0: standard, 1:extended */ 



/* N10_TPDO2 */
((UInt32*) IDPTR_MEM_R)[26] = (UInt32) RTICANMM_MAIN_CAN_copy_N10_TPDO2;
CANMMCAN_MIDTXSW[26] = 0;
CANMMCAN_RXCNT[26] = 0;
CANMMCAN_MIDRX[26] = 0x313;
CANMMCAN_MIDTXS[26] = 0x313;
CANMMCAN_RXMT[26] = RTICANMM_MESSAGE_TYPE_STD;
CANMMCAN_MIDFRX[26] = 0;  /* 0: standard, 1:extended */ 
CANMMCAN_MIDFTXS[26] = 0;  /* 0: standard, 1:extended */ 
CANMMCAN_MIDFTX[26] = 0;  /* 0: standard, 1:extended */ 



/* N10_TPDO3 */
((UInt32*) IDPTR_MEM_R)[27] = (UInt32) RTICANMM_MAIN_CAN_copy_N10_TPDO3;
CANMMCAN_MIDTXSW[27] = 0;
CANMMCAN_RXCNT[27] = 0;
CANMMCAN_MIDRX[27] = 0x314;
CANMMCAN_MIDTXS[27] = 0x314;
CANMMCAN_RXMT[27] = RTICANMM_MESSAGE_TYPE_STD;
CANMMCAN_MIDFRX[27] = 0;  /* 0: standard, 1:extended */ 
CANMMCAN_MIDFTXS[27] = 0;  /* 0: standard, 1:extended */ 
CANMMCAN_MIDFTX[27] = 0;  /* 0: standard, 1:extended */ 



/* N20_TPDO0 */
((UInt32*) IDPTR_MEM_R)[28] = (UInt32) RTICANMM_MAIN_CAN_copy_N20_TPDO0;
CANMMCAN_MIDTXSW[28] = 0;
CANMMCAN_RXCNT[28] = 0;
CANMMCAN_MIDRX[28] = 0x321;
CANMMCAN_MIDTXS[28] = 0x321;
CANMMCAN_RXMT[28] = RTICANMM_MESSAGE_TYPE_STD;
CANMMCAN_MIDFRX[28] = 0;  /* 0: standard, 1:extended */ 
CANMMCAN_MIDFTXS[28] = 0;  /* 0: standard, 1:extended */ 
CANMMCAN_MIDFTX[28] = 0;  /* 0: standard, 1:extended */ 



/* N20_TPDO1 */
((UInt32*) IDPTR_MEM_R)[29] = (UInt32) RTICANMM_MAIN_CAN_copy_N20_TPDO1;
CANMMCAN_MIDTXSW[29] = 0;
CANMMCAN_RXCNT[29] = 0;
CANMMCAN_MIDRX[29] = 0x322;
CANMMCAN_MIDTXS[29] = 0x322;
CANMMCAN_RXMT[29] = RTICANMM_MESSAGE_TYPE_STD;
CANMMCAN_MIDFRX[29] = 0;  /* 0: standard, 1:extended */ 
CANMMCAN_MIDFTXS[29] = 0;  /* 0: standard, 1:extended */ 
CANMMCAN_MIDFTX[29] = 0;  /* 0: standard, 1:extended */ 



/* N20_TPDO2 */
((UInt32*) IDPTR_MEM_R)[30] = (UInt32) RTICANMM_MAIN_CAN_copy_N20_TPDO2;
CANMMCAN_MIDTXSW[30] = 0;
CANMMCAN_RXCNT[30] = 0;
CANMMCAN_MIDRX[30] = 0x323;
CANMMCAN_MIDTXS[30] = 0x323;
CANMMCAN_RXMT[30] = RTICANMM_MESSAGE_TYPE_STD;
CANMMCAN_MIDFRX[30] = 0;  /* 0: standard, 1:extended */ 
CANMMCAN_MIDFTXS[30] = 0;  /* 0: standard, 1:extended */ 
CANMMCAN_MIDFTX[30] = 0;  /* 0: standard, 1:extended */ 



/* N20_TPDO3 */
((UInt32*) IDPTR_MEM_R)[31] = (UInt32) RTICANMM_MAIN_CAN_copy_N20_TPDO3;
CANMMCAN_MIDTXSW[31] = 0;
CANMMCAN_RXCNT[31] = 0;
CANMMCAN_MIDRX[31] = 0x324;
CANMMCAN_MIDTXS[31] = 0x324;
CANMMCAN_RXMT[31] = RTICANMM_MESSAGE_TYPE_STD;
CANMMCAN_MIDFRX[31] = 0;  /* 0: standard, 1:extended */ 
CANMMCAN_MIDFTXS[31] = 0;  /* 0: standard, 1:extended */ 
CANMMCAN_MIDFTX[31] = 0;  /* 0: standard, 1:extended */ 



/* N30_TPDO0 */
((UInt32*) IDPTR_MEM_R)[32] = (UInt32) RTICANMM_MAIN_CAN_copy_N30_TPDO0;
CANMMCAN_MIDTXSW[32] = 0;
CANMMCAN_RXCNT[32] = 0;
CANMMCAN_MIDRX[32] = 0x331;
CANMMCAN_MIDTXS[32] = 0x331;
CANMMCAN_RXMT[32] = RTICANMM_MESSAGE_TYPE_STD;
CANMMCAN_MIDFRX[32] = 0;  /* 0: standard, 1:extended */ 
CANMMCAN_MIDFTXS[32] = 0;  /* 0: standard, 1:extended */ 
CANMMCAN_MIDFTX[32] = 0;  /* 0: standard, 1:extended */ 



/* N30_TPDO1 */
((UInt32*) IDPTR_MEM_R)[33] = (UInt32) RTICANMM_MAIN_CAN_copy_N30_TPDO1;
CANMMCAN_MIDTXSW[33] = 0;
CANMMCAN_RXCNT[33] = 0;
CANMMCAN_MIDRX[33] = 0x332;
CANMMCAN_MIDTXS[33] = 0x332;
CANMMCAN_RXMT[33] = RTICANMM_MESSAGE_TYPE_STD;
CANMMCAN_MIDFRX[33] = 0;  /* 0: standard, 1:extended */ 
CANMMCAN_MIDFTXS[33] = 0;  /* 0: standard, 1:extended */ 
CANMMCAN_MIDFTX[33] = 0;  /* 0: standard, 1:extended */ 



/* N30_TPDO2 */
((UInt32*) IDPTR_MEM_R)[34] = (UInt32) RTICANMM_MAIN_CAN_copy_N30_TPDO2;
CANMMCAN_MIDTXSW[34] = 0;
CANMMCAN_RXCNT[34] = 0;
CANMMCAN_MIDRX[34] = 0x333;
CANMMCAN_MIDTXS[34] = 0x333;
CANMMCAN_RXMT[34] = RTICANMM_MESSAGE_TYPE_STD;
CANMMCAN_MIDFRX[34] = 0;  /* 0: standard, 1:extended */ 
CANMMCAN_MIDFTXS[34] = 0;  /* 0: standard, 1:extended */ 
CANMMCAN_MIDFTX[34] = 0;  /* 0: standard, 1:extended */ 



/* N30_TPDO3 */
((UInt32*) IDPTR_MEM_R)[35] = (UInt32) RTICANMM_MAIN_CAN_copy_N30_TPDO3;
CANMMCAN_MIDTXSW[35] = 0;
CANMMCAN_RXCNT[35] = 0;
CANMMCAN_MIDRX[35] = 0x334;
CANMMCAN_MIDTXS[35] = 0x334;
CANMMCAN_RXMT[35] = RTICANMM_MESSAGE_TYPE_STD;
CANMMCAN_MIDFRX[35] = 0;  /* 0: standard, 1:extended */ 
CANMMCAN_MIDFTXS[35] = 0;  /* 0: standard, 1:extended */ 
CANMMCAN_MIDFTX[35] = 0;  /* 0: standard, 1:extended */ 



/* SSDO_010 */
((UInt32*) IDPTR_MEM_R)[36] = (UInt32) RTICANMM_MAIN_CAN_copy_SSDO_010;
CANMMCAN_MIDTXSW[36] = 0;
CANMMCAN_RXCNT[36] = 0;
CANMMCAN_MIDRX[36] = 0x58A;
CANMMCAN_MIDTXS[36] = 0x58A;
CANMMCAN_RXMT[36] = RTICANMM_MESSAGE_TYPE_STD;
CANMMCAN_MIDFRX[36] = 0;  /* 0: standard, 1:extended */ 
CANMMCAN_MIDFTXS[36] = 0;  /* 0: standard, 1:extended */ 
CANMMCAN_MIDFTX[36] = 0;  /* 0: standard, 1:extended */ 



/* SSDO_020 */
((UInt32*) IDPTR_MEM_R)[37] = (UInt32) RTICANMM_MAIN_CAN_copy_SSDO_020;
CANMMCAN_MIDTXSW[37] = 0;
CANMMCAN_RXCNT[37] = 0;
CANMMCAN_MIDRX[37] = 0x594;
CANMMCAN_MIDTXS[37] = 0x594;
CANMMCAN_RXMT[37] = RTICANMM_MESSAGE_TYPE_STD;
CANMMCAN_MIDFRX[37] = 0;  /* 0: standard, 1:extended */ 
CANMMCAN_MIDFTXS[37] = 0;  /* 0: standard, 1:extended */ 
CANMMCAN_MIDFTX[37] = 0;  /* 0: standard, 1:extended */ 



/* SSDO_030 */
((UInt32*) IDPTR_MEM_R)[38] = (UInt32) RTICANMM_MAIN_CAN_copy_SSDO_030;
CANMMCAN_MIDTXSW[38] = 0;
CANMMCAN_RXCNT[38] = 0;
CANMMCAN_MIDRX[38] = 0x59E;
CANMMCAN_MIDTXS[38] = 0x59E;
CANMMCAN_RXMT[38] = RTICANMM_MESSAGE_TYPE_STD;
CANMMCAN_MIDFRX[38] = 0;  /* 0: standard, 1:extended */ 
CANMMCAN_MIDFTXS[38] = 0;  /* 0: standard, 1:extended */ 
CANMMCAN_MIDFTX[38] = 0;  /* 0: standard, 1:extended */ 



/* CSDO_010 */
((UInt32*) IDPTR_MEM_R)[39] = (UInt32) RTICANMM_MAIN_CAN_copy_CSDO_010;
CANMMCAN_MIDTXSW[39] = 0;
CANMMCAN_RXCNT[39] = 0;
CANMMCAN_MIDRX[39] = 0x60A;
CANMMCAN_MIDTXS[39] = 0x60A;
CANMMCAN_RXMT[39] = RTICANMM_MESSAGE_TYPE_STD;
CANMMCAN_MIDFRX[39] = 0;  /* 0: standard, 1:extended */ 
CANMMCAN_MIDFTXS[39] = 0;  /* 0: standard, 1:extended */ 
CANMMCAN_MIDFTX[39] = 0;  /* 0: standard, 1:extended */ 



/* CSDO_020 */
((UInt32*) IDPTR_MEM_R)[40] = (UInt32) RTICANMM_MAIN_CAN_copy_CSDO_020;
CANMMCAN_MIDTXSW[40] = 0;
CANMMCAN_RXCNT[40] = 0;
CANMMCAN_MIDRX[40] = 0x614;
CANMMCAN_MIDTXS[40] = 0x614;
CANMMCAN_RXMT[40] = RTICANMM_MESSAGE_TYPE_STD;
CANMMCAN_MIDFRX[40] = 0;  /* 0: standard, 1:extended */ 
CANMMCAN_MIDFTXS[40] = 0;  /* 0: standard, 1:extended */ 
CANMMCAN_MIDFTX[40] = 0;  /* 0: standard, 1:extended */ 



/* CSDO_030 */
((UInt32*) IDPTR_MEM_R)[41] = (UInt32) RTICANMM_MAIN_CAN_copy_CSDO_030;
CANMMCAN_MIDTXSW[41] = 0;
CANMMCAN_RXCNT[41] = 0;
CANMMCAN_MIDRX[41] = 0x61E;
CANMMCAN_MIDTXS[41] = 0x61E;
CANMMCAN_RXMT[41] = RTICANMM_MESSAGE_TYPE_STD;
CANMMCAN_MIDFRX[41] = 0;  /* 0: standard, 1:extended */ 
CANMMCAN_MIDFTXS[41] = 0;  /* 0: standard, 1:extended */ 
CANMMCAN_MIDFTX[41] = 0;  /* 0: standard, 1:extended */ 



/* DynSDOReq */
((UInt32*) IDPTR_MEM_R)[42] = (UInt32) RTICANMM_MAIN_CAN_copy_DynSDOReq;
CANMMCAN_MIDTXSW[42] = 0;
CANMMCAN_RXCNT[42] = 0;
CANMMCAN_MIDRX[42] = 0x6E0;
CANMMCAN_MIDTXS[42] = 0x6E0;
CANMMCAN_RXMT[42] = RTICANMM_MESSAGE_TYPE_STD;
CANMMCAN_MIDFRX[42] = 0;  /* 0: standard, 1:extended */ 
CANMMCAN_MIDFTXS[42] = 0;  /* 0: standard, 1:extended */ 
CANMMCAN_MIDFTX[42] = 0;  /* 0: standard, 1:extended */ 



/* HBGuard_010 */
((UInt32*) IDPTR_MEM_R)[43] = (UInt32) RTICANMM_MAIN_CAN_copy_HBGuard_010;
CANMMCAN_MIDTXSW[43] = 0;
CANMMCAN_RXCNT[43] = 0;
CANMMCAN_MIDRX[43] = 0x70A;
CANMMCAN_MIDTXS[43] = 0x70A;
CANMMCAN_RXMT[43] = RTICANMM_MESSAGE_TYPE_STD;
CANMMCAN_MIDFRX[43] = 0;  /* 0: standard, 1:extended */ 
CANMMCAN_MIDFTXS[43] = 0;  /* 0: standard, 1:extended */ 
CANMMCAN_MIDFTX[43] = 0;  /* 0: standard, 1:extended */ 



/* HBGuard_020 */
((UInt32*) IDPTR_MEM_R)[44] = (UInt32) RTICANMM_MAIN_CAN_copy_HBGuard_020;
CANMMCAN_MIDTXSW[44] = 0;
CANMMCAN_RXCNT[44] = 0;
CANMMCAN_MIDRX[44] = 0x714;
CANMMCAN_MIDTXS[44] = 0x714;
CANMMCAN_RXMT[44] = RTICANMM_MESSAGE_TYPE_STD;
CANMMCAN_MIDFRX[44] = 0;  /* 0: standard, 1:extended */ 
CANMMCAN_MIDFTXS[44] = 0;  /* 0: standard, 1:extended */ 
CANMMCAN_MIDFTX[44] = 0;  /* 0: standard, 1:extended */ 



/* HBGuard_030 */
((UInt32*) IDPTR_MEM_R)[45] = (UInt32) RTICANMM_MAIN_CAN_copy_HBGuard_030;
CANMMCAN_MIDTXSW[45] = 0;
CANMMCAN_RXCNT[45] = 0;
CANMMCAN_MIDRX[45] = 0x71E;
CANMMCAN_MIDTXS[45] = 0x71E;
CANMMCAN_RXMT[45] = RTICANMM_MESSAGE_TYPE_STD;
CANMMCAN_MIDFRX[45] = 0;  /* 0: standard, 1:extended */ 
CANMMCAN_MIDFTXS[45] = 0;  /* 0: standard, 1:extended */ 
CANMMCAN_MIDFTX[45] = 0;  /* 0: standard, 1:extended */ 



/* LSS_S */
((UInt32*) IDPTR_MEM_R)[46] = (UInt32) RTICANMM_MAIN_CAN_copy_LSS_S;
CANMMCAN_MIDTXSW[46] = 0;
CANMMCAN_RXCNT[46] = 0;
CANMMCAN_MIDRX[46] = 0x7E4;
CANMMCAN_MIDTXS[46] = 0x7E4;
CANMMCAN_RXMT[46] = RTICANMM_MESSAGE_TYPE_STD;
CANMMCAN_MIDFRX[46] = 0;  /* 0: standard, 1:extended */ 
CANMMCAN_MIDFTXS[46] = 0;  /* 0: standard, 1:extended */ 
CANMMCAN_MIDFTX[46] = 0;  /* 0: standard, 1:extended */ 



/* LSS_M */
((UInt32*) IDPTR_MEM_R)[47] = (UInt32) RTICANMM_MAIN_CAN_copy_LSS_M;
CANMMCAN_MIDTXSW[47] = 0;
CANMMCAN_RXCNT[47] = 0;
CANMMCAN_MIDRX[47] = 0x7E5;
CANMMCAN_MIDTXS[47] = 0x7E5;
CANMMCAN_RXMT[47] = RTICANMM_MESSAGE_TYPE_STD;
CANMMCAN_MIDFRX[47] = 0;  /* 0: standard, 1:extended */ 
CANMMCAN_MIDFTXS[47] = 0;  /* 0: standard, 1:extended */ 
CANMMCAN_MIDFTX[47] = 0;  /* 0: standard, 1:extended */ 
 
 


/* NMTZeroMsg */
CANMMCAN_MIDTX[0] = 0; 
((UInt32*) IDPTR_MEM_T)[0] = (UInt32) RTICANMM_MAIN_CAN_copy_NMTZeroMsg;



/* GFC */
CANMMCAN_MIDTX[1] = 1; 
((UInt32*) IDPTR_MEM_T)[1] = (UInt32) RTICANMM_MAIN_CAN_copy_GFC;



/* FM_MasterPrioLevel */
CANMMCAN_MIDTX[2] = 2; 
((UInt32*) IDPTR_MEM_T)[2] = (UInt32) RTICANMM_MAIN_CAN_copy_FM_MasterPrioLevel;



/* FM_TriggerTimeSlot */
CANMMCAN_MIDTX[3] = 3; 
((UInt32*) IDPTR_MEM_T)[3] = (UInt32) RTICANMM_MAIN_CAN_copy_FM_TriggerTimeSlot;



/* FM_ReqPrioLevel */
CANMMCAN_MIDTX[4] = 4; 
((UInt32*) IDPTR_MEM_T)[4] = (UInt32) RTICANMM_MAIN_CAN_copy_FM_ReqPrioLevel;



/* FM_RspMasterCapable */
CANMMCAN_MIDTX[5] = 5; 
((UInt32*) IDPTR_MEM_T)[5] = (UInt32) RTICANMM_MAIN_CAN_copy_FM_RspMasterCapable;



/* FM_ReqMasterCapable */
CANMMCAN_MIDTX[6] = 6; 
((UInt32*) IDPTR_MEM_T)[6] = (UInt32) RTICANMM_MAIN_CAN_copy_FM_ReqMasterCapable;



/* FM_ForceReset */
CANMMCAN_MIDTX[7] = 7; 
((UInt32*) IDPTR_MEM_T)[7] = (UInt32) RTICANMM_MAIN_CAN_copy_FM_ForceReset;



/* RED_IndicateActiveCANLine */
CANMMCAN_MIDTX[8] = 8; 
((UInt32*) IDPTR_MEM_T)[8] = (UInt32) RTICANMM_MAIN_CAN_copy_RED_IndicateActiveCANLine;



/* SYNC */
CANMMCAN_MIDTX[9] = 9; 
((UInt32*) IDPTR_MEM_T)[9] = (UInt32) RTICANMM_MAIN_CAN_copy_SYNC;



/* EMCY_010 */
CANMMCAN_MIDTX[10] = 10; 
((UInt32*) IDPTR_MEM_T)[10] = (UInt32) RTICANMM_MAIN_CAN_copy_EMCY_010;



/* EMCY_020 */
CANMMCAN_MIDTX[11] = 11; 
((UInt32*) IDPTR_MEM_T)[11] = (UInt32) RTICANMM_MAIN_CAN_copy_EMCY_020;



/* EMCY_030 */
CANMMCAN_MIDTX[12] = 12; 
((UInt32*) IDPTR_MEM_T)[12] = (UInt32) RTICANMM_MAIN_CAN_copy_EMCY_030;



/* TIME */
CANMMCAN_MIDTX[13] = 13; 
((UInt32*) IDPTR_MEM_T)[13] = (UInt32) RTICANMM_MAIN_CAN_copy_TIME;



/* N10_RPDO0 */
CANMMCAN_MIDTX[14] = 14; 
((UInt32*) IDPTR_MEM_T)[14] = (UInt32) RTICANMM_MAIN_CAN_copy_N10_RPDO0;



/* N10_RPDO1 */
CANMMCAN_MIDTX[15] = 15; 
((UInt32*) IDPTR_MEM_T)[15] = (UInt32) RTICANMM_MAIN_CAN_copy_N10_RPDO1;



/* N20_RPDO0 */
CANMMCAN_MIDTX[16] = 16; 
((UInt32*) IDPTR_MEM_T)[16] = (UInt32) RTICANMM_MAIN_CAN_copy_N20_RPDO0;



/* N20_RPDO1 */
CANMMCAN_MIDTX[17] = 17; 
((UInt32*) IDPTR_MEM_T)[17] = (UInt32) RTICANMM_MAIN_CAN_copy_N20_RPDO1;



/* N20_RPDO2 */
CANMMCAN_MIDTX[18] = 18; 
((UInt32*) IDPTR_MEM_T)[18] = (UInt32) RTICANMM_MAIN_CAN_copy_N20_RPDO2;



/* N20_RPDO3 */
CANMMCAN_MIDTX[19] = 19; 
((UInt32*) IDPTR_MEM_T)[19] = (UInt32) RTICANMM_MAIN_CAN_copy_N20_RPDO3;



/* N30_RPDO0 */
CANMMCAN_MIDTX[20] = 20; 
((UInt32*) IDPTR_MEM_T)[20] = (UInt32) RTICANMM_MAIN_CAN_copy_N30_RPDO0;



/* N30_RPDO1 */
CANMMCAN_MIDTX[21] = 21; 
((UInt32*) IDPTR_MEM_T)[21] = (UInt32) RTICANMM_MAIN_CAN_copy_N30_RPDO1;



/* N30_RPDO2 */
CANMMCAN_MIDTX[22] = 22; 
((UInt32*) IDPTR_MEM_T)[22] = (UInt32) RTICANMM_MAIN_CAN_copy_N30_RPDO2;



/* N30_RPDO3 */
CANMMCAN_MIDTX[23] = 23; 
((UInt32*) IDPTR_MEM_T)[23] = (UInt32) RTICANMM_MAIN_CAN_copy_N30_RPDO3;



/* N10_TPDO0 */
CANMMCAN_MIDTX[24] = 24; 
((UInt32*) IDPTR_MEM_T)[24] = (UInt32) RTICANMM_MAIN_CAN_copy_N10_TPDO0;



/* N10_TPDO1 */
CANMMCAN_MIDTX[25] = 25; 
((UInt32*) IDPTR_MEM_T)[25] = (UInt32) RTICANMM_MAIN_CAN_copy_N10_TPDO1;



/* N10_TPDO2 */
CANMMCAN_MIDTX[26] = 26; 
((UInt32*) IDPTR_MEM_T)[26] = (UInt32) RTICANMM_MAIN_CAN_copy_N10_TPDO2;



/* N10_TPDO3 */
CANMMCAN_MIDTX[27] = 27; 
((UInt32*) IDPTR_MEM_T)[27] = (UInt32) RTICANMM_MAIN_CAN_copy_N10_TPDO3;



/* N20_TPDO0 */
CANMMCAN_MIDTX[28] = 28; 
((UInt32*) IDPTR_MEM_T)[28] = (UInt32) RTICANMM_MAIN_CAN_copy_N20_TPDO0;



/* N20_TPDO1 */
CANMMCAN_MIDTX[29] = 29; 
((UInt32*) IDPTR_MEM_T)[29] = (UInt32) RTICANMM_MAIN_CAN_copy_N20_TPDO1;



/* N20_TPDO2 */
CANMMCAN_MIDTX[30] = 30; 
((UInt32*) IDPTR_MEM_T)[30] = (UInt32) RTICANMM_MAIN_CAN_copy_N20_TPDO2;



/* N20_TPDO3 */
CANMMCAN_MIDTX[31] = 31; 
((UInt32*) IDPTR_MEM_T)[31] = (UInt32) RTICANMM_MAIN_CAN_copy_N20_TPDO3;



/* N30_TPDO0 */
CANMMCAN_MIDTX[32] = 32; 
((UInt32*) IDPTR_MEM_T)[32] = (UInt32) RTICANMM_MAIN_CAN_copy_N30_TPDO0;



/* N30_TPDO1 */
CANMMCAN_MIDTX[33] = 33; 
((UInt32*) IDPTR_MEM_T)[33] = (UInt32) RTICANMM_MAIN_CAN_copy_N30_TPDO1;



/* N30_TPDO2 */
CANMMCAN_MIDTX[34] = 34; 
((UInt32*) IDPTR_MEM_T)[34] = (UInt32) RTICANMM_MAIN_CAN_copy_N30_TPDO2;



/* N30_TPDO3 */
CANMMCAN_MIDTX[35] = 35; 
((UInt32*) IDPTR_MEM_T)[35] = (UInt32) RTICANMM_MAIN_CAN_copy_N30_TPDO3;



/* SSDO_010 */
CANMMCAN_MIDTX[36] = 36; 
((UInt32*) IDPTR_MEM_T)[36] = (UInt32) RTICANMM_MAIN_CAN_copy_SSDO_010;



/* SSDO_020 */
CANMMCAN_MIDTX[37] = 37; 
((UInt32*) IDPTR_MEM_T)[37] = (UInt32) RTICANMM_MAIN_CAN_copy_SSDO_020;



/* SSDO_030 */
CANMMCAN_MIDTX[38] = 38; 
((UInt32*) IDPTR_MEM_T)[38] = (UInt32) RTICANMM_MAIN_CAN_copy_SSDO_030;



/* CSDO_010 */
CANMMCAN_MIDTX[39] = 39; 
((UInt32*) IDPTR_MEM_T)[39] = (UInt32) RTICANMM_MAIN_CAN_copy_CSDO_010;



/* CSDO_020 */
CANMMCAN_MIDTX[40] = 40; 
((UInt32*) IDPTR_MEM_T)[40] = (UInt32) RTICANMM_MAIN_CAN_copy_CSDO_020;



/* CSDO_030 */
CANMMCAN_MIDTX[41] = 41; 
((UInt32*) IDPTR_MEM_T)[41] = (UInt32) RTICANMM_MAIN_CAN_copy_CSDO_030;



/* DynSDOReq */
CANMMCAN_MIDTX[42] = 42; 
((UInt32*) IDPTR_MEM_T)[42] = (UInt32) RTICANMM_MAIN_CAN_copy_DynSDOReq;



/* HBGuard_010 */
CANMMCAN_MIDTX[43] = 43; 
((UInt32*) IDPTR_MEM_T)[43] = (UInt32) RTICANMM_MAIN_CAN_copy_HBGuard_010;



/* HBGuard_020 */
CANMMCAN_MIDTX[44] = 44; 
((UInt32*) IDPTR_MEM_T)[44] = (UInt32) RTICANMM_MAIN_CAN_copy_HBGuard_020;



/* HBGuard_030 */
CANMMCAN_MIDTX[45] = 45; 
((UInt32*) IDPTR_MEM_T)[45] = (UInt32) RTICANMM_MAIN_CAN_copy_HBGuard_030;



/* LSS_S */
CANMMCAN_MIDTX[46] = 46; 
((UInt32*) IDPTR_MEM_T)[46] = (UInt32) RTICANMM_MAIN_CAN_copy_LSS_S;



/* LSS_M */
CANMMCAN_MIDTX[47] = 47; 
((UInt32*) IDPTR_MEM_T)[47] = (UInt32) RTICANMM_MAIN_CAN_copy_LSS_M;



