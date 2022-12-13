/*
 *  linker script cortex-M3
 */

MEMORY
{
    flash(RX) : ORIGIN = 0x08000000, LENGTH = 128k
    sram(RWX) : ORIGIN = 0x20000000, LENGTH = 10k
}

SECTIONS
{
    .text : {
        *(.Vectors*)
        *(.text*)
        *(.rodata*)
    }> flash

    .data : {
        *(.data*)
    }> flash

    .bss : {
        *(.bss*)
    }> sram
}