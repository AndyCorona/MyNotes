#include <stdio.h>
#include <string.h>

int main(void){

    //存储用户输入的字符串
    char string[40];
    
    int i;

    printf("请输入一个单词：");
    scanf("%s",string);

    for(i = strlen(string); i >= 0; i--){

	printf("%c",string[i]);

    }
	
    printf("\n");

    return 0;

}
