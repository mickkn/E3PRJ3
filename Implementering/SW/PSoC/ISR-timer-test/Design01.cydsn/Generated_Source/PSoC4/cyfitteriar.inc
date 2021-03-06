#ifndef INCLUDED_CYFITTERIAR_INC
#define INCLUDED_CYFITTERIAR_INC
    INCLUDE cydeviceiar_trm.inc

/* Timer_1_TimerUDB */
Timer_1_TimerUDB_rstSts_stsreg__0__MASK EQU 0x01
Timer_1_TimerUDB_rstSts_stsreg__0__POS EQU 0
Timer_1_TimerUDB_rstSts_stsreg__2__MASK EQU 0x04
Timer_1_TimerUDB_rstSts_stsreg__2__POS EQU 2
Timer_1_TimerUDB_rstSts_stsreg__3__MASK EQU 0x08
Timer_1_TimerUDB_rstSts_stsreg__3__POS EQU 3
Timer_1_TimerUDB_rstSts_stsreg__MASK EQU 0x0D
Timer_1_TimerUDB_rstSts_stsreg__MASK_REG EQU CYREG_UDB_W8_MSK_03
Timer_1_TimerUDB_rstSts_stsreg__MASK_ST_AUX_CTL_REG EQU CYREG_UDB_CAT16_ACTL_MSK_03
Timer_1_TimerUDB_rstSts_stsreg__PER_ST_AUX_CTL_REG EQU CYREG_UDB_CAT16_ACTL_MSK_03
Timer_1_TimerUDB_rstSts_stsreg__STATUS_AUX_CTL_REG EQU CYREG_UDB_W8_ACTL_03
Timer_1_TimerUDB_rstSts_stsreg__STATUS_CNT_REG EQU CYREG_UDB_CAT16_CTL_ST_03
Timer_1_TimerUDB_rstSts_stsreg__STATUS_CONTROL_REG EQU CYREG_UDB_CAT16_CTL_ST_03
Timer_1_TimerUDB_rstSts_stsreg__STATUS_REG EQU CYREG_UDB_W8_ST_03
Timer_1_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__7__MASK EQU 0x80
Timer_1_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__7__POS EQU 7
Timer_1_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__CONTROL_AUX_CTL_REG EQU CYREG_UDB_W8_ACTL_03
Timer_1_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__CONTROL_REG EQU CYREG_UDB_W8_CTL_03
Timer_1_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__CONTROL_ST_REG EQU CYREG_UDB_CAT16_CTL_ST_03
Timer_1_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__COUNT_REG EQU CYREG_UDB_W8_CTL_03
Timer_1_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__COUNT_ST_REG EQU CYREG_UDB_CAT16_CTL_ST_03
Timer_1_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__MASK EQU 0x80
Timer_1_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__MASK_CTL_AUX_CTL_REG EQU CYREG_UDB_CAT16_ACTL_MSK_03
Timer_1_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__PER_CTL_AUX_CTL_REG EQU CYREG_UDB_CAT16_ACTL_MSK_03
Timer_1_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__PERIOD_REG EQU CYREG_UDB_W8_MSK_03
Timer_1_TimerUDB_sT8_timerdp_u0__A0_A1_REG EQU CYREG_UDB_CAT16_A_03
Timer_1_TimerUDB_sT8_timerdp_u0__A0_REG EQU CYREG_UDB_W8_A0_03
Timer_1_TimerUDB_sT8_timerdp_u0__A1_REG EQU CYREG_UDB_W8_A1_03
Timer_1_TimerUDB_sT8_timerdp_u0__D0_D1_REG EQU CYREG_UDB_CAT16_D_03
Timer_1_TimerUDB_sT8_timerdp_u0__D0_REG EQU CYREG_UDB_W8_D0_03
Timer_1_TimerUDB_sT8_timerdp_u0__D1_REG EQU CYREG_UDB_W8_D1_03
Timer_1_TimerUDB_sT8_timerdp_u0__DP_AUX_CTL_REG EQU CYREG_UDB_W8_ACTL_03
Timer_1_TimerUDB_sT8_timerdp_u0__F0_F1_REG EQU CYREG_UDB_CAT16_F_03
Timer_1_TimerUDB_sT8_timerdp_u0__F0_REG EQU CYREG_UDB_W8_F0_03
Timer_1_TimerUDB_sT8_timerdp_u0__F1_REG EQU CYREG_UDB_W8_F1_03
Timer_1_TimerUDB_sT8_timerdp_u0__MSK_DP_AUX_CTL_REG EQU CYREG_UDB_CAT16_ACTL_MSK_03
Timer_1_TimerUDB_sT8_timerdp_u0__PER_DP_AUX_CTL_REG EQU CYREG_UDB_CAT16_ACTL_MSK_03

