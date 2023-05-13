#include "hack_manager.h"
#include "enum_manager.h"
#include "font_manager.h"
#include "global_manager.h"
#include "player_manager.h"

// Global variable.
struct_hack_object global_hack_object;

#define PEEK( addr)			(* ( unsigned char *)( addr ) )
#define POKE( addr, data )	(* ( unsigned char *)( addr ) = ( data ) )

#define HACKER_START		0x01E0
#define HACKER_SPACE		32

void engine_hack_manager_init()
{
	struct_hack_object *ho = &global_hack_object;

	ho->hack_delays = 0;
	ho->hack_nodead = 0;
	ho->hack_currxp = 0;
	ho->hack_currhp = 0;
	ho->hack_goldno = 0;
	ho->hack_weapon = 0;
	ho->hack_armors = 0;
	ho->hack_oneups = 0;
	ho->hack_talker = 0;
	ho->hack_musics = 0;
	ho->hack_sounds = 0;
}

void engine_hack_manager_load()
{
	struct_hack_object *ho = &global_hack_object;

#ifndef _CONSOLE

	ho->hack_delays = PEEK( HACKER_START - 2 );			// 0x01DE		// Used to speed through any game delay.
	ho->hack_nodead = PEEK( HACKER_START - 1 );			// 0x01DF		// Non-zero value enables invincibility.
	ho->hack_currxp = PEEK( HACKER_START + 0 );			// 0x01E0		// Non-zero sets default experience pts.
	ho->hack_currhp = PEEK( HACKER_START + 1 );			// 0x01E1		// Non-zero sets default healthy points.
	ho->hack_goldno = PEEK( HACKER_START + 2 );			// 0x01E2		// Non-zero sets default gold available.
	ho->hack_weapon = PEEK( HACKER_START + 3 );			// 0x01E3		// Set value to 1 or 2 for stock else 0.
	ho->hack_armors = PEEK( HACKER_START + 4 );			// 0x01E4		// Set value to 1 or 2 for armor else 0.
	ho->hack_oneups = PEEK( HACKER_START + 5 );			// 0x01E5		// Set value to 1=Life otherwise 0=None.
	ho->hack_talker = PEEK( HACKER_START + 6 );			// 0x01E6		// Set value to 1=repeat villagers talk.
	ho->hack_musics = PEEK( HACKER_START + 7 );			// 0x01E7		// Set 0=Music to play otherwise silent.
	ho->hack_sounds = PEEK( HACKER_START + 8 );			// 0x01E8		// Set 0=Sound to play otherwise silent.

#endif
}

void engine_hack_manager_invert()
{
	struct_hack_object *ho = &global_hack_object;
	if( ho->hack_delays && HACKER_SPACE == ho->hack_delays )
	{
		ho->hack_delays = 0;
	}
	if( ho->hack_nodead && HACKER_SPACE == ho->hack_nodead )
	{
		ho->hack_nodead = 0;
	}

	if( ho->hack_currxp && HACKER_SPACE != ho->hack_currxp )
	{
		if( ho->hack_currxp > 0 && ho->hack_currxp <= MAX_XP && HACKER_SPACE != ho->hack_currxp )
		{
			engine_player_manager_def_currxp( ho->hack_currxp );
		}
	}
	if( ho->hack_currhp && HACKER_SPACE != ho->hack_currhp )
	{
		if( ho->hack_currhp > 0 && ho->hack_currhp <= MAX_HP )
		{
			engine_player_manager_def_currhp( ho->hack_currhp );
		}
	}
	if( ho->hack_goldno && HACKER_SPACE != ho->hack_goldno )
	{
		if( ho->hack_goldno > 0 && HACKER_SPACE != ho->hack_goldno )
		{
			engine_player_manager_def_goldno( ho->hack_goldno );
		}
	}
	if( ho->hack_weapon && HACKER_SPACE != ho->hack_weapon )
	{
		if( ho->hack_weapon > 0 && ho->hack_weapon <= weapon_type_axe )
		{
			engine_player_manager_def_weapon( ho->hack_weapon );
		}
	}
	if( ho->hack_armors && HACKER_SPACE != ho->hack_armors )
	{
		if( ho->hack_armors > 0 && ho->hack_armors <= armor_type_kolchuga )
		{
			engine_player_manager_def_armors( ho->hack_armors );
		}
	}
	if( ho->hack_oneups && HACKER_SPACE != ho->hack_oneups )
	{
		if( ho->hack_oneups > 0 && ho->hack_oneups <= life_type_oneup )
		{
			engine_player_manager_def_oneups( ho->hack_oneups );
		}
	}
	if( ho->hack_talker && HACKER_SPACE == ho->hack_talker )
	{
		ho->hack_talker = 0;
	}

	if( ho->hack_musics && HACKER_SPACE == ho->hack_musics )
	{
		ho->hack_musics = 0;
	}
	if( ho->hack_sounds && HACKER_SPACE == ho->hack_sounds )
	{
		ho->hack_sounds = 0;
	}

	// Invert default values.
	ho->hack_musics = !ho->hack_musics;
	ho->hack_sounds = !ho->hack_sounds;
}