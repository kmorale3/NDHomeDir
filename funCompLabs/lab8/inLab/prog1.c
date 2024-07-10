// prog1.c
#include <stdio.h>

int findsum(int [], int);

int main()
{
  int arr[] = {12, 34, 26, 49, 58};
  const int size = sizeof(arr)/sizeof(int);

  int sum = findsum(arr, size); 

  printf("the sum is: %d\n", sum);

  return 0;
}

int findsum(int a[], int sz)
{
  int s = 0;
  int i;
  for (i = 0; i < sz; i++) {
    s += a[i];
  }
  return s;
}

