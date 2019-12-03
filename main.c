#include <stdio.h>
#include <stdlib.h>
#include "keyword.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

//Lab02
int fget_word(FILE *fp, char *word);
int is_whitespace(char c);

int main(int argc, char *argv[]){
	FILE *fp;
	char filepath[100];
	char word[100];
	
	//file open
	printf("input the filepath : ");
	scanf("%s",filepath);
	fp = fopen(filepath, "r");
	
	if(fp == NULL){
		printf("filepath is wrong!\n");
		return -1;
	}
	while(fget_word(fp, word)){
		count_word(word);
		//printf("%s\n",word);
	}
	//output
	print_word();
	fclose(fp);
	
	return 0;
}

int is_whitespace(char c){
	if((c == ' ') || (c == '\n') || (c == '\r') || (c == '\t') || (c == '('))
		return 1;
	else
		return 0;
}

int fget_word(FILE *fp, char* word){
	char c;
	int cnt;
	
	while((c=fgetc(fp))!=EOF){
		if(is_whitespace(c) == 0)
			break;
	}
	if (c == EOF)
		return 0;
	cnt = 0;
	word[cnt++] = c;
	word[cnt]='\0';
	
	while((word[cnt]=fgetc(fp))!=EOF){
		if(is_whitespace(word[cnt]) == 1){
			word[cnt] = '\0';
			break;
		}
		cnt++;
	}
	return cnt;
}
