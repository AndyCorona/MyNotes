#include <stdio.h>
#include <float.h>

int main(void){

    signed char temp = 127 + 1;
    float toobig = FLT_MAX * 100.0f;
    float toosmall = FLT_MIN / FLT_MAX;

    printf("整数上溢：%d\n",temp);
    printf("浮点数上溢：%f\n",toobig);
    printf("浮点数下溢：%le\n",toosmall);
    
    return 0;

}
