#ifndef IDT_H_
#define IDT_H_
#include "types.h"

//0 and 1 privilege level, 2 if set then indicate ldt, else gdt, 3..15 index
//0x08 means frist entry in gdt with highest priority 
#define KERNEL_CS 0x08

typedef struct {
    uint16 base_lo;  //low 16bits address to jump to
    uint16 selecor;  //kernel segment selector
    uint8 always0;   //reserved
    uint8 flags;
    uint16 base_hi;  //high 16bits address to jump to
}__attribute__((packed)) idt_entry_t;

typedef struct {
    uint16 limit;
    uint32 base;
}__attribute__((packed)) idt_registe_t;

#define IDT_ENTRIES 256
idt_entry_t idt[IDT_ENTRIES];
idt_registe_t idt_reg;


void set_idt_gate(int n, uint32 handler);
void install_idt();



#endif //IDT_H_
