#include "random_manager.h"
#include "enum_manager.h"
#include "global_manager.h"
#include "hack_manager.h"
#include "quiz_manager.h"

#ifdef _CONSOLE
#include <stdlib.h>
#else
#include <genesis.h>
#endif

 // Private helper methods.
static void load_random();
static void load_normal();
static void load_mixed();

// Public methods.
void engine_random_manager_init()
{
	unsigned char idx, opt;

	for( idx = 0; idx < MAX_QUESTIONS; idx++ )
	{
		quiz_questions[ idx ] = 0;
	}

	for( idx = 0; idx < MAX_QUESTIONS; idx++ )
	{
		for( opt = 0; opt < MAX_OPTIONS; opt++ )
		{
			quiz_options[ idx ][ opt ] = 0;
		}
	}
}

void engine_random_manager_load()
{
	if( rand_type_normal == hacker_random )
	{
		load_normal();
	}
	else if( rand_type_mixed == hacker_random )
	{
		load_mixed();
	}
	else
	{
		load_random();
	}
}

void engine_random_manager_rand()
{
#ifdef _CONSOLE
	rand();
#else
	random();
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

// Private helper methods.
static void load_random()
{
	unsigned char idx, opt;
	for( idx = 0; idx < MAX_QUESTIONS; idx++ )
	{
		while( 1 )
		{
			unsigned char rnd = engine_random_manager_data( MAX_QUESTIONS );
			if( 0 == quiz_questions[ rnd ] )
			{
				quiz_questions[ rnd ] = idx;
				break;
			}
		}
	}

	for( idx = 0; idx < MAX_QUESTIONS; idx++ )
	{
		for( opt = 0; opt < MAX_OPTIONS; opt++ )
		{
			while( 1 )
			{
				unsigned char rnd = engine_random_manager_data( MAX_OPTIONS );
				if( 0 == quiz_options[ idx ][ rnd ] )
				{
					quiz_options[ idx ][ rnd ] = opt;
					break;
				}
			}
		}
	}
}

static void load_normal()
{
	unsigned char idx, opt;
	for( idx = 0; idx < MAX_QUESTIONS; idx++ )
	{
		quiz_questions[ idx ] = idx;
	}

	for( idx = 0; idx < MAX_QUESTIONS; idx++ )
	{
		for( opt = 0; opt < MAX_OPTIONS; opt++ )
		{
			quiz_options[ idx ][ opt ] = opt;
		}
	}
}

static void load_mixed()
{
	unsigned char idx, opt;
	for( idx = 0; idx < MAX_QUESTIONS; idx++ )
	{
		quiz_questions[ idx ] = idx;
	}

	for( idx = 0; idx < MAX_QUESTIONS; idx++ )
	{
		for( opt = 0; opt < MAX_OPTIONS; opt++ )
		{
			while( 1 )
			{
				unsigned char rnd = engine_random_manager_data( MAX_OPTIONS );
				if( 0 == quiz_options[ idx ][ rnd ] )
				{
					quiz_options[ idx ][ rnd ] = opt;
					break;
				}
			}
		}
	}
}