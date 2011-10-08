#include <core/stdio.h>
#include <core/arch.h>
#include <core/sched.h>
#include <core/mm.h>
#include <core/kvideo.h>
#include <core/kernel.h>


#if 0
void task1()
{
	int i;
/*	while(1)
		for(i = 0; i < 100; i++)
			vesa_draw_pixel(10+i, 10, 0x11111)*/
	int a = 0/0;	
	while(1) kprintf("%d\n", sched_get_pid()); 
}

void task2()
{
/*	while(1)
		for(i = 0; i < 100; i++)
			vesa_draw_pixel(100+i, 10, 0xFFFFF)*/

	while(1) kprintf("test %d\n", sched_get_pid());
	sched_exit();
}
#endif


void kmain(void *multiboot)
{
	int ml;

	kvideo_clear();
	kvideo_setcl(CL_RED);
	kprintf("Exos\n");
	kvideo_setcl(CL_LIGHTGRAY);


	/* Schedular */
	kvideo_setcl(CL_GREEN);
	kprintf("Schedular -> ");
	kvideo_setcl(CL_LIGHTGRAY);

	if(sched_init())
		kprintf("ok\n");
	else
		kprintf("error\n");

	/* Arch */
	kvideo_setcl(CL_GREEN);
	kprintf("Arch -> \n");
	kvideo_setcl(CL_LIGHTGRAY);

	ml = arch_init(multiboot);

	if(ml != -1)
		kprintf("  -> started %d tasks\n", ml);
	else
		return (void) kprintf("  -> error\n");


	/* Memory */
	kvideo_setcl(CL_GREEN);
	kprintf("Memory -> ");
	kvideo_setcl(CL_LIGHTGRAY);

	if(mm_init(arch_get_mem_size()))
		kprintf("ok, %d kbytes\n\n", arch_get_mem_size());
	else
		return (void) kprintf("Mem -> error\n");

	/* Start interrupt */
	arch_crit_end();

	#if 0
	vesa_init();
	vesa_draw_pixel(10, 10, 0xCCCCCC);
	#endif
	#if 0
	sched_exec("task1", task2, NULL, NULL);
	sched_exec("task1", task1, NULL, NULL);
	//sched_exec("task1", task2, NULL, NULL);
	#endif

	for(;;);
}




void shutdown()
{
	kvideo_setcl(CL_RED);
	kprintf("Going down.\n");
	kvideo_setcl(CL_LIGHTGRAY);
	arch_shutdown();
}



void reboot()
{
	kvideo_setcl(CL_RED);
	kprintf("Rebooting...\n");
	kvideo_setcl(CL_LIGHTGRAY);
	arch_reboot();
}

