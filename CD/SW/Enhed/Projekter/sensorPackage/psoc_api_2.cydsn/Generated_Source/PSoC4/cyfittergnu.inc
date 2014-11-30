.ifndef INCLUDED_CYFITTERGNU_INC
.set INCLUDED_CYFITTERGNU_INC, 1
.include "cydevicegnu_trm.inc"

/* P_VP */
.set P_VP__0__DM__MASK, 0x07
.set P_VP__0__DM__SHIFT, 0
.set P_VP__0__DR, CYREG_PRT2_DR
.set P_VP__0__HSIOM, CYREG_HSIOM_PORT_SEL2
.set P_VP__0__HSIOM_MASK, 0x0000000F
.set P_VP__0__HSIOM_SHIFT, 0
.set P_VP__0__INTCFG, CYREG_PRT2_INTCFG
.set P_VP__0__INTSTAT, CYREG_PRT2_INTSTAT
.set P_VP__0__MASK, 0x01
.set P_VP__0__PA__CFG0, CYREG_UDB_PA2_CFG0
.set P_VP__0__PA__CFG1, CYREG_UDB_PA2_CFG1
.set P_VP__0__PA__CFG10, CYREG_UDB_PA2_CFG10
.set P_VP__0__PA__CFG11, CYREG_UDB_PA2_CFG11
.set P_VP__0__PA__CFG12, CYREG_UDB_PA2_CFG12
.set P_VP__0__PA__CFG13, CYREG_UDB_PA2_CFG13
.set P_VP__0__PA__CFG14, CYREG_UDB_PA2_CFG14
.set P_VP__0__PA__CFG2, CYREG_UDB_PA2_CFG2
.set P_VP__0__PA__CFG3, CYREG_UDB_PA2_CFG3
.set P_VP__0__PA__CFG4, CYREG_UDB_PA2_CFG4
.set P_VP__0__PA__CFG5, CYREG_UDB_PA2_CFG5
.set P_VP__0__PA__CFG6, CYREG_UDB_PA2_CFG6
.set P_VP__0__PA__CFG7, CYREG_UDB_PA2_CFG7
.set P_VP__0__PA__CFG8, CYREG_UDB_PA2_CFG8
.set P_VP__0__PA__CFG9, CYREG_UDB_PA2_CFG9
.set P_VP__0__PC, CYREG_PRT2_PC
.set P_VP__0__PC2, CYREG_PRT2_PC2
.set P_VP__0__PORT, 2
.set P_VP__0__PS, CYREG_PRT2_PS
.set P_VP__0__SHIFT, 0
.set P_VP__DR, CYREG_PRT2_DR
.set P_VP__INTCFG, CYREG_PRT2_INTCFG
.set P_VP__INTSTAT, CYREG_PRT2_INTSTAT
.set P_VP__MASK, 0x01
.set P_VP__PA__CFG0, CYREG_UDB_PA2_CFG0
.set P_VP__PA__CFG1, CYREG_UDB_PA2_CFG1
.set P_VP__PA__CFG10, CYREG_UDB_PA2_CFG10
.set P_VP__PA__CFG11, CYREG_UDB_PA2_CFG11
.set P_VP__PA__CFG12, CYREG_UDB_PA2_CFG12
.set P_VP__PA__CFG13, CYREG_UDB_PA2_CFG13
.set P_VP__PA__CFG14, CYREG_UDB_PA2_CFG14
.set P_VP__PA__CFG2, CYREG_UDB_PA2_CFG2
.set P_VP__PA__CFG3, CYREG_UDB_PA2_CFG3
.set P_VP__PA__CFG4, CYREG_UDB_PA2_CFG4
.set P_VP__PA__CFG5, CYREG_UDB_PA2_CFG5
.set P_VP__PA__CFG6, CYREG_UDB_PA2_CFG6
.set P_VP__PA__CFG7, CYREG_UDB_PA2_CFG7
.set P_VP__PA__CFG8, CYREG_UDB_PA2_CFG8
.set P_VP__PA__CFG9, CYREG_UDB_PA2_CFG9
.set P_VP__PC, CYREG_PRT2_PC
.set P_VP__PC2, CYREG_PRT2_PC2
.set P_VP__PORT, 2
.set P_VP__PS, CYREG_PRT2_PS
.set P_VP__SHIFT, 0

