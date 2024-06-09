# $t0 -> endereço base
# $s0 -> x
# $s1 -> y
# $s2 -> k
# $s3 -> i

.text
.globl main
main:
lui $t0, 0x1001
lw $s0, 0($t0) # x = MEM[t0]
beq $s0, $zero, resultado
lw $s1, 4($t0) # y = MEM[t0 + 1]
beq $s1, $zero, resultado
ori $s3, $zero, 0 # i = 0
slt $t1, $s1, $zero # verifica se é menor que zero
beq $t1, $zero, multiplicacao
sub $s1, $zero, $s1
sub $s0, $zero, $s0
multiplicacao:
add $s2, $s2, $s0 # k = k + x
addi $s3, $s3, 1 # i = i + 1
bne $s3, $s1, multiplicacao 
resultado:
sw $s2, 8($t0)
.data
x: .word 20
y: .word 10
k: .word -1 # será sobrescrito no final
