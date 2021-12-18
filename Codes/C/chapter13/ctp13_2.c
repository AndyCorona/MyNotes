#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[]){

    FILE * target,*src;
    char buff[40];
    size_t count;

    while(argc != 3){
 	printf("Usage:%s src target\n",argv[0]);
	exit(EXIT_FAILURE);

    }
	
    while((src = fopen(argv[1],"rb")) == NULL){

	printf("Can't open %s\n",argv[1]);
	exit(EXIT_FAILURE);
    }

    while((target = fopen(argv[2],"wb")) == NULL){

	printf("Can't open %s\n",argv[2]);
	exit(EXIT_FAILURE);
    }

    while((count = fread(buff,sizeof(char),40,src)) > 0){

	fwrite(buff,sizeof(char),count,target);

    }

    if(fclose(target) !=0 || fclose(src)!=0)
        fprintf(stderr,"Error in closing file\n");    

    return 0;
}
