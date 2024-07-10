/*bitset.c*/
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int bitset = 0;

    for (int argind = 1; argind < argc; argind ++) {
        int bit = atoi(argv[argind]);
        bitset = bitset | (1<<bit); //bit mask
    }
    printf("%d\n", bitset);

    for (int i = 0; i < sizeof(int)*8; i++){
        if (bitset & (1<<i)){
            printf("%d is set!\n",i);
        }
    }
    return EXIT_SUCCESS;

}