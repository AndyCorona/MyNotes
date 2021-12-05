#include <stdio.h>

int main(void){

    const int DAY_PER_WEEK = 7;    
    int day;
    int week;

    printf("请输入天数：");
    scanf("%d", &day);

    while(day > 0){

        week = day / DAY_PER_WEEK;
        day = day % DAY_PER_WEEK;
        printf("%d days are %d weeks, %d days.\n",week * 7 + day, week,day);
	printf("请输入天数：");
	scanf("%d",&day);
    }

    return 0;

}
