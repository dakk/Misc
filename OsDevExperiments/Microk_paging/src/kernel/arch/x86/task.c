#include <libc.h>
#include "task.h"
#include "_task.h"
#include "paging.h"


extern page_directory_t *kernel_directory;
extern page_directory_t *current_directory;
extern void alloc_frame(page_t*,int,int);
extern uint32_t initial_esp;
extern uint32_t read_eip();

// The next available process ID.
uint32_t next_pid = 1;

void task_init()
{
	// Rather important stuff happening, no interrupts please!
	asm volatile("cli");

	// Relocate the stack so we know where it is.
	move_stack((void*)0xE0000000, 0x2000);

	// Initialise the first task (kernel task)
	task_current = task_list = (task_t*)kmalloc(sizeof(task_t));
	task_current->id = next_pid++;
	task_current->esp = task_current->ebp = 0;
	task_current->eip = 0;
	task_current->page_directory = current_directory;
	task_current->next = 0;
	task_current->kernel_stack = kmalloc_a(KERNEL_STACK_SIZE);
	msg_init(task_current);
	
	kstrcpy(task_current->name, "sys");

	// Reenable interrupts.
	asm volatile("sti");
}

void move_stack(void *new_stack_start, uint32_t size)
{
	uint32_t i;
	// Allocate some space for the new stack.
	for( i = (uint32_t)new_stack_start;
		 i >= ((uint32_t)new_stack_start-size);
		 i -= 0x1000)
	{
	// General-purpose stack is in user-mode.
	alloc_frame( get_page(i, 1, current_directory), 0 /* User mode */, 1 /* Is writable */ );
	}
	
	// Flush the TLB by reading and writing the page directory address again.
	uint32_t pd_addr;
	asm volatile("mov %%cr3, %0" : "=r" (pd_addr));
	asm volatile("mov %0, %%cr3" : : "r" (pd_addr));

	// Old ESP and EBP, read from registers.
	uint32_t old_stack_pointer; asm volatile("mov %%esp, %0" : "=r" (old_stack_pointer));
	uint32_t old_base_pointer;	asm volatile("mov %%ebp, %0" : "=r" (old_base_pointer));

	// Offset to add to old stack addresses to get a new stack address.
	uint32_t offset			= (uint32_t)new_stack_start - initial_esp;

	// New ESP and EBP.
	uint32_t new_stack_pointer = old_stack_pointer + offset;
	uint32_t new_base_pointer	= old_base_pointer	+ offset;

	// Copy the stack.
	kmemcpy((void*)new_stack_pointer, (void*)old_stack_pointer, initial_esp-old_stack_pointer);

	// Backtrace through the original stack, copying new values into
	// the new stack.	
	for(i = (uint32_t)new_stack_start; i > (uint32_t)new_stack_start-size; i -= 4)
	{
	uint32_t tmp = * (uint32_t*)i;
	// If the value of tmp is inside the range of the old stack, assume it is a base pointer
	// and remap it. This will unfortunately remap ANY value in this range, whether they are
	// base pointers or not.
	if (( old_stack_pointer < tmp) && (tmp < initial_esp))
	{
		tmp = tmp + offset;
		uint32_t *tmp2 = (uint32_t*)i;
		*tmp2 = tmp;
	}
	}

	// Change stacks.
	asm volatile("mov %0, %%esp" : : "r" (new_stack_pointer));
	asm volatile("mov %0, %%ebp" : : "r" (new_base_pointer));
}

void task_switch()
{
	// If we haven't initialised tasking yet, just return.
	if (!task_current)
		return;

	// Read esp, ebp now for saving later on.
	uint32_t esp, ebp, eip;
	asm volatile("mov %%esp, %0" : "=r"(esp));
	asm volatile("mov %%ebp, %0" : "=r"(ebp));

	// Read the instruction pointer. We do some cunning logic here:
	// One of two things could have happened when this function exits - 
	//	 (a) We called the function and it returned the EIP as requested.
	//	 (b) We have just switched tasks, and because the saved EIP is essentially
	//		 the instruction after read_eip(), it will seem as if read_eip has just
	//		 returned.
	// In the second case we need to return immediately. To detect it we put a dummy
	// value in EAX further down at the end of this function. As C returns values in EAX,
	// it will look like the return value is this dummy value! (0x12345).
	eip = read_eip();
    kprintf("%s\n", task_current->name);

	// Have we just switched tasks?
	if (eip == 0x12345)
		return;

	// No, we didn't switch tasks. Let's save some register values and switch.
	task_current->eip = eip;
	task_current->esp = esp;
	task_current->ebp = ebp;
	
	// Get the next task to run.
	task_current = task_current->next;
	// If we fell off the end of the linked list start again at the beginning.
	if (!task_current) task_current = task_list;

	eip = task_current->eip;
	esp = task_current->esp;
	ebp = task_current->ebp;

	// Make sure the memory manager knows we've changed page directory.
	current_directory = task_current->page_directory;

	// Change our kernel stack over.
	set_kernel_stack(task_current->kernel_stack+KERNEL_STACK_SIZE);
	// Here we:
	// * Stop interrupts so we don't get interrupted.
	// * Temporarily put the new EIP location in ECX.
	// * Load the stack and base pointers from the new task struct.
	// * Change page directory to the physical address (physicalAddr) of the new directory.
	// * Put a dummy value (0x12345) in EAX so that above we can recognise that we've just
	//	 switched task.
	// * Restart interrupts. The STI instruction has a delay - it doesn't take effect until after
	//	 the next instruction.
	// * Jump to the location in ECX (remember we put the new EIP in there).
	asm volatile("		 \
		cli;				 \
		mov %0, %%ecx;		 \
		mov %1, %%esp;		 \
		mov %2, %%ebp;		 \
		mov %3, %%cr3;		 \
		mov $0x12345, %%eax; \
		sti;				 \
		jmp *%%ecx			 "
				 : : "r"(eip), "r"(esp), "r"(ebp), "r"(current_directory->physicalAddr));
}

