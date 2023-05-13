#include "credit_screen.h"
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

#define CREDIT_SCREEN_DELAY		500
static void display();

void screen_credit_screen_load()
{
	engine_graphics_manager_draw_border();
	engine_graphics_manager_clear_part();

	engine_graphics_manager_draw_logo_big( LEFT_X + 2, TOP_Y + 3 );
	engine_font_manager_draw_text( LOCALE_CREDITS, LEFT_X + 12, TOP_Y + 10 );
	display();

	engine_graphics_manager_draw_border();
	engine_text_manager_cont();
	engine_timer_manager_load( CREDIT_SCREEN_DELAY );
}

void screen_credit_screen_update( unsigned char *screen_type )
{
	unsigned char input1;
	unsigned char input2;
	unsigned char timer;

	input1 = engine_input_manager_hold_buttonA();
	input2 = engine_input_manager_hold_buttonB();
	timer = engine_timer_manager_update();
	if( input1 || input2 || timer )
	{
		engine_game_manager_music_off();
		*screen_type = screen_type_title;
		return;
	}

	*screen_type = screen_type_credit;
}

static void display()
{
	unsigned char row;
	unsigned char idx;

	unsigned char x1;
	unsigned char x2;

	x1 = 4;
	x2 = 4 + 12 + 4;

	row = 13;
	for( idx = 0; idx < 12; idx += 2 )
	{
		engine_font_manager_draw_text( ( char * ) credit_texts[ idx + 0 ], LEFT_X + x1, TOP_Y + row );
		engine_font_manager_draw_text( ( char * ) credit_texts[ idx + 1 ], LEFT_X + x2, TOP_Y + row );
		row++;
	}

	engine_font_manager_draw_numb( 2, LEFT_X + 28, TOP_Y + 22 );
	engine_font_manager_draw_punc( LOCALE_STOP, LEFT_X + 29, TOP_Y + 22 );
	engine_font_manager_draw_numb( 0, LEFT_X + 30, TOP_Y + 22 );
}