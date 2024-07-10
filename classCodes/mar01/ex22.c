#include <stdio.h>


int main()
{
	int b[10]={33, 17,88,6}; // declare an array of 10 int's
	int c[]={12,67,24,57,88,45,56};

	printf("b: %d\n", sizeof(b));
	printf("c: %d\n", sizeof(c));

	int num = sizeof(c)/ sizeof(c[0]);
	printf("c has %d elements\n",num);

	printf("int: %d\n", sizeof(int));
	printf("float: %d\n", sizeof(float));
	printf("double: %d\n", sizeof(double));
	printf("long double: %d\n", sizeof(long double));


	return 0;
}
