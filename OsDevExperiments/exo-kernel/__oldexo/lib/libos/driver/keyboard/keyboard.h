#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <libos.h>


typedef struct
{
	unsigned lshift;
	unsigned rshift;
	unsigned alt;
	unsigned control;
	unsigned caps_lock;
	unsigned num_lock;

	unsigned code;
} keyboard_stat_t;

/*		static const uint8_t SHIFT_LEFT		=	0x2A;
		static const uint8_t SHIFT_RIGHT	=	0x36;
		static const uint8_t PAGE_UP		=	0x49;
		static const uint8_t PAGE_DOWN		=	0x51;
		static const uint8_t LOCK_CAPS		=	0x3A;
		static const uint8_t LOCK_NUM		=	0x45;
		static const uint8_t LED_NUM		=	2;
		static const uint8_t LED_CAPS		=	4;
*/		
		
#endif
