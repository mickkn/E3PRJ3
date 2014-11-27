/*
* File: main.c
* Description: Test of class buffer
* Project: PRJ3
* 
* Author: Bjørn Sørensen
*/


#include <project.h>
#include "buffer.h"

int main()
{
    // Create buffer
    buffer myBuf;
    buffer_init(&myBuf);
    
    int ret;
    
    // Create data for test
    char err[] = "E132";
    unsigned int err_len = 4;
    char data[] = "D015.202011";
    unsigned int data_len = 11;
    
    // Create read out variables
    char * read = NULL;
    unsigned int read_len;
    
    // Save error and get it
    buffer_saveData(&myBuf, err, err_len);
    buffer_getData(&myBuf, &read, &read_len);
    
    // Save data and 11 errors and get data
    // ret will change value to -21 when trying to write the last errors
    buffer_saveData(&myBuf, data, data_len);
    unsigned char i;
    for(i = 0; i < 11; i++)
        ret = buffer_saveData(&myBuf, err, err_len);
    buffer_getData(&myBuf, &read, &read_len);
    
    return 0;
}
