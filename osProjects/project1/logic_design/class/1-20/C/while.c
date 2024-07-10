#include <stdio.h>

int main()
{
    int i = 3;
    int x = 0;
    while (i >= 0) {
        printf("i = %d\n", i);
        i = i - 1;
    }
    x = 0xff;
    printf("x = %x\n", x);
}

