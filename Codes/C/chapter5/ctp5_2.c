#include <stdio.h>

int main(void){

    int num;
    int temp;

    printf("请输出一个整数：");
    scanf("%d",&num);
    temp = num + 11;

    while(num < temp){

        printf("%d ",num);
        num++;
    }
    printf("\n");
    return 0;
}
