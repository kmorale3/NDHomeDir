#include <stdio.h>
#include <math.h>
#include <time.h>

#define XSIZE 100
#define YSIZE 100
#define B 13

int main(void){

  int x[XSIZE][YSIZE];
  int y[XSIZE][YSIZE];
  int z[XSIZE][YSIZE];

  int i, j, k;
  
  int r;
   clock_t begin, end;

  double time_spent;

  /* Initialize x matrix */
  for(i=0; i<XSIZE; i++) {
    for(j=0; j<YSIZE; j++) {
      x[i][j] = 0;
    }
  }

  /* Initialize y matrix */
  for(i=0; i<XSIZE; i++) {
    for(j=0; j<YSIZE; j++) {
      y[i][j] = i + j;
    }
  }

  /* Initialize z matrix */
  for(i=0; i<XSIZE; i++) {
    for(j=0; j<YSIZE; j++) {
	z[i][j] = i + j;
    }
  }

int p,q,kk,jj,ii;

begin = clock();
  /* Do matrix multiply */
for(jj=0; jj<XSIZE; jj=jj+B) {
   for(kk=0; kk<YSIZE; kk=kk+B) {
      for(i=0; i<XSIZE; i=i+1) {
         if((jj+B) < YSIZE) {
            p = jj+B;
         }
         else {
            p = YSIZE;
         }
         for(j=jj; j<p; j=j+1) {
            r=0;
            if((kk+B) < XSIZE) {
               q = kk + B;
            } 
            else {
               q = XSIZE;
            }
            for(k=kk; k<q; k=k+1) {
                r = r + y[i][k]*z[k][j];
              }
            }
            x[i][j] = x[i][j] + r;
         }
      }
   }

  end = clock();

  time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
printf("cache1 blocking factor: %d\n%d x %d matrix\n", B,XSIZE, YSIZE);
printf("Time Spent on MM is:  %lf\n", time_spent);
}
