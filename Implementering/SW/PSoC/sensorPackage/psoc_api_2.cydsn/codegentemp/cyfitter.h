#ifndef INCLUDED_CYFITTER_H
#define INCLUDED_CYFITTER_H
#include <cydevice_trm.h>

/* SLC */
#define SLC__0__DM__MASK 0x07u
#define SLC__0__DM__SHIFT 0
#define SLC__0__DR CYREG_PRT0_DR
#define SLC__0__HSIOM CYREG_HSIOM_PORT_SEL0
#define SLC__0__HSIOM_MASK 0x0000000Fu
#define SLC__0__HSIOM_SHIFT 0u
#define SLC__0__INTCFG CYREG_PRT0_INTCFG
#define SLC__0__INTSTAT CYREG_PRT0_INTSTAT
#define SLC__0__MASK 0x01u
#define SLC__0__PA__CFG0 CYREG_UDB_PA0_CFG0
#define SLC__0__PA__CFG1 CYREG_UDB_PA0_CFG1
#define SLC__0__PA__CFG10 CYREG_UDB_PA0_CFG10
#define SLC__0__PA__CFG11 CYREG_UDB_PA0_CFG11
#define SLC__0__PA__CFG12 CYREG_UDB_PA0_CFG12
#define SLC__0__PA__CFG13 CYREG_UDB_PA0_CFG13
#define SLC__0__PA__CFG14 CYREG_UDB_PA0_CFG14
#define SLC__0__PA__CFG2 CYREG_UDB_PA0_CFG2
#define SLC__0__PA__CFG3 CYREG_UDB_PA0_CFG3
#define SLC__0__PA__CFG4 CYREG_UDB_PA0_CFG4
#define SLC__0__PA__CFG5 CYREG_UDB_PA0_CFG5
#define SLC__0__PA__CFG6 CYREG_UDB_PA0_CFG6
#define SLC__0__PA__CFG7 CYREG_UDB_PA0_CFG7
#define SLC__0__PA__CFG8 CYREG_UDB_PA0_CFG8
#define SLC__0__PA__CFG9 CYREG_UDB_PA0_CFG9
#define SLC__0__PC CYREG_PRT0_PC
#define SLC__0__PC2 CYREG_PRT0_PC2
#define SLC__0__PORT 0u
#define SLC__0__PS CYREG_PRT0_PS
#define SLC__0__SHIFT 0
#define SLC__DR CYREG_PRT0_DR
#define SLC__INTCFG CYREG_PRT0_INTCFG
#define SLC__INTSTAT CYREG_PRT0_INTSTAT
#define SLC__MASK 0x01u
#define SLC__PA__CFG0 CYREG_UDB_PA0_CFG0
#define SLC__PA__CFG1 CYREG_UDB_PA0_CFG1
#define SLC__PA__CFG10 CYREG_UDB_PA0_CFG10
#define SLC__PA__CFG11 CYREG_UDB_PA0_CFG11
#define SLC__PA__CFG12 CYREG_UDB_PA0_CFG12
#define SLC__PA__CFG13 CYREG_UDB_PA0_CFG13
#define SLC__PA__CFG14 CYREG_UDB_PA0_CFG14
#define SLC__PA__CFG2 CYREG_UDB_PA0_CFG2
#define SLC__PA__CFG3 CYREG_UDB_PA0_CFG3
#define SLC__PA__CFG4 CYREG_UDB_PA0_CFG4
#define SLC__PA__CFG5 CYREG_UDB_PA0_CFG5
#define SLC__PA__CFG6 CYREG_UDB_PA0_CFG6
#define SLC__PA__CFG7 CYREG_UDB_PA0_CFG7
#define SLC__PA__CFG8 CYREG_UDB_PA0_CFG8
#define SLC__PA__CFG9 CYREG_UDB_PA0_CFG9
#define SLC__PC CYREG_PRT0_PC
#define SLC__PC2 CYREG_PRT0_PC2
#define SLC__PORT 0u
#define SLC__PS CYREG_PRT0_PS
#define SLC__SHIFT 0

