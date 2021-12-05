#include <stdio.h>
#define INCHES_PER_FEET 12.0
#define CM_TO_INCHES 0.3937

int main(void){

    float height;
    int feet;
    float inches;
    
    printf("Enter a height in centimeters: ");
    scanf("%f",&height);

    while(height > 0){
	
	feet = height * CM_TO_INCHES / INCHES_PER_FEET;
	inches = height * CM_TO_INCHES - feet * INCHES_PER_FEET;

	printf("%0.1f cm = %d feet, %0.1f inches\n", height,feet,inches);
	printf("Enter a height in centimeters (<=0 to quit): ");
	scanf("%f",&height);
    }

    printf("bye\n");

    return 0;
}
