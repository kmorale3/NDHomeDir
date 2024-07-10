// Katie Morales
// 3-1-21
// five.c

#include <stdio.h>

int main() {
	int a[5];
	int i;

	printf("Enter 5 positive integers:\n ");

	for (i=0; i<5; i++) 
		scanf("%d",&a[i]);

	printf("%d %d %d %d %d\n",  a[4], a[3], a[2], a[1], a[0]);
	
	return 0;
}
