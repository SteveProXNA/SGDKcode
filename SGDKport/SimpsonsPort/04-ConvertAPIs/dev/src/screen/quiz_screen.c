#include "quiz_screen.h"
#include "../engine/audio_manager.h"
#include "../engine/enum_manager.h"
#include "../engine/font_manager.h"
#include "../engine/global_manager.h"
#include "../engine/input_manager.h"
#include "../engine/locale_manager.h"
#include "../engine/quiz_manager.h"
#include "../engine/score_manager.h"
#include "../engine/select_manager.h"
#include "../engine/sprite_manager.h"
#include "../engine/timer_manager.h"

static unsigned char screen_quiz_screen_delay;
static unsigned char screen_quiz_screen_state;
static unsigned char firstTime;

void screen_quiz_screen_init()
{
	screen_quiz_screen_delay = NORMAL_DELAY * 2;
}

void screen_quiz_screen_load()
{
	question_count++;
	screen_bases_screen_init();

	if( quiz_select == answer_index )
	{
		screen_quiz_screen_state = answer_type_right;
	}
	else
	{
		screen_quiz_screen_state = answer_type_wrong;
	}

	// Remove letter beneath answer sprite.
	engine_font_manager_text( LOCALE_BLANK5, QUIZ_X - 3, select_high_option[ quiz_select ] );
	firstTime = 0;
}

void screen_quiz_screen_update( unsigned char *screen_type )
{
	// Logic: display right or wrong sprite for delay.
	// Increment question counter
	// After the delay check this
	// if all questions answered then game over
	// otherwise then resume next question

	unsigned char input = 0;
	unsigned char level = 0;

	engine_sprite_manager_update();

	// Stagger logic over frames 1, 2, and 3+.
	firstTime++;
	if( 2 == firstTime )
	{
		if( answer_type_right == screen_quiz_screen_state )
		{
			engine_score_manager_update();
			engine_audio_manager_sound_woohoo();
		}
		else
		{
			engine_audio_manager_sound_doh();
		}

		firstTime = 3;
	}

	if( firstTime >= 3)
	{
		input = engine_input_manager_hold_fire1();
		if( input )
		{
			level = 1;
		}

		screen_bases_screen_timer++;
		if( screen_bases_screen_timer >= screen_quiz_screen_delay )
		{
			level = 1;
		}

		if( level )
		{
			engine_sprite_manager_hide( sprite_type_right );
			engine_sprite_manager_hide( sprite_type_wrong );
			engine_sprite_manager_update();

			question_index++;
			if( question_index >= question_long )
			{
				engine_select_manager_clear2();
				*screen_type = screen_type_over;
				return;
			}

			// OLD
			//*screen_type = screen_type_play;

			// NEW
			*screen_type = screen_type_number;
			return;
		}
	}

	if( answer_type_right == screen_quiz_screen_state )
	{
		engine_select_manager_draw_right();
	}
	else
	{
		engine_select_manager_draw_wrong();
	}

	engine_sprite_manager_update();
	*screen_type = screen_type_quiz;
}
