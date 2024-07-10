#include <stdio.h>


int main()
{
	int n;

	n=1;
	while (n<= 10) {
		printf("%d ", n);
		n++;
	}

	printf("\n");
	
	n=1;

	while(1) {
		printf("%d ", n);
		if (n==10) break;
		n++;
	}
	
	n=1;

	int keepgoing=1;
	while(keepgoing) {
		printf("%d ", n);
		if (n==10)keepgoing=0;
		n++;
	}
("\n");
	
/*	bool keepgoing=true;
	while(keepgoing) {
		printf("%d ", n);
		if (n==10) keepgoing=false;
		n++;
	}
*/
	return 0;
}
