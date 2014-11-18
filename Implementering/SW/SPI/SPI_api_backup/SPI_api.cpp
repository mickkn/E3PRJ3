#include "SPI_api.h"
#include <iostream>
#include <vector>
#include <fcntl.h>
#include <stdio.h>

using namespace std; //test

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
	int verifyResult;

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

	/* Parse char result to int */
	verifyResult = result - '0';

	/* Clear buffer */
	err = write(fp, &CL_BUF, 1);
	if(err < 0){
		printf("CLEAR ERROR: %d\n", err);
		close(fp);
		return -WERR;
	}

	/* Close file */
	close(fp);

	if(verifyResult == unit){
		return 0;
	}
	else{
		return -VERERR;
	}
}

int SPI_api::config(int unit, float temp, float humi)
{
	int fp, err;
	int dataLen = 1;
	char cmd[] = "P";	// 'P' for Parameter
	char tempArray[6];	// T T T . T \0
	char humiArray[4];	// F F F \0

	/* Parse floats to CharArrays */
	snprintf(tempArray, sizeof(tempArray), "%05.1f", temp);
	snprintf(humiArray, sizeof(humiArray), "%03.0f", humi);

	/* TEST
	printf("Temp char: %s\n", tempArray);
	printf("Humi char: %s\n", humiArray);
	*/

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

	/* Write temp to target without 0-termination */
	for(int i = 0 ; i < 5 ; i++){

		err = write(fp, &tempArray[i], dataLen);
		if(err < 0){
			printf("WRITE ERROR: %d\n", err);
			close(fp);
			return -WERR;
		}
	}

	/* Write humidity to target without 0-termination */
	for(int i = 0 ; i < 3 ; i++){

		err = write(fp, &humiArray[i], dataLen);
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

	return 0;
}

int SPI_api::getLog(vector<string> &data, int * units, int size)
{
	printf("test");

	int fp, err, i;
	int dataLen = 1;		// String length for Driver
	int stringDataLen = 14;	// String Data Length "DTTT.TFFFBEXXX"
	char cmd[] = "L";		// 'L' for Log
	char charResult;		// Used for buffering read chars
	string stringResult;
	string stringDataResult;
	string stringErrorResult;
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

	/* Build full string */
	for(i = 0 ; i < stringDataLen ; i++){
		err = read(fp, &charResult, dataLen);
		if(err < 0){
			printf("READ ERROR: %d\n", err);
			close(fp);
			return -RERR;
		}
		stringResult[i] = charResult;
	}

	/* Clear buffer */
	err = write(fp, &CL_BUF, 1);
		if(err < 0){
			printf("CLEAR ERROR: %d\n", err);
			close(fp);
			return -WERR;
		}

	close(fp);

	/* Build STRINGS */
	for(i = 0 ; i < stringDataLen-4 ; i++){
		stringDataResult[i] = stringResult[i];
	}
	for(i = 0 ; i < 4 ; i++){
		stringErrorResult[i] = stringResult[i+(dataLen-4)];
	}

	/* Add data and error string to vector */
	vectorResult[0] = stringDataResult;
	vectorResult[1] = stringErrorResult;

	data = vectorResult;

	printf("vectorResult0: 4");
	//printf("vectorResult1: %s\n", stringErrorResult);

	return 0;
}

