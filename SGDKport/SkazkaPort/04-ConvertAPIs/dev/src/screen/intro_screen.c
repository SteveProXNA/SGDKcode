#include "intro_screen.h"
#include "enum_manager.h"
#include "font_manager.h"
#include "game_manager.h"
#include "global_manager.h"
#include "graphics_manager.h"
#include "input_manager.h"
#include "locale_manager.h"
#include "random_manager.h"
#include "text_manager.h"
#include "timer_manager.h"
#include "fixedbank.h"

#define INTRO_SCREEN_DELAY		900

void screen_intro_screen_load()
{
	unsigned char row;
	unsigned char idx;

	engine_graphics_manager_draw_border();
	engine_graphics_manager_clear_part();

	engine_graphics_manager_draw_logo_big( LEFT_X + 2, TOP_Y + 3 );

	row = 10;
	for( idx = 0; idx < 10; idx++ )
	{
		engine_font_manager_draw_text( ( char * ) intro_texts[ idx ], LEFT_X + 2, TOP_Y + row );
		row++;
	}

	engine_graphics_manager_draw_border();
	engine_text_manager_cont();

	engine_font_manager_draw_punc( LOCALE_STOP, LEFT_X + 25, TOP_Y + 13 );
	engine_font_manager_draw_punc( LOCALE_STOP, LEFT_X + 27, TOP_Y + 16 );
	engine_font_manager_draw_punc( LOCALE_STOP, LEFT_X + 16, TOP_Y + 19 );

	engine_timer_manager_load( INTRO_SCREEN_DELAY );
	engine_game_manager_flash_on();
}

void screen_intro_screen_update( unsigned char *screen_type )
{
	unsigned char input;
	unsigned char timer;

	input = engine_input_manager_hold_buttonA();
	timer = engine_timer_manager_update();

	if( input || timer )
	{
		*screen_type = screen_type_load;
		return;
	}

	engine_random_manager_rand();
	*screen_type = screen_type_intro;
}
