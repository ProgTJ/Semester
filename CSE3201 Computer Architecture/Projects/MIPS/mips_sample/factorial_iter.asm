	addi	$a0, $zero, 6	# assign the input number

# factorial: computes the factorial of the input
#            number using an iterative algorithm
# preconditions
#   $a0 - input number (must be non-negative)
# postconditions
#   $v0 - factorial of the input
factorial:
	addi	$v0, $zero, 1	# result = 1
	blez	$a0, exit		# done if n <= 0
compute:
	mul	$v0, $a0, $v0	# n * result
	addi	$a0, $a0, -1	# n--
	bgtz	$a0, compute
exit:
	jr	$ra