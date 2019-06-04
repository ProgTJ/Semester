	addi $a0, $zero, 6	# assign the input base
	addi $a1, $zero, 10	# assign the input power

# factorial: computes the given power of the given
#            base number iteratively ($a0 ^ $a1)
# preconditions
#   $a0 - input base
#   $a1 - input power (must be non-negative)
# postconditions
#   $v0 - result of the computation
power:
	addi $v0, $zero, 1	# result = 1
	blez $a1, exit		# done if power <= 0
compute:
	mul	$v0, $a0, $v0	# result *= base
	addi $a1, $a1, -1	# power--
	bgtz $a1, compute	# loop if power > 0
exit:
	jr	$ra			# return to the caller