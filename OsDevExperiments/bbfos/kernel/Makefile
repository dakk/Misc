KERNEL		= 	kernel.bin
AS			=	as 
ASFLAGS		=	-march=generic32 --32
CC			=	gcc
CFLAGS		=	-m32 -std=gnu99 -ffreestanding -O2 -Wall -Wextra -I.
LD			=	gcc 
LDFLAGS		=	-m32 -ffreestanding -O2 -nostdlib -lgcc 

ARCH		= x86
ARCH_OBJS	= arch/$(ARCH)/boot.o arch/$(ARCH)/io.o arch/$(ARCH)/dt.o arch/$(ARCH)/serial.o arch/$(ARCH)/arch.o 
KERNEL_OBJS	= kernel.o
OBJS 		= $(ARCH_OBJS) $(KERNEL_OBJS)

all: $(OBJS)
	$(LD) $(LDFLAGS) -T linker.ld $(OBJS) -o $(KERNEL)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

%.o: %.s
	$(AS) $(ASFLAGS) -o $@ $<

clean:
	rm $(OBJS) $(KERNEL)