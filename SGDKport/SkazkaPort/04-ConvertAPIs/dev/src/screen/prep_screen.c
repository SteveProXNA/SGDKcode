#include "prep_screen.h"
#include "audio_manager.h"
#include "enum_manager.h"
#include "font_manager.h"
#include "game_manager.h"
#include "global_manager.h"
#include "graphics_manager.h"
#include "hack_manager.h"
#include "input_manager.h"
#include "locale_manager.h"
#include "select_manager.h"
#include "text_manager.h"
#include "timer_manager.h"
#include "fixedbank.h"

static unsigned char select_type;

void screen_prep_screen_load()
{
	unsigned char row;
	unsigned char idx;

	select_type = select_type_prep;

	engine_graphics_manager_draw_border();
	engine_graphics_manager_clear_part();

	engine_graphics_manager_draw_logo_small( LEFT_X + 1, TOP_Y + 1 );
	engine_graphics_manager_draw_underline();

	row = 7;
	for( idx = 0; idx < 9; idx++ )
	{
		engine_font_manager_draw_text( ( char * ) prep_texts[ idx ], LEFT_X + 3, TOP_Y + row );
		row++;
	}

	engine_font_manager_draw_punc( LOCALE_STOP, LEFT_X + 22, TOP_Y + 8 );
	engine_font_manager_draw_punc( LOCALE_QMARK, LEFT_X + 28, TOP_Y + 11 );

	engine_select_manager_load( select_type, LEFT_X + 13, TOP_Y + 14, 2 );
}

void screen_prep_screen_update( unsigned char *screen_type )
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
		*screen_type = screen_type_prep;
		return;
	}

	*screen_type = binary_type_no == selection ? screen_type_stats : screen_type_boss;
}
