#include <stdio.h>

int  A[3] = {5, 7, 0};

int add(int x, int y)
{
    return x + y;
}

int main()
{
    A[2] = add(A[0], A[1]);
}

