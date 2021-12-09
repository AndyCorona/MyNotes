#include <stdio.h>

double myfun(double,double);

int main(void){

    printf("1.5 和 2.7 的调和平均数为: %0.4f\n",myfun(1.5,2.7));   

    return 0;
}

//返回两数的调和平均数
double myfun(double d1,double d2){

    return 1.0/(1.0/d1*2.0 + 1.0/d2*2.0);
    
}
