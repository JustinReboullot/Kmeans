#include "graphical_functions.h"



void makeGrid(SDL_Surface* screen, const int screen_width, const int screen_height)
{
	for (int x = 10; x < screen_width; x += 10)
	{
		lineRGBA(screen, x, 0, x, screen_height, 0, 0, 0, 255);
	}
	for (int y = 10; y < screen_height; y += 10)
	{
		lineRGBA(screen, 0, y, screen_width, y, 0, 0, 0, 255);
	}
}

int convertX (const double x, const int screen_width)
{
	return 10*x + screen_width/2;
}

int convertY (const double y, const int screen_height)
{
	return -10*y + screen_height/2;
}
