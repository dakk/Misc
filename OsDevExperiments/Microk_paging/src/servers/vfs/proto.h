#ifndef VFS_PROTO_H
#define VFS_PROTO_H

#include <proto.h>

typedef enum
{
	VFS_OPEN = 0,
	VFS_CLOSE,
	VFS_READDIR,
	VFS_READ,
	VFS_WRITE,
	VFS_GETNODE,
	VFS_GETROOT,
	VFS_MOUNT,
	VFS_UMOUNT
} vfs_call_t;


#endif
