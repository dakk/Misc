#ifndef SCHED_H
#define SCHED_H

#include <types.h>
#include <core/ipc.h>
#include <core/arch.h>

#define SCHEDULAR_PTIME	10
#define SCHEDULAR_TICKS	10		///< Ticks to switch


typedef enum { TS_READY, TS_NULL } task_state_t;

/** Task structure */
typedef struct task_p
{
	pid_t			id;
	char			name[32];
	uint32_t		cpu;
	regs_t			regs;
	int32_t			timer;
	
	void 			*arch_data;
	void			*base;
	uint32_t		size;

	msg_queue_t		msg_queue;
	task_state_t		state;

	struct task_p		*next;
} task_t;


task_t		*task_list;
task_t		*task_current;
pid_t		id_current;

int		sched_init();
pid_t		sched_exec(char *name, void *entry, void *argv, void *env);
pid_t		sched_fork();
void		sched_exit();
pid_t		sched_get_pid();
void		sched_next();

unsigned	sched_started;

#endif
