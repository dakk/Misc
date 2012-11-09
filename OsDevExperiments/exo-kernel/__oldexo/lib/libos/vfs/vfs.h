#ifndef VFS_H
#define VFS_H

#include <types.h>

/** \defgroup vfs VirtualFileSystem */

/** \addtogroup vfs
 * @{
 */

/** Types of node */
typedef enum { NT_DIR, NT_FILE, NT_LINK } vfs_node_type_t;


#define VFS_TOKEN_SIZE	128		///< Max size of a token


/** Readdir structure */
struct readdir_t
{
	char name[VFS_TOKEN_SIZE];		///< Name of the node
	uint32_t inode_n;				///< Number of the node
	vfs_node_type_t type;			///< Type of the node
};


/** Structure of a node */
typedef struct vfs_node_p
{
	char name[VFS_TOKEN_SIZE];	///< Name of the node
	
	uid_t uid;					///< User id
	gid_t gid;					///< Group id
	pid_t pid;

	vfs_node_type_t type;		///< Type of node
	struct device_p *dev;		///< Device of the node

	uint32_t (*read)(struct vfs_node_p *node, char *buf, uint32_t size, uint64_t offset);
	uint32_t (*write)(struct vfs_node_p *node, char *buf, uint32_t size, uint64_t offset);
	int (*readdir)(struct vfs_node_p *node, struct readdir_t *rd, unsigned i);
	struct vfs_node_p *(*get_node)(struct vfs_node_p *node, uint32_t inode_n);
	int (*remove)(struct vfs_node_p *node);

	int (*umount)(struct vfs_node_p *root);
} vfs_node_t;


/** Structure of a mounted filesystem */
typedef struct mountpoint_p
{
	struct device_p *dev;		///< Pointer to the device
	vfs_node_t *root;			///< Root node

	char path[1024];			///< Mount path

	struct mountpoint_p *next;	///< Next mountpoint
} mountpoint_t;


/** Return the mountpoint from a path */
mountpoint_t *vfs_get_mountpoint(char *path);

/** 
 * Mount a filesystem from a device in a mountpoint 
 *
 * \param dev name of the device
 * \param point mountpoint path
 * \param fs filesystem name
 * \param flags mount flags 
 */
int vfs_mount(char *dev, char *point, char *fs, char *flags);

/** 
 * Umount a filesystem 
 * 
 * \param path mountpoint path 
 */
int vfs_umount(char *path);


/**
 * Open a node from a path
 */
struct vfs_node_p *vfs_open(char *path, char *flags);


/**
 * Read a buffer from a node
 *
 * \param fp node
 * \param buf buffer pointer
 * \param size bytes to read
 * \param offset offset for the reading
 *
 * \return read bytes
 */
uint32_t vfs_read(struct vfs_node_p *fp, char *buf, uint32_t size, uint64_t offset);


/**
 * Write a buffer in a node
 *
 * \param fp node
 * \param buf buffer pointer
 * \param size bytes to write
 * \param offset offset for the writing
 *
 * \return written bytes
 */
uint32_t vfs_write(struct vfs_node_p *fp, char *buf, uint32_t size, uint64_t offset);

/**
 * Close an opened node
 *
 * \param node
 */
void vfs_close(struct vfs_node_p *fp);


/**
 * Read an element from a directory node 
 *
 * \param node
 * \param rd readdir structure pointer for the readed element
 * \param i iterator for the reading
 */
int vfs_readdir(struct vfs_node_p *node, struct readdir_t *rd, unsigned i);


/**
 * Remove a node from the fs
 */
int vfs_remove(struct vfs_node_p *node);

/** @} */

#endif
