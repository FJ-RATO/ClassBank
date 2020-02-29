	.equ SFR_BASE_HI, 0xBF88      # 16 MSbits of SFR area       
	.equ TRISE, 0x6100            # TRISE address is 0xBF886100  
	.equ TRISB, 0x6040    
	.equ PORTE, 0x6110            # PORTE address is 0xBF886110  
	.equ PORTB, 0x6050    
	.equ LATE,  0x6120           # LATE  address is 0xBF886120
	.equ LATB,	0x6060
	.equ READ_CORE_TIMER,11
	.equ RESET_CORE_TIMER,12
	.equ READ_INT10,5

	.data
	.text
	.globl main

main:
	lui		$t1, SFR_BASE_HI

	lw		$t2, TRISE($t1)
	andi	$t2,$t2,0xFFF0
	sw		$t2, TRISE($t1) #config RE0-RE3 to 0


	li 		$t3,0x0000 #t3 counter = 0
body:

if:
	lw		$t2,LATE($t1)
	andi	$t2,$t2,0xFFF0
	or 		$t2,$t3,$t2
	sw		$t2,LATE($t1)
	add 	$t3,$t3,0x0001
	ble		$t3,0x000F,delay

els:
	li 	$t3,0




#delay subrotine
delay:	li $t0,250 #$t0 = delay in ms

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
		j body