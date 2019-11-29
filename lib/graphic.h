#pragma once
#define BLACK			0
#define BLUE			1
#define GREEN			2
#define CYAN			3
#define RED				4
#define MAGENTA			5
#define BROWN			6
#define GRAY 			7
#define DARK_GRAY		8
#define BRIGHT_BLUE		9
#define BRIGHT_GREEN	10
#define BRIGHT_CYAN		11
#define BRIGHT_RED		12
#define BRIGHT_MAGENTA	13
#define YELLOW			14
#define WHITE			15


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
