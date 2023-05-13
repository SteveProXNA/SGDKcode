#include "ready_screen.h"
#include "../engine/audio_manager.h"
#include "../engine/enum_manager.h"
#include "../engine/font_manager.h"
#include "../engine/global_manager.h"
#include "../engine/input_manager.h"
#include "../engine/locale_manager.h"
#include "../engine/quiz_manager.h"
#include "../engine/random_manager.h"
#include "../engine/score_manager.h"
#include "../engine/select_manager.h"
#include "../engine/timer_manager.h"

// Dots.
#define DOTS_X				7
#define DOTS_Y				23

static unsigned int screen_ready_screen_delay;
static unsigned char screen_ready_screen_delay2;
static unsigned char screen_bases_screen_timer2;
static unsigned char screen_ready_screen_dots;
static unsigned char first_time;

void screen_ready_screen_init()
{
	screen_ready_screen_delay = TITLE_DELAY + SPLASH_DELAY;
	screen_ready_screen_delay2 = NORMAL_DELAY;
}

void screen_ready_screen_load()
{
	screen_bases_screen_init();

	// Clear space.
	engine_select_manager_clear3();

	engine_font_manager_text( LOCALE_SUMMARY, 3, 6 );

	engine_font_manager_text( LOCALE_DIFFICULTY, 3, 10 );
	engine_font_manager_text( LOCALE_ARROW_LEFT, 2, 11 );
	engine_font_manager_text( select_diff_option[ diff_select ], 3, 11 );

	engine_font_manager_text( LOCALE_QUESTIONS, 3, 16 );
	engine_font_manager_text( LOCALE_ARROW_LEFT, 2, 17 );
	engine_font_manager_data( question_long, 5, 17 );

	engine_font_manager_text( LOCALE_GET, 3, 22 );
	engine_font_manager_text( LOCALE_READY, 3, 23 );

	// Initialize all relevant variables before quiz starts...
	question_index = 0;
	question_value = 0;
	question_count = 0;
	engine_score_manager_init();

	screen_bases_screen_timer2 = 0;
	screen_ready_screen_dots = 0;
	first_time = 0;
}

void screen_ready_screen_update( unsigned char *screen_type )
{
	unsigned char input = 0;
	unsigned char level = 0;

	engine_random_manager_rand();
	input = engine_input_manager_hold_fire2();
	if( input )
	{
		// Clean up.
		engine_font_manager_text( LOCALE_BLANK11, 2, 10 );
		engine_font_manager_text( LOCALE_BLANK11, 1, 11 );
		engine_font_manager_text( LOCALE_BLANK11, 1, 16 );
		engine_font_manager_text( LOCALE_BLANK11, 1, 17 );
		engine_font_manager_text( LOCALE_BLANK11, 0, 22 );
		engine_font_manager_text( LOCALE_BLANK11, 0, 23 );

		*screen_type = screen_type_long;
		return;
	}
	input = engine_input_manager_hold_fire1();
	if( input )
	{
		level = 1;
	}

	// Moving dots "animation".
	screen_bases_screen_timer2++;
	if( screen_bases_screen_timer2 >= screen_ready_screen_delay2 )
	{
		screen_ready_screen_dots++;
		if( screen_ready_screen_dots == 3 )
		{
			if( !first_time )
			{
				first_time = 1;
				engine_audio_manager_play_effect( effect_type_ready );
			}
		}

		if( screen_ready_screen_dots <= 3 )
		{
			engine_font_manager_text( LOCALE_DOT, DOTS_X + screen_ready_screen_dots, DOTS_Y );
		}

		screen_bases_screen_timer2 = 0;
	}

	screen_bases_screen_timer++;
	if( screen_bases_screen_timer >= screen_ready_screen_delay )
	{
		level = 1;
	}

	if( level )
	{
		engine_audio_manager_stop();

		*screen_type = screen_type_level;
		return;
	}

	*screen_type = screen_type_ready;
}
