// Katie Morales
// Logic Design Homework 2 problem 4

#include <stdio.h>

void disassemble(int the_input){
    //define a mask that will zero everything except the 4 least sinificant bits
    int mask = 0x0000000f; 
    //use an and to 0 out the other bits
    int rb = (the_input & mask);
    //shift the integer 4 bits in order to move the bits 5-8 from the end to become the 4 least significant
    int temp = the_input >> 4;
    //use an and with the mask toe extract these bits
    int ra = (temp & mask);
    //repreat the process twice to extract the remaining 8 bits
    temp = temp >> 4;
    int rw = (temp & mask);
    temp = temp >> 4;
    int opcode = (temp & mask);
    printf("opcode = %x \t rw = %x \t ra = %x \t rb = %x \n", opcode, rw, ra, rb);

}

int main() {
    int alba_input = 0x1234;
    disassemble(alba_input);
    alba_input = 0x63a4;
    disassemble(alba_input);
    alba_input = 0x317f;
    disassemble(alba_input);
    alba_input = 0x1ab2;
    disassemble(alba_input);
    

}