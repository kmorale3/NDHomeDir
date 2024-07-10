#include <stdio.h>
#include <math.h>

double myfunc(double);

int main()
{
	double x,y;
	printf("Please enter a value of x between 1 and -1: ");
	scanf("%lf",&x);
	y= myfunc(x);
	printf("The value is %f\n", y);		
	return 0;
}
double myfunc(double x){
	double a;//a is the value of the new term being added...
 	double y=1;//y is the output
	int i=1; //i is the number of times the loop iterates 
	while(1) {
		a=pow(x,i);
		if (a > 0.001) {
			y+=a;
			i++;
		}
		else {
			return y;
		}
	}
}

		

