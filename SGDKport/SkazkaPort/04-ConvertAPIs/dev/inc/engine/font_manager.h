#ifndef _FONT_MANAGER_H_
#define _FONT_MANAGER_H_

void engine_font_manager_draw_char( const unsigned char ch, unsigned char x, unsigned char y );
void engine_font_manager_draw_numb( const unsigned char ch, unsigned char x, unsigned char y );
void engine_font_manager_draw_punc( const unsigned char ch, unsigned char x, unsigned char y );
void engine_font_manager_draw_text( char *text, unsigned char x, unsigned char y );
void engine_font_manager_draw_data( unsigned int data, unsigned char x, unsigned char y );
void engine_font_manager_draw_zero( unsigned int data, unsigned char x, unsigned char y );

#endif//_FONT_MANAGER_H_