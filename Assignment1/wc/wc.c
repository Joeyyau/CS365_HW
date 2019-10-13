#include"stdio.h"
#include<stdlib.h>

long getFileSize(const char* filename)
{
    long size;
    FILE *f;
 
    f = fopen(filename, "rb");
    if (f == NULL) return -1;
    fseek(f, 0, SEEK_END);
    size = ftell(f);
    fclose(f);
	
    return size;
}

int main(int argc, char *argv[]) {
	
	FILE *fp;
	char *mode = "r";
	char outputFilename[] = "out.list";
	//char filename[100];
	char ch;
	
	//Total Chars, Space, Word counters
	int tChars = 0;
	int tLines = 0;	
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
			++tWords;
		}
		if(ch == ' ' || ch == '\n'){
			++tWords;
		}
		if(ch == '\n'){
			++tLines;
		}
	}
	if(tChars > 0){
		++tLines;
		++tWords;
	}	
}
else{
	printf("Failed to open the file.\n");
	return 0;
}

	

	if(argv[2] = "-c"){
		printf("Chars: %d \n", tChars);
		return 0;	
	}
    if(argv[2] = "-l"){
		printf("Lines: %d \n", tLines);
		return 0;
	}
	if(argv[2] = "-w"){
		printf("Words: %d \n", tWords);
		return 0;
	}
	else{
		printf("Chars: %d \n", tChars);
		printf("Lines: %d \n", tLines);
		printf("Words: %d \n", tWords);
		return 0;
}
return 0;
}


