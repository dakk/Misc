/** 
 * Show some system's stats 
 * 
 */
#include <core/arch.h>
#include <core/sched.h>
#include <core/stdio.h>
#include <core/kernel.h>
#include <core/mm.h>


void stat_main()
{
	int i;
	int j;


	kvideo_clear();

	for(;;)
	{
		arch_crit_start();


		kvideo_clear();
		
		kvideo_move_cursor(0, 0);
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
		kprintf("ram usage\n");
		
		i = 0;
		j = 0;

		task_t *t = task_list;
		while(t != NULL)
		{
			if(t->state == TS_NULL)
			{
				i++;
				continue;
			}
			
			kvideo_move_cursor(2, j+3);
			kprintf("%d", i);
			kvideo_move_cursor(15, j+3);
			kprintf("%s", t->name);
			kvideo_move_cursor(30, j+3);
			kprintf("%s", t->state != TS_NULL ? "running" : "stopped");
			kvideo_move_cursor(50, j+3);
			kprintf("%d", t->arch_data);
			kvideo_move_cursor(65, j+3);
			kprintf("%d\n", mm_get_used_mem_by_pid(sched_get_pid()));
			
			i++;		
			j++;

			t = t->next;
		} 
		
		//mm_alloc(1000);
		kvideo_move_cursor(2, 23);
		kprintf("ram: %d\tused: %d\tfree: %d", mm_get_total_mem(), 
				mm_get_used_mem(), mm_get_total_mem() - mm_get_used_mem());
		
		for(i = 0; i < 50; i++)
			for(j = 0; j < 0xFFFFF; j++);

		arch_crit_end();
	}
}



