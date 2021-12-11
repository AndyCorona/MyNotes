#include <stdio.h>

void sum_arr(const int *, const int *, int *, int);

int main(void){

    int i;
    int arr1[4] = {2,4,5,8};
    int arr2[4] = {1,0,4,6};
    int arr3[4];

    sum_arr(arr1,arr2,arr3,4);

    for(i = 0;i<4;i++){

	printf("%d ",arr3[i]);

    }
 
    return 0;

}

void sum_arr(const int * ptr1, const int * ptr2, int * ptr3, int n){

    int i;
    for(i = 0 ;i < n; i++){

	*(ptr3 + i) = *(ptr1 +i) + *(ptr2+ i);	

    }

}
