#ifndef KVIDEO_H
#define KVIDEO_H

enum
{
	CL_BLACK = 0x00, CL_BLUE, CL_GREEN, CL_CYAN, 
	CL_RED, CL_MAGENTA, CL_YELLOW, CL_LIGHTGRAY,
	CL_GRAY, CL_LIGHTBLUE, CL_LIGHTGREEN,
	CL_LIGHTCYAN, CL_LIGHTRED, CL_LIGHTMAGENTA,
	CL_LIGHTYELLOW, CL_WHITE
} color_t;


unsigned kvideo_getcl();
void kvideo_move_cursor(unsigned x, unsigned y);
void kvideo_scroll_dw();
void kvideo_setcl(unsigned cl);
void kvideo_clear();
void kvideo_putch(char ch);


#endif

