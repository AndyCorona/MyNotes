#include <stdio.h>
#include <ctype.h>

int main(void){

    char num;
    unsigned int odd_count = 0;
    unsigned int even_count = 0;
    double odd_sum = 0.0;
    double even_sum = 0.0;

    num = getchar();
   
    while(isdigit(num)){ //判断是否为字符 1-9

	if(num == '0') //字符 '0' 退出循环
            break;

        if(num % 2 == 0){ //偶数字符
 	    even_count++;
	    even_sum += num - 48; //数字字符转为对应的数字，如 '1' 转为 1

        }else { //奇数字符

	    odd_count++;
	    odd_sum += num - 48;
	}

        num = getchar();
    }

    printf("奇数个数：%d ",odd_count);
    printf("奇数平均值：%f\n",odd_sum / odd_count);
    printf("偶数个数：%d ",even_count);
    printf("偶数平均值：%f\n",even_sum / even_count);

    return 0;
}
