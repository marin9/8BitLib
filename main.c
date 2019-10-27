#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "graphic.h"
#include "input.h"
#include "main.h"


static int current;

struct game{
	char name[16];
	void (*step)();
	void (*rend)();
} apps[] = {
	{"Menu", menu_step, menu_rend},
	{"", 0, 0}
};


int main(int argc, char **argv){
	int c;
	int pflag=2;

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
	while(current>=0){
		apps[current].step();
		graphic_refresh();
		usleep(20000);
	}
	graphic_close();
	return 0;
}

void menu_set(int n){
	current=n;
}

void menu_step(){
	int k=input_getkey();
	
	if(k==EXIT){
		current=-1;
	}

	menu_rend();
}

void menu_rend(){
	graphic_clear(0);
	graphic_setcolor(GREEN);
	graphic_drawrect(0, 0, 42, 128);
	graphic_setcolor(WHITE);
	graphic_drawrect(42, 0, 44, 128);
	graphic_setcolor(BROWN);
	graphic_drawrect(86, 0, 42, 128);
}
