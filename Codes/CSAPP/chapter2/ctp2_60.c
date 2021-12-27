#include <stdio.h>
#include <assert.h>

unsigned replace_byte(unsigned x,int i, unsigned char b){

    //根据 i 的值左移到指定位置后，掩盖 x 的一个字节，用字节 b 替换
    unsigned int mask = ((unsigned)0xff) << (i<<3);
    unsigned int pos_byte = ((unsigned) b) << (i <<3);      

    return (x & ~mask) | pos_byte;

}

int main(void){

    unsigned num1 = replace_byte(0x12345678,2,0xAB);
    unsigned num2 = replace_byte(0x12345678,0,0xAB);

    assert(num1 == 0x12AB5678);
    assert(num2 == 0x123456AB);


    return 0;
}
