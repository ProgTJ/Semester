addi $a0, $zero, 2 # a
addi $a1, $zero, 6 # b

loop:
	blez $a1, end # if(a == 0) while (b > 0)
	addi $a0, $a0 1 # a=a+1
	addi $a1, $a1 -1 # b--
	bgtz $a1, loop
end:
	add $v0, $a0, $zero
	