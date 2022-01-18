#include "timer.h"
#include "isr.h"
#include "../drivers/ports.h"
#include "../drivers/screen.h"
#include "../kernel/util.h"


uint32 ticks;

void timer_call_back(registers_t regs){
    ++ticks;
    char buf[256];
    int_to_assic(ticks, buf);
    kprint("ticks: ");
    kprint(buf);
    kprint("\n");
}

void init_timer(uint32 freq){
    //reigster timer interrupt handler
    irq_register(IRQ0, timer_call_back);
    uint32 divisor = 1193180/ freq;
    uint8 low = (uint8)(divisor & 0xFF);
    uint8 high = (uint8)((divisor>>8)& 0xFF);

    //send the command
    port_byte_out(0x43, 0x36);
    port_byte_out(0x40, low);
    port_byte_out(0x40, high);
}