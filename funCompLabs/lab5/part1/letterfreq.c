//Author: Katie Morales
//March 15, 2021
//menucalc.c
//This program reads a file and displays the frequency of each letter of the alphabet within that file as well as the percent frequency.
#include <stdio.h>
#include <ctype.h>
#include <string.h>

void display(int freq[], int x, int numChar, int numLet, int lowMin, char infile[]);

int main()
{
	FILE *fp;
	char infile[30];

	printf("enter a file name: ");
	scanf("%s", infile);

	fp= fopen(infile, "r");
	if (!fp) {
		printf("file %s was not found\n", infile);
		return 1;
	}

	int x=26; //make program versatile for an alphabet of any size... you simply have to change the size of the freq array
	int freq[x];
	int i; //for loop counter
	for (i=0; i<x; ++i) {
		freq[i]=0; //initialize all values to 0
	}

	int val; //will temporarily store the character
	int lowMin=97,lowMax=122, capMin=65, capMax=90; //will be used to index frequency into array
	int numChar=0;
	int numLet=0;

	while (1) {
		fscanf(fp, "%c", &val);
		++numChar;
		if(feof(fp)){
			 break; //break once the end of the file has been reached
		}
		if ((val>=capMin) && (val<=capMax)) { //if it is a capital letter
			freq[val-capMin]+=1;
			++numLet;
		} else if ((val>=lowMin) && (val<=lowMax)) { //if it is a lowercase letter
			freq[val-lowMin]+=1;
			++numLet;
		}
	}
	numChar-=1; //remove the null character from the character count
	display(freq, x, numChar, numLet, lowMin, infile);

	return 0;
}

void display(int freq[], int x, int numChar, int numLet, int lowMin, char infile[]) {
	printf("General summary for %s:\n", infile);
	printf("\tthere were %d total characters\n", numChar);
	printf("\tthere were %d letters\n\n", numLet);
	printf("Letter counts:\n\t");

	int i;//for loop counter
	for (i=0; i<x; ++i) { //print letter frequencies
		printf("%c:%6d   ", i+lowMin, freq[i]);
		if ((i+1)%6==0) printf("\n\t");
	}
	printf("\n\n");
	
	printf("Letter percentages:\n\t");
	float per; //percent
	for (i=0; i<x; ++i) {
		per=((float)freq[i]*100/(float)numLet);
		printf("%c:%5.1f%c   ", i+lowMin, per,37);
		if ((i+1)%6==0) printf("\n\t");
	}	
	printf("\n");
}

