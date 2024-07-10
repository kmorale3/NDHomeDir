/* value.c */

#include <limits.h>
#include <stdint.h>
#include <stdio.h>

typedef union {
    //max of the 2 is 8 so the size is 8
    //when you change the string to 10, the size becomed 16
    //64 bit machines uses 8 byte words
    //compiler thinks 10 is weird and 16 is better, word size chunks
    uint64_t number;	// DISCUSS: signed vs unsigned
    char     string[6]; // DISCUSS: Change 6 to 10 (padding)
} Value;

void value_format(Value *v, FILE *stream) {
    fprintf(stream, "Value{number = %016lx, string = %s}\n", v->number, v->string);
}

void value_bytes(Value *v, FILE *stream) {
    //unsigned integer with 8 bits aka 1 bit 
    //an unsigned char also would have worked 
    //v is a value type which is a 64 bit
    //asll casting does is tell the compiler that you know
    // what you are doing when you tell it to be interpreted as a certain type
    //... it does not change the binary code at all
    //it just tells it to be interpreted one way
    uint8_t *bytes = (uint8_t *)v;  // DISCUSS: casting

    // DISCUSS: endianness
    for (int i = sizeof(Value) - 1; i >= 0; i--) {
    	printf("byte[%d] = %02x\n", i, bytes[i]);
    }
}

int main(int argc, char *argv[]) {
    printf("Sizeof(Value) = %lu\n", sizeof(Value));
    puts("");

    Value v = {0};
    value_format(&v, stdout);
    value_bytes(&v, stdout);
    puts("");

    v.number = -1; 
    value_format(&v, stdout);
    value_bytes(&v, stdout);
    puts("");
    
    //-1 and the longest unsigned int have the same hex value 
    //because of 2's complement
    //they have the same binary value 

    v.number = ULONG_MAX;
    printf("%lu\n", ULONG_MAX);
    value_format(&v, stdout);
    value_bytes(&v, stdout);
    puts("");

    // 46 in hex is F
    //45 is E
    //52 is R
    v.number = 0x4150524546; //FERPA
    value_format(&v, stdout);
    value_bytes(&v, stdout);

    return 0;
}