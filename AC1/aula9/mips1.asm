	.data
x:	.float 2.59375

	.text
	.globl main
	
main: 
do:	li $v0,5
	syscall #$v0 = readint
	
	la 	$t0,x #2.59375
	l.s	$f4,0($t0) #load 2.59375 to f4
	mtc1	$v0,$f6 #move from $v0 to $f6
	cvt.s.w $f6,$f6 #cast to float
	mul.s	$f12,$f6,$f4 # 2.59375*(float)reandint()
	li	$v0,2
	syscall #print float
	mtc1	$0,$f10 #f10 0.0 não tem de ser convertido por ser zero
	c.eq.s	$f12,$f10
	bc1f do
	li $v0,0
	jr $ra