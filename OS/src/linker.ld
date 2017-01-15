/*            Original file taken partly from Bran's Kernel Development */

ENTRY(loader) /* entery point */
SECTIONS
{

    . =  0x100000;
    __start = .;

    .text :
    {
        /*code = .; _code = .; __code = .;*/
        *(.text)
        . = ALIGN(0x1000);
    }

    .data :
    {
       /* data = .; _data = .; __data = .;*/
        *(.data)
        *(.rodata) /*ReadOnly*/
        . = ALIGN(0x1000);
    }

    .bss :
    {
       /* bss = .; _bss = .; __bss = .;*/
        *(.bss)
        . = ALIGN(0x1000);
    }

    __end = .;
}