/* P_FT1 */
.set P_FT1__0__DM__MASK, 0x38000
.set P_FT1__0__DM__SHIFT, 15
.set P_FT1__0__DR, CYREG_PRT2_DR
.set P_FT1__0__HSIOM, CYREG_HSIOM_PORT_SEL2
.set P_FT1__0__HSIOM_MASK, 0x00F00000
.set P_FT1__0__HSIOM_SHIFT, 20
.set P_FT1__0__INTCFG, CYREG_PRT2_INTCFG
.set P_FT1__0__INTSTAT, CYREG_PRT2_INTSTAT
.set P_FT1__0__MASK, 0x20
.set P_FT1__0__PA__CFG0, CYREG_UDB_PA2_CFG0
.set P_FT1__0__PA__CFG1, CYREG_UDB_PA2_CFG1
.set P_FT1__0__PA__CFG10, CYREG_UDB_PA2_CFG10
.set P_FT1__0__PA__CFG11, CYREG_UDB_PA2_CFG11
.set P_FT1__0__PA__CFG12, CYREG_UDB_PA2_CFG12
.set P_FT1__0__PA__CFG13, CYREG_UDB_PA2_CFG13
.set P_FT1__0__PA__CFG14, CYREG_UDB_PA2_CFG14
.set P_FT1__0__PA__CFG2, CYREG_UDB_PA2_CFG2
.set P_FT1__0__PA__CFG3, CYREG_UDB_PA2_CFG3
.set P_FT1__0__PA__CFG4, CYREG_UDB_PA2_CFG4
.set P_FT1__0__PA__CFG5, CYREG_UDB_PA2_CFG5
.set P_FT1__0__PA__CFG6, CYREG_UDB_PA2_CFG6
.set P_FT1__0__PA__CFG7, CYREG_UDB_PA2_CFG7
.set P_FT1__0__PA__CFG8, CYREG_UDB_PA2_CFG8
.set P_FT1__0__PA__CFG9, CYREG_UDB_PA2_CFG9
.set P_FT1__0__PC, CYREG_PRT2_PC
.set P_FT1__0__PC2, CYREG_PRT2_PC2
.set P_FT1__0__PORT, 2
.set P_FT1__0__PS, CYREG_PRT2_PS
.set P_FT1__0__SHIFT, 5
.set P_FT1__DR, CYREG_PRT2_DR
.set P_FT1__INTCFG, CYREG_PRT2_INTCFG
.set P_FT1__INTSTAT, CYREG_PRT2_INTSTAT
.set P_FT1__MASK, 0x20
.set P_FT1__PA__CFG0, CYREG_UDB_PA2_CFG0
.set P_FT1__PA__CFG1, CYREG_UDB_PA2_CFG1
.set P_FT1__PA__CFG10, CYREG_UDB_PA2_CFG10
.set P_FT1__PA__CFG11, CYREG_UDB_PA2_CFG11
.set P_FT1__PA__CFG12, CYREG_UDB_PA2_CFG12
.set P_FT1__PA__CFG13, CYREG_UDB_PA2_CFG13
.set P_FT1__PA__CFG14, CYREG_UDB_PA2_CFG14
.set P_FT1__PA__CFG2, CYREG_UDB_PA2_CFG2
.set P_FT1__PA__CFG3, CYREG_UDB_PA2_CFG3
.set P_FT1__PA__CFG4, CYREG_UDB_PA2_CFG4
.set P_FT1__PA__CFG5, CYREG_UDB_PA2_CFG5
.set P_FT1__PA__CFG6, CYREG_UDB_PA2_CFG6
.set P_FT1__PA__CFG7, CYREG_UDB_PA2_CFG7
.set P_FT1__PA__CFG8, CYREG_UDB_PA2_CFG8
.set P_FT1__PA__CFG9, CYREG_UDB_PA2_CFG9
.set P_FT1__PC, CYREG_PRT2_PC
.set P_FT1__PC2, CYREG_PRT2_PC2
.set P_FT1__PORT, 2
.set P_FT1__PS, CYREG_PRT2_PS
.set P_FT1__SHIFT, 5

