//Katie Morales
//3-1-21
//grades.c
//this program reads an array containing grades and displays their 

#include <stdio.h>
#include <math.h>

int findSize(int []); //finds size of array
float calcAve(int [], int); //calculates average of grades... there are two inputs: the grades array and the number of grades
float calcSTD(int [], int, float); //calculates standard deviation... three inputs: the grades array, the number of grades, and the average

int main()
{
  int grades[50] =
    { 96,73,62,87,80,63,93,79,71,99,
      82,83,80,97,89,82,93,92,95,89,
      71,97,91,95,63,81,76,98,64,86,
      74,79,98,82,77,68,87,70,75,97,
      71,94,68,87,79, -1 };

	int size;
	float average,std;
	size=findSize(grades);
   average=calcAve(grades, size);
	std=calcSTD(grades, size, average);

   return 0;
}

int findSize(int array[]) {
	int i; // for loop counter
	int n=0;// counter in for loop, to determine size

	for (i=0; i<=50; i++) {
		if (array[i]<0) { //-1 is the sentinel value
			break;
		}
		n++; //increase the counter each time the element is greater than 0 to find the size
	}
	printf("There are %d grades in the array.\n", n);

	return n;
}

float calcAve(int array[], int num) {
	int sum=0; //will be used to sum all the numbers before dividing
	int i; //will be used as counter in for loop
	float average; //calculated average

	for(i=0; i<num; i++) {
		sum+= array[i]; //add each individual value from the array to the sum
	}
	average= (float)sum / (float)num;
	printf("The class average is %.2lf\n", average);

	return average;
}

float calcSTD(int array[], int num, float average) {
	float diff[num]; //these will be the square of each values difference from the average
	int i; //counter in for loop
	float diffSum=0; //sum of diff array used to calculate average
	float diffAve; //average of the differences array
	float std; //standard deviation
	
	for (i=0; i<num; i++) {
		diff[i]= pow((array[i]-average),2);//calculate the squares of the differences between each grade and the average
	}	 

	for (i=0; i<num; i++) {
		diffSum+=diff[i];//sum the squares calculated above
	}

	diffAve= diffSum/num;//take the average of the sum calculated above

	std=sqrt(diffAve);//take the square root of the sum to find standard deviation:w


	printf("The standard deviation is %.2lf\n", std);

	return std;
}
