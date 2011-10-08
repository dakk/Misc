ARCH=x86


ifeq ($(ARCH),x86)
	ARCH_DIR=arch/x86
	ARCH_SOURCES=
endif

UI=ui/ui.o 
#ui/window.o ui/widget.o
UI_USER=ui/window.o ui/widget.o ui/widgets/label.o ui/draw.o
NET=network/network.o
AUDIO=
VFS=vfs/vfs.o vfs/tarfs.o
DRV=driver/driver.o driver/keyboard/keyboard.o driver/vesa/vesa.o 

SOURCES=$(ARCH_SOURCES) $(UI) $(AUDIO) $(NET) $(VFS) $(DRV) mutex.o string.o
WRAP=libos_wrapper.o string.o $(UI_USER)
OUTK=klibos.a
OUT=libos.a

CFLAGS=-I. -Wall -Wno-write-strings -nostdlib -nostartfiles -ffreestanding -fno-stack-protector -nostdlib -nostdinc -fno-builtin -nodefaultlibs -fno-exceptions
CXXFLAGS=-lang=c++ -fno-rtti $(CFLAGS)
ASFLAGS=-felf
ASM=nasm
CC=gcc
CPP=g++
AR=ar


all: $(SOURCES) pack

wrapper: $(WRAP) pack_wrap

pack_wrap:
	$(AR) rcs $(OUT) $(WRAP)

pack:
	cp $(SOURCES) obj
	$(AR) rcs $(OUTK) $(SOURCES)

.s.o:
	$(ASM) $(ASFLAGS) $<
.c.o:
	$(CC) $(CFLAGS) -c $< -o $@
.cpp.o:
	$(CPP) $(CXXFLAGS) -c $< -o $@

clean:
	rm $(WRAP) $(SOURCES) $(OUTK) $(OUT)

