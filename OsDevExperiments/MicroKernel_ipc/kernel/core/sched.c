#include <core/sched.h>
#include <core/elf.h>
#include <core/stdio.h>
#include <core/mm.h>
#include <config.h>


task_t *task_current = NULL;
task_t *task_list = NULL;


/** Initialize the schedular */
int sched_init()
{
	id_current = 1;

	task_list = NULL;
	task_current = NULL;

	return 1;
}


/** Exec a program */
pid_t sched_exec(char *name, void *entry, void *argv, void *env)
{
	if(entry == NULL)
		return (pid_t) -1;

	arch_crit_start();

	task_t *new = mm_alloc(sizeof(task_t));

	new->id = id_current++;
	kstrcpy(new->name, name);
	new->state = TS_READY;
	msg_init(&(new->msg_queue));

	/* If it's an elf */
	if(elf_check(entry))
	{
		switch(elf_get_class(entry))
		{
			case ELF_CLASS_32:
				elf_relocate32(entry);
				new->regs.eip = (uint32_t) elf_get_entry32(entry);
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
		new->regs.eip = (uint32_t) entry;
	}
	new->arch_data = arch_exec((void *) new->regs.eip);

	new->regs.eflags = 0x202;

	new->next = task_list;
	task_list = new;

	if(task_current == NULL)
		task_current = new;

	arch_crit_end();
	
	return new->id;
}


/** Exit */
void sched_exit()
{
	if(task_current == NULL)
		return;

	arch_crit_start();

	arch_crit_end();
	for(;;);
}


/** Fork a child */
pid_t sched_fork()
{
	arch_crit_start();
	unsigned p;

	
	/*
	 * kstrcpy(task_list[p].name, task_list[current_task].name);
	task_list[p].state = TS_READY;
	kmemcpy(&task_list[p].regs, &task_list[current_task], sizeof(regs_t));

	msg_init(&(task_list[p].msg_queue));
	active_tasks++;
	*/
	arch_crit_end();
	return p;
}




/** Go to next task */
void sched_next()
{
	if(task_current == NULL)
		return;

	task_current = task_current->next;

	if(task_current == NULL)
		task_current = task_list;
	
	//kprintf("Switch to %s\n", task_current->name);
}

/** Return the pid of the current process */
pid_t sched_get_pid()
{
	return task_current->id;
}
