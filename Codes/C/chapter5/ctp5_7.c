#include <stdio.h>

void cubed(double num);

int main(void){

    double num;

    printf("请输入一个小数：");
    scanf("%lf",&num);

    printf("%0.2f\n",num);
    cubed(num);

    return 0;
}

void cubed(double num){

    printf("立方值为：%0.2f\n", num * num * num);

}
