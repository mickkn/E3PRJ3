#ifndef INCLUDED_CYFITTER_H
#define INCLUDED_CYFITTER_H
#include <cydevice_trm.h>

/* SPIS_1_miso_s */
#define SPIS_1_miso_s__0__DM__MASK 0x38u
#define SPIS_1_miso_s__0__DM__SHIFT 3
#define SPIS_1_miso_s__0__DR CYREG_PRT3_DR
#define SPIS_1_miso_s__0__HSIOM CYREG_HSIOM_PORT_SEL3
#define SPIS_1_miso_s__0__HSIOM_MASK 0x000000F0u
#define SPIS_1_miso_s__0__HSIOM_SHIFT 4u
#define SPIS_1_miso_s__0__INTCFG CYREG_PRT3_INTCFG
#define SPIS_1_miso_s__0__INTSTAT CYREG_PRT3_INTSTAT
#define SPIS_1_miso_s__0__MASK 0x02u
#define SPIS_1_miso_s__0__OUT_SEL CYREG_UDB_PA3_CFG10
#define SPIS_1_miso_s__0__OUT_SEL_SHIFT 2u
#define SPIS_1_miso_s__0__OUT_SEL_VAL -1u
#define SPIS_1_miso_s__0__PA__CFG0 CYREG_UDB_PA3_CFG0
#define SPIS_1_miso_s__0__PA__CFG1 CYREG_UDB_PA3_CFG1
#define SPIS_1_miso_s__0__PA__CFG10 CYREG_UDB_PA3_CFG10
#define SPIS_1_miso_s__0__PA__CFG11 CYREG_UDB_PA3_CFG11
#define SPIS_1_miso_s__0__PA__CFG12 CYREG_UDB_PA3_CFG12
#define SPIS_1_miso_s__0__PA__CFG13 CYREG_UDB_PA3_CFG13
#define SPIS_1_miso_s__0__PA__CFG14 CYREG_UDB_PA3_CFG14
#define SPIS_1_miso_s__0__PA__CFG2 CYREG_UDB_PA3_CFG2
#define SPIS_1_miso_s__0__PA__CFG3 CYREG_UDB_PA3_CFG3
#define SPIS_1_miso_s__0__PA__CFG4 CYREG_UDB_PA3_CFG4
#define SPIS_1_miso_s__0__PA__CFG5 CYREG_UDB_PA3_CFG5
#define SPIS_1_miso_s__0__PA__CFG6 CYREG_UDB_PA3_CFG6
#define SPIS_1_miso_s__0__PA__CFG7 CYREG_UDB_PA3_CFG7
#define SPIS_1_miso_s__0__PA__CFG8 CYREG_UDB_PA3_CFG8
#define SPIS_1_miso_s__0__PA__CFG9 CYREG_UDB_PA3_CFG9
#define SPIS_1_miso_s__0__PC CYREG_PRT3_PC
#define SPIS_1_miso_s__0__PC2 CYREG_PRT3_PC2
#define SPIS_1_miso_s__0__PORT 3u
#define SPIS_1_miso_s__0__PS CYREG_PRT3_PS
#define SPIS_1_miso_s__0__SHIFT 1
#define SPIS_1_miso_s__DR CYREG_PRT3_DR
#define SPIS_1_miso_s__INTCFG CYREG_PRT3_INTCFG
#define SPIS_1_miso_s__INTSTAT CYREG_PRT3_INTSTAT
#define SPIS_1_miso_s__MASK 0x02u
#define SPIS_1_miso_s__PA__CFG0 CYREG_UDB_PA3_CFG0
#define SPIS_1_miso_s__PA__CFG1 CYREG_UDB_PA3_CFG1
#define SPIS_1_miso_s__PA__CFG10 CYREG_UDB_PA3_CFG10
#define SPIS_1_miso_s__PA__CFG11 CYREG_UDB_PA3_CFG11
#define SPIS_1_miso_s__PA__CFG12 CYREG_UDB_PA3_CFG12
#define SPIS_1_miso_s__PA__CFG13 CYREG_UDB_PA3_CFG13
#define SPIS_1_miso_s__PA__CFG14 CYREG_UDB_PA3_CFG14
#define SPIS_1_miso_s__PA__CFG2 CYREG_UDB_PA3_CFG2
#define SPIS_1_miso_s__PA__CFG3 CYREG_UDB_PA3_CFG3
#define SPIS_1_miso_s__PA__CFG4 CYREG_UDB_PA3_CFG4
#define SPIS_1_miso_s__PA__CFG5 CYREG_UDB_PA3_CFG5
#define SPIS_1_miso_s__PA__CFG6 CYREG_UDB_PA3_CFG6
#define SPIS_1_miso_s__PA__CFG7 CYREG_UDB_PA3_CFG7
#define SPIS_1_miso_s__PA__CFG8 CYREG_UDB_PA3_CFG8
#define SPIS_1_miso_s__PA__CFG9 CYREG_UDB_PA3_CFG9
#define SPIS_1_miso_s__PC CYREG_PRT3_PC
#define SPIS_1_miso_s__PC2 CYREG_PRT3_PC2
#define SPIS_1_miso_s__PORT 3u
#define SPIS_1_miso_s__PS CYREG_PRT3_PS
#define SPIS_1_miso_s__SHIFT 1