/* P_FT2 */
.set P_FT2__0__DM__MASK, 0x07
.set P_FT2__0__DM__SHIFT, 0
.set P_FT2__0__DR, CYREG_PRT0_DR
.set P_FT2__0__HSIOM, CYREG_HSIOM_PORT_SEL0
.set P_FT2__0__HSIOM_MASK, 0x0000000F
.set P_FT2__0__HSIOM_SHIFT, 0
.set P_FT2__0__INTCFG, CYREG_PRT0_INTCFG
.set P_FT2__0__INTSTAT, CYREG_PRT0_INTSTAT
.set P_FT2__0__MASK, 0x01
.set P_FT2__0__PA__CFG0, CYREG_UDB_PA0_CFG0
.set P_FT2__0__PA__CFG1, CYREG_UDB_PA0_CFG1
.set P_FT2__0__PA__CFG10, CYREG_UDB_PA0_CFG10
.set P_FT2__0__PA__CFG11, CYREG_UDB_PA0_CFG11
.set P_FT2__0__PA__CFG12, CYREG_UDB_PA0_CFG12
.set P_FT2__0__PA__CFG13, CYREG_UDB_PA0_CFG13
.set P_FT2__0__PA__CFG14, CYREG_UDB_PA0_CFG14
.set P_FT2__0__PA__CFG2, CYREG_UDB_PA0_CFG2
.set P_FT2__0__PA__CFG3, CYREG_UDB_PA0_CFG3
.set P_FT2__0__PA__CFG4, CYREG_UDB_PA0_CFG4
.set P_FT2__0__PA__CFG5, CYREG_UDB_PA0_CFG5
.set P_FT2__0__PA__CFG6, CYREG_UDB_PA0_CFG6
.set P_FT2__0__PA__CFG7, CYREG_UDB_PA0_CFG7
.set P_FT2__0__PA__CFG8, CYREG_UDB_PA0_CFG8
.set P_FT2__0__PA__CFG9, CYREG_UDB_PA0_CFG9
.set P_FT2__0__PC, CYREG_PRT0_PC
.set P_FT2__0__PC2, CYREG_PRT0_PC2
.set P_FT2__0__PORT, 0
.set P_FT2__0__PS, CYREG_PRT0_PS
.set P_FT2__0__SHIFT, 0
.set P_FT2__DR, CYREG_PRT0_DR
.set P_FT2__INTCFG, CYREG_PRT0_INTCFG
.set P_FT2__INTSTAT, CYREG_PRT0_INTSTAT
.set P_FT2__MASK, 0x01
.set P_FT2__PA__CFG0, CYREG_UDB_PA0_CFG0
.set P_FT2__PA__CFG1, CYREG_UDB_PA0_CFG1
.set P_FT2__PA__CFG10, CYREG_UDB_PA0_CFG10
.set P_FT2__PA__CFG11, CYREG_UDB_PA0_CFG11
.set P_FT2__PA__CFG12, CYREG_UDB_PA0_CFG12
.set P_FT2__PA__CFG13, CYREG_UDB_PA0_CFG13
.set P_FT2__PA__CFG14, CYREG_UDB_PA0_CFG14
.set P_FT2__PA__CFG2, CYREG_UDB_PA0_CFG2
.set P_FT2__PA__CFG3, CYREG_UDB_PA0_CFG3
.set P_FT2__PA__CFG4, CYREG_UDB_PA0_CFG4
.set P_FT2__PA__CFG5, CYREG_UDB_PA0_CFG5
.set P_FT2__PA__CFG6, CYREG_UDB_PA0_CFG6
.set P_FT2__PA__CFG7, CYREG_UDB_PA0_CFG7
.set P_FT2__PA__CFG8, CYREG_UDB_PA0_CFG8
.set P_FT2__PA__CFG9, CYREG_UDB_PA0_CFG9
.set P_FT2__PC, CYREG_PRT0_PC
.set P_FT2__PC2, CYREG_PRT0_PC2
.set P_FT2__PORT, 0
.set P_FT2__PS, CYREG_PRT0_PS
.set P_FT2__SHIFT, 0

