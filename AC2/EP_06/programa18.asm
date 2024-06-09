# $t0 -> endereço base
# $s0 -> x
# $s1 -> y
# $s2 -> k
# $s3 -> i
# $s4 -> j
# $s5 -> temp
.text
.globl main
main:
lui $t0, 0x1001
lw $s0, 0($t0)    # x = MEM[t0]
lw $s1, 4($t0)    # y = MEM[t0 + 4]
ori $s2, $zero, 1 # k = 1
ori $s4, $zero, 0 # j = 0

potencia_loop:
beq $s4, $s1, resultado_potencia # Se j == y, termina
ori $s3, $zero, 0 # i = 0
ori $s5, $zero, 0 # temp = 0

multiplicacao:
add $s5, $s5, $s2 # temp = temp + k
addi $s3, $s3, 1 # i = i + 1
bne $s3, $s0, multiplicacao # Enquanto i != x, multiplica x vezes
add $s2, $s5, $zero # k = temp
addi $s4, $s4, 1 # j = j + 1
j potencia_loop

resultado_potencia:
sw $s2, 8($t0) # MEM[t0 + 8] = k
.data
x: .word 9
y: .word 3
k: .word -1 # será sobrescrito no final
