/*
* File: SPI_dev.c
* Description: Implementation for EasyWater8000 spi device driver
* Project: PRJ3
* 
* Author: Mick Kirkegaard & Poul Overgaard
*/

#include <linux/cdev.h>
#include <linux/device.h>
#include <asm/uaccess.h>
#include <linux/input.h>
#include <linux/spi/spi.h>
#include <linux/module.h>
#include <linux/wait.h>
#include "SPI_dev.h"

#define MODULE_DEBUG 		0

#define NBR_PSOC4_CH		1

#define MAXLEN              	64

#define PSOC4_MAJOR       	64
#define PSOC4_MINOR        	0

MODULE_AUTHOR("MIPO - Mick & Poul");
MODULE_LICENSE("Dual BSD/GPL");
MODULE_DESCRIPTION("SPI Project 3 - EasyWater8000");

/* Char Driver Globals */
static struct cdev psoc4Dev;
struct file_operations psoc4_Fops;
static int devno;

/* We are only using ONE SPI device so far */
static struct spi_device *psoc4_spi_device = NULL;

/* Method to retrieve SPI device pointer */
struct spi_device* psoc4_get_device(void){
  return psoc4_spi_device;
}

/* Macro to handle Errors */
#define ERRGOTO(label, ...)                     \
  {                                             \
  printk (__VA_ARGS__);                         \
  goto label;                                   \
  } while(0)

/*
 * PSOC4 Probe
 * Used by the SPI Master to probe the device
 * when an SPI device is registered.
 */
static int __devinit psoc4_spi_probe(struct spi_device *spi)
{
      int err = 0;
      
      printk(KERN_DEBUG "New SPI device: %s using chip select: %i\n",
	    spi->modalias, spi->chip_select);

      spi->bits_per_word = 8;  // Bit per Transfer
      spi_setup(spi);

      if(MODULE_DEBUG)
	printk(KERN_DEBUG "TEST: psoc4.c psoc4_spi_probe\n");
      
      /* In this case we assume just one device */
      psoc4_spi_device = spi;  

      return err;
}

/*
 * PSOC4 Remove
 * Called when the SPI device is removed
 */
static int __devexit psoc4_remove(struct spi_device *spi)
{   
      struct psoc4 *psoc4dev = dev_get_drvdata(&spi->dev);
      
      if(MODULE_DEBUG)
	printk(KERN_DEBUG "TEST: psoc4.c psco4_remove\n");  
     
      psoc4_spi_device = 0;
      
      printk (KERN_ALERT "Removing SPI device %s on chip select %i\n", 
	      spi->modalias, spi->chip_select);

      kfree(psoc4dev); /* Free kernel memory */

      return 0;
}

/*
 * PSOC4 SPI Driver Struct
 * Holds function pointers to probe/release
 * methods and the name under which it is registered
 *
 */
static struct spi_driver psoc4_spi_driver = {
      .driver = {
	.name  = "psoc4",
	.bus   = &spi_bus_type,
	.owner = THIS_MODULE,
      },
      .probe = psoc4_spi_probe,
      .remove = __devexit_p(psoc4_remove),
};

/*
 * PSoC4 SPI Init
 * Registers the spi driver with the SPI host
 */
int psoc4_spi_init(void)
{  
  int err;

  err = spi_register_driver(&psoc4_spi_driver);
  
  if(err<0)
    printk (KERN_ALERT "Error %d registering the PSoC4 SPI driver\n", err);
  
  return err;
}

/*
 * SPI Exit
 */
void psoc4_spi_exit(void)
{
      spi_unregister_driver(&psoc4_spi_driver);
}

/*
 * PSoC4 CDRV Init
 * Registers the spi driver with the SPI host
 */
