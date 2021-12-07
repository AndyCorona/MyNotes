#include <stdio.h>
#define TAXRATE_SINGLE 17850
#define TAXRATE_MASTER 23900
#define TAXRATE_MARRIED 29750
#define TAXRATE_DIVORCE 14875

int main(void){

    unsigned int salary;
    unsigned int num;
    double tax;

    printf("请输入工资：");
    while(scanf("%u",&salary)){

        printf("\n***************************\n\n");
        printf("请选择税务种类：\n\n");
        printf("1) 单身        2）户主\n\n");
        printf("3）已婚共有    4）已婚离异\n\n");
        printf("5）退出\n\n");
        printf("**************************\n\n");
        scanf("%u",&num);
        if(num == 5)
 	    break;

	switch(num){
			
	    case 1:
		if(salary >= TAXRATE_SINGLE) 
                    tax = 0.15 * TAXRATE_SINGLE + 0.28 * (salary - TAXRATE_SINGLE);
		else
		    tax = 0.15 * salary;
		break;
	    case 2:
		if(salary >= TAXRATE_MASTER)

                    tax = 0.15 * TAXRATE_MASTER + 0.28 * (salary - TAXRATE_MASTER);
		else
		    tax = 0.15 * salary;;
		break;
	    case 3:
		if(salary >= TAXRATE_MARRIED)
                    tax = 0.15 * TAXRATE_MARRIED + 0.28 * (salary - TAXRATE_MARRIED);
		else
		    tax = 0.15 * salary;
		break;
	    case 4:
		if(salary >= TAXRATE_DIVORCE)
                    tax = 0.15 * TAXRATE_DIVORCE + 0.28 * (salary - TAXRATE_DIVORCE);
		else
		    tax = 0.15 * salary;		
		break;
 	}
    
        printf("税金为：%.2f\n",tax);
        printf("请输入工资：");

    }
    return 0;
}
