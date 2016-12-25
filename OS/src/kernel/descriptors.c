#include "descriptors.h"

//asm's Functions 
extern void gdt_write(unsigned int);
extern void idt_write(unsigned int);

extern void isr0();
extern void isr1();
extern void isr2();
extern void isr3();
extern void isr4();
extern void isr5();
extern void isr6();
extern void isr7();
extern void isr8();
extern void isr9();
extern void isr10();
extern void isr11();
extern void isr12();
extern void isr13();
extern void isr14();
extern void isr15();
extern void isr16();
extern void isr17();
extern void isr18();
extern void isr19();
extern void isr20();
extern void isr21();
extern void isr22();
extern void isr23();
extern void isr24();
extern void isr25();
extern void isr26();
extern void isr27();
extern void isr28();
extern void isr29();
extern void isr30();
extern void isr31();
extern void irq0(); // IRQ START HERE
extern void irq1();
extern void irq2();
extern void irq3();
extern void irq4();
extern void irq5();
extern void irq6();
extern void irq7();
extern void irq8();
extern void irq9();
extern void irq10();
extern void irq11();
extern void irq12();
extern void irq13();
extern void irq14();
extern void irq15();
extern void isr48();
extern void isr49();
extern void isr50();
extern void isr51();
extern void isr52();
extern void isr53();
extern void isr54();
extern void isr55();
extern void isr56();
extern void isr57();
extern void isr58();
extern void isr59();
extern void isr60();
extern void isr61();
extern void isr62();
extern void isr63();
extern void isr64();
extern void isr65();
extern void isr66();
extern void isr67();
extern void isr68();
extern void isr69();
extern void isr70();
extern void isr71();
extern void isr72();
extern void isr73();
extern void isr74();
extern void isr75();
extern void isr76();
extern void isr77();
extern void isr78();
extern void isr79();
extern void isr80();
extern void isr81();
extern void isr82();
extern void isr83();
extern void isr84();
extern void isr85();
extern void isr86();
extern void isr87();
extern void isr88();
extern void isr89();
extern void isr90();
extern void isr91();
extern void isr92();
extern void isr93();
extern void isr94();
extern void isr95();
extern void isr96();
extern void isr97();
extern void isr98();
extern void isr99();
extern void isr100();
extern void isr101();
extern void isr102();
extern void isr103();
extern void isr104();
extern void isr105();
extern void isr106();
extern void isr107();
extern void isr108();
extern void isr109();
extern void isr110();
extern void isr111();
extern void isr112();
extern void isr113();
extern void isr114();
extern void isr115();
extern void isr116();
extern void isr117();
extern void isr118();
extern void isr119();
extern void isr120();
extern void isr121();
extern void isr122();
extern void isr123();
extern void isr124();
extern void isr125();
extern void isr126();
extern void isr127();
extern void isr128();
extern void isr129();
extern void isr130();
extern void isr131();
extern void isr132();
extern void isr133();
extern void isr134();
extern void isr135();
extern void isr136();
extern void isr137();
extern void isr138();
extern void isr139();
extern void isr140();
extern void isr141();
extern void isr142();
extern void isr143();
extern void isr144();
extern void isr145();
extern void isr146();
extern void isr147();
extern void isr148();
extern void isr149();
extern void isr150();
extern void isr151();
extern void isr152();
extern void isr153();
extern void isr154();
extern void isr155();
extern void isr156();
extern void isr157();
extern void isr158();
extern void isr159();
extern void isr160();
extern void isr161();
extern void isr162();
extern void isr163();
extern void isr164();
extern void isr165();
extern void isr166();
extern void isr167();
extern void isr168();
extern void isr169();
extern void isr170();
extern void isr171();
extern void isr172();
extern void isr173();
extern void isr174();
extern void isr175();
extern void isr176();
extern void isr177();
extern void isr178();
extern void isr179();
extern void isr180();
extern void isr181();
extern void isr182();
extern void isr183();
extern void isr184();
extern void isr185();
extern void isr186();
extern void isr187();
extern void isr188();
extern void isr189();
extern void isr190();
extern void isr191();
extern void isr192();
extern void isr193();
extern void isr194();
extern void isr195();
extern void isr196();
extern void isr197();
extern void isr198();
extern void isr199();
extern void isr200();
extern void isr201();
extern void isr202();
extern void isr203();
extern void isr204();
extern void isr205();
extern void isr206();
extern void isr207();
extern void isr208();
extern void isr209();
extern void isr210();
extern void isr211();
extern void isr212();
extern void isr213();
extern void isr214();
extern void isr215();
extern void isr216();
extern void isr217();
extern void isr218();
extern void isr219();
extern void isr220();
extern void isr221();
extern void isr222();
extern void isr223();
extern void isr224();
extern void isr225();
extern void isr226();
extern void isr227();
extern void isr228();
extern void isr229();
extern void isr230();
extern void isr231();
extern void isr232();
extern void isr233();
extern void isr234();
extern void isr235();
extern void isr236();
extern void isr237();
extern void isr238();
extern void isr239();
extern void isr240();
extern void isr241();
extern void isr242();
extern void isr243();
extern void isr244();
extern void isr245();
extern void isr246();
extern void isr247();
extern void isr248();
extern void isr249();
extern void isr250();
extern void isr251();
extern void isr252();
extern void isr253();
extern void isr254();
extern void isr255();

