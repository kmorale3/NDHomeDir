#include <stdio.h>

int main()
{
	char s1[15];

	printf("enter a string: ");
	fgets(s1, 15, stdin);
	puts(s1);	

	return 0;
}
