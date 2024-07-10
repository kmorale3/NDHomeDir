//Katie Morales
//03/28/21
//playlife.c
//this is the main driver to simulate Conway's Game of Life
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "lifefunc.h"


int main(int argc, char *argv[]) {
	char mode; 
	if (argc== 1) 
		mode= 'i';//interactive mode
	else if (argc == 2)
		mode= 'b';//batch mode
	else 
		printf("error: too many arguments\n");
	char currentBoard[boardSize][boardSize];
	char futureBoard[boardSize][boardSize];
	initializeBoard(currentBoard);

	FILE *fp;
	if (mode=='i') {
		fp=stdin;
	} else {
		fp=fopen(argv[1], "r");
	}	
		printBoard(currentBoard);
		char inputStr[2]; //this will be the string that the 
		int arg1, arg2;
		while (1) { //always true while loop, will be broken once user enters q
			printf("COMMAND: ");
			fscanf(fp,"%s", inputStr);
			switch (inputStr[0]) {
				case 'a':
					fscanf(fp,"%d %d", &arg1, &arg2); 
					currentBoard[arg1+1][arg2+1]='X';
					break;
				case 'r':
					fscanf(fp,"%d %d", &arg1, &arg2); 
					currentBoard[arg1+1][arg2+1]=' ';
					break;
				case 'n':
					nextGen(currentBoard, futureBoard);
					break;
				case 'p':
					while (1) {
						nextGen(currentBoard, futureBoard);
						printBoard(currentBoard);
						usleep(250000);
					}
				case 'q':
					return 0;		
			}
			printBoard(currentBoard);
		}
	
	return 0;
}	 
