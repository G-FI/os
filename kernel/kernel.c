#include "../drivers/screen.h"
#include "../cpu/idt.h"
#include "../cpu/isr.h"

void main() {
    isr_install();

     __asm__ __volatile__ ("int $0");
    //  __asm__ __volatile__ ("int $1");
    //  __asm__ __volatile__ ("int $2");
    //  __asm__ __volatile__ ("int $3");
    //  __asm__ __volatile__ ("int $4");
    //  __asm__ __volatile__ ("int $5");
    //  __asm__ __volatile__ ("int $6");

}
