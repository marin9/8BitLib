#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include "graphic.h"
#include "audio.h"


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

void system_exit(int ret){
	SDL_Quit();
	exit(ret);
}

int system_getrand(){
	return rand();
}
