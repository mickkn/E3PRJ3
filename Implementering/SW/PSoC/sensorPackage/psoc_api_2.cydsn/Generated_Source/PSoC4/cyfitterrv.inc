    IF :LNOT::DEF:INCLUDED_CYFITTERRV_INC
INCLUDED_CYFITTERRV_INC EQU 1
    GET cydevicerv_trm.inc

; P_VP
P_VP__0__DM__MASK EQU 0x07
P_VP__0__DM__SHIFT EQU 0
P_VP__0__DR EQU CYREG_PRT2_DR
P_VP__0__HSIOM EQU CYREG_HSIOM_PORT_SEL2
P_VP__0__HSIOM_MASK EQU 0x0000000F
P_VP__0__HSIOM_SHIFT EQU 0
P_VP__0__INTCFG EQU CYREG_PRT2_INTCFG
P_VP__0__INTSTAT EQU CYREG_PRT2_INTSTAT
P_VP__0__MASK EQU 0x01
P_VP__0__PA__CFG0 EQU CYREG_UDB_PA2_CFG0
P_VP__0__PA__CFG1 EQU CYREG_UDB_PA2_CFG1
P_VP__0__PA__CFG10 EQU CYREG_UDB_PA2_CFG10
P_VP__0__PA__CFG11 EQU CYREG_UDB_PA2_CFG11
P_VP__0__PA__CFG12 EQU CYREG_UDB_PA2_CFG12
P_VP__0__PA__CFG13 EQU CYREG_UDB_PA2_CFG13
P_VP__0__PA__CFG14 EQU CYREG_UDB_PA2_CFG14
P_VP__0__PA__CFG2 EQU CYREG_UDB_PA2_CFG2
P_VP__0__PA__CFG3 EQU CYREG_UDB_PA2_CFG3
P_VP__0__PA__CFG4 EQU CYREG_UDB_PA2_CFG4
P_VP__0__PA__CFG5 EQU CYREG_UDB_PA2_CFG5
P_VP__0__PA__CFG6 EQU CYREG_UDB_PA2_CFG6
P_VP__0__PA__CFG7 EQU CYREG_UDB_PA2_CFG7
P_VP__0__PA__CFG8 EQU CYREG_UDB_PA2_CFG8
P_VP__0__PA__CFG9 EQU CYREG_UDB_PA2_CFG9
P_VP__0__PC EQU CYREG_PRT2_PC
P_VP__0__PC2 EQU CYREG_PRT2_PC2
P_VP__0__PORT EQU 2
P_VP__0__PS EQU CYREG_PRT2_PS
P_VP__0__SHIFT EQU 0
P_VP__DR EQU CYREG_PRT2_DR
P_VP__INTCFG EQU CYREG_PRT2_INTCFG
P_VP__INTSTAT EQU CYREG_PRT2_INTSTAT
P_VP__MASK EQU 0x01
P_VP__PA__CFG0 EQU CYREG_UDB_PA2_CFG0
P_VP__PA__CFG1 EQU CYREG_UDB_PA2_CFG1
P_VP__PA__CFG10 EQU CYREG_UDB_PA2_CFG10
P_VP__PA__CFG11 EQU CYREG_UDB_PA2_CFG11
P_VP__PA__CFG12 EQU CYREG_UDB_PA2_CFG12
P_VP__PA__CFG13 EQU CYREG_UDB_PA2_CFG13
P_VP__PA__CFG14 EQU CYREG_UDB_PA2_CFG14
P_VP__PA__CFG2 EQU CYREG_UDB_PA2_CFG2
P_VP__PA__CFG3 EQU CYREG_UDB_PA2_CFG3
P_VP__PA__CFG4 EQU CYREG_UDB_PA2_CFG4
P_VP__PA__CFG5 EQU CYREG_UDB_PA2_CFG5
P_VP__PA__CFG6 EQU CYREG_UDB_PA2_CFG6
P_VP__PA__CFG7 EQU CYREG_UDB_PA2_CFG7
P_VP__PA__CFG8 EQU CYREG_UDB_PA2_CFG8
P_VP__PA__CFG9 EQU CYREG_UDB_PA2_CFG9
P_VP__PC EQU CYREG_PRT2_PC
P_VP__PC2 EQU CYREG_PRT2_PC2
P_VP__PORT EQU 2
P_VP__PS EQU CYREG_PRT2_PS
P_VP__SHIFT EQU 0

