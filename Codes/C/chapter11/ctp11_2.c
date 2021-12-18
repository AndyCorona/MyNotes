#include <stdio.h>
#include <string.h>
#include <ctype.h>

char *func(char*,int);

int main(void){

    int n = 5;

    char arr[10];
    int m = 5;
    func(arr,n);
    puts(arr);

    
    return 0;
}

char * func(char *arr,int n){

    int i;
    int temp;
    
    for(i = 0; i < n; i++){

	temp = getchar();

	if(temp && !isblank(temp) && temp !='\n'){

	    arr[i] = temp;

	}else{

	    break;	

	}
		
    }
    arr[i] = '\0';	
    return arr;
}
