#include "select_manager.h"
#include "font_manager.h"
#include "global_manager.h"
#include "locale_manager.h"
#include "sprite_manager.h"

unsigned char diff_select, long_select, quiz_select;
unsigned char select_choice, select_height;
unsigned char select_option[ MAX_OPTIONS ];

unsigned char select_high_option[ MAX_OPTIONS ] = { OPTA_Y, OPTB_Y, OPTC_Y, OPTD_Y };
unsigned char select_text_option[ MAX_OPTIONS ][ 3 ] = { LOCALE_OPTA, LOCALE_OPTB, LOCALE_OPTC, LOCALE_OPTD };
unsigned char select_diff_option[ MAX_OPTIONS ][ 6 ] = { LOCALE_DIFF_OPT1, LOCALE_DIFF_OPT2, LOCALE_DIFF_OPT3, LOCALE_DIFF_OPT4 };
unsigned char select_long_option[ MAX_OPTIONS ] = { LOCALE_LONG_OPT1, LOCALE_LONG_OPT2, LOCALE_LONG_OPT3, LOCALE_LONG_OPT4 };


#define ANSWER_X		16
#define SELECT_X		20	//4
#define SELECT_Y		76	//60
#define SELECT_DELTA	32


void engine_select_manager_init()
{
	unsigned char idx = 0;
	for( idx = 0; idx < MAX_OPTIONS; idx++ )
	{
		select_option[ idx ] = SELECT_Y + idx * SELECT_DELTA;
	}

	diff_select = 0;		// Select difficulty option.
	long_select = 0;		// Number questions option.
	quiz_select = 0;		// Last questions selected.
	select_choice = 0;		// Variable that remembers.
	select_height = select_option[ select_choice ];
}

void engine_select_manager_base()
{
	unsigned char idx;
	for( idx = 0; idx < MAX_OPTIONS; idx++ )
	{
		engine_font_manager_text( select_text_option[ idx ], QUIZ_X, select_high_option[ idx ] );
	}
}

void engine_select_manager_clear2()
{
	unsigned char high;
	for( high = 4; high < 9; high++ )
	{
		engine_font_manager_text( LOCALE_BLANK, 4, high );
	}
	for( high = 9; high < 27; high++ )
	{
		engine_font_manager_text( LOCALE_BLANK22, 4, high );
	}
}
void engine_select_manager_clear3()
{
	unsigned char idx;
	for( idx = 0; idx < MAX_OPTIONS; idx++ )
	{
		engine_font_manager_text( LOCALE_BLANK5, QUIZ_X, select_high_option[ idx ] );
	}
}
void engine_select_manager_load_diff()
{
	unsigned char idx;
	for( idx = 0; idx < MAX_OPTIONS; idx++ )
	{
		engine_font_manager_text( select_diff_option[ idx ], QUIZ_X + 2, select_high_option[ idx ] );
	}

	select_choice = diff_select;
	select_height = select_option[ select_choice ];
}
void engine_select_manager_load_long()
{
	unsigned char idx;
	for( idx = 0; idx < MAX_OPTIONS; idx++ )
	{
		engine_font_manager_data( select_long_option[ idx ], QUIZ_X + LONG_DELTA, select_high_option[ idx ] );
		engine_font_manager_text( LOCALE_ARROW_SPACE, QUIZ_X + LONG_DELTA + 1, select_high_option[ idx ] );
	}

	select_choice = long_select;
	select_height = select_option[ select_choice ];
}

void engine_select_manager_load_quiz()
{
	quiz_select = 0;
	select_choice = quiz_select;
	select_height = select_option[ select_choice ];
}

unsigned char engine_select_manager_move_up( unsigned char select_choice )
{
	if( 0 == select_choice )
	{
		select_choice = ( MAX_OPTIONS - 1 );
	}
	else
	{
		select_choice--;
	}

	select_height = select_option[ select_choice ];
	return select_choice;
}

unsigned char engine_select_manager_move_down( unsigned char select_choice )
{
	if( ( MAX_OPTIONS - 1 ) == select_choice )
	{
		select_choice = 0;
	}
	else
	{
		select_choice++;
	}

	select_height = select_option[ select_choice ];
	return select_choice;
}

void engine_select_manager_draw_chose()
{
	engine_sprite_manager_draw_chose( SELECT_X, select_height );
}
void engine_select_manager_draw_right()
{
	engine_sprite_manager_draw_right( ANSWER_X + 4, select_height + 0 );
}
void engine_select_manager_draw_wrong()
{
	engine_sprite_manager_draw_wrong( ANSWER_X, select_height + 4 );
}