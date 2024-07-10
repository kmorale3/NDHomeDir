#include <stdio.h>

int X = 7;
int main()
{
    int* X_ptr = &X;
    int  v = *X_ptr;
    printf ("%X\n", v);
}

