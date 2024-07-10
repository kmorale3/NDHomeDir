//crossswordfunc.c
//Katie Morales
//4/12/21

#include "crosswordfunc.h"

const int boardSize=17;
const int letterMax=16;

void initBoards( char solution[][boardSize]) {
	int i, j; 
		for (i=0; i<boardSize; ++i) {
			for (j=0; j<boardSize; ++j) {
				if(i==0 ||i==(boardSize-1)) {
					solution[i][j]='-';
				} else if(j==0||j==(boardSize-1)) {
					solution[i][j]='|';
				} else {
					solution[i][j]='.';
				}
			}
		}
}
					
void copyBoard(char copy [][boardSize], char orig [][boardSize]) {
	int i, j;
	for (i=0; i<boardSize; ++i) {
		for (j=0; j<boardSize; ++j) {
			copy[i][j]=orig[i][j];
		}
	}
}

int readWords(FILE *fp, Words arr[]) {
	int count=0;
	int valid; //if equal to 1, the word is valid... if 0 it is not valid
	while (1) {
		fgets(arr[count].word,16, fp);
		valid=uppercase(arr[count].word);
		if (feof(fp)) {
			break;
		} else if(strlen(arr[count].word)>16){
			break; 
		} else if(!(strcmp(arr[count].word,"."))) {
			break;
		} else if (count==20) {
			break;
		} else if(valid==0) {
			break;
		}
		int i;
		for (i=0; i<16; i++) {
			arr[count].matches[i]=0;
		}
		count+=1; //increment count

	}
	return count;
}


int uppercase(char arr[]) {
	int length=strlen(arr);
	int i; //for loop counter
	for (i=0; i<length-1; i++) {//less that or equal to length to copy null character
		if((arr[i]>=65)&&(arr[i]<=90)) 
			continue;
		if((arr[i]>=97)&&(arr[i]<=122)) 
			arr[i]= arr[i] - 32; //convert from upper to lowercase
		else 
			return 0;
	}
	arr[length]=0;
	return 1;
}

void sortWords(Words arr[], int count) {
	int i,j;
	char temp[16];
	for (i=0; i<count; i++) {
		for (j=i; j>0; j-=1) {
			if (strlen(arr[j].word)>strlen(arr[j-1].word)) {
				strcpy(temp,arr[j-1].word);
				strcpy(arr[j-1].word,arr[j].word);
				strcpy(arr[j].word,temp);
			} 
			else 
				break;
		}
	}
}

void printBoard(char board[][boardSize]) {
	int i,j;
	for (i=0; i<boardSize; i++) {
		for (j=0; j<boardSize; j++) {
			printf("%c", board[i][j]);
		}
		printf("\n");
	}
}

void printPuzzle(char board[][boardSize]) {
	int i,j;
	for (i=0; i<boardSize; i++) {
		for (j=0; j<boardSize; j++) {
			if(board[i][j]=='.')
				printf("#");
			else if (board[i][j]=='|')
				printf("|");
			else if (board[i][j]=='-')
				printf("-");
			else
				printf(" ");
		}
		printf("\n");
	}
}

void printWords(Words word[], int count) {
	int i;
	for (i=0; i<count; i++) {
		strfry(word[i].word);
		printf("%d %d %s\n", word[i].row, word[i].col, word[i].word);
	}

}

void placeFirstWord(Words word[], int numWords, char solution[][boardSize]) {
	int length1=strlen(word[0].word);
	word[0].col=(boardSize-length1)/2+boardSize%2;
	word[0].row=boardSize/2;
	word[0].orient=0;
	int i;
	for (i=0; i<length1-1; i++) {
		solution[word[0].row][word[0].col+i]=word[0].word[i];
	}
}

void placeWords(int numWords, Words words[], char solution [][boardSize]) {
	int i,j;
	for (i=1; i<numWords; i++) {
		for (j=0; j<i; j++) {
			if (checkWords(words,i,j, solution))

				break;
		}
	}
}

