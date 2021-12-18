#include <stdio.h>
#include <string.h>

char *string_in(const char *,const char*);

int main(void){

    const char dest[] = "imuompimopimpimpimp";
    const char src[] = "imp";
    char *ptr = string_in(dest,src);

    printf("%td\n",(ptr - dest));
    puts(ptr);

    return 0;


}

char *string_in(const char * dest,const char * src){


    int i,j;    
    char *ptr = dest;
    int is_match_all;

    for(i = 0; i < (strlen(dest) - strlen(src) + 1); i++){

	is_match_all =1;

	for(j = 0; j < strlen(src); j++){

	    if(src[j] != dest[i+j])
		is_match_all=0;

	}

	if(is_match_all == 1)
            return (ptr + i);
    }  

    return NULL;

}

