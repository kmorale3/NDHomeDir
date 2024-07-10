// mortgage.c
// Author: Katie Morales 2/15/21
// this program creates an amortization (mortgage payment) table based upon the user's inputted principal amount, interest rate, and desired monthly payment
 #include <stdio.h>
#include <math.h>

int main(void)
{
	int m=1,yr; //this represents the months and the years which will be used in the final display statement
	double p, ir, b, mi,sum=0; //these represent payment, interest,  balance, monthly interest, and overall sum of money paid

	printf("please input the principal amount, interest rate, and desired monthly payment: ");
	scanf("%lf %lf %lf", &b, &ir, &p);

	while (ir<0) { //error message for a negative inputted interest rate
		printf("error: negative interest rate... please reenter a positive interest value: ");
		scanf("%lf", &ir);
	}

	printf("Month     Payment     Interest     Balance\n"); //labels at top of table

	mi= ir*0.01/12; //this converts the annual interest rate into a monthly rate and switches the percent to a decimal value

	if (p<mi*b) {
		printf("desired monthly payment too small... cannot pay mortgage\n");
		return 0;
	}

	while (b>0) {
		printf("%3d       ",m);//print the month
		if(b>=p) { //if the remaining balance is greater than the monthly payment
			printf("$%6.2lf      ",p);//print the normal monthly payment
			printf("$%6.2lf  ", mi*b);//the interest is the monthly interest multiplied by the current balance to find the current amount of interest for the month		
		} else {
			p=b+(mi*b); // the final payment (less than the normal monthly payment) will be equal to the remaining balance plus the monthly interest
			printf("$%6.2lf      ",p);//print the normal monthly payment
			printf("$%6.2lf  ", mi*b);//the interest is the monthly interest multiplied by the current balance to find the current amount of interest for the month		
		}	

		b=b-p+(mi*b);//the new balance is equal to the current balance minus the monthly payment plus the monthly interest
		printf("$%9.2lf\n", b);
		m=m+1; //add another month
		sum=sum+p; //this adds the money paid this month to the overall sum
		
	}
	m=m-1; //at the end of the last iteration of the while loop, an unnecessary month was added to m
	yr= m/12; //finds the complete years by dividing by 12... yr is an int variable so it will be an integer
	m=m % 12; //this finds the remainder of months divided by 12 in order to find the extra months 
	printf("You paid a total of $%.2lf over %d years and %d months\n", sum, yr, m);//final print statement

	return 0;

}
