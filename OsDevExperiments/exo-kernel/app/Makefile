CFLAGS=-I../lib/libos -Wall -Wno-write-strings -nostdlib -nostartfiles -ffreestanding -fno-stack-protector -nostdlib -nostdinc -fno-builtin -nodefaultlibs -fno-exceptions
CXXFLAGS=-lang=c++ -fno-rtti $(CFLAGS)
ASFLAGS=-felf
ASM=nasm
CC=gcc
CPP=g++
AR=ar

TEXTEDITOR=
UI=ui/ui.o
SOURCES=init.o bootsplash.o $(UI) $(TEXTEDITOR)


all: $(SOURCES) pack
	
.s.o:
	$(ASM) $(ASFLAGS) $<
.c.o:
	$(CC) $(CFLAGS) -c $< -o $@
.cpp.o:
	$(CPP) $(CXXFLAGS) -c $< -o $@
pack:
	cp $(SOURCES) obj
	$(AR) rcs apps.a $(SOURCES)


clean:
	rm $(SOURCES) apps.a
