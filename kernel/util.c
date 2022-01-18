#include "util.h"

void mem_copy(char *src, char *dst, int n){
    for(int i = 0; i < n; i++){
        dst[i] = src[i];
    }
}

void int_to_assic(int n, char *buf){
    int sign, i=0;
    if((sign == n) < 0) n = -n;
    do{
        buf[i++] = n%10 + '0';
    }while((n /= 10) > 0);

    if(sign < 0){
        buf[i++] = '-';
    }
    buf[i] = 0;
    reverse(buf);
}

void reverse(char *str){
    for(int i = 0, j = strlen(str) - 1; i < j; i++, j--){
        char t = str[i];
        str[i] = str[j];
        str[j] =t;
    }
}

int strlen(char *str){
    int n = 0;
    while(str[n] != 0) ++n;
    return n;
}