#include <core/ipc.h>
#include <core/sched.h>
#include <core/stdio.h>

uint8_t msg_send(msg_t *m)
{
	if(m->to > id_current)
		return 0;

	task_t *tl = task_list;

	while((tl != NULL) && (tl->id != m->to))
		tl = tl->next;

	if(tl != NULL)
		kmemcpy(&(tl->msg_queue.queue[++tl->msg_queue.number]), m, sizeof(msg_t));
	else
		return 0;
	
	return 1;
}

uint8_t	msg_recv(msg_t *m)
{
	if(task_current->msg_queue.number > 0)
		kmemcpy(m, &task_current->msg_queue.queue[--task_current->msg_queue.number], sizeof(msg_t));
	else
		return 0;
	return 1;
}



void msg_init(msg_queue_t *q)
{
	q->number = 0;	
}


void msg_clear_queue()
{
	msg_init(&(task_current->msg_queue));
}


