/** 
 * Show some system's stats 
 * 
 */
#include <core/arch.h>
#include <core/sched.h>
#include <core/stdio.h>
#include <core/kernel.h>


void stat_main()
{
	int i;
	int j;

	for(;;)
	{
		kvideo_clear();
		kprintf("            " KER_NAME " " KER_VERSION ": system stats daemon\n\n");
		kvideo_move_cursor(2, 2);
		kprintf("id");
		kvideo_move_cursor(15, 2);
		kprintf("name");
		kvideo_move_cursor(30, 2);
		kprintf("state");
		kvideo_move_cursor(50, 2);
		kprintf("data");
		kvideo_move_cursor(65, 2);
		kprintf("ram usage");
		
		i = 0;
		for(j = 0; j < active_tasks; )
		{
			if(task_list[i].state == TS_NULL)
			{
				i++;
				continue;
			}
			
			kvideo_move_cursor(2, j+3);
			kprintf("%d", i);
			kvideo_move_cursor(15, j+3);
			kprintf("%s", task_list[i].name);
			kvideo_move_cursor(30, j+3);
			kprintf("%s", task_list[i].state != TS_NULL ? "running" : "stopped");
			kvideo_move_cursor(50, j+3);
			kprintf("%d", task_list[i].arch_data);
			kvideo_move_cursor(65, j+3);
			kprintf("%d", mm_get_used_mem_by_pid(i));
			
			i++;		
			j++;
		} 
		
		
		kvideo_move_cursor(2, 23);
		kprintf("ram: %d\tused: %d\tfree: %d", mm_get_total_mem(), 
				mm_get_used_mem(), mm_get_total_mem() - mm_get_used_mem());
		
		for(j = 0; j < 0x5FFFFF; j++);
	}
}



