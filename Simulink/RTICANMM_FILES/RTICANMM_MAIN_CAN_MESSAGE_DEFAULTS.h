/*****************************************************************************************************************************/
/* RTICANMM_MAIN_CAN_MESSAGE_DEFAULTS */
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

CANMMCAN_MAXMSGPERSTEP = 0;

/* DefaultGlobalEnable */
CANMMCAN_GEIN = 1;


/* Feedthrough debug variable*/
CANMMCAN_FTD = 0;
CANMMCAN_RTVE = 1;


/* CSDO_010 */
CANMMCAN_TXCT[39] = 0; /* TX CycleTime[s] */
CANMMCAN_TXDT[39] = 0; /* TX DelayTime[s] */
CANMMCAN_RXdt[39] = 0; /* RX DeltaTime[s] */
CANMMCAN_RXt[39] = 0.0; /* RX Time[s] */
CANMMCAN_RXerr[39] = 0; /* RX Error */
CANMMCAN_RXLEN[39] = 8; /* RX Message Length */


/* CSDO_020 */
CANMMCAN_TXCT[40] = 0; /* TX CycleTime[s] */
CANMMCAN_TXDT[40] = 0; /* TX DelayTime[s] */
CANMMCAN_RXdt[40] = 0; /* RX DeltaTime[s] */
CANMMCAN_RXt[40] = 0.0; /* RX Time[s] */
CANMMCAN_RXerr[40] = 0; /* RX Error */
CANMMCAN_RXLEN[40] = 8; /* RX Message Length */


/* CSDO_030 */
CANMMCAN_TXCT[41] = 0; /* TX CycleTime[s] */
CANMMCAN_TXDT[41] = 0; /* TX DelayTime[s] */
CANMMCAN_RXdt[41] = 0; /* RX DeltaTime[s] */
CANMMCAN_RXt[41] = 0.0; /* RX Time[s] */
CANMMCAN_RXerr[41] = 0; /* RX Error */
CANMMCAN_RXLEN[41] = 8; /* RX Message Length */


/* DynSDOReq */
CANMMCAN_TXCT[42] = 0; /* TX CycleTime[s] */
CANMMCAN_TXDT[42] = 0; /* TX DelayTime[s] */
CANMMCAN_RXdt[42] = 0; /* RX DeltaTime[s] */
CANMMCAN_RXt[42] = 0.0; /* RX Time[s] */
CANMMCAN_RXerr[42] = 0; /* RX Error */
CANMMCAN_RXLEN[42] = 0; /* RX Message Length */


/* EMCY_010 */
CANMMCAN_TXCT[10] = 0; /* TX CycleTime[s] */
CANMMCAN_TXDT[10] = 0; /* TX DelayTime[s] */
CANMMCAN_RXdt[10] = 0; /* RX DeltaTime[s] */
CANMMCAN_RXt[10] = 0.0; /* RX Time[s] */
CANMMCAN_RXerr[10] = 0; /* RX Error */
CANMMCAN_RXLEN[10] = 8; /* RX Message Length */


/* EMCY_020 */
CANMMCAN_TXCT[11] = 0; /* TX CycleTime[s] */
CANMMCAN_TXDT[11] = 0; /* TX DelayTime[s] */
CANMMCAN_RXdt[11] = 0; /* RX DeltaTime[s] */
CANMMCAN_RXt[11] = 0.0; /* RX Time[s] */
CANMMCAN_RXerr[11] = 0; /* RX Error */
CANMMCAN_RXLEN[11] = 8; /* RX Message Length */


/* EMCY_030 */
CANMMCAN_TXCT[12] = 0; /* TX CycleTime[s] */
CANMMCAN_TXDT[12] = 0; /* TX DelayTime[s] */
CANMMCAN_RXdt[12] = 0; /* RX DeltaTime[s] */
CANMMCAN_RXt[12] = 0.0; /* RX Time[s] */
CANMMCAN_RXerr[12] = 0; /* RX Error */
CANMMCAN_RXLEN[12] = 8; /* RX Message Length */


/* FM_ForceReset */
CANMMCAN_TXCT[7] = 0; /* TX CycleTime[s] */
CANMMCAN_TXDT[7] = 0; /* TX DelayTime[s] */
CANMMCAN_RXdt[7] = 0; /* RX DeltaTime[s] */
CANMMCAN_RXt[7] = 0.0; /* RX Time[s] */
CANMMCAN_RXerr[7] = 0; /* RX Error */
CANMMCAN_RXLEN[7] = 0; /* RX Message Length */


/* FM_MasterPrioLevel */
CANMMCAN_TXCT[2] = 0; /* TX CycleTime[s] */
CANMMCAN_TXDT[2] = 0; /* TX DelayTime[s] */
CANMMCAN_RXdt[2] = 0; /* RX DeltaTime[s] */
CANMMCAN_RXt[2] = 0.0; /* RX Time[s] */
CANMMCAN_RXerr[2] = 0; /* RX Error */
CANMMCAN_RXLEN[2] = 2; /* RX Message Length */


/* FM_ReqMasterCapable */
CANMMCAN_TXCT[6] = 0; /* TX CycleTime[s] */
CANMMCAN_TXDT[6] = 0; /* TX DelayTime[s] */
CANMMCAN_RXdt[6] = 0; /* RX DeltaTime[s] */
CANMMCAN_RXt[6] = 0.0; /* RX Time[s] */
CANMMCAN_RXerr[6] = 0; /* RX Error */
CANMMCAN_RXLEN[6] = 0; /* RX Message Length */


/* FM_ReqPrioLevel */
CANMMCAN_TXCT[4] = 0; /* TX CycleTime[s] */
CANMMCAN_TXDT[4] = 0; /* TX DelayTime[s] */
CANMMCAN_RXdt[4] = 0; /* RX DeltaTime[s] */
CANMMCAN_RXt[4] = 0.0; /* RX Time[s] */
CANMMCAN_RXerr[4] = 0; /* RX Error */
CANMMCAN_RXLEN[4] = 0; /* RX Message Length */


/* FM_RspMasterCapable */
CANMMCAN_TXCT[5] = 0; /* TX CycleTime[s] */
CANMMCAN_TXDT[5] = 0; /* TX DelayTime[s] */
CANMMCAN_RXdt[5] = 0; /* RX DeltaTime[s] */
CANMMCAN_RXt[5] = 0.0; /* RX Time[s] */
CANMMCAN_RXerr[5] = 0; /* RX Error */
CANMMCAN_RXLEN[5] = 0; /* RX Message Length */


/* FM_TriggerTimeSlot */
CANMMCAN_TXCT[3] = 0; /* TX CycleTime[s] */
CANMMCAN_TXDT[3] = 0; /* TX DelayTime[s] */
CANMMCAN_RXdt[3] = 0; /* RX DeltaTime[s] */
CANMMCAN_RXt[3] = 0.0; /* RX Time[s] */
CANMMCAN_RXerr[3] = 0; /* RX Error */
CANMMCAN_RXLEN[3] = 0; /* RX Message Length */


/* GFC */
CANMMCAN_TXCT[1] = 0; /* TX CycleTime[s] */
CANMMCAN_TXDT[1] = 0; /* TX DelayTime[s] */
CANMMCAN_RXdt[1] = 0; /* RX DeltaTime[s] */
CANMMCAN_RXt[1] = 0.0; /* RX Time[s] */
CANMMCAN_RXerr[1] = 0; /* RX Error */
CANMMCAN_RXLEN[1] = 0; /* RX Message Length */


/* HBGuard_010 */
CANMMCAN_TXCT[43] = 0; /* TX CycleTime[s] */
CANMMCAN_TXDT[43] = 0; /* TX DelayTime[s] */
CANMMCAN_RXdt[43] = 0; /* RX DeltaTime[s] */
CANMMCAN_RXt[43] = 0.0; /* RX Time[s] */
CANMMCAN_RXerr[43] = 0; /* RX Error */
CANMMCAN_RXLEN[43] = 1; /* RX Message Length */


/* HBGuard_020 */
CANMMCAN_TXCT[44] = 0; /* TX CycleTime[s] */
CANMMCAN_TXDT[44] = 0; /* TX DelayTime[s] */
CANMMCAN_RXdt[44] = 0; /* RX DeltaTime[s] */
CANMMCAN_RXt[44] = 0.0; /* RX Time[s] */
CANMMCAN_RXerr[44] = 0; /* RX Error */
CANMMCAN_RXLEN[44] = 1; /* RX Message Length */


/* HBGuard_030 */
CANMMCAN_TXCT[45] = 0; /* TX CycleTime[s] */
CANMMCAN_TXDT[45] = 0; /* TX DelayTime[s] */
CANMMCAN_RXdt[45] = 0; /* RX DeltaTime[s] */
CANMMCAN_RXt[45] = 0.0; /* RX Time[s] */
CANMMCAN_RXerr[45] = 0; /* RX Error */
CANMMCAN_RXLEN[45] = 1; /* RX Message Length */


