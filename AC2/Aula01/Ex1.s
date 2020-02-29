		.equ	PRINT_STR,8

		.data
str:	.asciiz	"Hello World!"
		.text
		.globl main
main:	la $a0,str
		li $v0,PRINT_STR
		syscall
		li	$v0,0
		jr	$ra