/* SPIS_1_mosi_s */
#define SPIS_1_mosi_s__0__DM__MASK 0x07u
#define SPIS_1_mosi_s__0__DM__SHIFT 0
#define SPIS_1_mosi_s__0__DR CYREG_PRT3_DR
#define SPIS_1_mosi_s__0__HSIOM CYREG_HSIOM_PORT_SEL3
#define SPIS_1_mosi_s__0__HSIOM_MASK 0x0000000Fu
#define SPIS_1_mosi_s__0__HSIOM_SHIFT 0u
#define SPIS_1_mosi_s__0__INTCFG CYREG_PRT3_INTCFG
#define SPIS_1_mosi_s__0__INTSTAT CYREG_PRT3_INTSTAT
#define SPIS_1_mosi_s__0__MASK 0x01u
#define SPIS_1_mosi_s__0__PA__CFG0 CYREG_UDB_PA3_CFG0
#define SPIS_1_mosi_s__0__PA__CFG1 CYREG_UDB_PA3_CFG1
#define SPIS_1_mosi_s__0__PA__CFG10 CYREG_UDB_PA3_CFG10
#define SPIS_1_mosi_s__0__PA__CFG11 CYREG_UDB_PA3_CFG11
#define SPIS_1_mosi_s__0__PA__CFG12 CYREG_UDB_PA3_CFG12
#define SPIS_1_mosi_s__0__PA__CFG13 CYREG_UDB_PA3_CFG13
#define SPIS_1_mosi_s__0__PA__CFG14 CYREG_UDB_PA3_CFG14
#define SPIS_1_mosi_s__0__PA__CFG2 CYREG_UDB_PA3_CFG2
#define SPIS_1_mosi_s__0__PA__CFG3 CYREG_UDB_PA3_CFG3
#define SPIS_1_mosi_s__0__PA__CFG4 CYREG_UDB_PA3_CFG4
#define SPIS_1_mosi_s__0__PA__CFG5 CYREG_UDB_PA3_CFG5
#define SPIS_1_mosi_s__0__PA__CFG6 CYREG_UDB_PA3_CFG6
#define SPIS_1_mosi_s__0__PA__CFG7 CYREG_UDB_PA3_CFG7
#define SPIS_1_mosi_s__0__PA__CFG8 CYREG_UDB_PA3_CFG8
#define SPIS_1_mosi_s__0__PA__CFG9 CYREG_UDB_PA3_CFG9
#define SPIS_1_mosi_s__0__PC CYREG_PRT3_PC
#define SPIS_1_mosi_s__0__PC2 CYREG_PRT3_PC2
#define SPIS_1_mosi_s__0__PORT 3u
#define SPIS_1_mosi_s__0__PS CYREG_PRT3_PS
#define SPIS_1_mosi_s__0__SHIFT 0
#define SPIS_1_mosi_s__DR CYREG_PRT3_DR
#define SPIS_1_mosi_s__INTCFG CYREG_PRT3_INTCFG
#define SPIS_1_mosi_s__INTSTAT CYREG_PRT3_INTSTAT
#define SPIS_1_mosi_s__MASK 0x01u
#define SPIS_1_mosi_s__PA__CFG0 CYREG_UDB_PA3_CFG0
#define SPIS_1_mosi_s__PA__CFG1 CYREG_UDB_PA3_CFG1
#define SPIS_1_mosi_s__PA__CFG10 CYREG_UDB_PA3_CFG10
#define SPIS_1_mosi_s__PA__CFG11 CYREG_UDB_PA3_CFG11
#define SPIS_1_mosi_s__PA__CFG12 CYREG_UDB_PA3_CFG12
#define SPIS_1_mosi_s__PA__CFG13 CYREG_UDB_PA3_CFG13
#define SPIS_1_mosi_s__PA__CFG14 CYREG_UDB_PA3_CFG14
#define SPIS_1_mosi_s__PA__CFG2 CYREG_UDB_PA3_CFG2
#define SPIS_1_mosi_s__PA__CFG3 CYREG_UDB_PA3_CFG3
#define SPIS_1_mosi_s__PA__CFG4 CYREG_UDB_PA3_CFG4
#define SPIS_1_mosi_s__PA__CFG5 CYREG_UDB_PA3_CFG5
#define SPIS_1_mosi_s__PA__CFG6 CYREG_UDB_PA3_CFG6
#define SPIS_1_mosi_s__PA__CFG7 CYREG_UDB_PA3_CFG7
#define SPIS_1_mosi_s__PA__CFG8 CYREG_UDB_PA3_CFG8
#define SPIS_1_mosi_s__PA__CFG9 CYREG_UDB_PA3_CFG9
#define SPIS_1_mosi_s__PC CYREG_PRT3_PC
#define SPIS_1_mosi_s__PC2 CYREG_PRT3_PC2
#define SPIS_1_mosi_s__PORT 3u
#define SPIS_1_mosi_s__PS CYREG_PRT3_PS
#define SPIS_1_mosi_s__SHIFT 0

