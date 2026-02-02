/*
    Copyright (C) 2026 lunarmeadow (she/her)

    This program is free software; you can redistribute it and/or
    modify it under the terms of the GNU General Public License
    as published by the Free Software Foundation; either version 3
    of the License, or (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#include <stdint.h>

#include "render/draw.h"

#include "raylib.h"

#define WORLD_WIDTH 16
#define WORLD_HEIGHT 16

uint8_t worldMap[WORLD_WIDTH][WORLD_HEIGHT]=
{
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1},
  {1,0,0,0,1,1,0,1,0,0,1,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1},
  {1,0,0,0,1,1,1,1,1,0,1,0,0,0,0,1},
  {1,0,0,0,1,0,0,0,1,1,1,0,0,1,0,1},
  {1,0,0,0,1,0,0,0,0,0,0,0,0,1,0,1},
  {1,0,0,0,1,0,0,0,0,0,0,0,0,1,0,1},
  {1,0,0,0,1,0,0,0,0,0,0,0,0,1,0,1},
  {1,0,0,0,0,0,0,0,0,1,1,1,1,1,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

typedef struct player {
    int posX, posY;
    int angX, angY;
} player_t;

int main()
{
    InitWindow(screenWidth, screenHeight, "Test Window");
    SetTargetFPS(refreshRate);

    player_t player;

    player.posX = player.posY = 3;
    player.angX = -1;
    player.angY = 0;

    while (!WindowShouldClose()) 
    {
        BeginDrawing();
        
        ClearBackground(RAYWHITE);
        
        EndDrawing();
    }

    CloseWindow();
}