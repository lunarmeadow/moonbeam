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

#include "player.h"
#include "main.h"
#include "cast.h"
#include "draw.h"

#include "raylib.h"

int screenWidth = 1280;
int screenHeight = 960;
int refreshRate = 60;

// draw "floors" and "ceilings"
void ParallaxLoop(player_t* pobj, render_t* render)
{
    // 256 pixel overscan
    int ceilingStart = -256;
    int ceilingEnd = ((screenHeight / 2) + pobj->angZ) - (render->minHeight / 2) + 256;
    int floorStart = (ceilingEnd - 256) + render->minHeight / 2;
    int floorEnd = screenHeight + 256;

    DrawRectangleGradientV(0, ceilingStart, screenWidth, ceilingEnd, GRAY, BLACK);
    DrawRectangleGradientV(0, floorStart, screenWidth, floorEnd, BLACK, GRAY);
}