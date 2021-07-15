	.data
stg:	.word 72343
	.asciiz "Napoleao"
	.space 9 #para garantir que bnaparte começa com offset 22 (visto que o array é de 18 elementos)
	.asciiz "Bonaparte"
	.space 5 #para garantir o offset (visto que o array é de 15 elementos)
	.float 5.1
	.align 2
	
	.eqv print_int,1
	.eqv print_str,4
	.eqv print_float,2
	
	.text
	
	.globl main
main:	
	la $t0,stg
	
	lw $a0,0($t0)
	li $v0,print_int
	syscall
	
	addiu $a0,$t0,4
	li $v0,print_str
	syscall
	
	addiu $a0,$t0,22
	li $v0,print_str
	syscall
	
	l.s $f12,40($t0)
	li $v0,print_float
	syscall
	
	jr $ra
	
	