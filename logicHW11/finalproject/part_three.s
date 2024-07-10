// f000: LEDR
// f001: LEDG
// f002: HEX3-HEX0
// f003: HEX7-HEX4
// f004: SW

.text 

// write the general I/O based address 0xf000 to r10
ldi r10, 0xf0
ldi r0, 8
shl r10, r10, r0

//write the multiplier base address 0xf040 to r12
ldi r0, 0x40
or  r12, r10, r0

start:
//load in from switches

ld r0, r10, 4

//light up red leds
st r0, r10, 0

//display on HEX7-HEX4
st r0, r10, 3

ldi r1, 0xff
ldi r2, 8
shl r1, r1, r2
and r1, r0, r1
shr r1, r1, r2
//the value of m is now in r1

//write r1 to the address of m
st r1, r12, 0

ldi r3, 0
shl r3, r3, r2
ldi r3, 0xff
and r3, r0, r3
//the value of n is in r3

//write r3 to the address of n
st r3, r12, 1

//write any value to the address of start to begin multiplication
st r0, r12, 3


//loop on reading the value of busy until busy equals 0 and multiplication is done
loop:
ld r2, r12, 4
bz r2, finish



br loop

finish:
ld r3, r12, 2
//write the product to HEX3-HEX0
st r3, r10, 2

br start

quit



