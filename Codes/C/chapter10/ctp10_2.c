#include <stdio.h>

void copy_arr(double [], double [] , int);
void copy_ptr(double [], double [], int);
void copy_ptrs(double [], double [], double []);

int main(void){

    int i;

    double source[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
    double target1[5];
    double target2[5];
    double target3[5];

    copy_arr(target1, source, 5);
    copy_ptr(target2, source, 5);
    copy_ptrs(target3, source, source + 5);

    for(i = 0; i < 5; i++){

	printf("%.1f %.1f %.1f\n",target1[i],target2[i],target3[i]);

    }

    return 0;
}

void copy_arr(double target[], double source[], int n){

    while(n-- > 0){
	
	target[n] = source[n];

    }

}

void copy_ptr(double target[],double source[],int n){

    while(n-- > 0){

	*(target + n) = *(source + n);

    }

}
void copy_ptrs(double target[],double source[],double source5[]){

    do{

        *target = *source;
 	target++;
	source++;
	
    }while(source < source5);


}
