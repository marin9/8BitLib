#include <SDL2/SDL.h>
#include "input.h"


int input_getkey(){
	SDL_Event event;

	if(!SDL_PollEvent(&event)){
		return NO_INPUT;
	}

	if(event.type==SDL_QUIT){
		return KEY_EXIT;
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
				return KEY_UNKNOWN;
		}
	}
	return NO_INPUT;
}
