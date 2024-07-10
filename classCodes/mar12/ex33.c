#include <stdio.h>

int main()
{

	char str[10];

	printf("enter a string: ");
	fgets(str,10, stdin);
	puts(str);
	return 0;
}
