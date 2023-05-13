#include "sprite_manager.h"
#include "enum_manager.h"
#include "font_manager.h"
#include "global_manager.h"
#include "gfx_sprites.h"

#ifdef _CONSOLE
#include "_genesis.h"
#else
#include <genesis.h>
#endif

// Private fields.
Sprite* sprites[ MAX_SPRITES ] = { NULL, NULL, NULL };
const SpriteDefinition* spriteDefList[ MAX_SPRITES ] = { &gfx_chose, &gfx_right, &gfx_wrong };

// Private function.
static void init_sprite( const unsigned char index );

void engine_sprite_manager_init()
{
	SPR_init( 0, 0, 0 );

	init_sprite( sprite_type_chose );
	init_sprite( sprite_type_right );
	init_sprite( sprite_type_wrong );
}

void engine_sprite_manager_hide( unsigned char index )
{
	SPR_setVisibility( sprites[ index ], HIDDEN );
}

void engine_sprite_manager_update()
{
	SPR_update();
}

void engine_sprite_manager_draw( const unsigned char index, unsigned char x, unsigned char y )
{
	const SpriteDefinition* spriteDef;
	unsigned short *data = NULL;

	spriteDef = spriteDefList[ index ];
	if( NULL != spriteDef->palette )
	{
		data = spriteDef->palette->data;
	}

	VDP_setPalette( PAL3, data );
	SPR_setPosition( sprites[ index ], x, y );
	SPR_setVisibility( sprites[ index ], VISIBLE );
}

// Public methods DRAW.
void engine_sprite_manager_draw_chose( unsigned char x, unsigned char y )
{
	engine_sprite_manager_draw( sprite_type_chose, x, y );
}
void engine_sprite_manager_draw_right( unsigned char x, unsigned char y )
{
	engine_sprite_manager_draw( sprite_type_right, x, y );
}
void engine_sprite_manager_draw_wrong( unsigned char x, unsigned char y )
{
	engine_sprite_manager_draw( sprite_type_wrong, x, y );
}

static void init_sprite( const unsigned char index )
{
	const SpriteDefinition* spriteDef;
	unsigned short *data = NULL;

	spriteDef = spriteDefList[ index ];
	if( NULL != spriteDef->palette )
	{
		data = spriteDef->palette->data;
	}

	VDP_setPalette( PAL3, data );
	sprites[ index ] = SPR_addSprite( spriteDef, 0, 0, TILE_ATTR( PAL3, 0, FALSE, FALSE ) );
	SPR_setVisibility( sprites[ index ], HIDDEN );
}
