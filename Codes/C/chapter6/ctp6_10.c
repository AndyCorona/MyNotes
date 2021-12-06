#include <stdio.h>

//返回从 n1 到 n2 范围内的所有整数平方和
int squareRange(int n1, int n2);

int main(void){

    int lower;
    int upper;

    //获取用户输入的浮点数个数
    int verify;

    printf("Enter lower and upper integer limits:");
    verify = scanf("%d%d",&lower,&upper);

    while(verify){

        printf("The sums of the squares from %d to %d is %d\n", lower * lower, upper * upper, squareRange(lower,upper));
        printf("Enter next set of limits:");

        verify = scanf("%d%d",&lower,&upper);
    }

    return 0;
}

int squareRange(int num1, int num2){

    int i = num1;
    int sum = 0;

    for(; i <= num2; i++){

	sum += i * i;
    }

    return sum;
}
