# $t0 -> endereço base
# $s0 -> x1
# $s1 -> x2
# $s2 -> x3
# $s3 -> x4

.text
.globl main
main:
lui $t0, 0x1001
lw $s0, 0($t0) # x1 = MEM[0]
lw $s1, 4($t0) # x2 = MEM[1]
lw $s2, 8($t0) # x3 = MEM[2]
lw $s3, 12($t0) # x4 = MEM[3]
add $t1, $s0, $s1 # t1 = x1 + x2
add $t1, $t1, $s2 # t1 = (x1 + x2) + x3
add $t1, $t1, $s3 # t1 = (x1 + x2 + x3) + x4
sw $t1, 16($t0) # MEM[soma] = x1 + x2 + x3 + x4

.data
x1: .word 15
x2: .word 25
x3: .word 13
x4: .word 17
soma: .word -1