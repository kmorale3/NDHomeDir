#include <stdio.h>

int determine_sign (int input) {
    //in binary 0x80000000 is a 1 followed by 31 0's.. the only way that the following statement evaluates 
    //true is if the input has a 1 in that first bit, which means it is a negative number
    if (0x80000000 & input) { 
        return 1; //negative number
    }
    else {
        return 0; //positive number
    }
}
void check_overflow(int input1, int input2) {
    printf("            decimal      hex\n");
    int sum = input1 + input2;
    //figure out the sign of the 2 inputs...

    //in this case, there is either a positive or a negative or 2 negatives because a 1 represents a negative
    if (determine_sign(input1)|determine_sign(input2)) {
        // in this case, there are 2 negatives
        if (determine_sign(input1) & determine_sign(input2)) {
            if (determine_sign(sum)) //case of no overflow because 2 negatives sum to a negative
                printf(" value 1: %11d %08x \n value 2: %11d %08x \n sum:     %11d %08x \n no overflow\n\n", input1, input1, input2, input2, sum, sum);
            else // there is overflow becuase this means 2 negatives sum to a positive
                printf(" value 1: %11d %08x \n value 2: %11d %08x \n sum:     %11d %08x \n overflow\n\n", input1, input1, input2, input2, sum, sum);
        }
        else // 1 positive and 1 negative... never overflows
            printf(" value 1: %11d %08x \n value 2: %11d %08x \n sum:     %11d %08x \n no overflow\n\n", input1, input1, input2, input2, sum, sum);
    }

    //in this case, there are 2 positives because they both return 0 from the determine sign function 
    else {
        if (determine_sign(sum)) //case of overflow because 1 represents a negative sum and if 2 positives sum to negative, there is overflow
            printf(" value 1: %11d %08x \n value 2: %11d %08x \n sum:     %11d %08x \n overflow\n\n", input1, input1, input2, input2, sum, sum);
        else // there is not overflow
            printf(" value 1: %11d %08x \n value 2: %11d %08x \n sum:     %11d %08x \n no overflow\n\n", input1, input1, input2, input2, sum, sum);
    }
    
}

int main () {
    check_overflow(100,200);
    check_overflow(-100, -200);
    check_overflow(0x7fffffff,1);
    check_overflow(0x80000000, -1);
    check_overflow(0x7fffffff, 0x80000000);
}