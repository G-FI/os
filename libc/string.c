#include "string.h"

void int_to_ascii(int n, char *buf){
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

int strcmp(char *s1, char *s2){
    int i;
    for(i = 0; s1[i] == s2[i]; i++){
        if(s1[i] == 0) return 0;
    }
    return s1[i] - s2[i];
}

void append(char *str, char c){
    int n = strlen(str);
    str[n] = c;
    str[n+1] = 0;
}

void backspace(char *buf){
    int n = strlen(buf);
    buf[n-1] = 0; 
}

void hex_to_ascii(int n, char *buf){
    buf[0] = '0';
    buf[1] = 'X';
    int idx = 2;

    int tmp;
    for(int i = 28; i >= 0; i -= 4){
        //extract 4 bit every time
        tmp = (n >> i) & 0xF;
        if(tmp >= 0xA) buf[idx++] = tmp - 0xA + 'A';
        else buf[idx++] = tmp + '0';
    }
    buf[idx] = 0;
}