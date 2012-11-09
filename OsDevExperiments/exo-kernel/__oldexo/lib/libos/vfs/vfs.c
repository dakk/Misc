#include <libos.h>
#include "tarfs.h"
#include "vfs.h"
#include "string.h"


mountpoint_t *mountlist = NULL;



mountpoint_t *vfs_get_mountpoint(char *path)
{
	mountpoint_t *tmp = mountlist;
	mountpoint_t *l = mountlist;

	while(l != NULL)
	{
		if(	(_strncmp(l->path, path, _strlen(path)) == 0) &&
			(_strlen(tmp->path) < _strlen(l->path)))
				tmp = l;
		l = l->next;
	}

	return tmp;
}


int vfs_mount(char *dev, char *point, char *fs, char *flags)
{
	/* create the root node */
	struct vfs_node_p *root = NULL;
	
	if(_strcmp(fs, "tarfs") == 0)
		root = tarfs_mount(dev, flags);

	if(root == NULL)
		return 0;

	/* create mp */
	mountpoint_t *mp = (mountpoint_t *) mm_alloc(sizeof(mountpoint_t));
	mp->next = mountlist;
	mp->root = root;
	_strcpy(mp->path, point);
	mountlist = mp;

	return 1;
}


int vfs_umount(char *path)
{
	mountpoint_t *mp = mountlist;
	mountpoint_t *prev = NULL;

	while(mp != NULL)
	{
		if(_strcmp(path, mp->path) == 0)
		{
			mp->root->umount(mp->root);

			if(prev == NULL)
				mountlist = mp->next;
			else
				prev->next = mp->next;
			mm_free(mp);

			return 1;
		}
		prev = mp;
		mp = mp->next;
	}
	return 0;
}





struct vfs_node_p *vfs_open(char *path, char *flags)
{
	mountpoint_t *mp = vfs_get_mountpoint(path);

	if(mp == NULL)
		return (struct vfs_node_p *) NULL;

	path += _strlen(mp->path);

	/* split the restant path, and get nodes */
	char token[VFS_TOKEN_SIZE];
	unsigned tok_len;

	struct vfs_node_p *tmp = mp->root;
	struct readdir_t rd;
	unsigned i;

	while(tmp != NULL)
	{
		/* get the token */
		tok_len = 0;
		while((*path != '/') && (*path != 0))
		{
			token[tok_len] = *path;
			path++;
			tok_len++;
		}
		token[tok_len] = 0;


		/* read the dir and find the correct token */
		struct vfs_node_p *tmp2 = NULL;
		i = 0;

		while((tmp2 == NULL) && (tmp->readdir(tmp, &rd, i)))
		{
			if(_strcmp(tmp->name, token) == 0)
			{
				/* get the correct node */
				tmp2 = tmp->get_node(tmp, i);
				if(tmp != mp->root)
					mm_free(tmp);
				tmp = tmp2;

				if(*(path-1) == 0)
					return tmp;
			}
			i++;
		}
	}
	return (struct vfs_node_p *) NULL;
}






uint32_t vfs_read(struct vfs_node_p *fp, char *buf, uint32_t size, uint64_t offset)
{
	if(fp->read != NULL)
		return fp->read(fp, buf, size, offset);
	return 0;
}


uint32_t vfs_write(struct vfs_node_p *fp, char *buf, uint32_t size, uint64_t offset)
{
	if(fp->write != NULL)
		return fp->write(fp, buf, size, offset);
	return 0;
}


void vfs_close(struct vfs_node_p *fp)
{
	mm_free(fp);
}


int vfs_readdir(struct vfs_node_p *fp, struct readdir_t *rd, unsigned i)
{
	if(fp->readdir != NULL)
		return fp->readdir(fp, rd, i);
	return 0;
}


int vfs_remove(struct vfs_node_p *fp)
{
	if(fp->remove != NULL)
		return fp->remove(fp);
	return 0;
}

