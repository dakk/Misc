#include <libos.h>
#include "keyboard.h"

unsigned key_take = 1;
keyboard_stat_t keys;


///< Caratteri ascii
char standard_charset[] = {
		0, 0, '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '\'', 0, '\b', '\t', 'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p',   
		0, 0, '\n', 0, 'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 0, 0, 0, 0, 0, 'z', 'x', 'c', 'v', 'b', 'n', 'm', ',', '.', 
		'-', 0, 0, 0, ' ', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,'-', 0, '5', 0, '+', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 
	};
			
///< Caratteri ascii maiuscoli
char standard_charset_chifted[] = {
		0, 0, '!', '"', 0, '$', '%', '&', '/', '(', ')', '=', '?', '^', 0, '\t', 'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P', '[',
		']', '\n', 0, 'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L', '@', '#', 0, 0, '\\', 'Z', 'X', 'C', 'V', 'B', 'N', 'M', ';', ':', '_', 0,
		0, 0, ' ', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,'-', 0, '5', 0, '+', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 
	};




void keyboard_update_leds(uint8_t status)
{
 	while((io_inb(0x64)&2)!=0){}
 	io_outb(0x60,0xED);
 
 	while((io_inb(0x64)&2)!=0){}
 	io_outb(0x60,status);
}


#if 0
	unsigned code = io_inb(0x60);

	// Tasto rilasciato
    if (code & 0x80)
    {
		code &= 0x7F;
		switch(code)
		{
		/*	case KeyboardDriver::SHIFT_LEFT:
				Keys.LShift = false;
				break;

			case KeyboardDriver::SHIFT_RIGHT:
				Keys.RShift = false;
				break;
		}
    }
    // Tasto premuto
    else
    {
		switch(code)
		{						
			case KeyboardDriver::LOCK_CAPS:
				Keys.CapsLock = !Keys.CapsLock;
				updateLeds(KeyboardDriver::LED_CAPS | KeyboardDriver::LED_NUM);
				break;
				
			case KeyboardDriver::LOCK_NUM:
				Keys.NumLock = !Keys.NumLock;
				updateLeds(KeyboardDriver::LED_CAPS | KeyboardDriver::LED_NUM);
				break;
				
			case KeyboardDriver::SHIFT_LEFT:
				Keys.LShift = true;
				break;

			case KeyboardDriver::SHIFT_RIGHT:
				Keys.RShift = true;
				break;
			
			default:
				Keys.Code = code;
				//if((shift && !capslock) || (!shift && capslock)) buf[bufpoint] = keyboard_standard_charset_shifted[code];
				//else buf[bufpoint] = keyboard_standard_charset[code];
				//bufsize++;
				//bufpoint++;
				break;
		*/}
    }

}
#endif

/*

keyboard_stat_t keyboard_get_keys_state()
{
	return keys;
}
*/







int keyboard_probe(bus_type_t bus)
{
	return 1;
}


int keyboard_init(struct device_p *dev)
{
	keys.rshift = 0;
	keys.lshift = 0;
	keys.alt = 0;
	keys.control = 0;
	keys.caps_lock = 0;
	keys.num_lock = 0;
	keys.code = 0;


	return 1;
}

int keyboard_release(struct device_p *dev)
{
	return 1;
}


uint32_t keyboard_read(struct device_p *dev, char *buf, uint32_t size, uint64_t off)
{
	return 0;
}


uint32_t keyboard_write(struct device_p *dev, char *buf, uint32_t size, uint64_t off)
{
	return 0;
}


uint32_t keyboard_ioctl(struct device_p *dev, uint32_t fun, uint32_t arg1, uint32_t arg2, uint32_t arg3)
{
	return 0;
}





struct driver_p _keyboard_driver =
{
	.name = "kbd",

	.probe = keyboard_probe,
	.init = keyboard_init,
	.ioctl = keyboard_ioctl,
	.write = keyboard_write,
	.read = keyboard_read,
	.release = keyboard_release
};


