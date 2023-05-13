#include "level_screen.h"
#include "../engine/debug_manager.h"
#include "../engine/enum_manager.h"
#include "../engine/random_manager.h"
#include "../engine/select_manager.h"

void screen_level_screen_load()
{
	// Process this here just before quiz starts
	// Why?  Otherwise may cause music to "drag"
	engine_random_manager_init();
	engine_random_manager_load();

	engine_select_manager_load_quiz();
	engine_debug_manager_init();
}

void screen_level_screen_update( unsigned char *screen_type )
{
	*screen_type = screen_type_number;
}
