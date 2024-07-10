// f002: HEX3-HEX0

.text 

// write the general I/O based address 0xf000 to r10
ldi r10, 0xf0
ldi r0, 8
shl r10, r10, r0

//write the multiplier base address 0xf040 to r12
ldi r0, 0x40
or  r12, r10, r0

//write 0xab to the address of m
ldi r0, 0xab
st r0, r12, 0

//write 0xcd to the address of n
ldi r0, 0xcd
st r0, r12, 1

//write any value to the address of start to begin multiplication
st r0, r12, 3

// *** DEBUG ***
//dummy the prod value, give it 0x88ef
//ldi r3, 0x88
//ldi r4, 8
//shl r3, r3, r4
//ldi r4, 0xef
//or r3, r3, r4
//st r3, r12, 2
//dummy the busy value... INITIALLY NOT 0
//ldi r5, 1
//st r5, r12, 4
// *** DEBUG ***

//loop on reading the value of busy until busy equals 0 and multiplication is done
loop:
ld r2, r12, 4
bz r2, finish

// *** DEBUG ***
//change busy to be 0
//ldi r5, 0
//st r5, r12, 4
// *** DEBUG ***

br loop

finish:
ld r3, r12, 2
st r3, r10, 2
quit