/* SPIS_1_SCB */
#define SPIS_1_SCB__BIST_CONTROL CYREG_SCB1_BIST_CONTROL
#define SPIS_1_SCB__BIST_DATA CYREG_SCB1_BIST_DATA
#define SPIS_1_SCB__CTRL CYREG_SCB1_CTRL
#define SPIS_1_SCB__EZ_DATA00 CYREG_SCB1_EZ_DATA00
#define SPIS_1_SCB__EZ_DATA01 CYREG_SCB1_EZ_DATA01
#define SPIS_1_SCB__EZ_DATA02 CYREG_SCB1_EZ_DATA02
#define SPIS_1_SCB__EZ_DATA03 CYREG_SCB1_EZ_DATA03
#define SPIS_1_SCB__EZ_DATA04 CYREG_SCB1_EZ_DATA04
#define SPIS_1_SCB__EZ_DATA05 CYREG_SCB1_EZ_DATA05
#define SPIS_1_SCB__EZ_DATA06 CYREG_SCB1_EZ_DATA06
#define SPIS_1_SCB__EZ_DATA07 CYREG_SCB1_EZ_DATA07
#define SPIS_1_SCB__EZ_DATA08 CYREG_SCB1_EZ_DATA08
#define SPIS_1_SCB__EZ_DATA09 CYREG_SCB1_EZ_DATA09
#define SPIS_1_SCB__EZ_DATA10 CYREG_SCB1_EZ_DATA10
#define SPIS_1_SCB__EZ_DATA11 CYREG_SCB1_EZ_DATA11
#define SPIS_1_SCB__EZ_DATA12 CYREG_SCB1_EZ_DATA12
#define SPIS_1_SCB__EZ_DATA13 CYREG_SCB1_EZ_DATA13
#define SPIS_1_SCB__EZ_DATA14 CYREG_SCB1_EZ_DATA14
#define SPIS_1_SCB__EZ_DATA15 CYREG_SCB1_EZ_DATA15
#define SPIS_1_SCB__EZ_DATA16 CYREG_SCB1_EZ_DATA16
#define SPIS_1_SCB__EZ_DATA17 CYREG_SCB1_EZ_DATA17
#define SPIS_1_SCB__EZ_DATA18 CYREG_SCB1_EZ_DATA18
#define SPIS_1_SCB__EZ_DATA19 CYREG_SCB1_EZ_DATA19
#define SPIS_1_SCB__EZ_DATA20 CYREG_SCB1_EZ_DATA20
#define SPIS_1_SCB__EZ_DATA21 CYREG_SCB1_EZ_DATA21
#define SPIS_1_SCB__EZ_DATA22 CYREG_SCB1_EZ_DATA22
#define SPIS_1_SCB__EZ_DATA23 CYREG_SCB1_EZ_DATA23
#define SPIS_1_SCB__EZ_DATA24 CYREG_SCB1_EZ_DATA24
#define SPIS_1_SCB__EZ_DATA25 CYREG_SCB1_EZ_DATA25
#define SPIS_1_SCB__EZ_DATA26 CYREG_SCB1_EZ_DATA26
#define SPIS_1_SCB__EZ_DATA27 CYREG_SCB1_EZ_DATA27
#define SPIS_1_SCB__EZ_DATA28 CYREG_SCB1_EZ_DATA28
#define SPIS_1_SCB__EZ_DATA29 CYREG_SCB1_EZ_DATA29
#define SPIS_1_SCB__EZ_DATA30 CYREG_SCB1_EZ_DATA30
#define SPIS_1_SCB__EZ_DATA31 CYREG_SCB1_EZ_DATA31
#define SPIS_1_SCB__I2C_CFG CYREG_SCB1_I2C_CFG
#define SPIS_1_SCB__I2C_CTRL CYREG_SCB1_I2C_CTRL
#define SPIS_1_SCB__I2C_M_CMD CYREG_SCB1_I2C_M_CMD
#define SPIS_1_SCB__I2C_S_CMD CYREG_SCB1_I2C_S_CMD
#define SPIS_1_SCB__I2C_STATUS CYREG_SCB1_I2C_STATUS
#define SPIS_1_SCB__INTR_CAUSE CYREG_SCB1_INTR_CAUSE
#define SPIS_1_SCB__INTR_I2C_EC CYREG_SCB1_INTR_I2C_EC
#define SPIS_1_SCB__INTR_I2C_EC_MASK CYREG_SCB1_INTR_I2C_EC_MASK
#define SPIS_1_SCB__INTR_I2C_EC_MASKED CYREG_SCB1_INTR_I2C_EC_MASKED
#define SPIS_1_SCB__INTR_M CYREG_SCB1_INTR_M
#define SPIS_1_SCB__INTR_M_MASK CYREG_SCB1_INTR_M_MASK
#define SPIS_1_SCB__INTR_M_MASKED CYREG_SCB1_INTR_M_MASKED
#define SPIS_1_SCB__INTR_M_SET CYREG_SCB1_INTR_M_SET
#define SPIS_1_SCB__INTR_RX CYREG_SCB1_INTR_RX
#define SPIS_1_SCB__INTR_RX_MASK CYREG_SCB1_INTR_RX_MASK
#define SPIS_1_SCB__INTR_RX_MASKED CYREG_SCB1_INTR_RX_MASKED
#define SPIS_1_SCB__INTR_RX_SET CYREG_SCB1_INTR_RX_SET
#define SPIS_1_SCB__INTR_S CYREG_SCB1_INTR_S
#define SPIS_1_SCB__INTR_S_MASK CYREG_SCB1_INTR_S_MASK
#define SPIS_1_SCB__INTR_S_MASKED CYREG_SCB1_INTR_S_MASKED
#define SPIS_1_SCB__INTR_S_SET CYREG_SCB1_INTR_S_SET
#define SPIS_1_SCB__INTR_SPI_EC CYREG_SCB1_INTR_SPI_EC
#define SPIS_1_SCB__INTR_SPI_EC_MASK CYREG_SCB1_INTR_SPI_EC_MASK
#define SPIS_1_SCB__INTR_SPI_EC_MASKED CYREG_SCB1_INTR_SPI_EC_MASKED
#define SPIS_1_SCB__INTR_TX CYREG_SCB1_INTR_TX
#define SPIS_1_SCB__INTR_TX_MASK CYREG_SCB1_INTR_TX_MASK
#define SPIS_1_SCB__INTR_TX_MASKED CYREG_SCB1_INTR_TX_MASKED
#define SPIS_1_SCB__INTR_TX_SET CYREG_SCB1_INTR_TX_SET
#define SPIS_1_SCB__RX_CTRL CYREG_SCB1_RX_CTRL
#define SPIS_1_SCB__RX_FIFO_CTRL CYREG_SCB1_RX_FIFO_CTRL
#define SPIS_1_SCB__RX_FIFO_RD CYREG_SCB1_RX_FIFO_RD
#define SPIS_1_SCB__RX_FIFO_RD_SILENT CYREG_SCB1_RX_FIFO_RD_SILENT
#define SPIS_1_SCB__RX_FIFO_STATUS CYREG_SCB1_RX_FIFO_STATUS
#define SPIS_1_SCB__RX_MATCH CYREG_SCB1_RX_MATCH
#define SPIS_1_SCB__SPI_CTRL CYREG_SCB1_SPI_CTRL
#define SPIS_1_SCB__SPI_STATUS CYREG_SCB1_SPI_STATUS
#define SPIS_1_SCB__STATUS CYREG_SCB1_STATUS
#define SPIS_1_SCB__TX_CTRL CYREG_SCB1_TX_CTRL
#define SPIS_1_SCB__TX_FIFO_CTRL CYREG_SCB1_TX_FIFO_CTRL
#define SPIS_1_SCB__TX_FIFO_STATUS CYREG_SCB1_TX_FIFO_STATUS
#define SPIS_1_SCB__TX_FIFO_WR CYREG_SCB1_TX_FIFO_WR
#define SPIS_1_SCB__UART_CTRL CYREG_SCB1_UART_CTRL
#define SPIS_1_SCB__UART_RX_CTRL CYREG_SCB1_UART_RX_CTRL
#define SPIS_1_SCB__UART_RX_STATUS CYREG_SCB1_UART_RX_STATUS
#define SPIS_1_SCB__UART_TX_CTRL CYREG_SCB1_UART_TX_CTRL

