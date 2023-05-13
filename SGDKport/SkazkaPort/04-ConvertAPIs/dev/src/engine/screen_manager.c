#include "screen_manager.h"
#include "global_manager.h"
#include "enum_manager.h"

// Screens
#include "none_screen.h"
#include "splash_screen.h"
#include "title_screen.h"
#include "diff_screen.h"
#include "intro_screen.h"
#include "load_screen.h"
#include "start_screen.h"
#include "stats_screen.h"
#include "forest_screen.h"
#include "victory_screen.h"
#include "shop_screen.h"
#include "talk_screen.h"
#include "prep_screen.h"
#include "boss_screen.h"
#include "complete_screen.h"
#include "menu_screen.h"
#include "relive_screen.h"
#include "over_screen.h"
#include "credit_screen.h"
#include "kill_screen.h"
#include "test_screen.h"
#include "func_screen.h"

static unsigned char curr_screen_type;
static unsigned char next_screen_type;

static void( *load_method[ MAX_SCREEENS ] )( );
static void( *update_method[ MAX_SCREEENS ] )( unsigned char *screen_type );

void engine_screen_manager_init( unsigned char open_screen_type )
{
	next_screen_type = open_screen_type;
	curr_screen_type = screen_type_none;

	// Set load methods.
	load_method[ screen_type_none ] = screen_none_screen_load;
	load_method[ screen_type_splash ] = screen_splash_screen_load;
	load_method[ screen_type_title ] = screen_title_screen_load;
	load_method[ screen_type_diff ] = screen_diff_screen_load;
	load_method[ screen_type_intro ] = screen_intro_screen_load;
	load_method[ screen_type_load ] = screen_load_screen_load;
	load_method[ screen_type_start ] = screen_start_screen_load;
	load_method[ screen_type_stats ] = screen_stats_screen_load;
	load_method[ screen_type_forest ] = screen_forest_screen_load;
	load_method[ screen_type_victory ] = screen_victory_screen_load;
	load_method[ screen_type_shop ] = screen_shop_screen_load;
	load_method[ screen_type_talk ] = screen_talk_screen_load;
	load_method[ screen_type_prep ] = screen_prep_screen_load;
	load_method[ screen_type_boss ] = screen_boss_screen_load;
	load_method[ screen_type_complete ] = screen_complete_screen_load;
	load_method[ screen_type_menu ] = screen_menu_screen_load;
	load_method[ screen_type_relive ] = screen_relive_screen_load;
	load_method[ screen_type_over ] = screen_over_screen_load;
	load_method[ screen_type_credit ] = screen_credit_screen_load;
	load_method[ screen_type_kill ] = screen_kill_screen_load;
	load_method[ screen_type_test ] = screen_test_screen_load;
	load_method[ screen_type_func ] = screen_func_screen_load;

	// Set update methods.
	update_method[ screen_type_none ] = screen_none_screen_update;
	update_method[ screen_type_splash ] = screen_splash_screen_update;
	update_method[ screen_type_title ] = screen_title_screen_update;
	update_method[ screen_type_diff ] = screen_diff_screen_update;
	update_method[ screen_type_intro ] = screen_intro_screen_update;
	update_method[ screen_type_load ] = screen_load_screen_update;
	update_method[ screen_type_start ] = screen_start_screen_update;
	update_method[ screen_type_stats ] = screen_stats_screen_update;
	update_method[ screen_type_forest ] = screen_forest_screen_update;
	update_method[ screen_type_victory ] = screen_victory_screen_update;
	update_method[ screen_type_shop ] = screen_shop_screen_update;
	update_method[ screen_type_talk ] = screen_talk_screen_update;
	update_method[ screen_type_prep ] = screen_prep_screen_update;
	update_method[ screen_type_boss ] = screen_boss_screen_update;
	update_method[ screen_type_complete ] = screen_complete_screen_update;
	update_method[ screen_type_menu ] = screen_menu_screen_update;
	update_method[ screen_type_relive ] = screen_relive_screen_update;
	update_method[ screen_type_over ] = screen_over_screen_update;
	update_method[ screen_type_credit ] = screen_credit_screen_update;
	update_method[ screen_type_kill ] = screen_kill_screen_update;
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
