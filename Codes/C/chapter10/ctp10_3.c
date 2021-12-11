#include <stdio.h>

//对数组排序，无需更改数组内容，加 const
int max(const int *,const int *);

int main(void){

    int arr[10] = {4,23,12,54,3,1,1,3,43,1};
    int max_num;
    max_num = max(arr,arr + 10);
    printf("Maximum:%d",max_num);
   
    return 0;
}

int max(const int * start, const int * end){

    //获取数组首元素的值
    int max_num = *start;

    //超过数组长度则停止比较
    while(++start < end){
    
        if(max_num < *start)
            max_num = *start;

   }

    return max_num;

}
