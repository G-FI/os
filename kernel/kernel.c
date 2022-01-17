#include"../drivers/ports.h"
#include"../drivers/screen.h"

void main(){
    kprint_char('X', 0, 0, RED_ON_WHITE);
    clear_screen();
    kprint("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
}
