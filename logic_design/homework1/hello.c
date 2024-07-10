#include <stdio.h>
int main()
{
    //1.display hello world 
    printf("Hello, world!\n");
    int x = 2;
    int y = 3;

    //2.printf displaying x, y and x+y
    printf("x = %d  y = %d  sum = %d\n\n", x, y, x+y);

    //3.display decimal 74 in hex and as an ASCII character
    int z=74;
    printf("decimal: %d hex: %x, ascii: %c\n",z,z,z);

    //4.display hex 0x5a as a decimal and a character
    int a=0x5a;
    printf("decimal %d hex: %x ascii: %c\n",a,a,a);

    //5.display the character ‘a’ as decimal and hex values
    int b= 'a';
    printf("decimal %d, hex: %x ascii: %c\n\n",b,b,b);

    //6.display signed decimals -1, -2, and -3 as hex values
    int c=-1;
    int d=-2;
    int e= -3;
    printf("decimal %d, hex: %x\n",c,c);
    printf("decimal %d, hex: %x\n",d,d);
    printf("decimal %d, hex: %x\n\n",e,e);

    //7.display the hex values 0x7ffffffe, 0x7fffffff, 0x80000000, 0x80000001  as signed decimals
    int f= 0x7ffffffe;
    int g= 0x7fffffff;
    int h= 0x80000000;
    int i= 0x80000001;

    printf("decimal %d, hex: %x\n",f,f);
    printf("decimal %d, hex: %x\n",g,g);
    printf("decimal %d, hex: %x\n",h,h);
    printf("decimal %d, hex: %x\n\n",i,i);

    //8.take the largest unsigned integer in hex and display it as an unsigned decimal using %u
    unsigned int j= 0xffffffff;
    printf("largest unsigned: decimal %u, hex: %x\n\n",j,j);

    //9.display results from using the Boolean AND, OR, and NOT operators (&, |, ~)
    int k = 0x3;
    int l = 0x5;
    printf("a=%x b=%x\n",k,l);
    printf("a & b = %x\n", k & l);
    printf("a | b = %x\n", k | l);
    printf("~a = %x\n", ~k);

    //10.use a mask and the AND operation to zero out all but the 4 least-significant bits of an int
    int mask1 = 0x0000000f;
    int m= 0xfffffffc;
    printf("original a: %x\n",m);
    printf("mask: %x\n",mask1);
    printf("a & mask = %x\n", m & mask1);
    
    //11.use a mask and the OR operation to set to ones all but the 4 least-significant bits of an int
    int n=0x0000000c;
    int mask2 = 0xfffffff0;
    printf("original a: %x\n",n);
    printf("mask: %x\n",mask2);
    printf("a | mask = %x\n\n", m | mask2);

    int pos= 10;
    int neg = -8;

    //12. left shift on positive number
    printf("before shift: decimal: %d hex: %x\n", pos,pos);
    printf("left shift: decimal: %d hex: %x\n", pos << 1,pos <<1);

    //13. right shift on positive number
    printf("before shift: decimal: %d hex: %x\n", pos,pos);
    printf("right shift: decimal: %d hex: %x\n\n", pos >> 1,pos >> 1);

    //12. left shift on negative number
    printf("before shift: decimal: %d hex: %x\n", neg, neg);
    printf("left shift: decimal: %d hex: %x\n", neg << 1,neg <<1);

    //13. right shift on negative number
    printf("before shift: decimal: %d hex: %x\n", neg, neg);
    printf("right shift: decimal: %d hex: %x\n", neg >> 1,neg >> 1);

}
