#include <stdio.h>
void copy_arr(double *, double * , int);

int main(void){

    int i;
    int j;

    double source[3][2] = {{1.1, 2.2}, {3.3, 4.4}, {5.5,6.6}};
    double target[3][2];

    for(i = 0; i < 3; i++){

        copy_arr(target[i], source[i], 2);
    }

    for(i = 0; i <3; i++){

	for(j = 0;j < 2;j++){

            printf("%.1f ",source[i][j]);
	}
        putchar('\n');
    }

    return 0;
}

void copy_arr(double * target, double * source, int n){

    while(n-- > 0){
	
	target[n] = source[n];

    }

}

