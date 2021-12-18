#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 41

int main(void){
    FILE *fp;
    int num = 0; //单词编号
    char words[MAX];
    int ch;
    if ((fp = fopen("wordy", "a+")) == NULL){
	fprintf(stdout, "Can't open \"wordy\" file.\n");
	exit(EXIT_FAILURE);
    }
    
    rewind(fp);//返回至文件开头
    while((ch=getc(fp))!= EOF){
	if(ch == '\n')
	   num++; //根据换行符得到单词编号
    }
    
    fseek(fp,0L,SEEK_END);//返回文件末尾前一个字符

    puts("Enter words to add to the file; press the #");
    puts("key at the beginning of a line to terminate.");
    while ((fscanf(stdin, "%40s", words) == 1) && (words[0] != '#'))
	fprintf(fp, "%d:%s\n",++num,words);
    puts("File contents:");
    rewind(fp); /* 返回到文件开始处 */
    while (fscanf(fp, "%s", words) == 1)
	puts(words);
    puts("Done!");
    if (fclose(fp) != 0)
	fprintf(stderr, "Error closing file\n");
    return 0;
}

