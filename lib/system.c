#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>


void system_init(){
	if(SDL_Init(SDL_INIT_EVERYTHING)){
		printf("ERROR: sdl_init: %s\n", SDL_GetError());
		SDL_Quit();
		exit(1);
	}
	srand(time(0));
}

void system_sleep(int ms){
	SDL_Delay(ms);
}

void system_exit(){
	SDL_Quit();
	exit(0);
}

int system_getticks(){
	return SDL_GetTicks();
}

int system_getrand(){
	return rand();
}
