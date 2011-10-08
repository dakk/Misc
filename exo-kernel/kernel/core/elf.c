#include "elf.h"
#include <core/stdio.h>


/** Return the entry point of the elf file */
void *elf_get_entry32(void *data)
{
	elf_header_t *header = (elf_header_t *) data;
	return (void *) data + header->phoff;
}


/** Relocate all sections of an elf in memory */
void elf_relocate32(void *data)
{
	unsigned i;
	elf_header_t *header = (elf_header_t *) data;
	elf_section_header_t *prog_h;

	/* modify the relocation table and add the address of
	 * data as an offset for each address */

#if 0
	for(i = 0; i < header->shnum; i++)
	{
		prog_h = (elf_section_header_t *) ((unsigned long) header + header->shoff + i * header->shsize);

		kprintf("section - ");

		/*if(prog_h->type == 2)
		{*/
			elf_symbtab_entry_t *symtab = (elf_symbtab_entry_t *)(data + prog_h->offset);

			kprintf("%s\n", symtab->name);
	
			/*sh = (struct ELF_section_header_s*)(buf + eh->shoff + (sh->link * eh->shsize));
	
			if(sh->type == 3)
			{
				if(!index){return (char*)" ";}
				return (char *)(buf + sh->offset + index);
			}*/
		//}
	}
#endif
#if 0
		switch(prog_h->type)
		{
			case ELF_PTYPE_LOAD:
				kprintf("load\n");
				break;
		/*
        	case PT_LOAD:
				virtual_map_pages(pHeader->vaddr, pHeader->fileSize, 1, 1);
              
				memcpy((char*)pHeader->vaddr,(char*)offset+pHeader->offset, pHeader->fileSize);
				if(pHeader->fileSize < pHeader->memSize)
					memset((char *)pHeader->vaddr+pHeader->fileSize, 0, pHeader->memSize-pHeader->fileSize);
          break;
          */
			case ELF_PTYPE_NULL:
				kprintf("null\n");
				break;

			case ELF_PTYPE_DYNAMIC:
				kprintf("dynamic\n");
				break;

			case ELF_PTYPE_INTERP:
		  		kprintf("reloc\n");
				memcpy((char *) interp, (char *) header + prog_h->offset, prog_h->size);
				break;

			default:
				break;
				kprintf("%d\n", prog_h->type);
		};
#endif

}


unsigned elf_get_class(void *data)
{
	//elf_header_t *header = (elf_header_t *) data;
	return (unsigned) ELF_CLASS_32; 
}


/** Check if the passed data is an elf file */
unsigned elf_check(void *data)
{
	elf_header_t *header = (elf_header_t *) data;

	if( ((header->ident[1]) == 'E') &&
		((header->ident[2]) == 'L') &&
		((header->ident[3]) == 'F') &&
		((header->ident[0]) == 0x7f))
		return 1;
	
	return 0;		
}

