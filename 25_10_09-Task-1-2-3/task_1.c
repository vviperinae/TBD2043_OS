/* 
c program to count the number of spaces in a given file
argc: count of lines
argv[]: array of arg strings
argv[1]: filename
fp: file pointer
ch: to read each chr from file
sc: count spaces


STEP 1: Start the program
STEP 2: Declare the variables ch, *fp, sc=0
STEP 3: Open the file in read mode
STEP 4: Get the character
STEP 5: If ch== “ “ then increment sc value by one
STEP 6: Print no of spaces
STEP 7: Close the file
*/

#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>
int main(int argc,char *argv[]){
	FILE *fp; char ch; int sc=0;
	fp=fopen(argv[1],"r");
	if(fp==NULL){
		printf("unable to open a file: %s\n",argv[1]);
	
	}else{
		while(!feof(fp)){
		ch=fgetc(fp); if(ch==' ')
		sc++;
	}
	printf("no of spaces %d",sc);
	printf("\n");
	fclose(fp);
	}
}
