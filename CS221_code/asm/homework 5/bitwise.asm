# HW4 bitwise
# Gabe Howland

		.data
		.text
		.align 2
		.globl main

bitwise:

		addiu 	$sp, $sp, -4		# expand stack
		sw 		$ra, 0($sp)			# save return
		li 		$t2, 1 				# prep comparison register
		beq 	$a0, $0, endBW 		# are we done checking the number?
		andi 	$t1, $a0, 0x1		# bitwise AND with value 1
		beq 	$t1, $t2, countUp 	# branch if bitwise AND resulted in a 1
		srl 	$a0, $a0, 1 		# else shift number over
		jal 	bitwise 			# recurse
		lw 		$ra, 0($sp) 		# reset return
		addi 	$sp, $sp, 4 		# restore stack
		jr 		$ra 				# return

countUp:
		
		addi 	$v0, $v0, 1 		# increase counter of 1's
		srl 	$a0, $a0, 1 		# shift number over
		jal 	bitwise 			# recurse
		lw 		$ra, 0($sp)  		# reset return
		addi 	$sp, $sp, 4 		# restore stack
		jr 		$ra 				# return

endBW:
		lw 		$ra, 0($sp) 		# reset return
		addi 	$sp, $sp, 4 		# restore stack
		jr 		$ra 				# return
main:

		addiu 	$sp, $sp, -4 		# expand stack
		sw 		$ra, 0($sp) 		# save return
		li 		$v0, 5 				# prep for syscall for integer input
		syscall
		move 	$a0, $v0 			# move input to a0
		li 		$v0, 0 				# clear out v0 so it can be used to count
		jal 	bitwise 			# begin function
		move 	$a0, $v0 			# take count and move to a0
		li 		$v0, 1 				# prep for syscall print
		syscall
		lw 		$ra, 0($sp) 		# reset return
		addi 	$sp, $sp, 4 		# restore stack

		jr 		$ra 				# end program