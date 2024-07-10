#include <stdio.h>
int main ()
{
    char A[3] = {30, 31, 32};

    printf( "array index notation\n");
    printf( "A[0]:  addr: %p  data: %d\n",  &A[0],  A[0] );
    printf( "A[1]:  addr: %p  data: %d\n",  &A[1],  A[1] );
    printf( "A[2]:  addr: %p  data: %d\n",  &A[2],  A[2] );
    printf( "----------------------------------------\n" );
    printf( "pointer notation\n");
    printf( "A:     addr: %p  data: %d\n",  A,    *(A)   );
    printf( "A+1:   addr: %p  data: %d\n",  A+1,  *(A+1) );
    printf( "A+2:   addr: %p  data: %d\n",  A+2,  *(A+2) );
}

