#include <stdio.h>

int main()
{
	int n; //size of triangle
	int i,j; //for loop counters
	printf("Enter n (2-9): ");
	scanf("%d", &n);

	for (i=1; i<=n; i++) {
		for(j=1; j<=i; j++) {
			printf("%d ", j);
		}
	printf("\n");
	}
	
	for(i=n-1; i>=1; i-=1) {
		for(j=1; j<=i; j++) {
			printf("%d ", j);
		}
	printf("\n");
	}
		
	return 0;
}

