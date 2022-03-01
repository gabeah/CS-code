# Gabe Howland and Yik Yin Cheuk
# This program prints the value of variable x to the console.
    .data
x:  .word   -3
y:  .word   3
    .text
    .align 2
    .globl main

main:
    la  $t0, x          # load x
    la  $t1, y          # load y
    lw  $t2, 0($t0)     # load the value of x
    lw  $t3, 0($t1)     # load the value of y

    bgt $t2, $t3, big   # if $t2 > $t3, go BIG
    move $a0, $t3       # set up print output
    b print

big:
    move $a0, $t2       # if $t2 >= $t3...
    b print

print:
    li $v0, 1
    syscall

    jr $ra
