#include "helper.h"
SDL_Window   *Window=NULL;
SDL_Renderer *Renderer=NULL;


void init(void)
{
SDL_Init(SDL_INIT_EVERYTHING);
Window = SDL_CreateWindow("States",
			      SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 512, 512, SDL_WINDOW_HIDDEN);
//BEGIN ICON
SDL_Surface *icon;
icon = SDL_LoadBMP("./SDL2.bmp");
SDL_SetWindowIcon(Window, icon);
SDL_FreeSurface(icon);
//END ICON

Renderer = SDL_CreateRenderer(Window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

SDL_ShowWindow(Window);
SDL_SetRenderDrawColor( Renderer, 110, 110, 110, 255 );
SDL_RenderClear(Renderer);
SDL_RenderPresent(Renderer);

}

void exit_(void)
{

TTF_Quit();
SDL_DestroyRenderer(Renderer);
SDL_DestroyWindow(Window);
SDL_Quit();

}


