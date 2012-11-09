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
#ifndef ARCH_H
#define ARCH_H

#include <types.h>


/* Input ouput on ports */
void 		io_outb(uint16_t, uint8_t);
uint8_t 	io_inb(uint16_t);
void 		io_outw(uint16_t, uint16_t);
uint16_t 	io_inw(uint16_t);
void 		io_outd(uint16_t, uint32_t);
uint32_t 	io_ind(uint16_t);
void 		io_outl(uint16_t, uint64_t);
uint64_t 	io_inl(uint16_t);
void 		io_insl(uint16_t, char *, uint32_t);
void 		io_outsw(uint16_t, uint16_t *, uint32_t);
void 		io_insw(uint16_t, uint16_t *, uint32_t);


int			arch_init(void *mboot_ptr, uint32_t initial_stack);

void		video_move_cursor(unsigned x, unsigned y);
void		video_scroll();
void		video_clear();
void		video_putch(char ch);




#endif
