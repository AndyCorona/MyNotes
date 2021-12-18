#include <stdio.h>

int is_within(const char *, char);

int main(void){

    const char arr[] = "hello,world";
    int ch;

    for(ch = 0;ch < 128;ch++){

	printf("%c\n",is_within(arr,ch));

    }

    return 0;

}

int is_within(const char * dest,char ch){

    char * ptr = dest;

    while(*ptr){

        if(*ptr == ch)
	    return ch;
	else{
	
	    ptr++;	

 	}

    }

    return 0;

}