int checkWords(Words words[], int w1,int w2, char solution[][boardSize]) { 
	int word1loc, word2loc;
	Words word1=words[w1];
	Words word2=words[w2];
	int k;
	for (word1loc=0; word1loc<strlen(word1.word); word1loc++) {
		for (word2loc=0; word2loc<strlen(word2.word); word2loc++) {
			if ((word1.word[word1loc]==word2.word[word2loc]) &&
				 (checkFit(word1, word2, word1loc,word2loc, solution))) {
				int row, col;
				if(word2.orient==0) {
					col=word2.col+word2loc;
					row=word2.row-word1loc;
					for (k=0; k<strlen(word1.word)-1; k++) {
						solution[row+k][col]=word1.word[k];
					}
					word1.orient=1;
				}
				else { 
					col=word2.col-word1loc;
					row=word2.row+word2loc;
					for (k=0; k<strlen(word1.word)-1; k++) {
						solution[row][col+k]=word1.word[k];
					}
					word1.orient=0;
				}
				word1.row=row;
				word1.col=col;
				word2.matches[word2loc]=3;
				int sideMatch;
				if (word1loc==0)
					 
					sideMatch=2;
				else if (word1loc=strlen(word1.word))
					sideMatch=1;
				else 
					sideMatch=3;

				if (word2loc>0){
					word2.matches[word2loc-1]=sideMatch;
				}
				if (word2loc<15){
					word2.matches[word2loc+1]=sideMatch;
				}
				int l;
				words[w1]=word1;
				words[w2]=word2;
				for (l=0; l<16; l++) {
					words[w1].matches[l]=word1.matches[l];	
					words[w2].matches[l]=word2.matches[l];
				}	
				return 1;
			}
		}
	}			
	return 0;
}
	

int checkFit(Words word1, Words word2, int word1loc, int word2loc, char board[][boardSize]) {
	//if word 2 is horizontal, then word 1 is vertical.. fits if word 2's row is greater than word 1's start
	if (word2.orient==0) {
		if	(word2.row<word1loc) 
			return 0;
		if	 ((word2.row+strlen(word1.word)-word1loc)>boardSize-1) 
			return 0;
	}
	//if word 2 is vertical, then word 1 is horizontal.. fits if word 2's col is greater than word 1's start
	if (word2.orient==1) {
		if (word2.col<word1loc) 
			return 0;
		if	 ((word2.col+strlen(word1.word)-word1loc)>boardSize-1) 
			return 0;
	}
	int start=word2loc-1;
	if (start<0)
		start=0;
	int j;
	for (j=start; j<=word2loc+1;j++) {
	//already matched in both directions
	if (word2.matches[j]==3)
		return 0;
	//if it is matched with a word down/right, then it must be at the end of word 1
	if (word2.matches[j]==2)// && (word1loc<strlen(word1.word))) 
		return 0;
	//if it is matched with a word up/left, then it must be at the beginning of word 1
	if (word2.matches[j]==1)// && (word1loc>0)) 
		return 0;
	}
	//check for collisions with other words already places if word 2 is horizonatal
	if(word2.orient==0) {
		int row, col;
		int i;
		col=word2.col+word2loc;
		row=word2.row-word1loc;
		for (i=row; i<row+strlen(word1.word); i++) {
			if (i==word2.row)
				continue;
			if( board[i][col]!='.')
				return 0;
		}
	}
	
	//check for collisions with other words already places if word 2 is vertical
	if(word2.orient==1) {
		int row, col;
		int i;
		col=word2.col-word1loc;
		row=word2.row+word2loc;
		for (i=col; i<col+strlen(word1.word); i++) {
			if (i==word2.col)
				continue;
			if( board[row][i]!='.')
				return 0;
		}
	}
	return 1; //if these are all false
}
	
