#include <stdio.h>

int main(void){

    unsigned int number_of_char;   

    //统计文件中字符数，包括回车换行符
    while(getchar() != EOF){

	number_of_char++;

    }
    
    printf("文件总字符数: %u\n", number_of_char);

    return 0;
}
