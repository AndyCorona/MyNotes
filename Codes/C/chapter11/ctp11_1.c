#include <stdio.h>
#include <string.h>

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

	if(temp = getchar()){

	    arr[i] = temp;

	}else{

	    break;	

	}
		
    }
    arr[i] = '\0';	
    return arr;
}
