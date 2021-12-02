#include <stdio.h>

int main(void){

    int weight;

    printf("请输入水的质量(g)：");
    scanf("%d", &weight);
    printf("含有的水分子数量为：%e\n",weight / 3.0e-23);
    
    return 0;
}
