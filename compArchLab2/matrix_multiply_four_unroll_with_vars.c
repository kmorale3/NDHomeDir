#include <stdio.h>
#include <math.h>
#include <time.h>

#define XSIZE 160
#define YSIZE 160
#define MATRIX_SIZE 160


int main(void) {

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

  begin = clock();
 
  /* Do matrix multiply */

  /* INSERT CODE HERE. */
  // MATRIX_SIZE captures both the row and column dimensions of all matrices 

    for (i=0; i < MATRIX_SIZE; i+=2) { 
        for (j=0; j < MATRIX_SIZE; j+=2) { 
                int a = x[i][j];
                int b = x[i+1][j];
                int c = x[i+1][j+1];
                int d = x[i][j+1];
            for(k=0; k < MATRIX_SIZE; k++) { 
                a = a + y[i][k] * z[k][j]; 
                b = b + y[i+1][k] * z[k][j];
                c = c + y[i+1][k] * z[k][j+1];
                d = d + y[i][k] * z[k][j+1];
            } 
            x[i][j] = a;
            x[i+1][j]= b;
            x[i+1][j+1] = c;
            x[i][j+1] = d;
        } 
    } 
  end = clock();
  
  time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
  
  printf("Time Spent on MM is:  %lf\n", time_spent);
}
