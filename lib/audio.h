#pragma once
#define AUDIO_OFF	0
#define AUDIO_ON	1

void audio_init();
void audio_set(int s);
void audio_play(int freq, int ms);
void audio_stop();
void audio_clean();
