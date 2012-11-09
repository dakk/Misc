#include <types.h>
#include <libc.h>


void kstrcpy(char *a, char *b)
{
	while(*b != '\0')
	{
		*a = *b;
		a++; b++;
	}
	*a = '\0';
}


/* full a memory area with c */
void *kmemset(void *s, int c, size_t n)
{
	if((n % 8) == 0)
	{
		register uint64_t *a = (uint64_t *) s;	
		for (; 0 < n; n -= 8, a++)
			*a = c;
	}
	else if((n % 4) == 0)
	{
		register uint32_t *a = (uint32_t *) s;	
		for (; 0 < n; n -= 4, a++)
			*a = c;
	}
	else
	{
		register char *a = s;	
		for (; 0 < n; n--, a++)
			*a = c;
	}
	return s;
}




/** Copy a memory area */
void *kmemcpy(void *b , const void *a, size_t n)
{
	if((n % 8) == 0)
	{
		register uint64_t *s1 = (uint64_t *) b;
		register const uint64_t *s2 = (uint64_t *) a;
		for(; 0 < n; n-=8)
			*s1++ = *s2++;
	}
	else if((n % 4) == 0)
	{
		register uint32_t *s1 = (uint32_t *) b;
		register const uint32_t *s2 = (uint32_t *) a;
		for(; 0 < n; n-=4)
			*s1++ = *s2++;
	}
	else
	{
		register char *s1 = b;
		register const char *s2 = a;
		for(; 0<n; --n)
			*s1++ = *s2++;
	}

	return (void *) b;
}



/** Convert an int into a char* */
char *kitoa(int num)
{
	static char buff[10];
	char *str = buff + 9;
	int j = num;
	*str-- = 0;

	do 
		*str-- = num % 10 + '0';  
	while ((num = num / 10));

	if(j < 0)
		*str-- = '-';

	return ++str;
}




/** Convert an int into a char* hex */
char *kitox(int num)
{
	static char buff[10];
	char *str = buff + 9;
	*str-- = 0;

	do 
	{
		unsigned n = num % 16;
		char x;
		
		if(n <= 9) 
			x = n + '0';
		else
			x = (n - 9) + 'A' - 1;
		*str-- = x;  
	}
	while ((num = num / 16));

	return ++str;
}




/** Print a char */
void kputchar(char ch)
{
	video_putch(ch);
}



/** Print a string */
void kputs(const char *str)
{
	while(*str != '\0')
	{
		kputchar(*str);
		str++;
	}
}




/** Printf */
int kprintf(const char *format, ...)
{
	int len = 0;
	char output[255];
	char *current = &output[0];
	va_list ap;

	va_start(ap, format);

	while(*format != '\0')
	{
		if(*format == '%')
		{
			format++;

			switch (*format)
			{
				/* print a string */
				case 's':
					current = va_arg(ap, char *);
					kputs(current);
					break;
					
				/* print a char */
				case 'c':
					current = va_arg(ap, char *);
					kputchar(current[0]);
					break;

				/* print an hex */
				case 'x':
					kputs(kitox(va_arg(ap, int)));
					break;
					
				/* print a decimal */
				case 'd':
					kputs(kitoa(va_arg(ap, int)));
					break;


				/* % escape */
				case '%':
					kputchar('%');
					break;
			}
		}
		else
			kputchar(*format);

		format++;
		len++;
	}
	return len;
}



extern void panic(const char *message, const char *file, uint32_t line)
{
    // We encountered a massive problem and have to stop.
    asm volatile("cli"); // Disable interrupts.

    kputs("PANIC(");
    kputs(message);
    kputs(") at ");
    kputs(file);
    kputs(":");
    //kputs_dec(line);
    kputs("\n");
    // Halt by going into an infinite loop.
    for(;;);
}

extern void panic_assert(const char *file, uint32_t line, const char *desc)
{
    // An assertion failed, and we have to panic.
    asm volatile("cli"); // Disable interrupts.

    kputs("ASSERTION-FAILED(");
    kputs(desc);
    kputs(") at ");
    kputs(file);
    kputs(":");
    //kputs_dec(line);
    kputs("\n");
    // Halt by going into an infinite loop.
    for(;;);
}

