#include "8bit.h"
#include <stdio.h>

void menu_rend(){
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

	int t1, t2, n=0;
	while(1){
		t1=system_getticks();
		while(input_getkey());
		menu_rend();
		graphic_refresh();
		t2=system_getticks();
		system_sleep(10);
		++n;
		if(n>10){
			n=0;
			printf("%d\n", t2-t1);
		}
	}

	graphic_clean();
	audio_clean();
	system_exit();

	return 0;
}
