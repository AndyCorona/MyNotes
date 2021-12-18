#include <stdio.h>

char *func(const char *, char);

int main(int argc, char *argv[]){

    const char arr[] = "hello,world!";
    int ch; 

    for(ch = 0; ch < 128; ch++){

        char *result = func(arr,ch);

        if(result){
	
	    printf("found! %c\n",*result);	

        }else{

	    puts("not found");

        }   
    }

    return 0;
}

char *func(const char * target, char ch){

    int i = 0;
    char * ptr;
    ptr = target;

     while(*ptr){

	if(*ptr == ch){

	    return ptr + i;

	}else{
	    ptr++;
	    continue;
	
	}

    }

    return NULL;

}

