#include <ipc.h>
#include <syscall.h>

DEFN_SYSCALL1(video_putch, SYS_VIDEO_PUTCH, char)
DEFN_SYSCALL0(task_exit, SYS_TASK_EXIT)
DEFN_SYSCALL0(task_fork, SYS_TASK_FORK)
DEFN_SYSCALL4(task_exec, SYS_TASK_EXEC, void*, char*, char*, char*)
DEFN_SYSCALL0(task_getpid, SYS_TASK_GETPID)
DEFN_SYSCALL0(task_getname, SYS_TASK_GETNAME)
DEFN_SYSCALL1(task_kill, SYS_TASK_KILL, pid_t)
DEFN_SYSCALL0(msg_clear_queue, SYS_MSG_CLEAR_QUEUE)
DEFN_SYSCALL1(msg_send, SYS_MSG_SEND, msg_t*)
DEFN_SYSCALL1(msg_recv, SYS_MSG_RECV, msg_t*)

