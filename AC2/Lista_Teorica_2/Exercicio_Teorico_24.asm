# $s0 -> A[0]
# $s1 -> Soma de y[]
.text
.globl main
main:
lui $s0, 0x1001
lw $s1, 0($s0)
add $a0, $s0, $s1
lw $s1, 4($s0)
add $a1, $zero, $s1

jal vetor

add $s1, $zero, $v0
sw $s1, 8($s0)
j fim

vetor:
slti $t3, $a1, 31
bne $t3, $zero, pre_loop
addi $a1, $zero, 30
	pre_loop:
	add $t0, $zero, $zero
	loop:
		sll $t1, $t0, 2
		add $t1, $t1, $a0
		andi $t2, $t0, 0x1
		beq $t2, $zero, par
		impar:
			# Configurando o stack
			addi $sp, $sp, -4
			sw $ra, 4($sp)
			sw $a0, 0($sp)
			
			add $a0, $zero, $t0
			jal quadrado
						
			lw $a0, 0($sp)
			lw $ra, 4($sp)
			addi $sp, $sp, 4
			
			add $t5, $t5, $v0		
			sw $v0, 0($t1)
			j incremento_i
		par:
			# configurando a pilha
			addi $sp, $sp, -4
			sw $ra, 4($sp)
			sw $a0, 0($sp)
			
			add $a0, $zero, $t0
			jal quadrado
			
			lw $a0, 0($sp)
			lw $ra, 4($sp)
			addi $sp, $sp, 4
			
			sll $t3, $v0, 1
			sll $t4, $t0, 1
			add $t4, $t4, $t3
			addi $t4, $t4, 1
			add $t5, $t5, $t4
			sw $t4, 0($t1)
			
		incremento_i:
			addi $t0, $t0, 1
			slt $t4, $t0, $a1
			bne $t0, $a1, loop
			add $v0, $zero, $t5
			jr $ra

quadrado:
mult $a0, $a0
mflo $v0
jr $ra

fim:

.data
x: .word 16
y: .word 40
			
			
			