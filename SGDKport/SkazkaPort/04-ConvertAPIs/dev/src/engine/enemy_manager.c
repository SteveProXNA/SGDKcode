#include "enemy_manager.h"
#include "enum_manager.h"
#include "font_manager.h"
#include "global_manager.h"
#include "random_manager.h"
#include "text_manager.h"
#include "fixedbank.h"
#include "gfx.h"

// Global variable.
struct_enemy_object global_enemy_object;

unsigned char hplo_num[ MAX_ENEMIES ] =	{ 10, 10, 25, 25, 35, 50 };
unsigned char ax_num[ MAX_ENEMIES ] =	{  1,  1,  2,  2,  3,  4 };
unsigned char gldo_num[ MAX_ENEMIES ] = {  5,  5, 10, 10, 15,  0 };
unsigned char xpo_num[ MAX_ENEMIES ] =	{  2,  2,  4,  4, 10,  0 };

static void draw_enemy( unsigned char enemy, unsigned char x, unsigned char y );
static void draw_leshy( unsigned char x, unsigned char y );

void engine_enemy_manager_init()
{
	struct_enemy_object *eo = &global_enemy_object;
	eo->index = 0;
	eo->hplo = 0;
	eo->ax = 0;
	eo->gldo = 0;
	eo->xpo = 0;
}

void engine_enemy_manager_load( unsigned char level )
{
	unsigned char value = 0;
	unsigned char index = 0;

	value = engine_random_manager_next();
	switch( level )
	{
	case 1:
		index = value < 5 ? enemy_type_razboynik : enemy_type_hungry_wolf;
		break;
	case 2:
		if( value < 3 )
		{
			index = enemy_type_razboynik;
		}
		else if( value < 6 )
		{
			index = enemy_type_kikimora;
		}
		else if( value < 8 )
		{
			index = enemy_type_hungry_wolf;
		}
		else
		{
			index = enemy_type_leshy;
		}
		break;
	case 3:
		if( value < 1 )
		{
			index = enemy_type_razboynik;
		}
		else if( value < 2 )
		{
			index = enemy_type_hungry_wolf;
		}
		else if( value < 5 )
		{
			index = enemy_type_kikimora;
		}
		else if( value < 8 )
		{
			index = enemy_type_leshy;
		}
		else
		{
			index = enemy_type_baby_yaga;
		}
		break;
	}

	engine_target_manager_load( index );
}

void engine_target_manager_load( unsigned char index )
{
	struct_enemy_object *eo = &global_enemy_object;
	eo->index = index;
	eo->hplo = hplo_num[ index ];
	eo->ax = ax_num[ index ];
	eo->gldo = gldo_num[ index ];
	eo->xpo = xpo_num[ index ];
}

void engine_enemy_manager_text()
{
	struct_enemy_object *eo = &global_enemy_object;
	engine_font_manager_draw_text( ( char * ) enemy_texts[ eo->index ], LEFT_X + 16, TOP_Y + 9 );
}

void engine_enemy_manager_hplo()
{
	struct_enemy_object *eo = &global_enemy_object;
	engine_font_manager_draw_data( eo->hplo, LEFT_X + 29, TOP_Y + 21 );
}

void engine_enemy_manager_hit( char hp )
{
	struct_enemy_object *eo = &global_enemy_object;
	if( eo->hplo > hp )
	{
		eo->hplo -= hp;
	}
	else
	{
		eo->hplo = 0;
	}
}

void engine_enemy_manager_draw( unsigned char enemy, unsigned char x, unsigned char y )
{
	if( enemy_type_leshy != enemy )
	{
		draw_enemy( enemy, x, y );
	}
	else
	{
		draw_leshy( x, y );
	}
}

unsigned char engine_enemy_manager_dead()
{
	struct_enemy_object *eo = &global_enemy_object;
	return eo->hplo <= 0;
}

static void draw_enemy( unsigned char enemy, unsigned char x, unsigned char y )
{
	const unsigned char wide = 3;
	const unsigned char high = 4;

	u16 basetile = TILE_ATTR_FULL( PAL0, 0, 0, 0, ENEMY_TILES );
	VDP_setTileMapEx( BG_A, gfx_battle_enemies.tilemap, basetile, x, y, 0, enemy * high, wide, high, CPU );
}

static void draw_leshy( unsigned char x, unsigned char y )
{
	const unsigned char wide = 3;
	const unsigned char high = 4;

	u16 basetile = TILE_ATTR_FULL( PAL1, 0, 0, 0, LESHY_TILES );
	VDP_setTileMapEx( BG_A, gfx_battle_enemies_leshy.tilemap, basetile, x, y, 0, 0, wide, high, CPU );
}