#include <stdio.h>

int main()
{
    int i = 3;
    int x = 0;
loop_cond:
    if (i < 0) goto loop_exit; {
        printf("i = %d\n", i);
        i = i - 1;
        goto loop_cond;
    }
loop_exit:
    x = 0xff;
    printf("x = %x\n", x);
}

