//BEGIN HEAD
#include <stdlib.h>
#include "helper.h"

//BEGIN GLOBALS
int running = 1;
int gameState;
enum gameState {IDLE, INTRO, PLAYING, PAUSED, GAME_OVER};
void gameState_check(void);

//State Images
SDL_Texture *IdleImage	 	= NULL;
SDL_Texture *IntroImage		= NULL;
SDL_Texture *PlayingImage	= NULL;
SDL_Texture *PausedImage	= NULL;
SDL_Texture *GameOverImage	= NULL;

SDL_Event event;
//END GLOBALS

//BEGIN FUNCTIONS PROTOTYPES
//BEGIN GAME STATE FUNCTIONS PROTOTYPES
//BEGIN IDLE
void IdleGo(void);
void IdleReady(void);
void IdleSet(void);
void IdleUpdate(void);
void IdleEvents(void);
void IdleDraw(void);
void IdleBye(void);
//END IDLE

//BEGIN INTRO
void IntroGo(void);
void IntroReady(void);
void IntroSet(void);
void IntroUpdate(void);
void IntroEvents(void);
void IntroDraw(void);
void IntroBye(void);
//END INTRO

//BEGIN PLAYING
void PlayingGo(void);
void PlayingReady(void);
void PlayingSet(void);
void PlayingUpdate(void);
void PlayingEvents(void);
void PlayingDraw(void);
void PlayingBye(void);
//END PLAYING

//BEGIN PAUSED
void PausedGo(void);
void PausedReady(void);
void PausedSet(void);
void PausedUpdate(void);
void PausedEvents(void);
void PausedDraw(void);
void PausedBye(void);
//END PAUSED

//BEGIN GAME_OVER
void Game_overGo(void);
void Game_overReady(void);
void Game_overSet(void);
void Game_overUpdate(void);
void Game_overEvents(void);
void Game_overDraw(void);
void Game_overBye(void);
//END GAME_OVER

//END GAME STATE FUNCTIONS PROTOTYPES
//Helper Functions
SDL_bool	LoadFiles();
void		FreeFiles();
//END FUNCTIONS PROTOTYPES
//END HEAD

int main(int argc, char* argv[])
{
(void)argc;
(void)argv;
init();
if (!LoadFiles()){
	SDL_Log("failed to load at least one file...");
	return EXIT_FAILURE;
}


//set first game state
SDL_SetWindowTitle(Window, "IDLE");
gameState = IDLE;

while(running){
	SDL_RenderClear(Renderer);
	gameState_check();
	SDL_RenderPresent(Renderer);
}
FreeFiles();
exit_();
return EXIT_SUCCESS;
}
//BEGIN FUNCTIONS
void gameState_check(void)
{
		switch(gameState)
		{
		case IDLE:
			IdleGo();
			break;
		case INTRO:
			IntroGo();
			break;
		case PLAYING:
			PlayingGo();
			break;
		case PAUSED:
			PausedGo();
			break;
		case GAME_OVER:
			Game_overGo();
			break;
		default:
		break;
    		}
}

//BEGIN GAME STATE FUNCTIONS
//BEGIN IDLE
void IdleGo(void)
{
	IdleEvents();
	IdleUpdate();
	IdleDraw();
}

void IdleReady(void)
{
;
}

void IdleSet(void)
{
;
}

void IdleUpdate(void)
{
;
}

void IdleEvents(void)
{
	while(SDL_PollEvent(&event)){
		if(event.type == SDL_QUIT){
			running = 0;
		}
		if(event.type == SDL_MOUSEBUTTONDOWN){
			if(event.button.button == SDL_BUTTON_LEFT){
				SDL_SetWindowTitle(Window, "INTRO");
				gameState = INTRO;
				gameState_check();
			}
		}
	}
}

void IdleDraw(void)
{

	SDL_RenderCopy(Renderer, IdleImage, NULL, NULL);
}

void IdleBye(void)
{
;
}

//END IDLE

//BEGIN INTRO
void IntroGo(void)
{
	IntroEvents();
	IntroUpdate();
	IntroDraw();
}

void IntroReady(void)
{
;
}

void IntroSet(void)
{
;
}

void IntroUpdate(void)
{
;
}

void IntroEvents(void)
{
	while(SDL_PollEvent(&event)){
		if(event.type == SDL_QUIT){
			running = 0;
		}
		if(event.type == SDL_MOUSEBUTTONDOWN){
			if(event.button.button == SDL_BUTTON_LEFT){
				SDL_SetWindowTitle(Window, "PLAYING");
				PlayingSet();
				gameState = PLAYING;
				gameState_check();
			}
			
		}
		
	}
}

void IntroDraw(void)
{

	SDL_RenderCopy(Renderer, IntroImage, NULL, NULL);
}

void IntroBye(void)
{
;
}

//END INTRO

//BEGIN PLAYING
void PlayingGo(void)
{
	PlayingEvents();
	PlayingUpdate();
	PlayingDraw();
}