/* SPIS_1_SCB_IRQ */
#define SPIS_1_SCB_IRQ__INTC_CLR_EN_REG CYREG_CM0_ICER
#define SPIS_1_SCB_IRQ__INTC_CLR_PD_REG CYREG_CM0_ICPR
#define SPIS_1_SCB_IRQ__INTC_MASK 0x800u
#define SPIS_1_SCB_IRQ__INTC_NUMBER 11u
#define SPIS_1_SCB_IRQ__INTC_PRIOR_MASK 0xC0000000u
#define SPIS_1_SCB_IRQ__INTC_PRIOR_NUM 3u
#define SPIS_1_SCB_IRQ__INTC_PRIOR_REG CYREG_CM0_IPR2
#define SPIS_1_SCB_IRQ__INTC_SET_EN_REG CYREG_CM0_ISER
#define SPIS_1_SCB_IRQ__INTC_SET_PD_REG CYREG_CM0_ISPR

/* SPIS_1_SCBCLK */
#define SPIS_1_SCBCLK__DIVIDER_MASK 0x0000FFFFu
#define SPIS_1_SCBCLK__ENABLE CYREG_CLK_DIVIDER_A00
#define SPIS_1_SCBCLK__ENABLE_MASK 0x80000000u
#define SPIS_1_SCBCLK__MASK 0x80000000u
#define SPIS_1_SCBCLK__REGISTER CYREG_CLK_DIVIDER_A00

