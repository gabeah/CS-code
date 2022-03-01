
rec_fib:
    beq  $a3, $0, donefib  # end recursion if $a3 (n) is 0

    addi $sp, $sp, -4      # expand stack
    sw   $ra, 0($sp)       # save position in stack

    add  $a2, $a1, $a0     # add $a1 and $a0 (assuming both had 1 loaded into them
    move $a0, $a1          # set $a0 to be $a1
    move $a1, $a2          # set $a1 to be $a2
    
    addi $a3, $a3, -1      # decrease counter by 1
    
    jal  rec_fib           # recurse
    
    addi $sp, $sp, 4       # return space to stack
    jr $ra                 # continue returning out
    

donefib:
    addi $sp, $sp, 4       # give back initial space in stack
    jr   $ra               # start the return chain

fib:
    beq  $a3, $0, exit     # check if counter is 0 


    add  $a2, $a1, $a0     # add values together
    move $a0, $a1          # set a0 to a1
    move $a1, $a2          # set a1 to a2
    
    addi $a3, $a3, -1      # decrease counter
    
    b fib                  # loop