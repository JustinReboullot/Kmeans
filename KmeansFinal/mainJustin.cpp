/*This source code copyrighted by Lazy Foo' Productions (2004-2013)
and may not be redistributed without written permission.*/
#define N1 10
#define D1 2
#define K1 2

//The headers
#include <vector>
#include "SDL.h"
#include "SDL_gfxPrimitives.h"
#include "graphical_functions.h"
#include "data_generation_functions.h"
#include "Kmeans.h"
#include <iostream>
#include <fstream>//It was to debug code : should not be ther if it is.
using namespace std;

//It was to debug code : should not be ther if it is. 
ofstream dout("C:\\Users\\Justin\\Desktop\\debug.txt");

//Screen attributes
const int  SCREEN_WIDTH = 800; //SCREEN_WIDTH/10 doit être paire !
const int SCREEN_HEIGHT = 460; //SCREEN_HEIGHT/10 doit être paire !
const int SCREEN_BPP = 32;

//The surfaces
SDL_Surface *points = NULL;
SDL_Surface *screen = NULL;

//The event structure
SDL_Event event;

//The portions of the sprite map to be blitted
SDL_Rect clip[ 4 ];


//To initialize what has to be initialized.
bool init()
{
    //Initialize all SDL subsystems
    if( SDL_Init( SDL_INIT_EVERYTHING ) == -1 )
    {
        return false;
    }

    //Set up the screen
    screen = SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE );

    //If there was an error in setting up the screen
    if( screen == NULL )
    {
        return false;
    }

    //Set the window caption
    SDL_WM_SetCaption( "Kmeans", NULL );

    //If everything initialized fine
    return true;
}


//Draw a grid and the different points.
void FillScreenData(SDL_Surface* screen, const Kmeans& Km)
{
	SDL_FillRect( screen, &screen->clip_rect, SDL_MapRGB( screen->format, 0xFF, 0xFF, 0xFF ) );
 
	makeGrid(screen, SCREEN_WIDTH, SCREEN_HEIGHT); //Generate a grid. We can put (SCREEN_WIDTH/10 - 1)(SCREEN_HEIGHT/10 - 1) on this grid.


		for (int k = 0; k < K1; k++)
		{
			for (int n = 0; n < N1; n++)
				{
					switch (Km._gpIndex[n])
					{
						case 0:
							filledEllipseRGBA(screen, convertX(Km._data[n][0], SCREEN_WIDTH), convertY(Km._data[n][1], SCREEN_HEIGHT), 5, 5, 255, 0, 0, 255);
							break;
						case 1:
							filledEllipseRGBA(screen, convertX(Km._data[n][0], SCREEN_WIDTH), convertY(Km._data[n][1], SCREEN_HEIGHT), 5, 5, 0, 0, 255, 255);
							break;
					}
				}
			filledEllipseRGBA(screen, convertX(Km._centroids[k][0], SCREEN_WIDTH), convertY(Km._centroids[k][1], SCREEN_HEIGHT), 5, 5, 150, 150, 150, 255);
		}

}

//Handle when one presses the right arrow on keyboard. Takes in entry whether to do FindGroup or FindCentroids.
//Returns whether to do FindGroup the next time or not
bool handlePressKeyRight(bool DoFindGroup, Kmeans& Km)
{
	if( event.type == SDL_KEYDOWN )
		{
			if( event.key.keysym.sym == SDLK_RIGHT)
				{
					if( DoFindGroup )
					{
						Km.FindGroup();
						DoFindGroup = 0;
					}
					else
					{
						Km.FindCentroids();
						DoFindGroup = 1;
					}
				}
		}
	return DoFindGroup;
}




int main( int argc, char* args[] )
{
	double data[N1][D1];
	for (int i = 0 ; i < 5 ; i++)
	{
		data[i][0] = 1 + 2*double(i);
		data[i][1] = 1 + 2*double(i);
	}
	for (int i = 5 ; i < 10 ; i++)
	{
		data[i][0] = -1 - 2*double(i - 5);
		data[i][1] = -1 - 2*double(i - 5);
	}


	double centroids[K1][D1];
	centroids[0][0] = -10;
	centroids[0][1] = -10;
	centroids[1][0] = 10;
	centroids[1][1] = 10;

	//The maths part !
	Kmeans Km(data,centroids,D1,N1,K1); 	

    //Quit flag
    bool quit = false;

    //Initialize
    if( init() == false )
    {
        return 1;
    }

	//Update the screen
    if( SDL_Flip( screen ) == -1 )
    {
         return 1;    
    }
	
	//Boolean which tell whether FindGroup has been done before or FindCentroids : 0 if FindCentroids has been done before, 1 otherwise.
	bool DoFindGroup = 1;

    //While the user hasn't quit
    while( quit == false )
    {
        //If there's events to handle
        while( SDL_PollEvent( &event ) )
        {
			DoFindGroup = handlePressKeyRight(DoFindGroup, Km); //Handle key pressing.

            //If the user has Xed out the window
            if( event.type == SDL_QUIT )
            {
                //Quit the program
                quit = true;
            }    
        }

		//Fill the screen white
		FillScreenData(screen,Km);		

		//Update the screen
		if( SDL_Flip( screen ) == -1 )
		{
			 return 1;    
		}
    }

    //Quit SDL
    SDL_Quit();

    return 0;
}
