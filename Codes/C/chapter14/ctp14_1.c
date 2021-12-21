#include <stdio.h>
#include <string.h>

struct month {

    char name[20];
    char abbrev[4];
    int days;
    char number[7];

};


struct month months[12] = {
    {"January","jan",30,"one"},
    { "February", "feb", 28, "two" },
    { "March", "mar", 31, "three" },
    { "April", "apr", 30, "four" },
    { "May", "may", 31, "five" },
    { "June", "jun", 30, "six" },
    { "July", "jul", 31, "seven" },
    { "August", "aug", 31, "eight" },
    { "September", "sep", 30, "nine" },
    { "October", "oct", 31, "ten" },
    { "November", "nov", 30, "eleven" },
    { "December", "dec", 31, "twelve" }

};

int main(void){
    
    char temp[7];
    int day;

    puts("Enter the numer:");
    if(scanf("%s",temp)==1){

	day = days(temp); 

    } 
    printf("%s %d\n",temp,day);

    return 0;
}

int days(char * pt){

    int total_day = 0;
    char temp[7];
    strcpy(temp,pt);

    if(!strcmp(temp,"one"))
	total_day = 30;
    else if(!strcmp(temp,"two"))
        total_day = 58;
    else if(!strcmp(temp,"three"))
        total_day = 89;
    else if(!strcmp(temp,"four"))
        total_day = 119;
    else if(!strcmp(temp,"five"))
        total_day = 150;
    else if(!strcmp(temp,"six"))
        total_day = 180;
    else if(!strcmp(temp,"seven"))
        total_day = 211;
    else if(!strcmp(temp,"eight"))
        total_day = 242;
    else if(!strcmp(temp,"nine"))
        total_day = 272;
    else if(!strcmp(temp,"ten"))
        total_day =303 ;
    else if(!strcmp(temp,"eleven"))
        total_day = 333;
    else if(!strcmp(temp,"twelve"))
        total_day = 364;
    else
  	;
	
    return total_day;

}