/* LSS_M */
CANMMCAN_TXCT[47] = 0; /* TX CycleTime[s] */
CANMMCAN_TXDT[47] = 0; /* TX DelayTime[s] */
CANMMCAN_RXdt[47] = 0; /* RX DeltaTime[s] */
CANMMCAN_RXt[47] = 0.0; /* RX Time[s] */
CANMMCAN_RXerr[47] = 0; /* RX Error */
CANMMCAN_RXLEN[47] = 8; /* RX Message Length */


/* LSS_S */
CANMMCAN_TXCT[46] = 0; /* TX CycleTime[s] */
CANMMCAN_TXDT[46] = 0; /* TX DelayTime[s] */
CANMMCAN_RXdt[46] = 0; /* RX DeltaTime[s] */
CANMMCAN_RXt[46] = 0.0; /* RX Time[s] */
CANMMCAN_RXerr[46] = 0; /* RX Error */
CANMMCAN_RXLEN[46] = 8; /* RX Message Length */


/* N10_RPDO0 */
CANMMCAN_TXCT[14] = 0; /* TX CycleTime[s] */
CANMMCAN_TXDT[14] = 0; /* TX DelayTime[s] */
CANMMCAN_RXdt[14] = 0; /* RX DeltaTime[s] */
CANMMCAN_RXt[14] = 0.0; /* RX Time[s] */
CANMMCAN_RXerr[14] = 0; /* RX Error */
CANMMCAN_RXLEN[14] = 2; /* RX Message Length */


/* N10_RPDO1 */
CANMMCAN_TXCT[15] = 0; /* TX CycleTime[s] */
CANMMCAN_TXDT[15] = 0; /* TX DelayTime[s] */
CANMMCAN_RXdt[15] = 0; /* RX DeltaTime[s] */
CANMMCAN_RXt[15] = 0.0; /* RX Time[s] */
CANMMCAN_RXerr[15] = 0; /* RX Error */
CANMMCAN_RXLEN[15] = 4; /* RX Message Length */


/* N10_TPDO0 */
CANMMCAN_TXCT[24] = 0; /* TX CycleTime[s] */
CANMMCAN_TXDT[24] = 0; /* TX DelayTime[s] */
CANMMCAN_RXdt[24] = 0; /* RX DeltaTime[s] */
CANMMCAN_RXt[24] = 0.0; /* RX Time[s] */
CANMMCAN_RXerr[24] = 0; /* RX Error */
CANMMCAN_RXLEN[24] = 7; /* RX Message Length */


/* N10_TPDO1 */
CANMMCAN_TXCT[25] = 0; /* TX CycleTime[s] */
CANMMCAN_TXDT[25] = 0; /* TX DelayTime[s] */
CANMMCAN_RXdt[25] = 0; /* RX DeltaTime[s] */
CANMMCAN_RXt[25] = 0.0; /* RX Time[s] */
CANMMCAN_RXerr[25] = 0; /* RX Error */
CANMMCAN_RXLEN[25] = 8; /* RX Message Length */


/* N10_TPDO2 */
CANMMCAN_TXCT[26] = 0; /* TX CycleTime[s] */
CANMMCAN_TXDT[26] = 0; /* TX DelayTime[s] */
CANMMCAN_RXdt[26] = 0; /* RX DeltaTime[s] */
CANMMCAN_RXt[26] = 0.0; /* RX Time[s] */
CANMMCAN_RXerr[26] = 0; /* RX Error */
CANMMCAN_RXLEN[26] = 8; /* RX Message Length */


/* N10_TPDO3 */
CANMMCAN_TXCT[27] = 0; /* TX CycleTime[s] */
CANMMCAN_TXDT[27] = 0; /* TX DelayTime[s] */
CANMMCAN_RXdt[27] = 0; /* RX DeltaTime[s] */
CANMMCAN_RXt[27] = 0.0; /* RX Time[s] */
CANMMCAN_RXerr[27] = 0; /* RX Error */
CANMMCAN_RXLEN[27] = 8; /* RX Message Length */


/* N20_RPDO0 */
CANMMCAN_TXCT[16] = 0; /* TX CycleTime[s] */
CANMMCAN_TXDT[16] = 0; /* TX DelayTime[s] */
CANMMCAN_RXdt[16] = 0; /* RX DeltaTime[s] */
CANMMCAN_RXt[16] = 0.0; /* RX Time[s] */
CANMMCAN_RXerr[16] = 0; /* RX Error */
CANMMCAN_RXLEN[16] = 2; /* RX Message Length */


/* N20_RPDO1 */
CANMMCAN_TXCT[17] = 0; /* TX CycleTime[s] */
CANMMCAN_TXDT[17] = 0; /* TX DelayTime[s] */
CANMMCAN_RXdt[17] = 0; /* RX DeltaTime[s] */
CANMMCAN_RXt[17] = 0.0; /* RX Time[s] */
CANMMCAN_RXerr[17] = 0; /* RX Error */
CANMMCAN_RXLEN[17] = 4; /* RX Message Length */


/* N20_RPDO2 */
CANMMCAN_TXCT[18] = 0; /* TX CycleTime[s] */
CANMMCAN_TXDT[18] = 0; /* TX DelayTime[s] */
CANMMCAN_RXdt[18] = 0; /* RX DeltaTime[s] */
CANMMCAN_RXt[18] = 0.0; /* RX Time[s] */
CANMMCAN_RXerr[18] = 0; /* RX Error */
CANMMCAN_RXLEN[18] = 0; /* RX Message Length */


/* N20_RPDO3 */
CANMMCAN_TXCT[19] = 0; /* TX CycleTime[s] */
CANMMCAN_TXDT[19] = 0; /* TX DelayTime[s] */
CANMMCAN_RXdt[19] = 0; /* RX DeltaTime[s] */
CANMMCAN_RXt[19] = 0.0; /* RX Time[s] */
CANMMCAN_RXerr[19] = 0; /* RX Error */
CANMMCAN_RXLEN[19] = 0; /* RX Message Length */


/* N20_TPDO0 */
CANMMCAN_TXCT[28] = 0; /* TX CycleTime[s] */
CANMMCAN_TXDT[28] = 0; /* TX DelayTime[s] */
CANMMCAN_RXdt[28] = 0; /* RX DeltaTime[s] */
CANMMCAN_RXt[28] = 0.0; /* RX Time[s] */
CANMMCAN_RXerr[28] = 0; /* RX Error */
CANMMCAN_RXLEN[28] = 7; /* RX Message Length */


/* N20_TPDO1 */
CANMMCAN_TXCT[29] = 0; /* TX CycleTime[s] */
CANMMCAN_TXDT[29] = 0; /* TX DelayTime[s] */
CANMMCAN_RXdt[29] = 0; /* RX DeltaTime[s] */
CANMMCAN_RXt[29] = 0.0; /* RX Time[s] */
CANMMCAN_RXerr[29] = 0; /* RX Error */
CANMMCAN_RXLEN[29] = 8; /* RX Message Length */


/* N20_TPDO2 */
CANMMCAN_TXCT[30] = 0; /* TX CycleTime[s] */
CANMMCAN_TXDT[30] = 0; /* TX DelayTime[s] */
CANMMCAN_RXdt[30] = 0; /* RX DeltaTime[s] */
CANMMCAN_RXt[30] = 0.0; /* RX Time[s] */
CANMMCAN_RXerr[30] = 0; /* RX Error */
CANMMCAN_RXLEN[30] = 8; /* RX Message Length */


/* N20_TPDO3 */
CANMMCAN_TXCT[31] = 0; /* TX CycleTime[s] */
CANMMCAN_TXDT[31] = 0; /* TX DelayTime[s] */
CANMMCAN_RXdt[31] = 0; /* RX DeltaTime[s] */
CANMMCAN_RXt[31] = 0.0; /* RX Time[s] */
CANMMCAN_RXerr[31] = 0; /* RX Error */
CANMMCAN_RXLEN[31] = 8; /* RX Message Length */


/* N30_RPDO0 */
CANMMCAN_TXCT[20] = 0; /* TX CycleTime[s] */
CANMMCAN_TXDT[20] = 0; /* TX DelayTime[s] */
CANMMCAN_RXdt[20] = 0; /* RX DeltaTime[s] */
CANMMCAN_RXt[20] = 0.0; /* RX Time[s] */
CANMMCAN_RXerr[20] = 0; /* RX Error */
CANMMCAN_RXLEN[20] = 3; /* RX Message Length */


/* N30_RPDO1 */
CANMMCAN_TXCT[21] = 0; /* TX CycleTime[s] */
CANMMCAN_TXDT[21] = 0; /* TX DelayTime[s] */
CANMMCAN_RXdt[21] = 0; /* RX DeltaTime[s] */
CANMMCAN_RXt[21] = 0.0; /* RX Time[s] */
CANMMCAN_RXerr[21] = 0; /* RX Error */
CANMMCAN_RXLEN[21] = 6; /* RX Message Length */


