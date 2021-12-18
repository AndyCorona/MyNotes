#include <stdio.h>
#include <stdlib.h>
#define LEN 40

int main(int argc, char * argv[]){

    FILE * fp; 
    int count = 0; //计算指定字符出现的次数
    char ch; //保存用户指定的字符
    int temp; //临时保存从文件或标准输入中获取的字符
    int i; //循环变量

    if(argc < 2){

	fprintf(stderr,"Uasge:%s[char][filename]\n",argv[0]);
	exit(EXIT_FAILURE);

    }

    //只获取第二个命令行字符串参数的第一个字符
    ch = argv[1][0];

    if(argc == 2){

	while(( temp = getc(stdin))!='\n'){

	    if(temp == ch)
		count++;

	}

	fprintf(stdout,"%c repeat %d times in keyboard input\n",ch,count);

    }else{

	for(i = 0; i < argc - 2; i++){
	    //第二个命令行之后的参数都是文件名
	    if((fp=fopen(argv[i+2],"r")) == NULL){
		fprintf(stderr,"Can't open file %s\n",argv[i+2]);
		continue;		
	    }

	    while((temp = getc(fp)) != EOF){

	 	if(temp == ch)
		    count++;

	    }

	    fprintf(stdout,"%c repeat %d times in %s\n",ch,count,argv[i+2]);

	}
	

    }

    return 0;
}
