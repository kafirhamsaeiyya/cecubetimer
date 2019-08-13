// convpng v7.1
// this file contains all the graphics sources for easy inclusion in a project
#ifndef __logo_gfx__
#define __logo_gfx__
#include <stdint.h>

#define logo_gfx_transparent_color_index 0

#define rubikcube_width 60
#define rubikcube_height 60
#define rubikcube_size 3602
extern uint8_t rubikcube_data[3602];
#define rubikcube ((gfx_sprite_t*)rubikcube_data)
#define sizeof_logo_gfx_pal 512
extern uint16_t logo_gfx_pal[256];

#endif
