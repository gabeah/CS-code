# Gabe Howland and Yik Yin Cheuk
#Problem 2 asm
#this program subtracts two numbers

	.data
x:  .word  3
y:  .word  7

	.text
    .align 2
    .globl main
main:
	la $t0, x #load x
	la $t1, y #load y
	lw $t2, 0($t0) #load the value of x
	lw $t3, 0($t1) #load the value of y
	sub $t4, $t2, $t3 #subtract

	li $v0, 1 #prep for print
	move $a0, $t4 #load the integer needed
	syscall #print

	jr	$ra #return
