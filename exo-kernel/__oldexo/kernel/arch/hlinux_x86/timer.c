#include <types.h>
#include <core/stdio.h>
#include <core/sched.h>
#include <core/arch.h>

uint32_t pit_tick = 0;		///< Contatore dei PIT


/* ms sleep */
void timer_sleep(uint32_t ms)
{
}



 
/* tick count */
uint32_t timer_get_tick()
{
	return pit_tick;	
}

