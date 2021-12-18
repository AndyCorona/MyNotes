#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[]){

    FILE * fp1,*fp2;
    int temp;

    if(argc < 3){

	fprintf(stderr,"Usage:%s [filename1][filename2]\n",argv[0]);
	exit(EXIT_FAILURE);

    }

    if((fp1 = fopen(argv[1],"r")) == NULL || (fp2 = fopen(argv[2],"r")) == NULL){

	fprintf(stderr,"Can't open file\n");
	exit(EXIT_FAILURE);
    }

    label:while((temp = getc(fp1))!= EOF){


        if(temp != '\n'){
	    
	    fprintf(stdout,"%c",temp);
	    continue;

	}

	while((temp = getc(fp2)) != EOF){

	    fprintf(stdout,"%c",temp);
	    if(temp != '\n')
		continue;
	    else
		goto label;
	}

    }

    if(fclose(fp1)!= 0 || fclose(fp2) != 0){

	fprintf(stderr,"Can't close file\n");

    }

    return 0;

}
