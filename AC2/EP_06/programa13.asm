# $t0 -> endereço base
# $s0 -> A

.text
.globl main
main:
lui $t0, 0x1001 # armazenando o endereço base
lw $s0, 0($t0)
srl $t1, $s0, 31 # armazena o bit de sinal do numero
beq $t1, $zero, fim # Caso não seja negativo, pula para o fim

modulo:
sub $s0, $zero, $s0 # A = 0 - (-A)
sw $s0, 0($t0) # MEM[t0] = A

fim:
.data
A: .word -4