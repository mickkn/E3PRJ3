/*
* File: buffer.c
* Description: Implementation for EasyWater8000 class buffer
* Project: PRJ3
* 
* Author: Bjørn Sørensen
*/

#include "buffer.h"

// Public methods:
void buffer_init( buffer * const this )
{
    // Initialize members
    unsigned int i;
    for(i = 0; i < BUFFER_LENGTH; i++)
        this->buffer_[i] = 0;
    
   this->cursor_ = 0;
   this->len_ = BUFFER_LENGTH;
   this->dataIndex_ = 0;
   this->dataWritten_ = 0;
}

int buffer_saveData( buffer * const this, const char * buf, const unsigned int len )
{
    if(len <= 0)    // If len <= 0
        return -20;
    
    // Get space left in buffer_
    unsigned int spaceLeft;
    spaceLeft = this->len_ - this->cursor_;
    unsigned int index;
    index = this->cursor_;
    
    if(len > spaceLeft) // If not enough room
        return -21;
    
    if(buf[0] == 'D' && this->dataWritten_ == 1)    // Overwrite old data
    {
        index = this->dataIndex_;           // Set index to old dataIndex
    }
    else if(buf[0] == 'D')  // New data
    {   
        this->dataIndex_ = this->cursor_;   //  Set data index
        this->dataWritten_ = 1;             // Set flag that data has been written
        this->cursor_ += len;               // Update buffer cursor   
    }
    else
        this->cursor_ += len;               // Update buffer cursor 
    
    unsigned int i;
    for(i = 0; i < len; i++)            // Insert data into buffer
        this->buffer_[index + i] = buf[i];
    
    
    
    return 0;
}

int buffer_getData( buffer * const this, char ** buf, unsigned int * len )
{
    // Returns pointer and length of used space
    *buf = this->buffer_;
    *len = this->cursor_;
    this->cursor_ = 0;
    this->dataWritten_ = 0;
    
    return 0;
}
