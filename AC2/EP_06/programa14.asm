# $t0 -> endere�o base
# $s0 -> A

.text
.globl main
main:
lui $t0, 0x1001
lw $s0, 0($t0) # A = MEM[t0]
andi $t1, $s0, 0x1
sw $t1, 4($t0) # armazena 0 se � par e 1 se for �mpar

.data
A: .word 2
resp: .word -1