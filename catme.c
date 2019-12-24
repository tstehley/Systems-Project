#include<stdio.h>
int main(int argc, char *argv[]){
	FILE *infile;
	FILE *cat = popen("cat","w");
	/*FILE *grep= popen("grep","w");*/	
	char instr[64] = "metamorphosis.txt";
	char pat[32] = "Gregor";
	infile = fopen(instr,"r");	
	char cur[64];
	do{
		fgets(cur, 64, infile);
		fprintf(cat, "%s",cur);
	}while(cur != EOF);
	
/*	char a;
        a = fgetc(infile);
	while(a!=EOF){
		printf("%c",a);
		a = fgetc(infile);
	}*/
	return 0;
}
