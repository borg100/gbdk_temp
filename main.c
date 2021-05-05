#include <gb/gb.h>
#include <gb/metasprites.h>
#include "smoke.h"
#include "smoke_struct.h"

UBYTE running = 1;
joypads_t joypads;

#define TILE_SIZE 8


void load_smoke_data(Smoke *smoke, UINT8 first_tile)
{
    // Smoke tiles
    smoke->smoke_tile_index = first_tile;
    set_sprite_data(smoke->smoke_tile_index, 12, smoke_data);
}

void update_smoke(Smoke *smoke, UINT8 x, UINT8 y)
{
    if (smoke->facing_right == 0)
    {
        move_metasprite(
            smoke_metasprites[smoke->smoke_frame_index],
            smoke->smoke_tile_index,
            0,
            x + TILE_SIZE, y - TILE_SIZE);
    }
    else
    {
        move_metasprite_vflip(
            smoke_metasprites[smoke->smoke_frame_index],
            smoke->smoke_tile_index,
            0,
            x - TILE_SIZE, y - TILE_SIZE);
    }
}

void setup_smoke(Smoke *smoke)
{
    smoke->updated = 1;

    // Initial position
    smoke->x = 70;
    smoke->y = 50;

    smoke->facing_right = 0;
    smoke->standing = 1;

    // Smoke
    smoke->smoke_frame_index = 3;
    smoke->smoke_frame_delay = 0;
    smoke->smoke_start_delay = 0;
}

void main(void)
{
    DISPLAY_ON;
    SHOW_BKG;
    SHOW_SPRITES;

    OBP1_REG = 0xE1;
    BGP_REG = 0x1B;
    
    Smoke smoke;

    // Load sprite tiles.
    load_smoke_data(&smoke, 0);

    // Initialize the structs.
    setup_smoke(&smoke);

    joypad_init(1, &joypads);

    while (running)
    {
        joypad_ex(&joypads);

        if (smoke.updated == 1)
        {
            for (UBYTE i = 0; i < 40; i++)
                shadow_OAM[i].y = 0;

            smoke.updated = 0;
            update_smoke(&smoke, smoke.x, smoke.y);
        }

        wait_vbl_done();
    }
}
