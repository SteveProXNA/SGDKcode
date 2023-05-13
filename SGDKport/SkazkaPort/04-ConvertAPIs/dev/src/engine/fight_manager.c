#include "fight_manager.h"
#include "font_manager.h"
#include "enemy_manager.h"
#include "enum_manager.h"
#include "game_manager.h"
#include "global_manager.h"
#include "hack_manager.h"
#include "player_manager.h"
#include "text_manager.h"

static unsigned char get_damage( unsigned char random );

//3500 F = INT( RND( 1 ) * 10 )
//3510 IF F = 0 THEN D = 0
//3520 IF F = 1 OR F = 2 OR F = 3 THEN D = 1 + ATK:HPLO = HPLO - D
//3530 IF F = 4 OR F = 5 OR F = 6 THEN D = 2 + ATK : HPLO = HPLO - D
//3540 IF F = 7 OR F = 8 THEN D = 3 + ATK : HPLO = HPLO - D
//3550 IF F = 9 THEN D = 4 + ATK + ATK : HPLO = HPLO - D
//3560 IF HPLO = 0 OR HPLO <= 0 THEN Z = Z + XPO : V = V + GLDO : GOTO 3300
void engine_fight_manager_player_to_enemy( unsigned char *e_damage, unsigned char random )
{
	// Damage to enemy from player.
	struct_player_object *po = &global_player_object;
	unsigned char damage;
	unsigned char extra;

	extra = po->weapon;
	damage = get_damage( random );

	if( 4 == damage )
	{
		damage += extra + extra;
	}
	else if( 0 == damage )
	{
		damage += 0;
	}
	else
	{
		damage += extra;
	}

	*e_damage = damage;
}
//3600 G = INT( RND( 1 ) * 10 )
//3610 IF G = 0 THEN S = 0
//3620 IF G = 1 OR G = 2 OR G = 3 THEN S = 1 + ATKLO:N = N - S + ARM
//3630 IF G = 4 OR G = 5 OR G = 6 THEN S = 2 + ATKLO : N = N - S + ARM
//3640 IF G = 7 OR G = 8 THEN S = 3 + AX : N = N - S + ARM
//3650 IF G = 9 THEN S = 4 + AX : N = N - S + ARM
void engine_fight_manager_enemy_to_player( unsigned char *p_damage, unsigned char random )
{
	// Damage to player from enemy.
	struct_enemy_object *eo = &global_enemy_object;
	struct_hack_object *ho = &global_hack_object;
	struct_game_object *go = &global_game_object;
	struct_player_object *po = &global_player_object;

	unsigned char damage;
	unsigned char extra;
	if( ho->hack_nodead )
	{
		*p_damage = 0;
		return;
	}

	extra = eo->ax;
	damage = get_damage( random );

	if( 4 == damage || 3 == damage )
	{
		damage += extra;
	}

	// Inflict more damage to player in hard mode. 
	if( diff_type_hard == go->difficulty )
	{
		if( po->level > 2 && 2 == damage )
		{
			damage += extra;
		}
		if( po->level > 1 && 1 == damage )
		{
			damage += extra;
		}
	}

	*p_damage = damage;
}

//11700 U = INT( RND( 1 ) * 10 )
//11701 IF U = 0 THEN UU = 0
//11702 IF U = 1 OR U = 2 OR U = 3 THEN UU = 1
//11703 IF U = 7 OR U = 8 THEN UU = 3
//11704 IF U = 9 THEN UU = 4 + ATK
//11705 IF U = 4 OR U = 5 OR U = 6 THEN UU = 2
//11710 D = UU + ATK
//11720 HPC = HPC - D
void engine_fight_manager_player_to_boss( unsigned char *b_damage, unsigned char random, unsigned char weapon )
{
	// Damage to boss from player.
	unsigned char damage;
	unsigned char extra;

	extra = weapon;
	damage = get_damage( random );

	if( 4 == damage )
	{
		damage += extra;
	}

	damage += extra;
	*b_damage = damage;
}
//11730 UA = INT( RND( 1 ) * 10 )
//11731 IF UA = 0 THEN UC = 0
//11732 IF UA = 1 OR UA = 2 OR UA = 3 THEN UC = 1
//11733 IF UA = 4 OR UA = 5 OR UA = 6 THEN UC = 2
//11734 IF UA = 7 OR UA = 8 THEN UC = 3
//11735 IF UA = 9 THEN UC = 4 + AX
//11740 S = UC - ARM + AX
//11750 N = N - S
void engine_fight_manager_boss_to_player( unsigned char *p_damage, unsigned char random )
{
	// Damage to player from boss.
	struct_enemy_object *eo = &global_enemy_object;
	struct_hack_object *ho = &global_hack_object;

	unsigned char damage;
	unsigned char extra;

	if( ho->hack_nodead )
	{
		*p_damage = 0;
		return;
	}

	extra = eo->ax;
	damage = get_damage( random );

	if( 4 == damage )
	{
		damage += extra;
	}

	damage += extra;
	*p_damage = damage;
}

static unsigned char get_damage( unsigned char random )
{
	unsigned char damage = 0;
	if( random < 1 )
	{
		damage = 0;
	}
	else if( random < 4 )
	{
		damage = 1;
	}
	else if( random < 7 )
	{
		damage = 2;
	}
	else if( random < 9 )
	{
		damage = 3;
	}
	else if( random == 9 )
	{
		damage = 4;
	}

	return damage;
}

void engine_fight_manager_gold( unsigned char *p_xp, unsigned char *p_gold )
{
	struct_enemy_object *eo = &global_enemy_object;

	*p_xp = eo->xpo;
	*p_gold = eo->gldo;
}