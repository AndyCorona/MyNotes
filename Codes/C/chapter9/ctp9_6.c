#include <stdio.h>

void func(double *, double *, double *);

int main(void){

    double num1 = 9.9;
    double num2 = 7.0;
    double num3 = 10.0;

    printf("Before: num1 %.2f num2 %.2f num3 %.2f\n",num1,num2,num3);    

    func(&num1,&num2,&num3);

    printf("Before: num1 %.2f num2 %.2f num3 %.2f\n",num1,num2,num3);   

    return 0;

}


//d1 存放最小值，d3 存放最大值，d2 存放中间值
void func(double * d1, double * d2, double * d3){

    double temp;

    if(*d1 > *d2){

	temp = *d2;
	*d2 = *d1;
	*d1 = temp;

    }
    
     if(*d2 > *d3){

	temp = *d3;
	*d3 = *d2;
	*d2 = temp;

    }
}
