#include "libos.h"
#include "address.h"

/************************
 * kernel
 */
void *get_multiboot_header()
{
	/*void *(*call)();
	call = (void *) _ARCH_GET_HEADER;
	return call();*/
	return NULL;
}

void io_outb(uint16_t port, uint8_t value)
{
	void (*call)(uint16_t port, uint8_t value);
	call = (void *) _IO_OUTB;
	call(port, value);
}

uint8_t io_inb(uint16_t port)
{
	uint8_t (*call)(uint16_t port);
	call = (void *) _IO_INB;
	return call(port);
}

uint16_t io_inw(uint16_t port)
{
	uint16_t (*call)(uint16_t port);
	call = (void *) _IO_INW;
	return call(port);
}



void io_outw(uint16_t port, uint16_t value)
{
	void (*call)(uint16_t port, uint16_t value);
	call = (void *) _IO_OUTW;
	call(port, value);
}

void io_outd(uint16_t port, uint32_t value)
{
	void (*call)(uint16_t port, uint32_t value);
	call = (void *) _IO_OUTD;
	call(port, value);
}

uint32_t io_ind(uint16_t port);
void io_outl(uint16_t port, uint64_t value);
uint64_t io_inl(uint16_t port);
void io_insl(uint16_t port, char *buffer, uint32_t count);
void io_outsw(uint16_t port, uint16_t *buffer, uint32_t count);
void io_insw(uint16_t port, uint16_t *buffer, uint32_t count);



void sched_exit()
{
	void (*call)();
	call = (void *) _SCHED_EXIT;
	call();
	for(;;);
}

pid_t sched_exec(char *name, void *entry, void *argv, void *env)
{
	pid_t (*call)(char *name, void *entry, void *argv, void *env);
	call = (void *) _SCHED_EXEC;
	return call(name, entry, argv, env);
}

pid_t sched_fork()
{
	pid_t (*call)();
	call = (void *) _SCHED_FORK;
	return call();
}

void mm_reserve(uint32_t from, uint32_t to)
{
	void (*call)(uint32_t from, uint32_t to);
	call = (void *) _PHYS_RESERVE;
	call(from, to);
}


void mm_free(void *adr)
{
	void (*call)(void *adr);
	call = (void *) _MM_FREE;
	call(adr);
}


void *mm_alloc(size_t size)
{
	void *(*call)(size_t size);
	call = (void *) _MM_ALLOC;
	return call(size);
}


uint32_t mm_get_total_mem()
{
	uint32_t (*call)();
	call = (void *) _MM_GET_TOTAL_MEM;
	return call();
}


uint32_t mm_get_used_mem()
{
	uint32_t (*call)();
	call = (void *) _MM_GET_USED_MEM;
	return call();
}



void shutdown()
{
	void (*call)();
	call = (void *) _SHUTDOWN;
	call();
}


void reboot()
{
	void (*call)();
	call = (void *) _REBOOT;
	call();
}



uint32_t mm_get_usable_size(void *adr)
{
	uint32_t (*call)(void *adr);
	call = (void *) _MM_GET_USABLE_SIZE;
	return call(adr);
}



void kputchar(char ch)
{
	void (*call)(char ch);
	call = (void *) _KPUTCHAR;
	call(ch);
}




uint32_t timer_get_tick()
{
	uint32_t (*call)();
	call = (void *) _TIMER_GET_TICK;
	return call();
}




/********************************
 * driver/
 */
struct device_p *device_get(char *name)
{
	struct device_p *(*call)(char *name);
	call = (void *) _DEVICE_GET;
	return call(name);	
}

int device_probe_all(bus_type_t bus)
{
	int (*call)(bus_type_t bus);
	call = (void *) _DEVICE_PROBE_ALL;
	return call(bus);
}


void driver_add_all_drivers()
{	
	void (*call)();
	call = (void *) _DRIVER_ADD_ALL_DRIVERS;
	call();
}


void driver_add(struct driver_p *driver)
{	
	void (*call)(struct driver_p *driver);
	call = (void *) _DRIVER_ADD;
	call(driver);
}


/********************************
 * vfs/
 */
int vfs_mount(char *dev, char *point, char *fs, char *flags)
{
	int (*call)(char *dev, char *point, char *fs, char *flags);
	call = (void *) _VFS_MOUNT;
	return call(dev, point, fs, flags);
}


int vfs_umount(char *dev)
{
	int (*call)(char *dev);
	call = (void *) _VFS_UMOUNT;
	return call(dev);
}


struct vfs_node_p *vfs_open(char *path, char *flags)
{
	struct vfs_node_p *(*call)(char *path, char *flags);
	call = (void *) _VFS_OPEN;
	return call(path, flags);
}


uint32_t vfs_read(struct vfs_node_p *fp, char *buf, uint32_t size, uint64_t offset)
{
	uint32_t (*call)(struct vfs_node_p *fp, char *buf, uint32_t size, uint64_t offset);
	call = (void *) _VFS_READ;
	return call(fp, buf, size, offset);
}

uint32_t vfs_write(struct vfs_node_p *fp, char *buf, uint32_t size, uint64_t offset)
{
	uint32_t (*call)(struct vfs_node_p *fp, char *buf, uint32_t size, uint64_t offset);
	call = (void *) _VFS_WRITE;
	return call(fp, buf, size, offset);
}

void vfs_close(struct vfs_node_p *fp)
{
	void (*call)(struct vfs_node_p *fp);
	call = (void *) _VFS_CLOSE;
	call(fp);
}

int vfs_readdir(struct vfs_node_p *node, struct readdir_t *rd, unsigned i)
{
	int (*call)(struct vfs_node_p *node, struct readdir_t *rd, unsigned i);
	call = (void *) _VFS_READDIR;
	return call(node, rd, i);
}

int vfs_remove(struct vfs_node_p *node)
{
	int (*call)(struct vfs_node_p *node);
	call = (void *) _VFS_REMOVE;
	return call(node);
}



/********************************
 * ui/
 */
void ui_add_window(struct ui_window_p *w)
{
	void (*call)(struct ui_window_p *w);
	call = (void *) _UI_ADD_WINDOW;
	call(w);
}

void ui_del_window(struct ui_window_p *w)
{
	void (*call)(struct ui_window_p *w);
	call = (void *) _UI_DEL_WINDOW;
	call(w);
}

ui_env_t *ui_get_env()
{
	ui_env_t *(*call)();
	call = (void *) _UI_GET_ENV;
	return call();
}

void ui_env_init()
{
	void (*call)();
	call = (void *) _UI_ENV_INIT;
	call();
}
