//Author: Katie Morales
//March 15, 2021
//mysayings.c
//This program reads a file and displays the frequency of each letter of the alphabet within that file as well as the percent frequency.
#include <stdio.h>
#include <ctype.h>
#include <string.h>

const	int maxSayings=50;
const int maxChars=256;

int makeChoice(void);
void displaySayings(int , char [maxSayings][maxChars]); 
void newSaying(int, char [maxSayings][maxChars]);
void findWord(int, char [maxSayings][maxChars]);
void newFile(int, char [maxSayings][maxChars]);

int main()
{
	char sayings[maxSayings][maxChars];
	char tempSaying[maxChars];
	FILE *fp;
	char infile[30]; //name of file

	printf("enter a file name: ");
	scanf("%s", infile );
	getchar(); //this and all following getchar() lines are used to take in the newline character so as not to mess with the fgets function

	fp= fopen(infile, "r");
	if(!fp) {
		printf("error: file %s was not found", infile);
		return 0;
	}

	int count=0;
	while (1) { //read the file and store sayings into sayings[][]
		fgets(tempSaying, maxChars, fp);
		if (feof(fp))
			break;
		strcpy(sayings[count], tempSaying);//copy saying into the array
		count++; //increase the count to add the next saying to the next spot in the array
	}
	while(1) { //keep looping through until the user selects choice 5 which ends the program
		printf("\n");
		int choice;
		choice=makeChoice();//choose which option you would like 

		switch (choice) {//each switch case leads to another function which performs the desired task (case 5 ends program and default has the user reenter input
			case 1:
				displaySayings(count, sayings);
				break;
			case 2:
				count++;
				newSaying(count, sayings);
				break;
			case 3:
				findWord( count, sayings);
				break;
			case 4:
				newFile(count, sayings);
				break;
			case 5:
				printf("Goodbye!\n");
				return 0; //end the program
			default:
				printf("error: that was not a valid choice\n");
				break;
		}
	}
}

int makeChoice(void) {
	int choice;
	printf("1. display all sayings currently in the database\n2. enter a new saying into the database\n3. list sayings that contain a given word entered by the user\n4. save all sayings in a new text file\n5. quit the program\n");
	printf("Your choice: ");
	scanf("%d", &choice);
	getchar();
	return (int) choice;
}

void displaySayings(int count, char sayings[maxSayings][maxChars]) {
	int i;
	for(i=0; i<count; i++) {
		printf("  - %s", sayings[i]);
	}

}

void newSaying(int count, char sayings[maxSayings][maxChars]) {
	char tempSaying[maxChars];
	printf("Enter a new saying: ");
	fgets(tempSaying, maxChars, stdin);
	strcpy(sayings[count-1], tempSaying);//copy saying into the array
	printf("%s", sayings[count-1]);
}

void findWord(int count, char sayings [maxSayings] [maxChars]){
	char substring[maxChars];
	printf("Please enter the search substring: ");
	scanf("%s",substring);
	int i; //counter
	char *  found; //if substring is found
	for (i=0; i<count; i++) {
		 found= strstr (sayings[i], substring);
		if (found != NULL) {
			printf("  -");
			fputs(sayings[i], stdout);
		}
	}
}

void newFile(int count, char sayings [maxSayings][maxChars]) {
	char filename[30];
	printf("please enter the new file name: ");
	scanf("%s", filename);
	getchar();
	int i; //counter

	FILE *newFile;
	newFile= fopen(filename, "w");
	for(i=0; i<count; ++i) {
		fputs(sayings[i],newFile);
	}
	fclose(newFile);
}

