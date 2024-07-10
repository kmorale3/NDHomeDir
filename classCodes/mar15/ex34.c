#include <stdio.h>

int main()
{
	putchar('A');
	putchar('\n');

	putc('B', stdout);
	putchar(104);
	putchar(10);//new line

	puts("this is a string");

	return 0;
}
