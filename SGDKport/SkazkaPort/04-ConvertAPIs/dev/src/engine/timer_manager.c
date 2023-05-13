#include "timer_manager.h"
#include "hack_manager.h"

// Global variable.
struct_timer_object global_timer_object;

void engine_timer_manager_load( unsigned int delay )
{
	struct_timer_object *dObj = &global_timer_object;
	struct_hack_object *ho = &global_hack_object;
	dObj->timer_count = 0;
	dObj->timer_value = delay;

	// Used for testing so no wait.
	if( ho->hack_delays )
	{
		dObj->timer_value = 0;
	}
}

unsigned char engine_timer_manager_update()
{
	struct_timer_object *dObj = &global_timer_object;
	unsigned char test;

	dObj->timer_count++;
	test = dObj->timer_count >= dObj->timer_value;
	if( test )
	{
		dObj->timer_count = 0;
	}

	return test;
}