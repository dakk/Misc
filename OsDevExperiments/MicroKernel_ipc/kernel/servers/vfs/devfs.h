#ifndef DEVFS_H
#define DEVFS_H

#include "vfs.h"


uint32_t			devfs_read(struct vfs_node_p *node, char *buf, uint32_t size, uint64_t offset);
int					devfs_readdir(struct vfs_node_p *node, struct readdir_t *rd, unsigned i);
struct vfs_node_p *	devfs_get_node(struct vfs_node_p *node, uint32_t inode_n);
struct vfs_node_p *	devfs_mount(char *dev, char *flags);
int					devfs_umount(struct vfs_node_p *root);


void				devfs_makedev();


#endif
