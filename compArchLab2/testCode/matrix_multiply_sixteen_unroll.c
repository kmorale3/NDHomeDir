#include <stdio.h>
#include <math.h>
#include <time.h>

#define XSIZE 8
#define YSIZE 8
#define MATRIX_SIZE 8


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

    for (i=0; i < MATRIX_SIZE; i+=4) { 
        for (j=0; j < MATRIX_SIZE; j+=4) { 
          int a = x[i][j];     
          int b = x[i][j+1];   
          int c = x[i][j+2]; 
          int d = x[i][j+3];  
          int e = x[i+1][j];   
          int f = x[i+1][j+1]; 
          int g = x[i+1][j+2]; 
          int h = x[i+1][j+3]; 
          int l = x[i+2][j]; 
          int m = x[i+2][j+1]; 
          int n = x[i+2][j+2]; 
          int o = x[i+2][j+3]; 
          int p = x[i+3][j]; 
          int q = x[i+3][j+1]; 
          int r = x[i+3][j+2];
          int s = x[i+3][j+3];

            for(k=0; k < MATRIX_SIZE; k++) { 
                a = a + y[i][k] * z[k][j]; 
                b = b + y[i][k] * z[k][j+1];
                c = c + y[i][k] * z[k][j+2];
                d = d + y[i][k] * z[k][j+3];
                e = e + y[i+1][k] * z[k][j];
                f = f + y[i+1][k] * z[k][j+1];
                g = g + y[i+1][k] * z[k][j+2];
                h = h + y[i+1][k] * z[k][j+3];
                l = l + y[i+2][k] * z[k][j];
                m = m + y[i+2][k] * z[k][j+1];
                n = n + y[i+2][k] * z[k][j+2];
                o = o + y[i+2][k] * z[k][j+3];
                p = p + y[i+3][k] * z[k][j];
                q = q + y[i+3][k] * z[k][j+1];
                r = r + y[i+3][k] * z[k][j+2];
                s = s + y[i+3][k] * z[k][j+3];
            } 
            x[i][j]     = a;     
            x[i][j+1]   = b;   
            x[i][j+2]   = c; 
            x[i][j+3]   = d;  
            x[i+1][j]   = e;   
            x[i+1][j+1] = f; 
            x[i+1][j+2] = g; 
            x[i+1][j+3] = h; 
            x[i+2][j]   = l; 
            x[i+2][j+1] = m; 
            x[i+2][j+2] = n; 
            x[i+2][j+3] = o; 
            x[i+3][j]   = p; 
            x[i+3][j+1] = q; 
            x[i+3][j+2] = r;
            x[i+3][j+3] = s;
        } 
    } 


  end = clock();

  time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
  
  printf("Time Spent on MM is:  %lf\n", time_spent);

  printf("Sixteen Unroll\n");

  for(i=0; i<XSIZE; i++) {
    for(j=0; j<YSIZE; j++) {
      printf("%4d ", x[i][j]);
    }
    printf("\n");
  }
}
