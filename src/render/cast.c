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

#include "draw.h"

void RayLoop(float pDirX, float pDirY)
{
    float camX;
    float dirX, dirY;

    // cast ray for each horizontal pixel of screen
    for(int x = 0; x < screenWidth; x++)
    {
        camX = 2 * x / (float)screenWidth - 1;
        
    }
}