/* ADC_in */
#define ADC_in__0__DM__MASK 0xE00u
#define ADC_in__0__DM__SHIFT 9
#define ADC_in__0__DR CYREG_PRT2_DR
#define ADC_in__0__HSIOM CYREG_HSIOM_PORT_SEL2
#define ADC_in__0__HSIOM_MASK 0x0000F000u
#define ADC_in__0__HSIOM_SHIFT 12u
#define ADC_in__0__INTCFG CYREG_PRT2_INTCFG
#define ADC_in__0__INTSTAT CYREG_PRT2_INTSTAT
#define ADC_in__0__MASK 0x08u
#define ADC_in__0__PA__CFG0 CYREG_UDB_PA2_CFG0
#define ADC_in__0__PA__CFG1 CYREG_UDB_PA2_CFG1
#define ADC_in__0__PA__CFG10 CYREG_UDB_PA2_CFG10
#define ADC_in__0__PA__CFG11 CYREG_UDB_PA2_CFG11
#define ADC_in__0__PA__CFG12 CYREG_UDB_PA2_CFG12
#define ADC_in__0__PA__CFG13 CYREG_UDB_PA2_CFG13
#define ADC_in__0__PA__CFG14 CYREG_UDB_PA2_CFG14
#define ADC_in__0__PA__CFG2 CYREG_UDB_PA2_CFG2
#define ADC_in__0__PA__CFG3 CYREG_UDB_PA2_CFG3
#define ADC_in__0__PA__CFG4 CYREG_UDB_PA2_CFG4
#define ADC_in__0__PA__CFG5 CYREG_UDB_PA2_CFG5
#define ADC_in__0__PA__CFG6 CYREG_UDB_PA2_CFG6
#define ADC_in__0__PA__CFG7 CYREG_UDB_PA2_CFG7
#define ADC_in__0__PA__CFG8 CYREG_UDB_PA2_CFG8
#define ADC_in__0__PA__CFG9 CYREG_UDB_PA2_CFG9
#define ADC_in__0__PC CYREG_PRT2_PC
#define ADC_in__0__PC2 CYREG_PRT2_PC2
#define ADC_in__0__PORT 2u
#define ADC_in__0__PS CYREG_PRT2_PS
#define ADC_in__0__SHIFT 3
#define ADC_in__DR CYREG_PRT2_DR
#define ADC_in__INTCFG CYREG_PRT2_INTCFG
#define ADC_in__INTSTAT CYREG_PRT2_INTSTAT
#define ADC_in__MASK 0x08u
#define ADC_in__PA__CFG0 CYREG_UDB_PA2_CFG0
#define ADC_in__PA__CFG1 CYREG_UDB_PA2_CFG1
#define ADC_in__PA__CFG10 CYREG_UDB_PA2_CFG10
#define ADC_in__PA__CFG11 CYREG_UDB_PA2_CFG11
#define ADC_in__PA__CFG12 CYREG_UDB_PA2_CFG12
#define ADC_in__PA__CFG13 CYREG_UDB_PA2_CFG13
#define ADC_in__PA__CFG14 CYREG_UDB_PA2_CFG14
#define ADC_in__PA__CFG2 CYREG_UDB_PA2_CFG2
#define ADC_in__PA__CFG3 CYREG_UDB_PA2_CFG3
#define ADC_in__PA__CFG4 CYREG_UDB_PA2_CFG4
#define ADC_in__PA__CFG5 CYREG_UDB_PA2_CFG5
#define ADC_in__PA__CFG6 CYREG_UDB_PA2_CFG6
#define ADC_in__PA__CFG7 CYREG_UDB_PA2_CFG7
#define ADC_in__PA__CFG8 CYREG_UDB_PA2_CFG8
#define ADC_in__PA__CFG9 CYREG_UDB_PA2_CFG9
#define ADC_in__PC CYREG_PRT2_PC
#define ADC_in__PC2 CYREG_PRT2_PC2
#define ADC_in__PORT 2u
#define ADC_in__PS CYREG_PRT2_PS
#define ADC_in__SHIFT 3

