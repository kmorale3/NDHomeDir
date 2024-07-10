//Author: Katie Morales
//February 22, 2021
//gcdmain.c
//This program has the user input 2 integer numbers and then finds and prints their greatest common divisor

#include <stdio.h>
#include <math.h>

int getgcd(int, int);

int main()
{
	int x,y,gcd; //these will be the 2 integers and the gcd
	printf("Please enter 2 integers: ");
	scanf("%d %d", &x, &y);//take in inputs
	
	gcd=getgcd(x,y);//call function

	printf("the gcd is: %d\n", gcd);//print gcd

	return 0;

}

int getgcd(int x, int y)
{
	int gcd;//greatest comon divisor, what we are trying to calculate
	int i; //this will be used as a counter in a for loop
	int j; //this will be used as a counter in a for loop

	if (x==0||y==0) {//if either number is zero, then the gcd is zero
		gcd=0;
	}
	else if (x>=y) { 
		for (i=1; i<=y; i+=1) { //create a for loop that marches 1 through the lesser integer between x and y (the max gcd would be the 
			if (x%i==0 && y%i==0) { // if the remainder of both integers divided by the for loop counter is 0, then both numbers are divisible by it and it is a divisor
				gcd=i; //whenever there is a common divisor, this value is reset, so the final one will be the gcd
			}
		}
	}
	else if (y>=x) { 
		for (j=1; j<=x; j+=1) {
			if (x%j==0 && y%j==0) {
				gcd=j; 
			}
		}
	}
	return gcd;
}