struct gdt_entry_struct // GDT entry Struct
{
    unsigned short limit_low;
    unsigned short base_low;
    unsigned char  base_middle;
    unsigned char  access;
    unsigned char  granularity;
    unsigned char  base_high;
} __attribute__((packed));

typedef struct gdt_entry_struct gdt_entry_t;

struct gdt_ptr_struct // GDT descriptor Struct
{
    unsigned short limit;
    unsigned int base;
} __attribute__((packed));

typedef struct gdt_ptr_struct gdt_ptr_t;

struct idt_entry_struct {    // IDT entry Struct
	unsigned short base_low;
    	unsigned short selector;
    	unsigned char  always0;
    	unsigned char  flags;
    	unsigned short base_high;
} __attribute__((packed));

typedef struct idt_entry_struct idt_entry_t;

struct idt_ptr_struct // IDT descriptor Struct
{
    unsigned short _limit;
    unsigned int _base;
} __attribute__((packed));

typedef struct idt_ptr_struct idt_ptr_t;

gdt_entry_t gdt_entries[5]; // 5 segments (include null descriptor)
idt_entry_t inTab[256]; // 256 intterupts


gdt_entry_t gdt_set_gate(unsigned int base, unsigned int limit, unsigned char access, unsigned char granularity)
{
	gdt_entry_t gdt_entry;
	gdt_entry.base_low = (base&0xFFFF);
	gdt_entry.base_middle = (base>>16)&0xFF;
	gdt_entry.base_high = (base>>24)&0xFF;
	gdt_entry.limit_low = (limit&0xFFFF);
	gdt_entry.granularity = (limit>>16)&0x0F;
	gdt_entry.granularity |= granularity&0xF0;
	gdt_entry.access=access;
	return gdt_entry;
}

void init_idt_entry_t(unsigned short selector, unsigned int offset, unsigned char flags, int index)
{
	inTab[index].base_low = offset & 0xFFFF;
	inTab[index].selector = selector;
	inTab[index].flags = flags;
	inTab[index].always0 = 0;
	inTab[index].base_high = (offset >> 16) & 0xFFFF;
}


