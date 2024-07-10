#include <stdio.h>
#include <stdlib.h>

int  main(void) {

	//I created all of this code before I looked at the char_point_alloc_sol.c
	//In the solution for that code, there were 2 functions used that made the code cleaner, but I decided not to implement that into my solution since this was the raw solution that i created on my own
	//In the solution, the number of strings and the length of the stings were defined outside, but I just defined them in my main program
	

	long unsigned int array_len=7;//number of arrays

	//allocate the array of arrays
	double ** array1=(double **)malloc(array_len*sizeof(double*));//pointer to pointers
	
	long unsigned int array_len2=10;//number of doubles in each array in the array
	
	long unsigned int iter;

	//allocate the arrays within the array
	for (iter=0; iter<array_len; ++iter) {
		array1[iter]=(double *)malloc(array_len2*sizeof(double));//pointers being pointed at
	}

	//free the arrays in the array
	for (iter=0; iter<array_len; ++iter) {
		free(array1[iter]);
	}

	//free the overall array
	free(array1);

	return 0;
}
