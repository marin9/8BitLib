#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "graphic.h"
#include "input.h"



int menu_step(){

	return 0;
}

void menu_rend(){

}



int current=0;

struct game{
	char name[16];
	int (*step)();
	void (*rend)();
} apps[] = {
	{"Menu", menu_step, menu_rend}
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

	graphic_init(pflag);

	while(1){
		if(apps[current].step()){
			current=0;
			continue;
		}
		apps[current].rend();
		graphic_refresh();
		usleep(20000);
	}

	graphic_close();
	return 0;
}
