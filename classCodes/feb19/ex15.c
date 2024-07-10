#include <stdio.h>

int main()
{
	int n=4;
	n++; //postincrement
	printf("n is %d\n", n);

	++n;// pre-increment
	printf("n is %d\n", n);

	int a,b;
	b=3;
	a=7+ ++b;
	printf("b is %d\n", b);
	printf("a is %d\n", a);

	n+=6; // n=n+6
a/=b+4; //a=a/(b+4)
	return 0;
}
