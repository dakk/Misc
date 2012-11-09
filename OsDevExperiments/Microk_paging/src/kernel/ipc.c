#include <ipc.h>
#include <task.h>
#include <libc.h>

uint8_t msg_send(msg_t *m)
{
	task_t *t = task_list;
	
	while(t->next != NULL)
	{
		if(t->id == m->to)
		{
			kmemcpy(&t->msg_queue.queue[++t->msg_queue.number], m, sizeof(msg_t));
			return 1;
		}
	}
	return 0;
}

uint8_t	msg_recv(msg_t *m)
{
	if(task_current->msg_queue.number > 0)
		kmemcpy(m, &task_current->msg_queue.queue[--task_current->msg_queue.number], sizeof(msg_t));
	else
		return 0;
	return 1;
}



void msg_init(void *t)
{
	((task_t*) t)->msg_queue.number = 0;	
}


void msg_clear_queue()
{
	msg_init((void*) task_current);
}
