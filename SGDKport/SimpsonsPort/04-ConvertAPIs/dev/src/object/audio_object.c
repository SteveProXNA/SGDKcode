#include "audio_object.h"
#include "sfx_effects.h"
#include "sfx_musics.h"
#include "sfx_results.h"

const unsigned char *audio_effect[ MAX_EFFECTS ] =
{
	sfx_cheat,
	sfx_ready,
	sfx_right,
	sfx_wrong,
};
const unsigned int audio_effect_size[ MAX_EFFECTS ] =
{
	13568,
	15872,
	16384,
	14592,
};

const unsigned char *audio_music[ MAX_MUSICS ] =
{
	sfx_gameover,
	sfx_titlemusic,
};
const unsigned int audio_music_size[ MAX_MUSICS ] =
{
	34816,
	977152,
};

const unsigned char *audio_results[ MAX_RESULTS ] =
{
	sfx_right_01,
	sfx_right_02,
	sfx_right_03,
	sfx_wrong_01,
	sfx_wrong_02,
	sfx_wrong_03,
};
const unsigned int audio_results_size[ MAX_RESULTS ] =
{
	11008,
	11776,
	8704,
	8448,
	16384,
	7168,
};