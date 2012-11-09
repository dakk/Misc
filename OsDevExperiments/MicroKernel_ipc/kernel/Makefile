include Makefile.conf


all: $(SOURCES)	link
	
iso:
	mkdir isofiles
	mkdir isofiles/boot/
	mkdir isofiles/boot/grub/
	cp arch/x86/boot/stage2_eltorito isofiles/boot/grub
	cp arch/x86/kernel isofiles/kernel
	cp arch/x86/boot/menu.lst isofiles/boot/grub
	mkisofs -R -b boot/grub/stage2_eltorito -no-emul-boot -boot-load-size 4 -boot-info-table -o arch/x86/image.iso isofiles
	rm -r isofiles
test:
	qemu -cdrom arch/x86/image.iso -boot d -m 24


.s.o:
	$(ASM) $(ASFLAGS) $<
.c.o:
	$(CC) $(CFLAGS) -c $< -o $@
.cpp.o:
	$(CPP) $(CXXFLAGS) -c $< -o $@
link:
	$(LD) $(LDFLAGS) -o $(BIN) $(SOURCES)

clean:
	rm $(SOURCES)

