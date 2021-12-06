#include <stdio.h>

int main(void){

    int i = 1;

    double Daphne = 100.0;
    double Deirdre = 100.0;

    do{
    
        Daphne += 10.0;
        Deirdre = Deirdre * 1.05;   
        i++;

    }while(Daphne >= Deirdre);

    printf("经过 %d 年，复利回报超过单利回报\n", i--);

    return 0;
}

