#include <stdio.h>

int main(void){

    /*用户输入的杯数*/
    double cup;

    printf("请输出杯数:");
    scanf("%lf", &cup);

    /*一杯等于0.5品脱*/
    printf("对应的品脱为：%.2f\n",cup * 0.5 );
    /*一杯等于8盎司*/
    printf("对应的盎司为：%.2f\n",cup * 8.0 );
    /*一杯等于16汤勺*/
    printf("对应的汤勺为：%.2f\n",cup * 16);
    /*一杯等于48茶勺*/
    printf("对应的茶勺为：%.2f\n",cup * 48);

    return 0;
}
