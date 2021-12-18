#include <stdio.h>

char*func(char *);

int main(void){

char arr[] = "hello";
puts(func(arr));

}

char *func(char * arr){
arr++;

return arr;


}
