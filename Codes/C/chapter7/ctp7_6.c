#include <stdio.h>

int main(void){

    unsigned char current_char;
    unsigned char pre_char;
    unsigned int count_ei;

    while((current_char = getchar()) != '#'){ //一直读取到 # 为止

	if(pre_char == 'e' && current_char == 'i'){

	    count_ei++;

	}

	pre_char = current_char;

    }

    printf("ei 出现了 %u 次\n", count_ei);

    return 0;

}
