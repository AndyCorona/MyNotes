#include <stdio.h>
#include <string.h>

int main(){

    char lastname[20];
    char firstname[20];
    
    //姓的长度
    int num1;
    //名的长度
    int num2;

    printf("请输入姓：");
    scanf("%s",lastname);

    num1 = strlen(lastname);

    printf("请输入名：");
    scanf("%s",firstname);

    num2=strlen(firstname);
    printf("%s %s\n",lastname,firstname);
    printf("%*d %*d\n",num1,num1,num2,num2);
    printf("%-*d %-*d\n",num1,num1,num2,num2);

    return 0;
}
