#include <stdio.h>

int main(void){

    char temp;
    unsigned int count_replace;


    while((temp = getchar()) != '#'){

	switch(temp){

	    case '.':
		putchar('!');
		count_replace++;
		break;
	    case '!':
		printf("!!");
		count_replace++;
		break;
	    default:
		putchar(temp);
		break;
	}

    }

    printf("替换了 %u 次\n",count_replace);

    return 0;

}
