#include <stdio.h>

int main(int argc, char * argv[]){

    int i;
    for(i = argc; i > 1; i--){

	printf("%s ",argv[i-1]);

    }

    return 0;
}
