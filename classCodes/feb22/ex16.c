#include <stdio.h>

int triple(int); //prototype of triple 
int sum(int,int);
void greetings(void);

int main()
{
	greetings();
	int a, b;
	a=12;
	b=triple(a);
	printf("b is %d\n",b);
	printf("a is %d\n", a);

	int n=4;
	int m= triple(n);
	printf("m is %d\n", m);

	int z= sum(a,n);
printf("z is %d\n", z);
	return 0;
}

int triple(int a) 
{
	int b;
	b=3*a;
	a=55;
	return b;
}

int sum(int f, int g)
{
	return f+g;
}

void greetings(void)
{
	printf("hello everybody\n");
}
