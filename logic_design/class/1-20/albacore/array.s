// X[2] = X[0] + X[1]
.data
X: 3, 4, 0

.text
ldi r1, high(X)   // r1 = X
ldi r0, 8
shl r1, r1, r0
ldi r0, low(X)
or  r1, r1, r0
ld  r2, r0, 0     // r2 = X[0]
ld  r3, r0, 1     // r3 = X[1]
add r3, r3, r2    // r3 = r3 + r2
st  r3, r1, 2     // X[2] = r3
quit
