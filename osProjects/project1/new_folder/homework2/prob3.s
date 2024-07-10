.text 
ldi r1, 0xa5
ldi r2, 138
ldi r3, 0x05
add r4, r1, r3
st r2, r1, 5
ld  r5, r4, 0
or r0, r5, r5 
quit