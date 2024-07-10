#include <stdio.h>


int main()
{
	int a[10]; // declare an array of 10 int's
	int i, n=7;	

	a[0]= 6;
	a[1]= 71;
	a[2]= 85;

	for (i=0; i<=9; i++)
		a[i]=i*i*i;

	for (i=0; i<=9; i++)
		printf("a at index %d is %d\n", i, a[i]);

	printf("n is %d\n", n);
	a[10]=45;
	printf("n is %d\n", n); //never go out of the bounds of your array
	return 0;
}
