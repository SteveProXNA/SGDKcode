#ifndef _ENUM_MANAGER_H_
#define _ENUM_MANAGER_H_

typedef enum tag_enum_screen_type
{
	screen_type_none = 0,
	screen_type_splash = 1,
	screen_type_title = 2,
	screen_type_diff = 3,
	screen_type_intro = 4,
	screen_type_load = 5,
	screen_type_start = 6,
	screen_type_stats = 7,
	screen_type_forest = 8,
	screen_type_victory = 9,
	screen_type_shop = 10,
	screen_type_talk = 11,
	screen_type_prep = 12,
	screen_type_boss = 13,
	screen_type_complete = 14,
	screen_type_menu = 15,
	screen_type_relive = 16,
	screen_type_over = 17,
	screen_type_credit = 18,
	screen_type_kill = 19,
	screen_type_test = 20,
	screen_type_func = 21,

} enum_screen_type;

typedef enum tag_enum_input_type
{
	input_type_up = 0x01,
	input_type_down = 0x02,
	input_type_left = 0x04,
	input_type_right = 0x08,
	input_type_fire1 = 0x10,
	input_type_fire2 = 0x20,

} enum_input_type;

typedef enum tag_enum_diff_type
{
	diff_type_easy = 0,
	diff_type_hard = 1,

} enum_diff_type;

typedef enum tag_enum_select_type
{
	select_type_main = 0,
	select_type_stats = 1,
	select_type_forest = 2,
	select_type_shop = 3,
	select_type_prep = 4,
	select_type_boss = 5,
	select_type_menu = 6,
	select_type_diff = 7,

} enum_select_type;

typedef enum tag_enum_action_type
{
	action_type_forest = 0,
	action_type_shop = 1,
	action_type_rest = 2,
	action_type_talk = 3,
	action_type_boss = 4,
	action_type_menu = 5,

} enum_action_type;

typedef enum tag_enum_weapon_type
{
	weapon_type_dagger = 0,
	weapon_type_sword = 1,
	weapon_type_axe = 2,

} enum_weapon_type;

typedef enum tag_enum_armor_type
{
	armor_type_none = 0,
	armor_type_tegilay = 1,
	armor_type_kolchuga = 2,

} enum_armor_type;

typedef enum tag_enum_life_type
{
	life_type_none = 0,
	life_type_oneup = 1,

} enum_enum_life_type;

typedef enum tag_enum_enemy_type
{
	enemy_type_razboynik = 0,
	enemy_type_hungry_wolf = 1,
	enemy_type_kikimora = 2,
	enemy_type_leshy = 3,
	enemy_type_baby_yaga = 4,
	enemy_type_koschey = 5,

} enum_enemy_type;

typedef enum tag_enum_scene_type
{
	scene_type_select = 0,
	scene_type_decide = 1,
	scene_type_pushon = 2,

} enum_scene_type;

typedef enum tag_enum_fight_type
{
	fight_type_run = 0,
	fight_type_battle = 1,

} enum_fight_type;

typedef enum tag_enum_shop_type
{
	shop_type_sword = 0,
	shop_type_axe = 1,
	shop_type_tegilay = 2,
	shop_type_kolchuga = 3,
	shop_type_life = 4,

} enum_shop_type;

typedef enum tag_enum_binary_type
{
	binary_type_yes = 0,
	binary_type_no = 1,

} enum_binary_type;

typedef enum tag_enum_boss_type
{
	boss_type_beg = 0,
	boss_type_battle = 1,

} enum_boss_type;

typedef enum tag_enum_menu_type
{
	menu_type_exit = 0,
	menu_type_restart = 1,
	menu_type_continue = 2,

} enum_menu_type;

typedef enum tag_enum_stage_type
{
	event_stage_start = 0,
	event_stage_pause = 1,

} enum_stage_type;

typedef enum tag_enum_sound_type
{
	sound_type_0 = 0,
	sound_type_1 = 1,
	sound_type_2 = 2,
	sound_type_3 = 3,
	sound_type_4 = 4,
	sound_type_5 = 5,
	sound_type_6 = 6,
	sound_type_7 = 7,
	sound_type_8 = 8,
	sound_type_9 = 9,
	sound_type_10 = 10,
	sound_type_11 = 11,
	sound_type_12 = 12,
	sound_type_13 = 13,

} enum_sound_type;

typedef enum tag_enum_music_type
{
	music_intro = 0,
	music_boss = 1,
	music_over = 2,

} enum_music_type;

#endif//_ENUM_MANAGER_H_
