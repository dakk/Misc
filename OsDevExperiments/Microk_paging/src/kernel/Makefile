include ../Makefile.conf

SOURCES=main.o libc.o array_ord.o ipc.o ../servers/servers.a
CFLAGS=-nostdlib -nostdinc -fno-builtin -Iinclude -I.
ASFLAGS=-felf
        
        
ifeq ($(ARCH),x86)
	ARCH_DIR=arch/x86
	
	SOURCES+= $(ARCH_DIR)/boot.o $(ARCH_DIR)/video.o $(ARCH_DIR)/dt.o 
	SOURCES+= $(ARCH_DIR)/isr.o $(ARCH_DIR)/int.o $(ARCH_DIR)/gdt.o
	SOURCES+= $(ARCH_DIR)/timer.o $(ARCH_DIR)/paging.o
	SOURCES+= $(ARCH_DIR)/kheap.o $(ARCH_DIR)/syscall.o $(ARCH_DIR)/arch.o
	SOURCES+= $(ARCH_DIR)/process.o $(ARCH_DIR)/task.o
	
	
	ifeq ($(BITS),32)
		CFLAGS+=-m32
		LDFLAGS=-T$(ARCH_DIR)/32/link.ld -melf_i386
	endif
	ifeq ($(BITS),64)
		CFLAGS+=-m64
		LDFLAGS=-T$(ARCH_DIR)/32/link.ld -melf_i386
	endif
endif


all: $(SOURCES) link

clean:
	-rm *.o $(ARCH_DIR)/kernel $(ARCH_DIR)/*.o

link:
	ld $(LDFLAGS) -o $(ARCH_DIR)/kernel $(SOURCES)
	
iso_x86:
	mkdir isofiles
	mkdir isofiles/boot/
	mkdir isofiles/boot/grub/
	cp arch/x86/boot/stage2_eltorito isofiles/boot/grub
	cp arch/x86/kernel isofiles/kernel
	cp arch/x86/boot/menu.lst isofiles/boot/grub
	mkisofs -R -b boot/grub/stage2_eltorito -no-emul-boot -boot-load-size 4 -boot-info-table -o arch/x86/image.iso isofiles
	rm -r isofiles

test_x86:
	qemu -cdrom arch/x86/image.iso -boot d -m 20
	
.s.o:
	nasm $(ASFLAGS) $<
