#include <drivers.h>

struct driver_methods test_meth = 
	{
		.open = test_open,
		.close = test_close,
		.read = test_read,
		.write = test_write
	};


void main()
{
	if(!test_probe())
		return;
		
	test_init();
	
	driver_loop(test_meth);
}
