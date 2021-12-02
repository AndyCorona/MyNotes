#include <stdio.h>

int main(void){

    float temp;

    printf("Enter a floating-point value: ");
    scanf("%f",&temp);
    printf("fixed-point notation: %f\n",temp);
    printf("exponential notation: %e\n",temp);
    printf("p notation: %a\n",temp);

    return 0;
}
