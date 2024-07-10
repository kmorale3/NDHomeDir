#include <stdio.h>

int main() {
   int x = 0xffffffff;
   int y = 2;
   int z;
   z = x+y;
   printf("x: %d y: %d z:%d \n", x, y,z);
}
