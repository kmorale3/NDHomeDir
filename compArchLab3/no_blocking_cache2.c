#include <stdio.h>
#include <math.h>
#include <stdint.h>   // intptr_t, uintptr_t
#include <inttypes.h>

#define XSIZE 400
#define YSIZE 400

int main(void) {

  int x[XSIZE][YSIZE];
  int y[XSIZE][YSIZE];
  int z[XSIZE][YSIZE];

  int i, j, k;
  
  int r;

  /*printf("x base address: %p\n",x);
  printf("y base address: %p\n",y);
  printf("z base address: %p\n",z);

  printf("x[0][0]:   %p\n",&x[0][0]);
  printf("x[0][1]:   %p\n",&x[0][1]);
  printf("x[0][99]:  %p\n",&x[0][99]);
  printf("x[1][0]:   %p\n",&x[1][0]);
  printf("x[1][1]:   %p\n",&x[1][1]);
  printf("x[99][99]: %p\n",&x[99][99]);*/

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

   // cache 2: 2^11 blocks per cache
  int cacheValidBit2[2048] = {0};
  int cacheTag2[2048]      = {0};

  int numMisses2 = 0;
  int totalAccesses2 = 0;

  // get bits 6-16 (11 bit index)
  long unsigned int indexmask2  = 0x0001FFC0;
  // get bits 0-5 (6 bit offset)
  long unsigned int offsetmask2 = 0x0000003F;
  // get bits 17-31 (15 bit tag)
  long unsigned int tagmask2    = 0xFFFE000;

  unsigned long int address = (unsigned long long int)&y[i][j];
        // get the bits
  unsigned long int offset; 
  unsigned long int index;
  unsigned long int tag;

  int inCache;

  /* Do matrix multiply */
  for(i=0; i<XSIZE; i=i+1) {
    for(j=0; j<YSIZE; j=j+1) {
      r = 0;
      for(k=0; k<XSIZE; k=k+1) {
        r = r + y[i][k] * z[k][j];
        // check the y address in cache
        totalAccesses2 ++;
        address = (unsigned long long int)&y[i][k];
        // get the bits
        offset  = address & offsetmask2; 
        index   = address & indexmask2;
        tag     = address & tagmask2;
        // shift as needed 
        index = index >> 5;
        index = index % 2048;
        inCache = 1;
        if (cacheValidBit2[index] == 0) {
            cacheValidBit2[index] = 1;
            cacheTag2[index] = tag;
            inCache = 0;
        } else if (cacheTag2[index] != tag){
            cacheTag2[index] = tag;
            inCache = 0;
        }
        if (!inCache){
            numMisses2 ++;
        }
        // check the z address in cache
        totalAccesses2 ++;
        address = (unsigned long long int)&z[k][j];
        // get the bits
        offset  = address & offsetmask2; 
        index   = address & indexmask2;
        tag     = address & tagmask2;
        // shift as needed 
        index = index >> 5;
        index = index % 2048;
        inCache = 1;
        if (cacheValidBit2[index] == 0) {
            cacheValidBit2[index] = 1;
            cacheTag2[index] = tag;
            inCache = 0;
        } else if (cacheTag2[index] != tag){
            cacheTag2[index] = tag;
            inCache = 0;
        }
        if (inCache == 0){
            numMisses2 ++;
        }
      }
      x[i][j] = r;
      totalAccesses2 ++;
      address = (unsigned long long int)&x[i][j];
      // get the bits
      offset  = address & offsetmask2; 
      index   = address & indexmask2;
      tag     = address & tagmask2;
      // shift as needed 
      index = index >> 5;
      index = index % 2048;
      inCache = 1;
      if (cacheValidBit2[index] == 0) {
          cacheValidBit2[index] = 1;
          cacheTag2[index] = tag;
          inCache = 0;
      } else if (cacheTag2[index] != tag){
          cacheTag2[index] = tag;
          inCache = 0;
        }
      if (inCache == 0){
          numMisses2 ++;
      }
    }
  }
  printf("cache2 no blocking: %d x %d matrix\n", XSIZE, YSIZE);
  printf("totalaccesses: %d, totalmisses: %d\n", totalAccesses2, numMisses2);
}
