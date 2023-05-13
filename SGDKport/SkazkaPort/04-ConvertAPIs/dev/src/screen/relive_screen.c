#include "relive_screen.h"
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

#define RELIVE_SCREEN_DELAY		30

static unsigned char count;

void screen_relive_screen_load()
{
	engine_graphics_manager_draw_border();
	engine_graphics_manager_clear_part();

	engine_graphics_manager_draw_logo_small( LEFT_X + 1, TOP_Y + 1 );
	engine_graphics_manager_draw_underline( TOP_Y + 4 );

	engine_font_manager_draw_text( LOCALE_REVITALISING, LEFT_X + 9, TOP_Y + 12 );
	engine_timer_manager_load( RELIVE_SCREEN_DELAY );
	count = 0;
}

void screen_relive_screen_update( unsigned char *screen_type )
{
	unsigned char timer;
	timer = engine_timer_manager_update();
	if( timer )
	{
		engine_timer_manager_load( RELIVE_SCREEN_DELAY );
		if( count == 0 || count == 2 )
		{
			engine_audio_manager_play_sound( sound_type_9 );
		}

		if( count < 3 )
		{
			engine_font_manager_draw_punc( LOCALE_STOP, LEFT_X + 21 + count, TOP_Y + 12 );
		}

		count++;
		if( count > 3 )
		{
			// Replenish HP and remove +1.
			if( !engine_audio_manager_is_playing() )
			{
				engine_player_manager_rest();
				engine_player_manager_set_oneups( life_type_none );
				*screen_type = screen_type_stats;
				return;
			}
		}
	}

	*screen_type = screen_type_relive;
}
