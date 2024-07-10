#include <stdio.h>

int main()
{

	int a, n;
	printf("enter n: ");
	scanf("%d", &n);

	if(n ==1) {
		a=12;
	} else if(n==2) {
		a=31;
	} else if (n==3) {
		a=72;
	} else {
		a=55;
	}

	printf("a if %d\n", a);

	 return 0;

}


