addi $a0, $zero 6 #x
addi $a1, $zero 5 #y
addi $a2, $zero 1 #result

loop: blez $a1, exit
	mul $a2, $a2, $a0
	addi $a1, $a1 -1
	bgtz $a2, loop
exit:
	jr $ra