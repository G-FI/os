void main(){

//create a pointer to a char, and point to the first text cell of video memory
char *video_memory = (char*)0xb8000;

//display 'X' in the top-left of screen
    *video_memory = 'x';
    *(video_memory+1)=0xaa;
    /* *video_memory = 'H'; */
    /* *(video_memory + 1)='U'; */
    /* *(video_memory + 2)='P'; */
    /* *(video_memory + 3) ='E'; */
    /* *(video_memory + 4) ='N'; */
    /* *(video_memory + 5) ='G'; */
    /* *(video_memory + 6) ='Y'; */
    /* *(video_memory + 7) ='U'; */
}
