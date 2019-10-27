#include "graphic.h"


#include  <SDL2/SDL.h>



int main(int argc, char **argv){
	argc=argc;
	argv=argv;

	graphic_init(2);

	graphic_clear(0);


	int i;
	for(i=0;i<16;++i){
		graphic_setcolor(i);
		graphic_drawtext(2, 2, "ABCDEFGHIJKLMNOPQRSTUVWYZ");
		graphic_refresh();
		SDL_Delay(500);
	}


	graphic_close();
	return 0;
}

