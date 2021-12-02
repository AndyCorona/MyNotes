#include <stdio.h>
#include <string.h>

int main(){

    char name[20];

    printf("请输出姓名：");
    scanf("%s",name);

    //打印姓名，包括双引号
    printf("\"%s\"\n",name);

    //打印姓名，包括双引号，右对齐
    printf("\"%20s\"\n",name);

    //打印姓名，包括双引号，左对齐
    printf("\"%-20s\"\n",name);

    printf("%*s\n",strlen(name)+3,name);

    return 0;
}
