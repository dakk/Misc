#include <core/stdio.h>
#include "tarfs.h"
#include "vfs.h"

void vfs_main()
{
	//printf("Mounting / with tarfs\n");
	vfs_mount("ram", "/", "tarfs", NULL);

	//printf("Mounting /dev with devfs\n");
	vfs_mount("ram", "/dev", "devfs", NULL);
	
	while(1)
	{
		
		
	}
}
