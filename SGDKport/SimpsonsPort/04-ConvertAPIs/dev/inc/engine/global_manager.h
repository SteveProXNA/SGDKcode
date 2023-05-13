#ifndef _GLOBAL_MANAGER_H_
#define _GLOBAL_MANAGER_H_

// General.
#define MAX_SCREEENS		15

// Sprites.
#define SPRITE_TILES		64

// Delay.
#define SPLASH_DELAY		150
#define TITLE_DELAY			100
#define NORMAL_DELAY		50

// Quiz.
#define MAX_QUESTIONS		50

// Options.
#define MAX_OPTIONS			4

// Long.
#define LONG_DELTA			4

// Cheat.
#define CHEAT_TOTAL			5

// Summary.
#define INFO_SUMMARY_X		12
#define SUMMARY_TEXT_X		4
#define SUMMARY_DATA_X		21

// Actors.
#define MAX_ACTORS			16

// Audio
#define MAX_RIGHT			3
#define MAX_WRONG			3

// Audio
#define COLOR_BLACK			0
#define COLOR_WHITE			3


// Additional.
#define OPTN_X				9
#define OPTA_Y				11
#define OPTB_Y				15
#define OPTC_Y				19
#define OPTD_Y				23

#define QUIZ_X				4
#define QUIZ_Y				6

#define TITLE_X				27
#define TITLE_Y				4

extern unsigned char local_cheat;

// New globals.
#define MAX_SPRITES				3
#define MAX_EFFECTS				4
#define MAX_MUSICS				2
#define MAX_RESULTS				6

#define PALETTE1_TILES			65

#define SFX_EFFECT_START		65
#define SFX_MUSICS_START		SFX_EFFECT_START + MAX_EFFECTS
#define SFX_RESULT_START		SFX_MUSICS_START + MAX_RESULTS



#endif//_GLOBAL_MANAGER_H_