/* ADC_SAR_Seq_0_cy_psoc4_sar */
.set ADC_SAR_Seq_0_cy_psoc4_sar__SAR_CTRL, CYREG_SAR_CTRL
.set ADC_SAR_Seq_0_cy_psoc4_sar__SAR_INTR, CYREG_SAR_INTR
.set ADC_SAR_Seq_0_cy_psoc4_sar__SAR_INTR_CAUSE, CYREG_SAR_INTR_CAUSE
.set ADC_SAR_Seq_0_cy_psoc4_sar__SAR_INTR_MASK, CYREG_SAR_INTR_MASK
.set ADC_SAR_Seq_0_cy_psoc4_sar__SAR_INTR_MASKED, CYREG_SAR_INTR_MASKED
.set ADC_SAR_Seq_0_cy_psoc4_sar__SAR_INTR_SET, CYREG_SAR_INTR_SET
.set ADC_SAR_Seq_0_cy_psoc4_sar__SAR_NUMBER, 0
.set ADC_SAR_Seq_0_cy_psoc4_sar__SAR_RANGE_COND, CYREG_SAR_RANGE_COND
.set ADC_SAR_Seq_0_cy_psoc4_sar__SAR_RANGE_INTR_MASK, CYREG_SAR_RANGE_INTR_MASK
.set ADC_SAR_Seq_0_cy_psoc4_sar__SAR_RANGE_INTR_MASKED, CYREG_SAR_RANGE_INTR_MASKED
.set ADC_SAR_Seq_0_cy_psoc4_sar__SAR_RANGE_INTR_SET, CYREG_SAR_RANGE_INTR_SET
.set ADC_SAR_Seq_0_cy_psoc4_sar__SAR_RANGE_THRES, CYREG_SAR_RANGE_THRES
.set ADC_SAR_Seq_0_cy_psoc4_sar__SAR_SAMPLE_CTRL, CYREG_SAR_SAMPLE_CTRL
.set ADC_SAR_Seq_0_cy_psoc4_sar__SAR_SAMPLE_TIME01, CYREG_SAR_SAMPLE_TIME01
.set ADC_SAR_Seq_0_cy_psoc4_sar__SAR_SAMPLE_TIME23, CYREG_SAR_SAMPLE_TIME23
.set ADC_SAR_Seq_0_cy_psoc4_sar__SAR_SATURATE_INTR_MASK, CYREG_SAR_SATURATE_INTR_MASK
.set ADC_SAR_Seq_0_cy_psoc4_sar__SAR_SATURATE_INTR_MASKED, CYREG_SAR_SATURATE_INTR_MASKED
.set ADC_SAR_Seq_0_cy_psoc4_sar__SAR_SATURATE_INTR_SET, CYREG_SAR_SATURATE_INTR_SET

/* ADC_SAR_Seq_0_intClock */
.set ADC_SAR_Seq_0_intClock__DIVIDER_MASK, 0x0000FFFF
.set ADC_SAR_Seq_0_intClock__ENABLE, CYREG_CLK_DIVIDER_A00
.set ADC_SAR_Seq_0_intClock__ENABLE_MASK, 0x80000000
.set ADC_SAR_Seq_0_intClock__MASK, 0x80000000
.set ADC_SAR_Seq_0_intClock__REGISTER, CYREG_CLK_DIVIDER_A00