/* SPIS_1_sclk_s */
#define SPIS_1_sclk_s__0__DM__MASK 0x1C0000u
#define SPIS_1_sclk_s__0__DM__SHIFT 18
#define SPIS_1_sclk_s__0__DR CYREG_PRT0_DR
#define SPIS_1_sclk_s__0__HSIOM CYREG_HSIOM_PORT_SEL0
#define SPIS_1_sclk_s__0__HSIOM_MASK 0x0F000000u
#define SPIS_1_sclk_s__0__HSIOM_SHIFT 24u
#define SPIS_1_sclk_s__0__INTCFG CYREG_PRT0_INTCFG
#define SPIS_1_sclk_s__0__INTSTAT CYREG_PRT0_INTSTAT
#define SPIS_1_sclk_s__0__MASK 0x40u
#define SPIS_1_sclk_s__0__PA__CFG0 CYREG_UDB_PA0_CFG0
#define SPIS_1_sclk_s__0__PA__CFG1 CYREG_UDB_PA0_CFG1
#define SPIS_1_sclk_s__0__PA__CFG10 CYREG_UDB_PA0_CFG10
#define SPIS_1_sclk_s__0__PA__CFG11 CYREG_UDB_PA0_CFG11
#define SPIS_1_sclk_s__0__PA__CFG12 CYREG_UDB_PA0_CFG12
#define SPIS_1_sclk_s__0__PA__CFG13 CYREG_UDB_PA0_CFG13
#define SPIS_1_sclk_s__0__PA__CFG14 CYREG_UDB_PA0_CFG14
#define SPIS_1_sclk_s__0__PA__CFG2 CYREG_UDB_PA0_CFG2
#define SPIS_1_sclk_s__0__PA__CFG3 CYREG_UDB_PA0_CFG3
#define SPIS_1_sclk_s__0__PA__CFG4 CYREG_UDB_PA0_CFG4
#define SPIS_1_sclk_s__0__PA__CFG5 CYREG_UDB_PA0_CFG5
#define SPIS_1_sclk_s__0__PA__CFG6 CYREG_UDB_PA0_CFG6
#define SPIS_1_sclk_s__0__PA__CFG7 CYREG_UDB_PA0_CFG7
#define SPIS_1_sclk_s__0__PA__CFG8 CYREG_UDB_PA0_CFG8
#define SPIS_1_sclk_s__0__PA__CFG9 CYREG_UDB_PA0_CFG9
#define SPIS_1_sclk_s__0__PC CYREG_PRT0_PC
#define SPIS_1_sclk_s__0__PC2 CYREG_PRT0_PC2
#define SPIS_1_sclk_s__0__PORT 0u
#define SPIS_1_sclk_s__0__PS CYREG_PRT0_PS
#define SPIS_1_sclk_s__0__SHIFT 6
#define SPIS_1_sclk_s__DR CYREG_PRT0_DR
#define SPIS_1_sclk_s__INTCFG CYREG_PRT0_INTCFG
#define SPIS_1_sclk_s__INTSTAT CYREG_PRT0_INTSTAT
#define SPIS_1_sclk_s__MASK 0x40u
#define SPIS_1_sclk_s__PA__CFG0 CYREG_UDB_PA0_CFG0
#define SPIS_1_sclk_s__PA__CFG1 CYREG_UDB_PA0_CFG1
#define SPIS_1_sclk_s__PA__CFG10 CYREG_UDB_PA0_CFG10
#define SPIS_1_sclk_s__PA__CFG11 CYREG_UDB_PA0_CFG11
#define SPIS_1_sclk_s__PA__CFG12 CYREG_UDB_PA0_CFG12
#define SPIS_1_sclk_s__PA__CFG13 CYREG_UDB_PA0_CFG13
#define SPIS_1_sclk_s__PA__CFG14 CYREG_UDB_PA0_CFG14
#define SPIS_1_sclk_s__PA__CFG2 CYREG_UDB_PA0_CFG2
#define SPIS_1_sclk_s__PA__CFG3 CYREG_UDB_PA0_CFG3
#define SPIS_1_sclk_s__PA__CFG4 CYREG_UDB_PA0_CFG4
#define SPIS_1_sclk_s__PA__CFG5 CYREG_UDB_PA0_CFG5
#define SPIS_1_sclk_s__PA__CFG6 CYREG_UDB_PA0_CFG6
#define SPIS_1_sclk_s__PA__CFG7 CYREG_UDB_PA0_CFG7
#define SPIS_1_sclk_s__PA__CFG8 CYREG_UDB_PA0_CFG8
#define SPIS_1_sclk_s__PA__CFG9 CYREG_UDB_PA0_CFG9
#define SPIS_1_sclk_s__PC CYREG_PRT0_PC
#define SPIS_1_sclk_s__PC2 CYREG_PRT0_PC2
#define SPIS_1_sclk_s__PORT 0u
#define SPIS_1_sclk_s__PS CYREG_PRT0_PS
#define SPIS_1_sclk_s__SHIFT 6

