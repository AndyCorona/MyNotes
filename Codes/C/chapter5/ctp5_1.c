#include <stdio.h>
#define MINUTE_PER_HOUR 60

int main(void){
    
    int minute;
    int hour;

    printf("请输入分钟数（整数）：");
    scanf("%d",&minute);    
    while(minute){
	
	hour = minute /  MINUTE_PER_HOUR;
	minute = minute % MINUTE_PER_HOUR;
	printf("%d 小时 %d 分钟\n",hour,minute);		
	printf("请输入分钟数（整数）：");
	scanf("%d",&minute);
    }

    return 0;
}
