.data
array: .word 1,2,3,4,5
_N: .word 5
sum: .word 0
sumMessage: .asciiz "The sum of the array is: "

.text
main:

li $t0, 0 #sum
li $t1, 0 #index
la $t2, array #array address
lw $t3, _N #length

addi $t3, $t3, -1
loop:
bgt $t1, $t3, exit
mul $t4, $t1, 4 #word==4 bytes
add $t4, $t2, $t4
lw $t4, 0($t4)
add $t0, $t0, $t4
addi $t1, $t1, 1
j loop

exit:
li $v0, 4 #str
la $a0, sumMessage
syscall 		
li $v0, 1 #int
addi $a0,$t0,0
syscall
	