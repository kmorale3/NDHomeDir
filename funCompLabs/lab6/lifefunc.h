//lifefunc.h
//header file
#include <stdio.h>
const int boardSize; //includes border

void initializeArrays(char [][boardSize]);
void printBoard(char[][boardSize]);
void nextGen(char [][boardSize], char [][boardSize]);
