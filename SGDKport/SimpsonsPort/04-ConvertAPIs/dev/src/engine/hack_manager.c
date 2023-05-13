#include "hack_manager.h"

unsigned char hacker_debug;
unsigned char hacker_cheat, hacker_random;
unsigned char hacker_music, hacker_sound;

#define PEEK( addr)			(* ( unsigned char *)( addr ) )
#define POKE( addr, data )	(* ( unsigned char *)( addr ) = ( data ) )

#define HACKER_START		0x01E0
#define HACKER_SPACE		32

#ifdef _CONSOLE
#endif

void engine_hack_manager_init()
{
	hacker_debug = 0;
	hacker_cheat = 0;
	hacker_random = 0;
	hacker_music = 0;
	hacker_sound = 0;

#ifndef _CONSOLE

	hacker_debug = PEEK( HACKER_START - 1 );	// 0x01DF		// 0=debug on otherwise off.

	hacker_cheat = PEEK( HACKER_START + 0 );	// 0x01E0		// 0=there's no help at all.
	hacker_random = PEEK( HACKER_START + 1 );	// 0x01E1		// 0=randomly ask questions.
	hacker_music = PEEK( HACKER_START + 2 );	// 0x01E2		// 0=music on otherwise off.
	hacker_sound = PEEK( HACKER_START + 3 );	// 0x01E3		// 0=sound on otherwise off.

#endif
}

void engine_hack_manager_invert()
{
	if( hacker_cheat && HACKER_SPACE == hacker_cheat )
	{
		hacker_cheat = 0;
	}
	if( hacker_random && HACKER_SPACE == hacker_random )
	{
		hacker_random = 0;
	}
	if( hacker_music && HACKER_SPACE == hacker_music )
	{
		hacker_music = 0;
	}
	if( hacker_sound && HACKER_SPACE == hacker_sound )
	{
		hacker_sound = 0;
	}

	hacker_music = !hacker_music;
	hacker_sound = !hacker_sound;
}