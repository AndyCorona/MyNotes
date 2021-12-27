#include <stdio.h>
#include <assert.h>

int int_shifts_are_arithmetic(){
    
    //0xffffffff
    int num = -1;
    return !(num ^ (num >> 1));

}


int main(void){

    assert(int_shifts_are_arithmetic());

    return 0;
}
