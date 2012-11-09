#ifndef PROTO_H
#define PROTO_H

#include <types.h>

typedef struct proto
{
	uint32_t	call;
	uint64_t	arg1;
	uint64_t	arg2;
	uint64_t	arg3;
	uint64_t	arg4;
	uint64_t	arg5;
} proto_t;

typedef struct proto_reply
{
	uint32_t	reply;
} proto_reply_t;


#define PROTO_SIZE			(sizeof(proto_t))
#define PROTO_REPLY_SIZE	(sizeof(proto_reply_t))

#endif
