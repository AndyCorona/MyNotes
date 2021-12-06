#include <stdio.h>

//邓巴数
#define DUNBAR 150

int main(void){

    int friends = 5;
    int i = 0;

    while(friends <= DUNBAR){
    
	friends = (friends - 1) * 2;
	i++;
	printf("第%d周，共有%d个朋友\n",i,friends);
    }
	
    return 0;

}
