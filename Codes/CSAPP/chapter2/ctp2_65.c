#include <stdio.h>
#include <assert.h>

int add_ones(unsigned x){
    //将 int 的高 16 位和低 16 位异或
    x ^= x >> 16;
    //将 16 位异或结果分成高 8 位和低 8 位，继续异或
    x ^= x >> 8;
    //将 8 位异或结果分成高 4 位和低 4 位，继续异或
    x ^= x >> 4;
    //将 4 位异或结果分成高 2 位和低 2 位，继续异或
    x ^= x >> 2;
    //将 2 位异或结果分成高位和低位，异或
    x ^= x >> 1;
    //若最终异或结果为 1，说明有奇数个 1，否则有偶数个 1
    x &= 0x1;
    return x;

}

int main(void){
    
    assert(add_ones(0x10101110));
    assert(!add_ones(0x01101010));

    return 0;
}
