#include "system.h"
#include "graphic.h"
#include "input.h"

void render(){
	int x, y;
	graphic_clear(0);

	for(x=0;x<WINDOW_WIDTH;++x){
		for(y=0;y<WINDOW_HEIGHT;++y){
			graphic_setcolor((system_getrand()*system_getrand())%16);
			graphic_setpixel(x, y);			
		}
	}
}


int main(int argc, char **argv){
	argc=argc;
	argv=argv;

	system_init();


	while(1){
		while(input_getkey());
		render();
		graphic_refresh();
		system_sleep(10);
	}

	system_exit();
	return 0;
}