/* N30_RPDO2 */
CANMMCAN_TXCT[22] = 0; /* TX CycleTime[s] */
CANMMCAN_TXDT[22] = 0; /* TX DelayTime[s] */
CANMMCAN_RXdt[22] = 0; /* RX DeltaTime[s] */
CANMMCAN_RXt[22] = 0.0; /* RX Time[s] */
CANMMCAN_RXerr[22] = 0; /* RX Error */
CANMMCAN_RXLEN[22] = 0; /* RX Message Length */


/* N30_RPDO3 */
CANMMCAN_TXCT[23] = 0; /* TX CycleTime[s] */
CANMMCAN_TXDT[23] = 0; /* TX DelayTime[s] */
CANMMCAN_RXdt[23] = 0; /* RX DeltaTime[s] */
CANMMCAN_RXt[23] = 0.0; /* RX Time[s] */
CANMMCAN_RXerr[23] = 0; /* RX Error */
CANMMCAN_RXLEN[23] = 0; /* RX Message Length */


/* N30_TPDO0 */
CANMMCAN_TXCT[32] = 0; /* TX CycleTime[s] */
CANMMCAN_TXDT[32] = 0; /* TX DelayTime[s] */
CANMMCAN_RXdt[32] = 0; /* RX DeltaTime[s] */
CANMMCAN_RXt[32] = 0.0; /* RX Time[s] */
CANMMCAN_RXerr[32] = 0; /* RX Error */
CANMMCAN_RXLEN[32] = 7; /* RX Message Length */


/* N30_TPDO1 */
CANMMCAN_TXCT[33] = 0; /* TX CycleTime[s] */
CANMMCAN_TXDT[33] = 0; /* TX DelayTime[s] */
CANMMCAN_RXdt[33] = 0; /* RX DeltaTime[s] */
CANMMCAN_RXt[33] = 0.0; /* RX Time[s] */
CANMMCAN_RXerr[33] = 0; /* RX Error */
CANMMCAN_RXLEN[33] = 0; /* RX Message Length */


/* N30_TPDO2 */
CANMMCAN_TXCT[34] = 0; /* TX CycleTime[s] */
CANMMCAN_TXDT[34] = 0; /* TX DelayTime[s] */
CANMMCAN_RXdt[34] = 0; /* RX DeltaTime[s] */
CANMMCAN_RXt[34] = 0.0; /* RX Time[s] */
CANMMCAN_RXerr[34] = 0; /* RX Error */
CANMMCAN_RXLEN[34] = 8; /* RX Message Length */


/* N30_TPDO3 */
CANMMCAN_TXCT[35] = 0; /* TX CycleTime[s] */
CANMMCAN_TXDT[35] = 0; /* TX DelayTime[s] */
CANMMCAN_RXdt[35] = 0; /* RX DeltaTime[s] */
CANMMCAN_RXt[35] = 0.0; /* RX Time[s] */
CANMMCAN_RXerr[35] = 0; /* RX Error */
CANMMCAN_RXLEN[35] = 8; /* RX Message Length */


/* NMTZeroMsg */
CANMMCAN_TXCT[0] = 0; /* TX CycleTime[s] */
CANMMCAN_TXDT[0] = 0; /* TX DelayTime[s] */
CANMMCAN_RXdt[0] = 0; /* RX DeltaTime[s] */
CANMMCAN_RXt[0] = 0.0; /* RX Time[s] */
CANMMCAN_RXerr[0] = 0; /* RX Error */
CANMMCAN_RXLEN[0] = 2; /* RX Message Length */


/* RED_IndicateActiveCANLine */
CANMMCAN_TXCT[8] = 0; /* TX CycleTime[s] */
CANMMCAN_TXDT[8] = 0; /* TX DelayTime[s] */
CANMMCAN_RXdt[8] = 0; /* RX DeltaTime[s] */
CANMMCAN_RXt[8] = 0.0; /* RX Time[s] */
CANMMCAN_RXerr[8] = 0; /* RX Error */
CANMMCAN_RXLEN[8] = 0; /* RX Message Length */


/* SSDO_010 */
CANMMCAN_TXCT[36] = 0; /* TX CycleTime[s] */
CANMMCAN_TXDT[36] = 0; /* TX DelayTime[s] */
CANMMCAN_RXdt[36] = 0; /* RX DeltaTime[s] */
CANMMCAN_RXt[36] = 0.0; /* RX Time[s] */
CANMMCAN_RXerr[36] = 0; /* RX Error */
CANMMCAN_RXLEN[36] = 8; /* RX Message Length */


/* SSDO_020 */
CANMMCAN_TXCT[37] = 0; /* TX CycleTime[s] */
CANMMCAN_TXDT[37] = 0; /* TX DelayTime[s] */
CANMMCAN_RXdt[37] = 0; /* RX DeltaTime[s] */
CANMMCAN_RXt[37] = 0.0; /* RX Time[s] */
CANMMCAN_RXerr[37] = 0; /* RX Error */
CANMMCAN_RXLEN[37] = 8; /* RX Message Length */


/* SSDO_030 */
CANMMCAN_TXCT[38] = 0; /* TX CycleTime[s] */
CANMMCAN_TXDT[38] = 0; /* TX DelayTime[s] */
CANMMCAN_RXdt[38] = 0; /* RX DeltaTime[s] */
CANMMCAN_RXt[38] = 0.0; /* RX Time[s] */
CANMMCAN_RXerr[38] = 0; /* RX Error */
CANMMCAN_RXLEN[38] = 8; /* RX Message Length */


/* SYNC */
CANMMCAN_TXCT[9] = 0; /* TX CycleTime[s] */
CANMMCAN_TXDT[9] = 0; /* TX DelayTime[s] */
CANMMCAN_RXdt[9] = 0; /* RX DeltaTime[s] */
CANMMCAN_RXt[9] = 0.0; /* RX Time[s] */
CANMMCAN_RXerr[9] = 0; /* RX Error */
CANMMCAN_RXLEN[9] = 0; /* RX Message Length */


/* TIME */
CANMMCAN_TXCT[13] = 0; /* TX CycleTime[s] */
CANMMCAN_TXDT[13] = 0; /* TX DelayTime[s] */
CANMMCAN_RXdt[13] = 0; /* RX DeltaTime[s] */
CANMMCAN_RXt[13] = 0.0; /* RX Time[s] */
CANMMCAN_RXerr[13] = 0; /* RX Error */
CANMMCAN_RXLEN[13] = 6; /* RX Message Length */


/* DefaultGlobalEnable TX */
CANMMCAN_TXGEIN = 1;


/* ECU ENABLE */




/* ------------------------------------------------------------------------------ */
/* Message Defaults: */


/* NMTZeroMsg */
CANMMCAN_WBS[0] = 0; /* Would be sent */
CANMMCAN_TXEIN[0] = 1; /* DefaultEnable */
CANMMCAN_TXENIE[0] = 1; /* DefaultEnable */
CANMMCAN_TXCIN[0] = 1; /* DefaultCyclic 0: triggered 1: cyclic */
CANMMCAN_TXCIE[0] = 1; /* DefaultCyclic 0: triggered 1: cyclic */
CANMMCAN_TXKIEXC[0] = 1; /* Check 0: intern and/or extern    1: just intern */
CANMMCAN_TXLEN[0] = 2; /* Message length */
CANMMCAN_TXRBUF[0] = 0; /* internal -> do not change */
CANMMCAN_TXRXBUF[0] = 0; /* internal -> do not change */
CANMMCAN_TXusrm[0] = 1;
CANMMCAN_TXcraw[0] = 0; /* 0: SIGNALS 1:RAWDATA */


/* GFC */
CANMMCAN_WBS[1] = 0; /* Would be sent */
CANMMCAN_TXEIN[1] = 1; /* DefaultEnable */
CANMMCAN_TXENIE[1] = 1; /* DefaultEnable */
CANMMCAN_TXCIN[1] = 1; /* DefaultCyclic 0: triggered 1: cyclic */
CANMMCAN_TXCIE[1] = 1; /* DefaultCyclic 0: triggered 1: cyclic */
CANMMCAN_TXKIEXC[1] = 1; /* Check 0: intern and/or extern    1: just intern */
CANMMCAN_TXLEN[1] = 0; /* Message length */
CANMMCAN_TXRBUF[1] = 0; /* internal -> do not change */
CANMMCAN_TXRXBUF[1] = 0; /* internal -> do not change */
CANMMCAN_TXusrm[1] = 1;
CANMMCAN_TXcraw[1] = 0; /* 0: SIGNALS 1:RAWDATA */


