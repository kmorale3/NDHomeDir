//lifefunc.c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "lifefunc.h"

const int boardSize=42;

void initializeBoard(char board[][boardSize]) {
	int i, j; //for loop counters
		for (i=0; i<boardSize; ++i) {
			for (j=0; j<boardSize; ++j) {
				if ((i==0&&j==0)||
				    (i==(boardSize-1)&&j==0) ||
 					 (i==(boardSize-1)&&j==(boardSize-1))||
					 (i==0&&j==(boardSize-1))) {
					board[i][j]=' ';
				} else if(i==0||i==(boardSize-1)) {
					board[i][j]='-';
				} else if(j==0||j==(boardSize-1)) {
					board[i][j]='|';
				} else {
					board[i][j]=' ';
				}
			}
		}
}

void printBoard(char currentBoard[][boardSize]) {
	system("clear");
	int i,j; //for loop counters	
	char printChar; //charcater that will be printed on the board	
	for (i=0; i<boardSize; ++i) {
		for (j=0; j<boardSize; ++j) {
			printf("%c",currentBoard[i][j]);
		}
		printf("\n");
	}
	fflush(stdout); 
}

void nextGen(char currentBoard[][boardSize], char futureBoard[][boardSize]) {
	initializeBoard(futureBoard);
	int i, j,k,l; //for loop counters
	int neighborCount;
	for(i=1; i<boardSize-1; ++i) {
		for(j=1; j<boardSize-1; ++j) {
			neighborCount=0;
			for(k=i-1; k<=i+1; ++k) {
				for(l=j-1; l<=j+1; ++l) {
					if ((!(k==i&&l==j))&&(currentBoard[k][l]=='X'))
						++neighborCount;
				}
			}
			if (currentBoard[i][j]=='X') {
				if ((neighborCount<2)||(neighborCount>3))
					futureBoard[i][j]=' ';
				else 
					futureBoard[i][j]='X';
			} else {
				if (neighborCount==3) 
					futureBoard[i][j]='X';
			}
		}
	}
	
	for(i=1; i<boardSize-1; ++i) {
		for(j=1; j<boardSize-1; ++j) {
			currentBoard[i][j]=futureBoard[i][j];
		}
	}
}					
				


