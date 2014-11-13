# THIS FILE IS AUTOMATICALLY GENERATED
# Project: Z:\Desktop\E3PRJ3\Implementering\SW\SPI\PSoC4_SPI\SPI_slave\SPI_slave.cydsn\SPI_slave.cyprj
# Date: Wed, 12 Nov 2014 20:13:38 GMT
#set_units -time ns
create_clock -name {SPIS_1_SCBCLK(FFB)} -period 83.333333333333329 -waveform {0 41.6666666666667} [list [get_pins {ClockBlock/ff_div_2}]]
create_clock -name {CyHFCLK} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/hfclk}]]
create_generated_clock -name {SPIS_1_SCBCLK} -source [get_pins {ClockBlock/hfclk}] -edges {1 3 5} [list]
create_clock -name {CyIMO} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/imo}]]
create_clock -name {CySYSCLK} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/sysclk}]]
create_clock -name {CyILO} -period 31250 -waveform {0 15625} [list [get_pins {ClockBlock/ilo}]]
create_clock -name {CyLFCLK} -period 31250 -waveform {0 15625} [list [get_pins {ClockBlock/lfclk}]]


# Component constraints for Z:\Desktop\E3PRJ3\Implementering\SW\SPI\PSoC4_SPI\SPI_slave\SPI_slave.cydsn\TopDesign\TopDesign.cysch
# Project: Z:\Desktop\E3PRJ3\Implementering\SW\SPI\PSoC4_SPI\SPI_slave\SPI_slave.cydsn\SPI_slave.cyprj
# Date: Wed, 12 Nov 2014 20:13:35 GMT