/* RED_LED */
RED_LED__0__DM__MASK EQU 0x1C0000
RED_LED__0__DM__SHIFT EQU 18
RED_LED__0__DR EQU CYREG_PRT1_DR
RED_LED__0__HSIOM EQU CYREG_HSIOM_PORT_SEL1
RED_LED__0__HSIOM_MASK EQU 0x0F000000
RED_LED__0__HSIOM_SHIFT EQU 24
RED_LED__0__INTCFG EQU CYREG_PRT1_INTCFG
RED_LED__0__INTSTAT EQU CYREG_PRT1_INTSTAT
RED_LED__0__MASK EQU 0x40
RED_LED__0__PA__CFG0 EQU CYREG_UDB_PA1_CFG0
RED_LED__0__PA__CFG1 EQU CYREG_UDB_PA1_CFG1
RED_LED__0__PA__CFG10 EQU CYREG_UDB_PA1_CFG10
RED_LED__0__PA__CFG11 EQU CYREG_UDB_PA1_CFG11
RED_LED__0__PA__CFG12 EQU CYREG_UDB_PA1_CFG12
RED_LED__0__PA__CFG13 EQU CYREG_UDB_PA1_CFG13
RED_LED__0__PA__CFG14 EQU CYREG_UDB_PA1_CFG14
RED_LED__0__PA__CFG2 EQU CYREG_UDB_PA1_CFG2
RED_LED__0__PA__CFG3 EQU CYREG_UDB_PA1_CFG3
RED_LED__0__PA__CFG4 EQU CYREG_UDB_PA1_CFG4
RED_LED__0__PA__CFG5 EQU CYREG_UDB_PA1_CFG5
RED_LED__0__PA__CFG6 EQU CYREG_UDB_PA1_CFG6
RED_LED__0__PA__CFG7 EQU CYREG_UDB_PA1_CFG7
RED_LED__0__PA__CFG8 EQU CYREG_UDB_PA1_CFG8
RED_LED__0__PA__CFG9 EQU CYREG_UDB_PA1_CFG9
RED_LED__0__PC EQU CYREG_PRT1_PC
RED_LED__0__PC2 EQU CYREG_PRT1_PC2
RED_LED__0__PORT EQU 1
RED_LED__0__PS EQU CYREG_PRT1_PS
RED_LED__0__SHIFT EQU 6
RED_LED__DR EQU CYREG_PRT1_DR
RED_LED__INTCFG EQU CYREG_PRT1_INTCFG
RED_LED__INTSTAT EQU CYREG_PRT1_INTSTAT
RED_LED__MASK EQU 0x40
RED_LED__PA__CFG0 EQU CYREG_UDB_PA1_CFG0
RED_LED__PA__CFG1 EQU CYREG_UDB_PA1_CFG1
RED_LED__PA__CFG10 EQU CYREG_UDB_PA1_CFG10
RED_LED__PA__CFG11 EQU CYREG_UDB_PA1_CFG11
RED_LED__PA__CFG12 EQU CYREG_UDB_PA1_CFG12
RED_LED__PA__CFG13 EQU CYREG_UDB_PA1_CFG13
RED_LED__PA__CFG14 EQU CYREG_UDB_PA1_CFG14
RED_LED__PA__CFG2 EQU CYREG_UDB_PA1_CFG2
RED_LED__PA__CFG3 EQU CYREG_UDB_PA1_CFG3
RED_LED__PA__CFG4 EQU CYREG_UDB_PA1_CFG4
RED_LED__PA__CFG5 EQU CYREG_UDB_PA1_CFG5
RED_LED__PA__CFG6 EQU CYREG_UDB_PA1_CFG6
RED_LED__PA__CFG7 EQU CYREG_UDB_PA1_CFG7
RED_LED__PA__CFG8 EQU CYREG_UDB_PA1_CFG8
RED_LED__PA__CFG9 EQU CYREG_UDB_PA1_CFG9
RED_LED__PC EQU CYREG_PRT1_PC
RED_LED__PC2 EQU CYREG_PRT1_PC2
RED_LED__PORT EQU 1
RED_LED__PS EQU CYREG_PRT1_PS
RED_LED__SHIFT EQU 6

