#include <stdio.h>
int main ()
{
    char v = 7;
    
    printf( "address of v:          %p\n",  &v    );
    printf( "value at address of v: %d\n",  *(&v) );
}
