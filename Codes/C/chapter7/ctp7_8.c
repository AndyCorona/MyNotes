#include <stdio.h>
#define WORKTIME_PER_WEEK 40
#define LT_300 0.15
#define T_F 0.20
#define LT_450 0.25 

int main(void){


    int num;
    double BASIC_SALARY;
    unsigned int worktime;
    double salary;
    double tax_money;
    double your_money;

    printf("*************************************\n\n");
    printf("Enter the number corresponding to the desired pay rate or action:\n\n");
    printf("1) $8.75/hr              2) $9.33/hr\n\n");        
    printf("3) 10.00/hr              4) $11.20/hr\n\n");
    printf("5) quit\n\n");
    printf("*************************************\n");

    while(scanf("%d",&num)){

        if(num == 5)
	    break;
        if(num > 5 || num ==0){

	printf("please enter the number between 1 and 5.\n");
        printf("*************************************\n\n");
        printf("Enter the number corresponding to the desired pay rate or action:\n\n");
        printf("1) $8.75/hr              2) $9.33/hr\n\n");
        printf("3) 10.00/hr              4) $11.20/hr\n\n");
        printf("5) quit\n\n");
        printf("*************************************\n");

	continue;
	}

        switch(num){

        case 1:
            BASIC_SALARY = 8.75;
            break;
        case 2:
	    BASIC_SALARY = 9.33;
	    break;
        case 3:
		BASIC_SALARY = 10.00;
		break;
        case 4:
	    BASIC_SALARY = 11.20;
	    break;
        }

        printf("请输入一周的工作时间：");
        scanf("%u", &worktime);

        if(worktime >= 40){

	    salary = (1.5 * worktime - 0.5 * WORKTIME_PER_WEEK) * BASIC_SALARY;

        }else{

	    salary = BASIC_SALARY * worktime;

        }   

        if(salary <= 300.0){

            tax_money =  LT_300 * salary;
            your_money = (1 - LT_300) * salary;   

        }else if(salary <= 450.0){

	    tax_money = LT_300 * 300 + (salary - 300) * T_F;
   	    your_money = (1 - LT_300) * 300 + (salary - 300) * (1 - T_F);

        }else{

	    tax_money = LT_300 * 300 + T_F * 150 + (salary - 450) * LT_450;
            your_money = (1- LT_300) * 300 + 150 * (1 - T_F) + (salary - 450) * (1- LT_450);

        }   

        printf("总额为：%f\n",salary);
        printf("税金为：%f\n",tax_money);
        printf("净收入为：%f\n\n",your_money);

    
        printf("*************************************\n\n");
        printf("Enter the number corresponding to the desired pay rate or action:\n\n");
        printf("1) $8.75/hr              2) $9.33/hr\n\n");
        printf("3) 10.00/hr              4) $11.20/hr\n\n");
        printf("5) quit\n\n");
        printf("*************************************\n");

    }

    return 0;

}
