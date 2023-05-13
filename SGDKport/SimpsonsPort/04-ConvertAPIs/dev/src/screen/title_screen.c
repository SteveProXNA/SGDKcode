#include "title_screen.h"
#include "../engine/audio_manager.h"
#include "../engine/enum_manager.h"
#include "../engine/font_manager.h"
#include "../engine/graphics_manager.h"
#include "../engine/global_manager.h"
#include "../engine/image_manager.h"
#include "../engine/locale_manager.h"
#include "../engine/random_manager.h"
#include "../engine/timer_manager.h"

static unsigned char screen_title_screen_delay;

void screen_title_screen_init()
{
	screen_title_screen_delay = NORMAL_DELAY;
}

void screen_title_screen_load()
{
	engine_graphics_manager_clear_full();
	engine_image_manager_draw_title();

	screen_bases_screen_init();
	engine_font_manager_text( LOCALE_VERSION, 35, 26 );

	engine_audio_manager_play_music( music_type_simpsons );
}

void screen_title_screen_update( unsigned char *screen_type )
{
	screen_bases_screen_timer++;
	if( screen_bases_screen_timer >= screen_title_screen_delay )
	{
		*screen_type = screen_type_intro;
		return;
	}

	engine_random_manager_rand();
	*screen_type = screen_type_title;
}
