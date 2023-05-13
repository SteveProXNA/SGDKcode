#include "victory_screen.h"
#include "audio_manager.h"
#include "enum_manager.h"
#include "font_manager.h"
#include "game_manager.h"
#include "global_manager.h"
#include "graphics_manager.h"
#include "input_manager.h"
#include "locale_manager.h"
#include "player_manager.h"
#include "text_manager.h"
#include "timer_manager.h"
#include "fixedbank.h"

void screen_victory_screen_load()
{
	struct_player_object *po = &global_player_object;
	unsigned char row;
	unsigned char idx;

	engine_graphics_manager_draw_border();
	engine_graphics_manager_clear_part();

	engine_graphics_manager_draw_logo_small( LEFT_X + 1, TOP_Y + 1 );
	engine_graphics_manager_draw_underline();

	row = 9;
	for( idx = 0; idx < 4; idx++ )
	{
		engine_font_manager_draw_text( ( char * ) gold_texts[ idx ], LEFT_X + 7, TOP_Y + row );
		row++;
	}

	engine_font_manager_draw_punc( LOCALE_POINT, LEFT_X + 19, TOP_Y + 9 );
	engine_font_manager_draw_punc( LOCALE_HYPHEN, LEFT_X + 20, TOP_Y + 12 );
	engine_font_manager_draw_data( po->won, LEFT_X + 24, TOP_Y + 12 );
	engine_text_manager_cont();

	engine_audio_manager_play_sound( sound_type_7 );
}

void screen_victory_screen_update( unsigned char *screen_type )
{
	unsigned char input1 = engine_input_manager_hold_buttonA();
	unsigned char input2 = engine_input_manager_hold_buttonB();

	if( input1 || input2 )
	{
		if( !engine_audio_manager_is_playing() )
		{
			*screen_type = screen_type_stats;
			return;
		}
	}

	*screen_type = screen_type_victory;
}
