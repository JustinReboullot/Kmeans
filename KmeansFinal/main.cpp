//The headers
#include "SDL.h"
#include "SDL_gfxPrimitives.h"
#include "graphical_functions.h"
#include "Kmeans.h"
#include <vector>
#include <iostream>
#include <string>
using namespace std;

//Screen attributes
const int  SCREEN_WIDTH = 800; //SCREEN_WIDTH/10 doit être paire !
const int SCREEN_HEIGHT = 460; //SCREEN_HEIGHT/10 doit être paire !
const int SCREEN_BPP = 32;

//The surfaces
SDL_Surface *points = NULL;
SDL_Surface *screen = NULL;

//The event structure
SDL_Event event;


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
	//Define the colors of each groups. Can only go to 5 groups !!
	Uint8 groupColors[5][3];
	groupColors[0][0] = 255;
	groupColors[0][1] = 0;
	groupColors[0][2] = 0;
	groupColors[1][0] = 0;
	groupColors[1][1] = 0;
	groupColors[1][2] = 255;
	groupColors[2][0] = 0;
	groupColors[2][1] = 255;
	groupColors[2][2] = 0;
	groupColors[3][0] = 255;
	groupColors[3][1] = 0;
	groupColors[3][2] = 255;
	groupColors[4][0] = 0;
	groupColors[4][1] = 255;
	groupColors[4][2] = 255;


	SDL_FillRect( screen, &screen->clip_rect, SDL_MapRGB( screen->format, 0xFF, 0xFF, 0xFF ) );
 
	makeGrid(screen, SCREEN_WIDTH, SCREEN_HEIGHT); //Generate a grid. We can put (SCREEN_WIDTH/10 - 1)(SCREEN_HEIGHT/10 - 1) on this grid.

		for (int n = 0; n < Km._N; n++)
			{
				for (int k = 0; k < Km._K; k++)
				{
					if ( Km._gpIndex[n] == k )
					{
						filledEllipseRGBA(screen, convertX(Km._data[n][0], SCREEN_WIDTH), convertY(Km._data[n][1], SCREEN_HEIGHT), 5, 5, groupColors[k][0], groupColors[k][1], groupColors[k][2], 100);
					}
				}
			}
		for (int k =0; k < Km._K; k++)
		{
			filledEllipseRGBA(screen, convertX(Km._centroids[k][0], SCREEN_WIDTH), convertY(Km._centroids[k][1], SCREEN_HEIGHT), 5, 5, groupColors[k][0], groupColors[k][1], groupColors[k][2], 255);
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
	// definition des chemins
	// Les chemins étant relatifs, il faut que les deux fichiers de données soient
	// dans le même dossier que celui du code.
	string data;
	string centroids;
	/// Precisez l'adresse des fichiers contenant les données et les centroids.

	// Le fichier (data) contenant la données doit contenir comme premier élément
	// le nombre de ligne et comme second le nombre de colonnes puis les données.

    data = "base.txt";
	
    // Le fichier (centroids) contenant les centroids initiaux doit contenir 
    // comme premier élément le nombre de centroids puis les centroids.
	centroids = "centroids.txt";

	//The maths part !
	Kmeans Km(data,centroids); 

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
