addi $a0, $zero 2 # a
addi $a1, $zero 0
addi $a2, $zero 6 # b
addi $a3, $zero 1 

loop: 
	beq $a2, $a1, end # while b> 0
	add $a0, $a0, $a3 # a+= a + 1
	addi $a2, $a2 -1  # b --
	
	j loop
end: #ends the program
	add $v0, $a0, $zero
