#include <stdio.h>

int main(void){

    double height;

    printf("请输入你的身高（英寸）：");
    scanf("%lf",&height);
    printf("你的身高为：%.2f厘米\n",height * 2.54);

    return 0;
}
