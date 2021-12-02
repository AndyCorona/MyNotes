#include <stdio.h>

int main(void){

    void one_three(void);
    void two(void);

    printf("starting now:\n");
    one_three();
    two();
    printf("three\n");
    printf("done!\n");

    return 0;
}

void one_three(void){

    printf("one\n");
}
void two(void){

    printf("two\n");
}
