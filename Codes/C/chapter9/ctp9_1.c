#include <stdio.h>

double min(double,double);

int main(void){


    printf("%f\n", min(10.0,10.5));

    return 0;

}


double min(double x, double y){

    return (x > y)? x : y;
}
