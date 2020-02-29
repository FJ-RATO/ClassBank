	.equ SFR_BASE_HI, 0xBF88      # 16 MSbits of SFR area       
	.equ TRISE, 0x6100            # TRISE address is 0xBF886100  
	.equ TRISB, 0x6040    
	.equ PORTE, 0x6110            # PORTE address is 0xBF886110  
	.equ PORTB, 0x6050    
	.equ LATE,  0x6120           # LATE  address is 0xBF886120
	.equ LATB,	0x6060

	.data
	.text
	.globl main

main:
	lui 	$t1, SFR_BASE_HI
	
	lw		$t2, TRISE($t1)
	andi	$t2,$t2,0xFFFE
	sw		$t2, TRISE($t1) #config RE0 a 0

	lw		$t2,TRISB($t1)
	ori		$t2,$t2,0x0001
	sw		$t2,TRISB($t1)
body:
	lw		$t2,LATE($t1)
	andi	$t3,$t2,0xFFFE
	lw		$t4,PORTB($t1)
	andi 	$t4,$t4,0x0001
	or 		$t2,$t4,$t3
	sw		$t2,LATE($t1)

	j body
	jr 		$ra