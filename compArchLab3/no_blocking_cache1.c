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

   // cache 1: 2^10 blocks per cache = 1024
  int cacheValidBit1[1024] = {0};
  int cacheTag1[1024]      = {0};

  int numMisses1 = 0;
  int totalAccesses1 = 0;

  // get bits 0-4 (5 bit offset)
  long unsigned int indexmask1  = 0x00007FE0;
  //get bits 5-14 (10 bit index)
  long unsigned int offsetmask1 = 0x0000001F;
  // get bits 15-31 (17 bit tag)
  long unsigned int tagmask1    = 0xFFFF8000;

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
        totalAccesses1 ++;
        address = (unsigned long long int)&y[i][k];
        // get the bits
        offset  = address & offsetmask1; 
        index   = address & indexmask1;
        tag     = address & tagmask1;
        // shift as needed 
        index = index >> 5;
        index = index % 1024;
        inCache = 1;
        if (cacheValidBit1[index] == 0) {
            cacheValidBit1[index] = 1;
            cacheTag1[index] = tag;
            inCache = 0;
        } else if (cacheTag1[index] != tag){
            cacheTag1[index] = tag;
            inCache = 0;
        }
        if (!inCache){
            numMisses1 ++;
        }
        // check the z address in cache
        totalAccesses1 ++;
        address = (unsigned long long int)&z[k][j];
        // get the bits
        offset  = address & offsetmask1; 
        index   = address & indexmask1;
        tag     = address & tagmask1;
        // shift as needed 
        index = index >> 5;
        index = index % 1024;
        inCache = 1;
        if (cacheValidBit1[index] == 0) {
            cacheValidBit1[index] = 1;
            cacheTag1[index] = tag;
            inCache = 0;
        } else if (cacheTag1[index] != tag){
            cacheTag1[index] = tag;
            inCache = 0;
        }
        if (!inCache){
            numMisses1 ++;
        }
      }
      x[i][j] = r;
      totalAccesses1 ++;
      address = (unsigned long long int)&x[i][j];
      // get the bits
      offset  = address & offsetmask1; 
      index   = address & indexmask1;
      tag     = address & tagmask1;
      // shift as needed 
      index = index >> 5;
      index = index % 1024;
      inCache = 1;
      if (cacheValidBit1[index] == 0) {
          cacheValidBit1[index] = 1;
          cacheTag1[index] = tag;
          inCache = 0;
      } else if (cacheTag1[index] != tag){
          cacheTag1[index] = tag;
          inCache = 0;
        }
      if (!inCache){
          numMisses1 ++;
      }
    }
  }
  /*for (int i = 0; i < 1024; i++){
      printf("%x\n",cacheTag1[i]);
  }*/
  printf("cache1 no blocking: %d x %d matrix\n", XSIZE, YSIZE);
  printf("totalaccesses: %d, totalmisses: %d\n", totalAccesses1, numMisses1);
}
