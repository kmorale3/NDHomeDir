#include <stdio.h>
int mult(int m, int n);

int A[] = {9, 11, 0};

int main()
{
    int m, n, prod;
    
    m = A[0]; n = A[1];
    prod = mult(m, n);
    A[2] = prod;
    printf("%d (0x%x) x %d (0x%x) = %d (0x%x)\n", m, m, n, n, A[2], A[2]);
}

int mult(int m, int n)
{
    int prod = 0;
    int i = 4;
    int mask = 1;
    int nbit;

    while (i != 0) {
        nbit = mask & n;
        if (nbit != 0)
            prod = prod + m;
        m = m << 1;
        mask = mask << 1;
        i = i - 1;
    }
    return prod;
}



