OUTPUT_FORMAT(elf64-x86-64)
ENTRY(kmain)

SECTIONS
{
  /* Start the kernel at virtual address 0x100000 (1MB) */
  . = 0x100000;

  .text : {
    *(.text)       /* All code */
  }

  .rodata : {
    *(.rodata)     /* Read-only data */
  }

  .data : {
    *(.data)       /* Initialized data */
  }

  .bss : {
    *(.bss)        /* Uninitialized data */
    *(COMMON)
  }
}
