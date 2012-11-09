#include <libos.h>

#define		VERSION		"0.1"

extern void app_bootsplash();
extern void app_ui();

void lazy_sleep()
{
	unsigned i;
	for(i = 0; i < 0xFFFFFF; i++);
	/*
	uint32_t tim = timer_get_tick();
	uint32_t tim2;

	while((tim2 = timer_get_tick()) < (tim + 200));*/
}


void app_test()
{
//	lazy_sleep();
	kprintf("TestApp\n");
	//lazy_sleep();
	ui_window_t *ww = ui_window_new("testa");
	ui_window_set_position(ww, 160, 100);
	ui_add_window(ww);
}

int app_init()
{
	kprintf("Init (%s)\n", VERSION);
	kprintf("Probing all devices: %d probed\n", device_probe_all(BUS_PCI));
	
	kprintf("Rendering bootsplash in vesa mode\n");
	app_bootsplash();

	kprintf("Mounting / with tarfs\n");
	vfs_mount("ram", "/", "tarfs", NULL);

	kprintf("Mounting /dev with devfs\n");
	vfs_mount("ram", "/dev", "devfs", NULL);

	kprintf("Starting the ui\n");

	
	//sched_exec("test", app_test, NULL, NULL);
	app_ui();
	//sched_exec("ui", app_ui, NULL, NULL);
	//sched_exec("test", app_test, NULL, NULL);

	for(;;);
}



