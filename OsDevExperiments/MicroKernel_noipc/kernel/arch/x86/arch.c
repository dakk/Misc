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
#include <core/arch.h>
#include "dt.h"
#include <types.h>
#include <core/stdio.h>
#include <core/sched.h>
#include "multiboot.h"

multiboot_info_t *mb;

uint64_t mem = 0;

uint64_t arch_get_mem_size()
{
	return mem;
}


int arch_init(void *multib)
{
	int i;
	int ml = 0;
	asm("cli");

	mb = (multiboot_info_t *) multib;

	gdt_install();
	idt_install();
	isrs_install();
	irq_install();	
	timer_init();

	/* Start given tasks */
	mem = mb->mem_lower + mb->mem_upper;

	for(i = 0; i < mb->mods_count; i++)
	{
		multiboot_module_t *mod = (multiboot_module_t *) mb->mods_addr + i * sizeof(multiboot_module_t);

		pid_t p = sched_exec(((char*)mod->string)+1, (void *) mod->mod_start, NULL, NULL);

		if(p != -1)
		{
			kprintf("%s ", (char *) mod->string, p);
			ml++;
		}

	}

	return ml;
}


void *arch_exec(void *e)
{
	return NULL;
}

void *arch_get_header()
{
	return (void *) mb;
}

void arch_shutdown()
{
	while(1);
}



void arch_reboot()
{
	char temp;
	do
	{
		temp = io_inb(0x64);
		if((temp & 0x01) != 0)
		{
			(void)io_inb(0x60);
			continue;
		}
	} while((temp & 0x02) != 0);

	io_outb(0x64, 0xFE);
	while(1);
}



void arch_crit_end()
{ 
	asm("sti"); 
}


void arch_crit_start()
{ 
	asm("cli"); 
} 
