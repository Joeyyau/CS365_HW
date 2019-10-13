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
		if(ch == ' '){
			++tWords;
		}
		if(ch == '\n'){
			++tLines;
		}
	}	
}
else{
	printf("Failed to open the file.\n");
	return 0;
}

printf("\tFile: %s\n", argv[1]);
printf("\t1st Flag: %s\n", argv[2]);

if(argc >= 3){
	if(strcmp(argv[2], "-c") == 0){
		printf("Chars: %d \n", tChars);
		return 0;	
	}
    if(strcmp(argv[2], "-l") == 0){
		printf("Lines: %d \n", tLines);
		return 0;
	}
	if(strcmp(argv[2], "-w") == 0){
		printf("Words: %d \n", tWords / 2);
		return 0;
	}
	else{
		printf("Chars: %d \n", tChars);
		printf("Lines: %d \n", tLines);
		printf("Words: %d \n", tWords / 2);
		return 0;
	}
}
		printf("Chars: %d \n", tChars);
		printf("Lines: %d \n", tLines);
		printf("Words: %d \n", tWords / 2);
	return 0;
}


