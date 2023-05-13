#include "over_screen.h"
#include "../engine/audio_manager.h"
#include "../engine/enum_manager.h"
#include "../engine/font_manager.h"
#include "../engine/function_manager.h"
#include "../engine/global_manager.h"
#include "../engine/input_manager.h"
#include "../engine/locale_manager.h"
#include "../engine/quiz_manager.h"
#include "../engine/score_manager.h"
#include "../engine/select_manager.h"
#include "../engine/timer_manager.h"

// IMPORTANT disable compiler warning 4244
#ifdef _CONSOLE
#pragma warning( disable : 4244 ) 
#endif

static unsigned char screen_over_screen_delay1;
static unsigned int screen_over_screen_delay2;

void screen_over_screen_init()
{
	screen_over_screen_delay1 = TITLE_DELAY * 2;
	screen_over_screen_delay2 = TITLE_DELAY * 8;
}

void screen_over_screen_load()
{
	unsigned short percent = engine_function_manager_calculate_percentage( score_player, question_count );
	screen_bases_screen_init();

	engine_font_manager_text( LOCALE_BLANK, 2, 4 );
	engine_font_manager_text( LOCALE_OVER_MSG1, 4, 23 );
	engine_font_manager_text( LOCALE_OVER_MSG2, 4, 24 );

	engine_font_manager_text( LOCALE_UNDERLINED, INFO_SUMMARY_X, TITLE_Y - 1 );
	engine_font_manager_text( LOCALE_COMPLETION, INFO_SUMMARY_X, TITLE_Y + 0 );
	engine_font_manager_text( LOCALE_UNDERLINED, INFO_SUMMARY_X, TITLE_Y + 1 );

	engine_font_manager_text( LOCALE_QUIZ_TOTAL, SUMMARY_TEXT_X, 7 );
	engine_font_manager_zero( question_long, SUMMARY_DATA_X, 8 );

	engine_font_manager_text( LOCALE_QUIZ_SOLVE, SUMMARY_TEXT_X, 11 );
	engine_font_manager_zero( question_count, SUMMARY_DATA_X, 12 );

	engine_font_manager_text( LOCALE_QUIZ_RIGHT, SUMMARY_TEXT_X, 15 );
	engine_font_manager_zero( score_player, SUMMARY_DATA_X, 16 );

	// Allow for potential division by zero error.
	engine_font_manager_text( LOCALE_CURR_PERCENT, SUMMARY_TEXT_X, 19 );
	engine_font_manager_zero( percent, SUMMARY_DATA_X, 20 );
	engine_font_manager_text( LOCALE_PERCENT_SYM, SUMMARY_DATA_X + 1, 20 );

	// Remove arrow if in cheat mode.
	if( local_cheat )
	{
		engine_font_manager_text( LOCALE_BLANK3, QUIZ_X - 3, select_high_option[ answer_index ] );
	}

	engine_audio_manager_play_music( music_type_gameover );
}

void screen_over_screen_update( unsigned char *screen_type )
{
	unsigned char input = 0;
	unsigned char level = 0;

	screen_bases_screen_timer++;
	if( screen_bases_screen_timer < screen_over_screen_delay1 )
	{
		return;
	}

	input = engine_input_manager_hold_fire1();
	if( input )
	{
		level = 1;
	}

	screen_bases_screen_timer++;
	if( screen_bases_screen_timer >= screen_over_screen_delay2 )
	{
		level = 1;
	}

	if( level )
	{
		*screen_type = screen_type_title;
		return;
	}

	*screen_type = screen_type_over;
}
