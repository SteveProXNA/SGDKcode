#include "menu_screen.h"
#include "enum_manager.h"
#include "font_manager.h"
#include "game_manager.h"
#include "global_manager.h"
#include "graphics_manager.h"
#include "input_manager.h"
#include "locale_manager.h"
#include "select_manager.h"
#include "text_manager.h"
#include "timer_manager.h"
#include "fixedbank.h"

static unsigned char select_type;

void screen_menu_screen_load()
{
	unsigned char row;
	unsigned char idx;

	select_type = select_type_menu;

	engine_graphics_manager_draw_border();
	engine_graphics_manager_clear_part();

	engine_graphics_manager_draw_logo_small( LEFT_X + 1, TOP_Y + 1 );
	engine_graphics_manager_draw_underline( TOP_Y + 4 );

	row = 7;
	for( idx = 0; idx < 6; idx++ )
	{
		engine_font_manager_draw_text( ( char * ) menus_texts[ idx ], LEFT_X + 12, TOP_Y + row );
		row++;
	}

	engine_select_manager_load( select_type, LEFT_X + 10, TOP_Y + 10, 3 );
}

void screen_menu_screen_update( unsigned char *screen_type )
{
	unsigned char input;
	unsigned char selection;

	input = engine_input_manager_hold_buttonB();
	if( input )
	{
		*screen_type = screen_type_stats;
		return;
	}

	selection = engine_select_manager_update( select_type );
	if( NO_SELECTION == selection )
	{
		*screen_type = screen_type_menu;
		return;
	}

	switch( selection )
	{
	case menu_type_exit:
		engine_game_manager_intro_on();
		engine_game_manager_music_on();
		*screen_type = screen_type_title;
		break;
	case menu_type_restart:
		engine_game_manager_intro_off();
		engine_game_manager_music_off();
		*screen_type = screen_type_title;
		break;
	case menu_type_continue:
		*screen_type = screen_type_stats;
		break;
	}
}
