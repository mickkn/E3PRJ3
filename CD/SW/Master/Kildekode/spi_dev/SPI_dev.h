/*
* File: SPI_dev.h
* Description: Implementation for EasyWater8000 spi device driver
* Project: PRJ3
* 
* Author: Mick Kirkegaard & Poul Overgaard
*/

#pragma once

#include <linux/spi/spi.h>

struct spi_device* psoc4_get_device(void);
int psoc4_spi_read_reg8(struct spi_device *spi, u8 addr, char* value);
int psoc4_spi_write_reg8(struct spi_device *spi, u8 addr, char data);
int psoc4_spi_init(void);
void psoc4_spi_exit(void);