#include <syscall.h>
#include <arch.h>
#include <kernel.h>

extern dev_main();
	

int main(void *mboot_ptr, uint32_t initial_stack)
{
	pid_t p;
    video_clear();
    
	kputs("initializing kernel: " KERNEL_NAME " " KERNEL_VER "\n");
	arch_init(mboot_ptr, initial_stack);
	kputs("starting servers: ");

	task_exec(0, 0, 0, 0);
	kputs("dev ");
	kputs("vfs ");
	kputs("net ");
	//kputs("stat ");
	kputs("init ");
	kputs("\n");
	
	while(1);
	kputs("going in unsermode.\n");
	task_userswitch();
	
	
	
	//task_exec(&dev_main, "dev", NULL, NULL);
	
	/*
	task_userswitch();
	
	syscall_video_putch('c');
	syscall_video_putch('i');
	syscall_video_putch('a');
	
	syscall_task_fork();
	dev_main();
	*/
	
	while(1);
    return 0;
}