/* SPIS_1_ss_s */
#define SPIS_1_ss_s__0__DM__MASK 0xE00000u
#define SPIS_1_ss_s__0__DM__SHIFT 21
#define SPIS_1_ss_s__0__DR CYREG_PRT0_DR
#define SPIS_1_ss_s__0__HSIOM CYREG_HSIOM_PORT_SEL0
#define SPIS_1_ss_s__0__HSIOM_MASK 0xF0000000u
#define SPIS_1_ss_s__0__HSIOM_SHIFT 28u
#define SPIS_1_ss_s__0__INTCFG CYREG_PRT0_INTCFG
#define SPIS_1_ss_s__0__INTSTAT CYREG_PRT0_INTSTAT
#define SPIS_1_ss_s__0__MASK 0x80u
#define SPIS_1_ss_s__0__PA__CFG0 CYREG_UDB_PA0_CFG0
#define SPIS_1_ss_s__0__PA__CFG1 CYREG_UDB_PA0_CFG1
#define SPIS_1_ss_s__0__PA__CFG10 CYREG_UDB_PA0_CFG10
#define SPIS_1_ss_s__0__PA__CFG11 CYREG_UDB_PA0_CFG11
#define SPIS_1_ss_s__0__PA__CFG12 CYREG_UDB_PA0_CFG12
#define SPIS_1_ss_s__0__PA__CFG13 CYREG_UDB_PA0_CFG13
#define SPIS_1_ss_s__0__PA__CFG14 CYREG_UDB_PA0_CFG14
#define SPIS_1_ss_s__0__PA__CFG2 CYREG_UDB_PA0_CFG2
#define SPIS_1_ss_s__0__PA__CFG3 CYREG_UDB_PA0_CFG3
#define SPIS_1_ss_s__0__PA__CFG4 CYREG_UDB_PA0_CFG4
#define SPIS_1_ss_s__0__PA__CFG5 CYREG_UDB_PA0_CFG5
#define SPIS_1_ss_s__0__PA__CFG6 CYREG_UDB_PA0_CFG6
#define SPIS_1_ss_s__0__PA__CFG7 CYREG_UDB_PA0_CFG7
#define SPIS_1_ss_s__0__PA__CFG8 CYREG_UDB_PA0_CFG8
#define SPIS_1_ss_s__0__PA__CFG9 CYREG_UDB_PA0_CFG9
#define SPIS_1_ss_s__0__PC CYREG_PRT0_PC
#define SPIS_1_ss_s__0__PC2 CYREG_PRT0_PC2
#define SPIS_1_ss_s__0__PORT 0u
#define SPIS_1_ss_s__0__PS CYREG_PRT0_PS
#define SPIS_1_ss_s__0__SHIFT 7
#define SPIS_1_ss_s__DR CYREG_PRT0_DR
#define SPIS_1_ss_s__INTCFG CYREG_PRT0_INTCFG
#define SPIS_1_ss_s__INTSTAT CYREG_PRT0_INTSTAT
#define SPIS_1_ss_s__MASK 0x80u
#define SPIS_1_ss_s__PA__CFG0 CYREG_UDB_PA0_CFG0
#define SPIS_1_ss_s__PA__CFG1 CYREG_UDB_PA0_CFG1
#define SPIS_1_ss_s__PA__CFG10 CYREG_UDB_PA0_CFG10
#define SPIS_1_ss_s__PA__CFG11 CYREG_UDB_PA0_CFG11
#define SPIS_1_ss_s__PA__CFG12 CYREG_UDB_PA0_CFG12
#define SPIS_1_ss_s__PA__CFG13 CYREG_UDB_PA0_CFG13
#define SPIS_1_ss_s__PA__CFG14 CYREG_UDB_PA0_CFG14
#define SPIS_1_ss_s__PA__CFG2 CYREG_UDB_PA0_CFG2
#define SPIS_1_ss_s__PA__CFG3 CYREG_UDB_PA0_CFG3
#define SPIS_1_ss_s__PA__CFG4 CYREG_UDB_PA0_CFG4
#define SPIS_1_ss_s__PA__CFG5 CYREG_UDB_PA0_CFG5
#define SPIS_1_ss_s__PA__CFG6 CYREG_UDB_PA0_CFG6
#define SPIS_1_ss_s__PA__CFG7 CYREG_UDB_PA0_CFG7
#define SPIS_1_ss_s__PA__CFG8 CYREG_UDB_PA0_CFG8
#define SPIS_1_ss_s__PA__CFG9 CYREG_UDB_PA0_CFG9
#define SPIS_1_ss_s__PC CYREG_PRT0_PC
#define SPIS_1_ss_s__PC2 CYREG_PRT0_PC2
#define SPIS_1_ss_s__PORT 0u
#define SPIS_1_ss_s__PS CYREG_PRT0_PS
#define SPIS_1_ss_s__SHIFT 7

