#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFSIZE 4096
#define SLEN 81
void append(FILE * source, FILE * dest);

int main(int argc, char * argv[]){

    FILE * fa, * fs; //fa 指向目标文件，fs 指向源文件
    int files = 0; //附加的文件数量
    char file_app[SLEN]; //目标文件名
    char file_src[SLEN]; //源文件名
    int ch;
    int i;

    if(argc <=3){

	printf("Uasge: %s[source][dest...]\n",argv[0]);
	exit(EXIT_FAILURE);

    }

    files = argc - 2;

    if((fa = fopen(argv[1],"a+")) == NULL){

	fprintf(stderr,"Can't open %s\n",argv[1]);
	exit(EXIT_FAILURE);	

    }

    if(setvbuf(fa,NULL,_IOFBF,BUFSIZE) != 0){
	fputs("Can't create input buff\n",stderr);
	exit(EXIT_FAILURE);
    }

    for(i=0; i < argc -2; i++){

	if(strcmp(argv[1],argv[i+2]) ==0)
	    fputs("Can't append file to itself\n",stderr);
	else if((fs =fopen(argv[i+2],"r")) == NULL)
	    fprintf(stderr,"Can't open %s",argv[i+2]);
	else{

	    if(setvbuf(fs,NULL,_IOFBF,BUFSIZE)!=0){
	
	  	fputs("Can't create input buff\n",stderr);
		continue;
	
	    }
	append(fs,fa);
	if(ferror(fs)!=0)
	    fprintf(stderr,"Error in reading file %s\n",argv[1]);
	if(ferror(fa)!=0)
	    fprintf(stderr,"Error in writing file %s\n",argv[i+2]);
	fclose(fs);
	printf("File %s appended.\n",argv[1]);
	printf("Next file is %s\n",argv[i+3]);

	}
    }
    printf("Done appending %d files appended.\n",files);
    rewind(fa);
    printf("%s contents:\n",argv[1]);
    while((ch = getc(fa))!= EOF)
	putchar(ch);
    puts("Done displaying.");
    fclose(fa);
    return 0;
}

void append(FILE * source,FILE * dest){

    size_t bytes;
    static char temp[BUFSIZE];
    while((bytes = fread(temp,sizeof(char),BUFSIZE,source))>0)
	fwrite(temp,sizeof(char),bytes,dest);
}











