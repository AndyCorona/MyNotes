#include <stdio.h>

void chline(char,int,int);

int main(void){

    chline('*',10,6);

    return 0;

}


//打印指定字符 j 行 i 列
void chline(char ch, int i, int j){

    int temp;
    while(j-- > 0){
	
	temp = i;

	while(temp-- > 0){
	
	    putchar(ch);

	}
	putchar('\n');
    }
}
