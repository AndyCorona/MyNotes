#include <stdio.h>
#include <stdlib.h>
#define SIZE 40

int main(int argc, char * argv[]){

    FILE * fp;
    char buff[SIZE];
    int i;
    int ch;
    for(i = 0; i < argc-1;i++){

	if((fp = fopen(argv[i+1],"r")) == NULL){
	    fprintf(stderr,"Can't open %s",argv[i+1]);
	    exit(EXIT_FAILURE);
	}
	
	while((ch=getc(fp))!=EOF){

	    putc(ch,stdout);

	}
	
	if(fclose(fp)!=0){

	    fprintf(stderr,"Can't closing file\n");
	}

    }

    return 0;
}

