#include "devfs.h"



typedef struct
{
	char name[100];
	char file_mode[8];
	char owner[8];
	char group[8];
	char type;
} devfs_file_header_t;

typedef enum
{
	DFT_CHAR, DFT_BLOCK
} devfs_file_type_t;





uint32_t devfs_read(struct vfs_node_p *node, char *buf, uint32_t size, uint64_t offset)
{
	return 0;
}



int devfs_readdir(struct vfs_node_p *node, struct readdir_t *rd, unsigned i)
{
	return 0;
}


struct vfs_node_p *devfs_get_node(struct vfs_node_p *node, uint32_t inode_n)
{
	return NULL;
}


int devfs_umount(struct vfs_node_p *root)
{
	return 0;
}






struct vfs_node_p *devfs_mount(char *dev, char *flags)
{
	struct vfs_node_p *root = (struct vfs_node_p *) mm_alloc(sizeof(struct vfs_node_p));

	root->name[0] = '/';
	root->name[1] = 0;

	root->remove = NULL;
	root->get_node = devfs_get_node;
	root->readdir = devfs_readdir;
	root->write = NULL;
	root->read = devfs_read;
	root->umount = devfs_umount;
	
	return root;
}

