#include "8bit.h"

void menu_rend(){
	int i;
	graphic_clear(0);

	for(i=0;i<16;++i){
		graphic_setcolor(i);
		graphic_drawrect(i*8, 0, 128, 128);
	}

	graphic_setcolor(BLACK);
	graphic_setfontsize(1);
	graphic_drawtext(10, 10, "ABCDEFGHIJKLMNOPQRSTUVWXYZ");
	graphic_drawtext(10, 30, "abcdefghijklmnopqrstuvwxyz");
	graphic_drawtext(10, 50, "       0123456789");
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
