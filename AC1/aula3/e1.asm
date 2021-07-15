#	Mapa de regitos
#	$t0 - soma
# 	$t1 - value
#	$t2 - i

	.data
str1:	.asciiz	"Introduza um numero: "
str2:	.asciiz "Valor ignorado \n"
str3:	.asciiz "A soma dos positivos e: "

	.eqv print_string,4
	.eqv read_int,5
	.eqv print_int,1
	
	.text
	.globl main
main:	li $t0,0 #soma = 0
	li $t1,0 # value = 0
	li $t2,0 # i = 0
	
for:	bge $t2,5,endfor
	
	li $v0,print_string
	la $a0,str1
	syscall #print str1
	
	li $v0,read_int
	syscall #$v0 = readint()
	move $t1,$v0 #value = readint()

if:	blez $t1,else #value > 0
	add $t0,$t1,$t0
	j endif

else:
	li $v0,print_string
	la $a0,str2
	syscall #print str2
	
endif:
	addi $t2,$t2,1 #i++
	j for

endfor:
	li $v0,print_string
	la $a0,str3
	syscall
	li $v0,print_int
	move $a0,$t0
	syscall
	
	jr $ra