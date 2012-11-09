#ifndef FS_H
#define FS_H

#include <types.h>

#define NODE_NAME_MAX		128

typedef enum
{
	NT_FILE,
	NT_DIR,
	NT_LINK
} node_type_t;

typedef struct dirent
{
	char		name[NODE_NAME_MAX];
	uint64_t	inode_n;
} dirent_t;

typedef struct fs_node
{
	uint32_t (*readdir)(struct fs_node *node, dirent_t *d, uint64_t index);
	struct fs_node *(*getnode)(struct fs_node *node, dirent_t *d);

	uint32_t (*close)(struct fs_node *node);
	uint32_t (*open)(struct fs_node *node, uint8_t mode);
	uint32_t (*write)(struct fs_node *node, uint64_t offset, uint32_t size,uint8_t *data);
	uint32_t (*read)(struct fs_node *node, uint64_t offset, uint32_t size,uint8_t *data);
	
	node_type_t type;
	uint64_t	size;
	
	gid_t		gid;
	uid_t		uid;
	uint32_t	perm;
} fs_node_t;


void			vfs_init();

fs_node_t*		vfs_getroot();
uint32_t 		vfs_readdir(fs_node_t *node, dirent_t *d, uint64_t index);
fs_node_t*		vfs_getnode(fs_node_t *node, dirent_t *d);

uint32_t		vfs_close(fs_node_t *node);
uint32_t		vfs_open(fs_node_t *node, uint8_t mode);
uint32_t		vfs_write(fs_node_t *node, uint64_t offset, uint32_t size,uint8_t *data);
uint32_t		vfs_read(fs_node_t *node, uint64_t offset, uint32_t size,uint8_t *data);

uint32_t		vfs_mount(char *fs, uint32_t dev);

#endif
