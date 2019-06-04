addi $a0, $zero, 6
addi $a1, $zero, 7
addi $a2, $zero, 8
addi $a3, $zero, 9
add $t0, $a0, $a1 # Adds g + h
add $t1, $a2, $a3 # Adss i+j
sub $s0, $t0, $t1
add $v0, $s0, $zero
