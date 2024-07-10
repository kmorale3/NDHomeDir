#include <stdio.h>
#include <stdlib.h>

struct elt {
  int val;
  struct elt *next;
};

int  A[3] = {5, 7, 0};

int add(int x, int y)
{
    printf( "x:     %016p\n", &x );
    printf( "y:     %016p\n", &y );
    return x + y;
}

int main()
{
    int s;
    struct elt *ptr;
    
    printf("----------------------------- stack \n");
    printf( "&s:    %016p\n",  &s   );
    printf( "&ptr:  %016p\n",  &ptr );

    s = add(A[0], A[1]);
    A[2] = s;

    printf("----------------------------- heap \n");
    ptr = malloc(sizeof(struct elt));
    printf( "ptr:   %016p\n",  ptr          );
    printf( "&val:  %016p\n",  &(ptr->val)  );
    printf( "&next: %016p\n",  &(ptr->next) );
    ptr->val = s;
    
    printf("----------------------------- global data \n");
    printf( "&A:    %016p\n",  &A );
    
    printf("----------------------------- function text \n");
    printf( "main:  %016p\n",  main );
    printf( "add:   %016p\n",  add  );
    
    printf("-----------------------------\n\n");
    printf( "A[2]     = %d\n",  A[2]     );
    printf( "ptr->val = %d\n",  ptr->val );
}

