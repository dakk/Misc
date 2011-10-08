#ifndef TARFS_H
#define TARFS_H

#include <libos.h>
#include "vfs.h"



uint32_t tarfs_read(struct vfs_node_p *node, char *buf, uint32_t size, uint64_t offset);
int tarfs_readdir(struct vfs_node_p *node, struct readdir_t *rd, unsigned i);
struct vfs_node_p *tarfs_get_node(struct vfs_node_p *node, uint32_t inode_n);
struct vfs_node_p *tarfs_mount(char *dev, char *flags);
int tarfs_umount(struct vfs_node_p *root);


#endif
