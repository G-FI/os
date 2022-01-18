#include "../drivers/screen.h"
#include "../cpu/idt.h"
#include "../cpu/isr.h"
#include "../cpu/timer.h"
#include "../drivers/keyboard.h"

void main() {
    isr_install();
    __asm__ __volatile__ ("sti");
    
    kprint("timer init\n");
    /* init_timer(1); */
    
    init_keyboard();

}