/* BLUE_LED */
BLUE_LED__0__DM__MASK EQU 0xE00
BLUE_LED__0__DM__SHIFT EQU 9
BLUE_LED__0__DR EQU CYREG_PRT0_DR
BLUE_LED__0__HSIOM EQU CYREG_HSIOM_PORT_SEL0
BLUE_LED__0__HSIOM_MASK EQU 0x0000F000
BLUE_LED__0__HSIOM_SHIFT EQU 12
BLUE_LED__0__INTCFG EQU CYREG_PRT0_INTCFG
BLUE_LED__0__INTSTAT EQU CYREG_PRT0_INTSTAT
BLUE_LED__0__MASK EQU 0x08
BLUE_LED__0__PA__CFG0 EQU CYREG_UDB_PA0_CFG0
BLUE_LED__0__PA__CFG1 EQU CYREG_UDB_PA0_CFG1
BLUE_LED__0__PA__CFG10 EQU CYREG_UDB_PA0_CFG10
BLUE_LED__0__PA__CFG11 EQU CYREG_UDB_PA0_CFG11
BLUE_LED__0__PA__CFG12 EQU CYREG_UDB_PA0_CFG12
BLUE_LED__0__PA__CFG13 EQU CYREG_UDB_PA0_CFG13
BLUE_LED__0__PA__CFG14 EQU CYREG_UDB_PA0_CFG14
BLUE_LED__0__PA__CFG2 EQU CYREG_UDB_PA0_CFG2
BLUE_LED__0__PA__CFG3 EQU CYREG_UDB_PA0_CFG3
BLUE_LED__0__PA__CFG4 EQU CYREG_UDB_PA0_CFG4
BLUE_LED__0__PA__CFG5 EQU CYREG_UDB_PA0_CFG5
BLUE_LED__0__PA__CFG6 EQU CYREG_UDB_PA0_CFG6
BLUE_LED__0__PA__CFG7 EQU CYREG_UDB_PA0_CFG7
BLUE_LED__0__PA__CFG8 EQU CYREG_UDB_PA0_CFG8
BLUE_LED__0__PA__CFG9 EQU CYREG_UDB_PA0_CFG9
BLUE_LED__0__PC EQU CYREG_PRT0_PC
BLUE_LED__0__PC2 EQU CYREG_PRT0_PC2
BLUE_LED__0__PORT EQU 0
BLUE_LED__0__PS EQU CYREG_PRT0_PS
BLUE_LED__0__SHIFT EQU 3
BLUE_LED__DR EQU CYREG_PRT0_DR
BLUE_LED__INTCFG EQU CYREG_PRT0_INTCFG
BLUE_LED__INTSTAT EQU CYREG_PRT0_INTSTAT
BLUE_LED__MASK EQU 0x08
BLUE_LED__PA__CFG0 EQU CYREG_UDB_PA0_CFG0
BLUE_LED__PA__CFG1 EQU CYREG_UDB_PA0_CFG1
BLUE_LED__PA__CFG10 EQU CYREG_UDB_PA0_CFG10
BLUE_LED__PA__CFG11 EQU CYREG_UDB_PA0_CFG11
BLUE_LED__PA__CFG12 EQU CYREG_UDB_PA0_CFG12
BLUE_LED__PA__CFG13 EQU CYREG_UDB_PA0_CFG13
BLUE_LED__PA__CFG14 EQU CYREG_UDB_PA0_CFG14
BLUE_LED__PA__CFG2 EQU CYREG_UDB_PA0_CFG2
BLUE_LED__PA__CFG3 EQU CYREG_UDB_PA0_CFG3
BLUE_LED__PA__CFG4 EQU CYREG_UDB_PA0_CFG4
BLUE_LED__PA__CFG5 EQU CYREG_UDB_PA0_CFG5
BLUE_LED__PA__CFG6 EQU CYREG_UDB_PA0_CFG6
BLUE_LED__PA__CFG7 EQU CYREG_UDB_PA0_CFG7
BLUE_LED__PA__CFG8 EQU CYREG_UDB_PA0_CFG8
BLUE_LED__PA__CFG9 EQU CYREG_UDB_PA0_CFG9
BLUE_LED__PC EQU CYREG_PRT0_PC
BLUE_LED__PC2 EQU CYREG_PRT0_PC2
BLUE_LED__PORT EQU 0
BLUE_LED__PS EQU CYREG_PRT0_PS
BLUE_LED__SHIFT EQU 3

