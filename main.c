#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <SDL2/SDL.h>
#include "system.h"
#include "graphic.h"
#include "input.h"
#include "audio.h"


void menu_rend(){
	graphic_clear(0);
	graphic_setcolor(DARK_GREEN);
	graphic_drawrect(0, 0, 42, 128);
	graphic_setcolor(WHITE);
	graphic_drawrect(42, 0, 44, 128);
	graphic_setcolor(ORANGE);
	graphic_drawrect(86, 0, 42, 128);

	graphic_setcolor(BLACK);
	graphic_setfontsize(1);
	graphic_drawtext(10, 10, "ABCDEFGHIJKLMNOPQRSTUVWXYZ");
	graphic_drawtext(10, 30, "abcdefghijklmnopqrstuvwxyz");
}


int main(int argc, char **argv){
	argc=argc;
	argv=argv;

	system_init();
	graphic_init(2);
	audio_init();

	while(1){
		while(input_getkey());
		menu_rend();
		graphic_refresh();
		system_sleep(20);
	}

	graphic_clean();
	audio_clean();
	system_exit();

	return 0;
}
