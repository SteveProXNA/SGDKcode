#include "over_screen.h"
#include "audio_manager.h"
#include "enum_manager.h"
#include "font_manager.h"
#include "game_manager.h"
#include "global_manager.h"
#include "graphics_manager.h"
#include "input_manager.h"
#include "locale_manager.h"
#include "text_manager.h"
#include "timer_manager.h"
#include "fixedbank.h"

#define OVER_SCREEN_DELAY		200

static unsigned char first_time;

void screen_over_screen_load()
{
	unsigned char row;
	unsigned char idx;

	engine_graphics_manager_draw_border();
	engine_graphics_manager_clear_part();

	engine_graphics_manager_draw_logo_small( LEFT_X + 1, TOP_Y + 1 );
	engine_graphics_manager_draw_underline();

	row = 9;
	for( idx = 0; idx < 4; idx++ )
	{
		engine_font_manager_draw_text( ( char * ) over_texts[ idx ], LEFT_X + 9, TOP_Y + row );
		row++;
	}

	engine_font_manager_draw_punc( LOCALE_POINT, LEFT_X + 21, TOP_Y + 9 );
	engine_text_manager_cont();

	engine_timer_manager_load( OVER_SCREEN_DELAY );
	first_time = 1;
}

void screen_over_screen_update( unsigned char *screen_type )
{
	unsigned char input1;
	unsigned char input2;
	unsigned char timer;

	if( first_time )
	{
		first_time = 0;
		engine_game_manager_intro_off();
		engine_game_manager_music_off();

		// Play over music.
		engine_music_manager_over();
	}

	input1 = engine_input_manager_hold_buttonA();
	input2 = engine_input_manager_hold_buttonB();
	timer = engine_timer_manager_update();
	if( input1 || input2 || timer )
	{
		engine_audio_manager_stop();
		*screen_type = screen_type_title;
		return;
	}

	*screen_type = screen_type_over;
}
