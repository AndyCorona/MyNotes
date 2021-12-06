#include <stdio.h>

int main(void){

    //$ 的 ASCII 编码
    char dollar = 36;
    int i;
    int j;

    for(i = 0; i < 5; i++){

        for(j = 0; j < i + 1; j++){
		
	    printf("%c",dollar);
        }

	printf("\n");
    } 


    return 0;

}
