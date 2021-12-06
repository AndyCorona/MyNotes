#include <stdio.h>

int main(void){

    int i;
    int j;

    //A 的 ASCII 编码
    char character = 65;


    for(i = 0; i < 6; i++){
	
	for(j = 0; j < i + 1; j++){
	
	    printf("%c",character++); 
	    
	}

	printf("\n");
    }

    return 0;

}
