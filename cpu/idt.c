#include "idt.h"

void set_idt_gate(int n, uint32 handler){
    idt[n].base_lo = LOW16(handler);
    idt[n].selecor = KERNEL_CS;
    idt[n].always0 = 0;
    idt[n].flags = 0x8E; 
    idt[n].base_hi = HIGH16(handler);
}

void install_idt(){
    idt_reg.limit = sizeof(idt) - 1;
    idt_reg.base = &idt;
    __asm__ __volatile__ ("lidtl (%0)": : "r"(&idt_reg));
}