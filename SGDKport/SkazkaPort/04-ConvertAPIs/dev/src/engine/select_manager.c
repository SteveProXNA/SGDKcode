#include "select_manager.h"
#include "enum_manager.h"
#include "font_manager.h"
#include "input_manager.h"
#include "locale_manager.h"
#include "select_object.h"

// Global variables.
struct_select_object global_select_object;

// Private helper function.
static void initialize( unsigned char maxim );
static void draw_arrows();
static void draw_spaces();

void engine_select_manager_init()
{
	initialize( MAX_SELECTS );
}

void engine_select_manager_once()
{
	initialize( MAX_SELECTS - 1 );
}

void engine_select_manager_load( unsigned char index, unsigned char x, unsigned char y, unsigned char option )
{
	struct_select_object *so = &global_select_object;
	so->select_X = x;
	so->select_Y = y + so->select_index[ index ];
	so->select_min = y;
	so->select_max = y + option - 1;
	draw_arrows();
}

unsigned char engine_select_manager_update( unsigned char index )
{
	struct_select_object *so = &global_select_object;
	unsigned char input;

	input = engine_input_manager_hold_up();
	if( input )
	{
		draw_spaces();
		if( so->select_Y <= so->select_min )
		{
			so->select_Y = so->select_max + 1;
		}

		so->select_Y--;
		draw_arrows();
	}

	input = engine_input_manager_hold_down();
	if( input )
	{
		draw_spaces();
		if( so->select_Y >= so->select_max )
		{
			so->select_Y = so->select_min - 1;
		}

		so->select_Y++;
		draw_arrows();
	}

	// Updates select index unconditionally.
	so->select_index[ index ] = so->select_Y - so->select_min;

	input = engine_input_manager_hold_buttonA();
	if (input)
	{
		return so->select_index[ index ];
	}

	return NO_SELECTION;
}

static void initialize( unsigned char maxim )
{
	struct_select_object *so = &global_select_object;
	unsigned char index;

	for( index = 0; index < maxim; index++ )
	{
		so->select_index[ index ] = 0;
	}

	so->select_X = 0;
	so->select_Y = 0;
	so->select_min = 0;
	so->select_max = 0;
}

static void draw_arrows()
{
	struct_select_object *so = &global_select_object;
	engine_font_manager_draw_punc( LOCALE_ARROW, so->select_X, so->select_Y );
}

static void draw_spaces()
{
	struct_select_object *so = &global_select_object;
	engine_font_manager_draw_char( LOCALE_1_SPCS, so->select_X, so->select_Y );
}