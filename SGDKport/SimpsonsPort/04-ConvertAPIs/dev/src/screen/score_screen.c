#include "score_screen.h"
#include "../engine/enum_manager.h"
#include "../engine/font_manager.h"
#include "../engine/function_manager.h"
#include "../engine/input_manager.h"
#include "../engine/locale_manager.h"
#include "../engine/quiz_manager.h"
#include "../engine/score_manager.h"
#include "../engine/select_manager.h"

// IMPORTANT disable compiler warning 4244
#ifdef _CONSOLE
#pragma warning( disable : 4244 ) 
#endif

void screen_score_screen_load()
{
	unsigned short percent = engine_function_manager_calculate_percentage( score_player, question_count );
	engine_select_manager_clear2();

	engine_font_manager_text( LOCALE_FIRE2, 4, 23 );
	engine_font_manager_text( LOCALE_FIRE1, 4, 24 );

	engine_font_manager_text( LOCALE_STATISTICS, INFO_SUMMARY_X, TITLE_Y );
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
}

void screen_score_screen_update( unsigned char *screen_type )
{
	unsigned char input = 0;

	input = engine_input_manager_hold_fire2();
	if( input )
	{
		engine_select_manager_clear2();
		*screen_type = screen_type_play;
		return;
	}

	input = engine_input_manager_hold_fire1();
	if( input )
	{
		*screen_type = screen_type_over;
		return;
	}

	*screen_type = screen_type_score;
}
