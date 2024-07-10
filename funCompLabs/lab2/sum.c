// sum.c
// displays two sums:
// first is the sum of the squares of numbers 1 through 10
// second is the sum of the square roots of numbers 1 through 10
#include <stdio.h>
#include <math.h>

int main(void)
{
	int i; //this will be used as an accumulator for the first for loop 
	int j; //this will be used as an accumulator fro the second for loop 
	int sum1=0; //this will be the sum for the sqaures
	double sum2=0; //this will be the dum for the square roots

	for (i=1; i<=10; i=i+1) {
		sum1=sum1 + pow(i,2);
	} for (j=1; j<=10; j=j+1) {
		sum2=sum2 + sqrt(j);
	}

	printf("ths sum of the squares of numbers 1 through 10 is %d\n", sum1);
	printf("the sum of the square roots of numbers 1 through 10 is %lf\n", sum2);

	return 0;
}
