	.data
	.equ readint10,5
	.equ printint,6
	.equ printstr,8
str:	.asciiz	"Introduza um numero"
str1:	.asciiz "\nValor lido, em base 2: "
str2:	.asciiz "\nValor lido, em base 16: "
str3:	.asciiz "\nValor lido, em base 10 (unisgned): "
str4:	.asciiz "\nValor lido, em base 10 (signed)"
	.text
	.globl main
main:
	la $a0,str
	li $v0,printstr
	syscall
	li $v0,readint10
	syscall
	move $t1,$v0

	li $v0,printstr
	la $a0,str1
	syscall

	li $v0,printint
	move $a0,$t1
	li $a1,2
	syscall

	li $v0,printstr
	la $a0,str2
	syscall

	li $v0,printint
	move $a0,$t1
	li $a1,16
	syscall

	li $v0,printstr
	la $a0,str3
	syscall

	li $v0,printint
	move $a0,$t1
	li $a1,10
	syscall

	li $v0,printstr
	la $a0,str4
	syscall

	li $v0,7
	move $a0,$t1
	syscall

	j main
	j $ra

