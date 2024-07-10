#include <stdio.h>

void display(int [], int);
void tripleit(int[], int);
int main()
{
	int arr[]= {23, 11, 65, 74, 57, 68};

	int size= sizeof(arr) / sizeof(int);

	display(arr, size);
	tripleit(arr, size);
	display(arr, size);

	return 0;
}

void display(int a[], int s) 
{
	int i=0;
	
	for(i=0; i < s; i++)
		printf("%d\n", a[i]);
	printf("\n");
}

void tripleit(int a[], int s)
{
	int i;
	for (i=0; i<s; i++)
		a[i]=3*a[i];
}
