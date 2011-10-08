/**
 * \mainpage libOs
 * LibOs is the $(system) library that include all system api to create
 * applications for this exokernel system. Api are splitted in 4 main 
 * modules:
 * 		- <b>KernelBinding</b>:
 * 			it provides some function to handle kernel functions to allocate
 * 			and deallocate memory, create, kill and fork process, i/o with 
 * 			ports and other related things.
 *
 * 		- <b>VirtualFileSystem</b>:
 * 			it provides functions to mount/umount/format a filesystem and 
 * 			functions to perform operation with nodes (open/write/read/etc).
 * 			
 * 		- <b>Ui</b>:
 * 			it provides an object oriented framework to create graphics
 * 			user interface in a simple way. The gui layout manager is 
 * 			based on the boxing system (like gtk), and the event-handling
 * 			is made trought registered callbacks. There's a tiny set of 
 * 			widgets	at the moment.
 *
 * 		- <b>DeviceDriver</b>:
 * 			it provides a common interface for different drivers, and few 
 * 			functions to add/del drivers and probe devices from different 
 * 			types of bus (pci, usb, isa).
 *
 * 		- <b>Network</b>:
 *
 * 		- <b>Audio</b>:
 */
#ifndef __LIBOS_H
#define __LIBOS_H

#include "config.h"
#include "types.h"
#include "kernel/arch/x86/multiboot.h"
#include "kernel/arch/x86/arch.h"
#include "vfs/vfs.h"
#include "driver/driver.h"
#include "ui/ui.h"

/** \defgroup kernel KernelBinding */


/** \addtogroup kernel 
 * @{
 */
void *kmemset(void *s, int c, size_t n);
void *kmemcpy(void *b , const void *a, size_t n);

void io_outb(uint16_t port, uint8_t value);
uint8_t io_inb(uint16_t port);
uint16_t io_inw(uint16_t port);
void io_outw(uint16_t port, uint16_t value);
void io_outd(uint16_t port, uint32_t value);
//uint32_t io_ind(uint16_t port);
//void io_outl(uint16_t port, uint64_t value);
//uint64_t io_inl(uint16_t port);
//void io_insl(uint16_t port, char *buffer, uint32_t count);
//void io_outsw(uint16_t port, uint16_t *buffer, uint32_t count);
//void io_insw(uint16_t port, uint16_t *buffer, uint32_t count);


/* Schedular */
/** Exec a process */
pid_t sched_exec(char *name, void *entry, void *argv, void *env);
/** Fork the process */
pid_t sched_fork();
/** Exit from the process */
void sched_exit();


/* Memory */
/** Reserve a section of memory */
void mm_reserve(uint32_t, uint32_t);
/** Release a block of memory */
void mm_free(void *);
/** Alloc a block of memory */
void *mm_alloc(size_t);
/** Get the total amount of ram */
uint32_t mm_get_total_mem();
/** Get the total amount of used ram */
uint32_t mm_get_used_mem();
/** Get the size of a block */
uint32_t mm_get_usable_size(void *);


/** Shutdown the computer */
void shutdown();
/** Reboot the system */
void reboot();

/** Get tick count */
uint32_t timer_get_tick();

/** Put a char in the kernel output console */
void kputchar(char ch);

/** Get the multiboot header */
void *get_multiboot_header();

/** @}  */
#endif
