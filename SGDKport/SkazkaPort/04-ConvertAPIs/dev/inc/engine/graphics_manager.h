#ifndef _GRAPHICS_MANAGER_H_
#define _GRAPHICS_MANAGER_H_

void engine_graphics_manager_init();
void engine_graphics_manager_load();
void engine_graphics_manager_clear_full();
void engine_graphics_manager_clear_part();

void engine_graphics_manager_draw_border();
void engine_graphics_manager_draw_borderX( unsigned char left, unsigned char top, unsigned char wide, unsigned char high );
void engine_graphics_manager_draw_underline();
void engine_graphics_manager_draw_splash();
void engine_graphics_manager_draw_logo_big( unsigned char x, unsigned char y );
void engine_graphics_manager_draw_logo_small( unsigned char x, unsigned char y );
void engine_graphics_manager_draw_village( unsigned char x, unsigned char y );
void engine_graphics_manager_draw_koschey( unsigned char x, unsigned char y, unsigned char palette );
void engine_graphics_manager_draw_inventory( unsigned char x, unsigned char y );

#endif//_GRAPHICS_MANAGER_H_