#include "screen_manager.h"
#include "global_manager.h"
#include "enum_manager.h"

// Screens
#include "../screen/diff_screen.h"
#include "../screen/intro_screen.h"
#include "../screen/level_screen.h"
#include "../screen/long_screen.h"
#include "../screen/number_screen.h"
#include "../screen/over_screen.h"
#include "../screen/play_screen.h"
#include "../screen/quiz_screen.h"
#include "../screen/ready_screen.h"
#include "../screen/score_screen.h"
#include "../screen/splash_screen.h"
#include "../screen/title_screen.h"
#include "../screen/none_screen.h"
#include "../screen/test_screen.h"
#include "../screen/func_screen.h"

static unsigned char curr_screen_type;
static unsigned char next_screen_type;

static void( *load_method[ MAX_SCREEENS ] )( );
static void( *update_method[ MAX_SCREEENS ] )( unsigned char *screen_type );

void engine_screen_manager_init( unsigned char open_screen_type )
{
	next_screen_type = open_screen_type;
	curr_screen_type = screen_type_none;

	// Set init methods.
	screen_splash_screen_init();
	screen_title_screen_init();
	screen_intro_screen_init();
	screen_ready_screen_init();
	screen_diff_screen_init();
	screen_long_screen_init();
	screen_play_screen_init();
	screen_quiz_screen_init();
	screen_over_screen_init();

	// Set load methods.
	load_method[ screen_type_diff ] = screen_diff_screen_load;
	load_method[ screen_type_intro ] = screen_intro_screen_load;
	load_method[ screen_type_level ] = screen_level_screen_load;
	load_method[ screen_type_long ] = screen_long_screen_load;
	load_method[ screen_type_number ] = screen_number_screen_load;
	load_method[ screen_type_over ] = screen_over_screen_load;
	load_method[ screen_type_play ] = screen_play_screen_load;
	load_method[ screen_type_quiz ] = screen_quiz_screen_load;
	load_method[ screen_type_ready ] = screen_ready_screen_load;
	load_method[ screen_type_score ] = screen_score_screen_load;
	load_method[ screen_type_splash ] = screen_splash_screen_load;
	load_method[ screen_type_title ] = screen_title_screen_load;
	load_method[ screen_type_none ] = screen_none_screen_load;
	load_method[ screen_type_test ] = screen_test_screen_load;
	load_method[ screen_type_func ] = screen_func_screen_load;

	//// Set update methods.
	update_method[ screen_type_diff ] = screen_diff_screen_update;
	update_method[ screen_type_intro ] = screen_intro_screen_update;
	update_method[ screen_type_level ] = screen_level_screen_update;
	update_method[ screen_type_long ] = screen_long_screen_update;
	update_method[ screen_type_number ] = screen_number_screen_update;
	update_method[ screen_type_over ] = screen_over_screen_update;
	update_method[ screen_type_play ] = screen_play_screen_update;
	update_method[ screen_type_quiz ] = screen_quiz_screen_update;
	update_method[ screen_type_ready ] = screen_ready_screen_update;
	update_method[ screen_type_score ] = screen_score_screen_update;
	update_method[ screen_type_splash ] = screen_splash_screen_update;
	update_method[ screen_type_title ] = screen_title_screen_update;
	update_method[ screen_type_none ] = screen_none_screen_update;
	update_method[ screen_type_test ] = screen_test_screen_update;
	update_method[ screen_type_func ] = screen_func_screen_update;
}

void engine_screen_manager_update()
{
	if( curr_screen_type != next_screen_type )
	{
		curr_screen_type = next_screen_type;
		load_method[ curr_screen_type ]();
	}

	update_method[ curr_screen_type ]( &next_screen_type );
}
