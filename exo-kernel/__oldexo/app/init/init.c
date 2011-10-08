#include <libos.h>

#define		VERSION		"0.1"

int main()
{
	//printf("Init (%s)\n", VERSION);
	//printf("Probing all devices: %d probed.\n", device_probe_all(BUS_PCI));
	
	//printf("Mounting / with tarfs\n");
	vfs_mount("ram", "/", "tarfs", NULL);

	//printf("Mounting /dev with devfs\n");
	vfs_mount("ram", "/dev", "devfs", NULL);


	for(;;);
}



