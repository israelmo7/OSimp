CC:=gcc
CFLAGS:=-m32 -c -Wall
LD:=ld
LDFLAGS:=-melf_i386 -T linker.ld -o kernel.bin
ASM:=nasm
ASMFLAGS:=-f elf

all: kernel.o boot.o
	$(LD) $(LDFLAGS) kernel.o boot.o screen.o gdt.o descriptors.o string.o idt.o isr.o irq.o isr_wrapper.o communication.o heap.o paging.o paging_lib.o keyboard.o math.o

kernel.o: screen.o descriptors.o communication.o heap.o
	$(CC) $(CFLAGS) kernel/kernel.c

boot.o: kernel.o
	$(ASM) $(ASMFLAGS) -o boot.o boot/boot.asm

heap.o: paging.o
	$(CC) $(CFLAGS) kernel/heap.c

gdt.o:
	$(ASM) $(ASMFLAGS) -o gdt.o kernel/gdt.asm

paging.o: paging_lib.o
	$(CC) $(CFLAGS) kernel/paging.c

paging_lib.o:
	$(ASM) $(ASMFLAGS) -o paging_lib.o kernel/paging_lib.asm	
	
isr.o: irq.o keyboard.o
	$(CC) $(CFLAGS) kernel/isr.c

keyboard.o:
	$(CC) $(CFLAGS) kernel/keyboard.c

irq.o:
	$(CC) $(CFLAGS) kernel/irq.c
	
isr_wrapper.o: 
	$(ASM) $(ASMFLAGS) -o isr_wrapper.o kernel/isr_wrapper.asm

communication.o:
	$(CC) $(CFLAGS) kernel/libs/communication.c

descriptors.o: gdt.o idt.o
	$(CC) $(CFLAGS) kernel/descriptors.c

idt.o: isr.o isr_wrapper.o
	$(ASM) $(ASMFLAGS) -o idt.o kernel/idt.asm

screen.o: string.o
	$(CC) $(CFLAGS) kernel/screen.c

string.o: math.o
	$(CC) $(CFLAGS) kernel/libs/string.c

math.o:
	$(CC) $(CFLAGS) kernel/libs/math.c

clean:
	$(shell rm -rf *.o kernel.bin)
