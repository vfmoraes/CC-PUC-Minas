# $s0 -> x
# $s1 -> y
# $s2 -> z
# t0 -> endereço base

.text
.globl main
main:
lui $t0, 0x1001
lw $s0, 0($t0) # x = MEM[t0]
lw $s2, 4($t0) # z = MEM[t0+1]
sll $t1, $s0, 7 # t1 = 128x
sub $t1, $t1, $s0 # t1 = 128x - x = 127x

sll $t2, $s2, 6 # t2 = 64z
add $t2, $t2, $s2 # t2 = 64z + z = 65z
sub $t1, $t1, $t2 # t1 = 127x - 65z
addi $s1, $t1, 1 # t1 = (127x - 65z) + 1
sw $s1, 8($t0) # MEM[t0 + 2] = t1

.data
x: .word 5
z: .word 7
y: .word 0 # esse valor deverá ser sobrescrito após a execução do programa.