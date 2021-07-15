	.data
	.text
	.globl main
main:	 li $t0,0x052
	srl $t1,$t0,1 # bin >> 1
	xor $t2,$t0,$t1 # bin ^ (bin >> 1)
	#$t2 now has grey
	move $t3,$t2 #$t3 num
	srl  $t4,$t3,4 #$t4 aux_shifted
	xor  $t3,$t3,$t4
	srl  $t4,$t3,2 #$t4 aux_shifted
	xor  $t3,$t3,$t4
	srl  $t4,$t3,1 #$t4 aux_shifted
	xor  $t3,$t3,$t4
	
	
	