CC:=gcc
CFLAGS:=-m32 -c -Wall
LD:=ld
LDFLAGS:=-melf_i386 -T linker.ld -o kernel.bin
ASM:=nasm
ASMFLAGS:=-f elf

all: kernel.o boot.o
	$(LD) $(LDFLAGS) kernel.o boot.o screen.o gdt.o descriptors.o string.o idt.o isr.o irq.o isr_wrapper.o communication.o memory_m.o paging.o keyboard.o math.o

kernel.o: screen.o descriptors.o communication.o memory_m.o
	$(CC) $(CFLAGS) kernel/kernel.c

boot.o: kernel.o
	$(ASM) $(ASMFLAGS) -o boot.o boot/boot.asm

memory_m.o: paging.o
	$(CC) $(CFLAGS) kernel/memory_m.c

gdt.o:
	$(ASM) $(ASMFLAGS) -o gdt.o kernel/gdt.asm

paging.o:
	$(ASM) $(ASMFLAGS) -o paging.o kernel/paging.asm	
	
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
