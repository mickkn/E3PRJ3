# THIS FILE IS AUTOMATICALLY GENERATED
# Project: C:\buffer\buffer.cydsn\buffer.cyprj
# Date: Wed, 03 Dec 2014 12:25:02 GMT
#set_units -time ns
create_clock -name {CyHFCLK} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/hfclk}]]
create_clock -name {CyIMO} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/imo}]]
create_clock -name {CySYSCLK} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/sysclk}]]
create_clock -name {CyILO} -period 31250 -waveform {0 15625} [list [get_pins {ClockBlock/ilo}]]
create_clock -name {CyLFCLK} -period 31250 -waveform {0 15625} [list [get_pins {ClockBlock/lfclk}]]


# Component constraints for C:\buffer\buffer.cydsn\TopDesign\TopDesign.cysch
# Project: C:\buffer\buffer.cydsn\buffer.cyprj
# Date: Wed, 03 Dec 2014 12:25:00 GMT
