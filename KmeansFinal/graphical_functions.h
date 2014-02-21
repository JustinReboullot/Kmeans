#pragma once

#include "SDL.h"
#include "SDL_image.h"
#include "SDL_gfxPrimitives.h"
#include <string>

void makeGrid(SDL_Surface* screen, const int screen_width, const int screen_height);

int convertX (const double x, const int screen_width);

int convertY (const double y, const int screen_height);