#include <stdio.h>

//返回两数之差除以两数之积的结果
double func(double n1, double n2);

int main(void){

    double num1;
    double num2;

    printf("请输入两个浮点数：");
    scanf("%lf%lf",&num1,&num2);
    
    printf("%0.2f\n",func(num1,num2));
    
    return 0;
}

double func(double num1, double num2){

    return (num1 - num2) / (num1 * num2);

}
