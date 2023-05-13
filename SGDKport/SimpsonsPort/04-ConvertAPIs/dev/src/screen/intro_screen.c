#include "intro_screen.h"
#include "../engine/audio_manager.h"
#include "../engine/enum_manager.h"
#include "../engine/font_manager.h"
#include "../engine/global_manager.h"
#include "../engine/hack_manager.h"
#include "../engine/input_manager.h"
#include "../engine/locale_manager.h"
#include "../engine/random_manager.h"
#include "../engine/select_manager.h"
#include "../engine/timer_manager.h"

static unsigned char screen_intro_screen_delay;
static unsigned char cheat_count;

void screen_intro_screen_init()
{
	screen_intro_screen_delay = NORMAL_DELAY;
}

void screen_intro_screen_load()
{
	local_cheat = 0;
	cheat_count = 0;
	screen_bases_screen_init();

	engine_font_manager_text( LOCALE_PRESS, 4, 13 );
	engine_font_manager_text( LOCALE_START, 4, 14 );

	if( hacker_cheat )
	{
		engine_font_manager_text( LOCALE_CHEAT, 29, 10 );
		engine_font_manager_text( LOCALE_MODE, 29, 11 );

		engine_audio_manager_play_effect( effect_type_cheat );
		local_cheat = 1;
	}
}

void screen_intro_screen_update( unsigned char *screen_type )
{
	unsigned char input = 0;
	unsigned char input2 = 0;
	screen_bases_screen_timer++;
	if( screen_bases_screen_timer >= screen_intro_screen_delay )
	{
		if( screen_bases_screen_count )
		{
			engine_font_manager_text( LOCALE_PRESS, 4, 13 );
			engine_font_manager_text( LOCALE_START, 4, 14 );
		}
		else
		{
			engine_font_manager_text( LOCALE_BLANK5, 4, 13 );
			engine_font_manager_text( LOCALE_BLANK5, 4, 14 );
		}

		screen_bases_screen_count = !screen_bases_screen_count;
		screen_bases_screen_timer = 0;
	}

	input = engine_input_manager_hold_fire1();
	input2 = engine_input_manager_hold_buttonStart();
	if( input || input2 )
	{
		engine_audio_manager_play_effect( effect_type_right );
		*screen_type = screen_type_diff;
		return;
	}

	if( !hacker_cheat && !local_cheat )
	{
		input = engine_input_manager_hold_fire2();
		if( input )
		{
			cheat_count++;
			if( cheat_count >= CHEAT_TOTAL )
			{
				engine_font_manager_text( LOCALE_CHEAT, 29, 10 );
				engine_font_manager_text( LOCALE_MODE, 29, 11 );

				engine_audio_manager_play_effect( effect_type_cheat );
				local_cheat = 1;
			}
		}
	}

	engine_random_manager_rand();
	*screen_type = screen_type_intro;
}
