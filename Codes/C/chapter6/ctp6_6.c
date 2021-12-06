#include <stdio.h>

//返回整数平方
int square(int n);

//返回整数立方
int cubed(int n);

int main(void){

    //表格行数最小值
    int min;
    
    //表格行数最大值
    int max;

    int i;

    printf("请输入表格行数最小值：");
    scanf("%d",&min);
    printf("请输入表格行数最大值：");
    scanf("%d",&max);
    
    for(i = min; i < max; i++){

        printf("%d %d %d\n",i,square(i),cubed(i));
   
    }  

    return 0;

}


int square(int number){
 
   return number * number;
}

int cubed(int number){

    return number * number * number;

}
