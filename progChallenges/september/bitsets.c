#include <stdint.h>
#include <stdio.h>

int main(int argc, char* argv[]) {
    int elements[] = {1,2,4,0};
    //initialize bitset
    uint8_t bitset = 0;

    // add elements to bitset, use or to add
    // elements[i] has 0 as a sentinel, that's why we use elements[i] as the condition
    for (size_t i = 0; elements[i]; i++) {
        // 7 6 5 4 3 2 1 0
        // 0 0 0 0 0 0 0 0 [0]
        // 0 0 0 0 0 0 1 0 [1]
        bitset = bitset |  1 << elements[i];
    }
    // 0 0 0 1 0 1 1 0
    // %d decimal
    // %x hex
    // %c char 
    printf("%d\n",bitset);

    // test for elements in bitset , use and to check
    for (size_t i = 0; i < 6; i++) {
        if (bitset & (1<<i)){
            printf("%lu in bitset\n",i);
        }
    }

    //remove elements from bitset, USE AND WITH COMPLEMENT
        //could use XOR (don't use the xor twice, otherwise it will add it back)
    for (size_t i = 0; elements[i]; i++) {
        bitset = bitset &  ~(1 << elements[i]);
    }
    printf("%d\n",bitset);

}