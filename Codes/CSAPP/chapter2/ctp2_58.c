#include <stdio.h>
#include <assert.h>

typedef unsigned char * byte_pointer;


int is_little_endian(){

    int test_num = 0xff;
    byte_pointer pt = (byte_pointer) &test_num;
 
    
    //若第一个字节存放着最低有效字节的值，是小端法存储，否则为大端法存储 
    if(pt[0] == 0xff)
        return 1;
    return 0;
}

int main(void){

    assert(is_little_endian());

    return 0;
}