/* testPin */
#define testPin__0__DM__MASK 0x1C0u
#define testPin__0__DM__SHIFT 6
#define testPin__0__DR CYREG_PRT2_DR
#define testPin__0__HSIOM CYREG_HSIOM_PORT_SEL2
#define testPin__0__HSIOM_MASK 0x00000F00u
#define testPin__0__HSIOM_SHIFT 8u
#define testPin__0__INTCFG CYREG_PRT2_INTCFG
#define testPin__0__INTSTAT CYREG_PRT2_INTSTAT
#define testPin__0__MASK 0x04u
#define testPin__0__PA__CFG0 CYREG_UDB_PA2_CFG0
#define testPin__0__PA__CFG1 CYREG_UDB_PA2_CFG1
#define testPin__0__PA__CFG10 CYREG_UDB_PA2_CFG10
#define testPin__0__PA__CFG11 CYREG_UDB_PA2_CFG11
#define testPin__0__PA__CFG12 CYREG_UDB_PA2_CFG12
#define testPin__0__PA__CFG13 CYREG_UDB_PA2_CFG13
#define testPin__0__PA__CFG14 CYREG_UDB_PA2_CFG14
#define testPin__0__PA__CFG2 CYREG_UDB_PA2_CFG2
#define testPin__0__PA__CFG3 CYREG_UDB_PA2_CFG3
#define testPin__0__PA__CFG4 CYREG_UDB_PA2_CFG4
#define testPin__0__PA__CFG5 CYREG_UDB_PA2_CFG5
#define testPin__0__PA__CFG6 CYREG_UDB_PA2_CFG6
#define testPin__0__PA__CFG7 CYREG_UDB_PA2_CFG7
#define testPin__0__PA__CFG8 CYREG_UDB_PA2_CFG8
#define testPin__0__PA__CFG9 CYREG_UDB_PA2_CFG9
#define testPin__0__PC CYREG_PRT2_PC
#define testPin__0__PC2 CYREG_PRT2_PC2
#define testPin__0__PORT 2u
#define testPin__0__PS CYREG_PRT2_PS
#define testPin__0__SHIFT 2
#define testPin__DR CYREG_PRT2_DR
#define testPin__INTCFG CYREG_PRT2_INTCFG
#define testPin__INTSTAT CYREG_PRT2_INTSTAT
#define testPin__MASK 0x04u
#define testPin__PA__CFG0 CYREG_UDB_PA2_CFG0
#define testPin__PA__CFG1 CYREG_UDB_PA2_CFG1
#define testPin__PA__CFG10 CYREG_UDB_PA2_CFG10
#define testPin__PA__CFG11 CYREG_UDB_PA2_CFG11
#define testPin__PA__CFG12 CYREG_UDB_PA2_CFG12
#define testPin__PA__CFG13 CYREG_UDB_PA2_CFG13
#define testPin__PA__CFG14 CYREG_UDB_PA2_CFG14
#define testPin__PA__CFG2 CYREG_UDB_PA2_CFG2
#define testPin__PA__CFG3 CYREG_UDB_PA2_CFG3
#define testPin__PA__CFG4 CYREG_UDB_PA2_CFG4
#define testPin__PA__CFG5 CYREG_UDB_PA2_CFG5
#define testPin__PA__CFG6 CYREG_UDB_PA2_CFG6
#define testPin__PA__CFG7 CYREG_UDB_PA2_CFG7
#define testPin__PA__CFG8 CYREG_UDB_PA2_CFG8
#define testPin__PA__CFG9 CYREG_UDB_PA2_CFG9
#define testPin__PC CYREG_PRT2_PC
#define testPin__PC2 CYREG_PRT2_PC2
#define testPin__PORT 2u
#define testPin__PS CYREG_PRT2_PS
#define testPin__SHIFT 2

