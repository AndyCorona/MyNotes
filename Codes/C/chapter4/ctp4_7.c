#include <stdio.h>
#include <float.h>

int main(){

    double num1 = 1.0/3.0;
    float num2 = 1.0/3.0;

    printf("%0.6f\n",num1);
    printf("%0.12f\n",num1);
    printf("%0.16f\n",num1);
    printf("%0.6f\n",num2);
    printf("%0.12f\n",num2);
    printf("%0.16f\n",num2);
    printf("%d %d\n",FLT_DIG,DBL_DIG);
 
    return 0;
}
