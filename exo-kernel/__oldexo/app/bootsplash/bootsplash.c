#include <libos.h>

#define SIZE_X	10
#define SIZE_Y	10
#define SSLEEP	3

//unsigned splash_image[][] = { 0,0 };


void kputs(char *str);


void main()
{
	//device_t *vesa = device_get("vesa");
/*  
	if(vesa != NULL)
	{
		vesa->driver->init(vesa);
	}

	unsigned i, j;
*/
	kputchar('a');
	//kputs("cacca\n\0");
	kputchar('b');
	kputs("ciaoo\n\0");
	kputs("ciaoo\n");


	sched_exit();
	//test();
	while(1);
	/* Rendering of the splash */
//	while(1)
//		kputchar('a');
#if 0	
	vesa_init();

	while(1)
	for(i = 0; i < SIZE_X; i++)
	{
		for(j = 0; j < SIZE_Y; j++)
		{
			kputchar('a');
			//vesa_draw_pixel(i, j, 0xACCCC); //splash_image[i][j]);
		}
	}


	/* Sleep for some seconds */
	for(;;); //sleep(SSLEEP);

	return;
#endif
}



void kputs(char *str)
{
	kputchar('c');
	while(*str != '\0')
	{
		kputchar(*str);
		str++;
	}
}

