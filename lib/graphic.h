#pragma once
#define BLACK			0
#define DARK_GRAY		1
#define LIGHT_GRAY		2
#define WHITE			3
#define BROWN			4
#define DARK_RED		5
#define RED				6
#define PINK			7
#define ORANGE			8
#define BLUE			9
#define LIGHT_BLUE		10
#define PURPLE			11
#define YELLOW			12
#define DARK_GREEN		13
#define GREEN			14
#define CYAN			15


#define WINDOW_WIDTH	192
#define WINDOW_HEIGHT	128


void graphic_init(int s);
void graphic_clear(int c);
void graphic_setcolor(int c);
void graphic_setfontsize(int s);
void graphic_setpixel(int x, int y);
void graphic_drawrect(int x, int y, int w, int h);
void graphic_drawsprite(int x, int y, int w, int h, char *s);
void graphic_drawchar(int x, int y, char c);
void graphic_drawtext(int x, int y, char *s);
void graphic_refresh();
void graphic_clean();
