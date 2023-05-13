#include "none_screen.h"
#include "../engine/enum_manager.h"
#include "../engine/font_manager.h"

void screen_none_screen_load()
{
	engine_font_manager_text( "NONE SCREEN!!", 10, 2 );
}

void screen_none_screen_update( unsigned char *screen_type )
{
	*screen_type = screen_type_none;
}
