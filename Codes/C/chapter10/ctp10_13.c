#include <stdio.h>

#define ROW 3
#define COLUMN 5

void combine(const double *, const double *, const double *,double (*p)[COLUMN]);
double average(const double *);
double total_average(double (*p)[5]);
double max_num(double (*p)[5]);

int main(void){

    int i;
    int j;
    const double arr1[COLUMN] = {1.3,4.2,1.7,6.7,8.1};
    const double arr2[COLUMN] = {8.4,3.6,2.7,13.5,2.7};
    const double arr3[COLUMN] = {6.7,8.5,3.6,4.2,8.5};
    double com[ROW][COLUMN];
    combine(arr1,arr2,arr3,com);

    for(i = 0; i < ROW; i ++){

	for(j = 0; j < COLUMN; j++){

	    printf("%.2f ",com[i][j]);
	}
	putchar('\n');
    }

    

    printf("arr1_average:%.2f\n",average(arr1));
    printf("arr2_average:%.2f\n",average(arr2));
    printf("arr3_average:%.2f\n",average(arr3));
    printf("total_average:%.2f\n",total_average(com));
    printf("max_num:%.2f\n",max_num(com));

    return 0;
}

//将三个一维数组合并成一个二维数组
void combine(const double * ptr1, const double * ptr2, const double * ptr3, double (*ptr4)[COLUMN]){

    int i;
    int j;
 
    for(j = 0; j < COLUMN; j++){

        *(*(ptr4 + 0) + j) = *(ptr1 + j);
        *(*(ptr4 + 1) + j) = *(ptr2 + j);
	*(*(ptr4 + 2) + j) = *(ptr3 + j);
    }

}


double average(const double * ptr){

    int i;
    double sum;
    for(i = 0,sum = 0.0; i < COLUMN; i++){

	sum += *(ptr + i);

    }  

    return sum / COLUMN;
}

double total_average(double (*p)[5]){

    double sum;
    int i,j;

    for(i = 0,sum = 0.0; i < ROW; i++){

	for(j = 0; j < COLUMN; j++){

	    sum += *(*(p + i) + j);
	}
    }

    return sum / (ROW*COLUMN);

}

double max_num(double (*p)[5]){

    double max = 0.0;
    int i,j;

    for(i = 0; i < ROW; i++){

	for(j = 0; j < COLUMN; j++){
	    if(max < *(*(p + i) + j)){

                max = *(*(p + i) + j);
            }
        }
    }

    return max;

}