; P_FT1
P_FT1__0__DM__MASK EQU 0x38000
P_FT1__0__DM__SHIFT EQU 15
P_FT1__0__DR EQU CYREG_PRT2_DR
P_FT1__0__HSIOM EQU CYREG_HSIOM_PORT_SEL2
P_FT1__0__HSIOM_MASK EQU 0x00F00000
P_FT1__0__HSIOM_SHIFT EQU 20
P_FT1__0__INTCFG EQU CYREG_PRT2_INTCFG
P_FT1__0__INTSTAT EQU CYREG_PRT2_INTSTAT
P_FT1__0__MASK EQU 0x20
P_FT1__0__PA__CFG0 EQU CYREG_UDB_PA2_CFG0
P_FT1__0__PA__CFG1 EQU CYREG_UDB_PA2_CFG1
P_FT1__0__PA__CFG10 EQU CYREG_UDB_PA2_CFG10
P_FT1__0__PA__CFG11 EQU CYREG_UDB_PA2_CFG11
P_FT1__0__PA__CFG12 EQU CYREG_UDB_PA2_CFG12
P_FT1__0__PA__CFG13 EQU CYREG_UDB_PA2_CFG13
P_FT1__0__PA__CFG14 EQU CYREG_UDB_PA2_CFG14
P_FT1__0__PA__CFG2 EQU CYREG_UDB_PA2_CFG2
P_FT1__0__PA__CFG3 EQU CYREG_UDB_PA2_CFG3
P_FT1__0__PA__CFG4 EQU CYREG_UDB_PA2_CFG4
P_FT1__0__PA__CFG5 EQU CYREG_UDB_PA2_CFG5
P_FT1__0__PA__CFG6 EQU CYREG_UDB_PA2_CFG6
P_FT1__0__PA__CFG7 EQU CYREG_UDB_PA2_CFG7
P_FT1__0__PA__CFG8 EQU CYREG_UDB_PA2_CFG8
P_FT1__0__PA__CFG9 EQU CYREG_UDB_PA2_CFG9
P_FT1__0__PC EQU CYREG_PRT2_PC
P_FT1__0__PC2 EQU CYREG_PRT2_PC2
P_FT1__0__PORT EQU 2
P_FT1__0__PS EQU CYREG_PRT2_PS
P_FT1__0__SHIFT EQU 5
P_FT1__DR EQU CYREG_PRT2_DR
P_FT1__INTCFG EQU CYREG_PRT2_INTCFG
P_FT1__INTSTAT EQU CYREG_PRT2_INTSTAT
P_FT1__MASK EQU 0x20
P_FT1__PA__CFG0 EQU CYREG_UDB_PA2_CFG0
P_FT1__PA__CFG1 EQU CYREG_UDB_PA2_CFG1
P_FT1__PA__CFG10 EQU CYREG_UDB_PA2_CFG10
P_FT1__PA__CFG11 EQU CYREG_UDB_PA2_CFG11
P_FT1__PA__CFG12 EQU CYREG_UDB_PA2_CFG12
P_FT1__PA__CFG13 EQU CYREG_UDB_PA2_CFG13
P_FT1__PA__CFG14 EQU CYREG_UDB_PA2_CFG14
P_FT1__PA__CFG2 EQU CYREG_UDB_PA2_CFG2
P_FT1__PA__CFG3 EQU CYREG_UDB_PA2_CFG3
P_FT1__PA__CFG4 EQU CYREG_UDB_PA2_CFG4
P_FT1__PA__CFG5 EQU CYREG_UDB_PA2_CFG5
P_FT1__PA__CFG6 EQU CYREG_UDB_PA2_CFG6
P_FT1__PA__CFG7 EQU CYREG_UDB_PA2_CFG7
P_FT1__PA__CFG8 EQU CYREG_UDB_PA2_CFG8
P_FT1__PA__CFG9 EQU CYREG_UDB_PA2_CFG9
P_FT1__PC EQU CYREG_PRT2_PC
P_FT1__PC2 EQU CYREG_PRT2_PC2
P_FT1__PORT EQU 2
P_FT1__PS EQU CYREG_PRT2_PS
P_FT1__SHIFT EQU 5