/* timer_int */
timer_int__INTC_CLR_EN_REG EQU CYREG_CM0_ICER
timer_int__INTC_CLR_PD_REG EQU CYREG_CM0_ICPR
timer_int__INTC_MASK EQU 0x04
timer_int__INTC_NUMBER EQU 2
timer_int__INTC_PRIOR_MASK EQU 0xC00000
timer_int__INTC_PRIOR_NUM EQU 3
timer_int__INTC_PRIOR_REG EQU CYREG_CM0_IPR0
timer_int__INTC_SET_EN_REG EQU CYREG_CM0_ISER
timer_int__INTC_SET_PD_REG EQU CYREG_CM0_ISPR

/* timer1_int */
timer1_int__INTC_CLR_EN_REG EQU CYREG_CM0_ICER
timer1_int__INTC_CLR_PD_REG EQU CYREG_CM0_ICPR
timer1_int__INTC_MASK EQU 0x01
timer1_int__INTC_NUMBER EQU 0
timer1_int__INTC_PRIOR_MASK EQU 0xC0
timer1_int__INTC_PRIOR_NUM EQU 3
timer1_int__INTC_PRIOR_REG EQU CYREG_CM0_IPR0
timer1_int__INTC_SET_EN_REG EQU CYREG_CM0_ISER
timer1_int__INTC_SET_PD_REG EQU CYREG_CM0_ISPR

