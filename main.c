#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <SDL2/SDL.h>
#include "graphic.h"
#include "input.h"


void print_help(){
	printf(" Usage: minigames -p [pixel_size]\n");
	exit(0);
}


int main(int argc, char **argv){
	int pflag=2;
	int c;

	while((c=getopt(argc, argv, "hp:")) != -1){
		switch(c){
			case 'p':
				pflag=atoi(optarg);
				break;
			case 'h':
				print_help();
				break;
			default:
				printf("WARNING: Illegal arguments.\n");
				printf("Type -h for help.\n");
				exit(-1);
		}
	}

	graphic_init(pflag);

	while(1){
		c=input_getkey();
		printf("Key: %d\n", c);
		if(c==KEY_EXIT){
			break;
		}

		graphic_clear(4);
		graphic_setcolor(3);
		graphic_setfontsize(2);
		graphic_drawtext(10, 10, "MARIN BRALIC");
		graphic_refresh();

		SDL_Delay(20);
	}

	graphic_close();
	return 0;
}

