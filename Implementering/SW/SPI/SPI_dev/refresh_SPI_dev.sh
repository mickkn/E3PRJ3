rmmod SPI_devmod.ko
rmmod hotplug_SPI_dev.ko

rm /dev/spi_dev

insmod SPI_devmod.ko
insmod hotplug_SPI_dev.ko

mknod /dev/spi_dev c 64 0