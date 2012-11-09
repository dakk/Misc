SERVERS=servers/common/string.o
server_init = yes
server_vfs = yes
server_net = yes
server_stat = yes
server_dev = yes

ifeq ($(server_init),yes)
	SERVERS += servers/init/main.o
endif


ifeq ($(server_dev),yes)
	SERVERS += servers/dev/main.o
endif

ifeq ($(server_stat),yes)
	SERVERS += servers/stat/main.o
endif

ifeq ($(server_vfs),yes)
	SERVERS += servers/vfs/tarfs.o servers/vfs/vfs.o servers/vfs/main.o
	SERVERS += servers/vfs/devfs.o
endif

ifeq ($(server_net),yes)
	SERVERS += servers/net/main.o
endif



