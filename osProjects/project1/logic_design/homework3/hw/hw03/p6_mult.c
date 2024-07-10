#include <stdio.h>
#include <stdlib.h>

int mult(int, int);

int A[] = {9, 11, 0};

int main()
{   
    int  r0_prod;
    int  r1_m;
    int  r2_n;
    int* r3_A;
    
    r3_A = A;
    r1_m = r3_A[0];
    r2_n = r3_A[1];
    r0_prod = mult(r1_m, r2_n);
    r3_A[2] = r0_prod;
    exit;
}

int mult(int r1_m, int r2_n)
{
    int r0_prod;
    int r4_i;
    int r5_mask;
    int r6_nbit;
    int r7_1;

    r0_prod = 0;
    r4_i = 4;
    r5_mask = 1;
    r7_1 = 1;
 
loop: 
    if (r4_i == 0) goto finish;
    r6_nbit = r5_mask & r2_n;
    if (r6_nbit == 0) goto shift;
    r0_prod = r0_prod + r1_m;
	
shift: 
    r1_m = r1_m << r7_1;
    r5_mask = r5_mask << r7_1;
    r4_i = r4_i - r7_1;
    goto loop;
	
finish: 
    return r0_prod;
}



