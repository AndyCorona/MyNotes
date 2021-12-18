#include <stdio.h>

int func();

int main(void){

    int i;
    int count;
    for(i = 0; i < 100; i++)
        count = func();

    printf("%d\n",count);

    printf("%d\n",func());

    return 0;
}


int func(void){

    static int count;
    count++;
    return count;

}