/* RED_LED */
#define RED_LED__0__DM__MASK 0x1C0000u
#define RED_LED__0__DM__SHIFT 18
#define RED_LED__0__DR CYREG_PRT1_DR
#define RED_LED__0__HSIOM CYREG_HSIOM_PORT_SEL1
#define RED_LED__0__HSIOM_MASK 0x0F000000u
#define RED_LED__0__HSIOM_SHIFT 24u
#define RED_LED__0__INTCFG CYREG_PRT1_INTCFG
#define RED_LED__0__INTSTAT CYREG_PRT1_INTSTAT
#define RED_LED__0__MASK 0x40u
#define RED_LED__0__PA__CFG0 CYREG_UDB_PA1_CFG0
#define RED_LED__0__PA__CFG1 CYREG_UDB_PA1_CFG1
#define RED_LED__0__PA__CFG10 CYREG_UDB_PA1_CFG10
#define RED_LED__0__PA__CFG11 CYREG_UDB_PA1_CFG11
#define RED_LED__0__PA__CFG12 CYREG_UDB_PA1_CFG12
#define RED_LED__0__PA__CFG13 CYREG_UDB_PA1_CFG13
#define RED_LED__0__PA__CFG14 CYREG_UDB_PA1_CFG14
#define RED_LED__0__PA__CFG2 CYREG_UDB_PA1_CFG2
#define RED_LED__0__PA__CFG3 CYREG_UDB_PA1_CFG3
#define RED_LED__0__PA__CFG4 CYREG_UDB_PA1_CFG4
#define RED_LED__0__PA__CFG5 CYREG_UDB_PA1_CFG5
#define RED_LED__0__PA__CFG6 CYREG_UDB_PA1_CFG6
#define RED_LED__0__PA__CFG7 CYREG_UDB_PA1_CFG7
#define RED_LED__0__PA__CFG8 CYREG_UDB_PA1_CFG8
#define RED_LED__0__PA__CFG9 CYREG_UDB_PA1_CFG9
#define RED_LED__0__PC CYREG_PRT1_PC
#define RED_LED__0__PC2 CYREG_PRT1_PC2
#define RED_LED__0__PORT 1u
#define RED_LED__0__PS CYREG_PRT1_PS
#define RED_LED__0__SHIFT 6
#define RED_LED__DR CYREG_PRT1_DR
#define RED_LED__INTCFG CYREG_PRT1_INTCFG
#define RED_LED__INTSTAT CYREG_PRT1_INTSTAT
#define RED_LED__MASK 0x40u
#define RED_LED__PA__CFG0 CYREG_UDB_PA1_CFG0
#define RED_LED__PA__CFG1 CYREG_UDB_PA1_CFG1
#define RED_LED__PA__CFG10 CYREG_UDB_PA1_CFG10
#define RED_LED__PA__CFG11 CYREG_UDB_PA1_CFG11
#define RED_LED__PA__CFG12 CYREG_UDB_PA1_CFG12
#define RED_LED__PA__CFG13 CYREG_UDB_PA1_CFG13
#define RED_LED__PA__CFG14 CYREG_UDB_PA1_CFG14
#define RED_LED__PA__CFG2 CYREG_UDB_PA1_CFG2
#define RED_LED__PA__CFG3 CYREG_UDB_PA1_CFG3
#define RED_LED__PA__CFG4 CYREG_UDB_PA1_CFG4
#define RED_LED__PA__CFG5 CYREG_UDB_PA1_CFG5
#define RED_LED__PA__CFG6 CYREG_UDB_PA1_CFG6
#define RED_LED__PA__CFG7 CYREG_UDB_PA1_CFG7
#define RED_LED__PA__CFG8 CYREG_UDB_PA1_CFG8
#define RED_LED__PA__CFG9 CYREG_UDB_PA1_CFG9
#define RED_LED__PC CYREG_PRT1_PC
#define RED_LED__PC2 CYREG_PRT1_PC2
#define RED_LED__PORT 1u
#define RED_LED__PS CYREG_PRT1_PS
#define RED_LED__SHIFT 6

