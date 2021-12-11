#include <stdio.h>
#define ROW 3
#define COLUMN 5

void print_arr(int (*p)[COLUMN], int n);
void double_arr(int (*p)[COLUMN], int n);

int main(void){

    int i;

    int arr[ROW][COLUMN] = {{1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15}};

        print_arr(arr,ROW);
        double_arr(arr,ROW);
	print_arr(arr,ROW);

    return 0;


}

void print_arr(int (*ptr)[COLUMN], int n){

    int i;
    int j;
 
    for(i = 0; i < n; i++){
	for(j = 0;j < COLUMN;j++){
    
            printf("%d ",*(*(ptr + i) + j));
	
        }
    }
}

void double_arr(int (*ptr)[COLUMN], int n){

    int i;
    int j; 
   
    for(i = 0; i < n; i++){
	for(j = 0; j < COLUMN;j++){

            *(*(ptr+i) + j) *= 2;
        }
    }

}
