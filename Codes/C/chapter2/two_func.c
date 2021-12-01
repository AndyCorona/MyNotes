//一个文件中包含两个函数
#include <stdio.h>

void butler(void); /*函数原型*/

int main(void){

    printf("I will summon the butler function.\n");
    butler();
    printf("Yes. Bring me some tea and writable DVDs.\n");
    
    return 0;
}

void butler(void){ /*定义函数*/

    printf("You rang, sir?\n");
}
   
