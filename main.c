#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "main.h"
#include "graphic.h"
#include "keyboard.h"


static int current;

struct game{
	char name[16];
	void (*init)();
	void (*step)();
	void (*rend)();
} apps[] = {
	{"Menu", menu_init, menu_step, menu_rend},
	{"", 0, 0, 0}
};


void menu_set(int n){
	current=n;
	apps[n].init();
}

void menu_init(){
}

void menu_step(){
	int k=keyboard_getkey();
	if(k==EXIT){
		current=-1;
	}
}

void menu_rend(){
	graphic_clear(0);
	graphic_setcolor(GREEN);
	graphic_drawrect(0, 0, 42, 128);
	graphic_setcolor(WHITE);
	graphic_drawrect(42, 0, 44, 128);
	graphic_setcolor(BROWN);
	graphic_drawrect(86, 0, 42, 128);

	graphic_setcolor(BLACK);
	graphic_setfontsize(3);
	graphic_drawtext(10, 10, "ABCDEFGHIJKLMNOPRSTUVZXYWQ");
	graphic_drawtext(10, 30, "abcdefghijklmnopqrstuvwxyz");
}



int main(int argc, char **argv){
	int c;
	int pflag=3;

	while((c=getopt(argc, argv, "hp:")) != -1){
		switch(c){
		case 'p':
			pflag=atoi(optarg);
			break;
		case 'h':
			printf(" Usage: minigames -p [pixel_size]\n");
			exit(0);
			break;
		default:
			printf("WARNING: Illegal arguments.\n");
			printf("Type -h for help.\n");
			exit(-1);
		}
	}

	current=0;
	graphic_init(pflag);
	apps[current].init();

	while(current >= 0){
		apps[current].step();
		apps[current].rend(); //TODO segmentation fault
		graphic_refresh();
		usleep(10000);
	}

	graphic_close();
	return 0;
}
