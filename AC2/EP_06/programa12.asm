# $t0 -> endereço base
# $s0 -> k

.text
.globl main
main:
lui $t0, 0x1001
lw $t1, 0($t0) # t1 = MEM[t0]
lw $t1, 0($t1) # t1 = MEM[t1]
lw $t1, 0($t1) # t1 = MEM[t1]
lw $s0, 0($t1) # k = MEM[t1]
sll $s0, $s0, 1 # k = k * 2
sw $s0, 0($t1)# MEM[t1] = k

.data
ppp_x: .word 0x10010004
pp_x: .word 0x10010008
p_x: .word 0x1001000C
x: .word 10
