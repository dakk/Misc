all:
	make -C kernel
	make -C mlkernel
	qemu-system-i386 -kernel kernel/kernel.bin

clean:
	make -C kernel clean

run:
	qemu-system-i386 -kernel kernel/kernel.bin