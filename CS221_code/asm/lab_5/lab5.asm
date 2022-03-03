# Gabriel Howland
# Week 5 Lab

		.data
		

		.text
    	.align 2
    	.globl main

isSingleBit:

		addiu $sp, $sp, -4
		sw	  $ra, 0($sp)

bitLoop:
		
		ble   $a0, 1, doneLoop # check if $a0 is greater than 1
		
		li	  $a3, 0 		   # set return to tenative 0

		andi  $a1, $a0, 0x1	   # do bitwise AND with 1
		beq   $a1, 1, doneLoop # check if the final bit is 1
		srl   $a0, $a0, 1  	   # divide $a0 by 2
		
		li    $a3, 1 		   # set return to tenative 1

		b bitLoop 			   # loop
doneLoop:
		lw    $v0, 0($a3)
		lw	  $ra, 0($sp)
		addiu $sp, $sp, 4
		jr	  $ra


startSumArray:

		li 	$t0, 0 # load counter for loop
		li	$v0, 0 # reset sum value to 0
sumArray:
	
		bge	$t0, $a1, endSumArray # check if we have gone through whole array
		lw 	$t1, 0($a0) 	      # load current array number
		add 	$v0, $v0, $t1	# add value to sum
		addi 	$a0, $a0, 4 	# point to next value in array
		addi	$t0, $t0, 1 	# increase count

		j	sumArray 	# loop

endSumArray:
		jr 	$ra 	# return

startRSA:
		li	$t0, 0 # set counter value
		li 	$v0, 0 # reset v0 value
recSumArray:
		addiu	$sp, $sp, -4 # expand stack
		sw	$ra, 0($sp) # set return value

		beq 	$t0, $a0, firstReturn # check if recursion is done
		addiu 	$a0, $a0, 4 # point to next value in array
		addi 	$t0, $t0, 1 # increase counter value
		jal	recSumArray # recurse

		lw 	$t1, 0($a0) # load current array value
		add 	$v0, $v0, $t1 # add to sum current array value

		addiu 	$a0, $a0, -4 # decrease array pointer

		lw 	$ra, 0($sp) # restore return point
		addi	$sp, $sp, 4 # shrink stack

		jr 	$ra # return

firstReturn:
		lw 	$t1, 0($a0) # load last value of array
		add 	$v0, $v0, $t1 # add first value to sum

		addiu 	$a0, $a0, -4 # decrease array pointer

		lw 	$ra, 0($sp) # reset return pointer
		addi 	$sp, $sp, 4 # return stack size

		jr 	$ra 	# return	
