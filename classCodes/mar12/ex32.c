#include <stdio.h>

int main()
{
	char s1[]= "Computer Science";

	printf("%s\n", s1);
	puts(s1);

	char x= 'y';
	putc(x,stdout);
	printf("\n");
	putc(x+3,stdout);
	putc('\n',stdout);
	putc(x-4,stdout);
	putc('\n',stdout);

	putc(65,stdout);
	putc('\n',stdout);

	putchar(72);
	putchar(10);//new line
	return 0;
}
