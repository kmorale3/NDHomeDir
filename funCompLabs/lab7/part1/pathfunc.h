//pathfunc.h
//header file
//katie Morales
//3/30/21
#include <stdio.h>
#include <math.h>

typedef struct {
	float x;
	float y;
} Point;

int readvalues(FILE *, Point []);
float pathDistance(Point, Point); 
void display(Point);
