#ifndef SYSCALL_H
#define SYSCALL_H


#include <types.h>
#include <ipc.h>

#ifndef __CSYSCALL_H
	#include <arch.h>
	#include <task.h>
#endif


#define DECL_SYSCALL0(fn) int syscall_##fn();
#define DECL_SYSCALL1(fn,p1) int syscall_##fn(p1);
#define DECL_SYSCALL2(fn,p1,p2) int syscall_##fn(p1,p2);
#define DECL_SYSCALL3(fn,p1,p2,p3) int syscall_##fn(p1,p2,p3);
#define DECL_SYSCALL4(fn,p1,p2,p3,p4) int syscall_##fn(p1,p2,p3,p4);
#define DECL_SYSCALL5(fn,p1,p2,p3,p4,p5) int syscall_##fn(p1,p2,p3,p4,p5);

#define DEFN_SYSCALL0(fn, num) \
int syscall_##fn() \
{ \
  int a; \
  asm volatile("int $0x80" : "=a" (a) : "0" (num)); \
  return a; \
}

#define DEFN_SYSCALL1(fn, num, P1) \
int syscall_##fn(P1 p1) \
{ \
  int a; \
  asm volatile("int $0x80" : "=a" (a) : "0" (num), "b" ((int)p1)); \
  return a; \
}

#define DEFN_SYSCALL2(fn, num, P1, P2) \
int syscall_##fn(P1 p1, P2 p2) \
{ \
  int a; \
  asm volatile("int $0x80" : "=a" (a) : "0" (num), "b" ((int)p1), "c" ((int)p2)); \
  return a; \
}

#define DEFN_SYSCALL3(fn, num, P1, P2, P3) \
int syscall_##fn(P1 p1, P2 p2, P3 p3) \
{ \
  int a; \
  asm volatile("int $0x80" : "=a" (a) : "0" (num), "b" ((int)p1), "c" ((int)p2), "d"((int)p3)); \
  return a; \
}

#define DEFN_SYSCALL4(fn, num, P1, P2, P3, P4) \
int syscall_##fn(P1 p1, P2 p2, P3 p3, P4 p4) \
{ \
  int a; \
  asm volatile("int $0x80" : "=a" (a) : "0" (num), "b" ((int)p1), "c" ((int)p2), "d" ((int)p3), "S" ((int)p4)); \
  return a; \
}

#define DEFN_SYSCALL5(fn, num) \
int syscall_##fn(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5) \
{ \
  int a; \
  asm volatile("int $0x80" : "=a" (a) : "0" (num), "b" ((int)p1), "c" ((int)p2), "d" ((int)p3), "S" ((int)p4), "D" ((int)p5)); \
  return a; \
}



typedef enum 
{
	SYS_VIDEO_PUTCH,
	SYS_TASK_EXIT,
	SYS_TASK_FORK,
	SYS_TASK_EXEC,
	SYS_TASK_GETPID,
	SYS_TASK_GETNAME,
	SYS_TASK_KILL,
	SYS_MSG_CLEAR_QUEUE,
	SYS_MSG_SEND,
	SYS_MSG_RECV	
} syscall_list;


DECL_SYSCALL1(video_putch, char)
DECL_SYSCALL0(task_exit)
DECL_SYSCALL0(task_fork)
DECL_SYSCALL4(task_exec, void*, char*, char*, char*)
DECL_SYSCALL0(task_getpid)
DECL_SYSCALL0(task_getname)
DECL_SYSCALL1(task_kill, pid_t)
DECL_SYSCALL0(msg_clear_queue)
DECL_SYSCALL1(msg_send, msg_t*)
DECL_SYSCALL1(msg_recv, msg_t*)

//DEFN_SYSCALL1(video_puts, 0, const char*);


#define SYSCALL_NUM		10



#ifndef __CSYSCALL_H

static void *syscalls[10] =
{
    &video_putch,
    &task_exit,
    &task_fork,
    &task_exec,
    &task_getpid,
    &task_getname,
    &task_kill,
    &msg_clear_queue,
    &msg_send,
    &msg_recv
};
#endif


#endif
