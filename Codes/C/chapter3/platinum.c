#include <stdio.h>

int main(void){

    float weight;
    float value;

    printf("Are you worth your weight in platinum?\n");
    printf("Let's check it out.\n");
    printf("Please enter your weight in pounds: ");

    /*获取用户输入*/
    scanf("%f", &weight);

    value = 1700.0 * weight * 14.5833;
    printf("Your weight in plantinum is worth $%.2f.\n",value);
    printf("You are easilt worth that! If plantinum prices drop,\n");
    printf("eat more to maintain your value.\n");

    return 0;
}
