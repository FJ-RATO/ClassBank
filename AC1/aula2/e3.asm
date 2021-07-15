	.data
	.text
	.globl main
main:	li $t0,0xff000000

	sll $t1,$t0,1
	srl $t2,$t0,1
	sra $t3,$t0,1
	
	jr $ra
	
	