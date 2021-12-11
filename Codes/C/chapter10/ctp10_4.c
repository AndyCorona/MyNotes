#include <stdio.h>

int max(const double *, int);

int main(void){

    double arr[10] = {1.32,3.65,54.23,1.52,46.13,2.74,21.12,34.41,1.62,87.13};
    int max_index = max(arr,10);
    printf("Max index:%d",max_index);

    return 0;
}

int max(const double * start, int n){

    //获取数组首元素值
    double max_num = *start;
    int index = 0;

    while(n > 0){
	
	if(max_num < *(start +  n)){
	    max_num = *(start + n);
	    index = n;
        }
	n--;
    }   

    return index;  

}
