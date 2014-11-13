#include "SPI_api.h"
#include <iostream>
#include <vector>
#include <fcntl.h>
#include <stdio.h>

static char CL_BUF = 'C';

int SPI_api::activate(int unit) const
{
	int fp, err;
	int datalen = 1;	// String length
	char data[] = "A";	// 'A' for Activate

	/* Open file */
	fp = open("/dev/spi_dev", O_RDWR);

	/* Write datalen times */
	for(int i = 0 ; i < datalen ; i++){

		err = write(fp, &data[i], datalen);
			if(err < 0){
				printf("WRITE ERROR: %d\n", err);
				goto write_error;
			}
	}

	/* Clear buffer */
	err = write(fp, &CL_BUF, 1);
		if(err < 0){
			printf("CLEAR ERROR: %d\n", err);
			goto clear_error;
		}

	/* Close file */
	close(fp);

	return 0;

	clear_error:
	write_error:
		close(fp);
		return err;
}

int SPI_api::deactivate(int unit) const
{
	int fp, err;
	int datalen = 1;	// String length
	char data[] = "D";	// 'D' for Deactivate

	/* Open file */
	fp = open("/dev/spi_dev", O_RDWR);

	/* Write datalen times */
	for(int i = 0 ; i < datalen ; i++){

		err = write(fp, &data[i], datalen);
			if(err < 0){
				printf("WRITE ERROR: %d\n", err);
				goto write_error;
			}
	}

	/* Clear buffer */
	err = write(fp, &CL_BUF, 1);
		if(err < 0){
			printf("CLEAR ERROR: %d\n", err);
			goto clear_error;
		}

	/* Close file */
	close(fp);

	return 0;

	clear_error:
	write_error:
		close(fp);
		return err;
}

int SPI_api::verify(int unit) const
{
	int fp, err;
	int datalen = 1;	// String length
	char cmd[] = "V";	// 'V' for Verify
	char result;

	/* Open file */
	fp = open("/dev/spi_dev", O_RDWR);

	/* Write CMD to Target*/
	err = write(fp, &cmd[0], datalen);
		if(err < 0){
			printf("WRITE ERROR: %d\n", err);
			goto write_error;
		}
/*
	/* Read 1 times
	err = read(fp, &result, datalen);
		if(err < 0){
			printf("READ ERROR: %d \n", err);
			goto read_error;
		}
*/
	/* Clear buffer */
	err = write(fp, &CL_BUF, 1);
		if(err < 0){
			printf("CLEAR ERROR: %d\n", err);
			goto clear_error;
		}

	/* Close file */
	close(fp);

	return 0;

	clear_error:
	write_error:
	read_error:
		close(fp);
		return err;
}

int SPI_api::config(int unit, vector<string>)
{
	return 0;
}

int SPI_api::getLog(vector<string> &data, int * units, int size)
{
	return 0;
}

