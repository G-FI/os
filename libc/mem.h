#ifndef MEM_H_
#define MEM_H_

#include "../cpu/types.h"


void mem_copy(char *src, char *dst, int n);
uint32 kmalloc(int size, uint32 *pa);

#endif //MEM_H_