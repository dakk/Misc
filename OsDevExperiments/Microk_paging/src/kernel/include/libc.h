// common.h -- Defines typedefs and some global functions.
//             From JamesM's kernel development tutorials.

#ifndef COMMON_H
#define COMMON_H

#include <types.h>

#define PANIC(msg) panic(msg, __FILE__, __LINE__);
#define ASSERT(b) ((b) ? (void)0 : panic_assert(__FILE__, __LINE__, #b))

extern void panic(const char *message, const char *file, uint32_t line);
extern void panic_assert(const char *file, uint32_t line, const char *desc);


/** Argument list type */
typedef void * va_list;

#define va_start(list, lastpar) (list = &lastpar)
#define va_arg(list, type) *((type *)(list += sizeof(int)))
#define va_end(list) do {} while(0)


int kprintf(const char *format, ...);
void kputchar(char ch);
void kputs(const char *str);

int katoi(const char *str);
char *kitox(int num);
char *kitoa(int num);

void kstrcpy(char *a, char *b);

void *kmemset(void *s, int c, size_t n);
void *kmemcpy(void *b , const void *a, size_t n);


#endif // COMMON_H
