// Katie Morales
// 3-1-21
// many.c

#include <stdio.h>

int main() {
	int a[21];
	int i,j;
	int n=-1; //counter

	for (i=0; i<21; i++) {
		scanf("%d",&a[i]);
		if (a[i]==-1) break;
		n++;
		}
		
	for (j=n; j>=0; j-=1) {
		printf("%d ",a[j]);
	}

	printf("\n");

	return 0;
}
