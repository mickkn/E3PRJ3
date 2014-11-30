/*
* File: buffer.h
* Description: Header for EasyWater8000 class buffer
* Project: PRJ3
* 
* Author: Bjørn Sørensen
*/

#ifndef BUFFER_H
#define BUFFER_H

#define BUFFER_LENGTH 11+10*4   // 1 data reading and 10 errors

// Private:
typedef struct buffer_type
{
    char buffer_[BUFFER_LENGTH];    // Can hold 1 data reading and 10 errors
    unsigned int len_;              // Length of buffer_[]
    unsigned int cursor_;           // Points to next free index
} buffer;

// Public:
extern void buffer_init( buffer * const this );  // Constructor
extern int buffer_saveData( buffer * const this, const char * buf, const unsigned int len );
extern int buffer_getData( buffer * const this, char ** buf, unsigned int * len );

#endif  // ifndef BUFFER_H