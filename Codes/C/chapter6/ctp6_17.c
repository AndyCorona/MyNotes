#include <stdio.h>

int main(void){

    double money = 1000000.0;
    int i = 0;

    do{

	money = 1.08 * money - 100000.0;
	i++;  
	printf("还剩下 %f 钱\n",money);

    }while(money >= 0);

    printf("经过 %d 年后把钱取完\n",i);

    return 0;
}
