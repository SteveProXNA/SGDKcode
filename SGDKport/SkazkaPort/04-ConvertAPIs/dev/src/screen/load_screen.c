#include "load_screen.h"
#include "enum_manager.h"
#include "game_manager.h"
#include "player_manager.h"
#include "select_manager.h"

void screen_load_screen_load()
{
	engine_player_manager_load();
	engine_player_manager_calc();

	engine_select_manager_once();
}

void screen_load_screen_update( unsigned char *screen_type )
{
	struct_game_object *go = &global_game_object;
	unsigned char flash_arrow = go->flash_arrow;

	if( flash_arrow )
	{
		*screen_type = screen_type_start;
		return;
	}

	*screen_type = screen_type_stats;
}
