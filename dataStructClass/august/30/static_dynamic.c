#include <stdio.h>
#include <stdlib.h>

int main(){

	// Allocate a static array to 10, -19, 20, 34
	int static_arry[]={10, -19, 20, 34};
	
	
	// Allocate a dynamic array with a size variable
	long unsigned int int_size= 4*sizeof(int);
	int* dyn_arr = (int *)malloc(int_size);
	
	// Set the values in the dynamic array to 10, -19, 20, 34
	dyn_arr[0] = 10;
	dyn_arr[1] = -19;
	dyn_arr[2] = 20;
	dyn_arr[3] = 34;
	
	// Loop through and print the value and address of both the 
	// static and dynamic arrays 
	long unsigned int iter = 0;
	for (iter = 0; iter <int_size; iter ++) {
	fprintf( stdout, "%p %d %p %d\n",
			&static_array[iter], static_array[iter],
			&dyn_arr[iter], dyn_arr[iter]);
	}
	
	
	// Free the dynamic array
	free(dyn_arr);

	return 0;

}
