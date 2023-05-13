#ifndef _PLAYER_OBJECT_H_
#define _PLAYER_OBJECT_H_

// BASIC
// Z	CURR XP
// N	REM CURR HP
// V 	REM CURR GOLD
// Q$ 	REM WEAPON
// W$	REM ARMOR
// E$ 	REM MISC
// X	level		3
// M	MAX HP		30
// Y	MAX XP		99

typedef struct tag_struct_player_object
{
	unsigned char xp;				// Z
	unsigned char hp;				// N
	unsigned int gold;				// V
	unsigned char weapon;			// Q$	ATK
	unsigned char armor;			// W$	ARM
	unsigned char life;				// E$	UP
	unsigned char level;			// X
	unsigned char max_hp;			// M
	unsigned char max_xp;			// Y
	unsigned char won;

	unsigned char def_xp;			// Z
	unsigned char def_hp;			// N
	unsigned int def_gold;			// V
	unsigned char def_weapon;		// Q$	ATK
	unsigned char def_armor;		// W$	ARM
	unsigned char def_life;			// E$	UP

} struct_player_object;

#endif//_PLAYER_OBJECT_H_