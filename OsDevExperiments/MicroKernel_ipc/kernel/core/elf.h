#ifndef ELF_H
#define ELF_H

#include <types.h>

#define ELF_NIDENT			16
#define ELF_ID_MAG0			0
#define ELF_ID_MAG1			1
#define ELF_ID_MAG2			2
#define ELF_ID_MAG3			3
#define ELF_ID_CLASS		4
#define ELF_ID_DATA			5
#define ELF_ID_VERSION		6
#define ELF_ID_PAD			7
#define ELF_ID_NIDENT		16

#define ELF_TYPE_NONE		0
#define ELF_TYPE_REL		1
#define ELF_TYPE_EXEC		2
#define ELF_TYPE_DYN		3
#define ELF_TYPE_CORE		4
#define ELF_TYPE_LOPROC		0xFF00
#define ELF_TYPE_HIPROC		0xFFFF


typedef enum { MAC_NONE = 0, MAC_M32, MAC_SPARC, MAC_386, MAC_68K, MAC_88K, MAC_860	= 7, MAC_MIPS } elf_machine_t;


#define ELF_VER_NONE		0
#define ELF_VER_CURRENT		1


typedef enum { ELF_CLASS_NONE = 0, ELF_CLASS_32, ELF_CLASS_64 } elf_class_t;


#define ELF_DATA_NONE			0
#define ELF_DATA_2LSB			1
#define ELF_DATA_2MSB			2



#define ELF_PTYPE_NULL 0             /* Unused */
#define ELF_PTYPE_LOAD 1             /* Loadable segment (fileSize bytes) */
#define ELF_PTYPE_DYNAMIC 2          /* Dynamic segment */
#define ELF_PTYPE_INTERP 3           /* Size and location of null-ended path to interpreter */
#define ELF_PTYPE_NOTE 4             /* Note segment */
#define ELF_PTYPE_SHLIB 5            /* Reserved */
#define ELF_PTYPE_PHDR 6             /* Size and location of program header */
#define ELF_PTYPE_HIPROC 0x7fffffff  /* Reserved */
#define ELF_PTYPE_LOPROC 0x70000000  /* Reserved */


/** Elf header */
typedef struct
{
	char ident[ELF_NIDENT];

	uint16_t type;
	uint16_t machine;
	uint32_t version;
	uint32_t entry;
	uint32_t phoff;
	uint32_t shoff;
	uint32_t flags;
	uint16_t size;
	uint16_t phsize;
	uint16_t phnum;
	uint16_t shsize;
	uint16_t shnum;
	uint16_t strndx;
} elf_header_t;


typedef struct
{
	uint32_t offset;
	uint32_t info;
} elf32_reloc_t;

typedef struct
{
	elf32_reloc_t reloc;
	uint32_t addend;
} elf32_reloc_a_t;

/** Section elf header (check size) */
typedef struct
{
	uint32_t name;
	uint32_t type;
	uint32_t flags;
	uint32_t addr;
	uint32_t offset;
	uint32_t size;
	uint32_t link;
	uint32_t info;
	uint32_t align;
	uint32_t entsize;
} elf_section_header_t;


typedef struct 
{
	uint32_t name;
	uint32_t address;
	uint32_t size;
	uint8_t  info;
	uint8_t  other;
	uint16_t shndx;
} elf_symbtab_entry_t;


unsigned elf_check(void *data);
unsigned elf_get_class(void *data);
void *elf_get_entry32(void *data);
void elf_relocate32(void *data);


#endif
