#include <stdio.h>

int main(){

    float tall;
    char name[20];

    printf("请输入你的姓名：");
    scanf("%s",name);
    printf("请输入你的身高：");
    scanf("%f",&tall);
    printf("%s, you are %0.3f feet tall\n",name,tall);

    return 0;
}