/* Timer_TimerUDB */
Timer_TimerUDB_rstSts_stsreg__0__MASK EQU 0x01
Timer_TimerUDB_rstSts_stsreg__0__POS EQU 0
Timer_TimerUDB_rstSts_stsreg__16BIT_STATUS_AUX_CTL_REG EQU CYREG_UDB_W16_ACTL_02
Timer_TimerUDB_rstSts_stsreg__16BIT_STATUS_REG EQU CYREG_UDB_W16_ST_02
Timer_TimerUDB_rstSts_stsreg__2__MASK EQU 0x04
Timer_TimerUDB_rstSts_stsreg__2__POS EQU 2
Timer_TimerUDB_rstSts_stsreg__3__MASK EQU 0x08
Timer_TimerUDB_rstSts_stsreg__3__POS EQU 3
Timer_TimerUDB_rstSts_stsreg__MASK EQU 0x0D
Timer_TimerUDB_rstSts_stsreg__MASK_REG EQU CYREG_UDB_W8_MSK_02
Timer_TimerUDB_rstSts_stsreg__STATUS_AUX_CTL_REG EQU CYREG_UDB_W8_ACTL_02
Timer_TimerUDB_rstSts_stsreg__STATUS_REG EQU CYREG_UDB_W8_ST_02
Timer_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__16BIT_CONTROL_AUX_CTL_REG EQU CYREG_UDB_W16_ACTL_01
Timer_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__16BIT_CONTROL_CONTROL_REG EQU CYREG_UDB_W16_CTL_01
Timer_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__16BIT_CONTROL_COUNT_REG EQU CYREG_UDB_W16_CTL_01
Timer_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__16BIT_COUNT_CONTROL_REG EQU CYREG_UDB_W16_CTL_01
Timer_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__16BIT_COUNT_COUNT_REG EQU CYREG_UDB_W16_CTL_01
Timer_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__16BIT_MASK_MASK_REG EQU CYREG_UDB_W16_MSK_01
Timer_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__16BIT_MASK_PERIOD_REG EQU CYREG_UDB_W16_MSK_01
Timer_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__16BIT_PERIOD_MASK_REG EQU CYREG_UDB_W16_MSK_01
Timer_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__16BIT_PERIOD_PERIOD_REG EQU CYREG_UDB_W16_MSK_01
Timer_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__7__MASK EQU 0x80
Timer_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__7__POS EQU 7
Timer_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__CONTROL_AUX_CTL_REG EQU CYREG_UDB_W8_ACTL_01
Timer_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__CONTROL_REG EQU CYREG_UDB_W8_CTL_01
Timer_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__CONTROL_ST_REG EQU CYREG_UDB_CAT16_CTL_ST_01
Timer_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__COUNT_REG EQU CYREG_UDB_W8_CTL_01
Timer_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__COUNT_ST_REG EQU CYREG_UDB_CAT16_CTL_ST_01
Timer_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__MASK EQU 0x80
Timer_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__MASK_CTL_AUX_CTL_REG EQU CYREG_UDB_CAT16_ACTL_MSK_01
Timer_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__PER_CTL_AUX_CTL_REG EQU CYREG_UDB_CAT16_ACTL_MSK_01
Timer_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__PERIOD_REG EQU CYREG_UDB_W8_MSK_01
Timer_TimerUDB_sT24_timerdp_u0__16BIT_A0_REG EQU CYREG_UDB_W16_A0_00
Timer_TimerUDB_sT24_timerdp_u0__16BIT_A1_REG EQU CYREG_UDB_W16_A1_00
Timer_TimerUDB_sT24_timerdp_u0__16BIT_D0_REG EQU CYREG_UDB_W16_D0_00
Timer_TimerUDB_sT24_timerdp_u0__16BIT_D1_REG EQU CYREG_UDB_W16_D1_00
Timer_TimerUDB_sT24_timerdp_u0__16BIT_DP_AUX_CTL_REG EQU CYREG_UDB_W16_ACTL_00
Timer_TimerUDB_sT24_timerdp_u0__16BIT_F0_REG EQU CYREG_UDB_W16_F0_00
Timer_TimerUDB_sT24_timerdp_u0__16BIT_F1_REG EQU CYREG_UDB_W16_F1_00
Timer_TimerUDB_sT24_timerdp_u0__32BIT_A0_REG EQU CYREG_UDB_W32_A0_00
Timer_TimerUDB_sT24_timerdp_u0__32BIT_A1_REG EQU CYREG_UDB_W32_A1_00
Timer_TimerUDB_sT24_timerdp_u0__32BIT_D0_REG EQU CYREG_UDB_W32_D0_00
Timer_TimerUDB_sT24_timerdp_u0__32BIT_D1_REG EQU CYREG_UDB_W32_D1_00
Timer_TimerUDB_sT24_timerdp_u0__32BIT_DP_AUX_CTL_REG EQU CYREG_UDB_W32_ACTL_00
Timer_TimerUDB_sT24_timerdp_u0__32BIT_F0_REG EQU CYREG_UDB_W32_F0_00
Timer_TimerUDB_sT24_timerdp_u0__32BIT_F1_REG EQU CYREG_UDB_W32_F1_00
Timer_TimerUDB_sT24_timerdp_u0__A0_A1_REG EQU CYREG_UDB_CAT16_A_00
Timer_TimerUDB_sT24_timerdp_u0__A0_REG EQU CYREG_UDB_W8_A0_00
Timer_TimerUDB_sT24_timerdp_u0__A1_REG EQU CYREG_UDB_W8_A1_00
Timer_TimerUDB_sT24_timerdp_u0__D0_D1_REG EQU CYREG_UDB_CAT16_D_00
Timer_TimerUDB_sT24_timerdp_u0__D0_REG EQU CYREG_UDB_W8_D0_00
Timer_TimerUDB_sT24_timerdp_u0__D1_REG EQU CYREG_UDB_W8_D1_00
Timer_TimerUDB_sT24_timerdp_u0__DP_AUX_CTL_REG EQU CYREG_UDB_W8_ACTL_00
Timer_TimerUDB_sT24_timerdp_u0__F0_F1_REG EQU CYREG_UDB_CAT16_F_00
Timer_TimerUDB_sT24_timerdp_u0__F0_REG EQU CYREG_UDB_W8_F0_00
Timer_TimerUDB_sT24_timerdp_u0__F1_REG EQU CYREG_UDB_W8_F1_00
Timer_TimerUDB_sT24_timerdp_u1__16BIT_A0_REG EQU CYREG_UDB_W16_A0_01
Timer_TimerUDB_sT24_timerdp_u1__16BIT_A1_REG EQU CYREG_UDB_W16_A1_01
Timer_TimerUDB_sT24_timerdp_u1__16BIT_D0_REG EQU CYREG_UDB_W16_D0_01
Timer_TimerUDB_sT24_timerdp_u1__16BIT_D1_REG EQU CYREG_UDB_W16_D1_01
Timer_TimerUDB_sT24_timerdp_u1__16BIT_DP_AUX_CTL_REG EQU CYREG_UDB_W16_ACTL_01
Timer_TimerUDB_sT24_timerdp_u1__16BIT_F0_REG EQU CYREG_UDB_W16_F0_01
Timer_TimerUDB_sT24_timerdp_u1__16BIT_F1_REG EQU CYREG_UDB_W16_F1_01
Timer_TimerUDB_sT24_timerdp_u1__A0_A1_REG EQU CYREG_UDB_CAT16_A_01
Timer_TimerUDB_sT24_timerdp_u1__A0_REG EQU CYREG_UDB_W8_A0_01
Timer_TimerUDB_sT24_timerdp_u1__A1_REG EQU CYREG_UDB_W8_A1_01
Timer_TimerUDB_sT24_timerdp_u1__D0_D1_REG EQU CYREG_UDB_CAT16_D_01
Timer_TimerUDB_sT24_timerdp_u1__D0_REG EQU CYREG_UDB_W8_D0_01
Timer_TimerUDB_sT24_timerdp_u1__D1_REG EQU CYREG_UDB_W8_D1_01
Timer_TimerUDB_sT24_timerdp_u1__DP_AUX_CTL_REG EQU CYREG_UDB_W8_ACTL_01
Timer_TimerUDB_sT24_timerdp_u1__F0_F1_REG EQU CYREG_UDB_CAT16_F_01
Timer_TimerUDB_sT24_timerdp_u1__F0_REG EQU CYREG_UDB_W8_F0_01
Timer_TimerUDB_sT24_timerdp_u1__F1_REG EQU CYREG_UDB_W8_F1_01
Timer_TimerUDB_sT24_timerdp_u1__MSK_DP_AUX_CTL_REG EQU CYREG_UDB_CAT16_ACTL_MSK_01
Timer_TimerUDB_sT24_timerdp_u1__PER_DP_AUX_CTL_REG EQU CYREG_UDB_CAT16_ACTL_MSK_01
Timer_TimerUDB_sT24_timerdp_u2__16BIT_A0_REG EQU CYREG_UDB_W16_A0_02
Timer_TimerUDB_sT24_timerdp_u2__16BIT_A1_REG EQU CYREG_UDB_W16_A1_02
Timer_TimerUDB_sT24_timerdp_u2__16BIT_D0_REG EQU CYREG_UDB_W16_D0_02
Timer_TimerUDB_sT24_timerdp_u2__16BIT_D1_REG EQU CYREG_UDB_W16_D1_02
Timer_TimerUDB_sT24_timerdp_u2__16BIT_DP_AUX_CTL_REG EQU CYREG_UDB_W16_ACTL_02
Timer_TimerUDB_sT24_timerdp_u2__16BIT_F0_REG EQU CYREG_UDB_W16_F0_02
Timer_TimerUDB_sT24_timerdp_u2__16BIT_F1_REG EQU CYREG_UDB_W16_F1_02
Timer_TimerUDB_sT24_timerdp_u2__A0_A1_REG EQU CYREG_UDB_CAT16_A_02
Timer_TimerUDB_sT24_timerdp_u2__A0_REG EQU CYREG_UDB_W8_A0_02
Timer_TimerUDB_sT24_timerdp_u2__A1_REG EQU CYREG_UDB_W8_A1_02
Timer_TimerUDB_sT24_timerdp_u2__D0_D1_REG EQU CYREG_UDB_CAT16_D_02
Timer_TimerUDB_sT24_timerdp_u2__D0_REG EQU CYREG_UDB_W8_D0_02
Timer_TimerUDB_sT24_timerdp_u2__D1_REG EQU CYREG_UDB_W8_D1_02
Timer_TimerUDB_sT24_timerdp_u2__DP_AUX_CTL_REG EQU CYREG_UDB_W8_ACTL_02
Timer_TimerUDB_sT24_timerdp_u2__F0_F1_REG EQU CYREG_UDB_CAT16_F_02
Timer_TimerUDB_sT24_timerdp_u2__F0_REG EQU CYREG_UDB_W8_F0_02
Timer_TimerUDB_sT24_timerdp_u2__F1_REG EQU CYREG_UDB_W8_F1_02

