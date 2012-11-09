#include "fs.h"

fs_node_t *root_node = NULL;

void vfs_init()
{
	root_node = (fs_node_t *) malloc(sizeof(fs_node_t));
	root_node->type = NT_DIR;
	root_node->uid = 0;
	root_node->gid = 0;
	root_node->close = NULL;
	root_node->open = NULL;
	root_node->read = NULL;
	root_node->write = NULL;
	root_node->readdir = NULL;
	root_node->getnode = NULL;
}


fs_node_t* vfs_getroot()
{
	return root_node;
}


uint32_t vfs_readdir(fs_node_t *node, dirent_t *d, uint64_t index)
{
	
}


fs_node_t* vfs_getnode(fs_node_t *node, dirent_t *d)
{
	
}


uint32_t vfs_close(fs_node_t *node)
{
	
}



uint32_t vfs_open(fs_node_t *node, uint8_t mode)
{
	
}


uint32_t vfs_write(fs_node_t *node, uint64_t offset, uint32_t size,uint8_t *data)
{
	
}


uint32_t vfs_read(fs_node_t *node, uint64_t offset, uint32_t size,uint8_t *data)
{
	
}
