#include "timer_manager.h"

unsigned char screen_bases_screen_count;
unsigned int screen_bases_screen_timer;

void screen_bases_screen_init()
{
	screen_bases_screen_count = 0;
	screen_bases_screen_timer = 0;
}