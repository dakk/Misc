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

#include <config.h>
#include <types.h>

#ifdef X86
	#include <arch/x86/arch.h>
#endif


typedef struct
{


} arch_info_t;


/* System timedate */
typedef struct
{
	uint8_t hours;			///< Ora
	uint8_t minutes;		///< Minuti
	uint8_t seconds;		///< Secondi
	uint8_t month;			///< Mese
	uint8_t day;			///< Giorno
	uint8_t year;			///< Anno
} clock_data_t;


clock_data_t clock_data;	///< Data e ora globali


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


int 		arch_init(void *multiboot);
void 		arch_shutdown();
void 		arch_reboot();
void 		arch_crit_start();
void 		arch_crit_end();
void *		arch_get_header();
uint64_t	arch_get_mem_size();
void *		arch_exec(void *);

void		timer_sleep(uint32_t ms);
uint32_t	timer_get_tick();


void		handler_reg(uint8_t, void (*)(regs_t *r));
void		handler_unreg(uint8_t);


enum
{
	CL_BLACK = 0x00, CL_BLUE, CL_GREEN, CL_CYAN, 
	CL_RED, CL_MAGENTA, CL_YELLOW, CL_LIGHTGRAY,
	CL_GRAY, CL_LIGHTBLUE, CL_LIGHTGREEN,
	CL_LIGHTCYAN, CL_LIGHTRED, CL_LIGHTMAGENTA,
	CL_LIGHTYELLOW, CL_WHITE
} color_t;


unsigned	kvideo_getcl();
void		kvideo_move_cursor(unsigned x, unsigned y);
void		kvideo_scroll_dw();
void		kvideo_setcl(unsigned cl);
void		kvideo_clear();
void		kvideo_putch(char ch);


#endif
