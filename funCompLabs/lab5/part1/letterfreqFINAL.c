//Author: Katie Morales
//March 15, 2021
//menucalc.c
//This program reads a file and displays the frequency of each letter of the alphabet within that file as well as the percent frequency.
#include <stdio.h>
#include <ctype.h>
#include <string.h>

const int x=26; //number of letters in alphabet
const int lowMin=97; //ascii code for 'a'
const int capMin=65; //ascii code for 'A'

void display(int freq[], int nums[], char infile[]);
void initArr(int freq[]);
void findLetters(FILE *fp, int freq[], int nums[]);

int main()
{
	FILE *fp;
	char infile[30];//file name

	printf("enter a file name: ");
	scanf("%s", infile);

	fp= fopen(infile, "r");//open the file
	if (!fp) {
		printf("file %s was not found\n", infile);
		return 1;
	}
	
	int freq[x];
	initArr(freq);//give each index of freq[] an initial value of 0
	
	int nums[2];//will have the values for the number of characters and letters, nums[0] is number of characters and nums[1] is number of letters
	findLetters(fp,freq,nums);//edit the freq[] array to have the number of each letter
	display(freq,  nums, infile);//print the results

	return 0;
}

void display(int freq[], int nums[], char infile[]) {
	printf("\n");
	printf("General summary for %s:\n", infile);
	printf("    there were %d total characters\n", nums[0]);
	printf("    there were %d letters\n\n", nums[1]);
	printf("Letter counts:\n    ");

	int i;//for loop counter
	for (i=0; i<x; ++i) { //print letter frequencies
		printf("%c:%6d   ", i+lowMin, freq[i]);
		if ((i+1)%6==0) printf("\n    ");//only 6 letters per line
	}
	printf("\n\n");
	
	printf("Letter percentages:\n    ");
	float per; //percent
	for (i=0; i<x; ++i) { //calculate percentage for each letter
		per=((float)freq[i]*100/(float)nums[1]);//must typecast to get a float result
		printf("%c:%5.1f%c   ", i+lowMin, per,37);//37 is the ascii code for %
		if ((i+1)%6==0) printf("\n    ");//only 6 letters per line
	}	
	printf("\n\n");
}

void initArr(int freq[]) {
	int i; //for loop counter
	for (i=0; i<x; ++i) {
		freq[i]=0; //initialize all values to 0
	}
}

void findLetters(FILE *fp, int freq[], int nums[]) {
	int val; //will temporarily store the character
	nums[0]=0;//number of characters
	nums[1]=0;//number of letters

	while (1) {
		fscanf(fp, "%c", &val);
		++nums[0];//increase the number of characters each time the while loop runs
		if(feof(fp)){
			 break; //break once the end of the file has been reached
		}
		if ((val>=capMin) && (val<(capMin+x))) { //if it is a capital letter
			freq[val-capMin]+=1;//ascii code difference of character from ascii code for 'A'
			++nums[1];//increase the number of letters if it is a capital letter
		} else if ((val>=lowMin) && (val<(lowMin+x))) { //if it is a lowercase letter
			freq[val-lowMin]+=1;//ascii code difference of character from ascii code for 'a'
			++nums[1]; //increase the number of letters if it it a lowerase letter
		}
	}
	nums[0]-=1; //remove the null character from the character count
}
