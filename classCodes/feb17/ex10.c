#include <stdio.h>

int main()
{

	int a, n;
	printf("enter n: ");
	scanf("%d", &n);

	switch(n) {
	case 1:
		a=12;
		break;
	case 2:
		a=31;
		printf("a is %d now\n", a);
	case 3: case 4: case 5:
		a=72;
		printf("a is %d nowish\n", a);
		break;
	default:
		a=55;
	}



	printf("a is %d\n", a);

	 return 0;

}


