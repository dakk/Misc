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
#ifndef MM_H
#define MM_H

#include <types.h>

#define PHYS_MAX_PAGE	1048576					///< Max number of pages (4gb / 4kb / 32)
#define PHYS_PAGE_SIZE 	4						///< Size of a page (kb)
#define PHYS_MAX_BLOCKS	(PHYS_MAX_PAGE / 32)	///< Number of blocks of 32 pages


/** Memory block allocated */
typedef struct
{
	void *address; 		///< Address
	size_t dim;			///< Size
	pid_t pid;			///< Pid of the process that use this section
} phys_page_t;


phys_page_t phys_allocated[PHYS_MAX_BLOCKS];	///< Allocations array
unsigned phys_bitmap[PHYS_MAX_PAGE]; 			///< Physical bitmap
unsigned phys_page_number;						///< Pages number
uint32_t phys_total;							///< System memory

void phys_reserve(uint32_t, uint32_t);
void phys_free(void *);
void *phys_alloc(size_t);
void phys_init(uint32_t);
uint8_t phys_if_free_page(int *, int *);
uint32_t phys_get_free_pages();
uint32_t phys_first_free_alloc();

int mm_init(uint64_t);
void mm_test();
void mm_free(void *);
void mm_free_all(pid_t pid);
void *mm_alloc(size_t);
uint32_t mm_get_total_mem();
uint32_t mm_get_used_mem();
uint32_t mm_get_usable_size(void *);
void show_used_memory();


#endif
