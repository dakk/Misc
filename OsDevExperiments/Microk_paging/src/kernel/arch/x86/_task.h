#ifndef _TASK_H
#define _TASK_H

#include <types.h>

#define KERNEL_STACK_SIZE	2048

void	task_init();
void	task_switch();
void	move_stack(void *new_stack_start, uint32_t size);


#endif
