// ex30.c
#include <stdio.h>

int main()
{
  printf("%d\n", sizeof(5));
  printf("%d\n", sizeof(5555));
  printf("%d\n", sizeof('5'));
  char x = '5';
  printf("%d\n", sizeof(x));
  printf("%d\n", sizeof("5"));

  float z = 2.34;
  printf("%d\n", sizeof(z));
  printf("%d\n", sizeof(2.34));

  return 0;
}

