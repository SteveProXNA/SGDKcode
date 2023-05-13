#ifndef _TIMER_MANAGER_H_
#define _TIMER_MANAGER_H_

#include "timer_object.h"

// Global variable.
extern struct_timer_object global_timer_object;

// Timer Manager.
void engine_timer_manager_load( unsigned int delay );
unsigned char engine_timer_manager_update();

#endif//_TIMER_MANAGER_H_
