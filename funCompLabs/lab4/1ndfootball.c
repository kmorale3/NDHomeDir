//Katie Morales
//3-1-21
//ndfootball.c
//this program shares some statistics about notre dame football throughout the years
#include <stdio.h>
#include "nd_data.h"//global arrays

int years=(sizeof(wins)/sizeof(int));//number of years in the arrays, global variable to be accessed in many of the functions

int chooseQuestion(void);//choosing the question the user wants to see
//the following are all of the question options
void losingRecord(void);
void printRecord(void);
void nWins(void);
void nLosses(void);
void comebackSeasons(void);
void winningStreaks(void);
void undefeated(void);

int main()
{
	while (1) {//always true... choice 8 returns 0 to exit program
		int choice;
		choice= chooseQuestion();//enter function to choose question to be displayed
		switch (choice) {//switch statement to enter the corrcet program based upon the user's choice
		case 1:
			losingRecord();
			break;
		case 2: 
			printRecord();	
			break;
		case 3:
			nWins();
			break;
		case 4:
			nLosses();
			break;
		case 5:
			comebackSeasons();
			break;
		case 6:
			winningStreaks();
			break;
		case 7:
			undefeated();
			break;
		case 8: 
   		return 0;
		}
		printf("\n\n");
	}
}

int chooseQuestion (void){
	int choice; 
	printf("1: Display years with losing records. \n2: Display the record for a given year. \n3: Display years with at least \"n\" wins. \n4: Display years with at least \"n\" losses. \n5: Display \"comeback\" years. \n6: Display winning streaks. \n7: Display undefeated years. \n8: Exit. \nEnter your choice: ");//print the options
	scanf("%d", &choice);//user enters choice which is then returned to main
	return choice;
}
void losingRecord(void) {
	int i; //for loop counter
	printf("Years with a losing record: ");
	
	for(i=0; i<years; i++) {
		if (wins[i]<losses[i]) {//more losses than wins.. losing record
			printf("%d ",i+1900);
		}
	}
}

void printRecord(void) {
	int year; //selected year to show record
	printf("Enter the year: ");
	scanf("%d", &year);//user inputs the year
	printf("Wins: %d, Losses: %d", wins[year-1900], losses[year-1900]);//record is printed

}
	
void nWins(void) {
	int nW; //minimum number of wins
	printf("Enter minimum number of wins: ");
	scanf("%d", &nW);

	printf("Years with at least %d wins: ", nW);
	int i; //for loop counter
	for (i=0; i < years; i++) {
		if (wins[i] >= nW) {//if the number of wins is greater than the minimum inputted by the user, print that year
			printf("%d ", 1900 + i);
		}
	}
}
	
void nLosses(void) {
	int nL; //minimum number of Losses
	printf("Enter minimum number of losses: ");
	scanf("%d", &nL);

	printf("Years with at least %d losses: ", nL);
	int i; //for loop counter
	for (i=0; i < years; i++) {
		if (losses[i] >= nL) {//similar to previous function but with losses rather than wins
			printf("%d ", 1900 + i);
		}
	}
}

void comebackSeasons(void) {
	int i; //for loop counter
	printf("Winning seasons following a losing season: ");
	for (i=1; i < years; i++) {
		if ((wins[i] > losses[i]) && (wins[i-1] < losses[i-1])) {// if there is a winning seasons(more wins than losses) and a losing season(more losses than wins) in the index before(
			printf("%d ", 1900+i);
		}
	}
}

void winningStreaks(void) {
	int ix, iy; //for loop counters
	int n=0; //winning streak count
	int p0; //position of the first year of the streak
	for (ix=0; ix < years; ix++) {
		if ((wins[ix] > losses[ix]) && (n==0)) {
			p0=ix; //set p0 to the value of ix to count the streak
			n++;		
		} else if ((wins[ix] > losses[ix]) && (n!=0)) {//for all winning years after the p0 year
			n++; //increase the value of n for the streak
		} else if ((wins[ix] <= losses[ix]) && n>1) {//only display streaks longer than 1 year and display them after coming across a losing year that ends the streak
			printf("%d year winning streak from %d to %d\n", n, p0+1900, p0 + (n-1) + 1900);//print the streak... n is how many years the streak was... p0 is the first year of the streak while (p0+n-1+1900) is the final year of the streak
			n=0;//set n to 0 so that new streaks may now be counted
		} else if ((wins[ix] <= losses[ix]) && n<=1) {//if there is a losing year, but no streak to display
			n=0;//still reinitialize n to 0 so new streaks can be counted
 		} 
		if((ix==years-1) && (wins[ix] > losses[ix]) && (n>=1)) {//case in which the last year is a winning year because streaks are only counted after coming across a losing year, so if the last year is a winning year, the streak to current will not display
			printf("%d year winning streak from %d to %d\n", n, p0+1900, p0 + (n-1) + 1900);
		}
	}		
}
					
void undefeated(void) {
	int i;//for loop counter
	printf("Undefeated seasons: ");
	for (i=0; i<years; i++) {
		if (losses[i]==0) {//if there are no losses, that year is undefeated
			printf("%d ", 1900+i);
		}
	}
}			 
