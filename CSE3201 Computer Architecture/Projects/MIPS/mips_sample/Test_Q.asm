addi $a0, $zero 6 # x
addi $a1, $zero 8 # y
add $v0, $a0, $zero
add $v1, $a1, $zero
 
blez $a1, end # if y < 0
loop:
	
	addi $v0, $v0, -1
	addi $v1, $v1, -1
	
	bgtz $v1, loop

end:
	jr $ra