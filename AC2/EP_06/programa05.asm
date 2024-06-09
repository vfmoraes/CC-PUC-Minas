# $s0 -> x
# $s1 -> y
# $s2 -> z

addi $t0, $zero, 0x186A
sll $s0, $t0, 4 # x = 100.000
addi $t0, $zero, 0x30D4
sll $s1, $t0, 4 # y = 200.000
add $s2, $s0, $s1 # z = x + y