//statesfunc.c
//Katie Morales
//4/6/21

#include "statesfunc.h"

const int max=256;
const int statesNum=50;

int readstates(FILE *fp, State arr[]) {
	int count=0;
	char stateLine[max];

	while (1) {
		fgets(stateLine, max, fp);
		if (feof(fp)) 
			break;

		strcpy(arr[count].abb, strtok(stateLine, ","));//abbreviation of state
		strcpy(arr[count].name, strtok(NULL, ","));//states full name
		strcpy(arr[count].cap, strtok(NULL, ","));//states capital
		arr[count].year = atoi(strtok(NULL, "\n"));//states year

		count++; //increment count
	}
	return count;
}

int takeInput(void) {
	printf("1. List all data\n2. Input a state's abbreviation to see that state's info\n3. Input a state's abbreviation or name to see that state's capital\n4. Input a year to see states that entered the union that year\n5. List the states in order of entering the union\n6. Quit\n Enter your choice: ");
	int choice;
	scanf("%d", &choice);
	return choice;
}

void listAllData(State arr[], int count) {
	int i; //for loop counter
	for (i=0; i<count; i++) {
		printf("%s, %s, %s, %d\n", arr[i].abb, arr[i].name, arr[i].cap, arr[i].year);
	}
}

void lowercase(char arr[], char new_arr[]) {
	int length=strlen(arr);
	int i; //for loop counter
	for (i=0; i<=length; i++) {//less that or equal to length to copy null character
		if((arr[i]>=65)&&(arr[i]<=90)) 
			new_arr[i]= arr[i] + 32; //convert from upper to lowercase
		else 
			new_arr[i]= arr[i];
	}
}

void lowercaseState(State normal_arr[], State lower_arr[], int count) {
	int i; //for loop counter
	for (i=0; i<count; i++) {
		lowercase(normal_arr[i].abb, lower_arr[i].abb);
		lowercase(normal_arr[i].name, lower_arr[i].name);
		lowercase(normal_arr[i].cap, lower_arr[i].cap);
		lower_arr[i].year=normal_arr[i].year;
	}
}

void infoFromAbb(State arr[], State lower_arr[],int count) {
	char inputAbb[3];//2 characters for abbreivation + null
	printf("Please enter a state abbreviation: ");
	scanf("%s", inputAbb);
	char lower_inputAbb[3];
	lowercase(inputAbb, lower_inputAbb);
	int i;
	for (i=0; i<count; i++) {
		if (!(strcmp(lower_inputAbb, lower_arr[i].abb))){
			break;
		}
	}
	printf("%s, %s, %s, %d\n", arr[i].abb, arr[i].name, arr[i].cap, arr[i].year);
	
}

void capital(State arr[], State lower_arr[], int count) {
	int i;
	char inputState[50];//2 characters for abbreivation + null
	printf("Please enter a state abbreviation or name: ");
	fscanf(stdin,"%s", inputState);
	char lower_inputState[50];
	lowercase(inputState, lower_inputState);
	for (i=0; i<count; i++) {
		if (!(strcmp(lower_inputState, lower_arr[i].abb))){
			break;
		}
		else if (!(strcmp(lower_inputState, lower_arr[i].name))){
			break;
		}
	}
	printf("The capital is %s\n", arr[i].cap);
}

void stateYear(State arr[], int count) {
	int year;
	printf("Please enter a year: ");
	scanf("%d", &year);
	int i; 
	printf("States that entered the Union in %d: \n", year);
	for (i=0; i<count; i++) {
		if (arr[i].year==year) 
			printf("  %s\n", arr[i].name);
	}
}

void chronologicalOrder(State arr[], int count) {
	State chron[count];
	int i,j;
	State temp;
	for (i=0; i<count; i++) {
		chron[i]=arr[i];
		for (j=i; j>0; j-=1) {
			if (chron[j].year<chron[j-1].year) {
				temp=chron[j-1];
				chron[j-1]=chron[j];
				chron[j]=temp;
			} 
			else 
				break;
		}
	}
	listAllData(chron, count);
}	
