#ifndef DRIVER_H
#define DRIVER_H

#include <types.h>

struct device_p;

/** \defgroup drvdev DeviceDriver */
/** \defgroup dev Device */
/** \defgroup drv Driver */

/** \addtogroup drvdev
 * @{
 */

/** \addtogroup drv
 * @{
 */

/** Bus types */
typedef enum { BUS_PCI, BUS_ISA, BUS_USB } bus_type_t;

/** Structure of a driver */
typedef struct driver_p
{
	char name[32];						///< Name of the driver

	int (*probe)(bus_type_t bus);
	int (*init)(struct device_p *dev);
	int (*release)(struct device_p *dev);
	uint32_t (*read)(struct device_p *dev, char *buf, uint32_t size, uint64_t off);
	uint32_t (*write)(struct device_p *dev, char *buf, uint32_t size, uint64_t off);
	uint32_t (*ioctl)(struct device_p *dev, uint32_t fun, uint32_t arg1, uint32_t arg2, uint32_t arg3);

	struct driver_p *next;
} driver_t;



/** Add a new driver */
void driver_add(struct driver_p *driver);

/** Add all libOs drivers */
void driver_add_all_drivers();


/** @} */

/** \addtogroup dev
 * @{
 */
/** Structure of a device */
typedef struct device_p
{
	char name[32];

	struct driver_p *driver;
	struct device_p *next;
} device_t;


/** Get a device by the name */
struct device_p *device_get(char *name);

/** Probe all devices of a bus */
int device_probe_all(bus_type_t bus);


/** @} */
/** @} */

#endif
