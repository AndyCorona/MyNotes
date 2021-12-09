#include <stdio.h>

double power(double n, int p);

int main(void){

    double x, xpow;
    int exp;

    printf("Enter a number and the positive integer power");
    printf(" to which\nthe number will be raised. Enter q");
    printf(" to quit.\n");

    while (scanf("%lf%d", &x, &exp) == 2){

        xpow = power(x, exp); // 函数调用
	printf("%.3g to the power %d is %.5g\n", x, exp, xpow);
	printf("Enter next pair of numbers or q to quit.\n");
    }

    printf("Hope you enjoyed this power trip -- bye!\n");
    return 0;
}

//计算数 n 的 p 次方
double power(double n, int p) {


    //0 的任何次幂都为 0
    if(n == 0.0 && p != 0){

	return 0.0;

    }

    //任何数的 0 次幂都为 1
    if(p == 0){
        
	if(n == 0.0)
	    printf("0.0 to the power 0 is undefined\n");
	
        return 1.0;
    }



    double pow = 1;
    int i;

    //计算正次幂
    if( p > 0){

        for (i = 1; i <= p; i++)
            pow *= n;
        return pow; 
    }else{ //计算负次幂
     
	return 1.0/power(n,-p);
    }

}












