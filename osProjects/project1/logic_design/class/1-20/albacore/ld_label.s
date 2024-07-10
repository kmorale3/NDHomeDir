// demonstrate loading from the data segment

// constant 0xcafe at memory address v in data segment
.data 
v: 0xcafe

// start text segment
.text
// get address of v into r1
ldi r1, high(v) //assembler looks at its table and finds the high bytes of v
ldi r0, 8
shl r1, r1, r0
ldi r0, low(v)
or r1, r1, r0

// load data from address in r1 into r2
ld r2, r1, 0
quit
