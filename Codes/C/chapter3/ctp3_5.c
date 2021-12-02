#include <stdio.h>

int main(void){

    char age;

    printf("请输入年龄：");
    scanf("%d",&age);
    printf("该年龄对应的秒数为：%e\n",age *3.156e7 );

    return 0;

}
