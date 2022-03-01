# HOMEWORK 4
# Character count
# Tutor Callie helped me with this

		.data
str:	.asciiz	"the quick brown fox jumped over the lazy dog"

		.text
		.align 2
		.globl main

enter:
		li 		$t1, 0 				# start counter at 0

countOccurances:
		
		lb 		$t0, 0($a0) 		# load byte from addr pointer
		beq 	$t0, $a1, countUp 	# check if byte = byte of ascii comparison
		beq 	$t0, $0, end 		# check if byte = end of string
		addi 	$a0, $a0, 1 		# increase addr pointer to next byte
		j 		countOccurances 	# loop

countUp:
		addi 	$t1, $t1, 1 		# increase counter
		addi 	$a0, $a0, 1 		# increase addr pointer to next byte
		j 		countOccurances 	# loop

end:

		move 	$a0, $t1 			# move counter to a0
		jr 		$ra 				# return function

main:
		addiu 	$sp, $sp, -4 		# expand stack
		sw 		$ra, 0($sp) 		# save return

		li 		$v0 12 				# prep syscall input of ascii
		syscall
		move 	$a1, $v0 			# move input of ascii to a1
		la 		$a0, str 			# load addr of str

		jal 	enter 				# begin funct

		li 		$v0, 1 				# prep syscall of print
		syscall

		lw 		$ra, 0($sp) 		# reset return
		addi 	$sp, $sp, 4 		# restore stack

		jr $ra 						# end program