/* water_pin */
#define water_pin__0__DM__MASK 0x07u
#define water_pin__0__DM__SHIFT 0
#define water_pin__0__DR CYREG_PRT2_DR
#define water_pin__0__HSIOM CYREG_HSIOM_PORT_SEL2
#define water_pin__0__HSIOM_MASK 0x0000000Fu
#define water_pin__0__HSIOM_SHIFT 0u
#define water_pin__0__INTCFG CYREG_PRT2_INTCFG
#define water_pin__0__INTSTAT CYREG_PRT2_INTSTAT
#define water_pin__0__MASK 0x01u
#define water_pin__0__PA__CFG0 CYREG_UDB_PA2_CFG0
#define water_pin__0__PA__CFG1 CYREG_UDB_PA2_CFG1
#define water_pin__0__PA__CFG10 CYREG_UDB_PA2_CFG10
#define water_pin__0__PA__CFG11 CYREG_UDB_PA2_CFG11
#define water_pin__0__PA__CFG12 CYREG_UDB_PA2_CFG12
#define water_pin__0__PA__CFG13 CYREG_UDB_PA2_CFG13
#define water_pin__0__PA__CFG14 CYREG_UDB_PA2_CFG14
#define water_pin__0__PA__CFG2 CYREG_UDB_PA2_CFG2
#define water_pin__0__PA__CFG3 CYREG_UDB_PA2_CFG3
#define water_pin__0__PA__CFG4 CYREG_UDB_PA2_CFG4
#define water_pin__0__PA__CFG5 CYREG_UDB_PA2_CFG5
#define water_pin__0__PA__CFG6 CYREG_UDB_PA2_CFG6
#define water_pin__0__PA__CFG7 CYREG_UDB_PA2_CFG7
#define water_pin__0__PA__CFG8 CYREG_UDB_PA2_CFG8
#define water_pin__0__PA__CFG9 CYREG_UDB_PA2_CFG9
#define water_pin__0__PC CYREG_PRT2_PC
#define water_pin__0__PC2 CYREG_PRT2_PC2
#define water_pin__0__PORT 2u
#define water_pin__0__PS CYREG_PRT2_PS
#define water_pin__0__SHIFT 0
#define water_pin__DR CYREG_PRT2_DR
#define water_pin__INTCFG CYREG_PRT2_INTCFG
#define water_pin__INTSTAT CYREG_PRT2_INTSTAT
#define water_pin__MASK 0x01u
#define water_pin__PA__CFG0 CYREG_UDB_PA2_CFG0
#define water_pin__PA__CFG1 CYREG_UDB_PA2_CFG1
#define water_pin__PA__CFG10 CYREG_UDB_PA2_CFG10
#define water_pin__PA__CFG11 CYREG_UDB_PA2_CFG11
#define water_pin__PA__CFG12 CYREG_UDB_PA2_CFG12
#define water_pin__PA__CFG13 CYREG_UDB_PA2_CFG13
#define water_pin__PA__CFG14 CYREG_UDB_PA2_CFG14
#define water_pin__PA__CFG2 CYREG_UDB_PA2_CFG2
#define water_pin__PA__CFG3 CYREG_UDB_PA2_CFG3
#define water_pin__PA__CFG4 CYREG_UDB_PA2_CFG4
#define water_pin__PA__CFG5 CYREG_UDB_PA2_CFG5
#define water_pin__PA__CFG6 CYREG_UDB_PA2_CFG6
#define water_pin__PA__CFG7 CYREG_UDB_PA2_CFG7
#define water_pin__PA__CFG8 CYREG_UDB_PA2_CFG8
#define water_pin__PA__CFG9 CYREG_UDB_PA2_CFG9
#define water_pin__PC CYREG_PRT2_PC
#define water_pin__PC2 CYREG_PRT2_PC2
#define water_pin__PORT 2u
#define water_pin__PS CYREG_PRT2_PS
#define water_pin__SHIFT 0

