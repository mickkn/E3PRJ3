#include "SPI_api.h"
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
		return -ACT_ERR;
	}

	/* Write datalen times */
	for(int i = 0 ; i < dataLen ; i++){
		err = write(fp, &data[i], dataLen);
		if(err < 0){
			printf("WRITE ERROR: %d\n", err);
			close(fp);
			return -ACT_ERR;
		}
	}

	/* Clear buffer */
	err = write(fp, &CL_BUF, 1);
	if(err < 0){
		printf("CLEAR ERROR: %d\n", err);
		close(fp);
		return -ACT_ERR;
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
		return -DEACT_ERR;
	}

	/* Write datalen times */
	for(int i = 0 ; i < dataLen ; i++){
		err = write(fp, &data[i], dataLen);
		if(err < 0){
			printf("WRITE ERROR: %d\n", err);
			close(fp);
			return -DEACT_ERR;
		}
	}

	/* Clear buffer */
	err = write(fp, &CL_BUF, 1);
	if(err < 0){
		printf("CLEAR ERROR: %d\n", err);
		close(fp);
		return -DEACT_ERR;
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
		return -VER_ERR;
	}

	/* Write CMD to Target*/
	err = write(fp, &cmd[0], dataLen);
	if(err < 0){
		printf("WRITE ERROR: %d\n", err);
		close(fp);
		return -VER_ERR;
	}

	/* Read 2 times */
	for(int i = 0 ; i < 2 ; i++){
		err = read(fp, &result, dataLen);
		if(err < 0){
			printf("READ ERROR: %d \n", err);
			close(fp);
			return -VER_ERR;
		}
	}

	/* Parse char result to int */
	verifyResult = (result - '0');

	/* Clear buffer */
	err = write(fp, &CL_BUF, 1);
	if(err < 0){
		printf("CLEAR ERROR: %d\n", err);
		close(fp);
		return -VER_ERR;
	}

	/* Close file */
	close(fp);

	if(verifyResult == unit){
		return 0;
	}
	else{
		printf("Not Verified: %d\n", -VER_ERR);
		return -VER_ERR;
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

	/* Open file */
	fp = open("/dev/spi_dev", O_RDWR);
	if(fp < 0){
		printf("OPEN ERROR: %d\n", fp);
		close(fp);
		return -CONF_ERR;
	}

	/* Write CMD to Target*/
	err = write(fp, &cmd[0], dataLen);
	if(err < 0){
		printf("WRITE ERROR: %d\n", err);
		close(fp);
		return -CONF_ERR;
	}

	/* Write temp to target without 0-termination */
	for(int i = 0 ; i < 5 ; i++){
		err = write(fp, &tempArray[i], dataLen);
		if(err < 0){
			printf("WRITE ERROR: %d\n", err);
			close(fp);
			return -CONF_ERR;
		}
	}

	/* Write humidity to target without 0-termination */
	for(int i = 0 ; i < 3 ; i++){
		err = write(fp, &humiArray[i], dataLen);
		if(err < 0){
			printf("WRITE ERROR: %d\n", err);
			close(fp);
			return -CONF_ERR;
		}
	}

	/* Clear buffer */
	err = write(fp, &CL_BUF, 1);
	if(err < 0){
		printf("CLEAR ERROR: %d\n", err);
		close(fp);
		return -CONF_ERR;
	}

	return 0;
}

int SPI_api::getLog(vector<string> &data, int * units, int size)
{

	int fp, err, i;
	int dataLen = 1;		// String length for Driver
	char cmd[] = "L";		// 'L' for Log
	char charArrayLen;		// Variable for charArray size from target
	char charResult;		// Used for buffering read chars
	string stringResult;
		stringResult.clear();
	string stringDataResult;
		stringDataResult.clear();
	string stringErrorResult;
		stringErrorResult.clear();
	vector<string> vectorResult;
		vectorResult.clear();

	/* Open file */
	fp = open("/dev/spi_dev", O_RDWR);
	if(fp < 0){
		printf("OPEN ERROR: %d\n", fp);
		close(fp);
		return -LOG_ERR;
	}

	/* Write CMD to Target */
	err = write(fp, &cmd[0], dataLen);
	if(err < 0){
		printf("WRITE ERROR: %d\n", err);
		close(fp);
		return -LOG_ERR;
	}

	/* Read charArray length from target */
	err = read(fp, &charArrayLen, dataLen);
	if(err < 0){
		printf("READ ERROR: %d\n", err);
		close(fp);
		return -LOG_ERR;
	}

	//printf("charArrayLen: char = %c and int = %d \n", charArrayLen, charArrayLen);

	/* Vector Builder looking for D's or E's */
	for(i = 0 ; i < charArrayLen ; i++){
		err = read(fp, &charResult, dataLen);
		if(err < 0){
			printf("READ ERROR: %d\n", err);
			close(fp);
			return -LOG_ERR;
		}

		if(charResult == 'D'){
			stringDataResult.push_back(charResult); // Push 'D' to stringDataResult
			 // Build rest of stringDataResult
			for(int c = 0 ; c < 9 ; c++){
				err = read(fp, &charResult, dataLen);
				if(err < 0){
					printf("READ ERROR: %d\n", err);
					close(fp);
					return -LOG_ERR;
				}
				stringDataResult.push_back(charResult);
				i++;	// Increment 1st for-loop counter
			}
			//std::cout << "stringDataResult: " << stringDataResult << endl;
			// Push string to vectorResult
			vectorResult.push_back(stringDataResult);
			stringDataResult.clear();
		}

		if(charResult == 'E'){
			stringErrorResult.push_back(charResult); // Push 'E' to stringErrorResult
			// Build rest of stringErrorResult
			for(int c = 0 ; c < 3 ; c++){
				err = read(fp, &charResult, dataLen);
				if(err < 0){
					printf("READ ERROR: %d\n", err);
					close(fp);
					return -LOG_ERR;
				}
				stringErrorResult.push_back(charResult);
				i++;	// Increment 1st for-loop counter
			}
			//std::cout << "stringErrorResult: " << stringErrorResult << endl;
			// Push string to vectorResult and clear string
			vectorResult.push_back(stringErrorResult);
			stringErrorResult.clear();
		}
	}

	data = vectorResult;

	close(fp);

	return 0;
}

