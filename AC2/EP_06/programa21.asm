# $t0 -> endereço base
# $s0 -> x
# $s1 -> y

.text
.globl main
main:
lui $t0, 0x1001 # armazenando o endereço base
lw $s0, 0($t0)
slti $t1, $s0, 1
beq $t1, $zero, maiorZero # Se for 0, é maior que zero

menorigualZero:
mult $s0, $s0 # x^2
mflo $t2 # t2 = x^2
mult $t2, $t2 # x^4
mflo $t2 # t2 = x^4

addi $s1, $t2, -1
j resultado

maiorZero:
mult $s0, $s0 # x^2
mflo $t2 # t2 = x^2
mult $t2, $s0 # x^3
mflo $t2 # t2 = x^3

addi $s1, $t2, 1 # y = x^3 + 1

resultado:
sw $s1, 4($t0) # MEM[t0 + 1] = y
.data
x: .word -4
y: -1 # será sobrescrito no final
