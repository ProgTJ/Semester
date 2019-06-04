	addi	$a0, $zero, 6	# assign the input number

# factorial: computes the factorial of the input
#            number using a recursive algorithm
# preconditions
#   $a0 - input number (must be non-negative)
# postconditions
#   $v0 - factorial of the input
factorial:
	bgtz	$a0, doit
	addi	$v0, $zero, 1	# base case, 0! = 1
	jr	$ra			# return to the caller
doit:
	addi	$sp, $sp, -8	# stack frame
	sw	$s0, 0($sp)	# will use for argument n
	sw	$ra, 4($sp)	# return address
	
	add	$s0, $0, $a0	# save argument
	addi	$a0, $a0, -1	# n-1
	jal	factorial		# v0 = (n-1)!
	mul	$v0, $s0, $v0	# n*(n-1)!
	
	lw	$s0, 0($sp)	# restore registers from stack
	lw	$ra, 4($sp)
	addi	$sp, $sp, 8
	jr	$ra