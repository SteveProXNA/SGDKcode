#include "font_manager.h"
#include "gfx_tiles.h"

#define FONT_TILES	1		// 1  is graphics tile
#define TEXT_ROOT	32		// 32 is " " in ASCII.
#define DATA_ROOT	16		// 16 is "0" (48=16+32)
#define UNIT_ROOT	10		// 10 is decimal
#define DATA_LONG	3		// 3 placeholder

#ifdef _CONSOLE
#include "_genesis.h"
#else
#include <genesis.h>
#endif

void engine_font_manager_init()
{
	unsigned short *data = NULL;
	unsigned char palette = NULL;

	VDP_loadTileSet( gfx_font.tileset, FONT_TILES, TRUE );
	if( NULL != gfx_font.palette )
	{
		data = gfx_font.palette->data;
	}

	VDP_setPalette( palette, data );
}

void engine_font_manager_char( const unsigned char ch, unsigned char x, unsigned char y )
{
	unsigned char tile = ch - TEXT_ROOT;
	VDP_setMapEx( BG_A, gfx_font.tilemap, TILE_ATTR_FULL( PAL0, FALSE, FALSE, FALSE, FONT_TILES ), x, y, tile, 0, 1, 1 );
}

void engine_font_manager_text( const unsigned char *text, unsigned char x, unsigned char y )
{
	unsigned char idx = 0;
	while( '\0' != text[ idx ] )
	{
		signed char tile = text[ idx ] - TEXT_ROOT;
		VDP_setMapEx( BG_A, gfx_font.tilemap, TILE_ATTR_FULL( PAL0, FALSE, FALSE, FALSE, FONT_TILES ), x++, y, tile, 0, 1, 1 );
		idx++;
	}
}

void engine_font_manager_data( unsigned int data, unsigned char x, unsigned char y )
{
	unsigned char idx;
	signed char tile;

	unsigned int quotient = 0;
	unsigned char remainder = 0;

	for( idx = 0; idx < DATA_LONG; ++idx )
	{
		quotient = data / UNIT_ROOT;
		remainder = data % UNIT_ROOT;
		data /= UNIT_ROOT;

		tile = remainder + DATA_ROOT;
		if( 0 == quotient && 0 == remainder && idx > 0 )
		{
			// Replace with space!
			tile = 0;
		}

		VDP_setMapEx( BG_A, gfx_font.tilemap, TILE_ATTR_FULL( PAL0, FALSE, FALSE, FALSE, FONT_TILES ), x--, y, tile, 0, 1, 1 );
	}
}

void engine_font_manager_zero( unsigned int data, unsigned char x, unsigned char y )
{
	unsigned char idx;
	signed char tile;

	char hold[ DATA_LONG ];
	for( idx = 0; idx < DATA_LONG; ++idx )
	{
		hold[ idx ] = data % UNIT_ROOT;
		data /= UNIT_ROOT;

		tile = hold[ idx ] + DATA_ROOT;

		VDP_setMapEx( BG_A, gfx_font.tilemap, TILE_ATTR_FULL( PAL0, FALSE, FALSE, FALSE, FONT_TILES ), x--, y, tile, 0, 1, 1 );
	}
}