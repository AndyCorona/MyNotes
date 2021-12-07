#include <stdio.h>

int main(void){

    char temp;
    int i;


    while((temp = getchar()) != '#'){

	putchar(temp);
        printf("  %u ",temp);
	i++;

	if(i %8 == 0){

	    putchar('\n');
        }

    }

    putchar('\n');
  
    return 0;

}
