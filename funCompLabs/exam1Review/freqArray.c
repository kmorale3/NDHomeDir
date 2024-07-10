#include <stdio.h>
#include <math.h>

int freq(int[], int, int);

int main()
{
	int arr[]={1,1,2,2,2,3,3,3,3,4,4,4,4,5,6,7,8,9,9,9};
	int size;
	size= (sizeof(arr)/sizeof(int));
	int num; 
	int n;
	printf("Please enter a number between 0 and 9: ");
	scanf("%d", &num);
	n=freq(arr, size, num);
	printf("%d occurs in the array %d times\n", num, n);
	return 0;
}

int freq(int arr[], int size, int num) {
	int n;
	int i;
	for (i=0; i<size; i++) {
		if (arr[i]==num) 
			n++;
	}
	return n;
}
		

