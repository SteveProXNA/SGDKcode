#ifndef _SELECT_MANAGER_H_
#define _SELECT_MANAGER_H_

#include "select_object.h"

// Global variables.
extern struct_select_object global_select_object;

void engine_select_manager_init();
void engine_select_manager_once();
void engine_select_manager_load( unsigned char index, unsigned char x, unsigned char y, unsigned char option );
unsigned char engine_select_manager_update( unsigned char index );

#endif//_SELECT_MANAGER_H_
