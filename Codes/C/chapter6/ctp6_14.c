#include <stdio.h>

int main(void){

    int num1[8];
    int num2[8];
    int i; 


    //提示用户给第一个数组赋值
    for(i = 0; i < 8; i++){

	printf("请输入一个整数：");
	scanf("%d",&num1[i]);

    }

    for(i = 1, num2[0] = num1[0]; i < 8; i++){

	num2[i] = num2[i - 1] + num1[i];
    }

    for(i = 0; i < 8; i++){

        printf("%5d",num1[i]);

    }

    printf("\n");

    for(i = 0; i < 8; i++){

	printf("%5d", num2[i]);

    }
    printf("\n");

    return 0;
}