/* FM_MasterPrioLevel */
CANMMCAN_WBS[2] = 0; /* Would be sent */
CANMMCAN_TXEIN[2] = 1; /* DefaultEnable */
CANMMCAN_TXENIE[2] = 1; /* DefaultEnable */
CANMMCAN_TXCIN[2] = 1; /* DefaultCyclic 0: triggered 1: cyclic */
CANMMCAN_TXCIE[2] = 1; /* DefaultCyclic 0: triggered 1: cyclic */
CANMMCAN_TXKIEXC[2] = 1; /* Check 0: intern and/or extern    1: just intern */
CANMMCAN_TXLEN[2] = 2; /* Message length */
CANMMCAN_TXRBUF[2] = 0; /* internal -> do not change */
CANMMCAN_TXRXBUF[2] = 0; /* internal -> do not change */
CANMMCAN_TXusrm[2] = 1;
CANMMCAN_TXcraw[2] = 0; /* 0: SIGNALS 1:RAWDATA */


/* FM_TriggerTimeSlot */
CANMMCAN_WBS[3] = 0; /* Would be sent */
CANMMCAN_TXEIN[3] = 1; /* DefaultEnable */
CANMMCAN_TXENIE[3] = 1; /* DefaultEnable */
CANMMCAN_TXCIN[3] = 1; /* DefaultCyclic 0: triggered 1: cyclic */
CANMMCAN_TXCIE[3] = 1; /* DefaultCyclic 0: triggered 1: cyclic */
CANMMCAN_TXKIEXC[3] = 1; /* Check 0: intern and/or extern    1: just intern */
CANMMCAN_TXLEN[3] = 0; /* Message length */
CANMMCAN_TXRBUF[3] = 0; /* internal -> do not change */
CANMMCAN_TXRXBUF[3] = 0; /* internal -> do not change */
CANMMCAN_TXusrm[3] = 1;
CANMMCAN_TXcraw[3] = 0; /* 0: SIGNALS 1:RAWDATA */


/* FM_ReqPrioLevel */
CANMMCAN_WBS[4] = 0; /* Would be sent */
CANMMCAN_TXEIN[4] = 1; /* DefaultEnable */
CANMMCAN_TXENIE[4] = 1; /* DefaultEnable */
CANMMCAN_TXCIN[4] = 1; /* DefaultCyclic 0: triggered 1: cyclic */
CANMMCAN_TXCIE[4] = 1; /* DefaultCyclic 0: triggered 1: cyclic */
CANMMCAN_TXKIEXC[4] = 1; /* Check 0: intern and/or extern    1: just intern */
CANMMCAN_TXLEN[4] = 0; /* Message length */
CANMMCAN_TXRBUF[4] = 0; /* internal -> do not change */
CANMMCAN_TXRXBUF[4] = 0; /* internal -> do not change */
CANMMCAN_TXusrm[4] = 1;
CANMMCAN_TXcraw[4] = 0; /* 0: SIGNALS 1:RAWDATA */


/* FM_RspMasterCapable */
CANMMCAN_WBS[5] = 0; /* Would be sent */
CANMMCAN_TXEIN[5] = 1; /* DefaultEnable */
CANMMCAN_TXENIE[5] = 1; /* DefaultEnable */
CANMMCAN_TXCIN[5] = 1; /* DefaultCyclic 0: triggered 1: cyclic */
CANMMCAN_TXCIE[5] = 1; /* DefaultCyclic 0: triggered 1: cyclic */
CANMMCAN_TXKIEXC[5] = 1; /* Check 0: intern and/or extern    1: just intern */
CANMMCAN_TXLEN[5] = 0; /* Message length */
CANMMCAN_TXRBUF[5] = 0; /* internal -> do not change */
CANMMCAN_TXRXBUF[5] = 0; /* internal -> do not change */
CANMMCAN_TXusrm[5] = 1;
CANMMCAN_TXcraw[5] = 0; /* 0: SIGNALS 1:RAWDATA */


/* FM_ReqMasterCapable */
CANMMCAN_WBS[6] = 0; /* Would be sent */
CANMMCAN_TXEIN[6] = 1; /* DefaultEnable */
CANMMCAN_TXENIE[6] = 1; /* DefaultEnable */
CANMMCAN_TXCIN[6] = 1; /* DefaultCyclic 0: triggered 1: cyclic */
CANMMCAN_TXCIE[6] = 1; /* DefaultCyclic 0: triggered 1: cyclic */
CANMMCAN_TXKIEXC[6] = 1; /* Check 0: intern and/or extern    1: just intern */
CANMMCAN_TXLEN[6] = 0; /* Message length */
CANMMCAN_TXRBUF[6] = 0; /* internal -> do not change */
CANMMCAN_TXRXBUF[6] = 0; /* internal -> do not change */
CANMMCAN_TXusrm[6] = 1;
CANMMCAN_TXcraw[6] = 0; /* 0: SIGNALS 1:RAWDATA */


/* FM_ForceReset */
CANMMCAN_WBS[7] = 0; /* Would be sent */
CANMMCAN_TXEIN[7] = 1; /* DefaultEnable */
CANMMCAN_TXENIE[7] = 1; /* DefaultEnable */
CANMMCAN_TXCIN[7] = 1; /* DefaultCyclic 0: triggered 1: cyclic */
CANMMCAN_TXCIE[7] = 1; /* DefaultCyclic 0: triggered 1: cyclic */
CANMMCAN_TXKIEXC[7] = 1; /* Check 0: intern and/or extern    1: just intern */
CANMMCAN_TXLEN[7] = 0; /* Message length */
CANMMCAN_TXRBUF[7] = 0; /* internal -> do not change */
CANMMCAN_TXRXBUF[7] = 0; /* internal -> do not change */
CANMMCAN_TXusrm[7] = 1;
CANMMCAN_TXcraw[7] = 0; /* 0: SIGNALS 1:RAWDATA */


/* RED_IndicateActiveCANLine */
CANMMCAN_WBS[8] = 0; /* Would be sent */
CANMMCAN_TXEIN[8] = 1; /* DefaultEnable */
CANMMCAN_TXENIE[8] = 1; /* DefaultEnable */
CANMMCAN_TXCIN[8] = 1; /* DefaultCyclic 0: triggered 1: cyclic */
CANMMCAN_TXCIE[8] = 1; /* DefaultCyclic 0: triggered 1: cyclic */
CANMMCAN_TXKIEXC[8] = 1; /* Check 0: intern and/or extern    1: just intern */
CANMMCAN_TXLEN[8] = 0; /* Message length */
CANMMCAN_TXRBUF[8] = 0; /* internal -> do not change */
CANMMCAN_TXRXBUF[8] = 0; /* internal -> do not change */
CANMMCAN_TXusrm[8] = 1;
CANMMCAN_TXcraw[8] = 0; /* 0: SIGNALS 1:RAWDATA */


/* SYNC */
CANMMCAN_WBS[9] = 0; /* Would be sent */
CANMMCAN_TXEIN[9] = 1; /* DefaultEnable */
CANMMCAN_TXENIE[9] = 1; /* DefaultEnable */
CANMMCAN_TXCIN[9] = 1; /* DefaultCyclic 0: triggered 1: cyclic */
CANMMCAN_TXCIE[9] = 1; /* DefaultCyclic 0: triggered 1: cyclic */
CANMMCAN_TXKIEXC[9] = 1; /* Check 0: intern and/or extern    1: just intern */
CANMMCAN_TXLEN[9] = 0; /* Message length */
CANMMCAN_TXRBUF[9] = 0; /* internal -> do not change */
CANMMCAN_TXRXBUF[9] = 0; /* internal -> do not change */
CANMMCAN_TXusrm[9] = 1;
CANMMCAN_TXcraw[9] = 0; /* 0: SIGNALS 1:RAWDATA */


/* EMCY_010 */
CANMMCAN_WBS[10] = 0; /* Would be sent */
CANMMCAN_TXEIN[10] = 1; /* DefaultEnable */
CANMMCAN_TXENIE[10] = 1; /* DefaultEnable */
CANMMCAN_TXCIN[10] = 1; /* DefaultCyclic 0: triggered 1: cyclic */
CANMMCAN_TXCIE[10] = 1; /* DefaultCyclic 0: triggered 1: cyclic */
CANMMCAN_TXKIEXC[10] = 1; /* Check 0: intern and/or extern    1: just intern */
CANMMCAN_TXLEN[10] = 8; /* Message length */
CANMMCAN_TXRBUF[10] = 0; /* internal -> do not change */
CANMMCAN_TXRXBUF[10] = 0; /* internal -> do not change */
CANMMCAN_TXusrm[10] = 1;
CANMMCAN_TXcraw[10] = 0; /* 0: SIGNALS 1:RAWDATA */


