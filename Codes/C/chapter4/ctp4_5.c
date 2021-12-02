#include <stdio.h>

int main(){

    float rate;
    float size;

    printf("请输入下载速度(Mb/s):");
    scanf("%f",&rate);
    printf("请输入文件大小(MB):");
    scanf("%f",&size);

    // printf 中 \ 代表不中断的换行
    printf("At %0.2f megabits per second, a file of %0.2f megabytes\
    \ndownloads in %0.2f seconds.\n",rate,size,size * 8 / rate);

    return 0;
}


