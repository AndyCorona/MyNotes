#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define SIZE 40 //文件名长度


int main(void){

    char filename[SIZE]; //存放文件名
    FILE * src,* dest; //读写文件的指针
    int ch;     

    fprintf(stdout,"Enter the filename:\n"); 
    while(fscanf(stdin,"%s",filename) == EOF){

	fprintf(stderr,"no filename");
 	exit(EXIT_FAILURE);

    }

    while((src=fopen(filename,"r")) ==NULL || (dest = fopen(filename,"r+")) == NULL){

	fprintf(stderr,"Can't open %s",filename);

    }

    while((ch=getc(src)) !=EOF){

        ch=toupper(ch);
	putc(ch,dest);

    }

    while(fclose(src) !=0 || fclose(dest)!= 0)
        fprintf(stderr,"Error in closing file\n");    

    return 0;
}
