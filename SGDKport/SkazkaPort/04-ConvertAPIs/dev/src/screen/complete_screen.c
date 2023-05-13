#include "complete_screen.h"
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

#define BEAT_SCREEN_DELAY	900

void screen_complete_screen_load()
{
	unsigned char row;
	unsigned char idx;

	engine_graphics_manager_draw_border();
	engine_graphics_manager_clear_part();

	engine_graphics_manager_draw_logo_small( LEFT_X + 1, TOP_Y + 1 );
	engine_graphics_manager_draw_underline();

	row = 7;
	for( idx = 0; idx < 11; idx++ )
	{
		engine_font_manager_draw_text( ( char * ) beat_texts[ idx ], LEFT_X + 2, TOP_Y + row );
		row++;
	}

	engine_font_manager_draw_punc( LOCALE_POINT, LEFT_X + 22, TOP_Y + 7 );
	engine_font_manager_draw_punc( LOCALE_POINT, LEFT_X + 23, TOP_Y + 7 );
	engine_font_manager_draw_punc( LOCALE_POINT, LEFT_X + 27, TOP_Y + 17 );
	engine_font_manager_draw_punc( '.', LEFT_X + 16, TOP_Y + 13 );
	engine_text_manager_cont();

	engine_timer_manager_load( BEAT_SCREEN_DELAY );
	engine_music_manager_beat();
}

void screen_complete_screen_update( unsigned char *screen_type )
{
	unsigned char input1;
	unsigned char input2;
	unsigned char timer;

	input1 = engine_input_manager_hold_buttonA();
	input2 = engine_input_manager_hold_buttonB();
	timer = engine_timer_manager_update();

	if( input1 || input2 || timer )
	{
		engine_audio_manager_stop();
		engine_game_manager_intro_off();
		engine_game_manager_music_off();
		*screen_type = screen_type_title;
		return;
	}

	*screen_type = screen_type_complete;
}
