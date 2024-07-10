#include <stdio.h>

int main()
{
	char x;
	x= 'g';

	printf("%c\n",x);
	printf("%d\n",x);//shows ascii value in decimal

	int n;
	n=66;
	printf("%c\n",n);
	printf("%d\n",n);//shows ascii value

	x=x+3;
	printf("%c\n",x);

	char ch= 'a';
	int i;
	for (i=0; i<=15; i++) {
		printf("%c\n",ch+i);
	} 

	char y;
	y= 'p';
	printf("%d\n", y-'a'+1);

	return 0;
}
