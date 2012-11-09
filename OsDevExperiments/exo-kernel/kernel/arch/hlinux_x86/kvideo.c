/*
 * AbastractOS
 * Copyright (C) 2011 Davide Gessa
 * 
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */
#include <core/kvideo.h>
#include <stdio.h>

#define VIDEO_MAX_X		80
#define VIDEO_MAX_Y		25

unsigned video_x = 0;
unsigned video_y = 0;
char video_std_color = 36;


/* get current color */
unsigned kvideo_getcl()
{
	return video_std_color;
}


/* move the cursor */
void kvideo_move_cursor(unsigned x, unsigned y)
{
}


/* scroll down the screen */
void kvideo_scroll_dw()
{
	video_y--;		
}


/* set the color */
void kvideo_setcl(unsigned cl)
{
	switch(cl)
	{
		case CL_BLACK:
		case CL_BLUE:
		case CL_GREEN:
			cl = 32;
			break;
		//CL_CYAN, 
		case CL_RED:
			cl = 31;
			break;

		/*CL_MAGENTA, CL_YELLOW, */
		case CL_LIGHTGRAY:
		case CL_GRAY:
		
		/*CL_LIGHTBLUE, CL_LIGHTGREEN,
	CL_LIGHTCYAN, CL_LIGHTRED, CL_LIGHTMAGENTA,
	CL_LIGHTYELLOW, */
		case CL_WHITE:
		default:
			cl = 0;
	}
	video_std_color = cl;
}

/* clear the screen */
void kvideo_clear()
{
	system("clear");	
}



/* put a char */
void kvideo_putch(char ch)
{
	printf("\033[0;%dm%c", video_std_color, ch);
}


