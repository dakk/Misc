CFLAGS=-I../../lib/libos -Wall -Wno-write-strings -nostdlib -nostartfiles -ffreestanding -fno-stack-protector -nostdlib -nostdinc -fno-builtin -nodefaultlibs -fno-exceptions
CXXFLAGS=-lang=c++ -fno-rtti $(CFLAGS)
ASFLAGS=-felf
ASM=nasm
LDFLAGS=-T ../link.ld -q
#-Ttext=0
#binary 
#coff 
CC=gcc
CPP=g++
AR=ar


all: $(SOURCES) link

link:
	$(LD) $(LDFLAGS) -o $(BINARY) $(SOURCES) $(LIBS) ../../lib/libos/libos.a
	
.s.o:
	$(ASM) $(ASFLAGS) $<
.c.o:
	$(CC) $(CFLAGS) -c $< -o $@
.cpp.o:
	$(CPP) $(CXXFLAGS) -c $< -o $@

clean:
	rm $(SOURCES) $(BINARY)
