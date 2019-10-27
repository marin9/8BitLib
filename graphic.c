#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include "font.h"
#include "graphic.h"


#define WINDOW_HEIGHT	128
#define WINDOW_WIDTH	128

static int px_size;
static int font_size;
static SDL_Window *window;
static SDL_Renderer *rend;

struct color{
	int r;
	int g;
	int b;
} colors[] = {
	{0x00, 0x00, 0x00},
	{0x00, 0x00, 0xAA},
	{0x00, 0xAA, 0x00},
	{0x00, 0xAA, 0xAA},
	{0xAA, 0x00, 0x00},
	{0xAA, 0x00, 0xAA},
	{0xAA, 0x55, 0x00},
	{0xAA, 0xAA, 0xAA},

	{0x55, 0x55, 0x55},
	{0x55, 0x55, 0xFF},
	{0x55, 0xFF, 0x55},
	{0x55, 0xFF, 0xFF},
	{0xFF, 0x55, 0x55},
	{0xFF, 0x55, 0xFF},
	{0xFF, 0xFF, 0x55},
	{0xFF, 0xFF, 0xFF},
};



void graphic_init(int psize){
	SDL_Init(SDL_INIT_VIDEO);

	px_size=psize;
	font_size=1;

	window=SDL_CreateWindow(
		"Mini Games",
    	SDL_WINDOWPOS_UNDEFINED,
    	SDL_WINDOWPOS_UNDEFINED,
    	WINDOW_WIDTH*px_size,
    	WINDOW_HEIGHT*px_size,
    	SDL_WINDOW_SHOWN
	);
	if(!window){   
		printf("ERROR: graphic init: %s\n", SDL_GetError());
	    SDL_Quit();
		exit(1);
	}

	rend=SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if(!rend){
		printf("ERROR: graphic init: %s\n", SDL_GetError());
    	SDL_DestroyWindow(window);
		SDL_Quit();
		exit(2);
	}
}

void graphic_clear(int c){
	SDL_Rect rect;
	rect.x=0;
	rect.y=0;
	rect.w=WINDOW_HEIGHT*px_size;
	rect.h=WINDOW_HEIGHT*px_size;

	graphic_setcolor(c);
	SDL_RenderFillRect(rend, &rect);
}

void graphic_setcolor(int c){
	SDL_SetRenderDrawColor(rend, colors[c].r, colors[c].g, colors[c].b, 255);
}

void graphic_setfontsize(int s){
	font_size=s;
}

void graphic_setpixel(int x, int y){
	SDL_Rect rect;
	rect.x=x*px_size;
	rect.y=y*px_size;
	rect.w=px_size;
	rect.h=px_size;

	SDL_RenderFillRect(rend, &rect);
}

void graphic_drawrect(int x, int y, int w, int h){
	SDL_Rect rect;
	rect.x=x*px_size;
	rect.y=y*px_size;
	rect.w=w*px_size;
	rect.h=h*px_size;

	SDL_RenderFillRect(rend, &rect);
}

void graphic_drawsprite(int x, int y, int w, int h, char *s){
	int i, j;
	SDL_Rect rect;

	for(i=x;i<x+w;++i){
		for(j=y;j<y+h;++j){
			rect.x=i*px_size;
			rect.y=j*px_size;
			rect.w=px_size;
			rect.h=px_size;

			if(s[i-x+(j-y)*w] != -1){
				graphic_setcolor(s[i-x+(j-y)*w]);
				SDL_RenderFillRect(rend, &rect);
			}
		}
	}
}

void graphic_drawchar(int x, int y, char c){
	int i, j;
	SDL_Rect rect;

	for(i=x;i<x+FONT_WIDTH;++i){
		for(j=y;j<y+FONT_HEIGHT;++j){
			rect.x=i*px_size*font_size;
			rect.y=j*px_size*font_size;
			rect.w=px_size*font_size;
			rect.h=px_size*font_size;

			if(font[c-32][i-x+(j-y)*FONT_WIDTH]){
				SDL_RenderFillRect(rend, &rect);
			}
		}
	}

}

void graphic_drawtext(int x, int y, char *s){
	int i=0;

	while(s[i]){
		graphic_drawchar(x+i*(FONT_WIDTH+1), y, s[i]);
		++i;
	}
}

void graphic_refresh(){
	SDL_RenderPresent(rend);
}

void graphic_close(){
	SDL_DestroyRenderer(rend);
	SDL_DestroyWindow(window);
	SDL_Quit();
}
