#include <stdio.h>

int main(void){

    int i;
    int j;

    //储存用户输入的大写字母
    char character;
    char A;

    printf("请输入一个大写字母：");
    scanf("%c",&character);

    //根据用户输入决定外层循环次数
    int temp = character - 'A';
          
    for(i = 0 ; i <= temp; i ++){

	A = 65;
		
	//输出 A 到 character 
        for(j = 0; j < i + 1; j++){
	    
	    printf("%c", A++);
	}

	A--;

	// character - 1 到 A
	for(j = 0; j < i; j++){

	    printf("%c",--A);

	}
	 
	printf("\n");

    } 

    return 0;
}
