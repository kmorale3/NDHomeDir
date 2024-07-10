// quad.c
// computes the roots of the quadratic equation
#include <stdio.h>
#include <math.h>

int main(void)
{
	double a, b, c, disc;
	double x1, x2;

	printf("Enter the coefficients (a,b ,c) of a quadratic equation: ");
	scanf("%lf %lf %lf", &a, &b, &c);

	disc= sqrt(pow(b,2)-4*a*c);
	//printf("%lf\n", disc);

	x1= (-b+disc)/(2*a);
	x2= (-b-disc)/(2*a);

	printf("The solutions are %lf and %lf\n", x1, x2);

	return 0;
}
