#include <stdio.h>
#include <ctype.h>

char *func(char *arr,int);

int main(void){

    char arr[10];
    char * ptr;

    ptr = func(arr,3);
    puts(ptr);

    return 0;
}

char *func(char *arr,int n){

    int temp;
    int is_start = 0;

    char * ptr;
    ptr = arr;

    while(temp = getchar()){
		
	//控制读取次数
	if(--n < 0)
	   break;	

	//空格和制表符	
	if(isblank(temp)){

	    //忽略第一个单词前面的空白字符
	    if(!is_start){
		
		//不计第一个单词前面的空白符读取次数
          	n++;
		continue;
		
	    }else{

	        break;

            }

	//换行符退出
	}else if(temp == '\n'){
	
	    break;

        }else{
	    //开始读取第一个单词
	    is_start = 1;
 	    *ptr = temp;
	    ptr++;
	}

    }

    *ptr = '\0';

    return arr;
      
}

