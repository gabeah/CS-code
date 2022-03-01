# Gabe Howland
# CSCI-221 HW3

		.data
sum:	.word 	0
		.text
    	.align 2
    	.globl main
main:

		la $t0, sum 	# get variables set up
		li $v0, 5 		# Read integer
		syscall 		# ask for input
		move $t1, $v0 	# copy it into n
		lw $t2, 0($t0)	# load sum
		li $t4, 0 		# load counting value

add_loop:
		bgt $t4, $t1, end # if counter is less than n
		add $t2, $t2, $t4 # add sum up
		addi $t4, $t4, 1  # increase counter
		b add_loop		  # loop
end:
		move $a0, $t2 	# prep print value
		li $v0, 1 		# prep syscall
		syscall			# do syscall print

		jr $ra 			# end
		
