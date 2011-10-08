#include <libos.h>
#include "driver.h"
#include <string.h>

device_t *device_list = NULL;
driver_t *driver_list = NULL;

/*
extern driver_t _keyboard_driver;

_keyboard_driver.next = driver_list;
driver_list = &(_keyboard_driver);
*/

void driver_add_all_drivers()
{
	extern driver_t _keyboard_driver;
	extern driver_t _vesa_driver;

	//driver_add(&_keyboard_driver);
	driver_add(&_vesa_driver);
}


void driver_add(struct driver_p *driver)
{
	driver->next = driver_list;
	driver_list = driver;
}



struct device_p *device_get(char *name)
{
	struct device_p *td = device_list;

	while(td != NULL)
	{
		if(_strcmp(td->name, name) == 0)
			return td;
		td = td->next;
	}
	return NULL;
}



int device_probe_all(bus_type_t bus)
{
	if(driver_list == NULL)
		driver_add_all_drivers();

	driver_t *drv = driver_list;
	unsigned n = 0;

	while(drv != NULL)
	{
		if(drv->probe(bus) != 0)
		{
			device_t *dev = (device_t *) mm_alloc(sizeof(device_t));
			dev->driver = drv;
			_strcpy(dev->name, drv->name);
			dev->next = device_list;
			n++;
		}

		drv = drv->next;
	}

	return n;
}

