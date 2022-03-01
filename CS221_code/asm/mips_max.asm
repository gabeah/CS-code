# Gabriel Howland
# MIPS HW3 Max

		.data
		.text
    	.align 2
    	.globl main
 main:
 		li $t0, 0 # max		# set max value
 		li $t1, 0 # temp	# create temp value
 		li $t2, 0 # n 		# create the size of the number 'n'
 		li $v0, 5 			# setup syscall for n input
 		syscall
 		move $t2, $v0		# assign value 'n'
 		li $t3, 1 # counting
input:
		bgt $t3, $t2, end	# create loop
		li $v0, 5			# take a number
		syscall
		move $t1, $v0		# set as temp
		addi $t3, 1 		# increase the counting number
check:
		bgt $t0, $t1, input # if temp less than max
		move $t0, $t1		# set max as temp
		b input				# LOOP
end:
		move $a0, $t0		# take the maximum value
		li $v0, 1 			# print via syscall
		syscall

		jr $ra