/* Miscellaneous */
CYDEV_BCLK__HFCLK__HZ EQU 24000000
CYDEV_BCLK__HFCLK__KHZ EQU 24000
CYDEV_BCLK__HFCLK__MHZ EQU 24
CYDEV_BCLK__SYSCLK__HZ EQU 24000000
CYDEV_BCLK__SYSCLK__KHZ EQU 24000
CYDEV_BCLK__SYSCLK__MHZ EQU 24
CYDEV_CHIP_DIE_LEOPARD EQU 1
CYDEV_CHIP_DIE_PANTHER EQU 4
CYDEV_CHIP_DIE_PSOC4A EQU 2
CYDEV_CHIP_DIE_PSOC5LP EQU 5
CYDEV_CHIP_DIE_UNKNOWN EQU 0
CYDEV_CHIP_FAMILY_PSOC3 EQU 1
CYDEV_CHIP_FAMILY_PSOC4 EQU 2
CYDEV_CHIP_FAMILY_PSOC5 EQU 3
CYDEV_CHIP_FAMILY_UNKNOWN EQU 0
CYDEV_CHIP_FAMILY_USED EQU CYDEV_CHIP_FAMILY_PSOC4
CYDEV_CHIP_JTAG_ID EQU 0x04C81193
CYDEV_CHIP_MEMBER_3A EQU 1
CYDEV_CHIP_MEMBER_4A EQU 2
CYDEV_CHIP_MEMBER_4D EQU 3
CYDEV_CHIP_MEMBER_5A EQU 4
CYDEV_CHIP_MEMBER_5B EQU 5
CYDEV_CHIP_MEMBER_UNKNOWN EQU 0
CYDEV_CHIP_MEMBER_USED EQU CYDEV_CHIP_MEMBER_4A
CYDEV_CHIP_DIE_EXPECT EQU CYDEV_CHIP_MEMBER_USED
CYDEV_CHIP_DIE_ACTUAL EQU CYDEV_CHIP_DIE_EXPECT
CYDEV_CHIP_REV_LEOPARD_ES1 EQU 0
CYDEV_CHIP_REV_LEOPARD_ES2 EQU 1
CYDEV_CHIP_REV_LEOPARD_ES3 EQU 3
CYDEV_CHIP_REV_LEOPARD_PRODUCTION EQU 3
CYDEV_CHIP_REV_PANTHER_ES0 EQU 0
CYDEV_CHIP_REV_PANTHER_ES1 EQU 1
CYDEV_CHIP_REV_PANTHER_PRODUCTION EQU 1
CYDEV_CHIP_REV_PSOC4A_ES0 EQU 17
CYDEV_CHIP_REV_PSOC4A_PRODUCTION EQU 17
CYDEV_CHIP_REV_PSOC5LP_ES0 EQU 0
CYDEV_CHIP_REV_PSOC5LP_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_3A_ES1 EQU 0
CYDEV_CHIP_REVISION_3A_ES2 EQU 1
CYDEV_CHIP_REVISION_3A_ES3 EQU 3
CYDEV_CHIP_REVISION_3A_PRODUCTION EQU 3
CYDEV_CHIP_REVISION_4A_ES0 EQU 17
CYDEV_CHIP_REVISION_4A_PRODUCTION EQU 17
CYDEV_CHIP_REVISION_4D_ES0 EQU 0
CYDEV_CHIP_REVISION_4D_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_5A_ES0 EQU 0
CYDEV_CHIP_REVISION_5A_ES1 EQU 1
CYDEV_CHIP_REVISION_5A_PRODUCTION EQU 1
CYDEV_CHIP_REVISION_5B_ES0 EQU 0
CYDEV_CHIP_REVISION_5B_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_USED EQU CYDEV_CHIP_REVISION_4A_PRODUCTION
CYDEV_CHIP_REV_EXPECT EQU CYDEV_CHIP_REVISION_USED
CYDEV_CONFIG_READ_ACCELERATOR EQU 1
CYDEV_CONFIG_UNUSED_IO_AllowButWarn EQU 0
CYDEV_CONFIG_UNUSED_IO EQU CYDEV_CONFIG_UNUSED_IO_AllowButWarn
CYDEV_CONFIG_UNUSED_IO_AllowWithInfo EQU 1
CYDEV_CONFIG_UNUSED_IO_Disallowed EQU 2
CYDEV_CONFIGURATION_COMPRESSED EQU 1
CYDEV_CONFIGURATION_MODE_COMPRESSED EQU 0
CYDEV_CONFIGURATION_MODE EQU CYDEV_CONFIGURATION_MODE_COMPRESSED
CYDEV_CONFIGURATION_MODE_DMA EQU 2
CYDEV_CONFIGURATION_MODE_UNCOMPRESSED EQU 1
CYDEV_DEBUG_PROTECT_KILL EQU 4
CYDEV_DEBUG_PROTECT_OPEN EQU 1
CYDEV_DEBUG_PROTECT EQU CYDEV_DEBUG_PROTECT_OPEN
CYDEV_DEBUG_PROTECT_PROTECTED EQU 2
CYDEV_DEBUGGING_DPS_Disable EQU 3
CYDEV_DEBUGGING_DPS_SWD EQU 2
CYDEV_DEBUGGING_DPS EQU CYDEV_DEBUGGING_DPS_SWD
CYDEV_DEBUGGING_ENABLE EQU 1
CYDEV_HEAP_SIZE EQU 0x0100
CYDEV_PROJ_TYPE EQU 0
CYDEV_PROJ_TYPE_BOOTLOADER EQU 1
CYDEV_PROJ_TYPE_LOADABLE EQU 2
CYDEV_PROJ_TYPE_MULTIAPPBOOTLOADER EQU 3
CYDEV_PROJ_TYPE_STANDARD EQU 0
CYDEV_STACK_SIZE EQU 0x0400
CYDEV_USE_BUNDLED_CMSIS EQU 1
CYDEV_VARIABLE_VDDA EQU 1
CYDEV_VDDA_MV EQU 3300
CYDEV_VDDD_MV EQU 3300
CYIPBLOCK_M0S8_CTBM_VERSION EQU 0
CYIPBLOCK_m0s8cpuss_VERSION EQU 0
CYIPBLOCK_m0s8csd_VERSION EQU 0
CYIPBLOCK_m0s8gpio2_VERSION EQU 0
CYIPBLOCK_m0s8hsiom4a_VERSION EQU 0
CYIPBLOCK_m0s8lcd_VERSION EQU 0
CYIPBLOCK_m0s8lpcomp_VERSION EQU 0
CYIPBLOCK_m0s8pclk_VERSION EQU 0
CYIPBLOCK_m0s8sar_VERSION EQU 0
CYIPBLOCK_m0s8scb_VERSION EQU 0
CYIPBLOCK_m0s8srssv2_VERSION EQU 1
CYIPBLOCK_m0s8tcpwm_VERSION EQU 0
CYIPBLOCK_m0s8udbif_VERSION EQU 0
CYIPBLOCK_S8_GPIO_VERSION EQU 2
CYDEV_BOOTLOADER_ENABLE EQU 0

#endif /* INCLUDED_CYFITTERIAR_INC */
