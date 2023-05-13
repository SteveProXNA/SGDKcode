#include "splash_screen.h"
#include "enum_manager.h"
#include "global_manager.h"
#include "graphics_manager.h"
#include "input_manager.h"
#include "timer_manager.h"

#define SPLASH_SCREEN_DELAY		250

void screen_splash_screen_load()
{
	engine_graphics_manager_draw_splash();
	engine_graphics_manager_draw_borderX( 0, 0, OUTER_WIDE, OUTER_HIGH );

	engine_timer_manager_load( SPLASH_SCREEN_DELAY );
}

void screen_splash_screen_update( unsigned char *screen_type )
{
	unsigned char input;
	unsigned char timer;

	input = engine_input_manager_hold_buttonA();
	timer = engine_timer_manager_update();
	if( input || timer )
	{
		*screen_type = screen_type_title;
		return;
	}

	*screen_type = screen_type_splash;
}
