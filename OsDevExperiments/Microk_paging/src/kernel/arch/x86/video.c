// monitor.c -- Defines functions for writing to the monitor.
//             heavily based on Bran's kernel development tutorials,
//             but rewritten for JamesM's kernel tutorials.

#include "arch.h"

uint32_t*	video_memory = (uint32_t *)0xB8000;
uint8_t		cursor_x = 0;
uint8_t		cursor_y = 0;


void video_goto(uint8_t x, uint8_t y)
{
	cursor_x = x;
	cursor_y = y;
	
    uint16_t loc = cursor_y * 80 + cursor_x;
    
    io_outb(0x3D4, 14);   
    io_outb(0x3D5, loc >> 8);
    io_outb(0x3D4, 15);
    io_outb(0x3D5, loc);
}


void video_scroll()
{
    uint8_t attributeByte = (0 /*black*/ << 4) | (15 /*white*/ & 0x0F);
    uint16_t blank = 0x20 /* space */ | (attributeByte << 8);

    int i;
    for (i = 0*80; i < 24*80; i++)
        video_memory[i] = video_memory[i+80];
 
    for (i = 24*80; i < 25*80; i++)
        video_memory[i] = blank;
 
    cursor_y = 24;
}

// Writes a single character out to the screen.
void video_putch(char c)
{
	char *vidmem = (char *) video_memory;

	
	// Calcola la posizione nel buffer video
	unsigned i = (cursor_y * 80 * 2) + (cursor_x * 2);
	int j;
	
	// Esaminiamo il carattere
	switch(c)
	{
		// A capo
		case '\n':
			cursor_y++;
			cursor_x = 0;
			break;
			
		case '\b':
			if(cursor_x == 0)
			{
				cursor_x = 80-1;
				cursor_y = cursor_y-1;
			}
			cursor_x--;
			vidmem[i-2] = ' ';
			vidmem[i-1] = 7;
			break;
		
		// Tab
		case '\t':
			for(j = 0; j < 4; j++)
				video_putch(' ');
			break;

		// Carattere normale
		default:
			vidmem[i] = c;
			i++;
			vidmem[i] = 7;
			cursor_x++;
			break;
	}

	
	if(cursor_x >= 80)
	{
		cursor_y++;
		cursor_x = 0;
	}
	
	if(cursor_y >= 25)
		video_scroll();
    video_goto(cursor_x, cursor_y);
}

void video_clear()
{
    // Make an attribute byte for the default colours
    uint8_t attributeByte = (0 /*black*/ << 4) | (15 /*white*/ & 0x0F);
    uint16_t blank = 0x20 /* space */ | (attributeByte << 8);

    int i;
    for (i = 0; i < 80*25; i++)
    {
        video_memory[i] = blank;
    }


    video_goto(0, 0);
}
