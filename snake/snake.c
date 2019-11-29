#include "audio.h"
#include "input.h"
#include "system.h"
#include "graphic.h"
#include "sprites.h"
#include <stdio.h>
#include <stdlib.h>

#define FIELD_W		24
#define FIELD_H		16
#define MAX_LEVEL	16

static int end;
static int ort;
static int pause;
static int score;
static int level;
static int length;
static int counter;
static char snake[FIELD_W*FIELD_H][2];
static char food[2];


void game_init();
void game_input();
void game_tick();
void game_render();
void eat_food();
void generate_food();


int main(int argc, char **argv){
	if(argc==2){
		level=atoi(argv[1]);
	}
	if(level<0 || level>MAX_LEVEL){
		level=1;
	}

	system_init();
	game_init();
	game_render();
	system_pause(2);

	while(1){
		game_input();
		game_tick();
		game_render();
		system_sleep(10);
	}

	system_exit();
	return 0;
}

void game_init(){
	end=0;
	pause=0;
	score=0;
	ort=KEY_RIGHT;
	counter=20-level;
	length=4;
	snake[0][0]=12;
	snake[0][1]=8;
	snake[1][0]=11;
	snake[1][1]=8;
	snake[2][0]=10;
	snake[2][1]=8;
	snake[3][0]=9;
	snake[3][1]=8;

	generate_food();
}

void game_input(){
	int key=input_getkey();

	switch(key){
	case KEY_ESC:
		system_exit();
	case KEY_ENTER:
		if(end)
			game_init();
		else
			pause = !pause;
		break;
	case KEY_RIGHT:
	case KEY_LEFT:
	case KEY_DOWN:
	case KEY_UP:
		if(!pause && !end)
			ort=key;
		break;
	}
}

void game_tick(){
	if(pause || end)
		return;
	if(--counter)
		return;
	
	counter=20-level;

	int i;
	for(i=length;i>0;--i){
		snake[i][0]=snake[i-1][0];
		snake[i][1]=snake[i-1][1];
	}

	switch(ort){
	case KEY_RIGHT:
		++snake[0][0];
		break;
	case KEY_LEFT:
		--snake[0][0];
		break;
	case KEY_DOWN:
		++snake[0][1];
		break;
	case KEY_UP:
		--snake[0][1];
		break;
	}


	if(snake[0][0]<0 || snake[0][0]>=FIELD_W){
		end=1;
	}
	if(snake[0][1]<0 || snake[0][1]>=FIELD_H){
		end=1;
	}
	for(i=1;i<length;++i){
		if(snake[0][0]==snake[i][0] && snake[0][1]==snake[i][1]){
			end=1;
		}
		if(snake[0][0]==food[0] && snake[0][1]==food[1]){
			eat_food();
			generate_food();
		}
	}
}

void game_render(){
	int i;
	char score_buf[24];
	
	graphic_clear(0);
	graphic_drawsprite(food[0]*8, food[1]*8, 8, 8, sprite_food);

	switch(ort){
	case KEY_RIGHT:
		graphic_drawsprite(snake[0][0]*8, snake[0][1]*8, 8, 8, sprite_head_r);
		break;
	case KEY_LEFT:
		graphic_drawsprite(snake[0][0]*8, snake[0][1]*8, 8, 8, sprite_head_l);
		break;
	case KEY_DOWN:
		graphic_drawsprite(snake[0][0]*8, snake[0][1]*8, 8, 8, sprite_head_d);
		break;
	case KEY_UP:
		graphic_drawsprite(snake[0][0]*8, snake[0][1]*8, 8, 8, sprite_head_u);
		break;
	}

	for(i=1;i<length;++i){
		graphic_drawsprite(snake[i][0]*8, snake[i][1]*8, 8, 8, sprite_body);
	}

	graphic_setcolor(14);
	sprintf(score_buf, "%d", score);
	graphic_drawtext(1, 1, score_buf);

	if(pause){
		graphic_setcolor(YELLOW);
		graphic_drawtext(90, 64, "PAUSE");
	}
	graphic_refresh();
}

void generate_food(){
	int i;
	food[0]=system_getrand()%FIELD_W;
	food[1]=system_getrand()%FIELD_H;

	i=0;
	while(i<length){
		if(food[0]==snake[i][0] && food[1]==snake[i][1]){
			i=0;
			food[0]=system_getrand()%FIELD_W;
			food[1]=system_getrand()%FIELD_H;
		}else{
			++i;
		}
	}
}

void eat_food(){
	++length;
	score += 2*level;
	level=level > 1+(length/10) ? level : 1+(length/10);

	if(level>MAX_LEVEL)
		level=MAX_LEVEL;
}
