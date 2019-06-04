addi $t0, $zero, 10
addi $t1, $zero, 0
addi $t2, $zero, 17


loop:
	beq $t1, $t0, end # if t1 == 10 end loop
	add $t2, $t2, $t1
	addi $t1, $t1, $t1
	
	j loop

end: # ends the program
	addi $v0, $zero, 10
	
	
	