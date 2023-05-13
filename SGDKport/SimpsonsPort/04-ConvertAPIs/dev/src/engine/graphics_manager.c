#include "graphics_manager.h"

#ifdef _CONSOLE
#include "_genesis.h"
#else
#include <genesis.h>
#endif

#define GAME_AREA_X				0
#define GAME_AREA_Y				0
#define GAME_AREA_W				40
#define GAME_AREA_H				28


void engine_graphics_manager_clear_full()
{
	VDP_clearTileMapRect( BG_A, GAME_AREA_X, GAME_AREA_Y, GAME_AREA_W, GAME_AREA_H );
}
