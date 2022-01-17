#define VIDEO_ADDRESS 0xb8000
#define MAX_ROWS 25
#define MAX_COLS 80
#define WHITH_ON_BLACK 0x0f
#define RED_ON_WHITE 0xf4

//screen I/O port
#define REG_SCREEN_CTRL 0x3d4
#define REG_SCREEN_DATA 0x3d5

/*public kernel API*/

void clear_screen();
void kprint(char *msg);
void kprint_at(char *msg, int row, int col);