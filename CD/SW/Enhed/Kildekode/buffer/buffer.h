/*
* File: buffer.h
* Description: Header for EasyWater8000 class buffer
* Project: PRJ3
* 
* Author: Bjørn Sørensen
*/

#ifndef BUFFER_H
#define BUFFER_H

#define BUFFER_LENGTH 51

// Public:
extern void buffer_init( );  // Constructor
extern int buffer_saveData( const char * buf, const unsigned int len );
extern int buffer_getData( char ** buf, unsigned int * len );

#endif  // ifndef BUFFER_H