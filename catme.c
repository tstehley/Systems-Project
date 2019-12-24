#include<stdio.h>
int main(int argc, char *argv[]){
	FILE *infile;
	FILE *cat = popen("cat","w");
	
	if(argc <2){
		printf("No Input File Provided.\n");
	}
	if(argc <3){
		printf("No Pattern Provided.\n");
		return 1;
	}

	infile = fopen(argv[1],"r");
	if (infile == NULL){
		printf("Infile Not Found\n");
		return 1;
	}
/*	char a;
        a = fgetc(infile);
	while(a!=EOF){
		printf("%c",a);
		a = fgetc(infile);
	}*/
	return 0;
}
