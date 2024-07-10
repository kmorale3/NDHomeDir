//statesfunc.h
//header file
//katie Morales
//4/5/21
#include <stdio.h>
#include <string.h>


const int max; // max characters for each line
const int statesNum; //number of states in State states_arr, can be changed

typedef struct {
	char abb[3];
	char name[50];
	char cap[50];
	int year;
} State;


int readstates(FILE *, State []);
int takeInput(void);
void listAllData(State [], int);
void lowercase(char [], char[]);
void lowercaseState(State [], State[], int);
void infoFromAbb(State [], State[], int);
void capital(State [], State[], int);
void stateYear(State [], int);
void chronologicalOrder(State [], int);
