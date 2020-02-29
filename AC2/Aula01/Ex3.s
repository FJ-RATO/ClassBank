	.equ inkey,1	
	.equ getchar,2
	.equ putchar,3

	.data
	.text
	.globl main

main:
do:
	li $v0,inkey
	syscall
	move $t1,$v0
	beq $t1,$0,do
if:
	beq $t1,'\n',endif
	li $v0,putchar
	move $a0,$t1
	syscall
endif:
	bne $t1,'\n',do
	li $v0,0
	j $ra


