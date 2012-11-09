#ifndef TASK_H
#define TASK_H

#include <types.h>
#include <ipc.h>

#define TASK_NAME_SIZE		32

typedef enum 
{
	TS_RUNNING,
	TS_SLEEP,
	TS_KILLED
} task_state_t;

typedef struct task
{
    pid_t			id; 
    char			name[TASK_NAME_SIZE];			
    task_state_t	state;	
    
    uint32_t		time_to_sleep;
    
    uint32_t		esp;
    uint32_t		ebp; 
    uint32_t		eip; 
    void *			page_directory;
    uint32_t		kernel_stack; 
    
    msg_queue_t		msg_queue;
    
    struct task *	next; 
} task_t;


// Current task in execution
task_t *task_current;

// Task list queue
task_t *task_list;



void	task_exit();
pid_t	task_fork();
pid_t	task_exec(void *entry, char *name, char **args, char **env);
pid_t	task_getpid();
char*	task_getname();
void	task_kill(pid_t id);
void	task_userswitch();

#endif
