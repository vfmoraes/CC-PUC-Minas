# $s0 -> x
# $s1 -> y
# $s2 -> A[0]
.text
.globl main
main:
lui $s2, 0x1001
lw $s0, 0($s2)
lw $s1, 4($s2)
add $a0, $zero, $s0
add $a1, $zero, $s1
jal potencia
sw $v0, 8($s2)
j fim

potencia:
add $v0, $zero, $a0
addi $t1, $zero, 1
	loop:
		slt $t2, $t1, $a1
		beq $t2, $zero, retorno
		mult $v0, $a0
		mflo $v0
		addi $t1, $t1, 1
		j loop
	retorno:
		slti $t0, $a1, 1
		bne $t0, $zero, retorna_1
		jr $ra
	retorna_1:
		addi $v0, $zero, 1
		jr $ra
		
fim:

.data
x: .word 13
y: .word 7
