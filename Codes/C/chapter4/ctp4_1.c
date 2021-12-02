#include <stdio.h>

//编写一个程序，提示用户输入名和姓，然后以 "名,姓"的格式打印出来
int main(){

    //名
    char firstname[20];
    //姓
    char lastname[20];

    printf("请输入姓：");
    scanf("%s",lastname);
    printf("请输入名：");
    scanf("%s",firstname);

    printf("你好，%s,%s",lastname,firstname);

    return 0;
}
