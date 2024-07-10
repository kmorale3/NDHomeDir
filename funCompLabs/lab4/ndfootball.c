//Katie Morales
//3-1-21
//ndfootball.c
//this program shares some statistics about notre dame football throughout the years
#include <stdio.h>
#include "nd_data.h"

int years=(sizeof(wins)/sizeof(int));

int chooseQuestion (void);
int losingRecord(void);
int printRecord(void);


int main()
{
	losingRecord();
	printRecord();	
   return 0;
}

int losingRecord(void) {
	int i; //for loop counter
	printf("Years with a losing record: ");
	
	for (i=0; i<years; i++) {
		if (wins[i]<losses[i]) 
			printf("%d ",i+1900);
	}
	return 0;
}

int printRecord(void) {
	int year; //selected year to show record
	printf("Enter the year: ");
	scanf("%d", &year);
	printf("Wins: %d, Losses: %d", wins[year-1900], losses[year-1900]);

	return 0;
}
	
