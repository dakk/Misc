#include <ipc.h>
#include "fs.h"
#include "proto.h"

int vfs_main()
{
	msg_t m;
	proto_t *p;
	proto_reply_t r;
	
	while(1)
	{
		if(!msg_recv(&m))
			continue;
			
		if(m.size != PROTO_SIZE)
			continue;
			
		p = (proto_t *) m.data;
		
		if(p->call > VFS_UMOUNT)
			continue;
		
		
		switch(p->call)
		{
			VFS_OPEN:
				r.reply = (uint32_t) vfs_open((fs_node_t *) p->arg1, (uint8_t) p->arg2);
				break;
				
			VFS_CLOSE:
				r.reply = (uint32_t) vfs_close((fs_node_t *) p->arg1);
				break;
				
			VFS_READ:
				r.reply = (uint32_t) vfs_read((fs_node_t *) p->arg1, (uint64_t) p->arg2, (uint32_t) p->arg3, (uint8_t *) p->arg4);
				break;
				
			VFS_WRITE:
				r.reply = (uint32_t) vfs_write((fs_node_t *) p->arg1, (uint64_t) p->arg2, (uint32_t) p->arg3, (uint8_t *) p->arg4);
				break;
				
			VFS_READDIR:
				r.reply = (uint32_t) vfs_readdir((fs_node_t *) p->arg1, (dirent_t *) p->arg2, (uint64_t) p->arg3);
				break;
				
			VFS_GETNODE:
				r.reply = (uint32_t) vfs_getnode((fs_node_t *) p->arg1, (dirent_t *) p->arg2);
				break;
				
			VFS_GETROOT:
				r.reply = (uint32_t) vfs_getroot();
				break;
				
			VFS_MOUNT:
			VFS_UMOUNT:	
				break;
		}
		
		memcpy(m.data, r);
		m.size = sizeof(r);
		m.to = m.from;
		
		msg_send(&m);
	}
}



