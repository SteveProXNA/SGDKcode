#include "audio_object.h"
#include "sfx.h"

const unsigned char *audio_music[ MAX_MUSIC ] =
{
	sfx_music_intro,
	sfx_music_boss,
	sfx_music_over,
};
const unsigned int audio_music_size[ MAX_MUSIC ] =
{
	68608,
	41216,
	34560
};

const unsigned char *audio_sound[ MAX_SOUND ] =
{
	sfx_sound_type_0,
	sfx_sound_type_1,
	sfx_sound_type_2,
	sfx_sound_type_3,
	sfx_sound_type_4,
	sfx_sound_type_5,		// index 5 = sfx_right
	sfx_sound_type_6,		// index 6 = sfx_wrong
	sfx_sound_type_7,		// index 7 = sfx_cheat
	sfx_sound_type_8,
	sfx_sound_type_9,
	sfx_sound_type_10,
	sfx_sound_type_11,
	sfx_sound_type_12,
	sfx_sound_type_13,		// index 12 = explosion => kill screen
};
const unsigned int audio_sound_size[ MAX_SOUND ] =
{
	2048,
	2304,
	2048,
	2048,
	3072,
	6912,
	8448,
	8448,
	3840,
	12800,
	3072,
	199936,
	49408,
	14080,
};
