#include <stdio.h>

unsigned long Fibonacci(unsigned int n);

int main(void){ 

    unsigned int num;

    printf("请输入一个正整数计算斐波那契数列:");
    while(scanf("%u", &num)){

	printf("计算结果为:%ld\n",Fibonacci(num));

    }

    return 0;
}

unsigned long Fibonacci(unsigned int n){

    int i;
    unsigned long temp;   
    unsigned long num1 = 1;
    unsigned long num2 = 1;
    unsigned long result = 2;

    if(n == 1 || n == 2){

	return 1;

    }else{
	
        for(i = 3; i < n; i++){

	   temp  = num2;
	   num2 = num1 + num2;
	   num1 = temp;
	   result = num1 + num2; 
        }
        return result;  
    }
}