/* EMCY_020 */
CANMMCAN_WBS[11] = 0; /* Would be sent */
CANMMCAN_TXEIN[11] = 1; /* DefaultEnable */
CANMMCAN_TXENIE[11] = 1; /* DefaultEnable */
CANMMCAN_TXCIN[11] = 1; /* DefaultCyclic 0: triggered 1: cyclic */
CANMMCAN_TXCIE[11] = 1; /* DefaultCyclic 0: triggered 1: cyclic */
CANMMCAN_TXKIEXC[11] = 1; /* Check 0: intern and/or extern    1: just intern */
CANMMCAN_TXLEN[11] = 8; /* Message length */
CANMMCAN_TXRBUF[11] = 0; /* internal -> do not change */
CANMMCAN_TXRXBUF[11] = 0; /* internal -> do not change */
CANMMCAN_TXusrm[11] = 1;
CANMMCAN_TXcraw[11] = 0; /* 0: SIGNALS 1:RAWDATA */


/* EMCY_030 */
CANMMCAN_WBS[12] = 0; /* Would be sent */
CANMMCAN_TXEIN[12] = 1; /* DefaultEnable */
CANMMCAN_TXENIE[12] = 1; /* DefaultEnable */
CANMMCAN_TXCIN[12] = 1; /* DefaultCyclic 0: triggered 1: cyclic */
CANMMCAN_TXCIE[12] = 1; /* DefaultCyclic 0: triggered 1: cyclic */
CANMMCAN_TXKIEXC[12] = 1; /* Check 0: intern and/or extern    1: just intern */
CANMMCAN_TXLEN[12] = 8; /* Message length */
CANMMCAN_TXRBUF[12] = 0; /* internal -> do not change */
CANMMCAN_TXRXBUF[12] = 0; /* internal -> do not change */
CANMMCAN_TXusrm[12] = 1;
CANMMCAN_TXcraw[12] = 0; /* 0: SIGNALS 1:RAWDATA */


/* TIME */
CANMMCAN_WBS[13] = 0; /* Would be sent */
CANMMCAN_TXEIN[13] = 1; /* DefaultEnable */
CANMMCAN_TXENIE[13] = 1; /* DefaultEnable */
CANMMCAN_TXCIN[13] = 1; /* DefaultCyclic 0: triggered 1: cyclic */
CANMMCAN_TXCIE[13] = 1; /* DefaultCyclic 0: triggered 1: cyclic */
CANMMCAN_TXKIEXC[13] = 1; /* Check 0: intern and/or extern    1: just intern */
CANMMCAN_TXLEN[13] = 6; /* Message length */
CANMMCAN_TXRBUF[13] = 0; /* internal -> do not change */
CANMMCAN_TXRXBUF[13] = 0; /* internal -> do not change */
CANMMCAN_TXusrm[13] = 1;
CANMMCAN_TXcraw[13] = 0; /* 0: SIGNALS 1:RAWDATA */


/* N10_RPDO0 */
CANMMCAN_WBS[14] = 0; /* Would be sent */
CANMMCAN_TXEIN[14] = 1; /* DefaultEnable */
CANMMCAN_TXENIE[14] = 1; /* DefaultEnable */
CANMMCAN_TXCIN[14] = 1; /* DefaultCyclic 0: triggered 1: cyclic */
CANMMCAN_TXCIE[14] = 1; /* DefaultCyclic 0: triggered 1: cyclic */
CANMMCAN_TXKIEXC[14] = 1; /* Check 0: intern and/or extern    1: just intern */
CANMMCAN_TXLEN[14] = 2; /* Message length */
CANMMCAN_TXRBUF[14] = 0; /* internal -> do not change */
CANMMCAN_TXRXBUF[14] = 0; /* internal -> do not change */
CANMMCAN_TXusrm[14] = 1;
CANMMCAN_TXcraw[14] = 0; /* 0: SIGNALS 1:RAWDATA */


/* N10_RPDO1 */
CANMMCAN_WBS[15] = 0; /* Would be sent */
CANMMCAN_TXEIN[15] = 1; /* DefaultEnable */
CANMMCAN_TXENIE[15] = 1; /* DefaultEnable */
CANMMCAN_TXCIN[15] = 1; /* DefaultCyclic 0: triggered 1: cyclic */
CANMMCAN_TXCIE[15] = 1; /* DefaultCyclic 0: triggered 1: cyclic */
CANMMCAN_TXKIEXC[15] = 1; /* Check 0: intern and/or extern    1: just intern */
CANMMCAN_TXLEN[15] = 4; /* Message length */
CANMMCAN_TXRBUF[15] = 0; /* internal -> do not change */
CANMMCAN_TXRXBUF[15] = 0; /* internal -> do not change */
CANMMCAN_TXusrm[15] = 1;
CANMMCAN_TXcraw[15] = 0; /* 0: SIGNALS 1:RAWDATA */


/* N20_RPDO0 */
CANMMCAN_WBS[16] = 0; /* Would be sent */
CANMMCAN_TXEIN[16] = 1; /* DefaultEnable */
CANMMCAN_TXENIE[16] = 1; /* DefaultEnable */
CANMMCAN_TXCIN[16] = 1; /* DefaultCyclic 0: triggered 1: cyclic */
CANMMCAN_TXCIE[16] = 1; /* DefaultCyclic 0: triggered 1: cyclic */
CANMMCAN_TXKIEXC[16] = 1; /* Check 0: intern and/or extern    1: just intern */
CANMMCAN_TXLEN[16] = 2; /* Message length */
CANMMCAN_TXRBUF[16] = 0; /* internal -> do not change */
CANMMCAN_TXRXBUF[16] = 0; /* internal -> do not change */
CANMMCAN_TXusrm[16] = 1;
CANMMCAN_TXcraw[16] = 0; /* 0: SIGNALS 1:RAWDATA */


/* N20_RPDO1 */
CANMMCAN_WBS[17] = 0; /* Would be sent */
CANMMCAN_TXEIN[17] = 1; /* DefaultEnable */
CANMMCAN_TXENIE[17] = 1; /* DefaultEnable */
CANMMCAN_TXCIN[17] = 1; /* DefaultCyclic 0: triggered 1: cyclic */
CANMMCAN_TXCIE[17] = 1; /* DefaultCyclic 0: triggered 1: cyclic */
CANMMCAN_TXKIEXC[17] = 1; /* Check 0: intern and/or extern    1: just intern */
CANMMCAN_TXLEN[17] = 4; /* Message length */
CANMMCAN_TXRBUF[17] = 0; /* internal -> do not change */
CANMMCAN_TXRXBUF[17] = 0; /* internal -> do not change */
CANMMCAN_TXusrm[17] = 1;
CANMMCAN_TXcraw[17] = 0; /* 0: SIGNALS 1:RAWDATA */


/* N20_RPDO2 */
CANMMCAN_WBS[18] = 0; /* Would be sent */
CANMMCAN_TXEIN[18] = 1; /* DefaultEnable */
CANMMCAN_TXENIE[18] = 1; /* DefaultEnable */
CANMMCAN_TXCIN[18] = 1; /* DefaultCyclic 0: triggered 1: cyclic */
CANMMCAN_TXCIE[18] = 1; /* DefaultCyclic 0: triggered 1: cyclic */
CANMMCAN_TXKIEXC[18] = 1; /* Check 0: intern and/or extern    1: just intern */
CANMMCAN_TXLEN[18] = 0; /* Message length */
CANMMCAN_TXRBUF[18] = 0; /* internal -> do not change */
CANMMCAN_TXRXBUF[18] = 0; /* internal -> do not change */
CANMMCAN_TXusrm[18] = 1;
CANMMCAN_TXcraw[18] = 0; /* 0: SIGNALS 1:RAWDATA */


/* N20_RPDO3 */
CANMMCAN_WBS[19] = 0; /* Would be sent */
CANMMCAN_TXEIN[19] = 1; /* DefaultEnable */
CANMMCAN_TXENIE[19] = 1; /* DefaultEnable */
CANMMCAN_TXCIN[19] = 1; /* DefaultCyclic 0: triggered 1: cyclic */
CANMMCAN_TXCIE[19] = 1; /* DefaultCyclic 0: triggered 1: cyclic */
CANMMCAN_TXKIEXC[19] = 1; /* Check 0: intern and/or extern    1: just intern */
CANMMCAN_TXLEN[19] = 0; /* Message length */
CANMMCAN_TXRBUF[19] = 0; /* internal -> do not change */
CANMMCAN_TXRXBUF[19] = 0; /* internal -> do not change */
CANMMCAN_TXusrm[19] = 1;
CANMMCAN_TXcraw[19] = 0; /* 0: SIGNALS 1:RAWDATA */


