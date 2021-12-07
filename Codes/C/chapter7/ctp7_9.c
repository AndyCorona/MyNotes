#include <stdio.h>

int main(void){

    unsigned int num;

    printf("请输入一个大于0的整数：");

    while(scanf("%u",&num)){

	int i;
	for(i = 1; (i*i) < num; i++){

	    if( num % i == 0){

		printf("%u %u ",i,num /i);	
	
 	    }

        }	
	printf("\n请输入一个大于0的整数：");  

    }
    return 0;

}
