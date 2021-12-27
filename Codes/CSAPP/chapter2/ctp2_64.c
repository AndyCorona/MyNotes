#include <stdio.h>
#include <assert.h>

int any_odd_one(unsigned x){

    return !!(0x55555555 & x);

}


int main(void){

    assert(any_odd_one(0x4));
    assert(!any_odd_one(0x2));

    return 0;
}
