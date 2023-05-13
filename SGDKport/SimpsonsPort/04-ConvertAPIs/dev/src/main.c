#include "main.h"

int main()
{
	unsigned char open_screen_type = screen_type_splash;
	//unsigned char open_screen_type = screen_type_title;
	engine_screen_manager_init( open_screen_type );


	// Initialize.
	engine_font_manager_init();
	engine_hack_manager_init();
	engine_hack_manager_invert();

	engine_actor_manager_init();
	engine_audio_manager_init();
	engine_quiz_manager_init();
	engine_score_manager_init();
	engine_select_manager_init();
	engine_sprite_manager_init();

	while( 1 )
	{
		engine_input_manager_update();
		engine_screen_manager_update();

		VDP_waitVSync();
	}

	return 0;
}