#include "graphics_manager.h"
#include "game_manager.h"
#include "global_manager.h"
#include "text_manager.h"
#include "gfx.h"

#ifdef _CONSOLE
#include "_genesis.h"
#else
#include <genesis.h>
#endif

#define BORDER_TILES		56
#define SPLASH_TILES		64
#define LOGO_TILES			64
#define VILLAGE_TILES		128
#define BOSS_TILES			64
#define STOCK_TILES			256

static void drawImageEx( const Image *image, unsigned char palette, unsigned int index, unsigned char x, unsigned char y );
static void draw_setMapEx( unsigned int tile, unsigned char x, unsigned char y );

void engine_graphics_manager_init()
{
	u16 *pal0 = NULL;
	u16 *pal1 = NULL;
	u16 *pal2 = NULL;

	// Get the palette data from gfx.
#ifndef _CONSOLE
	pal0 = gfx_palette0.palette->data;
	pal1 = gfx_palette1.palette->data;
	pal2 = gfx_splash.palette->data;
#endif

	VDP_setPalette( PAL0, pal0 );
	VDP_setPalette( PAL1, pal1 );
	VDP_setPalette( PAL2, pal2 );

	VDP_loadTileSet( gfx_font.tileset, FONT_TILES, 1 );
	VDP_loadTileSet( gfx_border.tileset, BORDER_TILES, 1 );
}

void engine_graphics_manager_load()
{
	VDP_loadTileSet( gfx_stats_items.tileset, ITEMS_TILES, 1 );
	VDP_loadTileSet( gfx_battle_player.tileset, PLAYER_TILES, 1 );
	VDP_loadTileSet( gfx_battle_enemies.tileset, ENEMY_TILES, 1 );
	VDP_loadTileSet( gfx_battle_enemies_leshy.tileset, LESHY_TILES, 1 );
}

void engine_graphics_manager_clear_full()
{
	VDP_clearTileMapRect( BG_A, 0, 0, OUTER_WIDE, OUTER_HIGH );
}

void engine_graphics_manager_clear_part()
{
	VDP_clearTileMapRect( BG_A, LEFT_X + 1, TOP_Y + 1, INNER_WIDE - 2, INNER_HIGH - 2 );
}

void engine_graphics_manager_draw_border()
{
	struct_game_object *go = &global_game_object;
	const unsigned char tile = 1;

	// Draw the two underline unconditionally.
	draw_setMapEx( tile, LEFT_X, TOP_Y + 4 );
	draw_setMapEx( tile, LEFT_X + INNER_WIDE - 1, TOP_Y + 4 );

	if( !go->lines_once )
	{
		return;
	}

	engine_graphics_manager_draw_borderX( 0, 0, OUTER_WIDE, OUTER_HIGH );
	engine_graphics_manager_draw_borderX( LEFT_X, TOP_Y, LEFT_X + INNER_WIDE, TOP_Y + INNER_HIGH );
	engine_game_manager_lines_off();
}

void engine_graphics_manager_draw_borderX( unsigned char left, unsigned char top, unsigned char wide, unsigned char high )
{
	unsigned char idx;
	unsigned char tile = 0;

	draw_setMapEx( tile, left + 0, top + 0 );
	draw_setMapEx( tile, wide - 1, top + 0 );
	draw_setMapEx( tile, left + 0, high - 1 );
	draw_setMapEx( tile, wide - 1, high - 1 );

	// Vertical.
	tile = 1;
	for( idx = top + 1; idx <= high - 2; idx++ )
	{
		draw_setMapEx( tile, left + 0, idx );
		draw_setMapEx( tile, wide - 1, idx );
	}

	// Horizontal.
	tile = 2;
	for( idx = left + 1; idx <= wide - 2; idx++ )
	{
		draw_setMapEx( tile, idx, top + 0 );
		draw_setMapEx( tile, idx, high - 1 );
	}
}

void engine_graphics_manager_draw_underline()
{
	unsigned char idx;
	unsigned char wide = LEFT_X + INNER_WIDE;
	unsigned char tile = 0;

	draw_setMapEx( tile, LEFT_X, TOP_Y + 4 );
	draw_setMapEx( tile, wide - 1, TOP_Y + 4 );

	// Horizontal.
	tile = 2;
	for( idx = LEFT_X + 1; idx <= wide - 2; idx++ )
	{
		draw_setMapEx( tile, idx, TOP_Y + 4 );
	}
}

void engine_graphics_manager_draw_splash()
{
	drawImageEx( &gfx_splash, PAL2, SPLASH_TILES, LEFT_X + 0, TOP_Y + 0 );
}

void engine_graphics_manager_draw_logo_big( unsigned char x, unsigned char y )
{
	drawImageEx( &gfx_logo_big, PAL0, LOGO_TILES, x, y );
}

void engine_graphics_manager_draw_logo_small( unsigned char x, unsigned char y )
{
	drawImageEx( &gfx_logo_small, PAL0, LOGO_TILES, x, y );
}

void engine_graphics_manager_draw_village( unsigned char x, unsigned char y )
{
	drawImageEx( &gfx_stats_village, PAL1, VILLAGE_TILES, x, y );
}

void engine_graphics_manager_draw_koschey( unsigned char x, unsigned char y, unsigned char palette )
{
	drawImageEx( &gfx_koschey, palette, BOSS_TILES, x, y );
}

void engine_graphics_manager_draw_inventory( unsigned char x, unsigned char y )
{
	drawImageEx( &gfx_stats_inventory, PAL0, STOCK_TILES, x, y );
}

static void drawImageEx( const Image *image, unsigned char palette, unsigned int index, unsigned char x, unsigned char y )
{
	u16 basetile = TILE_ATTR_FULL( palette, 0, 0, 0, index );
	VDP_drawImageEx( BG_A, image, basetile, x, y, 0, CPU );
}
static void draw_setMapEx( unsigned int tile, unsigned char x, unsigned char y )
{
	VDP_setMapEx( BG_A, gfx_border.tilemap, TILE_ATTR_FULL( PAL0, 0, 0, 0, BORDER_TILES ), x, y, tile, 0, 1, 1 );
}