/* ADC_SAR_Seq_0_cy_psoc4_sar */
#define ADC_SAR_Seq_0_cy_psoc4_sar__SAR_CTRL CYREG_SAR_CTRL
#define ADC_SAR_Seq_0_cy_psoc4_sar__SAR_INTR CYREG_SAR_INTR
#define ADC_SAR_Seq_0_cy_psoc4_sar__SAR_INTR_CAUSE CYREG_SAR_INTR_CAUSE
#define ADC_SAR_Seq_0_cy_psoc4_sar__SAR_INTR_MASK CYREG_SAR_INTR_MASK
#define ADC_SAR_Seq_0_cy_psoc4_sar__SAR_INTR_MASKED CYREG_SAR_INTR_MASKED
#define ADC_SAR_Seq_0_cy_psoc4_sar__SAR_INTR_SET CYREG_SAR_INTR_SET
#define ADC_SAR_Seq_0_cy_psoc4_sar__SAR_NUMBER 0u
#define ADC_SAR_Seq_0_cy_psoc4_sar__SAR_RANGE_COND CYREG_SAR_RANGE_COND
#define ADC_SAR_Seq_0_cy_psoc4_sar__SAR_RANGE_INTR_MASK CYREG_SAR_RANGE_INTR_MASK
#define ADC_SAR_Seq_0_cy_psoc4_sar__SAR_RANGE_INTR_MASKED CYREG_SAR_RANGE_INTR_MASKED
#define ADC_SAR_Seq_0_cy_psoc4_sar__SAR_RANGE_INTR_SET CYREG_SAR_RANGE_INTR_SET
#define ADC_SAR_Seq_0_cy_psoc4_sar__SAR_RANGE_THRES CYREG_SAR_RANGE_THRES
#define ADC_SAR_Seq_0_cy_psoc4_sar__SAR_SAMPLE_CTRL CYREG_SAR_SAMPLE_CTRL
#define ADC_SAR_Seq_0_cy_psoc4_sar__SAR_SAMPLE_TIME01 CYREG_SAR_SAMPLE_TIME01
#define ADC_SAR_Seq_0_cy_psoc4_sar__SAR_SAMPLE_TIME23 CYREG_SAR_SAMPLE_TIME23
#define ADC_SAR_Seq_0_cy_psoc4_sar__SAR_SATURATE_INTR_MASK CYREG_SAR_SATURATE_INTR_MASK
#define ADC_SAR_Seq_0_cy_psoc4_sar__SAR_SATURATE_INTR_MASKED CYREG_SAR_SATURATE_INTR_MASKED
#define ADC_SAR_Seq_0_cy_psoc4_sar__SAR_SATURATE_INTR_SET CYREG_SAR_SATURATE_INTR_SET

/* ADC_SAR_Seq_0_intClock */
#define ADC_SAR_Seq_0_intClock__DIVIDER_MASK 0x0000FFFFu
#define ADC_SAR_Seq_0_intClock__ENABLE CYREG_CLK_DIVIDER_A00
#define ADC_SAR_Seq_0_intClock__ENABLE_MASK 0x80000000u
#define ADC_SAR_Seq_0_intClock__MASK 0x80000000u
#define ADC_SAR_Seq_0_intClock__REGISTER CYREG_CLK_DIVIDER_A00

