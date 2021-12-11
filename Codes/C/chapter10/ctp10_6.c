#include <stdio.h>

void reverse(double *,int);

int main(void){

    int i;
    double arr[5] = {1.4,2.5,3.6,4.7,5.8};   
    reverse(arr,5);
    for(i = 0; i < 5; i++){

	printf("%.1f ",arr[i]);

    }
    putchar('\n');

    return 0;
}

void reverse(double * arr, int n){

    int i;
    double temp;

    //arr[0] 和 arr[4]，arr[1] 和 arr[3] 互换位置
    for(i = 0; i < n/2; i++){

	temp = *(arr + i);
	*(arr + i) = *(arr + n -1 - i);
	*(arr + n -1 -i) = temp;
    }

}
