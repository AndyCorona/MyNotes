#include <stdio.h>
#include <string.h>

char *reverse(char *);

int main(void){

    char arr[40];

    puts("请输入字符串：");
    while(fgets(arr,39,stdin)){
	puts(reverse(arr));	
    }

    return 0;


}

char * reverse(char * arr){

    int len = strlen(arr);
    int i;
    char temp;    

    for(i = 0; i < len /2; i++){

	temp = arr[i];
	arr[i] = arr[len -i-1];
 	arr[len-i-1] = temp;

    }

    return arr;

}