pid_t task_fork()
{
	// We are modifying kernel structures, and so cannot be interrupted.
	asm volatile("cli");

	// Take a pointer to this process' task struct for later reference.
	task_t *parent_task = (task_t*)task_current;

	// Clone the address space.
	page_directory_t *directory = clone_directory(current_directory);

	// Create a new process.
	task_t *new_task = (task_t*)kmalloc(sizeof(task_t));
	new_task->id = next_pid++;
	new_task->esp = new_task->ebp = 0;
	new_task->eip = 0;
	new_task->page_directory = directory;
	task_current->kernel_stack = kmalloc_a(KERNEL_STACK_SIZE);
	new_task->next = 0;
	msg_init(new_task);

	// Add it
	new_task->next = task_list;
	task_list = new_task;

	// This will be the entry point for the new process.
	uint32_t eip = read_eip();

	// We could be the parent or the child here - check.
	if (task_current == parent_task)
	{
		// We are the parent, so set up the esp/ebp/eip for our child.
		uint32_t esp; asm volatile("mov %%esp, %0" : "=r"(esp));
		uint32_t ebp; asm volatile("mov %%ebp, %0" : "=r"(ebp));
		new_task->esp = esp;
		new_task->ebp = ebp;
		new_task->eip = eip;

		asm volatile("sti");

		return new_task->id;
	}
	else
		return 0;
}


char* task_getname()
{
	return (char *) task_current->name;
}

pid_t task_getpid()
{
	return task_current->id;
}


void task_exit()
{
	
}


pid_t task_exec(void *entry, char *name, char **args, char **env)
{
	// Rather important stuff happening, no interrupts please!
	asm volatile("cli");

	// Clone the address space.
	kprintf("lol\n");
	page_directory_t *directory = clone_directory(current_directory);
	kprintf("lol\n");

	// Create a new process.
	task_t *new_task = (task_t*)kmalloc(sizeof(task_t));
	new_task->id = next_pid++;
	new_task->esp = new_task->ebp = 0;
	new_task->eip = 0;
	new_task->page_directory = directory;
	task_current->kernel_stack = kmalloc_a(KERNEL_STACK_SIZE);
	new_task->next = 0;
	//msg_init(new_task);

	new_task->next = task_list;
	task_list = new_task;

	uint32_t esp; asm volatile("mov %%esp, %0" : "=r"(esp));
	uint32_t ebp; asm volatile("mov %%ebp, %0" : "=r"(ebp));
	new_task->esp = esp;
	new_task->ebp = ebp;
	new_task->eip = read_eip();

	asm volatile("sti");

	return new_task->id;
}

void task_kill(pid_t id)
{
	task_t *t = task_list;
	task_t *p = 0;
	
	while(t->next != NULL)
	{
		p = t;
		t = t->next;
		
		if(t->id == id)
		{
			p->next = t->next;
			kfree(t);
			break;
		}
	}
}

void task_userswitch()
{
	// Set up our kernel stack.
	set_kernel_stack(task_current->kernel_stack+KERNEL_STACK_SIZE);
	
	// Set up a stack structure for switching to user mode.
	asm volatile("	\
		cli; \
		mov $0x23, %ax; \
		mov %ax, %ds; \
		mov %ax, %es; \
		mov %ax, %fs; \
		mov %ax, %gs; \
					\
		 \
		mov %esp, %eax; \
		pushl $0x23; \
		pushl %esp; \
		pushf; \
		pushl $0x1B; \
		push $1f; \
		iret; \
	1: \
		"); 
		
}
