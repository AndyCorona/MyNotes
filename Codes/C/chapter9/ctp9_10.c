#include <stdio.h>

void to_base_m(unsigned long n,unsigned int m);

int main(void){

    unsigned long number;
    unsigned int m;
    printf("Enter an integer and base (q to quit):\n");
    while (scanf("%lu %u", &number,&m) == 2){
	printf("%u system equivalent: ",m);
	to_base_m(number,m);
	putchar('\n');
	printf("Enter an integer and base (q to quit):\n");
    }
    printf("Done.\n");
    return 0;
}

//打印 n 的 m 进制表示法
void to_base_m(unsigned long n,unsigned int m){

    if(m < 2 || m >10){

	printf("Sorry, base only between 2 and 10 supported");
	return;
    }

    int r;
    r = n % m;
    if (n >= m)
	to_base_m(n / m,m);
    
    switch(r){

	case 0:
	    putchar('0');
	    break;
        case 1:
            putchar('1');
            break;
        case 2:
            putchar('2');
            break;
        case 3:
            putchar('3');
            break;
        case 4:
            putchar('4');
            break;
        case 5:
            putchar('5');
            break;
        case 6:
            putchar('6');
            break;
        case 7:
            putchar('7');
            break;
        case 8:
            putchar('8');
            break;
        case 9:
            putchar('9');
            break;
    }    

    return;
}
