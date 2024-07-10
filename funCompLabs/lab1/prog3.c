#include <stdio.h>
#include <math.h>

//this program calculated the hypotenuse of a right triangle when inputted wwith 2 side lengths

int main(void){

   double a;
   double b; 
   double value;
   double hyp;
   printf("please input the 2 sides of the triangle to calculate hypotenuse: ");
   scanf("%lf %lf", &a, &b);

   value= a*a+b*b;
  // printf("%lf\n", value);
   hyp= sqrt(value);
   printf("The hypotenuse is %lf\n", hyp);

   return 0;
}

