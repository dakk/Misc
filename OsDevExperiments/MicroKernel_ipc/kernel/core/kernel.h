#ifndef KERNEL_H
#define KERNEL_H

#include <types.h>

#define KER_NAME		"unnamed"
#define KER_VERSION		"0.1"
#define KER_SYMBOLS_N	32



typedef enum 
{ 
	KSI_SHUTDOWN, 
	KSI_PUTCHAR, 
	KSI_REBOOT, 
	KSI_ALLOC, 
	KSI_FREE,
	KSI_EXEC,
	KSI_GET_PID,
	KSI_EXIT,
	KSI_FORK,
	KSI_MSG_SEND,
	KSI_MSG_RECV,
	KSI_MSG_CLEAR
} ker_symbols_id;


typedef uint32_t (*ker_entry)(uint32_t arg1, uint32_t arg2, uint32_t arg3, uint32_t arg4);


ker_entry ker_symbols[32];


#endif