/* N30_RPDO0 */
CANMMCAN_WBS[20] = 0; /* Would be sent */
CANMMCAN_TXEIN[20] = 1; /* DefaultEnable */
CANMMCAN_TXENIE[20] = 1; /* DefaultEnable */
CANMMCAN_TXCIN[20] = 1; /* DefaultCyclic 0: triggered 1: cyclic */
CANMMCAN_TXCIE[20] = 1; /* DefaultCyclic 0: triggered 1: cyclic */
CANMMCAN_TXKIEXC[20] = 1; /* Check 0: intern and/or extern    1: just intern */
CANMMCAN_TXLEN[20] = 3; /* Message length */
CANMMCAN_TXRBUF[20] = 0; /* internal -> do not change */
CANMMCAN_TXRXBUF[20] = 0; /* internal -> do not change */
CANMMCAN_TXusrm[20] = 1;
CANMMCAN_TXcraw[20] = 0; /* 0: SIGNALS 1:RAWDATA */


/* N30_RPDO1 */
CANMMCAN_WBS[21] = 0; /* Would be sent */
CANMMCAN_TXEIN[21] = 1; /* DefaultEnable */
CANMMCAN_TXENIE[21] = 1; /* DefaultEnable */
CANMMCAN_TXCIN[21] = 1; /* DefaultCyclic 0: triggered 1: cyclic */
CANMMCAN_TXCIE[21] = 1; /* DefaultCyclic 0: triggered 1: cyclic */
CANMMCAN_TXKIEXC[21] = 1; /* Check 0: intern and/or extern    1: just intern */
CANMMCAN_TXLEN[21] = 6; /* Message length */
CANMMCAN_TXRBUF[21] = 0; /* internal -> do not change */
CANMMCAN_TXRXBUF[21] = 0; /* internal -> do not change */
CANMMCAN_TXusrm[21] = 1;
CANMMCAN_TXcraw[21] = 0; /* 0: SIGNALS 1:RAWDATA */


/* N30_RPDO2 */
CANMMCAN_WBS[22] = 0; /* Would be sent */
CANMMCAN_TXEIN[22] = 1; /* DefaultEnable */
CANMMCAN_TXENIE[22] = 1; /* DefaultEnable */
CANMMCAN_TXCIN[22] = 1; /* DefaultCyclic 0: triggered 1: cyclic */
CANMMCAN_TXCIE[22] = 1; /* DefaultCyclic 0: triggered 1: cyclic */
CANMMCAN_TXKIEXC[22] = 1; /* Check 0: intern and/or extern    1: just intern */
CANMMCAN_TXLEN[22] = 0; /* Message length */
CANMMCAN_TXRBUF[22] = 0; /* internal -> do not change */
CANMMCAN_TXRXBUF[22] = 0; /* internal -> do not change */
CANMMCAN_TXusrm[22] = 1;
CANMMCAN_TXcraw[22] = 0; /* 0: SIGNALS 1:RAWDATA */


/* N30_RPDO3 */
CANMMCAN_WBS[23] = 0; /* Would be sent */
CANMMCAN_TXEIN[23] = 1; /* DefaultEnable */
CANMMCAN_TXENIE[23] = 1; /* DefaultEnable */
CANMMCAN_TXCIN[23] = 1; /* DefaultCyclic 0: triggered 1: cyclic */
CANMMCAN_TXCIE[23] = 1; /* DefaultCyclic 0: triggered 1: cyclic */
CANMMCAN_TXKIEXC[23] = 1; /* Check 0: intern and/or extern    1: just intern */
CANMMCAN_TXLEN[23] = 0; /* Message length */
CANMMCAN_TXRBUF[23] = 0; /* internal -> do not change */
CANMMCAN_TXRXBUF[23] = 0; /* internal -> do not change */
CANMMCAN_TXusrm[23] = 1;
CANMMCAN_TXcraw[23] = 0; /* 0: SIGNALS 1:RAWDATA */


/* N10_TPDO0 */
CANMMCAN_WBS[24] = 0; /* Would be sent */
CANMMCAN_TXEIN[24] = 1; /* DefaultEnable */
CANMMCAN_TXENIE[24] = 1; /* DefaultEnable */
CANMMCAN_TXCIN[24] = 1; /* DefaultCyclic 0: triggered 1: cyclic */
CANMMCAN_TXCIE[24] = 1; /* DefaultCyclic 0: triggered 1: cyclic */
CANMMCAN_TXKIEXC[24] = 1; /* Check 0: intern and/or extern    1: just intern */
CANMMCAN_TXLEN[24] = 7; /* Message length */
CANMMCAN_TXRBUF[24] = 0; /* internal -> do not change */
CANMMCAN_TXRXBUF[24] = 0; /* internal -> do not change */
CANMMCAN_TXusrm[24] = 1;
CANMMCAN_TXcraw[24] = 0; /* 0: SIGNALS 1:RAWDATA */


/* N10_TPDO1 */
CANMMCAN_WBS[25] = 0; /* Would be sent */
CANMMCAN_TXEIN[25] = 1; /* DefaultEnable */
CANMMCAN_TXENIE[25] = 1; /* DefaultEnable */
CANMMCAN_TXCIN[25] = 1; /* DefaultCyclic 0: triggered 1: cyclic */
CANMMCAN_TXCIE[25] = 1; /* DefaultCyclic 0: triggered 1: cyclic */
CANMMCAN_TXKIEXC[25] = 1; /* Check 0: intern and/or extern    1: just intern */
CANMMCAN_TXLEN[25] = 8; /* Message length */
CANMMCAN_TXRBUF[25] = 0; /* internal -> do not change */
CANMMCAN_TXRXBUF[25] = 0; /* internal -> do not change */
CANMMCAN_TXusrm[25] = 1;
CANMMCAN_TXcraw[25] = 0; /* 0: SIGNALS 1:RAWDATA */


/* N10_TPDO2 */
CANMMCAN_WBS[26] = 0; /* Would be sent */
CANMMCAN_TXEIN[26] = 1; /* DefaultEnable */
CANMMCAN_TXENIE[26] = 1; /* DefaultEnable */
CANMMCAN_TXCIN[26] = 1; /* DefaultCyclic 0: triggered 1: cyclic */
CANMMCAN_TXCIE[26] = 1; /* DefaultCyclic 0: triggered 1: cyclic */
CANMMCAN_TXKIEXC[26] = 1; /* Check 0: intern and/or extern    1: just intern */
CANMMCAN_TXLEN[26] = 8; /* Message length */
CANMMCAN_TXRBUF[26] = 0; /* internal -> do not change */
CANMMCAN_TXRXBUF[26] = 0; /* internal -> do not change */
CANMMCAN_TXusrm[26] = 1;
CANMMCAN_TXcraw[26] = 0; /* 0: SIGNALS 1:RAWDATA */


/* N10_TPDO3 */
CANMMCAN_WBS[27] = 0; /* Would be sent */
CANMMCAN_TXEIN[27] = 1; /* DefaultEnable */
CANMMCAN_TXENIE[27] = 1; /* DefaultEnable */
CANMMCAN_TXCIN[27] = 1; /* DefaultCyclic 0: triggered 1: cyclic */
CANMMCAN_TXCIE[27] = 1; /* DefaultCyclic 0: triggered 1: cyclic */
CANMMCAN_TXKIEXC[27] = 1; /* Check 0: intern and/or extern    1: just intern */
CANMMCAN_TXLEN[27] = 8; /* Message length */
CANMMCAN_TXRBUF[27] = 0; /* internal -> do not change */
CANMMCAN_TXRXBUF[27] = 0; /* internal -> do not change */
CANMMCAN_TXusrm[27] = 1;
CANMMCAN_TXcraw[27] = 0; /* 0: SIGNALS 1:RAWDATA */


/* N20_TPDO0 */
CANMMCAN_WBS[28] = 0; /* Would be sent */
CANMMCAN_TXEIN[28] = 1; /* DefaultEnable */
CANMMCAN_TXENIE[28] = 1; /* DefaultEnable */
CANMMCAN_TXCIN[28] = 1; /* DefaultCyclic 0: triggered 1: cyclic */
CANMMCAN_TXCIE[28] = 1; /* DefaultCyclic 0: triggered 1: cyclic */
CANMMCAN_TXKIEXC[28] = 1; /* Check 0: intern and/or extern    1: just intern */
CANMMCAN_TXLEN[28] = 7; /* Message length */
CANMMCAN_TXRBUF[28] = 0; /* internal -> do not change */
CANMMCAN_TXRXBUF[28] = 0; /* internal -> do not change */
CANMMCAN_TXusrm[28] = 1;
CANMMCAN_TXcraw[28] = 0; /* 0: SIGNALS 1:RAWDATA */


/* N20_TPDO1 */
CANMMCAN_WBS[29] = 0; /* Would be sent */
CANMMCAN_TXEIN[29] = 1; /* DefaultEnable */
CANMMCAN_TXENIE[29] = 1; /* DefaultEnable */
CANMMCAN_TXCIN[29] = 1; /* DefaultCyclic 0: triggered 1: cyclic */
CANMMCAN_TXCIE[29] = 1; /* DefaultCyclic 0: triggered 1: cyclic */
CANMMCAN_TXKIEXC[29] = 1; /* Check 0: intern and/or extern    1: just intern */
CANMMCAN_TXLEN[29] = 8; /* Message length */
CANMMCAN_TXRBUF[29] = 0; /* internal -> do not change */
CANMMCAN_TXRXBUF[29] = 0; /* internal -> do not change */
CANMMCAN_TXusrm[29] = 1;
CANMMCAN_TXcraw[29] = 0; /* 0: SIGNALS 1:RAWDATA */


