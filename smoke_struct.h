// #ifndef SMOKE_H //if its not defined, then proceed to line 2 and define it.
// #define SMOKE_H
//pragma once is a stronger method to ifndef <-> endif
//#pragma once
#include <gb/gb.h>

typedef struct Smoke
{
    UBYTE updated;

    UINT8 x;
    UINT8 y;

    UBYTE facing_right;
    UBYTE standing;

    // Smoke Metasprite
    UINT8 smoke_tile_index;
    UINT8 smoke_frame_index;
    UINT8 smoke_frame_delay;
    UINT8 smoke_start_delay;

} Smoke;
// #endif
//sort of like an end } of an if statement. If it is defined above, it will not be copied again