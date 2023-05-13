#include "start_screen.h"
#include "audio_manager.h"
#include "enum_manager.h"
#include "font_manager.h"
#include "game_manager.h"
#include "global_manager.h"
#include "graphics_manager.h"
#include "hack_manager.h"
#include "input_manager.h"
#include "locale_manager.h"
#include "player_manager.h"
#include "select_manager.h"
#include "timer_manager.h"
#include "text_manager.h"
#include "fixedbank.h"

#define START_FLASH_DELAY		50
#define START_FLASH_TOTAL		3
static unsigned char flash_index;
static unsigned char flash_count;

void screen_start_screen_load()
{
	struct_game_object *go = &global_game_object;
	struct_player_object *po = &global_player_object;
	engine_player_manager_calc();

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

	engine_font_manager_draw_punc( LOCALE_ARROW, LEFT_X + 12, TOP_Y + OPTION_ROW );
	engine_timer_manager_load( START_FLASH_DELAY );
	flash_index = 0;
	flash_count = 0;
}

void screen_start_screen_update( unsigned char *screen_type )
{
	struct_hack_object *ho = &global_hack_object;
	unsigned char timer;
	unsigned char input1;
	unsigned char input2;
	unsigned char nextr;

	nextr = 0;
	timer = engine_timer_manager_update();
	if( timer )
	{
		if( !ho->hack_delays )
		{
			flash_count = 1 - flash_count;
		}

		if( flash_count )
		{
			engine_font_manager_draw_char( LOCALE_1_SPCS, LEFT_X + 12, TOP_Y + OPTION_ROW );
		}
		else
		{
			engine_font_manager_draw_punc( LOCALE_ARROW, LEFT_X + 12, TOP_Y + OPTION_ROW );
			flash_index++;

			if( flash_index >= START_FLASH_TOTAL )
			{
				nextr = 1;
			}
		}
	}

	input1 = engine_input_manager_move_left();
	input2 = engine_input_manager_move_right();
	if( !nextr )
	{
		nextr = input1 || input2;
	}

	if( nextr )
	{
		*screen_type = screen_type_stats;
		return;
	}

	*screen_type = screen_type_start;
}
