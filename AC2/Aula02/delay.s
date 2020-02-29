	.equ READ_CORE_TIMER,11
	.equ RESET_CORE_TIMER,12
	.equ READ_INT10,5
	.data
	.text
	.globl main
main:	li	$v0,READ_INT10
		syscall
		move $t0,$v0

for:	ble $t0,0,endfor
		sub $t0,$t0,1
		
		li $v0,RESET_CORE_TIMER
		syscall
while:	li $v0,READ_CORE_TIMER
		syscall
		blt	$v0,20000,while
		j for
endfor:	
		li $v0,0
		jr $ra