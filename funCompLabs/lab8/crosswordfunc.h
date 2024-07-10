//crosswordfunc.h
//header file
//katie Morales
//4/5/21
#include <stdio.h>
#include <string.h>

//const int boardSize=17;
//const int letterMax=16;

typedef struct {
	int row;
	int col;
	int orient; //0 for across, 1 for vertical
	char word[16];
	char shuffle[16];
	int matches[16];//0=no match, 1= match up/left, 2=match down/right, 3=matchboth
} Words;

void initBoards(char [][17]);
void copyBoard(char [][17], char [][17]);
int readWords(FILE *fp, Words []);
int uppercase(char []);
void sortWords(Words [], int);
void printBoard(char [][17]);
void printPuzzle(char [][17]);
void printWords(Words [], int);
void placeFirstWord(Words [], int, char[][17]);
void placeWords(int, Words [], char [][17]);
int checkWords(Words [], int, int, char[][17]);
int checkFit(Words, Words, int, int, char[][17]);
