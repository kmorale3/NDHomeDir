.text
// load into r1 and r2
ldi r1, 0x3
ldi r2, 0x5

// not r2
not r3, r2

// (r1 & ~r2)
and r4, r1, r3

// not r1
not r5, r1

// (~r1 & r2)
and r6, r5, r2

// (r1 & ~r2) | (~r1 & r2)
or r0, r4, r6

quit