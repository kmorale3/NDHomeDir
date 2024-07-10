#include <stdio.h>

int main()

{
   int td;
   printf("How many touchdowns were scored? ");
   scanf("%d", &td);
   int ep;
   printf("How many extra points were scored? ");
   scanf("%d", &ep);
   int fg;
   printf("How many field goals were scored? ");
   scanf("%d", &fg);
   int s;
   printf("How many safeties were scored? ");
   scanf("%d",&s);

   int score;
   score= 6*td + 1*ep + 3*fg + 2*s;
   printf("The Irish scored %d points! \n", score);

   return 0;

}

