mov r8, #0
mov r7, #0

mov r2, #0
mov r3, #20

LOOP1:
str r2, [r8, r7]
ADD r7, r7, #4
ADD r2, r2, #1
CMP r2, r3
BNE LOOP1

mov r5, #0		@ sum
mov r2, #0
mov r7, #0

LOOP2:
LDR r4, [r7]
ADD r7, r7, #4
ADD r5, r5, r4
ADD r2, r2, #1
CMP r2, r3
BNE LOOP2