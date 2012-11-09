#include <syscall.h>

int dev_main()
{

	for(;;) syscall_video_putch('d');
}



