#include <stdio.h>

void Temperatures(double temp);


int main(void){


    double temp;
    
    printf("请输入一个华氏温度：");
    int num = scanf("%lf",&temp);

    
    while(num == 1){
	
        Temperatures(temp);	
	printf("请输入一个华氏温度：");
        num = scanf("%lf",&temp);
    }
    return 0;
}

void Temperatures(double temp){
       
    printf("华氏度：%0.2f ",temp);
    printf("摄氏度：%0.2f ",5.0 / 9.0 * (temp - 32.0));
    printf("开氏度：%0.2f\n",5.0 / 9.0 * (temp - 32.0) + 273.16);

}
