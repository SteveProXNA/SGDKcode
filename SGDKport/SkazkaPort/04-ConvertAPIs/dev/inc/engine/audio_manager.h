#ifndef _AUDIO_MANAGER_H_
#define _AUDIO_MANAGER_H_

void engine_audio_manager_init();
void engine_audio_manager_play_sound( unsigned char index );
void engine_audio_manager_play_music( unsigned char index );

void engine_sound_manager_fight();
void engine_music_manager_beat();
void engine_music_manager_intro();
void engine_music_manager_boss();
void engine_music_manager_over();

void engine_audio_manager_stop();
unsigned char engine_audio_manager_is_playing();

#endif//_AUDIO_MANAGER_H_
