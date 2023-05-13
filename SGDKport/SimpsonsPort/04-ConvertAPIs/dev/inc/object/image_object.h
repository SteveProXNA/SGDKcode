#ifndef __IMAGE_OBJECT_H__
#define __IMAGE_OBJECT_H__

#include "global_manager.h"

#ifdef _CONSOLE
#include "_genesis.h"
#else
#include <genesis.h>
#endif

extern const Image *image_actor[ MAX_ACTORS ];

#endif//__IMAGE_OBJECT_H__