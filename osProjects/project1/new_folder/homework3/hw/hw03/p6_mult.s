.data  
A: 9, 11, 0                   // int A[] = {9, 11, 0};
.text
main:   ldi r3, A                   //   r3_A = A;                                              
        ld  r1, r3, 0               //   r1_m = r3_A[0];
        ld  r2, r3, 1               //   r2_n = r3_A[1];
        jal mult                    //   r0_prod = mult(r1_m, r2_n);
        st  r0, r3, 2               //   r3_A[2] = r0_prod;
        quit                        //   exit;
mult:   ldi r0, 0                   //   r0_prod = 0;
        ldi r4, 4                   //   r4_i = 4;
        ldi r5, 1                   //   r5_mask = 1;
        ldi r7, 1                   //   r7_1 = 1;
        loop:   bz  r4, finish       //   if (r4_i == 0) goto finish;
                and r6, r5, r2      //   r6_nbit = r5_mask & r2_n;
                bz  r6, shift        //   if (r6_nbit == 0) goto shift;
                add r0, r0, r1      //   r0_prod = r0_prod + r1_m;
        shift:  shl r1, r1, r7       //   r1_m = r1_m << r7_1;
                shl r5, r5, r7       //   r5_mask = r5_mask << r7_1;
                sub r4, r4, r7           //   r4_i = r4_i - r7_1;
                br  loop      //   goto loop;
        finish: jr  r15             // finish: 
             //   return r0_prod;
                    // }



