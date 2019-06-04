addi $t0, $zero 4 # int n
addi $t1, $zero 1 # int f
addi $t2, $zero 0 # while (n >0)

loop: 
	beq $t0, $t2 end
	mul $t1, $t0, $t1
	addi $t0, $t0, $t0 -1
end: 
	addi $v0, $zero 0
	