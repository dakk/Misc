/** Vesa driver */
#include <libos.h>
#include "vesa.h"



multiboot_info_t *mbh;
vesa_mode_info_t *vmi;
vesa_general_info_t *vci;
char *vesa_mem;



int vesa_probe(bus_type_t bus)
{
	return 1;

	mbh = (multiboot_info_t *) arch_get_header();

	if(mbh->vbe_control_info != 0)
		return 1;
	else
		return 0;
}



int vesa_init(struct device_p *dev)
{
	kprintf("vesa_init\n");

	mbh = (multiboot_info_t *) arch_get_header();
	vmi = (vesa_mode_info_t *) mbh->vbe_mode_info;
	vci = (vesa_general_info_t *) mbh->vbe_control_info;
	vesa_mem = (char *) vmi->phys_base_ptr;

	return 1;
}

int vesa_release(struct device_p *dev)
{
	return 1;
}


uint32_t vesa_read(struct device_p *dev, char *buf, uint32_t size, uint64_t off)
{
	return 0;
}


uint32_t vesa_write(struct device_p *dev, char *buf, uint32_t size, uint64_t off)
{
	return 0;
}


uint32_t vesa_ioctl(struct device_p *dev, uint32_t fun, uint32_t arg1, uint32_t arg2, uint32_t arg3)
{

	register char *ptmp;

	switch(fun)
	{
		case VESA_IOCTL_GET_BUFFER:
			return (uint32_t) vesa_mem;

		case VESA_IOCTL_DRAW_PIXEL:
			//if (arg1 < 0 || arg1 > vmi->width || arg2 < 0 || arg2 > vmi->height) 
			//	return 0;
	
			arg1 = (arg1 * (vmi->bits_per_pixel >> 3));
			arg2 = (arg2 * vmi->bytes_per_scan_line);
	
			ptmp = &vesa_mem[arg1+arg2];
			ptmp[0] = arg3 & 0xff;
			ptmp[1] = (arg3>>8) & 0xff;
			ptmp[2] = (arg3>>16) & 0xff;
			return 0;

		case VESA_IOCTL_GET_PIXEL:
			if (arg1 < 0 || arg1 > vmi->width || arg2 < 0 || arg2 > vmi->height) 
				return 0;
		
			arg1 = (arg1 * (vmi->bits_per_pixel >> 3));
			arg2 = (arg2 * vmi->bytes_per_scan_line);

			ptmp = &vesa_mem[arg1+arg2];
	
			return *((char *) ptmp);


		case VESA_IOCTL_GET_BPSL:
			return vmi->bytes_per_scan_line;

		case VESA_IOCTL_GET_X:
			return vmi->width;

		case VESA_IOCTL_GET_Y:
			return vmi->height;	

		case VESA_IOCTL_GET_BPP:
			return vmi->bits_per_pixel;	
			
		default:
			return 0;
	}

}





struct driver_p _vesa_driver =
{
	.name = "vesa",

	.probe = vesa_probe,
	.init = vesa_init,
	.ioctl = vesa_ioctl,
	.write = vesa_write,
	.read = vesa_read,
	.release = vesa_release
};


