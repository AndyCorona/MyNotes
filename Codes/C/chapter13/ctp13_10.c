#include <stdio.h>
#include <stdlib.h>
#define LEN 40

int main(void){

    char filename[LEN];
    int position;
    FILE * fp;
    int ch;
 
    puts("Enter the filename:");
    if(fscanf(stdin,"%s",filename) < 0){

	fprintf(stderr,"need filename\n");
	exit(EXIT_FAILURE);

    }

    puts("Enter a position start");
    if(scanf("%d",&position) < 1 || position <0){

	exit(EXIT_FAILURE);

    }

    if((fp = fopen(filename,"r")) == NULL){

	fprintf(stderr,"Can't open file %s",filename);
	exit(EXIT_FAILURE);
    }

    fseek(fp,position,SEEK_SET); //从当前文件开始处，往前偏移 position 个字节
    while((ch = getc(fp)) !='\n'){

	putc(ch,stdout);

    }

    return 0;
}
