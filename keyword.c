#define MAX_NAME 30

struct keytab{
	int nums;			
	char name[MAX_NAME];
};

struct keytab keywrds[13] = {
	{0, "int"}, {0, "float"}, {0, "return"}, {0, "if"}, {0, "for"},
	{0, "while"}, {0, "goto"}, {0, "switch"}, {0, "case"},
	{0, "void"}, {0, "default"}, {0, "char"}, {0, "do"}
};

void count_word(char *word){
	int i;
	
	for(i=0; i<13; i++){
		if(strncmp(word, keywrds[i].name, strlen(keywrds[i].name)) == 0)
			keywrds[i].nums++;
	}
}

void print_word(){
	int i;
	
	for(i=0; i<13; i++)
		printf("%s : %d\n", keywrds[i].name, keywrds[i].nums);
}
