#include "shop_screen.h"
#include "audio_manager.h"
#include "enum_manager.h"
#include "font_manager.h"
#include "game_manager.h"
#include "global_manager.h"
#include "graphics_manager.h"
#include "hack_manager.h"
#include "input_manager.h"
#include "locale_manager.h"
#include "player_manager.h"
#include "select_manager.h"
#include "timer_manager.h"
#include "text_manager.h"
#include "fixedbank.h"

#define SHOP_SCREEN_DELAY1	50

static unsigned char event_stage;
static unsigned char select_type;
static unsigned char gold;

unsigned char inventory[ MAX_ITEMS ] = { 10, 20, 10, 20, 30 };

void screen_shop_screen_load()
{
	struct_player_object *po = &global_player_object;
	unsigned char row;
	unsigned char idx;
	gold = po->gold;

	select_type = select_type_shop;

	engine_graphics_manager_draw_border();
	engine_graphics_manager_clear_part();

	engine_graphics_manager_draw_logo_small( LEFT_X + 1, TOP_Y + 1 );
	engine_graphics_manager_draw_underline( TOP_Y + 4 );

	row = 7;
	for( idx = 0; idx < 8; idx++ )
	{
		engine_font_manager_draw_text( ( char * ) shop_texts[ idx ], LEFT_X + 9, TOP_Y + row );
		row++;
	}
	row = 10;
	for( idx = 0; idx < MAX_ITEMS; idx++ )
	{
		engine_font_manager_draw_data( inventory[ idx ], LEFT_X + 24, TOP_Y + row++ );
	}

	row = 10;
	engine_select_manager_load( select_type, LEFT_X + 7, TOP_Y + row, 5 );

	engine_font_manager_draw_text( LOCALE_SHOP_QUERY, LEFT_X + 7, TOP_Y + 17 );
	engine_font_manager_draw_punc( LOCALE_QMARK, LEFT_X + 24, TOP_Y + 17 );
	engine_font_manager_draw_text( LOCALE_YOU_HAVE, LEFT_X + 7, TOP_Y + 19 );
	engine_font_manager_draw_data( gold, LEFT_X + 24, TOP_Y + 19 );

	engine_timer_manager_load( SHOP_SCREEN_DELAY1 );
	event_stage = event_stage_start;
}

void screen_shop_screen_update( unsigned char *screen_type )
{
	struct_hack_object *ho = &global_hack_object;
	unsigned char input;
	unsigned char value;
	unsigned char timer;
	unsigned char selection;

	if( event_stage_pause == event_stage )
	{
		timer = engine_timer_manager_update();
		if( timer )
		{
			*screen_type = screen_type_stats;
			return;
		}
	}
	else
	{
		input = engine_input_manager_hold_buttonB();
		if( input )
		{
			if( !engine_audio_manager_is_playing() )
			{
				*screen_type = screen_type_stats;
				return;
			}
		}

		selection = engine_select_manager_update( select_type );
		if( NO_SELECTION == selection )
		{
			*screen_type = screen_type_shop;
			return;
		}

		// Check edge case "Not enough gold" SFX!
		if( engine_audio_manager_is_playing() )
		{
			*screen_type = screen_type_shop;
			return;
		}

		value = inventory[ selection ];
		if( value > gold )
		{
			engine_audio_manager_play_sound( sound_type_6 );
			engine_font_manager_draw_text( LOCALE_NOT_ENOUGH, LEFT_X + 8, TOP_Y + 21 );
			engine_font_manager_draw_punc( LOCALE_POINT, LEFT_X + 23, TOP_Y + 21 );
			*screen_type = screen_type_shop;
			return;
		}

		if( shop_type_sword == selection )
		{
			engine_player_manager_set_weapon( weapon_type_sword );
		}
		else if( shop_type_axe == selection )
		{
			engine_player_manager_set_weapon( weapon_type_axe );
		}
		else if( shop_type_kolchuga == selection )
		{
			engine_player_manager_set_armors( armor_type_kolchuga );
		}
		else if( shop_type_tegilay == selection )
		{
			engine_player_manager_set_armors( armor_type_tegilay );
		}
		else if( shop_type_life == selection )
		{
			engine_player_manager_set_oneups( life_type_oneup );
		}

		gold -= value;
		engine_player_manager_dec_gold( value );

		engine_font_manager_draw_text( LOCALE_30_SPCS, LEFT_X + 1, TOP_Y + 21 );
		engine_font_manager_draw_data( gold, LEFT_X + 24, TOP_Y + 19 );

		if( !ho->hack_delays )
		{
			engine_audio_manager_play_sound( sound_type_5 );
		}

		event_stage = event_stage_pause;
	}

	*screen_type = screen_type_shop;
}
