#include <stdio.h>

void larger_of(double *,double *);

int main(void){

    double num1 = 4.5;
    double num2 = 3.6;

    printf("Before: num1:%0.2f,num2:%0.2f\n",num1,num2);

    larger_of(&num1,&num2);   

    printf("After: num1:%0.2f,num2:%0.2f\n",num1,num2);

    return 0;

}

//把两数的值都替换成两数中较大的值
void larger_of(double * d1,double * d2){

    *d1 = *d2 = (*d1 > *d2)? *d1:*d2;
   
}
