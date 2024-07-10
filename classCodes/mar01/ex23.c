#include <stdio.h>


int main()
{
	int i;

	for (i=1; i<=10; i++) {
	if (i==5) continue; //skips remeainder of loop but continues following iterations
	printf("%d\n",i);
	if (i==8) break;
	}

	return 0;
}
