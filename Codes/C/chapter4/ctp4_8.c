#include <stdio.h>
//1 英里/加仑转为 235.239 升/100公里
#define ratio 235.239

int main(){

    //行驶的里程数，单位英里
    float mile;
    //消耗的汽油量，单位加仑
    float gallon;
    //消耗每加仑汽油行驶的英里数
    float unit;

    printf("Please input mile:");
    scanf("%f",&mile);
    printf("Pleasd input gallon cosumed:");    
    scanf("%f",&gallon);
    
    unit = mile/gallon;
    printf("the mile per gallon is:%0.1f\n",unit);
    printf("the liter per 100 kilometer is:%0.1f\n",unit * ratio);

    return 0;
}
