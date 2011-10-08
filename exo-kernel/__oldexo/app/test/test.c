#include <libos.h>


void kputs(char *);


int main()
{
	kputchar('c');
	kputs("ciao\n");
	kputchar('l');

	for(;;);

	ui_window_t *w = ui_window_new("test");
	ui_add_window(w);
	ui_window_loop(w);

	for(;;);
}



void kputs(char *str)
{
	while(*str != '\0')
	{
		kputchar(*str);
		str++;
	}
}

