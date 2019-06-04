	addi $a0, $zero, 6	# assign the input base
	addi $a1, $zero, 10	# assign the input power

# factorial: computes the given power of the given
#            base number iteratively ($a0 ^ $a1)
# algorithm:
#   group terms such that a minimum number of
#   multiplications are required to obtain result
#   i.e. 6 ^ 10 = (((6 ^ 2) ^ 2) ^ 2) * 6 ^ 2
#   as you can see 6 ^ 2 appears twice in the
#   expansion, however it is computed only once
# preconditions
#   $a0 - input base
#   $a1 - input power (must be non-negative)
# postconditions
#   $v0 - result of the computation
power:
	addi $v0, $zero, 1	# result = 1
	blez $a1, exit		# done if power <= 0
compute:
	andi $t1, $a1, 1	# temp = power & 0x1
	beq	$t1, $zero, skip	# skip mul if temp == 0
	mul	$v0, $v0, $a0	# result *= base
skip:
	mul	$a0, $a0, $a0	# compute base squared
	srl	$a1, $a1, 1	# power >> 1
	bgtz $a1, compute	# loop if power > 0
exit:
	jr	$ra			# return to the caller