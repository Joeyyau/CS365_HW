#include"stdio.h"
#include<stdlib.h>
int main(int argc, char *argv[]) {
	
	FILE *fp;
	char *mode = "r";
	char outputFilename[] = "out.list";
	char filename[100];
	char ch;
	
	//Total Chars, Space, Word counters
	int tChars = 0;
	int tSpaces = 0;	
	int tWords = 0; 
	
	int n, last = '\n';

	//printf("Enter a filename: ");
	//gets(filename);	
	
	fp = fopen(argv[1], "r");

if(fp){
	while((ch = getc(fp)) != EOF){
		last = n;
		tChars++;
		if(ch != ' ' && ch != '\n'){
			++tChars;
		}
		if(ch == ' ' || ch == '\n'){
			++tWords;
		}
		if(ch == '\n'){
			++tSpaces;
		}
	}
	if(tChars > 0){
		++tSpaces;
		++tWords;
	}	
}

else{
	printf("Failed to open the file.\n");
}

	printf("Chars: %d \n", tChars);
    printf("Spaces: %d \n", tSpaces);
	printf("Words: %d \n", tWords);

getchar();
return 0;
}
