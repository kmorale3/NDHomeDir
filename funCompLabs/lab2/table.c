// table.c
// Author: Katie Morales 2/15/21
// this program asks the user for 2 integers (x and y) and creates a multiplication table that is size x by y
#include <stdio.h>
#include <math.h>

int main(void)
{
	int x, y; //these will be the inputs to determine the size of the table
	int i, j, k, l; //these will be used as counter variables in the for loops
	int m; //m will be the product of each x and y that will be printed in the table
	printf("Please input 2 integers (x and y) to print out an x by y multiplication table: ");
	scanf("%d %d", &x, &y);

	printf("*   ");//blank space needed to format properly
	for (i=1; i<=x; i=i+1) { //this for loop is used to format the top of the table showing the x-values
		printf("   %3d", i);
	}
	printf("\n");//new line needed
	printf("    ");//format blank space
	for (j=1; j<=x; j=j+1) {//this for loop creates the dashed line underneath the top numbers
		printf("------");
	}
	printf("\n");
	
	for (k=1; k<=y; k=k+1) {
		printf("%2d |", k);
		for (l=1; l<=x; l=l+1) {
			m=k*l;
			printf("   %3d", m);  
		}
		printf("\n");
	}

	return 0;
}
