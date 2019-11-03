#include <SDL2/SDL.h>
#include <stdlib.h>
#include "input.h"


int input_getkey(){
	SDL_Event event;

	if(!SDL_PollEvent(&event)){
		return NO_INPUT;
	}

	if(event.type==SDL_QUIT){
		SDL_Quit();
		exit(0);
	}

	if(event.type==SDL_KEYDOWN){
		switch(event.key.keysym.sym){
		case SDLK_UP:
			return KEY_UP;
		case SDLK_DOWN:
			return KEY_DOWN;
		case SDLK_LEFT:
			return KEY_LEFT;
		case SDLK_RIGHT:
			return KEY_RIGHT;
		case SDLK_SPACE:
			return KEY_SPACE;
		case SDLK_ESCAPE:
			return KEY_ESC;
		case SDLK_RETURN:
			return KEY_ENTER;
		default:
			break;
		}
	}
	return NO_INPUT;
}

int input_getmouse(int *x, int *y){
	SDL_Event event;

	if(!SDL_PollEvent(&event)){
		return NO_INPUT;
	}

	if(event.type==SDL_QUIT){
		SDL_Quit();
		exit(0);
	}

	SDL_GetMouseState(x, y);

	if(event.type==SDL_MOUSEBUTTONDOWN){
		switch(event.button.button){
		case SDL_BUTTON_LEFT:
			return MOUSE_LEFT;
		case SDL_BUTTON_RIGHT:
			return MOUSE_RIGHT;
		default:
			break;
		}
	}
	return NO_INPUT;
}
