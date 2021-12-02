#include <stdio.h>


int main(){

    float num;

    printf("请输入一个浮点数：");
    scanf("%f",&num);
    printf("小数点记数法表示：%0.1f\n",num);
    printf("指数记数法表示：%0.1E\n",num);

    return 0;
}