/* ADC_SAR_Seq_0_IRQ */
.set ADC_SAR_Seq_0_IRQ__INTC_CLR_EN_REG, CYREG_CM0_ICER
.set ADC_SAR_Seq_0_IRQ__INTC_CLR_PD_REG, CYREG_CM0_ICPR
.set ADC_SAR_Seq_0_IRQ__INTC_MASK, 0x4000
.set ADC_SAR_Seq_0_IRQ__INTC_NUMBER, 14
.set ADC_SAR_Seq_0_IRQ__INTC_PRIOR_MASK, 0xC00000
.set ADC_SAR_Seq_0_IRQ__INTC_PRIOR_NUM, 3
.set ADC_SAR_Seq_0_IRQ__INTC_PRIOR_REG, CYREG_CM0_IPR3
.set ADC_SAR_Seq_0_IRQ__INTC_SET_EN_REG, CYREG_CM0_ISER
.set ADC_SAR_Seq_0_IRQ__INTC_SET_PD_REG, CYREG_CM0_ISPR

/* Miscellaneous */
.set CYDEV_BCLK__HFCLK__HZ, 24000000
.set CYDEV_BCLK__HFCLK__KHZ, 24000
.set CYDEV_BCLK__HFCLK__MHZ, 24
.set CYDEV_BCLK__SYSCLK__HZ, 24000000
.set CYDEV_BCLK__SYSCLK__KHZ, 24000
.set CYDEV_BCLK__SYSCLK__MHZ, 24
.set CYDEV_CHIP_DIE_LEOPARD, 1
.set CYDEV_CHIP_DIE_PANTHER, 4
.set CYDEV_CHIP_DIE_PSOC4A, 2
.set CYDEV_CHIP_DIE_PSOC5LP, 5
.set CYDEV_CHIP_DIE_UNKNOWN, 0
.set CYDEV_CHIP_FAMILY_PSOC3, 1
.set CYDEV_CHIP_FAMILY_PSOC4, 2
.set CYDEV_CHIP_FAMILY_PSOC5, 3
.set CYDEV_CHIP_FAMILY_UNKNOWN, 0
.set CYDEV_CHIP_FAMILY_USED, CYDEV_CHIP_FAMILY_PSOC4
.set CYDEV_CHIP_JTAG_ID, 0x04C81193
.set CYDEV_CHIP_MEMBER_3A, 1
.set CYDEV_CHIP_MEMBER_4A, 2
.set CYDEV_CHIP_MEMBER_4D, 3
.set CYDEV_CHIP_MEMBER_5A, 4
.set CYDEV_CHIP_MEMBER_5B, 5
.set CYDEV_CHIP_MEMBER_UNKNOWN, 0
.set CYDEV_CHIP_MEMBER_USED, CYDEV_CHIP_MEMBER_4A
.set CYDEV_CHIP_DIE_EXPECT, CYDEV_CHIP_MEMBER_USED
.set CYDEV_CHIP_DIE_ACTUAL, CYDEV_CHIP_DIE_EXPECT
.set CYDEV_CHIP_REV_LEOPARD_ES1, 0
.set CYDEV_CHIP_REV_LEOPARD_ES2, 1
.set CYDEV_CHIP_REV_LEOPARD_ES3, 3
.set CYDEV_CHIP_REV_LEOPARD_PRODUCTION, 3
.set CYDEV_CHIP_REV_PANTHER_ES0, 0
.set CYDEV_CHIP_REV_PANTHER_ES1, 1
.set CYDEV_CHIP_REV_PANTHER_PRODUCTION, 1
.set CYDEV_CHIP_REV_PSOC4A_ES0, 17
.set CYDEV_CHIP_REV_PSOC4A_PRODUCTION, 17
.set CYDEV_CHIP_REV_PSOC5LP_ES0, 0
.set CYDEV_CHIP_REV_PSOC5LP_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_3A_ES1, 0
.set CYDEV_CHIP_REVISION_3A_ES2, 1
.set CYDEV_CHIP_REVISION_3A_ES3, 3
.set CYDEV_CHIP_REVISION_3A_PRODUCTION, 3
.set CYDEV_CHIP_REVISION_4A_ES0, 17
.set CYDEV_CHIP_REVISION_4A_PRODUCTION, 17
.set CYDEV_CHIP_REVISION_4D_ES0, 0
.set CYDEV_CHIP_REVISION_4D_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_5A_ES0, 0
.set CYDEV_CHIP_REVISION_5A_ES1, 1
.set CYDEV_CHIP_REVISION_5A_PRODUCTION, 1
.set CYDEV_CHIP_REVISION_5B_ES0, 0
.set CYDEV_CHIP_REVISION_5B_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_USED, CYDEV_CHIP_REVISION_4A_PRODUCTION
.set CYDEV_CHIP_REV_EXPECT, CYDEV_CHIP_REVISION_USED
.set CYDEV_CONFIG_READ_ACCELERATOR, 1
.set CYDEV_CONFIG_UNUSED_IO_AllowButWarn, 0
.set CYDEV_CONFIG_UNUSED_IO, CYDEV_CONFIG_UNUSED_IO_AllowButWarn
.set CYDEV_CONFIG_UNUSED_IO_AllowWithInfo, 1
.set CYDEV_CONFIG_UNUSED_IO_Disallowed, 2
.set CYDEV_CONFIGURATION_COMPRESSED, 1
.set CYDEV_CONFIGURATION_MODE_COMPRESSED, 0
.set CYDEV_CONFIGURATION_MODE, CYDEV_CONFIGURATION_MODE_COMPRESSED
.set CYDEV_CONFIGURATION_MODE_DMA, 2
.set CYDEV_CONFIGURATION_MODE_UNCOMPRESSED, 1
.set CYDEV_DEBUG_PROTECT_KILL, 4
.set CYDEV_DEBUG_PROTECT_OPEN, 1
.set CYDEV_DEBUG_PROTECT, CYDEV_DEBUG_PROTECT_OPEN
.set CYDEV_DEBUG_PROTECT_PROTECTED, 2
.set CYDEV_DEBUGGING_DPS_Disable, 3
.set CYDEV_DEBUGGING_DPS_SWD, 2
.set CYDEV_DEBUGGING_DPS, CYDEV_DEBUGGING_DPS_SWD
.set CYDEV_DEBUGGING_ENABLE, 1
.set CYDEV_HEAP_SIZE, 0x0100
.set CYDEV_PROJ_TYPE, 0
.set CYDEV_PROJ_TYPE_BOOTLOADER, 1
.set CYDEV_PROJ_TYPE_LOADABLE, 2
.set CYDEV_PROJ_TYPE_MULTIAPPBOOTLOADER, 3
.set CYDEV_PROJ_TYPE_STANDARD, 0
.set CYDEV_STACK_SIZE, 0x0400
.set CYDEV_USE_BUNDLED_CMSIS, 1
.set CYDEV_VARIABLE_VDDA, 1
.set CYDEV_VDDA_MV, 3300
.set CYDEV_VDDD_MV, 3300
.set CYIPBLOCK_M0S8_CTBM_VERSION, 0
.set CYIPBLOCK_m0s8cpuss_VERSION, 0
.set CYIPBLOCK_m0s8csd_VERSION, 0
.set CYIPBLOCK_m0s8gpio2_VERSION, 0
.set CYIPBLOCK_m0s8hsiom4a_VERSION, 0
.set CYIPBLOCK_m0s8lcd_VERSION, 0
.set CYIPBLOCK_m0s8lpcomp_VERSION, 0
.set CYIPBLOCK_m0s8pclk_VERSION, 0
.set CYIPBLOCK_m0s8sar_VERSION, 0
.set CYIPBLOCK_m0s8scb_VERSION, 0
.set CYIPBLOCK_m0s8srssv2_VERSION, 1
.set CYIPBLOCK_m0s8tcpwm_VERSION, 0
.set CYIPBLOCK_m0s8udbif_VERSION, 0
.set CYIPBLOCK_S8_GPIO_VERSION, 2
.set CYDEV_BOOTLOADER_ENABLE, 0
.endif