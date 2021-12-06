#include <stdio.h>

int main(void){

    int i;
    int j;
  
    for(i = 0; i < 6; i++){
    
        //F 的 ASCII 编码  
        char character = 70;
         
	for(j = 0; j < i + 1; j++){

	    printf("%c", character--);
        }

        printf("\n");
    }
    



}
