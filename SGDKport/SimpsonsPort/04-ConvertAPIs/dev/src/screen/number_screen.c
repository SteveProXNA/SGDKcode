#include "number_screen.h"
#include "../engine/actor_manager.h"
#include "../engine/enum_manager.h"
#include "../engine/graphics_manager.h"

void screen_number_screen_load()
{
	engine_graphics_manager_clear_full();
	engine_actor_manager_load();
}

void screen_number_screen_update( unsigned char *screen_type )
{
	*screen_type = screen_type_play;
}
