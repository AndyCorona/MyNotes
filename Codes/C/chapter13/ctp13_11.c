#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 40
#define SIZE 255
int main(int argc, char * argv[]){

    char *string; //存储字符串
    char buff[SIZE];
    FILE * fp;    

    if(argc < 3){

	fprintf(stderr,"Usage:%s[string][filename]",argv[0]);
	exit(EXIT_FAILURE);

    }

    if((fp = fopen(argv[2],"r")) == NULL){

	fprintf(stderr,"Can't open file %s",argv[2]);
 	exit(EXIT_FAILURE);

    }
    
    string  = argv[1];
    while((fgets(buff,255,fp)) != NULL){

	if(strstr(buff,string) != NULL)
	
	    fprintf(stdout,"%s\n",buff);	    
	
    }

    return 0;

}
