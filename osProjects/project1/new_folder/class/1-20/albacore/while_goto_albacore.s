.text
//     int i = 3;
ldi r1, 3

//     int x = 0;
ldi r2,0

// loop_cond:
loop_cond:

//     if (i < 0) goto loop_exit;
bn r1, loop_exit

//     i = i - 1;
ldi r0, 1
sub r1, r1, r0

//     goto loop_cond;
br loop_cond

// loop_exit:
loop_exit:

//     x = 0xff;
ldi r2, 0xff

quit

