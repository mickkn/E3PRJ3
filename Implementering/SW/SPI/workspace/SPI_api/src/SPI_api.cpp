#include "SPI_api.h"
#include <iostream>
#include <vector>
#include <fcntl.h>
#include <stdio.h>

static char CL_BUF = 'C';

int SPI_api::activate(int unit) const
{
	int fp, err;
	int dataLen = 1;	// String length
	char data[] = "A";	// 'A' for Activate

	/* Open file */
	fp = open("/dev/spi_dev", O_RDWR);
	if(fp < 0){
		printf("OPEN ERROR: %d\n", fp);
		close(fp);
		return -OERR;
	}

	/* Write datalen times */
	for(int i = 0 ; i < dataLen ; i++){

		err = write(fp, &data[i], dataLen);
		if(err < 0){
			printf("WRITE ERROR: %d\n", err);
			close(fp);
			return -WERR;
		}
	}

	/* Clear buffer */
	err = write(fp, &CL_BUF, 1);
	if(err < 0){
		printf("CLEAR ERROR: %d\n", err);
		close(fp);
		return -WERR;
	}

	/* Close file */
	close(fp);

	return 0;
}

int SPI_api::deactivate(int unit) const
{
	int fp, err;
	int dataLen = 1;	// String length
	char data[] = "D";	// 'D' for Deactivate

	/* Open file */
	fp = open("/dev/spi_dev", O_RDWR);
	if(fp < 0){
		printf("OPEN ERROR: %d\n", fp);
		close(fp);
		return -OERR;
	}

	/* Write datalen times */
	for(int i = 0 ; i < dataLen ; i++){

		err = write(fp, &data[i], dataLen);
		if(err < 0){
			printf("WRITE ERROR: %d\n", err);
			close(fp);
			return -WERR;
		}
	}

	/* Clear buffer */
	err = write(fp, &CL_BUF, 1);
	if(err < 0){
		printf("CLEAR ERROR: %d\n", err);
		close(fp);
		return -WERR;
	}

	/* Close file */
	close(fp);

	return 0;
}

int SPI_api::verify(int unit) const
{
	int fp, err;
	int dataLen = 1;	// String length
	char cmd[] = "V";	// 'V' for Verify
	char result;

	/* Open file */
	fp = open("/dev/spi_dev", O_RDWR);
	if(fp < 0){
		printf("OPEN ERROR: %d\n", fp);
		close(fp);
		return -OERR;
	}

	/* Write CMD to Target*/
	err = write(fp, &cmd[0], dataLen);
	if(err < 0){
		printf("WRITE ERROR: %d\n", err);
		close(fp);
		return -WERR;
	}

	/* Read 2 times */
	for(int i = 0 ; i < 2 ; i++){
		err = read(fp, &result, dataLen);
		if(err < 0){
			printf("READ ERROR: %d \n", err);
			close(fp);
			return -RERR;
		}
	}

	/* Clear buffer */
	err = write(fp, &CL_BUF, 1);
	if(err < 0){
		printf("CLEAR ERROR: %d\n", err);
		close(fp);
		return -WERR;
	}

	/* Close file */
	close(fp);

	if(result == (char)unit)
		return 0;
	else
		return -1;
}

int SPI_api::config(int unit, vector<string> data)
{
	int fp, err;
	int dataLen = 1;	// String length
	char cmd[] = "P";	// 'V' for Verify
	int vectorLen = data.size();

	/* Open file */
	fp = open("/dev/spi_dev", O_RDWR);
	if(fp < 0){
		printf("OPEN ERROR: %d\n", fp);
		close(fp);
		return -OERR;
	}

	/* Write CMD to Target*/
	err = write(fp, &cmd[0], dataLen);
	if(err < 0){
		printf("WRITE ERROR: %d\n", err);
		close(fp);
		return -WERR;
	}

	/* Write vector<string> to target*/
	for(int i = 0 ; i < vectorLen ; i++){

		string tempString = data[i];

		for(unsigned int c = 0 ; c < tempString.length() ; c++){
			err = write(fp, &tempString[c], dataLen);
			if(err < 0){
				printf("WRITE ERROR: %d\n", err);
				close(fp);
				return err;
			}
		}
	}

	/* Clear buffer */
	err = write(fp, &CL_BUF, 1);
		if(err < 0){
			printf("CLEAR ERROR: %d\n", err);
			close(fp);
			return -WERR;
		}

	return 0;
}

int SPI_api::getLog(vector<string> &data, int * units, int size)
{
	int fp, err;
	int dataLen = 1;	// String length
	char cmd[] = "L";	// 'L' for Log
	char charResult, stringLen, vectorLen;
	string stringResult;
	vector<string> vectorResult;

	/* Open file */
	fp = open("/dev/spi_dev", O_RDWR);
	if(fp < 0){
		printf("OPEN ERROR: %d\n", fp);
		close(fp);
		return -OERR;
	}

	/* Write CMD to Target*/
	err = write(fp, &cmd[0], dataLen);
	if(err < 0){
		printf("WRITE ERROR: %d\n", err);
		close(fp);
		return -WERR;
	}

	/* Read vector length from target 2. time */
	for(int i = 0 ; i < 2 ; i++){
		err = read(fp, &vectorLen, dataLen);
		if(err < 0){
			printf("READ ERROR: %d\n", err);
			close(fp);
			return -RERR;
		}
	}

	/* Read vector<string> from target */
	for(int c = 0 ; c < (int)vectorLen ; c++){
		err = read(fp, &stringLen, dataLen);
		if(err < 0){
			printf("READ ERROR: %d\n", err);
			close(fp);
			return -RERR;
		}

		/* Read strings from target */
		for(int s = 0 ; s < (int)stringLen ; c++){
			err = read(fp, &charResult, dataLen);
			if(err < 0){
				printf("READ ERROR: %d\n", err);
				close(fp);
				return -RERR;
			}
			/* Build string from char's */
			stringResult[s] = charResult;
		}
		/* Build vector from string's */
		vectorResult[c] = stringResult;
	}

	data = vectorResult;

	return 0;
}

