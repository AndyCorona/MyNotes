#include <stdio.h>
#include <assert.h>

unsigned rotate_left(unsigned x,int n){

    int w = sizeof(int) << 3;
    //当 n 为 0 时，x >> w 为未定义的行为
    return (x << n) | x >> (w-n-1) >> 1;
}


int main(void){

    assert(rotate_left(0x12345678,4) == 0x23456781);
    assert(rotate_left(0x12345678,20) == 0x67812345);
    assert(rotate_left(0x12345678,0) == 0x12345678);

    return 0;
}
