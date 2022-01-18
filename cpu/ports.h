#ifndef PORTS_H_
#define PORTS_H_

//read a byte from I/O port
unsigned char port_byte_in(unsigned short port);
//write a byte to I/O port
void port_byte_out(unsigned short port, unsigned char data);
//read a word 
unsigned short port_word_in(unsigned short port);
//write a word 
void port_word_out(unsigned short port, unsigned short data);

#endif //PORTS_H_
