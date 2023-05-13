#ifndef _FIGHT_MANAGER_H_
#define _FIGHT_MANAGER_H_

void engine_fight_manager_player_to_enemy( unsigned char *e_damage, unsigned char random );
void engine_fight_manager_enemy_to_player( unsigned char *p_damage, unsigned char random );

void engine_fight_manager_player_to_boss( unsigned char *b_damage, unsigned char random, unsigned char weapon );
void engine_fight_manager_boss_to_player( unsigned char *p_damage, unsigned char random );

void engine_fight_manager_gold( unsigned char *p_xp, unsigned char *p_gold );

#endif//_FIGHT_MANAGER_H_
