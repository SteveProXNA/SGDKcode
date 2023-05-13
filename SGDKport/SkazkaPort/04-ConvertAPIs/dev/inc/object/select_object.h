#ifndef __SELECT_OBJECT_H__
#define __SELECT_OBJECT_H__

#include "global_manager.h"

typedef struct tag_struct_aelect_object
{
	unsigned char select_index[ MAX_SELECTS ];
	unsigned char select_X;
	unsigned char select_Y;
	unsigned char select_min;
	unsigned char select_max;

} struct_select_object;

#endif//__SELECT_OBJECT_H__
