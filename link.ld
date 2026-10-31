ENTRY(_start)
SECTIONS
{
  . = 0x0;
  .text : { *(.text*) }
  . = 0x10000000;
  .data : { *(.data*) }
  .rodata : { *(.rodata*) }
  .bss : { *(.bss*) *(COMMON) }
}
