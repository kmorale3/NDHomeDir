//pathfunc.c
//Katie Morales
//3/30/21
#include <stdio.h>
#include <math.h>
#include "pathfunc.h"

int readvalues(FILE *fp, Point arr[]) {
	int count=0;
	while (1) {
		fscanf(fp, "%f %f", &arr[count].x, &arr[count].y);//add values to points array
		if (feof(fp)) 
			break;
		count++; //increment count
	}
	return count;
}

float pathDistance(Point P, Point Q) {
	float distance;
	float xDiff= Q.x - P.x;//difference in the x values
	float yDiff= Q.y - P.y; //difference in the y values
	distance=sqrt(pow(xDiff, 2)+pow(yDiff, 2)); //distance formula: d^2=x^2+y^2
	return distance;
}

void display(Point P) {
	printf("%5g  | %5g\n", P.x, P.y);
}
