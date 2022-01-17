#include"ports.h"
#include"screen.h"

//helper function pre-declearation
int get_screen_offset(int row, int col);
int get_cursor_offset();
void set_cursor_offset(int offset);
int get_offset_row(int offset);
int get_offset_col(int offset);

int kprint_char(char c, int row, int col, char attr);

/*public API*/
void clear_screen(){
    int row;
    int col;
    for(row = 0; row < MAX_ROWS; row++){
        for(col = 0; col < MAX_COLS; col++){
            kprint_char(' ', row, col, 0);
        }
    }
    set_cursor_offset(get_screen_offset(0, 0));
}

void kprint_at(char *msg, int row, int col){
    for(int i = 0; msg[i] != 0; i++){
        kprint_char(msg[i], row, col, 0);
        row = -1; 
        col = -1;
    }
}

void kprint(char *msg){
    kprint_at(msg, -1, -1);
}

/*write c at (row, col), set cursor to next charactor, and return the offset*/
int kprint_char(char c, int row, int col, char attr){
    unsigned char *video_mem = (unsigned char *)VIDEO_ADDRESS;
    if(attr == 0) attr = WHITH_ON_BLACK;

    if(col >= MAX_COLS || row >= MAX_ROWS){
        video_mem[2 * (MAX_ROWS * MAX_COLS) - 2] = 'E';
        video_mem[2 * (MAX_ROWS * MAX_COLS) - 1] = WHITH_ON_BLACK;
        return get_screen_offset(row, col);
    }
    //get offset of (row, col)
    int offset;
    if(row >= 0 && col >= 0) offset = get_screen_offset(row, col);
    else offset = get_cursor_offset();

    if(c == '\n'){
        // offset = get_screen_offset(row + 1, 0);
        //in case of row and col == 1, row will be change 
        row = get_offset_row(offset);
        offset  = get_screen_offset(row + 1, 0);
    }else{
        video_mem[offset] = c;
        video_mem[offset + 1] = attr;
        offset += 2;
    }
    set_cursor_offset(offset);
    return offset;
}

int get_screen_offset(int row, int col){
    return (row * MAX_COLS + col) * 2;
}

int get_cursor_offset(){
    port_byte_out(REG_SCREEN_CTRL, 14);
    int offset = port_byte_in(REG_SCREEN_DATA) << 8;
    port_byte_out(REG_SCREEN_CTRL, 15);
    offset += port_byte_in(REG_SCREEN_DATA);
    return offset  * 2; //keep in mind *2
}

void set_cursor_offset(int offset){
    offset /= 2;
    port_byte_out(REG_SCREEN_CTRL, 14);
    //14->high 8 bits
    port_byte_out(REG_SCREEN_DATA, (unsigned char)(offset >> 8));
    //15->low 8 bits
    port_byte_out(REG_SCREEN_CTRL, 15);
    port_byte_out(REG_SCREEN_DATA, (unsigned char)(offset & 0xff));
}

int get_offset_row(int offset){
    return (offset/2) / MAX_COLS;
}

int get_offset_col(int offset){
    return (offset/2) % MAX_COLS;
}