// graph.c
// Author: Katie Morales 2/15/21
// this program makes a graph of the function y=6sin(e^(x/6))+6
#include <stdio.h>
#include <math.h>

int main(void)
{
	double x, y; // this defines the x and y variables
	int min=0, max= 21; //this defines the variables which will be used for the range
	int iy; //this will be used as a counter for printing the # to make the graph
	double ymin=10, ymax=0; //these variables will store the min and max value
	double xmin, xmax; //these variables will store the location of the min and max
	printf("Plot for y=6sin(e^(x/6))+6 for x from %d  to %d\n",min, max);
	printf("   X     Y\n");

	for (x=min; x<=max; x+=0.2) {//loop through the x-values, incrementing x by 0.2 each time until meeting the max
		y=6*sin(exp(x/6))+6; // calculate y based on the value of x
		printf("%5.2lf  %5.2lf  ", x, y);//print x and y
		for (iy=0; iy<=y; iy+=1) { //this for loop will run as many times as the number above the y value... thus all y values will be rounded up for the number of #
			printf("#");
		}
		printf("\n");
		if (y<=ymin) { //if the y value is lower than(or equal to) the current y-min... change the ymin and its x-location. ymin is originally at 10 and this function does have values below that
			ymin=y;
			xmin=x;
		} if (y>=ymax) { //if the y-value is greater than the current y-max... save the value and x-location into the max variables... the ymax starts at 0 and this function does have values greater than 0
			ymax=y;
			xmax=x;
		}
	}
	printf("The maximum of %.2lf was at %.2lf\n", ymax, xmax);
	printf("The minimum of %.2lf was at %.2lf\n", ymin, xmin);

	return 0;
}
