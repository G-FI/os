int caller_func(){
    callee_func(0xa1, 0xa2, 0xa3);
    return 0;
}

int callee_func(int arg1, int arg2, int arg3){
    return arg1 + arg2 + arg3;
}