/* GREEN_LED */
#define GREEN_LED__0__DM__MASK 0x1C0u
#define GREEN_LED__0__DM__SHIFT 6
#define GREEN_LED__0__DR CYREG_PRT0_DR
#define GREEN_LED__0__HSIOM CYREG_HSIOM_PORT_SEL0
#define GREEN_LED__0__HSIOM_MASK 0x00000F00u
#define GREEN_LED__0__HSIOM_SHIFT 8u
#define GREEN_LED__0__INTCFG CYREG_PRT0_INTCFG
#define GREEN_LED__0__INTSTAT CYREG_PRT0_INTSTAT
#define GREEN_LED__0__MASK 0x04u
#define GREEN_LED__0__PA__CFG0 CYREG_UDB_PA0_CFG0
#define GREEN_LED__0__PA__CFG1 CYREG_UDB_PA0_CFG1
#define GREEN_LED__0__PA__CFG10 CYREG_UDB_PA0_CFG10
#define GREEN_LED__0__PA__CFG11 CYREG_UDB_PA0_CFG11
#define GREEN_LED__0__PA__CFG12 CYREG_UDB_PA0_CFG12
#define GREEN_LED__0__PA__CFG13 CYREG_UDB_PA0_CFG13
#define GREEN_LED__0__PA__CFG14 CYREG_UDB_PA0_CFG14
#define GREEN_LED__0__PA__CFG2 CYREG_UDB_PA0_CFG2
#define GREEN_LED__0__PA__CFG3 CYREG_UDB_PA0_CFG3
#define GREEN_LED__0__PA__CFG4 CYREG_UDB_PA0_CFG4
#define GREEN_LED__0__PA__CFG5 CYREG_UDB_PA0_CFG5
#define GREEN_LED__0__PA__CFG6 CYREG_UDB_PA0_CFG6
#define GREEN_LED__0__PA__CFG7 CYREG_UDB_PA0_CFG7
#define GREEN_LED__0__PA__CFG8 CYREG_UDB_PA0_CFG8
#define GREEN_LED__0__PA__CFG9 CYREG_UDB_PA0_CFG9
#define GREEN_LED__0__PC CYREG_PRT0_PC
#define GREEN_LED__0__PC2 CYREG_PRT0_PC2
#define GREEN_LED__0__PORT 0u
#define GREEN_LED__0__PS CYREG_PRT0_PS
#define GREEN_LED__0__SHIFT 2
#define GREEN_LED__DR CYREG_PRT0_DR
#define GREEN_LED__INTCFG CYREG_PRT0_INTCFG
#define GREEN_LED__INTSTAT CYREG_PRT0_INTSTAT
#define GREEN_LED__MASK 0x04u
#define GREEN_LED__PA__CFG0 CYREG_UDB_PA0_CFG0
#define GREEN_LED__PA__CFG1 CYREG_UDB_PA0_CFG1
#define GREEN_LED__PA__CFG10 CYREG_UDB_PA0_CFG10
#define GREEN_LED__PA__CFG11 CYREG_UDB_PA0_CFG11
#define GREEN_LED__PA__CFG12 CYREG_UDB_PA0_CFG12
#define GREEN_LED__PA__CFG13 CYREG_UDB_PA0_CFG13
#define GREEN_LED__PA__CFG14 CYREG_UDB_PA0_CFG14
#define GREEN_LED__PA__CFG2 CYREG_UDB_PA0_CFG2
#define GREEN_LED__PA__CFG3 CYREG_UDB_PA0_CFG3
#define GREEN_LED__PA__CFG4 CYREG_UDB_PA0_CFG4
#define GREEN_LED__PA__CFG5 CYREG_UDB_PA0_CFG5
#define GREEN_LED__PA__CFG6 CYREG_UDB_PA0_CFG6
#define GREEN_LED__PA__CFG7 CYREG_UDB_PA0_CFG7
#define GREEN_LED__PA__CFG8 CYREG_UDB_PA0_CFG8
#define GREEN_LED__PA__CFG9 CYREG_UDB_PA0_CFG9
#define GREEN_LED__PC CYREG_PRT0_PC
#define GREEN_LED__PC2 CYREG_PRT0_PC2
#define GREEN_LED__PORT 0u
#define GREEN_LED__PS CYREG_PRT0_PS
#define GREEN_LED__SHIFT 2

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
