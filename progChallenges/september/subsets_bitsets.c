#include <stdint.h>
#include <stdio.h>

int divisible_subsets(int n) {
    int count = 0;
    for (int bitset = 0; bitset < (1<<10); bitset++) {// generate bitset
        int total = 0;
        for(int i = 0; i < 10; i++) {                 // check each bit in the bitset 
            total += (bitset & (1<<i)) ? i : 0 ;       // sum up elements of bitset 
        }
        count += (total % n == 0);
    }
    return count;
}

int main(int argc, char* argv[]) {
    int n;
    while(scanf("%d", &n) != EOF) {
        printf("%d\n",divisible_subsets(n));
    }
}