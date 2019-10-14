// @ Joey Tavares 10.13.19

#include"stdio.h"
#include<stdlib.h>

long getFileSize(const char* filename); //function to grab the file size.
int printAll(); //helper print function

int main(int argc, char *argv[]) {
	
	FILE *fp;
	char ch;
	
	//Total Chars, Space, Word counters
	int tChars = 0;
	int tLines = 0;	
	int tWords = 0; 
	fp = fopen(argv[1], "r");

if(fp){ 
	while((ch = getc(fp)) != EOF){ //Looks until EOF checking what each char is and adding
		tChars++;				   //to the respective counter. 
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

printf("\tFile: %s\n", argv[1]);      //decorative print
printf("\t1st Flag: %s\n", argv[2]);  //

if(argc >= 3){                        //If 3 or more arguments are passed in check which one and print based on that
	if(strcmp(argv[2], "-c") == 0){
		printf("Chars: %d \n", tChars); //Chars
		return 0;	
	}
    if(strcmp(argv[2], "-l") == 0){
		printf("Lines: %d \n", tLines); //Lines
		return 0;
	}
	if(strcmp(argv[2], "-w") == 0){
		printf("Words: %d \n", tWords / 2); //Words, wont be right *Counter doesn't work needs logic debugged.*
		return 0;
	}
	else{
		printAll(tChars, tLines, tWords);
		return 0;
	}
}		
		printAll(tChars, tLines, tWords); //No arguments passed in just print full output. 
	return 0;
}
// -----------------------  //
//Function implementations //
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

int printAll(tChars, tLines, tWords){
	printf("Chars: %d \n", tChars);
	printf("Lines: %d \n", tLines);
	printf("Words: %d \n", tWords / 2);
return 0;
}
