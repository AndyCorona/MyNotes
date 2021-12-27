#include <stdio.h>
#include <assert.h>
#include <limits.h>

int saturating_add(int x,int y){

    int sum = x + y;
    int mask = INT_MIN;

    //当 x > 0，y > 0 且 x + y < 0 时，正溢出
    int pos_over = !(x & mask) && !(y & mask) && (sum & mask);
    //当 x < 0，y < 0 且 x + y > 0 时，负溢出
    int neg_over = (x & mask) && (y & mask) && !(sum & mask);

    (pos_over && (sum = INT_MAX) || neg_over && (sum = INT_MIN));

    return sum;

}

int main(void){

    assert(INT_MAX == saturating_add(INT_MAX,0x1234));
    assert(INT_MIN == saturating_add(INT_MIN,-0x1234));
    assert(0x11 + 0x22 == saturating_add(0x11,0x22));

    return 0;
}
