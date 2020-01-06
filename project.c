#include<stdio.h>
#include<string.h>
#define MSTR 1024
int isCompressed(char instr[]){
	int len= strlen(instr);
	if(instr[(len-1)] == 'z' && instr[(len-2)] == 'g'){
		return(1);
	}else{
		return 0;
	}
}
int main (int argc, char *argv[]){
	/*Insures the necessary arguments are there*/
	if(argc < 2){
		printf("No input file provided.\n");
	}
	if(argc <3){
		printf("No pattern provided.\n");
		return 1;
	}
	FILE *cat;
	FILE *grep;
	/*Intermediate var used to connect*/
	char lines[MSTR];
	/*customizable command*/
	char catstr[MSTR]="";
	/*customizes commands to be run for arguments given*/
	if(isCompressed(argv[1]) == 1){
		strcat(catstr, "zcat ");
	}else{
		strcat(catstr,"cat ");
	}
	char grepstr[MSTR]="grep -w ";
	strcat(catstr, argv[1]);
	strcat(grepstr,argv[2]);
	/*printf("Piping %s into %s \n",catstr,grepstr);*/
	/*read from cat - open stream to be reas*/
	if(!(cat = popen(catstr,"r"))){
		printf("Error catting file\n");
		return 1;	
	}
	/*write to grep, open to stream*/
	if(!(grep = popen(grepstr, "w"))){
		printf("Grep error.\n");
		return 1;
	}
	/*With those sockets open, this takes up to MSTR lines from
	 * cat and pipes them into grep*/
	while(fgets(lines,MSTR,cat)){
		fputs(lines,grep);
	}
	/*Be kind, rewind*/
	pclose(cat);
	pclose(grep);
	return 0;
}
