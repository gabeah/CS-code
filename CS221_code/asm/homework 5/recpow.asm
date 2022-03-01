# Gabriel Howland
# HW4: recpow

		.data
		.text
		.align 2
		.globl main

recpow:

		addiu 	$sp, $sp, -4 	# expand stack
		sw 		$ra, 0($sp) 	# save return

		beq 	$a1, 0, recEnd  # check if we are at base to exponent 0
		addiu 	$a1, $a1, -1 	# subtract 1 from the exponent count

		jal 	recpow 			# recurse

		mul 	$v0, $a0, $v0 	# multiply return value by base value

		lw 		$ra, 0($sp) 	# reset return
		addi 	$sp, $sp, 4 	# restore stack

		jr 		$ra 			# return

recEnd:

		li 		$v0, 1 			# set v0 to 1
		lw 		$ra, 0($sp) 	# reset return
		addi 	$sp, $sp, 4 	# restore stack

		jr 		$ra 			# return

main:

		addiu 	$sp, $sp, -4 	# expand stack
		sw 		$ra, 0($sp) 	# save return

		li 		$v0, 5 			# prep for syscall input of base
		syscall
		move 	$a0, $v0 		# move base input to a0

		li 		$v0, 5 			# prep for syscall input of exponent
		syscall
		move 	$a1, $v0 		# move exponent input to a1

		jal 	recpow     		# run function

		move 	$a0, $v0 		# move returned value to a0
		li 		$v0, 1 			# prep for syscall print
		syscall

		lw 		$ra, 0($sp) 	# reset return
		addiu 	$sp, $sp, 4 	# restore stack

		jr $ra 					# end program