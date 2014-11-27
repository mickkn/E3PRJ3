/*
* File: buffer.c
* Description: Implementation for EasyWater8000 class buffer
* Project: PRJ3
* 
* Author: Bjørn Sørensen
*/

#include "buffer.h"

// Private:
static char buffer_[BUFFER_LENGTH];    // Can hold 1 data reading and 10 errors
static unsigned int len_;              // Length of buffer_[]
static unsigned int cursor_;           // Points to next free index

// Public methods:
void buffer_init( )
{
    // Initialize members
    unsigned int i;
    for(i = 0; i < BUFFER_LENGTH; i++)
        buffer_[i] = 0;
    
   cursor_ = 0;
   len_ = BUFFER_LENGTH;
}

int buffer_saveData( const char * buf, const unsigned int len )
{
    if(len <= 0)    // If len <= 0
        return -20;
    
    // Get space left in buffer_
    unsigned int spaceLeft;
    spaceLeft = len_ - cursor_;
    
    if(len > spaceLeft) // If not enough room
        return -21;
    
    unsigned int i;
    for(i = 0; i < len; i++)            // Insert data into buffer
        buffer_[cursor_ + i] = buf[i];
    
    cursor_ += len;              // Update buffer cursor

    return 0;
}

int buffer_getData( char ** buf, unsigned int * len )
{
    // Returns pointer and length of used space
    *buf = buffer_;
    *len = cursor_;
    cursor_ = 0;
    
    return 0;
}
