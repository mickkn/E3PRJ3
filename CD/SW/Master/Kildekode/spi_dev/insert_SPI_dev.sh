echo 0x3 > /sys/class/cplddrv/cpld/spi_route_reg
echo 0x1 > /sys/class/cplddrv/cpld/ext_serial_if_route_reg

insmod SPI_devmod.ko
insmod hotplug_SPI_dev.ko

mknod /dev/spi_dev c 64 0