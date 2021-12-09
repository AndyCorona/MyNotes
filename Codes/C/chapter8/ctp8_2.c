#include <stdio.h>

int main(void){

    char character;

    while((character = getchar()) != EOF){
    
	if(character > 32){

            putchar(character);
	    printf(" %d\n",character);

	}else{

	    printf("^%c %d\n", character + 64, character);

        }

    }

    return 0;

}
