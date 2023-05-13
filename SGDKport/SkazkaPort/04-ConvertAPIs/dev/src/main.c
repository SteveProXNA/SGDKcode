#include "main.h"

int main()
{
	unsigned char open_screen_type;

	open_screen_type = screen_type_splash;
	//open_screen_type = screen_type_title;

	// Initialize player first!
	engine_player_manager_init();
	engine_hack_manager_init();
	engine_hack_manager_load();
	engine_hack_manager_invert();

	engine_enemy_manager_init();
	engine_game_manager_init();
	engine_audio_manager_init();

	engine_graphics_manager_init();
	engine_graphics_manager_load();
	engine_graphics_manager_clear_full();

	engine_select_manager_init();
	engine_screen_manager_init( open_screen_type );
	while( 1 )
	{
		engine_input_manager_update();
		engine_screen_manager_update();

		VDP_waitVSync();
	}

	return 0;
}