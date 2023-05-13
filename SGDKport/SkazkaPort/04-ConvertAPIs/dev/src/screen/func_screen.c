#include "func_screen.h"
#include "enum_manager.h"
#include "font_manager.h"
#include "hack_manager.h"

void screen_func_screen_load()
{
	struct_hack_object *ho = &global_hack_object;
	engine_font_manager_draw_text( "FUNC SCREEN!!", 10, 0 );
	
	engine_font_manager_draw_data( ho->hack_delays, 10, 4 );
	engine_font_manager_draw_data( ho->hack_nodead, 10, 5 );

	engine_font_manager_draw_data( ho->hack_currxp, 10, 10 );
	engine_font_manager_draw_data( ho->hack_currhp, 10, 11 );
	engine_font_manager_draw_data( ho->hack_goldno, 10, 12 );
	engine_font_manager_draw_data( ho->hack_weapon, 10, 13 );
	engine_font_manager_draw_data( ho->hack_armors, 10, 14 );

	engine_font_manager_draw_data( ho->hack_oneups, 10, 20 );
	engine_font_manager_draw_data( ho->hack_talker, 10, 21 );
	engine_font_manager_draw_data( ho->hack_musics, 10, 22 );
	engine_font_manager_draw_data( ho->hack_sounds, 10, 23 );
}

void screen_func_screen_update( unsigned char *screen_type )
{
	*screen_type = screen_type_func;
}
