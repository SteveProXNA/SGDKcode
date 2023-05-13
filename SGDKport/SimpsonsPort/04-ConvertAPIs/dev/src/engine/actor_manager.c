#include "actor_manager.h"
#include "../engine/global_manager.h"
#include "../engine/image_manager.h"
#include "../engine/random_manager.h"

static unsigned char prevActor;
static unsigned char currActor;

void engine_actor_manager_init()
{
	prevActor = 0;
	currActor = 0;
}

void engine_actor_manager_load()
{
	while( 1 )
	{
		currActor = engine_random_manager_data( MAX_ACTORS );
		if( currActor != prevActor )
		{
			break;
		}
	}

	engine_image_manager_draw_actor( currActor );
	prevActor = currActor;
}

void engine_actor_manager_draw( unsigned char index )
{
	engine_image_manager_draw_actor( index );
}