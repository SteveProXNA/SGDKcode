#include "random_manager.h"
#include "global_manager.h"

#ifdef _CONSOLE
#include <stdlib.h>
#else
#include <genesis.h>
#endif

void engine_random_manager_rand()
{
#ifdef _CONSOLE
	rand();
#else
	random();
#endif
}

unsigned char engine_random_manager_next()
{
#ifdef _CONSOLE
	return rand() % MAX_RANDOM;
#else
	return random() % MAX_RANDOM;
#endif
}

unsigned char engine_random_manager_data( unsigned char max )
{
#ifdef _CONSOLE
	return rand() % max;
#else
	return random() % max;
#endif
}

unsigned char engine_random_manager_diff( unsigned char level )
{
	unsigned char value = 0;
#ifdef _CONSOLE
	value = rand() % HLF_RANDOM;
#else
	value = random() % HLF_RANDOM;
#endif

	return level <= value;
}