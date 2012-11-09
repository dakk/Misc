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
#ifndef STDIO_H
#define STDIO_H

#include <types.h>

#ifdef __cplusplus
extern "C"
{
#endif

/** Argument list type */
typedef void * va_list;

#define va_start(list, lastpar) (list = &lastpar)
#define va_arg(list, type) *((type *)(list += sizeof(int)))
#define va_end(list) do {} while(0)


int kprintf(const char *format, ...);
void kputchar(char ch);
void kputs(char *str);

int atoi(const char *str);
char *itox(int num);
char *itoa(int num);

void kstrcpy(char *a, char *b);

void *kmemset(void *s, int c, size_t n);
void *kmemcpy(void *b , const void *a, size_t n);


#ifdef __cplusplus
};
#endif


#endif
