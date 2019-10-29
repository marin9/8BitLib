#include <SDL2/SDL.h>
#include "keyboard.h"


int keyboard_getkey(){
	SDL_Event event;

	if(!SDL_PollEvent(&event)){
		return NO_KEY;
	}

	if(event.type==SDL_QUIT){
		return EXIT;
	}

	if(event.type==SDL_KEYDOWN){
		switch(event.key.keysym.sym){
			case SDLK_UP:
				return UP;
			case SDLK_DOWN:
				return DOWN;
			case SDLK_LEFT:
				return LEFT;
			case SDLK_RIGHT:
				return RIGHT;
			case SDLK_SPACE:
				return SPACE;
			case SDLK_ESCAPE:
				return ESC;
			case SDLK_RETURN:
				return ENTER;
			default:
				return UNKNKEY;
		}
	}
	return NO_KEY;
}
