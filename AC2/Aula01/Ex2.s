	.equ getchar,2
	.equ putchar,3

	.data
	.text
	.globl main

main:
do:
	li $v0,getchar
	syscall
	move $t1,$v0
if:
	beq $t1,'\n',endif
	li $v0,putchar
	move $a0,$t1
	syscall
endif:
	bne $t1,'\n',do
	li $v0,0
	j $ra
