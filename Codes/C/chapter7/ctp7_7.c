#include <stdio.h>
#define BASIC_SALARY 1000
#define WORKTIME_PER_WEEK 40
#define LT_300 0.15
#define T_F 0.20
#define LT_450 0.25 

int main(void){

    unsigned int worktime;
    double salary;
    double tax_money;
    double your_money;


    printf("请输入一周工作时间：");
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
    printf("净收入为：%f\n",your_money);

    return 0;

}
