#include <stdio.h>

int main(void){

    int num[8];
    int i;
    int start = 1;
    int j = 0;

    for(i = 0; i < 8; i++){
 
	start *= 2;

        //给数组赋值为 2 的前 8 次幂
        num[i] = start;     
    } 

    do{

        printf("%d\n", num[j++]);

    }while(j < 8);

  
    return 0;

}
