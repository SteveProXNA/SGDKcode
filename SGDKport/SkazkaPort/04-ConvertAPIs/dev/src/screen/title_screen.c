#include "title_screen.h"
#include "audio_manager.h"
#include "enum_manager.h"
#include "font_manager.h"
#include "game_manager.h"
#include "global_manager.h"
#include "graphics_manager.h"
#include "hack_manager.h"
#include "input_manager.h"
#include "locale_manager.h"
#include "random_manager.h"
#include "text_manager.h"
#include "timer_manager.h"

#define TITLE_FLASH_DELAY	50
#define TITLE_SOUND_DELAY	50

static unsigned char first_time;
static unsigned char event_stage;
static unsigned char flash_count;

void screen_title_screen_load()
{
	engine_graphics_manager_draw_border();
	engine_graphics_manager_clear_part();

	engine_graphics_manager_draw_logo_big( LEFT_X + 2, TOP_Y + 3 );
	engine_font_manager_draw_text( LOCALE_TITLE_MSG1, LEFT_X + 6, TOP_Y + 10 );
	engine_font_manager_draw_text( LOCALE_TITLE_MSG2, LEFT_X + 3, TOP_Y + 15 );
	engine_font_manager_draw_numb( 8, LEFT_X + 16, TOP_Y + 15 );

	engine_timer_manager_load( TITLE_FLASH_DELAY );
	first_time = 1;
	event_stage = event_stage_start;
	flash_count = 0;
}

void screen_title_screen_update( unsigned char *screen_type )
{
	struct_hack_object *ho = &global_hack_object;
	struct_game_object *go = &global_game_object;
	unsigned char input;
	unsigned char timer;

	engine_random_manager_rand();
	if( event_stage_pause == event_stage )
	{
		timer = engine_timer_manager_update();
		if( timer )
		{
			*screen_type = screen_type_diff;
			return;
		}
	}
	else
	{
		if( first_time )
		{
			first_time = 0;
			if( go->play_music )
			{
				// Play intro music.
				engine_music_manager_intro();
			}

			engine_text_manager_cont();
		}

		// Navigate to hidden credits screen.
		input = engine_input_manager_hold_buttonB();
		if( input )
		{
			engine_audio_manager_stop();
			*screen_type = screen_type_credit;
			return;
		}

		engine_random_manager_rand();
		timer = engine_timer_manager_update();
		if( timer )
		{
			if( !ho->hack_delays )
			{
				flash_count = 1 - flash_count;
			}

			if( flash_count )
			{
				engine_font_manager_draw_char( LOCALE_1_SPCS, LEFT_X + 15, TOP_Y + 21 );
			}
			else
			{
				engine_text_manager_one();
			}
		}

		input = engine_input_manager_hold_buttonA();
		if( input )
		{
			engine_text_manager_one();
			engine_timer_manager_load( TITLE_SOUND_DELAY );

			engine_audio_manager_stop();
			if( !ho->hack_delays )
			{
				engine_audio_manager_play_sound( sound_type_5 );
			}

			event_stage = event_stage_pause;
		}

		engine_random_manager_rand();
	}

	*screen_type = screen_type_title;
}
