#include <stdio.h>

int main(void){
    
    int times;
    int i;
    int j = -1;
    double psum;
    double nsum;

    printf("请输入次数：");
    scanf("%d",&times);
    
    while(times > 0){

	psum = 0.0;
        nsum = 0.0;

        for(i = 1; i <= times; i++){
	    		
	    psum += 1.0 / i;
	   // printf("%f\n",sum);
	   
        }

	printf("psum：%f\n",psum);

	for(i = 1; i <=times; i++){
      	    
	    j *= -1;
	    nsum +=  j * 1.0 / i;
	   // printf("%f\n",sum);
        }

	printf("收敛于：%f\n",nsum);


	printf("总和为：%f\n",psum + nsum);
	printf("请输入次数：");
 	scanf("%d",&times);
    }
	

    return 0;
}
