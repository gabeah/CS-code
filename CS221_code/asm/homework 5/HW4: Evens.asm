# HW4: Evens
# Gabe Howland
# help from tutor callie

		.data
arr:	.word  18, 23, 47, 98, 1, 5, 42
size:   .word  7

		.text
		.align 2
		.globl main


startNE:

		li 		$t3, 0 	# load counter for number of evens
		li 		$t4, 0 	# load counter for loop

numEvens:

		beq		$a1, $t4, endNE	 # check if loop counter = size
		lw		$t1, 0($a0) 	 # load the current array number
		andi 	$t2, $t1, 0x1    # do bit-wise AND with array number and 1 
		beq		$t2, $0, countUp # if bitwise result is 0, count up
		addi 	$a0, $a0, 4		 # move to next word in array
		addi 	$t4, $t4, 1 	 # increase counter
		j 		numEvens 		 # loop

countUp:

		addi 	$t3, $t3, 1 	 # increase counter for number evens
		addi 	$t4, $t4, 1 	 # increase loop count
		addi 	$a0, $a0, 4 	 # move to next word in array
		j 		numEvens 		 # loop

endNE:
		
		move 	$a0, $t3 		 # move counter for number evens to result
		jr		$ra 			 # return back to main

main:

		addiu 	$sp, $sp, -4     # increase stack space
		sw 		$ra, 0($sp) 	 # save return

		la 		$a0, arr 		 # load arr address
		la 		$t0, size 		 # load size address
		lw 		$a1, 0($t0) 	 # load size

		jal 	startNE  		 # run function

		li 		$v0, 1 			 # prep syscall
		syscall

		lw 		$ra, 0($sp) 	 # reset return
		addi 	$sp, $sp, 4 	 # reset stack

		jr 		$ra 			 # end