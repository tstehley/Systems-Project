#include<stdio.h>
#include<string.h>
#define MSTR 64
int main (int argc, char *argv[]){
	if(argc < 2){
		printf("No input file provided.");
	}
	if(argc <3){
		printf("No pattern provided.");
		return 1;
	}
	FILE *cat;
	FILE *grep;
	char lines[MSTR];
	char catstr[MSTR] ="cat ";
	char grepstr[MSTR]="grep -w ";
	strcat(catstr, argv[1]);
	strcat(grepstr,argv[2]);
	printf("Piping %s into %s \n",catstr,grepstr);
	return 0;
}
