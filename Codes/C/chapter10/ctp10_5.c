#include <stdio.h>

double diff_max_min(const double *,const double *);

int main(void){

    double arr[5] = {11.43, 11.35, 2.34, 28.34,99.24};
    printf("Diff in max to min:%.2f\n",diff_max_min(arr,arr+5));

    return 0;
}

double diff_max_min(const double * start, const double * end){

    double max_num = *start;
    double min_num = *start;

    while(++start < end){

	if(max_num < *start)
	    max_num = *start;
	if(min_num > *start)
	    min_num = *start;
    }

    return max_num - min_num;
}
