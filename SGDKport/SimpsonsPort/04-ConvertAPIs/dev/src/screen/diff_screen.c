#include "diff_screen.h"
#include "../engine/audio_manager.h"
#include "../engine/enum_manager.h"
#include "../engine/font_manager.h"
#include "../engine/global_manager.h"
#include "../engine/input_manager.h"
#include "../engine/locale_manager.h"
#include "../engine/random_manager.h"
#include "../engine/select_manager.h"
#include "../engine/sprite_manager.h"
#include "../engine/timer_manager.h"

static unsigned char screen_diff_screen_delay;
static unsigned char screen_diff_screen_state;

void screen_diff_screen_init()
{
	screen_diff_screen_delay = NORMAL_DELAY;
}

void screen_diff_screen_load()
{
	screen_bases_screen_init();
	screen_diff_screen_state = select_type_before;

	engine_font_manager_text( LOCALE_BLANK5, 4, 13 );
	engine_font_manager_text( LOCALE_BLANK5, 4, 14 );

	engine_select_manager_base();
	engine_font_manager_text( LOCALE_DIFFICULTY, 3, 6 );
	engine_select_manager_load_diff();
}

void screen_diff_screen_update( unsigned char *screen_type )
{
	unsigned char input = 0;
	engine_random_manager_rand();
	engine_sprite_manager_update();

	if( select_type_before == screen_diff_screen_state )
	{
		engine_select_manager_draw_chose();
		input = engine_input_manager_hold_up();
		if( input )
		{
			diff_select = engine_select_manager_move_up( diff_select );
		}

		input = engine_input_manager_hold_down();
		if( input )
		{
			diff_select = engine_select_manager_move_down( diff_select );
		}

		// IMPORTANT - don't allow to go back here as invalidates cheat mode!
		input = engine_input_manager_hold_fire1();
		if( input )
		{
			engine_audio_manager_play_effect( effect_type_right );
			screen_diff_screen_state = select_type_after;
		}
	}

	if( select_type_after == screen_diff_screen_state )
	{
		engine_font_manager_text( LOCALE_BLANK3, QUIZ_X - 1, select_high_option[ diff_select ] );
		engine_sprite_manager_hide( sprite_type_chose );

		engine_select_manager_draw_right();
		engine_sprite_manager_update();

		screen_bases_screen_timer++;
		if( screen_bases_screen_timer >= screen_diff_screen_delay )
		{
			engine_sprite_manager_hide( sprite_type_right );
			engine_sprite_manager_update();

			*screen_type = screen_type_long;
			return;
		}
	}

	engine_sprite_manager_update();
	*screen_type = screen_type_diff;
}
