
#include <core/arch.h>
#include <types.h>
#include <core/sched.h>
#include <core/stdio.h>
#include <core/kvideo.h>
#include "multiboot.h"
#include <pthread.h>

#define DEFAULT_MEMORY	(32*1024)

multiboot_info_t *mb;

uint64_t mem = 0;

uint64_t arch_get_mem_size()
{
	return mem;
}

extern void kmain(void *);
extern void *malloc(size_t);


void test()
{
	while(1) kputs("t");
}

int main(int argc, char **argv)
{
	kputs("Hosted\n");

	/* create the multiboot header */
	multiboot_info_t m;
	m.boot_loader_name = (unsigned) malloc(20);
	kstrcpy((char *) (m.boot_loader_name), "linux\0");
	m.mem_lower = 0;
	m.mem_upper = DEFAULT_MEMORY;
	m.mods_count = 0; //1;
	
	/* test */
	m.mods_addr = (uint32_t) malloc(sizeof(multiboot_module_t));
	((multiboot_module_t *) m.mods_addr)->string = (uint32_t) malloc(32);
	kstrcpy((char *) ((multiboot_module_t *) m.mods_addr)->string, "test");
	((multiboot_module_t *) m.mods_addr)->mod_start = (unsigned) test;

	/* call kmain */
	kmain(&m);

	return 0;
}



int arch_init(void *multib)
{
	int i;
	int ml = 0;

	mb = (multiboot_info_t *) multib;

	if(mb == NULL)
		return -1;


	kprintf("  -> boot from %s bootloader\n", mb->boot_loader_name);


	/* Start given tasks */
	mem = mb->mem_lower + mb->mem_upper;

	for(i = 0; i < mb->mods_count; i++)
	{
		multiboot_module_t *mod = (multiboot_module_t *) mb->mods_addr + i * sizeof(multiboot_module_t);

		pid_t p = sched_exec(((char*)mod->string)+1, (void *) mod->mod_start, NULL, NULL);

		if(p != -1)
		{
			kprintf("  -> started %s process from boot modules with pid %d\n", (char *) mod->string, p);
			ml++;
		}
		else
			kprintf("  -> failed to start %s process from boot modules\n", (char *) mod->string); 

	}

	return ml;
}




void *arch_exec(void *e)
{
	void (*c)();
	c = e;

	pthread_attr_t attr;
	pthread_t *threads = (pthread_t *) malloc(sizeof(pthread_t)); 

	pthread_attr_init(&attr); 
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

	pthread_create(threads, NULL, c, (void *) 0);

	return (void *) threads;
}


void *arch_get_header()
{
	return (void *) mb;
}

void arch_shutdown()
{
	while(1);
}



void arch_reboot()
{
	while(1);
}



void arch_crit_end()
{ 
}


void arch_crit_start()
{ 
} 
