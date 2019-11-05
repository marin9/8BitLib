#include "8bit.h"

void render(){
	int x, y;
	graphic_clear(0);

	for(x=0;x<128;++x){
		for(y=0;y<128;++y){
			graphic_setcolor((system_getrand()*system_getrand())%16);
			graphic_setpixel(x, y);			
		}
	}
}


int main(int argc, char **argv){
	argc=argc;
	argv=argv;

	system_init();
	graphic_init(2);
	audio_init();

	while(1){
		while(input_getkey());
		render();
		graphic_refresh();
		system_sleep(10);
	}

	graphic_clean();
	audio_clean();
	system_exit();

	return 0;
}
