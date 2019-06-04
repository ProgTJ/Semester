addi $a0, $zero, 2 # a
addi $a1, $zero, 6 #b

loop:
	blez $a1, exit
	addi $a0, $a0 1
	addi $a1, $a1 -1
	bgtz $a1, loop
	
exit:
	jr $ra
	