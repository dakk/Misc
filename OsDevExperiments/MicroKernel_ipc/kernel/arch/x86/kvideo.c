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
#define VIDEO_MAX_X		80
#define VIDEO_MAX_Y		25
#define VIDEO_MEM		0xB8000
#define VIDEO_TAB_DIM	4

unsigned video_x = 0;
unsigned video_y = 0;
char video_std_color = 0x07;


/* get current color */
unsigned kvideo_getcl()
{
	return video_std_color;
}


/* move the cursor */
void kvideo_move_cursor(unsigned x, unsigned y)
{
	asm(
		"movl  %0, %%eax   \n"
		"movl  %1, %%ebx   \n"
		"movl  $0x50, %%ecx   \n"
		"mul   %%ecx		  \n"
		"addl  %%ebx, %%eax   \n"
		"movw  $0x03d4, %%dx  \n"
		"pushl %%eax		  \n"
		"movb  $0x0f, %%al    \n"
		"out   %%al, %%dx     \n"
		"popl  %%eax		  \n"
		"movw  $0x03d5, %%dx  \n"
		"out   %%al, %%dx     \n"
		"shr   $0x08,%%eax      \n"
		"pushl %%eax		  \n"
		"movw  $0x03d4, %%dx  \n"
		"movb  $0x0e, %%al    \n"
		"out   %%al, %%dx     \n"
		"pop   %%eax		  \n"
		"movw  $0x03d5, %%dx  \n"
		"out   %%al, %%dx     \n"
		: : "g" (y), "g" (x)
	);
	
	video_x = x;
	video_y = y;
}


/* scroll down the screen */
void kvideo_scroll_dw()
{
	char *vidmem = (char *) VIDEO_MEM;
	
	unsigned int x;
	unsigned int y;
	unsigned int i;
	unsigned int j;
	
	
	for(x = 0; x < VIDEO_MAX_X; x++)
	{
		for(y = 0; y <= VIDEO_MAX_Y; y++)
		{
			i = (y * VIDEO_MAX_X * 2) + (x * 2);
			j = ((y+1) * VIDEO_MAX_X * 2) + (x * 2);
			vidmem[i] = vidmem[j];
			i++; j++;
			vidmem[i] = vidmem[j];
 		}
	}
	
	video_y--;		
}


/* set the color */
void kvideo_setcl(unsigned cl)
{
	video_std_color = cl;
}




/* put a char */
void kvideo_putch(char ch)
{
	char *vidmem = (char *) VIDEO_MEM;

	
	// Calcola la posizione nel buffer video
	unsigned i = (video_y * VIDEO_MAX_X * 2) + (video_x * 2);
	int j;
	
	// Esaminiamo il carattere
	switch(ch)
	{
		// A capo
		case '\n':
			video_y++;
			video_x = 0;
			break;
			
		case '\b':
			if(video_x == 0)
			{
				video_x = VIDEO_MAX_X-1;
				video_y = video_y-1;
			}
			video_x--;
			vidmem[i-2] = ' ';
			vidmem[i-1] = video_std_color;
			break;
		
		// Tab
		case '\t':
			for(j = 0; j < VIDEO_TAB_DIM; j++)
				kvideo_putch(' ');
			break;

		// Carattere normale
		default:
			vidmem[i] = ch;
			i++;
			vidmem[i] = video_std_color;
			video_x++;
			break;
	}


	// Controlla se le posizioni x e y hanno superato i limiti
	if(video_y >= VIDEO_MAX_Y)
		kvideo_scroll_dw();
		
	if(video_x >= VIDEO_MAX_X)
	{
		video_y++;
		video_x = 0;
	}
	
	kvideo_move_cursor((unsigned) video_x, (unsigned) video_y);
}




/* clear the screen */
void kvideo_clear()
{
	unsigned i;
	unsigned mv = VIDEO_MAX_X * VIDEO_MAX_Y;
	
	for(i = 0; i < mv; i++)
		kvideo_putch(' ');
	
	video_x = 0;
	video_y = 0;
}

