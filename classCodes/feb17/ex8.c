#include <stdio.h>

int main()
{
	int i, j;
   int sum=0;

   for (i=1; i<= 4; i= i +1){
		for (j=1; j <=3; j= j + 1) { 
			sum=sum +i*j;
		printf("%d %d %2d %2d\n", i, j, i*j, sum);
		}
	}

	printf("the sum is %d\n", sum);
	 return 0;

}


