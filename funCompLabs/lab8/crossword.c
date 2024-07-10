//Katie Morales
//4/12/21
//crossword.c
//this is the main driver for the crossword program
#include "crosswordfunc.h"


int main(int argc, char *argv[]) {
	int mode;
	FILE *fp;
	char fileName[30];
	if (argc==1) {
		mode=1;//interactive mode
		fp=stdin;
	} else if (argc==2) {
		fp=fopen(argv[1], "r");
		mode=2;//file input, no output
	//	if (fp==NULL)
	//		return;
	} else if (argc==3) {
		fp=fopen(argv[1], "r");
		mode=3;//file input, with output	
		if (fp==NULL)
			return;
	} else {
		printf("Error: too many inputs!\n");
		return 0;
	}

	Words word_arr[20];
	int boardSize=17;
	char solution[boardSize][boardSize];
	int numWords;
	initBoards(solution);
	numWords= readWords(fp,word_arr );
	sortWords(word_arr, numWords);
	placeFirstWord(word_arr, numWords, solution);
	placeWords(numWords, word_arr, solution);
	printBoard(solution);
	printPuzzle(solution);
	printWords(word_arr, numWords);
}
