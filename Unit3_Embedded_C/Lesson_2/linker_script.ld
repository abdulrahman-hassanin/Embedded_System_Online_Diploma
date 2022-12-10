ENTRY(reset)

MEMORY
{
    Mem (rwx): ORIGIN = 0X00000000, LENGTH = 64M
}

SECTIONS
{
    . = 0X10000;
    
    .startup . :
    {
        startup.o(.text)
    }> Mem

    .text :
    {
        *(.text) *(.rodata)
    }> Mem

    .data :
    {
        *(.data)
    }> Mem

    .bss :
    {
        *(.bss) *(.COMMON)
    }> Mem

    . = . + 0X1000;     /* 4KB of Stack Memory*/
    stack_top = .;
}
