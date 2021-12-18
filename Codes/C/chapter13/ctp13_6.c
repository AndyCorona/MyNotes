#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN 40

int main(void){

    FILE *in,*out;
    int ch;
    char src[LEN];
    char dest[LEN];
    int count = 0;
    puts("enter filename:");
    while(fscanf(stdin,"%s",src) == EOF){

	fprintf(stderr,"no filename\n");
	exit(EXIT_FAILURE);

    }


    if((in = fopen(src,"r")) == NULL){

	fprintf(stderr,"Can't open the file %s\n",src);
	exit(EXIT_FAILURE);
    }

    strncpy(dest,src,LEN-5);
    dest[LEN-5] = '\0';
    strcat(dest,".red");
    if((out = fopen(dest,"w")) == NULL){

	fprintf(stderr,"Can't create output file.\n");
        exit(3);

    }

    while((ch = getc(in)) != EOF){

	if(count++ %3 == 0)
	    putc(ch,out);

    }

    if(fclose(in) != 0 || fclose(out) !=0)
	fprintf(stderr,"Error in closing files\n");
    return 0;
}
