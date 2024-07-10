.text
//store value 0xfade to 0xa5 and 0xab

//load 0xfa into r1
ldi r1, 0xfa

//load 8 bits into r0
ldi r0, 8

//shift r1 by 8 bits
shl r1,r1,r0

//load 0xde into r0
ldi r0, 0xde

//write 0xfade to r1
or r1, r1, r0

// write the memory address 0xa5 to r2
ldi r2, 0xa5

//store the value in r1 (0xfade) to the memory address in r2 (0xa5)
//0 offset
st r1, r2, 0

//also store the value in the memory address 0xab
// 6 offset from 0xa5 (r2)
st r1, r2, 6

quit 



