#ifndef _QUIZ_MANAGER_H_
#define _QUIZ_MANAGER_H_

#include "global_manager.h"

extern unsigned char quiz_questions[ MAX_QUESTIONS ];
extern unsigned char quiz_options[ MAX_QUESTIONS ][ MAX_OPTIONS ];
extern unsigned char option_height[ MAX_OPTIONS ];
extern unsigned char question_index, question_long, question_count;
extern unsigned char question_value, option1_value, option2_value, option3_value, option4_value;
extern unsigned char answer_index, answer_value;

// Public methods.
void engine_quiz_manager_init();
void engine_quiz_manager_base();
void engine_quiz_manager_base2();
void engine_quiz_manager_base3( unsigned char y );
void engine_quiz_manager_answer( unsigned char q );
void engine_quiz_manager_cheat( unsigned char ans );
void engine_quiz_manager_cheat2( unsigned char ans, unsigned char flag );
void engine_quiz_manager_load( unsigned char qi, unsigned char qv, unsigned char opt1, unsigned char opt2, unsigned char opt3, unsigned char opt4 );

#endif//_QUIZ_MANAGER_H_
