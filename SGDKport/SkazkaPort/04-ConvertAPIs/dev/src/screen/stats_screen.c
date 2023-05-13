#include "stats_screen.h"
#include "audio_manager.h"
#include "enum_manager.h"
#include "font_manager.h"
#include "game_manager.h"
#include "global_manager.h"
#include "graphics_manager.h"
#include "locale_manager.h"
#include "player_manager.h"
#include "select_manager.h"
#include "timer_manager.h"
#include "text_manager.h"
#include "fixedbank.h"

static unsigned char select_type;

void screen_stats_screen_load()
{
	struct_game_object *go = &global_game_object;
	struct_player_object *po = &global_player_object;
	unsigned char flash_arrow = go->flash_arrow;

	select_type = select_type_stats;
	engine_player_manager_calc();

	if( !flash_arrow )
	{
		engine_graphics_manager_draw_border();
		engine_graphics_manager_clear_part();

		engine_graphics_manager_draw_logo_small( LEFT_X + 1, TOP_Y + 1 );
		engine_graphics_manager_draw_underline( TOP_Y + 4 );

		engine_graphics_manager_draw_village( LEFT_X + 12, TOP_Y + 6 );
		engine_graphics_manager_draw_inventory( LEFT_X + 2, TOP_Y + 14 );
		engine_player_manager_draw_inventory( po->weapon, po->armor, po->life, LEFT_X + 2, TOP_Y + 14 );

		engine_game_manager_print_stats();
		engine_game_manager_print_texts();
		engine_font_manager_draw_text( ( char * ) diff_texts[ go->difficulty ], LEFT_X + 7, TOP_Y + 21 );
	}

	engine_select_manager_load( select_type, LEFT_X + 12, TOP_Y + OPTION_ROW, 6 );
	engine_game_manager_flash_off();
}

void screen_stats_screen_update( unsigned char *screen_type )
{
	unsigned char selection = engine_select_manager_update( select_type );
	if( NO_SELECTION == selection )
	{
		*screen_type = screen_type_stats;
		return;
	}

	// Wait until SFX completed...
	*screen_type = screen_type_stats;
	if( engine_audio_manager_is_playing() )
	{
		return;
	}

	switch( selection )
	{
	case action_type_forest:
		*screen_type = screen_type_forest;
		break;
	case action_type_shop:
		*screen_type = screen_type_shop;
		break;
	case action_type_rest:
		engine_player_manager_rest();
		engine_player_manager_stats();
		engine_audio_manager_play_sound( sound_type_9 );
		break;
	case action_type_talk:
		*screen_type = screen_type_talk;
		break;
	case action_type_boss:
		*screen_type = screen_type_prep;
		break;
	case action_type_menu:
		*screen_type = screen_type_menu;
		break;
	default:
		break;
	}
}