static int __init psoc4_cdrv_init(void)
{ 
      int err;
      
      if(MODULE_DEBUG)
	printk(KERN_DEBUG "TEST: psoc4.c psoc4_cdrv_init\n");       
      
      /* Registers the spi driver with the SPI host*/
      err = psoc4_spi_init();
      if(err){
	printk (KERN_ALERT "Error %d registering the psoc4 SPI driver\n", err);
	ERRGOTO(error, "Failed SPI Initialization\n");
      }
      
      /* Allocate chrdev region */
      devno = MKDEV(PSOC4_MAJOR, PSOC4_MINOR);
      err = register_chrdev_region(devno, NBR_PSOC4_CH, "psoc4");  
      if(err){
	ERRGOTO(err_spi_init, "Failed registering char region (%d,%d) +%d, error %d\n",
		PSOC4_MAJOR, PSOC4_MINOR, NBR_PSOC4_CH, err);      
      }
      
      /* Register Char Device */
      cdev_init(&psoc4Dev, &psoc4_Fops);
      err = cdev_add(&psoc4Dev, devno, NBR_PSOC4_CH);
      if (err){
	ERRGOTO(err_register, "Error %d adding PSOC4 device\n", err);	
      
      }
      
      return 0;
  
  err_register:
  unregister_chrdev_region(devno, NBR_PSOC4_CH);

  err_spi_init:
  psoc4_spi_exit();
  
  error:
  return err;
}

/*
 * PSoC4 CDRV Exit
 * Exit routine called from character driver.
 * Unregisters the driver from the SPI host
 */
void psoc4_cdrv_exit(void)
{         
      printk("psoc4 driver Exit\n");
      cdev_del(&psoc4Dev);

      unregister_chrdev_region(devno, NBR_PSOC4_CH);
      
      spi_unregister_driver(&psoc4_spi_driver);
}

/*
 * PSoC4 CDRV OPEN
 * 
 */
int psoc4_cdrv_open(struct inode *inode, struct file *filep)
{ 
  
      int major = imajor(inode);
      int minor = iminor(inode);

      if(MODULE_DEBUG)
	printk(KERN_DEBUG "TEST: psoc4.c psoc4_cdrv_open\n"); 
      
      if(MODULE_DEBUG)
	printk("Opening PSOC4 Device [major], [minor]: %i, %i\n", major, minor);

      // Check if minor number is within range
      if (minor > NBR_PSOC4_CH-1)
      {
	printk("Minor no out of range (0-%i): %i\n", NBR_PSOC4_CH, minor);
	return -ENODEV;
      }

      // Check if a psoc4 device is registered
      if(!(psoc4_spi_device=psoc4_get_device()))
	return -ENODEV;
      
      return 0;
}



/*
 * PSoC4 CDRV RELEASE
 * 
 */
int psoc4_cdrv_release(struct inode *inode, struct file *filep)
{  
  
      int major = imajor(inode);
      int minor = iminor(inode);

      if(MODULE_DEBUG)
	printk(KERN_DEBUG "TEST: psoc4.c psoc4_cdrv_release\n"); 
      
      if(MODULE_DEBUG)
	printk("Closing PSOC4 Device [major], [minor]: %i, %i\n", major, minor);

      if ((minor > NBR_PSOC4_CH-1) || !(psoc4_spi_device=psoc4_get_device()))
	return -ENODEV;
      
      return 0;
}

/*
 * PSOC4 SPI Write 8-bit Register
 * Writes 8-bit content to register at 
 * the provided PSOC4 function address
 */
int psoc4_spi_write_reg8(struct spi_device *spi, u8 cmd, char data)
{
      struct spi_transfer t[1];	// Number of packages
      struct spi_message m;

      if(MODULE_DEBUG)
	printk(KERN_DEBUG "TEST: psoc4.c psoc4_spi_write_reg8\n");
      
      /* Check for valid spi device */
	if(!spi)
	return -ENODEV;
      
      /* Init Message */
      memset(&t, 0, sizeof(t)); 
      spi_message_init(&m);
      m.spi = spi;

      if(MODULE_DEBUG)
	printk(KERN_DEBUG "PSOC4: Write Reg8 Addr 0x%x Data '%c'\n", cmd, data);
      
      /* Configure tx/rx buffers */
      t[0].tx_buf = &data;
      t[0].rx_buf = NULL;
      t[0].len = 1;
      spi_message_add_tail(&t[0], &m);
      
      /* Transmit SPI Data (blocking) */
      spi_sync(m.spi, &m);

      return 0;
}

/*
 * PSoC4 CDRV WRITE
 */
