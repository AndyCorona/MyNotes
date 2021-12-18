#include <stdio.h>
#include <string.h>

char *func(char *);

int main(void){

    char arr[40];

    puts("请输入一个字符串：");
    while(fgets(arr,40,stdin)){

	fputs("原始字符串:",stdout);
	puts(arr);
	fputs("删除空格之后:",stdout);
	puts(func(arr));
    } 

    return 0;


}

char *func(char * arr){

    char * ptr = arr;
    int i = 0;


    while(*ptr){
	
	if(*ptr == ' '){
	    ptr++;
        }else{
	    *(arr + i) = *ptr++;
	    i++;
        }
    }
    arr[i] = '\0';
    return arr;

}
