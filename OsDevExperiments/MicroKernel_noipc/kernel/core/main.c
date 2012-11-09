#include <core/stdio.h>
#include <core/arch.h>
#include <core/sched.h>
#include <core/mm.h>
#include <core/kernel.h>


void task()
{
	while(1) kprintf("Task says: I'm %d\n", sched_get_pid()); 
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



void kmain(void *multiboot)
{
	int ml;

	kvideo_clear();
	kprintf("booting %s\n", KER_NAME);
	
	/* Schedular */
	kprintf("starting schedular... ");
	
	if(sched_init())
		kprintf("ok\n");
	else
		kprintf("error\n");

	/* Arch */
	kprintf("initalizing arch... ");
	
	ml = arch_init(multiboot);

	if(ml == 0)
		kprintf("ok\n");
	else if(ml != -1)
		kprintf(" ok (started %d tasks)\n", ml);
	else
	{
		kprintf("error\n");
		while(1);
	}


	/* Memory */
	kprintf("initializing memory... ");
	
	if(mm_init(arch_get_mem_size()))
		kprintf("ok, %d kbytes\n", arch_get_mem_size());
	else
		return (void) kprintf("error\n");


	/* Generating symbols table */
	kprintf("creating symbols table... ");
	ker_symbols[KSI_SHUTDOWN] = (ker_entry) shutdown;
	ker_symbols[KSI_REBOOT] = 	(ker_entry) reboot;
	ker_symbols[KSI_PUTCHAR] = 	(ker_entry) kputchar;
	ker_symbols[KSI_ALLOC] = 	(ker_entry) mm_alloc;
	ker_symbols[KSI_FREE] = 	(ker_entry) mm_free;
	ker_symbols[KSI_EXEC] = 	(ker_entry) sched_exec;
	ker_symbols[KSI_GET_PID] = 	(ker_entry) sched_get_pid;
	ker_symbols[KSI_EXIT] = 	(ker_entry) sched_exit;
	ker_symbols[KSI_FORK] = 	(ker_entry) sched_fork;
	kprintf("done\n\n");
	


	/* Start interrupt */
	arch_crit_end();
	
	/* starting servers */	
	kprintf("starting servers... ");
	
	#ifdef VFS
		extern void vfs_main();
		
		sched_exec("vfs", vfs_main, NULL, NULL);
		kprintf("vfs ");
	#endif
	#ifdef NET
		extern void net_main();
		
		sched_exec("net", net_main, NULL, NULL);
		kprintf("net ");
	#endif
	#ifdef INIT
		extern void init_main();
		
		sched_exec("init", init_main, NULL, NULL);
		kprintf("init ");
	#endif
	#ifdef DEV
		extern void dev_main();
		
		sched_exec("dev", dev_main, NULL, NULL);
		kprintf("dev ");
	#endif
	#ifdef STAT
		extern void stat_main();
		
		sched_exec("stat", stat_main, NULL, NULL);
		kprintf("stat ");
	#endif
	kprintf("\n");


	//ker_symbols[2]('a',0,0,0);

	while(1);
	for(ml = 0; ml < 500; ml++)
		sched_exec("task", task, NULL, NULL);


	for(;;);
}

