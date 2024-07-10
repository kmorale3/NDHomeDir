//Katie Morales
//3-1-21
//primes.c
//this program finds all of the prime numbers between 1 and 1000

#include <stdio.h>
#include <math.h>


int main()
{
	int num=1000; //max number
	int array[num]; //define array
	int i; //for loop counter

	for (i=0; i<num; i++){
		array[i]=1; //initialize all values in the array to a value of 1
	}

		int ix, iy; //counters to be used in the next for loops

	for (ix=2; ix<num; ix++) {
		if (array[ix]==1) {
			for (iy=ix+1; iy<num; iy++) {
				if ((iy)%(ix)==0) {
					array[iy]=0;
				}
			}
		}
	}

	int primeNums=0; //this will be used to format 10 prime numbers per row while printing 

	for (i=2; i<num; i++) {
		if (array[i]==1) {
			primeNums++; //add 1 to number of primes
			printf("%4d", i);
		if (primeNums%10==0) printf("\n");
		}
	}
	printf("\n");

   return 0;
}

