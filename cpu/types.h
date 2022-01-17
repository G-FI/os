#ifndef TYPES_H_
#define TYPES_H_

typedef unsigned int    uint32;
typedef int             int32;
typedef unsigned short  uint16;
typedef short           int16;
typedef unsigned char   uint8;
typedef char            int8;

#define HIGH16(addr) (uint16)((addr>>16)&(0xFFFF))
#define LOW16(addr) (uint16)(addr & 0xFFFF)
#endif //TYPES_H_
