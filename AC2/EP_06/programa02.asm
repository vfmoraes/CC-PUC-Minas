# $s0 -> x
# $s1 -> y

.text
.globl main
main:
addi $s0, $zero, 1 # x = 1
add $t0, $s0, $s0 # t0 = 2x
add $t0, $t0, $t0 # t0 = 4x
add $t0, $t0, $s0 # t0 = 5x
addi $s1, $t0, 15 # y = 5x + 15