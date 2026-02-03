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
#include <stdio.h>

#include "gamestate.h"
#include "draw.h"
#include "main.h"

#include "archive.h"

#include "raylib.h"

uint8_t worldMap[WORLD_WIDTH][WORLD_HEIGHT] =
{
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,1,1,1,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,2,0,0,0,0,0,1},
  {1,0,1,1,1,0,0,0,0,2,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,2,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,2,2,2,0,0,0,1},
  {1,0,0,0,0,3,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,3,3,3,0,0,0,4,0,0,0,0,1},
  {1,0,0,0,0,3,0,0,0,0,4,4,4,4,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,4,0,0,0,1},
  {1,0,0,0,0,0,0,0,4,4,4,4,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

void(*loopfunc)(void);

int main()
{
    int ret_code;

    // set loop func to the transition state of the first state 
    loopfunc = OnGameLoop;
    
    InitWindow(screenWidth, screenHeight, "Moonbeam");
    SetTargetFPS(refreshRate);

    if(!LoadPackFile())
    {
        ret_code = -1;
        goto shutdown;
    }

    while (!WindowShouldClose())
    {
        BeginDrawing();
        loopfunc();
        EndDrawing();
    }

    ret_code = 0;

shutdown:
    ClosePackFile();
    CloseWindow();
    return ret_code;
}

