# $t0 -> endereço base
# $s0 -> x
# $s1 -> y
# $s2 -> z

.text
.globl main
main:
lui $t0, 0x1001
lw $s0, 0($t0) # x = MEM[t0]
lw $s2, 4($t0) # z = MEM[t0 + 1]
sub $t1, $s0, $s2 # t1 = x - z
ori $t2, $zero, 0x493E
sll $t2, $t2, 4 # t2 = 300.000
add $s1, $t1, $t2 # t1 = (x - z) + 300.000
sw $s1, 8($t0) # MEM[t0 + 2] = y

.data
x: .word 100000
z: .word 200000
y: .word 0 # esse valor deverá ser sobrescrito após a execução do programa.

