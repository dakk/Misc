#include <core/sched.h>
#include <core/elf.h>
#include <core/stdio.h>
#include <core/mm.h>
#include <config.h>

unsigned current_task = 0;
unsigned active_tasks = 0;



/** Initialize the schedular */
int sched_init()
{
	unsigned i;

	for(i = 0; i < SCHEDULAR_TASKS; i++)
		task_list[i].state = TS_NULL;

	sched_started = 0;
	return 1;
}


/** Exec a program */
pid_t sched_exec(char *name, void *entry, void *argv, void *env)
{
	if(entry == NULL)
		return (pid_t) -1;

	arch_crit_start();

	unsigned p;

	p = sched_find_free();

	if(p == -1)
		return (pid_t) -1;

	kstrcpy(task_list[p].name, name);
	task_list[p].state = TS_READY;

	/* If it's an elf */
	if(elf_check(entry))
	{
		switch(elf_get_class(entry))
		{
			case ELF_CLASS_32:
				elf_relocate32(entry);
				task_list[p].regs.eip = (uint32_t) elf_get_entry32(entry);
				break;

			case ELF_CLASS_64:
				#ifdef BIT64

				#endif
				break;
		}
	}
	/* Threats as a binary file */
	else
	{
		task_list[p].regs.eip = (uint32_t) entry;
	}
	task_list[p].arch_data = arch_exec((void *) task_list[p].regs.eip);

	task_list[p].regs.eflags = 0x202;

	active_tasks++;

	if(active_tasks == 1)
		current_task = p;

	arch_crit_end();
	return p;
}


/** Exit */
void sched_exit()
{
	if(active_tasks == 0)
		return;

	arch_crit_start();
	
	task_list[current_task].state = TS_NULL;
	task_list[current_task].name[0] = 0;
	mm_free_by_pid(current_task);
	active_tasks--;

	arch_crit_end();
	for(;;);
}


/** Fork a child */
pid_t sched_fork()
{
	arch_crit_start();
	unsigned p;

	p = sched_find_free();

	if(p == -1)
		return (pid_t) -1;

	kstrcpy(task_list[p].name, task_list[current_task].name);
	task_list[p].state = TS_READY;
	kmemcpy(&task_list[p].regs, &task_list[current_task], sizeof(regs_t));

	active_tasks++;

	arch_crit_end();
	return p;
}


/** Search for a free task structure */
int sched_find_free()
{
	int i;

	for(i = 0; i < SCHEDULAR_TASKS; i++)
		if(task_list[i].state == TS_NULL)
			return i;
	return -1;
}



/** Go to next task */
void sched_next()
{
	//kprintf("switch\n");

	if(active_tasks == 0)
		return;

	/* Change task */        
	if(++current_task >= (SCHEDULAR_TASKS-1))
		current_task = 0;


	while(task_list[current_task].state != TS_READY)
	{
		if(++current_task >= (SCHEDULAR_TASKS-1))
			current_task = 0;
	}
}

/** Return the pid of the current process */
pid_t sched_get_pid()
{
	return current_task;
}
