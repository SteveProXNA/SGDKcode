#include "font_manager.h"
#include "global_manager.h"
#include "locale_manager.h"
#include "gfx.h"

#define TEXT_ROOT	64		// 64 is "A" (65-01).
#define DATA_ROOT	27		// 27 is "0" (48-27).
#define UNIT_ROOT	10		// 10 is decimal
#define DATA_LONG	3		// 3 placeholder

#ifdef _CONSOLE
#include "_genesis.h"
#else
#include <genesis.h>
#endif

// Private helper functions.
static unsigned char get_tile( unsigned char ch );
static unsigned char get_punc( unsigned char ch );
static void draw_setMapEx( unsigned int tile, unsigned char x, unsigned char y );

void engine_font_manager_draw_char( const unsigned char ch, unsigned char x, unsigned char y )
{
	unsigned char tile = get_tile( ch );
	draw_setMapEx( tile, x, y );
}

void engine_font_manager_draw_numb( const unsigned char ch, unsigned char x, unsigned char y )
{
	unsigned char tile = ch + DATA_ROOT;
	draw_setMapEx( tile, x, y );
}

void engine_font_manager_draw_punc( const unsigned char ch, unsigned char x, unsigned char y )
{
	unsigned char punc = get_punc( ch );
	draw_setMapEx( punc, x, y );
}

void engine_font_manager_draw_text( char *text, unsigned char x, unsigned char y )
{
	unsigned char idx = 0;
	unsigned char tile = 0;
	while( '\0' != text[ idx ] )
	{
		tile = get_tile( text[ idx ] );
		draw_setMapEx( tile, x, y );
		x++;
		idx++;
	}
}

void engine_font_manager_draw_data( unsigned int data, unsigned char x, unsigned char y )
{
	unsigned char idx;
	unsigned char tile;

	unsigned int quotient = 0;
	unsigned char remainder = 0;

	char hold[ DATA_LONG ];
	for( idx = 0; idx < DATA_LONG; ++idx )
	{
		quotient = data / UNIT_ROOT;
		remainder = data % UNIT_ROOT;

		hold[ idx ] = remainder;
		data /= UNIT_ROOT;

		tile = hold[ idx ] + DATA_ROOT;
		if( 0 == quotient && 0 == remainder && idx > 0 )
		{
			// Replace with space!
			tile = 0;
		}

		draw_setMapEx( tile, x, y );
		x--;
	}
}

void engine_font_manager_draw_zero( unsigned int data, unsigned char x, unsigned char y )
{
	unsigned char idx;
	unsigned char tile;

	char hold[ DATA_LONG ];
	for( idx = 0; idx < DATA_LONG; ++idx )
	{
		hold[ idx ] = data % UNIT_ROOT;
		data /= UNIT_ROOT;

		tile = hold[ idx ] + DATA_ROOT;
		draw_setMapEx( tile, x, y );
		x--;
	}
}

// Private helper functions.
static unsigned char get_tile( unsigned char ch )
{
	unsigned char lett = 0;
	if( ' ' != ch )
	{
		lett = ch - TEXT_ROOT;
	}

	return lett;
}
static unsigned char get_punc( unsigned char ch )
{
	if( LOCALE_PLUS == ch ) { return 37; }
	else if( LOCALE_HYPHEN == ch ) { return 38; }
	else if( LOCALE_QUOTE == ch ) { return 39; }
	else if( LOCALE_STOP == ch ) { return 40; }
	else if( LOCALE_COMMA == ch ) { return 41; }
	else if( LOCALE_COLON == ch ) { return 42; }
	else if( LOCALE_QMARK == ch ) { return 43; }
	else if( LOCALE_POINT == ch ) { return 44; }
	else if( LOCALE_SLASH == ch ) { return 45; }
	else if( LOCALE_BRACKET == ch ) { return 46; }
	else if( LOCALE_ARROW == ch ) { return 47; }
	return 0;
}
static void draw_setMapEx( unsigned int tile, unsigned char x, unsigned char y )
{
	VDP_setMapEx( BG_A, gfx_font.tilemap, TILE_ATTR_FULL( PAL0, 0, 0, 0, FONT_TILES ), x, y, tile, 0, 1, 1 );
}