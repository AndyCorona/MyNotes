#include <stdio.h>

int main(void){

    unsigned int space_count = 0;
    unsigned int line_count = 0;
    unsigned int char_count = 0; 
    char temp;

    temp = getchar();

    while(temp != '#'){

        switch(temp){
	    case ' ':
	        space_count++;
	        break;
	    case '\n':
	        line_count++;
	        break;
	    default:
	        char_count++;
	        break;
	}
	
	temp = getchar();
    }

    printf("空格个数：%u\n",space_count);
    printf("换行符个数：%u\n",line_count);
    printf("字符个数：%u\n",char_count);
    return 0;

}
