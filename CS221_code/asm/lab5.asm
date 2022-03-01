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

main:
		sw    $ra, 0($sp)

		li    $v0, 5
		syscall
		
		jal   isSingleBit

		sw	  $ra, 0($sp)
		jr	  $ra