#include <stdio.h>

//定义数组的长度
#define SIZE 26

int main(void){

    //创建字符数组
    char array[SIZE];
    int i;

    //将 a-z 放入字符数组，循环 26 次
    for(i = 0; i < 26; i++){
        
	//小写字母 a 的 ASCII 码为 97
	array[i] = 97 + i;

    }

    int j;
    //依次输出 a-z
    for (j = 0; j < 26; j++){
        
	printf("%c ",array[j]);	

    } 
	
    printf("\n");
    return 0;
}
