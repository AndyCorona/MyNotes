#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
 
int main(void)
{
    int n,i,k,j;
    printf("How many words do you wish to enter?");
    scanf("%d", &n);
    printf("Enter 5 words now: ");
    char **a = (char**)malloc(n * sizeof(char*));
    for (i = 0; i < n; ++i) {
        char b[100];
        scanf("%s", b);
        int n = strlen(b);
        char* str = (char*)malloc(n * sizeof(char));
        for (j = 0; j < n; ++j) {
            str[j] = b[j];
        }
        a[i] = str;
    }
    for (k = 0; k < n; ++k) {
        puts(a[k]);
    }
    return 0;
}