; P_FT2
P_FT2__0__DM__MASK EQU 0x07
P_FT2__0__DM__SHIFT EQU 0
P_FT2__0__DR EQU CYREG_PRT0_DR
P_FT2__0__HSIOM EQU CYREG_HSIOM_PORT_SEL0
P_FT2__0__HSIOM_MASK EQU 0x0000000F
P_FT2__0__HSIOM_SHIFT EQU 0
P_FT2__0__INTCFG EQU CYREG_PRT0_INTCFG
P_FT2__0__INTSTAT EQU CYREG_PRT0_INTSTAT
P_FT2__0__MASK EQU 0x01
P_FT2__0__PA__CFG0 EQU CYREG_UDB_PA0_CFG0
P_FT2__0__PA__CFG1 EQU CYREG_UDB_PA0_CFG1
P_FT2__0__PA__CFG10 EQU CYREG_UDB_PA0_CFG10
P_FT2__0__PA__CFG11 EQU CYREG_UDB_PA0_CFG11
P_FT2__0__PA__CFG12 EQU CYREG_UDB_PA0_CFG12
P_FT2__0__PA__CFG13 EQU CYREG_UDB_PA0_CFG13
P_FT2__0__PA__CFG14 EQU CYREG_UDB_PA0_CFG14
P_FT2__0__PA__CFG2 EQU CYREG_UDB_PA0_CFG2
P_FT2__0__PA__CFG3 EQU CYREG_UDB_PA0_CFG3
P_FT2__0__PA__CFG4 EQU CYREG_UDB_PA0_CFG4
P_FT2__0__PA__CFG5 EQU CYREG_UDB_PA0_CFG5
P_FT2__0__PA__CFG6 EQU CYREG_UDB_PA0_CFG6
P_FT2__0__PA__CFG7 EQU CYREG_UDB_PA0_CFG7
P_FT2__0__PA__CFG8 EQU CYREG_UDB_PA0_CFG8
P_FT2__0__PA__CFG9 EQU CYREG_UDB_PA0_CFG9
P_FT2__0__PC EQU CYREG_PRT0_PC
P_FT2__0__PC2 EQU CYREG_PRT0_PC2
P_FT2__0__PORT EQU 0
P_FT2__0__PS EQU CYREG_PRT0_PS
P_FT2__0__SHIFT EQU 0
P_FT2__DR EQU CYREG_PRT0_DR
P_FT2__INTCFG EQU CYREG_PRT0_INTCFG
P_FT2__INTSTAT EQU CYREG_PRT0_INTSTAT
P_FT2__MASK EQU 0x01
P_FT2__PA__CFG0 EQU CYREG_UDB_PA0_CFG0
P_FT2__PA__CFG1 EQU CYREG_UDB_PA0_CFG1
P_FT2__PA__CFG10 EQU CYREG_UDB_PA0_CFG10
P_FT2__PA__CFG11 EQU CYREG_UDB_PA0_CFG11
P_FT2__PA__CFG12 EQU CYREG_UDB_PA0_CFG12
P_FT2__PA__CFG13 EQU CYREG_UDB_PA0_CFG13
P_FT2__PA__CFG14 EQU CYREG_UDB_PA0_CFG14
P_FT2__PA__CFG2 EQU CYREG_UDB_PA0_CFG2
P_FT2__PA__CFG3 EQU CYREG_UDB_PA0_CFG3
P_FT2__PA__CFG4 EQU CYREG_UDB_PA0_CFG4
P_FT2__PA__CFG5 EQU CYREG_UDB_PA0_CFG5
P_FT2__PA__CFG6 EQU CYREG_UDB_PA0_CFG6
P_FT2__PA__CFG7 EQU CYREG_UDB_PA0_CFG7
P_FT2__PA__CFG8 EQU CYREG_UDB_PA0_CFG8
P_FT2__PA__CFG9 EQU CYREG_UDB_PA0_CFG9
P_FT2__PC EQU CYREG_PRT0_PC
P_FT2__PC2 EQU CYREG_PRT0_PC2
P_FT2__PORT EQU 0
P_FT2__PS EQU CYREG_PRT0_PS
P_FT2__SHIFT EQU 0

