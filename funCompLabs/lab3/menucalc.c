//Author: Katie Morales
//February 28, 2021
//menucalc.c
//This program is able to add, multiply, subtract, or divide to user inputted numbers.
#include <stdio.h>


double addNumbers(void);
double subtractNumbers(void);
double multiplyNumbers(void);
double divideNumbers(void); 
int makeChoice(void);

int main()
{
	int choice; //math operation choice
	while(1) {
		choice= makeChoice();//choose operation
			switch (choice) {
			case 1: //addition
 				addNumbers();
				break;
			case 2: //subtraction
				subtractNumbers();
				break;
			case 3: //multiplication
				multiplyNumbers();
				break;
			case 4: //division
				divideNumbers();
				break;
			case 5: //exit loop
				printf("Good bye!\n");
				return 0; //end the function completely
			default: //
				printf("\n"); //just reprompt user	
			}
	}
	return 0;
}
int makeChoice(void) {
	int choice; //operation choice
	
	printf("What would you like to do?\n  1 for addition\n  2 for subtraction\n  3 for multiplation\n  4 for division\n  5 to exit\n"); // prints choice options
	printf("Enter your choice: ");
	scanf("%d", &choice);
	
	return choice;
}

double addNumbers(void) {
	double x,y, result;//inputted numbers and their result
	printf("Enter two numbers: ");
	scanf("%lf %lf",&x, &y);//take in number inputs
	printf("Inputs: %g, %g\n", x,y);

	result= x+y;
	printf("(%g) + (%g) = %g\n\n", x, y, result);

	return 0;
}

double subtractNumbers(void) {
	double x,y, result;//inputted numbers and their result
	printf("Enter two numbers: ");
	scanf("%lf %lf",&x, &y);//take in number inputs
	printf("Inputs: %g, %g\n", x,y);

	result= x-y;
	printf("(%g) - (%g) = %g\n\n", x, y, result);

	return 0;
}
double multiplyNumbers(void) {
	double x,y, result;//inputted numbers and their result
	printf("Enter two numbers: ");
	scanf("%lf %lf",&x, &y);//take in number inputs
	printf("Inputs: %g, %g\n", x,y);

	result= x*y;
	printf("(%g) * (%g) = %g\n\n", x, y, result);

	return 0;
}
double divideNumbers(void) { 
	double x,y, result;//inputted numbers and their result
	printf("Enter two numbers: ");
	scanf("%lf %lf",&x, &y);//take in number inputs
	printf("Inputs: %g, %g\n", x,y);

	result= x/y;
	printf("(%g) / (%g) = %g\n\n", x, y, result);

	return 0;
}