/* N20_TPDO2 */
CANMMCAN_WBS[30] = 0; /* Would be sent */
CANMMCAN_TXEIN[30] = 1; /* DefaultEnable */
CANMMCAN_TXENIE[30] = 1; /* DefaultEnable */
CANMMCAN_TXCIN[30] = 1; /* DefaultCyclic 0: triggered 1: cyclic */
CANMMCAN_TXCIE[30] = 1; /* DefaultCyclic 0: triggered 1: cyclic */
CANMMCAN_TXKIEXC[30] = 1; /* Check 0: intern and/or extern    1: just intern */
CANMMCAN_TXLEN[30] = 8; /* Message length */
CANMMCAN_TXRBUF[30] = 0; /* internal -> do not change */
CANMMCAN_TXRXBUF[30] = 0; /* internal -> do not change */
CANMMCAN_TXusrm[30] = 1;
CANMMCAN_TXcraw[30] = 0; /* 0: SIGNALS 1:RAWDATA */


/* N20_TPDO3 */
CANMMCAN_WBS[31] = 0; /* Would be sent */
CANMMCAN_TXEIN[31] = 1; /* DefaultEnable */
CANMMCAN_TXENIE[31] = 1; /* DefaultEnable */
CANMMCAN_TXCIN[31] = 1; /* DefaultCyclic 0: triggered 1: cyclic */
CANMMCAN_TXCIE[31] = 1; /* DefaultCyclic 0: triggered 1: cyclic */
CANMMCAN_TXKIEXC[31] = 1; /* Check 0: intern and/or extern    1: just intern */
CANMMCAN_TXLEN[31] = 8; /* Message length */
CANMMCAN_TXRBUF[31] = 0; /* internal -> do not change */
CANMMCAN_TXRXBUF[31] = 0; /* internal -> do not change */
CANMMCAN_TXusrm[31] = 1;
CANMMCAN_TXcraw[31] = 0; /* 0: SIGNALS 1:RAWDATA */


/* N30_TPDO0 */
CANMMCAN_WBS[32] = 0; /* Would be sent */
CANMMCAN_TXEIN[32] = 1; /* DefaultEnable */
CANMMCAN_TXENIE[32] = 1; /* DefaultEnable */
CANMMCAN_TXCIN[32] = 1; /* DefaultCyclic 0: triggered 1: cyclic */
CANMMCAN_TXCIE[32] = 1; /* DefaultCyclic 0: triggered 1: cyclic */
CANMMCAN_TXKIEXC[32] = 1; /* Check 0: intern and/or extern    1: just intern */
CANMMCAN_TXLEN[32] = 7; /* Message length */
CANMMCAN_TXRBUF[32] = 0; /* internal -> do not change */
CANMMCAN_TXRXBUF[32] = 0; /* internal -> do not change */
CANMMCAN_TXusrm[32] = 1;
CANMMCAN_TXcraw[32] = 0; /* 0: SIGNALS 1:RAWDATA */


/* N30_TPDO1 */
CANMMCAN_WBS[33] = 0; /* Would be sent */
CANMMCAN_TXEIN[33] = 1; /* DefaultEnable */
CANMMCAN_TXENIE[33] = 1; /* DefaultEnable */
CANMMCAN_TXCIN[33] = 1; /* DefaultCyclic 0: triggered 1: cyclic */
CANMMCAN_TXCIE[33] = 1; /* DefaultCyclic 0: triggered 1: cyclic */
CANMMCAN_TXKIEXC[33] = 1; /* Check 0: intern and/or extern    1: just intern */
CANMMCAN_TXLEN[33] = 0; /* Message length */
CANMMCAN_TXRBUF[33] = 0; /* internal -> do not change */
CANMMCAN_TXRXBUF[33] = 0; /* internal -> do not change */
CANMMCAN_TXusrm[33] = 1;
CANMMCAN_TXcraw[33] = 0; /* 0: SIGNALS 1:RAWDATA */


/* N30_TPDO2 */
CANMMCAN_WBS[34] = 0; /* Would be sent */
CANMMCAN_TXEIN[34] = 1; /* DefaultEnable */
CANMMCAN_TXENIE[34] = 1; /* DefaultEnable */
CANMMCAN_TXCIN[34] = 1; /* DefaultCyclic 0: triggered 1: cyclic */
CANMMCAN_TXCIE[34] = 1; /* DefaultCyclic 0: triggered 1: cyclic */
CANMMCAN_TXKIEXC[34] = 1; /* Check 0: intern and/or extern    1: just intern */
CANMMCAN_TXLEN[34] = 8; /* Message length */
CANMMCAN_TXRBUF[34] = 0; /* internal -> do not change */
CANMMCAN_TXRXBUF[34] = 0; /* internal -> do not change */
CANMMCAN_TXusrm[34] = 1;
CANMMCAN_TXcraw[34] = 0; /* 0: SIGNALS 1:RAWDATA */


/* N30_TPDO3 */
CANMMCAN_WBS[35] = 0; /* Would be sent */
CANMMCAN_TXEIN[35] = 1; /* DefaultEnable */
CANMMCAN_TXENIE[35] = 1; /* DefaultEnable */
CANMMCAN_TXCIN[35] = 1; /* DefaultCyclic 0: triggered 1: cyclic */
CANMMCAN_TXCIE[35] = 1; /* DefaultCyclic 0: triggered 1: cyclic */
CANMMCAN_TXKIEXC[35] = 1; /* Check 0: intern and/or extern    1: just intern */
CANMMCAN_TXLEN[35] = 8; /* Message length */
CANMMCAN_TXRBUF[35] = 0; /* internal -> do not change */
CANMMCAN_TXRXBUF[35] = 0; /* internal -> do not change */
CANMMCAN_TXusrm[35] = 1;
CANMMCAN_TXcraw[35] = 0; /* 0: SIGNALS 1:RAWDATA */


/* SSDO_010 */
CANMMCAN_WBS[36] = 0; /* Would be sent */
CANMMCAN_TXEIN[36] = 1; /* DefaultEnable */
CANMMCAN_TXENIE[36] = 1; /* DefaultEnable */
CANMMCAN_TXCIN[36] = 1; /* DefaultCyclic 0: triggered 1: cyclic */
CANMMCAN_TXCIE[36] = 1; /* DefaultCyclic 0: triggered 1: cyclic */
CANMMCAN_TXKIEXC[36] = 1; /* Check 0: intern and/or extern    1: just intern */
CANMMCAN_TXLEN[36] = 8; /* Message length */
CANMMCAN_TXRBUF[36] = 0; /* internal -> do not change */
CANMMCAN_TXRXBUF[36] = 0; /* internal -> do not change */
CANMMCAN_TXusrm[36] = 1;
CANMMCAN_TXcraw[36] = 0; /* 0: SIGNALS 1:RAWDATA */


/* SSDO_020 */
CANMMCAN_WBS[37] = 0; /* Would be sent */
CANMMCAN_TXEIN[37] = 1; /* DefaultEnable */
CANMMCAN_TXENIE[37] = 1; /* DefaultEnable */
CANMMCAN_TXCIN[37] = 1; /* DefaultCyclic 0: triggered 1: cyclic */
CANMMCAN_TXCIE[37] = 1; /* DefaultCyclic 0: triggered 1: cyclic */
CANMMCAN_TXKIEXC[37] = 1; /* Check 0: intern and/or extern    1: just intern */
CANMMCAN_TXLEN[37] = 8; /* Message length */
CANMMCAN_TXRBUF[37] = 0; /* internal -> do not change */
CANMMCAN_TXRXBUF[37] = 0; /* internal -> do not change */
CANMMCAN_TXusrm[37] = 1;
CANMMCAN_TXcraw[37] = 0; /* 0: SIGNALS 1:RAWDATA */


/* SSDO_030 */
CANMMCAN_WBS[38] = 0; /* Would be sent */
CANMMCAN_TXEIN[38] = 1; /* DefaultEnable */
CANMMCAN_TXENIE[38] = 1; /* DefaultEnable */
CANMMCAN_TXCIN[38] = 1; /* DefaultCyclic 0: triggered 1: cyclic */
CANMMCAN_TXCIE[38] = 1; /* DefaultCyclic 0: triggered 1: cyclic */
CANMMCAN_TXKIEXC[38] = 1; /* Check 0: intern and/or extern    1: just intern */
CANMMCAN_TXLEN[38] = 8; /* Message length */
CANMMCAN_TXRBUF[38] = 0; /* internal -> do not change */
CANMMCAN_TXRXBUF[38] = 0; /* internal -> do not change */
CANMMCAN_TXusrm[38] = 1;
CANMMCAN_TXcraw[38] = 0; /* 0: SIGNALS 1:RAWDATA */


