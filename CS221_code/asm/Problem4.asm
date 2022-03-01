# Gabe Howland and Yik Yin Cheuk
# This program read in two positive integers, a and b, from the user and
# prints a * b.
    .text
    .align 2
    .globl main
main:
    li   $v0, 5          # set up reading of first int
    syscall
    move $t0, $v0        # store first int, a, into $t0
    blt  $t0, $0, done   # go to done if a not positive

    li   $v0, 5          # set up reading of first int
    syscall
    move $t1, $v0        # store first int, b, into $t1
    blt  $t1, $0, done   # go to done if b not positive

    move $a0, $0         # set up output at 0
loop:
    beq  $t0, $0, print  # loop until register is empty
    add  $a0, $a0, $t1   # multiply by adding
    sub $t0, 1           # decrease amount of loops
    b loop

print:
    li   $v0, 1       # set up "print int" system call
    syscall           # execute system call

done:
    jr   $ra          # return from main method
