#include <stdio.h>
#include <stdlib.h>

struct elt {
  int val;
  struct elt *next;
};

int  A[3] = {5, 7, 0};

int add(int x, int y)
{
    return x + y;
}

int main()
{
    int s;
    struct elt *ptr;

    s = add(A[0], A[1]);
    A[2] = s;

    ptr = malloc(sizeof(struct elt));
    ptr->val = s;
    
    printf( "A[2]     = %d\n",  A[2]     );
    printf( "ptr->val = %d\n",  ptr->val );
}

