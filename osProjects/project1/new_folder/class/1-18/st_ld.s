.text
// store value 7 to memory address 0xabcd

// write address xabcd to r1

ldi r1, 0xab
ldi r0, 8
shl r1, r1, r0
ldi r0, 0xcd
or r1, r1, r0

// write 7 to r2

ldi r2, 7

// store value in r2 to the address in r1 with offset 0

st r2, r1, 0

// load the value at memory address 0xabcd into r3

ld r3, r1, 0

// store the value 5 to memory address 0xabce
// use an offset of 1 from base address 0xabcd

ldi r2, 5
st r2, r1, 1

quit
