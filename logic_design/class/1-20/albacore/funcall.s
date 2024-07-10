.text
main:                // int main();
                    // {
ldi r1, 5           //   int x = 5;   // r1
ldi r2, 7           //   int y = 7;   // r2
                    //   int z;       // r3
jal sum2            //   z = sum2(x, y);
or r3, r0, r0 
quit      
                    // }
sum2:                // int sum2(int x, int y)
                  // {
add r0, r1, r2        //   return x + y
jr r15
                // }

