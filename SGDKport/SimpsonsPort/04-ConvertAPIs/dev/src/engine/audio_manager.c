#include "audio_manager.h"
#include "hack_manager.h"
#include "random_manager.h"
#include "audio_object.h"

#ifdef _CONSOLE
#include "_genesis.h"
#else
#include <genesis.h>
#endif

// Private helper function.
static void play_audio( const u8 id, const u8 priority, const u16 channel );
static void stop_audio();

static unsigned char prevRight, currRight;
static unsigned char prevWrong, currWrong;

void engine_audio_manager_init()
{
	unsigned char idx;
	const unsigned char *audio;
	unsigned int sized;

	// Initialize effects.
	for( idx = 0; idx < MAX_EFFECTS; idx++ )
	{
		audio = audio_effect[ idx ];
		sized = audio_effect_size[ idx ];
		SND_setPCM_XGM( SFX_EFFECT_START + idx, audio, sized );
	}

	// Initialize music.
	for( idx = 0; idx < MAX_MUSICS; idx++ )
	{
		audio = audio_music[ idx ];
		sized = audio_music_size[ idx ];
		SND_setPCM_XGM( SFX_MUSICS_START + idx, audio, sized );
	}

	// Initialize results.
	for( idx = 0; idx < MAX_RESULTS; idx++ )
	{
		audio = audio_results[ idx ];
		sized = audio_results_size[ idx ];
		SND_setPCM_XGM( SFX_RESULT_START + idx, audio, sized );
	}

	prevRight = 0; 	currRight = 0;
	prevWrong = 0; 	currWrong = 0;
}

void engine_audio_manager_play_effect( unsigned char index )
{
	if( !hacker_sound )
	{
		return;
	}

	play_audio( SFX_EFFECT_START + index, 1, SOUND_PCM_CH2 );
}

void engine_audio_manager_play_music( unsigned char index )
{
	if( !hacker_music )
	{	
		return;
	}

	play_audio( SFX_MUSICS_START + index, 1, SOUND_PCM_CH1 );
}

void engine_audio_manager_play_result( unsigned char index )
{
	if( !hacker_sound )
	{
		return;
	}

	play_audio( SFX_RESULT_START + index, 1, SOUND_PCM_CH2 );
}

void engine_audio_manager_stop()
{
	stop_audio();
}

void engine_audio_manager_sound_woohoo()
{
	while( 1 )
	{
		currRight = engine_random_manager_data( MAX_RIGHT );
		if( currRight != prevRight )
		{
			break;
		}
	}

	engine_audio_manager_play_result( currRight );
	prevRight = currRight;
}
void engine_audio_manager_sound_doh()
{
	while( 1 )
	{
		currWrong = engine_random_manager_data( MAX_WRONG );
		if( currWrong != prevWrong )
		{
			break;
		}
	}

	engine_audio_manager_play_result( currWrong + MAX_RIGHT );
	prevWrong = currWrong;
}

static void play_audio( const u8 id, const u8 priority, const u16 channel )
{
	XGM_startPlayPCM( id, priority, channel );
}
static void stop_audio()
{
	if( XGM_isPlayingPCM( SOUND_PCM_CH1_MSK ) )
	{
		XGM_stopPlayPCM( SOUND_PCM_CH1 );
	}
	if( XGM_isPlayingPCM( SOUND_PCM_CH2_MSK ) )
	{
		XGM_stopPlayPCM( SOUND_PCM_CH2 );
	}
}
