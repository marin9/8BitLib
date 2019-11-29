#include "audio.h"
#include "input.h"
#include "system.h"
#include "graphic.h"


int main(int argc, char **argv){
	int color=0;
	argc=argc;
	argv=argv;

	system_init();

	while(1){
		while(input_getkey()){
			color=(color+1)%16;
			audio_play(1000, 30);
		}
		graphic_clear(color);
		graphic_refresh();
		system_sleep(10);
	}

	system_exit();
	return 0;
}
