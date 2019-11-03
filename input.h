#pragma once
#define EVENT_NULL		0
#define EVENT_EXIT		1

#define MOUSE_LEFT		2
#define MOUSE_RIGHT		3

#define KEY_UP			10
#define KEY_DOWN		11
#define KEY_LEFT		12
#define KEY_RIGHT		13
#define KEY_SPACE		14
#define KEY_ENTER		15
#define KEY_ESC			16
#define KEY_UNKNOWN		17


int input_getkey();
int input_getmouse(int *x, int *y);
