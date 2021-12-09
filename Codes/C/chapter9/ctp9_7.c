#include <stdio.h>

int pos_char(char);

int main(void){

    char ch;
    int num;

    while((ch = getchar()) != EOF){

	num = pos_char(ch);
	if(num == -1){
	
	    printf("%c 不是字母\n",ch);

	}else{

	    printf("%c 是字母表中第 %d 个字母\n",ch,num);

	}

    }

}


int pos_char(char ch){

    //a-z 的 ASCII 码范围
    if(ch > 96 && ch < 123){

	return ch - 96;

    }
    //A-Z 的 ASCII 码范围
    else if(ch > 64 && ch <91){

	return ch - 64;

    }else{

	return -1;

    }
   
}