/* CSDO_010 */
CANMMCAN_WBS[39] = 0; /* Would be sent */
CANMMCAN_TXEIN[39] = 1; /* DefaultEnable */
CANMMCAN_TXENIE[39] = 1; /* DefaultEnable */
CANMMCAN_TXCIN[39] = 1; /* DefaultCyclic 0: triggered 1: cyclic */
CANMMCAN_TXCIE[39] = 1; /* DefaultCyclic 0: triggered 1: cyclic */
CANMMCAN_TXKIEXC[39] = 1; /* Check 0: intern and/or extern    1: just intern */
CANMMCAN_TXLEN[39] = 8; /* Message length */
CANMMCAN_TXRBUF[39] = 0; /* internal -> do not change */
CANMMCAN_TXRXBUF[39] = 0; /* internal -> do not change */
CANMMCAN_TXusrm[39] = 1;
CANMMCAN_TXcraw[39] = 0; /* 0: SIGNALS 1:RAWDATA */


/* CSDO_020 */
CANMMCAN_WBS[40] = 0; /* Would be sent */
CANMMCAN_TXEIN[40] = 1; /* DefaultEnable */
CANMMCAN_TXENIE[40] = 1; /* DefaultEnable */
CANMMCAN_TXCIN[40] = 1; /* DefaultCyclic 0: triggered 1: cyclic */
CANMMCAN_TXCIE[40] = 1; /* DefaultCyclic 0: triggered 1: cyclic */
CANMMCAN_TXKIEXC[40] = 1; /* Check 0: intern and/or extern    1: just intern */
CANMMCAN_TXLEN[40] = 8; /* Message length */
CANMMCAN_TXRBUF[40] = 0; /* internal -> do not change */
CANMMCAN_TXRXBUF[40] = 0; /* internal -> do not change */
CANMMCAN_TXusrm[40] = 1;
CANMMCAN_TXcraw[40] = 0; /* 0: SIGNALS 1:RAWDATA */


/* CSDO_030 */
CANMMCAN_WBS[41] = 0; /* Would be sent */
CANMMCAN_TXEIN[41] = 1; /* DefaultEnable */
CANMMCAN_TXENIE[41] = 1; /* DefaultEnable */
CANMMCAN_TXCIN[41] = 1; /* DefaultCyclic 0: triggered 1: cyclic */
CANMMCAN_TXCIE[41] = 1; /* DefaultCyclic 0: triggered 1: cyclic */
CANMMCAN_TXKIEXC[41] = 1; /* Check 0: intern and/or extern    1: just intern */
CANMMCAN_TXLEN[41] = 8; /* Message length */
CANMMCAN_TXRBUF[41] = 0; /* internal -> do not change */
CANMMCAN_TXRXBUF[41] = 0; /* internal -> do not change */
CANMMCAN_TXusrm[41] = 1;
CANMMCAN_TXcraw[41] = 0; /* 0: SIGNALS 1:RAWDATA */


/* DynSDOReq */
CANMMCAN_WBS[42] = 0; /* Would be sent */
CANMMCAN_TXEIN[42] = 1; /* DefaultEnable */
CANMMCAN_TXENIE[42] = 1; /* DefaultEnable */
CANMMCAN_TXCIN[42] = 1; /* DefaultCyclic 0: triggered 1: cyclic */
CANMMCAN_TXCIE[42] = 1; /* DefaultCyclic 0: triggered 1: cyclic */
CANMMCAN_TXKIEXC[42] = 1; /* Check 0: intern and/or extern    1: just intern */
CANMMCAN_TXLEN[42] = 0; /* Message length */
CANMMCAN_TXRBUF[42] = 0; /* internal -> do not change */
CANMMCAN_TXRXBUF[42] = 0; /* internal -> do not change */
CANMMCAN_TXusrm[42] = 1;
CANMMCAN_TXcraw[42] = 0; /* 0: SIGNALS 1:RAWDATA */


/* HBGuard_010 */
CANMMCAN_WBS[43] = 0; /* Would be sent */
CANMMCAN_TXEIN[43] = 1; /* DefaultEnable */
CANMMCAN_TXENIE[43] = 1; /* DefaultEnable */
CANMMCAN_TXCIN[43] = 1; /* DefaultCyclic 0: triggered 1: cyclic */
CANMMCAN_TXCIE[43] = 1; /* DefaultCyclic 0: triggered 1: cyclic */
CANMMCAN_TXKIEXC[43] = 1; /* Check 0: intern and/or extern    1: just intern */
CANMMCAN_TXLEN[43] = 1; /* Message length */
CANMMCAN_TXRBUF[43] = 0; /* internal -> do not change */
CANMMCAN_TXRXBUF[43] = 0; /* internal -> do not change */
CANMMCAN_TXusrm[43] = 1;
CANMMCAN_TXcraw[43] = 0; /* 0: SIGNALS 1:RAWDATA */


/* HBGuard_020 */
CANMMCAN_WBS[44] = 0; /* Would be sent */
CANMMCAN_TXEIN[44] = 1; /* DefaultEnable */
CANMMCAN_TXENIE[44] = 1; /* DefaultEnable */
CANMMCAN_TXCIN[44] = 1; /* DefaultCyclic 0: triggered 1: cyclic */
CANMMCAN_TXCIE[44] = 1; /* DefaultCyclic 0: triggered 1: cyclic */
CANMMCAN_TXKIEXC[44] = 1; /* Check 0: intern and/or extern    1: just intern */
CANMMCAN_TXLEN[44] = 1; /* Message length */
CANMMCAN_TXRBUF[44] = 0; /* internal -> do not change */
CANMMCAN_TXRXBUF[44] = 0; /* internal -> do not change */
CANMMCAN_TXusrm[44] = 1;
CANMMCAN_TXcraw[44] = 0; /* 0: SIGNALS 1:RAWDATA */


/* HBGuard_030 */
CANMMCAN_WBS[45] = 0; /* Would be sent */
CANMMCAN_TXEIN[45] = 1; /* DefaultEnable */
CANMMCAN_TXENIE[45] = 1; /* DefaultEnable */
CANMMCAN_TXCIN[45] = 1; /* DefaultCyclic 0: triggered 1: cyclic */
CANMMCAN_TXCIE[45] = 1; /* DefaultCyclic 0: triggered 1: cyclic */
CANMMCAN_TXKIEXC[45] = 1; /* Check 0: intern and/or extern    1: just intern */
CANMMCAN_TXLEN[45] = 1; /* Message length */
CANMMCAN_TXRBUF[45] = 0; /* internal -> do not change */
CANMMCAN_TXRXBUF[45] = 0; /* internal -> do not change */
CANMMCAN_TXusrm[45] = 1;
CANMMCAN_TXcraw[45] = 0; /* 0: SIGNALS 1:RAWDATA */


/* LSS_S */
CANMMCAN_WBS[46] = 0; /* Would be sent */
CANMMCAN_TXEIN[46] = 1; /* DefaultEnable */
CANMMCAN_TXENIE[46] = 1; /* DefaultEnable */
CANMMCAN_TXCIN[46] = 1; /* DefaultCyclic 0: triggered 1: cyclic */
CANMMCAN_TXCIE[46] = 1; /* DefaultCyclic 0: triggered 1: cyclic */
CANMMCAN_TXKIEXC[46] = 1; /* Check 0: intern and/or extern    1: just intern */
CANMMCAN_TXLEN[46] = 8; /* Message length */
CANMMCAN_TXRBUF[46] = 0; /* internal -> do not change */
CANMMCAN_TXRXBUF[46] = 0; /* internal -> do not change */
CANMMCAN_TXusrm[46] = 1;
CANMMCAN_TXcraw[46] = 0; /* 0: SIGNALS 1:RAWDATA */


/* LSS_M */
CANMMCAN_WBS[47] = 0; /* Would be sent */
CANMMCAN_TXEIN[47] = 1; /* DefaultEnable */
CANMMCAN_TXENIE[47] = 1; /* DefaultEnable */
CANMMCAN_TXCIN[47] = 1; /* DefaultCyclic 0: triggered 1: cyclic */
CANMMCAN_TXCIE[47] = 1; /* DefaultCyclic 0: triggered 1: cyclic */
CANMMCAN_TXKIEXC[47] = 1; /* Check 0: intern and/or extern    1: just intern */
CANMMCAN_TXLEN[47] = 8; /* Message length */
CANMMCAN_TXRBUF[47] = 0; /* internal -> do not change */
CANMMCAN_TXRXBUF[47] = 0; /* internal -> do not change */
CANMMCAN_TXusrm[47] = 1;
CANMMCAN_TXcraw[47] = 0; /* 0: SIGNALS 1:RAWDATA */

