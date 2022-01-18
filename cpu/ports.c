#include "ports.h"

unsigned char port_byte_in(unsigned short port){
    unsigned char result;
    //in %ax, %dx; from %dx read data to ax
    //the port number must be in dx
    __asm__("in %%dx, %%al": "=a"(result):"d"(port));
    return result;
}

void port_byte_out(unsigned short port, unsigned char data){
    //Transfers byte in AL,word in AX or dword in EAX to the specified hardware port address
    //out port, data
    __asm__("out %%al, %%dx": : "a"(data), "d"(port));
}

unsigned short port_word_in(unsigned short port){
    unsigned short result;
    __asm__("in %%dx, %%ax": "=a"(result): "d"(port));
    return result;
}

void port_wrod_out(unsigned short port, unsigned short data){
    __asm__("out %%ax, %%dx":: "a"(data), "d"(port));
}