void PlayingReady(void)
{
;
}

void PlayingSet(void)
{
;
}

void PlayingUpdate(void)
{
;
}

void PlayingEvents(void)
{
	while(SDL_PollEvent(&event)){
		if(event.type == SDL_QUIT){
			running = 0;
		}
		if(event.type == SDL_MOUSEBUTTONDOWN){
			if(event.button.button == SDL_BUTTON_LEFT){
				SDL_SetWindowTitle(Window, "PAUSED");
				gameState = PAUSED;
			}
			if(event.button.button == SDL_BUTTON_RIGHT){
				SDL_SetWindowTitle(Window, "GAME OVER");
				gameState = GAME_OVER;
			}
			gameState_check();
		}
		
	}
}

void PlayingDraw(void)
{
	SDL_RenderCopy(Renderer, PlayingImage, NULL, NULL);
}

void PlayingBye(void)
{
;
}

//END PLAYING

//BEGIN PAUSED
void PausedGo(void)
{
	PausedEvents();
	PausedUpdate();
	PausedDraw();
}

void PausedReady(void)
{
;
}

void PausedSet(void)
{
;
}

void PausedUpdate(void)
{
;
}

void PausedEvents(void)
{
	while(SDL_PollEvent(&event)){
		if(event.type == SDL_QUIT){
			running = 0;
		}
		if(event.type == SDL_MOUSEBUTTONDOWN){
			if(event.button.button == SDL_BUTTON_LEFT){
				SDL_SetWindowTitle(Window, "PLAYING");
				gameState = PLAYING;
				break;
			}
			if(event.button.button == SDL_BUTTON_RIGHT){
				SDL_SetWindowTitle(Window, "PLAYING");
				gameState = PLAYING;
				break;
			}
		}
	}
}

void PausedDraw(void)
{

SDL_RenderCopy(Renderer, PausedImage, NULL, NULL);

}

void PausedBye(void)
{
;
}

//END PAUSED

//BEGIN GAME_OVER
void Game_overGo(void)
{
	Game_overEvents();
	Game_overUpdate();
	Game_overDraw();
}

void Game_overReady(void)
{
;
}

void Game_overSet(void)
{
;
}

void Game_overUpdate(void)
{
;
}

void Game_overEvents(void)
{
	while(SDL_PollEvent(&event)){
		if(event.type == SDL_QUIT){
			running = 0;
		}
		if(event.type == SDL_MOUSEBUTTONDOWN){
			if(event.button.button == SDL_BUTTON_LEFT){
				gameState = IDLE;
				gameState_check();
			}
			
		}
	}
}

void Game_overDraw(void)
{

	SDL_RenderCopy(Renderer, GameOverImage, NULL, NULL);

}

void Game_overBye(void)
{
;
}

//END GAME_OVER

//END GAME STATE FUNCTIONS

//BEGIN HELPER
SDL_bool LoadFiles(void)
{
	
	//BEGIN STATE BACKGROUNDS
	SDL_Surface *surface    = NULL;
	surface = IMG_Load("./idle.png");
	IdleImage = SDL_CreateTextureFromSurface( Renderer, surface );
	if(IdleImage == NULL){
		SDL_Log("IdleImage failed");
		return SDL_FALSE;
	}
	
	surface = IMG_Load("./intro.png");
	IntroImage = SDL_CreateTextureFromSurface( Renderer, surface );
	if(IntroImage == NULL){
		SDL_Log("IntroImage failed");
		return SDL_FALSE;
	}
	
	surface = IMG_Load("./playing.png");
	PlayingImage = SDL_CreateTextureFromSurface( Renderer, surface );
	if(PlayingImage == NULL){
		SDL_Log("PlayingImage failed");
		return SDL_FALSE;
	}
	
	surface = IMG_Load("./paused.png");
	PausedImage = SDL_CreateTextureFromSurface( Renderer, surface );
	if(PausedImage == NULL){
		SDL_Log("PausedImage failed");
		return SDL_FALSE;
	}
	
	surface = IMG_Load("./GameOver.png");
	GameOverImage = SDL_CreateTextureFromSurface( Renderer, surface );
	if(GameOverImage == NULL){
		SDL_Log("GameOverImage failed");
		return SDL_FALSE;
	}
	SDL_FreeSurface(surface);
	//END STATE BACKGROUNDS
	
	return SDL_TRUE;
	
}

void FreeFiles(void)
{
	//Free Textures
	if(IdleImage != NULL)
		SDL_DestroyTexture(IdleImage);
	if(IntroImage != NULL)
		SDL_DestroyTexture(IntroImage);
	if(PlayingImage != NULL)
		SDL_DestroyTexture(PlayingImage);
	if(PausedImage != NULL)
		SDL_DestroyTexture(PausedImage);
	if(GameOverImage != NULL)
		SDL_DestroyTexture(GameOverImage);
}
//END HELPER
//END FUNCTIONS
