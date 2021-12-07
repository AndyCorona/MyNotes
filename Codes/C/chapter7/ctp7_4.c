#include <stdio.h>

int main(void){

    char temp;
    unsigned int count_replace;


    while((temp = getchar()) != '#'){

	if(temp == '.'){

	    putchar('!');
	    count_replace++;

        }else if( temp == '!'){

	    printf("!!");
	    count_replace++;

	}else{

	    putchar(temp);

	}

    }

    printf("替换了 %u 次\n",count_replace);

    return 0;

}
