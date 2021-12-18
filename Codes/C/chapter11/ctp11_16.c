#include <stdio.h>
#include <string.h>

char *myupper(char *);
char *mylower(char *);

int main(int argc, char *argv[]){

    if(!strcmp(argv[1],"-p")){
        fputs(argv[2],stdout);
    }else if(!strcmp(argv[1],"-u")){
        fputs(myupper(argv[2]),stdout);
    }else if(!strcmp(argv[1],"-l")){
        fputs(mylower(argv[2]),stdout);
    }else{	    
        fputs(argv[1],stdout);
    }
    return 0;
}

char* myupper(char * ptr){

    char * p = ptr;

    while(*p){

	*p = toupper(*p);
	p++;

    }

    return ptr;

}

char* mylower(char * ptr){

    char *p = ptr;

    while(*p){

        *p = tolower(*p);
	p++;
    }

    return ptr;

}

