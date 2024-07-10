#include <stdio.h>
#include <math.h>

void flip(int[], int);

int main()
{
	int arr[]= {4,6,2,1,9,5,7};
	int size;
	size= sizeof(arr)/sizeof(int);
	flip(arr,size);
	return 0;
}

void flip(int a[],int s) {
	int i;
	int p;
	for (i=0; i<s/2; i++) {
		p=a[i];
		a[i]=a[s-1-i];
		a[s-i-1]=p;
	}
	for (i=0; i<s; i++) {
		printf("%d ", a[i]);
	}
}
		
