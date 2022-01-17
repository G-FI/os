#include "../drivers/screen.h"

void main() {
    clear_screen();
    kprint_at("X", 0, 6);
    kprint_at("This text spans multiple lines", 10, 75);
    kprint_at("There is a line\nbreak", 20, 0);
    kprint("There is a line\nbreak");
    kprint_at("line 23", 23, 0);
    kprint_at("line 24", 24, 0);
    kprint_at("What happens when we run out of space", 24, 70);
}
