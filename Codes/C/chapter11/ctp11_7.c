#include <stdio.h>
#include <string.h>

char *mystrncpy(char *,char*,int);
int main(void){

    char s1[20];
    char s2[] = "hello,world!";

    puts(mystrncpy(s1,s2,15));

    return 0;

}

char *mystrncpy(char *s1, char *s2,int n){

    int i;
    char * ptr = s1;
    int length = strlen(s2);

    for(i = 0; i < n; i++){
        s1[i] = s2[i];
    }

    if(n > length)
	s1[i] = '\0';	

    return ptr;

}
