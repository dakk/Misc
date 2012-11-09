#ifndef IPC_H
#define IPC_H

#include <types.h>

#define MSG_SIZE		256
#define MSG_MAX			256


typedef struct
{
	uint8_t		data[MSG_SIZE];
	uint16_t	size;
	pid_t		from;
	pid_t		to;
	uid_t		user;
} msg_t;

typedef struct
{
	msg_t		queue[MSG_MAX];
	uint16_t 	number;
} msg_queue_t;



#ifndef __CSYSCALL_H
	uint8_t		msg_send(msg_t *m);
	uint8_t		msg_recv(msg_t *m);
	void		msg_clear_queue();
	void		msg_init(void *t);
#endif

#endif