/* ADC_SAR_Seq_0_IRQ */
#define ADC_SAR_Seq_0_IRQ__INTC_CLR_EN_REG CYREG_CM0_ICER
#define ADC_SAR_Seq_0_IRQ__INTC_CLR_PD_REG CYREG_CM0_ICPR
#define ADC_SAR_Seq_0_IRQ__INTC_MASK 0x4000u
#define ADC_SAR_Seq_0_IRQ__INTC_NUMBER 14u
#define ADC_SAR_Seq_0_IRQ__INTC_PRIOR_MASK 0xC00000u
#define ADC_SAR_Seq_0_IRQ__INTC_PRIOR_NUM 3u
#define ADC_SAR_Seq_0_IRQ__INTC_PRIOR_REG CYREG_CM0_IPR3
#define ADC_SAR_Seq_0_IRQ__INTC_SET_EN_REG CYREG_CM0_ISER
#define ADC_SAR_Seq_0_IRQ__INTC_SET_PD_REG CYREG_CM0_ISPR

/* Miscellaneous */
#define CYDEV_BCLK__HFCLK__HZ 24000000U
#define CYDEV_BCLK__HFCLK__KHZ 24000U
#define CYDEV_BCLK__HFCLK__MHZ 24U
#define CYDEV_BCLK__SYSCLK__HZ 24000000U
#define CYDEV_BCLK__SYSCLK__KHZ 24000U
#define CYDEV_BCLK__SYSCLK__MHZ 24U
#define CYDEV_CHIP_DIE_LEOPARD 1u
#define CYDEV_CHIP_DIE_PANTHER 4u
#define CYDEV_CHIP_DIE_PSOC4A 2u
#define CYDEV_CHIP_DIE_PSOC5LP 5u
#define CYDEV_CHIP_DIE_UNKNOWN 0u
#define CYDEV_CHIP_FAMILY_PSOC3 1u
#define CYDEV_CHIP_FAMILY_PSOC4 2u
#define CYDEV_CHIP_FAMILY_PSOC5 3u
#define CYDEV_CHIP_FAMILY_UNKNOWN 0u
#define CYDEV_CHIP_FAMILY_USED CYDEV_CHIP_FAMILY_PSOC4
#define CYDEV_CHIP_JTAG_ID 0x04C81193u
#define CYDEV_CHIP_MEMBER_3A 1u
#define CYDEV_CHIP_MEMBER_4A 2u
#define CYDEV_CHIP_MEMBER_4D 3u
#define CYDEV_CHIP_MEMBER_5A 4u
#define CYDEV_CHIP_MEMBER_5B 5u
#define CYDEV_CHIP_MEMBER_UNKNOWN 0u
#define CYDEV_CHIP_MEMBER_USED CYDEV_CHIP_MEMBER_4A
#define CYDEV_CHIP_DIE_EXPECT CYDEV_CHIP_MEMBER_USED
#define CYDEV_CHIP_DIE_ACTUAL CYDEV_CHIP_DIE_EXPECT
#define CYDEV_CHIP_REV_LEOPARD_ES1 0u
#define CYDEV_CHIP_REV_LEOPARD_ES2 1u
#define CYDEV_CHIP_REV_LEOPARD_ES3 3u
#define CYDEV_CHIP_REV_LEOPARD_PRODUCTION 3u
#define CYDEV_CHIP_REV_PANTHER_ES0 0u
#define CYDEV_CHIP_REV_PANTHER_ES1 1u
#define CYDEV_CHIP_REV_PANTHER_PRODUCTION 1u
#define CYDEV_CHIP_REV_PSOC4A_ES0 17u
#define CYDEV_CHIP_REV_PSOC4A_PRODUCTION 17u
#define CYDEV_CHIP_REV_PSOC5LP_ES0 0u
#define CYDEV_CHIP_REV_PSOC5LP_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_3A_ES1 0u
#define CYDEV_CHIP_REVISION_3A_ES2 1u
#define CYDEV_CHIP_REVISION_3A_ES3 3u
#define CYDEV_CHIP_REVISION_3A_PRODUCTION 3u
#define CYDEV_CHIP_REVISION_4A_ES0 17u
#define CYDEV_CHIP_REVISION_4A_PRODUCTION 17u
#define CYDEV_CHIP_REVISION_4D_ES0 0u
#define CYDEV_CHIP_REVISION_4D_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_5A_ES0 0u
#define CYDEV_CHIP_REVISION_5A_ES1 1u
#define CYDEV_CHIP_REVISION_5A_PRODUCTION 1u
#define CYDEV_CHIP_REVISION_5B_ES0 0u
#define CYDEV_CHIP_REVISION_5B_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_USED CYDEV_CHIP_REVISION_4A_PRODUCTION
#define CYDEV_CHIP_REV_EXPECT CYDEV_CHIP_REVISION_USED
#define CYDEV_CONFIG_READ_ACCELERATOR 1
#define CYDEV_CONFIG_UNUSED_IO_AllowButWarn 0
#define CYDEV_CONFIG_UNUSED_IO CYDEV_CONFIG_UNUSED_IO_AllowButWarn
#define CYDEV_CONFIG_UNUSED_IO_AllowWithInfo 1
#define CYDEV_CONFIG_UNUSED_IO_Disallowed 2
#define CYDEV_CONFIGURATION_COMPRESSED 1
#define CYDEV_CONFIGURATION_MODE_COMPRESSED 0
#define CYDEV_CONFIGURATION_MODE CYDEV_CONFIGURATION_MODE_COMPRESSED
#define CYDEV_CONFIGURATION_MODE_DMA 2
#define CYDEV_CONFIGURATION_MODE_UNCOMPRESSED 1
#define CYDEV_DEBUG_PROTECT_KILL 4
#define CYDEV_DEBUG_PROTECT_OPEN 1
#define CYDEV_DEBUG_PROTECT CYDEV_DEBUG_PROTECT_OPEN
#define CYDEV_DEBUG_PROTECT_PROTECTED 2
#define CYDEV_DEBUGGING_DPS_Disable 3
#define CYDEV_DEBUGGING_DPS_SWD 2
#define CYDEV_DEBUGGING_DPS CYDEV_DEBUGGING_DPS_SWD
#define CYDEV_DEBUGGING_ENABLE 1
#define CYDEV_HEAP_SIZE 0x0100
#define CYDEV_PROJ_TYPE 0
#define CYDEV_PROJ_TYPE_BOOTLOADER 1
#define CYDEV_PROJ_TYPE_LOADABLE 2
#define CYDEV_PROJ_TYPE_MULTIAPPBOOTLOADER 3
#define CYDEV_PROJ_TYPE_STANDARD 0
#define CYDEV_STACK_SIZE 0x0400
#define CYDEV_USE_BUNDLED_CMSIS 1
#define CYDEV_VARIABLE_VDDA 1
#define CYDEV_VDDA 3.3
#define CYDEV_VDDA_MV 3300
#define CYDEV_VDDD 3.3
#define CYDEV_VDDD_MV 3300
#define CYIPBLOCK_M0S8_CTBM_VERSION 0
#define CYIPBLOCK_m0s8cpuss_VERSION 0
#define CYIPBLOCK_m0s8csd_VERSION 0
#define CYIPBLOCK_m0s8gpio2_VERSION 0
#define CYIPBLOCK_m0s8hsiom4a_VERSION 0
#define CYIPBLOCK_m0s8lcd_VERSION 0
#define CYIPBLOCK_m0s8lpcomp_VERSION 0
#define CYIPBLOCK_m0s8pclk_VERSION 0
#define CYIPBLOCK_m0s8sar_VERSION 0
#define CYIPBLOCK_m0s8scb_VERSION 0
#define CYIPBLOCK_m0s8srssv2_VERSION 1
#define CYIPBLOCK_m0s8tcpwm_VERSION 0
#define CYIPBLOCK_m0s8udbif_VERSION 0
#define CYIPBLOCK_S8_GPIO_VERSION 2
#define CYDEV_BOOTLOADER_ENABLE 0

#endif /* INCLUDED_CYFITTER_H */
