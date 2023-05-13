#ifndef _ENEMY_MANAGER_H_
#define _ENEMY_MANAGER_H_

#include "enemy_object.h"

// Global variable.
extern struct_enemy_object global_enemy_object;

void engine_enemy_manager_init();
void engine_enemy_manager_load( unsigned char level );
void engine_target_manager_load( unsigned char index );
void engine_enemy_manager_text();
void engine_enemy_manager_hplo();
void engine_enemy_manager_hit( char hp );
void engine_enemy_manager_draw( unsigned char enemy, unsigned char x, unsigned char y );
unsigned char engine_enemy_manager_dead();

#endif//_ENEMY_MANAGER_H_
