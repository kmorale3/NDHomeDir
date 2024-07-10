#include <stdio.h>

int main()
{
	int n;
	printf("enter n: ");
	scanf("%d", &n);
	printf("the number is: %d\n", n);

	getchar();//flushes out the new line from the previous input
	int x;
	printf("enter a character: ");
	scanf("%c", &x);
	printf("the character is: -->%c<--\n", x);

	return 0;
}
