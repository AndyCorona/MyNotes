#include <stdio.h>
#include <string.h>

int main(void){

    int i;
    char character[255];

    printf("请输入一句话：");
    scanf("%s",character);

    for(i = strlen(character); i >= 0; i--){

       printf("%c", character[i]);
	
    }

    return 0;

}
