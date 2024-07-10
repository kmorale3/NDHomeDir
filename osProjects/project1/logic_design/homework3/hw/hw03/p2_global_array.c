#include <stdio.h>

int A[4] = {0xabc0, 0xabc1, 0xabc2, 0xabc3};
int main()
{
    int* A_ptr = A;             // starting address of A
    int  i = 2;                  
    int* Ai_ptr = A_ptr + i;    // same as &(A[i])
    int  d = *Ai_ptr;           // same as A[i]
    printf("%x\n", d);
}

