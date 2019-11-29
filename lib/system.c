#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include "graphic.h"
#include "audio.h"
#include "input.h"


void system_init(){
	if(SDL_Init(SDL_INIT_EVERYTHING)){
		printf("ERROR: sdl_init: %s\n", SDL_GetError());
		SDL_Quit();
		exit(1);
	}
	srand(time(0));
	graphic_init(2);
	audio_init();
}

void system_sleep(int ms){
	SDL_Delay(ms);
}

void system_pause(int s){
	s *= 10;
	while(s--){
		input_getkey();
		graphic_refresh();
		SDL_Delay(100);
	}
}

void system_exit(){
	graphic_clean();
	audio_clean();
	SDL_Quit();
	exit(0);
}

int system_getticks(){
	return SDL_GetTicks();
}

int system_getrand(){
	return rand();
}
