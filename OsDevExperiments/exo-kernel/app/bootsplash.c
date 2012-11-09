#include <libos.h>

#define SIZE_X	10
#define SIZE_Y	10
#define SSLEEP	3

//unsigned splash_image[][] = { 0,0 };


void app_bootsplash()
{
	unsigned i;
	unsigned j;
	device_t *vesa = device_get("vesa");

	if(vesa == NULL)
		return;
	
	vesa->driver->init(vesa);


	for(i = 0; i < SIZE_X; i++)
	{
		for(j = 0; j < SIZE_Y; j++)
		{	
			vesa->driver->ioctl(vesa, (unsigned) VESA_IOCTL_DRAW_PIXEL, i, j, 0xFFFF);
		}
	}


	return;
}



