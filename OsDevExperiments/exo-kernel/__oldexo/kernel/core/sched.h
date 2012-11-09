#ifndef SCHED_H
#define SCHED_H

#include <types.h>
#include <core/arch.h>

#define SCHEDULAR_PTIME	10
#define SCHEDULAR_TICKS	10		///< Ticks to switch
#define SCHEDULAR_TASKS	500		///< Max number of tasks


typedef enum { TS_READY, TS_NULL } task_state_t;

/** Task structure */
typedef struct
{
	char			name[32];
	uint32_t		cpu;
	regs_t			regs;
	int32_t			timer;
	
	void 			*arch_data;
	void			*base;
	uint32_t		size;

	task_state_t	state;
} task_t;


task_t task_list[SCHEDULAR_TASKS];		///< List of tasks


int sched_init();
pid_t sched_exec(char *name, void *entry, void *argv, void *env);
pid_t sched_fork();
void sched_exit();
pid_t sched_get_pid();

int sched_find_free();
void sched_next();

unsigned sched_started;

#endif
