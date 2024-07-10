#include <stdio.h>

int main()
{
	int n=1;
	while(n<=10) {//pre-test
		printf("n is %d\n",n);
		n=n+1;
	}

	do { // post-test
		...
		...
		...
	} while(n<=10);

	return 0;
}
