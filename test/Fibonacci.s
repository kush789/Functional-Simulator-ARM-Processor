mov r8, #0

mov r2, #0
mov r3, #20
mov r4, #0
mov r5, #1

mov r0, #1
str r0, [r8]
ADD r8, r8, #4

LOOP:
ADD r2,r2, #1
ADD r6,r5,r4
mov r4,r5
mov r5,r6
mov r1, r5
str r1, [r8]
add r8, r8, #4

CMP r2,r3
BNE LOOP