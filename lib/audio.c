#include <math.h>
#include <SDL2/SDL.h>
#include "audio.h"


#define AMPLITUDE		255.0f
#define SAMPLE_RATE		4000
#define BUFF_SIZE		64

static int status;
static int frequency;
static int progress;
static float duration;


static void audio_callback(void *user_data, Uint8 *raw_buffer, int bytes){
	int i;
	float t;
    Uint8 *buff=(Uint8*)raw_buffer;
    user_data=user_data;
 
    if(!status)
        return;

    for(i=0;i<bytes;++i){	
    	t=1.0f*progress/SAMPLE_RATE;
    	++progress;

    	if(t<duration){
			buff[i]=(Uint8)(AMPLITUDE*sin(2*M_PI*frequency*t));
		}else{
	   		SDL_PauseAudio(1);
	   		break;
	   }
	}
}


void audio_init(){
    SDL_AudioSpec want;
    SDL_AudioSpec have;

    want.freq=SAMPLE_RATE;
    want.format=AUDIO_U8;
    want.channels=1;
    want.samples=BUFF_SIZE;
    want.callback=audio_callback;
    want.userdata=0;

    if(SDL_OpenAudio(&want, &have)){
    	printf("ERROR: Audio_init fail: %s\n", SDL_GetError());
    	SDL_Quit();
    	exit(2);
    }

    if(want.format != have.format){
    	printf("ERROR: Audio_init fail: Illegal format.\n");
    	SDL_Quit();
    	exit(2);
    }

    status=AUDIO_ON;
}

void audio_set(int s){
    status=s;
}

void audio_play(int freq, int ms){
    if(!status)
        return;

	frequency=freq;
	duration=1.0f*ms/1000;
	progress=0;  
    SDL_PauseAudio(0);
}

void audio_stop(){
    if(status)
        return;
    
	SDL_PauseAudio(1);
}

void audio_clean(){
	SDL_CloseAudio();
}
