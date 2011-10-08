#include "tarfs.h"



typedef struct
{
	char name[100];
	char file_mode[8];
	char owner[8];
	char group[8];
	char size[12];
	char last_modification[12];
	char checksum[8];
	char type;
	char name_of_linked[100];
} tarfs_file_header_t;

typedef enum
{
	TARFT_NORMAL = '0', TARFT_HARD_LINK, TARFT_SYMBOLIC_LINK, TARFT_CHAR_SPECIAL,
	TARFT_BLOCK_SPECIAL, TARFT_DIRECTORY, TARFT_FIFO, TARFT_CONTIGUOUS
} tarfs_file_type_t;



uint64_t tarfs_get_value(char *field, unsigned size)
{
	uint64_t sum = 0;
	unsigned i;

	for(i = 0; (i < size) && (field[i] != 0); i++)
	{
		sum *= 8;
		sum += field[i] - '0';
	}

	return sum;
}




uint32_t tarfs_read(struct vfs_node_p *node, char *buf, uint32_t size, uint64_t offset)
{
	return 0;
}



int tarfs_readdir(struct vfs_node_p *node, struct readdir_t *rd, unsigned i)
{
	return 0;
}


struct vfs_node_p *tarfs_get_node(struct vfs_node_p *node, uint32_t inode_n)
{
	return NULL;
}


int tarfs_umount(struct vfs_node_p *root)
{
	return 0;
}





struct vfs_node_p *tarfs_mount(char *dev, char *flags)
{
	struct vfs_node_p *root = (struct vfs_node_p *) mm_alloc(sizeof(struct vfs_node_p));

	root->name[0] = '/';
	root->name[1] = 0;

	root->remove = NULL;
	root->get_node = tarfs_get_node;
	root->readdir = tarfs_readdir;
	root->write = NULL;
	root->read = tarfs_read;
	root->umount = tarfs_umount;
	
	return root;
}

