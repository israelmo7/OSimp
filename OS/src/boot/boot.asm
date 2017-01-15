;Runs in RealMode
global loader
 
extern kmain

MODULEALIGN equ  1<<0
MEMINFO     equ  1<<1
FLAGS       equ  MODULEALIGN | MEMINFO
MAGIC       equ    0x1BADB002 ; tell the sector is bootable
CHECKSUM    equ -(MAGIC + FLAGS)
 
section .text
 
align 4
    dd MAGIC
    dd FLAGS
    dd CHECKSUM

STACKSIZE equ 0x4000  ;size in bytes
 
loader:
	mov  esp, k_stack + STACKSIZE
	push eax
	push ebx
	
	call kmain
	
	cli
	.hang:
    		hlt
    		jmp  .hang

section .bss
 
align 4
k_stack:
    resb STACKSIZE ;set kernel stack
