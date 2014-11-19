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

	//std::cout << "Verifytest: " << result << endl;

	/* Parse char result to int */
	verifyResult = result - '0';

	//std::cout << "VerifyResulttest: " << result << endl;

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
		//printf("Verified\n");
		return 0;
	}
	else{
		//printf("Not Verified\n");
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

	int fp, err, i;
	int dataLen = 1;		// String length for Driver
	char charArrayLen;		// char array length from target
	char cmd[] = "L";		// 'L' for Log
	char charResult;		// Used for buffering read chars
	int errNo;
	int errCounter = 0;
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
		return -OERR;
	}

	/* Write CMD to Target*/
	err = write(fp, &cmd[0], dataLen);
	if(err < 0){
		printf("WRITE ERROR: %d\n", err);
		close(fp);
		return -WERR;
	}

	/* Read charArry length from target*/
		err = read(fp, &charArrayLen, dataLen);
		if(err < 0){
			printf("READ ERROR: %d\n", err);
			close(fp);
			return -RERR;
		}

	printf("charArrayLen: char = %c and int = %d \n", charArrayLen, charArrayLen);

	/* Build string from buffer from target */
	for(i = 0 ; i < (charArrayLen-1) ; i++){
		err = read(fp, &charResult, dataLen);
		if(err < 0){
			printf("READ ERROR: %d\n", err);
			close(fp);
			return -RERR;
		}
		stringResult.push_back(charResult);
	}

	std::cout << "stringResult: " <<  stringResult << endl;

	switch(stringResult[0]){
		case 'D':
			printf("Case D\n");
			/* BUILD DATASTRING DTTT.TFFFB */
			for(i = 0 ; i < 10 ; i++){
				stringDataResult.push_back(stringResult[i]);
			}
			vectorResult.push_back(stringDataResult);

			std::cout << "stringDataResult: " << stringDataResult << endl;

			/* BUILD ERROR STRING(S) IF PRESENT*/
			if(stringResult[10] == 'E'){

				errNo = (charArrayLen-11)/4;
				errCounter = 10;

				std::cout << "Number of Errors: " << errNo << endl;

				for(i = 0 ; i < errNo ; i++){
					for(int c = 0 ; c < 4 ; c++){
						stringErrorResult.push_back(stringResult[errCounter]);
						errCounter++;
					}
					std::cout << "stringErrorResult: " << stringErrorResult << endl;
					vectorResult.push_back(stringErrorResult);
					stringErrorResult.clear();
				}
			}

			break;
		case 'E':
			printf("Case E\n");
			errNo = (charArrayLen-1)/4;

			std::cout << "Number of Errors: " << errNo << endl;

			for(i = 0 ; i < errNo ; i++){
				for(int c = 0 ; c < 4 ; c++){
					stringErrorResult.push_back(stringResult[errCounter]);
					errCounter++;
				}
				std::cout << "stringErrorResult: " << stringErrorResult << endl;
				vectorResult.push_back(stringErrorResult);
				stringErrorResult.clear();
			}


			break;
	}

	data = vectorResult;

	close(fp);

	return 0;
}