ssize_t psoc4_cdrv_write(struct file *filep, const char __user *ubuf, 
		       size_t count, loff_t *f_pos)
{
      int cmd = 1;	// Made to write a initializer with SPI, maybe not needed
      
      int minor, len;
      char myArray[MAXLEN];
      
      minor = MINOR(filep->f_dentry->d_inode->i_rdev);
      
      if(MODULE_DEBUG)
	printk(KERN_ALERT "Writing to PSoC4 [Minor] %i \n", minor);
    
      /* Limit copy length to MAXLEN allocated and Copy from user */
      len = count < MAXLEN ? count : MAXLEN;
      if(copy_from_user(myArray, ubuf, len))
	printk(KERN_ALERT "ERROR in copy_from_user");
      
      /*
      * Do something
      */
      if(MODULE_DEBUG)
	printk(KERN_ALERT "Writing '%c' to address: %d\n", myArray[0], (u8)cmd);

      /*
       * Call SPI WRITE
       */
      
      psoc4_spi_write_reg8(psoc4_spi_device, cmd, myArray[0]);
      
      
      /* Legacy file ptr f_pos. Used to support 
      * random access but in char drv we dont! 
      * Move it the length actually  written 
      * for compability */
      *f_pos += len;

      /* return length actually written */
      return len;
}

/*
 * PSoC4 SPI Read 16-bit Register
 * Reads 16-bit content of register at 
 * the provided PSoC4 address
 */
int psoc4_spi_read_reg8(struct spi_device *spi, u8 addr, char* value)
{
      struct spi_transfer t[1];
      struct spi_message m;
      char data;
      char cmd = 'R';	// Read command
      
      if(MODULE_DEBUG)
	printk(KERN_DEBUG "TEST: psoc4.c psoc4_spi_read_reg16\n");
      
      /* Check for valid spi device */
      if(!spi)
	return -ENODEV;
      
      /* Init Message */
      memset(t, 0, sizeof(t));
      spi_message_init(&m);
      m.spi = spi;
      
      if(MODULE_DEBUG)
	printk(KERN_DEBUG "PSOC4: Read Reg8 Cmd: 0x%d Data: '%c'\n", cmd, data);
      
      /* Configure tx/rx buffers */
      t[0].delay_usecs = 100;	// Delay for PSoC4
      t[0].tx_buf = &cmd;
      t[0].rx_buf = &data;
      t[0].len = 1;
      spi_message_add_tail(&t[0], &m);
      
      /* Transmit SPI Data (blocking) */
      spi_sync(m.spi, &m);
      
      //printk("Data: '%c'\n", data);
      
      if(MODULE_DEBUG)
	printk(KERN_DEBUG "PSOC4: Read Reg8 Cmd: '%c' Data: '%c'\n", cmd, data);

      *value = data;
	  return 0;
}

/*
 * PSoC4 CDRV READ
 */
ssize_t psoc4_cdrv_read(struct file *filep, char __user *ubuf, 
                          size_t count, loff_t *f_pos)
{       
      int minor;
      int len = 1;
      //char resultBuf[MAXLEN];
      char result;
      u8 addr = 0;	// Dummy not used in prototype project

      if(MODULE_DEBUG)
	printk(KERN_DEBUG "TEST: psoc4.c psoc4_cdrv_read\n"); 
      
      minor = MINOR(filep->f_dentry->d_inode->i_rdev);

      if(MODULE_DEBUG)
	printk(KERN_ALERT "Reading from psoc4 [Minor] %i \n", minor);
      
      /* Perform SPI read */
      
      psoc4_spi_read_reg8(psoc4_spi_device, addr , &result);
      
      /* Copy data to user space */
      if(copy_to_user(ubuf, &result, len))
	return -EFAULT;
      
      //printk(KERN_ALERT "Result: '%c'\n", result);
      
      /* Move fileptr */
      *f_pos += len;

      return len;
}

/*
 * PSOC4 SPI FOPS Struct
 *
 */
struct file_operations psoc4_Fops = 
{
      .owner   = THIS_MODULE,
      .open    = psoc4_cdrv_open,
      .release = psoc4_cdrv_release,
      .write   = psoc4_cdrv_write,
      .read    = psoc4_cdrv_read,
};

/*
 * PSOC4 Init/Exit
 */
module_init(psoc4_cdrv_init);
module_exit(psoc4_cdrv_exit);