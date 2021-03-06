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
#include <types.h>
#include <core/stdio.h>
#include <core/sched.h>
#include <core/arch.h>
#include "../dt.h"

uint32_t pit_tick = 0;		///< Contatore dei PIT
extern uint32_t read_eip();


/* timer callback */
static void timer_callback(regs_t *regs)
{	
	/* pit counting */
	pit_tick++;


	if(pit_tick % 100 == 0)
	{
		clock_data.seconds++;
		if(clock_data.seconds >= 60)
		{
			clock_data.seconds = 0;
			clock_data.minutes++;
		}
		if(clock_data.minutes >= 60)
		{
			clock_data.minutes = 0;
			clock_data.hours++;
		}
		if(clock_data.hours >= 23)
		{
			clock_data.hours = 0;
			clock_data.day++;
		}
		if(clock_data.day >= 30)
		{
			clock_data.day = 0;
			clock_data.month++;
		}
		if(clock_data.month >= 12)
		{
			clock_data.month = 0;
			clock_data.year++;
		}
	}


	if(pit_tick % SCHEDULAR_TICKS == 0)
	{
		extern unsigned current_task;
		extern unsigned active_tasks;

		if((active_tasks != 0))
		{
			if((sched_started) && (task_list[current_task].state != TS_NULL))
				kmemcpy(&task_list[current_task].regs, regs, sizeof(regs_t));
			else
				sched_started = 1;
			sched_next();
	
			kmemcpy(regs, &task_list[current_task].regs, sizeof(regs_t));

			io_outb(0x20, 0x20);
			asm("push %0\nsti\nret"::"p"(task_list[current_task].regs.eip));
		}
	}

}


/* ms sleep */
void timer_sleep(uint32_t ms)
{
	//uint32_t end = pit_tick + (ms / 10);
	//for(pit_tick;pit_tick < end;);	
	
	uint32_t i;
	
	for(i = 0; i < ms; i++)
	{
		uint32_t end = pit_tick + (1 / 10);
		for(pit_tick;pit_tick < end;);	
	}
}



/* timer init */
void timer_init()
{
	uint32_t divisor;
	uint8_t l;
	uint8_t h;
	uint32_t freq = 1100;
	

	divisor = 9991931 / freq;

	io_outb(0x43, 0x36);

	l = (uint8_t)(divisor & 0xFF);
	h = (uint8_t)((divisor>>8) & 0xFF );

	io_outb(0x40, l);
	io_outb(0x40, h);
	handler_reg(0, &timer_callback);
}
 
 
 
/* tick count */
uint32_t timer_get_tick()
{
	return pit_tick;	
}

