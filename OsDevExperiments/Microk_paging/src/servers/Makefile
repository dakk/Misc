include ../Makefile.conf

CFLAGS=-nostdlib -nostdinc -fno-builtin -I. -Icommon/include
ASFLAGS=-felf       
SERVERS=common/syscall.o
PACK=servers.a

server_init = yes
server_vfs = yes
server_net = yes
server_stat = yes
server_dev = yes

ifeq ($(server_init),yes)
	SERVERS += init/main.o
endif


ifeq ($(server_dev),yes)
	SERVERS += dev/main.o
endif

ifeq ($(server_stat),yes)
	SERVERS += stat/main.o
endif

ifeq ($(server_vfs),yes)
	SERVERS += vfs/main.o vfs/fs.o
endif

ifeq ($(server_net),yes)
	SERVERS += net/main.o
endif



ifeq ($(ARCH),x86)
	ifeq ($(BITS),32)
		CFLAGS+=-m32
		ARFLAGS=elf64-x86-64
	endif
	ifeq ($(BITS),64)
		CFLAGS+=-m64
		ARFLAGS=elf32-i386
	endif
endif


all: $(SERVERS) pack

clean:
	-rm *.o $(SERVERS) $(PACK)

	
pack:
	ar rcs $(PACK) $(SERVERS)
	
