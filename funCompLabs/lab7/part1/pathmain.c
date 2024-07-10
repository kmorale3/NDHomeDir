//Katie Morales
//03/28/21
//pathmain.c
//this is the main driver for the path program
#include <stdio.h>
#include <math.h>
#include "pathfunc.h"

//typedef struct {
//	float x;
//	float y;
//} Point;

int main(int argc, char *argv[]) {
	FILE *fp;
	char fileName[30];
	if (argc==1) {
		printf("Please enter a file name; ");
		scanf("%s", fileName);
		fp=fopen(fileName, "r");
	} else if (argc==2) {
		fp=fopen(argv[1], "r");
	} else {
		printf("Error: too many inputs!");
		return 0;
	}

	Point points_arr[30]; 

	int count = readvalues(fp, points_arr);

	int i; 
	float distance=0; //overall path distance
	float distToNext; //this will store the values from the function which will then be added to the overall path distance
	for(i=0; i < count-1; i++) {
		distToNext= pathDistance(points_arr[i], points_arr[i+1]);
		distance+=distToNext;
	}

	printf("\nThere are %d points: \n\n", (count)); 
	printf("   x   |   y   \n");//top of the table
	printf("-------|-------\n");

	for (i=0; i<count; i++) {
		display(points_arr[i]);
	}

	printf("\nThe path distance through them is %.2f\n\n", distance);

	return 0;
}
