/*ENTRY(main)
OUTPUT_FORMAT(elf32-i386)
phys = 0x00100000;
SECTIONS
{
  .text phys : AT(phys)
  {
    code = .; _code = .; __code = .;
    *(.text)
    . = ALIGN(4096);
  }

  .data : AT(phys + (data - code))
  {
     data = .; _data = .; __data = .;
     *(.data)
     *(.rodata)
     . = ALIGN(4096);
  }

  .bss : AT(phys + (bss - code))
  {
    bss = .; _bss = .; __bss = .;
    *(.bss)
    . = ALIGN(4096);
  }

  end = .; _end = .; __end = .;
}*/
OUTPUT_ARCH("i386")
ENTRY(main)

SECTIONS {
  .text 0x100000 :{
  	_text = .;
  	*(.text);
  	_etext = .;
  }
  .data ALIGN(0x1000):{
  	_data = .;
  	*(.data);
  	_edata = .;
  }
  .bss ALIGN(0x1000):{
  	_bss = .;
  	*(COMMON);
  	*(.bss);
  	_ebss = .;
  	_end = .;
  }
}
/*
SECTIONS{
    . = 0x10000000;

    .text : {
        *(.text)
    }

    .rodata ALIGN (0x1000)  :{
        *(.rodata)
    }

    .data ALIGN (0x1000) : {
		start_ctors = .;
		*(.ctor*)
		end_ctors = .;
		start_dtors = .;
		*(.dtor*)
		end_dtors = .;
        *(.data)
    }

    .bss : {
        sbss = .;
        *(COMMON)
        *(.bss)
        ebss = .;
    }

	end = .; _end = .; __end = .;
}*/

