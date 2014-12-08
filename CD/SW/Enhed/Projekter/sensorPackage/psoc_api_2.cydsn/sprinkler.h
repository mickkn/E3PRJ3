//sprinkler.h
//
//Authour: Jakob Schmidt
//Version: 1.2
//Date: 14-11-14

//#pragma once
#ifndef sprinkler
#define sprinkler
#include <project.h>

//Constructor
extern void sprinkler_init();

//Destructor
extern void sprinkler_exit();

//Public methods
extern int sprinkler_setValue(unsigned char);

#endif