; ADC_SAR_Seq_0_cy_psoc4_sar
ADC_SAR_Seq_0_cy_psoc4_sar__SAR_CTRL EQU CYREG_SAR_CTRL
ADC_SAR_Seq_0_cy_psoc4_sar__SAR_INTR EQU CYREG_SAR_INTR
ADC_SAR_Seq_0_cy_psoc4_sar__SAR_INTR_CAUSE EQU CYREG_SAR_INTR_CAUSE
ADC_SAR_Seq_0_cy_psoc4_sar__SAR_INTR_MASK EQU CYREG_SAR_INTR_MASK
ADC_SAR_Seq_0_cy_psoc4_sar__SAR_INTR_MASKED EQU CYREG_SAR_INTR_MASKED
ADC_SAR_Seq_0_cy_psoc4_sar__SAR_INTR_SET EQU CYREG_SAR_INTR_SET
ADC_SAR_Seq_0_cy_psoc4_sar__SAR_NUMBER EQU 0
ADC_SAR_Seq_0_cy_psoc4_sar__SAR_RANGE_COND EQU CYREG_SAR_RANGE_COND
ADC_SAR_Seq_0_cy_psoc4_sar__SAR_RANGE_INTR_MASK EQU CYREG_SAR_RANGE_INTR_MASK
ADC_SAR_Seq_0_cy_psoc4_sar__SAR_RANGE_INTR_MASKED EQU CYREG_SAR_RANGE_INTR_MASKED
ADC_SAR_Seq_0_cy_psoc4_sar__SAR_RANGE_INTR_SET EQU CYREG_SAR_RANGE_INTR_SET
ADC_SAR_Seq_0_cy_psoc4_sar__SAR_RANGE_THRES EQU CYREG_SAR_RANGE_THRES
ADC_SAR_Seq_0_cy_psoc4_sar__SAR_SAMPLE_CTRL EQU CYREG_SAR_SAMPLE_CTRL
ADC_SAR_Seq_0_cy_psoc4_sar__SAR_SAMPLE_TIME01 EQU CYREG_SAR_SAMPLE_TIME01
ADC_SAR_Seq_0_cy_psoc4_sar__SAR_SAMPLE_TIME23 EQU CYREG_SAR_SAMPLE_TIME23
ADC_SAR_Seq_0_cy_psoc4_sar__SAR_SATURATE_INTR_MASK EQU CYREG_SAR_SATURATE_INTR_MASK
ADC_SAR_Seq_0_cy_psoc4_sar__SAR_SATURATE_INTR_MASKED EQU CYREG_SAR_SATURATE_INTR_MASKED
ADC_SAR_Seq_0_cy_psoc4_sar__SAR_SATURATE_INTR_SET EQU CYREG_SAR_SATURATE_INTR_SET

; ADC_SAR_Seq_0_intClock
ADC_SAR_Seq_0_intClock__DIVIDER_MASK EQU 0x0000FFFF
ADC_SAR_Seq_0_intClock__ENABLE EQU CYREG_CLK_DIVIDER_A00
ADC_SAR_Seq_0_intClock__ENABLE_MASK EQU 0x80000000
ADC_SAR_Seq_0_intClock__MASK EQU 0x80000000
ADC_SAR_Seq_0_intClock__REGISTER EQU CYREG_CLK_DIVIDER_A00

; ADC_SAR_Seq_0_IRQ
ADC_SAR_Seq_0_IRQ__INTC_CLR_EN_REG EQU CYREG_CM0_ICER
ADC_SAR_Seq_0_IRQ__INTC_CLR_PD_REG EQU CYREG_CM0_ICPR
ADC_SAR_Seq_0_IRQ__INTC_MASK EQU 0x4000
ADC_SAR_Seq_0_IRQ__INTC_NUMBER EQU 14
ADC_SAR_Seq_0_IRQ__INTC_PRIOR_MASK EQU 0xC00000
ADC_SAR_Seq_0_IRQ__INTC_PRIOR_NUM EQU 3
ADC_SAR_Seq_0_IRQ__INTC_PRIOR_REG EQU CYREG_CM0_IPR3
ADC_SAR_Seq_0_IRQ__INTC_SET_EN_REG EQU CYREG_CM0_ISER
ADC_SAR_Seq_0_IRQ__INTC_SET_PD_REG EQU CYREG_CM0_ISPR

; Miscellaneous
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
    ENDIF
    END
