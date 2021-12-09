#include <stdio.h>

int main(void){

    char character;
    int count_lower = 0;
    int count_upper = 0;


    while((character = getchar()) != EOF){

	if(character > 64 && character < 91){
	
	    count_upper++;

	}

	if(character > 96 && character < 123){

	    count_lower++;

	}

    }

    printf("大写字母个数：%d\n小写字母个数：%d\n",count_upper,count_lower);

    return 0;

}
