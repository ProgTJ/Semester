addi $a0, $zero 5 #i
addi $a1, $zero 6 #j
addi $a2, $zero 7 # Decrement
loop:
	blez $a2, exit
	addi $a3, $a0, $a1
	add $v0, $a3, $zero
	addi $a2, $a2 -1
	bgtz $a2, loop
exit:
	jr $ra

