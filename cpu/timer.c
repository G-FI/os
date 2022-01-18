#include "timer.h"
#include "isr.h"
#include "ports.h"
#include "../drivers/screen.h"


uint32 ticks;

void timer_callback(registers_t regs){
    ++ticks;
}

void init_timer(uint32 freq){
    //reigster timer interrupt handler
    irq_register(IRQ0, timer_callback);
    uint32 divisor = 1193180/ freq;
    uint8 low = (uint8)(divisor & 0xFF);
    uint8 high = (uint8)((divisor>>8)& 0xFF);

    //send the command
    port_byte_out(0x43, 0x36);
    port_byte_out(0x40, low);
    port_byte_out(0x40, high);
}