void gdt_setup()
{
	screen_print("GDT setting ..\n");
	gdt_ptr_t gdt_ptr;

	gdt_ptr.limit = (sizeof(gdt_entry_t) * 5) - 1;
	gdt_ptr.base  = (unsigned int)&gdt_entries;

	gdt_entries[0]=gdt_set_gate(0, 0, 0, 0); // Null Descriptor
	gdt_entries[1]=gdt_set_gate(0, 0xFFFFFFFF, 0x9A, 0xCF); // CodeSegment|KernelMode
	gdt_entries[2]=gdt_set_gate(0, 0xFFFFFFFF, 0x92, 0xCF); // DataSegment|KernelMode
	gdt_entries[3]=gdt_set_gate(0, 0xFFFFFFFF, 0xFA, 0xCF); // CodeSegment|UserMode
	gdt_entries[4]=gdt_set_gate(0, 0xFFFFFFFF, 0xF2, 0xCF); // DataSegment|UserMode
	gdt_write((unsigned int)&gdt_ptr); // Go To gdt.asm file.

	screen_print("GDT set!\n");
}

void idt_setup()
{
	screen_print("IDT setting ..\n");
	idt_ptr_t idt_ptr;
	
	idt_ptr._base = (unsigned int)&inTab;
	idt_ptr._limit = sizeof(idt_entry_t)*256-1;

	init_idt_entry_t(0x08,(unsigned int)isr0,0x8e,0);
	init_idt_entry_t(0x08,(unsigned int)isr1,0x8e,1);
	init_idt_entry_t(0x08,(unsigned int)isr2,0x8e,2);
	init_idt_entry_t(0x08,(unsigned int)isr3,0x8e,3);
	init_idt_entry_t(0x08,(unsigned int)isr4,0x8e,4);
	init_idt_entry_t(0x08,(unsigned int)isr5,0x8e,5);
	init_idt_entry_t(0x08,(unsigned int)isr6,0x8e,6);
	init_idt_entry_t(0x08,(unsigned int)isr7,0x8e,7);
	init_idt_entry_t(0x08,(unsigned int)isr8,0x8e,8);
	init_idt_entry_t(0x08,(unsigned int)isr9,0x8e,9);
	init_idt_entry_t(0x08,(unsigned int)isr10,0x8e,10);
	init_idt_entry_t(0x08,(unsigned int)isr11,0x8e,11);
	init_idt_entry_t(0x08,(unsigned int)isr12,0x8e,12);
	init_idt_entry_t(0x08,(unsigned int)isr13,0x8e,13);
	init_idt_entry_t(0x08,(unsigned int)isr14,0x8e,14);
	init_idt_entry_t(0x08,(unsigned int)isr15,0x8e,15);
	init_idt_entry_t(0x08,(unsigned int)isr16,0x8e,16);
	init_idt_entry_t(0x08,(unsigned int)isr17,0x8e,17);
	init_idt_entry_t(0x08,(unsigned int)isr18,0x8e,18);
	init_idt_entry_t(0x08,(unsigned int)isr19,0x8e,19);
	init_idt_entry_t(0x08,(unsigned int)isr20,0x8e,20);
	init_idt_entry_t(0x08,(unsigned int)isr21,0x8e,21);
	init_idt_entry_t(0x08,(unsigned int)isr22,0x8e,22);
	init_idt_entry_t(0x08,(unsigned int)isr23,0x8e,23);
	init_idt_entry_t(0x08,(unsigned int)isr24,0x8e,24);
	init_idt_entry_t(0x08,(unsigned int)isr25,0x8e,25);
	init_idt_entry_t(0x08,(unsigned int)isr26,0x8e,26);
	init_idt_entry_t(0x08,(unsigned int)isr27,0x8e,27);
	init_idt_entry_t(0x08,(unsigned int)isr28,0x8e,28);
	init_idt_entry_t(0x08,(unsigned int)isr29,0x8e,29);
	init_idt_entry_t(0x08,(unsigned int)isr30,0x8e,30);
	init_idt_entry_t(0x08,(unsigned int)isr31,0x8e,31);
	init_idt_entry_t(0x08,(unsigned int)irq0,0x8e,32); // IRQ START HERE
	init_idt_entry_t(0x08,(unsigned int)irq1,0x8e,33);
	init_idt_entry_t(0x08,(unsigned int)irq2,0x8e,34);
	init_idt_entry_t(0x08,(unsigned int)irq3,0x8e,35);
	init_idt_entry_t(0x08,(unsigned int)irq4,0x8e,36);
	init_idt_entry_t(0x08,(unsigned int)irq5,0x8e,37);
	init_idt_entry_t(0x08,(unsigned int)irq6,0x8e,38);
	init_idt_entry_t(0x08,(unsigned int)irq7,0x8e,39);
	init_idt_entry_t(0x08,(unsigned int)irq8,0x8e,40);
	init_idt_entry_t(0x08,(unsigned int)irq9,0x8e,41);
	init_idt_entry_t(0x08,(unsigned int)irq10,0x8e,42);
	init_idt_entry_t(0x08,(unsigned int)irq11,0x8e,43);
	init_idt_entry_t(0x08,(unsigned int)irq12,0x8e,44);
	init_idt_entry_t(0x08,(unsigned int)irq13,0x8e,45);
	init_idt_entry_t(0x08,(unsigned int)irq14,0x8e,46);
	init_idt_entry_t(0x08,(unsigned int)irq15,0x8e,47);
	init_idt_entry_t(0x08,(unsigned int)isr48,0x8e,48);
	init_idt_entry_t(0x08,(unsigned int)isr49,0x8e,49);
	init_idt_entry_t(0x08,(unsigned int)isr50,0x8e,50);
	init_idt_entry_t(0x08,(unsigned int)isr51,0x8e,51);
	init_idt_entry_t(0x08,(unsigned int)isr52,0x8e,52);
	init_idt_entry_t(0x08,(unsigned int)isr53,0x8e,53);
	init_idt_entry_t(0x08,(unsigned int)isr54,0x8e,54);
	init_idt_entry_t(0x08,(unsigned int)isr55,0x8e,55);
	init_idt_entry_t(0x08,(unsigned int)isr56,0x8e,56);
	init_idt_entry_t(0x08,(unsigned int)isr57,0x8e,57);
	init_idt_entry_t(0x08,(unsigned int)isr58,0x8e,58);
	init_idt_entry_t(0x08,(unsigned int)isr59,0x8e,59);
	init_idt_entry_t(0x08,(unsigned int)isr60,0x8e,60);
	init_idt_entry_t(0x08,(unsigned int)isr61,0x8e,61);
	init_idt_entry_t(0x08,(unsigned int)isr62,0x8e,62);
	init_idt_entry_t(0x08,(unsigned int)isr63,0x8e,63);
	init_idt_entry_t(0x08,(unsigned int)isr64,0x8e,64);
	init_idt_entry_t(0x08,(unsigned int)isr65,0x8e,65);
	init_idt_entry_t(0x08,(unsigned int)isr66,0x8e,66);
	init_idt_entry_t(0x08,(unsigned int)isr67,0x8e,67);
	init_idt_entry_t(0x08,(unsigned int)isr68,0x8e,68);
	init_idt_entry_t(0x08,(unsigned int)isr69,0x8e,69);
	init_idt_entry_t(0x08,(unsigned int)isr70,0x8e,70);
	init_idt_entry_t(0x08,(unsigned int)isr71,0x8e,71);
	init_idt_entry_t(0x08,(unsigned int)isr72,0x8e,72);
	init_idt_entry_t(0x08,(unsigned int)isr73,0x8e,73);
	init_idt_entry_t(0x08,(unsigned int)isr74,0x8e,74);
	init_idt_entry_t(0x08,(unsigned int)isr75,0x8e,75);
	init_idt_entry_t(0x08,(unsigned int)isr76,0x8e,76);
	init_idt_entry_t(0x08,(unsigned int)isr77,0x8e,77);
	init_idt_entry_t(0x08,(unsigned int)isr78,0x8e,78);
	init_idt_entry_t(0x08,(unsigned int)isr79,0x8e,79);
	init_idt_entry_t(0x08,(unsigned int)isr80,0x8e,80);
	init_idt_entry_t(0x08,(unsigned int)isr81,0x8e,81);
	init_idt_entry_t(0x08,(unsigned int)isr82,0x8e,82);
	init_idt_entry_t(0x08,(unsigned int)isr83,0x8e,83);
	init_idt_entry_t(0x08,(unsigned int)isr84,0x8e,84);
	init_idt_entry_t(0x08,(unsigned int)isr85,0x8e,85);
	init_idt_entry_t(0x08,(unsigned int)isr86,0x8e,86);
	init_idt_entry_t(0x08,(unsigned int)isr87,0x8e,87);
	init_idt_entry_t(0x08,(unsigned int)isr88,0x8e,88);
	init_idt_entry_t(0x08,(unsigned int)isr89,0x8e,89);
	init_idt_entry_t(0x08,(unsigned int)isr90,0x8e,90);
	init_idt_entry_t(0x08,(unsigned int)isr91,0x8e,91);
	init_idt_entry_t(0x08,(unsigned int)isr92,0x8e,92);
	init_idt_entry_t(0x08,(unsigned int)isr93,0x8e,93);
	init_idt_entry_t(0x08,(unsigned int)isr94,0x8e,94);
	init_idt_entry_t(0x08,(unsigned int)isr95,0x8e,95);
	init_idt_entry_t(0x08,(unsigned int)isr96,0x8e,96);
	init_idt_entry_t(0x08,(unsigned int)isr97,0x8e,97);
	init_idt_entry_t(0x08,(unsigned int)isr98,0x8e,98);
	init_idt_entry_t(0x08,(unsigned int)isr99,0x8e,99);
	init_idt_entry_t(0x08,(unsigned int)isr100,0x8e,100);
	init_idt_entry_t(0x08,(unsigned int)isr101,0x8e,101);
	init_idt_entry_t(0x08,(unsigned int)isr102,0x8e,102);
	init_idt_entry_t(0x08,(unsigned int)isr103,0x8e,103);
	init_idt_entry_t(0x08,(unsigned int)isr104,0x8e,104);
	init_idt_entry_t(0x08,(unsigned int)isr105,0x8e,105);
	init_idt_entry_t(0x08,(unsigned int)isr106,0x8e,106);
	init_idt_entry_t(0x08,(unsigned int)isr107,0x8e,107);
	init_idt_entry_t(0x08,(unsigned int)isr108,0x8e,108);
	init_idt_entry_t(0x08,(unsigned int)isr109,0x8e,109);
	init_idt_entry_t(0x08,(unsigned int)isr110,0x8e,110);
	init_idt_entry_t(0x08,(unsigned int)isr111,0x8e,111);
	init_idt_entry_t(0x08,(unsigned int)isr112,0x8e,112);
	init_idt_entry_t(0x08,(unsigned int)isr113,0x8e,113);
	init_idt_entry_t(0x08,(unsigned int)isr114,0x8e,114);
	init_idt_entry_t(0x08,(unsigned int)isr115,0x8e,115);
	init_idt_entry_t(0x08,(unsigned int)isr116,0x8e,116);
	init_idt_entry_t(0x08,(unsigned int)isr117,0x8e,117);
	init_idt_entry_t(0x08,(unsigned int)isr118,0x8e,118);
	init_idt_entry_t(0x08,(unsigned int)isr119,0x8e,119);
	init_idt_entry_t(0x08,(unsigned int)isr120,0x8e,120);
	init_idt_entry_t(0x08,(unsigned int)isr121,0x8e,121);
	init_idt_entry_t(0x08,(unsigned int)isr122,0x8e,122);
	init_idt_entry_t(0x08,(unsigned int)isr123,0x8e,123);
	init_idt_entry_t(0x08,(unsigned int)isr124,0x8e,124);
	init_idt_entry_t(0x08,(unsigned int)isr125,0x8e,125);
	init_idt_entry_t(0x08,(unsigned int)isr126,0x8e,126);
	init_idt_entry_t(0x08,(unsigned int)isr127,0x8e,127);
	init_idt_entry_t(0x08,(unsigned int)isr128,0x8e,128);
	init_idt_entry_t(0x08,(unsigned int)isr129,0x8e,129);
	init_idt_entry_t(0x08,(unsigned int)isr130,0x8e,130);
	init_idt_entry_t(0x08,(unsigned int)isr131,0x8e,131);
	init_idt_entry_t(0x08,(unsigned int)isr132,0x8e,132);
	init_idt_entry_t(0x08,(unsigned int)isr133,0x8e,133);
	init_idt_entry_t(0x08,(unsigned int)isr134,0x8e,134);
	init_idt_entry_t(0x08,(unsigned int)isr135,0x8e,135);
	init_idt_entry_t(0x08,(unsigned int)isr136,0x8e,136);
	init_idt_entry_t(0x08,(unsigned int)isr137,0x8e,137);
	init_idt_entry_t(0x08,(unsigned int)isr138,0x8e,138);
	init_idt_entry_t(0x08,(unsigned int)isr139,0x8e,139);
	init_idt_entry_t(0x08,(unsigned int)isr140,0x8e,140);
	init_idt_entry_t(0x08,(unsigned int)isr141,0x8e,141);
	init_idt_entry_t(0x08,(unsigned int)isr142,0x8e,142);
	init_idt_entry_t(0x08,(unsigned int)isr143,0x8e,143);
	init_idt_entry_t(0x08,(unsigned int)isr144,0x8e,144);
	init_idt_entry_t(0x08,(unsigned int)isr145,0x8e,145);
	init_idt_entry_t(0x08,(unsigned int)isr146,0x8e,146);
	init_idt_entry_t(0x08,(unsigned int)isr147,0x8e,147);
	init_idt_entry_t(0x08,(unsigned int)isr148,0x8e,148);
	init_idt_entry_t(0x08,(unsigned int)isr149,0x8e,149);
	init_idt_entry_t(0x08,(unsigned int)isr150,0x8e,150);
	init_idt_entry_t(0x08,(unsigned int)isr151,0x8e,151);
	init_idt_entry_t(0x08,(unsigned int)isr152,0x8e,152);
	init_idt_entry_t(0x08,(unsigned int)isr153,0x8e,153);
	init_idt_entry_t(0x08,(unsigned int)isr154,0x8e,154);
	init_idt_entry_t(0x08,(unsigned int)isr155,0x8e,155);
	init_idt_entry_t(0x08,(unsigned int)isr156,0x8e,156);
	init_idt_entry_t(0x08,(unsigned int)isr157,0x8e,157);
	init_idt_entry_t(0x08,(unsigned int)isr158,0x8e,158);
	init_idt_entry_t(0x08,(unsigned int)isr159,0x8e,159);
	init_idt_entry_t(0x08,(unsigned int)isr160,0x8e,160);
	init_idt_entry_t(0x08,(unsigned int)isr161,0x8e,161);
	init_idt_entry_t(0x08,(unsigned int)isr162,0x8e,162);
	init_idt_entry_t(0x08,(unsigned int)isr163,0x8e,163);
	init_idt_entry_t(0x08,(unsigned int)isr164,0x8e,164);
	init_idt_entry_t(0x08,(unsigned int)isr165,0x8e,165);
	init_idt_entry_t(0x08,(unsigned int)isr166,0x8e,166);
	init_idt_entry_t(0x08,(unsigned int)isr167,0x8e,167);
	init_idt_entry_t(0x08,(unsigned int)isr168,0x8e,168);
	init_idt_entry_t(0x08,(unsigned int)isr169,0x8e,169);
	init_idt_entry_t(0x08,(unsigned int)isr170,0x8e,170);
	init_idt_entry_t(0x08,(unsigned int)isr171,0x8e,171);
	init_idt_entry_t(0x08,(unsigned int)isr172,0x8e,172);
	init_idt_entry_t(0x08,(unsigned int)isr173,0x8e,173);
	init_idt_entry_t(0x08,(unsigned int)isr174,0x8e,174);
	init_idt_entry_t(0x08,(unsigned int)isr175,0x8e,175);
	init_idt_entry_t(0x08,(unsigned int)isr176,0x8e,176);
	init_idt_entry_t(0x08,(unsigned int)isr177,0x8e,177);
	init_idt_entry_t(0x08,(unsigned int)isr178,0x8e,178);
	init_idt_entry_t(0x08,(unsigned int)isr179,0x8e,179);
	init_idt_entry_t(0x08,(unsigned int)isr180,0x8e,180);
	init_idt_entry_t(0x08,(unsigned int)isr181,0x8e,181);
	init_idt_entry_t(0x08,(unsigned int)isr182,0x8e,182);
	init_idt_entry_t(0x08,(unsigned int)isr183,0x8e,183);
	init_idt_entry_t(0x08,(unsigned int)isr184,0x8e,184);
	init_idt_entry_t(0x08,(unsigned int)isr185,0x8e,185);
	init_idt_entry_t(0x08,(unsigned int)isr186,0x8e,186);
	init_idt_entry_t(0x08,(unsigned int)isr187,0x8e,187);
	init_idt_entry_t(0x08,(unsigned int)isr188,0x8e,188);
	init_idt_entry_t(0x08,(unsigned int)isr189,0x8e,189);
	init_idt_entry_t(0x08,(unsigned int)isr190,0x8e,190);
	init_idt_entry_t(0x08,(unsigned int)isr191,0x8e,191);
	init_idt_entry_t(0x08,(unsigned int)isr192,0x8e,192);
	init_idt_entry_t(0x08,(unsigned int)isr193,0x8e,193);
	init_idt_entry_t(0x08,(unsigned int)isr194,0x8e,194);
	init_idt_entry_t(0x08,(unsigned int)isr195,0x8e,195);
	init_idt_entry_t(0x08,(unsigned int)isr196,0x8e,196);
	init_idt_entry_t(0x08,(unsigned int)isr197,0x8e,197);
	init_idt_entry_t(0x08,(unsigned int)isr198,0x8e,198);
	init_idt_entry_t(0x08,(unsigned int)isr199,0x8e,199);
	init_idt_entry_t(0x08,(unsigned int)isr200,0x8e,200);
	init_idt_entry_t(0x08,(unsigned int)isr201,0x8e,201);
	init_idt_entry_t(0x08,(unsigned int)isr202,0x8e,202);
	init_idt_entry_t(0x08,(unsigned int)isr203,0x8e,203);
	init_idt_entry_t(0x08,(unsigned int)isr204,0x8e,204);
	init_idt_entry_t(0x08,(unsigned int)isr205,0x8e,205);
	init_idt_entry_t(0x08,(unsigned int)isr206,0x8e,206);
	init_idt_entry_t(0x08,(unsigned int)isr207,0x8e,207);
	init_idt_entry_t(0x08,(unsigned int)isr208,0x8e,208);
	init_idt_entry_t(0x08,(unsigned int)isr209,0x8e,209);
	init_idt_entry_t(0x08,(unsigned int)isr210,0x8e,210);
	init_idt_entry_t(0x08,(unsigned int)isr211,0x8e,211);
	init_idt_entry_t(0x08,(unsigned int)isr212,0x8e,212);
	init_idt_entry_t(0x08,(unsigned int)isr213,0x8e,213);
	init_idt_entry_t(0x08,(unsigned int)isr214,0x8e,214);
	init_idt_entry_t(0x08,(unsigned int)isr215,0x8e,215);
	init_idt_entry_t(0x08,(unsigned int)isr216,0x8e,216);
	init_idt_entry_t(0x08,(unsigned int)isr217,0x8e,217);
	init_idt_entry_t(0x08,(unsigned int)isr218,0x8e,218);
	init_idt_entry_t(0x08,(unsigned int)isr219,0x8e,219);
	init_idt_entry_t(0x08,(unsigned int)isr220,0x8e,220);
	init_idt_entry_t(0x08,(unsigned int)isr221,0x8e,221);
	init_idt_entry_t(0x08,(unsigned int)isr222,0x8e,222);
	init_idt_entry_t(0x08,(unsigned int)isr223,0x8e,223);
	init_idt_entry_t(0x08,(unsigned int)isr224,0x8e,224);
	init_idt_entry_t(0x08,(unsigned int)isr225,0x8e,225);
	init_idt_entry_t(0x08,(unsigned int)isr226,0x8e,226);
	init_idt_entry_t(0x08,(unsigned int)isr227,0x8e,227);
	init_idt_entry_t(0x08,(unsigned int)isr228,0x8e,228);
	init_idt_entry_t(0x08,(unsigned int)isr229,0x8e,229);
	init_idt_entry_t(0x08,(unsigned int)isr230,0x8e,230);
	init_idt_entry_t(0x08,(unsigned int)isr231,0x8e,231);
	init_idt_entry_t(0x08,(unsigned int)isr232,0x8e,232);
	init_idt_entry_t(0x08,(unsigned int)isr233,0x8e,233);
	init_idt_entry_t(0x08,(unsigned int)isr234,0x8e,234);
	init_idt_entry_t(0x08,(unsigned int)isr235,0x8e,235);
	init_idt_entry_t(0x08,(unsigned int)isr236,0x8e,236);
	init_idt_entry_t(0x08,(unsigned int)isr237,0x8e,237);
	init_idt_entry_t(0x08,(unsigned int)isr238,0x8e,238);
	init_idt_entry_t(0x08,(unsigned int)isr239,0x8e,239);
	init_idt_entry_t(0x08,(unsigned int)isr240,0x8e,240);
	init_idt_entry_t(0x08,(unsigned int)isr241,0x8e,241);
	init_idt_entry_t(0x08,(unsigned int)isr242,0x8e,242);
	init_idt_entry_t(0x08,(unsigned int)isr243,0x8e,243);
	init_idt_entry_t(0x08,(unsigned int)isr244,0x8e,244);
	init_idt_entry_t(0x08,(unsigned int)isr245,0x8e,245);
	init_idt_entry_t(0x08,(unsigned int)isr246,0x8e,246);
	init_idt_entry_t(0x08,(unsigned int)isr247,0x8e,247);
	init_idt_entry_t(0x08,(unsigned int)isr248,0x8e,248);
	init_idt_entry_t(0x08,(unsigned int)isr249,0x8e,249);
	init_idt_entry_t(0x08,(unsigned int)isr250,0x8e,250);
	init_idt_entry_t(0x08,(unsigned int)isr251,0x8e,251);
	init_idt_entry_t(0x08,(unsigned int)isr252,0x8e,252);
	init_idt_entry_t(0x08,(unsigned int)isr253,0x8e,253);
	init_idt_entry_t(0x08,(unsigned int)isr254,0x8e,254);
	init_idt_entry_t(0x08,(unsigned int)isr255,0x8e,255);

	idt_write((unsigned int)&idt_ptr);
	screen_print("IDT set!\n");
	pic_init();
	irq_setup();
	__asm__("sti");
}
void pic_init()
{
	screen_print("PIC setting ..\n");
	//Init [ICW1]
	outb(0x20, 0x11);
	outb(0xA0, 0x11);
	
	//Vector Offset [ICW2]
	//The offset from 0
	outb(0x21, 0x20);
	outb(0xA1, 0x28);

	//Connect the PICs [ICW3]
	outb(0x21,0x04); // Slave in IRQ2
	outb(0xA1,0x02);

	//Set Mode [ICW4]
	outb(0x21, 0x01); // x86 mode
	outb(0xA1, 0x01);

	//Masking
	outb(0x21, 0x0);
	outb(0xA1, 0x0);

	screen_print("PIC set!\n");
	
}



