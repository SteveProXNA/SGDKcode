#ifndef _PLAYER_MANAGER_H_
#define _PLAYER_MANAGER_H_

#include "player_object.h"

// Global variable.
extern struct_player_object global_player_object;

void engine_player_manager_init();
void engine_player_manager_load();
void engine_player_manager_calc();
void engine_player_manager_stats();
void engine_player_manager_rest();
void engine_player_manager_hplo();

void engine_player_manager_draw( unsigned char weapon, unsigned char armor, unsigned char x, unsigned char y );
void engine_player_manager_draw_inventory( unsigned char weapon, unsigned char armor, unsigned char life, unsigned char x, unsigned char y );

void engine_player_manager_dec_gold( unsigned char gold );
void engine_player_manager_inc_gold( unsigned char xp, unsigned char gold );
void engine_player_manager_hit( char hp );
void engine_player_manager_armor( unsigned char armor );
unsigned char engine_player_manager_dead();
unsigned char engine_player_manager_life();

// Hack manager allows player to override default values.
void engine_player_manager_def_currxp( unsigned currxp );
void engine_player_manager_def_currhp( unsigned currhp );
void engine_player_manager_def_goldno( unsigned goldno );
void engine_player_manager_def_weapon( unsigned weapon );
void engine_player_manager_def_armors( unsigned armors );
void engine_player_manager_def_oneups( unsigned oneups );

void engine_player_manager_set_weapon( unsigned weapon );
void engine_player_manager_set_armors( unsigned armors );
void engine_player_manager_set_oneups( unsigned oneups );

#endif//_PLAYER_MANAGER_H_